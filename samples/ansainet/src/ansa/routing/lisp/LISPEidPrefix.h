//
// Copyright (C) 2013, 2014 Brno University of Technology
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
 * @author Vladimir Vesely / ivesely@fit.vutbr.cz / http://www.fit.vutbr.cz/~ivesely/
 * @copyright Brno University of Technology (www.fit.vutbr.cz) under GPLv3
 */

#ifndef LISPEIDPREFIX_H_
#define LISPEIDPREFIX_H_

#include "inet/networklayer/common/L3Address.h"
#include "ansa/routing/lisp/LISPCommon.h"

namespace inet {
using namespace inet;
class LISPEidPrefix {

  public:

    LISPEidPrefix();
    LISPEidPrefix(const char* address, const char* length);
    LISPEidPrefix(L3Address address, unsigned char length);
    virtual ~LISPEidPrefix();

    bool operator== (const LISPEidPrefix& other) const;
    bool operator< (const LISPEidPrefix& other) const;

    std::string info() const;

    const L3Address& getEidAddr() const;
    void setEidAddr(const L3Address& eid);
    unsigned char getEidLength() const;
    void setEidLength(unsigned char eidLen);
    LISPCommon::Afi getEidAfi() const;

    bool isComponentOf(const LISPEidPrefix& coarserEid) const;

  private:
    L3Address eidAddr;
    L3Address eidNetwork;
    unsigned char eidLen;
};


//Free function
std::ostream& operator<< (std::ostream& os, const LISPEidPrefix& ep);

}

#endif /* LISPEIDPREFIX_H_ */
