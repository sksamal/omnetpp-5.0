//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 1992-2008 Andras Varga
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//


//
// Implements deflection routing in a Hypercube network
//

package fattree.components;
import inet.networklayer.common.InterfaceTable;


module TRouter
{
    parameters:
        int address;
        int dim;
        @display("i=block/switch");

    gates:
        inout in[];
        inout out[];
        
 	submodules:
    	interfaceTable: InterfaceTable {
        	 parameters:
                @display("p=57,134");
        }
}


