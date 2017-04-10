//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 2003-2004 Andras Varga
// Copyright (C) 2005-2013 Ahmet Sekercioglu
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//

channel lanlink extends ned.DatarateChannel
{
    parameters:
        delay = 0.01ms;
        datarate = 100000000bps; // bits/sec
}

channel wanlink extends ned.DatarateChannel
{
    parameters:
        delay = 5ms;
        datarate = 1000000bps; // bits/sec
}

network pkswitch_net
{
    submodules:
        host[4]: Host {
            parameters:
                address = index;
                @display("i=device/pc2");
        }
        router[2]: Router {
            parameters:
                address = index+sizeof(host);
                @display("i=abstract/router");
        }
    connections:
        host[0].out++ --> lanlink --> router[0].in++;
        host[0].in++ <-- lanlink <-- router[0].out++;

        host[1].out++ --> lanlink --> router[0].in++;
        host[1].in++ <-- lanlink <-- router[0].out++;

        router[0].out++ --> wanlink --> router[1].in++;
        router[0].in++ <-- wanlink <-- router[1].out++;

        host[2].out++ --> lanlink --> router[1].in++;
        host[2].in++ <-- lanlink <-- router[1].out++;

        host[3].out++ --> lanlink --> router[1].in++;
        host[3].in++ <-- lanlink <-- router[1].out++;
}


