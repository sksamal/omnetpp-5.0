/*
 * txc13.cc
 *
 *  Created on: Aug 10, 2011
 *      Author: alex
 */

//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 2003 Ahmet Sekercioglu
// Copyright (C) 2003-2004 Andras Varga
// Copyright (C) 2005 Brett Pentland
// Updated by Alexander Senior 2011.
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//
// $Id: txc13.cc,v 1.2 2005/09/29 00:00:11 ahmet Exp ahmet $

#include <stdio.h>
#include <string.h>
#include <omnetpp.h>
#include "tictoc13_m.h"

class Txc13 : public cSimpleModule
{
  protected:
    long numSent;
    long numReceived;
    cLongHistogram hopCountStats;
    cOutVector hopCountVector;
    int rt[6];

  public:
    virtual TicTocMsg13 *generateMessage();
    virtual void forwardMessage(TicTocMsg13 *msg);
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void finish();
};

Define_Module(Txc13);

void Txc13::initialize()
{
  // Initialize variables
  numSent = 0;
  numReceived = 0;
  WATCH(numSent);
  WATCH(numReceived);

  // Initialize the routing table
  rt[0] = par("route0");
  rt[1] = par("route1");
  rt[2] = par("route2");
  rt[3] = par("route3");
  rt[4] = par("route4");
  rt[5] = par("route5");

  hopCountStats.setName("hopCountStats");
  hopCountStats.setRangeAutoUpper(0, 10, 1.5);
  hopCountVector.setName("HopCount");

  // Module 0 sends the first message
  if (getIndex()==0)
    {
      // Boot the process scheduling the initial message as a self-message.
      TicTocMsg13 *msg = generateMessage();
      scheduleAt(0.0, msg);
    }
}

void Txc13::handleMessage(cMessage *msg)
{
  TicTocMsg13 *ttmsg = check_and_cast<TicTocMsg13 *>(msg);

  if (ttmsg->getDestination()==getIndex())  {
    // Message arrived
    int hopcount = ttmsg->getHopCount();
    ev << "Message " << ttmsg << " arrived after " << hopcount << " hops.\n";
    bubble("ARRIVED, starting new one!");

    // update statistics.
    numReceived++;
    hopCountVector.record(hopcount);
    hopCountStats.collect(hopcount);

    delete ttmsg;

    // Generate another one.
    ev << "Generating another message: ";
    TicTocMsg13 *newmsg = generateMessage();
    ev << newmsg << endl;
    forwardMessage(newmsg);
    numSent++;
  } else {
    // We need to forward the message.
    forwardMessage(ttmsg);
  }
}

void Txc13::finish()
{
  // This function is called by OMNeT++ at the end of the simulation.
  ev << "Sent:     " << numSent << endl;
  ev << "Received: " << numReceived << endl;
  ev << "Hop count, min:    " << hopCountStats.getMin() << endl;
  ev << "Hop count, max:    " << hopCountStats.getMax() << endl;
  ev << "Hop count, mean:   " << hopCountStats.getMean() << endl;
  ev << "Hop count, stddev: " << hopCountStats.getStddev() << endl;

  recordScalar("#sent", numSent);
  recordScalar("#received", numReceived);
  hopCountStats.recordAs("hop count");
}

TicTocMsg13 *Txc13::generateMessage()
{
  // Produce source and destination addresses.
  int src = getIndex();
  int n = size();
  int dest = intuniform(0,n-2);
  if (dest>=src) dest++;

  char msgname[20];
  sprintf(msgname, "tic-%d-to-%d", src, dest);

  // Create message object and set source and destination field.
  TicTocMsg13 *msg = new TicTocMsg13(msgname);
  msg->setSource(src);
  msg->setDestination(dest);
  return msg;
}

void Txc13::forwardMessage(TicTocMsg13 *msg)
{
  // Increment hop count.
  msg->setHopCount(msg->getHopCount()+1);

  // Gate selection from routing table.
  TicTocMsg13 *ttmsg = check_and_cast<TicTocMsg13 *>(msg);
  int k = rt[ttmsg->getDestination()];

  ev << "Forwarding message " << msg << " on port out[" << k << "]\n";
  send(msg, "out", k);
}


