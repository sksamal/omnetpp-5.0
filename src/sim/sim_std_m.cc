//
// Generated file, do not edit! Created by nedtool 5.0 from sim_std.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "sim_std_m.h"

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

namespace omnetpp {

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

class cObjectDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cObjectDescriptor();
    virtual ~cObjectDescriptor();

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

Register_ClassDescriptor(cObjectDescriptor);

cObjectDescriptor::cObjectDescriptor() : omnetpp::cClassDescriptor("omnetpp::cObject", "")
{
    propertynames = nullptr;
}

cObjectDescriptor::~cObjectDescriptor()
{
    delete[] propertynames;
}

bool cObjectDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cObject *>(obj)!=nullptr;
}

const char **cObjectDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "icon",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cObjectDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"icon")) return "cogwheel";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cObjectDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int cObjectDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        0,
        0,
        0,
        0,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *cObjectDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "className",
        "fullName",
        "fullPath",
        "info",
        "detailedInfo",
    };
    return (field>=0 && field<5) ? fieldNames[field] : nullptr;
}

int cObjectDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "className")==0) return base+0;
    if (fieldName[0]=='f' && strcmp(fieldName, "fullName")==0) return base+1;
    if (fieldName[0]=='f' && strcmp(fieldName, "fullPath")==0) return base+2;
    if (fieldName[0]=='i' && strcmp(fieldName, "info")==0) return base+3;
    if (fieldName[0]=='d' && strcmp(fieldName, "detailedInfo")==0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cObjectDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "string",
        "string",
        "string",
        "string",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : nullptr;
}

const char **cObjectDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "eventlog", "group", "hint",  nullptr };
            return names;
        }
        case 1: {
            static const char *names[] = { "group", "hint",  nullptr };
            return names;
        }
        case 2: {
            static const char *names[] = { "eventlog", "group", "hint",  nullptr };
            return names;
        }
        case 3: {
            static const char *names[] = { "eventlog", "getter", "group", "hint",  nullptr };
            return names;
        }
        case 4: {
            static const char *names[] = { "eventlog", "getter", "group", "hint",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cObjectDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"eventlog")) return "skip";
            if (!strcmp(propertyname,"group")) return "base";
            if (!strcmp(propertyname,"hint")) return "C++ class name";
            return nullptr;
        case 1:
            if (!strcmp(propertyname,"group")) return "base";
            if (!strcmp(propertyname,"hint")) return "If object is part of a module/gate vector: name with index";
            return nullptr;
        case 2:
            if (!strcmp(propertyname,"eventlog")) return "skip";
            if (!strcmp(propertyname,"group")) return "base";
            if (!strcmp(propertyname,"hint")) return "Hierarchical name, composed of full names of this object and its owners/parents";
            return nullptr;
        case 3:
            if (!strcmp(propertyname,"eventlog")) return "skip";
            if (!strcmp(propertyname,"getter")) return "info";
            if (!strcmp(propertyname,"group")) return "base";
            if (!strcmp(propertyname,"hint")) return "Text provided by the object's \"info\" method";
            return nullptr;
        case 4:
            if (!strcmp(propertyname,"eventlog")) return "skip";
            if (!strcmp(propertyname,"getter")) return "detailedInfo";
            if (!strcmp(propertyname,"group")) return "base";
            if (!strcmp(propertyname,"hint")) return "Text provided by the object's \"detailedInfo\" method";
            return nullptr;
        default: return nullptr;
    }
}

int cObjectDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cObject *pp = (cObject *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cObjectDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cObject *pp = (cObject *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getClassName());
        case 1: return oppstring2string(pp->getFullName());
        case 2: return oppstring2string(pp->getFullPath());
        case 3: return oppstring2string(pp->info());
        case 4: return oppstring2string(pp->detailedInfo());
        default: return "";
    }
}

bool cObjectDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cObject *pp = (cObject *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cObjectDescriptor::getFieldStructName(int field) const
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

void *cObjectDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cObject *pp = (cObject *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cNamedObjectDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cNamedObjectDescriptor();
    virtual ~cNamedObjectDescriptor();

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

Register_ClassDescriptor(cNamedObjectDescriptor);

cNamedObjectDescriptor::cNamedObjectDescriptor() : omnetpp::cClassDescriptor("omnetpp::cNamedObject", "omnetpp::cObject")
{
    propertynames = nullptr;
}

cNamedObjectDescriptor::~cNamedObjectDescriptor()
{
    delete[] propertynames;
}

bool cNamedObjectDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cNamedObject *>(obj)!=nullptr;
}

const char **cNamedObjectDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cNamedObjectDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cNamedObjectDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int cNamedObjectDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *cNamedObjectDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "name",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int cNamedObjectDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='n' && strcmp(fieldName, "name")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cNamedObjectDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **cNamedObjectDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "editable", "group", "hint",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cNamedObjectDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"group")) return "base";
            if (!strcmp(propertyname,"hint")) return "An editable string attribute of the object, also used for fullName and fullPath";
            return nullptr;
        default: return nullptr;
    }
}

int cNamedObjectDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cNamedObject *pp = (cNamedObject *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cNamedObjectDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cNamedObject *pp = (cNamedObject *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getName());
        default: return "";
    }
}

bool cNamedObjectDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cNamedObject *pp = (cNamedObject *)object; (void)pp;
    switch (field) {
        case 0: pp->setName((value)); return true;
        default: return false;
    }
}

const char *cNamedObjectDescriptor::getFieldStructName(int field) const
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

void *cNamedObjectDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cNamedObject *pp = (cNamedObject *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cOwnedObjectDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cOwnedObjectDescriptor();
    virtual ~cOwnedObjectDescriptor();

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

Register_ClassDescriptor(cOwnedObjectDescriptor);

cOwnedObjectDescriptor::cOwnedObjectDescriptor() : omnetpp::cClassDescriptor("omnetpp::cOwnedObject", "omnetpp::cNamedObject")
{
    propertynames = nullptr;
}

cOwnedObjectDescriptor::~cOwnedObjectDescriptor()
{
    delete[] propertynames;
}

bool cOwnedObjectDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cOwnedObject *>(obj)!=nullptr;
}

const char **cOwnedObjectDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cOwnedObjectDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cOwnedObjectDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int cOwnedObjectDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *cOwnedObjectDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "owner",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int cOwnedObjectDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='o' && strcmp(fieldName, "owner")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cOwnedObjectDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "cObject",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **cOwnedObjectDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "eventlog", "group", "hint",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cOwnedObjectDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"eventlog")) return "skip";
            if (!strcmp(propertyname,"group")) return "base";
            if (!strcmp(propertyname,"hint")) return "Module or container this object belongs to";
            return nullptr;
        default: return nullptr;
    }
}

int cOwnedObjectDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cOwnedObject *pp = (cOwnedObject *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cOwnedObjectDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cOwnedObject *pp = (cOwnedObject *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getOwner(); return out.str();}
        default: return "";
    }
}

bool cOwnedObjectDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cOwnedObject *pp = (cOwnedObject *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cOwnedObjectDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(cObject));
        default: return nullptr;
    };
}

void *cOwnedObjectDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cOwnedObject *pp = (cOwnedObject *)object; (void)pp;
    switch (field) {
        case 0: return (void *)static_cast<omnetpp::cObject *>(pp->getOwner()); break;
        default: return nullptr;
    }
}

class cNoncopyableOwnedObjectDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cNoncopyableOwnedObjectDescriptor();
    virtual ~cNoncopyableOwnedObjectDescriptor();

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

Register_ClassDescriptor(cNoncopyableOwnedObjectDescriptor);

cNoncopyableOwnedObjectDescriptor::cNoncopyableOwnedObjectDescriptor() : omnetpp::cClassDescriptor("omnetpp::cNoncopyableOwnedObject", "omnetpp::cOwnedObject")
{
    propertynames = nullptr;
}

cNoncopyableOwnedObjectDescriptor::~cNoncopyableOwnedObjectDescriptor()
{
    delete[] propertynames;
}

bool cNoncopyableOwnedObjectDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cNoncopyableOwnedObject *>(obj)!=nullptr;
}

const char **cNoncopyableOwnedObjectDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cNoncopyableOwnedObjectDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cNoncopyableOwnedObjectDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int cNoncopyableOwnedObjectDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *cNoncopyableOwnedObjectDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int cNoncopyableOwnedObjectDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cNoncopyableOwnedObjectDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **cNoncopyableOwnedObjectDescriptor::getFieldPropertyNames(int field) const
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

const char *cNoncopyableOwnedObjectDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cNoncopyableOwnedObjectDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cNoncopyableOwnedObject *pp = (cNoncopyableOwnedObject *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cNoncopyableOwnedObjectDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cNoncopyableOwnedObject *pp = (cNoncopyableOwnedObject *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cNoncopyableOwnedObjectDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cNoncopyableOwnedObject *pp = (cNoncopyableOwnedObject *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cNoncopyableOwnedObjectDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *cNoncopyableOwnedObjectDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cNoncopyableOwnedObject *pp = (cNoncopyableOwnedObject *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cDefaultListDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cDefaultListDescriptor();
    virtual ~cDefaultListDescriptor();

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

Register_ClassDescriptor(cDefaultListDescriptor);

cDefaultListDescriptor::cDefaultListDescriptor() : omnetpp::cClassDescriptor("omnetpp::cDefaultList", "omnetpp::cNoncopyableOwnedObject")
{
    propertynames = nullptr;
}

cDefaultListDescriptor::~cDefaultListDescriptor()
{
    delete[] propertynames;
}

bool cDefaultListDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cDefaultList *>(obj)!=nullptr;
}

const char **cDefaultListDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cDefaultListDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cDefaultListDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int cDefaultListDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *cDefaultListDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "defaultList",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int cDefaultListDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='d' && strcmp(fieldName, "defaultList")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cDefaultListDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "cOwnedObject",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **cDefaultListDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "getter", "group", "hint", "sizeGetter",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cDefaultListDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"getter")) return "defaultListGet";
            if (!strcmp(propertyname,"group")) return "owned objects";
            if (!strcmp(propertyname,"hint")) return "List of objects directly held by this component";
            if (!strcmp(propertyname,"sizeGetter")) return "defaultListSize";
            return nullptr;
        default: return nullptr;
    }
}

int cDefaultListDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cDefaultList *pp = (cDefaultList *)object; (void)pp;
    switch (field) {
        case 0: return pp->defaultListSize();
        default: return 0;
    }
}

std::string cDefaultListDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cDefaultList *pp = (cDefaultList *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->defaultListGet(i); return out.str();}
        default: return "";
    }
}

bool cDefaultListDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cDefaultList *pp = (cDefaultList *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cDefaultListDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(cOwnedObject));
        default: return nullptr;
    };
}

void *cDefaultListDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cDefaultList *pp = (cDefaultList *)object; (void)pp;
    switch (field) {
        case 0: return (void *)static_cast<omnetpp::cObject *>(pp->defaultListGet(i)); break;
        default: return nullptr;
    }
}

class cDisplayStringDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cDisplayStringDescriptor();
    virtual ~cDisplayStringDescriptor();

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

Register_ClassDescriptor(cDisplayStringDescriptor);

cDisplayStringDescriptor::cDisplayStringDescriptor() : omnetpp::cClassDescriptor("omnetpp::cDisplayString", "")
{
    propertynames = nullptr;
}

cDisplayStringDescriptor::~cDisplayStringDescriptor()
{
    delete[] propertynames;
}

bool cDisplayStringDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cDisplayString *>(obj)!=nullptr;
}

const char **cDisplayStringDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cDisplayStringDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cDisplayStringDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int cDisplayStringDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *cDisplayStringDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "value",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int cDisplayStringDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='v' && strcmp(fieldName, "value")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cDisplayStringDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **cDisplayStringDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "editable", "getter", "hint", "setter",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cDisplayStringDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"getter")) return "str";
            if (!strcmp(propertyname,"hint")) return "The editable display string itself";
            if (!strcmp(propertyname,"setter")) return "parse";
            return nullptr;
        default: return nullptr;
    }
}

int cDisplayStringDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cDisplayString *pp = (cDisplayString *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cDisplayStringDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cDisplayString *pp = (cDisplayString *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->str());
        default: return "";
    }
}

bool cDisplayStringDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cDisplayString *pp = (cDisplayString *)object; (void)pp;
    switch (field) {
        case 0: pp->parse((value)); return true;
        default: return false;
    }
}

const char *cDisplayStringDescriptor::getFieldStructName(int field) const
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

void *cDisplayStringDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cDisplayString *pp = (cDisplayString *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cPropertyDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cPropertyDescriptor();
    virtual ~cPropertyDescriptor();

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

Register_ClassDescriptor(cPropertyDescriptor);

cPropertyDescriptor::cPropertyDescriptor() : omnetpp::cClassDescriptor("omnetpp::cProperty", "omnetpp::cObject")
{
    propertynames = nullptr;
}

cPropertyDescriptor::~cPropertyDescriptor()
{
    delete[] propertynames;
}

bool cPropertyDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cProperty *>(obj)!=nullptr;
}

const char **cPropertyDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cPropertyDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cPropertyDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int cPropertyDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        0,
        0,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *cPropertyDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "isImplicit",
        "index",
        "value",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int cPropertyDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "isImplicit")==0) return base+0;
    if (fieldName[0]=='i' && strcmp(fieldName, "index")==0) return base+1;
    if (fieldName[0]=='v' && strcmp(fieldName, "value")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cPropertyDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "string",
        "string",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **cPropertyDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "getter", "group",  nullptr };
            return names;
        }
        case 1: {
            static const char *names[] = { "group",  nullptr };
            return names;
        }
        case 2: {
            static const char *names[] = { "getter", "hint",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cPropertyDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"getter")) return "isImplicit";
            if (!strcmp(propertyname,"group")) return "fields";
            return nullptr;
        case 1:
            if (!strcmp(propertyname,"group")) return "fields";
            return nullptr;
        case 2:
            if (!strcmp(propertyname,"getter")) return "info";
            if (!strcmp(propertyname,"hint")) return "Name and value";
            return nullptr;
        default: return nullptr;
    }
}

int cPropertyDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cProperty *pp = (cProperty *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cPropertyDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cProperty *pp = (cProperty *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->isImplicit());
        case 1: return oppstring2string(pp->getIndex());
        case 2: return oppstring2string(pp->info());
        default: return "";
    }
}

bool cPropertyDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cProperty *pp = (cProperty *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cPropertyDescriptor::getFieldStructName(int field) const
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

void *cPropertyDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cProperty *pp = (cProperty *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cPropertiesDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cPropertiesDescriptor();
    virtual ~cPropertiesDescriptor();

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

Register_ClassDescriptor(cPropertiesDescriptor);

cPropertiesDescriptor::cPropertiesDescriptor() : omnetpp::cClassDescriptor("omnetpp::cProperties", "omnetpp::cObject")
{
    propertynames = nullptr;
}

cPropertiesDescriptor::~cPropertiesDescriptor()
{
    delete[] propertynames;
}

bool cPropertiesDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cProperties *>(obj)!=nullptr;
}

const char **cPropertiesDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cPropertiesDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cPropertiesDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int cPropertiesDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *cPropertiesDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "contents",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int cPropertiesDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "contents")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cPropertiesDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "cProperty",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **cPropertiesDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "getter", "hint", "sizeGetter",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cPropertiesDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"getter")) return "get";
            if (!strcmp(propertyname,"hint")) return "The property list";
            if (!strcmp(propertyname,"sizeGetter")) return "getNumProperties";
            return nullptr;
        default: return nullptr;
    }
}

int cPropertiesDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cProperties *pp = (cProperties *)object; (void)pp;
    switch (field) {
        case 0: return pp->getNumProperties();
        default: return 0;
    }
}

std::string cPropertiesDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cProperties *pp = (cProperties *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->get(i); return out.str();}
        default: return "";
    }
}

bool cPropertiesDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cProperties *pp = (cProperties *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cPropertiesDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(cProperty));
        default: return nullptr;
    };
}

void *cPropertiesDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cProperties *pp = (cProperties *)object; (void)pp;
    switch (field) {
        case 0: return (void *)static_cast<omnetpp::cObject *>(pp->get(i)); break;
        default: return nullptr;
    }
}

class cComponentDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cComponentDescriptor();
    virtual ~cComponentDescriptor();

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

Register_ClassDescriptor(cComponentDescriptor);

cComponentDescriptor::cComponentDescriptor() : omnetpp::cClassDescriptor("omnetpp::cComponent", "omnetpp::cDefaultList")
{
    propertynames = nullptr;
}

cComponentDescriptor::~cComponentDescriptor()
{
    delete[] propertynames;
}

bool cComponentDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cComponent *>(obj)!=nullptr;
}

const char **cComponentDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cComponentDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cComponentDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int cComponentDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *cComponentDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "isModule",
        "componentType",
        "par",
        "props",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int cComponentDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "isModule")==0) return base+0;
    if (fieldName[0]=='c' && strcmp(fieldName, "componentType")==0) return base+1;
    if (fieldName[0]=='p' && strcmp(fieldName, "par")==0) return base+2;
    if (fieldName[0]=='p' && strcmp(fieldName, "props")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cComponentDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "cComponentType",
        "cPar",
        "cProperties",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **cComponentDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "getter", "group", "hint",  nullptr };
            return names;
        }
        case 1: {
            static const char *names[] = { "group", "hint",  nullptr };
            return names;
        }
        case 2: {
            static const char *names[] = { "getter", "group", "hint", "label", "sizeGetter",  nullptr };
            return names;
        }
        case 3: {
            static const char *names[] = { "getter", "group", "hint", "label",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cComponentDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"getter")) return "isModule";
            if (!strcmp(propertyname,"group")) return "fields";
            if (!strcmp(propertyname,"hint")) return "Whether this component is a module or a channel";
            return nullptr;
        case 1:
            if (!strcmp(propertyname,"group")) return "fields";
            if (!strcmp(propertyname,"hint")) return "The object that represents the type declaration for this component";
            return nullptr;
        case 2:
            if (!strcmp(propertyname,"getter")) return "par";
            if (!strcmp(propertyname,"group")) return "parameters,gates";
            if (!strcmp(propertyname,"hint")) return "Parameters";
            if (!strcmp(propertyname,"label")) return "parameters";
            if (!strcmp(propertyname,"sizeGetter")) return "getNumParams";
            return nullptr;
        case 3:
            if (!strcmp(propertyname,"getter")) return "getProperties";
            if (!strcmp(propertyname,"group")) return "parameters,gates";
            if (!strcmp(propertyname,"hint")) return "Properties";
            if (!strcmp(propertyname,"label")) return "properties";
            return nullptr;
        default: return nullptr;
    }
}

int cComponentDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cComponent *pp = (cComponent *)object; (void)pp;
    switch (field) {
        case 2: return pp->getNumParams();
        default: return 0;
    }
}

std::string cComponentDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cComponent *pp = (cComponent *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->isModule());
        case 1: {std::stringstream out; out << pp->getComponentType(); return out.str();}
        case 2: {std::stringstream out; out << pp->par(i); return out.str();}
        case 3: {std::stringstream out; out << pp->getProperties(); return out.str();}
        default: return "";
    }
}

bool cComponentDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cComponent *pp = (cComponent *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cComponentDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(cComponentType));
        case 2: return omnetpp::opp_typename(typeid(cPar));
        case 3: return omnetpp::opp_typename(typeid(cProperties));
        default: return nullptr;
    };
}

void *cComponentDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cComponent *pp = (cComponent *)object; (void)pp;
    switch (field) {
        case 1: return (void *)static_cast<omnetpp::cObject *>(pp->getComponentType()); break;
        case 2: return (void *)static_cast<omnetpp::cObject *>(&pp->par(i)); break;
        case 3: return (void *)static_cast<omnetpp::cObject *>(pp->getProperties()); break;
        default: return nullptr;
    }
}

class cChannelDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cChannelDescriptor();
    virtual ~cChannelDescriptor();

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

Register_ClassDescriptor(cChannelDescriptor);

cChannelDescriptor::cChannelDescriptor() : omnetpp::cClassDescriptor("omnetpp::cChannel", "omnetpp::cComponent")
{
    propertynames = nullptr;
}

cChannelDescriptor::~cChannelDescriptor()
{
    delete[] propertynames;
}

bool cChannelDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cChannel *>(obj)!=nullptr;
}

const char **cChannelDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "icon",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cChannelDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"icon")) return "channel";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cChannelDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int cChannelDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *cChannelDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "displayString",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int cChannelDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='d' && strcmp(fieldName, "displayString")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cChannelDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "cDisplayString",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **cChannelDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "group", "hint",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cChannelDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"group")) return "fields";
            if (!strcmp(propertyname,"hint")) return "Controls appearance of this channel in the GUI";
            return nullptr;
        default: return nullptr;
    }
}

int cChannelDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cChannel *pp = (cChannel *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cChannelDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cChannel *pp = (cChannel *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getDisplayString(); return out.str();}
        default: return "";
    }
}

bool cChannelDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cChannel *pp = (cChannel *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cChannelDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(cDisplayString));
        default: return nullptr;
    };
}

void *cChannelDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cChannel *pp = (cChannel *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getDisplayString()); break;
        default: return nullptr;
    }
}

class cIdealChannelDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cIdealChannelDescriptor();
    virtual ~cIdealChannelDescriptor();

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

Register_ClassDescriptor(cIdealChannelDescriptor);

cIdealChannelDescriptor::cIdealChannelDescriptor() : omnetpp::cClassDescriptor("omnetpp::cIdealChannel", "omnetpp::cChannel")
{
    propertynames = nullptr;
}

cIdealChannelDescriptor::~cIdealChannelDescriptor()
{
    delete[] propertynames;
}

bool cIdealChannelDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cIdealChannel *>(obj)!=nullptr;
}

const char **cIdealChannelDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cIdealChannelDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cIdealChannelDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int cIdealChannelDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *cIdealChannelDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int cIdealChannelDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cIdealChannelDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **cIdealChannelDescriptor::getFieldPropertyNames(int field) const
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

const char *cIdealChannelDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cIdealChannelDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cIdealChannel *pp = (cIdealChannel *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cIdealChannelDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cIdealChannel *pp = (cIdealChannel *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cIdealChannelDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cIdealChannel *pp = (cIdealChannel *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cIdealChannelDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *cIdealChannelDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cIdealChannel *pp = (cIdealChannel *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cDelayChannelDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cDelayChannelDescriptor();
    virtual ~cDelayChannelDescriptor();

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

Register_ClassDescriptor(cDelayChannelDescriptor);

cDelayChannelDescriptor::cDelayChannelDescriptor() : omnetpp::cClassDescriptor("omnetpp::cDelayChannel", "omnetpp::cChannel")
{
    propertynames = nullptr;
}

cDelayChannelDescriptor::~cDelayChannelDescriptor()
{
    delete[] propertynames;
}

bool cDelayChannelDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cDelayChannel *>(obj)!=nullptr;
}

const char **cDelayChannelDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cDelayChannelDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cDelayChannelDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int cDelayChannelDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *cDelayChannelDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int cDelayChannelDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cDelayChannelDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **cDelayChannelDescriptor::getFieldPropertyNames(int field) const
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

const char *cDelayChannelDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cDelayChannelDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cDelayChannel *pp = (cDelayChannel *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cDelayChannelDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cDelayChannel *pp = (cDelayChannel *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cDelayChannelDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cDelayChannel *pp = (cDelayChannel *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cDelayChannelDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *cDelayChannelDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cDelayChannel *pp = (cDelayChannel *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cDatarateChannelDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cDatarateChannelDescriptor();
    virtual ~cDatarateChannelDescriptor();

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

Register_ClassDescriptor(cDatarateChannelDescriptor);

cDatarateChannelDescriptor::cDatarateChannelDescriptor() : omnetpp::cClassDescriptor("omnetpp::cDatarateChannel", "omnetpp::cChannel")
{
    propertynames = nullptr;
}

cDatarateChannelDescriptor::~cDatarateChannelDescriptor()
{
    delete[] propertynames;
}

bool cDatarateChannelDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cDatarateChannel *>(obj)!=nullptr;
}

const char **cDatarateChannelDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cDatarateChannelDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cDatarateChannelDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int cDatarateChannelDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        0,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *cDatarateChannelDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "isBusy",
        "transmissionFinishTime",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int cDatarateChannelDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "isBusy")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "transmissionFinishTime")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cDatarateChannelDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "simtime_t",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **cDatarateChannelDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "getter", "group", "hint",  nullptr };
            return names;
        }
        case 1: {
            static const char *names[] = { "group", "hint",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cDatarateChannelDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"getter")) return "isBusy";
            if (!strcmp(propertyname,"group")) return "fields";
            if (!strcmp(propertyname,"hint")) return "If channel is currently transmitting";
            return nullptr;
        case 1:
            if (!strcmp(propertyname,"group")) return "fields";
            if (!strcmp(propertyname,"hint")) return "If busy: when currently active transmissions will finish";
            return nullptr;
        default: return nullptr;
    }
}

int cDatarateChannelDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cDatarateChannel *pp = (cDatarateChannel *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cDatarateChannelDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cDatarateChannel *pp = (cDatarateChannel *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->isBusy());
        case 1: return simtime2string(pp->getTransmissionFinishTime());
        default: return "";
    }
}

bool cDatarateChannelDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cDatarateChannel *pp = (cDatarateChannel *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cDatarateChannelDescriptor::getFieldStructName(int field) const
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

void *cDatarateChannelDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cDatarateChannel *pp = (cDatarateChannel *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cModuleDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cModuleDescriptor();
    virtual ~cModuleDescriptor();

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

Register_ClassDescriptor(cModuleDescriptor);

cModuleDescriptor::cModuleDescriptor() : omnetpp::cClassDescriptor("omnetpp::cModule", "omnetpp::cComponent")
{
    propertynames = nullptr;
}

cModuleDescriptor::~cModuleDescriptor()
{
    delete[] propertynames;
}

bool cModuleDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cModule *>(obj)!=nullptr;
}

const char **cModuleDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "icon",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cModuleDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"icon")) return "compound";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cModuleDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 9+basedesc->getFieldCount() : 9;
}

unsigned int cModuleDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        0,
        0,
        0,
        0,
        FD_ISCOMPOUND,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,
    };
    return (field>=0 && field<9) ? fieldTypeFlags[field] : 0;
}

const char *cModuleDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "id",
        "isSimple",
        "isVector",
        "index",
        "size",
        "displayString",
        "gate",
        "canvas",
        "osgCanvas",
    };
    return (field>=0 && field<9) ? fieldNames[field] : nullptr;
}

int cModuleDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "id")==0) return base+0;
    if (fieldName[0]=='i' && strcmp(fieldName, "isSimple")==0) return base+1;
    if (fieldName[0]=='i' && strcmp(fieldName, "isVector")==0) return base+2;
    if (fieldName[0]=='i' && strcmp(fieldName, "index")==0) return base+3;
    if (fieldName[0]=='s' && strcmp(fieldName, "size")==0) return base+4;
    if (fieldName[0]=='d' && strcmp(fieldName, "displayString")==0) return base+5;
    if (fieldName[0]=='g' && strcmp(fieldName, "gate")==0) return base+6;
    if (fieldName[0]=='c' && strcmp(fieldName, "canvas")==0) return base+7;
    if (fieldName[0]=='o' && strcmp(fieldName, "osgCanvas")==0) return base+8;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cModuleDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "bool",
        "bool",
        "int",
        "int",
        "cDisplayString",
        "cGate",
        "cCanvas",
        "cOsgCanvas",
    };
    return (field>=0 && field<9) ? fieldTypeStrings[field] : nullptr;
}

const char **cModuleDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "group", "hint",  nullptr };
            return names;
        }
        case 1: {
            static const char *names[] = { "getter", "group", "hint",  nullptr };
            return names;
        }
        case 2: {
            static const char *names[] = { "getter", "group", "hint",  nullptr };
            return names;
        }
        case 3: {
            static const char *names[] = { "group", "hint",  nullptr };
            return names;
        }
        case 4: {
            static const char *names[] = { "getter", "group", "hint",  nullptr };
            return names;
        }
        case 5: {
            static const char *names[] = { "group", "hint",  nullptr };
            return names;
        }
        case 6: {
            static const char *names[] = { "getter", "group", "hint", "label", "sizeGetter",  nullptr };
            return names;
        }
        case 7: {
            static const char *names[] = { "getter", "group", "hint",  nullptr };
            return names;
        }
        case 8: {
            static const char *names[] = { "getter", "group", "hint",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cModuleDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"group")) return "fields";
            if (!strcmp(propertyname,"hint")) return "Unique module ID -- IDs of deleted modules are not issued again";
            return nullptr;
        case 1:
            if (!strcmp(propertyname,"getter")) return "isSimple";
            if (!strcmp(propertyname,"group")) return "fields";
            if (!strcmp(propertyname,"hint")) return "Whether this is a simple module";
            return nullptr;
        case 2:
            if (!strcmp(propertyname,"getter")) return "isVector";
            if (!strcmp(propertyname,"group")) return "fields";
            if (!strcmp(propertyname,"hint")) return "Whether this module is part of a module vector";
            return nullptr;
        case 3:
            if (!strcmp(propertyname,"group")) return "fields";
            if (!strcmp(propertyname,"hint")) return "If vector: index of this module in its module vector";
            return nullptr;
        case 4:
            if (!strcmp(propertyname,"getter")) return "size";
            if (!strcmp(propertyname,"group")) return "fields";
            if (!strcmp(propertyname,"hint")) return "If vector: size of module vector this module belongs to";
            return nullptr;
        case 5:
            if (!strcmp(propertyname,"group")) return "fields";
            if (!strcmp(propertyname,"hint")) return "Controls appearance of this module in the GUI";
            return nullptr;
        case 6:
            if (!strcmp(propertyname,"getter")) return "gateByOrdinal";
            if (!strcmp(propertyname,"group")) return "parameters,gates";
            if (!strcmp(propertyname,"hint")) return "Module gates";
            if (!strcmp(propertyname,"label")) return "gates";
            if (!strcmp(propertyname,"sizeGetter")) return "gateCount";
            return nullptr;
        case 7:
            if (!strcmp(propertyname,"getter")) return "getCanvasIfExists";
            if (!strcmp(propertyname,"group")) return "fields";
            if (!strcmp(propertyname,"hint")) return "Built-in canvas instance";
            return nullptr;
        case 8:
            if (!strcmp(propertyname,"getter")) return "getOsgCanvasIfExists";
            if (!strcmp(propertyname,"group")) return "fields";
            if (!strcmp(propertyname,"hint")) return "Built-in 3D (OpenSceneGraph) canvas instance";
            return nullptr;
        default: return nullptr;
    }
}

int cModuleDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cModule *pp = (cModule *)object; (void)pp;
    switch (field) {
        case 6: return pp->gateCount();
        default: return 0;
    }
}

std::string cModuleDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cModule *pp = (cModule *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getId());
        case 1: return bool2string(pp->isSimple());
        case 2: return bool2string(pp->isVector());
        case 3: return long2string(pp->getIndex());
        case 4: return long2string(pp->size());
        case 5: {std::stringstream out; out << pp->getDisplayString(); return out.str();}
        case 6: {std::stringstream out; out << pp->gateByOrdinal(i); return out.str();}
        case 7: {std::stringstream out; out << pp->getCanvasIfExists(); return out.str();}
        case 8: {std::stringstream out; out << pp->getOsgCanvasIfExists(); return out.str();}
        default: return "";
    }
}

bool cModuleDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cModule *pp = (cModule *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cModuleDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 5: return omnetpp::opp_typename(typeid(cDisplayString));
        case 6: return omnetpp::opp_typename(typeid(cGate));
        case 7: return omnetpp::opp_typename(typeid(cCanvas));
        case 8: return omnetpp::opp_typename(typeid(cOsgCanvas));
        default: return nullptr;
    };
}

void *cModuleDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cModule *pp = (cModule *)object; (void)pp;
    switch (field) {
        case 5: return (void *)(&pp->getDisplayString()); break;
        case 6: return (void *)static_cast<omnetpp::cObject *>(pp->gateByOrdinal(i)); break;
        case 7: return (void *)static_cast<omnetpp::cObject *>(pp->getCanvasIfExists()); break;
        case 8: return (void *)static_cast<omnetpp::cObject *>(pp->getOsgCanvasIfExists()); break;
        default: return nullptr;
    }
}

class cSimpleModuleDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cSimpleModuleDescriptor();
    virtual ~cSimpleModuleDescriptor();

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

Register_ClassDescriptor(cSimpleModuleDescriptor);

cSimpleModuleDescriptor::cSimpleModuleDescriptor() : omnetpp::cClassDescriptor("omnetpp::cSimpleModule", "omnetpp::cModule")
{
    propertynames = nullptr;
}

cSimpleModuleDescriptor::~cSimpleModuleDescriptor()
{
    delete[] propertynames;
}

bool cSimpleModuleDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cSimpleModule *>(obj)!=nullptr;
}

const char **cSimpleModuleDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "icon",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cSimpleModuleDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"icon")) return "simple";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cSimpleModuleDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int cSimpleModuleDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        0,
        0,
        0,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *cSimpleModuleDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "isTerminated",
        "usesActivity",
        "stackSize",
        "stackUsage",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int cSimpleModuleDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "isTerminated")==0) return base+0;
    if (fieldName[0]=='u' && strcmp(fieldName, "usesActivity")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "stackSize")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "stackUsage")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cSimpleModuleDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "bool",
        "unsigned int",
        "unsigned int",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **cSimpleModuleDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "getter", "group", "hint",  nullptr };
            return names;
        }
        case 1: {
            static const char *names[] = { "getter", "group", "hint",  nullptr };
            return names;
        }
        case 2: {
            static const char *names[] = { "group", "hint",  nullptr };
            return names;
        }
        case 3: {
            static const char *names[] = { "group", "hint",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cSimpleModuleDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"getter")) return "isTerminated";
            if (!strcmp(propertyname,"group")) return "fields";
            if (!strcmp(propertyname,"hint")) return "Whether this module has terminated";
            return nullptr;
        case 1:
            if (!strcmp(propertyname,"getter")) return "usesActivity";
            if (!strcmp(propertyname,"group")) return "activity";
            if (!strcmp(propertyname,"hint")) return "Whether this simple module was programmed using the \"activity\" or the \"handleMessage\" C++ method";
            return nullptr;
        case 2:
            if (!strcmp(propertyname,"group")) return "activity";
            if (!strcmp(propertyname,"hint")) return "If module uses \"activity\": stack size allocated for this module -- zero means info not available";
            return nullptr;
        case 3:
            if (!strcmp(propertyname,"group")) return "activity";
            if (!strcmp(propertyname,"hint")) return "If module uses \"activity\": stack actually used by this module -- zero means info not available";
            return nullptr;
        default: return nullptr;
    }
}

int cSimpleModuleDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cSimpleModule *pp = (cSimpleModule *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cSimpleModuleDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cSimpleModule *pp = (cSimpleModule *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->isTerminated());
        case 1: return bool2string(pp->usesActivity());
        case 2: return ulong2string(pp->getStackSize());
        case 3: return ulong2string(pp->getStackUsage());
        default: return "";
    }
}

bool cSimpleModuleDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cSimpleModule *pp = (cSimpleModule *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cSimpleModuleDescriptor::getFieldStructName(int field) const
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

void *cSimpleModuleDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cSimpleModule *pp = (cSimpleModule *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cComponentTypeDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cComponentTypeDescriptor();
    virtual ~cComponentTypeDescriptor();

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

Register_ClassDescriptor(cComponentTypeDescriptor);

cComponentTypeDescriptor::cComponentTypeDescriptor() : omnetpp::cClassDescriptor("omnetpp::cComponentType", "omnetpp::cNoncopyableOwnedObject")
{
    propertynames = nullptr;
}

cComponentTypeDescriptor::~cComponentTypeDescriptor()
{
    delete[] propertynames;
}

bool cComponentTypeDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cComponentType *>(obj)!=nullptr;
}

const char **cComponentTypeDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cComponentTypeDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cComponentTypeDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int cComponentTypeDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *cComponentTypeDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int cComponentTypeDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cComponentTypeDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **cComponentTypeDescriptor::getFieldPropertyNames(int field) const
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

const char *cComponentTypeDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cComponentTypeDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cComponentType *pp = (cComponentType *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cComponentTypeDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cComponentType *pp = (cComponentType *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cComponentTypeDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cComponentType *pp = (cComponentType *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cComponentTypeDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *cComponentTypeDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cComponentType *pp = (cComponentType *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cModuleTypeDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cModuleTypeDescriptor();
    virtual ~cModuleTypeDescriptor();

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

Register_ClassDescriptor(cModuleTypeDescriptor);

cModuleTypeDescriptor::cModuleTypeDescriptor() : omnetpp::cClassDescriptor("omnetpp::cModuleType", "omnetpp::cComponentType")
{
    propertynames = nullptr;
}

cModuleTypeDescriptor::~cModuleTypeDescriptor()
{
    delete[] propertynames;
}

bool cModuleTypeDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cModuleType *>(obj)!=nullptr;
}

const char **cModuleTypeDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cModuleTypeDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cModuleTypeDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int cModuleTypeDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *cModuleTypeDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "isNetwork",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int cModuleTypeDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "isNetwork")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cModuleTypeDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **cModuleTypeDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "getter", "group", "hint",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cModuleTypeDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"getter")) return "isNetwork";
            if (!strcmp(propertyname,"group")) return "fields";
            if (!strcmp(propertyname,"hint")) return "Whether this module type can be used as toplevel module";
            return nullptr;
        default: return nullptr;
    }
}

int cModuleTypeDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cModuleType *pp = (cModuleType *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cModuleTypeDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cModuleType *pp = (cModuleType *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->isNetwork());
        default: return "";
    }
}

bool cModuleTypeDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cModuleType *pp = (cModuleType *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cModuleTypeDescriptor::getFieldStructName(int field) const
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

void *cModuleTypeDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cModuleType *pp = (cModuleType *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cChannelTypeDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cChannelTypeDescriptor();
    virtual ~cChannelTypeDescriptor();

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

Register_ClassDescriptor(cChannelTypeDescriptor);

cChannelTypeDescriptor::cChannelTypeDescriptor() : omnetpp::cClassDescriptor("omnetpp::cChannelType", "omnetpp::cComponentType")
{
    propertynames = nullptr;
}

cChannelTypeDescriptor::~cChannelTypeDescriptor()
{
    delete[] propertynames;
}

bool cChannelTypeDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cChannelType *>(obj)!=nullptr;
}

const char **cChannelTypeDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cChannelTypeDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cChannelTypeDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int cChannelTypeDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *cChannelTypeDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int cChannelTypeDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cChannelTypeDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **cChannelTypeDescriptor::getFieldPropertyNames(int field) const
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

const char *cChannelTypeDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cChannelTypeDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cChannelType *pp = (cChannelType *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cChannelTypeDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cChannelType *pp = (cChannelType *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cChannelTypeDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cChannelType *pp = (cChannelType *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cChannelTypeDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *cChannelTypeDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cChannelType *pp = (cChannelType *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cRegistrationListDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cRegistrationListDescriptor();
    virtual ~cRegistrationListDescriptor();

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

Register_ClassDescriptor(cRegistrationListDescriptor);

cRegistrationListDescriptor::cRegistrationListDescriptor() : omnetpp::cClassDescriptor("omnetpp::cRegistrationList", "omnetpp::cNamedObject")
{
    propertynames = nullptr;
}

cRegistrationListDescriptor::~cRegistrationListDescriptor()
{
    delete[] propertynames;
}

bool cRegistrationListDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cRegistrationList *>(obj)!=nullptr;
}

const char **cRegistrationListDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cRegistrationListDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cRegistrationListDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int cRegistrationListDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *cRegistrationListDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "contents",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int cRegistrationListDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "contents")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cRegistrationListDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "cObject",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **cRegistrationListDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "getter", "hint", "sizeGetter",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cRegistrationListDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"getter")) return "get";
            if (!strcmp(propertyname,"hint")) return "Contained objects";
            if (!strcmp(propertyname,"sizeGetter")) return "size";
            return nullptr;
        default: return nullptr;
    }
}

int cRegistrationListDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cRegistrationList *pp = (cRegistrationList *)object; (void)pp;
    switch (field) {
        case 0: return pp->size();
        default: return 0;
    }
}

std::string cRegistrationListDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cRegistrationList *pp = (cRegistrationList *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->get(i); return out.str();}
        default: return "";
    }
}

bool cRegistrationListDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cRegistrationList *pp = (cRegistrationList *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cRegistrationListDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(cObject));
        default: return nullptr;
    };
}

void *cRegistrationListDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cRegistrationList *pp = (cRegistrationList *)object; (void)pp;
    switch (field) {
        case 0: return (void *)static_cast<omnetpp::cObject *>(pp->get(i)); break;
        default: return nullptr;
    }
}

class cGateDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cGateDescriptor();
    virtual ~cGateDescriptor();

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

Register_ClassDescriptor(cGateDescriptor);

cGateDescriptor::cGateDescriptor() : omnetpp::cClassDescriptor("omnetpp::cGate", "omnetpp::cObject")
{
    propertynames = nullptr;
}

cGateDescriptor::~cGateDescriptor()
{
    delete[] propertynames;
}

bool cGateDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cGate *>(obj)!=nullptr;
}

const char **cGateDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "icon",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cGateDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"icon")) return "gate";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cGateDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 14+basedesc->getFieldCount() : 14;
}

unsigned int cGateDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        0,
        0,
        0,
        0,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,
        0,
        0,
        0,
        0,
    };
    return (field>=0 && field<14) ? fieldTypeFlags[field] : 0;
}

const char *cGateDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "type",
        "id",
        "isVector",
        "index",
        "deliverOnReceptionStart",
        "channel",
        "previousGate",
        "nextGate",
        "pathStartGate",
        "pathEndGate",
        "isConnectedOutside",
        "isConnectedInside",
        "isConnected",
        "isPathOK",
    };
    return (field>=0 && field<14) ? fieldNames[field] : nullptr;
}

int cGateDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+0;
    if (fieldName[0]=='i' && strcmp(fieldName, "id")==0) return base+1;
    if (fieldName[0]=='i' && strcmp(fieldName, "isVector")==0) return base+2;
    if (fieldName[0]=='i' && strcmp(fieldName, "index")==0) return base+3;
    if (fieldName[0]=='d' && strcmp(fieldName, "deliverOnReceptionStart")==0) return base+4;
    if (fieldName[0]=='c' && strcmp(fieldName, "channel")==0) return base+5;
    if (fieldName[0]=='p' && strcmp(fieldName, "previousGate")==0) return base+6;
    if (fieldName[0]=='n' && strcmp(fieldName, "nextGate")==0) return base+7;
    if (fieldName[0]=='p' && strcmp(fieldName, "pathStartGate")==0) return base+8;
    if (fieldName[0]=='p' && strcmp(fieldName, "pathEndGate")==0) return base+9;
    if (fieldName[0]=='i' && strcmp(fieldName, "isConnectedOutside")==0) return base+10;
    if (fieldName[0]=='i' && strcmp(fieldName, "isConnectedInside")==0) return base+11;
    if (fieldName[0]=='i' && strcmp(fieldName, "isConnected")==0) return base+12;
    if (fieldName[0]=='i' && strcmp(fieldName, "isPathOK")==0) return base+13;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cGateDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "char",
        "int",
        "bool",
        "int",
        "bool",
        "cChannel",
        "cGate",
        "cGate",
        "cGate",
        "cGate",
        "bool",
        "bool",
        "bool",
        "bool",
    };
    return (field>=0 && field<14) ? fieldTypeStrings[field] : nullptr;
}

const char **cGateDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "enum", "group", "hint",  nullptr };
            return names;
        }
        case 1: {
            static const char *names[] = { "group", "hint",  nullptr };
            return names;
        }
        case 2: {
            static const char *names[] = { "getter", "group", "hint",  nullptr };
            return names;
        }
        case 3: {
            static const char *names[] = { "group", "hint",  nullptr };
            return names;
        }
        case 4: {
            static const char *names[] = { "group", "hint",  nullptr };
            return names;
        }
        case 5: {
            static const char *names[] = { "group", "hint",  nullptr };
            return names;
        }
        case 6: {
            static const char *names[] = { "group", "hint",  nullptr };
            return names;
        }
        case 7: {
            static const char *names[] = { "group", "hint",  nullptr };
            return names;
        }
        case 8: {
            static const char *names[] = { "group", "hint",  nullptr };
            return names;
        }
        case 9: {
            static const char *names[] = { "group", "hint",  nullptr };
            return names;
        }
        case 10: {
            static const char *names[] = { "getter", "group", "hint",  nullptr };
            return names;
        }
        case 11: {
            static const char *names[] = { "getter", "group", "hint",  nullptr };
            return names;
        }
        case 12: {
            static const char *names[] = { "getter", "group", "hint",  nullptr };
            return names;
        }
        case 13: {
            static const char *names[] = { "getter", "group", "hint",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cGateDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "omnetpp::cGate::Type";
            if (!strcmp(propertyname,"group")) return "fields";
            if (!strcmp(propertyname,"hint")) return "Gate type";
            return nullptr;
        case 1:
            if (!strcmp(propertyname,"group")) return "fields";
            if (!strcmp(propertyname,"hint")) return "Gate id, unique within this module";
            return nullptr;
        case 2:
            if (!strcmp(propertyname,"getter")) return "isVector";
            if (!strcmp(propertyname,"group")) return "fields";
            if (!strcmp(propertyname,"hint")) return "Whether this gate is part of a gate vector";
            return nullptr;
        case 3:
            if (!strcmp(propertyname,"group")) return "fields";
            if (!strcmp(propertyname,"hint")) return "If vector: index of this gate within its gate vector";
            return nullptr;
        case 4:
            if (!strcmp(propertyname,"group")) return "fields";
            if (!strcmp(propertyname,"hint")) return "Only for simple module input gates, and if message transmission duration is nonzero: whether messages arriving on this gate will be given to the module at the start or the end of the reception";
            return nullptr;
        case 5:
            if (!strcmp(propertyname,"group")) return "connection";
            if (!strcmp(propertyname,"hint")) return "Channel object associated with the connection";
            return nullptr;
        case 6:
            if (!strcmp(propertyname,"group")) return "connection";
            if (!strcmp(propertyname,"hint")) return "The gate this one is connected to -- for output gates this points out of this module, and for input gates it points inside";
            return nullptr;
        case 7:
            if (!strcmp(propertyname,"group")) return "connection";
            if (!strcmp(propertyname,"hint")) return "The gate whose \"previousGate\" is this gate -- note that \"previous\" and \"next\" correspond to the direction of messages";
            return nullptr;
        case 8:
            if (!strcmp(propertyname,"group")) return "connection";
            if (!strcmp(propertyname,"hint")) return "The last gate in the \"previousGate->previousGate->previousGate...\" chain";
            return nullptr;
        case 9:
            if (!strcmp(propertyname,"group")) return "connection";
            if (!strcmp(propertyname,"hint")) return "The last gate in the \"nextGate->nextGate->nextGate...\" chain";
            return nullptr;
        case 10:
            if (!strcmp(propertyname,"getter")) return "isConnectedOutside";
            if (!strcmp(propertyname,"group")) return "connection";
            if (!strcmp(propertyname,"hint")) return "For an output gate this checks nextGate, and previousGate for an input gate";
            return nullptr;
        case 11:
            if (!strcmp(propertyname,"getter")) return "isConnectedInside";
            if (!strcmp(propertyname,"group")) return "connection";
            if (!strcmp(propertyname,"hint")) return "For an input gate this checks nextGate, and previousGate for an output gate";
            return nullptr;
        case 12:
            if (!strcmp(propertyname,"getter")) return "isConnected";
            if (!strcmp(propertyname,"group")) return "connection";
            if (!strcmp(propertyname,"hint")) return "Whether the gate is fully connected -- both inside and outside for a compound module gate, and outside for a simple module gate";
            return nullptr;
        case 13:
            if (!strcmp(propertyname,"getter")) return "isPathOK";
            if (!strcmp(propertyname,"group")) return "connection";
            if (!strcmp(propertyname,"hint")) return "The chain of connections is OK if it starts and ends at a simple module";
            return nullptr;
        default: return nullptr;
    }
}

int cGateDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cGate *pp = (cGate *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cGateDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cGate *pp = (cGate *)object; (void)pp;
    switch (field) {
        case 0: return enum2string(pp->getType(), "omnetpp::cGate::Type");
        case 1: return long2string(pp->getId());
        case 2: return bool2string(pp->isVector());
        case 3: return long2string(pp->getIndex());
        case 4: return bool2string(pp->getDeliverOnReceptionStart());
        case 5: {std::stringstream out; out << pp->getChannel(); return out.str();}
        case 6: {std::stringstream out; out << pp->getPreviousGate(); return out.str();}
        case 7: {std::stringstream out; out << pp->getNextGate(); return out.str();}
        case 8: {std::stringstream out; out << pp->getPathStartGate(); return out.str();}
        case 9: {std::stringstream out; out << pp->getPathEndGate(); return out.str();}
        case 10: return bool2string(pp->isConnectedOutside());
        case 11: return bool2string(pp->isConnectedInside());
        case 12: return bool2string(pp->isConnected());
        case 13: return bool2string(pp->isPathOK());
        default: return "";
    }
}

bool cGateDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cGate *pp = (cGate *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cGateDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 5: return omnetpp::opp_typename(typeid(cChannel));
        case 6: return omnetpp::opp_typename(typeid(cGate));
        case 7: return omnetpp::opp_typename(typeid(cGate));
        case 8: return omnetpp::opp_typename(typeid(cGate));
        case 9: return omnetpp::opp_typename(typeid(cGate));
        default: return nullptr;
    };
}

void *cGateDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cGate *pp = (cGate *)object; (void)pp;
    switch (field) {
        case 5: return (void *)static_cast<omnetpp::cObject *>(pp->getChannel()); break;
        case 6: return (void *)static_cast<omnetpp::cObject *>(pp->getPreviousGate()); break;
        case 7: return (void *)static_cast<omnetpp::cObject *>(pp->getNextGate()); break;
        case 8: return (void *)static_cast<omnetpp::cObject *>(pp->getPathStartGate()); break;
        case 9: return (void *)static_cast<omnetpp::cObject *>(pp->getPathEndGate()); break;
        default: return nullptr;
    }
}

class cArrayDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cArrayDescriptor();
    virtual ~cArrayDescriptor();

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

Register_ClassDescriptor(cArrayDescriptor);

cArrayDescriptor::cArrayDescriptor() : omnetpp::cClassDescriptor("omnetpp::cArray", "omnetpp::cOwnedObject")
{
    propertynames = nullptr;
}

cArrayDescriptor::~cArrayDescriptor()
{
    delete[] propertynames;
}

bool cArrayDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cArray *>(obj)!=nullptr;
}

const char **cArrayDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "icon",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cArrayDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"icon")) return "container";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cArrayDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int cArrayDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *cArrayDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "takeOwnership",
        "contents",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int cArrayDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "takeOwnership")==0) return base+0;
    if (fieldName[0]=='c' && strcmp(fieldName, "contents")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cArrayDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "cOwnedObject",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **cArrayDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "editable", "group", "hint",  nullptr };
            return names;
        }
        case 1: {
            static const char *names[] = { "getter", "hint", "sizeGetter",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cArrayDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"group")) return "fields";
            if (!strcmp(propertyname,"hint")) return "Whether the array should own the objects inserted into it";
            return nullptr;
        case 1:
            if (!strcmp(propertyname,"getter")) return "get";
            if (!strcmp(propertyname,"hint")) return "Objects contained in the array";
            if (!strcmp(propertyname,"sizeGetter")) return "size";
            return nullptr;
        default: return nullptr;
    }
}

int cArrayDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cArray *pp = (cArray *)object; (void)pp;
    switch (field) {
        case 1: return pp->size();
        default: return 0;
    }
}

std::string cArrayDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cArray *pp = (cArray *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getTakeOwnership());
        case 1: {std::stringstream out; out << pp->get(i); return out.str();}
        default: return "";
    }
}

bool cArrayDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cArray *pp = (cArray *)object; (void)pp;
    switch (field) {
        case 0: pp->setTakeOwnership(string2bool(value)); return true;
        default: return false;
    }
}

const char *cArrayDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(cOwnedObject));
        default: return nullptr;
    };
}

void *cArrayDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cArray *pp = (cArray *)object; (void)pp;
    switch (field) {
        case 1: return (void *)static_cast<omnetpp::cObject *>(pp->get(i)); break;
        default: return nullptr;
    }
}

class cEventDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cEventDescriptor();
    virtual ~cEventDescriptor();

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

Register_ClassDescriptor(cEventDescriptor);

cEventDescriptor::cEventDescriptor() : omnetpp::cClassDescriptor("omnetpp::cEvent", "omnetpp::cOwnedObject")
{
    propertynames = nullptr;
}

cEventDescriptor::~cEventDescriptor()
{
    delete[] propertynames;
}

bool cEventDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cEvent *>(obj)!=nullptr;
}

const char **cEventDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cEventDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cEventDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int cEventDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,
        0,
        0,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *cEventDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "schedulingPriority",
        "targetObject",
        "isScheduled",
        "arrivalTime",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int cEventDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "schedulingPriority")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "targetObject")==0) return base+1;
    if (fieldName[0]=='i' && strcmp(fieldName, "isScheduled")==0) return base+2;
    if (fieldName[0]=='a' && strcmp(fieldName, "arrivalTime")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cEventDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "short",
        "cObject",
        "bool",
        "simtime_t",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **cEventDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "editable", "group", "hint",  nullptr };
            return names;
        }
        case 1: {
            static const char *names[] = { "group", "hint",  nullptr };
            return names;
        }
        case 2: {
            static const char *names[] = { "getter", "group", "hint",  nullptr };
            return names;
        }
        case 3: {
            static const char *names[] = { "group", "hint",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cEventDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"group")) return "event";
            if (!strcmp(propertyname,"hint")) return "Controls order of messages with equal timestamps in FES";
            return nullptr;
        case 1:
            if (!strcmp(propertyname,"group")) return "event";
            if (!strcmp(propertyname,"hint")) return "The object this message will be delivered to";
            return nullptr;
        case 2:
            if (!strcmp(propertyname,"getter")) return "isScheduled";
            if (!strcmp(propertyname,"group")) return "sending";
            if (!strcmp(propertyname,"hint")) return "Whether event or message is currently scheduled (or in transit)";
            return nullptr;
        case 3:
            if (!strcmp(propertyname,"group")) return "sending";
            if (!strcmp(propertyname,"hint")) return "Simulation time the event or message will be (or was) delivered";
            return nullptr;
        default: return nullptr;
    }
}

int cEventDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cEvent *pp = (cEvent *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cEventDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cEvent *pp = (cEvent *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getSchedulingPriority());
        case 1: {std::stringstream out; out << pp->getTargetObject(); return out.str();}
        case 2: return bool2string(pp->isScheduled());
        case 3: return simtime2string(pp->getArrivalTime());
        default: return "";
    }
}

bool cEventDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cEvent *pp = (cEvent *)object; (void)pp;
    switch (field) {
        case 0: pp->setSchedulingPriority(string2long(value)); return true;
        default: return false;
    }
}

const char *cEventDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(cObject));
        default: return nullptr;
    };
}

void *cEventDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cEvent *pp = (cEvent *)object; (void)pp;
    switch (field) {
        case 1: return (void *)static_cast<omnetpp::cObject *>(pp->getTargetObject()); break;
        default: return nullptr;
    }
}

class cMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cMessageDescriptor();
    virtual ~cMessageDescriptor();

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

Register_ClassDescriptor(cMessageDescriptor);

cMessageDescriptor::cMessageDescriptor() : omnetpp::cClassDescriptor("omnetpp::cMessage", "omnetpp::cEvent")
{
    propertynames = nullptr;
}

cMessageDescriptor::~cMessageDescriptor()
{
    delete[] propertynames;
}

bool cMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cMessage *>(obj)!=nullptr;
}

const char **cMessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "icon",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cMessageDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"icon")) return "message";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 19+basedesc->getFieldCount() : 19;
}

unsigned int cMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        0,
        FD_ISEDITABLE,
        0,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,
        0,
        0,
        0,
        FD_ISEDITABLE,
        0,
        0,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,
        0,
        0,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,
    };
    return (field>=0 && field<19) ? fieldTypeFlags[field] : 0;
}

const char *cMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "id",
        "treeId",
        "kind",
        "displayString",
        "tags",
        "controlInfo",
        "parList",
        "isSelfMessage",
        "creationTime",
        "sendingTime",
        "timestamp",
        "senderModuleId",
        "senderGateId",
        "senderModule",
        "senderGate",
        "arrivalModuleId",
        "arrivalGateId",
        "arrivalModule",
        "arrivalGate",
    };
    return (field>=0 && field<19) ? fieldNames[field] : nullptr;
}

int cMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "id")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "treeId")==0) return base+1;
    if (fieldName[0]=='k' && strcmp(fieldName, "kind")==0) return base+2;
    if (fieldName[0]=='d' && strcmp(fieldName, "displayString")==0) return base+3;
    if (fieldName[0]=='t' && strcmp(fieldName, "tags")==0) return base+4;
    if (fieldName[0]=='c' && strcmp(fieldName, "controlInfo")==0) return base+5;
    if (fieldName[0]=='p' && strcmp(fieldName, "parList")==0) return base+6;
    if (fieldName[0]=='i' && strcmp(fieldName, "isSelfMessage")==0) return base+7;
    if (fieldName[0]=='c' && strcmp(fieldName, "creationTime")==0) return base+8;
    if (fieldName[0]=='s' && strcmp(fieldName, "sendingTime")==0) return base+9;
    if (fieldName[0]=='t' && strcmp(fieldName, "timestamp")==0) return base+10;
    if (fieldName[0]=='s' && strcmp(fieldName, "senderModuleId")==0) return base+11;
    if (fieldName[0]=='s' && strcmp(fieldName, "senderGateId")==0) return base+12;
    if (fieldName[0]=='s' && strcmp(fieldName, "senderModule")==0) return base+13;
    if (fieldName[0]=='s' && strcmp(fieldName, "senderGate")==0) return base+14;
    if (fieldName[0]=='a' && strcmp(fieldName, "arrivalModuleId")==0) return base+15;
    if (fieldName[0]=='a' && strcmp(fieldName, "arrivalGateId")==0) return base+16;
    if (fieldName[0]=='a' && strcmp(fieldName, "arrivalModule")==0) return base+17;
    if (fieldName[0]=='a' && strcmp(fieldName, "arrivalGate")==0) return base+18;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "long",
        "long",
        "short",
        "string",
        "cObject",
        "cObject",
        "cArray",
        "bool",
        "simtime_t",
        "simtime_t",
        "simtime_t",
        "int",
        "int",
        "cModule",
        "cGate",
        "int",
        "int",
        "cModule",
        "cGate",
    };
    return (field>=0 && field<19) ? fieldTypeStrings[field] : nullptr;
}

const char **cMessageDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "group", "hint",  nullptr };
            return names;
        }
        case 1: {
            static const char *names[] = { "group", "hint",  nullptr };
            return names;
        }
        case 2: {
            static const char *names[] = { "editable", "group", "hint",  nullptr };
            return names;
        }
        case 3: {
            static const char *names[] = { "group", "hint",  nullptr };
            return names;
        }
        case 4: {
            static const char *names[] = { "getter", "group", "hint", "sizeGetter",  nullptr };
            return names;
        }
        case 5: {
            static const char *names[] = { "hint",  nullptr };
            return names;
        }
        case 6: {
            static const char *names[] = { "getter", "group", "hint",  nullptr };
            return names;
        }
        case 7: {
            static const char *names[] = { "getter", "group", "hint",  nullptr };
            return names;
        }
        case 8: {
            static const char *names[] = { "group", "hint",  nullptr };
            return names;
        }
        case 9: {
            static const char *names[] = { "group", "hint",  nullptr };
            return names;
        }
        case 10: {
            static const char *names[] = { "editable", "group", "hint",  nullptr };
            return names;
        }
        case 11: {
            static const char *names[] = { "group", "hint",  nullptr };
            return names;
        }
        case 12: {
            static const char *names[] = { "group", "hint",  nullptr };
            return names;
        }
        case 13: {
            static const char *names[] = { "eventlog", "group", "hint",  nullptr };
            return names;
        }
        case 14: {
            static const char *names[] = { "eventlog", "group", "hint",  nullptr };
            return names;
        }
        case 15: {
            static const char *names[] = { "group", "hint",  nullptr };
            return names;
        }
        case 16: {
            static const char *names[] = { "group", "hint",  nullptr };
            return names;
        }
        case 17: {
            static const char *names[] = { "eventlog", "group", "hint",  nullptr };
            return names;
        }
        case 18: {
            static const char *names[] = { "eventlog", "group", "hint",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cMessageDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"group")) return "message";
            if (!strcmp(propertyname,"hint")) return "Automatically assigned unique identifier";
            return nullptr;
        case 1:
            if (!strcmp(propertyname,"group")) return "message";
            if (!strcmp(propertyname,"hint")) return "Identifier shared between the message and its copies";
            return nullptr;
        case 2:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"group")) return "message";
            if (!strcmp(propertyname,"hint")) return "Generic user-settable attribute, usually carries \"type\" or \"role\" or \"category\" of message";
            return nullptr;
        case 3:
            if (!strcmp(propertyname,"group")) return "message";
            if (!strcmp(propertyname,"hint")) return "Controls appearance of the message in GUI";
            return nullptr;
        case 4:
            if (!strcmp(propertyname,"getter")) return "getTag";
            if (!strcmp(propertyname,"group")) return "message";
            if (!strcmp(propertyname,"hint")) return "Pieces of metadata attached to the message";
            if (!strcmp(propertyname,"sizeGetter")) return "getNumTags";
            return nullptr;
        case 5:
            if (!strcmp(propertyname,"hint")) return "Used with protocol stacks: carries extra information when a packet is sent between protocol layers";
            return nullptr;
        case 6:
            if (!strcmp(propertyname,"getter")) return "getParListPtr";
            if (!strcmp(propertyname,"group")) return "message";
            if (!strcmp(propertyname,"hint")) return "OBSOLETE: use of \"parList\" should be replaced with message subclassing in the few models that still use it";
            return nullptr;
        case 7:
            if (!strcmp(propertyname,"getter")) return "isSelfMessage";
            if (!strcmp(propertyname,"group")) return "sending";
            if (!strcmp(propertyname,"hint")) return "Whether message is a self-message, scheduled to be delivered back to the same module at a later time";
            return nullptr;
        case 8:
            if (!strcmp(propertyname,"group")) return "sending";
            if (!strcmp(propertyname,"hint")) return "Simulation time the message was created";
            return nullptr;
        case 9:
            if (!strcmp(propertyname,"group")) return "sending";
            if (!strcmp(propertyname,"hint")) return "Simulation time of the current or last sending/scheduling of the message";
            return nullptr;
        case 10:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"group")) return "sending";
            if (!strcmp(propertyname,"hint")) return "User-settable timestamp for generic use";
            return nullptr;
        case 11:
            if (!strcmp(propertyname,"group")) return "sending";
            if (!strcmp(propertyname,"hint")) return "ID of the module performing the current or last send/schedule operation";
            return nullptr;
        case 12:
            if (!strcmp(propertyname,"group")) return "sending";
            if (!strcmp(propertyname,"hint")) return "Module-local ID of the gate on which the message was sent out -- -1==none for self-messages and after \"sendDirect\"";
            return nullptr;
        case 13:
            if (!strcmp(propertyname,"eventlog")) return "fullPath";
            if (!strcmp(propertyname,"group")) return "sending";
            if (!strcmp(propertyname,"hint")) return "ID of the module performing the current or last send/schedule operation";
            return nullptr;
        case 14:
            if (!strcmp(propertyname,"eventlog")) return "fullName";
            if (!strcmp(propertyname,"group")) return "sending";
            if (!strcmp(propertyname,"hint")) return "The gate on which the message was sent out -- nullptr for self-messages and after \"sendDirect\"";
            return nullptr;
        case 15:
            if (!strcmp(propertyname,"group")) return "sending";
            if (!strcmp(propertyname,"hint")) return "ID of the arrival module of the current or last sending/scheduling";
            return nullptr;
        case 16:
            if (!strcmp(propertyname,"group")) return "sending";
            if (!strcmp(propertyname,"hint")) return "Module-local ID of arrival gate for current or last sending -- -1==none for self-messages";
            return nullptr;
        case 17:
            if (!strcmp(propertyname,"eventlog")) return "fullPath";
            if (!strcmp(propertyname,"group")) return "sending";
            if (!strcmp(propertyname,"hint")) return "Arrival module for current or last sending/scheduling";
            return nullptr;
        case 18:
            if (!strcmp(propertyname,"eventlog")) return "fullName";
            if (!strcmp(propertyname,"group")) return "sending";
            if (!strcmp(propertyname,"hint")) return "Arrival gate for current or last sending -- nullptr for self-messages";
            return nullptr;
        default: return nullptr;
    }
}

int cMessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cMessage *pp = (cMessage *)object; (void)pp;
    switch (field) {
        case 4: return pp->getNumTags();
        default: return 0;
    }
}

std::string cMessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cMessage *pp = (cMessage *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getId());
        case 1: return long2string(pp->getTreeId());
        case 2: return long2string(pp->getKind());
        case 3: return oppstring2string(pp->getDisplayString());
        case 4: {std::stringstream out; out << pp->getTag(i); return out.str();}
        case 5: {std::stringstream out; out << pp->getControlInfo(); return out.str();}
        case 6: {std::stringstream out; out << pp->getParListPtr(); return out.str();}
        case 7: return bool2string(pp->isSelfMessage());
        case 8: return simtime2string(pp->getCreationTime());
        case 9: return simtime2string(pp->getSendingTime());
        case 10: return simtime2string(pp->getTimestamp());
        case 11: return long2string(pp->getSenderModuleId());
        case 12: return long2string(pp->getSenderGateId());
        case 13: {std::stringstream out; out << pp->getSenderModule(); return out.str();}
        case 14: {std::stringstream out; out << pp->getSenderGate(); return out.str();}
        case 15: return long2string(pp->getArrivalModuleId());
        case 16: return long2string(pp->getArrivalGateId());
        case 17: {std::stringstream out; out << pp->getArrivalModule(); return out.str();}
        case 18: {std::stringstream out; out << pp->getArrivalGate(); return out.str();}
        default: return "";
    }
}

bool cMessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cMessage *pp = (cMessage *)object; (void)pp;
    switch (field) {
        case 2: pp->setKind(string2long(value)); return true;
        case 10: pp->setTimestamp(string2simtime(value)); return true;
        default: return false;
    }
}

const char *cMessageDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 4: return omnetpp::opp_typename(typeid(cObject));
        case 5: return omnetpp::opp_typename(typeid(cObject));
        case 6: return omnetpp::opp_typename(typeid(cArray));
        case 13: return omnetpp::opp_typename(typeid(cModule));
        case 14: return omnetpp::opp_typename(typeid(cGate));
        case 17: return omnetpp::opp_typename(typeid(cModule));
        case 18: return omnetpp::opp_typename(typeid(cGate));
        default: return nullptr;
    };
}

void *cMessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cMessage *pp = (cMessage *)object; (void)pp;
    switch (field) {
        case 4: return (void *)static_cast<omnetpp::cObject *>(pp->getTag(i)); break;
        case 5: return (void *)static_cast<omnetpp::cObject *>(pp->getControlInfo()); break;
        case 6: return (void *)static_cast<omnetpp::cObject *>(pp->getParListPtr()); break;
        case 13: return (void *)static_cast<omnetpp::cObject *>(pp->getSenderModule()); break;
        case 14: return (void *)static_cast<omnetpp::cObject *>(pp->getSenderGate()); break;
        case 17: return (void *)static_cast<omnetpp::cObject *>(pp->getArrivalModule()); break;
        case 18: return (void *)static_cast<omnetpp::cObject *>(pp->getArrivalGate()); break;
        default: return nullptr;
    }
}

class cPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cPacketDescriptor();
    virtual ~cPacketDescriptor();

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

Register_ClassDescriptor(cPacketDescriptor);

cPacketDescriptor::cPacketDescriptor() : omnetpp::cClassDescriptor("omnetpp::cPacket", "omnetpp::cMessage")
{
    propertynames = nullptr;
}

cPacketDescriptor::~cPacketDescriptor()
{
    delete[] propertynames;
}

bool cPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cPacket *>(obj)!=nullptr;
}

const char **cPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "icon",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cPacketDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"icon")) return "packet";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int cPacketDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,
        0,
        0,
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *cPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "bitLength",
        "byteLength",
        "hasBitError",
        "encapsulatedPacket",
        "isReceptionStart",
        "duration",
    };
    return (field>=0 && field<6) ? fieldNames[field] : nullptr;
}

int cPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='b' && strcmp(fieldName, "bitLength")==0) return base+0;
    if (fieldName[0]=='b' && strcmp(fieldName, "byteLength")==0) return base+1;
    if (fieldName[0]=='h' && strcmp(fieldName, "hasBitError")==0) return base+2;
    if (fieldName[0]=='e' && strcmp(fieldName, "encapsulatedPacket")==0) return base+3;
    if (fieldName[0]=='i' && strcmp(fieldName, "isReceptionStart")==0) return base+4;
    if (fieldName[0]=='d' && strcmp(fieldName, "duration")==0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int64_t",
        "int64_t",
        "bool",
        "cPacket",
        "bool",
        "simtime_t",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : nullptr;
}

const char **cPacketDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "editable", "group", "hint",  nullptr };
            return names;
        }
        case 1: {
            static const char *names[] = { "editable", "group", "hint",  nullptr };
            return names;
        }
        case 2: {
            static const char *names[] = { "editable", "getter", "group", "hint", "setter",  nullptr };
            return names;
        }
        case 3: {
            static const char *names[] = { "hint",  nullptr };
            return names;
        }
        case 4: {
            static const char *names[] = { "getter", "group", "hint",  nullptr };
            return names;
        }
        case 5: {
            static const char *names[] = { "group", "hint",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"group")) return "packet";
            if (!strcmp(propertyname,"hint")) return "Simulated length of the message in bits, affects transmission time and probability of bit errors when sent through a channel";
            return nullptr;
        case 1:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"group")) return "packet";
            if (!strcmp(propertyname,"hint")) return "Length in bytes, i.e. length in bits divided by eight";
            return nullptr;
        case 2:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"getter")) return "hasBitError";
            if (!strcmp(propertyname,"group")) return "packet";
            if (!strcmp(propertyname,"hint")) return "Indicates that a bit error occurred when the message was sent through a channel with nonzero bit error rate";
            if (!strcmp(propertyname,"setter")) return "setBitError";
            return nullptr;
        case 3:
            if (!strcmp(propertyname,"hint")) return "Used with protocol stacks: stores an encapsulated higher-layer packet";
            return nullptr;
        case 4:
            if (!strcmp(propertyname,"getter")) return "isReceptionStart";
            if (!strcmp(propertyname,"group")) return "sending";
            if (!strcmp(propertyname,"hint")) return "When duration is nonzero: whether this message represents the start or the end of the frame reception";
            return nullptr;
        case 5:
            if (!strcmp(propertyname,"group")) return "sending";
            if (!strcmp(propertyname,"hint")) return "Transmission time over a channel with datarate";
            return nullptr;
        default: return nullptr;
    }
}

int cPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cPacket *pp = (cPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cPacket *pp = (cPacket *)object; (void)pp;
    switch (field) {
        case 0: return int642string(pp->getBitLength());
        case 1: return int642string(pp->getByteLength());
        case 2: return bool2string(pp->hasBitError());
        case 3: {std::stringstream out; out << pp->getEncapsulatedPacket(); return out.str();}
        case 4: return bool2string(pp->isReceptionStart());
        case 5: return simtime2string(pp->getDuration());
        default: return "";
    }
}

bool cPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cPacket *pp = (cPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setBitLength(string2int64(value)); return true;
        case 1: pp->setByteLength(string2int64(value)); return true;
        case 2: pp->setBitError(string2bool(value)); return true;
        default: return false;
    }
}

const char *cPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 3: return omnetpp::opp_typename(typeid(cPacket));
        default: return nullptr;
    };
}

void *cPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cPacket *pp = (cPacket *)object; (void)pp;
    switch (field) {
        case 3: return (void *)static_cast<omnetpp::cObject *>(pp->getEncapsulatedPacket()); break;
        default: return nullptr;
    }
}

class cRNGDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cRNGDescriptor();
    virtual ~cRNGDescriptor();

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

Register_ClassDescriptor(cRNGDescriptor);

cRNGDescriptor::cRNGDescriptor() : omnetpp::cClassDescriptor("omnetpp::cRNG", "omnetpp::cObject")
{
    propertynames = nullptr;
}

cRNGDescriptor::~cRNGDescriptor()
{
    delete[] propertynames;
}

bool cRNGDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cRNG *>(obj)!=nullptr;
}

const char **cRNGDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cRNGDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cRNGDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int cRNGDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *cRNGDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int cRNGDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cRNGDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **cRNGDescriptor::getFieldPropertyNames(int field) const
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

const char *cRNGDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cRNGDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cRNG *pp = (cRNG *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cRNGDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cRNG *pp = (cRNG *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cRNGDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cRNG *pp = (cRNG *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cRNGDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *cRNGDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cRNG *pp = (cRNG *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cRandomDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cRandomDescriptor();
    virtual ~cRandomDescriptor();

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

Register_ClassDescriptor(cRandomDescriptor);

cRandomDescriptor::cRandomDescriptor() : omnetpp::cClassDescriptor("omnetpp::cRandom", "omnetpp::cOwnedObject")
{
    propertynames = nullptr;
}

cRandomDescriptor::~cRandomDescriptor()
{
    delete[] propertynames;
}

bool cRandomDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cRandom *>(obj)!=nullptr;
}

const char **cRandomDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "icon",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cRandomDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"icon")) return "cogwheel";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cRandomDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int cRandomDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *cRandomDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "rng",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int cRandomDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='r' && strcmp(fieldName, "rng")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cRandomDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "cRNG",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **cRandomDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "getter", "setter",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cRandomDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"getter")) return "getRNG";
            if (!strcmp(propertyname,"setter")) return "setRNG";
            return nullptr;
        default: return nullptr;
    }
}

int cRandomDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cRandom *pp = (cRandom *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cRandomDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cRandom *pp = (cRandom *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getRNG(); return out.str();}
        default: return "";
    }
}

bool cRandomDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cRandom *pp = (cRandom *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cRandomDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(cRNG));
        default: return nullptr;
    };
}

void *cRandomDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cRandom *pp = (cRandom *)object; (void)pp;
    switch (field) {
        case 0: return (void *)static_cast<omnetpp::cObject *>(pp->getRNG()); break;
        default: return nullptr;
    }
}

class cUniformDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cUniformDescriptor();
    virtual ~cUniformDescriptor();

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

Register_ClassDescriptor(cUniformDescriptor);

cUniformDescriptor::cUniformDescriptor() : omnetpp::cClassDescriptor("omnetpp::cUniform", "omnetpp::cRandom")
{
    propertynames = nullptr;
}

cUniformDescriptor::~cUniformDescriptor()
{
    delete[] propertynames;
}

bool cUniformDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cUniform *>(obj)!=nullptr;
}

const char **cUniformDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cUniformDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cUniformDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int cUniformDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        0,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *cUniformDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "a",
        "b",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int cUniformDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='a' && strcmp(fieldName, "a")==0) return base+0;
    if (fieldName[0]=='b' && strcmp(fieldName, "b")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cUniformDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "double",
        "double",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **cUniformDescriptor::getFieldPropertyNames(int field) const
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

const char *cUniformDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cUniformDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cUniform *pp = (cUniform *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cUniformDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cUniform *pp = (cUniform *)object; (void)pp;
    switch (field) {
        case 0: return double2string(pp->getA());
        case 1: return double2string(pp->getB());
        default: return "";
    }
}

bool cUniformDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cUniform *pp = (cUniform *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cUniformDescriptor::getFieldStructName(int field) const
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

void *cUniformDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cUniform *pp = (cUniform *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cExponentialDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cExponentialDescriptor();
    virtual ~cExponentialDescriptor();

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

Register_ClassDescriptor(cExponentialDescriptor);

cExponentialDescriptor::cExponentialDescriptor() : omnetpp::cClassDescriptor("omnetpp::cExponential", "omnetpp::cRandom")
{
    propertynames = nullptr;
}

cExponentialDescriptor::~cExponentialDescriptor()
{
    delete[] propertynames;
}

bool cExponentialDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cExponential *>(obj)!=nullptr;
}

const char **cExponentialDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cExponentialDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cExponentialDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int cExponentialDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *cExponentialDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "mean",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int cExponentialDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='m' && strcmp(fieldName, "mean")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cExponentialDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "double",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **cExponentialDescriptor::getFieldPropertyNames(int field) const
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

const char *cExponentialDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cExponentialDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cExponential *pp = (cExponential *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cExponentialDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cExponential *pp = (cExponential *)object; (void)pp;
    switch (field) {
        case 0: return double2string(pp->getMean());
        default: return "";
    }
}

bool cExponentialDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cExponential *pp = (cExponential *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cExponentialDescriptor::getFieldStructName(int field) const
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

void *cExponentialDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cExponential *pp = (cExponential *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cNormalDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cNormalDescriptor();
    virtual ~cNormalDescriptor();

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

Register_ClassDescriptor(cNormalDescriptor);

cNormalDescriptor::cNormalDescriptor() : omnetpp::cClassDescriptor("omnetpp::cNormal", "omnetpp::cRandom")
{
    propertynames = nullptr;
}

cNormalDescriptor::~cNormalDescriptor()
{
    delete[] propertynames;
}

bool cNormalDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cNormal *>(obj)!=nullptr;
}

const char **cNormalDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cNormalDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cNormalDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int cNormalDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        0,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *cNormalDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "mean",
        "stddev",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int cNormalDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='m' && strcmp(fieldName, "mean")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "stddev")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cNormalDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "double",
        "double",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **cNormalDescriptor::getFieldPropertyNames(int field) const
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

const char *cNormalDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cNormalDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cNormal *pp = (cNormal *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cNormalDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cNormal *pp = (cNormal *)object; (void)pp;
    switch (field) {
        case 0: return double2string(pp->getMean());
        case 1: return double2string(pp->getStddev());
        default: return "";
    }
}

bool cNormalDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cNormal *pp = (cNormal *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cNormalDescriptor::getFieldStructName(int field) const
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

void *cNormalDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cNormal *pp = (cNormal *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cTruncNormalDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cTruncNormalDescriptor();
    virtual ~cTruncNormalDescriptor();

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

Register_ClassDescriptor(cTruncNormalDescriptor);

cTruncNormalDescriptor::cTruncNormalDescriptor() : omnetpp::cClassDescriptor("omnetpp::cTruncNormal", "omnetpp::cRandom")
{
    propertynames = nullptr;
}

cTruncNormalDescriptor::~cTruncNormalDescriptor()
{
    delete[] propertynames;
}

bool cTruncNormalDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cTruncNormal *>(obj)!=nullptr;
}

const char **cTruncNormalDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cTruncNormalDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cTruncNormalDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int cTruncNormalDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        0,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *cTruncNormalDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "mean",
        "stddev",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int cTruncNormalDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='m' && strcmp(fieldName, "mean")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "stddev")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cTruncNormalDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "double",
        "double",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **cTruncNormalDescriptor::getFieldPropertyNames(int field) const
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

const char *cTruncNormalDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cTruncNormalDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cTruncNormal *pp = (cTruncNormal *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cTruncNormalDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cTruncNormal *pp = (cTruncNormal *)object; (void)pp;
    switch (field) {
        case 0: return double2string(pp->getMean());
        case 1: return double2string(pp->getStddev());
        default: return "";
    }
}

bool cTruncNormalDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cTruncNormal *pp = (cTruncNormal *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cTruncNormalDescriptor::getFieldStructName(int field) const
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

void *cTruncNormalDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cTruncNormal *pp = (cTruncNormal *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cGammaDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cGammaDescriptor();
    virtual ~cGammaDescriptor();

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

Register_ClassDescriptor(cGammaDescriptor);

cGammaDescriptor::cGammaDescriptor() : omnetpp::cClassDescriptor("omnetpp::cGamma", "omnetpp::cRandom")
{
    propertynames = nullptr;
}

cGammaDescriptor::~cGammaDescriptor()
{
    delete[] propertynames;
}

bool cGammaDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cGamma *>(obj)!=nullptr;
}

const char **cGammaDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cGammaDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cGammaDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int cGammaDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        0,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *cGammaDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "alpha",
        "theta",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int cGammaDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='a' && strcmp(fieldName, "alpha")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "theta")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cGammaDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "double",
        "double",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **cGammaDescriptor::getFieldPropertyNames(int field) const
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

const char *cGammaDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cGammaDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cGamma *pp = (cGamma *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cGammaDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cGamma *pp = (cGamma *)object; (void)pp;
    switch (field) {
        case 0: return double2string(pp->getAlpha());
        case 1: return double2string(pp->getTheta());
        default: return "";
    }
}

bool cGammaDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cGamma *pp = (cGamma *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cGammaDescriptor::getFieldStructName(int field) const
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

void *cGammaDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cGamma *pp = (cGamma *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cBetaDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cBetaDescriptor();
    virtual ~cBetaDescriptor();

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

Register_ClassDescriptor(cBetaDescriptor);

cBetaDescriptor::cBetaDescriptor() : omnetpp::cClassDescriptor("omnetpp::cBeta", "omnetpp::cRandom")
{
    propertynames = nullptr;
}

cBetaDescriptor::~cBetaDescriptor()
{
    delete[] propertynames;
}

bool cBetaDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cBeta *>(obj)!=nullptr;
}

const char **cBetaDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cBetaDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cBetaDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int cBetaDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        0,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *cBetaDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "alpha1",
        "alpha2",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int cBetaDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='a' && strcmp(fieldName, "alpha1")==0) return base+0;
    if (fieldName[0]=='a' && strcmp(fieldName, "alpha2")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cBetaDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "double",
        "double",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **cBetaDescriptor::getFieldPropertyNames(int field) const
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

const char *cBetaDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cBetaDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cBeta *pp = (cBeta *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cBetaDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cBeta *pp = (cBeta *)object; (void)pp;
    switch (field) {
        case 0: return double2string(pp->getAlpha1());
        case 1: return double2string(pp->getAlpha2());
        default: return "";
    }
}

bool cBetaDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cBeta *pp = (cBeta *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cBetaDescriptor::getFieldStructName(int field) const
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

void *cBetaDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cBeta *pp = (cBeta *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cErlangDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cErlangDescriptor();
    virtual ~cErlangDescriptor();

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

Register_ClassDescriptor(cErlangDescriptor);

cErlangDescriptor::cErlangDescriptor() : omnetpp::cClassDescriptor("omnetpp::cErlang", "omnetpp::cRandom")
{
    propertynames = nullptr;
}

cErlangDescriptor::~cErlangDescriptor()
{
    delete[] propertynames;
}

bool cErlangDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cErlang *>(obj)!=nullptr;
}

const char **cErlangDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cErlangDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cErlangDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int cErlangDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        0,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *cErlangDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "k",
        "mean",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int cErlangDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='k' && strcmp(fieldName, "k")==0) return base+0;
    if (fieldName[0]=='m' && strcmp(fieldName, "mean")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cErlangDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",
        "double",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **cErlangDescriptor::getFieldPropertyNames(int field) const
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

const char *cErlangDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cErlangDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cErlang *pp = (cErlang *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cErlangDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cErlang *pp = (cErlang *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getK());
        case 1: return double2string(pp->getMean());
        default: return "";
    }
}

bool cErlangDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cErlang *pp = (cErlang *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cErlangDescriptor::getFieldStructName(int field) const
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

void *cErlangDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cErlang *pp = (cErlang *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cChiSquareDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cChiSquareDescriptor();
    virtual ~cChiSquareDescriptor();

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

Register_ClassDescriptor(cChiSquareDescriptor);

cChiSquareDescriptor::cChiSquareDescriptor() : omnetpp::cClassDescriptor("omnetpp::cChiSquare", "omnetpp::cRandom")
{
    propertynames = nullptr;
}

cChiSquareDescriptor::~cChiSquareDescriptor()
{
    delete[] propertynames;
}

bool cChiSquareDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cChiSquare *>(obj)!=nullptr;
}

const char **cChiSquareDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cChiSquareDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cChiSquareDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int cChiSquareDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *cChiSquareDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "k",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int cChiSquareDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='k' && strcmp(fieldName, "k")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cChiSquareDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **cChiSquareDescriptor::getFieldPropertyNames(int field) const
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

const char *cChiSquareDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cChiSquareDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cChiSquare *pp = (cChiSquare *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cChiSquareDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cChiSquare *pp = (cChiSquare *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getK());
        default: return "";
    }
}

bool cChiSquareDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cChiSquare *pp = (cChiSquare *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cChiSquareDescriptor::getFieldStructName(int field) const
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

void *cChiSquareDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cChiSquare *pp = (cChiSquare *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cStudentTDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cStudentTDescriptor();
    virtual ~cStudentTDescriptor();

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

Register_ClassDescriptor(cStudentTDescriptor);

cStudentTDescriptor::cStudentTDescriptor() : omnetpp::cClassDescriptor("omnetpp::cStudentT", "omnetpp::cRandom")
{
    propertynames = nullptr;
}

cStudentTDescriptor::~cStudentTDescriptor()
{
    delete[] propertynames;
}

bool cStudentTDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cStudentT *>(obj)!=nullptr;
}

const char **cStudentTDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cStudentTDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cStudentTDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int cStudentTDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *cStudentTDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "i",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int cStudentTDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "i")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cStudentTDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **cStudentTDescriptor::getFieldPropertyNames(int field) const
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

const char *cStudentTDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cStudentTDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cStudentT *pp = (cStudentT *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cStudentTDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cStudentT *pp = (cStudentT *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getI());
        default: return "";
    }
}

bool cStudentTDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cStudentT *pp = (cStudentT *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cStudentTDescriptor::getFieldStructName(int field) const
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

void *cStudentTDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cStudentT *pp = (cStudentT *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cCauchyDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cCauchyDescriptor();
    virtual ~cCauchyDescriptor();

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

Register_ClassDescriptor(cCauchyDescriptor);

cCauchyDescriptor::cCauchyDescriptor() : omnetpp::cClassDescriptor("omnetpp::cCauchy", "omnetpp::cRandom")
{
    propertynames = nullptr;
}

cCauchyDescriptor::~cCauchyDescriptor()
{
    delete[] propertynames;
}

bool cCauchyDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cCauchy *>(obj)!=nullptr;
}

const char **cCauchyDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cCauchyDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cCauchyDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int cCauchyDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        0,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *cCauchyDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "a",
        "b",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int cCauchyDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='a' && strcmp(fieldName, "a")==0) return base+0;
    if (fieldName[0]=='b' && strcmp(fieldName, "b")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cCauchyDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "double",
        "double",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **cCauchyDescriptor::getFieldPropertyNames(int field) const
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

const char *cCauchyDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cCauchyDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cCauchy *pp = (cCauchy *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cCauchyDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cCauchy *pp = (cCauchy *)object; (void)pp;
    switch (field) {
        case 0: return double2string(pp->getA());
        case 1: return double2string(pp->getB());
        default: return "";
    }
}

bool cCauchyDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cCauchy *pp = (cCauchy *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cCauchyDescriptor::getFieldStructName(int field) const
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

void *cCauchyDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cCauchy *pp = (cCauchy *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cTriangDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cTriangDescriptor();
    virtual ~cTriangDescriptor();

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

Register_ClassDescriptor(cTriangDescriptor);

cTriangDescriptor::cTriangDescriptor() : omnetpp::cClassDescriptor("omnetpp::cTriang", "omnetpp::cRandom")
{
    propertynames = nullptr;
}

cTriangDescriptor::~cTriangDescriptor()
{
    delete[] propertynames;
}

bool cTriangDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cTriang *>(obj)!=nullptr;
}

const char **cTriangDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cTriangDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cTriangDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int cTriangDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        0,
        0,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *cTriangDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "a",
        "b",
        "c",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int cTriangDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='a' && strcmp(fieldName, "a")==0) return base+0;
    if (fieldName[0]=='b' && strcmp(fieldName, "b")==0) return base+1;
    if (fieldName[0]=='c' && strcmp(fieldName, "c")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cTriangDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "double",
        "double",
        "double",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **cTriangDescriptor::getFieldPropertyNames(int field) const
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

const char *cTriangDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cTriangDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cTriang *pp = (cTriang *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cTriangDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cTriang *pp = (cTriang *)object; (void)pp;
    switch (field) {
        case 0: return double2string(pp->getA());
        case 1: return double2string(pp->getB());
        case 2: return double2string(pp->getC());
        default: return "";
    }
}

bool cTriangDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cTriang *pp = (cTriang *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cTriangDescriptor::getFieldStructName(int field) const
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

void *cTriangDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cTriang *pp = (cTriang *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cWeibullDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cWeibullDescriptor();
    virtual ~cWeibullDescriptor();

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

Register_ClassDescriptor(cWeibullDescriptor);

cWeibullDescriptor::cWeibullDescriptor() : omnetpp::cClassDescriptor("omnetpp::cWeibull", "omnetpp::cRandom")
{
    propertynames = nullptr;
}

cWeibullDescriptor::~cWeibullDescriptor()
{
    delete[] propertynames;
}

bool cWeibullDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cWeibull *>(obj)!=nullptr;
}

const char **cWeibullDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cWeibullDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cWeibullDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int cWeibullDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        0,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *cWeibullDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "a",
        "b",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int cWeibullDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='a' && strcmp(fieldName, "a")==0) return base+0;
    if (fieldName[0]=='b' && strcmp(fieldName, "b")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cWeibullDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "double",
        "double",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **cWeibullDescriptor::getFieldPropertyNames(int field) const
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

const char *cWeibullDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cWeibullDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cWeibull *pp = (cWeibull *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cWeibullDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cWeibull *pp = (cWeibull *)object; (void)pp;
    switch (field) {
        case 0: return double2string(pp->getA());
        case 1: return double2string(pp->getB());
        default: return "";
    }
}

bool cWeibullDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cWeibull *pp = (cWeibull *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cWeibullDescriptor::getFieldStructName(int field) const
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

void *cWeibullDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cWeibull *pp = (cWeibull *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cParetoShiftedDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cParetoShiftedDescriptor();
    virtual ~cParetoShiftedDescriptor();

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

Register_ClassDescriptor(cParetoShiftedDescriptor);

cParetoShiftedDescriptor::cParetoShiftedDescriptor() : omnetpp::cClassDescriptor("omnetpp::cParetoShifted", "omnetpp::cRandom")
{
    propertynames = nullptr;
}

cParetoShiftedDescriptor::~cParetoShiftedDescriptor()
{
    delete[] propertynames;
}

bool cParetoShiftedDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cParetoShifted *>(obj)!=nullptr;
}

const char **cParetoShiftedDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cParetoShiftedDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cParetoShiftedDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int cParetoShiftedDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        0,
        0,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *cParetoShiftedDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "a",
        "b",
        "c",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int cParetoShiftedDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='a' && strcmp(fieldName, "a")==0) return base+0;
    if (fieldName[0]=='b' && strcmp(fieldName, "b")==0) return base+1;
    if (fieldName[0]=='c' && strcmp(fieldName, "c")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cParetoShiftedDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "double",
        "double",
        "double",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **cParetoShiftedDescriptor::getFieldPropertyNames(int field) const
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

const char *cParetoShiftedDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cParetoShiftedDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cParetoShifted *pp = (cParetoShifted *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cParetoShiftedDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cParetoShifted *pp = (cParetoShifted *)object; (void)pp;
    switch (field) {
        case 0: return double2string(pp->getA());
        case 1: return double2string(pp->getB());
        case 2: return double2string(pp->getC());
        default: return "";
    }
}

bool cParetoShiftedDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cParetoShifted *pp = (cParetoShifted *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cParetoShiftedDescriptor::getFieldStructName(int field) const
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

void *cParetoShiftedDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cParetoShifted *pp = (cParetoShifted *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cIntUniformDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cIntUniformDescriptor();
    virtual ~cIntUniformDescriptor();

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

Register_ClassDescriptor(cIntUniformDescriptor);

cIntUniformDescriptor::cIntUniformDescriptor() : omnetpp::cClassDescriptor("omnetpp::cIntUniform", "omnetpp::cRandom")
{
    propertynames = nullptr;
}

cIntUniformDescriptor::~cIntUniformDescriptor()
{
    delete[] propertynames;
}

bool cIntUniformDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cIntUniform *>(obj)!=nullptr;
}

const char **cIntUniformDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cIntUniformDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cIntUniformDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int cIntUniformDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        0,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *cIntUniformDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "a",
        "b",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int cIntUniformDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='a' && strcmp(fieldName, "a")==0) return base+0;
    if (fieldName[0]=='b' && strcmp(fieldName, "b")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cIntUniformDescriptor::getFieldTypeString(int field) const
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
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **cIntUniformDescriptor::getFieldPropertyNames(int field) const
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

const char *cIntUniformDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cIntUniformDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cIntUniform *pp = (cIntUniform *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cIntUniformDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cIntUniform *pp = (cIntUniform *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getA());
        case 1: return long2string(pp->getB());
        default: return "";
    }
}

bool cIntUniformDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cIntUniform *pp = (cIntUniform *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cIntUniformDescriptor::getFieldStructName(int field) const
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

void *cIntUniformDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cIntUniform *pp = (cIntUniform *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cBernoulliDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cBernoulliDescriptor();
    virtual ~cBernoulliDescriptor();

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

Register_ClassDescriptor(cBernoulliDescriptor);

cBernoulliDescriptor::cBernoulliDescriptor() : omnetpp::cClassDescriptor("omnetpp::cBernoulli", "omnetpp::cRandom")
{
    propertynames = nullptr;
}

cBernoulliDescriptor::~cBernoulliDescriptor()
{
    delete[] propertynames;
}

bool cBernoulliDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cBernoulli *>(obj)!=nullptr;
}

const char **cBernoulliDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cBernoulliDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cBernoulliDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int cBernoulliDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *cBernoulliDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "p",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int cBernoulliDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "p")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cBernoulliDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "double",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **cBernoulliDescriptor::getFieldPropertyNames(int field) const
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

const char *cBernoulliDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cBernoulliDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cBernoulli *pp = (cBernoulli *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cBernoulliDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cBernoulli *pp = (cBernoulli *)object; (void)pp;
    switch (field) {
        case 0: return double2string(pp->getP());
        default: return "";
    }
}

bool cBernoulliDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cBernoulli *pp = (cBernoulli *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cBernoulliDescriptor::getFieldStructName(int field) const
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

void *cBernoulliDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cBernoulli *pp = (cBernoulli *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cBinomialDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cBinomialDescriptor();
    virtual ~cBinomialDescriptor();

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

Register_ClassDescriptor(cBinomialDescriptor);

cBinomialDescriptor::cBinomialDescriptor() : omnetpp::cClassDescriptor("omnetpp::cBinomial", "omnetpp::cRandom")
{
    propertynames = nullptr;
}

cBinomialDescriptor::~cBinomialDescriptor()
{
    delete[] propertynames;
}

bool cBinomialDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cBinomial *>(obj)!=nullptr;
}

const char **cBinomialDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cBinomialDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cBinomialDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int cBinomialDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        0,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *cBinomialDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "n",
        "p",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int cBinomialDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='n' && strcmp(fieldName, "n")==0) return base+0;
    if (fieldName[0]=='p' && strcmp(fieldName, "p")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cBinomialDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "double",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **cBinomialDescriptor::getFieldPropertyNames(int field) const
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

const char *cBinomialDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cBinomialDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cBinomial *pp = (cBinomial *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cBinomialDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cBinomial *pp = (cBinomial *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getN());
        case 1: return double2string(pp->getP());
        default: return "";
    }
}

bool cBinomialDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cBinomial *pp = (cBinomial *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cBinomialDescriptor::getFieldStructName(int field) const
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

void *cBinomialDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cBinomial *pp = (cBinomial *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cGeometricDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cGeometricDescriptor();
    virtual ~cGeometricDescriptor();

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

Register_ClassDescriptor(cGeometricDescriptor);

cGeometricDescriptor::cGeometricDescriptor() : omnetpp::cClassDescriptor("omnetpp::cGeometric", "omnetpp::cRandom")
{
    propertynames = nullptr;
}

cGeometricDescriptor::~cGeometricDescriptor()
{
    delete[] propertynames;
}

bool cGeometricDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cGeometric *>(obj)!=nullptr;
}

const char **cGeometricDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cGeometricDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cGeometricDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int cGeometricDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *cGeometricDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "p",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int cGeometricDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "p")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cGeometricDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "double",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **cGeometricDescriptor::getFieldPropertyNames(int field) const
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

const char *cGeometricDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cGeometricDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cGeometric *pp = (cGeometric *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cGeometricDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cGeometric *pp = (cGeometric *)object; (void)pp;
    switch (field) {
        case 0: return double2string(pp->getP());
        default: return "";
    }
}

bool cGeometricDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cGeometric *pp = (cGeometric *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cGeometricDescriptor::getFieldStructName(int field) const
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

void *cGeometricDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cGeometric *pp = (cGeometric *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cNegBinomialDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cNegBinomialDescriptor();
    virtual ~cNegBinomialDescriptor();

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

Register_ClassDescriptor(cNegBinomialDescriptor);

cNegBinomialDescriptor::cNegBinomialDescriptor() : omnetpp::cClassDescriptor("omnetpp::cNegBinomial", "omnetpp::cRandom")
{
    propertynames = nullptr;
}

cNegBinomialDescriptor::~cNegBinomialDescriptor()
{
    delete[] propertynames;
}

bool cNegBinomialDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cNegBinomial *>(obj)!=nullptr;
}

const char **cNegBinomialDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cNegBinomialDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cNegBinomialDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int cNegBinomialDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        0,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *cNegBinomialDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "n",
        "p",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int cNegBinomialDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='n' && strcmp(fieldName, "n")==0) return base+0;
    if (fieldName[0]=='p' && strcmp(fieldName, "p")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cNegBinomialDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "double",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **cNegBinomialDescriptor::getFieldPropertyNames(int field) const
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

const char *cNegBinomialDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cNegBinomialDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cNegBinomial *pp = (cNegBinomial *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cNegBinomialDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cNegBinomial *pp = (cNegBinomial *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getN());
        case 1: return double2string(pp->getP());
        default: return "";
    }
}

bool cNegBinomialDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cNegBinomial *pp = (cNegBinomial *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cNegBinomialDescriptor::getFieldStructName(int field) const
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

void *cNegBinomialDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cNegBinomial *pp = (cNegBinomial *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cPoissonDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cPoissonDescriptor();
    virtual ~cPoissonDescriptor();

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

Register_ClassDescriptor(cPoissonDescriptor);

cPoissonDescriptor::cPoissonDescriptor() : omnetpp::cClassDescriptor("omnetpp::cPoisson", "omnetpp::cRandom")
{
    propertynames = nullptr;
}

cPoissonDescriptor::~cPoissonDescriptor()
{
    delete[] propertynames;
}

bool cPoissonDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cPoisson *>(obj)!=nullptr;
}

const char **cPoissonDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cPoissonDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cPoissonDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int cPoissonDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *cPoissonDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "lambda",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int cPoissonDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='l' && strcmp(fieldName, "lambda")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cPoissonDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "double",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **cPoissonDescriptor::getFieldPropertyNames(int field) const
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

const char *cPoissonDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cPoissonDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cPoisson *pp = (cPoisson *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cPoissonDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cPoisson *pp = (cPoisson *)object; (void)pp;
    switch (field) {
        case 0: return double2string(pp->getLambda());
        default: return "";
    }
}

bool cPoissonDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cPoisson *pp = (cPoisson *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cPoissonDescriptor::getFieldStructName(int field) const
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

void *cPoissonDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cPoisson *pp = (cPoisson *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cStatisticDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cStatisticDescriptor();
    virtual ~cStatisticDescriptor();

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

Register_ClassDescriptor(cStatisticDescriptor);

cStatisticDescriptor::cStatisticDescriptor() : omnetpp::cClassDescriptor("omnetpp::cStatistic", "omnetpp::cOwnedObject")
{
    propertynames = nullptr;
}

cStatisticDescriptor::~cStatisticDescriptor()
{
    delete[] propertynames;
}

bool cStatisticDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cStatistic *>(obj)!=nullptr;
}

const char **cStatisticDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "icon",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cStatisticDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"icon")) return "statistic";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cStatisticDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 9+basedesc->getFieldCount() : 9;
}

unsigned int cStatisticDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
    };
    return (field>=0 && field<9) ? fieldTypeFlags[field] : 0;
}

const char *cStatisticDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "count",
        "weights",
        "sum",
        "sqrSum",
        "min",
        "max",
        "mean",
        "stddev",
        "variance",
    };
    return (field>=0 && field<9) ? fieldNames[field] : nullptr;
}

int cStatisticDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "count")==0) return base+0;
    if (fieldName[0]=='w' && strcmp(fieldName, "weights")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "sum")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "sqrSum")==0) return base+3;
    if (fieldName[0]=='m' && strcmp(fieldName, "min")==0) return base+4;
    if (fieldName[0]=='m' && strcmp(fieldName, "max")==0) return base+5;
    if (fieldName[0]=='m' && strcmp(fieldName, "mean")==0) return base+6;
    if (fieldName[0]=='s' && strcmp(fieldName, "stddev")==0) return base+7;
    if (fieldName[0]=='v' && strcmp(fieldName, "variance")==0) return base+8;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cStatisticDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "long",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
    };
    return (field>=0 && field<9) ? fieldTypeStrings[field] : nullptr;
}

const char **cStatisticDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "hint",  nullptr };
            return names;
        }
        case 1: {
            static const char *names[] = { "hint",  nullptr };
            return names;
        }
        case 2: {
            static const char *names[] = { "hint",  nullptr };
            return names;
        }
        case 3: {
            static const char *names[] = { "hint",  nullptr };
            return names;
        }
        case 4: {
            static const char *names[] = { "hint",  nullptr };
            return names;
        }
        case 5: {
            static const char *names[] = { "hint",  nullptr };
            return names;
        }
        case 6: {
            static const char *names[] = { "hint",  nullptr };
            return names;
        }
        case 7: {
            static const char *names[] = { "hint",  nullptr };
            return names;
        }
        case 8: {
            static const char *names[] = { "hint",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cStatisticDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"hint")) return "Number of observations collected so far";
            return nullptr;
        case 1:
            if (!strcmp(propertyname,"hint")) return "Sum of weights, which equals the number of observations in the unweighted case";
            return nullptr;
        case 2:
            if (!strcmp(propertyname,"hint")) return "Sum of observations";
            return nullptr;
        case 3:
            if (!strcmp(propertyname,"hint")) return "Sum of squares of the observations";
            return nullptr;
        case 4:
            if (!strcmp(propertyname,"hint")) return "Minimum of the observations";
            return nullptr;
        case 5:
            if (!strcmp(propertyname,"hint")) return "Maximum of the observations";
            return nullptr;
        case 6:
            if (!strcmp(propertyname,"hint")) return "Mean of the observations";
            return nullptr;
        case 7:
            if (!strcmp(propertyname,"hint")) return "Standard deviation of the observations";
            return nullptr;
        case 8:
            if (!strcmp(propertyname,"hint")) return "Variance of the observations";
            return nullptr;
        default: return nullptr;
    }
}

int cStatisticDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cStatistic *pp = (cStatistic *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cStatisticDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cStatistic *pp = (cStatistic *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getCount());
        case 1: return double2string(pp->getWeights());
        case 2: return double2string(pp->getSum());
        case 3: return double2string(pp->getSqrSum());
        case 4: return double2string(pp->getMin());
        case 5: return double2string(pp->getMax());
        case 6: return double2string(pp->getMean());
        case 7: return double2string(pp->getStddev());
        case 8: return double2string(pp->getVariance());
        default: return "";
    }
}

bool cStatisticDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cStatistic *pp = (cStatistic *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cStatisticDescriptor::getFieldStructName(int field) const
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

void *cStatisticDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cStatistic *pp = (cStatistic *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cStdDevDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cStdDevDescriptor();
    virtual ~cStdDevDescriptor();

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

Register_ClassDescriptor(cStdDevDescriptor);

cStdDevDescriptor::cStdDevDescriptor() : omnetpp::cClassDescriptor("omnetpp::cStdDev", "omnetpp::cStatistic")
{
    propertynames = nullptr;
}

cStdDevDescriptor::~cStdDevDescriptor()
{
    delete[] propertynames;
}

bool cStdDevDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cStdDev *>(obj)!=nullptr;
}

const char **cStdDevDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cStdDevDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cStdDevDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int cStdDevDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *cStdDevDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int cStdDevDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cStdDevDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **cStdDevDescriptor::getFieldPropertyNames(int field) const
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

const char *cStdDevDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cStdDevDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cStdDev *pp = (cStdDev *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cStdDevDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cStdDev *pp = (cStdDev *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cStdDevDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cStdDev *pp = (cStdDev *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cStdDevDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *cStdDevDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cStdDev *pp = (cStdDev *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cWeightedStdDevDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cWeightedStdDevDescriptor();
    virtual ~cWeightedStdDevDescriptor();

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

Register_ClassDescriptor(cWeightedStdDevDescriptor);

cWeightedStdDevDescriptor::cWeightedStdDevDescriptor() : omnetpp::cClassDescriptor("omnetpp::cWeightedStdDev", "omnetpp::cStdDev")
{
    propertynames = nullptr;
}

cWeightedStdDevDescriptor::~cWeightedStdDevDescriptor()
{
    delete[] propertynames;
}

bool cWeightedStdDevDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cWeightedStdDev *>(obj)!=nullptr;
}

const char **cWeightedStdDevDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cWeightedStdDevDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cWeightedStdDevDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int cWeightedStdDevDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *cWeightedStdDevDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int cWeightedStdDevDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cWeightedStdDevDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **cWeightedStdDevDescriptor::getFieldPropertyNames(int field) const
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

const char *cWeightedStdDevDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cWeightedStdDevDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cWeightedStdDev *pp = (cWeightedStdDev *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cWeightedStdDevDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cWeightedStdDev *pp = (cWeightedStdDev *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cWeightedStdDevDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cWeightedStdDev *pp = (cWeightedStdDev *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cWeightedStdDevDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *cWeightedStdDevDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cWeightedStdDev *pp = (cWeightedStdDev *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cDensityEstBaseDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cDensityEstBaseDescriptor();
    virtual ~cDensityEstBaseDescriptor();

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

Register_ClassDescriptor(cDensityEstBaseDescriptor);

cDensityEstBaseDescriptor::cDensityEstBaseDescriptor() : omnetpp::cClassDescriptor("omnetpp::cDensityEstBase", "omnetpp::cStdDev")
{
    propertynames = nullptr;
}

cDensityEstBaseDescriptor::~cDensityEstBaseDescriptor()
{
    delete[] propertynames;
}

bool cDensityEstBaseDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cDensityEstBase *>(obj)!=nullptr;
}

const char **cDensityEstBaseDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cDensityEstBaseDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cDensityEstBaseDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int cDensityEstBaseDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        0,
        0,
        0,
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *cDensityEstBaseDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "isTransformed",
        "underflowCell",
        "overflowCell",
        "numCells",
        "cellInfo",
    };
    return (field>=0 && field<5) ? fieldNames[field] : nullptr;
}

int cDensityEstBaseDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "isTransformed")==0) return base+0;
    if (fieldName[0]=='u' && strcmp(fieldName, "underflowCell")==0) return base+1;
    if (fieldName[0]=='o' && strcmp(fieldName, "overflowCell")==0) return base+2;
    if (fieldName[0]=='n' && strcmp(fieldName, "numCells")==0) return base+3;
    if (fieldName[0]=='c' && strcmp(fieldName, "cellInfo")==0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cDensityEstBaseDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "unsigned long",
        "unsigned long",
        "int",
        "cDensityEstBase::Cell",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : nullptr;
}

const char **cDensityEstBaseDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "getter", "group", "hint",  nullptr };
            return names;
        }
        case 1: {
            static const char *names[] = { "group", "hint",  nullptr };
            return names;
        }
        case 2: {
            static const char *names[] = { "group", "hint",  nullptr };
            return names;
        }
        case 3: {
            static const char *names[] = { "group", "hint",  nullptr };
            return names;
        }
        case 4: {
            static const char *names[] = { "getter", "group", "hint", "sizeGetter",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cDensityEstBaseDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"getter")) return "isTransformed";
            if (!strcmp(propertyname,"group")) return "histogram";
            if (!strcmp(propertyname,"hint")) return "If false, the object is still collecting initial observations to be used for laying out histogram cells";
            return nullptr;
        case 1:
            if (!strcmp(propertyname,"group")) return "histogram";
            if (!strcmp(propertyname,"hint")) return "Number of observations below the first histogram cell";
            return nullptr;
        case 2:
            if (!strcmp(propertyname,"group")) return "histogram";
            if (!strcmp(propertyname,"hint")) return "Number of observations above the last histogram cell";
            return nullptr;
        case 3:
            if (!strcmp(propertyname,"group")) return "histogram";
            if (!strcmp(propertyname,"hint")) return "Number of cells in the histogram";
            return nullptr;
        case 4:
            if (!strcmp(propertyname,"getter")) return "internalGetCellInfo";
            if (!strcmp(propertyname,"group")) return "histogram";
            if (!strcmp(propertyname,"hint")) return "Histogram cell bounds, observation count in the cell, and density estimate in the cell";
            if (!strcmp(propertyname,"sizeGetter")) return "getNumCells";
            return nullptr;
        default: return nullptr;
    }
}

int cDensityEstBaseDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cDensityEstBase *pp = (cDensityEstBase *)object; (void)pp;
    switch (field) {
        case 4: return pp->getNumCells();
        default: return 0;
    }
}

std::string cDensityEstBaseDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cDensityEstBase *pp = (cDensityEstBase *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->isTransformed());
        case 1: return ulong2string(pp->getUnderflowCell());
        case 2: return ulong2string(pp->getOverflowCell());
        case 3: return long2string(pp->getNumCells());
        case 4: {std::stringstream out; out << pp->internalGetCellInfo(i); return out.str();}
        default: return "";
    }
}

bool cDensityEstBaseDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cDensityEstBase *pp = (cDensityEstBase *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cDensityEstBaseDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 4: return omnetpp::opp_typename(typeid(cDensityEstBase::Cell));
        default: return nullptr;
    };
}

void *cDensityEstBaseDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cDensityEstBase *pp = (cDensityEstBase *)object; (void)pp;
    switch (field) {
        case 4: return (void *)(&pp->internalGetCellInfo(i)); break;
        default: return nullptr;
    }
}

class cHistogramBaseDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cHistogramBaseDescriptor();
    virtual ~cHistogramBaseDescriptor();

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

Register_ClassDescriptor(cHistogramBaseDescriptor);

cHistogramBaseDescriptor::cHistogramBaseDescriptor() : omnetpp::cClassDescriptor("omnetpp::cHistogramBase", "omnetpp::cDensityEstBase")
{
    propertynames = nullptr;
}

cHistogramBaseDescriptor::~cHistogramBaseDescriptor()
{
    delete[] propertynames;
}

bool cHistogramBaseDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cHistogramBase *>(obj)!=nullptr;
}

const char **cHistogramBaseDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cHistogramBaseDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cHistogramBaseDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int cHistogramBaseDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *cHistogramBaseDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int cHistogramBaseDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cHistogramBaseDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **cHistogramBaseDescriptor::getFieldPropertyNames(int field) const
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

const char *cHistogramBaseDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cHistogramBaseDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cHistogramBase *pp = (cHistogramBase *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cHistogramBaseDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cHistogramBase *pp = (cHistogramBase *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cHistogramBaseDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cHistogramBase *pp = (cHistogramBase *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cHistogramBaseDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *cHistogramBaseDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cHistogramBase *pp = (cHistogramBase *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cHistogramDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cHistogramDescriptor();
    virtual ~cHistogramDescriptor();

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

Register_ClassDescriptor(cHistogramDescriptor);

cHistogramDescriptor::cHistogramDescriptor() : omnetpp::cClassDescriptor("omnetpp::cHistogram", "omnetpp::cHistogramBase")
{
    propertynames = nullptr;
}

cHistogramDescriptor::~cHistogramDescriptor()
{
    delete[] propertynames;
}

bool cHistogramDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cHistogram *>(obj)!=nullptr;
}

const char **cHistogramDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cHistogramDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cHistogramDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int cHistogramDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *cHistogramDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int cHistogramDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cHistogramDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **cHistogramDescriptor::getFieldPropertyNames(int field) const
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

const char *cHistogramDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cHistogramDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cHistogram *pp = (cHistogram *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cHistogramDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cHistogram *pp = (cHistogram *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cHistogramDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cHistogram *pp = (cHistogram *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cHistogramDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *cHistogramDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cHistogram *pp = (cHistogram *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cVarHistogramDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cVarHistogramDescriptor();
    virtual ~cVarHistogramDescriptor();

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

Register_ClassDescriptor(cVarHistogramDescriptor);

cVarHistogramDescriptor::cVarHistogramDescriptor() : omnetpp::cClassDescriptor("omnetpp::cVarHistogram", "omnetpp::cHistogramBase")
{
    propertynames = nullptr;
}

cVarHistogramDescriptor::~cVarHistogramDescriptor()
{
    delete[] propertynames;
}

bool cVarHistogramDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cVarHistogram *>(obj)!=nullptr;
}

const char **cVarHistogramDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cVarHistogramDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cVarHistogramDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int cVarHistogramDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *cVarHistogramDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int cVarHistogramDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cVarHistogramDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **cVarHistogramDescriptor::getFieldPropertyNames(int field) const
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

const char *cVarHistogramDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cVarHistogramDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cVarHistogram *pp = (cVarHistogram *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cVarHistogramDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cVarHistogram *pp = (cVarHistogram *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cVarHistogramDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cVarHistogram *pp = (cVarHistogram *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cVarHistogramDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *cVarHistogramDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cVarHistogram *pp = (cVarHistogram *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cLongHistogramDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cLongHistogramDescriptor();
    virtual ~cLongHistogramDescriptor();

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

Register_ClassDescriptor(cLongHistogramDescriptor);

cLongHistogramDescriptor::cLongHistogramDescriptor() : omnetpp::cClassDescriptor("omnetpp::cLongHistogram", "omnetpp::cHistogram")
{
    propertynames = nullptr;
}

cLongHistogramDescriptor::~cLongHistogramDescriptor()
{
    delete[] propertynames;
}

bool cLongHistogramDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cLongHistogram *>(obj)!=nullptr;
}

const char **cLongHistogramDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cLongHistogramDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cLongHistogramDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int cLongHistogramDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *cLongHistogramDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int cLongHistogramDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cLongHistogramDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **cLongHistogramDescriptor::getFieldPropertyNames(int field) const
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

const char *cLongHistogramDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cLongHistogramDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cLongHistogram *pp = (cLongHistogram *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cLongHistogramDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cLongHistogram *pp = (cLongHistogram *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cLongHistogramDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cLongHistogram *pp = (cLongHistogram *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cLongHistogramDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *cLongHistogramDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cLongHistogram *pp = (cLongHistogram *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cDoubleHistogramDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cDoubleHistogramDescriptor();
    virtual ~cDoubleHistogramDescriptor();

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

Register_ClassDescriptor(cDoubleHistogramDescriptor);

cDoubleHistogramDescriptor::cDoubleHistogramDescriptor() : omnetpp::cClassDescriptor("omnetpp::cDoubleHistogram", "omnetpp::cHistogram")
{
    propertynames = nullptr;
}

cDoubleHistogramDescriptor::~cDoubleHistogramDescriptor()
{
    delete[] propertynames;
}

bool cDoubleHistogramDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cDoubleHistogram *>(obj)!=nullptr;
}

const char **cDoubleHistogramDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cDoubleHistogramDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cDoubleHistogramDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int cDoubleHistogramDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *cDoubleHistogramDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int cDoubleHistogramDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cDoubleHistogramDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **cDoubleHistogramDescriptor::getFieldPropertyNames(int field) const
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

const char *cDoubleHistogramDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cDoubleHistogramDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cDoubleHistogram *pp = (cDoubleHistogram *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cDoubleHistogramDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cDoubleHistogram *pp = (cDoubleHistogram *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cDoubleHistogramDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cDoubleHistogram *pp = (cDoubleHistogram *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cDoubleHistogramDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *cDoubleHistogramDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cDoubleHistogram *pp = (cDoubleHistogram *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cKSplitDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cKSplitDescriptor();
    virtual ~cKSplitDescriptor();

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

Register_ClassDescriptor(cKSplitDescriptor);

cKSplitDescriptor::cKSplitDescriptor() : omnetpp::cClassDescriptor("omnetpp::cKSplit", "omnetpp::cDensityEstBase")
{
    propertynames = nullptr;
}

cKSplitDescriptor::~cKSplitDescriptor()
{
    delete[] propertynames;
}

bool cKSplitDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cKSplit *>(obj)!=nullptr;
}

const char **cKSplitDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cKSplitDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cKSplitDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int cKSplitDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *cKSplitDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int cKSplitDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cKSplitDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **cKSplitDescriptor::getFieldPropertyNames(int field) const
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

const char *cKSplitDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cKSplitDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cKSplit *pp = (cKSplit *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cKSplitDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cKSplit *pp = (cKSplit *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cKSplitDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cKSplit *pp = (cKSplit *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cKSplitDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *cKSplitDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cKSplit *pp = (cKSplit *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cPSquareDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cPSquareDescriptor();
    virtual ~cPSquareDescriptor();

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

Register_ClassDescriptor(cPSquareDescriptor);

cPSquareDescriptor::cPSquareDescriptor() : omnetpp::cClassDescriptor("omnetpp::cPSquare", "omnetpp::cDensityEstBase")
{
    propertynames = nullptr;
}

cPSquareDescriptor::~cPSquareDescriptor()
{
    delete[] propertynames;
}

bool cPSquareDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cPSquare *>(obj)!=nullptr;
}

const char **cPSquareDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cPSquareDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cPSquareDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int cPSquareDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *cPSquareDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int cPSquareDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cPSquareDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **cPSquareDescriptor::getFieldPropertyNames(int field) const
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

const char *cPSquareDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cPSquareDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cPSquare *pp = (cPSquare *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cPSquareDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cPSquare *pp = (cPSquare *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cPSquareDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cPSquare *pp = (cPSquare *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cPSquareDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *cPSquareDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cPSquare *pp = (cPSquare *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cTransientDetectionDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cTransientDetectionDescriptor();
    virtual ~cTransientDetectionDescriptor();

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

Register_ClassDescriptor(cTransientDetectionDescriptor);

cTransientDetectionDescriptor::cTransientDetectionDescriptor() : omnetpp::cClassDescriptor("omnetpp::cTransientDetection", "omnetpp::cOwnedObject")
{
    propertynames = nullptr;
}

cTransientDetectionDescriptor::~cTransientDetectionDescriptor()
{
    delete[] propertynames;
}

bool cTransientDetectionDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cTransientDetection *>(obj)!=nullptr;
}

const char **cTransientDetectionDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cTransientDetectionDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cTransientDetectionDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int cTransientDetectionDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *cTransientDetectionDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int cTransientDetectionDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cTransientDetectionDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **cTransientDetectionDescriptor::getFieldPropertyNames(int field) const
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

const char *cTransientDetectionDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cTransientDetectionDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cTransientDetection *pp = (cTransientDetection *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cTransientDetectionDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cTransientDetection *pp = (cTransientDetection *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cTransientDetectionDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cTransientDetection *pp = (cTransientDetection *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cTransientDetectionDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *cTransientDetectionDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cTransientDetection *pp = (cTransientDetection *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cAccuracyDetectionDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cAccuracyDetectionDescriptor();
    virtual ~cAccuracyDetectionDescriptor();

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

Register_ClassDescriptor(cAccuracyDetectionDescriptor);

cAccuracyDetectionDescriptor::cAccuracyDetectionDescriptor() : omnetpp::cClassDescriptor("omnetpp::cAccuracyDetection", "omnetpp::cOwnedObject")
{
    propertynames = nullptr;
}

cAccuracyDetectionDescriptor::~cAccuracyDetectionDescriptor()
{
    delete[] propertynames;
}

bool cAccuracyDetectionDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cAccuracyDetection *>(obj)!=nullptr;
}

const char **cAccuracyDetectionDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cAccuracyDetectionDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cAccuracyDetectionDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int cAccuracyDetectionDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *cAccuracyDetectionDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int cAccuracyDetectionDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cAccuracyDetectionDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **cAccuracyDetectionDescriptor::getFieldPropertyNames(int field) const
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

const char *cAccuracyDetectionDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cAccuracyDetectionDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cAccuracyDetection *pp = (cAccuracyDetection *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cAccuracyDetectionDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cAccuracyDetection *pp = (cAccuracyDetection *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cAccuracyDetectionDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cAccuracyDetection *pp = (cAccuracyDetection *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cAccuracyDetectionDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *cAccuracyDetectionDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cAccuracyDetection *pp = (cAccuracyDetection *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cTDExpandingWindowsDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cTDExpandingWindowsDescriptor();
    virtual ~cTDExpandingWindowsDescriptor();

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

Register_ClassDescriptor(cTDExpandingWindowsDescriptor);

cTDExpandingWindowsDescriptor::cTDExpandingWindowsDescriptor() : omnetpp::cClassDescriptor("omnetpp::cTDExpandingWindows", "omnetpp::cTransientDetection")
{
    propertynames = nullptr;
}

cTDExpandingWindowsDescriptor::~cTDExpandingWindowsDescriptor()
{
    delete[] propertynames;
}

bool cTDExpandingWindowsDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cTDExpandingWindows *>(obj)!=nullptr;
}

const char **cTDExpandingWindowsDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cTDExpandingWindowsDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cTDExpandingWindowsDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int cTDExpandingWindowsDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *cTDExpandingWindowsDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int cTDExpandingWindowsDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cTDExpandingWindowsDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **cTDExpandingWindowsDescriptor::getFieldPropertyNames(int field) const
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

const char *cTDExpandingWindowsDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cTDExpandingWindowsDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cTDExpandingWindows *pp = (cTDExpandingWindows *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cTDExpandingWindowsDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cTDExpandingWindows *pp = (cTDExpandingWindows *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cTDExpandingWindowsDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cTDExpandingWindows *pp = (cTDExpandingWindows *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cTDExpandingWindowsDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *cTDExpandingWindowsDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cTDExpandingWindows *pp = (cTDExpandingWindows *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cADByStddevDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cADByStddevDescriptor();
    virtual ~cADByStddevDescriptor();

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

Register_ClassDescriptor(cADByStddevDescriptor);

cADByStddevDescriptor::cADByStddevDescriptor() : omnetpp::cClassDescriptor("omnetpp::cADByStddev", "omnetpp::cAccuracyDetection")
{
    propertynames = nullptr;
}

cADByStddevDescriptor::~cADByStddevDescriptor()
{
    delete[] propertynames;
}

bool cADByStddevDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cADByStddev *>(obj)!=nullptr;
}

const char **cADByStddevDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cADByStddevDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cADByStddevDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int cADByStddevDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *cADByStddevDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int cADByStddevDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cADByStddevDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **cADByStddevDescriptor::getFieldPropertyNames(int field) const
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

const char *cADByStddevDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cADByStddevDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cADByStddev *pp = (cADByStddev *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cADByStddevDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cADByStddev *pp = (cADByStddev *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cADByStddevDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cADByStddev *pp = (cADByStddev *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cADByStddevDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *cADByStddevDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cADByStddev *pp = (cADByStddev *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cExpressionDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cExpressionDescriptor();
    virtual ~cExpressionDescriptor();

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

Register_ClassDescriptor(cExpressionDescriptor);

cExpressionDescriptor::cExpressionDescriptor() : omnetpp::cClassDescriptor("omnetpp::cExpression", "omnetpp::cObject")
{
    propertynames = nullptr;
}

cExpressionDescriptor::~cExpressionDescriptor()
{
    delete[] propertynames;
}

bool cExpressionDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cExpression *>(obj)!=nullptr;
}

const char **cExpressionDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cExpressionDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cExpressionDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int cExpressionDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *cExpressionDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "str",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int cExpressionDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "str")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cExpressionDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **cExpressionDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "getter",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cExpressionDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"getter")) return "str";
            return nullptr;
        default: return nullptr;
    }
}

int cExpressionDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cExpression *pp = (cExpression *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cExpressionDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cExpression *pp = (cExpression *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->str());
        default: return "";
    }
}

bool cExpressionDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cExpression *pp = (cExpression *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cExpressionDescriptor::getFieldStructName(int field) const
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

void *cExpressionDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cExpression *pp = (cExpression *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cFSMDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cFSMDescriptor();
    virtual ~cFSMDescriptor();

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

Register_ClassDescriptor(cFSMDescriptor);

cFSMDescriptor::cFSMDescriptor() : omnetpp::cClassDescriptor("omnetpp::cFSM", "omnetpp::cOwnedObject")
{
    propertynames = nullptr;
}

cFSMDescriptor::~cFSMDescriptor()
{
    delete[] propertynames;
}

bool cFSMDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cFSM *>(obj)!=nullptr;
}

const char **cFSMDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cFSMDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cFSMDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int cFSMDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        0,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *cFSMDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "state",
        "stateName",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int cFSMDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "state")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "stateName")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cFSMDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "string",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **cFSMDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "hint",  nullptr };
            return names;
        }
        case 1: {
            static const char *names[] = { "hint",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cFSMDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"hint")) return "Numeric code of the state the FSM is currently in";
            return nullptr;
        case 1:
            if (!strcmp(propertyname,"hint")) return "Name of the current FSM state";
            return nullptr;
        default: return nullptr;
    }
}

int cFSMDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cFSM *pp = (cFSM *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cFSMDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cFSM *pp = (cFSM *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getState());
        case 1: return oppstring2string(pp->getStateName());
        default: return "";
    }
}

bool cFSMDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cFSM *pp = (cFSM *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cFSMDescriptor::getFieldStructName(int field) const
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

void *cFSMDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cFSM *pp = (cFSM *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cNEDMathFunctionDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cNEDMathFunctionDescriptor();
    virtual ~cNEDMathFunctionDescriptor();

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

Register_ClassDescriptor(cNEDMathFunctionDescriptor);

cNEDMathFunctionDescriptor::cNEDMathFunctionDescriptor() : omnetpp::cClassDescriptor("omnetpp::cNEDMathFunction", "omnetpp::cNoncopyableOwnedObject")
{
    propertynames = nullptr;
}

cNEDMathFunctionDescriptor::~cNEDMathFunctionDescriptor()
{
    delete[] propertynames;
}

bool cNEDMathFunctionDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cNEDMathFunction *>(obj)!=nullptr;
}

const char **cNEDMathFunctionDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cNEDMathFunctionDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cNEDMathFunctionDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int cNEDMathFunctionDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        0,
        0,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *cNEDMathFunctionDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "category",
        "description",
        "numArgs",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int cNEDMathFunctionDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "category")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "description")==0) return base+1;
    if (fieldName[0]=='n' && strcmp(fieldName, "numArgs")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cNEDMathFunctionDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "string",
        "int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **cNEDMathFunctionDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "hint",  nullptr };
            return names;
        }
        case 2: {
            static const char *names[] = { "hint",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cNEDMathFunctionDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"hint")) return "Function category";
            return nullptr;
        case 2:
            if (!strcmp(propertyname,"hint")) return "Number of \"double\" parameters this function takes";
            return nullptr;
        default: return nullptr;
    }
}

int cNEDMathFunctionDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cNEDMathFunction *pp = (cNEDMathFunction *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cNEDMathFunctionDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cNEDMathFunction *pp = (cNEDMathFunction *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getCategory());
        case 1: return oppstring2string(pp->getDescription());
        case 2: return long2string(pp->getNumArgs());
        default: return "";
    }
}

bool cNEDMathFunctionDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cNEDMathFunction *pp = (cNEDMathFunction *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cNEDMathFunctionDescriptor::getFieldStructName(int field) const
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

void *cNEDMathFunctionDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cNEDMathFunction *pp = (cNEDMathFunction *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cNEDFunctionDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cNEDFunctionDescriptor();
    virtual ~cNEDFunctionDescriptor();

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

Register_ClassDescriptor(cNEDFunctionDescriptor);

cNEDFunctionDescriptor::cNEDFunctionDescriptor() : omnetpp::cClassDescriptor("omnetpp::cNEDFunction", "omnetpp::cNoncopyableOwnedObject")
{
    propertynames = nullptr;
}

cNEDFunctionDescriptor::~cNEDFunctionDescriptor()
{
    delete[] propertynames;
}

bool cNEDFunctionDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cNEDFunction *>(obj)!=nullptr;
}

const char **cNEDFunctionDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cNEDFunctionDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cNEDFunctionDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount() : 7;
}

unsigned int cNEDFunctionDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        0,
        0,
        0,
        FD_ISARRAY,
        0,
        0,
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *cNEDFunctionDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "signature",
        "category",
        "description",
        "returnType",
        "argType",
        "minArgs",
        "maxArgs",
    };
    return (field>=0 && field<7) ? fieldNames[field] : nullptr;
}

int cNEDFunctionDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "signature")==0) return base+0;
    if (fieldName[0]=='c' && strcmp(fieldName, "category")==0) return base+1;
    if (fieldName[0]=='d' && strcmp(fieldName, "description")==0) return base+2;
    if (fieldName[0]=='r' && strcmp(fieldName, "returnType")==0) return base+3;
    if (fieldName[0]=='a' && strcmp(fieldName, "argType")==0) return base+4;
    if (fieldName[0]=='m' && strcmp(fieldName, "minArgs")==0) return base+5;
    if (fieldName[0]=='m' && strcmp(fieldName, "maxArgs")==0) return base+6;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cNEDFunctionDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "string",
        "string",
        "char",
        "char",
        "int",
        "int",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : nullptr;
}

const char **cNEDFunctionDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "hint",  nullptr };
            return names;
        }
        case 1: {
            static const char *names[] = { "hint",  nullptr };
            return names;
        }
        case 4: {
            static const char *names[] = { "sizeGetter",  nullptr };
            return names;
        }
        case 5: {
            static const char *names[] = { "hint",  nullptr };
            return names;
        }
        case 6: {
            static const char *names[] = { "hint",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cNEDFunctionDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"hint")) return "Argument types and return value";
            return nullptr;
        case 1:
            if (!strcmp(propertyname,"hint")) return "Function category";
            return nullptr;
        case 4:
            if (!strcmp(propertyname,"sizeGetter")) return "getMaxArgs";
            return nullptr;
        case 5:
            if (!strcmp(propertyname,"hint")) return "Number of mandatory arguments";
            return nullptr;
        case 6:
            if (!strcmp(propertyname,"hint")) return "Maximum number of arguments";
            return nullptr;
        default: return nullptr;
    }
}

int cNEDFunctionDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cNEDFunction *pp = (cNEDFunction *)object; (void)pp;
    switch (field) {
        case 4: return pp->getMaxArgs();
        default: return 0;
    }
}

std::string cNEDFunctionDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cNEDFunction *pp = (cNEDFunction *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getSignature());
        case 1: return oppstring2string(pp->getCategory());
        case 2: return oppstring2string(pp->getDescription());
        case 3: return long2string(pp->getReturnType());
        case 4: return long2string(pp->getArgType(i));
        case 5: return long2string(pp->getMinArgs());
        case 6: return long2string(pp->getMaxArgs());
        default: return "";
    }
}

bool cNEDFunctionDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cNEDFunction *pp = (cNEDFunction *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cNEDFunctionDescriptor::getFieldStructName(int field) const
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

void *cNEDFunctionDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cNEDFunction *pp = (cNEDFunction *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cOutVectorDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cOutVectorDescriptor();
    virtual ~cOutVectorDescriptor();

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

Register_ClassDescriptor(cOutVectorDescriptor);

cOutVectorDescriptor::cOutVectorDescriptor() : omnetpp::cClassDescriptor("omnetpp::cOutVector", "omnetpp::cNoncopyableOwnedObject")
{
    propertynames = nullptr;
}

cOutVectorDescriptor::~cOutVectorDescriptor()
{
    delete[] propertynames;
}

bool cOutVectorDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cOutVector *>(obj)!=nullptr;
}

const char **cOutVectorDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "icon",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cOutVectorDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"icon")) return "outvector";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cOutVectorDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int cOutVectorDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        0,
        0,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *cOutVectorDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "isEnabled",
        "valuesReceived",
        "valuesStored",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int cOutVectorDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "isEnabled")==0) return base+0;
    if (fieldName[0]=='v' && strcmp(fieldName, "valuesReceived")==0) return base+1;
    if (fieldName[0]=='v' && strcmp(fieldName, "valuesStored")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cOutVectorDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "long",
        "long",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **cOutVectorDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "editable", "getter", "hint", "setter",  nullptr };
            return names;
        }
        case 1: {
            static const char *names[] = { "hint",  nullptr };
            return names;
        }
        case 2: {
            static const char *names[] = { "hint",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cOutVectorDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"getter")) return "isEnabled";
            if (!strcmp(propertyname,"hint")) return "If disabled, values passed to this object to record are simply discarded";
            if (!strcmp(propertyname,"setter")) return "setEnabled";
            return nullptr;
        case 1:
            if (!strcmp(propertyname,"hint")) return "Number of values passed to this object to record";
            return nullptr;
        case 2:
            if (!strcmp(propertyname,"hint")) return "Number of values actually stored on the disk";
            return nullptr;
        default: return nullptr;
    }
}

int cOutVectorDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cOutVector *pp = (cOutVector *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cOutVectorDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cOutVector *pp = (cOutVector *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->isEnabled());
        case 1: return long2string(pp->getValuesReceived());
        case 2: return long2string(pp->getValuesStored());
        default: return "";
    }
}

bool cOutVectorDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cOutVector *pp = (cOutVector *)object; (void)pp;
    switch (field) {
        case 0: pp->setEnabled(string2bool(value)); return true;
        default: return false;
    }
}

const char *cOutVectorDescriptor::getFieldStructName(int field) const
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

void *cOutVectorDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cOutVector *pp = (cOutVector *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cParDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cParDescriptor();
    virtual ~cParDescriptor();

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

Register_ClassDescriptor(cParDescriptor);

cParDescriptor::cParDescriptor() : omnetpp::cClassDescriptor("omnetpp::cPar", "omnetpp::cObject")
{
    propertynames = nullptr;
}

cParDescriptor::~cParDescriptor()
{
    delete[] propertynames;
}

bool cParDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cPar *>(obj)!=nullptr;
}

const char **cParDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "icon",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cParDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"icon")) return "param";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cParDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount() : 7;
}

unsigned int cParDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        0,
        0,
        0,
        0,
        0,
        0,
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *cParDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "value",
        "type",
        "unit",
        "isNumeric",
        "isVolatile",
        "isExpression",
        "isShared",
    };
    return (field>=0 && field<7) ? fieldNames[field] : nullptr;
}

int cParDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='v' && strcmp(fieldName, "value")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+1;
    if (fieldName[0]=='u' && strcmp(fieldName, "unit")==0) return base+2;
    if (fieldName[0]=='i' && strcmp(fieldName, "isNumeric")==0) return base+3;
    if (fieldName[0]=='i' && strcmp(fieldName, "isVolatile")==0) return base+4;
    if (fieldName[0]=='i' && strcmp(fieldName, "isExpression")==0) return base+5;
    if (fieldName[0]=='i' && strcmp(fieldName, "isShared")==0) return base+6;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cParDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "char",
        "string",
        "bool",
        "bool",
        "bool",
        "bool",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : nullptr;
}

const char **cParDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "editable", "getter", "setter",  nullptr };
            return names;
        }
        case 1: {
            static const char *names[] = { "enum", "hint",  nullptr };
            return names;
        }
        case 2: {
            static const char *names[] = { "hint",  nullptr };
            return names;
        }
        case 3: {
            static const char *names[] = { "getter", "group", "hint",  nullptr };
            return names;
        }
        case 4: {
            static const char *names[] = { "getter", "group", "hint",  nullptr };
            return names;
        }
        case 5: {
            static const char *names[] = { "getter", "group", "hint",  nullptr };
            return names;
        }
        case 6: {
            static const char *names[] = { "getter", "group", "hint",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cParDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"getter")) return "str";
            if (!strcmp(propertyname,"setter")) return "parse";
            return nullptr;
        case 1:
            if (!strcmp(propertyname,"enum")) return "omnetpp::cPar::Type";
            if (!strcmp(propertyname,"hint")) return "Parameter type";
            return nullptr;
        case 2:
            if (!strcmp(propertyname,"hint")) return "For long and double types only";
            return nullptr;
        case 3:
            if (!strcmp(propertyname,"getter")) return "isNumeric";
            if (!strcmp(propertyname,"group")) return "flags";
            if (!strcmp(propertyname,"hint")) return "Whether parameter type is numeric, i.e. double or long";
            return nullptr;
        case 4:
            if (!strcmp(propertyname,"getter")) return "isVolatile";
            if (!strcmp(propertyname,"group")) return "flags";
            if (!strcmp(propertyname,"hint")) return "Whether parameter was declared volatile in the NED file";
            return nullptr;
        case 5:
            if (!strcmp(propertyname,"getter")) return "isExpression";
            if (!strcmp(propertyname,"group")) return "flags";
            if (!strcmp(propertyname,"hint")) return "Whether parameter value is a constant or an expression";
            return nullptr;
        case 6:
            if (!strcmp(propertyname,"getter")) return "isShared";
            if (!strcmp(propertyname,"group")) return "flags";
            if (!strcmp(propertyname,"hint")) return "Whether storage could be optimized by several modules sharing the same parameter value object";
            return nullptr;
        default: return nullptr;
    }
}

int cParDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cPar *pp = (cPar *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cParDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cPar *pp = (cPar *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->str());
        case 1: return enum2string(pp->getType(), "omnetpp::cPar::Type");
        case 2: return oppstring2string(pp->getUnit());
        case 3: return bool2string(pp->isNumeric());
        case 4: return bool2string(pp->isVolatile());
        case 5: return bool2string(pp->isExpression());
        case 6: return bool2string(pp->isShared());
        default: return "";
    }
}

bool cParDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cPar *pp = (cPar *)object; (void)pp;
    switch (field) {
        case 0: pp->parse((value)); return true;
        default: return false;
    }
}

const char *cParDescriptor::getFieldStructName(int field) const
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

void *cParDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cPar *pp = (cPar *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cMsgParDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cMsgParDescriptor();
    virtual ~cMsgParDescriptor();

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

Register_ClassDescriptor(cMsgParDescriptor);

cMsgParDescriptor::cMsgParDescriptor() : omnetpp::cClassDescriptor("omnetpp::cMsgPar", "omnetpp::cOwnedObject")
{
    propertynames = nullptr;
}

cMsgParDescriptor::~cMsgParDescriptor()
{
    delete[] propertynames;
}

bool cMsgParDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cMsgPar *>(obj)!=nullptr;
}

const char **cMsgParDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cMsgParDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cMsgParDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int cMsgParDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        0,
        0,
        0,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *cMsgParDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "value",
        "type",
        "isNumeric",
        "isConstant",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int cMsgParDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='v' && strcmp(fieldName, "value")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+1;
    if (fieldName[0]=='i' && strcmp(fieldName, "isNumeric")==0) return base+2;
    if (fieldName[0]=='i' && strcmp(fieldName, "isConstant")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cMsgParDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "char",
        "bool",
        "bool",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **cMsgParDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "editable", "getter", "hint", "setter",  nullptr };
            return names;
        }
        case 1: {
            static const char *names[] = { "enum", "hint",  nullptr };
            return names;
        }
        case 2: {
            static const char *names[] = { "getter", "group", "hint",  nullptr };
            return names;
        }
        case 3: {
            static const char *names[] = { "getter", "group", "hint",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cMsgParDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"getter")) return "str";
            if (!strcmp(propertyname,"hint")) return "Parameter value";
            if (!strcmp(propertyname,"setter")) return "parse";
            return nullptr;
        case 1:
            if (!strcmp(propertyname,"enum")) return "omnetpp::cPar::Type";
            if (!strcmp(propertyname,"hint")) return "Parameter type";
            return nullptr;
        case 2:
            if (!strcmp(propertyname,"getter")) return "isNumeric";
            if (!strcmp(propertyname,"group")) return "flags";
            if (!strcmp(propertyname,"hint")) return "Whether parameter is of numeric type";
            return nullptr;
        case 3:
            if (!strcmp(propertyname,"getter")) return "isConstant";
            if (!strcmp(propertyname,"group")) return "flags";
            if (!strcmp(propertyname,"hint")) return "Whether the parameter has a constant value";
            return nullptr;
        default: return nullptr;
    }
}

int cMsgParDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cMsgPar *pp = (cMsgPar *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cMsgParDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cMsgPar *pp = (cMsgPar *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->str());
        case 1: return enum2string(pp->getType(), "omnetpp::cPar::Type");
        case 2: return bool2string(pp->isNumeric());
        case 3: return bool2string(pp->isConstant());
        default: return "";
    }
}

bool cMsgParDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cMsgPar *pp = (cMsgPar *)object; (void)pp;
    switch (field) {
        case 0: pp->parse((value)); return true;
        default: return false;
    }
}

const char *cMsgParDescriptor::getFieldStructName(int field) const
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

void *cMsgParDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cMsgPar *pp = (cMsgPar *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cFutureEventSetDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cFutureEventSetDescriptor();
    virtual ~cFutureEventSetDescriptor();

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

Register_ClassDescriptor(cFutureEventSetDescriptor);

cFutureEventSetDescriptor::cFutureEventSetDescriptor() : omnetpp::cClassDescriptor("omnetpp::cFutureEventSet", "omnetpp::cOwnedObject")
{
    propertynames = nullptr;
}

cFutureEventSetDescriptor::~cFutureEventSetDescriptor()
{
    delete[] propertynames;
}

bool cFutureEventSetDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cFutureEventSet *>(obj)!=nullptr;
}

const char **cFutureEventSetDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "icon",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cFutureEventSetDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"icon")) return "container";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cFutureEventSetDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int cFutureEventSetDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *cFutureEventSetDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "length",
        "events",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int cFutureEventSetDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='l' && strcmp(fieldName, "length")==0) return base+0;
    if (fieldName[0]=='e' && strcmp(fieldName, "events")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cFutureEventSetDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "cEvent",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **cFutureEventSetDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "hint",  nullptr };
            return names;
        }
        case 1: {
            static const char *names[] = { "getter", "hint", "sizeGetter",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cFutureEventSetDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"hint")) return "Number of items contained";
            return nullptr;
        case 1:
            if (!strcmp(propertyname,"getter")) return "get";
            if (!strcmp(propertyname,"hint")) return "Events and self-messages and currently scheduled, and messages currently in transit";
            if (!strcmp(propertyname,"sizeGetter")) return "getLength";
            return nullptr;
        default: return nullptr;
    }
}

int cFutureEventSetDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cFutureEventSet *pp = (cFutureEventSet *)object; (void)pp;
    switch (field) {
        case 1: return pp->getLength();
        default: return 0;
    }
}

std::string cFutureEventSetDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cFutureEventSet *pp = (cFutureEventSet *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getLength());
        case 1: {std::stringstream out; out << pp->get(i); return out.str();}
        default: return "";
    }
}

bool cFutureEventSetDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cFutureEventSet *pp = (cFutureEventSet *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cFutureEventSetDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(cEvent));
        default: return nullptr;
    };
}

void *cFutureEventSetDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cFutureEventSet *pp = (cFutureEventSet *)object; (void)pp;
    switch (field) {
        case 1: return (void *)static_cast<omnetpp::cObject *>(pp->get(i)); break;
        default: return nullptr;
    }
}

class cEventHeapDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cEventHeapDescriptor();
    virtual ~cEventHeapDescriptor();

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

Register_ClassDescriptor(cEventHeapDescriptor);

cEventHeapDescriptor::cEventHeapDescriptor() : omnetpp::cClassDescriptor("omnetpp::cEventHeap", "omnetpp::cFutureEventSet")
{
    propertynames = nullptr;
}

cEventHeapDescriptor::~cEventHeapDescriptor()
{
    delete[] propertynames;
}

bool cEventHeapDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cEventHeap *>(obj)!=nullptr;
}

const char **cEventHeapDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cEventHeapDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cEventHeapDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int cEventHeapDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *cEventHeapDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int cEventHeapDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cEventHeapDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **cEventHeapDescriptor::getFieldPropertyNames(int field) const
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

const char *cEventHeapDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cEventHeapDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cEventHeap *pp = (cEventHeap *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cEventHeapDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cEventHeap *pp = (cEventHeap *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cEventHeapDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cEventHeap *pp = (cEventHeap *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cEventHeapDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *cEventHeapDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cEventHeap *pp = (cEventHeap *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cQueueDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cQueueDescriptor();
    virtual ~cQueueDescriptor();

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

Register_ClassDescriptor(cQueueDescriptor);

cQueueDescriptor::cQueueDescriptor() : omnetpp::cClassDescriptor("omnetpp::cQueue", "omnetpp::cOwnedObject")
{
    propertynames = nullptr;
}

cQueueDescriptor::~cQueueDescriptor()
{
    delete[] propertynames;
}

bool cQueueDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cQueue *>(obj)!=nullptr;
}

const char **cQueueDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "icon",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cQueueDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"icon")) return "queue";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cQueueDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int cQueueDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        0,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *cQueueDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "takeOwnership",
        "length",
        "contents",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int cQueueDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "takeOwnership")==0) return base+0;
    if (fieldName[0]=='l' && strcmp(fieldName, "length")==0) return base+1;
    if (fieldName[0]=='c' && strcmp(fieldName, "contents")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cQueueDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "int",
        "cOwnedObject",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **cQueueDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "editable", "group", "hint",  nullptr };
            return names;
        }
        case 1: {
            static const char *names[] = { "hint",  nullptr };
            return names;
        }
        case 2: {
            static const char *names[] = { "getter", "hint", "sizeGetter",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cQueueDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"group")) return "fields";
            if (!strcmp(propertyname,"hint")) return "Whether the queue should own the objects inserted into it";
            return nullptr;
        case 1:
            if (!strcmp(propertyname,"hint")) return "Number of items in the queue";
            return nullptr;
        case 2:
            if (!strcmp(propertyname,"getter")) return "get";
            if (!strcmp(propertyname,"hint")) return "Queue contents";
            if (!strcmp(propertyname,"sizeGetter")) return "getLength";
            return nullptr;
        default: return nullptr;
    }
}

int cQueueDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cQueue *pp = (cQueue *)object; (void)pp;
    switch (field) {
        case 2: return pp->getLength();
        default: return 0;
    }
}

std::string cQueueDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cQueue *pp = (cQueue *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getTakeOwnership());
        case 1: return long2string(pp->getLength());
        case 2: {std::stringstream out; out << pp->get(i); return out.str();}
        default: return "";
    }
}

bool cQueueDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cQueue *pp = (cQueue *)object; (void)pp;
    switch (field) {
        case 0: pp->setTakeOwnership(string2bool(value)); return true;
        default: return false;
    }
}

const char *cQueueDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 2: return omnetpp::opp_typename(typeid(cOwnedObject));
        default: return nullptr;
    };
}

void *cQueueDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cQueue *pp = (cQueue *)object; (void)pp;
    switch (field) {
        case 2: return (void *)static_cast<omnetpp::cObject *>(pp->get(i)); break;
        default: return nullptr;
    }
}

class cPacketQueueDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cPacketQueueDescriptor();
    virtual ~cPacketQueueDescriptor();

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

Register_ClassDescriptor(cPacketQueueDescriptor);

cPacketQueueDescriptor::cPacketQueueDescriptor() : omnetpp::cClassDescriptor("omnetpp::cPacketQueue", "omnetpp::cQueue")
{
    propertynames = nullptr;
}

cPacketQueueDescriptor::~cPacketQueueDescriptor()
{
    delete[] propertynames;
}

bool cPacketQueueDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cPacketQueue *>(obj)!=nullptr;
}

const char **cPacketQueueDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cPacketQueueDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cPacketQueueDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int cPacketQueueDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        0,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *cPacketQueueDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "bitLength",
        "byteLength",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int cPacketQueueDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='b' && strcmp(fieldName, "bitLength")==0) return base+0;
    if (fieldName[0]=='b' && strcmp(fieldName, "byteLength")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cPacketQueueDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int64_t",
        "int64_t",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **cPacketQueueDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "hint",  nullptr };
            return names;
        }
        case 1: {
            static const char *names[] = { "hint",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cPacketQueueDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"hint")) return "Total size of messages in the queue";
            return nullptr;
        case 1:
            if (!strcmp(propertyname,"hint")) return "Total size of messages in the queue, in bytes";
            return nullptr;
        default: return nullptr;
    }
}

int cPacketQueueDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cPacketQueue *pp = (cPacketQueue *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cPacketQueueDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cPacketQueue *pp = (cPacketQueue *)object; (void)pp;
    switch (field) {
        case 0: return int642string(pp->getBitLength());
        case 1: return int642string(pp->getByteLength());
        default: return "";
    }
}

bool cPacketQueueDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cPacketQueue *pp = (cPacketQueue *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cPacketQueueDescriptor::getFieldStructName(int field) const
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

void *cPacketQueueDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cPacketQueue *pp = (cPacketQueue *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cHasherDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cHasherDescriptor();
    virtual ~cHasherDescriptor();

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

Register_ClassDescriptor(cHasherDescriptor);

cHasherDescriptor::cHasherDescriptor() : omnetpp::cClassDescriptor("omnetpp::cHasher", "")
{
    propertynames = nullptr;
}

cHasherDescriptor::~cHasherDescriptor()
{
    delete[] propertynames;
}

bool cHasherDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cHasher *>(obj)!=nullptr;
}

const char **cHasherDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cHasherDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cHasherDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int cHasherDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *cHasherDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "hash",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int cHasherDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='h' && strcmp(fieldName, "hash")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cHasherDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **cHasherDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "getter", "hint",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cHasherDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"getter")) return "str";
            if (!strcmp(propertyname,"hint")) return "The current hash value";
            return nullptr;
        default: return nullptr;
    }
}

int cHasherDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cHasher *pp = (cHasher *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cHasherDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cHasher *pp = (cHasher *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->str());
        default: return "";
    }
}

bool cHasherDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cHasher *pp = (cHasher *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cHasherDescriptor::getFieldStructName(int field) const
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

void *cHasherDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cHasher *pp = (cHasher *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cFingerprintCalculatorDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cFingerprintCalculatorDescriptor();
    virtual ~cFingerprintCalculatorDescriptor();

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

Register_ClassDescriptor(cFingerprintCalculatorDescriptor);

cFingerprintCalculatorDescriptor::cFingerprintCalculatorDescriptor() : omnetpp::cClassDescriptor("omnetpp::cFingerprintCalculator", "omnetpp::cObject")
{
    propertynames = nullptr;
}

cFingerprintCalculatorDescriptor::~cFingerprintCalculatorDescriptor()
{
    delete[] propertynames;
}

bool cFingerprintCalculatorDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cFingerprintCalculator *>(obj)!=nullptr;
}

const char **cFingerprintCalculatorDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cFingerprintCalculatorDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cFingerprintCalculatorDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int cFingerprintCalculatorDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *cFingerprintCalculatorDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int cFingerprintCalculatorDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cFingerprintCalculatorDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **cFingerprintCalculatorDescriptor::getFieldPropertyNames(int field) const
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

const char *cFingerprintCalculatorDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cFingerprintCalculatorDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cFingerprintCalculator *pp = (cFingerprintCalculator *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cFingerprintCalculatorDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cFingerprintCalculator *pp = (cFingerprintCalculator *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cFingerprintCalculatorDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cFingerprintCalculator *pp = (cFingerprintCalculator *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cFingerprintCalculatorDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *cFingerprintCalculatorDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cFingerprintCalculator *pp = (cFingerprintCalculator *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cSimulationDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cSimulationDescriptor();
    virtual ~cSimulationDescriptor();

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

Register_ClassDescriptor(cSimulationDescriptor);

cSimulationDescriptor::cSimulationDescriptor() : omnetpp::cClassDescriptor("omnetpp::cSimulation", "omnetpp::cNoncopyableOwnedObject")
{
    propertynames = nullptr;
}

cSimulationDescriptor::~cSimulationDescriptor()
{
    delete[] propertynames;
}

bool cSimulationDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cSimulation *>(obj)!=nullptr;
}

const char **cSimulationDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "icon",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cSimulationDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"icon")) return "container";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cSimulationDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount() : 7;
}

unsigned int cSimulationDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        0,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,
        0,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *cSimulationDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "simTime",
        "eventNumber",
        "fes",
        "lastComponentId",
        "systemModule",
        "component",
        "fingerprintCalculator",
    };
    return (field>=0 && field<7) ? fieldNames[field] : nullptr;
}

int cSimulationDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "simTime")==0) return base+0;
    if (fieldName[0]=='e' && strcmp(fieldName, "eventNumber")==0) return base+1;
    if (fieldName[0]=='f' && strcmp(fieldName, "fes")==0) return base+2;
    if (fieldName[0]=='l' && strcmp(fieldName, "lastComponentId")==0) return base+3;
    if (fieldName[0]=='s' && strcmp(fieldName, "systemModule")==0) return base+4;
    if (fieldName[0]=='c' && strcmp(fieldName, "component")==0) return base+5;
    if (fieldName[0]=='f' && strcmp(fieldName, "fingerprintCalculator")==0) return base+6;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cSimulationDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "simtime_t",
        "int64_t",
        "cFutureEventSet",
        "int",
        "cModule",
        "cComponent",
        "cFingerprintCalculator",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : nullptr;
}

const char **cSimulationDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "hint",  nullptr };
            return names;
        }
        case 1: {
            static const char *names[] = { "hint",  nullptr };
            return names;
        }
        case 2: {
            static const char *names[] = { "getter", "hint", "label",  nullptr };
            return names;
        }
        case 3: {
            static const char *names[] = { "group", "hint",  nullptr };
            return names;
        }
        case 4: {
            static const char *names[] = { "group", "hint",  nullptr };
            return names;
        }
        case 5: {
            static const char *names[] = { "group", "hint", "label", "sizeGetter",  nullptr };
            return names;
        }
        case 6: {
            static const char *names[] = { "hint",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cSimulationDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"hint")) return "The current simulation time in seconds";
            return nullptr;
        case 1:
            if (!strcmp(propertyname,"hint")) return "The current event number -- counts from 0 up";
            return nullptr;
        case 2:
            if (!strcmp(propertyname,"getter")) return "getFES";
            if (!strcmp(propertyname,"hint")) return "Self-messages scheduled, and messages in transit";
            if (!strcmp(propertyname,"label")) return "futureEvents";
            return nullptr;
        case 3:
            if (!strcmp(propertyname,"group")) return "components";
            if (!strcmp(propertyname,"hint")) return "The largest component ID issued so far";
            return nullptr;
        case 4:
            if (!strcmp(propertyname,"group")) return "components";
            if (!strcmp(propertyname,"hint")) return "The top-level module";
            return nullptr;
        case 5:
            if (!strcmp(propertyname,"group")) return "components";
            if (!strcmp(propertyname,"hint")) return "List of components indexed by component ID";
            if (!strcmp(propertyname,"label")) return "components";
            if (!strcmp(propertyname,"sizeGetter")) return "getLastComponentId";
            return nullptr;
        case 6:
            if (!strcmp(propertyname,"hint")) return "Used for computing simulation fingerprint";
            return nullptr;
        default: return nullptr;
    }
}

int cSimulationDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cSimulation *pp = (cSimulation *)object; (void)pp;
    switch (field) {
        case 5: return pp->getLastComponentId();
        default: return 0;
    }
}

std::string cSimulationDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cSimulation *pp = (cSimulation *)object; (void)pp;
    switch (field) {
        case 0: return simtime2string(pp->getSimTime());
        case 1: return int642string(pp->getEventNumber());
        case 2: {std::stringstream out; out << pp->getFES(); return out.str();}
        case 3: return long2string(pp->getLastComponentId());
        case 4: {std::stringstream out; out << pp->getSystemModule(); return out.str();}
        case 5: {std::stringstream out; out << pp->getComponent(i); return out.str();}
        case 6: {std::stringstream out; out << pp->getFingerprintCalculator(); return out.str();}
        default: return "";
    }
}

bool cSimulationDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cSimulation *pp = (cSimulation *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cSimulationDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 2: return omnetpp::opp_typename(typeid(cFutureEventSet));
        case 4: return omnetpp::opp_typename(typeid(cModule));
        case 5: return omnetpp::opp_typename(typeid(cComponent));
        case 6: return omnetpp::opp_typename(typeid(cFingerprintCalculator));
        default: return nullptr;
    };
}

void *cSimulationDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cSimulation *pp = (cSimulation *)object; (void)pp;
    switch (field) {
        case 2: return (void *)static_cast<omnetpp::cObject *>(pp->getFES()); break;
        case 4: return (void *)static_cast<omnetpp::cObject *>(pp->getSystemModule()); break;
        case 5: return (void *)static_cast<omnetpp::cObject *>(pp->getComponent(i)); break;
        case 6: return (void *)static_cast<omnetpp::cObject *>(pp->getFingerprintCalculator()); break;
        default: return nullptr;
    }
}

class cSchedulerDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cSchedulerDescriptor();
    virtual ~cSchedulerDescriptor();

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

Register_ClassDescriptor(cSchedulerDescriptor);

cSchedulerDescriptor::cSchedulerDescriptor() : omnetpp::cClassDescriptor("omnetpp::cScheduler", "omnetpp::cObject")
{
    propertynames = nullptr;
}

cSchedulerDescriptor::~cSchedulerDescriptor()
{
    delete[] propertynames;
}

bool cSchedulerDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cScheduler *>(obj)!=nullptr;
}

const char **cSchedulerDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cSchedulerDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cSchedulerDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int cSchedulerDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *cSchedulerDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int cSchedulerDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cSchedulerDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **cSchedulerDescriptor::getFieldPropertyNames(int field) const
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

const char *cSchedulerDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cSchedulerDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cScheduler *pp = (cScheduler *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cSchedulerDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cScheduler *pp = (cScheduler *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cSchedulerDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cScheduler *pp = (cScheduler *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cSchedulerDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *cSchedulerDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cScheduler *pp = (cScheduler *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cSequentialSchedulerDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cSequentialSchedulerDescriptor();
    virtual ~cSequentialSchedulerDescriptor();

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

Register_ClassDescriptor(cSequentialSchedulerDescriptor);

cSequentialSchedulerDescriptor::cSequentialSchedulerDescriptor() : omnetpp::cClassDescriptor("omnetpp::cSequentialScheduler", "omnetpp::cScheduler")
{
    propertynames = nullptr;
}

cSequentialSchedulerDescriptor::~cSequentialSchedulerDescriptor()
{
    delete[] propertynames;
}

bool cSequentialSchedulerDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cSequentialScheduler *>(obj)!=nullptr;
}

const char **cSequentialSchedulerDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cSequentialSchedulerDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cSequentialSchedulerDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int cSequentialSchedulerDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *cSequentialSchedulerDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int cSequentialSchedulerDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cSequentialSchedulerDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **cSequentialSchedulerDescriptor::getFieldPropertyNames(int field) const
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

const char *cSequentialSchedulerDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cSequentialSchedulerDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cSequentialScheduler *pp = (cSequentialScheduler *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cSequentialSchedulerDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cSequentialScheduler *pp = (cSequentialScheduler *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cSequentialSchedulerDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cSequentialScheduler *pp = (cSequentialScheduler *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cSequentialSchedulerDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *cSequentialSchedulerDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cSequentialScheduler *pp = (cSequentialScheduler *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cRealTimeSchedulerDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cRealTimeSchedulerDescriptor();
    virtual ~cRealTimeSchedulerDescriptor();

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

Register_ClassDescriptor(cRealTimeSchedulerDescriptor);

cRealTimeSchedulerDescriptor::cRealTimeSchedulerDescriptor() : omnetpp::cClassDescriptor("omnetpp::cRealTimeScheduler", "omnetpp::cScheduler")
{
    propertynames = nullptr;
}

cRealTimeSchedulerDescriptor::~cRealTimeSchedulerDescriptor()
{
    delete[] propertynames;
}

bool cRealTimeSchedulerDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cRealTimeScheduler *>(obj)!=nullptr;
}

const char **cRealTimeSchedulerDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cRealTimeSchedulerDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cRealTimeSchedulerDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int cRealTimeSchedulerDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *cRealTimeSchedulerDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int cRealTimeSchedulerDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cRealTimeSchedulerDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **cRealTimeSchedulerDescriptor::getFieldPropertyNames(int field) const
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

const char *cRealTimeSchedulerDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cRealTimeSchedulerDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cRealTimeScheduler *pp = (cRealTimeScheduler *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cRealTimeSchedulerDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cRealTimeScheduler *pp = (cRealTimeScheduler *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cRealTimeSchedulerDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cRealTimeScheduler *pp = (cRealTimeScheduler *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cRealTimeSchedulerDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *cRealTimeSchedulerDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cRealTimeScheduler *pp = (cRealTimeScheduler *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cTopology_NodeDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cTopology_NodeDescriptor();
    virtual ~cTopology_NodeDescriptor();

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

Register_ClassDescriptor(cTopology_NodeDescriptor);

cTopology_NodeDescriptor::cTopology_NodeDescriptor() : omnetpp::cClassDescriptor("omnetpp::cTopology_Node", "")
{
    propertynames = nullptr;
}

cTopology_NodeDescriptor::~cTopology_NodeDescriptor()
{
    delete[] propertynames;
}

bool cTopology_NodeDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cTopology_Node *>(obj)!=nullptr;
}

const char **cTopology_NodeDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cTopology_NodeDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cTopology_NodeDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount() : 8;
}

unsigned int cTopology_NodeDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,
        0,
        0,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISPOINTER,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISPOINTER,
        0,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISPOINTER,
    };
    return (field>=0 && field<8) ? fieldTypeFlags[field] : 0;
}

const char *cTopology_NodeDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "moduleId",
        "module",
        "weight",
        "enabled",
        "inLink",
        "outLink",
        "distanceToTarget",
        "path",
    };
    return (field>=0 && field<8) ? fieldNames[field] : nullptr;
}

int cTopology_NodeDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='m' && strcmp(fieldName, "moduleId")==0) return base+0;
    if (fieldName[0]=='m' && strcmp(fieldName, "module")==0) return base+1;
    if (fieldName[0]=='w' && strcmp(fieldName, "weight")==0) return base+2;
    if (fieldName[0]=='e' && strcmp(fieldName, "enabled")==0) return base+3;
    if (fieldName[0]=='i' && strcmp(fieldName, "inLink")==0) return base+4;
    if (fieldName[0]=='o' && strcmp(fieldName, "outLink")==0) return base+5;
    if (fieldName[0]=='d' && strcmp(fieldName, "distanceToTarget")==0) return base+6;
    if (fieldName[0]=='p' && strcmp(fieldName, "path")==0) return base+7;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cTopology_NodeDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "cModule",
        "double",
        "bool",
        "cTopology_LinkIn",
        "cTopology_LinkIn",
        "double",
        "cTopology_LinkOut",
    };
    return (field>=0 && field<8) ? fieldTypeStrings[field] : nullptr;
}

const char **cTopology_NodeDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "hint",  nullptr };
            return names;
        }
        case 1: {
            static const char *names[] = { "hint",  nullptr };
            return names;
        }
        case 2: {
            static const char *names[] = { "hint",  nullptr };
            return names;
        }
        case 3: {
            static const char *names[] = { "getter", "hint",  nullptr };
            return names;
        }
        case 4: {
            static const char *names[] = { "getter", "hint", "sizeGetter",  nullptr };
            return names;
        }
        case 5: {
            static const char *names[] = { "getter", "hint", "sizeGetter",  nullptr };
            return names;
        }
        case 6: {
            static const char *names[] = { "group", "hint",  nullptr };
            return names;
        }
        case 7: {
            static const char *names[] = { "group", "hint", "sizeGetter",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cTopology_NodeDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"hint")) return "ID of the module this node corresponds to";
            return nullptr;
        case 1:
            if (!strcmp(propertyname,"hint")) return "The module this node corresponds to";
            return nullptr;
        case 2:
            if (!strcmp(propertyname,"hint")) return "Node weight -- affects graph algorithms such as shortest path";
            return nullptr;
        case 3:
            if (!strcmp(propertyname,"getter")) return "isEnabled";
            if (!strcmp(propertyname,"hint")) return "Node state -- affects graph algorithms such as shortest path";
            return nullptr;
        case 4:
            if (!strcmp(propertyname,"getter")) return "getLinkIn";
            if (!strcmp(propertyname,"hint")) return "Incoming links of this graph node";
            if (!strcmp(propertyname,"sizeGetter")) return "getNumInLinks";
            return nullptr;
        case 5:
            if (!strcmp(propertyname,"getter")) return "getLinkOut";
            if (!strcmp(propertyname,"hint")) return "Outgoing links of this graph node";
            if (!strcmp(propertyname,"sizeGetter")) return "getNumOutLinks";
            return nullptr;
        case 6:
            if (!strcmp(propertyname,"group")) return "shortest path";
            if (!strcmp(propertyname,"hint")) return "After running a shortest path algorithm: distance to the target node";
            return nullptr;
        case 7:
            if (!strcmp(propertyname,"group")) return "shortest path";
            if (!strcmp(propertyname,"hint")) return "The next link of the shortest path or paths towards the target node";
            if (!strcmp(propertyname,"sizeGetter")) return "getNumPaths";
            return nullptr;
        default: return nullptr;
    }
}

int cTopology_NodeDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cTopology_Node *pp = (cTopology_Node *)object; (void)pp;
    switch (field) {
        case 4: return pp->getNumInLinks();
        case 5: return pp->getNumOutLinks();
        case 7: return pp->getNumPaths();
        default: return 0;
    }
}

std::string cTopology_NodeDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cTopology_Node *pp = (cTopology_Node *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getModuleId());
        case 1: {std::stringstream out; out << pp->getModule(); return out.str();}
        case 2: return double2string(pp->getWeight());
        case 3: return bool2string(pp->isEnabled());
        case 4: {std::stringstream out; out << pp->getLinkIn(i); return out.str();}
        case 5: {std::stringstream out; out << pp->getLinkOut(i); return out.str();}
        case 6: return double2string(pp->getDistanceToTarget());
        case 7: {std::stringstream out; out << pp->getPath(i); return out.str();}
        default: return "";
    }
}

bool cTopology_NodeDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cTopology_Node *pp = (cTopology_Node *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cTopology_NodeDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(cModule));
        case 4: return omnetpp::opp_typename(typeid(cTopology_LinkIn));
        case 5: return omnetpp::opp_typename(typeid(cTopology_LinkIn));
        case 7: return omnetpp::opp_typename(typeid(cTopology_LinkOut));
        default: return nullptr;
    };
}

void *cTopology_NodeDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cTopology_Node *pp = (cTopology_Node *)object; (void)pp;
    switch (field) {
        case 1: return (void *)static_cast<omnetpp::cObject *>(pp->getModule()); break;
        case 4: return (void *)(pp->getLinkIn(i)); break;
        case 5: return (void *)(pp->getLinkOut(i)); break;
        case 7: return (void *)(pp->getPath(i)); break;
        default: return nullptr;
    }
}

class cTopology_LinkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cTopology_LinkDescriptor();
    virtual ~cTopology_LinkDescriptor();

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

Register_ClassDescriptor(cTopology_LinkDescriptor);

cTopology_LinkDescriptor::cTopology_LinkDescriptor() : omnetpp::cClassDescriptor("omnetpp::cTopology_Link", "")
{
    propertynames = nullptr;
}

cTopology_LinkDescriptor::~cTopology_LinkDescriptor()
{
    delete[] propertynames;
}

bool cTopology_LinkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cTopology_Link *>(obj)!=nullptr;
}

const char **cTopology_LinkDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cTopology_LinkDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cTopology_LinkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int cTopology_LinkDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        0,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *cTopology_LinkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "weight",
        "enabled",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int cTopology_LinkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='w' && strcmp(fieldName, "weight")==0) return base+0;
    if (fieldName[0]=='e' && strcmp(fieldName, "enabled")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cTopology_LinkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "double",
        "bool",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **cTopology_LinkDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "hint",  nullptr };
            return names;
        }
        case 1: {
            static const char *names[] = { "getter", "hint",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cTopology_LinkDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"hint")) return "Link weight -- affects graph algorithms such as shortest path";
            return nullptr;
        case 1:
            if (!strcmp(propertyname,"getter")) return "isEnabled";
            if (!strcmp(propertyname,"hint")) return "Link state -- affects graph algorithms such as shortest path";
            return nullptr;
        default: return nullptr;
    }
}

int cTopology_LinkDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cTopology_Link *pp = (cTopology_Link *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cTopology_LinkDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cTopology_Link *pp = (cTopology_Link *)object; (void)pp;
    switch (field) {
        case 0: return double2string(pp->getWeight());
        case 1: return bool2string(pp->isEnabled());
        default: return "";
    }
}

bool cTopology_LinkDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cTopology_Link *pp = (cTopology_Link *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cTopology_LinkDescriptor::getFieldStructName(int field) const
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

void *cTopology_LinkDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cTopology_Link *pp = (cTopology_Link *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cTopology_LinkInDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cTopology_LinkInDescriptor();
    virtual ~cTopology_LinkInDescriptor();

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

Register_ClassDescriptor(cTopology_LinkInDescriptor);

cTopology_LinkInDescriptor::cTopology_LinkInDescriptor() : omnetpp::cClassDescriptor("omnetpp::cTopology_LinkIn", "omnetpp::cTopology_Link")
{
    propertynames = nullptr;
}

cTopology_LinkInDescriptor::~cTopology_LinkInDescriptor()
{
    delete[] propertynames;
}

bool cTopology_LinkInDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cTopology_LinkIn *>(obj)!=nullptr;
}

const char **cTopology_LinkInDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cTopology_LinkInDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cTopology_LinkInDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int cTopology_LinkInDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISPOINTER,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *cTopology_LinkInDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "remoteNode",
        "remoteGate",
        "localGate",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int cTopology_LinkInDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='r' && strcmp(fieldName, "remoteNode")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "remoteGate")==0) return base+1;
    if (fieldName[0]=='l' && strcmp(fieldName, "localGate")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cTopology_LinkInDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "cTopology_Node",
        "cGate",
        "cGate",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **cTopology_LinkInDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "hint",  nullptr };
            return names;
        }
        case 1: {
            static const char *names[] = { "hint",  nullptr };
            return names;
        }
        case 2: {
            static const char *names[] = { "hint",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cTopology_LinkInDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"hint")) return "The node at the remote end of this connection";
            return nullptr;
        case 1:
            if (!strcmp(propertyname,"hint")) return "The gate at the remote end of this connection";
            return nullptr;
        case 2:
            if (!strcmp(propertyname,"hint")) return "The gate at the local end of this connection";
            return nullptr;
        default: return nullptr;
    }
}

int cTopology_LinkInDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cTopology_LinkIn *pp = (cTopology_LinkIn *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cTopology_LinkInDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cTopology_LinkIn *pp = (cTopology_LinkIn *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getRemoteNode(); return out.str();}
        case 1: {std::stringstream out; out << pp->getRemoteGate(); return out.str();}
        case 2: {std::stringstream out; out << pp->getLocalGate(); return out.str();}
        default: return "";
    }
}

bool cTopology_LinkInDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cTopology_LinkIn *pp = (cTopology_LinkIn *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cTopology_LinkInDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(cTopology_Node));
        case 1: return omnetpp::opp_typename(typeid(cGate));
        case 2: return omnetpp::opp_typename(typeid(cGate));
        default: return nullptr;
    };
}

void *cTopology_LinkInDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cTopology_LinkIn *pp = (cTopology_LinkIn *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(pp->getRemoteNode()); break;
        case 1: return (void *)static_cast<omnetpp::cObject *>(pp->getRemoteGate()); break;
        case 2: return (void *)static_cast<omnetpp::cObject *>(pp->getLocalGate()); break;
        default: return nullptr;
    }
}

class cTopology_LinkOutDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cTopology_LinkOutDescriptor();
    virtual ~cTopology_LinkOutDescriptor();

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

Register_ClassDescriptor(cTopology_LinkOutDescriptor);

cTopology_LinkOutDescriptor::cTopology_LinkOutDescriptor() : omnetpp::cClassDescriptor("omnetpp::cTopology_LinkOut", "omnetpp::cTopology_Link")
{
    propertynames = nullptr;
}

cTopology_LinkOutDescriptor::~cTopology_LinkOutDescriptor()
{
    delete[] propertynames;
}

bool cTopology_LinkOutDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cTopology_LinkOut *>(obj)!=nullptr;
}

const char **cTopology_LinkOutDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cTopology_LinkOutDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cTopology_LinkOutDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int cTopology_LinkOutDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISPOINTER,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *cTopology_LinkOutDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "remoteNode",
        "remoteGate",
        "localGate",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int cTopology_LinkOutDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='r' && strcmp(fieldName, "remoteNode")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "remoteGate")==0) return base+1;
    if (fieldName[0]=='l' && strcmp(fieldName, "localGate")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cTopology_LinkOutDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "cTopology_Node",
        "cGate",
        "cGate",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **cTopology_LinkOutDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "hint",  nullptr };
            return names;
        }
        case 1: {
            static const char *names[] = { "hint",  nullptr };
            return names;
        }
        case 2: {
            static const char *names[] = { "hint",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cTopology_LinkOutDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"hint")) return "The node at the remote end of this connection";
            return nullptr;
        case 1:
            if (!strcmp(propertyname,"hint")) return "The gate at the remote end of this connection";
            return nullptr;
        case 2:
            if (!strcmp(propertyname,"hint")) return "The gate at the local end of this connection";
            return nullptr;
        default: return nullptr;
    }
}

int cTopology_LinkOutDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cTopology_LinkOut *pp = (cTopology_LinkOut *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cTopology_LinkOutDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cTopology_LinkOut *pp = (cTopology_LinkOut *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getRemoteNode(); return out.str();}
        case 1: {std::stringstream out; out << pp->getRemoteGate(); return out.str();}
        case 2: {std::stringstream out; out << pp->getLocalGate(); return out.str();}
        default: return "";
    }
}

bool cTopology_LinkOutDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cTopology_LinkOut *pp = (cTopology_LinkOut *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cTopology_LinkOutDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(cTopology_Node));
        case 1: return omnetpp::opp_typename(typeid(cGate));
        case 2: return omnetpp::opp_typename(typeid(cGate));
        default: return nullptr;
    };
}

void *cTopology_LinkOutDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cTopology_LinkOut *pp = (cTopology_LinkOut *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(pp->getRemoteNode()); break;
        case 1: return (void *)static_cast<omnetpp::cObject *>(pp->getRemoteGate()); break;
        case 2: return (void *)static_cast<omnetpp::cObject *>(pp->getLocalGate()); break;
        default: return nullptr;
    }
}

class cTopologyDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cTopologyDescriptor();
    virtual ~cTopologyDescriptor();

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

Register_ClassDescriptor(cTopologyDescriptor);

cTopologyDescriptor::cTopologyDescriptor() : omnetpp::cClassDescriptor("omnetpp::cTopology", "omnetpp::cOwnedObject")
{
    propertynames = nullptr;
}

cTopologyDescriptor::~cTopologyDescriptor()
{
    delete[] propertynames;
}

bool cTopologyDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cTopology *>(obj)!=nullptr;
}

const char **cTopologyDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cTopologyDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cTopologyDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int cTopologyDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISPOINTER,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *cTopologyDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "numNodes",
        "node",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int cTopologyDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='n' && strcmp(fieldName, "numNodes")==0) return base+0;
    if (fieldName[0]=='n' && strcmp(fieldName, "node")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cTopologyDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "cTopology_Node",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **cTopologyDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "group", "hint",  nullptr };
            return names;
        }
        case 1: {
            static const char *names[] = { "hint", "sizeGetter",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cTopologyDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"group")) return "fields";
            if (!strcmp(propertyname,"hint")) return "Number of nodes in this topology object";
            return nullptr;
        case 1:
            if (!strcmp(propertyname,"hint")) return "List of nodes in this topology object";
            if (!strcmp(propertyname,"sizeGetter")) return "getNumNodes";
            return nullptr;
        default: return nullptr;
    }
}

int cTopologyDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cTopology *pp = (cTopology *)object; (void)pp;
    switch (field) {
        case 1: return pp->getNumNodes();
        default: return 0;
    }
}

std::string cTopologyDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cTopology *pp = (cTopology *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getNumNodes());
        case 1: {std::stringstream out; out << pp->getNode(i); return out.str();}
        default: return "";
    }
}

bool cTopologyDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cTopology *pp = (cTopology *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cTopologyDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(cTopology_Node));
        default: return nullptr;
    };
}

void *cTopologyDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cTopology *pp = (cTopology *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(pp->getNode(i)); break;
        default: return nullptr;
    }
}

class cXMLElementDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cXMLElementDescriptor();
    virtual ~cXMLElementDescriptor();

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

Register_ClassDescriptor(cXMLElementDescriptor);

cXMLElementDescriptor::cXMLElementDescriptor() : omnetpp::cClassDescriptor("omnetpp::cXMLElement", "omnetpp::cObject")
{
    propertynames = nullptr;
}

cXMLElementDescriptor::~cXMLElementDescriptor()
{
    delete[] propertynames;
}

bool cXMLElementDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cXMLElement *>(obj)!=nullptr;
}

const char **cXMLElementDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cXMLElementDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cXMLElementDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int cXMLElementDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        0,
        0,
        0,
        0,
        0,
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *cXMLElementDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "tagName",
        "nodeValue",
        "sourceLocation",
        "hasAttributes",
        "hasChildren",
        "detailedInfo",
    };
    return (field>=0 && field<6) ? fieldNames[field] : nullptr;
}

int cXMLElementDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "tagName")==0) return base+0;
    if (fieldName[0]=='n' && strcmp(fieldName, "nodeValue")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceLocation")==0) return base+2;
    if (fieldName[0]=='h' && strcmp(fieldName, "hasAttributes")==0) return base+3;
    if (fieldName[0]=='h' && strcmp(fieldName, "hasChildren")==0) return base+4;
    if (fieldName[0]=='d' && strcmp(fieldName, "detailedInfo")==0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cXMLElementDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "string",
        "string",
        "bool",
        "bool",
        "string",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : nullptr;
}

const char **cXMLElementDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "hint",  nullptr };
            return names;
        }
        case 1: {
            static const char *names[] = { "hint",  nullptr };
            return names;
        }
        case 2: {
            static const char *names[] = { "hint",  nullptr };
            return names;
        }
        case 3: {
            static const char *names[] = { "getter", "hint",  nullptr };
            return names;
        }
        case 4: {
            static const char *names[] = { "getter", "hint",  nullptr };
            return names;
        }
        case 5: {
            static const char *names[] = { "getter", "label",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cXMLElementDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"hint")) return "XML element tag";
            return nullptr;
        case 1:
            if (!strcmp(propertyname,"hint")) return "Contents of text node inside this XML element";
            return nullptr;
        case 2:
            if (!strcmp(propertyname,"hint")) return "Location this XML element was parsed from";
            return nullptr;
        case 3:
            if (!strcmp(propertyname,"getter")) return "hasAttributes";
            if (!strcmp(propertyname,"hint")) return "Whether this XML element has attributes";
            return nullptr;
        case 4:
            if (!strcmp(propertyname,"getter")) return "hasChildren";
            if (!strcmp(propertyname,"hint")) return "Whether this XML element has child elements";
            return nullptr;
        case 5:
            if (!strcmp(propertyname,"getter")) return "detailedInfo";
            if (!strcmp(propertyname,"label")) return "contents";
            return nullptr;
        default: return nullptr;
    }
}

int cXMLElementDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cXMLElement *pp = (cXMLElement *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cXMLElementDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cXMLElement *pp = (cXMLElement *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getTagName());
        case 1: return oppstring2string(pp->getNodeValue());
        case 2: return oppstring2string(pp->getSourceLocation());
        case 3: return bool2string(pp->hasAttributes());
        case 4: return bool2string(pp->hasChildren());
        case 5: return oppstring2string(pp->detailedInfo());
        default: return "";
    }
}

bool cXMLElementDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cXMLElement *pp = (cXMLElement *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cXMLElementDescriptor::getFieldStructName(int field) const
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

void *cXMLElementDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cXMLElement *pp = (cXMLElement *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cFigureDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cFigureDescriptor();
    virtual ~cFigureDescriptor();

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

Register_ClassDescriptor(cFigureDescriptor);

cFigureDescriptor::cFigureDescriptor() : omnetpp::cClassDescriptor("omnetpp::cFigure", "omnetpp::cOwnedObject")
{
    propertynames = nullptr;
}

cFigureDescriptor::~cFigureDescriptor()
{
    delete[] propertynames;
}

bool cFigureDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cFigure *>(obj)!=nullptr;
}

const char **cFigureDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cFigureDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cFigureDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int cFigureDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *cFigureDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "id",
        "visible",
        "tags",
        "transform",
        "children",
    };
    return (field>=0 && field<5) ? fieldNames[field] : nullptr;
}

int cFigureDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "id")==0) return base+0;
    if (fieldName[0]=='v' && strcmp(fieldName, "visible")==0) return base+1;
    if (fieldName[0]=='t' && strcmp(fieldName, "tags")==0) return base+2;
    if (fieldName[0]=='t' && strcmp(fieldName, "transform")==0) return base+3;
    if (fieldName[0]=='c' && strcmp(fieldName, "children")==0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cFigureDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "bool",
        "string",
        "Transform",
        "cFigure",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : nullptr;
}

const char **cFigureDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: {
            static const char *names[] = { "editable", "getter",  nullptr };
            return names;
        }
        case 2: {
            static const char *names[] = { "editable",  nullptr };
            return names;
        }
        case 3: {
            static const char *names[] = { "editable", "fromstring", "tostring",  nullptr };
            return names;
        }
        case 4: {
            static const char *names[] = { "getter", "sizeGetter",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cFigureDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"getter")) return "isVisible";
            return nullptr;
        case 2:
            if (!strcmp(propertyname,"editable")) return "";
            return nullptr;
        case 3:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"fromstring")) return "cFigure::parseTransform($)";
            if (!strcmp(propertyname,"tostring")) return ".str()";
            return nullptr;
        case 4:
            if (!strcmp(propertyname,"getter")) return "getFigure";
            if (!strcmp(propertyname,"sizeGetter")) return "getNumFigures";
            return nullptr;
        default: return nullptr;
    }
}

int cFigureDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cFigure *pp = (cFigure *)object; (void)pp;
    switch (field) {
        case 4: return pp->getNumFigures();
        default: return 0;
    }
}

std::string cFigureDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cFigure *pp = (cFigure *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getId());
        case 1: return bool2string(pp->isVisible());
        case 2: return oppstring2string(pp->getTags());
        case 3: return pp->getTransform().str();
        case 4: {std::stringstream out; out << pp->getFigure(i); return out.str();}
        default: return "";
    }
}

bool cFigureDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cFigure *pp = (cFigure *)object; (void)pp;
    switch (field) {
        case 1: pp->setVisible(string2bool(value)); return true;
        case 2: pp->setTags((value)); return true;
        case 3: pp->setTransform(cFigure::parseTransform(value)); return true;
        default: return false;
    }
}

const char *cFigureDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 3: return omnetpp::opp_typename(typeid(Transform));
        case 4: return omnetpp::opp_typename(typeid(cFigure));
        default: return nullptr;
    };
}

void *cFigureDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cFigure *pp = (cFigure *)object; (void)pp;
    switch (field) {
        case 3: return (void *)(&pp->getTransform()); break;
        case 4: return (void *)static_cast<omnetpp::cObject *>(pp->getFigure(i)); break;
        default: return nullptr;
    }
}

class cGroupFigureDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cGroupFigureDescriptor();
    virtual ~cGroupFigureDescriptor();

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

Register_ClassDescriptor(cGroupFigureDescriptor);

cGroupFigureDescriptor::cGroupFigureDescriptor() : omnetpp::cClassDescriptor("omnetpp::cGroupFigure", "omnetpp::cFigure")
{
    propertynames = nullptr;
}

cGroupFigureDescriptor::~cGroupFigureDescriptor()
{
    delete[] propertynames;
}

bool cGroupFigureDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cGroupFigure *>(obj)!=nullptr;
}

const char **cGroupFigureDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cGroupFigureDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cGroupFigureDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int cGroupFigureDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *cGroupFigureDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int cGroupFigureDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cGroupFigureDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **cGroupFigureDescriptor::getFieldPropertyNames(int field) const
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

const char *cGroupFigureDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cGroupFigureDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cGroupFigure *pp = (cGroupFigure *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cGroupFigureDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cGroupFigure *pp = (cGroupFigure *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cGroupFigureDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cGroupFigure *pp = (cGroupFigure *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cGroupFigureDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *cGroupFigureDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cGroupFigure *pp = (cGroupFigure *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cAbstractLineFigureDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cAbstractLineFigureDescriptor();
    virtual ~cAbstractLineFigureDescriptor();

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

Register_ClassDescriptor(cAbstractLineFigureDescriptor);

cAbstractLineFigureDescriptor::cAbstractLineFigureDescriptor() : omnetpp::cClassDescriptor("omnetpp::cAbstractLineFigure", "omnetpp::cFigure")
{
    propertynames = nullptr;
}

cAbstractLineFigureDescriptor::~cAbstractLineFigureDescriptor()
{
    delete[] propertynames;
}

bool cAbstractLineFigureDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cAbstractLineFigure *>(obj)!=nullptr;
}

const char **cAbstractLineFigureDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cAbstractLineFigureDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cAbstractLineFigureDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount() : 8;
}

unsigned int cAbstractLineFigureDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<8) ? fieldTypeFlags[field] : 0;
}

const char *cAbstractLineFigureDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "lineColor",
        "lineStyle",
        "lineWidth",
        "lineOpacity",
        "capStyle",
        "startArrowhead",
        "endArrowhead",
        "zoomLineWidth",
    };
    return (field>=0 && field<8) ? fieldNames[field] : nullptr;
}

int cAbstractLineFigureDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='l' && strcmp(fieldName, "lineColor")==0) return base+0;
    if (fieldName[0]=='l' && strcmp(fieldName, "lineStyle")==0) return base+1;
    if (fieldName[0]=='l' && strcmp(fieldName, "lineWidth")==0) return base+2;
    if (fieldName[0]=='l' && strcmp(fieldName, "lineOpacity")==0) return base+3;
    if (fieldName[0]=='c' && strcmp(fieldName, "capStyle")==0) return base+4;
    if (fieldName[0]=='s' && strcmp(fieldName, "startArrowhead")==0) return base+5;
    if (fieldName[0]=='e' && strcmp(fieldName, "endArrowhead")==0) return base+6;
    if (fieldName[0]=='z' && strcmp(fieldName, "zoomLineWidth")==0) return base+7;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cAbstractLineFigureDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "Color",
        "int",
        "double",
        "double",
        "int",
        "int",
        "int",
        "bool",
    };
    return (field>=0 && field<8) ? fieldTypeStrings[field] : nullptr;
}

const char **cAbstractLineFigureDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "editable", "fromstring", "tostring",  nullptr };
            return names;
        }
        case 1: {
            static const char *names[] = { "editable", "enum",  nullptr };
            return names;
        }
        case 2: {
            static const char *names[] = { "editable",  nullptr };
            return names;
        }
        case 3: {
            static const char *names[] = { "editable",  nullptr };
            return names;
        }
        case 4: {
            static const char *names[] = { "editable", "enum",  nullptr };
            return names;
        }
        case 5: {
            static const char *names[] = { "editable", "enum",  nullptr };
            return names;
        }
        case 6: {
            static const char *names[] = { "editable", "enum",  nullptr };
            return names;
        }
        case 7: {
            static const char *names[] = { "editable",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cAbstractLineFigureDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"fromstring")) return "cFigure::parseColor($)";
            if (!strcmp(propertyname,"tostring")) return ".str()";
            return nullptr;
        case 1:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"enum")) return "omnetpp::cFigure::LineStyle";
            return nullptr;
        case 2:
            if (!strcmp(propertyname,"editable")) return "";
            return nullptr;
        case 3:
            if (!strcmp(propertyname,"editable")) return "";
            return nullptr;
        case 4:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"enum")) return "omnetpp::cFigure::CapStyle";
            return nullptr;
        case 5:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"enum")) return "omnetpp::cFigure::Arrowhead";
            return nullptr;
        case 6:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"enum")) return "omnetpp::cFigure::Arrowhead";
            return nullptr;
        case 7:
            if (!strcmp(propertyname,"editable")) return "";
            return nullptr;
        default: return nullptr;
    }
}

int cAbstractLineFigureDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cAbstractLineFigure *pp = (cAbstractLineFigure *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cAbstractLineFigureDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cAbstractLineFigure *pp = (cAbstractLineFigure *)object; (void)pp;
    switch (field) {
        case 0: return pp->getLineColor().str();
        case 1: return enum2string(pp->getLineStyle(), "omnetpp::cFigure::LineStyle");
        case 2: return double2string(pp->getLineWidth());
        case 3: return double2string(pp->getLineOpacity());
        case 4: return enum2string(pp->getCapStyle(), "omnetpp::cFigure::CapStyle");
        case 5: return enum2string(pp->getStartArrowhead(), "omnetpp::cFigure::Arrowhead");
        case 6: return enum2string(pp->getEndArrowhead(), "omnetpp::cFigure::Arrowhead");
        case 7: return bool2string(pp->getZoomLineWidth());
        default: return "";
    }
}

bool cAbstractLineFigureDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cAbstractLineFigure *pp = (cAbstractLineFigure *)object; (void)pp;
    switch (field) {
        case 0: pp->setLineColor(cFigure::parseColor(value)); return true;
        case 1: pp->setLineStyle((omnetpp::cFigure::LineStyle)string2enum(value, "omnetpp::cFigure::LineStyle")); return true;
        case 2: pp->setLineWidth(string2double(value)); return true;
        case 3: pp->setLineOpacity(string2double(value)); return true;
        case 4: pp->setCapStyle((omnetpp::cFigure::CapStyle)string2enum(value, "omnetpp::cFigure::CapStyle")); return true;
        case 5: pp->setStartArrowhead((omnetpp::cFigure::Arrowhead)string2enum(value, "omnetpp::cFigure::Arrowhead")); return true;
        case 6: pp->setEndArrowhead((omnetpp::cFigure::Arrowhead)string2enum(value, "omnetpp::cFigure::Arrowhead")); return true;
        case 7: pp->setZoomLineWidth(string2bool(value)); return true;
        default: return false;
    }
}

const char *cAbstractLineFigureDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(Color));
        default: return nullptr;
    };
}

void *cAbstractLineFigureDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cAbstractLineFigure *pp = (cAbstractLineFigure *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getLineColor()); break;
        default: return nullptr;
    }
}

class cLineFigureDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cLineFigureDescriptor();
    virtual ~cLineFigureDescriptor();

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

Register_ClassDescriptor(cLineFigureDescriptor);

cLineFigureDescriptor::cLineFigureDescriptor() : omnetpp::cClassDescriptor("omnetpp::cLineFigure", "omnetpp::cAbstractLineFigure")
{
    propertynames = nullptr;
}

cLineFigureDescriptor::~cLineFigureDescriptor()
{
    delete[] propertynames;
}

bool cLineFigureDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cLineFigure *>(obj)!=nullptr;
}

const char **cLineFigureDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cLineFigureDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cLineFigureDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int cLineFigureDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISEDITABLE,
        FD_ISCOMPOUND | FD_ISEDITABLE,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *cLineFigureDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "start",
        "end",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int cLineFigureDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "start")==0) return base+0;
    if (fieldName[0]=='e' && strcmp(fieldName, "end")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cLineFigureDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "Point",
        "Point",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **cLineFigureDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "editable", "fromstring", "tostring",  nullptr };
            return names;
        }
        case 1: {
            static const char *names[] = { "editable", "fromstring", "tostring",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cLineFigureDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"fromstring")) return "cFigure::parsePoint($)";
            if (!strcmp(propertyname,"tostring")) return ".str()";
            return nullptr;
        case 1:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"fromstring")) return "cFigure::parsePoint($)";
            if (!strcmp(propertyname,"tostring")) return ".str()";
            return nullptr;
        default: return nullptr;
    }
}

int cLineFigureDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cLineFigure *pp = (cLineFigure *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cLineFigureDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cLineFigure *pp = (cLineFigure *)object; (void)pp;
    switch (field) {
        case 0: return pp->getStart().str();
        case 1: return pp->getEnd().str();
        default: return "";
    }
}

bool cLineFigureDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cLineFigure *pp = (cLineFigure *)object; (void)pp;
    switch (field) {
        case 0: pp->setStart(cFigure::parsePoint(value)); return true;
        case 1: pp->setEnd(cFigure::parsePoint(value)); return true;
        default: return false;
    }
}

const char *cLineFigureDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(Point));
        case 1: return omnetpp::opp_typename(typeid(Point));
        default: return nullptr;
    };
}

void *cLineFigureDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cLineFigure *pp = (cLineFigure *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getStart()); break;
        case 1: return (void *)(&pp->getEnd()); break;
        default: return nullptr;
    }
}

class cArcFigureDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cArcFigureDescriptor();
    virtual ~cArcFigureDescriptor();

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

Register_ClassDescriptor(cArcFigureDescriptor);

cArcFigureDescriptor::cArcFigureDescriptor() : omnetpp::cClassDescriptor("omnetpp::cArcFigure", "omnetpp::cAbstractLineFigure")
{
    propertynames = nullptr;
}

cArcFigureDescriptor::~cArcFigureDescriptor()
{
    delete[] propertynames;
}

bool cArcFigureDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cArcFigure *>(obj)!=nullptr;
}

const char **cArcFigureDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cArcFigureDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cArcFigureDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int cArcFigureDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *cArcFigureDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "bounds",
        "startAngle",
        "endAngle",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int cArcFigureDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='b' && strcmp(fieldName, "bounds")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "startAngle")==0) return base+1;
    if (fieldName[0]=='e' && strcmp(fieldName, "endAngle")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cArcFigureDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "Rectangle",
        "double",
        "double",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **cArcFigureDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "editable", "fromstring", "tostring",  nullptr };
            return names;
        }
        case 1: {
            static const char *names[] = { "editable",  nullptr };
            return names;
        }
        case 2: {
            static const char *names[] = { "editable",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cArcFigureDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"fromstring")) return "cFigure::parseRectangle($)";
            if (!strcmp(propertyname,"tostring")) return ".str()";
            return nullptr;
        case 1:
            if (!strcmp(propertyname,"editable")) return "";
            return nullptr;
        case 2:
            if (!strcmp(propertyname,"editable")) return "";
            return nullptr;
        default: return nullptr;
    }
}

int cArcFigureDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cArcFigure *pp = (cArcFigure *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cArcFigureDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cArcFigure *pp = (cArcFigure *)object; (void)pp;
    switch (field) {
        case 0: return pp->getBounds().str();
        case 1: return double2string(pp->getStartAngle());
        case 2: return double2string(pp->getEndAngle());
        default: return "";
    }
}

bool cArcFigureDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cArcFigure *pp = (cArcFigure *)object; (void)pp;
    switch (field) {
        case 0: pp->setBounds(cFigure::parseRectangle(value)); return true;
        case 1: pp->setStartAngle(string2double(value)); return true;
        case 2: pp->setEndAngle(string2double(value)); return true;
        default: return false;
    }
}

const char *cArcFigureDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(Rectangle));
        default: return nullptr;
    };
}

void *cArcFigureDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cArcFigure *pp = (cArcFigure *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getBounds()); break;
        default: return nullptr;
    }
}

class cPolylineFigureDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cPolylineFigureDescriptor();
    virtual ~cPolylineFigureDescriptor();

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

Register_ClassDescriptor(cPolylineFigureDescriptor);

cPolylineFigureDescriptor::cPolylineFigureDescriptor() : omnetpp::cClassDescriptor("omnetpp::cPolylineFigure", "omnetpp::cAbstractLineFigure")
{
    propertynames = nullptr;
}

cPolylineFigureDescriptor::~cPolylineFigureDescriptor()
{
    delete[] propertynames;
}

bool cPolylineFigureDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cPolylineFigure *>(obj)!=nullptr;
}

const char **cPolylineFigureDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cPolylineFigureDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cPolylineFigureDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int cPolylineFigureDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *cPolylineFigureDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "points",
        "smooth",
        "joinStyle",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int cPolylineFigureDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "points")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "smooth")==0) return base+1;
    if (fieldName[0]=='j' && strcmp(fieldName, "joinStyle")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cPolylineFigureDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "Point",
        "bool",
        "int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **cPolylineFigureDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "editable", "fromstring", "getter", "setter", "sizeGetter", "tostring",  nullptr };
            return names;
        }
        case 1: {
            static const char *names[] = { "editable",  nullptr };
            return names;
        }
        case 2: {
            static const char *names[] = { "editable", "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cPolylineFigureDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"fromstring")) return "cFigure::parsePoint($)";
            if (!strcmp(propertyname,"getter")) return "getPoint";
            if (!strcmp(propertyname,"setter")) return "setPoint";
            if (!strcmp(propertyname,"sizeGetter")) return "getNumPoints";
            if (!strcmp(propertyname,"tostring")) return ".str()";
            return nullptr;
        case 1:
            if (!strcmp(propertyname,"editable")) return "";
            return nullptr;
        case 2:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"enum")) return "omnetpp::cFigure::JoinStyle";
            return nullptr;
        default: return nullptr;
    }
}

int cPolylineFigureDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cPolylineFigure *pp = (cPolylineFigure *)object; (void)pp;
    switch (field) {
        case 0: return pp->getNumPoints();
        default: return 0;
    }
}

std::string cPolylineFigureDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cPolylineFigure *pp = (cPolylineFigure *)object; (void)pp;
    switch (field) {
        case 0: return pp->getPoint(i).str();
        case 1: return bool2string(pp->getSmooth());
        case 2: return enum2string(pp->getJoinStyle(), "omnetpp::cFigure::JoinStyle");
        default: return "";
    }
}

bool cPolylineFigureDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cPolylineFigure *pp = (cPolylineFigure *)object; (void)pp;
    switch (field) {
        case 0: pp->setPoint(i,cFigure::parsePoint(value)); return true;
        case 1: pp->setSmooth(string2bool(value)); return true;
        case 2: pp->setJoinStyle((omnetpp::cFigure::JoinStyle)string2enum(value, "omnetpp::cFigure::JoinStyle")); return true;
        default: return false;
    }
}

const char *cPolylineFigureDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(Point));
        default: return nullptr;
    };
}

void *cPolylineFigureDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cPolylineFigure *pp = (cPolylineFigure *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getPoint(i)); break;
        default: return nullptr;
    }
}

class cAbstractShapeFigureDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cAbstractShapeFigureDescriptor();
    virtual ~cAbstractShapeFigureDescriptor();

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

Register_ClassDescriptor(cAbstractShapeFigureDescriptor);

cAbstractShapeFigureDescriptor::cAbstractShapeFigureDescriptor() : omnetpp::cClassDescriptor("omnetpp::cAbstractShapeFigure", "omnetpp::cFigure")
{
    propertynames = nullptr;
}

cAbstractShapeFigureDescriptor::~cAbstractShapeFigureDescriptor()
{
    delete[] propertynames;
}

bool cAbstractShapeFigureDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cAbstractShapeFigure *>(obj)!=nullptr;
}

const char **cAbstractShapeFigureDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cAbstractShapeFigureDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cAbstractShapeFigureDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 9+basedesc->getFieldCount() : 9;
}

unsigned int cAbstractShapeFigureDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISCOMPOUND | FD_ISEDITABLE,
        FD_ISCOMPOUND | FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<9) ? fieldTypeFlags[field] : 0;
}

const char *cAbstractShapeFigureDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "outlined",
        "filled",
        "lineColor",
        "fillColor",
        "lineStyle",
        "lineWidth",
        "lineOpacity",
        "fillOpacity",
        "zoomLineWidth",
    };
    return (field>=0 && field<9) ? fieldNames[field] : nullptr;
}

int cAbstractShapeFigureDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='o' && strcmp(fieldName, "outlined")==0) return base+0;
    if (fieldName[0]=='f' && strcmp(fieldName, "filled")==0) return base+1;
    if (fieldName[0]=='l' && strcmp(fieldName, "lineColor")==0) return base+2;
    if (fieldName[0]=='f' && strcmp(fieldName, "fillColor")==0) return base+3;
    if (fieldName[0]=='l' && strcmp(fieldName, "lineStyle")==0) return base+4;
    if (fieldName[0]=='l' && strcmp(fieldName, "lineWidth")==0) return base+5;
    if (fieldName[0]=='l' && strcmp(fieldName, "lineOpacity")==0) return base+6;
    if (fieldName[0]=='f' && strcmp(fieldName, "fillOpacity")==0) return base+7;
    if (fieldName[0]=='z' && strcmp(fieldName, "zoomLineWidth")==0) return base+8;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cAbstractShapeFigureDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "bool",
        "Color",
        "Color",
        "int",
        "double",
        "double",
        "double",
        "bool",
    };
    return (field>=0 && field<9) ? fieldTypeStrings[field] : nullptr;
}

const char **cAbstractShapeFigureDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "editable", "getter",  nullptr };
            return names;
        }
        case 1: {
            static const char *names[] = { "editable", "getter",  nullptr };
            return names;
        }
        case 2: {
            static const char *names[] = { "editable", "fromstring", "tostring",  nullptr };
            return names;
        }
        case 3: {
            static const char *names[] = { "editable", "fromstring", "tostring",  nullptr };
            return names;
        }
        case 4: {
            static const char *names[] = { "editable", "enum",  nullptr };
            return names;
        }
        case 5: {
            static const char *names[] = { "editable",  nullptr };
            return names;
        }
        case 6: {
            static const char *names[] = { "editable",  nullptr };
            return names;
        }
        case 7: {
            static const char *names[] = { "editable",  nullptr };
            return names;
        }
        case 8: {
            static const char *names[] = { "editable",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cAbstractShapeFigureDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"getter")) return "isOutlined";
            return nullptr;
        case 1:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"getter")) return "isFilled";
            return nullptr;
        case 2:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"fromstring")) return "cFigure::parseColor($)";
            if (!strcmp(propertyname,"tostring")) return ".str()";
            return nullptr;
        case 3:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"fromstring")) return "cFigure::parseColor($)";
            if (!strcmp(propertyname,"tostring")) return ".str()";
            return nullptr;
        case 4:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"enum")) return "omnetpp::cFigure::LineStyle";
            return nullptr;
        case 5:
            if (!strcmp(propertyname,"editable")) return "";
            return nullptr;
        case 6:
            if (!strcmp(propertyname,"editable")) return "";
            return nullptr;
        case 7:
            if (!strcmp(propertyname,"editable")) return "";
            return nullptr;
        case 8:
            if (!strcmp(propertyname,"editable")) return "";
            return nullptr;
        default: return nullptr;
    }
}

int cAbstractShapeFigureDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cAbstractShapeFigure *pp = (cAbstractShapeFigure *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cAbstractShapeFigureDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cAbstractShapeFigure *pp = (cAbstractShapeFigure *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->isOutlined());
        case 1: return bool2string(pp->isFilled());
        case 2: return pp->getLineColor().str();
        case 3: return pp->getFillColor().str();
        case 4: return enum2string(pp->getLineStyle(), "omnetpp::cFigure::LineStyle");
        case 5: return double2string(pp->getLineWidth());
        case 6: return double2string(pp->getLineOpacity());
        case 7: return double2string(pp->getFillOpacity());
        case 8: return bool2string(pp->getZoomLineWidth());
        default: return "";
    }
}

bool cAbstractShapeFigureDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cAbstractShapeFigure *pp = (cAbstractShapeFigure *)object; (void)pp;
    switch (field) {
        case 0: pp->setOutlined(string2bool(value)); return true;
        case 1: pp->setFilled(string2bool(value)); return true;
        case 2: pp->setLineColor(cFigure::parseColor(value)); return true;
        case 3: pp->setFillColor(cFigure::parseColor(value)); return true;
        case 4: pp->setLineStyle((omnetpp::cFigure::LineStyle)string2enum(value, "omnetpp::cFigure::LineStyle")); return true;
        case 5: pp->setLineWidth(string2double(value)); return true;
        case 6: pp->setLineOpacity(string2double(value)); return true;
        case 7: pp->setFillOpacity(string2double(value)); return true;
        case 8: pp->setZoomLineWidth(string2bool(value)); return true;
        default: return false;
    }
}

const char *cAbstractShapeFigureDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 2: return omnetpp::opp_typename(typeid(Color));
        case 3: return omnetpp::opp_typename(typeid(Color));
        default: return nullptr;
    };
}

void *cAbstractShapeFigureDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cAbstractShapeFigure *pp = (cAbstractShapeFigure *)object; (void)pp;
    switch (field) {
        case 2: return (void *)(&pp->getLineColor()); break;
        case 3: return (void *)(&pp->getFillColor()); break;
        default: return nullptr;
    }
}

class cRectangleFigureDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cRectangleFigureDescriptor();
    virtual ~cRectangleFigureDescriptor();

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

Register_ClassDescriptor(cRectangleFigureDescriptor);

cRectangleFigureDescriptor::cRectangleFigureDescriptor() : omnetpp::cClassDescriptor("omnetpp::cRectangleFigure", "omnetpp::cAbstractShapeFigure")
{
    propertynames = nullptr;
}

cRectangleFigureDescriptor::~cRectangleFigureDescriptor()
{
    delete[] propertynames;
}

bool cRectangleFigureDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cRectangleFigure *>(obj)!=nullptr;
}

const char **cRectangleFigureDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cRectangleFigureDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cRectangleFigureDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int cRectangleFigureDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *cRectangleFigureDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "bounds",
        "cornerRx",
        "cornerRy",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int cRectangleFigureDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='b' && strcmp(fieldName, "bounds")==0) return base+0;
    if (fieldName[0]=='c' && strcmp(fieldName, "cornerRx")==0) return base+1;
    if (fieldName[0]=='c' && strcmp(fieldName, "cornerRy")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cRectangleFigureDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "Rectangle",
        "double",
        "double",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **cRectangleFigureDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "editable", "fromstring", "tostring",  nullptr };
            return names;
        }
        case 1: {
            static const char *names[] = { "editable",  nullptr };
            return names;
        }
        case 2: {
            static const char *names[] = { "editable",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cRectangleFigureDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"fromstring")) return "cFigure::parseRectangle($)";
            if (!strcmp(propertyname,"tostring")) return ".str()";
            return nullptr;
        case 1:
            if (!strcmp(propertyname,"editable")) return "";
            return nullptr;
        case 2:
            if (!strcmp(propertyname,"editable")) return "";
            return nullptr;
        default: return nullptr;
    }
}

int cRectangleFigureDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cRectangleFigure *pp = (cRectangleFigure *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cRectangleFigureDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cRectangleFigure *pp = (cRectangleFigure *)object; (void)pp;
    switch (field) {
        case 0: return pp->getBounds().str();
        case 1: return double2string(pp->getCornerRx());
        case 2: return double2string(pp->getCornerRy());
        default: return "";
    }
}

bool cRectangleFigureDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cRectangleFigure *pp = (cRectangleFigure *)object; (void)pp;
    switch (field) {
        case 0: pp->setBounds(cFigure::parseRectangle(value)); return true;
        case 1: pp->setCornerRx(string2double(value)); return true;
        case 2: pp->setCornerRy(string2double(value)); return true;
        default: return false;
    }
}

const char *cRectangleFigureDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(Rectangle));
        default: return nullptr;
    };
}

void *cRectangleFigureDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cRectangleFigure *pp = (cRectangleFigure *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getBounds()); break;
        default: return nullptr;
    }
}

class cOvalFigureDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cOvalFigureDescriptor();
    virtual ~cOvalFigureDescriptor();

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

Register_ClassDescriptor(cOvalFigureDescriptor);

cOvalFigureDescriptor::cOvalFigureDescriptor() : omnetpp::cClassDescriptor("omnetpp::cOvalFigure", "omnetpp::cAbstractShapeFigure")
{
    propertynames = nullptr;
}

cOvalFigureDescriptor::~cOvalFigureDescriptor()
{
    delete[] propertynames;
}

bool cOvalFigureDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cOvalFigure *>(obj)!=nullptr;
}

const char **cOvalFigureDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cOvalFigureDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cOvalFigureDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int cOvalFigureDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *cOvalFigureDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "bounds",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int cOvalFigureDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='b' && strcmp(fieldName, "bounds")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cOvalFigureDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "Rectangle",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **cOvalFigureDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "editable", "fromstring", "tostring",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cOvalFigureDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"fromstring")) return "cFigure::parseRectangle($)";
            if (!strcmp(propertyname,"tostring")) return ".str()";
            return nullptr;
        default: return nullptr;
    }
}

int cOvalFigureDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cOvalFigure *pp = (cOvalFigure *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cOvalFigureDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cOvalFigure *pp = (cOvalFigure *)object; (void)pp;
    switch (field) {
        case 0: return pp->getBounds().str();
        default: return "";
    }
}

bool cOvalFigureDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cOvalFigure *pp = (cOvalFigure *)object; (void)pp;
    switch (field) {
        case 0: pp->setBounds(cFigure::parseRectangle(value)); return true;
        default: return false;
    }
}

const char *cOvalFigureDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(Rectangle));
        default: return nullptr;
    };
}

void *cOvalFigureDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cOvalFigure *pp = (cOvalFigure *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getBounds()); break;
        default: return nullptr;
    }
}

class cPieSliceFigureDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cPieSliceFigureDescriptor();
    virtual ~cPieSliceFigureDescriptor();

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

Register_ClassDescriptor(cPieSliceFigureDescriptor);

cPieSliceFigureDescriptor::cPieSliceFigureDescriptor() : omnetpp::cClassDescriptor("omnetpp::cPieSliceFigure", "omnetpp::cAbstractShapeFigure")
{
    propertynames = nullptr;
}

cPieSliceFigureDescriptor::~cPieSliceFigureDescriptor()
{
    delete[] propertynames;
}

bool cPieSliceFigureDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cPieSliceFigure *>(obj)!=nullptr;
}

const char **cPieSliceFigureDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cPieSliceFigureDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cPieSliceFigureDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int cPieSliceFigureDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *cPieSliceFigureDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "bounds",
        "startAngle",
        "endAngle",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int cPieSliceFigureDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='b' && strcmp(fieldName, "bounds")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "startAngle")==0) return base+1;
    if (fieldName[0]=='e' && strcmp(fieldName, "endAngle")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cPieSliceFigureDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "Rectangle",
        "double",
        "double",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **cPieSliceFigureDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "editable", "fromstring", "tostring",  nullptr };
            return names;
        }
        case 1: {
            static const char *names[] = { "editable",  nullptr };
            return names;
        }
        case 2: {
            static const char *names[] = { "editable",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cPieSliceFigureDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"fromstring")) return "cFigure::parseRectangle($)";
            if (!strcmp(propertyname,"tostring")) return ".str()";
            return nullptr;
        case 1:
            if (!strcmp(propertyname,"editable")) return "";
            return nullptr;
        case 2:
            if (!strcmp(propertyname,"editable")) return "";
            return nullptr;
        default: return nullptr;
    }
}

int cPieSliceFigureDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cPieSliceFigure *pp = (cPieSliceFigure *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cPieSliceFigureDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cPieSliceFigure *pp = (cPieSliceFigure *)object; (void)pp;
    switch (field) {
        case 0: return pp->getBounds().str();
        case 1: return double2string(pp->getStartAngle());
        case 2: return double2string(pp->getEndAngle());
        default: return "";
    }
}

bool cPieSliceFigureDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cPieSliceFigure *pp = (cPieSliceFigure *)object; (void)pp;
    switch (field) {
        case 0: pp->setBounds(cFigure::parseRectangle(value)); return true;
        case 1: pp->setStartAngle(string2double(value)); return true;
        case 2: pp->setEndAngle(string2double(value)); return true;
        default: return false;
    }
}

const char *cPieSliceFigureDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(Rectangle));
        default: return nullptr;
    };
}

void *cPieSliceFigureDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cPieSliceFigure *pp = (cPieSliceFigure *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getBounds()); break;
        default: return nullptr;
    }
}

class cPolygonFigureDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cPolygonFigureDescriptor();
    virtual ~cPolygonFigureDescriptor();

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

Register_ClassDescriptor(cPolygonFigureDescriptor);

cPolygonFigureDescriptor::cPolygonFigureDescriptor() : omnetpp::cClassDescriptor("omnetpp::cPolygonFigure", "omnetpp::cAbstractShapeFigure")
{
    propertynames = nullptr;
}

cPolygonFigureDescriptor::~cPolygonFigureDescriptor()
{
    delete[] propertynames;
}

bool cPolygonFigureDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cPolygonFigure *>(obj)!=nullptr;
}

const char **cPolygonFigureDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cPolygonFigureDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cPolygonFigureDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int cPolygonFigureDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *cPolygonFigureDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "points",
        "smooth",
        "joinStyle",
        "fillRule",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int cPolygonFigureDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "points")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "smooth")==0) return base+1;
    if (fieldName[0]=='j' && strcmp(fieldName, "joinStyle")==0) return base+2;
    if (fieldName[0]=='f' && strcmp(fieldName, "fillRule")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cPolygonFigureDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "Point",
        "bool",
        "int",
        "int",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **cPolygonFigureDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "editable", "fromstring", "getter", "setter", "sizeGetter", "tostring",  nullptr };
            return names;
        }
        case 1: {
            static const char *names[] = { "editable",  nullptr };
            return names;
        }
        case 2: {
            static const char *names[] = { "editable", "enum",  nullptr };
            return names;
        }
        case 3: {
            static const char *names[] = { "editable", "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cPolygonFigureDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"fromstring")) return "cFigure::parsePoint($)";
            if (!strcmp(propertyname,"getter")) return "getPoint";
            if (!strcmp(propertyname,"setter")) return "setPoint";
            if (!strcmp(propertyname,"sizeGetter")) return "getNumPoints";
            if (!strcmp(propertyname,"tostring")) return ".str()";
            return nullptr;
        case 1:
            if (!strcmp(propertyname,"editable")) return "";
            return nullptr;
        case 2:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"enum")) return "omnetpp::cFigure::JoinStyle";
            return nullptr;
        case 3:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"enum")) return "omnetpp::cFigure::FillRule";
            return nullptr;
        default: return nullptr;
    }
}

int cPolygonFigureDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cPolygonFigure *pp = (cPolygonFigure *)object; (void)pp;
    switch (field) {
        case 0: return pp->getNumPoints();
        default: return 0;
    }
}

std::string cPolygonFigureDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cPolygonFigure *pp = (cPolygonFigure *)object; (void)pp;
    switch (field) {
        case 0: return pp->getPoint(i).str();
        case 1: return bool2string(pp->getSmooth());
        case 2: return enum2string(pp->getJoinStyle(), "omnetpp::cFigure::JoinStyle");
        case 3: return enum2string(pp->getFillRule(), "omnetpp::cFigure::FillRule");
        default: return "";
    }
}

bool cPolygonFigureDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cPolygonFigure *pp = (cPolygonFigure *)object; (void)pp;
    switch (field) {
        case 0: pp->setPoint(i,cFigure::parsePoint(value)); return true;
        case 1: pp->setSmooth(string2bool(value)); return true;
        case 2: pp->setJoinStyle((omnetpp::cFigure::JoinStyle)string2enum(value, "omnetpp::cFigure::JoinStyle")); return true;
        case 3: pp->setFillRule((omnetpp::cFigure::FillRule)string2enum(value, "omnetpp::cFigure::FillRule")); return true;
        default: return false;
    }
}

const char *cPolygonFigureDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(Point));
        default: return nullptr;
    };
}

void *cPolygonFigureDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cPolygonFigure *pp = (cPolygonFigure *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getPoint(i)); break;
        default: return nullptr;
    }
}

class cPathFigureDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cPathFigureDescriptor();
    virtual ~cPathFigureDescriptor();

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

Register_ClassDescriptor(cPathFigureDescriptor);

cPathFigureDescriptor::cPathFigureDescriptor() : omnetpp::cClassDescriptor("omnetpp::cPathFigure", "omnetpp::cAbstractShapeFigure")
{
    propertynames = nullptr;
}

cPathFigureDescriptor::~cPathFigureDescriptor()
{
    delete[] propertynames;
}

bool cPathFigureDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cPathFigure *>(obj)!=nullptr;
}

const char **cPathFigureDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cPathFigureDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cPathFigureDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int cPathFigureDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISCOMPOUND | FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *cPathFigureDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "path",
        "offset",
        "joinStyle",
        "capStyle",
        "fillRule",
    };
    return (field>=0 && field<5) ? fieldNames[field] : nullptr;
}

int cPathFigureDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "path")==0) return base+0;
    if (fieldName[0]=='o' && strcmp(fieldName, "offset")==0) return base+1;
    if (fieldName[0]=='j' && strcmp(fieldName, "joinStyle")==0) return base+2;
    if (fieldName[0]=='c' && strcmp(fieldName, "capStyle")==0) return base+3;
    if (fieldName[0]=='f' && strcmp(fieldName, "fillRule")==0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cPathFigureDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "Point",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : nullptr;
}

const char **cPathFigureDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "editable",  nullptr };
            return names;
        }
        case 1: {
            static const char *names[] = { "editable", "fromstring", "tostring",  nullptr };
            return names;
        }
        case 2: {
            static const char *names[] = { "editable", "enum",  nullptr };
            return names;
        }
        case 3: {
            static const char *names[] = { "editable", "enum",  nullptr };
            return names;
        }
        case 4: {
            static const char *names[] = { "editable", "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cPathFigureDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"editable")) return "";
            return nullptr;
        case 1:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"fromstring")) return "cFigure::parsePoint($)";
            if (!strcmp(propertyname,"tostring")) return ".str()";
            return nullptr;
        case 2:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"enum")) return "omnetpp::cFigure::JoinStyle";
            return nullptr;
        case 3:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"enum")) return "omnetpp::cFigure::CapStyle";
            return nullptr;
        case 4:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"enum")) return "omnetpp::cFigure::FillRule";
            return nullptr;
        default: return nullptr;
    }
}

int cPathFigureDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cPathFigure *pp = (cPathFigure *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cPathFigureDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cPathFigure *pp = (cPathFigure *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getPath());
        case 1: return pp->getOffset().str();
        case 2: return enum2string(pp->getJoinStyle(), "omnetpp::cFigure::JoinStyle");
        case 3: return enum2string(pp->getCapStyle(), "omnetpp::cFigure::CapStyle");
        case 4: return enum2string(pp->getFillRule(), "omnetpp::cFigure::FillRule");
        default: return "";
    }
}

bool cPathFigureDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cPathFigure *pp = (cPathFigure *)object; (void)pp;
    switch (field) {
        case 0: pp->setPath((value)); return true;
        case 1: pp->setOffset(cFigure::parsePoint(value)); return true;
        case 2: pp->setJoinStyle((omnetpp::cFigure::JoinStyle)string2enum(value, "omnetpp::cFigure::JoinStyle")); return true;
        case 3: pp->setCapStyle((omnetpp::cFigure::CapStyle)string2enum(value, "omnetpp::cFigure::CapStyle")); return true;
        case 4: pp->setFillRule((omnetpp::cFigure::FillRule)string2enum(value, "omnetpp::cFigure::FillRule")); return true;
        default: return false;
    }
}

const char *cPathFigureDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(Point));
        default: return nullptr;
    };
}

void *cPathFigureDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cPathFigure *pp = (cPathFigure *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getOffset()); break;
        default: return nullptr;
    }
}

class cAbstractTextFigureDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cAbstractTextFigureDescriptor();
    virtual ~cAbstractTextFigureDescriptor();

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

Register_ClassDescriptor(cAbstractTextFigureDescriptor);

cAbstractTextFigureDescriptor::cAbstractTextFigureDescriptor() : omnetpp::cClassDescriptor("omnetpp::cAbstractTextFigure", "omnetpp::cFigure")
{
    propertynames = nullptr;
}

cAbstractTextFigureDescriptor::~cAbstractTextFigureDescriptor()
{
    delete[] propertynames;
}

bool cAbstractTextFigureDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cAbstractTextFigure *>(obj)!=nullptr;
}

const char **cAbstractTextFigureDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cAbstractTextFigureDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cAbstractTextFigureDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int cAbstractTextFigureDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND | FD_ISEDITABLE,
        FD_ISCOMPOUND | FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *cAbstractTextFigureDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "position",
        "anchor",
        "text",
        "font",
        "color",
        "opacity",
    };
    return (field>=0 && field<6) ? fieldNames[field] : nullptr;
}

int cAbstractTextFigureDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "position")==0) return base+0;
    if (fieldName[0]=='a' && strcmp(fieldName, "anchor")==0) return base+1;
    if (fieldName[0]=='t' && strcmp(fieldName, "text")==0) return base+2;
    if (fieldName[0]=='f' && strcmp(fieldName, "font")==0) return base+3;
    if (fieldName[0]=='c' && strcmp(fieldName, "color")==0) return base+4;
    if (fieldName[0]=='o' && strcmp(fieldName, "opacity")==0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cAbstractTextFigureDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "Point",
        "int",
        "string",
        "Font",
        "Color",
        "double",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : nullptr;
}

const char **cAbstractTextFigureDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "editable", "fromstring", "tostring",  nullptr };
            return names;
        }
        case 1: {
            static const char *names[] = { "editable", "enum",  nullptr };
            return names;
        }
        case 2: {
            static const char *names[] = { "editable",  nullptr };
            return names;
        }
        case 3: {
            static const char *names[] = { "editable", "fromstring", "tostring",  nullptr };
            return names;
        }
        case 4: {
            static const char *names[] = { "editable", "fromstring", "tostring",  nullptr };
            return names;
        }
        case 5: {
            static const char *names[] = { "editable",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cAbstractTextFigureDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"fromstring")) return "cFigure::parsePoint($)";
            if (!strcmp(propertyname,"tostring")) return ".str()";
            return nullptr;
        case 1:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"enum")) return "omnetpp::cFigure::Anchor";
            return nullptr;
        case 2:
            if (!strcmp(propertyname,"editable")) return "";
            return nullptr;
        case 3:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"fromstring")) return "cFigure::parseFont($)";
            if (!strcmp(propertyname,"tostring")) return ".str()";
            return nullptr;
        case 4:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"fromstring")) return "cFigure::parseColor($)";
            if (!strcmp(propertyname,"tostring")) return ".str()";
            return nullptr;
        case 5:
            if (!strcmp(propertyname,"editable")) return "";
            return nullptr;
        default: return nullptr;
    }
}

int cAbstractTextFigureDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cAbstractTextFigure *pp = (cAbstractTextFigure *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cAbstractTextFigureDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cAbstractTextFigure *pp = (cAbstractTextFigure *)object; (void)pp;
    switch (field) {
        case 0: return pp->getPosition().str();
        case 1: return enum2string(pp->getAnchor(), "omnetpp::cFigure::Anchor");
        case 2: return oppstring2string(pp->getText());
        case 3: return pp->getFont().str();
        case 4: return pp->getColor().str();
        case 5: return double2string(pp->getOpacity());
        default: return "";
    }
}

bool cAbstractTextFigureDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cAbstractTextFigure *pp = (cAbstractTextFigure *)object; (void)pp;
    switch (field) {
        case 0: pp->setPosition(cFigure::parsePoint(value)); return true;
        case 1: pp->setAnchor((omnetpp::cFigure::Anchor)string2enum(value, "omnetpp::cFigure::Anchor")); return true;
        case 2: pp->setText((value)); return true;
        case 3: pp->setFont(cFigure::parseFont(value)); return true;
        case 4: pp->setColor(cFigure::parseColor(value)); return true;
        case 5: pp->setOpacity(string2double(value)); return true;
        default: return false;
    }
}

const char *cAbstractTextFigureDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(Point));
        case 3: return omnetpp::opp_typename(typeid(Font));
        case 4: return omnetpp::opp_typename(typeid(Color));
        default: return nullptr;
    };
}

void *cAbstractTextFigureDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cAbstractTextFigure *pp = (cAbstractTextFigure *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getPosition()); break;
        case 3: return (void *)(&pp->getFont()); break;
        case 4: return (void *)(&pp->getColor()); break;
        default: return nullptr;
    }
}

class cTextFigureDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cTextFigureDescriptor();
    virtual ~cTextFigureDescriptor();

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

Register_ClassDescriptor(cTextFigureDescriptor);

cTextFigureDescriptor::cTextFigureDescriptor() : omnetpp::cClassDescriptor("omnetpp::cTextFigure", "omnetpp::cAbstractTextFigure")
{
    propertynames = nullptr;
}

cTextFigureDescriptor::~cTextFigureDescriptor()
{
    delete[] propertynames;
}

bool cTextFigureDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cTextFigure *>(obj)!=nullptr;
}

const char **cTextFigureDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cTextFigureDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cTextFigureDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int cTextFigureDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *cTextFigureDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int cTextFigureDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cTextFigureDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **cTextFigureDescriptor::getFieldPropertyNames(int field) const
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

const char *cTextFigureDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cTextFigureDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cTextFigure *pp = (cTextFigure *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cTextFigureDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cTextFigure *pp = (cTextFigure *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cTextFigureDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cTextFigure *pp = (cTextFigure *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cTextFigureDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *cTextFigureDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cTextFigure *pp = (cTextFigure *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cLabelFigureDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cLabelFigureDescriptor();
    virtual ~cLabelFigureDescriptor();

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

Register_ClassDescriptor(cLabelFigureDescriptor);

cLabelFigureDescriptor::cLabelFigureDescriptor() : omnetpp::cClassDescriptor("omnetpp::cLabelFigure", "omnetpp::cAbstractTextFigure")
{
    propertynames = nullptr;
}

cLabelFigureDescriptor::~cLabelFigureDescriptor()
{
    delete[] propertynames;
}

bool cLabelFigureDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cLabelFigure *>(obj)!=nullptr;
}

const char **cLabelFigureDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cLabelFigureDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cLabelFigureDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int cLabelFigureDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *cLabelFigureDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int cLabelFigureDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cLabelFigureDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **cLabelFigureDescriptor::getFieldPropertyNames(int field) const
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

const char *cLabelFigureDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cLabelFigureDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cLabelFigure *pp = (cLabelFigure *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cLabelFigureDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cLabelFigure *pp = (cLabelFigure *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool cLabelFigureDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cLabelFigure *pp = (cLabelFigure *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cLabelFigureDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *cLabelFigureDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cLabelFigure *pp = (cLabelFigure *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cAbstractImageFigureDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cAbstractImageFigureDescriptor();
    virtual ~cAbstractImageFigureDescriptor();

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

Register_ClassDescriptor(cAbstractImageFigureDescriptor);

cAbstractImageFigureDescriptor::cAbstractImageFigureDescriptor() : omnetpp::cClassDescriptor("omnetpp::cAbstractImageFigure", "omnetpp::cFigure")
{
    propertynames = nullptr;
}

cAbstractImageFigureDescriptor::~cAbstractImageFigureDescriptor()
{
    delete[] propertynames;
}

bool cAbstractImageFigureDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cAbstractImageFigure *>(obj)!=nullptr;
}

const char **cAbstractImageFigureDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cAbstractImageFigureDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cAbstractImageFigureDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount() : 8;
}

unsigned int cAbstractImageFigureDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND | FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<8) ? fieldTypeFlags[field] : 0;
}

const char *cAbstractImageFigureDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "position",
        "anchor",
        "width",
        "height",
        "interpolation",
        "opacity",
        "tintColor",
        "tintAmount",
    };
    return (field>=0 && field<8) ? fieldNames[field] : nullptr;
}

int cAbstractImageFigureDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "position")==0) return base+0;
    if (fieldName[0]=='a' && strcmp(fieldName, "anchor")==0) return base+1;
    if (fieldName[0]=='w' && strcmp(fieldName, "width")==0) return base+2;
    if (fieldName[0]=='h' && strcmp(fieldName, "height")==0) return base+3;
    if (fieldName[0]=='i' && strcmp(fieldName, "interpolation")==0) return base+4;
    if (fieldName[0]=='o' && strcmp(fieldName, "opacity")==0) return base+5;
    if (fieldName[0]=='t' && strcmp(fieldName, "tintColor")==0) return base+6;
    if (fieldName[0]=='t' && strcmp(fieldName, "tintAmount")==0) return base+7;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cAbstractImageFigureDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "Point",
        "int",
        "double",
        "double",
        "int",
        "double",
        "Color",
        "double",
    };
    return (field>=0 && field<8) ? fieldTypeStrings[field] : nullptr;
}

const char **cAbstractImageFigureDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "editable", "fromstring", "tostring",  nullptr };
            return names;
        }
        case 1: {
            static const char *names[] = { "editable", "enum",  nullptr };
            return names;
        }
        case 2: {
            static const char *names[] = { "editable",  nullptr };
            return names;
        }
        case 3: {
            static const char *names[] = { "editable",  nullptr };
            return names;
        }
        case 4: {
            static const char *names[] = { "editable", "enum",  nullptr };
            return names;
        }
        case 5: {
            static const char *names[] = { "editable",  nullptr };
            return names;
        }
        case 6: {
            static const char *names[] = { "editable", "fromstring", "tostring",  nullptr };
            return names;
        }
        case 7: {
            static const char *names[] = { "editable",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cAbstractImageFigureDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"fromstring")) return "cFigure::parsePoint($)";
            if (!strcmp(propertyname,"tostring")) return ".str()";
            return nullptr;
        case 1:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"enum")) return "omnetpp::cFigure::Anchor";
            return nullptr;
        case 2:
            if (!strcmp(propertyname,"editable")) return "";
            return nullptr;
        case 3:
            if (!strcmp(propertyname,"editable")) return "";
            return nullptr;
        case 4:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"enum")) return "omnetpp::cFigure::Interpolation";
            return nullptr;
        case 5:
            if (!strcmp(propertyname,"editable")) return "";
            return nullptr;
        case 6:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"fromstring")) return "cFigure::parseColor($)";
            if (!strcmp(propertyname,"tostring")) return ".str()";
            return nullptr;
        case 7:
            if (!strcmp(propertyname,"editable")) return "";
            return nullptr;
        default: return nullptr;
    }
}

int cAbstractImageFigureDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cAbstractImageFigure *pp = (cAbstractImageFigure *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cAbstractImageFigureDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cAbstractImageFigure *pp = (cAbstractImageFigure *)object; (void)pp;
    switch (field) {
        case 0: return pp->getPosition().str();
        case 1: return enum2string(pp->getAnchor(), "omnetpp::cFigure::Anchor");
        case 2: return double2string(pp->getWidth());
        case 3: return double2string(pp->getHeight());
        case 4: return enum2string(pp->getInterpolation(), "omnetpp::cFigure::Interpolation");
        case 5: return double2string(pp->getOpacity());
        case 6: return pp->getTintColor().str();
        case 7: return double2string(pp->getTintAmount());
        default: return "";
    }
}

bool cAbstractImageFigureDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cAbstractImageFigure *pp = (cAbstractImageFigure *)object; (void)pp;
    switch (field) {
        case 0: pp->setPosition(cFigure::parsePoint(value)); return true;
        case 1: pp->setAnchor((omnetpp::cFigure::Anchor)string2enum(value, "omnetpp::cFigure::Anchor")); return true;
        case 2: pp->setWidth(string2double(value)); return true;
        case 3: pp->setHeight(string2double(value)); return true;
        case 4: pp->setInterpolation((omnetpp::cFigure::Interpolation)string2enum(value, "omnetpp::cFigure::Interpolation")); return true;
        case 5: pp->setOpacity(string2double(value)); return true;
        case 6: pp->setTintColor(cFigure::parseColor(value)); return true;
        case 7: pp->setTintAmount(string2double(value)); return true;
        default: return false;
    }
}

const char *cAbstractImageFigureDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(Point));
        case 6: return omnetpp::opp_typename(typeid(Color));
        default: return nullptr;
    };
}

void *cAbstractImageFigureDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cAbstractImageFigure *pp = (cAbstractImageFigure *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getPosition()); break;
        case 6: return (void *)(&pp->getTintColor()); break;
        default: return nullptr;
    }
}

class cImageFigureDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cImageFigureDescriptor();
    virtual ~cImageFigureDescriptor();

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

Register_ClassDescriptor(cImageFigureDescriptor);

cImageFigureDescriptor::cImageFigureDescriptor() : omnetpp::cClassDescriptor("omnetpp::cImageFigure", "omnetpp::cAbstractImageFigure")
{
    propertynames = nullptr;
}

cImageFigureDescriptor::~cImageFigureDescriptor()
{
    delete[] propertynames;
}

bool cImageFigureDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cImageFigure *>(obj)!=nullptr;
}

const char **cImageFigureDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cImageFigureDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cImageFigureDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int cImageFigureDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *cImageFigureDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "imageName",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int cImageFigureDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "imageName")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cImageFigureDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **cImageFigureDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "editable",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cImageFigureDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"editable")) return "";
            return nullptr;
        default: return nullptr;
    }
}

int cImageFigureDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cImageFigure *pp = (cImageFigure *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cImageFigureDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cImageFigure *pp = (cImageFigure *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getImageName());
        default: return "";
    }
}

bool cImageFigureDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cImageFigure *pp = (cImageFigure *)object; (void)pp;
    switch (field) {
        case 0: pp->setImageName((value)); return true;
        default: return false;
    }
}

const char *cImageFigureDescriptor::getFieldStructName(int field) const
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

void *cImageFigureDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cImageFigure *pp = (cImageFigure *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class cPixmapFigureDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cPixmapFigureDescriptor();
    virtual ~cPixmapFigureDescriptor();

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

Register_ClassDescriptor(cPixmapFigureDescriptor);

cPixmapFigureDescriptor::cPixmapFigureDescriptor() : omnetpp::cClassDescriptor("omnetpp::cPixmapFigure", "omnetpp::cAbstractImageFigure")
{
    propertynames = nullptr;
}

cPixmapFigureDescriptor::~cPixmapFigureDescriptor()
{
    delete[] propertynames;
}

bool cPixmapFigureDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cPixmapFigure *>(obj)!=nullptr;
}

const char **cPixmapFigureDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cPixmapFigureDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cPixmapFigureDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int cPixmapFigureDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *cPixmapFigureDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "pixmap",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int cPixmapFigureDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "pixmap")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cPixmapFigureDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "Pixmap",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **cPixmapFigureDescriptor::getFieldPropertyNames(int field) const
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

const char *cPixmapFigureDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int cPixmapFigureDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cPixmapFigure *pp = (cPixmapFigure *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cPixmapFigureDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cPixmapFigure *pp = (cPixmapFigure *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getPixmap(); return out.str();}
        default: return "";
    }
}

bool cPixmapFigureDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cPixmapFigure *pp = (cPixmapFigure *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *cPixmapFigureDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(Pixmap));
        default: return nullptr;
    };
}

void *cPixmapFigureDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cPixmapFigure *pp = (cPixmapFigure *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getPixmap()); break;
        default: return nullptr;
    }
}

class cCanvasDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    cCanvasDescriptor();
    virtual ~cCanvasDescriptor();

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

Register_ClassDescriptor(cCanvasDescriptor);

cCanvasDescriptor::cCanvasDescriptor() : omnetpp::cClassDescriptor("omnetpp::cCanvas", "omnetpp::cOwnedObject")
{
    propertynames = nullptr;
}

cCanvasDescriptor::~cCanvasDescriptor()
{
    delete[] propertynames;
}

bool cCanvasDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<cCanvas *>(obj)!=nullptr;
}

const char **cCanvasDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *cCanvasDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int cCanvasDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int cCanvasDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,
        0,
        FD_ISCOMPOUND | FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *cCanvasDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "rootFigure",
        "allTags",
        "backgroundColor",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int cCanvasDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='r' && strcmp(fieldName, "rootFigure")==0) return base+0;
    if (fieldName[0]=='a' && strcmp(fieldName, "allTags")==0) return base+1;
    if (fieldName[0]=='b' && strcmp(fieldName, "backgroundColor")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *cCanvasDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "cFigure",
        "string",
        "Color",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **cCanvasDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 2: {
            static const char *names[] = { "editable", "fromstring", "tostring",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *cCanvasDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 2:
            if (!strcmp(propertyname,"editable")) return "";
            if (!strcmp(propertyname,"fromstring")) return "cFigure::parseColor($)";
            if (!strcmp(propertyname,"tostring")) return ".str()";
            return nullptr;
        default: return nullptr;
    }
}

int cCanvasDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    cCanvas *pp = (cCanvas *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cCanvasDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    cCanvas *pp = (cCanvas *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getRootFigure(); return out.str();}
        case 1: return oppstring2string(pp->getAllTags());
        case 2: return pp->getBackgroundColor().str();
        default: return "";
    }
}

bool cCanvasDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    cCanvas *pp = (cCanvas *)object; (void)pp;
    switch (field) {
        case 2: pp->setBackgroundColor(cFigure::parseColor(value)); return true;
        default: return false;
    }
}

const char *cCanvasDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(cFigure));
        case 2: return omnetpp::opp_typename(typeid(Color));
        default: return nullptr;
    };
}

void *cCanvasDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    cCanvas *pp = (cCanvas *)object; (void)pp;
    switch (field) {
        case 0: return (void *)static_cast<omnetpp::cObject *>(pp->getRootFigure()); break;
        case 2: return (void *)(&pp->getBackgroundColor()); break;
        default: return nullptr;
    }
}

} // namespace omnetpp

