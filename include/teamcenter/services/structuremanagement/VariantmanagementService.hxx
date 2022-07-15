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

#ifndef TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT_VARIANTMANAGEMENTSERVICE_HXX
#define TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT_VARIANTMANAGEMENTSERVICE_HXX

#include <teamcenter/services/structuremanagement/_2012_09/Variantmanagement.hxx>
#include <teamcenter/services/structuremanagement/_2013_05/Variantmanagement.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/structuremanagement/StructureManagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Structuremanagement
        {
            class VariantmanagementService;

/**
 * This library has operations related to BOM variant functionality. This service has
 * 4 operations
 * <br>
 * <br>
 * <ul>
 * <li type="disc">getBOMVariantConfigOptions
 * </li>
 * <li type="disc">getModularOptionsForBom
 * </li>
 * <li type="disc">createVariantItem
 * </li>
 * <li type="disc">createAndSubstituteVariantItem
 * </li>
 * </ul>
 * <br>
 * <br>
 * Operations '<code>getBOMVariantConfigOptions</code>'  & '<code>getModularOptionsForBom</code>'
 * are<b> </b>internal SOAs, and can be used only by Teamcenter Rich Client. Operations
 * 3 & 4 are published and can be used by any User additional to Teamcenter Rich Client.
 * <br>
 * Operations '<code>getBOMVariantConfigOptions</code>' and '<code>getModularOptionsForBom</code>'
 * can be used for getting Modular variant information defined on <b>BOMLine</b> object(s)
 * and currently applied variant configuration (including Legacy and Modular variants)
 * for <b>BOMLine</b> and its <b>BOMWindow</b>, respectively.
 * <br>
 * Operation '<code>createVariantItem</code>' should be used to create variant <b>Item</b>
 * for <b>BOMLine</b> after applying a variant Configuration.  Operation '<code>createAndSubstituteVariantItem</code>'
 * should be invoked when user wants create new variant Item and then substitute to
 * variant BOMLine.
 * <br>
 * <br>
 * <b>Dependencies:</b>
 * <br>
 * DataManagement
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoastructuremanagementstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoastructuremanagementtypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOASTRUCTUREMANAGEMENTSTRONGMNGD_API VariantmanagementService
    : public Teamcenter::Services::Structuremanagement::_2012_09::Variantmanagement,
             public Teamcenter::Services::Structuremanagement::_2013_05::Variantmanagement
{
public:
    static VariantmanagementService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * This operation will create new variant <b>Item</b> for given <b>BOMLine</b> (also
     * called as 'Generic <b>BOMLine</b>') from a BOM structure (also called as 'Generic
     * Structure') having variability using variants. Addition to creating new variant Item,
     * this is operation will also replace or substitute newly created variant Item Revision
     * in given target <b>BOMLine</b> (also called as 'VI <b>BOMLine</b>') in variant Structure
     * which corresponding to fully configured structure by fixing variability in Generic
     * BOM Structure.
     * <br>
     * <br>
     * Operation also accepts 2 flags <code>'findVIBeforeCreate</code>' used to control
     * if existing variant <b>Item</b> should be searched and used instead of creating new
     * variant <b>Item</b> and <code>'linkVIToGenericItem</code>' to link newly created
     * variant <b>Item</b> to source <b>Item</b> of generic <b>BOMLine</b>.
     * <br>
     * <br>
     * The new variant <b>Item</b> can be created in 2 ways either creating new separate
     * <b>Item</b> or doing "Save-As" operation on generic Item. In case of "Save-As" the
     * parameter <code>'CreateOrSaveAsDescriptor</code>' will provide additional information
     * about which all related objects are carried over to new <b>Item</b> from source generic
     * <b>Item</b>.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation should be used when user has Generic Structure & corresponding created
     * variant Structure and user wants to create <b>Item</b> which is variant for each
     * child BOMLine object and replace in variant Structure.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Product Structure Authoring - The application that allows people to create and manage
     * product structure using the various components such as configuration management;
     * option and variants etc.
     *
     * @param createAndSubstituteVIInput
     *        Consists of set of output structures, an output structure for each input. An output
     *        structure have respective input <code>'genericBOMLine</code>' & <code>'viBOMLine</code>'
     *        and newly created <b>ItemRevision</b> object as <code>'newVariantItemRevision</code>';
     *        along with flag '<code>isExistingVIFound</code>' indicating if <code>'newVariantItemRevision</code>'
     *        is created newly or found existing Item which is variant and used.
     *
     * @return
     *         This operation returns substituted <b>ItemRevision</b>  which is variant and flag
     *         to indicate <b>Item</b> is created newly or being used existing with same variant
     *         Configuration.
     *         <br>
     *         <br>
     *         In case of errors ServiceData will return partial errors. Possible Errors are listed
     *         below.
     *         <br>
     *         <ul>
     *         <li type="disc">48102 Variant Item cannot be created for legacy option.
     *         </li>
     *         <li type="disc">48103 Variant Item options must all have a value defined.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Structuremanagement::_2012_09::Variantmanagement::CreateAndSubsVIResponse createAndSubstituteVariantItem ( const std::vector< Teamcenter::Services::Structuremanagement::_2012_09::Variantmanagement::CreateAndSubsVIInput >& createAndSubstituteVIInput ) = 0;

    /**
     * This operation will create new variant <b>Item</b> for given <b>BOMLine</b> (also
     * called as 'Generic <b>BOMLine</b>') from a BOM structure (also called as 'Generic
     * Structure') having variability using variant Options.
     * <br>
     * <br>
     * Operation also accepts a flag <code>'linkVIToGenericItem</code>' to link newly created
     * variant <b>Item</b> to source Item of 'generic <b>BOMLine</b>'.
     * <br>
     * <br>
     * The new variant <b>Item</b> can be created in 2 ways either by creating new separate
     * <b>Item</b> or doing "Save-As" operation on generic <b>Item</b>. In case of "Save-As"
     * the parameter
     * <br>
     * <code>'CreateOrSaveAsDescriptor</code>' will provide additional information about
     * which all related objects are carried over to new <b>Item</b> from source generic
     * <b>Item</b>.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation should be used when user wants to create new variant <b>Item</b> using
     * generic <b>BOMLine</b> from a generic BOM structure.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Product Structure Authoring - The application that allows people to create and manage
     * product structure using the various components such as configuration management;
     * option and variants etc.
     *
     * @param createVIInputs
     *        List of <code>createVIInput</code> structures
     *
     * @return
     *         It returns newly created variant <b>ItemRevision</b>.
     *         <br>
     *         In case of errors <code>ServiceData</code> will return partial errors. Possible Errors
     *         are listed below.
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">48102 Variant Item cannot be created for legacy option.
     *         </li>
     *         <li type="disc">48103 Variant Item options must all have a value defined.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Structuremanagement::_2012_09::Variantmanagement::CreateVIResponse createVariantItem ( const std::vector< Teamcenter::Services::Structuremanagement::_2012_09::Variantmanagement::CreateVIInput >& createVIInputs ) = 0;

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


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("VariantmanagementService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/structuremanagement/StructureManagement_undef.h>
#endif

