//
// Copyright (C) 2009 - today Brno University of Technology, Czech Republic
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
 * @file IEigrpModule.h
 * @author Jan Bloudicek (jbloudicek@gmail.com)
 * @author Vit Rek (rek@kn.vutbr.cz)
 * @author Vladimir Vesely (ivesely@fit.vutbr.cz)
 * @copyright Brno University of Technology (www.fit.vutbr.cz) under GPLv3
 */
#ifndef IEIGRPMODULE_H_
#define IEIGRPMODULE_H_

#include "ansa/routing/eigrp/messages/EigrpMessage_m.h"
#include "ansa/routing/eigrp/tables/EigrpNetworkTable.h"
namespace inet {
/**
 * Interface for EIGRP configuration.
 */

template <typename IPAddress>
class IEigrpModule
{
  public:
    virtual ~IEigrpModule() {}
    //-- Process configuration
    /**
     * Adds interface to EIGRP.
     * @param interfaceId ID of interface
     * @param networkID ID of network in EigrpNetworkTable
     */
    virtual void addInterface(int interfaceId, int networkId, bool enabled) = 0;

    /**
     * Adds interface to EIGRP for IPv6
     *
     * @param   interfaceId     ID of interface
     * @param   enabled         state of interface in EIGRP process, enabled or disabled
     */
    virtual void addInterface(int interfaceId, bool enabled) = 0;
    /**
     * Adds new network to EigrpNetworkTable for routing.
     */
    virtual EigrpNetwork<IPAddress> *addNetwork(IPAddress address, IPAddress mask) = 0;
    virtual void setASNum(int asNum) = 0;
    virtual int getASNum() = 0;
    virtual void setKValues(const EigrpKValues& kValues) = 0;
    virtual void setMaximumPath(int maximumPath) = 0;
    virtual void setVariance(int variance) = 0;
    virtual void setStub(const EigrpStub& stub) = 0;

    // Interface configuration
    virtual void setHelloInt(int interval, int interfaceId) = 0;
    virtual void setHoldInt(int interval, int interfaceId) = 0;
    virtual void setSplitHorizon(bool shEnabled, int interfaceId) = 0;
    virtual void setPassive(bool passive, int ifaceId) = 0;

    /**
     * Sets router ID
     *
     * @param   routerID        EIGRP process routerID, represented as IPv4 address
     */
    virtual void setRouterId(IPv4Address routerID) = 0;

    /**
     * Adds information about IPv6 network prefix
     *
     * @param   network     network prefix
     * @param   prefixLen   length of network prefix
     * @param   ifaceId     ID of interface contains network prefix
     * @return  True if successfully added, otherwise false (e.g. same IPv6 prefix on different interfaces)
     * @note    Checks duplicates
     */
    virtual bool addNetPrefix(const IPAddress &network, const short int prefixLen, const int ifaceId) = 0;
};
}
#endif /* IEIGRPMODULE_H_ */
