//==========================================================================
// neddtdvalidatorbase.h -
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


#ifndef __OMNETPP_NEDXML_NEDDTDVALIDATORBASE_H
#define __OMNETPP_NEDXML_NEDDTDVALIDATORBASE_H

#include "nedvalidator.h"

namespace omnetpp {
namespace nedxml {

/**
 * Adds utility methods for DTD validation to NEDValidatorBase.
 *
 * @ingroup Validation
 */
class NEDXML_API NEDDTDValidatorBase : public NEDValidatorBase
{
  protected:
    struct Choice {
        int tags[20]; // array terminated by NED_NULL (increase size if needed)
        char mult;
    };

    // helper function
    void tryCheckChoice(NEDElement *node, NEDElement *&curchild, int tags[], char mult);

    /** @name Utility functions */
    //@{
    void checkSequence(NEDElement *node, int tags[], char mult[]);
    void checkChoice(NEDElement *node, int tags[], char mult);
    void checkSeqOfChoices(NEDElement *node, Choice choices[], int n);
    void checkEmpty(NEDElement *node);
    void checkRequiredAttribute(NEDElement *node, const char *attr);
    void checkEnumeratedAttribute(NEDElement *node, const char *attr, const char *vals[], int n);
    void checkNameAttribute(NEDElement *node, const char *attr);
    void checkCommentAttribute(NEDElement *node, const char *attr);
    //@}
  public:
    NEDDTDValidatorBase(NEDErrorStore *e) : NEDValidatorBase(e) {}
};

} // namespace nedxml
}  // namespace omnetpp


#endif

