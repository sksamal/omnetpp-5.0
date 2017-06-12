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
 * @author Vladimir Vesely (ivesely@fit.vutbr.cz)
 * @copyright Brno University of Technology (www.fit.vutbr.cz) under GPLv3
 */
#ifndef LLDPDEVICECONFIGURATOR_H_
#define LLDPDEVICECONFIGURATOR_H_

#include <omnetpp.h>
#include <algorithm>

#include "ansa/linklayer/lldp/LLDPMain.h"
//#include "ansa/linklayer/lldp/tables/LLDPAgentTable.h"

namespace inet {
class INET_API LLDPDeviceConfigurator
{

   private:
      const char *deviceId = nullptr;
      const char *deviceType = nullptr;
      cXMLElement* configFile = nullptr;
      cXMLElement *device = nullptr;

   protected:
      IInterfaceTable *ift = nullptr;

   public:
      LLDPDeviceConfigurator();
      LLDPDeviceConfigurator(const char* devId, const char* devType, cXMLElement* confFile, IInterfaceTable* intf);
      virtual ~LLDPDeviceConfigurator();

      //xmlParser
      static bool Str2Int(int *retValue, const char *str);

      static cXMLElement * GetDevice(const char *deviceType, const char *deviceId, cXMLElement* configFile);
      static cXMLElement * GetInterface(cXMLElement *iface, cXMLElement *device);

      /////////////////////////////
      // configuration for LLDP  //
      /////////////////////////////
      void loadLLDPConfig(LLDPMain *lMain);
      void loadLLDPInterfacesConfig(cXMLElement *device, LLDPMain *lMain);
      void loadLLDPInterface(cXMLElement *ifaceElem, LLDPMain *lMain, LLDPAgent *lIface);
};


} /* namespace inet */

#endif /* LLDPDEVICECONFIGURATOR_H_ */
