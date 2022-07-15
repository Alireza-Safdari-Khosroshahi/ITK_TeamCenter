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

#ifndef FND0_SERVICES_CONFIGURATORADMIN_VARIANTADMINSERVICE_HXX
#define FND0_SERVICES_CONFIGURATORADMIN_VARIANTADMINSERVICE_HXX

#include <fnd0/services/configuratoradmin/_2013_05/Variantadmin.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <fnd0/services/configuratoradmin/ConfiguratorAdmin_exports.h>

namespace Fnd0
{
    namespace Services
    {
        namespace Configuratoradmin
        {
            class VariantadminService;

/**
 * Service interface to provide operations to manage variant options, assign variants,
 * define defaults and constraints for variants in product.
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libfnd0soaconfiguratoradminstrongmngd.dll
 * </li>
 * <li type="disc">libfnd0soaconfiguratoradmintypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class FND0SOACONFIGURATORADMINSTRONGMNGD_API VariantadminService
    : public Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin
{
public:
    static VariantadminService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * This operation allocates variant option values, or ranges of values, to an <b>ItemRevision</b>,
     * or updates or removes these allocations. When the first value of a variant option
     * family is allocated a declaration for this variant option family is added to the
     * <b>ItemRevision</b> and stays there until explicitly removed with this operation
     * (see parameter <code>actionCode</code> below).
     * <br>
     * The owning <b>Item</b>, sometimes referred to as "Dictionary Item", manages the lifecycle
     * of the variant option data it owns. After creating or updating variant data in the
     * context of a Dictionary Revision it can be allocated to other <b>ItemRevision</b>
     * objects. Allocating variant option data, which is owned by a centrally managed Dictionary
     * Item, can be useful when re-using product data with variant conditions across product
     * boundaries. The term "Product ItemRevision" is sometimes used to refer to the <b>ItemRevision</b>
     * to which variant data is allocated. This could be an <b>ItemRevision</b> of an <b>Item</b>
     * different from the Dictionary Item.
     * <br>
     * The attempt to remove a variant option value or variant option family that is referenced
     * in constraints results an error.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * A user wants to create a new variant option Voltage := { 120; 230; 240; 400 } with
     * the intent to allocate these values to a product <b>ItemRevision</b> representing
     * a washing machine as well as a product <b>ItemRevision</b> representing a dryer so
     * that a common fuse panel assembly can be shared between the two product contexts
     * such that the elements in the assembly can have the same variant conditions. To achieve
     * this, the user calls operation createUpdateVariantOptions to create the new option
     * on a Dictionary Item "APPLIANCE". After that operation <code>allocateVariantOptionValues</code>
     * can be used to allocate (some of) these values from APPLIANCE/A to product ItemRevision
     * WASHER/A as well as to DRYER/A.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createUpdateVariantOptions
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Configuration Management - Capability to configure structured data based on revsion
     * rules; effectivities; Status etc.
     *
     * @param contextRevision
     *        The <b>ItemRevision</b> whose variability is updated in this operation.
     *
     * @param variability
     *        The list of variant option values, or value ranges, to allocate to the <b>ItemRevision</b>
     *        specified by the <code>contextRevision</code> parameter.
     *
     * @param actionCode
     *        Valid values are:
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;<code>ActionCodeValueAllocate</code> : Allocates a discrete
     *        value in a (free-form or fixed value list) family, or allocates a value range in
     *        a (free-form only) family. The additional variability must be compatible with the
     *        existing set of constraint rules
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;<code>ActionCodeValueRemove</code> : Removes previously allocated
     *        variability. The removal must be compatible with the existing set of constraint rules.
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;<code>ActionCodeValueUpdate</code> : Changes properties of
     *        existing variability allocations. Variability allocations can change to a different
     *        value in the same family. If this family supports free-form values the variability
     *        allocation can also change from a discrete value to a range and vice versa. The variability
     *        change must be compatible with the existing set of constraint rules.
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;<code>ActionCodeFamilyRemove</code> : Remove an entire family
     *        from the variability that is allocated to the context revision. The removal must
     *        be compatible with the existing set of constraint rules.
     *        <br>
     *
     * @return
     *         The list of variant option values, or value ranges, that have additionally been allocated
     *         to the <b>ItemRevision</b> specified by the <code>contextRevision</code> parameter.
     *         <br>
     *         This operation may return partial errors in the service data for the following Teamcenter
     *         errors:
     *         <br>
     *         <ul>
     *         <li type="disc">93001 : An internal error has occurred in the "<code>Fnd0ConfiguratorAdmin</code>"
     *         module.
     *         </li>
     *         <li type="disc">93003 : The input context revision is null.
     *         </li>
     *         <li type="disc">93004 : No option family "<code>Familyname</code>" with namespace
     *         "<code>DictionaryNamespace</code>"  can be found.
     *         </li>
     *         <li type="disc">93006 : The input Business Object type name is "<code>typename</code>".
     *         A type name of "<code>typename</code>" or one  of its sub-types is expected.
     *         </li>
     *         <li type="disc">93007 : The variability allocation cannot be changed in the context
     *         of <b>ItemRevision</b> "<code>contextRevision</code>". It can only be changed in
     *         the context of an <b>ItemRevisions</b> that references it.
     *         </li>
     *         <li type="disc">93011 : The variability allocation is referenced by multiple ItemRevisions.
     *         Please use the "Save As" command on this object in the context of one of (one of)
     *         the Item Revision(s) that reference this allocation to make an exclusive copy and
     *         therefore resolve the ambiguity.
     *         </li>
     *         <li type="disc">93012 : Objects of type can be saved-as only when they are referenced
     *         by multiple Item Revisions.
     *         </li>
     *         <li type="disc">94001 : An internal error has occurred in the "<code>Fnd0SoaConfiguratorAdmin</code>"
     *         module.
     *         </li>
     *         <li type="disc">515110 : An instance may not be deleted while referenced by other
     *         instances or class variables. Remove all references to the instance to be deleted.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           This operation may raise a <code>Teamcenter::Soa::Server::ServiceException</code>
     *           wrapping around following Teamcenter errors:
     *           <br>
     *           <ul>
     *           <li type="disc">515024 : The tag given (for <code>contextRevision</code>) is not
     *           a valid tag.
     *           </li>
     *           <li type="disc">515177 : Attempt to access remote/archived (<code>contextRevision</code>)
     *           instance.
     *           </li>
     *           <li type="disc">515001 : You do not have sufficient access rights for the attempted
     *           operation (lock <code>contextRevision</code>  for modify).
     *           </li>
     *           <li type="disc">39000+x : Errors raised in module TCTYPE during property inflation
     *           in the service framework.
     *           </li>
     *           <li type="disc">38000+x : Errors raised in module PROP during property inflation
     *           in the service framework.
     *           </li>
     *           </ul>
     */
    virtual Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::VariabilityAllocationResponse allocateVariantOptionValues ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  contextRevision,
        const std::vector< Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::VariabilityExpression >& variability,
        const AllocateOptionValueActionCode&  actionCode ) = 0;

    /**
     * Service interface <code>VariantAdmin</code> uses 3 different representations for
     * variant expressions:
     * <br>
     * 1.&nbsp;&nbsp;&nbsp;&nbsp;Formula string
     * <br>
     * 2.&nbsp;&nbsp;&nbsp;&nbsp;Sub-expressions
     * <br>
     * 3.&nbsp;&nbsp;&nbsp;&nbsp;Teamcenter Normal Form (TNF)
     * <br>
     * This operation converts from any of these input formats to all of these output formats.
     * The formula string can be formatted to show or hide family name and family namespace.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * A user has received a variant expression in form of a fully qualified configuration
     * formula string from another operation, for example <code>getDerivedDefaultRules</code>
     * might have returned an applicability expression "<code>([ENGINEERING_DICTIONARY]Capacity='512
     * GB' | [MANUFACTURING_DICTIONARY]Height='9 mm') & ([ENGINEERING_DICTIONARY]Capacity='320
     * GB' | [MANUFACTURING_DICTIONARY]Height='7 mm')</code>".
     * <br>
     * In many cases, variant expressions are easier to apprehend in Teamcenter Normal Form
     * ( TNF ). Therefore the user calls operation <code>convertVariantExpressions</code>
     * to convert the expression into the following 2 TNFs:
     * <br>
     * <ul>
     * <li type="disc"><code>[ENGINEERING_DICTIONARY]Capacity='512 GB' & [MANUFACTURING_DICTIONARY]Height='7
     * mm'</code>
     * </li>
     * <li type="disc"><code>[ENGINEERING_DICTIONARY]Capacity='320 GB' & [MANUFACTURING_DICTIONARY]Height='9
     * mm'</code>
     * </li>
     * </ul>
     * <br>
     * In addition the user requests a different formula string format that hides family
     * name and family namespace for ease of reading: <code>('512 GB' | '9 mm') & ('320
     * GB' | '7 mm')</code>
     * <br>
     * Operations in service interface <code>VariantAdmin</code>, for example <code>getDerivedDefaultRules</code>,
     * automatically return <code>VariantExpression</code> structs with a TNF representation
     * unless TNF normalization is suppressed or times out while generating the response
     * structure. In that case operation <code>convertVariantExpressions</code> can be used
     * to explicitly request TNF normalization.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * getVariantCriteria
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Configuration Management - Capability to configure structured data based on revsion
     * rules; effectivities; Status etc.
     *
     * @param contextRevision
     *        The <b>ItemRevision</b> in which context the expressions are converted.
     *
     * @param variantExpressions
     *        The input expressions to convert. Only one of the three formats has to be provided
     *        on input.
     *
     * @param formulaFormat
     *        Specifies the requested format for variant expression formula strings. Valid values
     *        are:
     *        <br>
     *        <code>UseDefaultFormat</code> : The default format is defined by preferences<code>
     *        PSE_show_option_item_prefix</code> and<code> PSE_show_option_family_prefix</code>.
     *        <br>
     *        <code>ShowFamilyAndItem</code> : Include family name and product namespace name in
     *        return formula.
     *        <br>
     *        <code>ShowFamilyHideItem</code> : Include family name but exclude product namespace
     *        name in return formula.
     *        <br>
     *        <code>HideFamilyAndItem</code> : Exclude both family name and product namespace name
     *        in return formula.
     *
     * @return
     *         This operation converts the input configuration expressions to all 3 representations.
     *         The output includes a formula string representation for each expression that is formatted
     *         according to parameter <code>formulaFormat</code>.
     *
     *
     * @exception ServiceException
     *           This operation may raise<code> Teamcenter::Soa::Server::ServiceException</code>
     *           wrapping around following Teamcenter errors:
     *           <br>
     *           <ul>
     *           <li type="disc">515024 : The tag given (for <code>contextRevision</code>) is not
     *           a valid tag
     *           </li>
     *           <li type="disc">515177 : Attempt to access remote/archived (<code>contextRevision</code>)
     *           instance
     *           </li>
     *           <li type="disc">515001 : You do not have sufficient access rights for the attempted
     *           operation (load <code>contextRevision</code>)
     *           </li>
     *           <li type="disc">39000+x : Errors raised in module TCTYPE during property inflation
     *           in the service framework
     *           </li>
     *           <li type="disc">38000+x : Errors raised in module PROP  during property inflation
     *           in the service framework
     *           </li>
     *           <li type="disc">92001 : An internal error has occurred in the <code>Fnd0SoaConfigFilterCriteria</code>
     *           module
     *           </li>
     *           <li type="disc">256000 : An internal configurator error occurred.
     *           </li>
     *           <li type="disc">256001 : A general configurator error occurred.
     *           </li>
     *           <li type="disc">256002 : The following product is invalid: [<i>DictionaryNamespace</i>]<i>FamilyName</i>
     *           (Context: <i>info</i>).
     *           </li>
     *           <li type="disc">256003 : The following feature value is invalid: [<i>DictionaryNamespace</i>]<i>FamilyName</i>
     *           (Context: <i>info</i>).
     *           </li>
     *           <li type="disc">256004 : The following feature family is invalid: [<i>DictionaryNamespace</i>]<i>FamilyName</i>
     *           (Context: <i>info</i>).
     *           </li>
     *           <li type="disc">256005 : An invalid feature combination was found (Context: <i>info</i>).
     *           </li>
     *           <li type="disc">256006 : An invalid product configuration was found (Context: <i>info</i>).
     *           </li>
     *           <li type="disc">256007 : An invalid expression was found (Context: <i>info</i>).
     *           </li>
     *           <li type="disc">256008 : The following Boolean operator is invalid: <i>opcode</i>
     *           (Context: <i>info</i>).
     *           </li>
     *           <li type="disc">256009 : An invalid effectivity date was found (Context: <i>info</i>).
     *           </li>
     *           <li type="disc">256010 : A time-out occurred (Context: <i>info</i>).
     *           </li>
     *           <li type="disc">256011 : A resource is not available (Context: <i>info</i>).
     *           </li>
     *           <li type="disc">256012 : The following <i>function</i>ality is not implemented: function
     *           (Version: <i>TcVersion</i>).
     *           </li>
     *           <li type="disc">256013 : A configurator implementation specific error occurred (Context:
     *           <i>info</i>).
     *           </li>
     *           <li type="disc">256014 : The effectivity expression contains unmatched quote at position<i>
     *           number</i>.
     *           </li>
     *           <li type="disc">256015 : The effectivity expression contains unmatched bracket at
     *           position <i>number</i>.
     *           </li>
     *           <li type="disc">256016 : An unexpected token '<i>text</i>' was found at position
     *           <i>number</i>.
     *           </li>
     *           <li type="disc">256017 : The entry '<i>text</i>' was found at position <i>number</i>
     *           when an option value was expected.
     *           </li>
     *           <li type="disc">256018 : The token '<i>text</i>' is missing after '<i>text</i>' at
     *           position <i>number</i>.
     *           </li>
     *           <li type="disc">256019 : The effectivity expression adaptor does not support text
     *           used at position <i>number</i>.
     *           </li>
     *           <li type="disc">256020 : The XML tag '<i>text</i>' has no text value.
     *           </li>
     *           <li type="disc">256021 : The string '<i>formula</i>' cannot be converted into an
     *           expression.
     *           </li>
     *           <li type="disc">256022 : The operator code '<i>opcode</i>' in token at position <i>number</i>
     *           is unknown.
     *           </li>
     *           <li type="disc">256023 : The effectivity value '<i>text</i>' in token at position
     *           <i>number</i> is unknown.256024&nbsp;&nbsp;&nbsp;&nbsp;The effectivity family '<i>text</i>'
     *           in token at position <i>number</i> is unknown.
     *           </li>
     *           <li type="disc">256025 : An ambiguous option value name '<i>FamilyName</i>' in namespace
     *           '<i>DictionaryNamespace</i>' in token at position <i>number</i> was found: <i>text</i>.
     *           </li>
     *           <li type="disc">256026 : An ambiguous option family name '<i>FamilyName</i>' in token
     *           at position <i>number</i> was found: '<i>text</i>'.
     *           </li>
     *           <li type="disc">256027 : The option namespace '<i>DictionaryNamespace</i>' in token
     *           at position <i>number</i> is invalid.
     *           </li>
     *           <li type="disc">256028 : The effectivity family '<i>FamilyName</i>' in token at position
     *           <i>number</i> is invalid.
     *           </li>
     *           <li type="disc">256029 : The effectivity option value '<i>text</i>' for family '<i>FamilyName</i>'
     *           in token at position <i>number</i> is invalid.
     *           </li>
     *           <li type="disc">256030 : The effectivity option value '<i>text</i>' for family '<i>FamilyName</i>'
     *           in token at position <i>number</i> is invalid: its value is not numeric.
     *           </li>
     *           <li type="disc">256031 : The effectivity option value '<i>text</i>' for family '<i>FamilyName</i>'
     *           in token at position <i>number</i> is invalid. The value unit of measure '<i>text</i>'
     *           does not match the family unit of measure '<i>text</i>'.
     *           </li>
     *           <li type="disc">256032 : The option / family / family namespace combination '<i>text</i>'
     *           / '<i>FamilyName</i>' / '<i>DictionaryNamespace</i>' in token at position <i>number</i>
     *           is invalid.
     *           </li>
     *           <li type="disc">256033 : The family '<i>FamilyName</i>' for option / family namespace
     *           combination '<i>text</i>' / '<i>DictionaryNamespace</i>' in token at position <i>number</i>
     *           is invalid.
     *           </li>
     *           <li type="disc">256034 : There is no option value in token at position <i>number</i>.
     *           </li>
     *           <li type="disc">256035 : The effectivity option value '<i>text</i>' for family '<i>FamilyName</i>'
     *           in token at position <i>number</i> is invalid. The value is not a valid date.
     *           </li>
     *           </ul>
     */
    virtual Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::VariantExpressionResponse convertVariantExpressions ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  contextRevision,
        const std::vector< Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::VariantExpression >& variantExpressions,
        const FormulaFormat&  formulaFormat ) = 0;

    /**
     * This operation creates, updates, or deletes a set of 'exclude' and / or 'include'
     * constraint rules for a given context <b>ItemRevisio</b>n according to parameter <code>actionCode</code>.
     * Configuration criteria that either match exclude constraints, or don't satisfy include
     * constraints, with sufficient severity (for example: "error") will fail criteria validation.
     * Configuration criteria that satisfy include constraints are modified according to
     * the include rule criteria during criteria validation.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Exclude rule use case:</b>
     * <br>
     * A product configuration admin user wants to establish an imperative rule that for
     * a given product model the set of interior colours is limited to "Anthracite", "Umbra",
     * or "Basalt" whenever exterior colour "Black" is chosen. All other interior colours
     * for example: "Pearl" or "Silver" should return a validation error.
     * <br>
     * The rule can be created as an exclude rule with <code>productFamilyCondition="Model=M1",
     * applicabilityCondition="Colour_Ext=Black", constraintCondition="Colour_Int!=Anthracite
     * & Colour_Int!=Umbra & Colour_Int!=Basalt", and severity=ConstraintSeverityError.</code>
     * <br>
     * Configuration criteria "Model<code>=M1 & Colour_Ext=Black & Colour_Int!=Pearl</code>"
     * successfully pass the first rule when validating the criteria with <code>Fnd0::Soa::ConfigFilterCriteria::_2013_05::VariantManagement::getVariantCriteria</code>.
     * At the end of passing the rule the criteria remain unmodified.
     * <br>
     * <b>
     * <br>
     * Include Rule Usecase:</b>
     * <br>
     * A product configuration admin user wants to establish an imperative rule that for
     * a given product model the set of interior colours is limited to "Anthracite", "Umbra",
     * or "Basalt" whenever exterior colour "Black" is chosen. In addition a rule should
     * be created for that product model that selects interior colour "Anthracite" if no
     * specific colour has been selected yet. Otherwise a warning "Please obtain approval
     * for interior colour" shall be displayed.
     * <br>
     * The first rule can be created as an include rule with <code>productFamilyCondition="Model=M1",
     * applicabilityCondition="Colour_Ext=Black", constraintCondition="Colour_Int=Anthracite
     * | Colour_Int=Umbra | Colour_Int=Basalt", and severity=ConstraintSeverityError.</code>
     * <br>
     * The second rule can be created as an include rule with <code>productFamilyCondition="Model=M1",
     * applicabilityCondition="Colour_Ext=Black", constraintCondition="Colour_Int=Anthracite",
     * and severity=ConstraintSeverityWarning.</code>
     * <br>
     * Configuration criteria "<code>Model=M1 & Colour_Ext=Black & Colour_Int!=Pearl</code>"
     * successfully pass the first rule when validating the criteria with <code>Fnd0::Soa::ConfigFilterCriteria::_2013_05::VariantManagement::getVariantCriteria</code>.
     * At the end of passing the first rule the criteria are refined to "<code>Model=M1
     * & Colour_Ext=Black & Colour_Int!=Pearl & (Colour_Int=Anthracite | Colour_Int=Umbra
     * | Colour_Int=Basalt)</code>", which is equivalent to "<code>Model=M1 & Colour_Ext=Black
     * & (Colour_Int=Anthracite | Colour_Int=Umbra | Colour_Int=Basalt)</code>", which then
     * also successfully passes the second rule without returning a warning. After passing
     * the second rule the criteria are further refined to "<code>Model=M1 & Colour_Ext=Black
     * & (Colour_Int=Anthracite | Colour_Int=Umbra | Colour_Int=Basalt) & Colour_Int=Anthracite</code>"
     * which is equivalent to "<code>Model=M1 & Colour_Ext=Black & Colour_Int=Anthracite</code>".
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createUpdateVariantOptions
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Configuration Management - Capability to configure structured data based on revsion
     * rules; effectivities; Status etc.
     *
     * @param contextRevision
     *        The <b>ItemRevision</b> whose constraint rules are to be created or updated in this
     *        operation.
     *
     * @param constraintRules
     *        A list of constraint rules each defining either an inclusive or exclusive constraint.
     *
     * @param actionCode
     *        Specifies the constraint rule action to perform.
     *        <br>
     *        Valid values are:
     *        <br>
     *        <ul>
     *        <li type="disc"><code>ActionCodeAdd</code> : Create new constraint rule
     *        </li>
     *        <li type="disc"><code>ActionCodeUpdate</code> : Update an existing constraint rule
     *        </li>
     *        <li type="disc"><code>ActionCodeRemove</code> : Create new constraint rule
     *        </li>
     *        </ul>
     *
     * @return
     *         This operation returns created or modified exclude constraint rule (<b>Fnd0ExcludeConstraintRule</b>)
     *         or include constraint rule (<b>Fnd0IncludeConstraintRule</b> ) objects. Deleted exclude
     *         or include constraint rule objects are reported in the service data of this operation.
     *         <br>
     *         This operation may return partial errors in the service data for the following Teamcenter
     *         errors:
     *         <br>
     *         <ul>
     *         <li type="disc">94001 : An internal error has occurred in the "<code>Fnd0SoaConfiguratorAdmin</code>"
     *         module.
     *         </li>
     *         <li type="disc">94002 : An error occurred while processing a previous element in
     *         the operation input causing this operation input to be skipped.
     *         </li>
     *         <li type="disc">94005 : The VariantOptionValue structure must contain either [<code>variant</code>]
     *         or [<code>namespaceItem, namespaceRevision, familyName</code>].
     *         </li>
     *         <li type="disc">94006 : A duplicate value "<code>number</code>" was found.
     *         </li>
     *         <li type="disc">93001 : An internal error has occurred in the "<code>Fnd0ConfiguratorAdmin</code>"
     *         module.
     *         </li>
     *         <li type="disc">93003 : The input context revision is null.
     *         </li>
     *         <li type="disc">93006 : The input Business Object type name is "<code>typename</code>".
     *         A type name of "<code>typename</code>" or one of its sub-types is expected.
     *         </li>
     *         <li type="disc">93008 : The options "<code>FamilyNameList</code>" are not allocated
     *         for the context <b>ItemRevision</b> "<code>contextRevision</code>". Please allocate
     *         the options to the context <b>ItemRevision</b> and try again.
     *         </li>
     *         <li type="disc">93009 : The sequence number cannot be less than -1.
     *         </li>
     *         <li type="disc">39014 : The business object type for the constraint rule is not known.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           This operation may raise a <code>Teamcenter::Soa::Server::ServiceExceptio</code>n
     *           wrapping around following Teamcenter errors:
     *           <br>
     *           <ul>
     *           <li type="disc">515024 : The tag given (for <code>contextRevision</code>) is not
     *           a valid tag.
     *           </li>
     *           <li type="disc">515177 : Attempt to access remote/archived (<code>contextRevision</code>)
     *           instance.
     *           </li>
     *           <li type="disc">515001 : You do not have sufficient access rights for the attempted
     *           operation (lock <code>contextRevision</code> for modify).
     *           </li>
     *           <li type="disc">39000+x : Errors raised in module TCTYPE during property inflation
     *           in the service framework.
     *           </li>
     *           <li type="disc">38000+x : Errors raised in module PROP  during property inflation
     *           in the service framework.
     *           </li>
     *           </ul>
     */
    virtual Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::ConstraintRuleResponse createUpdateConstraintRules ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  contextRevision,
        const std::vector< Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::ConstraintRuleExpression >& constraintRules,
        const ActionCode&  actionCode ) = 0;

    /**
     * This operation creates, updates, or deletes <b>Fnd0DerivedDefaultRule</b> objects
     * for given context <b>ItemRevision</b>, as indicated by parameter <code>actionCode</code>.
     * <br>
     * When validating variant configuration criteria, derived default rules are evaluated
     * after fixed defaults. Default rules are evaluated by sequence number. Their evaluation
     * is skipped if the result would create unsatisfiable criteria. Default rules refine
     * variant configuration criteria, i.e. they narrow down the input criteria, unless
     * that would result in criteria equivalent to the Boolean constant FALSE. They never
     * broaden the input criteria.
     * <br>
     * When deleting an existing default rule the input is expected to specify the existing
     * business object to delete. When updating an existing default rule the input is expected
     * to also specify the new default assignment. When creating a new default rule the
     * input is expected to provide the business object type for the new rule object and
     * to specify the new default assignment.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * An application wants to create a derived default rule that for a given product model
     * the set of interior colors is defaulted to "Anthracite", or "Umbra" whenever exterior
     * color "Black" is chosen.
     * <br>
     * The rule can be created as a derived default rule with productFamilyCondition=<code>"Model=M1",
     * applicabilityCondition="Colour_Ext=Black", defaultAssignment="Colour_Int=Anthracite
     * | Colour_Int=Umbra</code>".
     * <br>
     * Applying this default rule with operation <code>Fnd0::Soa::ConfigFilterCriteria::_2013_05::VariantManagement::getVariantCriteria</code>
     * returns the following results:
     * <br>
     * <ul>
     * <li type="disc"><b>Input Criteria:</b> <code>Model=M1 & Color_Ext=Black</code> <b>Output
     * Criteria:</b> <code>Model=M1 & Color_Ext=Black & (Colour_Int=Anthracite | Colour_Int=Umbra)</code>
     * </li>
     * <li type="disc"><b>Input Criteria:</b> <code>Model=M1 & Color_Ext=Black & (Colour_Int=Anthracite
     * | Colour_Int=Basalt | Colour_Int=Umbra)</code> <b>Output Criteria:</b> <code>Model=M1
     * & Color_Ext=Black & (Colour_Int=Anthracite | Colour_Int=Umbra)</code>
     * </li>
     * <li type="disc"><b>Input Criteria:</b><code> Model=M1 & Color_Ext=Black & Color_Int!=
     * Quartz</code> <b>Output Criteria:</b> <code>Model=M1 & Color_Ext=Black & (Colour_Int=Anthracite
     * | Colour_Int=Umbra)</code>
     * </li>
     * <li type="disc"><b>Input Criteria:</b><code> Model=M1 & Color_Ext=Black & Color_Int=
     * Anthracite</code>  <b>Output Criteria:</b> <code>Model=M1 & Color_Ext=Black & Color_Int=
     * Anthracite</code>
     * </li>
     * <li type="disc"><b>Input Criteria:</b> <code>Model=M1 & Color_Ext=Black & Color_Int=
     * Quartz</code>  <b>Output Criteria:</b> <code>Model=M1 & Color_Ext=Black & Color_Int=
     * Quartz</code>
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createUpdateVariantOptions, getAllocatedVariantOptionValues
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Configuration Management - Capability to configure structured data based on revsion
     * rules; effectivities; Status etc.
     *
     * @param contextRevision
     *        The <b>ItemRevision</b> whose default rules are to be created or updated in this
     *        operation.
     *
     * @param defaultRules
     *        A list of <code>DefaultRuleExpression</code> structures each defining a default rule
     *        for a given variant option family.
     *
     * @param actionCode
     *        Enumeration <code>ActionCode</code> value which drives behavior of this operation
     *        and accordingly other parameters are interpreted. It can have following values:
     *        <br>
     *        <ul>
     *        <li type="disc">ActionCodeAdd : Create new default rule
     *        </li>
     *        <li type="disc">ActionCodeUpdate : Update an existing default rule
     *        </li>
     *        <li type="disc">ActionCodeRemove : Remove an existing default rule
     *        </li>
     *        </ul>
     *
     * @return
     *         This operation returns created or update <b>Fnd0DerivedDefaultRule</b> objects. Deleted
     *         <b>Fnd0DerivedDefaultRule</b> objects are reported in the service data of this operation.
     *         <br>
     *         This operation may return partial errors in the service data for the following Teamcenter
     *         errors:
     *         <br>
     *         <ul>
     *         <li type="disc">94001 : An internal error has occurred in then "<code>Fnd0SoaConfiguratorAdmin</code>"
     *         module.
     *         </li>
     *         <li type="disc">94002 : An error occurred while processing a previous element in
     *         the operation input causing this operation input to be skipped.
     *         </li>
     *         <li type="disc">94003 : The variability expression must not be null for default rules.
     *         </li>
     *         <li type="disc">94005 : The VariantOptionValue structure must either specify a [<code>variant</code>]
     *         member, or a [<code>namespaceItem, namespaceRevision, familyName</code>] tupel.
     *         </li>
     *         <li type="disc">94006 : A duplicate value "<code>number</code>" was found.
     *         </li>
     *         <li type="disc">93001 : An internal error has occurred in the "<code>Fnd0ConfiguratorAdmin</code>"
     *         module.
     *         </li>
     *         <li type="disc">93003 : The input context revision is null.
     *         </li>
     *         <li type="disc">93006 : The input business object type name is "<code>typename</code>"
     *         A type name of "<code>typename</code>" or one of its sub-types is expected.
     *         </li>
     *         <li type="disc">93008 : The options "<code>FamilyNameList</code>" are not allocated
     *         for the context <b>ItemRevision</b> "<code>contextRevision</code>". Please allocate
     *         the options for the context revision and try again.
     *         </li>
     *         <li type="disc">93009 : The sequence number cannot be less than -1.
     *         </li>
     *         <li type="disc">93013 : No default value supplied: a Fixed or Derived Default must
     *         set a specific option value.
     *         </li>
     *         <li type="disc">39014 : The business object type for the new default rule is not
     *         known.
     *         </li>
     *         <li type="disc">264003 : An invalid operation code was found: <code>opcode</code>.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           This operation may raise a<code> Teamcenter::Soa::Server::ServiceException </code>wrapping
     *           around following Teamcenter errors:
     *           <br>
     *           <ul>
     *           <li type="disc">515024 : The tag given (for <code>contextRevision</code>) is not
     *           a valid tag.
     *           </li>
     *           <li type="disc">515177 : Attempt to access remote/archived (<code>contextRevision</code>)
     *           instance
     *           </li>
     *           <li type="disc">515001 : You do not have sufficient access rights for the attempted
     *           operation (lock <code>contextRevision</code> for modify).
     *           </li>
     *           <li type="disc">39000+x : Errors raised in module TCTYPE during property inflation
     *           in the service framework.
     *           </li>
     *           <li type="disc">38000+x : Errors raised in module PROP during property inflation
     *           in the service framework.
     *           </li>
     *           </ul>
     */
    virtual Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::DerivedDefaultRuleResponse createUpdateDerivedDefaultRules ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  contextRevision,
        const std::vector< Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::DerivedDefaultRuleExpression >& defaultRules,
        const ActionCode&  actionCode ) = 0;

    /**
     * This operation creates, updates, or deletes <b>Fnd0FixedDefaultRule</b> objects for
     * given context <b>ItemRevision</b>, as indicated by parameter <code>actionCode</code>.
     * <br>
     * When validating variant configuration criteria, fixed default rules are evaluated
     * before derived defaults. Default rules are evaluated by sequence number. Their evaluation
     * is skipped if the result would create unsatisfiable criteria. Default rules refine
     * variant configuration criteria, i.e. they narrow down the input criteria, unless
     * that would result in criteria equivalent to the Boolean constant FALSE. They never
     * broaden the input criteria.
     * <br>
     * When deleting an existing default rule the input is expected to specify the existing
     * business object to delete. When updating an existing default rule the input is expected
     * to also specify the new default assignment. When creating a new default rule the
     * input is expected to provide the business object type for the new rule object and
     * to specify the new default assignment.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * An application wants to create a default rule that selects interior color 'Pearl'
     * or 'Cream' by default. This can be achieved by creating a fixed default rule with
     * <code>defaultAssignment="Color_Int=Pearl | Color_Int=Cream"</code>.
     * <br>
     * Applying this default rule with operation <code>Fnd0::Soa::ConfigFilterCriteria::_2013_05::VariantManagement::getVariantCriteria</code>
     * returns the following results:
     * <br>
     * <ul>
     * <li type="disc"><b>Input criteria :</b> Color_Ext=Anthracite <b>Output criteria :</b>
     * Color_Ext=Anthracite & (Color_Int=Pearl | Color_Int=Cream)
     * </li>
     * <li type="disc"><b>Input criteria :</b> Color_Int=Pearl | Color_Int=Cream | Color_Int=Papyrus
     * <b>Output criteria :</b> Color_Int=Pearl | Color_Int=Cream
     * </li>
     * <li type="disc"><b>Input criteria :</b> Color_Int!=Papyrus <b>Output criteria :</b>
     * Color_Int=Pearl | Color_Int=Cream
     * </li>
     * <li type="disc"><b>Input criteria :</b> Color_Int=Cream <b>Output criteria :</b>
     * Color_Int=Cream
     * </li>
     * <li type="disc"><b>Input criteria :</b> Color_Int=Papyrus <b>Output criteria : </b>Color_Int=Papyrus
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createUpdateVariantOptions, getAllocatedVariantOptionValues
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Configuration Management - Capability to configure structured data based on revsion
     * rules; effectivities; Status etc.
     *
     * @param contextRevision
     *        The <b>ItemRevision</b> whose default rules are updated in this operation.
     *
     * @param defaultRules
     *        A list  of <b>FixedDefaultRuleExpression</b> structures each defining a default rule
     *        for a given variant option family.
     *
     * @param actionCode
     *        Enumeration <code>ActionCode</code> value which drives behavior of this operation
     *        and accordingly other parameters are interpreted. It can have one of following values:
     *        <br>
     *        <ul>
     *        <li type="disc"><code>ActionCodeAdd</code> : Create new default rule
     *        </li>
     *        <li type="disc"><code>ActionCodeUpdate</code> : Update an existing default rule
     *        </li>
     *        <li type="disc"><code>ActionCodeRemove</code> : Remove an existing default rule
     *        </li>
     *        </ul>
     *
     * @return
     *         This operation returns created or updated <b>Fnd0FixedDefaultRule</b> objects. Deleted
     *         <b>Fnd0FixedDefaultRule</b> objects are reported in the service data of this operation.
     *         <br>
     *         This operation may return partial errors in the service data for the following Teamcenter
     *         errors:
     *         <br>
     *         <ul>
     *         <li type="disc">94001 : An internal error has occurred in the "<code>Fnd0SoaConfiguratorAdmin</code>"
     *         module.
     *         </li>
     *         <li type="disc">94002 : An error occurred while processing a previous element in
     *         the operation input causing this operation input to be skipped.
     *         </li>
     *         <li type="disc">94003 : The variability expression must not be null for default rules.
     *         </li>
     *         <li type="disc">94004 : The Fixed Default Rule object cannot be passed as null.
     *         </li>
     *         <li type="disc">94005 : The <code>VariantOptionValue</code> structure must either
     *         specify a <code>[variant</code>] member, or a [<code>namespaceItem, namespaceRevision,
     *         familyName</code>] tupel.
     *         </li>
     *         <li type="disc">94006 : A duplicate <code>value</code> "value" was found.
     *         </li>
     *         <li type="disc">93001 : An internal error has occurred in the "<code>Fnd0ConfiguratorAdmin</code>"
     *         module.
     *         </li>
     *         <li type="disc">93003 : The input context revision is null.
     *         </li>
     *         <li type="disc">93006 : The input Business Object type name is "<code>typename</code>".
     *         A type name of "<code>typename</code>" or one of its sub-types is expected.
     *         </li>
     *         <li type="disc">93008 : The options "<code>FamilyNameList</code>" are not allocated
     *         for the context <b>ItemRevision</b> "<code>contextRevision</code>". Please allocate
     *         the options for the context revision and try again.
     *         </li>
     *         <li type="disc">93013 : No default value supplied: a Fixed or Derived Default must
     *         set a specific Option Value.
     *         </li>
     *         <li type="disc">39014 : The business object type for the new default rule is not
     *         known.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           This operation may raise a <code>Teamcenter::Soa::Server::ServiceException</code>
     *           wrapping around following Teamcenter errors:
     *           <br>
     *           <ul>
     *           <li type="disc">515024 : The tag given (for <code>contextRevision</code>) is not
     *           a valid tag.
     *           </li>
     *           <li type="disc">515177 : Attempt to access remote/archived (<code>contextRevision</code>)
     *           instance.
     *           </li>
     *           <li type="disc">515001 : You do not have sufficient access rights for the attempted
     *           operation (lock <code>contextRevision</code>  for modify).
     *           </li>
     *           <li type="disc">39000+x : Errors raised in module TCTYPE during property inflation
     *           in the service framework.
     *           </li>
     *           <li type="disc">38000+x : Errors raised in module PROP during property inflation
     *           in the service framework.
     *           </li>
     *           </ul>
     */
    virtual Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::FixedDefaultRuleResponse createUpdateFixedDefaultRules ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  contextRevision,
        const std::vector< Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::FixedDefaultRuleExpression >& defaultRules,
        const ActionCode&  actionCode ) = 0;

    /**
     * This operation creates, updates and deletes Option Family Group information in context
     * of the given <b>ItemRevision</b>. Option Family Group objects are meant to group
     * <b>Fnd0VariantOptionFamily</b> objects for the purpose of reviewing them together
     * as a group, for example: when defining configuration criteria.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User has created many Variant Option Families and wants to categorize variant option
     * families which could be related to each other so as to easily find or manage the
     * variant option families. For example: variant option families like "Steering", "Dashboard",
     * "Seat Covers" can be grouped into a <b>Fnd0OptionFamilyGroup</b> object named "Interiors".
     * This grouping can also help users of the <code>Fnd0::Soa::ConfigFilterCriteria::_2013_05::VariantManagement::getAvailableProductVariability</code>
     * service  to determine the set of families for which it is useful to query available
     * variability together in one call.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * allocateVariantOptionValues, createUpdateVariantOptions, getAllocatedVariantOptionValues
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Configuration Management - Capability to configure structured data based on revsion
     * rules; effectivities; Status etc.
     *
     * @param optionFamilyGroups
     *        The information needed for creating, updating, or deleting group information in context
     *        of an Item Revision.
     *
     * @return
     *         This operation returns a list of <b>Fnd0OptionFamilyGroup</b> objects which are created
     *         or updated. Deleted groups are reported in the service data of the response.
     *         <br>
     *         This operation may return partial errors in the service data for the following Teamcenter
     *         errors:
     *         <br>
     *         <ul>
     *         <li type="disc">93016 : The Option Family Group name must not be empty during creation.
     *         </li>
     *         <li type="disc">93017 : The Option Family Group object cannot be passed as null.
     *         </li>
     *         <li type="disc">93018 : The Option Family Group with name "<code>name</code>" already
     *         exists for the context Item Revision "<code>ItemRevision</code>".
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           This operation may raise a <code>Teamcenter::Soa::Server::ServiceException</code>
     *           wrapping around following Teamcenter errors:
     *           <br>
     *           <ul>
     *           <li type="disc">515024 : The tag given (for <code>contextRevision</code>) is not
     *           a valid tag.
     *           </li>
     *           <li type="disc">515177 : Attempt to access remote/archived (<code>contextRevision</code>)
     *           instance.
     *           </li>
     *           <li type="disc">515001 : You do not have sufficient access rights for the attempted
     *           operation (lock <code>contextRevision</code> for modify).
     *           </li>
     *           <li type="disc">39000+x : Errors raised in module TCTYPE during property inflation
     *           in the service framework.
     *           </li>
     *           <li type="disc">38000+x : Errors raised in module PROP  during property inflation
     *           in the service framework.
     *           </li>
     *           </ul>
     */
    virtual Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::OptionFamilyGroupsResponse createUpdateOptionFamilyGroups ( const std::vector< Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::OptionFamilyGroupInfo >& optionFamilyGroups ) = 0;

    /**
     * This operation creates or updates variant option data on an Item that owns / will
     * own these variant options.
     * <br>
     * An owning <b>Item</b>, sometimes referred to as "Dictionary Item", manages the lifecycle
     * of the variant option data it owns. After creating or updating variant data in the
     * context of a Dictionary Revision it can be allocated to other <b>ItemRevision</b>
     * objects. Allocating variant option data, which is owned by a centrally managed Dictionary
     * Item, can be useful when re-using product data with variant conditions across product
     * boundaries. The term "Product ItemRevision" is sometimes used to refer to the <b>ItemRevision</b>
     * to which variant data is allocated. This could be an <b>ItemRevision</b> of an <b>Item</b>
     * different from the Dictionary Item.
     * <br>
     * Creating new variant option data for an owning item automatically also allocates
     * this variant option data to the specified context revision of the owning item.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * A user wants to create a new variant option Voltage := { 120; 230; 240; 400 } with
     * the intent to allocate these values to a product <b>ItemRevision</b> representing
     * a washing machine as well as a product <b>ItemRevision</b> representing a dryer so
     * that a common fuse panel assembly can be shared between the two product contexts
     * such that the elements in the assembly can have the same variant conditions. To achieve
     * this, the user calls operation createUpdateVariantOptions to create the new option
     * on a Dictionary Item "APPLIANCE". After that operation allocateVariantOptionValues
     * can be used to allocate (some of) these values from APPLIANCE/A to product ItemRevision
     * WASHER/A as well as to DRYER/A.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Configuration Management - Capability to configure structured data based on revsion
     * rules; effectivities; Status etc.
     *
     * @param contextRevision
     *        The <b>ItemRevision</b> in which context the variant options are created or updated.
     *
     * @param variantOptionFamilies
     *        A vector of VariantOptionFamily structures each describing modifications to variant
     *        option family and required action to be done. If the object already exists and the
     *        state cannot be changed to match the modifications a partial error is returned.
     *
     * @return
     *         The list of created or changed variant options. Deleted variant options are reported
     *         in the service data.
     *         <br>
     *         This operation may return partial errors in the service data for the following Teamcenter
     *         errors:
     *         <br>
     *         <ul>
     *         <li type="disc">93001 : An internal error has occurred in the "<code>Fnd0ConfiguratorAdmin</code>"
     *         module.
     *         </li>
     *         <li type="disc">93003 : The input context revision is null.
     *         </li>
     *         <li type="disc">93004 : No option family "<code>Familyname</code>" with namespace
     *         "<code>DictionaryNamespace</code>"  can be found.
     *         </li>
     *         <li type="disc">93006 : The input Business Object type name is "<code>typename</code>".
     *         A type name of "<code>typename</code>" or one of its sub-types is expected.
     *         </li>
     *         <li type="disc">93007 : The variability allocation cannot be changed in the context
     *         of <b>ItemRevision</b> <code>contextRevision</code>. It can only be changed in the
     *         context of an <b>ItemRevisions</b> that references it
     *         </li>
     *         <li type="disc">93010 : The variant option value "<code>text</code>" is a duplicate.
     *         Values must be unique within the option family.
     *         </li>
     *         <li type="disc">93011 : The variability allocation is referenced by multiple <b>ItemRevisions</b>.
     *         Please use the "Save As" command on this object in the context of one of (one of)
     *         the Item Revision(s) that reference this allocation to make an exclusive copy and
     *         therefore resolve the ambiguity.
     *         </li>
     *         <li type="disc">93012 : Objects of type can be saved-as only when they are referenced
     *         by multiple Item Revisions.
     *         </li>
     *         <li type="disc">93013 : No default value supplied. A Fixed or Derived Default must
     *         set a specific option value.
     *         </li>
     *         <li type="disc">93015 : Logical data type families have a single value equal to the
     *         name of the option family.  It is not permitted to create, add, or update values
     *         for option family "<code>FamilyName</code>" on the ItemRevision.
     *         </li>
     *         <li type="disc">94001 : An internal error has occurred in the "<code>Fnd0SoaConfiguratorAdmin</code>"
     *         module.
     *         </li>
     *         <li type="disc">94003 : The variability expression must not be null for default rules.
     *         </li>
     *         <li type="disc">94004 : The Fixed Default Rule object cannot be passed as null.
     *         </li>
     *         <li type="disc">264003 : An invalid operation code was found: <code>opcode</code>.
     *         </li>
     *         <li type="disc">43009 : Invalid value.
     *         </li>
     *         <li type="disc">43001 : Internal error in PS module: <code>text</code>
     *         </li>
     *         <li type="disc">515106 : The object cannot be saved because it contains at least
     *         one attribute that violates a unique attribute rule.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           This operation may raise a <code>Teamcenter::Soa::Server::ServiceException</code>
     *           wrapping around following Teamcenter errors:
     *           <br>
     *           <ul>
     *           <li type="disc">515024 : The tag given (for <code>contextRevision</code>) is not
     *           a valid tag.
     *           </li>
     *           <li type="disc">515177 : Attempt to access remote/archived (<code>contextRevision</code>)
     *           instance.
     *           </li>
     *           <li type="disc">515001 : You do not have sufficient access rights for the attempted
     *           operation (lock <code>contextRevision</code> for modify).
     *           </li>
     *           <li type="disc">39000+x : Errors raised in module TCTYPE during property inflation
     *           in the service framework.
     *           </li>
     *           <li type="disc">38000+x : Errors raised in module PROP during property inflation
     *           in the service framework.
     *           </li>
     *           </ul>
     */
    virtual Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::VariantOptionResponse createUpdateVariantOptions ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  contextRevision,
        const std::vector< Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::VariantOptionFamily >& variantOptionFamilies ) = 0;

    /**
     * This operation returns variability that was allocated to the context revision.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * A variant option "Voltage := { 120; 220; 230; 240; 380, 400 }" is owned by Item APPLIANCE.
     * For the purpose of allocating some of these values to a product <b>ItemRevision</b>
     * a user wants to know, which of these values are approved for allocation to new products
     * according to company business rules. To achieve this, the user configures item APPLIANCE
     * with an appropriate RevisionRule that selects APPLIANCE/C. A call to <code>getAllocatedVariantOptionValues</code>
     * for APPLIANCE/C returns Voltage := { 120; 230; 240; 400 } as currently approved values
     * for product allocation. The user can then use operation <code>allocateVariantOptionValues</code>
     * to allocate (some of) these values from APPLIANCE/C to the product <b>ItemRevision</b>.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * allocateVariantOptionValues, createUpdateVariantOptions
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Configuration Management - Capability to configure structured data based on revsion
     * rules; effectivities; Status etc.
     *
     * @param contextRevision
     *        The <b>ItemRevision</b> for which allocated variability is requested in this operation.
     *
     * @return
     *         This operation returns list of variant option values, or value ranges, that were
     *         allocated to the specified context <b>ItemRevision</b>.
     *
     *
     * @exception ServiceException
     *           This operation may raise a <code>Teamcenter::Soa::Server::ServiceException</code>
     *           wrapping around following Teamcenter errors:
     *           <br>
     *           <ul>
     *           <li type="disc">93001 : An internal error has occurred in the "<code>Fnd0SoaConfiguratorAdmin</code>"
     *           module.
     *           </li>
     *           <li type="disc">515024 : The tag given ( for <code>contextRevision</code> ) is not
     *           a valid tag.
     *           </li>
     *           <li type="disc">515177 : Attempt to access remote/archived (<code> contextRevision</code>
     *           ) instance.
     *           </li>
     *           <li type="disc">515001 : You do not have sufficient access rights for the attempted
     *           operation ( load <code>contextRevision</code> ).
     *           </li>
     *           <li type="disc">39000+x : Errors raised in module TCTYPE during property inflation
     *           in the service framework.
     *           </li>
     *           <li type="disc">38000+x : Errors raised in module PROP during property inflation
     *           in the service framework.
     *           </li>
     *           </ul>
     */
    virtual Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::VariabilityAllocationResponse getAllocatedVariantOptionValues ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  contextRevision ) = 0;

    /**
     * This operation returns the constraint rules (<b>Fnd0ExcludeConstraintRule</b> and
     * / or <b>Fnd0IncludeConstraintRule</b>) defined for a given context <b>ItemRevision</b>.
     * If the request specifies variant option values or families in parameter <code>optionValueReferenced</code>
     * the response will contain all constraint rules that reference at least one of these
     * values or families anywhere in the <code>productFamilyCondition, applicabilityCondition,
     * or constraintCondition</code>. Otherwise the response will contain all applicable
     * constraint rules. If the request specifies one or more <code>filterExpression</code>
     * the response will contain constraint rules whose <code>productFamilyCondition</code>,
     * <code>applicabilityCondition</code>, or <code>constraintCondition</code> satisfy
     * at least one of these expressions according to the specified solve type. Otherwise
     * the response will contain all applicable constraint rules.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * A user has created the following exclude rules for a given ItemRevision:
     * <br>
     * 1. WHILE "Model = M1" AND "Engine = 95 H.P." AND "Year = 2010" THEN ERROR "This engine
     * is not available for the selected model / year combination."
     * <br>
     * 2. IF "Engine = 110 H.P." AND "Year = 2011" THEN ERROR "This engine is not available
     * for the selected year."
     * <br>
     * Exclude constraint rules associated with this <b>ItemRevision</b> can be queried
     * based on variant option families, variant option values, or variant expressions:
     * <br>
     * <ul>
     * <li type="disc">A request specifying variant option family "Model" in <code>optionValueReferenced</code>
     * parameter returns rule 1.
     * </li>
     * <li type="disc">A request specifying variant option value "Engine = 110 H.P." in
     * <code>optionValueReferenced</code> parameter returns rule 2.
     * </li>
     * <li type="disc">A request specifying "Model = M1" in parameter <code>filterExpression</code>
     * along with a solveType "<b>EXPLICIT</b>" returns rule 1.
     * </li>
     * <li type="disc">A request specifying "Model = M1" in parameter <code>filterExpression</code>
     * along with a solveType "<b>COPRIME</b>" returns rule 2.
     * </li>
     * <li type="disc">A request specifying "Model = M1" in parameter <code>filterExpression</code>
     * along with a solveType "<b>EXPLICIT</b>|<b>COPRIME</b>" returns rule 1 as well as
     * rule 2.
     * </li>
     * </ul>
     * <br>
     * Include constraint rule follows an analogous approach.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createUpdateConstraintRules
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Configuration Management - Capability to configure structured data based on revsion
     * rules; effectivities; Status etc.
     *
     * @param contextRevision
     *        The <b>ItemRevision</b> for which constraint rules are requested.
     *
     * @param filterExpression
     *        A vector of expressions that will filter constraint rule search results. Individual
     *        <code>filterExpressions</code> are combined with operator OR to form a solve expression
     *        when selecting configurator rules.  If the request does not list specific filter
     *        expressions then the response will contain all applicable constraint rules for the
     *        given <code>contextRevision</code>.
     *
     * @param optionValueReferenced
     *        A vector of variant options values or families for which constraint rules are requested.
     *        If the vector is empty the response will contain all applicable constraint rules.
     *        <br>
     *        If the vector is not empty, the response will contain constraint rules that reference
     *        one or more  values or families identified in the vector anywhere in <code>productFamilyCondition</code>,
     *        <code>applicabilityCondition</code>, or <code>constraintCondition</code>.
     *
     * @param boType
     *        Specifies which type of rules to fetch. Valid values should be <b>Fnd0ConstraintRule</b>
     *        or a sub type.
     *        <br>
     *        <ul>
     *        <li type="disc">If an empty string ( "" ) is specified the operation returns both
     *        include and exclude constraint rules.
     *        </li>
     *        <li type="disc">If <b>Fnd0ConstraintRule</b> is specified the operation returns both
     *        include and exclude constraint rules.
     *        </li>
     *        <li type="disc">If <b>Fnd0ExcludeConstraintRule</b> is specified, the operation will
     *        return only exclude constraint rules of type <b>Fnd0ExcludeConstraintRule</b> and
     *        its sub-types.
     *        </li>
     *        <li type="disc">If <b>Fnd0IncludeConstraintRule</b> is specified, the operation will
     *        return only include constraint rules of type <b>Fnd0IncludeConstraintRule</b> and
     *        its sub-types.
     *        </li>
     *        <li type="disc">If any custom business object type is specified, the operation will
     *        return rules of this type and its sub-types.
     *        </li>
     *        </ul>
     *
     * @param severity
     *        The severity code associated with message. Valid values are one or combination of
     *        following:
     *        <br>
     *        <ul>
     *        <li type="disc">1 ( Error ) : Configuration criteria that satisfy this constraint
     *        are classified as invalid.
     *        </li>
     *        <li type="disc">2 ( Warning) : Classifies information associated with this constraint
     *        as considerations, such as recommendations, which are important to review if configuration
     *        criteria satisfy this constraint.
     *        </li>
     *        <li type="disc">4 ( Information ) : Classifies information associated with this constraint
     *        as additional information, such as hints, which are of interest if configuration
     *        criteria satisfy this constraint.
     *        </li>
     *        </ul>
     *        <br>
     *        To specify combinatorial severity, bitwise OR operation should be performed on above
     *        values. For example: To specify severity as "Error or Information", a value = 1 bitwiseOr
     *        4 must be specified.
     *
     * @param solveType
     *        Indicates the type of solve to use for the <code>filterExpression</code>. For possible
     *        values see preference <code>TC_Default_Solve_Type</code>.
     *
     * @return
     *         This operation returns exclude constraint rules defined on the <b>ItemRevision</b>
     *         that match the given filter conditions or criteria.
     *
     *
     * @exception ServiceException
     *           This operation may raise a <code>Teamcenter::Soa::Server::ServiceException</code>
     *           wrapping around following Teamcenter errors:
     *           <br>
     *           <ul>
     *           <li type="disc">93001 : An internal error has occurred in the "<code>Fnd0SoaConfiguratorAdmin</code>"
     *           module.
     *           </li>
     *           <li type="disc">515024 : The tag given ( for <code>contextRevision</code> ) is not
     *           a valid tag.
     *           </li>
     *           <li type="disc">515177 : Attempt to access remote/archived (<code> contextRevision</code>
     *           ) instance.
     *           </li>
     *           <li type="disc">515001 : You do not have sufficient access rights for the attempted
     *           operation (load <code> contextRevision</code> ).
     *           </li>
     *           <li type="disc">39000+x : Errors raised in module TCTYPE during property inflation
     *           in the service framework.
     *           </li>
     *           <li type="disc">38000+x : Errors raised in module PROP  during property inflation
     *           in the service framework.
     *           </li>
     *           </ul>
     */
    virtual Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::ConstraintRuleResponse getConstraintRules ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  contextRevision,
        const std::vector< Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::VariantExpression >& filterExpression,
        const std::vector< Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::VariantOptionValue >& optionValueReferenced,
        const std::string&  boType,
        int severity,
        int solveType ) = 0;

    /**
     * This operation returns derived default rules (<b>Fnd0DerivedDefaultRule</b>) defined
     * for a given context <b>ItemRevision</b>. If the request specifies one or more variant
     * option values or families in parameter <code>optionValueReferenced</code> the response
     * will contain all derived default rules that reference one or more of these values
     * or families anywhere in the <code>productFamilyCondition</code>, <code>applicabilityCondition</code>,
     * or <code>defaultCondition</code>.  Otherwise the response will contain all applicable
     * derived default rules. If the request specifies one or more <code>filterExpression</code>
     * the response will contain derived default rules whose <code>productFamilyCondition</code>,
     * <code>applicabilityCondition</code>, or <code>defaultCondition</code> satisfy one
     * or more of these expressions according to the specified solve type. Otherwise the
     * response will contain all applicable derived default rules.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createUpdateDerivedDefaultRules
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Configuration Management - Capability to configure structured data based on revsion
     * rules; effectivities; Status etc.
     *
     * @param contextRevision
     *        The <b>ItemRevision</b> for which derived default rules are requested.
     *
     * @param filterExpression
     *        A list of variant expression to filter the derived default rules. Individual <code>filterExpressions</code>
     *        are combined with operator OR to form a filter expression when selecting configurator
     *        rules.  If the request does not list specific filter expressions then the response
     *        will contain all applicable default rules for given <code>contextRevision</code>.
     *
     * @param optionValueReferenced
     *        A list of variant option values or families for which default rules are requested.
     *        If the vector is empty the response will contain all applicable default rules.
     *        <br>
     *        If the vector is not empty, the response will contain default rules that reference
     *        one or more values or families identified in the vector anywhere in <code>defaultCondition</code>.
     *
     * @param solveType
     *        Indicates the type of solve to use for the <code>filterExpression</code>. For possible
     *        values see preference <code>TC_Default_Solve_Type</code>.
     *
     * @return
     *         This operation returns derived default rules defined on an Item Revision according
     *         to the search and filter criteria.
     *
     *
     * @exception ServiceException
     *           This operation may raise a <code>Teamcenter::Soa::Server::ServiceException</code>
     *           wrapping around following Teamcenter errors:
     *           <br>
     *           <ul>
     *           <li type="disc">94001 : An internal error has occurred in then "<code>Fnd0SoaConfiguratorAdmin</code>"
     *           module.
     *           </li>
     *           </ul>
     */
    virtual Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::DerivedDefaultRuleResponse getDerivedDefaultRules ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  contextRevision,
        const std::vector< Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::VariantExpression >& filterExpression,
        const std::vector< Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::VariantOptionValue >& optionValueReferenced,
        int solveType ) = 0;

    /**
     * This operation returns fixed default rules (<b>Fnd0FixedDefaultRule</b>) defined
     * for a given context <b>ItemRevision</b>. If the request specifies one or more variant
     * option values or families in parameter <code>optionValueReferenced</code> the response
     * will contain all fixed default rules that reference one or more of these values or
     * families anywhere in the <code>defaultCondition</code>.  Otherwise the response will
     * contain all applicable fixed default rules. If the request specifies one or more
     * <code>filterExpression</code> the response will contain fixed default rules whose
     * <code>defaultCondition</code> satisfies one or more of these expressions according
     * to the specified solve type. Otherwise the response will contain all applicable fixed
     * default rules.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createUpdateFixedDefaultRules
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Configuration Management - Capability to configure structured data based on revsion
     * rules; effectivities; Status etc.
     *
     * @param contextRevision
     *        The <b>ItemRevision</b> for which derived default rules are requested.
     *
     * @param filterExpression
     *        Individual <code>filterExpressions</code> are combined with operator OR to form a
     *        filter expression when selecting configurator rules.  If the request does not list
     *        specific filter expressions then the response will contain all applicable default
     *        rules for given <code>contextRevision</code>.
     *
     * @param optionValueReferenced
     *        A list of variant option values for which default rules are requested. If the vector
     *        is empty the response will contain all applicable default rules.
     *        <br>
     *        If the list is not empty, the response will contain default rules that reference
     *        one or more values or families identified in the list anywhere in <code>defaultCondition</code>.
     *        <br>
     *
     * @param solveType
     *        Indicates the type of solve to use for the <code>filterExpression</code>. For possible
     *        values see preference <code>TC_Default_Solve_Type</code>.
     *
     * @return
     *         This operation returns fixed default rules defined on an <b>ItemRevision</b> according
     *         to search and filter criteria.
     *
     *
     * @exception ServiceException
     *           This operation may raise a <code>Teamcenter::Soa::Server::ServiceException</code>
     *           wrapping around following Teamcenter errors:
     *           <br>
     *           <ul>
     *           <li type="disc">94001 : An internal error has occurred in the <code>Fnd0SoaConfiguratorAdmin</code>
     *           module.
     *           </li>
     *           </ul>
     */
    virtual Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::FixedDefaultRuleResponse getFixedDefaultRules ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  contextRevision,
        const std::vector< Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::VariantExpression >& filterExpression,
        const std::vector< Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::VariantOptionValue >& optionValueReferenced,
        int solveType ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("VariantadminService")

};
        }
    }
}


#pragma warning ( pop )

#include <fnd0/services/configuratoradmin/ConfiguratorAdmin_undef.h>
#endif

