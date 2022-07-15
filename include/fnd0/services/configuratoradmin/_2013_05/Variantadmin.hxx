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

#ifndef FND0_SERVICES_CONFIGURATORADMIN__2013_05_VARIANTADMIN_HXX
#define FND0_SERVICES_CONFIGURATORADMIN__2013_05_VARIANTADMIN_HXX

#include <teamcenter/soa/client/model/Fnd0ConstraintRule.hxx>
#include <teamcenter/soa/client/model/Fnd0DerivedDefaultRule.hxx>
#include <teamcenter/soa/client/model/Fnd0FixedDefaultRule.hxx>
#include <teamcenter/soa/client/model/Fnd0OptionFamilyGroup.hxx>
#include <teamcenter/soa/client/model/Fnd0OptionValue.hxx>
#include <teamcenter/soa/client/model/Item.hxx>
#include <teamcenter/soa/client/model/ItemRevision.hxx>
#include <teamcenter/soa/client/model/UnitOfMeasure.hxx>
#include <teamcenter/soa/client/model/Variant.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <fnd0/services/configuratoradmin/ConfiguratorAdmin_exports.h>

namespace Fnd0
{
    namespace Services
    {
        namespace Configuratoradmin
        {
            namespace _2013_05
            {
                class Variantadmin;

class FND0SOACONFIGURATORADMINSTRONGMNGD_API Variantadmin
{
public:

    struct VariantOptionValue;
    struct VariantFormula;
    struct VariantExpression;
    struct ConstraintRuleExpression;
    struct ConstraintRuleResponse;
    struct VariabilityExpression;
    struct DerivedDefaultRuleExpression;
    struct DerivedDefaultRuleResponse;
    struct FixedDefaultRuleExpression;
    struct FixedDefaultRuleResponse;
    struct OptionFamilyGroup;
    struct OptionFamilyGroupInfo;
    struct OptionFamilyGroupOutput;
    struct OptionFamilyGroupsOutput;
    struct OptionFamilyGroupsResponse;
    struct VariabilityAllocationResponse;
    struct VariantExpressionResponse;
    struct VariantOptionFamily;
    struct VariantOptionResponse;

    /**
     * Action code enum.
     */
    enum ActionCode{ ActionCodeAdd,
                 ActionCodeRemove,
                 ActionCodeUpdate
                 };

    /**
     * Allocate option value action codes.
     */
    enum AllocateOptionValueActionCode{ ActionCodeValueAllocate,
                 ActionCodeValueRemove,
                 ActionCodeValueUpdate,
                 ActionCodeFamilyRemove
                 };

    /**
     * Severity code for error message.
     */
    enum ConstraintSeverity{ ConstraintSeverityInformation,
                 ConstraintSeverityWarning,
                 ConstraintSeverityError
                 };

    /**
     * The format for variant expression formula strings.
     */
    enum FormulaFormat{ UseDefaultFormat,
                 ShowFamilyAndItem,
                 ShowFamilyHideItem,
                 HideFamilyAndItem
                 };

    /**
     * List of attributes which maps attribute name to value(s). All values are expressed
     * in their string equivalant.
     */
    typedef std::map< std::string, std::vector< std::string > > AttributeInfoMap;

    /**
     * Represents a value in a variant option family. The family is either directly specified
     * with parameter "<code>variant</code>", or is indirectly defined either by specifying
     * parameter "<code>variantObject</code>", or by the combination of the owning item
     * given in parameter "<code>namespaceItem</code>" together with parameter "<code>familyName</code>".
     * The actual value in this family is either specified by parameter "<code>valueCode</code>"
     * or identified by parameter "<code>variantObject</code>". The additional properties
     * for the value that is represented by the <b>WorkspaceObject</b> object follows the
     * revision configuration of the <b>ItemRevision</b>, to which the variant option value
     * was allocated. The structure is interpreted to be "<code>NULL</code>" if the following
     * values are set to its parameters:
     * <br>
     * <code>variantObject</code> : <code>NULLTAG</code>
     * <br>
     * <code>namespaceItem</code> : <code>NULLTAG</code>
     * <br>
     * <code>familyName</code> : An empty ( "" ) string
     * <br>
     * <code>valueCode</code> : An empty ( "" ) string
     * <br>
     * <code>boType</code> : An empty ( "" ) string
     * <br>
     * <code>attrInfo</code> : An empty map
     */
    struct VariantOptionValue
    {
        /**
         * The object managing additional properties of this variant option value providing
         * additional information about this value in a given context, for example: in the context
         * of the owning <b>ItemRevision</b>, or in the context of the <b>ItemRevision</b>,
         * to which this variant option value was allocated. This parameter is optional. Its
         * value depends on the context in which this <code>VariantOptionValue</code> struct
         * exists.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Fnd0OptionValue>  optionValue;
        /**
         * Option value business object type which should be created. This is an optional property.
         * If empty value is provided, <b>Fnd0OptionValue</b> is used as business object type.
         * Business object type specified in this property must be either <b>Fnd0OptionValue</b>
         * or its sub type.
         */
        std::string boType;
        /**
         * The list of properties and their values which need to be set when creating the new
         * object of the type specified by <code>boType</code> property. The properties in this
         * map must be available on create descriptor of object being created.
         * <br>
         * In case of update the list of properties and their values which need to be set when
         * updating the object being represented by <code>optionValue </code>property. The properties
         * in this map must be available on object being updated.
         */
        AttributeInfoMap attrInfo;
        /**
         * The <b>Item</b> owning the variant family for which data should be created or updated.
         * The owning item serves as a namespace in which the variant option family has a well-defined
         * meaning.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Item>  namespaceItem;
        /**
         * The name of the variant option family. The name is unique within its namespace.
         */
        std::string familyName;
        /**
         * The text representation of the value. A value is unique within its family.
         */
        std::string valueCode;
        /**
         * This is variant option family object which owns the option value.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Variant>  variant;
    };

    /**
     * Represents a formula string associated with a <code>VariantExpression</code> in "
     * <b>Teamcenter language</b>".  A formula of the form "[<i>OptionNamespace</i>]<i>FamilyName</i>
     * = <i>UniqueValue</i>" is called <b>"explicit</b>" because no product context is required
     * to determine the family name for the value, or the option namespace for the family
     * name. <i>OptionNamespace</i> and <i>FamilyName</i> are explicitly spelled out. A
     * variant formula is in "<b>Teamcenter language</b>" if its form comprised of the lexemes
     * documented for the Variant Formula property. A formula of the form "<i>UniqueValue</i>"
     * is called "<b>stenographic</b>" because a parser has to infer <i>OptionNamespace</i>
     * and <i>FamilyName</i>. This is possible if there is only one value with that name
     * in the current context.
     */
    struct VariantFormula
    {
        /**
         * Formula string in configurator syntax.
         */
        std::string formula;
        /**
         * Identifies the Item in which context this formula is defined. Used in conjunction
         * with parameter <code>contextItemRevisionID</code> to resolve any ambiguity in variant
         * option value names. It can be empty ("") if the formula is in explicit Teamcenter
         * language.
         */
        std::string contextItemID;
        /**
         * Identifies the <b>ItemRevision</b> for <code>contextItemID</code>, and thereby the
         * business process context in which the data associated with "<code>contextItemID</code>"
         * is uniquely defined. Used in conjunction with parameter <code>contextItemID</code>
         * to resolve any ambiguity in variant option value names. It can be empty ("") if the
         * formula is in explicit Teamcenter language.
         */
        std::string contextItemRevisionID;
    };

    /**
     * Represents a Boolean variant expression. A <code>NULL VariantExpression</code> structure
     * is treated as the identity element for all commutative "<code>opcode</code>" values.
     * The structure is interpreted as "<code>NULL</code>" when it has following values
     * set for its parameters:
     * <br>
     * <code>subExpressions</code> : An empty vector
     * <br>
     * <code>value</code> : A <code>NULL VariantOptionValue</code> structure
     * <br>
     * <code>opCode</code> : -1
     * <br>
     * <code>formula</code> : A "NULL" VariantFormula structure
     * <br>
     * <code>tnf</code> : An empty vector
     * <br>
     * A <code>VariantExpression</code> that is equivalent to the Boolean constant <code>TRUE</code>
     * returns a TNF parameter comprising one expression with an <code>opcode</code> value
     * of <code>39</code>.
     * <br>
     * A <code>VariantExpression</code> that is equivalent to the Boolean constant <code>FALSE</code>
     * returns a TNF parameter comprising one expression with an <code>opcode</code> value
     * of <code>40</code>.
     */
    struct VariantExpression
    {
        /**
         * The list of <code>VariantExpression</code> sub-expressions combined with "<code>opcode</code>".
         */
        std::vector< Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::VariantExpression > subExpressions;
        /**
         * The value to which "<code>opCode</code>" compares. "<code>subExpressions</code>"
         * and "<code>value</code>" both must not be present.
         */
        Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::VariantOptionValue value;
        /**
         * Operation code such as "and" and "or", see ps/ps_tokens.h.
         */
        int opCode;
        /**
         * If present, this parameter contains the variant expression in string format.
         */
        Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::VariantFormula formula;
        /**
         * If present, this parameter provides a representation of the enclosing expression
         * in Teamcenter Normal Form (TNF).
         * <br>
         * The parameter is intended as "courtesy information" so to make additional SOA calls
         * unnecessary by providing information that is expected to be of value if performance
         * permits it. Based on the assumption that the vast majority of <code>VariantExpression</code>
         * structs can be converted to TNF very efficiently the server can afford to convert
         * them to TNF as a "free gift". If this becomes a performance bottleneck the server
         * may return a response with an empty <code>tnf</code> member, in which case the application
         * can explicitly request a <code>tnf</code> representation using operation <code>convertVariantExpressions</code>,
         * if need be. Preference <code>TC_tnf_timeout_period</code> controls the timeout mechanism.
         * If TNF generation takes more time than specified in preference <code>TC_tnf_timeout_period</code>,
         * server returns an empty <code>tnf</code> member.
         * <br>
         * If combined with OR the list of <code>tnf</code> expressions is logically equivalent
         * to the enclosing expression. Each TNF is provided as a conjunction of Disjunctive
         * Normal Forms (DNF) where all DNFs reference a single variant option family. Each
         * clause in the outermost conjunction can reference a different variant option family.
         * <br>
         * <b>Example 1:</b>
         * <br>
         * Formula: (ENG = V6 | ENG = V8) & (D = 2.6L | D >= 3L & D <= 3.6L)
         * <br>
         * TNF: Yes
         * <br>
         * Note: DNF1 references family ENG and DNF2 references family D
         * <br>
         * <b>Example 2:</b>
         * <br>
         * Formula: (ENG = V6 | TRANS = AUTO) & (TRANS = M5 | ENG = V8)
         * <br>
         * TNF: No
         * <br>
         * Note: DNF1 references family ENG as well as TRANS and  DNF2 references family ENG
         * as well as TRANS
         */
        std::vector< Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::VariantExpression > tnf;
    };

    /**
     * Represents an inclusion or exclusion rule describing a constraint on combining variant
     * option values. The structure is interpreted as "<code>NULL</code>" if it has the
     * following values set for its parameters:
     * <br>
     * <code>message</code> : An empty string ( "" )
     * <br>
     * <code>severity</code> : <code>ConstraintSeverityInformation</code>
     * <br>
     * <code>productFamilyCondition</code> : A <code>NULL</code> <code>VariantExpression</code>
     * structure
     * <br>
     * <code>constraintCondition</code> : A <code>NULL</code> <code>VariantExpression</code>
     * structure
     * <br>
     * <code>sequence</code> : -1
     * <br>
     * <code>constraintRule</code> : A <code>NULLTAG</code>
     * <br>
     * <code>boType</code> : An empty ( "" ) string
     * <br>
     * <code>attrInfo</code> : An empty map
     * <br>
     * <code>clientId</code> : An empty ( "" ) string
     * <br>
     */
    struct ConstraintRuleExpression
    {
        /**
         * This unique ID is used to identify return data elements and partial errors associated
         * with this structure.
         */
        std::string clientId;
        /**
         * The text string associated with the rule violation.
         */
        std::string message;
        /**
         * The severity code associated with message. Valid values are:
         * <br>
         * <ul>
         * <li type="disc"><code>ConstraintSeverityInformation</code> : Classifies information
         * associated with this constraint as additional information, such as hints, which are
         * of interest if configuration criteria satisfy this constraint.
         * </li>
         * <li type="disc"><code>ConstraintSeverityWarning</code> : Classifies information associated
         * with this constraint as considerations, such as recommendations, which are important
         * to review if configuration criteria satisfy this constraint.
         * </li>
         * <li type="disc"><code>ConstraintSeverityError</code> : Configuration criteria that
         * satisfy this constraint are classified as invalid.
         * </li>
         * </ul>
         * <br>
         * When validating configuration criteria a corresponding message with this severity
         * will be returned if the configuration criteria trigger this rule.
         */
        ConstraintSeverity severity;
        /**
         * The family of products. It is recommended to form this expression from elemental
         * literal expressions referencing variant option families with an <code>isModelDesignationRelevant</code>
         * value of TRUE. NULL conditions behave as if they were equivalent to the Boolean constant
         * TRUE, i.e. a statement qualified by a NULL condition always applies.
         */
        Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::VariantExpression productFamilyCondition;
        /**
         * The condition under which the constraint rule applies. NULL conditions behave as
         * if they were equivalent to the Boolean constant TRUE, i.e. a statement qualified
         * by a NULL condition always applies.
         */
        Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::VariantExpression applicabilityCondition;
        /**
         * The constraint to enforce.
         * <br>
         * Exclusive constraints specify the condition that must not be met by any valid configuration.
         * Criteria "A" satisfy, but don't meet an exclude constraint condition "A & B". Therefore
         * criteria "A" would successfully pass criteria validation. Criteria "A & B & C" on
         * the other hand satisfy and meet the exclude constraint condition "A & B". Therefore
         * criteria "A & B & C" would fail criteria validation.
         * <br>
         * Inclusive constraints specify the condition that must be satisfied by all valid configurations.
         * Criteria "A" satisfy an include constraint condition "A & B". Inclusive constraints
         * modify the configuration criteria during criteria validation according to the rule
         * criteria, for example: "A" is refined to "A & B".
         * <br>
         * All constraint rules must have a <code>constraintCondition</code>.
         * <br>
         */
        Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::VariantExpression constraintCondition;
        /**
         * The sequence number this constraint rule has relative to other constraint rules in
         * the same context
         */
        int sequence;
        /**
         * The object managing additional properties of this constraint rule. It can be used
         * to identify the object in an <code>ActionCodeRemove</code> operation. Properties
         * of the corresponding business object can help further describe this constraint rule,
         * for example: last modifying user, name, and description.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Fnd0ConstraintRule>  constraintRule;
        /**
         * When creating a new constraint rule this parameter is required to specify the business
         * object type of the new constraint rule. For include constraint rules <b>Fnd0IncludeConstraintRule</b>
         * or one of its sub-types should be used. For exclude constraint rules <b>Fnd0ExcludeConstraintRule</b>
         * or one of its sub-types should be used.
         * <br>
         * When updating or deleting a constraint rule this parameter can be left empty. Non-empty
         * values are ignored.
         * <br>
         * When a <code>ConstraintRuleExpression</code> structure is part of any response structure
         * this parameter will be empty.
         */
        std::string boType;
        /**
         * The list of properties and their values which need to be set when creating the new
         * object of the type specified by boType property. The properties in this map must
         * be available on create descriptor of object being created.
         * <br>
         * When updating or deleting an existing constraint rule this parameter can be empty.
         * <br>
         * When this structure is part of response structure this parameter will be empty.
         */
        AttributeInfoMap attrInfo;
    };

    /**
     * Contains a list of constraint rule expressions.
     */
    struct ConstraintRuleResponse
    {
        /**
         * The list of  include or exclude constraint rules which is created or updated. When
         * this structure is part of a response from operation <code>getConstraintRule</code>,
         * this parameter represents the matching list of include or exclude constraint rule.
         */
        std::vector< Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::ConstraintRuleExpression > constraintRules;
        /**
         * The service data for errors and returned objects.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Represents a set or range of variant option values for a single variant option family.
     * The structure is interpreted as "<code>NULL</code>" if it has the following values
     * set for its parameters:
     * <br>
     * <code>family</code> : <code>NULLTAG</code>
     * <br>
     * <code>variability</code> : A <code>NULL</code> <code>VariantExpression</code> structure
     */
    struct VariabilityExpression
    {
        /**
         * This unique ID is used to identify return data elements and partial errors associated
         * with this structure.
         */
        std::string clientId;
        /**
         * The variant option family for which this structure identifies the set or range of
         * variant option values.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Variant>  family;
        /**
         * Minimum value of the domain of value defined for Variant Family.
         */
        std::string minimumValue;
        /**
         * Maximum value of the domain of value defined for Variant Family.
         */
        std::string maximumValue;
        /**
         * Structure describes a variant expression.
         */
        Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::VariantExpression variability;
    };

    /**
     * Represents a derived default rule for a given variant option family. The structure
     * is interpreted as "<code>NULL</code>" if it has the following values set for its
     * parameters:
     * <br>
     * <code>defaultAssignment</code> : A <code>NULL VariabilityExpression</code> structure
     * <br>
     * <code>productFamilyCondition</code> : A <code>NULL VariantExpression</code> structure
     * <br>
     * <code>applicabilityCondition</code> : A <code>NULL VariantExpression</code> structure
     * <br>
     * <code>sequence</code> : -1
     * <br>
     * <code>defaultRule</code> : <code>NULLTAG</code>
     * <br>
     * <code>boType</code> : An empty ( "" ) string
     * <br>
     * <code>attrInfo</code> : An empty map
     * <br>
     * <code>clientId</code> : An empty ( "" ) string
     * <br>
     */
    struct DerivedDefaultRuleExpression
    {
        /**
         * This unique ID is used to identify return data elements and partial errors associated
         * with this structure.
         */
        std::string clientId;
        /**
         * The value, or set of values, or range of values, to assign to a family by default
         * for the product family identified by productFamilyCondition provided that applicabilityCondition
         * is met.
         */
        Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::VariabilityExpression defaultAssignment;
        /**
         * A VariantExpression identifying a family of products. It is recommended to form this
         * expression from elemental literal expressions referencing variant option families
         * with a isModelDesignationRelevant value of true in VariantOptionFamily. NULL conditions
         * behave as if they were equivalent to the Boolean constant TRUE, i.e. a statement
         * qualified by a NULL condition always applies.
         */
        Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::VariantExpression productFamilyCondition;
        /**
         * A VariantExpression specifying a condition under which the default rule applies.
         * NULL conditions behave as if they were equivalent to the Boolean constant TRUE, i.e.
         * a statement qualified by a NULL condition always applies.
         */
        Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::VariantExpression applicabilityCondition;
        /**
         * The sequence number this default rule has relative to other default rules in the
         * same context.
         */
        int sequence;
        /**
         * The object managing the additional properties of this derived default rule. It can
         * be used to identify the object in an ActionCode::ActionCodeRemove operation. Properties
         * of the descriptor object can help further describe this default rule, for example:
         * last modifying user, name, and description.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Fnd0DerivedDefaultRule>  defaultRule;
        /**
         * Derived default rule business object type which should be created. This is an optional
         * property. If empty value is provided, Fnd0DerivedDefaultRule is used as business
         * object type. Business object type specified in this property must be either Fnd0DerivedDefaultRule
         * or its sub type.
         */
        std::string boType;
        /**
         * The list of properties and their values which need to be set when creating the new
         * object of the type specified by <code>boType</code> property. The properties in this
         * map must be available on create descriptor of object being created.
         */
        AttributeInfoMap attrInfo;
    };

    /**
     * Contains a list of derived default rules for variant options.
     */
    struct DerivedDefaultRuleResponse
    {
        /**
         * The set of default rules for each input variant option family.
         */
        std::vector< Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::DerivedDefaultRuleExpression > defaultRules;
        /**
         * The service data for errors and returned objects.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Represents a default rule for a given variant option family. The structure is interpreted
     * as "<code>NULL</code>" if it has the following values set for its parameters:
     * <br>
     * <code>defaultAssignment</code> : A <code>NULL VariabilityExpression</code> structure
     * <br>
     * <code>defaultRule</code> : <code>NULLTAG</code>
     * <br>
     * <code>boType</code> : An empty ( "" ) string
     * <br>
     * <code>attrInfo</code> : An empty map
     * <br>
     * <code>clientId</code> : An empty ( "" ) string
     */
    struct FixedDefaultRuleExpression
    {
        /**
         * This unique ID is used to identify return data elements and partial errors associated
         * with this structure.
         */
        std::string clientId;
        /**
         * The value, or set of values, or range of values, to assign to a family by default
         * for the product family identified by productFamilyCondition provided that applicabilityCondition
         * is met.
         */
        Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::VariabilityExpression defaultAssignment;
        /**
         * The object managing the additional properties of this default rule. It can be used
         * to identify the object in an ActionCode::ActionCodeRemove operation. Properties of
         * the descriptor object can help further describe this default rule, for example: last
         * modifying user, name, and description.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Fnd0FixedDefaultRule>  defaultRule;
        /**
         * Fixed default rule business object type which should be created. This is an optional
         * property. If empty value is provided, Fnd0FixedDefaultRule is used as business object
         * type. Business object type specified in this property must be either Fnd0FixedDefaultRule
         * or its sub type.
         */
        std::string boType;
        /**
         * The list of properties and their values which need to be set when creating the new
         * object of the type specified by <code>boType</code> property. The properties in this
         * map must be available on create descriptor of object being created.
         */
        AttributeInfoMap attrInfo;
    };

    /**
     * Contains a list of fixed default rules for variant options.
     */
    struct FixedDefaultRuleResponse
    {
        /**
         * A list of fixed default rules that match the given search and filter criteria.
         */
        std::vector< Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::FixedDefaultRuleExpression > defaultRules;
        /**
         * The service data for errors and returned objects.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure provides information needed for creating or updating option family
     * groups.
     */
    struct OptionFamilyGroup
    {
        /**
         * This unique ID is used to identify return data elements and partial errors associated
         * with this structure.
         */
        std::string clientId;
        /**
         * Name of the <b>Fnd0OptionFamilyGroup</b> object to be created or to be updated with
         * a new name. This parameter cannot be empty when creating new groups. For update or
         * delete operations this parameter is optional.
         */
        std::string familyGroupName;
        /**
         * Description of the <b>Fnd0OptionFamilyGroup</b> object. This is an optional parameter.
         */
        std::string familyGroupDesc;
        /**
         * Position at which this <b>Fnd0OptionFamilyGroup</b> object should be created, or
         * the new index position of the <b>Fnd0OptionFamilyGroup</b> object in context of an
         * Item Revision. A value of -1 creates or moves the group to the end.
         */
        int sequence;
        /**
         * List of Variant Option Families containing Variant objects. This parameter will contain
         * a complete list of variant option family objects to group. In case of update, the
         * list of option families will be overwritten in <b>Fnd0OptionFamilyGroup</b> object
         * in same order in which they appear in this list.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Variant>  > optionFamilies;
        /**
         * <b>Fnd0OptionFamilyGroup</b> object. The operation creates a new <b>Fnd0OptionFamilyGroup</b>
         * object if this parameter is NULL. Otherwise it updates / deletes the specified object.
         * Whenever <b>Fnd0OptionFamilyGroup</b> objects are updated that are shared among different
         * item revisions, new copies of the groups are created before they are modified. If
         * so the group parameter in the <code>OptionFamilyGroupOutput</code> structure references
         * the new modified group. Callers can associate inputs with outputs based on the <code>clientId</code>.
         * If corresponding input and output structures reference different group objects the
         * server has copied and modified a new group object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Fnd0OptionFamilyGroup>  group;
        /**
         * Business object type of the new Option Family Group object, for example: <b>Fnd0OptionFamilyGroup</b>
         * or a sub type name. If this parameter is empty, <b>Fnd0OptionFamilyGroup</b> will
         * be assumed when creating a new group. When updating a group the parameter is expected
         * to be empty or equal to the type name of the <code>group</code> parameter.
         */
        std::string boType;
        /**
         * The list of properties and their values which need to be set when creating the new
         * object of the type specified by <code>boType</code> property. The properties in this
         * map must be available on create descriptor of object being created.
         */
        AttributeInfoMap attrInfoMap;
        /**
         * If true, the specified <b>Fnd0OptionFamilyGroup</b> object will be deleted. Deleted
         * groups are reported in the service data of the response.
         */
        bool remove;
    };

    /**
     * A vector of GroupInfo structures that provide information needed for creating or
     * updating group information in the context of an Item Revision.
     */
    struct OptionFamilyGroupInfo
    {
        /**
         * This unique ID is used to identify return data elements and partial errors associated
         * with this structure.
         */
        std::string clientId;
        /**
         * The <b>ItemRevision</b> of the owning Item in which context <b>Fnd0OptionFamilyGroup</b>
         * object should be created or updated.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  contextRevision;
        /**
         * A list of <code>OptionFamilyGroup</code> objects which provides information to create/update
         * the Option Family Groups in context of an Item Revision.
         */
        std::vector< Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::OptionFamilyGroup > groups;
    };

    /**
     * Represents a created or updated group with an input OptionFamilyGroup structure based
     * on a client ID.
     */
    struct OptionFamilyGroupOutput
    {
        /**
         * This unique ID is used to identify return data elements and partial errors associated
         * with this structure.
         */
        std::string clientId;
        /**
         * <b>Fnd0OptionFamilyGroup</b> object which is created or updated.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Fnd0OptionFamilyGroup>  group;
    };

    /**
     * A structure to contain the list of groups created or updated.
     */
    struct OptionFamilyGroupsOutput
    {
        /**
         * This unique ID is used to identify return data elements and partial errors associated
         * with this structure.
         */
        std::string clientId;
        /**
         * A list of <code>OptionFamilyGroupOutput</code> objects which contains created/updated
         * <b>Fnd0OptionFamilyGroup</b> objects.
         */
        std::vector< Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::OptionFamilyGroupOutput > groups;
    };

    /**
     * Contains a list of groups created or updated.
     */
    struct OptionFamilyGroupsResponse
    {
        /**
         * List of <code>OptionFamilyGroupsOutput</code> objects. These objects have information
         * of created or updated <b>Fnd0OptionFamilyGroup</b> objects.
         */
        std::vector< Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::OptionFamilyGroupsOutput > groupsData;
        /**
         * The service data for errors and returned objects.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Contains a list of variant option values, or value ranges, that have been allocated
     * to the context <b>ItemRevision</b>.
     */
    struct VariabilityAllocationResponse
    {
        /**
         * A vector of <code>VariabilityExpression</code> structures defining the total  variability
         * for the <b>ItemRevision</b> specified by the <code>contextRevision</code> input parameter.
         */
        std::vector< Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::VariabilityExpression > variability;
        /**
         * The service data for errors and returned objects.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Contains a list of variant expressions.
     */
    struct VariantExpressionResponse
    {
        /**
         * List of converted <code>VariantExpression</code> structures. The sequence in this
         * list corresponds to the input parameter <code>variantExpressions</code>.
         */
        std::vector< Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::VariantExpression > variantExpressions;
        /**
         * The service data for errors and returned objects.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Represents a variant option family. The family is either directly specified with
     * parameter "<code>familyObject</code>", or is indirectly defined by the combination
     * of the owning item given in parameter "<code>namespaceItem</code>" together with
     * parameter "<code>familyName</code>". The structure is interpreted to be "<code>NULL</code>"
     * if the following values are set to its parameters:
     * <br>
     * <code>namespaceItem</code> : <code>NULLTAG</code>
     * <br>
     * <code>familyName</code> : An empty ( "" ) string
     * <br>
     * <code>familyDescription</code> : An empty ( "" ) string
     * <br>
     * <code>unitOfMeasure</code> : <code>NULLTAG</code>
     * <br>
     * <code>valueDataType</code> : -1
     * <br>
     * <code>hasNonExclusiveValues</code> : <code>false</code>
     * <br>
     * <code>supportsFreeFormValues</code> : <code>false</code>
     * <br>
     * <code>isDiscretionary</code> : <code>false</code>
     * <br>
     * <code>isModelDesignationRelevant</code> : <code>false</code>
     * <br>
     * <code>minimumValue</code> : An empty ( "" ) string
     * <br>
     * <code>maximumValue</code> : An empty ( "" ) string
     * <br>
     * <code>values</code> : An empty vector of <code>VariantOptionValue</code> structure
     * <br>
     * <code>fixedDefaultRule</code> : An empty <code>FixedDefaultRuleExpression</code>
     * structure
     */
    struct VariantOptionFamily
    {
        /**
         * This unique ID is used to identify return data elements and partial errors associated
         * with this structure.
         */
        std::string clientId;
        /**
         * The <b>Item</b> owning the variant family for which data should be created or updated.
         * The owning item serves as a namespace in which the variant option family has a well-defined
         * meaning
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Item>  namespaceItem;
        /**
         * The name of the variant option family. The name is unique within its namespace.
         */
        std::string familyName;
        /**
         * The persistent object that represents this variant option family.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Variant>  familyObject;
        /**
         * The description of the variant option family.
         */
        std::string familyDescription;
        /**
         * The unit of measure used for all values in this family.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::UnitOfMeasure>  unitOfMeasure;
        /**
         * Indicates the value data type for values assigned to this variant option family.
         * Possible values are defined in ps/ps_tokens.h, for example:<code> PS_variant_option_mode_dynamic_compariso</code>n
         * |  <code>PS_variant_option_mode_numeric_comparison</code> | <code>PS_variant_option_mode_integer_comparison</code>
         * for a variant option family with integer values. It generally is a problem to use
         * <code>EQUAL</code> comparators for variant conditions involving numeric variant option
         * families unless the <code>PS_variant_option_mode_integer_comparison</code> behavior
         * is specified. It is often better to use inequality comparators like<code> LESS_THAN</code>
         * for variant conditions involving numeric variant option families so to describe a
         * value range.
         */
        int valueDataType;
        /**
         * If true, valid product configurations may exist that select more than one value of
         * this family at the same type, for example: multiple values of an "accessories" family.
         */
        bool hasNonExclusiveValues;
        /**
         * If true, variant conditions and configurations can assign free form values to this
         * family. Configurung a product withvariant conditions referencing expressions using
         * EQUAL comparators for families with free-form values may present problems if the
         * user editing the configuration cannot anticipate the exact value to enter. It is
         * therefore usually better to use inequality comparators like LESS_THAN for variant
         * conditions so to describe a value range.
         */
        bool supportsFreeFormValues;
        /**
         * If true, valid and complete product configurations may exist that don't select any
         * value in this family. Selecting none of the values in such a family means <i>"none
         * of these values</i>", for example: for an "accessories" family.
         * <br>
         * If false, all valid configurations are expected select a value to be complete. Selecting
         * none of the values means "<i>irrespective of</i>".
         */
        bool isDiscretionary;
        /**
         * If true, the family is used in model designators, which identify a family of product
         * variants. Model designators summarize product variants having significant business
         * process relevant characteristics in common. The variant option families representing
         * these <i>"significant business process relevant characteristics</i>" use a <code>isModelDesignationRelevant</code>
         * value of "true", for example: variant option family "Series". Model designation relevant
         * variant option families are expected to be used in "While" conditions for defaults
         * and constraints.
         */
        bool isModelDesignationRelevant;
        /**
         * If <code>supportsFreeFormValues</code> is "true" this parameter specifies the minimum
         * value that can be assigned to this family. An empty value indicates that no lower
         * bound exists.
         */
        std::string minimumValue;
        /**
         * If <code>supportsFreeFormValues</code> is "true" this parameter specifies the maximum
         * value that can be assigned to this family. An empty value indicates that no upper
         * bound exists.
         */
        std::string maximumValue;
        /**
         * A list of available variant option values.
         */
        std::vector< Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::VariantOptionValue > values;
        /**
         * Provides information on the fixed default for this family. Information is given using
         * <code>FixedDefaultRuleExpression</code> structure.
         */
        Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::FixedDefaultRuleExpression fixedDefaultRule;
    };

    /**
     * Contains a list of variant option families.
     */
    struct VariantOptionResponse
    {
        /**
         * Vector of updated or created variant option families.
         */
        std::vector< Fnd0::Services::Configuratoradmin::_2013_05::Variantadmin::VariantOptionFamily > variantOptions;
        /**
         * The service data for errors and returned objects.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




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


protected:
    virtual ~Variantadmin() {}
};
            }
        }
    }
}

#include <fnd0/services/configuratoradmin/ConfiguratorAdmin_undef.h>
#endif

