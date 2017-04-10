//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 1992-2005 Andras Varga
// Copyright (C) 2005 Ahmet Sekercioglu
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//
// $Id: app_sink.h,v 1.1 2007/05/13 11:07:28 ahmet Exp $

#ifndef __APPSINK_H
#define __APPSINK_H

class AppSink : public cSimpleModule
{
  private:
    // Statistics
    long numReceived;
    cLongHistogram hopCountStats;
    cOutVector hopCountVector;
    cDoubleHistogram pkDelayStats;
    cOutVector pkDelayVector;
    cLongHistogram pkSizeStats;

  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void finish();
};

#endif
