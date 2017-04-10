//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 1992-2005 Andras Varga
// Copyright (C) 2005-2007 Ahmet Sekercioglu
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//
// $Id: server.cc,v 1.1 2007/05/13 11:07:28 ahmet Exp $

#include <omnetpp.h>
#include "packet_m.h"
#include "pdroptailqueue.h"
#include "server.h"

Define_Module(Server);

Server::~Server()
{
  // Discard the remaining event (if it exists).
  cancelAndDelete(timeToXmtAPacket);
}

void Server::initialize()
{
  // Self-message to notify ourselves when transmission of a packet is completed.
  timeToXmtAPacket = new cMessage("timeToXmtAPacket");

  // Passive queue module connected to this server. 
  passiveQueue = new PDropTailQueue;
  if (!gate("in")->isConnected()) {
    error("Server does not have a queue connected.");
  }
  passiveQueue = check_and_cast<PDropTailQueue *> (gate("in")->getPreviousGate()->getOwnerModule());

  // Let's request our first packet.
  scheduleAt(simTime(), timeToXmtAPacket);
}

void Server::handleMessage(cMessage *msg)
{
  if (msg == timeToXmtAPacket) { // Channel has just finished transmitting a packet.
    // Request a packet from the passive queue connected.
    passiveQueue->request(); 
  } else {
    // A packet has arrived.
    // We should never get one when the transmission line is busy transmitting.
    ASSERT(!(gate("out")->getNextGate()->getTransmissionChannel()->isBusy()));
    send(msg,"out");
    // Notify ourselves the moment the transmission line finishes transmitting the packet.
    scheduleAt(gate("out")->getNextGate()->getTransmissionChannel()->getTransmissionFinishTime(), timeToXmtAPacket);
  }
}


