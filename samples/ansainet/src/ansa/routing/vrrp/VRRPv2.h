//
// Copyright (C) 2009 - today, Brno University of Technology, Czech Republic
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 
/**
* @file VRRPv2.h
* @author Petr Vitek
* @author Vladimir Vesely (ivesely@fit.vutbr.cz)
* @copyright Brno University of Technology (www.fit.vutbr.cz) under GPLv3
* @brief
* @detail
*/
#ifndef __ANSA_VRRPV2_H_
#define __ANSA_VRRPV2_H_

#include <omnetpp.h>
#include "ansa/routing/vrrp/VRRPv2VirtualRouter.h"

namespace inet {

/**
 * The VRRPv2 class represents a communication gateway with VRRPv2modules modules.
 *
 * @author Petr Vitek
 */
class VRRPv2 : public cSimpleModule
{
    protected:
        const   char*   CONFIG_PAR      = "configData";
        const   char*   IFT_PAR         = "interfaceTableModule";
        const   char*   HOSTNAME_PAR    = "hostname";
        const   char*   VRID_PAR        = "vrid";
        const   char*   INTERFACE_PAR   = "interface";

        const   char*   VRIN_GATE       = "vrIn";
        const   char*   VROUT_GATE      = "vrOut";
        const   char*   IPIN_GATE       = "ipIn";
        const   char*   IPOUT_GATE      = "ipOut";

        const   char*   VR_MOD          = "ansa.routing.vrrp.VRRPv2VirtualRouter";

        std::string hostname;
        std::vector<VRRPv2VirtualRouter *> virtualRouterTable;

    protected:
        virtual int numInitStages() const override  {return NUM_INIT_STAGES;}
        virtual void initialize( int stage) override;
        virtual void handleMessage(cMessage *msg) override;
        virtual void updateDisplayString();

        std::string getHostname() { return hostname; };

    public:
        VRRPv2();

        /**
         * Dynamic creation of modules Virtual Router
         * @param interface interafceId
         * @param vrid      Virtual Router ID
         */
        virtual void addVirtualRouter(int interface, int vrid, const char* ifnam);

};
}
#endif
