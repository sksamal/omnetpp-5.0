//
// Copyright (C) 2012 Naiara Garcia Royo, Felix Espina Antolin
// Copyright (C) 2012 Universidad Publica de Navarra
//
// This file is part of OBSModules.
//
// OBSModules is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// OBSModules is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with OBSModules.  If not, see <http://www.gnu.org/licenses/>.
//
#include <fstream>
#include <omnetpp.h>
//#include "IPDatagram_m.h"
#include "IPv4Datagram.h"
#include "TCPSegment.h"
#include "UDPPacket_m.h"
#include "UDPPacket.h"
#include "OBS_Burst.h"
#include "OBS_BurstifierInfo_m.h"

using namespace std;

//! Burst receiver: receives bursts with or without packets inside of it (with OBS_BurstifierInfo attached).
//! Output for OBS_PacketBurstifier and OBS_FileBurstifier.
class testSink2 : public cSimpleModule{
   protected:
      virtual void initialize();
      virtual void finish();
      virtual void handleMessage(cMessage *msg);
   private:
      void openFiles();
      bool compareFiles();
      void deleteFiles();
      ifstream currentFile, patternFile;
      ofstream outputFile;
      string errorPhrase;
};
