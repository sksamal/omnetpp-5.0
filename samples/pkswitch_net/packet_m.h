//
// Generated file, do not edit! Created by nedtool 4.6 from packet.msg.
//

#ifndef _PACKET_M_H_
#define _PACKET_M_H_

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0406
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Enum generated from <tt>packet.msg:6</tt> by nedtool.
 * <pre>
 * enum PayloadTypes
 * {
 * 
 *     routing = 1; // we will use to mark routing packets
 *     data = 2; // best-effort, bulk data
 *     video = 3;
 *     voip = 4;
 * }
 * </pre>
 */
enum PayloadTypes {
    routing = 1,
    data = 2,
    video = 3,
    voip = 4
};

/**
 * Class generated from <tt>packet.msg:18</tt> by nedtool.
 * <pre>
 * //
 * // Represents a packet in the network.
 * //
 * packet Packet
 * {
 *     int srcAddr;
 *     int destAddr;
 *     int hopCount;
 *     int payloadType @enum(PayloadTypes);
 *     unsigned char data[1000];
 * }
 * </pre>
 */
class Packet : public ::cPacket
{
  protected:
    int srcAddr_var;
    int destAddr_var;
    int hopCount_var;
    int payloadType_var;
    unsigned char data_var[1000];

  private:
    void copy(const Packet& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const Packet&);

  public:
    Packet(const char *name=NULL, int kind=0);
    Packet(const Packet& other);
    virtual ~Packet();
    Packet& operator=(const Packet& other);
    virtual Packet *dup() const {return new Packet(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getSrcAddr() const;
    virtual void setSrcAddr(int srcAddr);
    virtual int getDestAddr() const;
    virtual void setDestAddr(int destAddr);
    virtual int getHopCount() const;
    virtual void setHopCount(int hopCount);
    virtual int getPayloadType() const;
    virtual void setPayloadType(int payloadType);
    virtual unsigned int getDataArraySize() const;
    virtual unsigned char getData(unsigned int k) const;
    virtual void setData(unsigned int k, unsigned char data);
};

inline void doPacking(cCommBuffer *b, Packet& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, Packet& obj) {obj.parsimUnpack(b);}


#endif // ifndef _PACKET_M_H_

