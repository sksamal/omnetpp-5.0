//==========================================================================
//   SAXPARSER_NONE.CC -
//            part of OMNeT++
//
//==========================================================================

/*--------------------------------------------------------------*
  Copyright (C) 2002-2015 Andras Varga
  Copyright (C) 2006-2015 OpenSim Ltd.

  This file is distributed WITHOUT ANY WARRANTY. See the file
  `license' for details on this and other legal matters.
*--------------------------------------------------------------*/

#include <cstring>
#include <cstdio>
#include <cassert>
#include "nederror.h"
#include "saxparser.h"

namespace omnetpp {
namespace nedxml {


SAXParser::SAXParser()
{
    saxhandler = nullptr;
}

void SAXParser::setHandler(SAXHandler *sh)
{
    saxhandler = sh;
    sh->setParser(this);
}

bool SAXParser::parse(const char *filename)
{
    return doParse(filename, nullptr);
}

bool SAXParser::parseContent(const char *content)
{
    return doParse(nullptr, content);
}

bool SAXParser::doParse(const char *filename, const char *content)
{
    strcpy(errortext, "XML input is not supported: this copy of OMNeT++ was "
                      "compiled without an XML parser (libXML or Expat)");
    return false;
}

int SAXParser::getCurrentLineNumber()
{
    return 0;
}

}  // namespace nedxml
}  // namespace omnetpp

