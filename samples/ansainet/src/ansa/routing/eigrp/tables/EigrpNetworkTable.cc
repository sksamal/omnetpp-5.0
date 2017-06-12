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
 * @author Jan Bloudicek (jbloudicek@gmail.com)
 * @author Vit Rek (rek@kn.vutbr.cz)
 * @author Vladimir Vesely (ivesely@fit.vutbr.cz)
 * @copyright Brno University of Technology (www.fit.vutbr.cz) under GPLv3
 */

#include "ansa/routing/eigrp/tables/EigrpNetworkTable.h"
namespace inet {
template<typename IPAddress>
EigrpNetworkTable<IPAddress>::~EigrpNetworkTable()
{
    int cnt = networkVec.size();

    for (int i = 0; i < cnt; i++)
    {
        delete networkVec[i];
    }
    networkVec.clear();
}

template<typename IPAddress>
EigrpNetwork<IPAddress> *EigrpNetworkTable<IPAddress>::addNetwork(IPAddress& address, IPAddress& mask)
{
    typename std::vector<EigrpNetwork<IPAddress> *>::iterator it;
    for (it = networkVec.begin(); it != networkVec.end(); ++it)
    {// through all networks search same
        if((*it)->getAddress() == address && (*it)->getMask() == mask)
        {// found same -> do not add new
            return (*it);
        }
    }

    // Not found -> add new
    EigrpNetwork<IPAddress> *net = new EigrpNetwork<IPAddress>(address, mask, networkCnt++);
    networkVec.push_back(net);
    return net;
}

template<typename IPAddress>
EigrpNetwork<IPAddress> *EigrpNetworkTable<IPAddress>::findNetworkById(int netId)
{
    typename std::vector<EigrpNetwork<IPAddress> *>::iterator it;

    for (it = networkVec.begin(); it != networkVec.end(); it++)
    {
        if ((*it)->getNetworkId() == netId)
        {
            return (*it);
        }
    }

    return NULL;
}


template<>
bool EigrpNetworkTable<IPv4Address>::isInterfaceIncluded(const IPv4Address& ifAddress, const IPv4Address& ifMask, int *resultNetId)
{
    typename std::vector<EigrpNetwork<IPv4Address> *>::iterator it;
    int netMaskLen, ifMaskLen;

    if (ifAddress.isUnspecified())
        return false;

    for (it = networkVec.begin(); it != networkVec.end(); it++)
    {
        IPv4Address netPrefix = (*it)->getAddress();
        IPv4Address netMask = (*it)->getMask();

        netMaskLen = (netMask.isUnspecified()) ? getNetmaskLength(netPrefix.getNetworkMask()) : getNetmaskLength(netMask);
        ifMaskLen = getNetmaskLength(ifMask);

        // prefix isUnspecified -> network = 0.0.0.0 -> all interfaces, or
        // mask is unspecified -> classful match or
        // mask is specified -> classless match
        if (netPrefix.isUnspecified() ||
                (netMask.isUnspecified() && netPrefix.isNetwork(ifAddress) && netMaskLen <= ifMaskLen) ||
                (maskedAddrAreEqual(netPrefix, ifAddress, netMask) && netMaskLen <= ifMaskLen))
        {// IP address of the interface match the prefix
            (*resultNetId) = (*it)->getNetworkId();
            return true;
        }
    }

    return false;
}

/**
 * Determines if specified netaddress/mask is included in eigrp process
 * @param   ifAddress   address of interface
 * @param   ifMask      mask of interface
 * @param   resultNetId ID of network
 * @return  True (and set resultNetId) if address is included in network, which is enabled in Eigrp process, otherwise false (resultNetId is undefined).
 *
 * In IPv6 is netmask always specified, because it is strictly classless.
 * Configuration is defined per interfaces, and there is no wildcard.
 * In other words matching is much simpler that in the IPv4.
 */
template<>
bool EigrpNetworkTable<IPv6Address>::isInterfaceIncluded(const IPv6Address& ifAddress, const IPv6Address& ifMask, int *resultNetId)
{
    typename std::vector<EigrpNetwork<IPv6Address> *>::iterator it;
    int netMaskLen, ifMaskLen;

    if (ifAddress.isUnspecified())
        return false; //interface without address can not be included in Eigrp process

    for (it = networkVec.begin(); it != networkVec.end(); it++)
    {//go through all networks and determine if ifAddress is from that network
        IPv6Address netPrefix = (*it)->getAddress();    //network address
        IPv6Address netMask = (*it)->getMask();         //network mask

        netMaskLen = getNetmaskLength(netMask);
        ifMaskLen = getNetmaskLength(ifMask);

        // prefix isUnspecified -> network = 0.0.0.0 -> all interfaces, or
        // prefix is specified -> classless match
        if (netPrefix.isUnspecified() ||
                (maskedAddrAreEqual(netPrefix, ifAddress, netMask) && netMaskLen <= ifMaskLen)) //TODO - PROB-02 - reused from IPv4 version, is it ok?
        {// IP address of the interface match the prefix
            (*resultNetId) = (*it)->getNetworkId();
            return true;
        }
    }

    return false;
}

template class EigrpNetworkTable<IPv4Address>;

#ifndef DISABLE_EIGRP_IPV6
template class EigrpNetworkTable<IPv6Address>;
#endif /* DISABLE_EIGRP_IPV6 */
}
