//
// Generated file, do not edit! Created by nedtool 5.0 from src/CoreNode/OBS_CoreRoutingTableEntry.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "OBS_CoreRoutingTableEntry_m.h"

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

Register_Class(OBS_CoreRoutingTableEntry);

OBS_CoreRoutingTableEntry::OBS_CoreRoutingTableEntry() : ::omnetpp::cObject()
{
    this->inPort = -1;
    this->inColour = -1;
    this->inLabel = -1;
    this->outPort = -1;
    this->outColour = -1;
    this->outLabel = -1;
}

OBS_CoreRoutingTableEntry::OBS_CoreRoutingTableEntry(const OBS_CoreRoutingTableEntry& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

OBS_CoreRoutingTableEntry::~OBS_CoreRoutingTableEntry()
{
}

OBS_CoreRoutingTableEntry& OBS_CoreRoutingTableEntry::operator=(const OBS_CoreRoutingTableEntry& other)
{
    if (this==&other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void OBS_CoreRoutingTableEntry::copy(const OBS_CoreRoutingTableEntry& other)
{
    this->inPort = other.inPort;
    this->inColour = other.inColour;
    this->inLabel = other.inLabel;
    this->outPort = other.outPort;
    this->outColour = other.outColour;
    this->outLabel = other.outLabel;
}

void OBS_CoreRoutingTableEntry::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->inPort);
    doParsimPacking(b,this->inColour);
    doParsimPacking(b,this->inLabel);
    doParsimPacking(b,this->outPort);
    doParsimPacking(b,this->outColour);
    doParsimPacking(b,this->outLabel);
}

void OBS_CoreRoutingTableEntry::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->inPort);
    doParsimUnpacking(b,this->inColour);
    doParsimUnpacking(b,this->inLabel);
    doParsimUnpacking(b,this->outPort);
    doParsimUnpacking(b,this->outColour);
    doParsimUnpacking(b,this->outLabel);
}

int OBS_CoreRoutingTableEntry::getInPort() const
{
    return this->inPort;
}

void OBS_CoreRoutingTableEntry::setInPort(int inPort)
{
    this->inPort = inPort;
}

int OBS_CoreRoutingTableEntry::getInColour() const
{
    return this->inColour;
}

void OBS_CoreRoutingTableEntry::setInColour(int inColour)
{
    this->inColour = inColour;
}

int OBS_CoreRoutingTableEntry::getInLabel() const
{
    return this->inLabel;
}

void OBS_CoreRoutingTableEntry::setInLabel(int inLabel)
{
    this->inLabel = inLabel;
}

int OBS_CoreRoutingTableEntry::getOutPort() const
{
    return this->outPort;
}

void OBS_CoreRoutingTableEntry::setOutPort(int outPort)
{
    this->outPort = outPort;
}

int OBS_CoreRoutingTableEntry::getOutColour() const
{
    return this->outColour;
}

void OBS_CoreRoutingTableEntry::setOutColour(int outColour)
{
    this->outColour = outColour;
}

int OBS_CoreRoutingTableEntry::getOutLabel() const
{
    return this->outLabel;
}

void OBS_CoreRoutingTableEntry::setOutLabel(int outLabel)
{
    this->outLabel = outLabel;
}

class OBS_CoreRoutingTableEntryDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OBS_CoreRoutingTableEntryDescriptor();
    virtual ~OBS_CoreRoutingTableEntryDescriptor();

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

Register_ClassDescriptor(OBS_CoreRoutingTableEntryDescriptor);

OBS_CoreRoutingTableEntryDescriptor::OBS_CoreRoutingTableEntryDescriptor() : omnetpp::cClassDescriptor("OBS_CoreRoutingTableEntry", "omnetpp::cObject")
{
    propertynames = nullptr;
}

OBS_CoreRoutingTableEntryDescriptor::~OBS_CoreRoutingTableEntryDescriptor()
{
    delete[] propertynames;
}

bool OBS_CoreRoutingTableEntryDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OBS_CoreRoutingTableEntry *>(obj)!=nullptr;
}

const char **OBS_CoreRoutingTableEntryDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OBS_CoreRoutingTableEntryDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OBS_CoreRoutingTableEntryDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int OBS_CoreRoutingTableEntryDescriptor::getFieldTypeFlags(int field) const
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
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *OBS_CoreRoutingTableEntryDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "inPort",
        "inColour",
        "inLabel",
        "outPort",
        "outColour",
        "outLabel",
    };
    return (field>=0 && field<6) ? fieldNames[field] : nullptr;
}

int OBS_CoreRoutingTableEntryDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "inPort")==0) return base+0;
    if (fieldName[0]=='i' && strcmp(fieldName, "inColour")==0) return base+1;
    if (fieldName[0]=='i' && strcmp(fieldName, "inLabel")==0) return base+2;
    if (fieldName[0]=='o' && strcmp(fieldName, "outPort")==0) return base+3;
    if (fieldName[0]=='o' && strcmp(fieldName, "outColour")==0) return base+4;
    if (fieldName[0]=='o' && strcmp(fieldName, "outLabel")==0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OBS_CoreRoutingTableEntryDescriptor::getFieldTypeString(int field) const
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
        "int",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : nullptr;
}

const char **OBS_CoreRoutingTableEntryDescriptor::getFieldPropertyNames(int field) const
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

const char *OBS_CoreRoutingTableEntryDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int OBS_CoreRoutingTableEntryDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OBS_CoreRoutingTableEntry *pp = (OBS_CoreRoutingTableEntry *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string OBS_CoreRoutingTableEntryDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OBS_CoreRoutingTableEntry *pp = (OBS_CoreRoutingTableEntry *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getInPort());
        case 1: return long2string(pp->getInColour());
        case 2: return long2string(pp->getInLabel());
        case 3: return long2string(pp->getOutPort());
        case 4: return long2string(pp->getOutColour());
        case 5: return long2string(pp->getOutLabel());
        default: return "";
    }
}

bool OBS_CoreRoutingTableEntryDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OBS_CoreRoutingTableEntry *pp = (OBS_CoreRoutingTableEntry *)object; (void)pp;
    switch (field) {
        case 0: pp->setInPort(string2long(value)); return true;
        case 1: pp->setInColour(string2long(value)); return true;
        case 2: pp->setInLabel(string2long(value)); return true;
        case 3: pp->setOutPort(string2long(value)); return true;
        case 4: pp->setOutColour(string2long(value)); return true;
        case 5: pp->setOutLabel(string2long(value)); return true;
        default: return false;
    }
}

const char *OBS_CoreRoutingTableEntryDescriptor::getFieldStructName(int field) const
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

void *OBS_CoreRoutingTableEntryDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OBS_CoreRoutingTableEntry *pp = (OBS_CoreRoutingTableEntry *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}


