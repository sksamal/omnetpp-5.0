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

package obsmodules.Examples.FSONodeTest;
import inet.networklayer.configurator.ipv4.IPv4NetworkConfigurator;
import obsmodules.src.misc.OBS_OpticalMonitor;
import obsmodules.src.FSONode.FSO_Node;
import inet.node.inet.StandardHost;

// Edge Node testing network.
// It consists of two hosts interconnected by an OBS network. Each host has its own edge node.
// Between each edge, an optical monitor module is connected in order to collect information about bursts that pass through the network.
//
network FSONodeTest
{
    parameters:
        int lambdas; // Number of data channels (same for all fibers)
		int servers;
		
    submodules:

        host1: StandardHost {
            parameters:
                @display("p=46,72;i=device/pc2");
        }

        fso1: FSO_Node {
            parameters:
                lambdasPerInPort = lambdas;
                lambdasPerOutPort = lambdas;
                servernumPorts = servers;
        }

        configurator: IPv4NetworkConfigurator {
            @display("p=62,127");
            config = xmldoc("IPv4Config.xml");
        }

        monitor: OBS_OpticalMonitor {
            parameters:
                @display("p=246,240;i=block/process");
            gates:
                in[lambdas+1];
                out[lambdas+1];
        }

        fso2: FSO_Node {
            parameters:
                lambdasPerInPort = lambdas;
                lambdasPerOutPort = lambdas;
                servernumPorts = servers;
        }

        host2: StandardHost {
            parameters:
                @display("p=440,112;i=device/pc2");
        }
    connections:
        host1.ethg++ <--> { datarate=100Gbps; } <--> fso1.ethIO++;
        host2.ethg++ <--> { datarate=100Gbps; } <--> fso2.ethIO++;

        for i=0..lambdas {
            fso1.oxcout++ --> monitor.in[i];
            monitor.out[i] --> fso2.oxcin++;
            fso2.oxcout++ --> fso1.oxcin++;
        }
}
