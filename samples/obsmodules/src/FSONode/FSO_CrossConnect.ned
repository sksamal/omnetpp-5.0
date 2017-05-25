//
// Copyright (C) 2010-2013 Javier Armendariz Silva, Naiara Garcia Royo, Felix Espina Antolin
// Copyright (C) 2010-2013 Universidad Publica de Navarra
//
// This file is part of OBSModules.
//
// OBSModules is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// OBSModules is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with OBSModules.  If not, see <http://www.gnu.org/licenses/>.
//

package obsmodules.src.FSONode;

import obsmodules.src.EdgeNode.OBS_EdgeNode;
import obsmodules.src.CoreNode.OBS_CoreNode;
import obsmodules.src.CoreNode.OBS_CoreInput;
import obsmodules.src.CoreNode.OBS_CoreOutput;
import obsmodules.src.CoreNode.OBS_OpticalCrossConnect;
import obsmodules.src.CoreNode.OBS_CoreControlUnit;
//
// FSO node for a OBS network. Its a complex module composed of functionalities of 
// OBScore and OBSedge modules
//
module FSO_CrossConnect
{
    parameters:

 		// Optical switch parameters
        int lambdasPerInPort; //Number of input data channels for each fiber
        int lambdasPerOutPort; //Number of output data channels for each fiber 
        string inputColours; // Colour of each input data channel of each fiber. Should be a list of int numbers and vertical bars separated by spaces (each vertical bar separates a fiber). Use an empty string if you don't want to use colours. Example: "2 3 4 | 4 3 2 | 5 4 3" (3 fibers with 3 lambdas each one)
        string outputColours; // Colour of each output data channel of each fiber. Should be a list of int numbers and vertical bars separated by spaces (each vertical bar separates a fiber). Use an empty string if you don't want to use colours. Example: "2 3 4 | 4 3 2 | 5 4 3" (3 fibers with 3 lambdas each one)

        @display("bgb=434,264;i=block/wrx");

    gates:

        // Optical i/o (towards the network)
        // Number of optical ports, not channels
        input in[];
        output out[];
        
        // Number of wavelengths from obsModule
		input obsin[];
		output obsout[];

    submodules:

        oxcSwitch: OBS_OpticalCrossConnect {
            parameters:
                @display("i=block/switch;p=221,177");
            gates:
//                in[(sizeof(in)-1)*lambdasPerInPort + sizeof(obsin)-1];  
                    // One from each port goes to control,
                    // and lambda times the number of ports + lambdas in obsin
//                out[(sizeof(out)-1)*lambdasPerOutPort + sizeof(obsout)-1];  
                	// One from each port comes from control,
                	// and lambda times the number of ports + lambdas in obsout
        }

        oxcControl: OBS_CoreControlUnit {
            parameters:
                numPorts = sizeof(in)+ sizeof(obsin);   // size of input ports + size of obs
                lambdasPerOutPort = string(lambdasPerOutPort);  
                @display("i=block/cogwheel;p=243,77");
            gates:
 //               in[sizeof(in)]; // size of input ports
 //               out[sizeof(in)]; // size of input ports
        }
	
        oxcInput: OBS_CoreInput {
            parameters:
                lambdasPerPort = string(lambdasPerInPort+1);
                numPorts = sizeof(in)+sizeof(obsin);  // each lambda from edge on separate port
                									// may not be good design
                colours = inputColours;
                @display("i=block/arrival;p=89,177");
            gates:
 //               in[sizeof(in)*lambasPerInPort];
 //               out[sizeof(in)*lambdasPerInPort];
        }

        oxcOutput: OBS_CoreOutput {
            parameters:
                lambdasPerPort = string(lambdasPerOutPort+1);
                numPorts = sizeof(out) + sizeof(obsout);  // each obs lambda on separate port
                colours = outputColours;
                @display("i=block/arrival;p=350,177");
            gates:
   //             in[sizeof(out)*lambdasPerOutPort];
   //             out[sizeof(out)*lambasPerOutPort];
        }


    connections:

		// Connect input and output ports to oxcInput and oxcOutput
        for i=0..sizeof(in)-1 {
            in[i] --> oxcInput.in++;
        }

        for i=0..sizeof(in)-1 {
            oxcOutput.out++ --> out[i];
        }

		// Not a good design, but each lambda on obsIn is taken on a separate port
		//         
        for i=0..sizeof(obsin) -1 {
            obsin[i] --> oxcInput.in++;
        }


        for i=0..sizeof(obsout) -1 {
            oxcOutput.out++ --> obsout[i];
        }
        
		//Connect the control channels form oxcInput to the control unit
		//Control channels are exactly the number of input ports (one wavelength per port)
        for i=0..sizeof(in) + sizeof(obsin)-1 {
            oxcInput.out++ --> oxcControl.in++;
            oxcControl.out++ --> oxcOutput.in++;
        }

		// Connect oxcin (optical core) data channels to oxcInput and to OXC cross-connect
		// lambda-1 times the number of ports
        for i=0..((lambdasPerInPort)*(sizeof(in))+ sizeof(obsin)) -1 {
            oxcInput.out++ --> oxcSwitch.in++;
        }

        //Connect OXC cross-connect to OXcOutput and then to oxcout (optical core)
        // lambda-1 times the number of ports
        for i=0..((lambdasPerOutPort)*(sizeof(out))+ sizeof(obsout)) -1 {
            oxcSwitch.out++ --> oxcOutput.in++;
        }

}
