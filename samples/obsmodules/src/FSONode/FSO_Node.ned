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
import obsmodules.src.CoreNode.OBS_OpticalCrossConnect;
import obsmodules.src.CoreNode.OBS_CoreControlUnit;
//
// FSO node for a OBS network. Its a complex module composed of functionalities of 
// OBScore and OBSedge modules
//
module FSO_Node
{
    parameters:

        // Edge 
        int edgenumInLambdas; // Number of input data channels for the OBS interface.
        int edgenumOutLambdas; // Number of output data channels for the OBS interface.
        string edgeinColours; // Colour array for input data channels.
        string edgeoutColours; // Colour array for output data channels.

 		// Core
        int corenumPorts; //Number of fibers
        string corelambdasPerInPort; //Number of input data channels for each fiber
        string corelambdasPerOutPort; //Number of output data channels for each fiber 
        string coreinputColours; // Colour of each input data channel of each fiber. Should be a list of int numbers and vertical bars separated by spaces (each vertical bar separates a fiber). Use an empty string if you don't want to use colours. Example: "2 3 4 | 4 3 2 | 5 4 3" (3 fibers with 3 lambdas each one)
        string coreoutputColours; // Colour of each output data channel of each fiber. Should be a list of int numbers and vertical bars separated by spaces (each vertical bar separates a fiber). Use an empty string if you don't want to use colours. Example: "2 3 4 | 4 3 2 | 5 4 3" (3 fibers with 3 lambdas each one)

        @display("bgb=434,264;i=block/switch");

    gates:

        // Edge side
        inout edgepppIO[];	// PPP port
        inout edgeethIO[];	// Ethernet port
        input edgeobsIn[];  // OBS input
        output edgeobsOut[]; //OBS output

        // Core side
        input corein[];
        output coreout[];

    submodules:

        elec_switch: OBS_EdgeNode {
            parameters:
                numInLambdas = edgenumInLambdas;
                numOutLambdas = edgenumOutLambdas;
                routingTable.routingFile = "Fso2.irt";
                @display("i=block/classifier2;p=223,218");
            gates:
                obsIn[sizeof(edgeobsin)];
                obsOut[sizeof(edgeobsout)];
        }

        fso_switch: OBS_OpticalCrossConnect {
            parameters:
                @display("i=block/switch;p=223,41");
            gates:
                in[corenumPorts];
                out[corenumPorts];
        }

        fso_input: FSO_Input {
            @display("i=block/arrival,p,50,116;p=59,128");
            numoxcPorts = corenumPorts;
            numserverPorts = sizeof(edgeobsin);
        }

        fso_output: FSO_Output {
            numoxcPorts = corenumPorts;
            numserverPorts = sizeof(edgeobsout);
            @display("i=block/departure,p,310,138;p=373,128");
        }

        ControlUnit: OBS_CoreControlUnit {
            parameters:
                numPorts = corenumPorts + edgenumPorts;
                lambdasPerOutPort = lambdasPerOutPort;
                @display("i=block/cogwheel;p=223,128");
            gates:
                in[corenumPorts + sizeof(obsin)]; //
                out[corenumPorts + sizeof(obsout)]; //
        }
        
        connections:
        //Connect input control channels
        for i=0..sizeof(corein)-1 {
            corein++ --> fso_input.in[i];
        }
        
        //Connect output control channels
        for i=0..sizeof(coreout)-1 {
            fso_output.out[i] --> coreout++;
        }
        
        //Connect the control channels with the control unit
        for i=0..numPorts-1 {
            fso_input.out[i] --> ControlUnit.in[i];
            ControlUnit.out[i] --> fso_output.in[i];
        }
        
        //Connect input oxc data channels
        for i=numPorts..sizeof(corein)-1 {
            fso_input.out[i] --> fso_switch.in[i-numPorts];
        }
        
        //Connect output oxc data channels
        for i=numPorts..sizeof(coreout)-1 {
            fso_switch.out[i-numPorts] --> fso_output.in[i];
        }
        
        for i=0..sizeof(edgeobsOut)-1 {
            elec_switch.obsOut[i] --> fso_output.in[corein+i];
        }

        for i=0..sizeof(edgeobsOut)-1 {
            fso_input.out[coreout+i] --> elec_switch.obsIn[i];
        }
                
}
