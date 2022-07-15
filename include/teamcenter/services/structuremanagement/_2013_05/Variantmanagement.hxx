/* 
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
 ==================================================
 Copyright 2012
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

 ==================================================

   Auto-generated source from service interface.
                 DO NOT EDIT

 ==================================================
*/

#ifndef TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT__2013_05_VARIANTMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT__2013_05_VARIANTMANAGEMENT_HXX

#include <teamcenter/soa/client/model/BOMLine.hxx>
#include <teamcenter/soa/client/model/BOMWindow.hxx>
#include <teamcenter/soa/client/model/Item.hxx>
#include <teamcenter/soa/client/model/Variant.hxx>
#include <teamcenter/soa/client/model/VariantRule.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/structuremanagement/StructureManagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Structuremanagement
        {
            namespace _2013_05
            {
                class Variantmanagement;

class TCSOASTRUCTUREMANAGEMENTSTRONGMNGD_API Variantmanagement
{
public:

    struct ApplyBOMVariantRulesResponse;
    struct BOMVariantOptionValueEntry;
    struct BOMVariantRuleContents;
    struct BOMVariantRuleOutput;
    struct BOMVariantRulesResponse;
    struct GetBOMVariantRuleInput;
    struct GetVariantExpressionsMatchInfoResponse;
    struct InputBOMLinesSet;
    struct SetBOMVariantRuleData;
    struct SetBOMVariantRulesResponse;
    struct VariantExpressionClauseList;
    struct VariantExpressionsDetails;
    struct VariantOptionValue;

    /**
     * It contains list of variant rules applied on the window.
     */
    struct ApplyBOMVariantRulesResponse
    {
        /**
         * List of  BOMVariantRuleContents object associated with the BOMWidow
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2013_05::Variantmanagement::BOMVariantRuleContents > rules;
        /**
         * Object of service data, that returns partial errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * <b>BOMWindow</b> object on which rules have been applied
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMWindow>  window;
    };

    /**
     * It contains details of option, its description and values associated with that particular
     * option.
     */
    struct BOMVariantOptionValueEntry
    {
        /**
         * <b>Variant</b> object that contains details of option value.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Variant>  option;
        /**
         * <b>Item</b> on which option is set.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Item>  owningItem;
        /**
         * Name of the option associated with <b>Item</b>
         */
        std::string optionName;
        /**
         * Additional information about option
         */
        std::string optionDesc;
        /**
         * List containing options and configuration details
         * <br>
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2013_05::Variantmanagement::VariantOptionValue > variantOptionValue;
    };

    /**
     * BOMVariantRuleContents contains variant rule, the saved variant rules associated
     * with the window,   list of option value details and a boolean flag for constraints
     * evaluation status.
     * <br>
     * 
     * <br>
     * In <b>getBOMVariantRules</b> operation , this structure used as output.
     * <br>
     * <br>
     * In <b>setBOMVariantRule</b> operation, this structure used as input as well as output.
     * As input, it contains details of variant rule, saved variant rule, saved variant
     * rule modification flag and list of options that needs to be set on variant rule.
     * As output, it contains details of variant rule with set option values.
     * <br>
     * <br>
     * In <b>applyBOMVariantRules</b> operation, this structure used as input as well as
     * output. Typically the variantRule, svr, isSVRModified provided as input and  list
     * of BOMVariantOptionValueEntry and isConstraintsEvaluated are part of output.
     * <br>
     * 
     * <br>
     * Constraints (defaults, derived defaults and rule check) will only be evaluated for
     * single variant rule having single option value.
     * <br>
     */
    struct BOMVariantRuleContents
    {
        /**
         * <b>VariantRule</b> with which window has been configured. This cannot be NULL
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::VariantRule>  variantRule;
        /**
         * Saved variant rule with which  window has been configured. This will be NULL if window
         * is not configured with saved variant rule.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  svr;
        /**
         * True, if saved variant rule has been modified.
         */
        bool isSVRModified;
        /**
         * List of options associated with <b>VariantRule</b>
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2013_05::Variantmanagement::BOMVariantOptionValueEntry > bomVariantOptionValueEntry;
        /**
         * True, if default, derived default have been evaluated
         */
        bool isConstraintsEvaluated;
    };

    /**
     * <b>BOMVariantRuleOutput</b> contains window and the list of rule associated with
     * window. It has the identifier to map input variant rule to output variant rule.
     */
    struct BOMVariantRuleOutput
    {
        /**
         * <b>BOMWindow</b> on which rules are set
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMWindow>  window;
        /**
         * List of  BOMVariantRuleContents  objects
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2013_05::Variantmanagement::BOMVariantRuleContents > rules;
        /**
         * Identifier to map input variant rules to output variant rules.
         */
        std::string clientId;
    };

    /**
     * List of varaint rule data associated with window.
     */
    struct BOMVariantRulesResponse
    {
        /**
         * List of  BOMVariantRuleOutput  object
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2013_05::Variantmanagement::BOMVariantRuleOutput > variantRuleData;
        /**
         * Object of service data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * It contains information about window and saved variant rules which user want to add,
     * delete, update or override.
     */
    struct GetBOMVariantRuleInput
    {
        /**
         * <b>BOMWindow</b> object for which variant rule is being requested.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMWindow>  window;
        /**
         * The variant rule for which the contents are requested.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::VariantRule>  variantRule;
        /**
         * List of saved variant rules which user want to add, unset, update or override. It
         * is optional.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > svrs;
        /**
         * unique identifier for each window. Output will have same identifier, to let caller
         * know, which rule list is associated with which window.
         */
        std::string clientId;
        /**
         * This flag indicates different action mode associated to SVRs which includes  add
         * (add new saved variant rule), unset (unset existing saved variant rule), update (update
         * configuration using saved variant rule), override (override configuration using saved
         * variant rule).
         * <br>
         * <br>
         * <i>0</i> &nbsp;&nbsp;&nbsp;&nbsp;Set this value, when you want to get variant rule
         * from window(default value).
         * <br>
         * <i>1</i>  &nbsp;&nbsp;&nbsp;&nbsp;Set this value, when you want to apply or add new
         * saved variant rule in case of multiple rule scenario
         * <br>
         * <i>2 </i> &nbsp;&nbsp;&nbsp;&nbsp;Set this value, when you want to unset existing
         * saved variant rule in case of multiple rule scenario.
         * <br>
         * <i>3</i> &nbsp;&nbsp;&nbsp;&nbsp;Set this mode, if user wants to override existing
         * option value in saved variant rule.
         * <br>
         * <i>4 </i>&nbsp;&nbsp;&nbsp;&nbsp;Set this mode, if user wants to update existing
         * option value in saved variant rule.
         * <br>
         */
        int svrActionMode;
    };

    /**
     * The response of method getVariantExpressionsMatchInfo.
     */
    struct GetVariantExpressionsMatchInfoResponse
    {
        /**
         * The entries in this list corresponds to each input InputBOMLinesSet.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2013_05::Variantmanagement::VariantExpressionsDetails > variantExpressionsDetails;
        /**
         * The partial errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The list of roll up BOMLine objects and non-roll up BOMLine objects.
     */
    struct InputBOMLinesSet
    {
        /**
         * The list of BOMLine objects for which rolled up variant conditions and rolled up
         * clause lists  to be calculated. If this list is empty, then this operation will populate
         * the variant expressions for the nonRollUPBOMLines and their corresponding clause
         * lists in the response.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  > rollUpBOMLines;
        /**
         * The list of BOMLine objects for which occurrence variant conditions and clause lists
         * to be returned. If this list is empty, , then this operation will populate the rolled
         * up variant expressions and corresponding clause lists in the response.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  > nonRollUpBOMLines;
        /**
         * If true, the comparison will be peformed between all the input bomLines i.e. rollUpBOMLines
         * and nonRollUpBOMLines till a mismatch is found.
         */
        bool doCompare;
    };

    /**
     * <b>SetBOMVariantRuleData</b> contains information about window and variant rule that
     * needs to be set on the window. This structure will be used as an input and as an
     * output. Input contains details of  window and BOMVariantRuleContents  that needs
     * to be set on window . Output contains details of BOMVariantRuleContents  having information
     * about option values set on the variant rule.
     */
    struct SetBOMVariantRuleData
    {
        /**
         * <b>BOMWindow</b> object on which variant rules will be set
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMWindow>  window;
        /**
         * A list of BOMVariantRuleContents  object which contain details of Variant Rule and
         * list of options and values.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2013_05::Variantmanagement::BOMVariantRuleContents > rules;
        /**
         * Identifier to map input variant rule to output variant rule
         */
        std::string clientId;
    };

    /**
     * SetBOMVariantRulesResponse object reference.
     */
    struct SetBOMVariantRulesResponse
    {
        /**
         * List of  objects containing setBOMVariantRuleData  object
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2013_05::Variantmanagement::SetBOMVariantRuleData > setBOMVariantRuleData;
        /**
         * Object of service data that that returns partial errors
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Contains clauseList object and corresponding clause list text.
     */
    struct VariantExpressionClauseList
    {
        /**
         * The text representation of the clauseList. If the line does not have the variant
         * condition then this list will be empty.
         */
        std::vector< std::string > clauseListText;
        /**
         * The clauseList object of the VarientExpression. If the line does not have the variant
         * condition then corresponding entry in this list will be null.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  clauseList;
    };

    /**
     * The VariantExpressionsDetails represents response for each input InputBOMLinesSet.
     * It contains clause List and corresponding clause List text for rollUpBOMLines and
     * nonRollUpBOMLines.
     */
    struct VariantExpressionsDetails
    {
        /**
         * The rolled up clause list object and clauseListText for the BOMLine objects in the
         * rollUpBomLines list. Each entry in this list corresponds to one BOMLine in rollUpBomLines
         * list.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2013_05::Variantmanagement::VariantExpressionClauseList > rollUpClauseList;
        /**
         * The clause lists for the BOMLines objects in the nonRollUpBomLines list.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2013_05::Variantmanagement::VariantExpressionClauseList > nonRollUpClauseList;
        /**
         * True if the input doCompare flag is set and any of the BOMLines of the inputBOMLinesSets
         * are different due to variant conditions.
         */
        bool isDifferent;
    };

    /**
     * Details of option values.
     */
    struct VariantOptionValue
    {
        /**
         * Value assigned to option
         */
        std::string value;
        /**
         * Indicates, how value is set. Possible values are
         * <br>
         * <ul>
         * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;<i>Unset</i>  value is unset,
         * </li>
         * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;<i>Unset (potentially derived)</i>  derivable
         * value is unset,
         * </li>
         * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;<i>Derived</i>  value is from derived option
         * value  ,
         * </li>
         * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;<i>Defaulted</i>  value from default option
         * value,
         * </li>
         * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;<i>Set by User</i>  value is set by user,
         * </li>
         * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;<i>Set by Rule</i>  value is set by rule,
         * </li>
         * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;<i>Variant Item</i>  value set by variant
         * item
         * </li>
         * </ul>
         */
        std::string howSet;
        /**
         * It indicates how value is set. It is integer representation of  howSet.
         * <br>
         * Valid values are as follows.
         * <br>
         * <i>0 </i> value is unset,
         * <br>
         * <i>1 </i> derivable value is unset,
         * <br>
         * <i>2 </i> value is from derived option value  ,
         * <br>
         * <i>3 </i> value from default option value,
         * <br>
         * <i>4</i>  value is set by user,
         * <br>
         * <i>5</i>  value is set by rule,
         * <br>
         * <i>8 </i> value set by variant item.
         * <br>
         */
        int howSetInt;
        /**
         * Name of saved variant rule given by user or name of the owningItem
         */
        std::string whereSet;
        /**
         * Position of option value in variant revision
         */
        int index;
        /**
         * If rule is configured with particular option value.
         */
        bool isConfiguredOptionValue;
    };




    /**
     * This operation calculates and returns the rolledup variant expressions and rolledUp
     * clause lists for the input rollUpBomLines. For the nonRolledUpBomLines, BOMLine variant
     * conditions and clause lists will be returned. . If doCompare parameter is set as
     * true, then this operation compares the equivalent lines based on the variant conditions
     * and sets the isDifferent variable accordingly. The lines in input rollUpBomLines,
     * will be compared using the rolled up variants and the lines in the nonRollUpBomLines
     * list will be compared using variant conditions. All the lines in one InputBOMLinesSet
     * will be compared with each other till a difference is found.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Options & Variants - Modular and Legacy - Capability to specify variabilty (options)
     * on a product structure and be able to define multiple variants and solve for a specific
     * configuration.
     *
     * @param inputBOMLinesSets
     *        The list of roll up BOMLine objects and non-roll up BOMLine objects.
     *
     * @return
     *         A list VariantExpressionsDetails, one for each request input and serviceData for
     *         partial errors. The following partial errors may be returned: 1. 214506: An error
     *         has occurred while retrieving the variant expression match information for the input
     *         BOM Line set "%1$". 2. 46217: An error has occurred while calculating the Rollup
     *         Variant Condition for the BOM Line.
     *
     */
    virtual Teamcenter::Services::Structuremanagement::_2013_05::Variantmanagement::GetVariantExpressionsMatchInfoResponse getVariantExpressionsMatchInfo ( const std::vector< Teamcenter::Services::Structuremanagement::_2013_05::Variantmanagement::InputBOMLinesSet >& inputBOMLinesSets ) = 0;

    /**
     * The applyBOMVariantRules operation applies given variant rules to the  window and
     * returns applied variant rule. A list of saved variant rules can be applied to the
     * window. Variant rule that contain options having multiple values can be applied to
     * the window. Output will be the window and list of variant rule has been applied to
     * the window.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation will be used when variant rules needs to be applied on the window.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Product Structure Authoring - The application that allows people to create and manage
     * product structure using the various components such as configuration management;
     * option and variants etc.
     *
     * @param window
     *        <b>BOMWindow</b> object on which variant rules will be applied.
     *
     * @param rules
     *        This input has a list of BOMVariantRuleContents which contain details of variant
     *        rule and list of options and values
     *
     * @return
     *         This operation returns list of  BomVariantRuleContents object which contains details
     *         of option values that is applied to window. If multiple saved variant rules set on
     *         the window or options having multiple values then constraints  (defaults and derived
     *         defaults and rule check) will not be evaluated.
     *
     *
     * @exception ServiceException
     *           This operation may raise a Teamcenter::Soa::Server::ServiceException wrapping
     *           around following Teamcenter errors:
     *           <br>
     *           <ul>
     *           <li type="disc">46001 Invalid input  is received from input structure BomVariantRuleContents&nbsp;&nbsp;&nbsp;&nbsp;
     *           </li>
     *           <li type="disc">214507   Single variant rule cannot be applied if window is in Overlay
     *           mode . Multiple variant rule is expected.
     *           </li>
     *           </ul>
     */
    virtual Teamcenter::Services::Structuremanagement::_2013_05::Variantmanagement::ApplyBOMVariantRulesResponse applyBOMVariantRules ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMWindow>  window,
        const std::vector< Teamcenter::Services::Structuremanagement::_2013_05::Variantmanagement::BOMVariantRuleContents >& rules ) = 0;

    /**
     * This operation takes list of window and its identifier and returns variant rules
     * and saved variant rules associated with the window. As part of input in this operation
     * user can provide saved variant rule along with saved variant rule action mode. This
     * action indicates add, remove, update or override actions related to saved variant
     * rule. There could be multiple variant rules, associated with window. List of these
     * rules will be returned as the output. It also returns list of option and list of
     * values associated with each option.  A flag in the value list indicates, if window
     * is configured with the particular option value.  There could be multiple values associated
     * with a single option and there could be multiple saved variant rules associated with
     * a window.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation should be used when user wants to get variant rules associated with
     * window. User may also use it to set , unset, override or update saved variant rule
     * based on the window mode
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Product Structure Authoring - The application that allows people to create and manage
     * product structure using the various components such as configuration management;
     * option and variants etc.
     *
     * @param variantRuleInput
     *        List of window for which variant rules are being requested
     *
     * @return
     *         List of variant rules associated with the window. There can be single variant rule
     *         or multiple saved variant rules associated with the window.
     *         <br>
     *         <br>
     *
     *
     * @exception ServiceException
     *           This operation may raise a Teamcenter::Soa::Server::ServiceException wrapping
     *           around following Teamcenter errors.
     *           <br>
     *           <ul>
     *           <li type="disc">46001&nbsp;&nbsp;&nbsp;&nbsp; Invalid input is received from input
     *           structure GetBomVariantRuleInput
     *           </li>
     *           <li type="disc">214508   Overlay requires at least two variant rules to be loaded.
     *           You cannot remove input variant rule.
     *           </li>
     *           <li type="disc">214509   Input Variant rule is invalid for the current bom window
     *           mode.
     *           </li>
     *           <li type="disc">214510   For the input svrActionMode, input saved variant rules are
     *           invalid.
     *           </li>
     *           </ul>
     */
    virtual Teamcenter::Services::Structuremanagement::_2013_05::Variantmanagement::BOMVariantRulesResponse getBOMVariantRules ( const std::vector< Teamcenter::Services::Structuremanagement::_2013_05::Variantmanagement::GetBOMVariantRuleInput >& variantRuleInput ) = 0;

    /**
     * This operation set the input variant rule to the window and returns the list of variant
     * rule and respective window.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation should be used when user want to set values of the option on variant
     * rule.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * getBOMVariantRules
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Product Structure Authoring - The application that allows people to create and manage
     * product structure using the various components such as configuration management;
     * option and variants etc.
     *
     * @param setBOMVariantRuleInput
     *        List of input object containing variant rule and window on which rule will be set.
     *
     * @return
     *         This operation returns variant rule and details of option values that is set to window.
     *
     *
     * @exception ServiceException
     *           This operation may raise a Teamcenter::Soa::Server::ServiceException wrapping
     *           around following Teamcenter errors:
     *           <br>
     *           <br>
     *           46001 Invalid  input is received from input structure SetBOMVariantRuleData
     */
    virtual Teamcenter::Services::Structuremanagement::_2013_05::Variantmanagement::SetBOMVariantRulesResponse setBOMVariantRules ( const std::vector< Teamcenter::Services::Structuremanagement::_2013_05::Variantmanagement::SetBOMVariantRuleData >& setBOMVariantRuleInput ) = 0;


protected:
    virtual ~Variantmanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/structuremanagement/StructureManagement_undef.h>
#endif

