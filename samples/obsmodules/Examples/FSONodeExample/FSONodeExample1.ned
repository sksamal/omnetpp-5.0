//
// Suraj uses FSO_Node1 design and IPv4Config1.xml
//

package obsmodules.Examples.FSONodeExample;

import obsmodules.src.FSONode.FSO_Node1;
import inet.node.inet.StandardHost;
import inet.networklayer.configurator.ipv4.IPv4NetworkConfigurator;

network FSONodeExample1
{
    parameters:
        int lambdas; //Number of data channels in the fiber connecting edges
 		int servers = default(1);
    submodules:
 
        host1: StandardHost {
            parameters:
                forwarding = true;
                @display("p=46,112");
        }
        host2: StandardHost {
            parameters:
                forwarding = true;
                @display("p=48,272");
        }
        fso1: FSO_Node1 {
            parameters:
                lambdasPerInPort = lambdas;
                lambdasPerOutPort = lambdas;
                servernumPorts = servers;
                @display("p=259,112");
            gates:
 //               oxcin[lambdas];
 //               oxcout[lambdas];
 //               ethIO[servers];
        }
        fso2: FSO_Node1 {
            parameters:
                lambdasPerInPort = lambdas;
                lambdasPerOutPort = lambdas;
                servernumPorts = servers;
                @display("p=258,272");
            gates:
 //               oxcin[lambdas];
 //               oxcout[lambdas];
 //               ethIO[servers];
        }
        
        configurator: IPv4NetworkConfigurator {
            @display("p=62,127");
            config = xmldoc("IPv4Config1.xml");
        }
        
    connections:
        //Connections between hosts and FSO Nodes
        host1.ethg++ <--> { datarate=1Gbps; } <--> fso1.ethIO++;
        host2.ethg++ <--> { datarate=1Gbps; } <--> fso2.ethIO++;

        //Core Optical connections
        for i=0..lambdas {
            fso1.oxcout++ --> fso2.oxcin++;
            fso2.oxcout++ --> fso1.oxcin++;
        }
}