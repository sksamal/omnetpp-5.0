//
// A rack is the basic building block of a FatTree.
// One edge router is allocated an certain amount of servers.
//
// 

package fattree.components;

//import inet.nodes.inet.StandardHost;
//import inet.nodes.inet.Router;
import fattree.logic.ipaddress.RackIPConfig;
import ned.DatarateChannel;
import ned.IdealChannel;

module Rack
{
    parameters:
        @Rack;
        // We get value from pod module.
        int k;
        int address;
        @display("bgb=600,250");

    gates:
        // As many ports as aggregation routers.
        inout portToServer[k/2];
        inout portToAgg[k/2];
        

    types:
        channel ethernetline extends DatarateChannel
        {
            delay = 0.1us;
            datarate = 1Gbps;
        }

    submodules:
        // k/2 servers are connected with one edge router.
        servers[k/2]: Server {
            // Reach value down.
            dim = k;
            address = index;
            @display("p=80,160,r,80");
            @display("i=device/device");
        }
        
        router: TRouter {
			parameters:
                address = address;
                dim = k/2;
                @display("p=125,171");
            gates:
                in[k/2];
                out[k/2];
        }
        
        ipconfig: RackIPConfig {
        @display("p=568,31");
        }
        
        
      connections allowunconnected:
        
        for i=0..k/2-1 {
 			router.in[i] <--> portToAgg[i];			
            router.out[i] <--> servers[i].port;//portToServer[i];
        }
        
        // Connect all servers with the one edge switch.
 //       for i=0..sizeof(servers)-1 {
  //          portToServer[i] <--> ethernetline <--> servers[i].port;
   //     }
        
}
