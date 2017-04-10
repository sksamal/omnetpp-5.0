//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 1992-2005 Andras Varga
// Copyright (C) 2005-2007 Ahmet Sekercioglu
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//
// $Id: pdroptailqueue.h,v 1.1 2007/05/13 11:07:28 ahmet Exp $

#ifndef __PDROPTAILQUEUE_H
#define __PDROPTAILQUEUE_H

class PDropTailQueue : public cSimpleModule
{
  private:
    cQueue pkQueue;
    cLongHistogram qLengthStats;
    cOutVector qLengthVector;
    int pkCapacity;
    long numDiscardedPks;
    int qLength;
    bool serverIdle;
  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void finish();
    ~PDropTailQueue();
  public:
    virtual void request(); // This method is called by the server to request a packet.
};

#endif
