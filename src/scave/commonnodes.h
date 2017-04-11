//=========================================================================
//  COMMONNODES.H - part of
//                  OMNeT++/OMNEST
//           Discrete System Simulation in C++
//
//  Author: Andras Varga
//
//=========================================================================

/*--------------------------------------------------------------*
  Copyright (C) 1992-2015 Andras Varga
  Copyright (C) 2006-2015 OpenSim Ltd.

  This file is distributed WITHOUT ANY WARRANTY. See the file
  `license' for details on this and other legal matters.
*--------------------------------------------------------------*/

#ifndef __OMNETPP_SCAVE_COMMONNODES_H
#define __OMNETPP_SCAVE_COMMONNODES_H

#include <string>
#include "common/filereader.h"
#include "node.h"
#include "nodetype.h"

namespace omnetpp {
namespace scave {

#ifdef _MSC_VER
#pragma warning(disable:4355) // 'this' : used in base member initializer list
#endif


/**
 * Base class for one-port producer nodes.
 */
class SCAVE_API SingleSourceNode : public Node
{
    public:
        Port out;
    public:
        SingleSourceNode() : out(this) {}
};


/**
 * Base class for one-port consumer nodes.
 */
class SCAVE_API SingleSinkNode : public Node
{
    public:
        Port in;
    public:
        SingleSinkNode() : in(this) {}
};


/**
 * Base class for processing nodes with one input and one output port.
 */
class SCAVE_API FilterNode : public Node
{
    protected:
        virtual bool isFinished() const override;
    public:
        Port in;
        Port out;
    public:
        FilterNode() : in(this), out(this) {}
};

/**
 * Base class for reading input from file.
 */
class SCAVE_API ReaderNode : public Node
{
    protected:
        std::string filename;
        omnetpp::common::FileReader reader;
    public:
        ReaderNode(const char* filename, size_t bufferSize)
            : filename(filename), reader(filename, bufferSize) {}
        int64_t getFileSize() { return reader.getFileSize(); }
        int64_t getNumReadBytes() { return reader.getNumReadBytes(); }
};

/**
 * NodeType for SingleSourceNode.
 */
class SCAVE_API SingleSourceNodeType : public NodeType
{
    public:
        virtual const char *getCategory() const override {return "single sources";}
        virtual bool isHidden() const override {return true;}
        virtual Port *getPort(Node *node, const char *portname) const override;
};


/**
 * NodeType for SingleSinkNode.
 */
class SCAVE_API SingleSinkNodeType : public NodeType
{
    public:
        virtual const char *getCategory() const override {return "single sinks";}
        virtual bool isHidden() const override {return true;}
        virtual Port *getPort(Node *node, const char *portname) const override;
};


/**
 * NodeType for FilterNode.
 */
class SCAVE_API FilterNodeType : public NodeType
{
    public:
        virtual const char *getCategory() const override {return "filter";}
        virtual bool isHidden() const override {return false;}
        virtual Port *getPort(Node *node, const char *portname) const override;
};

/**
 * NodeType for ReaderNode.
 */
class SCAVE_API ReaderNodeType : public NodeType
{
    public:
        virtual const char *getCategory() const override {return "reader-node";}
        virtual bool isHidden() const override {return true;}
};

} // namespace scave
}  // namespace omnetpp


#endif


