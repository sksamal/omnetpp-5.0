//
// Generated file, do not edit! Created by nedtool 4.6 from messages/ShutDownVM.msg.
//

#ifndef _SHUTDOWNVM_M_H_
#define _SHUTDOWNVM_M_H_

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
 * Class generated from <tt>messages/ShutDownVM.msg:13</tt> by nedtool.
 * <pre>
 * //
 * // Msg. to inititate turning off a vm.
 * //
 * packet ShutDownVM extends GenericAppMsg
 * {
 *     string vmaddress;
 *     int serviceport;
 *     int connIDtoCon;
 *     bool serverState;
 * }
 * </pre>
 */
class ShutDownVM : public ::GenericAppMsg
{
  protected:
    opp_string vmaddress_var;
    int serviceport_var;
    int connIDtoCon_var;
    bool serverState_var;

  private:
    void copy(const ShutDownVM& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const ShutDownVM&);

  public:
    ShutDownVM(const char *name=NULL, int kind=0);
    ShutDownVM(const ShutDownVM& other);
    virtual ~ShutDownVM();
    ShutDownVM& operator=(const ShutDownVM& other);
    virtual ShutDownVM *dup() const {return new ShutDownVM(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual const char * getVmaddress() const;
    virtual void setVmaddress(const char * vmaddress);
    virtual int getServiceport() const;
    virtual void setServiceport(int serviceport);
    virtual int getConnIDtoCon() const;
    virtual void setConnIDtoCon(int connIDtoCon);
    virtual bool getServerState() const;
    virtual void setServerState(bool serverState);
};

inline void doPacking(cCommBuffer *b, ShutDownVM& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, ShutDownVM& obj) {obj.parsimUnpack(b);}


#endif // ifndef _SHUTDOWNVM_M_H_

