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

#ifndef FND0_SERVICES_CONFIGFILTERCRITERIA__2011_06_EFFECTIVITYMANAGEMENT_HXX
#define FND0_SERVICES_CONFIGFILTERCRITERIA__2011_06_EFFECTIVITYMANAGEMENT_HXX

#include <teamcenter/soa/client/model/ConfigurationFamily.hxx>
#include <teamcenter/soa/client/model/POM_object.hxx>
#include <teamcenter/soa/client/model/RevisionRule.hxx>


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
            namespace _2011_06
            {
                class Effectivitymanagement;

class FND0SOACONFIGFILTERCRITERIASTRONGMNGD_API Effectivitymanagement
{
public:

    struct AvailableProductEffectivityResponse;
    struct ConfigOption;
    struct ConfigFormula;
    struct ConfigExpression;
    struct ConfigRuleViolation;
    struct ConfigurableProductsResponse;
    struct DefaultRule;
    struct EffectivityCondition;
    struct EffectivityConditionResponse;
    struct EffectivityExpressionsResponse;
    struct EffectivityFormulaeResponse;
    struct EffectivityTable;
    struct EffectivityTableRow;
    struct EffectivityTablesResponse;
    struct EffectivityValidationRecord;
    struct ProductInfo;
    struct RevRuleEffectivityCriteria;
    struct RevRuleEffectivityCriteriaResponse;

    /**
     * Response structure containing available product effectivity information.
     */
    struct AvailableProductEffectivityResponse
    {
        /**
         * Vector of expressions specifying an available range of effectivity. Together they
         * cover the range of availability over all families given in the input parameters <code>familiesToTest</code>
         * and (indirectly) <code>exprsToTest</code>.
         */
        std::vector< Fnd0::Services::Configfiltercriteria::_2011_06::Effectivitymanagement::ConfigExpression > configExpressions;
        /**
         * Partial errors are returned in Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The ConfigOption structure represents a configuration option that is unique in the
     * context of a configuration family. The ConfigOption structure is interpreted as "NULL"
     * if it has the following values set for its parameters:  - family: NULLTAG  - name:
     * empty string ("")  - description: empty string ("")
     */
    struct ConfigOption
    {
        /**
         * Namespace in which this option has unique semantics.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ConfigurationFamily>  family;
        /**
         * Name of the option value. "" is treated as NULL, i.e., it does not match any criteria,
         * not even other NULL values.
         */
        std::string name;
        /**
         * Description of the option value.
         */
        std::string description;
    };

    /**
     * The <code>ConfigFormula</code> structure represents a formula string associated with
     * a configuration expression in configurator syntax. The <code>ConfigFormula</code>
     * structure is considered <i>NULL</i> if it has following values set for its parameters:
     * <br>
     * <ul>
     * <li type="disc">formula: empty string ( )
     * </li>
     * <li type="disc">productName: empty string ( )
     * </li>
     * <li type="disc">productNameSpace: empty string ()
     * </li>
     * </ul>
     */
    struct ConfigFormula
    {
        /**
         * Formula string in a configurator specific encoding. Teamcenter configurators used
         * in the EffectivityManagement service interface encode formula in <b>Explicit Teamcenter
         * Language</b>.
         */
        std::string formula;
        /**
         * Specifies a product (e.g. using its Item ID). May be used in conjunction with parameter
         * <code>productNameSpace</code> when resolving ambiguity in effectivity option value
         * names.
         */
        std::string productName;
        /**
         * Namespace in which parameter <code>productName</code> has a unique definition, e.g.
         * an Item Revision ID, a Model Year, or a Product Type. May be used in conjunction
         * with parameter <code>productNameSpace</code> when resolving ambiguity in effectivity
         * option value names.
         */
        std::string productNameSpace;
    };

    /**
     * The <code>ConfigExpression</code> structure is interpreted as <code>NULL</code> if
     * it has the following values:
     * <br>
     * <ul>
     * <li type="disc">subExpressions: an empty vector
     * </li>
     * <li type="disc">value: a <code>NULL</code> <code>ConfigOption</code> structure
     * </li>
     * <li type="disc">opCode: <i>neg</i> 1
     * </li>
     * <li type="disc">formula: a <code>NULL</code> <code>ConfigFormula</code> structure
     * </li>
     * <li type="disc">effectivityTable: an empty vector
     * </li>
     * </ul>
     */
    struct ConfigExpression
    {
        /**
         * The list of sub expressions to be combined with <code>opcode</code>. <code>subExpressions</code>
         * and value must not both be present. If neither <code>subExpressions</code> nor <code>value</code>
         * are present, the expression is treated as the identity element for all <code>opcode</code>
         * values.
         */
        std::vector< Fnd0::Services::Configfiltercriteria::_2011_06::Effectivitymanagement::ConfigExpression > subExpressions;
        /**
         * The value to which <code>opCode</code> compares. <code>subExpressions</code> and
         * value must not both be present. If neither <code>subExpressions</code> nor <code>value</code>
         * are present, the expression is treated as the identity element for all <code>opcode</code>
         * values.
         */
        Fnd0::Services::Configfiltercriteria::_2011_06::Effectivitymanagement::ConfigOption value;
        /**
         * <ul>
         * <li type="disc">The operation code such as <code>or</code>, and, or <code>equal</code>.
         * See <code>$TC_INCLUDE/ps/ps_tokens.h.</code>
         * </li>
         * </ul>
         */
        int opCode;
        /**
         * If present, contains the configuration expression as a configuration formula.
         */
        Fnd0::Services::Configfiltercriteria::_2011_06::Effectivitymanagement::ConfigFormula formula;
        /**
         * If present, contains a representation of the configuration expression formatted as
         * a table where each row represents one validity range.
         */
        std::vector< Fnd0::Services::Configfiltercriteria::_2011_06::Effectivitymanagement::EffectivityTableRow > effectivityTable;
    };

    /**
     * The ConfigRuleViolation structure represents a violated rule along with the message
     * associated with rule violation. The ConfigRuleViolation structure is interpreted
     * to be <i>NULL</i> if following values are set to its parameters:
     * <br>
     * <ul>
     * <li type="disc">message: empty string ( )
     * </li>
     * <li type="disc">violatedCondition: a <i>NULL</i> ConfigExpression structure
     * </li>
     * </ul>
     */
    struct ConfigRuleViolation
    {
        /**
         * The text string associated with the rule violation.
         */
        std::string message;
        /**
         * The rule that was found to be violated.
         */
        Fnd0::Services::Configfiltercriteria::_2011_06::Effectivitymanagement::ConfigExpression violatedCondition;
    };

    /**
     * Response structure containing Configurable Product Information.
     */
    struct ConfigurableProductsResponse
    {
        /**
         * List of configurable products defined in the effectivity configurator.
         */
        std::vector< Fnd0::Services::Configfiltercriteria::_2011_06::Effectivitymanagement::ProductInfo > configurableProducts;
        /**
         * Partial errors are returned in ServiceData.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The DefaultRule structure represents the details of the default expression that is
     * applied to a config condition. The DefaultRule structure is interpreted to be <i>NULL</i>
     * if it has following values set to its parameters:
     * <br>
     * <ul>
     * <li type="disc">partiallyApplicable: false
     * </li>
     * <li type="disc">restrictiveCondition: a <i>NULL</i> ConfigExpression structure
     * </li>
     * <li type="disc">appliedDefault: <i>NULL</i> ConfigExpression structure
     * </li>
     * <li type="disc">appliedTo: <i>NULL</i> ConfigExpression structure
     * </li>
     * </ul>
     */
    struct DefaultRule
    {
        /**
         * If <i>true</i>, the <b>DefaultRule</b> is only applicable to a subset of the criteria.
         */
        bool partiallyApplicable;
        /**
         * The condition under which the default is applicable. A NULL <b>ConfigExpression</b>
         * structure indicates that the rule is always applicable.
         */
        Fnd0::Services::Configfiltercriteria::_2011_06::Effectivitymanagement::ConfigExpression restrictiveCondition;
        /**
         * The default that is applied, e.g., whenever <i>restrictiveCondition</i> is met.
         */
        Fnd0::Services::Configfiltercriteria::_2011_06::Effectivitymanagement::ConfigExpression appliedDefault;
        /**
         * The configuration criteria before applying the default.
         */
        Fnd0::Services::Configfiltercriteria::_2011_06::Effectivitymanagement::ConfigExpression appliedTo;
    };

    /**
     * The EffectivityCondition structure is interpreted to be "NULL" if the following values
     * are set to its parameters: formula: a "NULL" ConfigFormula structure (with all its
     * parameters sets to empty strings); affectedElement: NULLTAG
     */
    struct EffectivityCondition
    {
        /**
         * Effectivity condition formula
         */
        Fnd0::Services::Configfiltercriteria::_2011_06::Effectivitymanagement::ConfigFormula formula;
        /**
         * Product element on which the effectivity condition has been set
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::POM_object>  affectedElement;
    };

    /**
     * Response structure returning a set effectivity expressions. The response structure
     * is returned from multiple operations and needs to be interpreted depending on the
     * context in which it is returned.
     */
    struct EffectivityConditionResponse
    {
        /**
         * A vector of effectivity condition structures where each element references the resulting
         * effectivity condition and the corresponding object. The return vector does not necessarily
         * need to correspond to the input vector by index as it may need to contain information
         * about additional modified objects along with their new effectivity condition. This
         * could be the result of effectivity propagation to sub elements.
         */
        std::vector< Fnd0::Services::Configfiltercriteria::_2011_06::Effectivitymanagement::EffectivityCondition > effectivityConditions;
        /**
         * Partial errors are returned in Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Response structure returning a set effectivity expressions. The response structure
     * is returned from multiple operations and needs to be interpreted depending on the
     * context in which it is returned.
     */
    struct EffectivityExpressionsResponse
    {
        /**
         * A vector of effectivity expressions. The response structure is returned from multiple
         * operations and needs to be interpreted depending on the context in which it is returned.
         */
        std::vector< Fnd0::Services::Configfiltercriteria::_2011_06::Effectivitymanagement::ConfigExpression > effectivityExpressions;
        /**
         * Partial errors are returned in Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Response structure returning a set configuration formulae in a configurator specific
     * encoding. The response structure is returned from multiple operations and needs to
     * be interpreted depending on the context in which it is returned.
     */
    struct EffectivityFormulaeResponse
    {
        /**
         * A vector configuration formulae each representing one effectivity expression in a
         * configurator specific encoding. The response structure is returned from multiple
         * operations and needs to be interpreted depending on the context in which it is returned.
         */
        std::vector< Fnd0::Services::Configfiltercriteria::_2011_06::Effectivitymanagement::ConfigFormula > effectivityFormulae;
        /**
         * Partial errors are returned in Service Data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The <code>EffectivityTable</code> structure represents the set of validity ranges
     * for a configuration expression.
     * <br>
     * If <code>EffectivityTables</code> for different expressions (e.g. Unit = 5 and Unit
     * > 4 & Unit <code>EffectivityTableRows</code> might be different, but will still be
     * logically equivalent to the input expressions they correspond to.
     * <br>
     * The following example illustrates 3 different logically equivalent <code>EffectivityTable</code>
     * structures. A given Teamcenter server session will consistently return one of them.
     * <br>
     * <br>
     * <ul>
     * <li type="disc"><i>Unit=1..2 Date=Jan..Feb</i>
     * </li>
     * <li type="disc"><i>Unit=1..2 Date=Feb..Mar</i>
     * </li>
     * <li type="disc"><i>Unit=1..2 Date=Mar..Apr</i>
     * </li>
     * <li type="disc"><i>Unit=2..3 Date=Mar..Apr</i>
     * </li>
     * <li type="disc"><i>Unit=3..4 Date=Mar..Apr</i>
     * </li>
     * </ul>
     * <br>
     * <br>
     * The effectivity table above is equivalent to
     * <br>
     * <br>
     * <ul>
     * <li type="disc"><i>Unit=1..2 Date=Jan..Apr</i>
     * </li>
     * <li type="disc"><i>Unit=2..4 Date=Mar..Apr</i>
     * </li>
     * </ul>
     * <br>
     * <br>
     * But it is also equivalent to
     * <br>
     * <br>
     * <ul>
     * <li type="disc"><i>Unit=1..4 Date=Mar..Apr</i>
     * </li>
     * <li type="disc"><i>Unit=1..2 Date=Jan..Mar</i>
     * </li>
     * </ul>
     * <br>
     * <br>
     * The <code>EffectivityTable</code> structure is interpreted to be NULL if the following
     * values are set to its parameters:
     * <br>
     * <br>
     * <ul>
     * <li type="disc"><code>effectivityTableRows</code>: an empty vector
     * </li>
     * </ul>
     */
    struct EffectivityTable
    {
        /**
         * A vector of EffectivityTableRow structures each representing an effectivity range.
         * Some ranges may overlap.
         */
        std::vector< Fnd0::Services::Configfiltercriteria::_2011_06::Effectivitymanagement::EffectivityTableRow > effectivityTableRows;
    };

    /**
     * The EffectivityTableRow structure represents a validity range. The following constants
     * have special meaning:
     * <br>
     * <ul>
     * <li type="disc">January 2, 1900 12:00 AM UTC: Open Start Date
     * </li>
     * <li type="disc">December 30, 9999 12:00 AM UTC: Open End Date
     * </li>
     * <li type="disc">December 26, 9999 12:00 AM UTC: Stock Out
     * </li>
     * <li type="disc">1: Open Start Unit
     * </li>
     * <li type="disc">2147483647: Open End Unit
     * </li>
     * <li type="disc">2147483646: Stock Out
     * </li>
     * </ul>
     * <br>
     * Effect in as well as effect out points may have <i>NULL</i> values, which indicate
     * no value assigned:
     * <br>
     * <ul>
     * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;Neg 1: no unit value assigned
     * </li>
     * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;<i>NULL</i> date: no date value assigned
     * </li>
     * </ul>
     * <br>
     * The <code>EffectivityTableRow</code> structure is interpreted as <i>NULL</i> if the
     * following values are set:
     * <br>
     * <ul>
     * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;unitIn: Neg 1
     * </li>
     * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;unitOut: Neg 1
     * </li>
     * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;dateIn: a <i>NULL</i> date
     * </li>
     * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;dateOut: a <i>NULL</i> date
     * </li>
     * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;rest: a <i>NULL</i> <code>ConfigFormula</code>
     * structure
     * </li>
     * </ul>
     */
    struct EffectivityTableRow
    {
        /**
         * Unit at which this validity range starts.
         */
        int unitIn;
        /**
         * Unit at which the validity range ends.
         */
        int unitOut;
        /**
         * Date at which the validity range starts.
         */
        Teamcenter::Soa::Common::DateTime dateIn;
        /**
         * Date at which the validity range ends.
         */
        Teamcenter::Soa::Common::DateTime dateOut;
        /**
         * Effectivity conditions in this range that are neither date nor unit related.
         */
        Fnd0::Services::Configfiltercriteria::_2011_06::Effectivitymanagement::ConfigFormula rest;
    };

    /**
     * <code>EffectivityTablesResponse</code> structure
     */
    struct EffectivityTablesResponse
    {
        /**
         * A vector of effectivity table structures each representing one effectivity expression.
         */
        std::vector< Fnd0::Services::Configfiltercriteria::_2011_06::Effectivitymanagement::EffectivityTable > effectivityTables;
        /**
         * Partial errors are returned in Service Data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The EffectivityValidationRecord structure represents validation results for effectivity
     * criteria associated with a revision rule. The EffectivityValidationRecord structure
     * is interpreted to be "NULL" if the following values are set to its parameters:  -
     * validationDate: a null date representing "0001-01-01T00:00:00Z" ("January 1, 0001,
     * midnight, UTC")  - validationResult: a "NULL" ConfigFormula structure with all its
     * parameters set to empty strings  - undeterminedFamilies: an empty vector  - violations:
     * an empty vector  - appliedDefaults: an empty vector
     */
    struct EffectivityValidationRecord
    {
        /**
         * Date at which the validation was performed.
         */
        Teamcenter::Soa::Common::DateTime validationDate;
        /**
         * Validation result after applying effectivity configurator rules.
         */
        Fnd0::Services::Configfiltercriteria::_2011_06::Effectivitymanagement::ConfigFormula validationResult;
        /**
         * Families that are not set to a single value. If empty, the criteria are complete.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ConfigurationFamily>  > undeterminedFamilies;
        /**
         * Violation records. If empty, the effectivity criteria are valid.
         */
        std::vector< Fnd0::Services::Configfiltercriteria::_2011_06::Effectivitymanagement::ConfigRuleViolation > violations;
        /**
         * One record for each applied default in the sequence they were applied
         */
        std::vector< Fnd0::Services::Configfiltercriteria::_2011_06::Effectivitymanagement::DefaultRule > appliedDefaults;
    };

    /**
     * The ProductInfo structure represents product name and product namespace combination.
     * This structure is interpreted as NULL if it has empty ( ) values for <code>productName</code>
     * and <code>productNameSpace</code> parameters.
     */
    struct ProductInfo
    {
        /**
         * Specifies a product. A (<code>productName,productNamespace</code>) tuple is used
         * as a parameter in configurator service calls so to allow the configurator to resolve
         * any ambiguity in effectivity condition parameters. Applications using this <code>EffectivityManagement</code>
         * service should define a mechanism to obtain an appropriate value for this parameter.
         * For example, <code>ApplicationModel</code> objects like Collaborative Design models
         * (<b>Cpd0CollaborativeDesign</b>) make them available via properties <code>mdl0config_product_name</code>,
         * and <code>mdl0config_prod_namespace.</code>
         */
        std::string productName;
        /**
         * Specifies a namespace in which parameter <code>productName</code> has a unique definition,
         * e.g. a specific model year, or product type. A (<code>productName,productNamespace</code>)
         * tuple is used as a parameter in configurator service calls so to allow the configurator
         * to resolve any ambiguity in effectivity condition parameters. Applications using
         * this <code>EffectivityManagement</code> service should define a mechanism to obtain
         * an appropriate value for this parameter. For example, <code>ApplicationModel</code>
         * objects like Collaborative Design models (<b>Cpd0CollaborativeDesign</b>) make them
         * available via properties <code>mdl0config_product_name</code>, and <code>mdl0config_prod_namespace.</code>
         */
        std::string productNameSpace;
    };

    /**
     * The RevRuleEffectivityCriteria structure represents a revision rule along with its
     * effectivity criteria and associated validation records. The RevRuleEffectivityCriteria
     * structure is interpreted to be <i>NULL</i> if the following values are set for its
     * parameters:
     * <br>
     * <ul>
     * <li type="disc">revisionRule: <i>NULL</i>TAG
     * </li>
     * <li type="disc">primaryEffectivity: a NULL ConfigFormula structure with all its parameters
     * set to empty strings
     * </li>
     * <li type="disc">solveType: neg 1
     * </li>
     * <li type="disc">validationRecords: empty vector
     * </li>
     * </ul>
     */
    struct RevRuleEffectivityCriteria
    {
        /**
         * The modified <b>RevisionRule</b>. This could be a transient copy.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::RevisionRule>  revisionRule;
        /**
         * Original unprocessed effectivity criteria, before effectivity configurator rules
         * were applied.
         */
        Fnd0::Services::Configfiltercriteria::_2011_06::Effectivitymanagement::ConfigFormula primaryEffectivity;
        /**
         * Indicates the type of solve that will be performed when using the effectivity criteria
         * in configuration filters.
         */
        int solveType;
        /**
         * Validation records related to the effectivity criteria
         */
        std::vector< Fnd0::Services::Configfiltercriteria::_2011_06::Effectivitymanagement::EffectivityValidationRecord > validationRecords;
    };

    /**
     * Response structure containing Revision Rule Effectivity Criteria Infomation.
     */
    struct RevRuleEffectivityCriteriaResponse
    {
        /**
         * Vector of effectivity criteria structures.
         */
        std::vector< Fnd0::Services::Configfiltercriteria::_2011_06::Effectivitymanagement::RevRuleEffectivityCriteria > effectivityCriteria;
        /**
         * Partial errors are returned in Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * This operation returns string representations (formulae) for a given set of effectivity
     * expressions. This operation connects to the effectivity configurator service whose
     * service endpoint is specified by the <code>configuratorURL</code> parameter. The
     * actual conversion to formula strings is performed by this configurator service. The
     * result may vary depending on the choice of service endpoint and the product identified
     * by parameters <code>productName</code> and <code>productNameSpace</code>. For example
     * a given configurator might return shorthand representations for formulae if these
     * are unique in the context of the specified product. Teamcenter 9 only supports local
     * built in Teamcenter configurators where parameters <code>productName</code>, <code>productNameSpace</code>,
     * and<code> configuratorURL</code> can be set to an empty string.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Obtain a formula string representation (<code>ConfigFormula</code>) in the context
     * of a Collaborative Design model (<b>Cpd0CollaborativeDesign</b>) for an effectivity
     * expression (<code>ConfigExpression</code>) when these expression do not already reference
     * a formula.
     * <br>
     * <br>
     * When effectivity expressions are returned from effectivity SOA operations, e.g. <code>getAvailableProductEffectivity</code>
     * for a given <b>RevisionRule</b>, they usually already contain a corresponding formula
     * string representation. However, there is no guarantee they always do, e.g. if the
     * configurator link is temporarily down.
     * <br>
     * <br>
     * Another scenario in which effectivity expressions exist without a corresponding formula
     * string representation is when these expressions are constructed in the SOA client.
     * <br>
     * <ul>
     * <li type="disc">Identifiers for the product associated with the Collaborative Design
     * model (CD) are obtained from CD properties  <code>mdl0config_product_name</code>,
     * and <code>mdl0config_prod_namespace</code>.
     * </li>
     * <li type="disc">Operation <code>convertEffectivityExpressions</code> is used to convert
     * the effectivity conditions into formula strings.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * getProperties
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Configuration Management - Capability to configure structured data based on revsion
     * rules; effectivities; Status etc.
     *
     * @param expressions
     *        Vector of effectivity expressions (<code>ConfigExpression</code>) where these expression
     *        do not yet contain a corresponding formula string representation (<code>ConfigFormula</code>).
     *
     * @param productName
     *        Specifies a product. A (<code>productName</code><i>,</i><code>productNamespace</code>)
     *        tuple is used as a parameter in configurator service calls so to allow the configurator
     *        to resolve any ambiguity in effectivity condition parameters. Applications using
     *        this <code>EffectivityManagement</code> service should define a mechanism to obtain
     *        an appropriate value for this parameter. For example, <code>ApplicationModel</code>
     *        objects like Collaborative Design models (<b>Cpd0CollaborativeDesign</b>) make them
     *        available via properties <code>mdl0config_product_name</code>, and <code>mdl0config_prod_namespace</code>.
     *
     * @param productNameSpace
     *        Specifies a namespace in which parameter <code>productName</code> has a unique definition,
     *        e.g. a specific model year, or product type. A (<code>productName</code><i>,</i><code>productNamespace</code>)
     *        tuple is used as a parameter in configurator service calls so to allow the configurator
     *        to resolve any ambiguity in effectivity condition parameters. Applications using
     *        this <code>EffectivityManagement</code> service should define a mechanism to obtain
     *        an appropriate value for this parameter. For example, <code>ApplicationModel</code>
     *        objects like Collaborative Design models (<b>Cpd0CollaborativeDesign</b>) make them
     *        available via properties <code>mdl0config_product_name</code>, and <code>mdl0config_prod_namespace</code>.
     *
     * @param configuratorURL
     *        URL for the Effectivity Configurator service endpoint to connect to.
     *
     * @return
     *         A set of configurator specific formula string representations in for a set of effectivity
     *         expressions, e.g.<code>[Teamcenter::]Unit >= 1 & [Teamcenter::]Unit < 11</code>.
     *         Partial errors may be returned in <code>ServiceData</code>, e.g. if the service fails
     *         to connect to the configurator, or if an error was returned from the configurator.
     *
     */
    virtual Fnd0::Services::Configfiltercriteria::_2011_06::Effectivitymanagement::EffectivityFormulaeResponse convertEffectivityExpressions ( const std::vector< Fnd0::Services::Configfiltercriteria::_2011_06::Effectivitymanagement::ConfigExpression >& expressions,
        const std::string&  productName,
        const std::string&  productNameSpace,
        const std::string&  configuratorURL ) = 0;

    /**
     * This operation returns string representations (formulae) for a given set of effectivity
     * tables where each table describes a separate set of effectivity ranges. This operation
     * connects to the effectivity configurator service whose service endpoint is specified
     * by the <code>configuratorURL</code> parameter. The actual conversion to formula strings
     * is performed by this configurator service. The result may vary depending on the choice
     * of service endpoint and the product identified by parameters <code>productName</code>
     * and <code>productNameSpace</code>. For example a given configurator might return
     * shorthand representations for formulae if these are unique in the context of the
     * specified product. Teamcenter 9 only supports local built in Teamcenter configurators
     * where parameters <code>productName</code>, <code>productNameSpace</code>, and <code>configuratorURL</code>
     * can be set to an empty string.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Review the configurator encoded formula string representation for a table of effectivity
     * ranges before assigning the effectivity ranges to a Revision Rule.
     * <br>
     * <ul>
     * <li type="disc">An application displays a dialog that collects a set of effectivity
     * ranges in form of(<i>unit in ,unit out </i>) and/or (<i>date in ,date out</i>) tuples
     * from the user with the intent to eventually use these effectivity ranges as configuration
     * criteria to be assigned to a <b>RevisionRule</b>.
     * </li>
     * <li type="disc">The user wants to review the configurator encoding of the corresponding
     * effectivity expression
     * </li>
     * <li type="disc">Operation <code>convertEffectivityTables</code> is used to convert
     * the effectivity table of effect in and effect out points into a formula string.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Configuration Management - Capability to configure structured data based on revsion
     * rules; effectivities; Status etc.
     *
     * @param effectivityTables
     *        Vector of effectivity tables representing validity ranges as rows of (<i>effect in,effect
     *        out</i>) tuples.
     *
     * @param productName
     *        Specifies a product. A (<code>productName,productNamespace</code>) tuple is used
     *        as a parameter in configurator service calls so to allow the configurator to resolve
     *        any ambiguity in effectivity condition parameters. Applications using this <code>EffectivityManagement</code>
     *        service should define a mechanism to obtain an appropriate value for this parameter.
     *        For example, <code>ApplicationModel</code> objects like Collaborative Design models
     *        (<b>Cpd0CollaborativeDesign</b>) make them available via properties <b>mdl0config_product_name</b>,
     *        and <b>mdl0config_prod_namespace</b>.
     *
     * @param productNameSpace
     *        Specifies a namespace in which parameter <code>productName</code> has a unique definition,
     *        e.g. a specific model year, or product type. A (<code>productName,productNamespace</code>)
     *        tuple is used as a parameter in configurator service calls so to allow the configurator
     *        to resolve any ambiguity in effectivity condition parameters. Applications using
     *        this <code>EffectivityManagement</code> service should define a mechanism to obtain
     *        an appropriate value for this parameter. For example, <code>ApplicationModel</code>
     *        objects like Collaborative Design models (<b>Cpd0CollaborativeDesign</b>) make them
     *        available via properties <b>mdl0config_product_name</b>, and <b>mdl0config_prod_namespace</b>.
     *
     * @param configuratorURL
     *        URL for the Effectivity Configurator service endpoint to connect to.
     *
     * @return
     *         A set of formula strings representing a set of effectivity tables, e.g. <code>[Teamcenter::]Unit
     *         >= 1 & [Teamcenter::]Unit < 11</code>. Partial errors may be returned in <code>ServiceData</code>,
     *         e.g. if the service fails to connect to the configurator.
     *
     */
    virtual Fnd0::Services::Configfiltercriteria::_2011_06::Effectivitymanagement::EffectivityFormulaeResponse convertEffectivityTables ( const std::vector< Fnd0::Services::Configfiltercriteria::_2011_06::Effectivitymanagement::EffectivityTable >& effectivityTables,
        const std::string&  productName,
        const std::string&  productNameSpace,
        const std::string&  configuratorURL ) = 0;

    /**
     * This operation returns available effectivity that could be used to satisfy the specified
     * <b>RevisionRule</b>, or the subset of the <b>RevisionRule</b> as defined by parameters
     * <code>exprsToTest</code> and <code>familiesToTest</code>. Parameters <code>productName</code>
     * and <code>productNameSpace</code> can be used to identify a product whose effectivity
     * constraints will be considered in this operation. No product effectivity constraints
     * are considered if these parameters are empty. If parameters <code>exprsToTest</code>
     * and <code>familiesToTest</code><i> </i>are empty and no product context is given
     * the unmodified basic range of effectivity represented by the given <b>RevisionRule</b>
     * is returned. If <code>exprsToTest</code> or <code>familiesToTest</code> are provided,
     * then the available range of effectivity for these expressions and /or families will
     * be returned.
     * <br>
     * <br>
     * The operation forms a <i>config</i> expression from the provided input parameters
     * by ORing the expressions in parameter <code>exprsToTest</code> (resulting in TRUE
     * if <code>exprsToTest</code> was empty), and ANDing the result with the effectivity
     * associated with the <b>RevisionRule</b> (using TRUE if none was specified). The response
     * will return available effectivity for the union set of families used in this <i>config</i>
     * expression with the families listed in <code>familiesToTest</code>. If the resulting
     * list is empty, <i>available</i> effectivity for all families will be returned. Effectivity
     * is considered available if it neither conflicts with the <i>config</i> expression
     * nor with the effectivity validation rules defined in the product identified by parameters
     * <code>productName</code> and <code>productNameSpace</code> (if present). Because
     * of the way the <i>config</i> expression is formed the operation can only return meaningful
     * results if either a <b>RevisionRule</b>, or a list of <code>exprsToTest</code>, or
     * a list of <code>familiesToTest</code> (or a combination of the above) are provided.
     * If all parameters are NULL the response will return no effectivity.
     * <br>
     * <br>
     * Operation <code>getRevRuleEffectivityCriteria</code> should be used if symbolic variable
     * substitution and/or constraint processing is required for *all* variant option families,
     * or if validation records are required that specify violated constraints.
     * <br>
     * <br>
     * Operation <code>setEffectivityConditions</code> should be used if assigning the combined
     * effectivity range covering a set of existing objects does not require the evaluation
     * of configurator constraints. The difference is that <code>getAvailableProductEffectivity</code>
     * supports parameters that enable effectivity configurator validation rules, which
     * can be used to eliminate effectivity combinations from the combined range that are
     * not available according to the current set of validation rules. Eliminating invalid
     * combinations reduces the number of false positive results detected by automated collision
     * detection systems such as Teamcenter Clearance Analysis. On the other hand persisting
     * such expressions causes the condition to be out of date if the set of configurator
     * validation rules changes.
     * <br>
     * This operation connects to the effectivity configurator service whose service endpoint
     * is specified by the <code>configuratorURL</code> parameter. The actual evaluation
     * of configurator rules to trim available effectivity, and conversions to and from
     * formula strings, are performed by this configurator service. The resulting formula
     * string conversions may vary depending on the choice of service endpoint. For example
     * a given configurator might return shorthand representations for formulae if these
     * are unique in the context of the specified product. Teamcenter 9 only supports local
     * builtin Teamcenter configurators where parameter <code>configuratorURL</code> can
     * be set to an empty string. Teamcenter configurators used in the <code>EffectivityManagement</code>
     * service interface encode configuration formulae in <b>Explicit Teamcenter Language</b>
     * for which no product context is required (see operation <code>getEffectivityExpressions</code>
     * for more details on <b>Explicit Teamcenter Language</b> and <code>productName</code>
     * and <code>productNameSpace</code>).
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Use case 1:Initialize an effectivity criteria dialog for a given <b>RevisionRule</b>.
     * <br>
     * <ul>
     * <li type="disc">The application uses operation <code>getAvailableProductEffectivity</code>
     * with <code>productName=, productNameSpace=, exprsToTest={}, and familiesToTest={},
     * substituteDependentVariables=0, applyConstraints=0.</code>
     * </li>
     * <li type="disc">The response will contain effectivity ranges as they are stored on
     * the <b>RevisionRule</b> without additional configurator processing. References to
     * effectivity configuration families (<b>ConfigurationFamily</b>) are returned in <code>ServiceData</code>.
     * </li>
     * </ul>
     * <br>
     * <br>
     * Use case 2:
     * <br>
     * Initialize an effectivity criteria dialog for a product that was created using the
     * Teamcenter effectivity configurator with the intent to setup a new <b>RevisionRule</b>.
     * <br>
     * <ul>
     * <li type="disc">The application uses operation <code>getAvailableProductEffectivity</code>
     * with <code>productName=MyProductItemID, productNameSpace=MyProductRevID, exprsToTest={},
     * and familiesToTest={}, substituteDependentVariables=0, applyConstraints=0.</code>
     * </li>
     * <li type="disc">The response will contain all nominal effectivity ranges in this
     * product. No constraint processing is required. References to effectivity configuration
     * families (<b>ConfigurationFamily</b>) are returned in <b>ServiceData</b>.
     * </li>
     * </ul>
     * <br>
     * Use case 3:
     * <br>
     * Initialize an effectivity criteria dialog for a product that is associated with a
     * Collaborative Design (CD) model with the intent to setup a new <b>RevisionRule</b>.
     * <br>
     * <ul>
     * <li type="disc">Identifiers for the product associated with the CD (Cpd0CollaborativeDesign)
     * are obtained from CD properties <code>mdl0config_product_name</code>, and <code>mdl0config_prod_namespace</code>.
     * </li>
     * <li type="disc">The application uses operation <code>getAvailableProductEffectivity</code>
     * with <code>productName=</code> and <code>productNameSpace= </code> as obtained in
     * the previous step,<code> exprsToTest={}, and familiesToTest={}, substituteDependentVariables=0,
     * applyConstraints=0.</code>
     * </li>
     * <li type="disc">The response will contain all nominal effectivity ranges in this
     * product. No constraint processing is required. References to effectivity configuration
     * families (<b>ConfigurationFamily</b>) are returned in <code>ServiceData</code>.
     * </li>
     * </ul>
     * <br>
     * Use case 4:
     * <br>
     * Iterate through all available configuration families (<b>ConfigurationFamily</b>)
     * with the intent to assign values to each configuration family in an iterative process
     * while dynamically requesting the remaining available range of values for a given
     * configuration family.
     * <br>
     * <ul>
     * <li type="disc">The application uses operation <code>getAvailableProductEffectivity</code>
     * with the same values for <code>productName</code>, and <code>productNameSpace</code>
     * that was used in the initialization step (see above use cases). Parameter exprsToTest
     * is used to accumulate the choices that were made in previous iteration steps. Parameter
     * <code>familiesToTest={nextFamilyInList} </code>is used to specify the family for
     * which available value ranges are requested in this iteration step. The remaining
     * parameter values are <code>substituteDependentVariables</code>=0, and <code>applyConstraints</code>=1.
     * </li>
     * <li type="disc">The response will contain the available value range for the specified
     * <code>familiesToTest</code>.
     * </li>
     * </ul>
     * <br>
     * <br>
     * Use case 5:
     * <br>
     * Request the effectivity configuration criteria in which at least one of multiple
     * objects configures and eliminate criteria from this result that violate any current
     * validation rules in the context of a Collaborative Design (CD) model.
     * <br>
     * <ul>
     * <li type="disc">A radar cable design shall be given an effectivity condition such
     * that it configures whenever any of a given set of radar systems and radar screens
     * configures.
     * </li>
     * <li type="disc">Identifiers for the product associated with the CD (<b>Cpd0CollaborativeDesign</b>)
     * are obtained from CD  properties <code>mdl0config_product_name</code>, and <code>mdl0config_prod_namespace</code>.
     * </li>
     * <li type="disc">The application uses operation <code>getEffectivityConditions</code>
     * to obtain the set of conditions associated with the radar systems and screens.
     * </li>
     * <li type="disc">The application uses operation <code>getAvailableProductEffectivity</code>
     * where parameter <code>exprsToTest</code> is used to pass the effectivity conditions
     * associated with the radar systems and screens. Parameter familiesToTest is left empty.
     * The remaining parameter values are <code>substituteDependentVariables</code>=0, and
     * <code>applyConstraints</code>=1.
     * </li>
     * <li type="disc">The response will contain the actually available effectivity range
     * for the listed radar systems and screens according to the current set of effectivity
     * configurator validation rules.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * getProperties, findWorkspaceObjects
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Configuration Management - Capability to configure structured data based on revsion
     * rules; effectivities; Status etc.
     *
     * @param revisionRule
     *        <b>RevisionRule</b> in which context availability is requested. If present it will
     *        be used to filter available values. If no <b>RevisionRule</b> is specified all configuration
     *        criteria are expected to be defined in <code>exprsToTest</code>.
     *
     * @param exprsToTest
     *        Specifies additional effectivity expressions in which context availability is requested.
     *
     * @param familiesToTest
     *        Specifies configuration families for which available values are requested in addition
     *        to those referenced from <code>exprsToTest</code> and <b>RevisionRule</b>.
     *
     * @param substituteDependentVariables
     *        Indicates whether or not to substitute dependent variables, such as <code>PlantVacationShutdown</code>.
     *        Value <i>0</i> will indicate no substitution is required. A value of <i>1</i> will
     *        enable substitution of dependent variables
     *
     * @param applyConstraints
     *        Indicates whether or not to apply the constraints. Value <i>0</i> will indicate constraint
     *        application is not required. A value of <i>1</i> will enable application of constraints
     *
     * @param productName
     *        Specifies a product. A (<code>productName,productNamespace</code>) tuple is used
     *        as a parameter in configurator service calls so to allow the configurator to resolve
     *        any ambiguity in effectivity condition parameters. Applications using this <code>EffectivityManagement</code>
     *        service should define a mechanism to obtain an appropriate value for this parameter.
     *        For example, <code>ApplicationModel</code> objects like Collaborative Design models
     *        (<b>Cpd0CollaborativeDesign</b>) make them available via properties <code>mdl0config_product_name</code>,
     *        and <code>mdl0config_prod_namespace</code>.
     *
     * @param productNameSpace
     *        Specifies a namespace in which parameter <code>productName</code> has a unique definition,
     *        e.g. a specific model year, or product type. A (<code>productName,productNamespace</code>)
     *        tuple is used as a parameter in configurator service calls so to allow the configurator
     *        to resolve any ambiguity in effectivity condition parameters. Applications using
     *        this <code>EffectivityManagement</code> service should define a mechanism to obtain
     *        an appropriate value for this parameter. For example, <code>ApplicationModel</code>
     *        objects like Collaborative Design models (<b>Cpd0CollaborativeDesign</b>) make them
     *        available via properties <code>mdl0config_product_name</code>, and <code>mdl0config_prod_namespace</code>.
     *
     * @param configuratorURL
     *        URL for the Effectivity Configurator service endpoint to connect to.
     *
     * @return
     *         Returns the available product effectivity based on the specified revision rule and
     *         product parameters. Partial errors may be returned in <code>ServiceData</code>, e.g.
     *         if the service fails to connect to the configurator, or if an error was returned
     *         from the configurator.
     *
     */
    virtual Fnd0::Services::Configfiltercriteria::_2011_06::Effectivitymanagement::AvailableProductEffectivityResponse getAvailableProductEffectivity ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::RevisionRule>  revisionRule,
        const std::vector< Fnd0::Services::Configfiltercriteria::_2011_06::Effectivitymanagement::ConfigExpression >& exprsToTest,
        const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ConfigurationFamily>  >& familiesToTest,
        int substituteDependentVariables,
        int applyConstraints,
        const std::string&  productName,
        const std::string&  productNameSpace,
        const std::string&  configuratorURL ) = 0;

    /**
     * This operation returns all effectivity configurable products from the effectivity
     * configurator identified by parameter <code>configuratorURL</code>. The operation
     * connects to the effectivity configurator service whose service endpoint is specified
     * by the <code>configuratorURL</code> parameter. The query for available effectivity
     * configurable products is performed by this configurator service. Teamcenter 9 only
     * supports local builtin Teamcenter configurators where parameter <code>configuratorURL</code>
     * can be set to an empty string. Teamcenter configurators use an Item ID for <code>productName</code>
     * and an Item Revision ID or RDV  Product Context Identifier for <code>productNameSpace</code>.
     * Teamcenter configurators return all <b>ItemRevision</b> objects that allocate effectivity
     * configuration families as effectivity configurable products.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Associate a product item with a Collaborative Design (CD) model so that effectivity
     * configurator rules associated with this product are also associated with the CD.
     * The assumption is that the CD is an application model (<b>Mdl0ApplicationModel</b>)
     * for the product represented by this product item.
     * <br>
     * <ul>
     * <li type="disc">Operation <code>getConfigurableProducts</code> is used to obtain
     * a list of all effectivity configurable products.
     * </li>
     * <li type="disc">User reviews the list of available (<code>productName, productNameSpace</code>)
     * and selects one.
     * </li>
     * <li type="disc">Operation <code>findWorkspaceObjects</code> is used to locate the
     * product <b>ItemRevision</b> that corresponds to the given (<code>productName, productNameSpace</code>)
     * tuple.
     * </li>
     * <li type="disc">Operation <code>createRelations</code> is used to attach the product
     * <b>ItemRevision</b> to the CD using <code>primaryObject=CD, secondaryObject=MyProductItemRevision,
     * and relationType=Mdl0HasConfiguratorContext.</code>
     * </li>
     * <li type="disc">Operation <code>refreshObjects</code> is used to refresh the CD.
     * </li>
     * <li type="disc">Identifiers for the product associated with the CD (<b>Cpd0CollaborativeDesign</b>)
     * are obtained from CD properties <code>mdl0config_product_name</code>, and <code>mdl0config_prod_namespace.</code>
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
     *        URL for the Effectivity Configurator service endpoint to connect to.
     *
     * @return
     *         This operation returns all effectivity configurable products from the effectivity
     *         configurator. Partial errors may be returned in <code>ServiceData</code>, e.g. if
     *         the service fails to connect to the configurator, or if an error was returned from
     *         the configurator.
     *
     */
    virtual Fnd0::Services::Configfiltercriteria::_2011_06::Effectivitymanagement::ConfigurableProductsResponse getConfigurableProducts ( const std::string&  configuratorURL ) = 0;

    /**
     * This operation returns the effectivity conditions associated with the objects specified
     * in <code>affectedObjects</code> in form of a configurator specific formula string.
     * This operation connects to the effectivity configurator service whose service endpoint
     * is specified by the <code>configuratorURL</code> parameter. The actual conversion
     * to formula strings is performed by this configurator service. The result may vary
     * depending on the choice of service endpoint. For example a given configurator might
     * return shorthand representations for formulae if these are unique in the context
     * of the specified product. Teamcenter 9 only supports local built in Teamcenter configurators
     * where parameter <code>configuratorURL</code> can be set to an empty string.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Obtain a formula string representation for the effectivity configuration conditions
     * associated with set of design elements (<b>Cpd0DesignModelElement</b>) in a Collaborative
     * Design model (<b>Cpd0CollaborativeDesign</b>).
     * <br>
     * <ul>
     * <li type="disc">Multiple weld points (<b>Cpd0DesignFeature</b>) exist in the context
     * of a Design Control Element (<b>Cpd0DesignControlElement</b>).
     * </li>
     * <li type="disc">The effectivity range for each weld point is therefore equivalent
     * to the intersection between their own effectivity range and the range of effectivity
     * for the Design Control Element (DCE).
     * </li>
     * <li type="disc">In order to review the effectivity ranges an application requests
     * the effectivity condition for each weld point using operation <code>getEffectivityConditions</code>.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Configuration Management - Capability to configure structured data based on revsion
     * rules; effectivities; Status etc.
     *
     * @param affectedObjects
     *        Contains objects for which effectivity conditions are requested. Only objects with
     *        <code>EffectivityConfigurable</code> behavior such as <b>Mdl0ConditionalArtifact</b>
     *        (e.g. <b>Ptn0ChildParentLink</b> or <b>Ptn0Membership</b>) or <b>Mdl0ConditionalElement</b>
     *        (e.g. <b>Cpd0DesignControlElement</b>, <b>Cpd0DesignElement</b>, <b>Cpd0DesignSubsetElement</b>,
     *        or <b>Cpd0ArcFilletWeld</b> and <b>Cpd0ArcGrooveWeld</b>) can have effectivity conditions.
     *        For objects that either dont have <code>EffectivityConfigurable</code> behavior,
     *        or which are not associated with an effectivity condition, a <i>NULL</i> configuration
     *        formula struct is returned.
     *
     * @param configuratorURL
     *        URL for the Effectivity Configurator service endpoint to connect to.
     *
     * @return
     *         A set of formula strings representing the effectivity conditions in a configurator
     *         specific encoding that are associated with the objects in <code>affectedObjects</code>,
     *         e.g.<code> [Teamcenter::]Unit >= 1 & [Teamcenter::]Unit < 11.</code> Partial errors
     *         may be returned in <code>ServiceData</code>, e.g. if the service fails to connect
     *         to the configurator, or if an error was returned from the configurator.
     *
     */
    virtual Fnd0::Services::Configfiltercriteria::_2011_06::Effectivitymanagement::EffectivityFormulaeResponse getEffectivityConditions ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::POM_object>  >& affectedObjects,
        const std::string&  configuratorURL ) = 0;

    /**
     * This operation returns effectivity expressions for a given set of effectivity formulae
     * in the context of the given productName and productNameSpace combination. This operation
     * connects to the effectivity configurator service whose service endpoint is specified
     * by the configuratorURL parameter. Any conversion from formula strings is performed
     * by this configurator service. Depending on the (configurator specific) encoding the
     * operation might require the specification of a product context using parameters productName
     * and productNameSpace. For example, a given configurator might recognize shorthand
     * representations for formulae if these are unique in the context of the specified
     * product. Teamcenter 9 only supports local built in Teamcenter configurators where
     * parameter configuratorURL can be set to an empty string. Teamcenter configurators
     * dont require a product context if the formulae are in <b>Explicit Teamcenter Language</b>.
     * The encoding is explicit if all lexemes are uniquely identified, e.g. <i>[OptionNamespace]FamilyName
     * = UniqueValue</i>, where no product context is required to determine the family name
     * for a value, or the option namespace for the family. A variant formula is in <b>Explicit</b>
     * <b>Teamcenter Language</b> if its form is explicit and comprised of the lexemes documented
     * for the Teamcenter Variant Formula property. Teamcenter configurators support shorthand
     * encodings like <i>FamilyName = UniqueValue</i> or <i>UniqueValue</i> if the lexemes
     * used in the shorthand encoding are unique in the specified product context.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Obtain an effectivity expression (<b>ConfigExpression</b>) for a formula string representation
     * (<b>ConfigFormula</b>) in the context of a Collaborative Design model (<b>Cpd0CollaborativeDesign</b>).
     * <br>
     * Some effectivity SOA operations, <b>e.g. </b><code>getEffectivityConditions</code>,
     * formula string representations, which might be easier to review if presented in expression
     * format.
     * <br>
     * <ul>
     * <li type="disc">A weld point (<b>Cpd0DesignFeature</b>) exists in the context of
     * a Design Control Element (<b>Cpd0DesignControlElement</b>).
     * </li>
     * <li type="disc">Effectivity Unit=10..UP is assigned to the weld point using operation
     * <code>setEffectivityConditions</code>.
     * </li>
     * <li type="disc">The same operation is then used to assign effectivity Unit=1..5 to
     * Design Control Element (DCE), which reduces the effectivity range of all model elements
     * controlled by this DCE. The result is that the weld point above is no longer effective
     * since its effectivity range has no overlap with the DCE that controls it.
     * </li>
     * <li type="disc">In order to understand why the weld point is not effective an application
     * requests the effectivity condition for the weld point using operation <code>getEffectivityConditions</code>.
     * </li>
     * <li type="disc">Depending on the number of control elements associated with this
     * weld point the effectivity condition formula in the response might be difficult to
     * comprehend. Therefore the application requests a conversion into an effectivity expression
     * using operation <code>getEffectivityExpressions</code>.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * getEffectivityConditions, setEffectivityConditions
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Configuration Management - Capability to configure structured data based on revsion
     * rules; effectivities; Status etc.
     *
     * @param formulae
     *        Vector of effectivity formulae in a configurator specific encoding.
     *
     * @param productName
     *        Specifies a product. A (<code>productName,productNamespace</code>) tuple is used
     *        as a parameter in configurator service calls so to allow the configurator to resolve
     *        any ambiguity in effectivity condition parameters. Applications using this <code>EffectivityManagement</code>
     *        service should define a mechanism to obtain an appropriate value for this parameter.
     *        For example, <code>ApplicationModel</code> objects like Collaborative Design models
     *        (<b>Cpd0CollaborativeDesign</b>) make them available via properties <code>mdl0config_product_name</code>,
     *        and <code>mdl0config_prod_namespace.</code>
     *
     * @param productNameSpace
     *        Specifies a namespace in which parameter <code>productName</code> has a unique definition,
     *        e.g. a specific model year, or product type. A (<code>productName,productNamespace</code>)
     *        tuple is used as a parameter in configurator service calls so to allow the configurator
     *        to resolve any ambiguity in effectivity condition parameters. Applications using
     *        this <code>EffectivityManagement</code> service should define a mechanism to obtain
     *        an appropriate value for this parameter. For example, <code>ApplicationModel</code>
     *        objects like Collaborative Design models (<b>Cpd0CollaborativeDesign</b>) make them
     *        available via properties <code>mdl0config_product_name</code>, and <code>mdl0config_prod_namespace.</code>
     *
     * @param configuratorURL
     *        URL for the Effectivity Configurator service endpoint to connect to.
     *
     * @return
     *         Effectivity expressions that correspond to the effectivity formulae in the input.
     *         <b>ConfigurationFamily</b> objects referenced from the response structure are added
     *         to the <code>ServiceData</code> as reference objects via <code>ServiceData::addObject().</code>
     *         Partial errors may be returned in <code>ServiceData</code>, e.g. if the service fails
     *         to connect to the configurator, or if an error was returned from the configurator.
     *
     */
    virtual Fnd0::Services::Configfiltercriteria::_2011_06::Effectivitymanagement::EffectivityExpressionsResponse getEffectivityExpressions ( const std::vector< Fnd0::Services::Configfiltercriteria::_2011_06::Effectivitymanagement::ConfigFormula >& formulae,
        const std::string&  productName,
        const std::string&  productNameSpace,
        const std::string&  configuratorURL ) = 0;

    /**
     * This operation returns effectivity table representations in form of rows consisting
     * of
     * <br>
     * (<i>effect in,effect out</i>) tuples for a given set of effectivity condition formulae.
     * This operation connects to the effectivity configurator service whose service endpoint
     * is specified by the configuratorURL parameter. Any conversion from formula strings
     * is performed by this configurator service. Depending on the (configurator specific)
     * encoding the operation might require the specification of a product context using
     * parameters productName and productNameSpace. For example, a given configurator might
     * recognize shorthand representations for formulae if these are unique in the context
     * of the specified product. Teamcenter 9 only supports local built in Teamcenter configurators
     * where parameter configuratorURL can be set to an empty string. Teamcenter configurators
     * dont require a product context if the formulae are in <b>Explicit Teamcenter Language</b>.
     * The encoding is explicit if all lexemes are uniquely identified, e.g. <i>[OptionNamespace]FamilyName
     * = UniqueValue</i>, where no product context is required to determine the family name
     * for a value, or the option namespace for the family. A variant formula is in <b>Explicit
     * Teamcenter Language</b> if its form is explicit and comprised of the lexemes documented
     * for the Teamcenter <b>Variant Formula</b> property. Teamcenter configurators support
     * shorthand encodings like <i>FamilyName = UniqueValue</i> or <i>UniqueValue</i>  if
     * the lexemes used in the shorthand encoding are unique in the specified product context.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Obtain an effectivity table (<b>EffectivityTable</b>) for a formula string representation
     * (<b>ConfigFormula</b>) in the context of a Collaborative Design model (<b>Cpd0CollaborativeDesign</b>).
     * <br>
     * Some effectivity SOA operations, e.g. <code>getEffectivityConditions</code>, return
     * formula string representations, which might be easier to review if presented in a
     * table of rows consisting of (<i>effect in,effect ou</i>t) tuples.
     * <br>
     * <ul>
     * <li type="disc">Two weld points (<b>Cpd0DesignFeature</b>) exists, each in the context
     * of multiple different Design Control Elements (<b>Cpd0DesignControlElement</b>).
     * </li>
     * <li type="disc">The effectivity range for each weld point is therefore equivalent
     * to the intersection between their own effectivity range and the combined range of
     * effectivity for their respective set of Design Control Elements (DCE).
     * </li>
     * <li type="disc">In order to compare the effectivity ranges for the 2 weld points
     * an application requests the effectivity condition for each weld point using operation
     * <code>getEffectivityConditions</code>.
     * </li>
     * <li type="disc">Depending on the number of control elements associated with each
     * weld point the effectivity condition formula in the response can be different even
     * if their ranges are logically equivalent. Therefore the application requests a conversion
     * to effectivity tables using operation <code>getEffectivityTables</code> so that the
     * two effectivity ranges can be compared.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * getEffectivityConditions
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Configuration Management - Capability to configure structured data based on revsion
     * rules; effectivities; Status etc.
     *
     * @param formulae
     *        Vector of effectivity formulae in a configurator specific encoding.
     *
     * @param productName
     *        Specifies a product. A (<code>productName,productNamespace</code>) tuple is used
     *        as a parameter in configurator service calls so to allow the configurator to resolve
     *        any ambiguity in effectivity condition parameters. Applications using this <code>EffectivityManagement</code>
     *        service should define a mechanism to obtain an appropriate value for this parameter.
     *        For example, <code>ApplicationModel</code> objects like Collaborative Design models
     *        (<b>Cpd0CollaborativeDesign</b>) make them available via properties <code>mdl0config_product_name</code>,
     *        and <code>mdl0config_prod_namespace.</code>
     *
     * @param productNameSpace
     *        Specifies a namespace in which parameter <code>productName</code> has a unique definition,
     *        e.g. a specific model year, or product type. A (<code>productName</code><i>,</i><code>productNamespace</code>)
     *        tuple is used as a parameter in configurator service calls so to allow the configurator
     *        to resolve any ambiguity in effectivity condition parameters. Applications using
     *        this <code>EffectivityManagement</code> service should define a mechanism to obtain
     *        an appropriate value for this parameter. For example, <code>ApplicationModel</code>
     *        objects like Collaborative Design models (<b>Cpd0CollaborativeDesign</b>) make them
     *        available via properties <code>mdl0config_product_name</code>, and<code> mdl0config_prod_namespace.</code>
     *
     * @param configuratorURL
     *        URL for the Effectivity Configurator service endpoint to connect to.
     *
     * @return
     *         A set of effectivity tables representing the input effectivity formulae, e.g.<i>
     *         unit in=1</i>, <i>unit out=11</i> for <code>[Teamcenter::]Unit >= 1 & [Teamcenter::]Unit
     *         < 11</code>. Partial errors may be returned in <code>ServiceData</code>, e.g. if
     *         the service fails to connect to the configurator, or if an error was returned from
     *         the configurator.
     *
     */
    virtual Fnd0::Services::Configfiltercriteria::_2011_06::Effectivitymanagement::EffectivityTablesResponse getEffectivityTables ( const std::vector< Fnd0::Services::Configfiltercriteria::_2011_06::Effectivitymanagement::ConfigFormula >& formulae,
        const std::string&  productName,
        const std::string&  productNameSpace,
        const std::string&  configuratorURL ) = 0;

    /**
     * This operation returns the effectivity criteria associated with a set of <b>RevisionRule</b>
     * objects. If a non zero value is specified for parameters <code>substituteDependentVariables</code>,
     * <code>applyConstraints</code>, and/or <code>applyDefaults</code>, the operation will
     * connect to the effectivity configurator specified by parameter <code>configuratorURL</code>.
     * The actual evaluation of configurator rules, and conversions to and from formula
     * strings, are performed by this configurator service. The resulting formula string
     * conversions may vary depending on the choice of service endpoint. For example a given
     * configurator might return shorthand representations for formulae if these are unique
     * in the context of the specified product. Teamcenter 9 only supports local builtin
     * Teamcenter configurators where parameter <code>configuratorURL</code> can be set
     * to an empty string. Teamcenter configurators used in the EffectivityManagement service
     * interface encode configuration formulae in <b>Explicit Teamcenter Language</b> for
     * which no product context is required (see operation <code>getEffectivityExpressions</code>
     * for more details on <b>Explicit Teamcenter Language</b> and <code>productName</code>
     * and <code>productNameSpace</code>.
     * <br>
     * <br>
     * Operation <code>getRevRuleEffectivityCriteria</code> should be used if symbolic variable
     * substitution and/or constraint processing is required for *all* variant option families,
     * or if validation records are required that specify violated constraints.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Use case 1:
     * <br>
     * Initialize an effectivity criteria dialog for a given <b>RevisionRule</b>.
     * <br>
     * <ul>
     * <li type="disc">The application uses operation <code>getRevRuleEffectivityCriteria</code>
     * with <code>revisionRules={myRevRule}, productName=, productNameSpace=</code>, <code>substituteDependentVariables=0,
     * applyConstraints=0.</code>
     * </li>
     * <li type="disc">The response will contain effectivity ranges as they are stored on
     * <b>RevisionRule</b> <code>myRevRule</code>  without additional configurator processing.
     * References to effectivity configuration families (<b>ConfigurationFamily</b>) are
     * returned in <code>ServiceData</code>.
     * </li>
     * </ul>
     * <br>
     * <br>
     * Use case 2:
     * <br>
     * Initialize an effectivity criteria dialog for a product that was created using the
     * Teamcenter effectivity configurator with the intent to setup a new <b>RevisionRule</b>.
     * <br>
     * <ul>
     * <li type="disc">The application uses operation <code>getRevRuleEffectivityCriteria</code>
     * with <code>productName=MyProductItemID, productNameSpace=MyProductRevID, substituteDependentVariables=0,
     * applyConstraints=0.</code>
     * </li>
     * <li type="disc">The response will contain all nominal effectivity ranges in this
     * product. No constraint processing is required. References to effectivity configuration
     * families (<b>ConfigurationFamily</b>) are returned in <code>ServiceData</code>.
     * </li>
     * </ul>
     * <br>
     * <br>
     * Use case 3:
     * <br>
     * Initialize an effectivity criteria dialog for a product that is associated with a
     * Collaborative Design (CD) model with the intent to setup a new <b>RevisionRule</b>.
     * <br>
     * <ul>
     * <li type="disc">Identifiers for the product associated with the CD (<b>Cpd0CollaborativeDesign</b>)
     * are obtained from CD  properties <code>mdl0config_product_name</code>, and <code>mdl0config_prod_namespace</code>.
     * </li>
     * <li type="disc">The application uses operation <code>getRevRuleEffectivityCriteria</code>
     * with <code>productName= , productNameSpace=  as obtained in the previous step, substituteDependentVariables=0,
     * applyConstraints=0.</code>
     * </li>
     * <li type="disc">The response will contain all nominal effectivity ranges in this
     * product. No constraint processing is required. References to effectivity configuration
     * families (<b>ConfigurationFamily</b>) are returned in <code>ServiceData</code>.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * findWorkspaceObjects
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Configuration Management - Capability to configure structured data based on revsion
     * rules; effectivities; Status etc.
     *
     * @param revisionRules
     *        A vector of <b>RevisionRule</b> objects for which effectivity criteria are requested.
     *
     * @param substituteDependentVariables
     *        Indicates whether or not to substitute dependent variables, such as <code>PlantVacationShutdown</code>.
     *        Value <i>0</i> will indicate no substitution is required. A value of <i>1</i> will
     *        enable substitution of dependent variables
     *
     * @param applyConstraints
     *        Indicates whether or not to apply the constraints. Value <i>0</i> will indicate constraint
     *        application is not required. A value of <i>1</i> will enable application of constraints.
     *
     * @param applyDefaults
     *        Indicates whether or not to apply defaults. Value <i>0</i> will indicate that defaults
     *        should not be applied. A value of <i>1</i> will enable application of defaults.
     *
     * @param productName
     *        Specifies a product. A (<code>productName,productNamespace</code>) tuple is used
     *        as a parameter in configurator service calls so to allow the configurator to resolve
     *        any ambiguity in effectivity condition parameters. Applications using this <code>EffectivityManagement</code>
     *        service should define a mechanism to obtain an appropriate value for this parameter.
     *        For example, <code>ApplicationModel</code> objects like Collaborative Design models
     *        (<b>Cpd0CollaborativeDesign</b>) make them available via properties <code>mdl0config_product_name</code>,
     *        and <code>mdl0config_prod_namespace.</code>
     *
     * @param productNameSpace
     *        Specifies a namespace in which parameter <code>productName</code> has a unique definition,
     *        e.g. a specific model year, or product type. A (<code>productName,productNamespace</code>)
     *        tuple is used as a parameter in configurator service calls so to allow the configurator
     *        to resolve any ambiguity in effectivity condition parameters. Applications using
     *        this <code>EffectivityManagement</code> service should define a mechanism to obtain
     *        an appropriate value for this parameter. For example, <code>ApplicationModel</code>
     *        objects like Collaborative Design models (<b>Cpd0CollaborativeDesign</b>) make them
     *        available via properties <code>mdl0config_product_name</code>, and <code>mdl0config_prod_namespace.</code>
     *
     * @param configuratorURL
     *        URL for the Effectivity Configurator service endpoint to connect to.
     *
     * @return
     *         <ul>
     *         <li type="disc">Returns the effectivity criteria associated with the given set of
     *         <b>RevisionRule</b> objects. Dynamic validation results will be requested from the
     *         effectivity configurator service identified by parameter <code>configuratorURL</code>
     *         if parameters <code>productName</code> and <code>productNameSpace</code> identify
     *         a product context and a non zero value was specified for the <code>applyDefaults</code>
     *         parameter. If <code>substituteDependentVariables</code> and/or <code>applyConstraints</code>
     *         were specified without enabling <code>applyDefaults</code> the validation results
     *         will only reflect configurator constraints and substitutions without completeness
     *         and validity checking. A NULL date will be returned in the validationDate field of
     *         the validation record in that case. Otherwise pre computed validation results will
     *         be returned for the product identified by parameters <code>productName</code> and
     *         <code>productNameSpace</code>. <b>ConfigurationFamily</b> objects referenced from
     *         the response structure are added to the <code>ServiceData</code> as reference objects
     *         via <code>ServiceData::addObject()</code>. Partial errors may be returned in <code>ServiceData</code>,
     *         e.g. if the service fails to connect to the configurator, or if an error was returned
     *         from the configurator.
     *         </li>
     *         </ul>
     *
     */
    virtual Fnd0::Services::Configfiltercriteria::_2011_06::Effectivitymanagement::RevRuleEffectivityCriteriaResponse getRevRuleEffectivityCriteria ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::RevisionRule>  >& revisionRules,
        int substituteDependentVariables,
        int applyConstraints,
        int applyDefaults,
        const std::string&  productName,
        const std::string&  productNameSpace,
        const std::string&  configuratorURL ) = 0;

    /**
     * This operation applies the specified effectivity condition to all objects listed
     * in <code>affectedObjects</code> and their sub objects (where applicable) in the context
     * of the given (<code>productName,productNameSpace)</code> combination.
     * <br>
     * The operation returns formulae for created/modified effectivity conditions in a configurator
     * specific encoding along with a reference to the modified objects. This operation
     * connects to the effectivity configurator service whose service endpoint is specified
     * by the <code>configuratorURL</code> parameter. The actual conversion to and from
     * formula strings is performed by this configurator service. The result may vary depending
     * on the choice of service endpoint. For example a given configurator might return
     * shorthand representations for formulae if these are unique in the context of the
     * specified product. Teamcenter 9 only supports local built in Teamcenter configurators
     * where parameter <code>configuratorURL</code> can be set to an empty string. Teamcenter
     * configurators used in the <code>EffectivityManagement</code> service interface encode
     * configuration formulae in <b>Explicit Teamcenter Language</b> for which no product
     * context is required (see operation <code>getEffectivityExpressions</code> for more
     * details on <b>Explicit Teamcenter Language</b>  and <code>productName and productNameSpace</code>).
     * <br>
     * <br>
     * If the effectivity condition are propagated to sub elements (e.g. sub ordinate elements
     * associated with a DesignElement of category Reuse, or design features such as weld
     * points associated with a Design Control Element), then these sub elements are returned
     * as modified objects in the <code>ServiceData</code>.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Use case 1:
     * <br>
     * Assign an effectivity condition to a design feature (<b>Cpd0DesignFeature</b>) in
     * a Collaborative Design model (<b>Cpd0CollaborativeDesign</b>).
     * <br>
     * <ul>
     * <li type="disc">Two alternative weld points exist in the context of a common Design
     * Control Element (DCE).
     * </li>
     * <li type="disc">Effectivity <i>Unit=1..9</i> is assigned to the first weld point
     * using operation <code>setEffectivityConditions</code>.
     * </li>
     * <li type="disc">Effectivity <i>Unit=10..UP</i>  is assigned to the second weld point
     * using the same service operation.
     * </li>
     * <li type="disc">Then effectivity <i>Unit=5..15</i> is assigned to the DCE (<b>Cpd0DesignControlElement</b>),
     * which reduces the effectivity range of all elements controlled by this DCE. The result
     * is that the first weld point is effective for <i>Unit=5..9</i>, while the second
     * is effective <i>Unit=10..15.</i>
     * </li>
     * <li type="disc">Finally a NULL effectivity range is assigned to the DCE, which removes
     * the effectivity condition from the DCE, and extends the effectivity range of all
     * elements controlled by this DCE to their original values. The result is that the
     * first weld point is again effective for <i>Unit=1..9</i>, while the second is effective
     * <i>Unit=10..UP.</i>
     * </li>
     * </ul>
     * <br>
     * <br>
     * Use case 2:
     * <br>
     * Assign an effectivity condition to a Design Element (DE) such that its effectivity
     * range covers the combined range of effectivity of multiple other DEs in a Collaborative
     * Design (CD) model.
     * <br>
     * <ul>
     * <li type="disc">Multiple alternative radar systems and radar screens exist in a CD
     * (<b>Cpd0CollaborativeDesign</b>). Radar system R1 is effective for <i>Unit=1..10</i>,
     * while radar system <i>R2</i> is effective for <i>Unit=11..UP</i>. Radar display unit
     * <i>D1</i> is effective for <i>Unit=1..5</i>, while radar display unit <i>D2</i> is
     * effective for<i> Unit=6..UP</i>. I.e. every product unit has exactly one radar system
     * and one radar screen, but the combination of radar systems and screens varies for
     * different product units.
     * </li>
     * <li type="disc">The same radar cable <i>C1</i> connects all radar units with their
     * display screens. <i>C1</i> is effective for <i>Unit=1..UP.</i>
     * </li>
     * <li type="disc">Effective <i>Unit=3..UP</i> a new radar cable <i>C2</i> shall replace
     * <i>C1</i> such that it covers the combined effectivity range for <i>R1, R2, D1,</i>
     * and <i>D2</i>.
     * </li>
     * <li type="disc">To achieve this goal, operation setEffectivityConditions is used
     * to assign the combined effectivity range of <i>R1, R2, D1</i>, and <i>D2</i>, to
     * the new radar cable <i>C2</i> with <i>affectedObjects={C2}</i>, s<i>ampleObjects={R1,
     * R2, D1, D2</i>}, <i>opCode=11 (OR)</i>, and <i>actionCode=1 (OVERWRITE)</i>.<i> C2s
     * </i>effectivity range is now <i>Unit=1..UP</i>, while its effectivity configuration
     * formula is<i> Unit=1..10 or Unit=11..UP or Unit=1..5 or Unit=6..UP.</i>
     * </li>
     * <li type="disc">C2s design is completed and reviewed in this state.
     * </li>
     * <li type="disc">Finally operation <code>setEffectivityConditions</code> is used with
     * a<i>ffectedObjects={C2}, replacedObjects={C1}</i>, <i>formulae={Unit>=3}</i>, <i>opCode=11</i>
     * (OR), and<i> actionCode=4 (REDUCE)</i>. <i>C2s</i> effectivity range is now <i>Unit=3..UP</i>,
     * while <i>C1s</i> effectivity range is now <i>Unit=1..2.</i>
     * </li>
     * </ul>
     * <br>
     * <br>
     * Use case 3:
     * <br>
     * Extend the effectivity range for a set of Design Elements (DE) such that their effectivity
     * range also covers the combined effectivity configuration criteria attached to two
     * <b>RevisionRules</b>.
     * <br>
     * <ul>
     * <li type="disc">Multiple alternative radar systems and radar screens exist in a CD
     * (<b>Cpd0CollaborativeDesign</b>). Radar system R1 is effective for <i>Unit={1, 3}</i>,
     * while radar system <i>R2</i> is effective for<i> Unit={2, 4}</i>. Radar display unit
     * <i>D1</i> is effective for<i> Unit={1, 2}</i>, while radar display unit <i>D2</i>
     * is effective for<i> Unit={3, 4}</i>. I.e. all product <i>units 1..4</i> have exactly
     * one radar system and one radar screen, but the combination of radar systems and screens
     * varies for different product units.
     * </li>
     * <li type="disc">Field tests have shown that the combination between <i>R1</i> and
     * <i>D2</i> is best. Therefore this combination shall be made effective for the upcoming
     * new product units 5 and 6, represented by <b>RevisionRules</b> <i>Rule1:Unit=5 and
     * Rule2:Unit=6.</i>
     * </li>
     * <li type="disc">To achieve this goal, operation <i>setEffectivityConditions</i> is
     * used to assign the combined effectivity configuration criteria associated to <i>Rule1</i>
     * and <i>Rule2</i>, to <i>affectedObjects={R1,D2}</i> by using <i>sampleObjects={Rule1,
     * Rule2 },</i> <i>opCode=11 (OR),</i> and <i>actionCode=2 (EXTEND)</i>. The result
     * is that <i>R1s</i> effectivity range is now <i>Unit={1, 3, 5, 6}</i>, while <i>D2s</i>
     * effectivity range is now <i>Unit={3, 4, 5, 6}.</i>
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * setEffectivityConditions
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Configuration Management - Capability to configure structured data based on revsion
     * rules; effectivities; Status etc.
     *
     * @param sampleObjects
     *        Effectivity conditions on objects in this list are combined with <code>opCode</code>
     *        to form the effectivity condition to be set on <code>affectedObjects</code>. These
     *        may also include <b>RevisionRule</b> objects. Can be empty.
     *
     * @param formulae
     *        Configuration formulae in this list are combined with <i>opCode</i> to form the effectivity
     *        condition to be set on <code>affectedObjects</code>. Can be empty.
     *
     * @param expressions
     *        Configuration expressions in this list are combined with <code>opCode</code> to form
     *        the effectivity condition to be set on <code>affectedObjects</code>. Can be empty.
     *
     * @param opCode
     *        Specifies how to combine the inputs given in <i>sampleObjects</i>, <i>formulae</i>,
     *        and <i>expression</i>, e.g. 10 for <i>AND</i>, or <i>11</i> for <i>OR</i>. See<i>
     *        </i><code>$TC_INCLUDE/ps/ps_tokens.h.</code>
     *
     * @param actionCode
     *        Represents the type of action to be performed with the new effectivity condition
     *        when applying it to <code>affectedObjects</code>. Valid values are
     *        <br>
     *        <ul>
     *        <li type="disc">1 : Overwrite   SET
     *        </li>
     *        <li type="disc">2 : Extend&nbsp;&nbsp;&nbsp;&nbsp;  OR
     *        </li>
     *        <li type="disc">4 : Reduce&nbsp;&nbsp;&nbsp;&nbsp; AND
     *        </li>
     *        </ul>
     *
     * @param affectedObjects
     *        Lists objects to which the new effectivity condition sill be assigned.
     *
     * @param replacedObjects
     *        Lists objects that will be replaced by corresponding elements in <code>affectedObjects</code>
     *        vector where <code>affectedObjects[index] </code>replaces <code>replacedObjects[index]
     *        </code>if and only if <code>replacedObjects[index] </code>is not a <i>NULL</i> object,
     *        and <i>index</i> <code>replacedObjects.length().</code> In this context replacing
     *        one object with another means that the effectivity range of the replaced object will
     *        be reduced to no longer overlap with the effectivity of the replacing object.
     *
     * @param productName
     *        Specifies a product. A (<code>productName,productNamespace</code>) tuple is used
     *        as a parameter in configurator service calls so to allow the configurator to resolve
     *        any ambiguity in effectivity condition parameters. Applications using this <code>EffectivityManagement</code>
     *        service should define a mechanism to obtain an appropriate value for this parameter.
     *        For example, <code>ApplicationModel</code> objects like Collaborative Design models
     *        (<b>Cpd0CollaborativeDesign</b>) make them available via properties <code>mdl0config_product_name</code>,
     *        and <code>mdl0config_prod_namespace.</code>
     *
     * @param productNameSpace
     *        Specifies a namespace in which parameter <code>productName</code> has a unique definition,
     *        e.g. a specific model year, or product type. A (<code>productName,productNamespace</code>)
     *        tuple is used as a parameter in configurator service calls so to allow the configurator
     *        to resolve any ambiguity in effectivity condition parameters. Applications using
     *        this <code>EffectivityManagement</code> service should define a mechanism to obtain
     *        an appropriate value for this parameter. For example, <code>ApplicationModel</code>
     *        objects like Collaborative Design models (<b>Cpd0CollaborativeDesign</b>) make them
     *        available via properties <code>mdl0config_product_name</code>, and <code>mdl0config_prod_namespace.</code>
     *
     * @param configuratorURL
     *        URL for the Effectivity Configurator service endpoint to connect to.
     *
     * @return
     *         The configuration formulae for created/modified effectivity conditions along with
     *         a reference to the modified objects. If effectivity condition were propagated to
     *         sub elements, they returned as modified objects in <code>ServiceData</code>. If the
     *         effectivity conditions of replaced objects were modified they returned as modified
     *         objects in <code>ServiceData</code>. Partial errors may be returned in <code>ServiceData</code>,
     *         e.g. if the service fails to connect to the configurator, or if an error was returned
     *         from the configurator.
     *
     */
    virtual Fnd0::Services::Configfiltercriteria::_2011_06::Effectivitymanagement::EffectivityConditionResponse setEffectivityConditions ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::POM_object>  >& sampleObjects,
        const std::vector< Fnd0::Services::Configfiltercriteria::_2011_06::Effectivitymanagement::ConfigFormula >& formulae,
        const std::vector< Fnd0::Services::Configfiltercriteria::_2011_06::Effectivitymanagement::ConfigExpression >& expressions,
        int opCode,
        int actionCode,
        const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::POM_object>  >& affectedObjects,
        const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::POM_object>  >& replacedObjects,
        const std::string&  productName,
        const std::string&  productNameSpace,
        const std::string&  configuratorURL ) = 0;

    /**
     * This operation assigns the specified effectivity criteria to the revision rules listed
     * in <code>affectedRevRules</code>. If a (<code>productName</code>,<code>productNameSpace</code>)
     * combination is specified, then existing validation records associated with this product
     * will be added to the response. If a non zero value is specified for parameters <code>substituteDependentVariables</code>,
     * <code>applyConstraints</code>, and/or <code>applyDefaults</code>, then corresponding
     * effectivity configurator rules will be applied to the effectivity criteria and the
     * corresponding validation records will be returned in the response structure. Runtime
     * copies of the <b>RevisionRules</b> listed in <code>affectedRevRules</code> are created
     * with the requested effectivity configuration criteria if parameter <code>createPrivateCopy</code>
     * is set to true. In that case the response structure will reference the new runtime
     * copies. Otherwise WRITE or REVISE privileges for <code>affectedRevRules</code> are
     * required. If parameter saveNow is set to true and <code>createPrivateCopy</code>
     * is set to false, then <b>RevisionRule</b> modifications are saved. Otherwise, <code>affectedRevRules</code>
     * are updated, but not saved.
     * <br>
     * <br>
     * This operation connects to the effectivity configurator service whose service endpoint
     * is specified by the configuratorURL parameter. The actual conversion to and from
     * formula strings is performed by this configurator service. The result may vary depending
     * on the choice of service endpoint. For example a given configurator might return
     * shorthand representations for formulae if these are unique in the context of the
     * specified product. Teamcenter 9 only supports local built in Teamcenter configurators
     * where parameter <i>configuratorURL</i> can be set to an empty string. Teamcenter
     * configurators used in the EffectivityManagement service interface encode configuration
     * formulae in Explicit Teamcenter Language for which no product context is required
     * (see operation <code>getEffectivityExpressions</code> for more details on <b>Explicit
     * Teamcenter Language </b> and <code>productName</code> and <code>productNameSpace</code>).
     * <br>
     * <br>
     * Parameter <i>solveType</i> can be used to specify a filter strategy when evalutating
     * the effectivity configuration criteria. This parameter is used to combine one or
     * more of the following with binary OR:
     * <br>
     * <br>
     * <ul>
     * <li type="disc">MISMATCH&nbsp;&nbsp;&nbsp;&nbsp;                1: objects conflicting
     * with the solve criteria
     * </li>
     * <li type="disc">EXPLICIT&nbsp;&nbsp;&nbsp;&nbsp;                    2: objects explicitly
     * satisfying the solve criteria
     * </li>
     * <li type="disc">COPRIME&nbsp;&nbsp;&nbsp;&nbsp;                    4: objects potentially
     * satisfying the solve criteria
     * </li>
     * <li type="disc">TRUE&nbsp;&nbsp;&nbsp;&nbsp;                        8: objects having
     * an effectivity condition = TRUE
     * </li>
     * <li type="disc">FALSE&nbsp;&nbsp;&nbsp;&nbsp;                        16: objects
     * having an effectivity condition = FALSE
     * </li>
     * <li type="disc">CONDITION&nbsp;&nbsp;&nbsp;&nbsp;                32: objects having
     * a non constant effectivity condition
     * </li>
     * <li type="disc">ERROR_CHECK&nbsp;&nbsp;&nbsp;&nbsp;            64: objects having
     * effectivity conditions returning an error
     * </li>
     * <li type="disc">NO_CONDITION&nbsp;&nbsp;&nbsp;&nbsp;        128: objects with configurable
     * behavior without a condition
     * </li>
     * <li type="disc">NO_CONFIG_BEHAVIOR&nbsp;&nbsp;&nbsp;&nbsp;256: objects without configurable
     * behavior
     * </li>
     * <li type="disc">INVERT&nbsp;&nbsp;&nbsp;&nbsp;                    512: inverts the
     * filter results
     * </li>
     * </ul>
     * <br>
     * <br>
     * For example a <i>solveType</i> value of 398=256+128+8+4+2 produces the same filter
     * results as 529= 512+16+1, but is more efficient if most objects are expected to fail
     * the filter. On the other hand if most objects are expected to pass the filter than
     * 529 is more efficient. If in doubt a value of 529 is recommended in most cases.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Setup a <b>RevisionRule</b> to define effectivity configuration criteria that cover
     * the combined effectivity ranges of a set of Design Elements (DE) in a Collaborative
     * Design (CD) model.
     * <br>
     * <br>
     * <ul>
     * <li type="disc">Multiple alternative radar systems and radar screens exist in a CD
     * (<b>Cpd0CollaborativeDesign</b>). Radar system R1 is effective for Unit={1, 3}, while
     * radar system R2 is effective for Unit={2, 4}. Radar display unit D1 is effective
     * for Unit={1, 2}, while radar display unit D2 is effective for Unit={3, 4}.
     * </li>
     * <li type="disc">A radar cable C1 shall be added to the CD suitable to connect any
     * radar system with any radar screen. To find DEs that can exist together with any
     * radar system and screen a RevisionRule shall be defined that covers their combined
     * effectivity range.
     * </li>
     * <li type="disc">To achieve this goal, operation setRevRuleEffectivityCriteria is
     * used to assign the combined effectivity range for R1, R2, D1, and D2, to a transient
     * RevisionRule copy of the system RevisionRule Rule1 Working; Any Status.
     * </li>
     * <li type="disc">affectedRevRules={Rule1}
     * </li>
     * <li type="disc">sampleObjects={R1, R2, D1, D2}
     * </li>
     * <li type="disc">opCode=11 (OR)
     * </li>
     * <li type="disc">actionCode=1 (SET)
     * </li>
     * <li type="disc">substituteDependentVariables=0 (DISABLE)
     * </li>
     * <li type="disc">applyConstraints=1 (ENABLE)
     * </li>
     * <li type="disc">applyDefault=0 (DISABE)
     * </li>
     * <li type="disc">solveType=529 (MISMATCH|FALSE|INVERT)
     * </li>
     * <li type="disc">saveNow=false
     * </li>
     * <li type="disc">createPrivateCopy=true
     * </li>
     * <li type="disc">The result is that a new transient RevisionRule Rule1 is created
     * with effectivity configuration criteria Unit=1..4.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * setEffectivityConditions
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Configuration Management - Capability to configure structured data based on revsion
     * rules; effectivities; Status etc.
     *
     * @param sampleObjects
     *        Effectivity conditions on objects in this list are combined with <code>opCode</code>
     *        to form the effectivity condition to be set on <code>affectedObjects</code>. These
     *        may also include <b>RevisionRule</b> objects. Can be empty.
     *
     * @param formulae
     *        Configuration formulae in this list are combined with <code>opCode</code> to form
     *        the effectivity condition to be set on <code>affectedObjects</code>. Can be empty.
     *
     * @param expressions
     *        Configuration expressions in this list are combined with opCode to form the effectivity
     *        condition to be set on <code>affectedObjects</code>. Can be empty.
     *
     * @param opCode
     *        Specifies how to combine the inputs given in <i>sampleObjects</i>, <i>formulae</i>,
     *        and <i>expression</i>, e.g. 10 for <i>AND, </i>or<i> 11 for OR. </i>See<i> $TC_INCLUDE/ps/ps_tokens.h.</i>
     *
     * @param substituteDependentVariables
     *        Indicates whether or not to substitute dependent variables, such as <code>PlantVacationShutdown</code>.
     *        Value 0 will indicate no substitution is required. A value of 1 will enable substitution
     *        of dependent variables. If this feature is not supported by the selected configurator
     *        the value is ignored.
     *
     * @param applyConstraints
     *        Indicates whether or not to apply the constraints. Value 0 will indicate constraint
     *        application is not required. A value of 1 will enable application of constraints.
     *
     * @param applyDefault
     *        Indicates whether or not to apply defaults. Value "0" will indicate that defaults
     *        should not be applied. A value of "1" will enable application of defaults.
     *
     * @param actionCode
     *        Represents the type of action to be performed with the new effectivity criteria are
     *        applied to <code>affectedRevRules</code>. Valid values are
     *        <br>
     *        <ul>
     *        <li type="disc">1 : Overwrite  SET
     *        </li>
     *        <li type="disc">2 : Extend      OR
     *        </li>
     *        <li type="disc">4 : Reduce     AND
     *        </li>
     *        </ul>
     *
     * @param solveType
     *        Indicates the type of solve that shall be performed when using the effectivity criteria
     *        in configuration filters. Valid values are binary OR combinations of one or more
     *        of the following values:
     *        <br>
     *        <ul>
     *        <li type="disc">1 : MISMATCH
     *        </li>
     *        <li type="disc">2 : EXPLICIT
     *        </li>
     *        <li type="disc">4 : COPRIME
     *        </li>
     *        <li type="disc">8 : TRUE
     *        </li>
     *        <li type="disc">16 : FALSE
     *        </li>
     *        <li type="disc">32 : CONDITION
     *        </li>
     *        <li type="disc">64 : ERROR_CHECK
     *        </li>
     *        <li type="disc">128 : NO_CONDITION
     *        </li>
     *        <li type="disc">256 : NO_CONFIG_BEHAVIOR
     *        </li>
     *        <li type="disc">512 : INVERT
     *        </li>
     *        </ul>
     *
     * @param saveNow
     *        Indicates whether the input revision rules should be saved in database. A true value
     *        for this parameter takes effect only if <code>createPrivateCopy</code> parameter
     *        is set to false.
     *
     * @param createPrivateCopy
     *        Indicates whether runtime private copies of the revision rules need to be created
     *        based on given revision rules and effectivity criteria.
     *
     * @param affectedRevRules
     *        Lists Revision Rules to which the new effectivity criteria will be assigned.
     *
     * @param productName
     *        Specifies a product. A (<code>productName</code>,<code>productNamespace</code>) tuple
     *        is used as a parameter in configurator service calls so to allow the configurator
     *        to resolve any ambiguity in effectivity condition parameters. Applications using
     *        this <code>EffectivityManagement</code> service should define a mechanism to obtain
     *        an appropriate value for this parameter. For example, <code>ApplicationModel</code>
     *        objects like Collaborative Design models (<b>Cpd0CollaborativeDesign</b>) make them
     *        available via properties <code>mdl0config_product_name</code>, and <code>mdl0config_prod_namespace</code>.
     *
     * @param productNameSpace
     *        Specifies a namespace in which parameter <code>productName</code> has a unique definition,
     *        e.g. a specific model year, or product type. A (<code>productName</code>,<code>productNamespace</code>)
     *        tuple is used as a parameter in configurator service calls so to allow the configurator
     *        to resolve any ambiguity in effectivity condition parameters. Applications using
     *        this <i>EffectivityManagement</i> service should define a mechanism to obtain an
     *        appropriate value for this parameter. For example, <code>ApplicationModel</code>
     *        objects like Collaborative Design models (<b>Cpd0CollaborativeDesign</b>) make them
     *        available via properties <code>mdl0config_product_name</code>, and <code>mdl0config_prod_namespace</code>.
     *
     * @param configuratorURL
     *        URL for the Effectivity Configurator service endpoint to connect to.
     *
     * @return
     *         The new effectivity criteria along with the new or modified <b>RevisionRules</b>.
     *         If a (<code>productName</code>,<code>productNameSpace</code>) combination was specified,
     *         then existing validation records associated with this product will be in the response.
     *         If a nonzero value was specified for parameters <code>substituteDependentVariables</code>,
     *         <code>applyConstraints</code>, and/or <code>applyDefaults</code>, then corresponding
     *         effectivity configurator rules will be applied to the effectivity criteria and the
     *         corresponding validation records will be in the response. Runtime copies of the RevisionRules
     *         listed in <code>affectedRevRules</code> are created with the requested effectivity
     *         configuration criteria if parameter <code>createPrivateCopy</code> was set to <i>true</i>.
     *         In that case the response will reference the new runtime copies. If parameter saveNow
     *         was set to <i>true</i> and <code>createPrivateCopy</code> was set to <i>false</i>,
     *         then RevisionRule modifications are saved. Otherwise, <code>affectedRevRules</code>
     *         are updated, but not saved. Changed <b>RevisionRule</b> objects are added to ServiceData
     *         as updated objects via<code> ServiceData::addUpdatedObject(). </code>ConfigurationFamily
     *         objects referenced from the response structure are added to <code>ServiceData</code>
     *         as reference objects via <code>ServiceData::addObject()</code>.Partial errors may
     *         be returned in <code>ServiceData</code>, e.g. if the service fails to connect to
     *         the configurator, or if an error was returned from the configurator.
     *
     */
    virtual Fnd0::Services::Configfiltercriteria::_2011_06::Effectivitymanagement::RevRuleEffectivityCriteriaResponse setRevRuleEffectivityCriteria ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::POM_object>  >& sampleObjects,
        const std::vector< Fnd0::Services::Configfiltercriteria::_2011_06::Effectivitymanagement::ConfigFormula >& formulae,
        const std::vector< Fnd0::Services::Configfiltercriteria::_2011_06::Effectivitymanagement::ConfigExpression >& expressions,
        int opCode,
        int substituteDependentVariables,
        int applyConstraints,
        int applyDefault,
        int actionCode,
        int solveType,
        bool saveNow,
        bool createPrivateCopy,
        const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::RevisionRule>  >& affectedRevRules,
        const std::string&  productName,
        const std::string&  productNameSpace,
        const std::string&  configuratorURL ) = 0;


protected:
    virtual ~Effectivitymanagement() {}
};
            }
        }
    }
}

#include <fnd0/services/configfiltercriteria/ConfigFilterCriteria_undef.h>
#endif

