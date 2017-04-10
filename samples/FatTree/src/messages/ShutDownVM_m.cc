//
// Generated file, do not edit! Created by nedtool 4.6 from messages/ShutDownVM.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "ShutDownVM_m.h"

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

Register_Class(ShutDownVM);

ShutDownVM::ShutDownVM(const char *name, int kind) : ::GenericAppMsg(name,kind)
{
    this->vmaddress_var = 0;
    this->serviceport_var = 0;
    this->connIDtoCon_var = 0;
    this->serverState_var = 0;
}

ShutDownVM::ShutDownVM(const ShutDownVM& other) : ::GenericAppMsg(other)
{
    copy(other);
}

ShutDownVM::~ShutDownVM()
{
}

ShutDownVM& ShutDownVM::operator=(const ShutDownVM& other)
{
    if (this==&other) return *this;
    ::GenericAppMsg::operator=(other);
    copy(other);
    return *this;
}

void ShutDownVM::copy(const ShutDownVM& other)
{
    this->vmaddress_var = other.vmaddress_var;
    this->serviceport_var = other.serviceport_var;
    this->connIDtoCon_var = other.connIDtoCon_var;
    this->serverState_var = other.serverState_var;
}

void ShutDownVM::parsimPack(cCommBuffer *b)
{
    ::GenericAppMsg::parsimPack(b);
    doPacking(b,this->vmaddress_var);
    doPacking(b,this->serviceport_var);
    doPacking(b,this->connIDtoCon_var);
    doPacking(b,this->serverState_var);
}

void ShutDownVM::parsimUnpack(cCommBuffer *b)
{
    ::GenericAppMsg::parsimUnpack(b);
    doUnpacking(b,this->vmaddress_var);
    doUnpacking(b,this->serviceport_var);
    doUnpacking(b,this->connIDtoCon_var);
    doUnpacking(b,this->serverState_var);
}

const char * ShutDownVM::getVmaddress() const
{
    return vmaddress_var.c_str();
}

void ShutDownVM::setVmaddress(const char * vmaddress)
{
    this->vmaddress_var = vmaddress;
}

int ShutDownVM::getServiceport() const
{
    return serviceport_var;
}

void ShutDownVM::setServiceport(int serviceport)
{
    this->serviceport_var = serviceport;
}

int ShutDownVM::getConnIDtoCon() const
{
    return connIDtoCon_var;
}

void ShutDownVM::setConnIDtoCon(int connIDtoCon)
{
    this->connIDtoCon_var = connIDtoCon;
}

bool ShutDownVM::getServerState() const
{
    return serverState_var;
}

void ShutDownVM::setServerState(bool serverState)
{
    this->serverState_var = serverState;
}

class ShutDownVMDescriptor : public cClassDescriptor
{
  public:
    ShutDownVMDescriptor();
    virtual ~ShutDownVMDescriptor();

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

Register_ClassDescriptor(ShutDownVMDescriptor);

ShutDownVMDescriptor::ShutDownVMDescriptor() : cClassDescriptor("ShutDownVM", "GenericAppMsg")
{
}

ShutDownVMDescriptor::~ShutDownVMDescriptor()
{
}

bool ShutDownVMDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<ShutDownVM *>(obj)!=NULL;
}

const char *ShutDownVMDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int ShutDownVMDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount(object) : 4;
}

unsigned int ShutDownVMDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *ShutDownVMDescriptor::getFieldName(void *object, int field) const
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
    };
    return (field>=0 && field<4) ? fieldNames[field] : NULL;
}

int ShutDownVMDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='v' && strcmp(fieldName, "vmaddress")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "serviceport")==0) return base+1;
    if (fieldName[0]=='c' && strcmp(fieldName, "connIDtoCon")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "serverState")==0) return base+3;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *ShutDownVMDescriptor::getFieldTypeString(void *object, int field) const
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
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : NULL;
}

const char *ShutDownVMDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int ShutDownVMDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    ShutDownVM *pp = (ShutDownVM *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string ShutDownVMDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    ShutDownVM *pp = (ShutDownVM *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getVmaddress());
        case 1: return long2string(pp->getServiceport());
        case 2: return long2string(pp->getConnIDtoCon());
        case 3: return bool2string(pp->getServerState());
        default: return "";
    }
}

bool ShutDownVMDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    ShutDownVM *pp = (ShutDownVM *)object; (void)pp;
    switch (field) {
        case 0: pp->setVmaddress((value)); return true;
        case 1: pp->setServiceport(string2long(value)); return true;
        case 2: pp->setConnIDtoCon(string2long(value)); return true;
        case 3: pp->setServerState(string2bool(value)); return true;
        default: return false;
    }
}

const char *ShutDownVMDescriptor::getFieldStructName(void *object, int field) const
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

void *ShutDownVMDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    ShutDownVM *pp = (ShutDownVM *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


