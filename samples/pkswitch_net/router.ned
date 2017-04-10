//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 2003-2004 Andras Varga
// Copyright (C) 2005-2013 Ahmet Sekercioglu
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//

module Router
{
    parameters:
        int address;
        @display("bgb=328,186");
    gates:
        input in[];
        output out[];
    submodules:
        network_layer: NetworkLayer {
            parameters:
                // See Section 9.1.2 (Submodule display strings) of the user manual
                // for details on the use of display strings.
                @display("p=70,96;i=block/switch");
            gates:
                in[sizeof(in)];
                out[sizeof(out)];
        }
        pk_queue[sizeof(out)]: PDropTailQueue {
            parameters:
                @display("p=170,36,column,60;i=block/passiveq;q=packet_queue");
        }
        server[sizeof(out)]: Server {
            parameters:
                @display("p=270,36,column,60;i=block/server");
        }
    connections allowunconnected:
        for i=0..sizeof(in)-1 {
            network_layer.out[i] --> pk_queue[i].in;
            pk_queue[i].out --> server[i].in;
            server[i].out --> { @display("m=e"); } --> out[i];
            network_layer.in[i] <-- { @display("m=w,,,48,0"); } <-- in[i];
        }
}

