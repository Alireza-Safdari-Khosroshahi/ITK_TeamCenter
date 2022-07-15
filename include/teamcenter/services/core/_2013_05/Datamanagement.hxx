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

#ifndef TEAMCENTER_SERVICES_CORE__2013_05_DATAMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_CORE__2013_05_DATAMANAGEMENT_HXX

#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/core/Core_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Core
        {
            namespace _2013_05
            {
                class Datamanagement;

class TCSOACORESTRONGMNGD_API Datamanagement
{
public:

    struct DeepCopyData;
    struct GeneratedValue;
    struct GeneratedValuesOutput;
    struct GenerateNextValuesIn;
    struct GenerateNextValuesResponse;
    struct GetChildrenInputData;
    struct GetChildrenOutput;
    struct GetChildrenResponse;
    struct GetPasteRelationsInputData;
    struct GetPasteRelationsOutput;
    struct GetPasteRelationsResponse;
    struct PasteRelationsInfo;
    struct ReviseIn;
    struct ReviseObjectsResponse;
    struct ReviseOut;
    struct ReviseTree;
    struct SubTypeNamesInput;
    struct SubTypeNamesOut;
    struct SubTypeNamesResponse;
    struct ValidateInput;
    struct ValidateValuesResponse;
    struct ValidationResults;
    struct ValidationStatus;

    /**
     * Additional parameters needed to generate the next values.
     */
    typedef std::map< std::string, std::string > AdditionalInputParamsMap;

    /**
     * A map of property name and PropertyValuesInput list.
     */
    typedef std::map< std::string, std::vector< GenerateNextValuesIn > > CompoundObjectInputMap;

    /**
     * A map where the key is the property name and the value is a list of <code>ValidateInput</code>.
     * This map contains the property values of the secondary objects.
     */
    typedef std::map< std::string, std::vector< ValidateInput > > CompoundValidateInputMap;

    /**
     * A map of property name and GeneratedValue list.
     */
    typedef std::map< std::string, GeneratedValue > GeneratedValuesMap;

    /**
     * A map of property name and list of  GeneratedValues.
     */
    typedef std::map< std::string, std::vector< GeneratedValuesOutput > > GeneratedValuesOfSecondaryObjectsMap;

    /**
     * This is a map of input BusinessObject to a vector of GetChildrenOutput objects.
     * It is used to look up the output for a given input BusinessObject.
     */
    typedef std::map< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> , std::vector< GetChildrenOutput > > GetChildrenOutputMap;

    /**
     * This is a map of input to a vector of GetPasteRelationOutput objects. It is used
     * to look up the output for a given input business object.
     */
    typedef std::map< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> , GetPasteRelationsOutput > GetPasteRelationsOutputMap;

    /**
     * A map of  property name and  naming rule pattern  pairs.
     */
    typedef std::map< std::string, std::string > PropertyNameWithSelectedPatternMap;

    /**
     * Map of property name(key) and property values(values) in string format.
     */
    typedef std::map< std::string, std::vector< std::string > > PropertyValues;

    /**
     * A map of property name and values list.
     */
    typedef std::map< std::string, std::vector< std::string > > PropValuesMap;

    /**
     * A map where the key is the <code>clientId</code> and the value is a list of <code>ValidationResults</code>
     * for the properties.
     */
    typedef std::map< std::string, ValidationResults > ValidationResultsMap;

    /**
     * The <code>DeepCopyData</code> data structure holds the relevant information regarding
     * applicable deep copy rules.
     */
    struct DeepCopyData
    {
        /**
         * Other side object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  attachedObject;
        /**
         * Name of relation type or reference property for which DeepCopy rule is configured.
         */
        std::string propertyName;
        /**
         * If <code>Relation</code>, it represents Relation type property. If <code>Reference</code>,
         * it represents Reference property.
         */
        std::string propertyType;
        /**
         * DeepCopy action [NoCopy, CopyAsReference, CopyAsObject or Select].
         */
        std::string copyAction;
        /**
         * If true the target object is processed as primary, otherwise it is processed as a
         * secondary object.
         */
        bool isTargetPrimary;
        /**
         * If true, the copy action can not be modified. If false, the copy action can be changed
         * different action by the user. In this case, the copy action field in the revise dialog
         * is editable.
         */
        bool isRequired;
        /**
         * If true, the custom properties on the source relation object are copied over to the
         * newly-created relation. If false, custom properties are not copied.
         */
        bool copyRelations;
        /**
         * OperationInput type name.
         */
        std::string operationInputTypeName;
        /**
         * List of DeepCopy data for the secondary objects on the other side.
         */
        std::vector< Teamcenter::Services::Core::_2013_05::Datamanagement::DeepCopyData > childDeepCopyData;
        /**
         * OperationInput field to capture property values of attached object, to apply on copied
         * object of attached object. Map of property name(key) and property values(values)
         * in string format of attached object, to be set on copied object of attached object.
         * The calling client is responsible for converting the different property types (int,
         * float, date .etc) to a string using the appropriate toXXXString functions in the
         * SOA client  framework Property class.
         */
        PropertyValues operationInputs;
    };

    /**
     * This structure contains the  generated value for the input property. It also contains
     * the information whether or not the generated values can be modified in the user interface.
     */
    struct GeneratedValue
    {
        /**
         * The error encountered during the generation of value.
         */
        int errorCode;
        /**
         * The  value generated based on the user exit/naming rule configured on the property.If
         * the property has multiple naming rule patterns with counters  and if the selected
         * pattern is passed as empty string, the value is generated based on the first pattern
         * configured on the naming rule. An error 74006 is returned if the generated value
         * does not match the naming rule pattern configured on the property and the nextValue
         * is set to empty string. An error 74006 is returned if the generated value does not
         * match the naming rule pattern configured on the property and the nextValue is set
         * to empty string.
         */
        std::string nextValue;
        /**
         * True if the user can modify the generated value.If isModifiable is false the attempts
         * to change the generated value shall be prevented at the user interface.
         */
        bool isModifiable;
    };

    /**
     * This structure contains the values generated for each of the properties supplied
     * in  the propertyNameWithSelectedPattern map of corresponding PropertyValuesInput
     * structure.
     */
    struct GeneratedValuesOutput
    {
        /**
         * Identifying string from the source GenerateNextValuesInput.
         */
        std::string clientId;
        /**
         * This contains map of property name and its values.
         */
        GeneratedValuesMap generatedValues;
        /**
         * Field contains value for generated secondary object property values.
         */
        GeneratedValuesOfSecondaryObjectsMap generatedValuesOfSecondaryObjects;
    };

    /**
     * The input required to generate the next values.
     */
    struct GenerateNextValuesIn
    {
        /**
         * A unique string supplied by the caller.
         */
        std::string clientId;
        /**
         * The type of the operation for which the values are to be generated. 1-CREATE
         * <br>
         * 2-REVISE
         * <br>
         * 3-SAVEAS.
         * <br>
         * <br>
         * An error 74007 is returned by the generateNextValues operation if the operationType
         * value is not in any of the above.
         */
        int operationType;
        /**
         * The name of the business object for which the property values are to be generated.
         * An error 39007 is returned by the generateNextValues operation if the type name is
         * not valid.
         */
        std::string businessObjectName;
        /**
         * A map of  property name and  naming rule pattern  pairs( string/string ).The key
         * is the property name for which the value is to be generated and the value is the
         * naming rule pattern string selected for  that property. If no pattern is selected
         * for the property  the pattern string  should be empty string. The caller should only
         * pass the properties that are autoassignable.
         */
        PropertyNameWithSelectedPatternMap propertyNameWithSelectedPattern;
        /**
         * A map of property name and values list(string/vector) of all the properties that
         * are provided as inputs to create/revise/save as action of an object excluding the
         * properties whose values are needed to be generated.If a multi field key is configured
         * on the object ,the values of the constituent properties of the multi field key other
         * than the ones for which the values are currently being generated are obtained from
         * this map in order to perform the validation.
         * <br>
         * The entries in this map are also used to generate values for the autoassignable properties
         * of some business objects.
         * <br>
         * <br>
         * Eg:
         * <br>
         * Identifier: "idContext" value is needed to generate "idfr_id" property value
         * <br>
         * <br>
         * An error  74032 is returned if any of the above property values are not provided
         * .
         * <br>
         * <br>
         * The values of the properties are to be provided as strings. For non string type properties
         * use the Property.toXXXString functions (ie. toDateString) to covert the actual values
         * to a string.
         * <br>
         */
        PropValuesMap propValues;
        /**
         * A map of extra information which is required by user exits to generate values.
         * <br>
         * A map where the key (string) is a parameter name and the value (string) is the parameter
         * value.
         * <br>
         * <br>
         * Valid parameters are:
         * <br>
         * <br>
         * "ruleSuffix":
         * <br>
         * This is only used when Baseline action to be performed. 'PDR'  should be passed
         * as ruleSuffix  in case of Baseline action. An error 74030 is returned if invalid
         * ruleSuffix is supplied.
         * <br>
         * <br>
         * "sourceObject":
         * <br>
         * The object that is being revised/saved  or  the parent object  during  Dataset creation
         * . Its value should be passed as the object UID. An error 74031 is returned if this
         * parameter is not provided during revise/save as action.  It is optional in case of
         * Dataset creation .
         * <br>
         * <br>
         * Object Name&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Operation&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Value&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|
         * <br>
         * ============================================|
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;ITEM&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Create&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;NULLTAG&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;SaveAs&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Source
         * tag&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;ITEM Revision&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Create/SaveAs&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;NULLTAG&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Revise&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Source
         * tag&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Baseline&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Source
         * tag&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
         * |
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;Identifier&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Create&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;NULLTAG&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
         * |&nbsp;&nbsp;&nbsp;&nbsp;
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Revise/SaveAs&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
         * Source tag&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
         * |
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
         * |
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;Dataset&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
         * Create&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
         * Source tag&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
         * |
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
         * SaveAs&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;NULLTAG&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
         * |
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
         * |
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;CPD Objects&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;Create/Revise/SaveAs&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
         * Source tag&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
         * |
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
         * |
         * <br>
         * ============================================|
         * <br>
         * <br>
         * Any parameter other than the above will not be considered.
         * <br>
         */
        AdditionalInputParamsMap additionalInputParams;
        /**
         * Map for compound property.
         * <br>
         * A map where the key (string) is a compound property name and the value (vector) is
         * vector of GenerateNextValuesIn type.
         * <br>
         * <br>
         * By using this map user can generate values for its own properties and also values
         * for any of its   compound objects's propert. Provided property is autoassignable.
         * <br>
         * <br>
         * For example user can generate value for "item_id" on item Object and value for "item_revision_id"
         * property also using its compound pbject ItemRevision using this map.
         */
        CompoundObjectInputMap compoundObjectInput;
    };

    /**
     * This output structure contains service data with partial errors and a list of GeneratedValuesOutput
     * each for an entry in the generateNextValuesIn input list.
     */
    struct GenerateNextValuesResponse
    {
        /**
         * The Service Data with partial errors for each GenerateNextValuesInput and identified
         * by  its clientId.
         */
        Teamcenter::Soa::Client::ServiceData data;
        /**
         * A list of GeneratedValuesOutput one for each entry in generateNextvaluesIn input
         * list and  identified by its clientId.
         */
        std::vector< Teamcenter::Services::Core::_2013_05::Datamanagement::GeneratedValuesOutput > generatedValues;
    };

    /**
     * This structure defines the object for which to retrieve children and optionally the
     * propertyNames from which to retrieve those children.  If propertyNames is undefined,
     * then the Teamcenter <Type>_DefaultChildProperties preference is used.
     */
    struct GetChildrenInputData
    {
        /**
         * Identifier used to track the input object.  Primarily this is used to identify which
         * PartialError corresponds to which input object.
         */
        std::string clientId;
        /**
         * The object for which to retrieve children.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  obj;
        /**
         * The properties to use to retrieve children.  Only the properties defined in this
         * list are used. If this list is empty, then the children are returned based on the
         * <Type>_DefaultChildProperties and <Type>_PseudoFolders preferences.  Please see the
         * P<i>references and Environment Variables Reference</i> and the<i> RichClient Interface
         * Guide</i> for information on configuring there preferences
         */
        std::vector< std::string > propertyNames;
    };

    /**
     * This structure contains the children output for the defined property name.
     */
    struct GetChildrenOutput
    {
        /**
         * This is the list of Teamcenter business object children which exist within this property
         * name.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > children;
        /**
         * The property the child belongs to in the parent input object.
         */
        std::string propertyName;
    };

    /**
     * Output structure for the getChildren operation.
     */
    struct GetChildrenResponse
    {
        /**
         * The service data contains any partial errors which may have been encountered during
         * processing.  All business objects which are returned are added to the serviceData's
         * plain objects list.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * A map of requested objects and a list of children(business object/vector<GetChildrenOutput>).
         */
        GetChildrenOutputMap objectWithChildren;
    };

    /**
     * Object input structure of getPasteRelations operation.
     */
    struct GetPasteRelationsInputData
    {
        /**
         * Identifier used to track the input object.  Primarily this is used to identify which
         * PartialError corresponds to which input object.
         */
        std::string clientId;
        /**
         * The parent object for which to get the paste relations.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  obj;
        /**
         * The child type name for which the paste relations will be retrieved.
         */
        std::string childTypeName;
    };

    /**
     * Output structure of getPasteRelations operation.  This structure contains all the
     * paste relations for a given business object.
     */
    struct GetPasteRelationsOutput
    {
        /**
         * This is the list of paste relation names and other info for the given business object.
         */
        std::vector< Teamcenter::Services::Core::_2013_05::Datamanagement::PasteRelationsInfo > pasteRelationsInfo;
        /**
         * The zero-based index of the preferred paste relation in the list of paste relation
         * names.
         */
        int indexOfPreferred;
    };

    /**
     * Response of getPasteRelations operation.  This structure contains the servicedata
     * and the outputMap to look up the paste relations for a given business object.
     */
    struct GetPasteRelationsResponse
    {
        /**
         * The service data contains any partial errors which may have been encountered during
         * processing.  All business objects which are returned are added to the serviceData&apos;s
         * plain objects list.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * A map of input parent object to a vector of GetPasteRelationsOutput objects.
         */
        GetPasteRelationsOutputMap outputMap;
    };

    /**
     * Object output structure of getPasteRelations operation.
     */
    struct PasteRelationsInfo
    {
        /**
         * The paste relation name.
         */
        std::string pasteRelationName;
        /**
         * A flag indicating whether the relation will enable the children to be shown under
         * the parent when expanded.
         */
        bool isExpandable;
    };

    /**
     * Input structure for <code>reviseObjects</code> operation of any revisable object.
     */
    struct ReviseIn
    {
        /**
         * Target object being revised
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  targetObject;
        /**
         * Map of property name(key) and property values(values) in string format, to be set
         * on new object being created with revise. The calling client is responsible for converting
         * the different property types (int, float, date .etc) to a string using the appropriate
         * toXXXString functions in the SOA client framework Property class.
         */
        PropertyValues reviseInputs;
        /**
         * Relevant information regarding applicable deep copy rules for the objects attached
         * to the targetobject.
         */
        std::vector< Teamcenter::Services::Core::_2013_05::Datamanagement::DeepCopyData > deepCopyDatas;
    };

    /**
     * Output structure of <code>reviseObjects</code> operation have information of new
     * resultant objects created and error information if any.
     */
    struct ReviseObjectsResponse
    {
        /**
         * The target object and the newly created revised objects.
         */
        std::vector< Teamcenter::Services::Core::_2013_05::Datamanagement::ReviseOut > output;
        /**
         * List corresponding to the input target objects that holds mapping between the original
         * objects and the copied objects.
         */
        std::vector< Teamcenter::Services::Core::_2013_05::Datamanagement::ReviseTree > reviseTrees;
        /**
         * Data containing created objects, errors, etc.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Member of Output structure of <code>reviseObjects</code> operation, having information
     * of original and newly created objects.
     */
    struct ReviseOut
    {
        /**
         * Original object being revised.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  targetObject;
        /**
         * Newly created revised objects during revise operation.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > objects;
    };

    /**
     * Member of Output structure of <code>reviseObjects</code> operation, having information
     * of attached objects and newly created objects from them.
     */
    struct ReviseTree
    {
        /**
         * Original object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  originalObject;
        /**
         * Object copy after Revise. This could be NULL if no copy was made or same as original
         * object if the copy is a reference to the original.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  objectCopy;
        /**
         * Nested information for next level of the tree.
         */
        std::vector< Teamcenter::Services::Core::_2013_05::Datamanagement::ReviseTree > childReviseNodes;
    };

    /**
     * The parent business object type name and context for which the sub business object
     * type names are to be retrieved.
     */
    struct SubTypeNamesInput
    {
        /**
         * The business object type name for which sub business object type names are to be
         * returned. If all sub business object type names are needed then pass BusinessObject
         * as input.
         */
        std::string typeName;
        /**
         * Context name based on which server returns the business object type names.
         * <br>
         * <br>
         * Supported contexts:
         * <br>
         * <br>
         * subtypes: Returns all sub business object type names.
         */
        std::string contextName;
        /**
         * Name of the preference to be used to exclude the sub business object type names from
         * the output. Preference needs to be a multi-valued to specify the names of the business
         * object types to be excluded.
         * <br>
         * <br>
         * This is optional. It could be empty string.
         */
        std::string exclusionPreference;
    };

    /**
     * This is the output structure which holds list of sub business object type names for
     * a given business object type based on the context specified.
     */
    struct SubTypeNamesOut
    {
        /**
         * The parent business object type name.
         */
        std::string typeName;
        /**
         * Name of the context for which  the typeName represents.
         */
        std::string contextName;
        /**
         * Name of the preference to be used to exclude the sub business object type names from
         * the output. Preference needs to be a multi-valued to specify the names of the business
         * object types to be excluded.
         * <br>
         * <br>
         * This is optional. It could be empty string.
         */
        std::string exclusionPreference;
        /**
         * List of sub business object type names based on the context name.
         */
        std::vector< std::string > subTypeNames;
        /**
         * List of sub business object type displayable names based on the context name.
         */
        std::vector< std::string > displayableSubTypeNames;
    };

    /**
     * The returned business object type names based on the context for each input business
     * object type.
     */
    struct SubTypeNamesResponse
    {
        /**
         * List of  business object type names.
         */
        std::vector< Teamcenter::Services::Core::_2013_05::Datamanagement::SubTypeNamesOut > output;
        /**
         * The Service data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure contains the necessary input for the <code>validateValues</code> operation
     * to support generic property validation while retaining support for some existing
     * user exits for specific properties.  The <code>validateValues</code> operation details
     * legacy user exit support.
     */
    struct ValidateInput
    {
        /**
         * A unique string supplied by the caller.  This ID is used to identify return data
         * elements and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * The operation type for which the input values are to be validated. Valid values are:
         * <br>
         * <br>
         * <ul>
         * <li type="disc">0 for create
         * </li>
         * <li type="disc">1 for revise
         * </li>
         * <li type="disc">2 for saveas
         * </li>
         * <li type="disc">3 for generic validation
         * </li>
         * </ul>
         */
        int operationType;
        /**
         * The name of the <b>business object</b> for which the property values are to be validated.
         */
        std::string businessObjectName;
        /**
         * A map where the key (string) is a property name and the value (string) is the property
         * value to be validated.  The value input is a list to support multi-value properties.
         * The values of the properties are to be provided as strings.
         */
        PropertyValues propValuesMap;
        /**
         * A map where the key (string) is a property name and the value (<code>ValidateInput</code>)
         * is input for the property. This contains the property values of the secondary objects.
         */
        CompoundValidateInputMap compoundObjectInput;
    };

    /**
     * The response from the <code>validateValues</code> operation.
     */
    struct ValidateValuesResponse
    {
        /**
         * A map where the key (string) is the <code>clientId</code> and the value (<code>ValidationResults</code>)
         * is a list of validation results for the properties.
         */
        ValidationResultsMap validationResults;
        /**
         * Service data containing errors that occurred during the operation.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure holds the property validation results for <code>validateValues</code>
     * operation.
     */
    struct ValidationResults
    {
        /**
         * If true, the MFK value is unique.  If false, the MFK value is not unique.
         */
        bool uniqueID;
        /**
         * A list of <b>ValidationStatus</b>, which contains the validation status for each
         * input property value.
         */
        std::vector< Teamcenter::Services::Core::_2013_05::Datamanagement::ValidationStatus > validationStatus;
    };

    /**
     * This structure holds the validation status for a property.
     */
    struct ValidationStatus
    {
        /**
         * The property name.
         */
        std::string propName;
        /**
         * The status of the property value validation. The possible values are:
         * <br>
         * <br>
         * <ul>
         * <li type="disc">0 for valid
         * </li>
         * <li type="disc">1 for invalid
         * </li>
         * <li type="disc">2 for override
         * </li>
         * <li type="disc">3 for duplicate
         * </li>
         * </ul>
         */
        int valueStatus;
        /**
         * The modified property value if modified by the user exit.  This is a list to support
         * multi-value properties.
         */
        std::vector< std::string > modifiedValue;
    };




    /**
     * Returns the paste relation names for the given parent types and the child types,
     * within which the expandable relations and the preferred paste relation are indicated.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model General - This component provides a set of generic capabilities that form
     * the very core of Teamcenter platform.
     *
     * @param inputs
     *        The list of  the parent object and the child type.
     *
     * @return
     *         This returns the getPasteRelations, a tree structure that contains the relations
     *         for the given business object together with expandability, and the information of
     *         which one is the preferred relation.
     *         <br>
     *         <br>
     *         The following partial error may be returned:
     *         <br>
     *         214110: The input object is not valid.
     *         <br>
     *         39014: The specified type NonExistingItem does not exist.
     *         <br>
     *         39028: No paste relations were found for the type.
     *         <br>
     *         39029: No expandable paste relations were found for the type.
     *         <br>
     *         39030: No preferred paste relation was found for the type.
     *
     */
    virtual Teamcenter::Services::Core::_2013_05::Datamanagement::GetPasteRelationsResponse getPasteRelations ( const std::vector< Teamcenter::Services::Core::_2013_05::Datamanagement::GetPasteRelationsInputData >& inputs ) = 0;

    /**
     * This operation is generic single revise operation for revisable business objects.
     * This operation revises the given objects and copies or creates new objects using
     * the data for the property values and deep copy data. Deep copy processing is recursive
     * such that relations between secondary objects, or from secondary objects to the revised
     * object, are replicated during this revise operation based upon deep copy rule configuration.
     * This operation supports codeless configuration of custom properties. The following
     * lists of revisable types are supported for this operation:
     * <br>
     * <ul>
     * <li type="disc">ItemRevision ( foundation template) and its sub-types
     * </li>
     * <li type="disc">Identifier ( foundation template ) and its sub-types
     * </li>
     * <li type="disc">Mdl0ConditionalElement (CPD solution ) and its sub-types
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model General - This component provides a set of generic capabilities that form
     * the very core of Teamcenter platform.
     *
     * @param reviseIn
     *        Input data containing target object and DeepCopyData of the attached objects
     *
     * @return
     *         The return contains a list of business objects that were created with revise. Failures
     *         for any element in the input list are returned as a Partial Error in the ServiceData.
     *         The Partial Errors includes the index of the failed element from the input list.
     *         The following partial errors may be returned (with the index of the failed input
     *         argument):
     *         <br>
     *         <ul>
     *         <li type="disc">252082&nbsp;&nbsp;&nbsp;&nbsp;The target object cannot be revised
     *         (non-revisable type)
     *         </li>
     *         <li type="disc">48038&nbsp;&nbsp;&nbsp;&nbsp;A revision with requested revision id
     *         already exist
     *         </li>
     *         <li type="disc">236013&nbsp;&nbsp;&nbsp;&nbsp;Target object/Attached object does
     *         not have mentioned property type
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Core::_2013_05::Datamanagement::ReviseObjectsResponse reviseObjects ( const std::vector< Teamcenter::Services::Core::_2013_05::Datamanagement::ReviseIn >& reviseIn ) = 0;

    /**
     * This operation validates whether the input property values are valid according to
     * defined naming rules and specified user exits for the input property.  Also, for
     * the properties used in the multifield key (MFK) definition for the input type, this
     * operation validates whether the combined property values makes up a unique value.
     * <br>
     * <br>
     * The<code> validateValues</code> operation can be called before other service operations
     * that create new objects, such as the <code>createObjects</code> or <code>saveAsObjects</code>
     * operations, in order to avoid errors that would occur during object creation due
     * to invalid property values.  For example, if a large set of objects to be created
     * is passed to the <code>createObjects</code> operation, where half of the set could
     * fail due to invalid property values, the <code>validateValues</code> operation could
     * be used to avoid those failures by checking whether the input object property values
     * are valid.
     * <br>
     * <br>
     * All of the input property names and their values should be included in <code>ValidateInput</code>
     * <code>propValuesMap</code>.
     * <br>
     * <br>
     * For user exit support, an existing user exit will be called if a specific property
     * is specified along with additional input according to the user exit parameter names.
     * The specific property, referred to as the identifying property below, dictates which
     * user exit will be called.  The additional input name and its value should also be
     * include in <code>ValidateInput</code> <code>propValuesMap</code>.
     * <br>
     * <br>
     * User exit name: <code>USER_validate_dataset_name</code>
     * <br>
     * Identifying property:
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;<code>object_name</code>: The <b>Dataset</b> name to be validated.
     * This must be set in <code>propValuesMap</code>
     * <br>
     * Additional user exit parameter names:
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;<code>vdnItemType</code>: The <b>Item</b> type for the new
     * <b>Item</b>, which has not necessarily been created yet.
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;<code>vdnOldDataset</code>: The old <b>Dataset</b> object.
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;<code>vdnOldDatasetOwner</code>: The old <b>ItemRevision</b>
     * object.
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;<code>vdnNewDatasetItemId</code>: The <b>Item</b> ID for
     * the new item, which has not necessarily been created yet.
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;vdnNewDatasetRevisionId: The <b>ItemRevision</b> ID for the
     * new revision, which has not necessarily been created yet.
     * <br>
     * <br>
     * User exit name: <code>USER_validate_item_rev_id</code>
     * <br>
     * Identifying property:
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;<code>item_id</code>: The <b>Item</b> ID entered in the dialog
     * box by the user.  This must be set in <code>propValuesMap</code>.
     * <br>
     * Additional user exit parameter names:
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;<code>item_revision_id</code>: The <b>ItemRevision</b> ID
     * entered in the dialog box by the user.  This must be set in <code>propValuesMap</code>.
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;<code>object_type</code>: The <b>Item</b> type entered into
     * the dialog box by the user.  This may be NULL.  This must be set in <code>propValuesMap</code>.
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;<code>viriItemObject</code>: The <code>Item</code> for item
     * revise. For new <code>Item</code> this should be NULLTAG.
     * <br>
     * <br>
     * User exit name: <code>USER_validate_alternate</code>
     * <br>
     * Identifying property:
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;<code>altid_of</code>: The identifiable type object to which
     * the alternate ID is associated.
     * <br>
     * Additional user exit parameter names:
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;<code>idcontext</code>: The <b>IDContext</b> object which
     * holds the cardinality rule for the given identifiable type object and the <b>Identifier</b>
     * type object.
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;<code>vaAltIdObject</code>: The alternate ID object.
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;<code>vaAltIdType</code>: The <b>Identifier</b> type object.
     * <br>
     * <br>
     * User exit name: <code>USER_validate_alt_id</code>
     * <br>
     * Identifying property:
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;<code>idfr_id</code>: The alternate ID which is to be validated
     * against any of the naming rule associated with the <b>Identifier</b> type.
     * <br>
     * Additional user exit parameter names:
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;<code>idcontext</code>: No longer used.
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;<code>vaiIdfrType</code>: The name of the <b>Identifier</b>
     * type whose alternate ID is being validated.
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;<code>vaiPatternName</code>: The name of the <b>Identifier</b>
     * type or <b>IdentifierRevision</b> type whose alternate ID is being validated.
     * <br>
     * <br>
     * For the MFK uniqueness validation, it is important to note that the check for uniqueness
     * is done against existing objects in Teamcenter and not between separate client inputs.
     * It is the responsibility of the client to validate whether separate input values
     * in a single call would conflict with each other.
     * <br>
     * <br>
     * The <code>ValidateInput</code> <code>operationType</code> input is currently a placeholder
     * for future functionality that differentiates validation according to the workflow
     * type, where validation for creating an object may be different then validation for
     * saving an object.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Use Case 1:
     * <br>
     * Prior to calling the service operation <code>saveAsObjects</code>, which may fail
     * due to an error with any input property value, the client would call <code>validateValues</code>
     * for the properties to have Teamcenter check whether the values are valid.
     * <br>
     * <br>
     * Use Case 2:
     * <br>
     * Prior to making a call to the service operation <code>createObjects</code> for several
     * objects, the client wants to ensure that each object will be created with a unique
     * identifier according to the MFK definition for the object type. The client would
     * call <code>validateValues</code> for the properties to have Teamcenter check that
     * the values are valid and that the combined values would make a unique MFK value.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model General - This component provides a set of generic capabilities that form
     * the very core of Teamcenter platform.
     *
     * @param inputs
     *        The list of <b>ValidateInput</b>. The properties specified in each input are validated
     *        against defined naming rules and user exits. The property values are also combined
     *        to validate whether they make up a unique value.
     *        <br>
     *
     * @return
     *         The operation response includes status information for naming rule validation for
     *         each individual property.  The response also includes whether the combined property
     *         values would create a unique MKF value according to the MFK definition.
     *         <br>
     *         <br>
     *         The following partial error may be returned (with the index of the failed input argument):
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">214134  An error has occurred during the property validation for
     *         the object of client ID "id". Please check the returned partial errors related to
     *         this object for additional information.
     *         </li>
     *         <li type="disc">38099  Operation <i>operationName</i> not implemented for properties
     *         of this <i>type</i> type.
     *         </li>
     *         <li type="disc">38101  An invalid object reference was passed to the property operation.
     *         Please refer to the Teamcenter syslog file for more information, and report this
     *         error to your system administrator.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Core::_2013_05::Datamanagement::ValidateValuesResponse validateValues ( const std::vector< Teamcenter::Services::Core::_2013_05::Datamanagement::ValidateInput >& inputs ) = 0;

    /**
     * This operation returns the children for each input object.  The children returned
     * is determined by the input <code>propertyNames</code> list of strings which defines
     * the properties which are to be processed in order to collect the children to be returned
     * If the <code>propertyNames</code> list is empty, then the properties which are processed
     * to object the children is based on the <Type>_DefaultChildProperties and <Type>_DefaultPseudoFolder
     * preferences.  Please see the <i>Preferences and Environment Variables Reference</i>
     * and the<i> RichClient Interface Guide</i> for information on configuring these preferences.
     * Children for which the user does not have read-access will be excluded from the returned
     * list of children. No partial error is given if the <code>propertyNames</code> list
     * or the <Type>_DefaultChildProperties preference contains an invalid property name
     * for the input object, children for the remaining <code>propertyNames</code> will
     * be returned.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Assume the following data exists in Teamcenter:
     * <br>
     * Item
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;Item Revision
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;Item Master Form
     * <br>
     * <br>
     * The ItemRevision exists in the Item's "revision_list" property.
     * <br>
     * Item Item Master Form exists in the Item's "IMAN_master_form" property.
     * <br>
     * <br>
     * <b>Use case 1 (Get all children/no filter)</b>
     * <br>
     * 1.&nbsp;&nbsp;&nbsp;&nbsp;The user selects the Item in the above data in a tree viewer
     * which shows all objects.
     * <br>
     * 2.&nbsp;&nbsp;&nbsp;&nbsp;The user clicks the "+" to expand the Item.
     * <br>
     * 3.&nbsp;&nbsp;&nbsp;&nbsp;The client then invokes getChildren with the selected object
     * (Item), and no entries in the <code>propertyNames</code> argument.
     * <br>
     * 4.&nbsp;&nbsp;&nbsp;&nbsp;getChildren determines the selected object's type, retrieves
     * <Type>_DefaultChildProperties and <Type>_PseudoFolders preferences, and returns the
     * Item Revision and Item Master Form, their type objects, and the propertyName in which
     * they exist related to the parent.
     * <br>
     * 5.&nbsp;&nbsp;&nbsp;&nbsp;The client then displays the returned list of children
     * as child nodes in the tree.
     * <br>
     * <br>
     * <b>Use case 2 (Get subset of children/with filter)</b>
     * <br>
     * 1.&nbsp;&nbsp;&nbsp;&nbsp;The user selects the Item in the above data in a tree viewer
     * which only shows object related via the revision_list property.
     * <br>
     * 2.&nbsp;&nbsp;&nbsp;&nbsp;The user clicks the "+" to expand the Item.
     * <br>
     * 3.&nbsp;&nbsp;&nbsp;&nbsp;The client then invokes getChildren with the selected object
     * (Item), and gives "revision_list" in the <code>propertyNames</code> list.
     * <br>
     * 4.&nbsp;&nbsp;&nbsp;&nbsp;getChildren iterates over the propertyNames list, and returns
     * the Item Revision object, its child type object, and the propertyName in which it
     * exists related to the parent.
     * <br>
     * 5.&nbsp;&nbsp;&nbsp;&nbsp;The client then displays the returned list of children
     * as child nodes in the tree.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model Method Layer - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of our PLM platform. This component defines basic method
     * structure.
     *
     * @param inputs
     *        The list of objects and desired children for which to expand and return children.
     *
     * @return
     *         The partial error 236027 (error) is returned if there is an error retrieving the
     *         value for a valid property.
     *
     */
    virtual Teamcenter::Services::Core::_2013_05::Datamanagement::GetChildrenResponse getChildren ( const std::vector< Teamcenter::Services::Core::_2013_05::Datamanagement::GetChildrenInputData >& inputs ) = 0;

    /**
     * This operation returns sub business object type names for each business object type
     * name given as the input for the specified context.
     * <br>
     * <br>
     * It returns the input base type in the sub business object type names list too.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model Types - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of Teamcenter PLM platform. This component defines Types
     * framework.
     *
     * @param inBOTypeNames
     *        A list of business object type names with the desired context.
     *
     * @return
     *         Returns the sub business object type names for each requested parent business object
     *         type. It returns the input base type in the sub business object type names list too.
     *         <br>
     *         <br>
     *         The following partial errors may be returned:
     *         <br>
     *         <br>
     *         39007: The requested business name does not exist
     *         <br>
     *         <br>
     *         39031: The requested context is not supported
     *
     */
    virtual Teamcenter::Services::Core::_2013_05::Datamanagement::SubTypeNamesResponse getSubTypeNames ( const std::vector< Teamcenter::Services::Core::_2013_05::Datamanagement::SubTypeNamesInput >& inBOTypeNames ) = 0;

    /**
     * This operation generates values for the given properties of an object(s) during create/revise/save
     * as action based on the user exits or naming rules configured on those properties.Customer
     * user exits are given priority over the naming rules if both of them are configured
     * on the same property. The counter has to be set active on the naming rule in order
     * to generate the next value for a property. This operation also performs naming rule
     * and multi field key validation on the generated values and return appropriate partial
     * errors if the validation fails.
     * <br>
     * <br>
     * For user exit support, an existing user exit will be called to generate values. Right
     * now we support below given user exits for corrosponding Objest type.
     * <br>
     * <br>
     * Object: Item
     * <br>
     * User exit name: USER_new_item_id
     * <br>
     * Property: item_id
     * <br>
     * <br>
     * Object: ItemRevision
     * <br>
     * User exit name: USER_new_revision_id, USER_new_revision_id_from_alt_rule(Baseline)
     * <br>
     * Property: item_revision_id
     * <br>
     * <br>
     * Object: Dataset
     * <br>
     * User exit name: USER_new_dataset_id
     * <br>
     * Property: pubr_object_id
     * <br>
     * <br>
     * Object: Dataset
     * <br>
     * User exit name: USER_new_dataset_rev
     * <br>
     * Property: rev
     * <br>
     * <br>
     * Object: Identifier
     * <br>
     * User exit name: IDFR_new_alt_id, IDFR_new_rev_id(In Revise case)
     * <br>
     * Property: idfr_id
     * <br>
     * <br>
     * Object: CPD Objects
     * <br>
     * User exit name: USER_new_cpd_id
     * <br>
     * Property: CPD Objects related property
     * <br>
     * <br>
     * These each user exits need some specific inputs which are required by them to generate
     * ids. These inputs are part of "generateNextValuesIn" structure and are described
     * in details in its description.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * a)&nbsp;&nbsp;&nbsp;&nbsp;User clicks on assign button in Create/Revise/Saveas dialog:
     * <br>
     * <br>
     * Autoassignable properties are those that have either a user exit or a naming rule
     * with counter configured.A constant "autoassignable" is defined on the PropertyDescription
     * class and its value can be obtained using PropertyDescription.getConstant() API.
     * "Assign" button is displayed in create/revise/save as dialog to populate their values.
     * <br>
     * <br>
     * This operation is used  to  generate the values for the autoassignable properties
     * when the user clicks on the "Assign" button.The caller should collect the list of
     * all autoassignable properties  that do not have any user input and pass them to this
     * operation. If  the autoassignable  property has a naming rule , the  naming rule
     * pattern selected by the user  for  that property should also be passed as input to
     * this operation. In all other cases the naming rule pattern should be passed as empty
     * string.
     * <br>
     * <br>
     * b)&nbsp;&nbsp;&nbsp;&nbsp;User clicks on finish button in Create/Revise/Saveas dialog:
     * <br>
     * <br>
     * This operation is also used to generate the values for the autoassignable properties
     * when the user clicks "Finish" button in in create/revise/save as dialog. The caller
     * should collect the list of  all autoassignable properties that do not have any value
     * generated and pass them to this operation. If  the autoassignable  property has a
     * naming rule , the  naming rule pattern selected by the user  for  that property should
     * also be passed as input to this operation. In all other cases the naming rule pattern
     * should be passed as empty string.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Naming Rules - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of Teamcenter PLM platform. This component defines Naming
     * Rules and Revision Naming Rules.
     *
     * @param generateNextValuesIn
     *        This is the input that the SOA 'generateNextValues' expects. This contains the list
     *        of properties for which the next values are to be generated. This structure itself
     *        holds another structure PropertyValuesInput which actually holds essential information
     *        like the business object name, the property values and other additional information.
     *        <br>
     *        GenerateNextValluesInput also specifies the operation name in the form of an integer
     *        <br>
     *        [ 1. CREATE 2. REVISE 3. SAVE-AS ].
     *
     * @return
     *         A list of GeneratedValuesOutput, one for each entry in generateNextvaluesIn input
     *         list and identified by clientId. GeneratedValuesOutput in turn contains GeneratedValue
     *         for each supplied property which has the generated value for the property and the
     *         modifiable status. The following partial error may be returned, the clientId from
     *         the offending GenerateNextValuesInput will be attached to any partial error:
     *         <br>
     *         <ul>
     *         <li type="disc">38015 &nbsp;&nbsp;&nbsp;&nbsp;Unable to find a property with the
     *         requested name.
     *         </li>
     *         <li type="disc">39007&nbsp;&nbsp;&nbsp;&nbsp;The specified type name is invalid.
     *         </li>
     *         <li type="disc">38312 &nbsp;&nbsp;&nbsp;&nbsp;The property is not autoassignable.
     *         </li>
     *         <li type="disc">74015 &nbsp;&nbsp;&nbsp;&nbsp;The selected pattern does not match
     *         any of the Naming Rule patterns configured for the  property.
     *         </li>
     *         <li type="disc">74031 &nbsp;&nbsp;&nbsp;&nbsp;The sourceObject parameter is missing
     *         during revise/save as action.
     *         </li>
     *         <li type="disc">74030 &nbsp;&nbsp;&nbsp;&nbsp;The ruleSuffix parameter is not valid.
     *         </li>
     *         <li type="disc">74032 &nbsp;&nbsp;&nbsp;&nbsp;The dependant property values were
     *         not provided, and therefore an auto-generated value could not be created.
     *         </li>
     *         <li type="disc">74006 &nbsp;&nbsp;&nbsp;&nbsp;The  generated value does not match
     *         any of the naming rule patterns configured on the property.
     *         </li>
     *         <li type="disc">74007&nbsp;&nbsp;&nbsp;&nbsp;Invalid operation type is provided.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Core::_2013_05::Datamanagement::GenerateNextValuesResponse generateNextValues ( const std::vector< Teamcenter::Services::Core::_2013_05::Datamanagement::GenerateNextValuesIn >& generateNextValuesIn ) = 0;


protected:
    virtual ~Datamanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/core/Core_undef.h>
#endif

