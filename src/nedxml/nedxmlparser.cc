//==========================================================================
//  NEDXMLPARSER.CC - part of
//
//                     OMNeT++/OMNEST
//            Discrete System Simulation in C++
//
//==========================================================================

/*--------------------------------------------------------------*
  Copyright (C) 2002-2015 Andras Varga
  Copyright (C) 2006-2015 OpenSim Ltd.

  This file is distributed WITHOUT ANY WARRANTY. See the file
  `license' for details on this and other legal matters.
*--------------------------------------------------------------*/

#include "saxparser.h"
#include "nedsaxhandler.h"
#include "nederror.h"
#include "nedxmlparser.h"

namespace omnetpp {
namespace nedxml {

NEDElement *parseXML(const char *filename, NEDErrorStore *errors)
{
    NEDSAXHandler sh(filename, errors);
    SAXParser parser;

    parser.setHandler(&sh);
    bool ok = parser.parse(filename);
    if (!ok) {
        errors->addError("", "error reading `%s': %s", filename, parser.getErrorMessage());
        return nullptr;
    }
    return sh.getTree();
}

}  // namespace nedxml
}  // namespace omnetpp

