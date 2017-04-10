//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 2003-2004 Andras Varga
// Copyright (C) 2005-2013 Ahmet Sekercioglu
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//


module Host
{
    parameters:
        int address;
        string destAddressList; // list of destination host addresses,
                                 // separated by space. E.g. "1 3 9"
    gates:
        input in[];
        output out[];
    submodules:
        app_gen: AppGen {
            parameters:
                destAddresses = destAddressList;
                @display("p=82,88;i=block/source");
        }
        app_sink: AppSink {
            parameters:
                @display("p=160,88;i=block/sink");
        }
        network_layer: NetworkLayer {
            parameters:
                @display("p=117,168;i=block/switch");
            gates:
                in[sizeof(in)];
                out[sizeof(out)];
        }
        pk_queue[sizeof(out)]: PDropTailQueue {
            parameters:
                @display("p=55,224;i=block/passiveq;q=packet_queue");
        }
        server[sizeof(out)]: Server {
            parameters:
                @display("p=51,300,c,60;i=block/server");
        }
    connections:
        network_layer.localOut --> app_sink.in;
        network_layer.localIn <-- app_gen.out;
        for i=0..sizeof(in)-1 {
            network_layer.out[i] --> pk_queue[i].in;
            pk_queue[i].out --> server[i].in;
            server[i].out --> { @display("m=s"); } --> out[i];
            network_layer.in[i] <-- { @display("m=s"); } <-- in[i];
        }
}

