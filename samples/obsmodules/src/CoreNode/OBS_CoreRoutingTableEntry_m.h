//
// Generated file, do not edit! Created by nedtool 5.0 from src/CoreNode/OBS_CoreRoutingTableEntry.msg.
//

#ifndef __OBS_COREROUTINGTABLEENTRY_M_H
#define __OBS_COREROUTINGTABLEENTRY_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0500
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>src/CoreNode/OBS_CoreRoutingTableEntry.msg:27</tt> by nedtool.
 * <pre>
 * //
 * // Represents an entry of the Core node routing table.
 * //
 * // Used on OBS_CoreRoutingTable.
 * //
 * class OBS_CoreRoutingTableEntry
 * {
 *     int inPort = -1; //Input port
 *     int inColour = -1; //Input colour
 *     int inLabel = -1; //Input label
 *     int outPort = -1; //Output port
 *     int outColour = -1; //Output colour
 *     int outLabel = -1; //Output label
 * }
 * </pre>
 */
class OBS_CoreRoutingTableEntry : public ::omnetpp::cObject
{
  protected:
    int inPort;
    int inColour;
    int inLabel;
    int outPort;
    int outColour;
    int outLabel;

  private:
    void copy(const OBS_CoreRoutingTableEntry& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const OBS_CoreRoutingTableEntry&);

  public:
    OBS_CoreRoutingTableEntry();
    OBS_CoreRoutingTableEntry(const OBS_CoreRoutingTableEntry& other);
    virtual ~OBS_CoreRoutingTableEntry();
    OBS_CoreRoutingTableEntry& operator=(const OBS_CoreRoutingTableEntry& other);
    virtual OBS_CoreRoutingTableEntry *dup() const {return new OBS_CoreRoutingTableEntry(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b);

    // field getter/setter methods
    virtual int getInPort() const;
    virtual void setInPort(int inPort);
    virtual int getInColour() const;
    virtual void setInColour(int inColour);
    virtual int getInLabel() const;
    virtual void setInLabel(int inLabel);
    virtual int getOutPort() const;
    virtual void setOutPort(int outPort);
    virtual int getOutColour() const;
    virtual void setOutColour(int outColour);
    virtual int getOutLabel() const;
    virtual void setOutLabel(int outLabel);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const OBS_CoreRoutingTableEntry& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, OBS_CoreRoutingTableEntry& obj) {obj.parsimUnpack(b);}


#endif // ifndef __OBS_COREROUTINGTABLEENTRY_M_H
