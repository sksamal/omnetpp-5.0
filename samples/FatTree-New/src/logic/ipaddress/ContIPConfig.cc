//
// Author: Michael Klopf
//

#include "ContIPConfig.h"
#include <IPv4Address.h>
#include <InterfaceTable.h>
//#include <IPAddressResolver.h>
#include <IPv4InterfaceData.h>

using namespace inet;
Define_Module(ContIPConfig);

void ContIPConfig::initialize(int stage)
{
    if (stage == 1) {
        // Set ip for the traffic controller.
        cTopology conTopology("ControllerTopology");
        conTopology.extractByProperty("Controller");
        //EV << "We found " << conTopology.getNumNodes() << " controller elements.\n";

        setConIPAddress(conTopology);
    }
}

void ContIPConfig::setConIPAddress(cTopology& topology) {
    // Get network address/netmask and check if address space is big enough.
    uint32_t networkAddress = inet::IPv4Address(par("networkAddress").stringValue()).getInt();
    uint32_t netmask = inet::IPv4Address(par("netmask").stringValue()).getInt();
    int maxNodes = (~netmask)-1;
    if (topology.getNumNodes()>maxNodes)
            error("netmask too large, not enough addresses for all %d nodes", topology.getNumNodes());

    int numCon = 1;
    // Find the controller and assign it the address.
    for (int i = 0; i < topology.getNumNodes(); i++) {
        // ip is disjunction of network address and the first ip of subnet.
        uint32_t addr = networkAddress | uint32_t(numCon++);
        //EV << "Con El has IP " << IPAddress(addr).str().c_str() << " . . . . . . . . . . . . . . . . \n";

        // Write Address in interface table.
        IInterfaceTable *ift = check_and_cast < IInterfaceTable *>(topology.getNode(i)->getModule());
        for (int j=0; j<ift->getNumInterfaces(); j++)
        {
            InterfaceEntry *ie = ift->getInterface(j);
            if (!ie->isLoopback()) //check for loopback address
            {
                ie->ipv4Data()->setIPAddress(IPv4Address(addr));
                ie->ipv4Data()->setNetmask(IPv4Address::ALLONES_ADDRESS); // full address must match for local delivery
            }
        }
        // Set display string of virtual machine.
        if (this->getSimulation()->getActiveEnvir()->isGUI()) {
            // update display string
            topology.getNode(i)->getModule()->getDisplayString().setTagArg("t",0,IPv4Address(addr).str().c_str());
        }
    }
}

void ContIPConfig::handleMessage(cMessage *msg)
{
    error("this module doesn't handle messages, it runs only in initialize()");
}
