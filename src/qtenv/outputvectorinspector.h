//==========================================================================
//  OUTPUTVECTORINSPECTOR.H - part of
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

#ifndef __OMNETPP_QTENV_OUTPUTVECTORINSPECTOR_H
#define __OMNETPP_QTENV_OUTPUTVECTORINSPECTOR_H

#include "envir/envirbase.h"
#include "inspector.h"

namespace omnetpp {
namespace qtenv {


class CircBuffer
{
   public:
      struct CBEntry {
        simtime_t t;
        double value1, value2;
      };
   protected:
      CBEntry *buf;
      int siz, n, head;
   public:
      CircBuffer( int size );
      ~CircBuffer();
      void add(simtime_t t, double value1, double value2);
      int headPos() {return head;}
      int tailPos() {return (head-n+1+siz)%siz;}
      int items() {return n;}
      int size() {return siz;}
      CBEntry& entry(int k) {return buf[k];}
};

class QTENV_API OutputVectorInspector : public Inspector
{
   public:
      CircBuffer circbuf;

   protected:
      char canvas[64];

      // configuration
      enum {DRAW_DOTS, DRAW_BARS, DRAW_PINS, DRAW_SAMPLEHOLD, DRAW_LINES, NUM_DRAWINGMODES};
      bool autoscale;
      int drawingMode;
      double miny, maxy;
      double timeScale; // x scaling: secs/10 pixel
      simtime_t hairlineTime;   // t position of moving axis

   public:
      OutputVectorInspector(QWidget *parent, bool isTopLevel, InspectorFactory *f);
      ~OutputVectorInspector();
      virtual void doSetObject(cObject *obj) override;
      virtual void refresh() override;

      // return textual information in general or about a value/value pair
      void generalInfo( char *buf );
      void valueInfo( char *buf, int valueindex );

      // configuration get (text form) / set
      void getConfig( char *buf );
      void setConfig( bool autoscale, double timef, double miny, double maxy, const char *mode);
};

} // namespace qtenv
} // namespace omnetpp


#endif


