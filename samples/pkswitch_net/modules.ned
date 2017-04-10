//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 2003-2004 Andras Varga
// Copyright (C) 2005-2013 Ahmet Sekercioglu
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//
// $Id: modules.ned,v 1.2 2007/05/13 11:07:28 ahmet Exp $

simple AppGen
{
    parameters:
        string destAddresses;
        volatile int pkSize;
        volatile double iaTime;
    gates:
        output out;
}

simple AppSink
{
    gates:
        input in;
}

simple NetworkLayer
{
    gates:
        input in[];
        output out[];
        input localIn;
        output localOut;
}

simple PDropTailQueue
{
    parameters:
        int pkCapacity;
    gates:
        input in;
        output out;
}

simple Server
{
    gates:
        input in;
        output out;
}

