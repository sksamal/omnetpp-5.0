//==========================================================================
//  GATEINSPECTOR.H - part of
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

#ifndef __OMNETPP_QTENV_GATEINSPECTOR_H
#define __OMNETPP_QTENV_GATEINSPECTOR_H

#include "inspector.h"

namespace omnetpp {
namespace qtenv {

class QTENV_API GateInspector : public Inspector
{
   protected:
      char canvas[128];

   protected:
      virtual void doSetObject(cObject *obj) override;

   public:
      GateInspector(QWidget *parent, bool isTopLevel, InspectorFactory *f);
      virtual void refresh() override;
      virtual void redraw() override;

      // notifications from envir:
      virtual void displayStringChanged(cGate *gate);
};

} // namespace qtenv
} // namespace omnetpp

#endif
