//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 1992-2005 Andras Varga
// Copyright (C) 2005-2007 Ahmet Sekercioglu
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//
// $Id: app_gen.h,v 1.3 2013/06/11 06:10:42 ahmet Exp $

#ifndef __APPGEN_H
#define __APPGEN_H

class AppGen : public cSimpleModule
{
  private:
    int pkSize;
    simtime_t iaTime;

    // Statistics
    long numSent;

    std::vector<int> destAddresses;
    cMessage *timeToGenerateAPacket;

  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void finish();
};

#endif
