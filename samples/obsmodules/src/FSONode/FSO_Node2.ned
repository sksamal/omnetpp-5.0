//
//
// FSO Node design 2
// Suraj: This design uses Edge_Interface as a submodule (and not Edge_Node) //

package obsmodules.src.FSONode;

import obsmodules.src.EdgeNode.OBS_EdgeInterface;
import obsmodules.src.CoreNode.OBS_CoreNode;
import obsmodules.src.FSONode.FSO_CrossConnect;
import inet.networklayer.common.InterfaceTable;
import inet.linklayer.ppp.PPPInterface;
import inet.linklayer.ethernet.EthernetInterface;
import inet.networklayer.ipv4.IPv4NetworkLayer;
import inet.networklayer.ipv4.IPv4RoutingTable;

//
// FSO node for a OBS network. Its a complex module composed of functionalities of 
// OBScore and OBSedge modules
//
module FSO_Node2
{
    parameters:
        @networkNode;
 		// FSO Optical switch parameters
        int lambdasPerInPort; //Number of input channels per fiber
        int lambdasPerOutPort; //Number of output channels per fiber (always the same as input) 
        string inputColours; // Colour of each input data channel of each fiber. Should be a list of int numbers and vertical bars separated by spaces (each vertical bar separates a fiber). Use an empty string if you don't want to use colours. Example: "2 3 4 | 4 3 2 | 5 4 3" (3 fibers with 3 lambdas each one)
        string outputColours; // Colour of each output data channel of each fiber. Should be a list of int numbers and vertical bars separated by spaces (each vertical bar separates a fiber). Use an empty string if you don't want to use colours. Example: "2 3 4 | 4 3 2 | 5 4 3" (3 fibers with 3 lambdas each one)
        *.interfaceTableModule = default(absPath(".interfaceTable"));
        *.routingTableModule = default(absPath(".routingTable"));

        // Electrical port parameters
        int servernumPorts;  // Number of servers connected in the TOR
        int lambdasEdge = servernumPorts; // For now, assume one lambda dedicated to each server in TOR
        @display("bgb=434,264;i=block/wrx");

    gates:

        // Electrical i/o (from servers)
        inout pppIO[];	// PPP port
        inout ethIO[];	// Ethernet port**.numPacketBurstifiers = 16
 //       input obsIn[];  // OBS input
 //       output obsOut[]; //OBS output


        // Optical i/o (towards the network)
        input oxcin[];
        output oxcout[];

    submodules:

 //       torInterface: OBS_EdgeNode {
 //           parameters:
 //               numInLambdas = lambdasPerInPort;
 //               numOutLambdas = lambdasPerOutPort;
 //               outColours = outputColours;
 //               @display("i=block/classifier2;p=198.46155,200.76924");
 //           gates:

                // Interfaces towards the optical ports
  //              obsIn[lambdasPerInPort + 1];
  //              obsOut[lambdasPerOutPort + 1];

                // Interfaces towards individual hosts or servers
//        }

        interfaceTable: InterfaceTable {
            parameters:
                @display("p=103.07693,123.07693;i=block/table");
        }
        routingTable: IPv4RoutingTable {
            parameters:
                forwarding = true;
                routerId = "auto";
                @display("p=281.53848,127.692314;i=block/table");
        }
        networkLayer: IPv4NetworkLayer {
            parameters:
                @display("p=183.84616,189.23077;i=block/fork;q=queue");
        }
        ppp[sizeof(pppIO)]: PPPInterface {
            parameters:
                @display("p=88.46154,190,row,110;q=l2queue;i=block/ifcard");
        }
        eth[sizeof(ethIO)]: EthernetInterface {
            parameters:
                @display("p=281.53848,189.23077,row,110;q=l2queue;i=block/ifcard");
        }
        obs: OBS_EdgeInterface {
            parameters:
                numInLambdas = lambdasEdge;
                numOutLambdas = lambdasEdge;
                //inColours = inputColours; 
                outColours = outputColours;
                @display("p=183.84616,93.07693;q=l2queue;i=block/ifcard");
        }

        fsoModule: FSO_CrossConnect {
            parameters:
                inputColours = inputColours;
                outputColours = outputColours;
                lambdasPerInPort = lambdasPerInPort;
                lambdasPerOutPort = lambdasPerOutPort;
                lambdasEdge = lambdasEdge;
                numInPorts = sizeof(oxcin)/lambdasPerInPort;
                numOutPorts = sizeof(oxcin)/lambdasPerInPort;
                
                @display("i=block/switch;p=261.53848,49.23077");

            gates:
//                in[2*sizeof(oxcin)];
//                out[2*sizeof(oxcout)];
        }

    connections allowunconnected:

		// Connect oxcin (optical core) data channels oxcInputs to OXC inputs
        for i=0..sizeof(oxcin)-1 {
            oxcin[i] --> fsoModule.in++;
        }

        //Connect input from obsin (tor/electrical side) data channels to obsin in fsoModule
        // One extra for control channel
        for i=0..lambdasEdge {
            //           obsIn++ --> fsoSwitch.in[lambdasPerInPort+i+1];
            obs.physOut++ --> fsoModule.obsin++;
        }

        //Connect output oxc ports (first part) data channels to oxcout (optical core)
        for i=0..sizeof(oxcout)-1 {
            fsoModule.out++ --> oxcout[i];
        }

        //Connect obsout from fsoModule to obsOut (tor/electrical side)
        // One extra for control channel
        for i=0..lambdasEdge {
            //           fsoSwitch.out[i + lambdasPerOutPort+1] --> obsOut++;
            fsoModule.obsout++ --> obs.physIn++;
        }

        //Connect input eth/ppp ports to edgeNode eth/ppp ports
//        for i=0..sizeof(ethIO)-1 {
//            ethIO[i] <--> torInterface.ethIO++;
//        }

//        for i=0..sizeof(pppIO)-1 {
//            pppIO[i] <--> torInterface.pppIO++;
//        }

        // connections to the outer world
        for i=0..sizeof(pppIO)-1 {
            pppIO[i] <--> ppp[i].phys;
            //            ppp[i].upperLayerOut --> networkLayer.ifIn[i];
            //            ppp[i].upperLayerIn <-- networkLayer.ifOut[i];
            ppp[i].upperLayerOut --> networkLayer.ifIn++;
            ppp[i].upperLayerIn <-- networkLayer.ifOut++;
        }

        for i=0..sizeof(ethIO)-1 {
            ethIO[i] <--> eth[i].phys;
            //            eth[i].upperLayerOut --> networkLayer.ifIn[sizeof(pppIO)+i];
            //            eth[i].upperLayerIn <-- networkLayer.ifOut[sizeof(pppIO)+i];
            eth[i].upperLayerOut --> networkLayer.ifIn++;
            eth[i].upperLayerIn <-- networkLayer.ifOut++;
        }

 //       for i=0..sizeof(obsIn)-1 {
            //            obsIn[i] --> obs.physIn[i];
 //           obsIn[i] --> obs.physIn++;
 //       }

 //       for i=0..sizeof(obsOut)-1 {
 //           //            obs.physOut[i] --> obsOut[i];
 //           obs.physOut++ --> obsOut[i];
 //       }

        //Connection between OBS Interface and Network layer. Only one line, as mentioned before
        //        obs.netwOut --> networkLayer.ifIn[sizeof(pppIO)+sizeof(ethIO)];
        //        obs.netwIn <-- networkLayer.ifOut[sizeof(pppIO)+sizeof(ethIO)];
        obs.upperLayerOut --> networkLayer.ifIn++;
        obs.upperLayerIn <-- networkLayer.ifOut++;

}
