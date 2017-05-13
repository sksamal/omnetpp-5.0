//
// Author: Michael Klopf
//

#ifndef __FATTREEVMMIGRATIONCASE1_AGGIPCONFIG_H_
#define __FATTREEVMMIGRATIONCASE1_AGGIPCONFIG_H_

#include <omnetpp.h>
#include <IPv4Address.h>
using namespace omnetpp;
using namespace inet;
/**
 * Sets the IP address of the aggregation router at a certain position
 * in dependence to the k-value of the fat tree.
 */
class AggIPConfig : public cSimpleModule
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
        /**
         * gives the position of the POD the router lies in.
         */
        int podposition;
    protected:
        virtual int numInitStages() const  {return 2;}
        virtual void initialize(int stage);
        virtual void handleMessage(cMessage *msg);
        /**
         * Takes the k-value, the position of the aggregation router in the
         * pod and the position of the pod among the pods to compute the
         * ip address.
         */
        virtual IPv4Address createAddress(int k, int position, int podposition);
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
