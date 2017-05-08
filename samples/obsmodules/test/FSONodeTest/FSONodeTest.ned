//
// Copyright (C) 2012 Naiara Garcia Royo
// Copyright (C) 2012 Universidad Publica de Navarra
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

package obsmodules.test.FSONodeTest;

import obsmodules.src.tests.sources.testSource3;
import obsmodules.src.tests.sinks.testSink3;
import obsmodules.src.FSONode.FSO_Node;


// Network used to check that the OBS_CoreNode module works properly.
network FSONodeTest
{
    parameters:
        int numPorts; //Number of input (output) fibers
        int totalInLambdas; //Sum of the values on the string "lambdasPerInPort"
        int totalOutLambdas; //Sum of the values on the string "lambdasPerOutPort"
    submodules:
        source: testSource3 {
            gates:
                out[totalInLambdas+numPorts];
        }
        fsoNode: FSO_Node {
            parameters:
                corenumPorts = numPorts; //Number of fibers
                @display("i=block/switch");
            gates:
                corein[totalInLambdas+numPorts];
                coreout[totalOutLambdas+numPorts];
        }
        sink: testSink3 {
            gates:
                in[totalOutLambdas+numPorts];
        }

    connections:
        for i=0..totalInLambdas+numPorts-1 {
            source.out[i] --> fsoNode.corein[i];
        }

        for i=0..totalOutLambdas+numPorts-1 {
            fsoNode.coreout[i] --> sink.in[i];
        }
}
