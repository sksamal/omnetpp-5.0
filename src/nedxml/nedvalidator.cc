//==========================================================================
// Part of the OMNeT++/OMNEST Discrete Event Simulation System
//
// Generated from ned.dtd by dtdclassgen.pl
//
//==========================================================================

/*--------------------------------------------------------------*
  Copyright (C) 2002-2015 Andras Varga

  This file is distributed WITHOUT ANY WARRANTY. See the file
  `license' for details on this and other legal matters.
*--------------------------------------------------------------*/

//
// THIS IS A GENERATED FILE, DO NOT EDIT!
//


#include <cstdio>
#include "nederror.h"
#include "nedexception.h"
#include "nedvalidator.h"

namespace omnetpp {
namespace nedxml {

void  NEDValidatorBase::validate(NEDElement *node)
{
    validateElement(node);
    for (NEDElement *child=node->getFirstChild(); child; child=child->getNextSibling())
        validate(child);
}

void  NEDValidatorBase::validateElement(NEDElement *node)
{
    try {
        switch (node->getTagCode()) {
            case NED_FILES: validateElement(static_cast<FilesElement *>(node)); break;
            case NED_NED_FILE: validateElement(static_cast<NedFileElement *>(node)); break;
            case NED_COMMENT: validateElement(static_cast<CommentElement *>(node)); break;
            case NED_PACKAGE: validateElement(static_cast<PackageElement *>(node)); break;
            case NED_IMPORT: validateElement(static_cast<ImportElement *>(node)); break;
            case NED_PROPERTY_DECL: validateElement(static_cast<PropertyDeclElement *>(node)); break;
            case NED_EXTENDS: validateElement(static_cast<ExtendsElement *>(node)); break;
            case NED_INTERFACE_NAME: validateElement(static_cast<InterfaceNameElement *>(node)); break;
            case NED_SIMPLE_MODULE: validateElement(static_cast<SimpleModuleElement *>(node)); break;
            case NED_MODULE_INTERFACE: validateElement(static_cast<ModuleInterfaceElement *>(node)); break;
            case NED_COMPOUND_MODULE: validateElement(static_cast<CompoundModuleElement *>(node)); break;
            case NED_CHANNEL_INTERFACE: validateElement(static_cast<ChannelInterfaceElement *>(node)); break;
            case NED_CHANNEL: validateElement(static_cast<ChannelElement *>(node)); break;
            case NED_PARAMETERS: validateElement(static_cast<ParametersElement *>(node)); break;
            case NED_PARAM: validateElement(static_cast<ParamElement *>(node)); break;
            case NED_PROPERTY: validateElement(static_cast<PropertyElement *>(node)); break;
            case NED_PROPERTY_KEY: validateElement(static_cast<PropertyKeyElement *>(node)); break;
            case NED_GATES: validateElement(static_cast<GatesElement *>(node)); break;
            case NED_GATE: validateElement(static_cast<GateElement *>(node)); break;
            case NED_TYPES: validateElement(static_cast<TypesElement *>(node)); break;
            case NED_SUBMODULES: validateElement(static_cast<SubmodulesElement *>(node)); break;
            case NED_SUBMODULE: validateElement(static_cast<SubmoduleElement *>(node)); break;
            case NED_CONNECTIONS: validateElement(static_cast<ConnectionsElement *>(node)); break;
            case NED_CONNECTION: validateElement(static_cast<ConnectionElement *>(node)); break;
            case NED_CONNECTION_GROUP: validateElement(static_cast<ConnectionGroupElement *>(node)); break;
            case NED_LOOP: validateElement(static_cast<LoopElement *>(node)); break;
            case NED_CONDITION: validateElement(static_cast<ConditionElement *>(node)); break;
            case NED_EXPRESSION: validateElement(static_cast<ExpressionElement *>(node)); break;
            case NED_OPERATOR: validateElement(static_cast<OperatorElement *>(node)); break;
            case NED_FUNCTION: validateElement(static_cast<FunctionElement *>(node)); break;
            case NED_IDENT: validateElement(static_cast<IdentElement *>(node)); break;
            case NED_LITERAL: validateElement(static_cast<LiteralElement *>(node)); break;
            case NED_MSG_FILE: validateElement(static_cast<MsgFileElement *>(node)); break;
            case NED_NAMESPACE: validateElement(static_cast<NamespaceElement *>(node)); break;
            case NED_CPLUSPLUS: validateElement(static_cast<CplusplusElement *>(node)); break;
            case NED_STRUCT_DECL: validateElement(static_cast<StructDeclElement *>(node)); break;
            case NED_CLASS_DECL: validateElement(static_cast<ClassDeclElement *>(node)); break;
            case NED_MESSAGE_DECL: validateElement(static_cast<MessageDeclElement *>(node)); break;
            case NED_PACKET_DECL: validateElement(static_cast<PacketDeclElement *>(node)); break;
            case NED_ENUM_DECL: validateElement(static_cast<EnumDeclElement *>(node)); break;
            case NED_ENUM: validateElement(static_cast<EnumElement *>(node)); break;
            case NED_ENUM_FIELDS: validateElement(static_cast<EnumFieldsElement *>(node)); break;
            case NED_ENUM_FIELD: validateElement(static_cast<EnumFieldElement *>(node)); break;
            case NED_MESSAGE: validateElement(static_cast<MessageElement *>(node)); break;
            case NED_PACKET: validateElement(static_cast<PacketElement *>(node)); break;
            case NED_CLASS: validateElement(static_cast<ClassElement *>(node)); break;
            case NED_STRUCT: validateElement(static_cast<StructElement *>(node)); break;
            case NED_FIELD: validateElement(static_cast<FieldElement *>(node)); break;
            case NED_UNKNOWN: validateElement(static_cast<UnknownElement *>(node)); break;
            default: INTERNAL_ERROR1(node,"validateElement(): unknown tag '%s'", node->getTagName());
        }
    }
    catch (NEDException& e)
    {
        INTERNAL_ERROR1(node,"validateElement(): NEDException: %s", e.what());
    }
}

} // namespace nedxml
}  // namespace omnetpp

