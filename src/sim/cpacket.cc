//========================================================================
//  CPACKET.CC - part of
//                 OMNeT++/OMNEST
//              Discrete System Simulation in C++
//
//  Author: Andras Varga
//
//========================================================================

/*--------------------------------------------------------------*
  Copyright (C) 1992-2015 Andras Varga
  Copyright (C) 2006-2015 OpenSim Ltd.

  This file is distributed WITHOUT ANY WARRANTY. See the file
  `license' for details on this and other legal matters.
*--------------------------------------------------------------*/

#include <sstream>
#include "omnetpp/globals.h"
#include "omnetpp/cpacket.h"
#include "omnetpp/csimplemodule.h"
#include "omnetpp/platdep/platmisc.h"  // INT64_PRINTF_FORMAT

#ifdef WITH_PARSIM
#include "omnetpp/ccommbuffer.h"
#endif

using namespace omnetpp;

using std::ostream;

// comment out to disable reference-counting for encapsulated messages
#define REFCOUNTING

Register_Class(cPacket);

cPacket::cPacket(const cPacket& pkt) : cMessage(pkt)
{
    encapsulatedPacket = nullptr;
    shareCount = 0;
    copy(pkt);
}

cPacket::cPacket(const char *name, short k, int64_t l) : cMessage(name, k)
{
    bitLength = l;
    encapsulatedPacket = nullptr;
    duration = 0;
    shareCount = 0;
}

cPacket::~cPacket()
{
    if (encapsulatedPacket)
#ifdef REFCOUNTING
        _deleteEncapMsg();
#else
        dropAndDelete(encapsulatedPacket);
#endif
}

std::string cPacket::info() const  //FIXME revise
{
//    if (tomod<0)
//        return std::string("(new msg)");

    std::stringstream out;
//    const char *deletedstr = "<deleted module>";
//
//    if (delivd > simTime())
//    {
//        // if it arrived in the past, dt is usually unimportant, don't print it
//        out << "at t=" << delivd << ", in dt=" << (delivd - simTime()) << "; ";
//    }
//
//#define MODNAME(modp) ((modp) ? (modp)->getFullPath().c_str() : deletedstr)
//    if (getKind()==MK_STARTER)
//    {
//        cModule *tomodp = getSimulation()->getModule(tomod);
//        out << "starter for " << MODNAME(tomodp) << " (id=" << tomod << ") ";
//    }
//    else if (getKind()==MK_TIMEOUT)
//    {
//        cModule *tomodp = getSimulation()->getModule(tomod);
//        out << "timeoutmsg for " << MODNAME(tomodp) << " (id=" << tomod << ") ";
//    }
//    else if (frommod==tomod)
//    {
//        cModule *tomodp = getSimulation()->getModule(tomod);
//        out << "selfmsg for " << MODNAME(tomodp) << " (id=" << tomod << ") ";
//    }
//    else
//    {
//        cModule *frommodp = getSimulation()->getModule(frommod);
//        cModule *tomodp = getSimulation()->getModule(tomod);
//        out << "src=" << MODNAME(frommodp) << " (id=" << frommod << ") ";
//        out << " dest=" << MODNAME(tomodp) << " (id=" << tomod << ") ";
//    }
//#undef MODNAME
//
//    if (encapmsg)
//        // #ifdef REFCOUNTING const_cast<cPacket *>(this)->_detachEncapMsg();  // see _detachEncapMsg() comment why this might be needed
//        out << "  encapsulates: (" << encapmsg->getClassName() << ")" << encapmsg->getFullName();
//
//    if (ctrlp)
//        out << "  control info: (" << ctrlp->getClassName() << ") " << ctrlp->getFullName() << "\n";
//
    return out.str();
}

void cPacket::forEachChild(cVisitor *v)
{
    cMessage::forEachChild(v);

    if (encapsulatedPacket) {
#ifdef REFCOUNTING
        _detachEncapMsg();  // see method comment why this is needed
#endif
        v->visit(encapsulatedPacket);
    }
}

std::string cPacket::detailedInfo() const
{
    return "";  // all fields are available via reflection, no point in repeating them here
}

void cPacket::parsimPack(cCommBuffer *buffer) const
{
#ifndef WITH_PARSIM
    throw cRuntimeError(this, E_NOPARSIM);
#else
    cMessage::parsimPack(buffer);
    buffer->pack(bitLength);
    buffer->pack(duration);
    if (buffer->packFlag(encapsulatedPacket != nullptr))
        buffer->packObject(encapsulatedPacket);
#endif
}

void cPacket::parsimUnpack(cCommBuffer *buffer)
{
#ifndef WITH_PARSIM
    throw cRuntimeError(this, E_NOPARSIM);
#else
    ASSERT(shareCount == 0);
    cMessage::parsimUnpack(buffer);
    buffer->unpack(bitLength);
    buffer->unpack(duration);
    if (buffer->checkFlag())
        take(encapsulatedPacket = (cPacket *)buffer->unpackObject());
#endif
}

cPacket& cPacket::operator=(const cPacket& msg)
{
    if (this == &msg)
        return *this;
    cMessage::operator=(msg);
    copy(msg);
    return *this;
}

void cPacket::copy(const cPacket& msg)
{
#ifdef REFCOUNTING
    if (shareCount != 0)
        throw cRuntimeError(this, "operator=(): this message is refcounted (shared between "
                                  "several messages), it is forbidden to change it");
#endif

    bitLength = msg.bitLength;
    duration = msg.duration;

#ifndef REFCOUNTING
    dropAndDelete(encapsulatedPacket);
    if (msg.encapsulatedPacket)
        take(encapsulatedPacket = (cPacket *)msg.encapsulatedPacket->dup());
    else
        encapsulatedPacket = nullptr;
#else
    if (encapsulatedPacket)
        _deleteEncapMsg();
    encapsulatedPacket = msg.encapsulatedPacket;
    if (encapsulatedPacket && ++encapsulatedPacket->shareCount == 0) {  // sharecount overflow
        --encapsulatedPacket->shareCount;
        take(encapsulatedPacket = (cPacket *)encapsulatedPacket->dup());
    }
#endif
}

#ifdef REFCOUNTING
void cPacket::_deleteEncapMsg()
{
    if (encapsulatedPacket->shareCount > 0) {
        encapsulatedPacket->shareCount--;
        if (encapsulatedPacket->owner == this)
            encapsulatedPacket->owner = nullptr;
    }
    else {
        // note: dropAndDelete(encapmsg) cannot be used, because due to sharecounting
        // ownerp is not valid (may be any former owner, possibly deleted since then)
        encapsulatedPacket->owner = nullptr;
        delete encapsulatedPacket;
    }
}

#endif

#ifdef REFCOUNTING
void cPacket::_detachEncapMsg()
{
    if (encapsulatedPacket->shareCount > 0) {
        // "de-share" object - create our own copy
        encapsulatedPacket->shareCount--;
        if (encapsulatedPacket->owner == this)
            encapsulatedPacket->owner = nullptr;
        take(encapsulatedPacket = (cPacket *)encapsulatedPacket->dup());
    }
    else {
        // note: due to sharecounting, ownerp may be pointing to a previous owner -- fix it
        encapsulatedPacket->owner = this;
    }
}

#endif

void cPacket::setBitLength(int64_t l)
{
    if (l < 0)
        throw cRuntimeError(this, "setBitLength(): negative length %" INT64_PRINTF_FORMAT "d", l);
    bitLength = l;
}

void cPacket::addBitLength(int64_t l)
{
    bitLength += l;
    if (bitLength < 0)
        throw cRuntimeError(this, "addBitLength(): length became negative (%" INT64_PRINTF_FORMAT ") after adding %" INT64_PRINTF_FORMAT "d", bitLength, l);
}

void cPacket::encapsulate(cPacket *msg)
{
    if (encapsulatedPacket)
        throw cRuntimeError(this, "encapsulate(): another message already encapsulated");

    if (msg) {
        if (msg->getOwner() != getSimulation()->getContextSimpleModule())
            throw cRuntimeError(this, "encapsulate(): not owner of message (%s)%s, owner is (%s)%s",
                    msg->getClassName(), msg->getFullName(),
                    msg->getOwner()->getClassName(), msg->getOwner()->getFullPath().c_str());
        take(encapsulatedPacket = msg);
#ifdef REFCOUNTING
        ASSERT(encapsulatedPacket->shareCount == 0);
#endif
        bitLength += encapsulatedPacket->bitLength;
        transferTagsFrom(msg);
    }
}

cPacket *cPacket::decapsulate()
{
    if (!encapsulatedPacket)
        return nullptr;
    if (bitLength > 0)
        bitLength -= encapsulatedPacket->bitLength;
    if (bitLength < 0)
        throw cRuntimeError(this, "decapsulate(): packet length is smaller than encapsulated packet");

#ifdef REFCOUNTING
    if (encapsulatedPacket->shareCount > 0) {
        encapsulatedPacket->shareCount--;
        if (encapsulatedPacket->owner == this)
            encapsulatedPacket->owner = nullptr;
        cPacket *msg = encapsulatedPacket->dup();
        encapsulatedPacket = nullptr;
        msg->transferTagsFrom(this);
        return msg;
    }
    encapsulatedPacket->owner = this;
#endif
    cPacket *msg = encapsulatedPacket;
    encapsulatedPacket = nullptr;
    drop(msg);
    msg->transferTagsFrom(this);
    return msg;
}

cPacket *cPacket::getEncapsulatedPacket() const
{
#ifdef REFCOUNTING
    // encapmsg may be shared (sharecount>0) -- we'll make our own copy,
    // so that other messages are not affected in case the user modifies
    // the encapsulated message via the returned pointer.
    // Trick: this is a const method, so we can only do changes via a
    // non-const copy of the 'this' pointer.
    if (encapsulatedPacket)
        const_cast<cPacket *>(this)->_detachEncapMsg();
#endif
    return encapsulatedPacket;
}

bool cPacket::hasEncapsulatedPacket() const
{
    return encapsulatedPacket != nullptr;
}

long cPacket::getEncapsulationId() const
{
    // find innermost msg. Note: don't use getEncapsulatedPacket() because it does copy-on-touch of shared msgs
    const cPacket *msg = this;
    while (msg->encapsulatedPacket)
        msg = msg->encapsulatedPacket;
    return msg->getId();
}

long cPacket::getEncapsulationTreeId() const
{
    // find innermost msg. Note: don't use getEncapsulatedPacket() because it does copy-on-touch of shared msgs
    const cPacket *msg = this;
    while (msg->encapsulatedPacket)
        msg = msg->encapsulatedPacket;
    return msg->getTreeId();
}

