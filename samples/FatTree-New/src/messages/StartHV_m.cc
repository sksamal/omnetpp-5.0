//
// Generated file, do not edit! Created by nedtool 4.6 from messages/StartHV.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "StartHV_m.h"

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

EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("SourceNames");
    if (!e) enums.getInstance()->add(e = new cEnum("SourceNames"));
    e->insert(VM, "VM");
    e->insert(CONTROLLER, "CONTROLLER");
);

Register_Class(StartHV);

StartHV::StartHV(const char *name, int kind) : ::GenericAppMsg(name,kind)
{
    this->hvaddress_var = 0;
    this->source_var = 0;
    this->serverState_var = 0;
}

StartHV::StartHV(const StartHV& other) : ::GenericAppMsg(other)
{
    copy(other);
}

StartHV::~StartHV()
{
}

StartHV& StartHV::operator=(const StartHV& other)
{
    if (this==&other) return *this;
    ::GenericAppMsg::operator=(other);
    copy(other);
    return *this;
}

void StartHV::copy(const StartHV& other)
{
    this->hvaddress_var = other.hvaddress_var;
    this->source_var = other.source_var;
    this->serverState_var = other.serverState_var;
}

void StartHV::parsimPack(cCommBuffer *b)
{
    ::GenericAppMsg::parsimPack(b);
    doPacking(b,this->hvaddress_var);
    doPacking(b,this->source_var);
    doPacking(b,this->serverState_var);
}

void StartHV::parsimUnpack(cCommBuffer *b)
{
    ::GenericAppMsg::parsimUnpack(b);
    doUnpacking(b,this->hvaddress_var);
    doUnpacking(b,this->source_var);
    doUnpacking(b,this->serverState_var);
}

const char * StartHV::getHvaddress() const
{
    return hvaddress_var.c_str();
}

void StartHV::setHvaddress(const char * hvaddress)
{
    this->hvaddress_var = hvaddress;
}

int StartHV::getSource() const
{
    return source_var;
}

void StartHV::setSource(int source)
{
    this->source_var = source;
}

bool StartHV::getServerState() const
{
    return serverState_var;
}

void StartHV::setServerState(bool serverState)
{
    this->serverState_var = serverState;
}

class StartHVDescriptor : public cClassDescriptor
{
  public:
    StartHVDescriptor();
    virtual ~StartHVDescriptor();

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

Register_ClassDescriptor(StartHVDescriptor);

StartHVDescriptor::StartHVDescriptor() : cClassDescriptor("StartHV", "GenericAppMsg")
{
}

StartHVDescriptor::~StartHVDescriptor()
{
}

bool StartHVDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<StartHV *>(obj)!=NULL;
}

const char *StartHVDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int StartHVDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int StartHVDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *StartHVDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "hvaddress",
        "source",
        "serverState",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int StartHVDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='h' && strcmp(fieldName, "hvaddress")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "source")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "serverState")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *StartHVDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "int",
        "bool",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *StartHVDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 1:
            if (!strcmp(propertyname,"enum")) return "SourceNames";
            return NULL;
        default: return NULL;
    }
}

int StartHVDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    StartHV *pp = (StartHV *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string StartHVDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    StartHV *pp = (StartHV *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getHvaddress());
        case 1: return long2string(pp->getSource());
        case 2: return bool2string(pp->getServerState());
        default: return "";
    }
}

bool StartHVDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    StartHV *pp = (StartHV *)object; (void)pp;
    switch (field) {
        case 0: pp->setHvaddress((value)); return true;
        case 1: pp->setSource(string2long(value)); return true;
        case 2: pp->setServerState(string2bool(value)); return true;
        default: return false;
    }
}

const char *StartHVDescriptor::getFieldStructName(void *object, int field) const
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

void *StartHVDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    StartHV *pp = (StartHV *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


