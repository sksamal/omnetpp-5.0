//
// Generated file, do not edit! Created by nedtool 4.6 from messages/TTimerCon.msg.
//

#ifndef _TTIMERCON_M_H_
#define _TTIMERCON_M_H_

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0406
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



// cplusplus {{
#include "GenericAppMsg_m.h"
// }}

/**
 * Class generated from <tt>messages/TTimerCon.msg:24</tt> by nedtool.
 * <pre>
 * //
 * // TODO generated message class
 * //
 * packet TTimerCon extends GenericAppMsg
 * {
 * }
 * </pre>
 */
class TTimerCon : public ::GenericAppMsg
{
  protected:

  private:
    void copy(const TTimerCon& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const TTimerCon&);

  public:
    TTimerCon(const char *name=NULL, int kind=0);
    TTimerCon(const TTimerCon& other);
    virtual ~TTimerCon();
    TTimerCon& operator=(const TTimerCon& other);
    virtual TTimerCon *dup() const {return new TTimerCon(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
};

inline void doPacking(cCommBuffer *b, TTimerCon& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, TTimerCon& obj) {obj.parsimUnpack(b);}


#endif // ifndef _TTIMERCON_M_H_
