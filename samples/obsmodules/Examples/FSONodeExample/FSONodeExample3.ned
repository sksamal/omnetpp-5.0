//
// Suraj uses FSO_Node1 design and IPv4Config1.xml
//

package obsmodules.Examples.FSONodeExample;

import obsmodules.src.FSONode.FSO_Node2;
import inet.node.inet.StandardHost;
import inet.networklayer.configurator.ipv4.IPv4NetworkConfigurator;

network FSONodeExample3
{
    parameters:
        int oxcnumPorts; // Number of fibers (oxc ports)
        int lambdas; //Number of data channels per fiber port
        int servers = default(1); // Number or servers or lambdaEdge
    submodules:

        host1[servers]: StandardHost {
            parameters:
                forwarding = true;
                @display("p=154,33,ri,35");
        }

        host2[servers]: StandardHost {
            parameters:
                forwarding = true;
                @display("p=168,298,ri,25");

        }

        fso1: FSO_Node2 {
            parameters:
                lambdasPerInPort = lambdas;
                lambdasPerOutPort = lambdas;
                servernumPorts = servers;
                @display("p=359,112");
            gates:
        }
        fso2: FSO_Node2 {
            parameters:
                lambdasPerInPort = lambdas;
                lambdasPerOutPort = lambdas;
                servernumPorts = servers;
                @display("p=358,272");
            gates:
        }

        configurator: IPv4NetworkConfigurator {
            @display("p=99,189");
            config = xmldoc("IPv4Config3.xml");
        }

    connections:
        //Connections between hosts and FSO Nodes
        for i=0..sizeof(host1)-1 {
            host1[i].ethg++ <--> {  datarate = 1Gbps; } <--> fso1.ethIO++;
            host2[i].ethg++ <--> {  datarate = 1Gbps; } <--> fso2.ethIO++;
        }
//        host1.ethg++ <--> {  datarate = 1Gbps; } <--> fso1.ethIO++;
//        host2.ethg++ <--> {  datarate = 1Gbps; } <--> fso2.ethIO++;

        //Core Optical connections
        for i=0..oxcnumPorts*lambdas-1 {
            fso1.oxcout++ --> fso2.oxcin++;
            fso2.oxcout++ --> fso1.oxcin++;
        }


}
