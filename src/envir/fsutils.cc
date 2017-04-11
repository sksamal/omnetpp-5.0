//==========================================================================
//  FSUTILS.CC - part of
//                     OMNeT++/OMNEST
//             Discrete System Simulation in C++
//
//  Author: Andras Varga
//
//==========================================================================

/*--------------------------------------------------------------*
  Copyright (C) 1992-2015 Andras Varga
  Copyright (C) 2006-2015 OpenSim Ltd.

  This file is distributed WITHOUT ANY WARRANTY. See the file
  `license' for details on this and other legal matters.
*--------------------------------------------------------------*/

#include "common/fileutil.h"
#include "omnetpp/onstartup.h"
#include "omnetpp/cexception.h"
#include "omnetpp/platdep/platmisc.h"
#include "fsutils.h"

using namespace omnetpp::common;

namespace omnetpp {
namespace envir {

std::string makeLibFileName(const char *libname, const char *prefix, const char *suffix)
{
    bool hasDir = strchr(libname, '/') != nullptr || strchr(libname, '\\') != nullptr;
    std::string dir, fileNameOnly;
    splitFileName(libname, dir, fileNameOnly);
    bool hasExt = strchr(fileNameOnly.c_str(), '.') != nullptr;

    std::string libFileName;
    if (hasExt)
        libFileName = libname;  // when an exact file name is given, leave it unchanged
    else if (hasDir)
        libFileName = dir + "/" + prefix + fileNameOnly + suffix;
    else
        libFileName = std::string(prefix) + fileNameOnly + suffix;
    return libFileName;
}

static bool opp_loadlibrary(const char *libname)
{
#if HAVE_DLOPEN
    std::string libFileName = makeLibFileName(libname, "lib", SHARED_LIB_SUFFIX);
    if (!dlopen(libFileName.c_str(), RTLD_NOW|RTLD_GLOBAL))
        throw std::runtime_error(std::string("Cannot load library '")+libFileName+"': "+dlerror());
    return true;

#elif defined(_WIN32)
# ifdef __GNUC__
    std::string libFileName = makeLibFileName(libname, "lib", ".dll");  // MinGW
# else
    std::string libFileName = makeLibFileName(libname, "", ".dll");  // Visual C++
# endif
    if (!LoadLibrary((char *)libFileName.c_str()))
        throw std::runtime_error(std::string("Cannot load library '")+libFileName+"': "+opp_getWindowsError(GetLastError()));
    return true;

#else
    throw std::runtime_error(std::string("Cannot load library '")+libname+"': dlopen() syscall not available");
#endif
}

void loadExtensionLibrary(const char *lib)
{
    try {
        opp_loadlibrary(lib);
        CodeFragments::executeAll(CodeFragments::STARTUP);
    }
    catch (std::runtime_error& e) {
        throw cRuntimeError(e.what());
    }
}

}  // namespace envir
}  // namespace omnetpp

