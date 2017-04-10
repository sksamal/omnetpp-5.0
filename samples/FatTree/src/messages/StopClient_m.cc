//
// Generated file, do not edit! Created by nedtool 4.6 from messages/StopClient.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "StopClient_m.h"

USING_NAMESPACE


// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




// Template rule for outputting std::vector<T> types
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

Register_Class(StopClient);

StopClient::StopClient(const char *name, int kind) : ::GenericAppMsg(name,kind)
{
    this->delay_var = 0;
    this->clientIsOff_var = 0;
    this->connIDSysCon_var = 0;
    this->clientAddr_var = 0;
    this->serviceport_var = 0;
}

StopClient::StopClient(const StopClient& other) : ::GenericAppMsg(other)
{
    copy(other);
}

StopClient::~StopClient()
{
}

StopClient& StopClient::operator=(const StopClient& other)
{
    if (this==&other) return *this;
    ::GenericAppMsg::operator=(other);
    copy(other);
    return *this;
}

void StopClient::copy(const StopClient& other)
{
    this->delay_var = other.delay_var;
    this->clientIsOff_var = other.clientIsOff_var;
    this->connIDSysCon_var = other.connIDSysCon_var;
    this->clientAddr_var = other.clientAddr_var;
    this->serviceport_var = other.serviceport_var;
}

void StopClient::parsimPack(cCommBuffer *b)
{
    ::GenericAppMsg::parsimPack(b);
    doPacking(b,this->delay_var);
    doPacking(b,this->clientIsOff_var);
    doPacking(b,this->connIDSysCon_var);
    doPacking(b,this->clientAddr_var);
    doPacking(b,this->serviceport_var);
}

void StopClient::parsimUnpack(cCommBuffer *b)
{
    ::GenericAppMsg::parsimUnpack(b);
    doUnpacking(b,this->delay_var);
    doUnpacking(b,this->clientIsOff_var);
    doUnpacking(b,this->connIDSysCon_var);
    doUnpacking(b,this->clientAddr_var);
    doUnpacking(b,this->serviceport_var);
}

int StopClient::getDelay() const
{
    return delay_var;
}

void StopClient::setDelay(int delay)
{
    this->delay_var = delay;
}

bool StopClient::getClientIsOff() const
{
    return clientIsOff_var;
}

void StopClient::setClientIsOff(bool clientIsOff)
{
    this->clientIsOff_var = clientIsOff;
}

int StopClient::getConnIDSysCon() const
{
    return connIDSysCon_var;
}

void StopClient::setConnIDSysCon(int connIDSysCon)
{
    this->connIDSysCon_var = connIDSysCon;
}

const char * StopClient::getClientAddr() const
{
    return clientAddr_var.c_str();
}

void StopClient::setClientAddr(const char * clientAddr)
{
    this->clientAddr_var = clientAddr;
}

int StopClient::getServiceport() const
{
    return serviceport_var;
}

void StopClient::setServiceport(int serviceport)
{
    this->serviceport_var = serviceport;
}

class StopClientDescriptor : public cClassDescriptor
{
  public:
    StopClientDescriptor();
    virtual ~StopClientDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(StopClientDescriptor);

StopClientDescriptor::StopClientDescriptor() : cClassDescriptor("StopClient", "GenericAppMsg")
{
}

StopClientDescriptor::~StopClientDescriptor()
{
}

bool StopClientDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<StopClient *>(obj)!=NULL;
}

const char *StopClientDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int StopClientDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount(object) : 5;
}

unsigned int StopClientDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *StopClientDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "delay",
        "clientIsOff",
        "connIDSysCon",
        "clientAddr",
        "serviceport",
    };
    return (field>=0 && field<5) ? fieldNames[field] : NULL;
}

int StopClientDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='d' && strcmp(fieldName, "delay")==0) return base+0;
    if (fieldName[0]=='c' && strcmp(fieldName, "clientIsOff")==0) return base+1;
    if (fieldName[0]=='c' && strcmp(fieldName, "connIDSysCon")==0) return base+2;
    if (fieldName[0]=='c' && strcmp(fieldName, "clientAddr")==0) return base+3;
    if (fieldName[0]=='s' && strcmp(fieldName, "serviceport")==0) return base+4;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *StopClientDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "bool",
        "int",
        "string",
        "int",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : NULL;
}

const char *StopClientDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int StopClientDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    StopClient *pp = (StopClient *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string StopClientDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    StopClient *pp = (StopClient *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getDelay());
        case 1: return bool2string(pp->getClientIsOff());
        case 2: return long2string(pp->getConnIDSysCon());
        case 3: return oppstring2string(pp->getClientAddr());
        case 4: return long2string(pp->getServiceport());
        default: return "";
    }
}

bool StopClientDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    StopClient *pp = (StopClient *)object; (void)pp;
    switch (field) {
        case 0: pp->setDelay(string2long(value)); return true;
        case 1: pp->setClientIsOff(string2bool(value)); return true;
        case 2: pp->setConnIDSysCon(string2long(value)); return true;
        case 3: pp->setClientAddr((value)); return true;
        case 4: pp->setServiceport(string2long(value)); return true;
        default: return false;
    }
}

const char *StopClientDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *StopClientDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    StopClient *pp = (StopClient *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


