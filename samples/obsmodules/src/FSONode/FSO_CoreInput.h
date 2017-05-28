//
// Suraj modified for FSO
//

#include<omnetpp.h>
#include<map>

using namespace std;
using namespace omnetpp;

//! This module acts as an interface to the core node's modules (control unit and OXC). Separates data and control channels.
//! Also, this implements methods to translate "colours" to physical gate IDs.
class FSO_CoreInput : public cSimpleModule{
   private:
      vector< map<int,int> > colours; //!< Input colour map.
      int numPorts; //!< Number of connected fibers.
      int *inPortBegin; //!< This array stores the input gate index to which the beginning of each optical fiber is connected. For example: If lambdasPerPort is "3 2 3", it will be "0 4 7".
      int *outDataBegin; //!< This array stores the output gate index to which the beginning of the data channels of each optical fiber is connected. For example: If lambdasPerPort is "3 2 3", it will be "3 6 8".
      int *portLen; //!< Number of channels (data+control) for each optical fiber.
   public:
      virtual ~FSO_CoreInput();
      //! Return the OXC gate where burst will pass through.
      int getOXCGate(int port, int lambda);
      //! The name explains itself :)
      int getLambdaByColour(int port,int colour);
   protected:
      virtual void initialize();
      virtual void handleMessage(cMessage *msg);
      int getInPort(int gateIndex);
      int getInLambda(int gateIndex);
};
