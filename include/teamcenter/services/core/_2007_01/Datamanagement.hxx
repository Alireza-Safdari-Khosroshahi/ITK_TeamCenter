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

#ifndef TEAMCENTER_SERVICES_CORE__2007_01_DATAMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_CORE__2007_01_DATAMANAGEMENT_HXX

#include <teamcenter/soa/client/model/Dataset.hxx>
#include <teamcenter/soa/client/model/Folder.hxx>
#include <teamcenter/soa/client/model/Item.hxx>
#include <teamcenter/soa/client/model/ItemRevision.hxx>
#include <teamcenter/soa/client/model/ListOfValues.hxx>
#include <teamcenter/soa/client/model/WorkspaceObject.hxx>
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
            namespace _2007_01
            {
                class Datamanagement;

class TCSOACORESTRONGMNGD_API Datamanagement
{
public:

    struct CreateFormsOutput;
    struct CreateOrUpdateFormsResponse;
    struct FormAttributesInfo;
    struct FormInfo;
    struct FormPropDescriptor;
    struct GenerateUIDResponse;
    struct GetDatasetCreationRelatedInfoResponse;
    struct GetItemCreationRelatedInfoResponse;
    struct GetItemFromIdInfo;
    struct GetItemFromIdItemOutput;
    struct GetItemFromIdItemRevOutput;
    struct GetItemFromIdPref;
    struct GetItemFromIdResponse;
    struct MoveToNewFolderInfo;
    struct MoveToNewFolderResponse;
    struct RelationFilter;
    struct SaveAsNewItemInfo;
    struct SaveAsNewItemOutput;
    struct SaveAsNewItemResponse;
    struct VecStruct;
    struct WhereReferencedInfo;
    struct WhereReferencedOutput;
    struct WhereReferencedResponse;
    struct WhereUsedOutput;
    struct WhereUsedParentInfo;
    struct WhereUsedResponse;

    /**
     * A map of <code>InputToNewItem</code> <code>(string, SaveAsNewItemOutput</code>).
     */
    typedef std::map< std::string, SaveAsNewItemOutput > InputToNewItemMap;

    /**
     * A map of attribute names and desired value pairs (string/VecStruct).
     */
    typedef std::map< std::string, VecStruct > NameValueMap;

    /**
     * Map of string array property names to values (<code>string, vector<string></code>).
     */
    typedef std::map< std::string, std::vector< std::string > > StringArrayMap;

    /**
     * This structure contains newly created form or updated form information.
     */
    struct CreateFormsOutput
    {
        /**
         * Identifier that helps the client to track the object(s) created or updated.
         */
        std::string clientId;
        /**
         * The <b>Form</b> object created or updated
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  form;
    };

    /**
     * Holds the Response of created or updated <b>Forms</b>
     */
    struct CreateOrUpdateFormsResponse
    {
        /**
         * List of created or updated <b>Form</b> objects
         */
        std::vector< Teamcenter::Services::Core::_2007_01::Datamanagement::CreateFormsOutput > outputs;
        /**
         * Standard <code>ServiceData</code> member
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure contains the Form Attributes Information.
     */
    struct FormAttributesInfo
    {
        /**
         * <b>Form</b> Type
         */
        std::string formType;
        /**
         * A list of property descriptors
         */
        std::vector< Teamcenter::Services::Core::_2007_01::Datamanagement::FormPropDescriptor > formPDs;
    };

    /**
     * Holds the Information of <b>Form</b> to be created or updated
     */
    struct FormInfo
    {
        /**
         * Identifier that helps the client to track the object(s) created, required; should
         * be unique for the input set
         */
        std::string clientId;
        /**
         * The <b>Form</b> object, if null then create; otherwise, update.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  formObject;
        /**
         * Parent object of the <b>Form</b> to be created
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  parentObject;
        /**
         * Relation name between Parent and <b>Form</b> to be created
         */
        std::string relationName;
        /**
         * If true, save the <b>Form</b> to database
         */
        bool saveDB;
        /**
         * Name of the <b>Form</b> to be created
         */
        std::string name;
        /**
         * Description of the Form to be created, can be an empty string.
         */
        std::string description;
        /**
         * <b>Form</b> Type of the <b>Form</b> to be created
         */
        std::string formType;
        /**
         * <b>Form</b> property map for the <b>Form</b> to be updated
         */
        StringArrayMap attributesMap;
    };

    /**
     * This structure contains information for Form Properties Descriptor.
     */
    struct FormPropDescriptor
    {
        /**
         * Propety name
         */
        std::string propName;
        /**
         * Property display name
         */
        std::string displayName;
        /**
         * Property value type
         */
        int propValueType;
        /**
         * Property type
         */
        int propType;
        /**
         * true if property is displayable, otherwise false
         */
        bool isDisplayable;
        /**
         * true if property is an array, otherwise false
         */
        bool isArray;
        /**
         * List of values
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ListOfValues>  lov;
        /**
         * true if propety is required, otherwise false
         */
        bool isRequired;
        /**
         * true if property is enabled, otherwise false
         */
        bool isEnabled;
        /**
         * true if Property is Modifiable
         */
        bool isModifiable;
        /**
         * Attached specifier
         */
        int attachedSpecifier;
        /**
         * Property maximumlLength
         */
        int maxLength;
        /**
         * A list of interdependent properties
         */
        std::vector< std::string > interdependentProps;
    };

    /**
     * Return structure for <code>generateUID</code> operation
     */
    struct GenerateUIDResponse
    {
        /**
         * List of the UIDs that were generated
         */
        std::vector< std::string > uids;
        /**
         * Contains any errors encountered during processing in the partial errors list.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Holds the Response data from getDatasetCreationRelatedInfo
     */
    struct GetDatasetCreationRelatedInfoResponse
    {
        /**
         * List of <b>Tool</b> names
         */
        std::vector< std::string > toolNames;
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
     * This data structure contains a naming rules, property rules, form property descriptor,
     * unit of measure, and <b>ItemRevision</b> type. Partial failure message will be returned
     * in <code>ServiceData</code>.
     */
    struct GetItemCreationRelatedInfoResponse
    {
        /**
         * List of complex value property rules
         */
        std::vector< std::string > complexValuePropertyRules;
        /**
         * List of initial values
         */
        std::vector< std::string > initValuePropertyRules;
        /**
         * Pattern map (string/string)
         */
        StringArrayMap patternMap;
        /**
         * List of unit of measures
         */
        std::vector< std::string > uoms;
        /**
         * List of <b>Form</b> attributes
         */
        std::vector< Teamcenter::Services::Core::_2007_01::Datamanagement::FormAttributesInfo > formAttrs;
        /**
         * <b>ItemRevision</b> type name
         */
        std::string revTypeName;
        /**
         * The successful object ids, partial errors and failures
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Input structure for getItemFromIdInfo, each of which contain an item id and optionally
     * a list of revision ids which specify which Item Revisions to retrieve.
     */
    struct GetItemFromIdInfo
    {
        /**
         * Item id string for Item to retrieve, required
         */
        std::string itemId;
        /**
         * Revision ids which specify which Item Revisions to retrieve, optional
         */
        std::vector< std::string > revIds;
    };

    /**
     * This structure contains information for <code>getItemFromId</code> operation.
     */
    struct GetItemFromIdItemOutput
    {
        /**
         * <b>Item</b> object reference of the item found
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Item>  item;
        /**
         * List of <code>GetItemFromIdItemRevOutput</code>
         */
        std::vector< Teamcenter::Services::Core::_2007_01::Datamanagement::GetItemFromIdItemRevOutput > itemRevOutput;
    };

    /**
     * This structure contains an <b>ItemRevision</b> object and a list of found <b>Dataset</b>
     * objects.
     */
    struct GetItemFromIdItemRevOutput
    {
        /**
         * <b>ItemRevision</b> object reference of the item revision found
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  itemRevision;
        /**
         * List of <b>Dataset</b> object references found
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  > datasets;
    };

    /**
     * Input structure for <code>getItemFromAttribute</code> used to filter the returned
     * <b>ItemRevision</b> objects.
     */
    struct GetItemFromIdPref
    {
        /**
         * A list of <code>RelationFilter</code> structures for determining which <b>ItemRevision</b>
         * objects to return
         */
        std::vector< Teamcenter::Services::Core::_2007_01::Datamanagement::RelationFilter > prefs;
    };

    /**
     * Return structure for getItemFromId operation
     */
    struct GetItemFromIdResponse
    {
        /**
         * List of GetItemFromIdItemOutput
         */
        std::vector< Teamcenter::Services::Core::_2007_01::Datamanagement::GetItemFromIdItemOutput > output;
        /**
         * Standard ServiceData member
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Input structure for the <code>moveToNewFolder</code> operation.
     * <br>
     */
    struct MoveToNewFolderInfo
    {
        /**
         * Folder object reference of the old folder, whose content is going to move to new
         * folder.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Folder>  oldFolder;
        /**
         * Folder object reference of the new folder, where object content is going to move,
         * required. If not specified, processing will continue to the new input.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Folder>  newFolder;
        /**
         * List of object references to be moved from the old folder to the new folder or copied
         * to the new folder, required. If not specified, processing will continue to the next
         * input.
         * <br>
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > objectsToMove;
    };

    /**
     * Return structure for the <code>moveToNewFolder</code> operation.
     * <br>
     */
    struct MoveToNewFolderResponse
    {
        /**
         * Contains the updated old folder, the new folder, and partial errors from this operation.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * A filter for determining which <b>ItemRevision</b> objects to return.
     */
    struct RelationFilter
    {
        /**
         * The  relation type name that specifies the relation that relates the <b>ItemRevision</b>
         * to the <b>Dataset</b>.
         */
        std::string relationTypeName;
        /**
         * A list of  <b>Dataset</b> object type names to return
         */
        std::vector< std::string > objectTypeNames;
    };

    /**
     * Input structure for saveAsNewItem operation
     */
    struct SaveAsNewItemInfo
    {
        /**
         * Used to uniquely identify the input (Required)
         */
        std::string clientId;
        /**
         * Original Item Revision to be used for the SaveAsNewItem operation (Required)
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  itemRevision;
        /**
         * Item id string for creating new item, optional
         */
        std::string itemId;
        /**
         * Revision id string for creating new revision, optional
         */
        std::string revId;
        /**
         * Name string for creating new item/revision, optional
         */
        std::string name;
        /**
         * Description string for creating new item/revision, optional
         */
        std::string description;
        /**
         * Folder object reference to attach Item to, if null, the Item will go to the default
         * preference location for created objects.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Folder>  folder;
    };

    /**
     * The data strucutre contains newly created object inforamtiobn.
     */
    struct SaveAsNewItemOutput
    {
        /**
         * New <b>Item</b> object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Item>  item;
        /**
         * New <b>ItemRevision</b> object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  itemRev;
    };

    /**
     * The data structure contains return information for the operation.
     */
    struct SaveAsNewItemResponse
    {
        /**
         * Map whose keys are the input clientIds and output values (newly created <b>Item</b>
         * and <b>ItemRevision</b> objects) pairs (<code>string</code>, <code>SaveAsNewItemOutput</code>)
         */
        InputToNewItemMap inputToNewItem;
        /**
         * Service data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure contains string list.
     */
    struct VecStruct
    {
        /**
         * A list of strings
         */
        std::vector< std::string > stringVec;
    };

    /**
     * This data structure contains output information of referencer, relation and level.
     */
    struct WhereReferencedInfo
    {
        /**
         * <b>WorkspaceObject</b> that references the input object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  referencer;
        /**
         * String name of the relation between the reference and the input object
         */
        std::string relation;
        /**
         * Level at which referencer was found.
         */
        int level;
    };

    /**
     * This data structure contains output information of reference, relation name and level
     * for given input objects.
     */
    struct WhereReferencedOutput
    {
        /**
         * <b>WorkspaceObject</b> that is referenced by info
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  inputObject;
        /**
         * Output information containing reference, relation name and level for <code>inputObject</code>
         */
        std::vector< Teamcenter::Services::Core::_2007_01::Datamanagement::WhereReferencedInfo > info;
    };

    /**
     * This data structure contains output information for a list of where referenced objects.
     */
    struct WhereReferencedResponse
    {
        /**
         * List of information containing reference, relation name and level for input object
         */
        std::vector< Teamcenter::Services::Core::_2007_01::Datamanagement::WhereReferencedOutput > output;
        /**
         * Service data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure contains information for <code>WhereUsedOutput</code>.
     */
    struct WhereUsedOutput
    {
        /**
         * Input <b>WorkspaceObject</b> object reference for mapping to the output
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  inputObject;
        /**
         * List of <code>WhereUsedParentInfo</code> structures
         */
        std::vector< Teamcenter::Services::Core::_2007_01::Datamanagement::WhereUsedParentInfo > info;
    };

    /**
     * This structure contains Generic Parent Info.
     */
    struct WhereUsedParentInfo
    {
        /**
         * Parent <b>ItemRevision</b> object reference which uses the given object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  parentItemRev;
        /**
         * The level at which the parent <b>ItemRevision</b> was found
         */
        int level;
    };

    /**
     * <code>WhereUsedResponse</code> contains list of <code>WhereUsedOutput</code>  structure.
     * This structure contains list of <b>Item</b> and <b>ItemRevision</b> objects which
     * are results of <code>whereUsed</code> search.
     */
    struct WhereUsedResponse
    {
        /**
         * List of WhereUsedOutput structures
         */
        std::vector< Teamcenter::Services::Core::_2007_01::Datamanagement::WhereUsedOutput > output;
        /**
         * Standard <code>ServiceData</code> member
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * This operation is to support updating list of objects with the given property names
     * and values. All the objects updated with same set of property and values data.  Also
     * see  Teamcenter::Soa::Core::2010_09::<b>setProperties</b> operation.
     * <br>
     * Note: Objects are saved as a part of this operation itself.
     *
     * @param objects
     *        List of Business Objects for which the properties values to be set.
     *
     * @param attributes
     *        A map of attribute names and desired value pairs (string/VecStruct). The <code>VecStruct</code>
     *        is a list of strings to support both single valued and multivalued properties of
     *        any type. The calling client is responsible for converting the different property
     *        types (like integer, double, date etc...) to a string using the appropriate toXXXString
     *        functions in the SOA client frameworks Property class.
     *
     * @return
     *         Each updated Business Object is added to the Updated list of the ServiceData. If
     *         property name is missing, error 214121 is returned as a Partial Error. If setting
     *         of property value(s) fails , error 214114 is returned as a Partial Error. The corresponding
     *         Business Objects from the input is attached to the Partial Error.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData setProperties ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& objects,
        const NameValueMap&  attributes ) = 0;

    /**
     * This function returns a number of Teamcenter UIDs generated from the Teamcenter server.
     * This operation can be used for assigning unique identifiers to objects that will
     * not be stored in Teamcenter or for objects which have yet to be created in Teamcenter.
     * <br>
     * <br>
     * The <code>createObjects</code> and <code>createOrUpdateParts</code> operations will
     * support input of a preallocated UID for use during creation. Please see those operation
     * descriptions for further details.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * The integration create workflow requires data to be precreated and stored outside
     * of Teamcenter and then used during the Teamcenter create process. For example, generating
     * a UID for an <b>ItemRevision</b> object and then storing that UID in the CAD integration
     * data file. The UID is then used as input to the create SOA operation and that UID
     * is assigned to the created object.
     * <br>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createOrUpdateParts, createObjects
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model CXPOM - Provides a (sparse) set of functions for the interface of C++
     * on POM.
     *
     * @param nUID
     *        The number of UIDs to be generated.
     *
     * @return
     *         Response contains generated UID strings and error information in <code>ServiceData</code>.
     *         <br>
     *
     */
    virtual Teamcenter::Services::Core::_2007_01::Datamanagement::GenerateUIDResponse generateUID ( int nUID ) = 0;

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
     *        desired <b>Dataset</b> type name
     *
     * @param parentObject
     *        The containe object under which the new <b>Dataset</b> object will be created
     *
     * @return
     *         This operation returns a list of <b>Tool</b>, default <b>Dataset</b> name, flag to
     *         modify the name, naming property rule. Partial failure messages will be returned
     *         in <code>ServiceData</code>.
     *
     */
    virtual Teamcenter::Services::Core::_2007_01::Datamanagement::GetDatasetCreationRelatedInfoResponse getDatasetCreationRelatedInfo ( const std::string&  typeName,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  parentObject ) = 0;

    /**
     * The <code>moveToNewFolder</code> operation moves a set of objects from one folder
     * to another. This operation allows for moving multiple sets of objects to and from
     * different folders. If no old folder is specified, this operation adds the objects
     * to the new folder.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <ul>
     * <li type="disc">The user selects an object or group of objects and specifies the
     * folder for the objects to be copied into.
     * </li>
     * <li type="disc">The user selects an object or group of objects, removes them from
     * a specified folder and specifies the folder for the objects to be copied into.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model Folder - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of Teamcenter PLM platform. This component covers Folders.
     *
     * @param moveToNewFolderInfos
     *        A list of <code>MoveToNewFolderInfo</code> structures each containing an old <b>Folder</b>
     *        object a new <b>Folder</b> object, and a vector of objects to be moved from the old
     *        folder to the new folder
     *
     * @return
     *         Response contains <code>ServiceData</code> which contains folders that were updated
     *         by the operation. Any failure will be returned via <code>ServiceData</code> with
     *         moved object mapped to error message.
     *         <br>
     *
     */
    virtual Teamcenter::Services::Core::_2007_01::Datamanagement::MoveToNewFolderResponse moveToNewFolder ( const std::vector< Teamcenter::Services::Core::_2007_01::Datamanagement::MoveToNewFolderInfo >& moveToNewFolderInfos ) = 0;

    /**
     * This operation creates <b>Form</b> objects or update existing <b>Form</b> objects
     * using the info provided. A new <b>Form</b> will be associated to the container object
     * with specified relation type. The properties of the existing <b>Form</b> will be
     * updated.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model Form - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of our PLM platform. This component covers Forms .
     *
     * @param info
     *        Input for creating or updating <b>Form</b> objects
     *
     * @return
     *         Containing newly created or updated <b>Form</b> objects. Any failure will be returned
     *         with clientId mapped to error message in the <code>ServiceData</code> list of partial
     *         errors. The error code can be one of the follows:
     *         <br>
     *         <ul>
     *         <li type="disc">525084: User does not have write privilege to the container object
     *         </li>
     *         <li type="disc">Others: error code from <b>Folder</b> creation
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Core::_2007_01::Datamanagement::CreateOrUpdateFormsResponse createOrUpdateForms ( const std::vector< Teamcenter::Services::Core::_2007_01::Datamanagement::FormInfo >& info ) = 0;

    /**
     * This operation will return naming rules, property rule, form property descriptor,
     * unit of measurement and <b>ItemRevision</b> type name based on <b>Item</b> type selected
     * by user during <b>Item</b> creation.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model Item - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of Teamcenter PLM platform. This component defines the Item
     * Class and behavior.
     *
     * @param typeName
     *        <b>Item</b> type name
     *
     * @param parentObject
     *        <b>parentObject</b> is an unused parameter and may be null
     *
     * @return
     *         This operation returns information about complex property rules, property rules,
     *         naming rules, unit of measurement, form properties and revision type for the input
     *         <b>Item</b> type. Any errors that occur will be returned as a partial error with
     *         the source business object attached to the partial error. The following partial error
     *         may be returned:
     *         <br>
     *         <ul>
     *         <li type="disc">74521: Error getting Property Constant value
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Core::_2007_01::Datamanagement::GetItemCreationRelatedInfoResponse getItemCreationRelatedInfo ( const std::string&  typeName,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  parentObject ) = 0;

    /**
     * This operation returns Items, Item Revisions, and Dataset based on the input item
     * id. Input is a list of GetItemFromIdInfo structures each of which contain an item
     * id (GetItemFromIdInfo.itemId) and optionally a list of revision ids (GetItemFromIdInfo.revIds)
     * which specify which Item Revisions to retrieve.  Also input is and integer value
     * (nRev) which can also be used to help specify which Item Revisions to return with
     * the Item.  The final input is a GetItemFromIdPref structure which contains a list
     * of RelationFilter structures (GetItemFromIdPref.prefs) each of which contain a relation
     * type name (RelationFilter.relationTypeName) and a list of object type names (RelationFilter.objectTypeNames).
     * This filter can be used to specify which Datasets are returned.  The relation type
     * name specifies the relation that relates the Item Revision to the Dataset.  The object
     * type name is the type of Dataset to return.  For example, if relationTypeName is
     * "IMAN_reference" and the object type name is "Text" then only those Datasets of type
     * "Text" that are related to candidate Item Revisions with the "IMAN_reference" relation
     * will be returned.  Supplying no value or an empty value for the rev id list and 0
     * for nRevs will signify the return of no Item Revisions, and thus no Datasets will
     * be returned either.  Supplying no value or an empty value for the rev id list and
     * a negative value for nRevs will signify the return of all Item Revisions.   Supplying
     * no value or an empty value for the rev id list and a positive value for nRev will
     * signify the return of the latest number of Item Revisions specified by the integer--if
     * the number of actual revisions found is greater than the input nRev, all revisions
     * for the found Item will be returned. Supplying a rev id list will only return those
     * revisions, and the nRev value will not be processed. For example, if the input rev
     * Id is "A" and the nRev value is 0, only revision "A" will be returned. If the rev
     * id list is empty and nRevs = 5, then the 5 latest Item Revisions will be returned.
     * If no preference filter is specified, all Datasets will be returned.  The return
     * is a GetItemFromIdResponse which contains a list of GetItemFromIdItemOutput (GetItemFromIdResponse.output
     * and a ServiceData (GetItemFromIdResponse.serviceData).  Each GetItemFromIdItemOutput
     * contains an Item (GetItemFromIdItemOutput.item) and a list of GetItemFromIdItemRevOutput
     * structures (GetItemFromIdItemOutput.itemRevOutput).  Each GetItemFromIdItemRevOutput
     * structure contains an Item Revision (GetItemFromIdItemRevOutput.itemRevision) and
     * a list of found Datasets (GetItemFromIdItemRevOutput.datasets).
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model Item - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of Teamcenter PLM platform. This component defines the Item
     * Class and behavior.
     *
     * @param infos
     *        list of GetItemFromIdInfo structures
     *
     * @param nRev
     *        value for the latest number of Item Revisions to return
     *
     * @param pref
     *        GetItemFromIdPref structure for relation and types filtering
     *
     * @return
     *         contains found item, its item revisions and the datasets attached to the revision.
     *         Partial Errors will be returned as a map of input item id to error message.
     *
     * @deprecated
     *         As of Tc 8, use the getItemAndRelatedObjects operation.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Tc 8, use the getItemAndRelatedObjects operation."))
#endif
    virtual Teamcenter::Services::Core::_2007_01::Datamanagement::GetItemFromIdResponse getItemFromId ( const std::vector< Teamcenter::Services::Core::_2007_01::Datamanagement::GetItemFromIdInfo >& infos,
        int nRev,
        const Teamcenter::Services::Core::_2007_01::Datamanagement::GetItemFromIdPref&  pref ) = 0;

    /**
     * This operation creates a new <b>Item</b> object and <b>ItemRevision</b> object from
     * an existing <b>ItemRevision</b> object.  The master form properties may be supplied
     * for the new <b>ItemRevision</b> and item master form objects.  If master form data
     * is not supplied the master forms will be initialized from the master forms attached
     * to the existing <b>ItemRevision</b>.  Deep Copy rules may also be supplied to override
     * the default Deep Copy rules.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model Item - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of Teamcenter PLM platform. This component defines the Item
     * Class and behavior.
     *
     * @param info
     *        The necessary information to create the new <b>Item</b> and <b>ItemRevision</b>
     *
     * @return
     *         This operation returns information containing a list of new objects in the <code>Create</code>
     *         list and a list of mapping the input revision to the new <b>Item</b> and <b>ItemRevision</b>.
     *
     *
     * @exception ServiceException
     *           
     * @deprecated
     *         As of Tc 8, use the saveAsNewItem2 operation.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Tc 8, use the saveAsNewItem2 operation."))
#endif
    virtual Teamcenter::Services::Core::_2007_01::Datamanagement::SaveAsNewItemResponse saveAsNewItem ( const std::vector< Teamcenter::Services::Core::_2007_01::Datamanagement::SaveAsNewItemInfo >& info ) = 0;

    /**
     * This operation finds the objects and relations that reference a given object.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User selects an object, specifies the number of levels (or all) of referencers to
     * return and executes a where referenced query.
     * <br>
     * <br>
     * For example, the user selects a <b>Dataset</b> which has a specification relation
     * to an Item and is contained in the users <b>Home</b> folder. The Item is contained
     * in the user <b>Newstuff</b> folder and in the view folder of another Item Revision.
     * If the user selects level 2, the Item and <b>Home</b> folder would be returned at
     * level 1 and the <b>Newstuff</b> folder and view folder of the other <b>ItemRevision</b>
     * would be returned at level 2.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model Method Layer - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of our PLM platform. This component defines basic method
     * structure.
     *
     * @param objects
     *        List of <b>WorkspaceObject</b> references to find referencers for. If an element
     *        in the list is null a partial error is returned, and processing on the remaining
     *        objects continues.,
     *        <br>
     *
     * @param numLevels
     *        Number of levels to traverse to find the referencers. For example, if A references
     *        B, and B references C, a 1 level search from C produces just B, but a 2 level search
     *        produces both A and B. If neg 1, all levels are returned.
     *        <br>
     *
     * @return
     *         The found business objects referencing each input object, the level at which it was
     *         found and the relation to between the two (if any). The following partial errors
     *         may be returned with the source input object attached to the partial error:
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">214110 The input object is not valid.
     *         </li>
     *         <li type="disc">214111 Where Referenced operation failed.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Core::_2007_01::Datamanagement::WhereReferencedResponse whereReferenced ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  >& objects,
        int numLevels ) = 0;

    /**
     * This operation is used to reload the in-memory representation of the objects from
     * the database. Any references to the object will still be valid. Any in-memory changes
     * to the original object will be lost. If the object has been changed in the database
     * since it was last loaded, then those changes will not be present in memory. The operation
     * updates the in memory representation to reflect database changes and does not obtain
     * write lock on any objects.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Use this operation to reload the in-memory representation of one or more objects
     * from the Teamcenter database.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model Types - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of Teamcenter PLM platform. This component defines Types
     * framework.
     *
     * @param objects
     *        A list of object to be refreshed
     *
     * @return
     *         This operation returns service data containing the objects that were successfully
     *         refreshed or partial error message if any. The following error may be returned:
     *         <br>
     *         <ul>
     *         <li type="disc">515024: The given object does not exist in the database or is not
     *         a persistent object.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData refreshObjects ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& objects ) = 0;

    /**
     * The <code>whereUsed</code> service identifies all the parent <b>Item</b> and <b>ItemRevision</b>
     * objects in the structure where the input <b>Item</b> or <b>ItemRevision</b> is used.
     * User can provide <b>RevisionRule</b> to search for specific <b>ItemRevision</b>.
     * By default all <b>ItemRevision</b> objects are returned. The number of levels of
     * <code>whereUsed</code> search indicates, whether to return one or top or all levels
     * of assemblies. It supports search on <b>Item</b>, <b>ItemRevision</b>  and <b>Dataset</b>.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * A user performs <code>whereUsed</code> search to find all the assemblies that contain
     * a particular <b>Item</b> or <b>ItemRevision</b>. User inputs <b>Item</b> or <b>ItemRevision</b>
     * and the search can be made with following options:
     * <br>
     * <ul>
     * <li type="disc"><b>RevisionRule</b> This can be set to All, displaying all <b>ItemRevision</b>
     * objects  that have an occurrence of target <b>ItemRevision</b>. If a specific <b>RevisionRule</b>
     * is selected only the <b>ItemRevision</b> objects  configured by the rule are returned
     * in the search.
     * </li>
     * <li type="disc">Depth up to which numbers of levels are to be returned.
     * </li>
     * </ul>
     * <br>
     * <br>
     * The output contains list of  each parent level search result in the structure.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * WhereUsed - Provides where used search capability for Item, ItemRevision, DataSet
     * and apperanceGroup objects in the database. User can apply the Rev Rule criteria
     * to filter the results for configured results.
     *
     * @param objects
     *        List of object references on which to perform the <code>whereUsed</code> search.
     *        It is a required parameter.
     *
     * @param numLevels
     *        Number of levels to traverse in the <code>whereUsed</code> search and return
     *
     * @param whereUsedPrecise
     *        Boolean representing whether to only send back precise parents ( used by <b>ItemRevision</b>
     *        specifically and not <b>Item</b>)
     *
     * @param rule
     *        <b>RevisionRule</b> used get unique configured <b>ItemRevision</b> from each level
     *        of <code>whereUsed</code> search, ignored if whereUsedPrecise = true
     *
     * @return
     *         Contains input object and for each input object, the <b>ItemRevision</b> object(s)
     *         found and the level at which it was found.
     *         <br>
     *         Failure will be returned via <code>ServiceData</code> with original input object
     *         mapped to error message.
     *         <br>
     *         214110&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The
     *         input object is not valid
     *         <br>
     *         214112&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Where
     *         Used operation failed
     *         <br>
     *         27074&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Where
     *         used functionality  is not supported for this object
     *         <br>
     *
     * @deprecated
     *         As of Teamcenter 9.1, use the whereUsed operation from the _2012_02 namespace.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 9.1, use the whereUsed operation from the _2012_02 namespace."))
#endif
    virtual Teamcenter::Services::Core::_2007_01::Datamanagement::WhereUsedResponse whereUsed ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& objects,
        int numLevels,
        bool whereUsedPrecise,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  rule ) = 0;


protected:
    virtual ~Datamanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/core/Core_undef.h>
#endif

