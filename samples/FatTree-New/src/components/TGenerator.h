//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 1992-2008 Andras Varga
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//


#ifndef __TGENERATOR_H_
#define __TGENERATOR_H_

#include <omnetpp.h>
using namespace omnetpp;

#define STACKSIZE 16384

/**
 * Packet generator; see NED file for more info.
 */
class TGenerator : public cSimpleModule
{
  public:
    TGenerator() : cSimpleModule(STACKSIZE) {}
    virtual void activity();
};

#endif

