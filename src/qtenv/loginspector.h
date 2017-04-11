//==========================================================================
//  LOGINSPECTOR.H - part of
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

#ifndef __OMNETPP_QTENV_LOGINSPECTOR_H
#define __OMNETPP_QTENV_LOGINSPECTOR_H

#include <set>
#include "omnetpp/cmessageprinter.h"
#include "logbuffer.h"
#include "componenthistory.h"
#include "inspector.h"
#include <textviewerwidget.h>

namespace omnetpp {
namespace qtenv {

class StringTextViewerContentProvider;
class ModuleOutputContentProvider;

class QTENV_API LogInspector : public Inspector
{
    Q_OBJECT
   private:
      QAction *runUntilAction;
      QAction *fastRunUntilAction;

      QToolBar *createToolbar(bool isTopLevel);
      void addModeActions(QToolBar *toolBar);

   private slots:
      void runUntil();
      void fastRunUntil();
      void stopSimulation();
      void onFontChanged();

   public:
      enum Mode {LOG, MESSAGES};

   protected:
      static const QString PREF_COLUMNWIDTHS;
      static const QString PREF_MODE;
      static const QString PREF_SAVE_FILENAME;

      LogBuffer *logBuffer; // not owned
      ComponentHistory *componentHistory; // not owned
      TextViewerWidget *textWidget;
      std::set<int> excludedModuleIds;
      Mode mode;

      cComponent *getInspectedObject();

      bool isMatchingComponent(int componentId);
      bool isAncestorModule(int componentId, int potentialAncestorModuleId);

      QString lastFindText;
      TextViewerWidget::FindOptions lastFindOptions;

      QAction *toMessagesModeAction;
      QAction *toLogModeAction;

      QSize sizeHint() const override;

signals:
      void selectionChanged(cObject*);

   protected slots:
      void onFindButton(); // opens a dialog
      void findAgain(); // when F3 is pressed, uses the last set options
      void findAgainReverse(); // same, but in the other direction (with shift)

      void onFilterButton();
      // displays the selected message in the object inspector if in messages mode
      void onCaretMoved(int lineIndex, int column);
      void onRightClicked(QPoint globalPos, int lineIndex, int column);

      void toMessagesMode();
      void toLogMode();

      void saveColumnWidths();
      void restoreColumnWidths();

      void saveContent();

   public:
      LogInspector(QWidget *parent, bool isTopLevel, InspectorFactory *f);
      virtual ~LogInspector();
      virtual void doSetObject(cObject *obj) override;
      virtual void refresh() override;

      virtual Mode getMode() const {return mode;}
      virtual void setMode(Mode mode);
};

} // namespace qtenv
} // namespace omnetpp

#endif
