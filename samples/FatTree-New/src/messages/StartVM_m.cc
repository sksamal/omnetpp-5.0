//
// Generated file, do not edit! Created by nedtool 4.6 from messages/StartVM.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "StartVM_m.h"

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

Register_Class(StartVM);

StartVM::StartVM(const char *name, int kind) : ::GenericAppMsg(name,kind)
{
    this->vmaddress_var = 0;
    this->serviceport_var = 0;
    this->connIDtoCon_var = 0;
    this->serverState_var = 0;
    this->activeVMSize_var = 0;
}

StartVM::StartVM(const StartVM& other) : ::GenericAppMsg(other)
{
    copy(other);
}

StartVM::~StartVM()
{
}

StartVM& StartVM::operator=(const StartVM& other)
{
    if (this==&other) return *this;
    ::GenericAppMsg::operator=(other);
    copy(other);
    return *this;
}

void StartVM::copy(const StartVM& other)
{
    this->vmaddress_var = other.vmaddress_var;
    this->serviceport_var = other.serviceport_var;
    this->connIDtoCon_var = other.connIDtoCon_var;
    this->serverState_var = other.serverState_var;
    this->activeVMSize_var = other.activeVMSize_var;
}

void StartVM::parsimPack(cCommBuffer *b)
{
    ::GenericAppMsg::parsimPack(b);
    doPacking(b,this->vmaddress_var);
    doPacking(b,this->serviceport_var);
    doPacking(b,this->connIDtoCon_var);
    doPacking(b,this->serverState_var);
    doPacking(b,this->activeVMSize_var);
}

void StartVM::parsimUnpack(cCommBuffer *b)
{
    ::GenericAppMsg::parsimUnpack(b);
    doUnpacking(b,this->vmaddress_var);
    doUnpacking(b,this->serviceport_var);
    doUnpacking(b,this->connIDtoCon_var);
    doUnpacking(b,this->serverState_var);
    doUnpacking(b,this->activeVMSize_var);
}

const char * StartVM::getVmaddress() const
{
    return vmaddress_var.c_str();
}

void StartVM::setVmaddress(const char * vmaddress)
{
    this->vmaddress_var = vmaddress;
}

int StartVM::getServiceport() const
{
    return serviceport_var;
}

void StartVM::setServiceport(int serviceport)
{
    this->serviceport_var = serviceport;
}

int StartVM::getConnIDtoCon() const
{
    return connIDtoCon_var;
}

void StartVM::setConnIDtoCon(int connIDtoCon)
{
    this->connIDtoCon_var = connIDtoCon;
}

bool StartVM::getServerState() const
{
    return serverState_var;
}

void StartVM::setServerState(bool serverState)
{
    this->serverState_var = serverState;
}

int StartVM::getActiveVMSize() const
{
    return activeVMSize_var;
}

void StartVM::setActiveVMSize(int activeVMSize)
{
    this->activeVMSize_var = activeVMSize;
}

class StartVMDescriptor : public cClassDescriptor
{
  public:
    StartVMDescriptor();
    virtual ~StartVMDescriptor();

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

Register_ClassDescriptor(StartVMDescriptor);

StartVMDescriptor::StartVMDescriptor() : cClassDescriptor("StartVM", "GenericAppMsg")
{
}

StartVMDescriptor::~StartVMDescriptor()
{
}

bool StartVMDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<StartVM *>(obj)!=NULL;
}

const char *StartVMDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int StartVMDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount(object) : 5;
}

unsigned int StartVMDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *StartVMDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "vmaddress",
        "serviceport",
        "connIDtoCon",
        "serverState",
        "activeVMSize",
    };
    return (field>=0 && field<5) ? fieldNames[field] : NULL;
}

int StartVMDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='v' && strcmp(fieldName, "vmaddress")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "serviceport")==0) return base+1;
    if (fieldName[0]=='c' && strcmp(fieldName, "connIDtoCon")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "serverState")==0) return base+3;
    if (fieldName[0]=='a' && strcmp(fieldName, "activeVMSize")==0) return base+4;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *StartVMDescriptor::getFieldTypeString(void *object, int field) const
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
        "int",
        "bool",
        "int",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : NULL;
}

const char *StartVMDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int StartVMDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    StartVM *pp = (StartVM *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string StartVMDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    StartVM *pp = (StartVM *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getVmaddress());
        case 1: return long2string(pp->getServiceport());
        case 2: return long2string(pp->getConnIDtoCon());
        case 3: return bool2string(pp->getServerState());
        case 4: return long2string(pp->getActiveVMSize());
        default: return "";
    }
}

bool StartVMDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    StartVM *pp = (StartVM *)object; (void)pp;
    switch (field) {
        case 0: pp->setVmaddress((value)); return true;
        case 1: pp->setServiceport(string2long(value)); return true;
        case 2: pp->setConnIDtoCon(string2long(value)); return true;
        case 3: pp->setServerState(string2bool(value)); return true;
        case 4: pp->setActiveVMSize(string2long(value)); return true;
        default: return false;
    }
}

const char *StartVMDescriptor::getFieldStructName(void *object, int field) const
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

void *StartVMDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    StartVM *pp = (StartVM *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


