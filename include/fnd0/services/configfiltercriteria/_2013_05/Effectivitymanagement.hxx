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

#ifndef FND0_SERVICES_CONFIGFILTERCRITERIA__2013_05_EFFECTIVITYMANAGEMENT_HXX
#define FND0_SERVICES_CONFIGFILTERCRITERIA__2013_05_EFFECTIVITYMANAGEMENT_HXX

#include <fnd0/services/configfiltercriteria/_2011_06/Effectivitymanagement.hxx>


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
                class Effectivitymanagement;

class FND0SOACONFIGFILTERCRITERIASTRONGMNGD_API Effectivitymanagement
{
public:

    struct EffectivityDisplayStringResponse;
    struct EffectivityOverlapStateResponse;
    struct OverlapStateList;

    /**
     * Operlap states enumerations.
     */
    enum OverlapState{ OverlapStateNone,
                 OverlapStateSubset,
                 OverlapStateMatch,
                 OverlapStateSuperset,
                 OverlapStateIntersect
                 };

    /**
     * A list of localized string representations for effectivity expressions. The format
     * is a pure output format intended to increase ease of reading. It cannot be used as
     * input because its format allows ambiguous syntax.
     */
    struct EffectivityDisplayStringResponse
    {
        /**
         * Vector of effectivity display strings. This format is the same as for effectivity
         * formula properties <b>mdl0effectivity_formula</b> and <b>mdl0allowed_eff_formula.</b>
         */
        std::vector< std::string > displayString;
        /**
         * Teamcenter service data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Indicates the degreee of overlap for pairs of effectivity expressions.
     */
    struct EffectivityOverlapStateResponse
    {
        /**
         * A vector of overlap enumeration values.
         */
        std::vector< Fnd0::Services::Configfiltercriteria::_2013_05::Effectivitymanagement::OverlapStateList > overlapStates;
        /**
         * Teamcenter service data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * A list of indicators for the degree of overlap between two effectivity expressions.
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
         * expression's solution set has some overlap with the refernce expression's solution
         * set.
         * <br>
         * 
         */
        std::vector< OverlapState > overlapStates;
    };




    /**
     * This operation returns a localized string representation for effectivity expressions.
     * This string representation is the same that is used for display values of effectivity
     * formula properties <b>mdl0effectivity_formula</b> and <b>mdl0allowed_eff_formula</b>.
     * Applications can use this API to display effectivity conditions for objects that
     * have not yet been saved with this effectivity, e.g. if multiple effectivity modifications
     * are accumulated in a client session before they are saved. In this scenario effectivity
     * properties are not (yet) available prior to saving modified objects.
     * <br>
     * This operation connects to the effectivity configurator service whose service endpoint
     * is specified by the <code>configuratorURL</code> parameter. The actual conversion
     * to formula strings is performed by this configurator service. Depending on the (configurator
     * specific) encoding the operation might require the specification of a product context
     * using parameters <code>productName</code> and <code>productNameSpace</code>. For
     * example, a given configurator might use  shorthand representations for formulae if
     * these are unique in the context of the specified product. Teamcenter 10.1 only supports
     * local built in Teamcenter configurators where parameter <code>configuratorURL</code>
     * can be set to an empty string. Teamcenter configurators don't require a product context
     * if the formulae are in <b>Explicit Teamcenter Language</b>. The encoding is explicit
     * if all lexemes are uniquely identified, e.g. [<i>OptionNamespace</i>]<i>FamilyName</i>
     * = <i>UniqueValue</i>, where no product context is required to determine the family
     * name for a value, or the option namespace for the family. A configuration condition
     * formula is in<b> Explicit Teamcenter Language</b> if its form is explicit and comprised
     * of the lexemes documented for the Teamcenter <b>Variant Formula</b> property. Teamcenter
     * configurators support shorthand encodings like <i>FamilyName</i> = <i>UniqueValue</i>
     * or <i>UniqueValue</i> if the lexemes used in the shorthand encoding are unique in
     * the specified product context.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * An application prepares several effectivity conditions with the intent to save them
     * to a set of objects using operation <b>setEffectivityConditions</b>. The application
     * wants to display the effectivity display string that would get saved with setEffectivityConditions
     * before actually saving them.
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
     * @param expressions
     *        Configuration expressions for which the effectivity display string is requested.
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
     *        use the Revision ID of the product ItemRevision for <code>productNameSpace</code>.
     *        The productNameSpace value for a Collaborative Design (<b>Cpd0CollaborativeDesign</b>)
     *        can be obtained from property <code>Mdl0ApplicationModel::mdl0config_prod_namespace.</code>
     *
     * @param configuratorURL
     *        The service end point for the effectivity configurator service. If empty the local
     *        Teamcenter configurator is used. Tc10.1 only supports local Teamcenter configurators.
     *        In Tc10.1 a non-empty <code>configuratorURL</code> parameter will cause an error.
     *        <br>
     *        <br>
     *
     * @return
     *         Response object containing effectivity display values.
     *
     *
     * @exception ServiceException
     *           This operation may raise <code>Teamcenter::Soa::Server::ServiceException </code>wrapping
     *           around following Teamcenter errors:
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
     *           256007&nbsp;&nbsp;&nbsp;&nbsp;An invalid expression was found (Context: info).
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
     *           256012&nbsp;&nbsp;&nbsp;&nbsp;The following <i>function</i>ality is not implemented:
     *           function (<i>Version: TcVersion</i>).
     *           <br>
     *           256013&nbsp;&nbsp;&nbsp;&nbsp;A configurator implementation specific error occurred
     *           (<i>Context: info)</i>.
     *           <br>
     *           256014&nbsp;&nbsp;&nbsp;&nbsp;The effectivity expression contains unmatched quote
     *           at position <i>number</i>.
     *           <br>
     *           256015&nbsp;&nbsp;&nbsp;&nbsp;The effectivity expression contains unmatched bracket
     *           at position <i>number</i>.
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
     *           256024&nbsp;&nbsp;&nbsp;&nbsp;The effectivity family <i>'text</i>' in token at position
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
     *           '<i>FamilyName</i>' in token at position number is invalid: the value unit of measure
     *           '<i>text</i>' does not match the family unit of measure<i> 'text</i>'.
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
    virtual Fnd0::Services::Configfiltercriteria::_2013_05::Effectivitymanagement::EffectivityDisplayStringResponse getEffectivityDisplayString ( const std::vector< Fnd0::Services::Configfiltercriteria::_2011_06::Effectivitymanagement::ConfigExpression >& expressions,
        const std::string&  productName,
        const std::string&  productNameSpace,
        const std::string&  configuratorURL ) = 0;

    /**
     * This operation determines and returns the degree of overlap between a set of effectivity
     * expressions and a set of reference effectivity criteria expressions. When applications
     * create or update DesignElements (DE) and assign effectivity, the UI may want to qualify
     * the degree of overlap between the effectivity of the DE and the currently active
     * RevRule effectivity criteria.
     * <br>
     * The following example illustrates the overlap states for a set of expressions:
     * <br>
     * <code>RevisionRule:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|---------------|
     * <br>
     * Object&nbsp;0:&nbsp;&nbsp;|----|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;:&nbsp;OverlapStateNone
     * <br>
     * Object&nbsp;1:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|------|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;:&nbsp;OverlapStateIntersect
     * <br>
     * Object&nbsp;2:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|----|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;:&nbsp;OverlapStateSubset
     * <br>
     * Object&nbsp;3:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|------|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;:&nbsp;OverlapStateIntersect
     * <br>
     * Object&nbsp;4:&nbsp;&nbsp;|-----------------------------|&nbsp;&nbsp;&nbsp;:&nbsp;OverlapStateSuperset
     * <br>
     * Object&nbsp;5:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|---------------|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;:&nbsp;OverlapStateMatch
     * <br>
     * Object&nbsp;6:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|-------------------|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;:&nbsp;OverlapStateSuperset
     * <br>
     * Object&nbsp;7:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|-------------------|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;:
     * OverlapStateSuperset</code>
     * <br>
     * This operation connects to the effectivity configurator service whose service endpoint
     * is specified by the <code>configuratorURL</code> parameter. Any conversion from formula
     * strings is performed by this configurator service. Depending on the (configurator
     * specific) encoding the operation might require the specification of a product context
     * using parameters <code>productName</code> and <code>productNameSpace</code>. For
     * example, a given configurator might recognize shorthand representations for formulae
     * if these are unique in the context of the specified product. Teamcenter 10.1 only
     * supports local built in Teamcenter configurators where parameter <code>configuratorURL</code>
     * can be set to an empty string. Teamcenter configurators don't require a product context
     * if the formulae are in <b>Explicit Teamcenter Language</b>. The encoding is explicit
     * if all lexemes are uniquely identified, e.g. [<i>OptionNamespace</i>]<i>FamilyName</i>
     * = <i>UniqueValue</i>, where no product context is required to determine the family
     * name for a value, or the option namespace for the family. A configuration expression
     * formula is in <b>Explicit Teamcenter Language </b>if its form is explicit and comprised
     * of the lexemes documented for the Teamcenter <b>Variant Formula </b>property. Teamcenter
     * configurators support shorthand encodings like <i>FamilyName = UniqueValue</i> or
     * <i>UniqueValue</i> if the lexemes used in the shorthand encoding are unique in the
     * specified product context.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * An application wants to qualify effectivity conditions that were retrieved with <b>getEffectivityConditions</b>
     * as to whether the condition is equal to, intersects with, or is a subset or superset
     * of the effectivity criteria associated with one or more <b>RevisionRules</b>. This
     * cannot be achieved with properties on effectivity conditions or RevisionRules because
     * the result depends on the combination of an effectivity condition and the effectivity
     * configuration criteria on a <b>RevisionRule</b>. One and the same condition may have
     * different overlap states with different RevisionRules.
     * <br>
     * The application calls <b>getEffectivityOverlapStates</b> and passes the effectivity
     * criteria (as obtained from a <b>RevisionRule</b> using <b>getRevRuleEffectivityCriteria</b>)
     * as <code>referenceExpressions</code>, and the effectivity conditions (as obtained
     * from a set of product data elements using <b>getEffectivityConditions</b>) as <code>expressions</code>.
     * <br>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * getEffectivityConditions, getRevRuleEffectivityCriteria
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Configuration Management - Capability to configure structured data based on revsion
     * rules; effectivities; Status etc.
     *
     * @param referenceExpressions
     *        The vector of reference effectivity criteria expressions.
     *
     * @param expressions
     *        Vector of effectivity expressions. The response returns the overlap state of each
     *        expression in this vector, with each of the reference effectivity criteria expressions
     *        given in the <code>referenceExpressions</code> parameter.
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
     *        The service end point for the effectivity configurator service. If empty the local
     *        Teamcenter configurator is used. Tc10.1 only supports local Teamcenter configurators.
     *        In Tc10.1 a non-empty <code>configuratorURL</code> parameter will cause an error.
     *
     * @return
     *         Compares each effectivity expressions with each reference expression and returns
     *         the degreee of overlap
     *
     *
     * @exception ServiceException
     *           This operation may raise <code>Teamcenter::Soa::Server::ServiceException </code>wrapping
     *           around following Teamcenter errors:
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
     *           256007&nbsp;&nbsp;&nbsp;&nbsp;An invalid expression was found (C<i>ontext: info</i>).
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
     *           256014&nbsp;&nbsp;&nbsp;&nbsp;The effectivity expression contains unmatched quote
     *           at position <i>number</i>.
     *           <br>
     *           256015&nbsp;&nbsp;&nbsp;&nbsp;The effectivity expression contains unmatched bracket
     *           at position <i>number</i>.
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
     *           in token at position <i>number</i> was found: '<i>text</i>'.
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
     *           of measure '<i>text</i>' does not match the family unit of measure '<i>te&nbsp;&nbsp;&nbsp;&nbsp;xt</i>'.
     *           <br>
     *           256032&nbsp;&nbsp;&nbsp;&nbsp;The option / family / family namespace combination
     *           '<i>text</i>' / '<i>FamilyName</i>' / '<i>DictionaryNamespace</i>' in token at position
     *           <i>number</i> is invalid.
     *           <br>
     *           256033&nbsp;&nbsp;&nbsp;&nbsp;The family '<i>FamilyName</i>' for option / family
     *           namespace combination '<i>text</i>' / '<i>DictionaryNamespace</i>' in token at position
     *           number is invalid.
     *           <br>
     *           256034&nbsp;&nbsp;&nbsp;&nbsp;There is no option value in token at position <i>number</i>.
     *           <br>
     *           256035&nbsp;&nbsp;&nbsp;&nbsp;The effectivity option value '<i>text</i>' for family
     *           '<i>FamilyName</i>' in token at position '<i>number</i>' is invalid: the value is
     *           not a valid date.
     *           <br>
     */
    virtual Fnd0::Services::Configfiltercriteria::_2013_05::Effectivitymanagement::EffectivityOverlapStateResponse getEffectivityOverlapStates ( const std::vector< Fnd0::Services::Configfiltercriteria::_2011_06::Effectivitymanagement::ConfigExpression >& referenceExpressions,
        const std::vector< Fnd0::Services::Configfiltercriteria::_2011_06::Effectivitymanagement::ConfigExpression >& expressions,
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

