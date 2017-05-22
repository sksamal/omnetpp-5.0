//
// FSO Node design 1
// Suraj: This design uses Edge_Node as a submodule 

package obsmodules.src.FSONode;

import obsmodules.src.EdgeNode.OBS_EdgeNode;
import obsmodules.src.CoreNode.OBS_CoreNode;
import obsmodules.src.CoreNode.OBS_OpticalCrossConnect;
import obsmodules.src.CoreNode.OBS_CoreControlUnit;
//
// FSO node for a OBS network. Its a complex module composed of functionalities of 
// OBScore and OBSedge modules
//
module FSO_Node1
{
    parameters:

 		// FSO Optical switch parameters
        int lambdasPerInPort; //Number of input data channels for each fiber
        int lambdasPerOutPort; //Number of output data channels for each fiber 
        string inputColours; // Colour of each input data channel of each fiber. Should be a list of int numbers and vertical bars separated by spaces (each vertical bar separates a fiber). Use an empty string if you don't want to use colours. Example: "2 3 4 | 4 3 2 | 5 4 3" (3 fibers with 3 lambdas each one)
        string outputColours; // Colour of each output data channel of each fiber. Should be a list of int numbers and vertical bars separated by spaces (each vertical bar separates a fiber). Use an empty string if you don't want to use colours. Example: "2 3 4 | 4 3 2 | 5 4 3" (3 fibers with 3 lambdas each one)

        // Electrical port parameters
        int servernumPorts;
        @display("bgb=434,264;i=block/wrx");

    gates:

        // Electrical i/o (from servers)
        inout pppIO[];	// PPP port
        inout ethIO[];	// Ethernet port**.numPacketBurstifiers = 16
        

        // Optical i/o (towards the network)
        input oxcin[];
        output oxcout[];

    submodules:

        torInterface: OBS_EdgeNode {
            parameters:
                numInLambdas = lambdasPerInPort;
                numOutLambdas = lambdasPerOutPort;
                outColours = outputColours;
                @display("i=block/classifier2;p=125,177");
            gates:

                // Interfaces towards the optical ports
        //        obsIn[sizeof(oxcin)];
        //        obsOut[sizeof(oxcout)];

                // Interfaces towards individual hosts or servers
  //              ethIO[sizeof(ethIO)];
  //              pppIO[sizeof(pppIO)];
        }

        fsoSwitch: FSO_CrossConnect {
            parameters:
                inputColours = inputColours;
                outputColours = outputColours;
                lambdasPerInPort = lambdasPerInPort;
                lambdasPerOutPort = lambdasPerOutPort;
                @display("i=block/switch;p=261.53848,49.23077");

            gates:
                in[2*sizeof(oxcin)];
                out[2*sizeof(oxcout)];
        }


    connections:

		// Connect oxcin (optical core) data channels oxcInputs to OXC inputs
        for i=0..lambdasPerInPort {
            oxcin[i] --> fsoSwitch.in[i];
        }

        //Connect input from obsin (tor/electrical side) data channels to oxc ports (second part)
        for i=0..lambdasPerInPort {
              torInterface.obsOut++ --> fsoSwitch.in[lambdasPerInPort+i+1];
        }

        //Connect output oxc ports (first part) data channels to oxcout (optical core)
        for i=0..lambdasPerOutPort {
            fsoSwitch.out[i] --> oxcout[i];
        }

        //Connect oxc ports (second part) data channels to obsOut (tor/electrical side)
        for i=0..lambdasPerOutPort {
              fsoSwitch.out[i + lambdasPerOutPort+1] --> torInterface.obsIn++;
        }

        //Connect input eth/ppp ports to edgeNode eth/ppp ports
        for i=0..sizeof(ethIO)-1 {
            ethIO[i] <--> torInterface.ethIO++;
        }

        for i=0..sizeof(pppIO)-1 {
            pppIO[i] <--> torInterface.pppIO++;
        }

}
