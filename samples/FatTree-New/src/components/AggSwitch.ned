//
// A rack is the basic building block of a FatTree.
// One edge router is allocated an certain amount of servers.
//
// 

package fattree.components;

//import inet.nodes.inet.StandardHost;
//import inet.nodes.inet.Router;

import ned.DatarateChannel;
import ned.IdealChannel;

module AggSwitch
{
    parameters:
        @Agg;
        // We get value from pod module.
        int k;
        int address;
        @display("bgb=600,250");
 
    gates:
        // As many ports as aggregation routers.
        inout portToCore[k/2];
        inout portToRack[k/2];
        

    types:
        channel ethernetline extends DatarateChannel
        {
            delay = 0.1us;
            datarate = 1Gbps;
        }
        
     submodules:
           router: TRouter {
		    parameters:
 //               address = index;
                dim = k/2;
                @display("p=125,171");
            gates:
                in[k/2];
                out[k/2];
        
        }
  
      connections allowunconnected:      
         for i=0..k/2-1 {
 			router.in[i] <--> portToRack[i];			
            router.out[i] <--> portToCore[i];
        }
 
     
}
