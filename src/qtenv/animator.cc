//==========================================================================
//  ANIMATOR.CC - part of
//
//                     OMNeT++/OMNEST
//            Discrete System Simulation in C++
//
//==========================================================================

/*--------------------------------------------------------------*
  Copyright (C) 1992-2015 Andras Varga
  Copyright (C) 2006-2015 OpenSim Ltd.

  This file is distributed WITHOUT ANY WARRANTY. See the file
  `license' for details on this and other legal matters.
*--------------------------------------------------------------*/

#include "animator.h"

#include "qtenv.h"
#include "moduleinspector.h" // for the layer

#include <QDebug>
#include <QEventLoop>
#include <QGraphicsView>
#include <omnetpp/cfutureeventset.h>
#include <utility>

#define emit

namespace omnetpp {
namespace qtenv {

const int Animator::frameRate = 60;
const double Animator::msgEndCreep = 10;

Animator::Animator()
{
    timer.setInterval(1000 / frameRate);
    timer.setSingleShot(false);
    connect(&timer, SIGNAL(timeout()), this, SLOT(onFrameTimer()));
}

Animator::~Animator() {
    clear();
}

void Animator::redrawMessages() {
    clear();

    // this thingy is only needed if animation is going on
    if (!getQtenv()->animating)
        return;

    // loop through all messages in the event queue and display them
    cFutureEventSet *fes = getSimulation()->getFES();
    int fesLen = fes->getLength();
    for (int i = 0; i < fesLen; i++) {
        cEvent *event = fes->get(i);
        if (!event->isMessage())
            continue;
        cMessage *msg = (cMessage *)event;

        cModule *arrivalMod = msg->getArrivalModule();

        for (auto &insp : getQtenv()->getInspectors()) {
            auto moduleInsp = dynamic_cast<ModuleInspector *>(insp);
            if (!moduleInsp) {
                continue;
            }

            if (arrivalMod &&
                arrivalMod->getParentModule() == moduleInsp->getObject() &&
                msg->getArrivalGateId() >= 0)
            {
                cGate *arrivalGate = msg->getArrivalGate();

                auto messageItem = new MessageItem(moduleInsp->getAnimationLayer());
                MessageItemUtil::setupFromDisplayString(messageItem, msg, moduleInsp->getImageSizeFactor());

                // if arrivalGate is connected, msg arrived on a connection, otherwise via sendDirect()
                messageItem->setPos(arrivalGate->getPreviousGate()
                             ? moduleInsp->getConnectionLine(arrivalGate->getPreviousGate()).p2()
                             : moduleInsp->getSubmodCoords(arrivalMod));
                messageItems[std::make_pair(moduleInsp, msg)] = messageItem;
            }
        }
    }
}

void Animator::addAnimation(Animation *anim) {
    animations.push_back(anim);
}

void Animator::onFrameTimer() {
    for (auto &a : animations) {
        if (a && (a->groupIndex == 0) && a->ended()) {
            delete a;
            a = nullptr;
        }
    }

    animations.remove(nullptr);

    if (finished()) {
        emit finish();
        return;
    }

    for (auto it = animations.begin(); it != animations.end(); ++it) {
        // counting the number of animations that must be performed before *it can be started
        (*it)->groupIndex = std::count_if(animations.begin(), it, [&it](Animation *a) {
            const Animation &a1 = *a;
            const Animation &a2 = **it;

            bool sameMethod = (a1.type == Animation::ANIM_METHODCALL)
                && (a2.type == Animation::ANIM_METHODCALL)
                && (a1.text == a2.text);

            bool sameMsg = a1.msg == a2.msg;
            bool sameKind = (a1.mode == a2.mode)
                && (a1.direction == a2.direction)
                && (a1.type == a2.type);

            // the animations take place in inspectors that inspect the same module
            bool sameObject = a1.inspector->getObject() == a2.inspector->getObject();

            // user configurable in the preferences dialog
            bool concurrentEnabled = getQtenv()->getPref("concurrent-anim").value<bool>();

            // these two animations can be played at the same time
            bool concurrent = sameMethod
                || (concurrentEnabled && !sameMsg)
                || (sameMsg && sameKind && sameObject);

            // if not, we count the first into the groupIndex of the second
            return !concurrent;
        });
    }

    if (animations.empty()) {
        return;
    }

    for (auto &a : animations) {
        if (a->groupIndex == 0) { // this animation doesn't have to wait any longer
            for (auto &i : messageItems) {
                if (i.first == std::make_pair(a->inspector, a->msg)) {
                    i.second->setVisible(false);
                }
            }
            a->advance((1.0f / frameRate) * getQtenv()->opt->animationSpeed * (inHurry ? 5 : 1));
        }
    }
}

void Animator::play() {
    if (!finished()) {
        QEventLoop loop;
        timer.start();
        connect(this, SIGNAL(finish()), &loop, SLOT(quit()));
        loop.exec();
        timer.stop();
    }

    inHurry = false;
}

bool Animator::finished() {
    return std::count_if(animations.begin(), animations.end(), [](Animation *anim) { return anim && !anim->ended(); }) == 0;
}

void Animator::clear() {
    if (!finished()) {
        for (auto a : animations) {
            delete a;
        }
        animations.clear();
        emit finish();
    }
    for (auto i : messageItems) {
        delete i.second;
    }
    messageItems.clear();
}

void Animator::hurry()
{
    if (!finished())
        inHurry = true;
}

void Animator::clearInspector(ModuleInspector *insp) {
    for (auto &anim : animations) {
        if (anim->inspector == insp) {
            delete anim;
            anim = nullptr;
        }
    }
    animations.remove(nullptr);

    for (auto it = messageItems.begin(); it != messageItems.end(); /* blank */ ) {
        if ((*it).first.first == insp) {
            delete (*it).second;
            messageItems.erase(it++);
        } else {
            ++it;
        }
    }
}


void Animation::setToTime(float time) {
    this->time = time;
    float t = time/duration;

    if (ended()) {
        if (mode != ANIM_BEGIN || direction == DIR_ASCENT || direction == DIR_DESCENT) {
            if (connectionItem) connectionItem->setVisible(false);
            if (messageItem) messageItem->setVisible(false);
        }
        if (type == ANIM_SENDDIRECT && messageItem) {
            messageItem->setPos(dest);
            messageItem->setVisible(true);
        }
    } else {
        if (connectionItem
                && (type != ANIM_SENDDIRECT // respecting the preference
                    || getQtenv()->opt->showSendDirectArrows))
            connectionItem->setVisible(true);
        if (messageItem) messageItem->setVisible(true);
    }

    switch (type) {
    case ANIM_SENDDIRECT:
        if (mode == ANIM_END) {
            messageItem->setVisible((t < 0.2) || (t > 0.4 && t < 0.6) || (t > 0.8 && t < 1));
            break;
        } // if not and END - a.k.a. delivery, we just slide
    case ANIM_ON_CONN:
        messageItem->setPos((1.0f - t) * src + t * dest);
        break;
    case ANIM_METHODCALL:
        connectionItem->setDashOffset(-t * 20);
        break;
    }
}

void Animation::advance(float delta) {
    // std::min so messages won't go past their destination
    setToTime(std::min(duration, time + delta));
}

bool Animation::ended() {
    return time >= duration;
}

// this is only needed for debugging
QString Animation::info()
{
    QString typeString;
    switch (type) {
    case ANIM_ON_CONN: typeString = "on conn"; break;
    case ANIM_METHODCALL: typeString = "metdhodcall"; break;
    case ANIM_SENDDIRECT: typeString = "senddirect"; break;
    }

    QString directionString;
    switch (direction) {
    case DIR_ASCENT: directionString = "ascent"; break;
    case DIR_DESCENT: directionString = "descent"; break;
    case DIR_HORIZ: directionString = "horiz"; break;
    }

    QString modeString;
    switch (mode) {
    case ANIM_BEGIN: modeString = "begin"; break;
    case ANIM_END: modeString = "end"; break;
    case ANIM_THROUGH: modeString = "through"; break;
    }
    return typeString + " " + directionString + " " + modeString + " \"" + text + "\"";
}

Animation::Animation(ModuleInspector *insp, Animation::AnimType type, AnimDirection direction, SendAnimMode mode, QPointF src, QPointF dest, cMessage *msg, const QString &text)
    : type(type), direction(direction), mode(mode), text(text), msg(msg), inspector(insp), src(src), dest(dest)
{
    auto layer = insp->getAnimationLayer();

    if (type != ANIM_ON_CONN) {
        connectionItem = new ConnectionItem(layer);
        connectionItem->setVisible(false);
        connectionItem->setSource(src);
        connectionItem->setDestination(dest);
        connectionItem->setColor((type == ANIM_METHODCALL) ? "red" : "blue");
        connectionItem->setLineStyle(Qt::DashLine);
        connectionItem->setWidth(2);
        connectionItem->setText(text);
        connectionItem->setTextPosition(Qt::AlignCenter);
        connectionItem->setTextColor("black");
    }

    if (type != ANIM_METHODCALL) {
        messageItem = new MessageItem(layer);
        MessageItemUtil::setupFromDisplayString(messageItem, msg, insp->getImageSizeFactor());
        messageItem->setVisible(false);
        messageItem->setPos(src);
    }

    auto delta = dest - src;

               // if SENDDIRECT is in END, that's the flashing, so make it a bit quicker
    duration = (type == ANIM_SENDDIRECT) ? ((mode == ANIM_END) ? 0.5 : 1) :
               // at most 1 sec, otherwise 100 pixels/sec
               (type == ANIM_ON_CONN) ? std::min(std::sqrt(delta.x() * delta.x() + delta.y() * delta.y()) * 0.01, 1.0) :
               // it is a method call, the duration can be set in the preferences dialog (in ms units)
               getQtenv()->opt->methodCallAnimDelay / 1000.0;
}

Animation::Animation(ModuleInspector *insp, Animation::AnimType type, Animation::AnimDirection direction, const QPointF &src, const QPointF &dest, cMessage *msg, const QString &text)
    :Animation(insp, type, direction, ANIM_BEGIN, src, dest, msg, text) {
    // the delegated ctor does the job
}

Animation::~Animation() {
    delete connectionItem;
    delete messageItem;
}



void Animator::animateMethodcallAscent(ModuleInspector *insp, cModule *srcSubmod, const char *methodText)
{
    auto start = insp->getSubmodCoords(srcSubmod);
    QPointF end(start.x() + start.y() / 4, 0);
    addAnimation(new Animation(insp, Animation::ANIM_METHODCALL, Animation::DIR_ASCENT, start, end, nullptr, methodText));
}

void Animator::animateMethodcallDescent(ModuleInspector *insp, cModule *destSubmod, const char *methodText)
{
    auto end = insp->getSubmodCoords(destSubmod);
    QPointF start(end.x() - end.y() / 4, 0);
    addAnimation(new Animation(insp, Animation::ANIM_METHODCALL, Animation::DIR_DESCENT, start, end, nullptr, methodText));
}

void Animator::animateMethodcallHoriz(ModuleInspector *insp, cModule *srcSubmod, cModule *destSubmod, const char *methodText)
{
    auto start = insp->getSubmodCoords(srcSubmod);
    auto end = insp->getSubmodCoords(destSubmod);
    addAnimation(new Animation(insp, Animation::ANIM_METHODCALL, Animation::DIR_HORIZ, start, end, nullptr, methodText));
}

void Animator::animateSendOnConn(ModuleInspector *insp, cGate *srcGate, cMessage *msg, SendAnimMode mode)
{
    QLineF connLine = insp->getConnectionLine(srcGate);

    QPointF srcPos = connLine.p1();
    QPointF destPos = connLine.p2();

    if (mode == ANIM_END) {
        srcPos = connLine.p2();
        cModule *dest = srcGate->getNextGate()->getOwnerModule();
        QPointF destCenterPos = insp->getSubmodCoords(dest);
        QPointF fromEdgeToCenter = destCenterPos - connLine.p2();
        double length = std::sqrt(fromEdgeToCenter.x() * fromEdgeToCenter.x() + fromEdgeToCenter.y() * fromEdgeToCenter.y());
        ASSERT(length > 0.0); // there is a minimum bounding box size on the modules, so the edge can't be in the center
        destPos = connLine.p2() + fromEdgeToCenter / length * std::min(length, msgEndCreep);
    }

    addAnimation(new Animation(insp, Animation::ANIM_ON_CONN, Animation::DIR_HORIZ,
                               mode, srcPos, destPos, msg));
}

void Animator::animateSenddirectAscent(ModuleInspector *insp, cModule *srcSubmod, cMessage *msg)
{
    auto start = insp->getSubmodCoords(srcSubmod);
    QPointF end(start.x() + start.y() / 4, 0);
    addAnimation(new Animation(insp, Animation::ANIM_SENDDIRECT, Animation::DIR_ASCENT, start, end, msg));
}

void Animator::animateSenddirectDescent(ModuleInspector *insp, cModule *destSubmod, cMessage *msg, SendAnimMode mode)
{
    auto end = insp->getSubmodCoords(destSubmod);
    QPointF start(end.x() - end.y() / 4, 0);
    addAnimation(new Animation(insp, Animation::ANIM_SENDDIRECT, Animation::DIR_DESCENT, mode, start, end, msg));
}

void Animator::animateSenddirectHoriz(ModuleInspector *insp, cModule *srcSubmod, cModule *destSubmod, cMessage *msg, SendAnimMode mode)
{
    auto start = insp->getSubmodCoords(srcSubmod);
    auto end = insp->getSubmodCoords(destSubmod);
    addAnimation(new Animation(insp, Animation::ANIM_SENDDIRECT, Animation::DIR_HORIZ, mode, start, end, msg));
}

void Animator::animateSenddirectDelivery(ModuleInspector *insp, cModule *destSubmod, cMessage *msg)
{
    auto end = insp->getSubmodCoords(destSubmod);
    addAnimation(new Animation(insp, Animation::ANIM_SENDDIRECT, Animation::DIR_HORIZ, ANIM_END, end, end, msg));
}

} // namespace qtenv
} // namespace omnetpp
