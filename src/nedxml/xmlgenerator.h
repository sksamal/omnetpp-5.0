//==========================================================================
//  XMLGENERATOR.H - part of
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


#ifndef __OMNETPP_NEDXML_XMLGENERATOR_H
#define __OMNETPP_NEDXML_XMLGENERATOR_H


#include <iostream>
#include "nedelements.h"

namespace omnetpp {
namespace nedxml {

/**
 * @brief Simple front-end to NEDXMLGenerator.
 *
 * @ingroup XMLGenerator
 */
NEDXML_API void generateXML(std::ostream& out, NEDElement *tree, bool srcloc, int indentsize = 4);

/**
 * @brief Simple front-end to NEDXMLGenerator.
 *
 * @ingroup XMLGenerator
 */
NEDXML_API std::string generateXML(NEDElement *tree, bool srcloc, int indentsize = 4);

/**
 * @brief Serializes a NED object tree in XML format.
 *
 * @ingroup XMLGenerator
 */
class NEDXML_API NEDXMLGenerator
{
  protected:
    bool printSrcLoc;
    int indentSize;
    virtual void printAttrValue(std::ostream& out, const char *s);
    virtual void doGenerate(std::ostream& out, NEDElement *node, int level);

  public:
    /**
     * Constructor
     */
    NEDXMLGenerator();

    /**
     * Destructor
     */
    virtual ~NEDXMLGenerator();

    /**
     * Enable or disable generation of src-loc attributes in the output XML.
     * src-loc attributes contain filename-line-column information that refers
     * to the original document. For example, if the NEDElement tree was
     * produced by parsing a NED file, src-loc attributes refer to locations
     * in the NED file.
     */
    virtual void setSourceLocationAttributes(bool srcloc);

    /**
     * Set indent size in the output XML.
     */
    virtual void setIndentSize(int indentsize);

    /**
     * Serialize the object tree as XML to the given output stream.
     * The XML declaration will be:
     * <pre>
     * <?xml version="1.0"?>
     * </pre>
     * I.e. unspecified encoding, and no document type will be included.
     */
    virtual void generate(std::ostream& out, NEDElement *tree);

    /**
     * Serialize the object tree into XML, and return the result as string.
     */
    virtual std::string generate(NEDElement *tree);

};

} // namespace nedxml
}  // namespace omnetpp


#endif
