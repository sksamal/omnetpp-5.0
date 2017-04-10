//
// Generated file, do not edit! Created by nedtool 5.0 from src/EdgeNode/OBS_ScheduledBurstItem.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "OBS_ScheduledBurstItem_m.h"

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

Register_Class(OBS_ScheduledBurstItem);

OBS_ScheduledBurstItem::OBS_ScheduledBurstItem(const char *name, int kind) : ::omnetpp::cPacket(name,kind)
{
    this->listIndex = -1;
    this->burstId = -1;
    this->sendTime = -1;
    this->minOffset = -1;
    this->maxOffset = -1;
}

OBS_ScheduledBurstItem::OBS_ScheduledBurstItem(const OBS_ScheduledBurstItem& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

OBS_ScheduledBurstItem::~OBS_ScheduledBurstItem()
{
}

OBS_ScheduledBurstItem& OBS_ScheduledBurstItem::operator=(const OBS_ScheduledBurstItem& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void OBS_ScheduledBurstItem::copy(const OBS_ScheduledBurstItem& other)
{
    this->listIndex = other.listIndex;
    this->burstId = other.burstId;
    this->sendTime = other.sendTime;
    this->minOffset = other.minOffset;
    this->maxOffset = other.maxOffset;
}

void OBS_ScheduledBurstItem::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->listIndex);
    doParsimPacking(b,this->burstId);
    doParsimPacking(b,this->sendTime);
    doParsimPacking(b,this->minOffset);
    doParsimPacking(b,this->maxOffset);
}

void OBS_ScheduledBurstItem::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->listIndex);
    doParsimUnpacking(b,this->burstId);
    doParsimUnpacking(b,this->sendTime);
    doParsimUnpacking(b,this->minOffset);
    doParsimUnpacking(b,this->maxOffset);
}

int OBS_ScheduledBurstItem::getListIndex() const
{
    return this->listIndex;
}

void OBS_ScheduledBurstItem::setListIndex(int listIndex)
{
    this->listIndex = listIndex;
}

int OBS_ScheduledBurstItem::getBurstId() const
{
    return this->burstId;
}

void OBS_ScheduledBurstItem::setBurstId(int burstId)
{
    this->burstId = burstId;
}

::omnetpp::simtime_t OBS_ScheduledBurstItem::getSendTime() const
{
    return this->sendTime;
}

void OBS_ScheduledBurstItem::setSendTime(::omnetpp::simtime_t sendTime)
{
    this->sendTime = sendTime;
}

::omnetpp::simtime_t OBS_ScheduledBurstItem::getMinOffset() const
{
    return this->minOffset;
}

void OBS_ScheduledBurstItem::setMinOffset(::omnetpp::simtime_t minOffset)
{
    this->minOffset = minOffset;
}

::omnetpp::simtime_t OBS_ScheduledBurstItem::getMaxOffset() const
{
    return this->maxOffset;
}

void OBS_ScheduledBurstItem::setMaxOffset(::omnetpp::simtime_t maxOffset)
{
    this->maxOffset = maxOffset;
}

class OBS_ScheduledBurstItemDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OBS_ScheduledBurstItemDescriptor();
    virtual ~OBS_ScheduledBurstItemDescriptor();

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

Register_ClassDescriptor(OBS_ScheduledBurstItemDescriptor);

OBS_ScheduledBurstItemDescriptor::OBS_ScheduledBurstItemDescriptor() : omnetpp::cClassDescriptor("OBS_ScheduledBurstItem", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

OBS_ScheduledBurstItemDescriptor::~OBS_ScheduledBurstItemDescriptor()
{
    delete[] propertynames;
}

bool OBS_ScheduledBurstItemDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OBS_ScheduledBurstItem *>(obj)!=nullptr;
}

const char **OBS_ScheduledBurstItemDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OBS_ScheduledBurstItemDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OBS_ScheduledBurstItemDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int OBS_ScheduledBurstItemDescriptor::getFieldTypeFlags(int field) const
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
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *OBS_ScheduledBurstItemDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "listIndex",
        "burstId",
        "sendTime",
        "minOffset",
        "maxOffset",
    };
    return (field>=0 && field<5) ? fieldNames[field] : nullptr;
}

int OBS_ScheduledBurstItemDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='l' && strcmp(fieldName, "listIndex")==0) return base+0;
    if (fieldName[0]=='b' && strcmp(fieldName, "burstId")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "sendTime")==0) return base+2;
    if (fieldName[0]=='m' && strcmp(fieldName, "minOffset")==0) return base+3;
    if (fieldName[0]=='m' && strcmp(fieldName, "maxOffset")==0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OBS_ScheduledBurstItemDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "simtime_t",
        "simtime_t",
        "simtime_t",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : nullptr;
}

const char **OBS_ScheduledBurstItemDescriptor::getFieldPropertyNames(int field) const
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

const char *OBS_ScheduledBurstItemDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int OBS_ScheduledBurstItemDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OBS_ScheduledBurstItem *pp = (OBS_ScheduledBurstItem *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string OBS_ScheduledBurstItemDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OBS_ScheduledBurstItem *pp = (OBS_ScheduledBurstItem *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getListIndex());
        case 1: return long2string(pp->getBurstId());
        case 2: return simtime2string(pp->getSendTime());
        case 3: return simtime2string(pp->getMinOffset());
        case 4: return simtime2string(pp->getMaxOffset());
        default: return "";
    }
}

bool OBS_ScheduledBurstItemDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OBS_ScheduledBurstItem *pp = (OBS_ScheduledBurstItem *)object; (void)pp;
    switch (field) {
        case 0: pp->setListIndex(string2long(value)); return true;
        case 1: pp->setBurstId(string2long(value)); return true;
        case 2: pp->setSendTime(string2simtime(value)); return true;
        case 3: pp->setMinOffset(string2simtime(value)); return true;
        case 4: pp->setMaxOffset(string2simtime(value)); return true;
        default: return false;
    }
}

const char *OBS_ScheduledBurstItemDescriptor::getFieldStructName(int field) const
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

void *OBS_ScheduledBurstItemDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OBS_ScheduledBurstItem *pp = (OBS_ScheduledBurstItem *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}


