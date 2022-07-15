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

#ifndef TEAMCENTER_SERVICES_CORE__2010_04_DATAMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_CORE__2010_04_DATAMANAGEMENT_HXX

#include <teamcenter/services/core/_2007_06/Datamanagement.hxx>
#include <teamcenter/services/core/_2008_06/Datamanagement.hxx>
#include <teamcenter/soa/client/model/Dataset.hxx>
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
            namespace _2010_04
            {
                class Datamanagement;

class TCSOACORESTRONGMNGD_API Datamanagement
{
public:

    struct AttributeInfo;
    struct AvailableBusinessObjectTypeInfo;
    struct BusinessObjectHierarchy;
    struct CommitDatasetFileInfo;
    struct CreateDatasetsResponse;
    struct DatasetFileInfo;
    struct DatasetFileTicketInfo;
    struct DatasetInfo;
    struct DatasetOutput;
    struct DisplayableBusinessObjectsOut;
    struct DisplayableSubBusinessObjectsResponse;
    struct GetAvailableBusinessObjectTypesResponse;
    struct GetDatasetCreationRelatedInfoResponse2;
    struct LocalizableResults;
    struct LocalizableStatusInput;
    struct LocalizableStatusOutput;
    struct LocalizableStatusResponse;
    struct LocalizedPropertyValuesInfo;
    struct LocalizedPropertyValuesList;
    struct NamedReferenceObjectInfo;
    struct NameLocaleStruct;
    struct NameValueLocaleStruct;
    struct PropertyInfo;

    /**
     * A map of classes and their types
     */
    typedef std::map< std::string, std::vector< AvailableBusinessObjectTypeInfo > > BusinessObjectClassToTypesMap;

    /**
     * This structure contains the name value pairs.
     */
    struct AttributeInfo
    {
        /**
         * Name of the attribute that needs to be set.
         */
        std::string name;
        /**
         * Values to be set
         */
        std::vector< std::string > values;
    };

    /**
     * This structure represents<b> Business Object</b> name, display name, and its hierarchy.
     */
    struct AvailableBusinessObjectTypeInfo
    {
        /**
         * Name of the <b>Business Object</b>
         */
        std::string type;
        /**
         * Display name of the <b>Business Object</b>
         */
        std::string displayType;
        /**
         * Bottom up hierarchy of the<b> Business Object</b> going up to the input <b>Business
         * Object</b>
         */
        std::vector< std::string > hierarchies;
    };

    /**
     * This structure contains information about a bottom up hierarchy starting with a <b>Business
     * Object </b>name and going up the hierarchy of parents up to the primary <b>Business
     * Object</b>.
     */
    struct BusinessObjectHierarchy
    {
        /**
         * Name of the <b>Business Object</b>
         */
        std::string boName;
        /**
         * Display Name of the<b> Business Object</b>
         */
        std::string boDisplayName;
        /**
         * Names of <b>Business Object</b>s going up the hierarchy of parents up to the primary
         * <b>Business Object</b>
         */
        std::vector< std::string > boParents;
    };

    /**
     * This structure contains the basic info for a file to be uploaded to a dataset.
     */
    struct CommitDatasetFileInfo
    {
        /**
         * <b>Dataset</b> object reference.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  dataset;
        /**
         * Flag to create new version ( TRUE ) or not ( FALSE ).
         */
        bool createNewVersion;
        /**
         * A list of <code>DatasetFileTicketInfos</code>.
         */
        std::vector< Teamcenter::Services::Core::_2010_04::Datamanagement::DatasetFileTicketInfo > datasetFileTicketInfos;
    };

    /**
     * Return structure for createDatasets operation
     */
    struct CreateDatasetsResponse
    {
        /**
         * List of output structure for creatDatasets operation. Each element in the list contains
         * a client Id and the related <b>Dataset</b> object created.
         */
        std::vector< Teamcenter::Services::Core::_2010_04::Datamanagement::DatasetOutput > datasetOutput;
        /**
         * Standard <code>ServiceData</code> member
         */
        Teamcenter::Soa::Client::ServiceData servData;
    };

    /**
     * Holds the basic info for a file to be uploaded to a <b>Dataset</b>.
     */
    struct DatasetFileInfo
    {
        /**
         * A unique string used to identify return data elements and partial errors associated
         * with this input structure.
         */
        std::string clientId;
        /**
         * Name of file to be uploaded.  Filename only, should not contain path to filename.
         */
        std::string fileName;
        /**
         * Named Reference relation to file.
         */
        std::string namedReferenceName;
        /**
         * Flag to indicate if file is text ( TRUE ) or binary (FALSE ).
         */
        bool isText;
        /**
         * Flag to indicate if file can be overwritten ( TRUE ) or not ( FALSE ).
         */
        bool allowReplace;
    };

    /**
     * This structure contains the basic info for a file to be uploaded to a dataset.
     */
    struct DatasetFileTicketInfo
    {
        /**
         * Member of type <b>DatasetFileInfo</b>.
         */
        Teamcenter::Services::Core::_2010_04::Datamanagement::DatasetFileInfo datasetFileInfo;
        /**
         * ID of ticket.
         */
        std::string ticket;
    };

    /**
     * The DatasetInfo struct represents all of the data necessary to construct the <b>Dataset</b>
     * object.  The basic attributes that required are passed as named elements in the struct.
     * All other attributes are passed as name/value pairs in the AttributeInfo struct.
     * The nrObjectInfos field allows for the attachment of an object that will be related
     * to this newly created <b>Dataset</b>.
     */
    struct DatasetInfo
    {
        /**
         * A unique string used to identify return data elements and partial errors associated
         * with this input structure.
         */
        std::string clientId;
        /**
         * Name attribute value
         */
        std::string name;
        /**
         * Description attribute value
         */
        std::string description;
        /**
         * Type attribute value
         */
        std::string type;
        /**
         * ID attribute value
         */
        std::string datasetId;
        /**
         * Revision attribute value
         */
        std::string datasetRev;
        /**
         * Name of the <b>Tool</b> used to open the created <b>Dataset</b>, may be an empty
         * string.
         */
        std::string toolUsed;
        /**
         * List of attribute name values pairs to be set
         */
        std::vector< Teamcenter::Services::Core::_2010_04::Datamanagement::AttributeInfo > attrs;
        /**
         * List of  info of the files to be uploaded
         */
        std::vector< Teamcenter::Services::Core::_2010_04::Datamanagement::DatasetFileInfo > datasetFileInfos;
        /**
         * list of info of named references of the <b>Dataset</b>
         */
        std::vector< Teamcenter::Services::Core::_2010_04::Datamanagement::NamedReferenceObjectInfo > nrObjectInfos;
        /**
         * Object reference of the container used to hold the created <b>Dataset</b>
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  container;
        /**
         * Name of the relation type for the <b>Dataset</b> to be created
         */
        std::string relationType;
    };

    /**
     * This structure contains return data from <code>createDatasets</code> operation.
     */
    struct DatasetOutput
    {
        /**
         * Identifier defined by user to track the input criteria.
         */
        std::string clientId;
        /**
         * <b>Dataset</b> object reference of the created dataset
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  dataset;
        /**
         * List of <code>CommitDatasetFileInfos</code>
         */
        std::vector< Teamcenter::Services::Core::_2010_04::Datamanagement::CommitDatasetFileInfo > commitInfo;
    };

    /**
     * This structure contains a list of displayable business objects (BO) under a given
     * BO(displayable sub-BO hierarchy).
     */
    struct DisplayableBusinessObjectsOut
    {
        /**
         * The Business Object name for which displayable Hierarchy is returned.
         */
        std::string boTypeName;
        /**
         * Displayable BO hierarchy
         */
        std::vector< Teamcenter::Services::Core::_2010_04::Datamanagement::BusinessObjectHierarchy > displayableBOTypeNames;
    };

    /**
     * Structure to hold list of Business Objects and its displayable names.
     */
    struct DisplayableSubBusinessObjectsResponse
    {
        /**
         * List of displayable Business Objects.
         */
        std::vector< Teamcenter::Services::Core::_2010_04::Datamanagement::DisplayableBusinessObjectsOut > output;
        /**
         * The Service data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Returned service response structure to represents the displayable Business Objects
     * information.
     */
    struct GetAvailableBusinessObjectTypesResponse
    {
        /**
         * A map of <b>Business Object </b>names and associated descendant Business Objects
         * (<b>string, vector<AvailableBusinessObjectTypeInfo>></b>)
         */
        BusinessObjectClassToTypesMap inputClassToTypes;
        /**
         * The ServiceData.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Holds the Response data from getDatasetCreationRelatedInfo2
     */
    struct GetDatasetCreationRelatedInfoResponse2
    {
        /**
         * List of <b>Tool</b> names
         */
        std::vector< std::string > toolNames;
        /**
         * List of <b>Tool</b> display names.
         */
        std::vector< std::string > toolDisplayNames;
        /**
         * The name of the new <b>Dataset</b>, can be an empty string
         */
        std::string newDatasetName;
        /**
         * If true, the name of the <b>Dataset</b> can be modified
         */
        bool nameCanBeModified;
        /**
         * List of properties have the initialized values from property constant attachments
         */
        std::vector< std::string > initValuePropertyRules;
        /**
         * Standard <code>ServiceData</code> member
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This data structure contains property names and boolean value to indicate whether
     * this property is localizable.
     */
    struct LocalizableResults
    {
        /**
         * Internal property name.
         */
        std::string propName;
        /**
         * boolean value to indicate localizability of this property.
         */
        bool islocalizable;
    };

    /**
     * This data structure contains the type of the business object and its internal property
     * names.
     */
    struct LocalizableStatusInput
    {
        /**
         * String Object Type Name
         */
        std::string objTypeName;
        /**
         * A list of the internal property names of the object.
         */
        std::vector< std::string > propNames;
    };

    /**
     * This structure contains object type name and localizable information.
     */
    struct LocalizableStatusOutput
    {
        /**
         * Object Type Name
         */
        std::string objTypeName;
        /**
         * Result containing localizable information.
         */
        std::vector< Teamcenter::Services::Core::_2010_04::Datamanagement::LocalizableResults > results;
    };

    /**
     * This data structure contains a list of localized results and <code>ServiceData</code>.
     */
    struct LocalizableStatusResponse
    {
        /**
         * A list of <code>LocalizableResults</code> structure to hold the localizable information
         * for all properties.
         */
        std::vector< Teamcenter::Services::Core::_2010_04::Datamanagement::LocalizableStatusOutput > results;
        /**
         * <code>serviceData</code>
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This data structure contains business object tag and a list of of <code>NameValueLocaleStruct</code>
     */
    struct LocalizedPropertyValuesInfo
    {
        /**
         * The business object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  object;
        /**
         * A list of <code>NameValueLocaleStruct</code> that holds property name, value and
         * locale information.
         */
        std::vector< Teamcenter::Services::Core::_2010_04::Datamanagement::NameValueLocaleStruct > propertyValues;
    };

    /**
     * This structure contains  a list of output localized property value info and  partial
     * error.
     */
    struct LocalizedPropertyValuesList
    {
        /**
         * A list of structure LocalizedPropertyValuesInfo to keep the localized property values
         * info.
         */
        std::vector< Teamcenter::Services::Core::_2010_04::Datamanagement::LocalizedPropertyValuesInfo > output;
        /**
         * Used for storing partial error and standard service data.
         */
        Teamcenter::Soa::Client::ServiceData partialErrors;
    };

    /**
     * This structure contains information regarding named reference type value, object
     * reference, object type name and list of attribute information to set on the object.
     */
    struct NamedReferenceObjectInfo
    {
        /**
         * Identifier defined by user to track the related object.
         */
        std::string clientId;
        /**
         * Object reference of the object to attach to dataset as named reference.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  object;
        /**
         * The Named Reference from the dataset to this object, required
         */
        std::string namedReferenceName;
        /**
         * Reference Type. It is either AE_PART_OF or AE_ASSOCIATION
         */
        std::string referenceType;
    };

    /**
     * This structure contains a property name and list of possible locales.
     */
    struct NameLocaleStruct
    {
        /**
         * A property name string
         */
        std::string name;
        /**
         * A list of language locales.
         */
        std::vector< std::string > locales;
    };

    /**
     * This structure contains localization related information for property values.
     */
    struct NameValueLocaleStruct
    {
        /**
         * Property name (internal)
         */
        std::string name;
        /**
         * A list of property values
         */
        std::vector< std::string > values;
        /**
         * The name of the locale
         */
        std::string locale;
        /**
         * Sequence number
         */
        int seqNum;
        /**
         * The name of the localization status.
         * <br>
         * The status must be one of the following values:
         * <br>
         * <ul>
         * <li type="disc">for the approved status: "<i>A</i>", "<i>Approved</i>" or the version
         * of the "Approved" string for the client/server log-in locale.
         * </li>
         * <li type="disc">for the in-review status: "<i>R</i>", "<i>In Review</i>", "<i>In-Review</i>",
         * "<i>InReview</i>" or the version of the "In Review" string for the client/server
         * log-in locale.
         * </li>
         * <li type="disc">for the pending status: "<i>P</i>", "<i>Pending</i>" or the version
         * of the "Pending" string for the client/server log-in locale.
         * </li>
         * <li type="disc">for the invalid status: "<i>I</i>", "<i>Invalid</i>" or the version
         * of the "Invalid" string for the client/server log-in locale.
         * </li>
         * <li type="disc">for the master status: "<i>M</i>", "<i>Master</i>" or the version
         * of the "Master" string for the client/server log-in locale.
         * </li>
         * </ul>
         */
        std::vector< std::string > status;
        /**
         * Description of statuses used for tooltip on the user interface
         */
        std::vector< std::string > statusDesc;
        /**
         * Master value indication
         */
        bool master;
    };

    /**
     * This data structure contains business object and a list of properties and locales.
     */
    struct PropertyInfo
    {
        /**
         * The desired business object to retrieved localized property values
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  object;
        /**
         * A list of NameLocaleStruct to hold the desired properties and locales.
         */
        std::vector< Teamcenter::Services::Core::_2010_04::Datamanagement::NameLocaleStruct > propsToget;
    };




    /**
     * This operation returns sub <b>Business Object</b> names that are displayable to the
     * login user in the object creation dialog and their display names for each Primary
     * Business Object given as the input.  Returned Business Object lists have exclusions
     * of Business Objects and their secondary Business Objects as specified in the input.
     * This returns the hierarchy of displayable objects for each Business Object it returns.
     *
     * @param input
     *        A list of Business Object names and their exclusion list for which the displayable
     *        Business Objects are to be retrieved.
     *
     * @return
     *         Contains a list of BO type names to be displayed for input
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Core::_2010_04::Datamanagement::DisplayableSubBusinessObjectsResponse findDisplayableSubBusinessObjectsWithDisplayNames ( const std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::BOWithExclusionIn >& input ) = 0;

    /**
     * This operation returns <b>Business Object</b> names and their display names for each
     * primary Business Object given as the input.  Returned Business Object lists have
     * exclusions of Business Objects and their secondary Business Objects as specified
     * in the input. If any of the returned Business Objects is also a primary Business
     * Object then this operation may not return its secondary Business Objects by default.
     * In order to return its secondary Business Objects also, it is required to add this
     * Business Object name to following preference TYPE_DISPLAY_RULES_list_types_of_subclasses.
     * <br>
     * Please see the Preferences and Environment Variables Reference documentation for
     * preference TYPE_DISPLAY_RULES_list_types_of_subclasses for more information.
     * <br>
     * This is a lightweight way of getting all displayable Business Objects by name rather
     * than model object.
     * <br>
     *
     * @param classes
     *        A list of primary Business Object names and their exclusion list.
     *
     * @return
     *         A map of given base class name and its available instance types. Failure will be
     *         returned with error messages in service data.
     *
     */
    virtual Teamcenter::Services::Core::_2010_04::Datamanagement::GetAvailableBusinessObjectTypesResponse getAvailableTypesWithDisplayNames ( const std::vector< Teamcenter::Services::Core::_2007_06::Datamanagement::BaseClassInput >& classes ) = 0;

    /**
     * This operation creates a list of <b>Dataset</b> objects, sets the requested attribute
     * data, adds named references, fetches write tickets for files that will be uploaded
     * as named references and creates the specified relation type between created <b>Dataset</b>
     * and input container object. The caller needs to convert the structure members from
     * the output Core::_2010_04::Datamanagement::CommitDatasetFileInfo to the input Core::_2006_03::Filemanagement::CommitDatasetFileInfo
     * if the caller wants to use the 2010_04  version of createDatasets in combination
     * with commitDatasetFiles.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model Dataset - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of Teamcenter PLM platform.  This component defines class
     * 'Dataset' behavior.
     *
     * @param input
     *        Input list of DatasetInfo structures
     *
     * @return
     *         The created <b>Dataset</b> objects.  Created Datasets and updated container objects
     *         will be returned in the ServiceData lists of created and updated objects respectively.
     *         Any failure will be returned with clientId mapped to error message in the <code>ServiceData</code>
     *         list of partial errors.
     *
     */
    virtual Teamcenter::Services::Core::_2010_04::Datamanagement::CreateDatasetsResponse createDatasets ( const std::vector< Teamcenter::Services::Core::_2010_04::Datamanagement::DatasetInfo >& input ) = 0;

    /**
     * This operation pre-populates <b>Dataset</b> creation information, default new <b>Dataset</b>
     * name and <b>Tool</b> names, for a specified <b>Dataset</b> type.  This operation
     * is used to get all the information associates with the specified <b>Dataset</b> prior
     * to the creation operation. The returned default new <b>Dataset</b> name may be determined
     * by the parent container object.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model Dataset - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of Teamcenter PLM platform.  This component defines class
     * 'Dataset' behavior.
     *
     * @param typeName
     *        The desired <b>Dataset</b> type name
     *
     * @param parentObject
     *        The container object under which the new <b>Dataset</b> object will be created
     *
     * @return
     *         This operation returns a list of <b>Tool</b> names, <b>Tool</b> display names, default
     *         <b>Dataset</b> name, flag to modify the name, naming property rule. Partial failure
     *         message will be returned in <code>ServiceData</code>.
     *
     */
    virtual Teamcenter::Services::Core::_2010_04::Datamanagement::GetDatasetCreationRelatedInfoResponse2 getDatasetCreationRelatedInfo2 ( const std::string&  typeName,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  parentObject ) = 0;

    /**
     * Typically business object property values are returned in the locale of the current
     * session, this operation returns desired property values in any of the supported locales
     * of the Teamcenter server.  String type properties may be localized with values for
     * each supported locale, this operation will return the translated values for one or
     * more desired locales.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Retrieve the localized values for localizable property
     * <br>
     * <br>
     * </b>When running Teamcenter in language environment other than the English, user
     * wants to see the localized property value to be displayed in corresponding language
     * in the UI.   This operation can be used to fulfill this requirement. By providing
     * the desired business object, internal name of the properties, and specific locale
     * name(s), this operation will return the localized property value(s) in that particular
     * locale(s).
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model L10N framework - The framework to provide a user interface in the locale
     * of users as well as manage the product information (metadata, operation data and
     * file content) in multiple languages.
     *
     * @param info
     *        A list of desired business objects, property names, and locales to retrieve those
     *        properties in.
     *
     * @return
     *         This operation returns the requested property values in each of the requested locales
     *         or returns errors:
     *         <br>
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;38030: The property is not marked as localizable.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;38302: The specified locale is invalid.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;38041: An invalid object is being used in conjunction with
     *         the property.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;38044: The property value is not set.
     *
     */
    virtual Teamcenter::Services::Core::_2010_04::Datamanagement::LocalizedPropertyValuesList getLocalizedProperties ( const std::vector< Teamcenter::Services::Core::_2010_04::Datamanagement::PropertyInfo >& info ) = 0;

    /**
     * The operation is used to determine if string-type property is localizable or not
     * and can retrieve the localizable status for ONE or MORE properties.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Determine whether a string property is marked as localizable property
     * <br>
     * <br>
     * </b>User needs to use this service operation to determine a string property is localizable
     * first before he can add the translations to the value of this property.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model L10N framework - The framework to provide a user interface in the locale
     * of users as well as manage the product information (metadata, operation data and
     * file content) in multiple languages.
     *
     * @param inputInfo
     *        A list of business object type names and internal property names
     *
     * @return
     *         This operation returns response containing boolean value to indicate whether this
     *         property is localizable or returns errors.
     *         <br>
     *         <ul>
     *         <li type="disc">39014: The specified type does not exist
     *         </li>
     *         <li type="disc">39021: Error occurred finding corresponding ImanType
     *         </li>
     *         <li type="disc">74521: Error getting Property Constant value
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           
     * @deprecated
     *         As of Teamcenter 9, the isLocalizable information is part of propertydescriptor.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 9, the isLocalizable information is part of propertydescriptor."))
#endif
    virtual Teamcenter::Services::Core::_2010_04::Datamanagement::LocalizableStatusResponse isPropertyLocalizable ( const std::vector< Teamcenter::Services::Core::_2010_04::Datamanagement::LocalizableStatusInput >& inputInfo ) = 0;

    /**
     * This operation allows user to set or modify the display values for a localized property
     * on a single object. This sets the property values for a single property on an object
     * in different locales. With the display values capability, each localized string property
     * could have different language translations associated with that.
     * <br>
     * <br>
     * Please be aware of the following:
     * <br>
     * <ul>
     * <li type="disc">This operation is only used to set the secondary (not the master)
     * values of the localized property. User can still package the master value (with localization
     * status marked as "<i>M</i>") in the <code>LocalizedPropertyValuesInfo</code> structure,
     * however, the operation will ignore and skip the master value during the process.
     * </li>
     * <li type="disc">This operation is only used to set the localization values for one
     * property. If you want to set the localized values for multiple properties, please
     * use operation <code>setLocalizedPropertyValues</code>().
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model L10N framework - The framework to provide a user interface in the locale
     * of users as well as manage the product information (metadata, operation data and
     * file content) in multiple languages.
     *
     * @param info
     *        The business object and a list of the property name, value and locale of the property
     *        value.
     *
     * @return
     *         This operation returns Service data containing any partial error.
     *         <br>
     *         <ul>
     *         <li type="disc"><b>38015</b>: Unable to find a property with name %1$.
     *         </li>
     *         <li type="disc"><b>38040</b>: Invalid property descriptor tag.
     *         </li>
     *         <li type="disc"><b>38041</b>: An invalid object instance tag is being used in conjunction
     *         with property %1$
     *         </li>
     *         <li type="disc"><b>38043</b>: Unable to get value from a pomattribute for property
     *         %1$
     *         </li>
     *         <li type="disc"><b>38300</b>: The property is not marked as localizable.
     *         </li>
     *         <li type="disc"><b>38303</b>: The translation is out-of-index for the multi-valued
     *         property.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData setLocalizedProperties ( const Teamcenter::Services::Core::_2010_04::Datamanagement::LocalizedPropertyValuesInfo&  info ) = 0;

    /**
     * Sets the property values for multiple properties on a single object in different
     * locales. With the display values capability, each localized string property could
     * have different language translations associated with that. This operation allows
     * user to set or modify the display values for the localized properties on a single
     * object.
     * <br>
     * <br>
     * It should be noted that this operation is only used to set the secondary (not the
     * master) values of the localized properties. User can still package the master value
     * (with localization status marked as "<i>M</i>") in the <code>LocalizedPropertyValuesInfo</code>
     * structure, however, the operation will ignore and skip these master values during
     * the process.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model L10N framework - The framework to provide a user interface in the locale
     * of users as well as manage the product information (metadata, operation data and
     * file content) in multiple languages.
     *
     * @param info
     *        A list of business object, the property name, value and locale of the property value.
     *
     * @return
     *         This operation returns Service data containing any partial error.
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">7007:   Invalid Tag - the requested object does not exist
     *         </li>
     *         <li type="disc">38022: The Object type is invalid for property
     *         </li>
     *         <li type="disc">38040: Invalid property descriptor tag.
     *         </li>
     *         <li type="disc">38046: Cannot perform requested operation on non-multi-valued property.
     *         </li>
     *         <li type="disc">38300: The property is not marked as localizable.
     *         </li>
     *         <li type="disc">38303: The translation is out-of-index for the multi-valued property.
     *         </li>
     *         <li type="disc">51021: The VLA string length %1$ exceeds the allowed maximum length
     *         of %2$ characters. Excess data will be truncated.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData setLocalizedPropertyValues ( const std::vector< Teamcenter::Services::Core::_2010_04::Datamanagement::LocalizedPropertyValuesInfo >& info ) = 0;


protected:
    virtual ~Datamanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/core/Core_undef.h>
#endif

