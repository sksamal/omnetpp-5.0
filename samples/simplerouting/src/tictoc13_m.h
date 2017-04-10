//
// Generated file, do not edit! Created by nedtool 4.6 from tictoc13.msg.
//

#ifndef _TICTOC13_M_H_
#define _TICTOC13_M_H_

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0406
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>tictoc13.msg:13</tt> by nedtool.
 * <pre>
 * message TicTocMsg13
 * {
 *     int source;
 *     int destination;
 *     int hopCount = 0;
 * }
 * </pre>
 */
class TicTocMsg13 : public ::cMessage
{
  protected:
    int source_var;
    int destination_var;
    int hopCount_var;

  private:
    void copy(const TicTocMsg13& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const TicTocMsg13&);

  public:
    TicTocMsg13(const char *name=NULL, int kind=0);
    TicTocMsg13(const TicTocMsg13& other);
    virtual ~TicTocMsg13();
    TicTocMsg13& operator=(const TicTocMsg13& other);
    virtual TicTocMsg13 *dup() const {return new TicTocMsg13(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getSource() const;
    virtual void setSource(int source);
    virtual int getDestination() const;
    virtual void setDestination(int destination);
    virtual int getHopCount() const;
    virtual void setHopCount(int hopCount);
};

inline void doPacking(cCommBuffer *b, TicTocMsg13& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, TicTocMsg13& obj) {obj.parsimUnpack(b);}


#endif // ifndef _TICTOC13_M_H_

