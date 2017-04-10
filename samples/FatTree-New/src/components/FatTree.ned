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

network FatTree
{
    parameters:
        @FatTree;
        // We get value from pod module.
        int k;
        @display("bgb=600,400");

        
    types:
        channel ethernetline extends DatarateChannel
        {
            delay = 0.1us;
            datarate = 1Gbps;
        }
    
       submodules:
        // k/2 racks are in one pod.
        racks[k*k/2]: Rack {
            // Reach values down.
            k = k;
            address = index;
            @display("p=80,240,r,120");
            @display("i=device/server2");
        }

		// Also k/2 aggregation routers in one pod.
        aggs[k*k/2]: AggSwitch {
            k = k;
            address = index;
            router.address = index;
            @display("p=80,160,r,120");
        }
        
        cores[k]: CoreSwitch {
            // Reach values down.
            k = k;
            address = index;
            router.address = index;
            @display("p=140,80,r,240");
            @display("i=device/server2");
        }
               
        
    connections allowunconnected:
        // Connect a rack with all aggregation switches. Do it for all racks.
        for i=0..sizeof(racks)-1, for j=0..k/2-1 {
            racks[i].portToAgg++ <--> IdealChannel <--> aggs[int(i/(k/2))*(k/2) + j].portToRack++;
        }   
        
        // Connect a core switch with all aggregation switches in all pods
        for i=0..sizeof(cores)-1, for j=0..k-1 {
            cores[i].portToAgg++ <--> IdealChannel <--> aggs[j*(k/2)+(i%(k/2))].portToCore++;
        }    
                
}
