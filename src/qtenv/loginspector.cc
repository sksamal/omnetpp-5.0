//==========================================================================
//  LOGINSPECTOR.CC - part of
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

#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <QToolBar>
#include <QAction>
#include <QToolButton>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QDebug>
#include <QMenu>

#include "common/stringtokenizer.h"
#include "loginspector.h"
#include "qtenv.h"
#include "qtutil.h"
#include "inspectorutil.h"
#include "mainwindow.h"
#include "inspectorfactory.h"
#include "logfinddialog.h"
#include "logfilterdialog.h"
#include "textviewerproviders.h"

using namespace omnetpp::common;

namespace omnetpp {
namespace qtenv {

#define LL    INT64_PRINTF_FORMAT

void _dummy_for_loginspector() {}

class LogInspectorFactory : public InspectorFactory
{
  public:
    LogInspectorFactory(const char *name) : InspectorFactory(name) {}

    bool supportsObject(cObject *obj) override { return dynamic_cast<cComponent*>(obj) != nullptr; }
    int getInspectorType() override { return INSP_MODULEOUTPUT; }
    double getQualityAsDefault(cObject *object) override { return 0.5; }
    Inspector *createInspector(QWidget *parent, bool isTopLevel) override { return new LogInspector(parent, isTopLevel, this); }
};

Register_InspectorFactory(LogInspectorFactory);

LogInspector::LogInspector(QWidget *parent, bool isTopLevel, InspectorFactory *f)
    : Inspector(parent, isTopLevel, f) {
    logBuffer = getQtenv()->getLogBuffer();

    componentHistory = getQtenv()->getComponentHistory();

    auto layout = new QGridLayout(this);
    layout->setMargin(0);
    layout->setSpacing(0);

    textWidget = new TextViewerWidget(this);
    textWidget->setFont(getQtenv()->getLogFont());
    QToolBar *toolBar = createToolbar(isTopLevel);
    if(isTopLevel)
        layout->addWidget(toolBar);

    layout->addWidget(textWidget);
    connect(textWidget, SIGNAL(caretMoved(int,int)), this, SLOT(onCaretMoved(int, int)));
    connect(textWidget, SIGNAL(rightClicked(QPoint,int,int)), this, SLOT(onRightClicked(QPoint,int, int)));
    parent->setMinimumSize(100, 50); // caution: too small widget height with heading displayed may cause notification loop!

    /*
    stringContent = new StringTextViewerContentProvider(
                       "Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n"
                       "Quisque eget dolor pharetra, fermentum lectus ac, luctus enim.\n"
                       "Vestibulum maximus nulla molestie bibendum vehicula.\n"
                       "Sed a augue vel ipsum pretium laoreet sit amet quis turpis.\n"
                       "Praesent ut felis ornare, convallis mauris ac, viverra justo.\n"
                       "Fusce id lacus sodales, vestibulum sem tempus, placerat diam.\n"
                       "Nullam suscipit justo vitae tristique blandit.\n"
                       "Duis non purus congue, pulvinar erat quis, tristique nibh.\n"
                       "Integer a lorem vitae tortor elementum facilisis quis ut orci.\n");
    */

    QAction *findAgainAction = new QAction(this);
    findAgainAction->setShortcut(Qt::Key_F3);
    connect(findAgainAction, SIGNAL(triggered()), this, SLOT(findAgain()));
    addAction(findAgainAction);

    QAction *findAgainReverseAction = new QAction(this);
    findAgainReverseAction->setShortcut(Qt::ShiftModifier + Qt::Key_F3);
    connect(findAgainReverseAction, SIGNAL(triggered()), this, SLOT(findAgainReverse()));
    addAction(findAgainReverseAction);

    connect(getQtenv(), SIGNAL(fontChanged()), this, SLOT(onFontChanged()));

    setMode(LOG);
}

LogInspector::~LogInspector() {
    if (mode == MESSAGES) {
        saveColumnWidths();
    }
}

void LogInspector::onFontChanged()
{
    textWidget->setFont(getQtenv()->getLogFont());
}

const QString LogInspector::PREF_COLUMNWIDTHS = "columnwidths";
const QString LogInspector::PREF_MODE = "mode";
const QString LogInspector::PREF_SAVE_FILENAME = "savefilename";

QToolBar *LogInspector::createToolbar(bool isTopLevel)
{
    QToolBar *toolBar = new QToolBar();
    if(isTopLevel)
    {
        addTopLevelToolBarActions(toolBar);

        toolBar->addSeparator();
        toolBar->addAction(QIcon(":/tools/icons/tools/copy.png"), "Copy selected text to clipboard (Ctrl+C)",
                           textWidget, SLOT(copySelection()))->setShortcut(Qt::ControlModifier + Qt::Key_C);
        toolBar->addAction(QIcon(":/tools/icons/tools/find.png"), "Find string in window (Ctrl+F)",
                           this, SLOT(onFindButton()))->setShortcut(Qt::ControlModifier + Qt::Key_F);
        toolBar->addAction(QIcon(":/tools/icons/tools/save.png"), "Save window contents to file",
                           this, SLOT(saveContent()));
        toolBar->addAction(QIcon(":/tools/icons/tools/filter.png"), "Filter window contents (Ctrl+H)",
                           this, SLOT(onFilterButton()))->setShortcut(Qt::ControlModifier + Qt::Key_H);

        toolBar->addSeparator();
        addModeActions(toolBar);

        toolBar->addSeparator();
        runUntilAction = toolBar->addAction(QIcon(":/tools/icons/tools/mrun.png"), "Run until next event in this module", this,
                                            SLOT(runUntil()));
        runUntilAction->setCheckable(true);

        fastRunUntilAction = toolBar->addAction(QIcon(":/tools/icons/tools/mfast.png"), "Fast run until next event in this module (Ctrl+F4)",
                                                this, SLOT(fastRunUntil()));
        fastRunUntilAction->setCheckable(true);
        fastRunUntilAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_4));

        toolBar->addAction(QIcon(":/tools/icons/tools/stop.png"), "Stop the simulation (F8)", this, SLOT(stopSimulation()))->setShortcut(
                    QKeySequence(Qt::Key_F8));
    }
    else
    {
        toolBar->addAction(QIcon(":/tools/icons/tools/copy.png"), "Copy selected text to clipboard (Ctrl+C)",
                           textWidget, SLOT(copySelection()))->setShortcut(Qt::ControlModifier + Qt::Key_C);
        toolBar->addAction(QIcon(":/tools/icons/tools/find.png"), "Find string in window (Ctrl+F)",
                           this, SLOT(onFindButton()))->setShortcut(Qt::ControlModifier + Qt::Key_F);
        toolBar->addAction(QIcon(":/tools/icons/tools/filter.png"), "Filter window contents (Ctrl+H)",
                           this, SLOT(onFilterButton()))->setShortcut(Qt::ControlModifier + Qt::Key_H);

        addModeActions(toolBar);

        textWidget->setToolBar(toolBar);
    }

    return toolBar;
}

//void LogInspector::setSunkenRunUntil(bool isSunken)
//{
//    runUntilAction->setChecked(isSunken);
//}

void LogInspector::addModeActions(QToolBar *toolBar)
{
    toMessagesModeAction = new QAction(toolBar);
    toMessagesModeAction->setCheckable(true);
    toMessagesModeAction->setIcon(QIcon(":/tools/icons/tools/pkheader.png"));
    toMessagesModeAction->setText("Show message/packet traffic");
    connect(toMessagesModeAction, SIGNAL(triggered()), this, SLOT(toMessagesMode()));
    toolBar->addAction(toMessagesModeAction);

    toLogModeAction = new QAction(toolBar);
    toLogModeAction->setCheckable(true);
    toLogModeAction->setIcon(QIcon(":/tools/icons/tools/log.png"));
    toLogModeAction->setText("Show log");
    connect(toLogModeAction, SIGNAL(triggered()), this, SLOT(toLogMode()));
    toolBar->addAction(toLogModeAction);
}

void LogInspector::setMode(Mode m) {
    if (mode == MESSAGES) {
        saveColumnWidths();
    }

    switch (m) {
    case LOG:
        toLogModeAction->setChecked(true);
        toMessagesModeAction->setChecked(false);
        textWidget->setContentProvider(new ModuleOutputContentProvider(getQtenv(), getInspectedObject(), LOG));
        break;
    case MESSAGES:
        toMessagesModeAction->setChecked(true);
        toLogModeAction->setChecked(false);
        textWidget->setContentProvider(new ModuleOutputContentProvider(getQtenv(), getInspectedObject(), MESSAGES));
        break;
    }

    mode = m;

    if (mode == MESSAGES) {
        restoreColumnWidths();
    }

    setPref(PREF_MODE, mode);
}

void LogInspector::doSetObject(cObject *obj)
{
    Inspector::doSetObject(obj);
    setMode((Mode)getPref(PREF_MODE, getMode()).toInt());
}

cComponent *LogInspector::getInspectedObject()
{
    return static_cast<cComponent*>(object);
}

QSize LogInspector::sizeHint() const
{
    return QSize(700, 300);
}

void LogInspector::runUntil()
{
    runUntilAction->setEnabled(false);
    getQtenv()->runSimulationLocal(qtenv::Qtenv::eRunMode::RUNMODE_NORMAL, nullptr, this);
    runUntilAction->setChecked(false);
    runUntilAction->setEnabled(true);
}

void LogInspector::fastRunUntil()
{
    fastRunUntilAction->setEnabled(false);
    getQtenv()->runSimulationLocal(qtenv::Qtenv::eRunMode::RUNMODE_FAST, nullptr, this);
    fastRunUntilAction->setChecked(false);
    fastRunUntilAction->setEnabled(true);
}

void LogInspector::stopSimulation()
{
    MainWindow *mainWindow = getQtenv()->getMainWindow();
    mainWindow->on_actionStop_triggered();
}

void LogInspector::refresh() {
    Inspector::refresh();
    textWidget->onContentChanged();
    textWidget->update();
    textWidget->viewport()->update();
}


void LogInspector::onFindButton() {
    auto dialog = new LogFindDialog(this, lastFindText, lastFindOptions);
    if (dialog->exec() == QDialog::Accepted) {
        lastFindText = dialog->getText();
        lastFindOptions = dialog->getOptions();
        if (!lastFindText.isEmpty())
            textWidget->find(lastFindText, lastFindOptions);
    }
    delete dialog;
}

void LogInspector::onFilterButton() {
    auto dialog = new LogFilterDialog(this, dynamic_cast<cModule *>(getInspectedObject()), excludedModuleIds);
    if (dialog->exec() == QDialog::Accepted) {
        excludedModuleIds = dialog->getExcludedModuleIds();
        auto provider = dynamic_cast<ModuleOutputContentProvider *>(textWidget->getContentProvider());
        if (provider) {
            provider->setExcludedModuleIds(excludedModuleIds);
        }
        textWidget->onContentChanged();
    }
    delete dialog;
}

void LogInspector::onCaretMoved(int lineIndex, int column) {
    auto msg = (cMessage*)textWidget->getContentProvider()->getUserData(lineIndex);
    if (msg)
        emit selectionChanged(msg);
}

void LogInspector::onRightClicked(QPoint globalPos, int lineIndex, int column) {
    auto msg = (cMessage*)textWidget->getContentProvider()->getUserData(lineIndex);
    if (msg) {
        QMenu *menu = InspectorUtil::createInspectorContextMenu(msg, this);
        menu->exec(globalPos);
    }
}

void LogInspector::findAgain() {
    if (!lastFindText.isEmpty())
        textWidget->find(lastFindText, lastFindOptions);
}

void LogInspector::findAgainReverse() {
    if (!lastFindText.isEmpty())
        textWidget->find(lastFindText, lastFindOptions ^ TextViewerWidget::FIND_BACKWARDS);
}

void LogInspector::toMessagesMode() {
    setMode(MESSAGES);
}

void LogInspector::toLogMode() {
    setMode(LOG);
}

void LogInspector::saveColumnWidths() {
    auto widths = textWidget->getColumnWidths();
    if (!widths.isEmpty() && std::all_of(widths.begin(), widths.end(),
                                         [](const QVariant &v){ return v.isValid(); } )) {
        setPref(PREF_COLUMNWIDTHS, widths);
    }
}

void LogInspector::restoreColumnWidths() {
        textWidget->setColumnWidths(getPref(PREF_COLUMNWIDTHS, QList<QVariant>()).toList());
}

void LogInspector::saveContent()
{
    QString fileName = getPref(PREF_SAVE_FILENAME, "omnetpp.out").toString();
    fileName = QFileDialog::getSaveFileName(this, tr("Save Log Window Contents"), "/home/jana/" + fileName,
                                                    tr("Log files (*.out);;All files (*)"));

    int lineNumber = textWidget->getContentProvider()->getLineCount();

    QFile file(fileName);
    if (fileName.isEmpty() || !file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);

    for(int i = 0; i < lineNumber; ++i)
        out << textWidget->getContentProvider()->getLineText(i);

    file.close();
    setPref(PREF_SAVE_FILENAME, fileName.split(QDir::separator()).last());
}

} // namespace qtenv
} // namespace omnetpp

