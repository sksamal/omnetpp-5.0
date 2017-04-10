//
// Generated file, do not edit! Created by nedtool 5.0 from src/messages/OBS_BurstControlPacket.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "OBS_BurstControlPacket_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: no doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: no doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp


// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
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

Register_Class(OBS_BurstControlPacket);

OBS_BurstControlPacket::OBS_BurstControlPacket(const char *name, int kind) : ::omnetpp::cPacket(name,kind)
{
    this->burstArrivalDelta = -1;
    this->burstColour = -1;
    this->label = -1;
    this->burstifierId = -1;
    this->numSeq = -1;
    this->senderId = -1;
    this->burstSize = -1;
}

OBS_BurstControlPacket::OBS_BurstControlPacket(const OBS_BurstControlPacket& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

OBS_BurstControlPacket::~OBS_BurstControlPacket()
{
}

OBS_BurstControlPacket& OBS_BurstControlPacket::operator=(const OBS_BurstControlPacket& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void OBS_BurstControlPacket::copy(const OBS_BurstControlPacket& other)
{
    this->burstArrivalDelta = other.burstArrivalDelta;
    this->burstColour = other.burstColour;
    this->label = other.label;
    this->burstifierId = other.burstifierId;
    this->numSeq = other.numSeq;
    this->senderId = other.senderId;
    this->burstSize = other.burstSize;
}

void OBS_BurstControlPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->burstArrivalDelta);
    doParsimPacking(b,this->burstColour);
    doParsimPacking(b,this->label);
    doParsimPacking(b,this->burstifierId);
    doParsimPacking(b,this->numSeq);
    doParsimPacking(b,this->senderId);
    doParsimPacking(b,this->burstSize);
}

void OBS_BurstControlPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->burstArrivalDelta);
    doParsimUnpacking(b,this->burstColour);
    doParsimUnpacking(b,this->label);
    doParsimUnpacking(b,this->burstifierId);
    doParsimUnpacking(b,this->numSeq);
    doParsimUnpacking(b,this->senderId);
    doParsimUnpacking(b,this->burstSize);
}

::omnetpp::simtime_t OBS_BurstControlPacket::getBurstArrivalDelta() const
{
    return this->burstArrivalDelta;
}

void OBS_BurstControlPacket::setBurstArrivalDelta(::omnetpp::simtime_t burstArrivalDelta)
{
    this->burstArrivalDelta = burstArrivalDelta;
}

int OBS_BurstControlPacket::getBurstColour() const
{
    return this->burstColour;
}

void OBS_BurstControlPacket::setBurstColour(int burstColour)
{
    this->burstColour = burstColour;
}

int OBS_BurstControlPacket::getLabel() const
{
    return this->label;
}

void OBS_BurstControlPacket::setLabel(int label)
{
    this->label = label;
}

int OBS_BurstControlPacket::getBurstifierId() const
{
    return this->burstifierId;
}

void OBS_BurstControlPacket::setBurstifierId(int burstifierId)
{
    this->burstifierId = burstifierId;
}

int OBS_BurstControlPacket::getNumSeq() const
{
    return this->numSeq;
}

void OBS_BurstControlPacket::setNumSeq(int numSeq)
{
    this->numSeq = numSeq;
}

int OBS_BurstControlPacket::getSenderId() const
{
    return this->senderId;
}

void OBS_BurstControlPacket::setSenderId(int senderId)
{
    this->senderId = senderId;
}

int OBS_BurstControlPacket::getBurstSize() const
{
    return this->burstSize;
}

void OBS_BurstControlPacket::setBurstSize(int burstSize)
{
    this->burstSize = burstSize;
}

class OBS_BurstControlPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OBS_BurstControlPacketDescriptor();
    virtual ~OBS_BurstControlPacketDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(OBS_BurstControlPacketDescriptor);

OBS_BurstControlPacketDescriptor::OBS_BurstControlPacketDescriptor() : omnetpp::cClassDescriptor("OBS_BurstControlPacket", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

OBS_BurstControlPacketDescriptor::~OBS_BurstControlPacketDescriptor()
{
    delete[] propertynames;
}

bool OBS_BurstControlPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OBS_BurstControlPacket *>(obj)!=nullptr;
}

const char **OBS_BurstControlPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OBS_BurstControlPacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OBS_BurstControlPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount() : 7;
}

unsigned int OBS_BurstControlPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *OBS_BurstControlPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "burstArrivalDelta",
        "burstColour",
        "label",
        "burstifierId",
        "numSeq",
        "senderId",
        "burstSize",
    };
    return (field>=0 && field<7) ? fieldNames[field] : nullptr;
}

int OBS_BurstControlPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='b' && strcmp(fieldName, "burstArrivalDelta")==0) return base+0;
    if (fieldName[0]=='b' && strcmp(fieldName, "burstColour")==0) return base+1;
    if (fieldName[0]=='l' && strcmp(fieldName, "label")==0) return base+2;
    if (fieldName[0]=='b' && strcmp(fieldName, "burstifierId")==0) return base+3;
    if (fieldName[0]=='n' && strcmp(fieldName, "numSeq")==0) return base+4;
    if (fieldName[0]=='s' && strcmp(fieldName, "senderId")==0) return base+5;
    if (fieldName[0]=='b' && strcmp(fieldName, "burstSize")==0) return base+6;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OBS_BurstControlPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "simtime_t",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : nullptr;
}

const char **OBS_BurstControlPacketDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *OBS_BurstControlPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int OBS_BurstControlPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OBS_BurstControlPacket *pp = (OBS_BurstControlPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string OBS_BurstControlPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OBS_BurstControlPacket *pp = (OBS_BurstControlPacket *)object; (void)pp;
    switch (field) {
        case 0: return simtime2string(pp->getBurstArrivalDelta());
        case 1: return long2string(pp->getBurstColour());
        case 2: return long2string(pp->getLabel());
        case 3: return long2string(pp->getBurstifierId());
        case 4: return long2string(pp->getNumSeq());
        case 5: return long2string(pp->getSenderId());
        case 6: return long2string(pp->getBurstSize());
        default: return "";
    }
}

bool OBS_BurstControlPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OBS_BurstControlPacket *pp = (OBS_BurstControlPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setBurstArrivalDelta(string2simtime(value)); return true;
        case 1: pp->setBurstColour(string2long(value)); return true;
        case 2: pp->setLabel(string2long(value)); return true;
        case 3: pp->setBurstifierId(string2long(value)); return true;
        case 4: pp->setNumSeq(string2long(value)); return true;
        case 5: pp->setSenderId(string2long(value)); return true;
        case 6: pp->setBurstSize(string2long(value)); return true;
        default: return false;
    }
}

const char *OBS_BurstControlPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *OBS_BurstControlPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OBS_BurstControlPacket *pp = (OBS_BurstControlPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}


