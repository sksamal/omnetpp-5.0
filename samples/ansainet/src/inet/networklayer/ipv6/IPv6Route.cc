//
// Copyright (C) 2005 Andras Varga
// Copyright (C) 2005 Wei Yang, Ng
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this program; if not, see <http://www.gnu.org/licenses/>.
//

#include "inet/networklayer/ipv6/IPv6Route.h"
#include "inet/networklayer/ipv6/IPv6RoutingTable.h"

#include "IPv6RoutingTable.h"

namespace inet {

Register_Abstract_Class(IPv6Route);

#ifdef ANSAINET
const char* inet::IPv6Route::getSourceTypeAbbreviation() const {
    switch (_sourceType) {
        case IFACENETMASK:
            return "C";
        case MANUAL:
            return (getDestPrefix().isUnspecified() ? "S*": "S");
        case ROUTER_ADVERTISEMENT:
            return "ra";
        case RIP:
            return "R";
        case OSPF:
            return "O";
        case BGP:
            return "B";
        case EIGRP:
            return getAdminDist() < IPv6Route::dEIGRPExternal ? "D" : "D EX";
        case LISP:
            return "l";
        case BABEL:
            return "ba";
        case ODR:
            return "o";
        default:
            return "???";
    }
}
#endif

std::string IPv6Route::info() const
{
    std::stringstream out;
#ifdef ANSAINET
    out << getSourceTypeAbbreviation();
    out << " ";
    if (getDestPrefix().isUnspecified())
        out << "::";
    else
        out << getDestPrefix();
    out << "/" << getPrefixLength();
    if (getNextHop().isUnspecified())
    {
        out << " is directly connected";
    }
    else
    {
        out << " [" << getAdminDist() << "/" << getMetric() << "]";
        out << " via ";
        out << getNextHop();
    }
    out << ", " << getInterface()->getName();
#else
    out << getDestPrefix() << "/" << getPrefixLength() << " --> ";
    out << "if:" << (_interfacePtr ? _interfacePtr->getName() : "*  ");
    out << " next hop:" << getNextHop();
    out << " " << IRoute::sourceTypeName(getSourceType());
    if (getExpiryTime() > 0)
        out << " exp:" << getExpiryTime();
#endif
    return out.str();

}

std::string IPv6Route::detailedInfo() const
{
    return std::string();
}

void IPv6Route::changed(int fieldCode)
{
    if (_rt)
        _rt->routeChanged(this, fieldCode);
}

IRoutingTable *IPv6Route::getRoutingTableAsGeneric() const
{
    return getRoutingTable();
}

} // namespace inet

