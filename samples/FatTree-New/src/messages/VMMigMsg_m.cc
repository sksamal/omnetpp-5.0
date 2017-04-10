//
// Generated file, do not edit! Created by nedtool 4.6 from messages/VMMigMsg.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "VMMigMsg_m.h"

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
    cEnum *e = cEnum::find("StateNames");
    if (!e) enums.getInstance()->add(e = new cEnum("StateNames"));
    e->insert(INIT_MIG, "INIT_MIG");
    e->insert(ENABLEHV2, "ENABLEHV2");
    e->insert(HV2ENABLED, "HV2ENABLED");
    e->insert(STARTVMMIG, "STARTVMMIG");
    e->insert(COPYINGDATA, "COPYINGDATA");
    e->insert(COPYSTART, "COPYSTART");
    e->insert(DATARECEIVED, "DATARECEIVED");
    e->insert(COPYSUCCESS, "COPYSUCCESS");
    e->insert(TURNOFFVM1, "TURNOFFVM1");
    e->insert(VM1TURNEDOFF, "VM1TURNEDOFF");
    e->insert(STARTVM2, "STARTVM2");
    e->insert(VM2TURNEDON, "VM2TURNEDON");
    e->insert(STARTSUCCESS, "STARTSUCCESS");
    e->insert(TURNOFFHV1, "TURNOFFHV1");
    e->insert(HV1TURNEDOFF, "HV1TURNEDOFF");
);

Register_Class(VMMigMsg);

VMMigMsg::VMMigMsg(const char *name, int kind) : ::GenericAppMsg(name,kind)
{
    this->msgtype_var = 0;
    this->hv1address_var = 0;
    this->hv2address_var = 0;
    this->vm1address_var = 0;
    this->vm2address_var = 0;
    this->conaddress_var = 0;
    this->turnOffHV1_var = 0;
    this->turnOnHV2_var = 0;
    this->connIdfromHV1ToCon_var = 0;
    this->connIdToMigS_var = 0;
    this->connIdfromHV2ToHV1_var = 0;
    this->serviceport_var = 0;
}

VMMigMsg::VMMigMsg(const VMMigMsg& other) : ::GenericAppMsg(other)
{
    copy(other);
}

VMMigMsg::~VMMigMsg()
{
}

VMMigMsg& VMMigMsg::operator=(const VMMigMsg& other)
{
    if (this==&other) return *this;
    ::GenericAppMsg::operator=(other);
    copy(other);
    return *this;
}

void VMMigMsg::copy(const VMMigMsg& other)
{
    this->msgtype_var = other.msgtype_var;
    this->hv1address_var = other.hv1address_var;
    this->hv2address_var = other.hv2address_var;
    this->vm1address_var = other.vm1address_var;
    this->vm2address_var = other.vm2address_var;
    this->conaddress_var = other.conaddress_var;
    this->turnOffHV1_var = other.turnOffHV1_var;
    this->turnOnHV2_var = other.turnOnHV2_var;
    this->connIdfromHV1ToCon_var = other.connIdfromHV1ToCon_var;
    this->connIdToMigS_var = other.connIdToMigS_var;
    this->connIdfromHV2ToHV1_var = other.connIdfromHV2ToHV1_var;
    this->serviceport_var = other.serviceport_var;
}

void VMMigMsg::parsimPack(cCommBuffer *b)
{
    ::GenericAppMsg::parsimPack(b);
    doPacking(b,this->msgtype_var);
    doPacking(b,this->hv1address_var);
    doPacking(b,this->hv2address_var);
    doPacking(b,this->vm1address_var);
    doPacking(b,this->vm2address_var);
    doPacking(b,this->conaddress_var);
    doPacking(b,this->turnOffHV1_var);
    doPacking(b,this->turnOnHV2_var);
    doPacking(b,this->connIdfromHV1ToCon_var);
    doPacking(b,this->connIdToMigS_var);
    doPacking(b,this->connIdfromHV2ToHV1_var);
    doPacking(b,this->serviceport_var);
}

void VMMigMsg::parsimUnpack(cCommBuffer *b)
{
    ::GenericAppMsg::parsimUnpack(b);
    doUnpacking(b,this->msgtype_var);
    doUnpacking(b,this->hv1address_var);
    doUnpacking(b,this->hv2address_var);
    doUnpacking(b,this->vm1address_var);
    doUnpacking(b,this->vm2address_var);
    doUnpacking(b,this->conaddress_var);
    doUnpacking(b,this->turnOffHV1_var);
    doUnpacking(b,this->turnOnHV2_var);
    doUnpacking(b,this->connIdfromHV1ToCon_var);
    doUnpacking(b,this->connIdToMigS_var);
    doUnpacking(b,this->connIdfromHV2ToHV1_var);
    doUnpacking(b,this->serviceport_var);
}

int VMMigMsg::getMsgtype() const
{
    return msgtype_var;
}

void VMMigMsg::setMsgtype(int msgtype)
{
    this->msgtype_var = msgtype;
}

const char * VMMigMsg::getHv1address() const
{
    return hv1address_var.c_str();
}

void VMMigMsg::setHv1address(const char * hv1address)
{
    this->hv1address_var = hv1address;
}

const char * VMMigMsg::getHv2address() const
{
    return hv2address_var.c_str();
}

void VMMigMsg::setHv2address(const char * hv2address)
{
    this->hv2address_var = hv2address;
}

const char * VMMigMsg::getVm1address() const
{
    return vm1address_var.c_str();
}

void VMMigMsg::setVm1address(const char * vm1address)
{
    this->vm1address_var = vm1address;
}

const char * VMMigMsg::getVm2address() const
{
    return vm2address_var.c_str();
}

void VMMigMsg::setVm2address(const char * vm2address)
{
    this->vm2address_var = vm2address;
}

const char * VMMigMsg::getConaddress() const
{
    return conaddress_var.c_str();
}

void VMMigMsg::setConaddress(const char * conaddress)
{
    this->conaddress_var = conaddress;
}

bool VMMigMsg::getTurnOffHV1() const
{
    return turnOffHV1_var;
}

void VMMigMsg::setTurnOffHV1(bool turnOffHV1)
{
    this->turnOffHV1_var = turnOffHV1;
}

bool VMMigMsg::getTurnOnHV2() const
{
    return turnOnHV2_var;
}

void VMMigMsg::setTurnOnHV2(bool turnOnHV2)
{
    this->turnOnHV2_var = turnOnHV2;
}

int VMMigMsg::getConnIdfromHV1ToCon() const
{
    return connIdfromHV1ToCon_var;
}

void VMMigMsg::setConnIdfromHV1ToCon(int connIdfromHV1ToCon)
{
    this->connIdfromHV1ToCon_var = connIdfromHV1ToCon;
}

int VMMigMsg::getConnIdToMigS() const
{
    return connIdToMigS_var;
}

void VMMigMsg::setConnIdToMigS(int connIdToMigS)
{
    this->connIdToMigS_var = connIdToMigS;
}

int VMMigMsg::getConnIdfromHV2ToHV1() const
{
    return connIdfromHV2ToHV1_var;
}

void VMMigMsg::setConnIdfromHV2ToHV1(int connIdfromHV2ToHV1)
{
    this->connIdfromHV2ToHV1_var = connIdfromHV2ToHV1;
}

int VMMigMsg::getServiceport() const
{
    return serviceport_var;
}

void VMMigMsg::setServiceport(int serviceport)
{
    this->serviceport_var = serviceport;
}

class VMMigMsgDescriptor : public cClassDescriptor
{
  public:
    VMMigMsgDescriptor();
    virtual ~VMMigMsgDescriptor();

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

Register_ClassDescriptor(VMMigMsgDescriptor);

VMMigMsgDescriptor::VMMigMsgDescriptor() : cClassDescriptor("VMMigMsg", "GenericAppMsg")
{
}

VMMigMsgDescriptor::~VMMigMsgDescriptor()
{
}

bool VMMigMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<VMMigMsg *>(obj)!=NULL;
}

const char *VMMigMsgDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int VMMigMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 12+basedesc->getFieldCount(object) : 12;
}

unsigned int VMMigMsgDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<12) ? fieldTypeFlags[field] : 0;
}

const char *VMMigMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "msgtype",
        "hv1address",
        "hv2address",
        "vm1address",
        "vm2address",
        "conaddress",
        "turnOffHV1",
        "turnOnHV2",
        "connIdfromHV1ToCon",
        "connIdToMigS",
        "connIdfromHV2ToHV1",
        "serviceport",
    };
    return (field>=0 && field<12) ? fieldNames[field] : NULL;
}

int VMMigMsgDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='m' && strcmp(fieldName, "msgtype")==0) return base+0;
    if (fieldName[0]=='h' && strcmp(fieldName, "hv1address")==0) return base+1;
    if (fieldName[0]=='h' && strcmp(fieldName, "hv2address")==0) return base+2;
    if (fieldName[0]=='v' && strcmp(fieldName, "vm1address")==0) return base+3;
    if (fieldName[0]=='v' && strcmp(fieldName, "vm2address")==0) return base+4;
    if (fieldName[0]=='c' && strcmp(fieldName, "conaddress")==0) return base+5;
    if (fieldName[0]=='t' && strcmp(fieldName, "turnOffHV1")==0) return base+6;
    if (fieldName[0]=='t' && strcmp(fieldName, "turnOnHV2")==0) return base+7;
    if (fieldName[0]=='c' && strcmp(fieldName, "connIdfromHV1ToCon")==0) return base+8;
    if (fieldName[0]=='c' && strcmp(fieldName, "connIdToMigS")==0) return base+9;
    if (fieldName[0]=='c' && strcmp(fieldName, "connIdfromHV2ToHV1")==0) return base+10;
    if (fieldName[0]=='s' && strcmp(fieldName, "serviceport")==0) return base+11;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *VMMigMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "string",
        "string",
        "string",
        "string",
        "string",
        "bool",
        "bool",
        "int",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<12) ? fieldTypeStrings[field] : NULL;
}

const char *VMMigMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "StateNames";
            return NULL;
        default: return NULL;
    }
}

int VMMigMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    VMMigMsg *pp = (VMMigMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string VMMigMsgDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    VMMigMsg *pp = (VMMigMsg *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getMsgtype());
        case 1: return oppstring2string(pp->getHv1address());
        case 2: return oppstring2string(pp->getHv2address());
        case 3: return oppstring2string(pp->getVm1address());
        case 4: return oppstring2string(pp->getVm2address());
        case 5: return oppstring2string(pp->getConaddress());
        case 6: return bool2string(pp->getTurnOffHV1());
        case 7: return bool2string(pp->getTurnOnHV2());
        case 8: return long2string(pp->getConnIdfromHV1ToCon());
        case 9: return long2string(pp->getConnIdToMigS());
        case 10: return long2string(pp->getConnIdfromHV2ToHV1());
        case 11: return long2string(pp->getServiceport());
        default: return "";
    }
}

bool VMMigMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    VMMigMsg *pp = (VMMigMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setMsgtype(string2long(value)); return true;
        case 1: pp->setHv1address((value)); return true;
        case 2: pp->setHv2address((value)); return true;
        case 3: pp->setVm1address((value)); return true;
        case 4: pp->setVm2address((value)); return true;
        case 5: pp->setConaddress((value)); return true;
        case 6: pp->setTurnOffHV1(string2bool(value)); return true;
        case 7: pp->setTurnOnHV2(string2bool(value)); return true;
        case 8: pp->setConnIdfromHV1ToCon(string2long(value)); return true;
        case 9: pp->setConnIdToMigS(string2long(value)); return true;
        case 10: pp->setConnIdfromHV2ToHV1(string2long(value)); return true;
        case 11: pp->setServiceport(string2long(value)); return true;
        default: return false;
    }
}

const char *VMMigMsgDescriptor::getFieldStructName(void *object, int field) const
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

void *VMMigMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    VMMigMsg *pp = (VMMigMsg *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


