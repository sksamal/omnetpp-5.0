//
// Copyright (C) 2010-2012 Javier Armendariz Silva, Naiara Garcia Royo
// Copyright (C) 2010-2012 Universidad Publica de Navarra
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

#include "OBS_BurstDisassembler.h"

Define_Module(OBS_BurstDisassembler);

OBS_BurstDisassembler::~OBS_BurstDisassembler(){
   //Cleanup receivedBurst queue
   list<OBS_Burst*>::iterator iter_list;
   OBS_Burst *item;
   for(iter_list = receivedBursts.begin();iter_list != receivedBursts.end(); iter_list++){
      item = *iter_list;
      delete item;
   }
   receivedBursts.clear();
}

void OBS_BurstDisassembler::initialize(){
   recvBursts = 0;
   fakeBursts.setName("fakeBurstSize");

   listSize = 0;
   VlistSize.setName("listSize");

   WATCH(recvBursts);
}

void OBS_BurstDisassembler::handleMessage(cMessage *msg){
   if(dynamic_cast< OBS_Burst *> (msg) == NULL){ delete msg; return; } //BCP's shouldn't pass to this point

   if(msg->getKind() == 1){ //Burst beginning. Put this message to the queue

      take(msg); //take ownership
      OBS_Burst *recvBurst = check_and_cast < OBS_Burst*> (msg);
      receivedBursts.push_back(recvBurst);
      //Add this burst in the received burst counter
      recvBursts++;

      listSize++;
      VlistSize.record(listSize);

   }
   else if(msg->getKind() == 2){ //Burst end. Search the beginning message and disassemble it
      OBS_Burst *recvBurst = check_and_cast < OBS_Burst*> (msg);
      int bId,nSeq; //burst ID values
   
      bId = recvBurst->getBurstifierId();
      nSeq = recvBurst->getNumSeq();

      list<OBS_Burst*>::iterator i;
      OBS_Burst* actElem;
      // Search from the beginning because the burst that we are looking for is probably one of the oldest. (less iterations = more efficient) :)
      for(i = receivedBursts.begin(); i != receivedBursts.end(); i++){
         actElem = *i;
         if((actElem->getBurstifierId() == bId) && (actElem->getNumSeq() == nSeq)) break; //Burst found!
      }
   
      if(i != receivedBursts.end()){ //If the iterator above didn't reach to the end... it means the burst was found.
         OBS_Burst *burstIni= check_and_cast< OBS_Burst* > (*i);
         //if burst's queue is empty, it's a "fake" burst (generated by OBS_FileBurstifier)
         if(!burstIni->hasMessages()){
            //register its length into a vector
        	 fakeBursts.record(burstIni->getByteLength());
         }  

         cMessage *tempPack;
         while(burstIni->hasMessages()){ //Release packets until burstIni queue is empty
            tempPack = burstIni->retrieveMessage();
            //TODO: Send packets to an intermediate buffer so all packets won't be released to electrical network at the same time
            send(tempPack,"out");
         }
         //Cleanup
         delete msg;
         delete burstIni;
         i = receivedBursts.erase(i);

         listSize--;
         VlistSize.record(listSize);
      }
      else{
         printf("<OBS_BurstDissasembler><t=%s> Error!! burst with id=(%d,%d) not found!\n",simTime().str().c_str(),bId,nSeq);
         delete msg;
      }
   }
}

void OBS_BurstDisassembler::finish(){
   recordScalar("received Bursts",recvBursts);   
}
