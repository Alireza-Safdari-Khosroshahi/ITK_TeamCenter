// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2012.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.



#ifndef TEAMCENTER_SOA_CLIENT_REVNAMERULE_HXX
#define TEAMCENTER_SOA_CLIENT_REVNAMERULE_HXX

#include <string>
#include <vector>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/client/Chooseable.hxx>



#include <teamcenter/soa/client/SoaClientMngdExports.h>


namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {


/**
 * This class is used to specify the revision naming rules (sequence of IDs) for item revisions.
 * The revision naming rule is made up of three parts, the Initial revisions, Secondary revisions and  revisions.
 * The Initial and Secondary revisions are considered major revisions while the Supplemental revision is
 * for minor revisions. The use of an Initial and Secondary revisions allows different rules to be applied
 * to an Item at different times in the Item's lifecycle. For example the Initial revision rule can be applied
 * to an Item during its design phase, and the Secondary revision rule applied during the production phase.
 * For example an Item may have the following revisions:
 * <pre>
 *
 * 01  Initial (Major) Revision            Design Phase
 * 02  Initial (Major) Revision            Design Phase
 * A   Secondary (Major) Revision          Production Phase
 * A01 Supplemental (Minor) Revision       Production Phase
 * A02 Supplemental (Minor) Revision       Production Phase
 * B   Secondary (Major) Revision          Production Phase
 * </pre>
 *
 * The RevNameRule has starting values for the Initial and Secondary revisions. When performing a
 * Create or Save-As action the client application (or user) can choose between Initial or Secondary starting
 * value to assign to the revision id of the Item. When performing a Revise action the client should use the
 * DataManagementService.getRevNRattachDetails service operation to get the next revision label for the
 * specific item. 
 */
class TCSOACLIENTMNGD_API RevNameRule: public Chooseable
{
public:


    /**
     * Describes the versioning sequence for Initial and Secondary revision rules.
     */
    enum RuleType
    {
        /** Secondary Revision type is not specified. */
        NoSecondaryFormat,
        /** The rule will be made up of numeric characters.*/
        Numeric,
        /** The rule will be made up of alphabetic characters */
        Alphabetic,
        /** The rule will be made up of alphabetic and numeric characters. */
        Alphanumeric
    };

   /**
     * Further describes alphabetic rules.
     */
    enum AlphabeticCase
    {
        /** An alphabetic rule will be made up of both upper and lower case letters. */
        Mixed,
        /** An alphabetic rule will be made up of only lower case letters. */
        Lower,
        /**  An alphabetic rule will be made up of only upper case letters. */
        Upper

    };

    /**
     * Describes the versioning sequence for the Supplemental revision rules.
     * See documentation in the BMIDE for a complete description of these values and how
     * they are combined with the Initial and Secondary values
     */
    enum SupplementalRuleType
    {
        /** */   NoSupplFormat,
        /** */   NumericNoZeroFill,
        /** */   FixedTwoDigitsZeroFill,
        /** */   FixedThreeDigitsZeroFill,
        /** */   FixedFourDigitsZeroFill,
        /** */   CurrentRevLetterNumericNoZeroFill,
        /** */   CurrentRevLetterFixedOneDigit,
        /** */   CurrentRevLetterFixedTwoDigitsZeroFill,
        /** */   NextRevLetterNumericNoZeroFill,
        /** */   NextRevLetterFixedOneDigit,
        /** */   NextRevLetterFixedTwoDigitsZeroFill
     };



    virtual ~RevNameRule();
    /**
     * @return The name of the Revision Naming Rule
     */
    virtual std::string getName()=0;

    /**
     * Returns the starting value of the Initial Revision rule.
     * Example: "A", "1", etc. This is the value that should be assigned to the
     * Item during a Create or Save-As process. If the value is displayed to the user
     * as a choice between Initial and Secondary rules, the value from {@link #getDescription}
     * should also be displayed:
     * <pre>
     *  01, Major Revision Design Phase
     *   A, Major Revision Production Phase
     * </pre>
     *
     * @return The starting value of the Initial Revision rule.
     */
    virtual std::string getStartingRevision()=0;

    /**
     * @return The description the Initial Revision rule.
     * @since %Teamcenter server 10.0
     */
    virtual std::string getDescription ()=0;

    /**
     * @return The type of the Initial Revision rule.
     */
    virtual RuleType getType()=0;



    /**
     * Returns the starting value of the Secondary Revision rule.
     * Example: "A", "1", etc. This is the value that should be assigned to the Item during a
     * Create or Save-As process. If the value is displayed to the user as a choice between
     * Initial and Secondary rules, the value from getSecondaryDescription should also be displayed:
     * <pre>
     * 01, Major Revision Design Phase
     *  A, Major Revision Production Phase
     *</pre>
     *
     * @return The description the Secondary Revision rule.
     * @since %Teamcenter server 10.0
     */
    virtual std::string getSecondaryStartingRevision ()=0;

    /**
     * @return The description the Secondary Revision rule.
     * @since %Teamcenter server 10.0
     */
    virtual std::string getSecondaryDescription ()=0;

    /**
     * @return The type of the Secondary Revision rule.
     * @since %Teamcenter server 10.0
     */
    virtual RuleType getSecondaryType()=0;



    /**
     * True if the skip letters are to be excluded from the revision rule.
     * A list of skip letters is returned from the {@link #getSkipLetters} method.
     *
     * @return    True if the skip letters are to be excluded from the revision rule
     */
    virtual bool exludeSkipLetters()=0;

   /**
     * @return The list of skip letters (IOQSXZ)  to be excluded from the rule (may be empty).
     * @since %Teamcenter server 10.0
     */
    virtual std::string getSkipLetters ()=0;


    /**
     * @return The type of letters used the Initial, Secondary and Supplemental Revision rules.
     * @since %Teamcenter server 10.0
     */
    virtual AlphabeticCase getAlphabeticCase()=0;


    /**
     * @return The type of the Supplemental Revision rule.
     * @since %Teamcenter server 10.0
     */
    virtual SupplementalRuleType getSupplementalType()=0;


    SOA_CLASS_NEW_OPERATORS

protected:
    RevNameRule();

};
}}}//end namespace

#include <teamcenter/soa/client/SoaClientMngdUndef.h>

#endif


