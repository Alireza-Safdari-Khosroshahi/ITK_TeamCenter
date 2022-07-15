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

#ifndef FND0_SERVICES_CONFIGFILTERCRITERIA__2013_05_VARIANTMANAGEMENT_HXX
#define FND0_SERVICES_CONFIGFILTERCRITERIA__2013_05_VARIANTMANAGEMENT_HXX

#include <teamcenter/soa/client/model/ConfigurationFamily.hxx>
#include <teamcenter/soa/client/model/Fnd0OptionValue.hxx>
#include <teamcenter/soa/client/model/POM_object.hxx>
#include <teamcenter/soa/client/model/Variant.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <fnd0/services/configfiltercriteria/ConfigFilterCriteria_exports.h>

namespace Fnd0
{
    namespace Services
    {
        namespace Configfiltercriteria
        {
            namespace _2013_05
            {
                class Variantmanagement;

class FND0SOACONFIGFILTERCRITERIASTRONGMNGD_API Variantmanagement
{
public:

    struct AvailableProductVariabilityResponse;
    struct TeamcenterConfiguratorInfo;
    struct ConfigOption;
    struct ConfigFormula;
    struct ConfigExpression;
    struct AvailableVariability;
    struct ConfigRuleViolation;
    struct ConfigurableProductsResponse;
    struct DefaultRule;
    struct OverlapStateList;
    struct ProductInfo;
    struct SetVariantConditionResponse;
    struct VariantCondition;
    struct VariantConditionInput;
    struct VariantConditionOutput;
    struct VariantConditionResponse;
    struct VariantCriteria;
    struct VariantCriteriaResponse;
    struct VariantExpressionsResponse;
    struct VariantOverlapStateResponse;
    struct VariantValidationRecord;

    /**
     * Severity code for error message.
     */
    enum ConstraintSeverity{ ConstraintSeverityInformation,
                 ConstraintSeverityWarning,
                 ConstraintSeverityError
                 };

    /**
     * Specifies the requested format for variant expression formula strings.
     */
    enum FormulaFormat{ UseDefaultFormat,
                 ShowFamilyAndItem,
                 ShowFamilyHideItem,
                 HideFamilyAndItem
                 };

    /**
     * Overlap enumration state.
     */
    enum OverlapState{ OverlapStateNone,
                 OverlapStateSubset,
                 OverlapStateMatch,
                 OverlapStateSuperset,
                 OverlapStateIntersect
                 };

    /**
     * A list of variant option values, or value ranges, that is available for a given product.
     */
    struct AvailableProductVariabilityResponse
    {
        /**
         * A list of <code>AvailableVariability</code> expressions defining available variability.
         * The number of elements in this list corresponds to the number of elements in the
         * input parameter <code>familiesToTest</code>. If an empty <code>familiesToTest</code>
         * list was specified the number of elements in this list corresponds to the number
         * of elements in the assumed list of families that is derived from input parameters
         * <code>exprsToTest</code> and <code>variantCriteriaObject</code>.
         */
        std::vector< Fnd0::Services::Configfiltercriteria::_2013_05::Variantmanagement::AvailableVariability > availabilityExpressions;
        /**
         * The service data for errors and returned objects.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Contains additional information about variant data that is only available when using
     * Teamcenter configurators. For any non Teamcenter configurator, this structure may
     * contain null elements.
     * <br>
     * The <code>TeamcenterConfiguratorInfo</code> structure is interoperated as "NULL"
     * if it has following values set for its parameters:
     * <br>
     * variant : NULLTAG
     * <br>
     * optionValue : NULLTAG
     * <br>
     */
    struct TeamcenterConfiguratorInfo
    {
        /**
         * Teamcenter family business object of type <b>Variant</b>. It can be null if information
         * is retrieved from non Teamcenter configurator.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Variant>  variant;
        /**
         * Workspace representation of option value code. This parameter can be null if information
         * is being retrieved from non Teamcenter configurator.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Fnd0OptionValue>  optionValue;
    };

    /**
     * Represents a configuration option that is unique in the context of a <b>ConfigurationFamily</b>.
     * <br>
     * The ConfigOption structure is interpreted as "NULL" if it has the following values
     * set for its parameters:  family: NULLTAG
     * <br>
     * valueCode: empty string ("")
     * <br>
     * description: empty string ("")
     * <br>
     * additionalInfo : Null Structure
     * <br>
     */
    struct ConfigOption
    {
        /**
         * A <b>ConfigurationFamily</b> object which represents a configuration option.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ConfigurationFamily>  family;
        /**
         * Name of the option value. "" is treated as NO VALUE SELECTED, i.e. it does not match
         * any non-empty name.
         */
        std::string valueCode;
        /**
         * Description of the option value.
         */
        std::string description;
        /**
         * A <code>TeamcenterConfiguratorInfo</code> struct having additional information about
         * Teamcenter configurator objects.
         */
        Fnd0::Services::Configfiltercriteria::_2013_05::Variantmanagement::TeamcenterConfiguratorInfo additionalInfo;
    };

    /**
     * Represents a formula string associated with a configuration expression in configurator
     * syntax.  A formula of the form "[OptionNamespace]FamilyName = UniqueValue" is called
     * "explicit" because no product context is required to determine the family name for
     * the value, or the option namespace for the family name. OptionNamespace and FamilyName
     * are explicitly spelled out. A variant formula is in "explicit Teamcenter language"
     * if its form is explicit and comprised of the lexemes documented for the Variant Formula
     * property. A formula of the form "UniqueValue" is called "stenographic" because a
     * parser has to infer OptionNamespace and FamilyName. This is possible if there is
     * only one value with that name throughout the entire product. If lexemes other than
     * those documented for the Variant Formula property are used the formula is in "external
     * variant language" and a custom configurator is required to decode the formula. If
     * a formula is explicit Teamcenter language, productName and productNameSpace can be
     * empty (""). The ConfigFormula structure is considered "NULL" if it has following
     * values set for its parameters: - formula: empty string ("") - productName: empty
     * string ("") - productNameSpace: empty string ("")
     */
    struct ConfigFormula
    {
        /**
         * Formula string in configurator syntax.
         */
        std::string formula;
        /**
         * Name of the product(e.g.ItemID). Used in conjunction with productNameSpace parameter
         * to resolve any ambiguity in variant option value names.
         */
        std::string productName;
        /**
         * Namespace of the product in which the "product" has unique semantics, e.g., ItemRevID,
         * model_year or product_type. Used in conjunction with productName parameter to resolve
         * any ambiguity in variant option value names.
         */
        std::string productNameSpace;
    };

    /**
     * Represents a configuration expression. The <code>ConfigExpression</code> structure
     * is interpreted as "<code>NULL</code>" when it has following values set for its parameters:
     * <br>
     * <code>subExpressions</code> : An empty vector of <code>ConfigExpression</code> structure
     * <br>
     * <code>value</code> : A "NULL" <code>ConfigOption</code> structure
     * <br>
     * <code>opCode</code> : -1
     * <br>
     * <code>formula</code> : A "NULL" <code>ConfigFormula</code> structure
     * <br>
     * <code>tnf</code> : An empty vector of <code>ConfixExpression</code> structures.
     * <br>
     * A <code>ConfigExpression</code> that is equivalent to the Boolean constant <code>TRUE</code>
     * returns a TNF parameter comprising one expression with an <code>opcode</code> value
     * of <code>39</code>.
     * <br>
     * A <code>ConfigExpression</code> that is equivalent to the Boolean constant <code>FALSE</code>
     * returns a TNF parameter comprising one expression with an <code>opcode</code> value
     * of <code>40</code>.
     */
    struct ConfigExpression
    {
        /**
         * A vector of <code>ConfigExpression</code>. If this parameter is present the enclosing
         * expression represents a compound expression combining this set of subexpressions
         * with the operator specified in the opCode parameter. If the enclosing expression
         * is non-NULL either this parameter or the "<code>value</code>" parameter must be present.
         */
        std::vector< Fnd0::Services::Configfiltercriteria::_2013_05::Variantmanagement::ConfigExpression > subExpressions;
        /**
         * It is a <code>ConfigOption</code> struct. If this parameter is present the enclosing
         * expression represents an elemental expression literal. The parameter specifies the
         * value to which <code>opCode</code> compares. If the enclosing expression is non-NULL
         * either this parameter or the <code>subExpressions</code> parameter must be present.
         * <code>subExpressions</code> <code>and</code> value must not both be present.
         */
        Fnd0::Services::Configfiltercriteria::_2013_05::Variantmanagement::ConfigOption value;
        /**
         * Operation code such as "and" and "or", see ps/ps_tokens.h.
         */
        int opCode;
        /**
         * It is a <code>ConfigFormula</code> struct. If present, contains the configuration
         * expression in string format (courtesy info).
         */
        Fnd0::Services::Configfiltercriteria::_2013_05::Variantmanagement::ConfigFormula formula;
        /**
         * If present, this parameter provides a representation of the enclosing expression
         * in Teamcenter Normal Form (TNF).
         * <br>
         * The parameter is intended as "courtesy information" so to make additional SOA calls
         * unnecessary by providing information that is expected to be of value if performance
         * permits it. Based on the assumption that the vast majority of ConfigExpression structs
         * can be converted to TNF very efficiently the server can afford to convert them to
         * TNF as a "free gift". If this becomes a performance bottleneck the server may return
         * a response with an empty tnf member, in which case the application can explicitly
         * request a tnf representation using operation <code>convertVariantExpressions</code>,
         * if need be. Preference <code>TC_tnf_timeout_period</code> controls the timeout mechanism.
         * If TNF generation takes more time than specified in preference <code>TC_tnf_timeout_period</code>,
         * server returns an empty <code>tnf</code> member.
         * <br>
         * If combined with OR the list of tnf expressions is logically equivalent to the enclosing
         * expression. Each TNF is provided as a conjunction of Disjunctive Normal Forms (DNF)
         * where all DNFs reference a single variant option family. Each clause in the outermost
         * conjunction can reference a different variant option family.
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
        std::vector< Fnd0::Services::Configfiltercriteria::_2013_05::Variantmanagement::ConfigExpression > tnf;
    };

    /**
     * Defines available variant option values for a given variant option family along with
     * the default value for operation <code>getAvailableProductVariability</code>. The
     * <code>AvailableVariability</code> structure is interpreted as "NULL" if it has the
     * following values set for its parameters: defaultValue: NULL structure
     * <br>
     * minimumValue : An empty ( "" ) string
     * <br>
     * maximumValue : An empty ( "" ) string
     * <br>
     * availability: NULL structure
     * <br>
     */
    struct AvailableVariability
    {
        /**
         * Specifies the variant option family and optionally its default value. If no default
         * rules exist, or they select a default value that is ruled out due to other constraints,
         * the ConfigOption structure will only specify the family along with an empty "name"
         * parameter to indicate a non-existing value.
         */
        Fnd0::Services::Configfiltercriteria::_2013_05::Variantmanagement::ConfigOption defaultValue;
        /**
         * A configuration expression referencing only values for the family specified in the
         * option parameter. This could be a list of ORed discrete values, e.g. "(L=1 | L=2)"
         * or a list of ORed ranges consisting of minimum and maximum expressions, e.g. "W>10
         * & W<20".
         */
        Fnd0::Services::Configfiltercriteria::_2013_05::Variantmanagement::ConfigExpression availability;
        /**
         * Minimum value in a range expression of domain of family value.
         */
        std::string minimumValue;
        /**
         * Maximum value in a range expression of domain of family values.
         */
        std::string maximumValue;
    };

    /**
     * Represents a violated rule along with the message and severity associated with rule
     * violation.  The <code>ConfigRuleViolation</code> structure is interpreted to be "NULL"
     * if following values are set to its parameters:
     * <br>
     * - <code>message</code>: empty string ("")
     * <br>
     * - <code>severity</code>: ConstraintSeverityInformation
     * <br>
     * - <code>violatedCondition</code>: a "NULL" <code>ConfigExpression</code> structure
     */
    struct ConfigRuleViolation
    {
        /**
         * The message to display if this rule is violated.
         */
        std::string message;
        /**
         * The severity code for the message. Valid values are:
         * <br>
         * - ConstraintSeverityInformation : Classifies information associated with this constraint
         * as additional information, such as hints, which are of interest if configuration
         * criteria satisfy this constraint.
         * <br>
         * - ConstraintSeverityWarning : Classifies information associated with this constraint
         * as considerations, such as recommendations, which are important to review if configuration
         * criteria satisfy this constraint.
         * <br>
         * - ConstraintSeverityError : Configuration criteria that satisfy this constraint
         * are classified as invalid.
         */
        ConstraintSeverity severity;
        /**
         * The rule that was found to be violated.
         */
        Fnd0::Services::Configfiltercriteria::_2013_05::Variantmanagement::ConfigExpression violatedCondition;
    };

    /**
     * Contains a list of products defining variant configuration data that can be used
     * to configure this product.
     */
    struct ConfigurableProductsResponse
    {
        /**
         * A vector of <code>ProductInfo</code> structures listing all variant configurable
         * products defined in the configurator.
         */
        std::vector< Fnd0::Services::Configfiltercriteria::_2013_05::Variantmanagement::ProductInfo > configurableProducts;
        /**
         * The service data for errors and returned objects.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * A rule to determine the default value, or value range, for a variant option family.
     * The <code>DefaultRule</code> structure is interpreted to be "NULL" if it has following
     * values set to its parameters:
     * <br>
     * - <code>partiallyApplicable</code>: false
     * <br>
     * - <code>restrictiveCondition</code>: a "NULL" ConfigExpression
     * <br>
     * - <code>appliedDefault</code>: "NULL" ConfigExpression structure
     * <br>
     * - <code>appliedTo</code>: "NULL" ConfigExpression structure
     */
    struct DefaultRule
    {
        /**
         * If "true", the default is only applicable to a subset of the criteria (courtesy info).
         */
        bool partiallyApplicable;
        /**
         * The condition under which the default is applicable. Can be NULL.
         */
        Fnd0::Services::Configfiltercriteria::_2013_05::Variantmanagement::ConfigExpression restrictiveCondition;
        /**
         * The default condition that was applied, indicating that "<code>restrictiveCondition</code>"
         * was met.
         */
        Fnd0::Services::Configfiltercriteria::_2013_05::Variantmanagement::ConfigExpression appliedDefault;
        /**
         * The config condition before applying the default."<code>appliedDefault</code>".
         */
        Fnd0::Services::Configfiltercriteria::_2013_05::Variantmanagement::ConfigExpression appliedTo;
    };

    /**
     * List of overlap states.
     */
    struct OverlapStateList
    {
        /**
         * A vector of overlap enumeration values. Valid values for an overlap enumeration are:
         * <br>
         * -&nbsp;&nbsp;&nbsp;&nbsp;OverlapStateNone : The two expressions have no overlap.
         * There is no satisfing solution common to both expressions. A conjunction (AND combination)
         * of the two is unsatisfiable.
         * <br>
         * -&nbsp;&nbsp;&nbsp;&nbsp;OverlapStateSubset : The two expressions overlap. The expression's
         * solution set is a subset of the reference expression's solution set. The conjunction
         * (AND combination) of the expression with the negated reference expression is unsatisfiable.
         * <br>
         * -&nbsp;&nbsp;&nbsp;&nbsp;OverlapStateMatch : The two expressions are logically equivalent.
         * Every solution that satifies one expression also satifies the other, and vice versa.
         * <br>
         * -&nbsp;&nbsp;&nbsp;&nbsp;OverlapStateSuperset : The two expressions overlap. The
         * expression's solution set is a superset of the reference expression's solution set.
         * The conjunction (AND combination) of the negated expression with the reference expression
         * is unsatisfiable.
         * <br>
         * -&nbsp;&nbsp;&nbsp;&nbsp;OverlapStateIntersect : The two expressions overlap. The
         * expression's solution set has some overlap with the reference expression's solution
         * set.
         * <br>
         */
        std::vector< OverlapState > overlapStates;
    };

    /**
     * Identifies variant configurable products defined in the variant configurator.
     * <br>
     * The  <code>ProductInfo</code> structure is interpreted as "NULL" if it has the following
     * values set for its parameters:
     * <br>
     * productName : An empty ( "" ) string
     * <br>
     * productNameSpace : An empty ( "" ) string
     * <br>
     */
    struct ProductInfo
    {
        /**
         * Identifies the product. It is used in conjunction with parameter <code>productNameSpace</code>
         * to resolve potential ambiguity in variant option value names, and to identify product
         * context specific constraints. Teamcenter configurators use a Multiple Field Key (MFK)
         * stable identifier (see property <code>Item::fnd0VariantNamespace</code>) of the product
         * item for <code>productName</code>. The <code>productName</code> value for a Collaborative
         * Design (<b>Cpd0CollaborativeDesign</b>) can be obtained from property <code>Mdl0ApplicationModel::mdl0config_product_name</code>.
         */
        std::string productName;
        /**
         * Specifies the namespace for the product identifier. It is used in conjunction with
         * parameter <code>productName</code> to resolve potential ambiguity in variant option
         * value names, and to identify product context specific constraints. Teamcenter configurators
         * use the Revision ID of the product ItemRevision for <code>productNameSpace</code>.
         * The <code>productNameSpace</code> value for a Collaborative Design (<b>Cpd0CollaborativeDesign</b>)
         * can be obtained from property <code>Mdl0ApplicationModel::mdl0config_prod_namespace</code>
         */
        std::string productNameSpace;
    };

    /**
     * Contains the resulting variant conditions and the objects they belong to.
     */
    struct SetVariantConditionResponse
    {
        /**
         * Vector of variant conditions attached to product elements.
         */
        std::vector< Fnd0::Services::Configfiltercriteria::_2013_05::Variantmanagement::VariantConditionOutput > variantConditionsOutput;
        /**
         * The service data for errors and returned objects.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Represents a variant expression that is associated to a product element. The <code>VariantCondition</code>
     * structure is interpreted to be "NULL" if the following values are set to its parameters:
     * <br>
     * - condition: a "NULL" <code>ConfigExpression</code> structure
     * <br>
     * - affectedElement: NULLTAG
     * <br>
     */
    struct VariantCondition
    {
        /**
         * The variant condition that is attached to affectedElement.
         */
        Fnd0::Services::Configfiltercriteria::_2013_05::Variantmanagement::ConfigExpression condition;
        /**
         * Product element to which the variant condition applies.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::POM_object>  affectedElement;
    };

    /**
     * <code>VariantConditionInput</code> is a structure to provide relevant inputs for
     * setting the variant condition.
     */
    struct VariantConditionInput
    {
        /**
         * This unique ID is used to identify return data elements and partial errors associated
         * with this input structure.
         */
        std::string clientId;
        /**
         * Objects, whose variant conditions should be combined and then copied to derive the
         * variant condition to be set on <code>affectedObjects</code>. These may include configurable
         * objects (e.g. Mdl0ConditionalElement) and/or criteria objects (e.g. VariantRule).
         * Can be empty.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::POM_object>  > sampleObjects;
        /**
         * Formulae to be included when deriving variant criteria for <code>affectedObjects</code>.
         * Can be empty.
         */
        std::vector< Fnd0::Services::Configfiltercriteria::_2013_05::Variantmanagement::ConfigFormula > formulae;
        /**
         * Configuration expressions to be included when deriving variant criteria for <code>affectedObjects</code>.
         * Can be empty.
         */
        std::vector< Fnd0::Services::Configfiltercriteria::_2013_05::Variantmanagement::ConfigExpression > expressions;
        /**
         * Specifies how to combine the inputs given in "<code>sampleObjects</code>", "<code>expressions</code>",
         * and "<code>formulae</code>". The values are defined in ps/ps_tokens.h, e.g. "10"
         * for "AND" , or "11" for "OR".
         */
        int opCode;
        /**
         * Represents the type of action to be performed with the derived variant condition.
         * Valid values are as follows:
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;1 - Overwrite (SET)
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;2 - Extend (OR)
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;4 - Reduce (AND)
         * <br>
         */
        int actionCode;
        /**
         * Represents product elements on which the variant condition needs to be set
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::POM_object>  > affectedObjects;
        /**
         * Represents the product elements that will be replaced by corresponding elements in
         * <code>affectedObjects</code>. The result is that the current variant scope for each
         * <code>replacedObject</code> is reduced by the variant scope assigned to <code>affectedObjects</code>
         * so that they don't have overlapping variants scopes.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::POM_object>  > replacedObjects;
    };

    /**
     * Returns the variant conditions and objects they belong to, that were modified in
     * the same transaction.
     */
    struct VariantConditionOutput
    {
        /**
         * Client ID to map input information with output information.
         */
        std::string clientId;
        /**
         * List of variant conditions.
         */
        std::vector< Fnd0::Services::Configfiltercriteria::_2013_05::Variantmanagement::VariantCondition > variantConditions;
    };

    /**
     * Returns variant conditions and the objects they belong to.
     */
    struct VariantConditionResponse
    {
        /**
         * Vector of variant conditions attached to product elements.
         */
        std::vector< Fnd0::Services::Configfiltercriteria::_2013_05::Variantmanagement::VariantCondition > variantConditions;
        /**
         * The service data for errors and returned objects.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The <code>VariantCriteria</code> structure represents a criteria object along with
     * its variant criteria and associated validation records. The <code>VariantCriteria</code>
     * structure is interpreted to be "NULL" if the following values are set for its parameters:
     * - <code>variantCriteriaObject</code>: NULLTAG - <code>primaryVariantScope</code>:
     * a "NULL" ConfigFormula structure - <code>solveType</code>: -1 - <code>validationRecords</code>:
     * empty vector
     */
    struct VariantCriteria
    {
        /**
         * The <b>VariantRule</b> with which the criteria defines in this structure is associated.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::POM_object>  variantCriteriaObject;
        /**
         * Nominal variant criteria before applying constraints and defaults.
         */
        Fnd0::Services::Configfiltercriteria::_2013_05::Variantmanagement::ConfigExpression primaryVariantScope;
        /**
         * Indicates how the variant criteria need to be solved. For possible values see preference
         * <code>TC_Default_Solve_Type</code>.
         */
        int solveType;
        /**
         * Validation records related to the variant criteria.
         */
        std::vector< Fnd0::Services::Configfiltercriteria::_2013_05::Variantmanagement::VariantValidationRecord > validationRecords;
    };

    /**
     * Returns variant configuration criteria along with default and constraint processing
     * results.
     */
    struct VariantCriteriaResponse
    {
        /**
         * Vector of variant criteria structures
         */
        std::vector< Fnd0::Services::Configfiltercriteria::_2013_05::Variantmanagement::VariantCriteria > variantCriteria;
        /**
         * Teamcenter ServiceData
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Returns variant expressions in the requested output representation.
     */
    struct VariantExpressionsResponse
    {
        /**
         * List of converted <code>ConfigExpression</code> structures. The sequence in this
         * list corresponds to the input parameter <code>variantExpressions</code>.
         */
        std::vector< Fnd0::Services::Configfiltercriteria::_2013_05::Variantmanagement::ConfigExpression > variantExpressions;
        /**
         * The service data for errors and returned objects.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Indicates the degreee of overlap for pairs of variant expressions.
     */
    struct VariantOverlapStateResponse
    {
        /**
         * A vector of vectors of overlap enumeration values. The first vector lists overlap
         * states for all expressions with the first reference variant criteria expression.
         * The sequence of overlap states corresponds to the sequence of input expressions.
         */
        std::vector< Fnd0::Services::Configfiltercriteria::_2013_05::Variantmanagement::OverlapStateList > overlapStates;
        /**
         * The service data for errors and returned objects.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Represents validation results for variant criteria associated with a variant criteria
     * object (<b>VariantRule</b> ). The <code>VariantValidationRecord</code> structure
     * is interpreted to be "NULL" if the following values are set to its parameters:
     * <br>
     * <code>-validationDate</code>: a NULLDATE as defined for the SOA client side binding
     * in use.
     * <br>
     * <code>-validationResult</code>: a "NULL" ConfigFormula structure
     * <br>
     * <code>-undeterminedFamilies</code>: an empty vector
     * <br>
     * <code>-violations</code>: an empty vector
     * <br>
     * <code>-appliedDefaults</code>: an empty vector
     */
    struct VariantValidationRecord
    {
        /**
         * Date of validation.
         */
        Teamcenter::Soa::Common::DateTime validationDate;
        /**
         * Validation result reflecting constraints and defaults.
         */
        Fnd0::Services::Configfiltercriteria::_2013_05::Variantmanagement::ConfigExpression validationResult;
        /**
         * Families that are not set to a unique value. If empty, the criteria are complete.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ConfigurationFamily>  > undeterminedFamilies;
        /**
         * Violation records. If empty, the variant criteria are valid.
         */
        std::vector< Fnd0::Services::Configfiltercriteria::_2013_05::Variantmanagement::ConfigRuleViolation > violations;
        /**
         * One record for each applied default in the sequence they were applied.
         */
        std::vector< Fnd0::Services::Configfiltercriteria::_2013_05::Variantmanagement::DefaultRule > appliedDefaults;
    };




    /**
     * Service interface <code>ConfigFilterCriteria</code> uses 3 different representations
     * for variant expressions:
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
     * A user has received a configuration expression in form of a fully qualified configuration
     * formula string from another operation, e.g. <code>getVariantCriteria</code> might
     * have returned <code>"([MANUFACTURING]Height = '9 mm' | [ENGINEERING]Size = '2.5"')
     * & ([ENGINEERING]Capacity = '512 GB' | [ENGINEERING]Size = '1.8"') & ([ENGINEERING]Capacity
     * = '320 GB' | [MANUFACTURING]Height = '7 mm') & ([MODEL]Model = SSD | [ENGINEERING]Capacity
     * = '320 GB') & ([MODEL]Model = 'HDD 7200' | [ENGINEERING]Capacity = '512 GB')". </code>
     * <br>
     * In many cases, configuration expressions are easier to apprehend in TNF. Therefore
     * the user calls operation <code>convertVariantExpressions</code> to convert the expression
     * into the following 2 TNFs:
     * <br>
     * <code>1.&nbsp;&nbsp;&nbsp;&nbsp;[MODEL]Model=SSD & [ENGINEERING]Capacity='512 GB'
     * & [ENGINEERING]Size='2.5"' & [MANUFACTURING]Height='7 mm'
     * <br>
     * 2.&nbsp;&nbsp;&nbsp;&nbsp;[MODEL]Model='HDD 7200' & [ENGINEERING]Capacity='320 GB'
     * & [ENGINEERING]Size='1.8"' & [MANUFACTURING]Height='9 mm'</code>
     * <br>
     * In addition the user requests a different formula string format that hides family
     * name and family namespace for ease of reading:
     * <br>
     * <ul>
     * <li type="disc"><code>('9 mm' | '2.5"') & ('512 GB' | '1.8"') & ('320 GB' | '7 mm')
     * & (SSD | '320 GB') & ('HDD 7200' | '512 GB')</code>
     * </li>
     * </ul>
     * <br>
     * Operations in service interface <code>ConfigFilterCriteria</code>, e.g. <code>getVariantCriteria</code>,
     * automatically return <code>ConfigExpression</code> structs with a TNF representation
     * unless TNF normalization times out while generating the response structure. In that
     * case operation <code>convertVariantExpressions</code> can be used to explicitly request
     * TNF normalization.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * getDerivedDefaultRules
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Configuration Management - Capability to configure structured data based on revsion
     * rules; effectivities; Status etc.
     *
     * @param variantExpressions
     *        List of <code>ConfigExpression</code> structures having at least one of the 3 input
     *        formats populated.
     *
     * @param formulaFormat
     *        Specifies the format of the formula string in the response. Possible values are:
     *        <br>
     *        <ul>
     *        <li type="disc"><code>UseDefaultFormat</code>: Formula strings will be formatted
     *        according to Teamcenter preferences <b>TC_show_option_family_prefix</b> and <b>TC_show_option_item_prefix</b>.
     *        </li>
     *        <li type="disc"><code>ShowFamilyAndItem</code>: Formats formula string as if preferences
     *        <b>TC_show_option_family_prefix</b> and <b>TC_show_option_item_prefix</b> were temporarily
     *        set to TRUE.
     *        </li>
     *        <li type="disc"><code>ShowFamilyHideItem</code>: Formats formula strings as if preference
     *        <b>TC_show_option_family_prefix</b> was temporarily set to TRUE and preference <b>TC_show_option_item_prefix</b>
     *        was temporarily set to FALSE.
     *        </li>
     *        <li type="disc"><code>HideFamilyAndItem</code>: Formats formula strings as if preferences
     *        <b>TC_show_option_family_prefix</b> and <b>TC_show_option_item_prefix</b> were temporarily
     *        set to FALSE.
     *        </li>
     *        </ul>
     *        <br>
     *        Parameter <code>formulaFormat</code> does not affect the construction of Sub-expressions
     *        or TNF representations.
     *
     * @param productName
     *        Identifies the product. It is used in conjunction with parameter <code>productNameSpace</code>
     *        to resolve potential ambiguity in variant option value names, and to identify product
     *        context specific constraints. Teamcenter configurators use a Multiple Field Key (MFK)
     *        stable identifier (see property <code>Item::fnd0VariantNamespace</code>) of the product
     *        item for <code>productName</code>. The <code>productName</code> value for a Collaborative
     *        Design (<b>Cpd0CollaborativeDesign</b>) can be obtained from property <code>Mdl0ApplicationModel::mdl0config_product_name</code>.
     *
     * @param productNameSpace
     *        Specifies the namespace for the product identifier. It is used in conjunction with
     *        parameter <code>productName</code> to resolve potential ambiguity in variant option
     *        value names, and to identify product context specific constraints. Teamcenter configurators
     *        use the Revision ID of the product ItemRevision for <code>productNameSpace</code>.
     *        The <code>productNameSpace</code> value for a Collaborative Design (<b>Cpd0CollaborativeDesign</b>)
     *        can be obtained from property <code>Mdl0ApplicationModel::mdl0config_prod_namespace</code>.
     *
     * @param configuratorURL
     *        This is service end point for the variant configurator service. If empty the local
     *        Teamcenter configurator is used. Tc10.1 only supports local Teamcenter configurators.
     *        In Tc10.1 a non-empty <code>configuratorURL</code> parameter will cause an error.
     *
     * @return
     *         Converts given variant formulae (string representation) into variant expressions.
     *         ConfigurationFamily objects referenced from the response structure are added to the
     *         ServiceData as reference objects via ServiceData::addObject(). ServiceException is
     *         thrown when there is a failure in connecting to configurator. In all other cases,
     *         partial errors are returned in ServiceData.
     *
     *
     * @exception ServiceException
     *           This operation may raise <code>Teamcenter::Soa::Server::ServiceException</code>
     *           wrapping around following Teamcenter errors:
     *           <br>
     *           <br>
     *           39000+x&nbsp;&nbsp;&nbsp;&nbsp;Errors raised in module TCTYPE during property inflation
     *           in the service framework
     *           <br>
     *           38000+x&nbsp;&nbsp;&nbsp;&nbsp;Errors raised in module PROP during property inflation
     *           in the service framework
     *           <br>
     *           92001&nbsp;&nbsp;&nbsp;&nbsp;An internal error has occurred in then <code>Fnd0SoaConfigFilterCriteria</code>
     *           module
     *           <br>
     *           256000&nbsp;&nbsp;&nbsp;&nbsp;An internal configurator error occurred.
     *           <br>
     *           256001&nbsp;&nbsp;&nbsp;&nbsp;A general configurator error occurred.
     *           <br>
     *           256002&nbsp;&nbsp;&nbsp;&nbsp;The following product is invalid: [<i>DictionaryNamespace</i>]<i>FamilyName</i>
     *           (Context: <i>info</i>).
     *           <br>
     *           256003&nbsp;&nbsp;&nbsp;&nbsp;The following feature value is invalid: [<i>DictionaryNamespace</i>]<i>FamilyName</i>
     *           (<i>Context:</i> <i>info</i>).
     *           <br>
     *           256004&nbsp;&nbsp;&nbsp;&nbsp;The following feature family is invalid: [<i>DictionaryNamespace</i>]<i>FamilyName</i>
     *           (<i>Context:</i> <i>info</i>).
     *           <br>
     *           256005&nbsp;&nbsp;&nbsp;&nbsp;An invalid feature combination was found (<i>Context:
     *           info</i>).
     *           <br>
     *           256006&nbsp;&nbsp;&nbsp;&nbsp;An invalid product configuration was found (<i>Context:
     *           info</i>).
     *           <br>
     *           256007&nbsp;&nbsp;&nbsp;&nbsp;An invalid expression was found (<i>Context: info</i>).
     *           <br>
     *           256008&nbsp;&nbsp;&nbsp;&nbsp;The following Boolean operator is invalid: opcode (<i>Context:
     *           info</i>).
     *           <br>
     *           256009&nbsp;&nbsp;&nbsp;&nbsp;An invalid effectivity date was found (<i>Context:
     *           info</i>).
     *           <br>
     *           256010&nbsp;&nbsp;&nbsp;&nbsp;A time-out occurred (<i>Context: info</i>).
     *           <br>
     *           256011&nbsp;&nbsp;&nbsp;&nbsp;A resource is not available (<i>Context: info</i>).
     *           <br>
     *           256012&nbsp;&nbsp;&nbsp;&nbsp;The following <i>function</i>ality is not implemented:
     *           function (Version: <i>TcVersion</i>).
     *           <br>
     *           256013&nbsp;&nbsp;&nbsp;&nbsp;A configurator implementation specific error occurred
     *           (<i>Context: info</i>).
     *           <br>
     *           256014&nbsp;&nbsp;&nbsp;&nbsp;The effectivity expression contains unmatched quote
     *           at position <i>number</i>.
     *           <br>
     *           256015&nbsp;&nbsp;&nbsp;&nbsp;The effectivity expression contains unmatched bracket
     *           at <i>position number</i>.
     *           <br>
     *           256016&nbsp;&nbsp;&nbsp;&nbsp;An unexpected token '<i>text</i>' was found at position
     *           <i>number</i>.
     *           <br>
     *           256017&nbsp;&nbsp;&nbsp;&nbsp;The entry '<i>text</i>' was found at position <i>number</i>
     *           when an option value was expected.
     *           <br>
     *           256018&nbsp;&nbsp;&nbsp;&nbsp;The token '<i>text</i>' is missing after '<i>text</i>'
     *           at position <i>number</i>.
     *           <br>
     *           256019&nbsp;&nbsp;&nbsp;&nbsp;The effectivity expression adaptor does not support
     *           <i>text</i> used at position <i>number</i>.
     *           <br>
     *           256020&nbsp;&nbsp;&nbsp;&nbsp;The XML tag '<i>text</i>' has no text value.
     *           <br>
     *           256021&nbsp;&nbsp;&nbsp;&nbsp;The string '<i>formula</i>' cannot be converted into
     *           an expression.
     *           <br>
     *           256022&nbsp;&nbsp;&nbsp;&nbsp;The operator code '<i>opcode</i>' in token at position
     *           <i>number</i> is unknown.
     *           <br>
     *           256023&nbsp;&nbsp;&nbsp;&nbsp;The effectivity value '<i>text</i>' in token at position
     *           <i>number</i> is unknown.
     *           <br>
     *           256024&nbsp;&nbsp;&nbsp;&nbsp;The effectivity family '<i>text</i>' in token at position
     *           <i>number</i> is unknown.
     *           <br>
     *           256025&nbsp;&nbsp;&nbsp;&nbsp;An ambiguous option value name '<i>FamilyName</i>'
     *           in namespace '<i>DictionaryNamespace</i>' in token at position <i>number</i> was
     *           found: <i>text</i>.
     *           <br>
     *           256026&nbsp;&nbsp;&nbsp;&nbsp;An ambiguous option family name '<i>FamilyName</i>'
     *           in token at position number was found: '<i>text</i>'.
     *           <br>
     *           256027&nbsp;&nbsp;&nbsp;&nbsp;The option namespace '<i>DictionaryNamespace</i>' in
     *           token at position <i>number</i> is invalid.
     *           <br>
     *           256028&nbsp;&nbsp;&nbsp;&nbsp;The effectivity family '<i>FamilyName</i>' in token
     *           at position <i>number</i> is invalid.
     *           <br>
     *           256029&nbsp;&nbsp;&nbsp;&nbsp;The effectivity option value '<i>text</i>' for family
     *           '<i>FamilyName</i>' in token at position <i>number</i> is invalid.
     *           <br>
     *           256030&nbsp;&nbsp;&nbsp;&nbsp;The effectivity option value '<i>text</i>' for family
     *           '<i>FamilyName</i>' in token at position <i>number</i> is invalid: its value is not
     *           numeric.
     *           <br>
     *           256031&nbsp;&nbsp;&nbsp;&nbsp;The effectivity option value '<i>text</i>' for family
     *           '<i>FamilyName</i>' in token at position <i>number</i> is invalid: the value unit
     *           of measure '<i>text</i>' does not match the family unit of measure '<i>text</i>'.
     *           <br>
     *           256032&nbsp;&nbsp;&nbsp;&nbsp;The option / family / family namespace combination
     *           '<i>text</i>' / '<i>FamilyName</i>' / '<i>DictionaryNamespace</i>' in token at position
     *           <i>number</i> is invalid.
     *           <br>
     *           256033&nbsp;&nbsp;&nbsp;&nbsp;The family '<i>FamilyName</i>' for option / family
     *           namespace combination '<i>text</i>' / '<i>DictionaryNamespace</i>' in token at position
     *           <i>number</i> is invalid.
     *           <br>
     *           256034&nbsp;&nbsp;&nbsp;&nbsp;There is no option value in token at position <i>number</i>.
     *           <br>
     *           256035&nbsp;&nbsp;&nbsp;&nbsp;The effectivity option value '<i>text</i>' for family
     *           '<i>FamilyName</i>' in token at position '<i>number</i>' is invalid: the value is
     *           not a valid date.
     */
    virtual Fnd0::Services::Configfiltercriteria::_2013_05::Variantmanagement::VariantExpressionsResponse convertVariantExpressions ( const std::vector< Fnd0::Services::Configfiltercriteria::_2013_05::Variantmanagement::ConfigExpression >& variantExpressions,
        const FormulaFormat&  formulaFormat,
        const std::string&  productName,
        const std::string&  productNameSpace,
        const std::string&  configuratorURL ) = 0;

    /**
     * This operation returns available product variability that could be used to satisfy
     * the specified variant criteria object (<b>VariantRule</b>), or the subset of the
     * criteria as defined by parameters <code>exprsToTest</code> and <code>familiesToTest</code>.
     * <br>
     * Parameters <code>productName</code> and <code>productNameSpace</code> identify the
     * product whose constraints will be considered in this operation. Specifying empty
     * values for <code>productName</code> and <code>productNameSpace</code> will result
     * in a <code>ServiceException</code> based on a corresponding Teamcenter error code.
     * <br>
     * The service forms a configuration expression from the provided input parameters by
     * ORing the expressions in parameter <code>exprsToTest</code> (resulting in TRUE if
     * <code>exprsToTest</code> was empty), and ANDing the result with <code>variantCriteriaObject</code>
     * (if it is present). The response will return available variability that could be
     * used to satisfy this configuration expression.
     * <br>
     * If input parameters <code>variantCriteriaObject</code>, <code>exprsToTest</code>,
     * and <code>familiesToTest</code> are NULL, then the response will return the complete
     * variability for the product.
     * <br>
     * Symbolic variable substitution and / or constraint processing is applied to the variant
     * option families for which variability is returned (see above discussion about configuration
     * expression and parameter <code>familiesToTest</code>). Operation <code>Fnd0::Soa::ConfigFilterCriteria::_2013_05::VariantManagement::VariantManagementImpl::
     * getVariantCriteria</code> can be used if symbolic variable substitution and constraint
     * processing is required for all variant option families, or if validation records
     * are required that specify violated constraints.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Use case 1:
     * <br>
     * Initialize a variant criteria dialog for a new <b>VariantRule</b> in the context
     * of a product <b>ItemRevision</b> <code>MyProductItemID/A</code>:
     * <br>
     * <ul>
     * <li type="disc">The application uses operation <code>getAvailableProductVariability</code>
     * with <code>variantCriteriaObject=null, productName=MyProductItemID, productNameSpace=A,
     * exprsToTest={}, </code>and<code> familiesToTest={}, substituteDependentVariables=0,
     * applyConstraints=0.</code>
     * </li>
     * <li type="disc">The response will contain all variability available for product <b>ItemRevision</b>
     * <code>MyProductItemID/A </code>without applying variability constraints. References
     * to variant configuration families (<b>ConfigurationFamily</b>) are returned in <code>ServiceData</code>.
     * </li>
     * </ul>
     * <br>
     * <br>
     * Use case 2:
     * <br>
     * Initialize a variant criteria dialog for a product that is associated with a Collaborative
     * Design (CD) model with the intent to setup a new <b>VariantRule</b>.
     * <br>
     * <ul>
     * <li type="disc">Identifiers for the product associated with the CD (<b>Cpd0CollaborativeDesign</b>)
     * are obtained from CD properties <code>mdl0config_product_name</code>, and <code>mdl0config_prod_namespace</code>.
     * </li>
     * <li type="disc">The application uses operation <code>getAvailableProductVariability</code>
     * with <code>productName</code> and <code>productNameSpace</code> as obtained in the
     * previous step,<code> exprsToTest={}</code>, and <code>familiesToTest={}</code>, <code>substituteDependentVariables=0,
     * applyConstraints=0.</code>
     * </li>
     * <li type="disc">The response will contain all variability available for the product
     * that is associated with this CD without applying variability constraints. References
     * to variant configuration families (<b>ConfigurationFamily</b>) are returned in <code>ServiceData</code>.
     * </li>
     * </ul>
     * <br>
     * <br>
     * Use case 3:
     * <br>
     * Iterate through all available configuration families (<b>ConfigurationFamily</b>)
     * with the intent to assign values to each configuration family in an iterative process
     * while dynamically requesting the remaining available range of values for a given
     * configuration family.
     * <br>
     * <ul>
     * <li type="disc">The application uses operation <code>getAvailableProductVariability</code>
     * with the same values for <code>productName</code>, and <code>productNameSpace</code>
     * that was used in the initialization step (see above use cases). Parameter <code>exprsToTest</code>
     * is used to accumulate the choices that were made in previous iterations of this step.
     * </li>
     * <li type="disc">The application uses operation <code>getReferenceListProperty</code>
     * with property <code>ItemRevision::fnd0option_groups</code> for the product ItemRevision
     * to retrieve s list of variant option family groups.
     * </li>
     * <li type="disc">In order to get available value ranges for one or more families in
     * one of the groups obtained in the previous step the application uses operation <code>getAvailableProductVariability</code>
     * with parameter <code>familiesToTest={nextFamilyInList}</code>. The remaining parameter
     * values are <code>substituteDependentVariables=0</code>, and<code> applyConstraints=1</code>.
     * </li>
     * <li type="disc">The response will contain the available value range for the specified
     * <code>familiesToTest</code>.
     * </li>
     * </ul>
     * <br>
     * <br>
     * Use case 4:
     * <br>
     * Request the variant configuration criteria in which at least one of multiple objects
     * configures and eliminate criteria from this result that violate any current validation
     * rules in the context of a Collaborative Design (CD) model.
     * <br>
     * <ul>
     * <li type="disc">A user has designed a new radar cable and wants to assign a variant
     * condition such that the cable configures whenever any radar system and radar screen
     * configures.
     * </li>
     * <li type="disc">Identifiers for the product associated with the CD (<b>Cpd0CollaborativeDesign</b>)
     * are obtained from CD properties <code>mdl0config_product_name</code>, and <code>mdl0config_prod_namespace</code>.
     * </li>
     * <li type="disc">The application uses operation <code>getVariantConditions</code>
     * to obtain the set of conditions associated with the radar systems and screens.
     * </li>
     * <li type="disc">The application uses operation <code>getAvailableProductVariability</code>
     * where parameter <code>exprsToTest</code> is used to pass the variant conditions associated
     * with the radar systems and screens. Parameter <code>familiesToTest</code> is left
     * empty. The remaining parameter values are <code>substituteDependentVariables=0</code>,
     * and <code>applyConstraints=1</code>.
     * </li>
     * <li type="disc">The response will contain the actually available variability for
     * the listed radar systems and screens according to the current set of variant configurator
     * validation rules.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * getVariantConditions, getReferenceListProperty, getProperties, findWorkspaceObjects
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Configuration Management - Capability to configure structured data based on revsion
     * rules; effectivities; Status etc.
     *
     * @param variantCriteriaObject
     *        <b>VariantRule</b> in which context availability is requested. If present it will
     *        be used to filter available values. If a NULLTAG is specified all configuration criteria
     *        are expected to be defined in <code>exprsToTest</code>.
     *
     * @param exprsToTest
     *        Specifies variant expressions to evaluate as additional config expressions.
     *
     * @param familiesToTest
     *        Specifies the list of configuration families for which available values are requested.
     *        If empty, the list of families is derived from <code>exprsToTest</code> and <code>variantCriteriaObject</code>.
     *
     * @param substituteSymbolicVariables
     *        Indicates whether or not to substitute symbolic variables, or "group options" such
     *        as "All_CD_Radios". Value "0" indicates that no substitution is required. A non-zero
     *        value will enable substitution.
     *        <br>
     *        In Tc1.01 a value other than 0 will result in an error.
     *
     * @param applyConstraints
     *        Indicates whether or not to apply the constraints. Value "0" will indicate constraint
     *        application is not required. A non-zero value will enable application of constraints.
     *        The value can be a bitwise OR combination of one or more of the following values:
     *        <br>
     *        0: disable configurator constraint evaluation
     *        <br>
     *        1: enable configurator constraint evaluation
     *        <br>
     *        2: skip constraints if they only reference unset families
     *        <br>
     *        4: skip constraints that don't reference all configExpression families
     *        <br>
     *        8: report warnings in addition to errors
     *        <br>
     *        16: also report informational messages
     *        <br>
     *        32: don't stop if a violation is encountered (use with care)
     *        <br>
     *        64: treat constraints with warning severity as if they had error severity
     *        <br>
     *
     * @param productName
     *        Identifies the product. It is used in conjunction with parameter <code>productNameSpace</code>
     *        to resolve potential ambiguity in variant option value names, and to identify product
     *        context specific constraints. Teamcenter configurators use a Multiple Field Key (MFK)
     *        stable identifier (see property <code>Item::fnd0VariantNamespace</code>) of the product
     *        item for <code>productName</code>. The productName value for a Collaborative Design
     *        (<b>Cpd0CollaborativeDesign</b>) can be obtained from property <code>Mdl0ApplicationModel::mdl0config_product_name</code>.
     *
     * @param productNameSpace
     *        Specifies the namespace for the product identifier. It is used in conjunction with
     *        parameter productName to resolve potential ambiguity in variant option value names,
     *        and to identify product context specific constraints. Teamcenter configurators use
     *        the Revision ID of the product ItemRevision for <code>productNameSpace</code>. The
     *        <code>productNameSpace</code> value for a Collaborative Design (<b>Cpd0CollaborativeDesign</b>)
     *        can be obtained from property <code>Mdl0ApplicationModel::mdl0config_prod_namespace</code>.
     *
     * @param configuratorURL
     *        The service end point for the variant configurator service. If empty the local Teamcenter
     *        configurator is used. Tc10.1 only supports local Teamcenter configurators. In Tc10.1
     *        a non-empty <code>configuratorURL</code> parameter will cause an error.
     *
     * @return
     *         The combined variant scope that could be applied to a new product data object such
     *         that it covers the combined variant range for all exprsToTest.
     *
     *
     * @exception ServiceException
     *           This operation may raise a <code>Teamcenter::Soa::Server::ServiceException</code>
     *           wrapping around the following Teamcenter errors:
     *           <br>
     *           92001&nbsp;&nbsp;&nbsp;&nbsp;An internal error has occurred in the "<code>Fnd0SoaConfigFilterCriteria</code>"
     *           module.
     *           <br>
     *           92002&nbsp;&nbsp;&nbsp;&nbsp;The <code>Product</code> Name and Product <code>Namespace</code>
     *           must not be empty.
     *           <br>
     *           256000&nbsp;&nbsp;&nbsp;&nbsp;An internal configurator error occurred.
     *           <br>
     *           256001&nbsp;&nbsp;&nbsp;&nbsp;A general configurator error occurred.
     *           <br>
     *           256002&nbsp;&nbsp;&nbsp;&nbsp;The following product is invalid: [<i>DictionaryNamespace</i>]<i>FamilyName</i>
     *           (Context: <i>info</i>).
     *           <br>
     *           256003&nbsp;&nbsp;&nbsp;&nbsp;The following feature value is invalid: [<i>DictionaryNamespace</i>]<i>FamilyName</i>
     *           (<i>Context: info</i>).
     *           <br>
     *           256004&nbsp;&nbsp;&nbsp;&nbsp;The following feature family is invalid: [<i>DictionaryNamespace</i>]<i>FamilyName</i>
     *           (<i>Context: info</i>).
     *           <br>
     *           256005&nbsp;&nbsp;&nbsp;&nbsp;An invalid feature combination was found (<i>Context:
     *           info</i>).
     *           <br>
     *           256006&nbsp;&nbsp;&nbsp;&nbsp;An invalid product configuration was found (<i>Context:
     *           info</i>).
     *           <br>
     *           256007&nbsp;&nbsp;&nbsp;&nbsp;An invalid expression was found (<i>Context: info</i>).
     *           <br>
     *           256008&nbsp;&nbsp;&nbsp;&nbsp;The following Boolean operator is invalid: <i>opcode</i>
     *           (<i>Context: info</i>).
     *           <br>
     *           256009&nbsp;&nbsp;&nbsp;&nbsp;An invalid effectivity date was found (<i>Context:
     *           info</i>).
     *           <br>
     *           256010&nbsp;&nbsp;&nbsp;&nbsp;A time-out occurred (<i>Context: info</i>).
     *           <br>
     *           256011&nbsp;&nbsp;&nbsp;&nbsp;A resource is not available (<i>Context: info</i>).
     *           <br>
     *           256012&nbsp;&nbsp;&nbsp;&nbsp;The following functionality is not implemented: <i>function</i>
     *           (Version: <i>TcVersion</i>).
     *           <br>
     *           256013&nbsp;&nbsp;&nbsp;&nbsp;A configurator implementation specific error occurred
     *           (<i>Context: info</i>).
     *           <br>
     *           256014&nbsp;&nbsp;&nbsp;&nbsp;The variant expression contains unmatched quote at
     *           position <i>number</i>.
     *           <br>
     *           256015&nbsp;&nbsp;&nbsp;&nbsp;The variant expression contains unmatched bracket at
     *           <i>position number</i>.
     *           <br>
     *           256016&nbsp;&nbsp;&nbsp;&nbsp;An unexpected token '<i>text</i>' was found at position
     *           <i>number</i>.
     *           <br>
     *           256017&nbsp;&nbsp;&nbsp;&nbsp;The entry '<i>text</i>' was found at position <i>number</i>
     *           when an option value was expected.
     *           <br>
     *           256018&nbsp;&nbsp;&nbsp;&nbsp;The token '<i>text</i>' is missing after '<i>text</i>'
     *           at position <i>number</i>.
     *           <br>
     *           256019&nbsp;&nbsp;&nbsp;&nbsp;The variant expression adaptor does not support <i>text</i>
     *           used at position <i>number</i>.
     *           <br>
     *           256020&nbsp;&nbsp;&nbsp;&nbsp;The XML tag '<i>text</i>' has no text value.
     *           <br>
     *           256021&nbsp;&nbsp;&nbsp;&nbsp;The string '<i>formula</i>' cannot be converted into
     *           an expression.
     *           <br>
     *           256022&nbsp;&nbsp;&nbsp;&nbsp;The operator code '<i>opcode</i>' in token at position
     *           <i>number</i> is unknown.
     *           <br>
     *           256023&nbsp;&nbsp;&nbsp;&nbsp;The variant value '<i>text</i>' in token at position
     *           <i>number</i> is unknown.
     *           <br>
     *           256024&nbsp;&nbsp;&nbsp;&nbsp;The variant family '<i>text</i>' in token at position
     *           <i>number</i> is unknown.
     *           <br>
     *           256025&nbsp;&nbsp;&nbsp;&nbsp;An ambiguous option value name '<i>FamilyName</i>'
     *           in namespace '<i>DictionaryNamespace</i>' in token at position <i>number</i> was
     *           found: <i>text</i>.
     *           <br>
     *           256026&nbsp;&nbsp;&nbsp;&nbsp;An ambiguous option family name '<i>FamilyName</i>'
     *           in token at position <i>number</i> was found: '<i>text</i>'.
     *           <br>
     *           256027&nbsp;&nbsp;&nbsp;&nbsp;The option namespace '<i>DictionaryNamespace</i>' in
     *           token at position <i>number</i> is invalid.
     *           <br>
     *           256028&nbsp;&nbsp;&nbsp;&nbsp;The variant family '<i>FamilyName</i>' in token at
     *           position <i>number</i> is invalid.
     *           <br>
     *           256029&nbsp;&nbsp;&nbsp;&nbsp;The variant option value '<i>text</i>' for family '<i>FamilyName</i>'
     *           in token at position <i>number</i> is invalid.
     *           <br>
     *           256030&nbsp;&nbsp;&nbsp;&nbsp;The variant option value '<i>text</i>' for family '<i>FamilyName</i>'
     *           in token at position <i>number</i> is invalid: its value is not numeric.
     *           <br>
     *           256031&nbsp;&nbsp;&nbsp;&nbsp;The variant option value '<i>text</i>' for family '<i>FamilyName</i>'
     *           in token at position <i>number</i> is invalid: the value unit of measure '<i>text</i>'
     *           does not match the family unit of measure '<i>text</i>'.
     *           <br>
     *           256032&nbsp;&nbsp;&nbsp;&nbsp;The option / family / family namespace combination
     *           <i>'text</i>' / '<i>FamilyName</i>' / '<i>DictionaryNamespace</i>' in token at position
     *           <i>number</i> is invalid.
     *           <br>
     *           256033&nbsp;&nbsp;&nbsp;&nbsp;The family '<i>FamilyName</i>' for option / family
     *           namespace combination '<i>text</i>' / '<i>DictionaryNamespace</i>' in token at position
     *           <i>number</i> is invalid.
     *           <br>
     *           256034&nbsp;&nbsp;&nbsp;&nbsp;There is no option value in token at position <i>number</i>.
     *           <br>
     *           256035&nbsp;&nbsp;&nbsp;&nbsp;The variant option value '<i>text</i>' for family '<i>FamilyName</i>'
     *           in token at position '<i>number</i>' is invalid: the value is not a valid date.
     *           <br>
     */
    virtual Fnd0::Services::Configfiltercriteria::_2013_05::Variantmanagement::AvailableProductVariabilityResponse getAvailableProductVariability ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::POM_object>  variantCriteriaObject,
        const std::vector< Fnd0::Services::Configfiltercriteria::_2013_05::Variantmanagement::ConfigExpression >& exprsToTest,
        const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ConfigurationFamily>  >& familiesToTest,
        int substituteSymbolicVariables,
        int applyConstraints,
        const std::string&  productName,
        const std::string&  productNameSpace,
        const std::string&  configuratorURL ) = 0;

    /**
     * This operation returns all variant configurable products from the variant configurator
     * identified by parameter <code>configuratorURL</code>. The operation connects to the
     * variant configurator service whose service endpoint is specified by the <code>configuratorURL</code>
     * parameter. The query for available variant configurable products is performed by
     * this configurator service. Teamcenter 10.1 only supports local built in Teamcenter
     * configurators where parameter configuratorURL can be set to an empty string. Teamcenter
     * configurators return all <b>ItemRevision</b> objects that allocate variant configuration
     * families as variant configurable products.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * A user wants to associate a product <b>ItemRevision</b> with a Collaborative Design
     * (CD) model so that effectivity configurator rules associated with this product are
     * also associated with the CD. The assumption is that the CD is an application model
     * (<b>Mdl0ApplicationModel</b>) for the product represented by this product item.
     * <br>
     * <br>
     * <ul>
     * <li type="disc">Operation <code>getConfigurableProducts</code> is used to obtain
     * a list of all variant configurable products.
     * </li>
     * <li type="disc">User reviews the list of available (productName, productNameSpace)
     * and selects one.
     * </li>
     * <li type="disc">Operation <code>findWorkspaceObjects</code> is used to locate the
     * product <b>ItemRevision</b> that corresponds to the given (productName, productNameSpace)
     * tuple.
     * </li>
     * <li type="disc">Operation <code>createRelations</code> is used to attach the product
     * <b>ItemRevision</b> to the CD using primaryObject=CD, secondaryObject=MyProductItemRevision,
     * and relationType=Mdl0HasConfiguratorContext.
     * </li>
     * <li type="disc">Operation <code>refreshObjects</code> is used to refresh the CD.
     * </li>
     * <li type="disc">Identifiers for the product associated with the CD (<b>Cpd0CollaborativeDesign</b>)
     * are obtained from CD properties <code>mdl0config_product_name</code>, and m<code>dl0config_prod_namespace.</code>
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createObjects, createRelations, refreshObjects, findWorkspaceObjects
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Configuration Management - Capability to configure structured data based on revsion
     * rules; effectivities; Status etc.
     *
     * @param configuratorURL
     *        For future use,  non-empty <code>configuratorURL</code> parameter will cause an error.
     *
     * @return
     *         Used to get all "Product Name" and "Product Name Space" tuples known to the configurator.
     *         ServiceException is thrown when there is a failure in connecting to configurator.
     *         In all other cases, partial errors are returned in ServiceData.
     *
     *
     * @exception ServiceException
     *           This operation may raise a <code>Teamcenter::Soa::Server::ServiceException </code>wrapping
     *           around the following Teamcenter errors:
     *           <br>
     *           <br>
     *           256000 : An internal configurator error occurred.
     *           <br>
     *           256001 : A general configurator error occurred.
     *           <br>
     *           256010 : A time-out occurred (Context: <i>context information</i>).
     *           <br>
     *           256011 : A resource is not available (Context: <i>context information</i>).
     *           <br>
     *           256012 : The following functionality is not implemented: name (Version: <i>Teamcenter
     *           version)</i>.
     *           <br>
     *           256013 : A configurator implementation specific error occurred (Context: <i>context
     *           information</i>).
     *           <br>
     */
    virtual Fnd0::Services::Configfiltercriteria::_2013_05::Variantmanagement::ConfigurableProductsResponse getConfigurableProducts ( const std::string&  configuratorURL ) = 0;

    /**
     * This operation returns a set of product configurations managed at the configurator
     * level, say for product tracking or reporting purposes.
     * <br>
     * Teamcenter variant configurators manage product configurations as <b>VariantRules</b>
     * which are attached to an <b>ItemRevision</b> representing the product using any relationship
     * type (see also preference <code>TC_Default_SVR_Relationship</code>). The product
     * is identified by <code>productName</code> and <code>productNameSpace</code> parameters.
     * Teamcenter configurators use a Multiple Field Key (MFK) stable identifier (see property<code>
     * Item::fnd0VariantNamespace</code>) of the product <b>item</b> for <code>productName</code>,
     * and the revision ID for <code>productNameSpace</code>. The identifiers of the product
     * associated with a Collaborative Design (<b>Cpd0CollaborativeDesign</b>) can be obtained
     * from properties <code>Mdl0ApplicationModel::mdl0config_product_name</code>, and <code>Mdl0ApplicationModel::mdl0config_prod_namespace</code>.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * An engineering project administrator has created a product <b>ItemRevision</b>. A
     * manufacturing engineering user creates and maintains <b>VariantRules</b> that represent
     * a set of configurations for prototype builds. The project administrator attaches
     * these <b>VariantRules</b> to the product <b>ItemRevision</b>. Product engineering
     * users can use operation <code>getProductConfigurations</code> to review existing
     * prototype configurations. The user can then chose one of the configurations to initialize
     * variant configuration criteria with operation <code>setVariantCriteria</code>.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * setVariantCriteria
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Configuration Management - Capability to configure structured data based on revsion
     * rules; effectivities; Status etc.
     *
     * @param productName
     *        Identifies the product. It is used in conjunction with parameter <code>productNameSpace</code>
     *        to resolve potential ambiguity in variant option value names, and to identify product
     *        context specific constraints. Teamcenter configurators use a Multiple Field Key (MFK)
     *        stable identifier (see property <code>Item::fnd0VariantNamespace</code>) of the product
     *        item for <code>productName</code>. The <code>productName</code> value for a Collaborative
     *        Design (<b>Cpd0CollaborativeDesign</b>) can be obtained from property <code>Mdl0ApplicationModel::mdl0config_product_name</code>.
     *
     * @param productNameSpace
     *        Specifies the namespace for the product identifier. It is used in conjunction with
     *        parameter <code>productName</code> to resolve potential ambiguity in variant option
     *        value names, and to identify product context specific constraints. Teamcenter configurators
     *        use the Revision ID of the product <b>ItemRevision</b> for <code>productNameSpace</code>.
     *        The <code>productNameSpace</code> value for a Collaborative Design (<b>Cpd0CollaborativeDesign</b>)
     *        can be obtained from property <code>Mdl0ApplicationModel::mdl0config_prod_namespace</code>.
     *
     * @param configuratorURL
     *        The service end point for the variant configurator service. If empty the local Teamcenter
     *        configurator is used. Tc10.1 only supports local Teamcenter configurators. In Tc10.1
     *        a non-empty <code>configuratorURL</code> parameter will cause an error.
     *
     * @return
     *         Response object containing variant criateria list.
     *
     *
     * @exception ServiceException
     *           This operation may raise <code>Teamcenter::Soa::Server::ServiceException</code>
     *           wrapping around following Teamcenter errors:
     *           <br>
     *           <br>
     *           92002: The Product Name and Product Namespace must not be empty.
     *           <br>
     */
    virtual Fnd0::Services::Configfiltercriteria::_2013_05::Variantmanagement::VariantCriteriaResponse getProductConfigurations ( const std::string&  productName,
        const std::string&  productNameSpace,
        const std::string&  configuratorURL ) = 0;

    /**
     * This operation returns the variant conditions associated with the objects specified
     * in <code>affectedObjects</code>. This operation connects to the variant configurator
     * specified by the value for configuratorURL in order to convert persistent variant
     * formulae into a Teamcenter expression representation. This will be required if the
     * variant formula was persisted in a configurator specific format that is not the same
     * as the explicit Teamcenter variant formula format. If the configuratorURL is passed
     * in as empty string, then the local Teamcenter configurator will be used.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * A product engineering user has set variant conditions on some components of a product.
     * For example a user may have set a variant condition '<code>Engine=1200</code>' on
     * an engine component that is only valid for engines with a displacement of 1,200 ccm.
     * This operation will retrieve such variant conditions from the database.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * setVariantConditions
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Configuration Management - Capability to configure structured data based on revsion
     * rules; effectivities; Status etc.
     *
     * @param affectedObjects
     *        Represents product elements for which variant condition information is requested.
     *
     * @param configuratorURL
     *        The service end point for the variant configurator service. If empty the local Teamcenter
     *        configurator is used. Tc10.1 only supports local Teamcenter configurators. In Tc10.1
     *        a non-empty <code>configuratorURL</code> parameter will cause an error.
     *
     * @return
     *         Response object containing variant conditions.
     *
     *
     * @exception ServiceException
     *           This operation may raise <code>Teamcenter::Soa::Server::ServiceException </code>wrapping
     *           around following Teamcenter errors:
     *           <br>
     *           <br>
     *           92001 An internal error has occurred in the <code>Fnd0SoaConfigFilterCriteria</code>
     *           module
     *           <br>
     */
    virtual Fnd0::Services::Configfiltercriteria::_2013_05::Variantmanagement::VariantConditionResponse getVariantConditions ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::POM_object>  >& affectedObjects,
        const std::string&  configuratorURL ) = 0;

    /**
     * This operation returns the variant criteria for the given criteria objects (<b>VariantRules</b>).
     * <br>
     * If values are specified for <code>productName</code> and <code>productNameSpace</code>,
     * then pre-computed validation records will also be returned in the response structure,
     * if available for the specified product(see command line utility validate_variant_rule).
     * <br>
     * If a non-zero value is specified for <code>substituteSymbolicVariables</code>, <code>applyConstraints</code>,
     * and or <code>applyDefaults</code> parameters, then the variant criteria will be passed
     * to the configurator for default and constraint processing. In that case up-to-date
     * validation records will be returned in the response structure.
     * <br>
     * The settings for <code>applyConstraints</code> and <code>applyDefaults</code> parameters
     * are active only if <code>productName</code> and <code>productNameSpace</code> are
     * supplied. If <code>productName</code> and <code>productNameSpace</code> are empty,
     * then neither the constraints nor the defaults can be applied for lack of knowing
     * which product's constraints and defaults apply. If default and / or constraint processing
     * is turned on it will be applied to all variant option families. Service <code>getAvailableProductVariability</code>
     * can be used if default and constraint processing are only required for a subset of
     * families.
     * <br>
     * This operation will be faster if constraint and default processing is not requested.
     * This operation will connect to the variant configurator specified by the value for
     * <code>configuratorURL</code>.
     * <br>
     * Tc10.1 does not support symbolic variables, or "group options" such as "All_CD_Radios".
     * Therefore any value other than 0 for <code>substituteSymbolicVariables</code> will
     * result in an error in Tc10.1.
     * <br>
     * If the <code>configuratorURL</code> is passed in as empty string, then the local
     * Teamcenter configurator will be used. Tc10.1 only supports local Teamcenter configurators.
     * In Tc10.1 a non-empty <code>configuratorURL</code> parameter will cause an error.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * A configuration admin user allocates variant option families to an <b>ItemRevision</b>
     * using operation <code>Fnd0::Soa::ConfiguratorAdmin::_2013_05::VariantAdmin::allocateVariantOptionValues</code>.
     * After that defaults and constraint rules are defined  for the families allocated
     * to this <b>ItemRevision</b> using operations <code>Fnd0::Soa::ConfiguratorAdmin::_2013_05::VariantAdmin::createUpdateFixedDefaultRules,
     * Fnd0::Soa::ConfiguratorAdmin::_2013_05::VariantAdmin::createUpdateDerivedDefaultRules,
     * Fnd0::Soa::ConfiguratorAdmin::_2013_05::VariantAdmin::createUpdateExcludeConstraintRules,
     * and Fnd0::Soa::ConfiguratorAdmin::_2013_05::VariantAdmin::createUpdateIncludeConstraintRules</code>.
     * <br>
     * At this point a product engineering user wants to query variant configuration criteria
     * associated with a given criteria object (<b>VariantRules</b>). Operation <code>getVariantCriteria</code>
     * can be used to query the variant configuration criteria associated with the <b>VariantRule</b>
     * in the context of applicable default and constraint rules defined for the <b>ItemRevision</b>
     * identified by parameter <code>productName</code> and <code>productNameSpace</code>.
     * <br>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * setVariantCriteria, createUpdateVariantOptions, allocateVariantOptionValues, createUpdateFixedDefaultRules,
     * createUpdateDerivedDefaultRules, createUpdateExcludeConstraintRules, createUpdateIncludeConstraintRules,
     * setIncludeConstraintRules, setFixedDefaultRules
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Configuration Management - Capability to configure structured data based on revsion
     * rules; effectivities; Status etc.
     *
     * @param variantCriteriaObjects
     *        Vector of object defining variant solve criteria, e.g. <b>VariantRule</b> objects.
     *
     * @param substituteSymbolicVariables
     *        Indicates whether or not to substitute symbolic variables, or "group options" such
     *        as "All_CD_Radios". Value "0" indicates that no substitution is required. A non-zero
     *        value will enable substitution. In Tc1.01 a value other than 0 will result in an
     *        error.
     *
     * @param applyConstraints
     *        Indicates whether or not to apply the constraints. The parameter value is a bit pattern
     *        specifying the requested operation. A parameter value of 25 reports warnings and
     *        informational messages in addition to errors :
     *        <br>
     *        Apply constraints | Report Warnings | Report Info = 1+8+16 = 25
     *        <br>
     *        0 -  indicates constraint application is not required
     *        <br>
     *        1 -  apply configuration constraints
     *        <br>
     *        2 - skip constraints if they only reference unset families
     *        <br>
     *        4 - skip constraints that don't reference all configExpression families
     *        <br>
     *        8 - report warnings in addition to errors
     *        <br>
     *        16 - also report informational messages
     *        <br>
     *        32 - continue Validation On Error
     *        <br>
     *        64 - treat constraints with warning severity as if they had error severity
     *        <br>
     *
     * @param applyDefaults
     *        Indicates whether or not to apply defaults.  The parameter value is a bit pattern
     *        specifying one or more of the following:
     *        <br>
     *        0 -  indicates that defaults should not be applied
     *        <br>
     *        1 -  will enable application of defaults
     *        <br>
     *        2 - ignore all derived defaults and only process fixed defaults
     *        <br>
     *        4 - skip partially satisfied derived defaults
     *        <br>
     *        8 - force partially satisfied derived defaults
     *        <br>
     *
     * @param productName
     *        Identifies the product. It is used in conjunction with parameter <code>productNameSpace</code>
     *        to resolve potential ambiguity in variant option value names, and to identify product
     *        context specific constraints. Teamcenter configurators use a Multiple Field Key (MFK)
     *        stable identifier (see property <code>Item::fnd0VariantNamespace</code>) of the product
     *        item for <code>productName</code>. The <code>productName</code> value for a Collaborative
     *        Design (<b>Cpd0CollaborativeDesign</b>) can be obtained from property <code>Mdl0ApplicationModel::mdl0config_product_name.</code>
     *
     * @param productNameSpace
     *        Specifies the namespace for the product identifier. It is used in conjunction with
     *        parameter <code>productName</code> to resolve potential ambiguity in variant option
     *        value names, and to identify product context specific constraints. Teamcenter configurators
     *        use the Revision ID of the product <b>ItemRevision</b> for <code>productNameSpace</code>.
     *        The <code>productNameSpace</code> value for a Collaborative Design (<b>Cpd0CollaborativeDesign</b>)
     *        can be obtained from property <code>Mdl0ApplicationModel::mdl0config_prod_namespace.</code>
     *
     * @param configuratorURL
     *        This is service end point for the variant configurator service. If empty the local
     *        Teamcenter configurator is used. Tc10.1 only supports local Teamcenter configurators.
     *        In Tc10.1 a non-empty <code>configuratorURL</code> parameter will cause an error.
     *
     * @return
     *         Response object containing variant criteria information.
     *
     *
     * @exception ServiceException
     *           This operation may raise a <code>Teamcenter::Soa::Server::ServiceException</code>
     *           wrapping around following Teamcenter errors:
     *           <br>
     *           <br>
     *           92001&nbsp;&nbsp;&nbsp;&nbsp;An internal error has occurred in the "<code>Fnd0SoaConfigFilterCriteria</code>"
     *           module.
     *           <br>
     *           256000&nbsp;&nbsp;&nbsp;&nbsp;An internal configurator error occurred.
     *           <br>
     *           256001&nbsp;&nbsp;&nbsp;&nbsp;A general configurator error occurred.
     *           <br>
     *           256002&nbsp;&nbsp;&nbsp;&nbsp;The following product is invalid: [<i>DictionaryNamespace</i>]<i>FamilyName</i>
     *           (Context: <i>info</i>).
     *           <br>
     *           256003&nbsp;&nbsp;&nbsp;&nbsp;The following feature value is invalid: [<i>DictionaryNamespace</i>]<i>FamilyName</i>
     *           (<i>Context: info</i>).
     *           <br>
     *           256004&nbsp;&nbsp;&nbsp;&nbsp;The following feature family is invalid: [<i>DictionaryNamespace</i>]<i>FamilyName</i>
     *           (<i>Context: info</i>).
     *           <br>
     *           256005&nbsp;&nbsp;&nbsp;&nbsp;An invalid feature combination was found (<i>Context:
     *           info</i>).
     *           <br>
     *           256006&nbsp;&nbsp;&nbsp;&nbsp;An invalid product configuration was found (<i>Context:
     *           info</i>).
     *           <br>
     *           256007&nbsp;&nbsp;&nbsp;&nbsp;An invalid expression was found (<i>Context: info</i>).
     *           <br>
     *           256008&nbsp;&nbsp;&nbsp;&nbsp;The following Boolean operator is invalid: <i>opcode</i>
     *           (<i>Context: info</i>).
     *           <br>
     *           256009&nbsp;&nbsp;&nbsp;&nbsp;An invalid effectivity date was found (<i>Context:
     *           info</i>).
     *           <br>
     *           256010&nbsp;&nbsp;&nbsp;&nbsp;A time-out occurred (<i>Context: info</i>).
     *           <br>
     *           256011&nbsp;&nbsp;&nbsp;&nbsp;A resource is not available (<i>Context: info</i>).
     *           <br>
     *           256012&nbsp;&nbsp;&nbsp;&nbsp;The following functionality is not implemented: <i>function</i>
     *           (<i>Version: TcVersion</i>).
     *           <br>
     *           256013&nbsp;&nbsp;&nbsp;&nbsp;A configurator implementation specific error occurred
     *           (<i>Context: info</i>).
     *           <br>
     *           256014&nbsp;&nbsp;&nbsp;&nbsp;The variant expression contains unmatched quote at
     *           position <i>number</i>.
     *           <br>
     *           256015&nbsp;&nbsp;&nbsp;&nbsp;The variant expression contains unmatched bracket at
     *           position <i>number</i>.
     *           <br>
     *           256016&nbsp;&nbsp;&nbsp;&nbsp;An unexpected token '<i>text</i>' was found at position
     *           <i>number</i>.
     *           <br>
     *           256017&nbsp;&nbsp;&nbsp;&nbsp;The entry '<i>text</i>' was found at position <i>number</i>
     *           when an option value was expected.
     *           <br>
     *           256018&nbsp;&nbsp;&nbsp;&nbsp;The token '<i>text</i>' is missing after '<i>text</i>'
     *           at position <i>number</i>.
     *           <br>
     *           256019&nbsp;&nbsp;&nbsp;&nbsp;The variant expression adaptor does not support <i>text</i>
     *           used at position <i>number</i>.
     *           <br>
     *           256020&nbsp;&nbsp;&nbsp;&nbsp;The XML tag '<i>text</i>' has no text value.
     *           <br>
     *           256021&nbsp;&nbsp;&nbsp;&nbsp;The string '<i>formula</i>' cannot be converted into
     *           an expression.
     *           <br>
     *           256022&nbsp;&nbsp;&nbsp;&nbsp;The operator code '<i>opcode</i>' in token at position
     *           <i>number</i> is unknown.
     *           <br>
     *           256023&nbsp;&nbsp;&nbsp;&nbsp;The variant value '<i>text</i>' in token at position
     *           <i>number</i> is unknown.
     *           <br>
     *           256024&nbsp;&nbsp;&nbsp;&nbsp;The variant family '<i>text</i>' in token at position
     *           <i>number</i> is unknown.
     *           <br>
     *           256025&nbsp;&nbsp;&nbsp;&nbsp;An ambiguous option value name '<i>FamilyName</i>'
     *           in namespace '<i>DictionaryNamespace</i>' in token at position <i>number</i> was
     *           found: <i>text</i>.
     *           <br>
     *           256026&nbsp;&nbsp;&nbsp;&nbsp;An ambiguous option family name '<i>FamilyName</i>'
     *           in token at position <i>number</i> was found: '<i>text</i>'.
     *           <br>
     *           256027&nbsp;&nbsp;&nbsp;&nbsp;The option namespace '<i>DictionaryNamespace</i>' in
     *           token at position <i>number</i> is invalid.
     *           <br>
     *           256028&nbsp;&nbsp;&nbsp;&nbsp;The variant family '<i>FamilyName</i>' in token at
     *           position <i>number</i> is invalid.
     *           <br>
     *           256029&nbsp;&nbsp;&nbsp;&nbsp;The variant option value '<i>text</i>' for family '<i>FamilyName</i>'
     *           in token at position <i>number</i> is invalid.
     *           <br>
     *           256030&nbsp;&nbsp;&nbsp;&nbsp;The variant option value '<i>text</i>' for family '<i>FamilyName</i>'
     *           in token at position <i>number</i> is invalid: its value is not numeric.
     *           <br>
     *           256031&nbsp;&nbsp;&nbsp;&nbsp;The variant option value '<i>text</i>' for family '<i>FamilyName</i>'
     *           in token at position <i>number</i> is invalid: the value unit of measure '<i>text</i>'
     *           does not match the family unit of measure '<i>text</i>'.
     *           <br>
     *           256032&nbsp;&nbsp;&nbsp;&nbsp;The option / family / family namespace combination
     *           '<i>text</i>' / '<i>FamilyName</i>' / '<i>DictionaryNamespace</i>' in token at position
     *           <i>number</i> is invalid.
     *           <br>
     *           256033&nbsp;&nbsp;&nbsp;&nbsp;The family '<i>FamilyName</i>' for option / family
     *           namespace combination '<i>text</i>' / '<i>DictionaryNamespace</i>' in token at position
     *           <i>number</i> is invalid.
     *           <br>
     *           256034&nbsp;&nbsp;&nbsp;&nbsp;There is no option value in token at position <i>number</i>.
     *           <br>
     *           256035&nbsp;&nbsp;&nbsp;&nbsp;The variant option value '<i>text</i>' for family '<i>FamilyName</i>'
     *           in token at position '<i>number</i>' is invalid: the value is not a valid date.
     *           <br>
     */
    virtual Fnd0::Services::Configfiltercriteria::_2013_05::Variantmanagement::VariantCriteriaResponse getVariantCriteria ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::POM_object>  >& variantCriteriaObjects,
        int substituteSymbolicVariables,
        int applyConstraints,
        int applyDefaults,
        const std::string&  productName,
        const std::string&  productNameSpace,
        const std::string&  configuratorURL ) = 0;

    /**
     * This operation determines and returns the degree of overlap between a set of variant
     * expressions and a set of reference variant expressions. When applications create
     * or update DesignElements (DE) and assign variant conditions, the UI may want to qualify
     * the degree of overlap between the variant condition of the DE and the currently active
     * variant configuration criteria.
     * <br>
     * The following example illustrates the overlap states for a set of expressions:
     * <br>
     * <code>VariantRule:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|---------------|
     * <br>
     * Object&nbsp;0:&nbsp;&nbsp;|----|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;:&nbsp;OverlapStateNone
     * <br>
     * Object&nbsp;1:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|------|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;:&nbsp;OverlapStateIntersect
     * <br>
     * Object&nbsp;2:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|----|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;:&nbsp;OverlapStateSubset
     * <br>
     * Object&nbsp;3:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|------|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;:&nbsp;OverlapStateIntersect
     * <br>
     * Object&nbsp;4:&nbsp;&nbsp;|-----------------------------|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;:&nbsp;OverlapStateSuperset
     * <br>
     * Object&nbsp;5:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|---------------|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;:&nbsp;OverlapStateMatch
     * <br>
     * Object&nbsp;6:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|-------------------|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;:&nbsp;OverlapStateSuperset
     * <br>
     * Object&nbsp;7:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|-------------------|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;:&nbsp;OverlapStateSuperset
     * <br>
     * Object&nbsp;8:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FALSE&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;:&nbsp;OverlapStateNone
     * <br>
     * Object&nbsp;9:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;TRUE&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;:
     * OverlapStateSuperset</code>
     * <br>
     * This operation connects to the variant configurator service whose service endpoint
     * is specified by the <code>configuratorURL</code> parameter. Any conversion from formula
     * strings is performed by this configurator service. Depending on the (configurator
     * specific) encoding the operation might require the specification of a product context
     * using parameters <code>productName</code> and <code>productNameSpace</code>. For
     * example, a given configurator might recognize shorthand representations for formulae
     * if these are unique in the context of the specified product. Teamcenter 10.1 only
     * supports local built in Teamcenter configurators where parameter configuratorURL
     * can be set to an empty string. Teamcenter configurators don't require a product context
     * if the formulae are in <b>Explicit Teamcenter Language</b>. The encoding is explicit
     * if all lexemes are uniquely identified, e.g. [<i>OptionNamespace</i>]<i>FamilyName</i>
     * = <i>UniqueValue</i>, where no product context is required to determine the family
     * name for a value, or the option namespace for the family. A configuration expression
     * formula is in <b>Explicit Teamcenter Language</b> if its form is explicit and comprised
     * of the lexemes documented for the Teamcenter <code>Variant Formula</code> property.
     * Teamcenter configurators support shorthand encodings like <i>FamilyName = UniqueValue</i>
     * or <i>UniqueValue</i> if the lexemes used in the shorthand encoding are unique in
     * the specified product context.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * An application wants to qualify variant conditions that were retrieved with <b>getVariantConditions</b>
     * as to whether the condition is equal to, intersects with, or is a subset or superset
     * of the variant criteria associated with one or more <b>VariantRules</b>. This cannot
     * be achieved with properties on variant conditions or <b>VariantRules</b> because
     * the result depends on the combination of a variant condition and the variant configuration
     * criteria on a <b>VariantRule</b>. One and the same condition may have different overlap
     * states with different VariantRules.
     * <br>
     * The application calls <b>getVariantOverlapStates</b> and passes the variant criteria
     * (as obtained from a <b>VariantRule</b> using <b>getVariantCriteria</b>) as <code>referenceExpressions</code>,
     * and the variant conditions (as obtained from a set of product data elements using
     * <b>getVariantConditions</b>) as <code>expressions</code>.
     * <br>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * getVariantConditions, getVariantCriteria
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Configuration Management - Capability to configure structured data based on revsion
     * rules; effectivities; Status etc.
     *
     * @param referenceExpressions
     *        The vector of reference variant criteria expressions.
     *
     * @param expressions
     *        Vector of variant expressions. The response returns the overlap state of each expression
     *        in this vector, with each of the reference variant criteria expressions given in
     *        the <code>referenceExpressions</code> parameter.
     *
     * @param productName
     *        Identifies the product. It is used in conjunction with parameter <code>productNameSpace</code>
     *        to resolve potential ambiguity in variant option value names, and to identify product
     *        context specific constraints. Teamcenter configurators use a Multiple Field Key (MFK)
     *        stable identifier (see property <code>Item::fnd0VariantNamespace</code>) of the product
     *        item for <code>productName</code>. The <code>productName</code> value for a Collaborative
     *        Design (<b>Cpd0CollaborativeDesign</b>) can be obtained from property <code>Mdl0ApplicationModel::mdl0config_product_name.</code>
     *
     * @param productNameSpace
     *        Specifies the namespace for the product identifier. It is used in conjunction with
     *        parameter <code>productName</code> to resolve potential ambiguity in variant option
     *        value names, and to identify product context specific constraints. Teamcenter configurators
     *        use the Revision ID of the product <b>ItemRevision</b> for <code>productNameSpace</code>.
     *        The <code>productNameSpace</code> value for a Collaborative Design (<b>Cpd0CollaborativeDesign</b>)
     *        can be obtained from property <code>Mdl0ApplicationModel::mdl0config_prod_namespace.</code>
     *
     * @param configuratorURL
     *        The service end point for the variant configurator service. If empty the local Teamcenter
     *        configurator is used. Tc10.1 only supports local Teamcenter configurators. In Tc10.1
     *        a non-empty <code>configuratorURL</code> parameter will cause an error.
     *
     * @return
     *         Compares each variant expression with each reference expression and returns the degreee
     *         of overlap.
     *
     *
     * @exception ServiceException
     *           This operation may raise <code>Teamcenter::Soa::Server::ServiceException</code>
     *           wrapping around following Teamcenter errors:
     *           <br>
     *           <br>
     *           256000&nbsp;&nbsp;&nbsp;&nbsp;An internal configurator error occurred.
     *           <br>
     *           256001&nbsp;&nbsp;&nbsp;&nbsp;A general configurator error occurred.
     *           <br>
     *           256002&nbsp;&nbsp;&nbsp;&nbsp;The following product is invalid: [<i>DictionaryNamespace</i>]<i>FamilyName</i>
     *           (Context: <i>info</i>).
     *           <br>
     *           256003&nbsp;&nbsp;&nbsp;&nbsp;The following feature value is invalid: [<i>DictionaryNamespace</i>]<i>FamilyName</i>
     *           (<i>Context: info</i>).
     *           <br>
     *           256004&nbsp;&nbsp;&nbsp;&nbsp;The following feature family is invalid: [<i>DictionaryNamespace</i>]<i>FamilyName</i>
     *           (<i>Context: info</i>).
     *           <br>
     *           256005&nbsp;&nbsp;&nbsp;&nbsp;An invalid feature combination was found (<i>Context:
     *           info</i>).
     *           <br>
     *           256006&nbsp;&nbsp;&nbsp;&nbsp;An invalid product configuration was found (<i>Context:
     *           info</i>).
     *           <br>
     *           256007&nbsp;&nbsp;&nbsp;&nbsp;An invalid expression was found (<i>Context: info</i>).
     *           <br>
     *           256008&nbsp;&nbsp;&nbsp;&nbsp;The following Boolean operator is invalid: <i>opcode</i>
     *           (<i>Context: info</i>).
     *           <br>
     *           256009&nbsp;&nbsp;&nbsp;&nbsp;An invalid effectivity date was found (<i>Context:
     *           info</i>).
     *           <br>
     *           256010&nbsp;&nbsp;&nbsp;&nbsp;A time-out occurred (<i>Context: info</i>).
     *           <br>
     *           256011&nbsp;&nbsp;&nbsp;&nbsp;A resource is not available (<i>Context: info</i>).
     *           <br>
     *           256012&nbsp;&nbsp;&nbsp;&nbsp;The following functionality is not implemented: <i>function</i>
     *           (<i>Version: TcVersion</i>).
     *           <br>
     *           256013&nbsp;&nbsp;&nbsp;&nbsp;A configurator implementation specific error occurred
     *           (<i>Context: info</i>).
     *           <br>
     *           256014&nbsp;&nbsp;&nbsp;&nbsp;The variant expression contains unmatched quote at
     *           position <i>number</i>.
     *           <br>
     *           256015&nbsp;&nbsp;&nbsp;&nbsp;The variant expression contains unmatched bracket at
     *           position <i>number</i>.
     *           <br>
     *           256016&nbsp;&nbsp;&nbsp;&nbsp;An unexpected token '<i>text</i>' was found at position
     *           <i>number</i>.
     *           <br>
     *           256017&nbsp;&nbsp;&nbsp;&nbsp;The entry '<i>text</i>' was found at position <i>number</i>
     *           when an option value was expected.
     *           <br>
     *           256018&nbsp;&nbsp;&nbsp;&nbsp;The token '<i>text</i>' is missing after '<i>text</i>'
     *           at position <i>number</i>.
     *           <br>
     *           256019&nbsp;&nbsp;&nbsp;&nbsp;The variant expression adaptor does not support <i>text</i>
     *           used at position <i>number</i>.
     *           <br>
     *           256020&nbsp;&nbsp;&nbsp;&nbsp;The XML tag '<i>text</i>' has no <i>text</i> value.
     *           <br>
     *           256021&nbsp;&nbsp;&nbsp;&nbsp;The string '<i>formula</i>' cannot be converted into
     *           an expression.
     *           <br>
     *           256022&nbsp;&nbsp;&nbsp;&nbsp;The operator code '<i>opcode</i>' in token at position
     *           <i>number</i> is unknown.
     *           <br>
     *           256023&nbsp;&nbsp;&nbsp;&nbsp;The variant value '<i>text</i>' in token at position
     *           <i>number</i> is unknown.
     *           <br>
     *           256024&nbsp;&nbsp;&nbsp;&nbsp;The variant family '<i>text</i>' in token at position
     *           <i>number</i> is unknown.
     *           <br>
     *           256025&nbsp;&nbsp;&nbsp;&nbsp;An ambiguous option value name '<i>FamilyName</i>'
     *           in namespace '<i>DictionaryNamespace</i>' in token at position <i>number</i> was
     *           found: <i>text</i>.
     *           <br>
     *           256026&nbsp;&nbsp;&nbsp;&nbsp;An ambiguous option family name '<i>FamilyName</i>'
     *           in token at position <i>number</i> was found: '<i>text</i>'.
     *           <br>
     *           256027&nbsp;&nbsp;&nbsp;&nbsp;The option namespace '<i>DictionaryNamespace</i>' in
     *           token at position <i>number</i> is invalid.
     *           <br>
     *           256028&nbsp;&nbsp;&nbsp;&nbsp;The variant family '<i>FamilyName</i>' in token at
     *           position <i>number</i> is invalid.
     *           <br>
     *           256029&nbsp;&nbsp;&nbsp;&nbsp;The variant option value '<i>text</i>' for family '<i>FamilyName</i>'
     *           in token at position <i>number</i> is invalid.
     *           <br>
     *           256030&nbsp;&nbsp;&nbsp;&nbsp;The variant option value '<i>text</i>' for family '<i>FamilyName</i>'
     *           in token at position <i>number</i> is invalid: its value is not numeric.
     *           <br>
     *           256031&nbsp;&nbsp;&nbsp;&nbsp;The variant option value '<i>text</i>' for family '<i>FamilyName</i>'
     *           in token at position number is invalid: the value unit of measure '<i>text</i>' does
     *           not match the family unit of measure '<i>text</i>'.
     *           <br>
     *           256032&nbsp;&nbsp;&nbsp;&nbsp;The option / family / family namespace combination
     *           '<i>text</i>' / '<i>FamilyName</i>' / '<i>DictionaryNamespace</i>' in token at position
     *           number is invalid.
     *           <br>
     *           256033&nbsp;&nbsp;&nbsp;&nbsp;The family '<i>FamilyName</i>' for option / family
     *           namespace combination '<i>text</i>' / '<i>DictionaryNamespace</i>' in token at position
     *           <i>number</i> is invalid.
     *           <br>
     *           256034&nbsp;&nbsp;&nbsp;&nbsp;There is no option value in token at position <i>number</i>.
     *           <br>
     *           256035&nbsp;&nbsp;&nbsp;&nbsp;The variant option value '<i>text</i>' for family '<i>FamilyName</i>'
     *           in token at position '<i>number</i>' is invalid: the value is not a valid date.
     *           <br>
     */
    virtual Fnd0::Services::Configfiltercriteria::_2013_05::Variantmanagement::VariantOverlapStateResponse getVariantOverlapStates ( const std::vector< Fnd0::Services::Configfiltercriteria::_2013_05::Variantmanagement::ConfigExpression >& referenceExpressions,
        const std::vector< Fnd0::Services::Configfiltercriteria::_2013_05::Variantmanagement::ConfigExpression >& expressions,
        const std::string&  productName,
        const std::string&  productNameSpace,
        const std::string&  configuratorURL ) = 0;

    /**
     * This operation creates, updates, or removes variant conditions for a set of input
     * objects.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Use case 1
     * <br>
     * An administrative user for corporate standards has created a variant option family
     * <code>Model</code> on <b>Item</b> <code>CorpVariants</code> with values <code>Economy</code>
     * and <code>Luxury</code>. An administrative user for an engineering project has created
     * a product <b>Item</b> <code>ProjABC</code> and allocated the two values <code>[Model]Economy</code>
     * and <code>[Model]Luxury</code> from <b>ItemRevision</b> <code>CorpVariants/A</code>
     * to the product <b>ItemRevision</b> <code>ProjABC/01</code>. At this point a product
     * engineering user wants to set a variant condition <code>[CorpVariants]Model = Economy</code>
     * on a design element (<b>Cpd0DesignElement</b>). To achieve this, the user can pass
     * parameter <code>formula</code> to operation <code>setVariantConditions</code> as
     * <code>Model = Economy</code>, <code>productName</code> as <code>ProjABC</code>, <code>productNamespace</code>
     * as 01 (which identifies the product context), <code>actionCode</code> as <code>Overwrite</code>
     * and <code>affectedObjects</code> to contain the target design element object. As
     * an alternative to the <code>formula</code> string representation of the new variant
     * condition, the user could have used one of the other representations (sub-expression\value,
     * or the Teamcenter Normal Form (TNF)) for the new variant condition.
     * <br>
     * At some later point in time the product engineering user wants to extend the variant
     * conditions on a set of existing design elements to  <code>... OR [CorpVariants]Model
     * = Luxury</code>. To achieve this, the user can pass parameter formula as <code>Model
     * = Luxury</code>, <code>productName</code> as <code>ProjABC</code>, <code>productNamespace</code>
     * as 01, and <code>actionCode</code> as <code>Extend</code>. The set of objects for
     * which the variant condition should be changed is passed in parameter <code>affectedObjects</code>.
     * <br>
     * For another set of design element the user wants to reduce the variant scope of their
     * existing variant conditions <code>([CorpVariants]Model = Economy OR [CorpVariants]Model
     * = ...) AND ...</code> down to be only applicable to <code>[CorpVariants]Model = Economy
     * AND ...</code> To achieve this, operation <code>setVariantConditions</code> can be
     * used with parameters <code>actionCode</code> as <code>Reduce</code>, formula as <code>Model
     * = Economy</code>, <code>productName</code> as <code>ProjABC</code>, and <code>productNamespace</code>
     * as 01.
     * <br>
     * <br>
     * Use case 2
     * <br>
     * A product engineering user wants to assign a variant scope to a design element that
     * matches the combined variant scope of a set of other objects. Operation <code>setVariantConditions</code>
     * can be used to achieve this by passing the set of other objects in parameter <code>sampleObjects</code>,
     * along with parameter <code>opCode</code> = 11 (OR).
     * <br>
     * For example a user wants to assign a variant condition to the electrical wire that
     * connects the battery with the alternator. To achieve this, the user passes all battery
     * variants together with all alternator variants in parameter <code>sampleObjects</code>,
     * along with parameter <code>opCode</code> = 11 (OR). The result is a variant condition
     * that configures the cable whenever any battery or alternator configures.
     * <br>
     * <br>
     * Use case 3
     * <br>
     * A product engineering user wants to assign a variant scope to a design element that
     * matches the common variant scope of a set of other objects. Operation <code>setVariantConditions</code>
     * can be used to achieve this by passing the set of other objects in parameter <code>sampleObjects</code>,
     * along with parameter <code>opCode</code> = 10 (AND).
     * <br>
     * For example a user wants to assign a variant condition to a software module that
     * is only required when a particular distance control module is configured together
     * with a specific anti-lock braking module. To achieve this, the user passes the distance
     * control module together with the anti-lock braking module in parameter <code>sampleObjects</code>,
     * along with parameter <code>opCode</code> = 10 (AND). The result is a variant condition
     * that configures the software module only when the distance control module is configured
     * together with the anti-lock braking module.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * allocateVariantOptionValues, createUpdateVariantOptions, getAvailableProductVariability
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Configuration Management - Capability to configure structured data based on revsion
     * rules; effectivities; Status etc.
     *
     * @param conditions
     *        A list of input conditions which should be created or updated. To remove a condition
     *        specify a NULL condition structure.
     *
     * @param productName
     *        Identifies the product. It is used in conjunction with parameter <code>productNameSpace</code>
     *        to resolve potential ambiguity in variant option value names, and to identify product
     *        context specific constraints. Teamcenter configurators use a Multiple Field Key (MFK)
     *        stable identifier (see property <code>Item::fnd0VariantNamespace</code>) of the product
     *        item for <code>productName</code>. The <code>productName</code> value for a Collaborative
     *        Design (<b>Cpd0CollaborativeDesign</b>) can be obtained from property <code>Mdl0ApplicationModel::mdl0config_product_name.</code>
     *
     * @param productNameSpace
     *        Specifies the namespace for the product identifier. It is used in conjunction with
     *        parameter <code>productName</code> to resolve potential ambiguity in variant option
     *        value names, and to identify product context specific constraints. Teamcenter configurators
     *        use the Revision ID of the product <b>ItemRevision</b> for <code>productNameSpace</code>.
     *        The <code>productNameSpace</code> value for a Collaborative Design (<b>Cpd0CollaborativeDesign</b>)
     *        can be obtained from property <code>Mdl0ApplicationModel::mdl0config_prod_namespace.</code>
     *
     * @param configuratorURL
     *        This is the service end point for the variant configurator service. If empty the
     *        local Teamcenter configurator is used. Tc10.1 only supports local Teamcenter configurator.
     *        In Tc10.1 a non-empty <code>configuratorURL</code> parameter will cause an error.
     *
     * @return
     *         Response object contains variant conditions set.
     *
     *
     * @exception ServiceException
     *           This operation may raise <code>Teamcenter::Soa::Server::ServiceException</code>
     *           wrapping around following Teamcenter errors:
     *           <br>
     *           <br>
     *           92001 An internal error has occurred in the <code>Fnd0SoaConfigFilterCriteria</code>
     *           module
     *           <br>
     */
    virtual Fnd0::Services::Configfiltercriteria::_2013_05::Variantmanagement::SetVariantConditionResponse setVariantConditions ( const std::vector< Fnd0::Services::Configfiltercriteria::_2013_05::Variantmanagement::VariantConditionInput >& conditions,
        const std::string&  productName,
        const std::string&  productNameSpace,
        const std::string&  configuratorURL ) = 0;

    /**
     * This operation assigns the specified variant criteria to the given criteria objects
     * (<b>VariantRules</b>).
     * <br>
     * The settings for parameters <code>substituteSymbolicVariables</code>, <code>applyConstraints</code>,
     * and <code>applyDefaults</code> are active only if a <code>productName</code> and
     * <code>productNameSpace</code> combination is supplied.
     * <br>
     * If a non-zero value is specified for <code>substituteSymbolicVariables</code>, <code>applyConstraints</code>,
     * and or <code>applyDefaults</code> parameters, then the variant criteria will be passed
     * to the variant configurator for validation. As a result validation records will be
     * computed for the product identified by the given <code>productName</code> and <code>productNameSpace</code>
     * combinationand returned as part of the server response.
     * <br>
     * If <code>productName</code> and <code>productNameSpace</code> are empty, then neither
     * the constraints nor the defaults can be applied for lack of knowing which product's
     * constraints and defaults apply. This operation will be faster if constraint and default
     * processing is not requested.
     * <br>
     * This operation will connect to the variant configurator specified by the value for
     * <code>configuratorURL</code>. If the <code>configuratorURL</code> is passed in as
     * empty string, then the local Teamcenter configurator will be used.
     * <br>
     * Tc10.1 does not support symbolic variables, or "group options" such as "All_CD_Radios".
     * Therefore any value other than 0 for <code>substituteSymbolicVariables</code> will
     * result in an error in Tc10.1.
     * <br>
     * Tc10.1 only supports local Teamcenter configurators. In Tc10.1 a non-empty <code>configuratorURL</code>
     * parameter will cause an error.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * A configuration admin user allocates variant option families to an <b>ItemRevision</b>
     * using operation <code>Fnd0::Soa::ConfiguratorAdmin::_2013_05::VariantAdmin::allocateVariantOptionValues</code>.
     * After that defaults and constraint rules are defined  for the families allocated
     * to this <b>ItemRevision</b> using operations <code>Fnd0::Soa::ConfiguratorAdmin::_2013_05::VariantAdmin::createUpdateFixedDefaultRules,
     * Fnd0::Soa::ConfiguratorAdmin::_2013_05::VariantAdmin::createUpdateDerivedDefaultRules,
     * Fnd0::Soa::ConfiguratorAdmin::_2013_05::VariantAdmin::createUpdateExcludeConstraintRules,
     * </code>and<code> Fnd0::Soa::ConfiguratorAdmin::_2013_05::VariantAdmin::createUpdateIncludeConstraintRules.</code>
     * <br>
     * At this point a product engineering user wants to update variant configuration criteria
     * associated with a given criteria object (<b>VariantRule</b>). Operation <code>setVariantCriteria</code>
     * can be used to assign a value to a variant option family in this criteria object
     * (<b>VariantRule</b>) in the context of applicable default and constraint rules defined
     * for the <b>ItemRevision</b> identified by parameter <code>productName</code> and
     * <code>productNameSpace</code>.
     * <br>
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
     * @param sampleObjects
     *        Objects, whose variant conditions are applied as variant criteria to <code>affectedObjects</code>.
     *        These may include configurable objects (e.g. <b>Mdl0ConditionalElement</b>) and/or
     *        criteria objects (e.g. <b>VariantRule</b>). Can be empty.
     *
     * @param formulae
     *        Variant expression formulae to be included when deriving variant criteria for <code>affectedObjects</code>.
     *        Can be empty.
     *
     * @param expressions
     *        Configuration expressions to be included when deriving variant criteria for <code>affectedObjects</code>.
     *        Can be empty.
     *
     * @param opCode
     *        Specifies how to combine the inputs given in "<code>sampleObjects</code>", "<code>expressions</code>",
     *        and "<code>formulae</code>". The values are defined in ps/ps_tokens.h, e.g. "10"
     *        for "AND" , or "11" for "OR".
     *
     * @param substituteSymbolicVariables
     *        Indicates whether or not to substitute symbolic variables, or "group options" such
     *        as "All_CD_Radios". Value "0" indicates that no substitution is required. A non-zero
     *        value will enable substitution. In Tc10.1 a value other than 0 will result in an
     *        error.
     *
     * @param applyConstraints
     *        Indicates whether or not to apply the constraints. The parameter value is a bit pattern
     *        specifying the requested operation. A parameter value of 25 reports warnings and
     *        informational messages in addition to errors :
     *        <br>
     *        Apply constraints | Report Warnings | Report Info = 1+8+16 = 25
     *        <br>
     *        0 -  indicates constraint application is not required
     *        <br>
     *        1 -  apply configuration constraints
     *        <br>
     *        2 - skip constraints if they only reference unset families
     *        <br>
     *        4 - skip constraints that don't reference all configExpression families
     *        <br>
     *        8 - report warnings in addition to errors
     *        <br>
     *        16 - also report informational messages
     *        <br>
     *        32 - continue Validation On Error
     *        <br>
     *        64 - treat constraints with warning severity as if they had error severity
     *        <br>
     *
     * @param applyDefaults
     *        Indicates whether or not to apply defaults.  The parameter value is a bit pattern
     *        specifying one or more of the following:
     *        <br>
     *        0 -  indicates that defaults should not be applied
     *        <br>
     *        1 -  will enable application of defaults
     *        <br>
     *        2 - ignore all derived defaults and only process fixed defaults
     *        <br>
     *        4 - skip partially satisfied derived defaults
     *        <br>
     *        8 - force partially satisfied derived defaults
     *        <br>
     *
     * @param actionCode
     *        Represents the type of action to be performed with the derived variant criteria.
     *        Valid values are as follows:
     *        <br>
     *        1 - Overwrite (SET)
     *        <br>
     *        2 - Extend (OR)
     *        <br>
     *        4 - Reduce (AND)
     *
     * @param solveType
     *        Indicates the type of solve that needs to be performed with the variant criteria.
     *        For possible values see preference <code>TC_Default_Solve_Type.</code>
     *
     * @param saveNow
     *        Indicates whether the input objects should be saved to the database.
     *
     * @param createVariantRule
     *        Indicates whether a new <b>VariantRule</b> should be created as a copy of the input
     *        objects before assigning the new variant criteria. Unsaved changes to VariantRules
     *        automatically stored in a session recovery table to that they are not lost if a new
     *        Teamcenter server serves the next request.
     *
     * @param affectedVariantCriteriaObjects
     *        Variant criteria objects (<b>VariantRules</b>) for which variant criteria are assigned.
     *        Use a NULL object to create a new VariantRule from scratch.
     *        <br>
     *
     * @param productName
     *        Identifies the product. It is used in conjunction with parameter <code>productNameSpace</code>
     *        to resolve potential ambiguity in variant option value names, and to identify product
     *        context specific constraints. Teamcenter configurators use a Multiple Field Key (MFK)
     *        stable identifier (see property <b>Item::fnd0VariantNamespace</b>) of the product
     *        <b>item</b> for <code>productName</code>. The <code>productName</code> value for
     *        a Collaborative Design (<b>Cpd0CollaborativeDesign</b>) can be obtained from property<code>
     *        Mdl0ApplicationModel::mdl0config_product_name.</code>
     *
     * @param productNameSpace
     *        Specifies the namespace for the product identifier. It is used in conjunction with
     *        parameter <code>productName</code> to resolve potential ambiguity in variant option
     *        value names, and to identify product context specific constraints. Teamcenter configurators
     *        use the Revision ID of the product <b>ItemRevision</b> for <code>productNameSpace</code>.
     *        The <code>productNameSpace</code> value for a Collaborative Design (<b>Cpd0CollaborativeDesign</b>)
     *        can be obtained from property <code>Mdl0ApplicationModel::mdl0config_prod_namespace.</code>
     *
     * @param configuratorURL
     *        This is service end point for the variant configurator service. If empty the local
     *        Teamcenter configurator is used. Tc10.1 only supports local Teamcenter configurators.
     *        In Tc10.1 a non-empty <code>configuratorURL</code> parameter will cause an error.
     *
     * @return
     *         Response containing variant criteria set.
     *
     *
     * @exception ServiceException
     *           This operation may raise a <code>Teamcenter::Soa::Server::ServiceException </code>wrapping
     *           around following Teamcenter errors:
     *           <br>
     *           <br>
     *           92001&nbsp;&nbsp;&nbsp;&nbsp;An internal error has occurred in the "<code>Fnd0SoaConfigFilterCriteria</code>"
     *           module.
     *           <br>
     *           256000&nbsp;&nbsp;&nbsp;&nbsp;An internal configurator error occurred.
     *           <br>
     *           256001&nbsp;&nbsp;&nbsp;&nbsp;A general configurator error occurred.
     *           <br>
     *           256002&nbsp;&nbsp;&nbsp;&nbsp;The following product is invalid: [<i>DictionaryNamespace</i>]<i>FamilyName</i>
     *           (Context: <i>info</i>).
     *           <br>
     *           256003&nbsp;&nbsp;&nbsp;&nbsp;The following feature value is invalid: [<i>DictionaryNamespace</i>]<i>FamilyName</i>
     *           (<i>Context: info</i>).
     *           <br>
     *           256004&nbsp;&nbsp;&nbsp;&nbsp;The following feature family is invalid: [<i>DictionaryNamespace</i>]<i>FamilyName</i>
     *           (<i>Context: info</i>).
     *           <br>
     *           256005&nbsp;&nbsp;&nbsp;&nbsp;An invalid feature combination was found (<i>Context:
     *           info</i>).
     *           <br>
     *           256006&nbsp;&nbsp;&nbsp;&nbsp;An invalid product configuration was found (<i>Context:
     *           info</i>).
     *           <br>
     *           256007&nbsp;&nbsp;&nbsp;&nbsp;An invalid expression was found (<i>Context: info)</i>.
     *           <br>
     *           256008&nbsp;&nbsp;&nbsp;&nbsp;The following Boolean operator is invalid: <i>opcode</i>
     *           (<i>Context: info</i>).
     *           <br>
     *           256009&nbsp;&nbsp;&nbsp;&nbsp;An invalid effectivity date was found (<i>Context:
     *           info</i>).
     *           <br>
     *           256010&nbsp;&nbsp;&nbsp;&nbsp;A time-out occurred (<i>Context: info</i>).
     *           <br>
     *           256011&nbsp;&nbsp;&nbsp;&nbsp;A resource is not available (<i>Context: info</i>).
     *           <br>
     *           256012&nbsp;&nbsp;&nbsp;&nbsp;The following functionality is not implemented: function
     *           (<i>Version: TcVersion</i>).
     *           <br>
     *           256013&nbsp;&nbsp;&nbsp;&nbsp;A configurator implementation specific error occurred
     *           (<i>Context: info</i>).
     *           <br>
     *           256014&nbsp;&nbsp;&nbsp;&nbsp;The variant expression contains unmatched quote at
     *           position <i>number</i>.
     *           <br>
     *           256015&nbsp;&nbsp;&nbsp;&nbsp;The variant expression contains unmatched bracket at
     *           position <i>number</i>.
     *           <br>
     *           256016&nbsp;&nbsp;&nbsp;&nbsp;An unexpected token '<i>text</i>' was found at position
     *           <i>number</i>.
     *           <br>
     *           256017&nbsp;&nbsp;&nbsp;&nbsp;The entry '<i>text</i>' was found at position <i>number</i>
     *           when an option value was expected.
     *           <br>
     *           256018&nbsp;&nbsp;&nbsp;&nbsp;The token '<i>text</i>' is missing after '<i>text</i>'
     *           at position <i>number</i>.
     *           <br>
     *           256019&nbsp;&nbsp;&nbsp;&nbsp;The variant expression adaptor does not support <i>text</i>
     *           used at position <i>number</i>.
     *           <br>
     *           256020&nbsp;&nbsp;&nbsp;&nbsp;The XML tag '<i>text</i>' has no <i>text</i> value.
     *           <br>
     *           256021&nbsp;&nbsp;&nbsp;&nbsp;The string '<i>formula</i>' cannot be converted into
     *           an expression.
     *           <br>
     *           256022&nbsp;&nbsp;&nbsp;&nbsp;The operator code '<i>opcode</i>' in token at position
     *           <i>number</i> is unknown.
     *           <br>
     *           256023&nbsp;&nbsp;&nbsp;&nbsp;The variant value '<i>text</i>' in token at position
     *           <i>number</i> is unknown.
     *           <br>
     *           256024&nbsp;&nbsp;&nbsp;&nbsp;The variant family '<i>text</i>' in token at position
     *           <i>number</i> is unknown.
     *           <br>
     *           256025&nbsp;&nbsp;&nbsp;&nbsp;An ambiguous option value name '<i>FamilyName</i>'
     *           in namespace '<i>DictionaryNamespace</i>' in token at position <i>number</i> was
     *           found: <i>text</i>.
     *           <br>
     *           256026&nbsp;&nbsp;&nbsp;&nbsp;An ambiguous option family name '<i>FamilyName</i>'
     *           in token at position <i>number</i> was found: '<i>text</i>'.
     *           <br>
     *           256027&nbsp;&nbsp;&nbsp;&nbsp;The option namespace 'DictionaryNamespace' in token
     *           at position <i>number</i> is invalid.
     *           <br>
     *           256028&nbsp;&nbsp;&nbsp;&nbsp;The variant family '<i>FamilyName</i>' in token at
     *           position <i>number</i> is invalid.
     *           <br>
     *           256029&nbsp;&nbsp;&nbsp;&nbsp;The variant option value '<i>text</i>' for family '<i>FamilyName</i>'
     *           in token at position <i>number</i> is invalid.
     *           <br>
     *           256030&nbsp;&nbsp;&nbsp;&nbsp;The variant option value '<i>text</i>' for family '<i>FamilyName</i>'
     *           in token at position <i>number</i> is invalid: its value is not numeric.
     *           <br>
     *           256031&nbsp;&nbsp;&nbsp;&nbsp;The variant option value '<i>text</i>' for family '<i>FamilyName</i>'
     *           in token at position <i>number</i> is invalid: the value unit of measure '<i>text</i>'
     *           does not match the family unit of measure '<i>text</i>'.
     *           <br>
     *           256032&nbsp;&nbsp;&nbsp;&nbsp;The option / family / family namespace combination
     *           '<i>text</i>' / '<i>FamilyName</i>' / '<i>DictionaryNamespace</i>' in token at position
     *           <i>number</i> is invalid.
     *           <br>
     *           256033&nbsp;&nbsp;&nbsp;&nbsp;The family '<i>FamilyName</i>' for option / family
     *           namespace combination '<i>text</i>' / '<i>DictionaryNamespace</i>' in token at position
     *           <i>number</i> is invalid.
     *           <br>
     *           256034&nbsp;&nbsp;&nbsp;&nbsp;There is no option value in token at position <i>number</i>.
     *           <br>
     *           256035&nbsp;&nbsp;&nbsp;&nbsp;The variant option value '<i>text</i>' for family '<i>FamilyName</i>'
     *           in token at position '<i>number</i>' is invalid: the value is not a valid date.
     *           <br>
     */
    virtual Fnd0::Services::Configfiltercriteria::_2013_05::Variantmanagement::VariantCriteriaResponse setVariantCriteria ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::POM_object>  >& sampleObjects,
        const std::vector< Fnd0::Services::Configfiltercriteria::_2013_05::Variantmanagement::ConfigFormula >& formulae,
        const std::vector< Fnd0::Services::Configfiltercriteria::_2013_05::Variantmanagement::ConfigExpression >& expressions,
        int opCode,
        int substituteSymbolicVariables,
        int applyConstraints,
        int applyDefaults,
        int actionCode,
        int solveType,
        bool saveNow,
        bool createVariantRule,
        const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::POM_object>  >& affectedVariantCriteriaObjects,
        const std::string&  productName,
        const std::string&  productNameSpace,
        const std::string&  configuratorURL ) = 0;


protected:
    virtual ~Variantmanagement() {}
};
            }
        }
    }
}

#include <fnd0/services/configfiltercriteria/ConfigFilterCriteria_undef.h>
#endif

