//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 1992-2005 Andras Varga
// Copyright (C) 2005-2013 Ahmet Sekercioglu
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//

#include <vector>
#include <omnetpp.h>
#include "packet_m.h"
#include "app_sink.h"

Define_Module(AppSink);

void AppSink::initialize()
{
  numReceived = 0;
  
  WATCH(numReceived);

  hopCountVector.setName("hopCountVector");
  hopCountStats.setName("hopCountStats");
  hopCountStats.setRangeAutoUpper(0,20,1.5);

  pkDelayVector.setName("pkDelayVector");
  pkDelayStats.setName("pkDelayStats");
  // pkDelayStats.setRangeAutoUpper(0,20,1.5);

  pkSizeStats.setName("pkSizeStats");
  // pkSizeStats.setRangeAutoUpper(0,20,1.5);
}

void AppSink::handleMessage(cMessage *msg)
{
  // Handle incoming packet
  Packet *pk = check_and_cast<Packet *>(msg);
  if (ev.isGUI()) getParentModule()->bubble("Arrived");
  numReceived++;

  // Display the number of packets received.
  char buf[40];
  sprintf(buf, "rcvd: %ld", numReceived);
  getDisplayString().setTagArg("t", 0, buf);

  ev << simTime() << " received packet " << pk->getName() << " after " << pk->getHopCount() << "hops" << endl;
  hopCountVector.record(pk->getHopCount());
  hopCountStats.collect(pk->getHopCount());
  pkDelayVector.record(simTime() - pk->getTimestamp());
  pkDelayStats.collect(simTime() - pk->getTimestamp());
  pkSizeStats.collect(pk->getBitLength());

  delete pk; pk = NULL;
}

void AppSink::finish()
{
  ev << getParentModule()->getFullName() << "." << getFullName() << ":" << endl;
  ev << "  pks. received: " << numReceived << endl;

  ev << "  hop count, min:    " << hopCountStats.getMin() << endl;
  ev << "  hop count, max:    " << hopCountStats.getMax() << endl;
  ev << "  hop count, mean:   " << hopCountStats.getMean() << endl;
  ev << "  hop count, stddev: " << hopCountStats.getStddev() << endl;

  ev << "  pk. delay, min:    " << pkDelayStats.getMin() << endl;
  ev << "  pk. delay, max:    " << pkDelayStats.getMax() << endl;
  ev << "  pk. delay, mean:   " << pkDelayStats.getMean() << endl;
  ev << "  pk. delay, stddev: " << pkDelayStats.getStddev() << endl;
  
  ev << "  pk. size, min:    " << pkSizeStats.getMin() << endl;
  ev << "  pk. size, max:    " << pkSizeStats.getMax() << endl;
  ev << "  pk. size, mean:   " << pkSizeStats.getMean() << endl;
  ev << "  pk. size, stddev: " << pkSizeStats.getStddev() << endl;
  ev << " " << endl;
  
  recordScalar("#received", numReceived);
  hopCountStats.recordAs("hop count");
  pkDelayStats.recordAs("pk delay");
  pkSizeStats.recordAs("pk size");
}
