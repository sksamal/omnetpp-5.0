//
//

#include<omnetpp.h>
#include<map>
#include<vector>

using namespace std;
using namespace omnetpp;


//! This module does the reverse task of CoreInput: Gather both control and data channels and reorder it in order to connect the core node with another OBS node.
//! It also supports "colours" for data channels.
class FSO_CoreOutput : public cSimpleModule{
   private:
      vector< map<int,int> > colours; //!< Output colour map array (one map for each fiber).
      int **gate2Colour; //! Mapping between port/lambda and colours.
      int numPorts; //! Number of connected fibers.
      int *portLen; //! Number of channels (data+control) for each optical fiber.
      int *inDataBegin; //! This array stores the input gate index to which the beginning of the data channels of each optical fiber is connected. For example: If lambdasPerPort is "3 2 3", it will be "3 6 8".
      int *outPortBegin; //! This array stores the output gate index to which the beginning of each optical fiber is connected. For example: If lambdasPerPort is "3 2 3", it will be "0 4 7".
   protected:
      virtual void initialize();
      virtual void handleMessage(cMessage *msg);
      int getOutPort(int gateIndex);
      int getOutLambda(int gateIndex);
   public:
      virtual ~FSO_CoreOutput();
      //! Convert port and lambda to OXC output gate.
      int getOXCGate(int port,int lambda);
      //! The name explains itself :).
      int getLambdaByColour(int port,int colour);
      //! Get output colour by port and lambda.
      int getColourByLambda(int port,int lambda);
};
