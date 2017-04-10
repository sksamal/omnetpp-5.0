//==========================================================================
//   OPP_STRING.H - part of
//                     OMNeT++/OMNEST
//            Discrete System Simulation in C++
//
//==========================================================================

/*--------------------------------------------------------------*
  Copyright (C) 1992-2015 Andras Varga
  Copyright (C) 2006-2015 OpenSim Ltd.

  This file is distributed WITHOUT ANY WARRANTY. See the file
  `license' for details on this and other legal matters.
*--------------------------------------------------------------*/

#ifndef __OMNETPP_OPP_STRING_H
#define __OMNETPP_OPP_STRING_H

#include <vector>
#include <map>
#include <ostream>
#include "simkerneldefs.h"
#include "simutil.h"

namespace omnetpp {

/**
 * @brief Lightweight string class, used internally in some parts of \opp.
 *
 * In simulation models it is better to use std::string or const char *
 * instead.
 *
 * opp_string has only one data member, a char* pointer. Allocation and
 * deallocation of the contents takes place via opp_strdup() and operator
 * delete.
 *
 * @ingroup Utilities
 */
class SIM_API opp_string
{
  private:
    char *str;

  public:
    /**
     * Constructor.
     */
    opp_string()  {str = nullptr;}

    /**
     * Constructor.
     */
    opp_string(const char *s)  {str = opp_strdup(s);}

    /**
     * Constructor.
     */
    opp_string(const char *s, int n)  {str = new char[n+1]; strncpy(str, s?s:"", n); str[n] = '\0';}

    /**
     * Constructor.
     */
    opp_string(const std::string& s)  {str = opp_strdup(s.c_str());}

    /**
     * Copy constructor.
     */
    opp_string(const opp_string& s)  {str = opp_strdup(s.str);}

    /**
     * Destructor.
     */
    ~opp_string()  {delete [] str;}

    /**
     * Return pointer to the string.
     */
    const char *c_str() const  {return str ? str : "";}

    /**
     * Null (empty) string or not.
     */
    bool empty() const  {return !str || !str[0];}

    /**
     * Returns pointer to the internal buffer where the string is stored.
     * It is allowed to write into the string via this pointer, but the
     * length of the string should not be exceeded.
     */
    char *buffer()  {return str;}

    /**
     * Returns the length of the string.
     */
    int size() const {return str ? strlen(str) : 0;}

    /**
     * Allocates a buffer of the given size.
     */
    char *reserve(unsigned size)  {delete[] str;str=new char[size];return str;}

    /**
     * Deletes the old value and opp_strdup()'s the new value
     * to create the object's own copy.
     */
    const char *operator=(const char *s)  {delete[] str;str=opp_strdup(s);return str;}

    /**
     * Assignment.
     */
    opp_string& operator=(const opp_string& s)  {operator=(s.str); return *this;}

    /**
     * Assignment.
     */
    opp_string& operator=(const std::string& s)  {operator=(s.c_str()); return *this;}

    /**
     * Comparison.
     */
    bool operator<(const opp_string& s) const  {return opp_strcmp(str,s.str) < 0;}

    /**
     * Concatenation
     */
    opp_string& operator+=(const char *s) {return operator=(std::string(str).append(s));}

    /**
     * Concatenation
     */
    opp_string& operator+=(const opp_string& s) {operator+=(s.str); return *this;}

    /**
     * Concatenation
     */
    opp_string& operator+=(const std::string& s) {operator+=(s.c_str()); return *this;}

    /**
     * Concatenation
     */
    opp_string operator+(const char *s) {return opp_string((std::string(str)+s).c_str());}

    /**
     * Concatenation
     */
    opp_string operator+(const opp_string& s) {return operator+(s.c_str());}

    /**
     * Concatenation
     */
    opp_string operator+(const std::string& s) {return operator+(s.c_str());}

};

inline std::ostream& operator<<(std::ostream& out, const opp_string& s)
{
    out << s.c_str(); return out;
}


/**
 * @brief Lightweight string vector, used internally in some parts of \opp.
 *
 * Inheritance is used to "de-templatize" the vector class, because the
 * Windows DLL interface is not really a friend of templated classes.
 *
 * @ingroup Utilities
 */
class SIM_API opp_string_vector : public std::vector<opp_string>
{
  public:
    opp_string_vector() {}
    opp_string_vector(const opp_string_vector& other) : std::vector<opp_string>(other) {}
};


/**
 * @brief Lightweight string-to-string map, used internally in some parts of \opp.
 *
 * Inheritance is used to "de-templatize" the map class, because the
 * Windows DLL interface is not really a friend of templated classes.
 *
 * @ingroup Utilities
 */
class SIM_API opp_string_map : public std::map<opp_string,opp_string>
{
  public:
    opp_string_map() {}
    opp_string_map(const opp_string_map& other) : std::map<opp_string,opp_string>(other) {}
};

}  // namespace omnetpp


#endif


