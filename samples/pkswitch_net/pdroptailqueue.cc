//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 1992-2005 Andras Varga
// Copyright (C) 2006-2013 Ahmet Sekercioglu
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//


#include <omnetpp.h>
#include "packet_m.h"
#include "pdroptailqueue.h"

// Passive droptail queue: It does not include a built-in server, a server
// needs to be connected to its output, and only sends a packet to the server if
// the server requests it. 
Define_Module(PDropTailQueue);

PDropTailQueue::~PDropTailQueue()
{
  // Discard the remaining events (if any exists).
}

void PDropTailQueue::initialize()
{
  pkCapacity = par("pkCapacity");
  pkQueue.setName("packet_queue");
  numDiscardedPks = 0;
  qLength = pkQueue.length();
 
  WATCH(qLength);
  WATCH(numDiscardedPks);

  qLengthVector.setName("qLengthVector");
  qLengthStats.setName("qLengthStats");
  qLengthStats.setRangeAutoUpper(0,20,1.5);
}

void PDropTailQueue::handleMessage(cMessage *msg)
{
  // A packet has arrived.
  Packet *pkt=static_cast<Packet *>(msg);
  if (pkt->getBitLength() == 0) {
    // 0 length packets cause problems since they take 0 seconds to transmit.
    error("Received packet has 0 length.");
    ev << "Discarded the 0 length packet: " << pkt->getName() << endl;
    delete pkt; pkt = NULL;
    numDiscardedPks++;
  }
  qLength = pkQueue.length();
  if (qLength < pkCapacity) {
    pkQueue.insert(pkt);
    if (serverIdle) { 
      // Server previously has requested a packet but we haven't sent one
      // (we didn't have any packets to send). We can send it now.
      pkt = (Packet *) pkQueue.pop();
      send(pkt,"out");
      serverIdle = false;
    }
  } else {
    ev << "Queue overflow, packet discarded: " << pkt->getName() << endl;
    delete pkt; pkt = NULL;
    numDiscardedPks++;
  }
  qLengthStats.collect(qLength);
  qLengthVector.record(qLength);
}

void PDropTailQueue::request()
{
    Enter_Method("request()");

    if (!pkQueue.empty()) {
      cMessage *msg = (cMessage *) pkQueue.pop();
      send(msg,"out");
      serverIdle = false;
    } else {
      serverIdle = true; // Server is idle but queue does not have any packets to send.
    }
    //    if (ev.isGUI()) displayString().setTagArg("i",1, queue.empty() ? "" : "cyan");
}

void PDropTailQueue::finish()
{
  ev << getParentModule()->getFullName() << "." << getFullName() << ":" << endl;
  ev << "  queue length, min:    " << qLengthStats.getMin() << endl;
  ev << "  queue length, max:    " << qLengthStats.getMax() << endl;
  ev << "  queue length, mean:   " << qLengthStats.getMean() << endl;
  ev << "  queue length, stddev: " << qLengthStats.getStddev() << endl;
  ev << " " << endl;
  
  qLengthStats.recordAs("queue length");
  recordScalar("#discardedPks", numDiscardedPks);
}

