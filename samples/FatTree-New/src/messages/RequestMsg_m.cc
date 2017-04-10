//
// Generated file, do not edit! Created by nedtool 4.6 from messages/RequestMsg.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "RequestMsg_m.h"

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

Register_Class(RequestMsg);

RequestMsg::RequestMsg(const char *name, int kind) : ::GenericAppMsg(name,kind)
{
    this->connID_var = 0;
    this->serviceport_var = 0;
    this->depTime_var = 0;
}

RequestMsg::RequestMsg(const RequestMsg& other) : ::GenericAppMsg(other)
{
    copy(other);
}

RequestMsg::~RequestMsg()
{
}

RequestMsg& RequestMsg::operator=(const RequestMsg& other)
{
    if (this==&other) return *this;
    ::GenericAppMsg::operator=(other);
    copy(other);
    return *this;
}

void RequestMsg::copy(const RequestMsg& other)
{
    this->connID_var = other.connID_var;
    this->serviceport_var = other.serviceport_var;
    this->depTime_var = other.depTime_var;
}

void RequestMsg::parsimPack(cCommBuffer *b)
{
    ::GenericAppMsg::parsimPack(b);
    doPacking(b,this->connID_var);
    doPacking(b,this->serviceport_var);
    doPacking(b,this->depTime_var);
}

void RequestMsg::parsimUnpack(cCommBuffer *b)
{
    ::GenericAppMsg::parsimUnpack(b);
    doUnpacking(b,this->connID_var);
    doUnpacking(b,this->serviceport_var);
    doUnpacking(b,this->depTime_var);
}

int RequestMsg::getConnID() const
{
    return connID_var;
}

void RequestMsg::setConnID(int connID)
{
    this->connID_var = connID;
}

int RequestMsg::getServiceport() const
{
    return serviceport_var;
}

void RequestMsg::setServiceport(int serviceport)
{
    this->serviceport_var = serviceport;
}

double RequestMsg::getDepTime() const
{
    return depTime_var;
}

void RequestMsg::setDepTime(double depTime)
{
    this->depTime_var = depTime;
}

class RequestMsgDescriptor : public cClassDescriptor
{
  public:
    RequestMsgDescriptor();
    virtual ~RequestMsgDescriptor();

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

Register_ClassDescriptor(RequestMsgDescriptor);

RequestMsgDescriptor::RequestMsgDescriptor() : cClassDescriptor("RequestMsg", "GenericAppMsg")
{
}

RequestMsgDescriptor::~RequestMsgDescriptor()
{
}

bool RequestMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<RequestMsg *>(obj)!=NULL;
}

const char *RequestMsgDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int RequestMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int RequestMsgDescriptor::getFieldTypeFlags(void *object, int field) const
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
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *RequestMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "connID",
        "serviceport",
        "depTime",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int RequestMsgDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "connID")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "serviceport")==0) return base+1;
    if (fieldName[0]=='d' && strcmp(fieldName, "depTime")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *RequestMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "double",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *RequestMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int RequestMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    RequestMsg *pp = (RequestMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string RequestMsgDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    RequestMsg *pp = (RequestMsg *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getConnID());
        case 1: return long2string(pp->getServiceport());
        case 2: return double2string(pp->getDepTime());
        default: return "";
    }
}

bool RequestMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    RequestMsg *pp = (RequestMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setConnID(string2long(value)); return true;
        case 1: pp->setServiceport(string2long(value)); return true;
        case 2: pp->setDepTime(string2double(value)); return true;
        default: return false;
    }
}

const char *RequestMsgDescriptor::getFieldStructName(void *object, int field) const
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

void *RequestMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    RequestMsg *pp = (RequestMsg *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


