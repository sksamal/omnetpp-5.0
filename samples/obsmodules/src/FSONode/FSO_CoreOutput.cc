//
//
//

#include <FSO_CoreOutput.h>

Define_Module(FSO_CoreOutput);

FSO_CoreOutput::~FSO_CoreOutput(){
   int i;
   for(i=0;i<numPorts;i++)
      free(gate2Colour[i]);
   free(gate2Colour);
   free(portLen);
   free(inDataBegin);
   free(outPortBegin);
}

void FSO_CoreOutput::initialize(){
   numPorts = par("numPorts");
   
   const char* portLenStr = par("lambdasPerPort").stringValue();
   if(strcmp(portLenStr,"") == 0) throw cRuntimeError("FSO_CoreOutput: lambdasPerPort not initialized");

   const char* obsportLenStr = par("lambdasEdge").stringValue();
   if(strcmp(portLenStr,"") == 0) throw cRuntimeError("FSO_CoreInput: lambdasEdge not initialized");

   portLen = (int*)calloc(numPorts,sizeof(int));
   inDataBegin = (int*)calloc(numPorts,sizeof(int));
   outPortBegin = (int*)calloc(numPorts,sizeof(int));

   cStringTokenizer tokenizer(portLenStr);
   int i = 0;
   while(tokenizer.hasMoreTokens()){
      portLen[i] = atoi(tokenizer.nextToken()); // lambdasPerPort considers only data channels. In this array we include a control channel for each fiber.
      i++;
   }

   // Suraj - copy from previous value of not all lambas provided
   for(;i<numPorts-1;i++)
       portLen[i] = portLen[i-1];

   cStringTokenizer obsporttokenizer(obsportLenStr);

   while(obsporttokenizer.hasMoreTokens()){
      portLen[i] = atoi(obsporttokenizer.nextToken()); // lambdasEdge considers only data+ sizeof(obsin) -1) channels. In this array we include a control channel for each fiber.
      i++;
   }

   // Suraj - copy from previous value of not all lambas provided
   for(;i<numPorts;i++)
       portLen[i] = portLen[i-1];

   inDataBegin[0] = numPorts; // First fiber begins just after control channels
   for(i=1;i<numPorts;i++)
      inDataBegin[i] = inDataBegin[i-1] + (portLen[i-1] - 1); //Adds number of channels (except control) to the previous fiber index

   //This array stores the beginning index of each output fiber
   //Here, we will include control channel
   outPortBegin[0] = 0;

   for(i=1;i<numPorts;i++) //Similar to inDataBegin but here we won't subtract 1 because we will include control channels
      outPortBegin[i] = outPortBegin[i-1] + (portLen[i-1]);

   cout<<"FSO_CoreOutPut: (numPorts="<<numPorts<<")\n";
   for(i=0;i<numPorts;i++)
   {
       cout<<"Fiber "<<i<<" input--> control channel= "<<i<<" data (start="<< inDataBegin[i]<<",end="<<inDataBegin[i] + portLen[i]-1 -1<<") output --> (start="<<outPortBegin[i]<< ", end="<<(outPortBegin[i] + portLen[i] - 1)<<")"<<endl;
   }

   //Create the inverse colour map: lambda to colour
   //Indexed by port number and lambda, returns the colour
   gate2Colour = (int**)calloc(numPorts,sizeof(int*));
   for(i=0;i<numPorts;i++)
      gate2Colour[i] = (int*)calloc(portLen[i]-1,sizeof(int));

   //Create colour map as a vector of maps. Just the same as CoreInput
   const char* colourString = par("colours");

   map<int,int> tempMap;
   colours.reserve(numPorts);

   //Add the empty string case:
   if(strcmp(colourString,"") == 0){
      int j=0;
      for(i=0;i<numPorts;i++){
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

void FSO_CoreOutput::handleMessage(cMessage *msg){

    cGate *gate = msg->getArrivalGate();
    int msgPort = getOutPort(gate->getIndex());
    int msgLambda = getOutLambda(gate->getIndex());
    cout << "CoreOutput:: Msg arrived on gate "<<gate->getIndex()<<" (port="<<msgPort<<" lambda="<<msgLambda<<")"<<endl;

    msg->setSchedulingPriority(0); //Restore message original priority

    send(msg,"out",outPortBegin[msgPort] + msgLambda); // Simply forward incoming message to the corresponding output gate
    cout<< "CoreOutput:: Msg sent on gate="<<outPortBegin[msgPort] + msgLambda<<"(port="<<msgPort<<", msgLambda="<<msgLambda<<")"<<endl;
}

int FSO_CoreOutput::getOutPort(int gateIndex){
   if(gateIndex < numPorts) //It's a BCP
      return gateIndex;
   else{ // Data channel
      int i;
      for(i=0;i<numPorts-1;i++){
         if((gateIndex >= inDataBegin[i]) && (gateIndex < inDataBegin[i+1]))
            return i;
      }
      if((gateIndex >= inDataBegin[numPorts-1]) && (gateIndex < inDataBegin[numPorts-1] + portLen[numPorts-1])) return numPorts - 1;
   }
   return -1;
}

int FSO_CoreOutput::getOutLambda(int gateIndex){
   int port = getOutPort(gateIndex); //Use getOutPort to know the fiber where this channel belongs to (in this case, port refers to fiber and gateIndex to OMNeT gate)
   if(gateIndex < numPorts) //BCP
      return portLen[port] - 1; // Return last lambda for this fiber
   else
      return gateIndex - (outPortBegin[port] + (numPorts - port)); // The last sum is made to take into account the first data channel is in a location proportional of the number of fibers
}

int FSO_CoreOutput::getOXCGate(int port,int lambda){
   Enter_Method("requesting OXC output gate for port %d, lambda %d\n",port,lambda);
   return inDataBegin[port] + lambda - numPorts;
}

int FSO_CoreOutput::getLambdaByColour(int port,int colour){
   Enter_Method("requesting lambda by port %d and colour %d\n",port,colour);
   if (colours[port].count(colour) != 0){//If the colour exists
	   return colours[port][colour];
   }
   else{//If the colour does not exist
	   throw cRuntimeError("The colour \"%d\" does not exist", colour);
	   return -1;
   }
}

int FSO_CoreOutput::getColourByLambda(int port,int lambda){
	Enter_Method_Silent();
   return gate2Colour[port][lambda];
}
