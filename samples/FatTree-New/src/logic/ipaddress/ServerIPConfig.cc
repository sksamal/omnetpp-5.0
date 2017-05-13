//
// Author: Michael Klopf
// 

#include "ServerIPConfig.h"
#include <InterfaceTable.h>
//#include <IPv4AddressResolver.h>
#include <IPv4InterfaceData.h>

Define_Module(ServerIPConfig);

void ServerIPConfig::initialize(int stage)
{
    if (stage == 1) {
        serverIndex = getParentModule()->par("address");
        rackIndex = getParentModule()->getParentModule()->par("address");
        k = getParentModule()->getParentModule()->par("k");

      //  EV << "Edge Router " << position << " lies in POD: " << podposition << ".\n";

        IPv4Address address = createAddress(serverIndex, rackIndex, k);
        EV << "Server " << serverIndex << " in POD " << rackIndex << " k " << k << " has IP " << address.str() << "\n";

        setServerIPv4Address(address);
        setDisplayString(address);
    }
}

IPv4Address ServerIPConfig::createAddress(int serverIndex, int rackIndex, int k) {
    // First byte determined by ned file.
    int i0 = IPv4Address((const char*)par("networkAddress")).getDByte(0);
    // Number of the POD the router lies in.
    int i1 = rackIndex/(k/2);
    // Router the server is connected to.
    int i2 = rackIndex%(k/2);
    // Number of the server.
    int i3 = serverIndex+2;

    return IPv4Address(i0, i1, i2, i3);
}

void ServerIPConfig::setServerIPv4Address(IPv4Address address) {

    // find interface table and assign address to all (non-loopback) interfaces
    IInterfaceTable *ift = check_and_cast < IInterfaceTable *>(getParentModule());
    for (int i=0; i<ift->getNumInterfaces(); i++)
    {
        InterfaceEntry *ie = ift->getInterface(i);
        if (!ie->isLoopback())
        {
            ie->ipv4Data()->setIPAddress(IPv4Address(address));
            ie->ipv4Data()->setNetmask(IPv4Address::ALLONES_ADDRESS); // full address must match for local delivery
        }
    }
}

void ServerIPConfig::setDisplayString(IPv4Address address) {
    if (this->getSimulation()->getActiveEnvir()->isGUI()) {
        // update display string
        this->getDisplayString().setTagArg("t",0,address.str().c_str());
    }
}

void ServerIPConfig::handleMessage(cMessage *msg)
{
    error("this module doesn't handle messages, it runs only in initialize()");
}
