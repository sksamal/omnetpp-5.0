//
// Generated file, do not edit! Created by nedtool 4.6 from messages/StartClient.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "StartClient_m.h"

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

Register_Class(StartClient);

StartClient::StartClient(const char *name, int kind) : ::GenericAppMsg(name,kind)
{
    this->delay_var = 0;
    this->clientIsOn_var = 0;
    this->clientAddr_var = 0;
    this->serviceport_var = 0;
}

StartClient::StartClient(const StartClient& other) : ::GenericAppMsg(other)
{
    copy(other);
}

StartClient::~StartClient()
{
}

StartClient& StartClient::operator=(const StartClient& other)
{
    if (this==&other) return *this;
    ::GenericAppMsg::operator=(other);
    copy(other);
    return *this;
}

void StartClient::copy(const StartClient& other)
{
    this->delay_var = other.delay_var;
    this->clientIsOn_var = other.clientIsOn_var;
    this->clientAddr_var = other.clientAddr_var;
    this->serviceport_var = other.serviceport_var;
}

void StartClient::parsimPack(cCommBuffer *b)
{
    ::GenericAppMsg::parsimPack(b);
    doPacking(b,this->delay_var);
    doPacking(b,this->clientIsOn_var);
    doPacking(b,this->clientAddr_var);
    doPacking(b,this->serviceport_var);
}

void StartClient::parsimUnpack(cCommBuffer *b)
{
    ::GenericAppMsg::parsimUnpack(b);
    doUnpacking(b,this->delay_var);
    doUnpacking(b,this->clientIsOn_var);
    doUnpacking(b,this->clientAddr_var);
    doUnpacking(b,this->serviceport_var);
}

int StartClient::getDelay() const
{
    return delay_var;
}

void StartClient::setDelay(int delay)
{
    this->delay_var = delay;
}

bool StartClient::getClientIsOn() const
{
    return clientIsOn_var;
}

void StartClient::setClientIsOn(bool clientIsOn)
{
    this->clientIsOn_var = clientIsOn;
}

const char * StartClient::getClientAddr() const
{
    return clientAddr_var.c_str();
}

void StartClient::setClientAddr(const char * clientAddr)
{
    this->clientAddr_var = clientAddr;
}

int StartClient::getServiceport() const
{
    return serviceport_var;
}

void StartClient::setServiceport(int serviceport)
{
    this->serviceport_var = serviceport;
}

class StartClientDescriptor : public cClassDescriptor
{
  public:
    StartClientDescriptor();
    virtual ~StartClientDescriptor();

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

Register_ClassDescriptor(StartClientDescriptor);

StartClientDescriptor::StartClientDescriptor() : cClassDescriptor("StartClient", "GenericAppMsg")
{
}

StartClientDescriptor::~StartClientDescriptor()
{
}

bool StartClientDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<StartClient *>(obj)!=NULL;
}

const char *StartClientDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int StartClientDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount(object) : 4;
}

unsigned int StartClientDescriptor::getFieldTypeFlags(void *object, int field) const
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
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *StartClientDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "delay",
        "clientIsOn",
        "clientAddr",
        "serviceport",
    };
    return (field>=0 && field<4) ? fieldNames[field] : NULL;
}

int StartClientDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='d' && strcmp(fieldName, "delay")==0) return base+0;
    if (fieldName[0]=='c' && strcmp(fieldName, "clientIsOn")==0) return base+1;
    if (fieldName[0]=='c' && strcmp(fieldName, "clientAddr")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "serviceport")==0) return base+3;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *StartClientDescriptor::getFieldTypeString(void *object, int field) const
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
        "string",
        "int",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : NULL;
}

const char *StartClientDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int StartClientDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    StartClient *pp = (StartClient *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string StartClientDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    StartClient *pp = (StartClient *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getDelay());
        case 1: return bool2string(pp->getClientIsOn());
        case 2: return oppstring2string(pp->getClientAddr());
        case 3: return long2string(pp->getServiceport());
        default: return "";
    }
}

bool StartClientDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    StartClient *pp = (StartClient *)object; (void)pp;
    switch (field) {
        case 0: pp->setDelay(string2long(value)); return true;
        case 1: pp->setClientIsOn(string2bool(value)); return true;
        case 2: pp->setClientAddr((value)); return true;
        case 3: pp->setServiceport(string2long(value)); return true;
        default: return false;
    }
}

const char *StartClientDescriptor::getFieldStructName(void *object, int field) const
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

void *StartClientDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    StartClient *pp = (StartClient *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


