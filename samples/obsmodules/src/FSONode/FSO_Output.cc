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

#include <FSO_Output.h>

Define_Module(FSO_Output);

FSO_Output::~FSO_Output(){
   int i;
   for(i=0;i<numoxcPorts;i++)
      free(gate2Colour[i]);
   free(gate2Colour);
   free(portLen);
   free(inDataBegin);
   free(outPortBegin);
}

void FSO_Output::initialize(){
   numoxcPorts = par("numoxcPorts");
   
   const char* portLenStr = par("lambdasPerPort").stringValue();
   if(strcmp(portLenStr,"") == 0) throw cRuntimeError("FSO_Output: lambdasPerPort not initialized");

   portLen = (int*)calloc(numoxcPorts,sizeof(int));
   inDataBegin = (int*)calloc(numoxcPorts,sizeof(int));
   outPortBegin = (int*)calloc(numoxcPorts,sizeof(int));

   cStringTokenizer tokenizer(portLenStr);
   int i = 0;
   while(tokenizer.hasMoreTokens()){
      portLen[i] = atoi(tokenizer.nextToken()) + 1; // lambdasPerPort considers only data channels. In this array we include a control channel for each fiber.
      i++;
   }

   inDataBegin[0] = numoxcPorts; // First fiber begins just after control channels

   for(i=1;i<numoxcPorts;i++)
      inDataBegin[i] = inDataBegin[i-1] + (portLen[i-1] - 1); //Adds number of channels (except control) to the previous fiber index

   //This array stores the beginning index of each output fiber
   //Here, we will include control channel
   outPortBegin[0] = 0;

   for(i=1;i<numoxcPorts;i++) //Similar to inDataBegin but here we won't subtract 1 because we will include control channels
      outPortBegin[i] = outPortBegin[i-1] + (portLen[i-1]);

   //Create the inverse colour map: lambda to colour
   //Indexed by port number and lambda, returns the colour
   gate2Colour = (int**)calloc(numoxcPorts,sizeof(int*));
   for(i=0;i<numoxcPorts;i++)
      gate2Colour[i] = (int*)calloc(portLen[i]-1,sizeof(int));

   //Create colour map as a vector of maps. Just the same as CoreInput
   const char* colourString = par("colours");

   map<int,int> tempMap;
   colours.reserve(numoxcPorts);

   //Add the empty string case:
   if(strcmp(colourString,"") == 0){
      int j=0;
      for(i=0;i<numoxcPorts;i++){
		 for(j=0;j<(portLen[i]-1);j++){
            tempMap[j] = j;
            gate2Colour[i][j] = j; // Colour = lambda
         }
         colours.push_back(map<int,int>(tempMap));
         tempMap.clear();
      }
   }else{
      //Begin with parsing process
      cStringTokenizer colourTokenizer(colourString);

      int colourLambda = 0;
      int colourPort = 0;
      int colourValue = 0;
      while(colourTokenizer.hasMoreTokens()){
         const char* token = colourTokenizer.nextToken();
         if(strcmp(token,"|") == 0){ //vertical bar read. Change to the next fiber and reinitialize lambda counter
            colours.push_back(map<int,int>(tempMap));
            colourLambda = 0;
            colourPort++;
            tempMap.clear();
         }else{ //Assume it is an int value (it should). Register this colour
            colourValue = atoi(token);
            tempMap[colourValue] = colourLambda;
            gate2Colour[colourPort][colourLambda] = colourValue;
            colourLambda++;
         }
      }
      //When finished. Insert the rest into the vector
      colours.push_back(map<int,int>(tempMap));
      tempMap.clear(); // All done and clean :)
   }
}

void FSO_Output::handleMessage(cMessage *msg){

    cGate *gate = msg->getArrivalGate();
    int msgPort = getOutPort(gate->getIndex());
    int msgLambda = getOutLambda(gate->getIndex());
    
    msg->setSchedulingPriority(0); //Restore message original priority

    send(msg,"out",outPortBegin[msgPort] + msgLambda); // Simply forward incoming message to the corresponding output gate
}

int FSO_Output::getOutPort(int gateIndex){
   if(gateIndex < numoxcPorts) //It's a BCP
      return gateIndex;
   else{ // Data channel
      int i;
      for(i=0;i<numoxcPorts-1;i++){
         if((gateIndex >= inDataBegin[i]) && (gateIndex < inDataBegin[i+1]))
            return i;
      }
      if((gateIndex >= inDataBegin[numoxcPorts-1]) && (gateIndex < inDataBegin[numoxcPorts-1] + portLen[numoxcPorts-1])) return numoxcPorts - 1;
   }
   return -1;
}

int FSO_Output::getOutLambda(int gateIndex){
   int port = getOutPort(gateIndex); //Use getOutPort to know the fiber where this channel belongs to (in this case, port refers to fiber and gateIndex to OMNeT gate)
   if(gateIndex < numoxcPorts) //BCP
      return portLen[port] - 1; // Return last lambda for this fiber
   else
      return gateIndex - (outPortBegin[port] + (numoxcPorts - port)); // The last sum is made to take into account the first data channel is in a location proportional of the number of fibers
}

int FSO_Output::getOXCGate(int port,int lambda){
   Enter_Method("requesting OXC output gate for port %d, lambda %d\n",port,lambda);
   return inDataBegin[port] + lambda - numoxcPorts;
}

int FSO_Output::getLambdaByColour(int port,int colour){
   Enter_Method("requesting lambda by port %d and colour %d\n",port,colour);
   if (colours[port].count(colour) != 0){//If the colour exists
	   return colours[port][colour];
   }
   else{//If the colour does not exist
	   throw cRuntimeError("The colour \"%d\" does not exist", colour);
	   return -1;
   }
}

int FSO_Output::getColourByLambda(int port,int lambda){
	Enter_Method_Silent();
   return gate2Colour[port][lambda];
}
