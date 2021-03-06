//
// Generated file, do not edit! Created by nedtool 5.0 from TelnetPkt.msg.
//

#ifndef __TELNETPKT_M_H
#define __TELNETPKT_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0500
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



// cplusplus {{
#include "NetPkt_m.h"
// }}

/**
 * Class generated from <tt>TelnetPkt.msg:22</tt> by nedtool.
 * <pre>
 * //
 * // Message class for representing a Telnet packet (bytes carried in TCP).
 * // For purposes of this model, we don't care about TCP connection setup
 * // and teardown, about TCP acks, or finite IP packet size.
 * //
 * packet TelnetPkt extends NetPkt
 * {
 *     string payload;
 * }
 * </pre>
 */
class TelnetPkt : public ::NetPkt
{
  protected:
    ::omnetpp::opp_string payload;

  private:
    void copy(const TelnetPkt& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const TelnetPkt&);

  public:
    TelnetPkt(const char *name=nullptr, int kind=0);
    TelnetPkt(const TelnetPkt& other);
    virtual ~TelnetPkt();
    TelnetPkt& operator=(const TelnetPkt& other);
    virtual TelnetPkt *dup() const {return new TelnetPkt(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b);

    // field getter/setter methods
    virtual const char * getPayload() const;
    virtual void setPayload(const char * payload);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const TelnetPkt& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, TelnetPkt& obj) {obj.parsimUnpack(b);}


#endif // ifndef __TELNETPKT_M_H

