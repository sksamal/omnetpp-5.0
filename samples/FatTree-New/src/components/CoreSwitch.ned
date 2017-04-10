//
// The pod connects the aggregation layer routers with the racks.
//
// Author: Michael Klopf
// 

package fattree.components;

//import inet.nodes.inet.Router;

import ned.DatarateChannel;
import ned.IdealChannel;


module CoreSwitch
{
    parameters:
        @Core;
        // We get value from FatTree module.
        int k;
        int address;

        @display("bgb=600,250");
    gates:
        // As many gates as core routers.
        inout portToAgg[k];
        
     submodules:
           router: TRouter {	    
            parameters:
 //               address = address;
                dim = k/2;
                @display("p=125,171");
            gates:
                in[k/2];
                out[k/2];
    
        }
  
      connections allowunconnected:      
         for i=0..k/2-1 {
 			router.in[i] <--> portToAgg[i];			
            router.out[i] <--> portToAgg[k/2+i];
        }
        

}
