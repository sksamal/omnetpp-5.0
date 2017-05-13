//
// Author: Michael Klopf
// 

#ifndef __FATTREEVMMIGRATIONCASE1_COREIPCONFIG_H_
#define __FATTREEVMMIGRATIONCASE1_COREIPCONFIG_H_

#include <omnetpp.h>
#include <IPv4Address.h>
using namespace omnetpp;
using namespace inet;

/**
 * Sets the IP address of the core router at a certain position
 * in dependence to the k-value of the fat tree.
 */
class CoreIPConfig : public cSimpleModule
{
    protected:
        /**
         * value, which is necessary for building fat tree.
         */
        int k;
        /**
         * gives the position among the other core routers.
         */
        int position;
    protected:
        virtual int numInitStages() const  {return 2;}
        virtual void initialize(int stage);
        virtual void handleMessage(cMessage *msg);

        /**
         * Takes the k-value and the position of the core router in the
         * network and computes the address.
         */
        virtual IPv4Address createAddress(int k, int position);
        /**
         * Finds the interface table and assigns the ip address
         * to all non-loopback interfaces.
         */
        virtual void setRouterIPAddress(IPv4Address address);
        /**
         * Sets the ip address as display string in graphical environment.
         */
        virtual void setDisplayString(IPv4Address address);
};

#endif
