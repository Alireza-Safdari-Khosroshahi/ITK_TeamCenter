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

#ifndef TEAMCENTER_SERVICES_CORE__2006_03_DATAMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_CORE__2006_03_DATAMANAGEMENT_HXX

#include <teamcenter/soa/client/model/Dataset.hxx>
#include <teamcenter/soa/client/model/Folder.hxx>
#include <teamcenter/soa/client/model/Group.hxx>
#include <teamcenter/soa/client/model/ImanRelation.hxx>
#include <teamcenter/soa/client/model/Item.hxx>
#include <teamcenter/soa/client/model/ItemRevision.hxx>
#include <teamcenter/soa/client/model/User.hxx>
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
            namespace _2006_03
            {
                class Datamanagement;

class TCSOACORESTRONGMNGD_API Datamanagement
{
public:

    struct CreateDatasetsOutput;
    struct CreateDatasetsResponse;
    struct CreateFolderInput;
    struct CreateFoldersOutput;
    struct CreateFoldersResponse;
    struct CreateItemsOutput;
    struct CreateItemsResponse;
    struct CreateRelationsOutput;
    struct CreateRelationsResponse;
    struct DatasetProperties;
    struct ExtendedAttributes;
    struct GenerateItemIdsAndInitialRevisionIdsProperties;
    struct GenerateItemIdsAndInitialRevisionIdsResponse;
    struct GenerateRevisionIdsProperties;
    struct GenerateRevisionIdsResponse;
    struct ItemIdsAndInitialRevisionIds;
    struct ItemProperties;
    struct ObjectOwner;
    struct Relationship;
    struct ReviseProperties;
    struct ReviseResponse;
    struct RevisionIds;

    /**
     * A map represents the property name and display value pair.
     */
    typedef std::map< std::string, std::string > AttributeNameValueMap;

    /**
     * A map of index to <code>ItemIdsAndInitialRevisionIds</code>.
     */
    typedef std::map< int, std::vector< ItemIdsAndInitialRevisionIds > > IndexToIdMap;

    /**
     * IndexToRevIdMap
     */
    typedef std::map< int, RevisionIds > IndexToRevIdMap;

    /**
     * ItemRevMap
     */
    typedef std::map< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision> , Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  > ItemRevMap;

    /**
     * Map of <b>ItemRevision</b> to <code>ReviseProperties</code> (<code>ItemRevision</code>,
     * <code>ReviseProperties</code>).
     */
    typedef std::map< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision> , ReviseProperties > ItemRevPropertyMap;

    /**
     * This structure contains information for createDatasets operation.
     */
    struct CreateDatasetsOutput
    {
        /**
         * Identifier that helps the client to track the object(s) created.
         */
        std::string clientId;
        /**
         * <b>Dataset</b> object reference that was created
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  dataset;
    };

    /**
     * Return structure for createDatasets operation
     */
    struct CreateDatasetsResponse
    {
        /**
         * A list of created <b>Dataset</b> output
         */
        std::vector< Teamcenter::Services::Core::_2006_03::Datamanagement::CreateDatasetsOutput > output;
        /**
         * Standard <code>ServiceData</code> member
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Input structure for createFolders operation
     */
    struct CreateFolderInput
    {
        /**
         * Identifier that helps the client to track the object created, optional.
         */
        std::string clientId;
        /**
         * Name of the folder to be created, optional, if null, uses value from USER_new_folder_name
         * user exit
         */
        std::string name;
        /**
         * Description of the folder to be created, optional
         */
        std::string desc;
    };

    /**
     * This structure contains information for <code>createFolders</code> operation.
     */
    struct CreateFoldersOutput
    {
        /**
         * Identifier that helps the client to track the object created.
         */
        std::string clientId;
        /**
         * <b>Folder</b> object reference that was created
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Folder>  folder;
    };

    /**
     * Return structure for createFolders operation
     */
    struct CreateFoldersResponse
    {
        /**
         * Each element in the list contains a client Id and the related <b>Folder</b> object
         * created.
         */
        std::vector< Teamcenter::Services::Core::_2006_03::Datamanagement::CreateFoldersOutput > output;
        /**
         * Standard <code>ServiceData</code> member
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The data structure contains a list of created items and item revisions.
     */
    struct CreateItemsOutput
    {
        /**
         * Identifier that helps the client to track the object(s) created.
         */
        std::string clientId;
        /**
         * The created <b>Item</b> object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Item>  item;
        /**
         * The created <b>ItemRevision</b> object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  itemRev;
    };

    /**
     * Return structure for <code>createItems</code> operation.
     */
    struct CreateItemsResponse
    {
        /**
         * A list of the created <b>Item</b> and <b>ItemRevision</b>
         */
        std::vector< Teamcenter::Services::Core::_2006_03::Datamanagement::CreateItemsOutput > output;
        /**
         * Service data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The relations created between the primary and secondary object.
     */
    struct CreateRelationsOutput
    {
        /**
         * The unmodified value from the <code>Relationship.clientId</code>. This can be used
         * by the caller to indentify this data structure with the source input data.
         */
        std::string clientId;
        /**
         * The newly created relation.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ImanRelation>  relation;
    };

    /**
     * <code>CreateRelationsResponse</code> structure represents the relations created between
     * the primary and secondary object and errors occurred.
     */
    struct CreateRelationsResponse
    {
        /**
         * A list of created relations.
         */
        std::vector< Teamcenter::Services::Core::_2006_03::Datamanagement::CreateRelationsOutput > output;
        /**
         * Standard <code>ServiceData</code> object to hold the partial errors that the operation
         * encounters.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Input structure for createDatasets operation
     */
    struct DatasetProperties
    {
        /**
         * Identifier that helps the client to track the object(s) created, required, should
         * be unique for the input set
         */
        std::string clientId;
        /**
         * Type of the <b>Dataset</b> to be created
         */
        std::string type;
        /**
         * Name of the <b>Dataset</b> to be created
         */
        std::string name;
        /**
         * Description of the <b>Dataset</b> to be created, may be an empty string
         */
        std::string description;
        /**
         * Name of the <b>Tool</b> used to open the created <b>Dataset</b>, may be an empty
         * string.
         */
        std::string toolUsed;
        /**
         * Object reference of the container used to hold the created <b>Dataset</b>, may be
         * an empty string
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  container;
        /**
         * Name of the relation type for the <b>Dataset</b> to be created, may be an empty string.
         */
        std::string relationType;
    };

    /**
     * This structure contains information for <code>createItems</code> operation to support
     * setting attribute values on the created <b>Item</b>, <b>ItemRevision</b>, or corresponding
     * master forms that may be created with the objects.
     */
    struct ExtendedAttributes
    {
        /**
         * The type of object to set these properties on i.e. <b>Connection</b>, <b>ConnectionRevision</b>
         */
        std::string objectType;
        /**
         * A map of  attributes names and initial values pairs (<code>string/string</code>).
         * Multi-valued properties are represented with a comma separated string
         */
        AttributeNameValueMap attributes;
    };

    /**
     * The input information for <code>generateItemIdsAndInitialRevisionIds</code> operation.
     */
    struct GenerateItemIdsAndInitialRevisionIdsProperties
    {
        /**
         * <b>Item</b> object reference to use as a basis for the next <b>Item</b> ID. This
         * value is optional.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  item;
        /**
         * Type of the <b>Item</b> for which the IDs will be generated.  This value is optional.
         * The default is <i>Item</i>.
         */
        std::string itemType;
        /**
         * Total number of IDs to be generated
         */
        int count;
    };

    /**
     * Return structure for <code>generateItemIdsAndInitialRevisionIds</code> operation
     */
    struct GenerateItemIdsAndInitialRevisionIdsResponse
    {
        /**
         * A list of the new <b>Item</b> and <b>ItemRevision</b> IDs and flags indicating if
         * the system is configured to allow modification of the id values after they have been
         * generated.
         */
        IndexToIdMap outputItemIdsAndInitialRevisionIds;
        /**
         * Service data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The data structure contains information for <code>generateRevisionIds</code> operation
     */
    struct GenerateRevisionIdsProperties
    {
        /**
         * <b>Item</b> object reference to get the next revision id, optional
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  item;
        /**
         * Type of the ids to generate, optional
         */
        std::string itemType;
    };

    /**
     * The data structure contains returned information for <code>generateRevisionIds</code>
     * operation
     */
    struct GenerateRevisionIdsResponse
    {
        /**
         * A list of the new generated id values
         */
        IndexToRevIdMap outputRevisionIds;
        /**
         * Service data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure contain output information for <code>generateItemIdsAndInitialRevisionIds</code>
     * operation indicating the new item id, new revision id, and a flag for each that indicates
     * if the caller should be able to override the generated values.
     */
    struct ItemIdsAndInitialRevisionIds
    {
        /**
         * Newly generated <b>Item</b> Id
         */
        std::string newItemId;
        /**
         * Newly generated <b>ItemRevision</b> Id
         */
        std::string newRevId;
        /**
         * Flag to specify whether <b>Item</b> id is modifiable
         */
        bool isItemModify;
        /**
         * Flag to specify whether <b>ItemRevision</b> id is modifiable
         */
        bool isRevModify;
    };

    /**
     * Input structure for createItems operation.  Specifies attributes for the new <b>Item</b>
     * or <b>ItemRevision</b>.
     */
    struct ItemProperties
    {
        /**
         * Identifier that helps the client to track the object(s) created, optional.
         */
        std::string clientId;
        /**
         * Id of the <b>Item</b> to be created, optional
         */
        std::string itemId;
        /**
         * Name of the <b>Item</b> to be created, optional
         */
        std::string name;
        /**
         * Type of the <b>Item</b> to be created, optional, default is <b>Item</b>
         */
        std::string type;
        /**
         * Id of the initail revision of the <b>Item</b> to be created, optional
         */
        std::string revId;
        /**
         * Unit of measure(UOM) of the <b>Item</b> to be created, optional
         */
        std::string uom;
        /**
         * Description of the <b>Item</b> to be created, optional
         */
        std::string description;
        /**
         * Name/value pairs for additional attributes to set, optional
         */
        std::vector< Teamcenter::Services::Core::_2006_03::Datamanagement::ExtendedAttributes > extendedAttributes;
    };

    /**
     * This structure contains the business object whose owner needs to be changed, new
     * owning user of the object and new owning group of the object.
     */
    struct ObjectOwner
    {
        /**
         * Teamcenter Business object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  object;
        /**
         * New owning user of the business object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::User>  owner;
        /**
         * New owning group of the business object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Group>  group;
    };

    /**
     * <code>Relationship</code> structure represents all required parameters to create
     * the relation between the primary and secondary object.
     */
    struct Relationship
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this <code>Relationship</code> structure.
         */
        std::string clientId;
        /**
         * Name of the relation type to create, required. This could be an empty string, in
         * which case the relation name will be searched in the preference, <b>ParentTypeName_ChildTypeName_default_relation
         * </b>or<b> ParentTypeName_default_relation</b>.
         */
        std::string relationType;
        /**
         * The primary object to create the relation from
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  primaryObject;
        /**
         * The secondary object to create the relation to.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  secondaryObject;
        /**
         * The user data object used to create the relation. This parameter is optional.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  userData;
    };

    /**
     * This structure contains information about new revision id, name, description and
     * extended attributes.
     */
    struct ReviseProperties
    {
        /**
         * New revision id of the <b>Item</b> to be revised, optional
         */
        std::string revId;
        /**
         * Name of the new <b>ItemRevision</b>, optional
         */
        std::string name;
        /**
         * Description of the new <b>ItemRevision</b>, optional
         */
        std::string description;
        /**
         * Name/value pairs for additional attributes to set, optional
         */
        AttributeNameValueMap extendedAttributes;
    };

    /**
     * Return structure for revise operation
     */
    struct ReviseResponse
    {
        /**
         * A Map whose keys are the input old item revisions and values are the newly created
         * revisions
         */
        ItemRevMap oldItemRevToNewItemRev;
        /**
         * Standard ServiceData member
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure contains information for <code>generateRevisionIds</code> operation
     */
    struct RevisionIds
    {
        /**
         * Revision id that was generated
         */
        std::string newRevId;
        /**
         * Flag to specify whether revision id is modifiable
         */
        bool isModify;
    };




    /**
     * This service operation is provided to get property values of instances outside of
     * the current <b>object property policy</b> for a particular business object.  Net
     * result of this operation includes the properties expressly defined in the input attributes
     * as well as the properties defined in the current Object Property Policy.
     * <br>
     * <br>
     * This operation takes care of following:
     * <br>
     * <ul>
     * <li type="disc">Since all relations are stored as properties on the primary object,
     * this operation supports the expanding of relations.
     * </li>
     * <li type="disc">Properties in the input attribute argument that reference other objects
     * (relations) will have the properties for those referenced objects returned as defined
     * by the Object Property Policy.
     * </li>
     * </ul>
     *
     * @param objects
     *        List of attribute/property name strings for which values are needed
     *
     * @param attributes
     *        List of object references for which property values are requested
     *
     * @return
     *         Objects that successfully have properties added are returned in the ServiceData list
     *         of plain objects.  Any failures will be returned with the input object mapped to
     *         the error message in the ServiceData list of partial errors.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData getProperties ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& objects,
        const std::vector< std::string >& attributes ) = 0;

    /**
     * This operation is provided to update the Teamcenter objects for the given name/display
     * value pairs. This operation works for all supported property value types to set display
     * values. When setting this operation it invokes the server <b>PROP_UIF_set_value</b>
     * extensions. For updating an array property, display values need to be comma (,) separated
     * which server parses them into individual values before assigning.
     * <br>
     * Note:  Since LOVs support the <b>display as</b> feature where internal values of
     * the LOV can be different from displayable values, this operation expects that internal
     * value of the selection to be passed and not the display value.
     * <br>
     *
     * @param objects
     *        A list of objects for which property values need to be set
     *
     * @param attributes
     *        A map of attribute names and display values of a property  (string/string)
     *
     * @return
     *         Objects that successfully have properties set are returned in the ServiceData list
     *         of updated objects.  Any failures will be returned with the input object mapped to
     *         the error message in the ServiceData list of partial errors.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData setDisplayProperties ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& objects,
        const AttributeNameValueMap&  attributes ) = 0;

    /**
     * This operation creates a list of <b>Datasets</b> and creates the specified relation
     * between created <b>Dataset</b> and input container object.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model Dataset - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of Teamcenter PLM platform.  This component defines class
     * 'Dataset' behavior.
     *
     * @param input
     *        The information needed to create <b>Dataset</b> objects
     *        <br>
     *
     * @return
     *         This operation returns a list of CreateDatasetsOutput structures (which contain the
     *         created <b>Dataset</b> objects).  Created <b>Datasets</b> and update container objects
     *         will be returned in the <code>ServiceData</code> lists of created and updated objects
     *         respectively.  Any failure will be returned with client id mapped to error message
     *         in the <code>ServiceData</code> list of partial errors.  The error code of the failures
     *         can be any of follows:
     *         <br>
     *         <ul>
     *         <li type="disc">214122: Name or Type of the <b>Dataset</b> to be created is not provided
     *         </li>
     *         <li type="disc">525084: User does not have write privilage to the container object
     *         </li>
     *         <li type="disc">9010:  Unable to find type of <b>Dataset</b> to be created.
     *         </li>
     *         <li type="disc">9008: Specied <b>Tool</b> of the <b>Dataset</b> to be created is
     *         invaild.
     *         </li>
     *         <li type="disc">89015: Fail to create relation between the container object and the
     *         <b>Dataset</b> to be created.
     *         </li>
     *         <li type="disc">Others: Error codes from <b>Dataset</b> Creation.
     *         </li>
     *         </ul>
     *
     * @deprecated
     *         As of Tc 8, use the createDatasets2 operation.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Tc 8, use the createDatasets2 operation."))
#endif
    virtual Teamcenter::Services::Core::_2006_03::Datamanagement::CreateDatasetsResponse createDatasets ( const std::vector< Teamcenter::Services::Core::_2006_03::Datamanagement::DatasetProperties >& input ) = 0;

    /**
     * This operation creates a list of new <b>Folder</b> objects with the given names,
     * descriptions and attaches them to the parent container. If attaching a created <b>Folder</b>
     * to its parent container fails, the <b>Folder</b> will not be deleted.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model Folder - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of Teamcenter PLM platform. This component covers Folders.
     *
     * @param folders
     *        Input struture to create <b>Folder</b> Objects
     *
     * @param container
     *        The object to which all the created <b>Folder</b> objects will be related to via
     *        the input relation type, may be null.
     *
     * @param relationType
     *        The name of relation type that all created <b>Folder</b> objects will be related
     *        to the container, may be an empty string.
     *
     * @return
     *         The created <b>Folder</b> objects. The created <b>Folder</b> objects and the updated
     *         container objects will be returned in the created and updated list of the <code>ServiceData</code>.
     *         Any failures will be returned in the <code>ServiceData</code> list of partial errors.
     *         The error code can be one of the followings:
     *         <br>
     *         <ul>
     *         <li type="disc">525084: User does not have write privilege to the container object
     *         </li>
     *         <li type="disc">6010: <b>Folder</b> name is not specified (empty string)
     *         </li>
     *         <li type="disc">89015: Fail to create relation between the container object and the
     *         <b>Folder</b> to be created
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Core::_2006_03::Datamanagement::CreateFoldersResponse createFolders ( const std::vector< Teamcenter::Services::Core::_2006_03::Datamanagement::CreateFolderInput >& folders,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  container,
        const std::string&  relationType ) = 0;

    /**
     * This operation can be used to change the ownership on a given business object to
     * the given user and group.  Owning user attribute on the business object will be changed
     * to the given user and owning group attribute is changed to the given group.  The
     * user needs <b>CHANGE_OWNER</b> privilege and <b>WRITE</b> privilege on the business
     * object to be able to change its ownership.  If user does not have the required privileges
     * then this operation will return error code <b>515001</b>. If the given user is invalid
     * or given group is invalid then this operation will return error code <b>515024</b>.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Change owner menu action calls this operation.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model General - This component provides a set of generic capabilities that form
     * the very core of Teamcenter platform.
     *
     * @param input
     *        Input object to the operation that holds the business object, new owning user and
     *        new owning group.
     *
     * @return
     *         This operation returns ServiceData object.  If the object's ownership is changed
     *         successfully then the object is returned in the updated objects list in the ServiceData.
     *         Any failure will be returned with the input object mapped to the error message in
     *         the list of partial errors in the ServiceData.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData changeOwnership ( const std::vector< Teamcenter::Services::Core::_2006_03::Datamanagement::ObjectOwner >& input ) = 0;

    /**
     * This operation creates a list of <b>Items</b> and associated data (<b>ItemRevision</b>/<b>ItemMasterForm</b>/<b>ItemRevisionMasterForm</b>)
     * based on the input attribute structures and the specified relation type between created
     * <b>Item</b> and input object.  If container and relation type are not input, none
     * of the<b> Item</b>s will be related to a container. (There is no default, if any
     * destination is desired, it must be provided as input).
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model Item - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of Teamcenter PLM platform. This component defines the Item
     * Class and behavior.
     *
     * @param properties
     *        A list of properties to create new <b>Item</b> objects
     *
     * @param container
     *        The container object to which all the items will be related to via the input relation
     *        type, optional.
     *
     * @param relationType
     *        The relation type that will be used to relate the newly created <b>Item</b>s to the
     *        container, optional.
     *
     * @return
     *         The created <b>Item</b> and associated <b>ItemRevison</b> objects. The created <b>Item</b>s
     *         are included in the created list of the <code>ServiceData</code>, and the container
     *         object (if any) is added to the updated list. Any failure will be returned with client
     *         id mapped to error message in the <code>ServiceData</code> list of partial errors.
     *
     */
    virtual Teamcenter::Services::Core::_2006_03::Datamanagement::CreateItemsResponse createItems ( const std::vector< Teamcenter::Services::Core::_2006_03::Datamanagement::ItemProperties >& properties,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  container,
        const std::string&  relationType ) = 0;

    /**
     * This operation generates a list of <b>Item</b> IDs and initial <b>ItemRevision</b>
     * IDs.  The initial revision ID is defined as the first revision ID for the given type.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model Item - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of Teamcenter PLM platform. This component defines the Item
     * Class and behavior.
     *
     * @param input
     *        A list of the <b>Item</b>, <b>Item</b> type, and the number of IDs to generate.
     *
     * @return
     *         A list of new <b>Item</b> and <b>ItemRevision</b> IDs.
     *
     */
    virtual Teamcenter::Services::Core::_2006_03::Datamanagement::GenerateItemIdsAndInitialRevisionIdsResponse generateItemIdsAndInitialRevisionIds ( const std::vector< Teamcenter::Services::Core::_2006_03::Datamanagement::GenerateItemIdsAndInitialRevisionIdsProperties >& input ) = 0;

    /**
     * This operation generates a set of revision IDs.  The ID can be either the next ID
     * for an existing <b>Item</b> or the first revision ID for a new <b>Item</b>.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * revise, revise2
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model Item - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of Teamcenter PLM platform. This component defines the Item
     * Class and behavior.
     *
     * @param input
     *        A list <b>Item</b> and <b>Item</b> type
     *
     * @return
     *         The generated revision IDs.  Failures are returned with the input index into the
     *         list of <code>GenerateRevisionIdsProperties</code> mapped to the error message in
     *         the <code>ServiceData</code> list of partial errors. The following errors may be
     *         returned:
     *         <br>
     *         <ul>
     *         <li type="disc">39014: The specified type does not exist
     *         </li>
     *         <li type="disc">515009: A POM internal error has occurred. Please report it to your
     *         administrator.
     *         </li>
     *         <li type="disc">11081: The Revise function is not currently supported via Global
     *         Services.
     *         </li>
     *         <li type="disc">74029: The auto-assignment cannot generate an ID. A Naming Rule without
     *         a counter has been configured on the property. Please contact your system administrator.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Core::_2006_03::Datamanagement::GenerateRevisionIdsResponse generateRevisionIds ( const std::vector< Teamcenter::Services::Core::_2006_03::Datamanagement::GenerateRevisionIdsProperties >& input ) = 0;

    /**
     * Revises a list of next Item Revisions based on input existing Item Revision object
     * references and any additional attributes.  Uses deep copy rules to propagate existing
     * relations from the Item Revision or to create new references.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model Item - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of Teamcenter PLM platform. This component defines the Item
     * Class and behavior.
     *
     * @param input
     *        A map of Item Revisions and ReviseProperties structures
     *
     * @return
     *         is a structure which contains a map of old and new Item Revisions and the ServiceData
     *         structure.  Any failures will be returned with input Item Revision mapped to error
     *         message in the ServiceData list of partial errors.
     *
     *
     * @exception ServiceException
     *           None
     * @deprecated
     *         As of Tc 8, use the revise2 operation.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Tc 8, use the revise2 operation."))
#endif
    virtual Teamcenter::Services::Core::_2006_03::Datamanagement::ReviseResponse revise ( const ItemRevPropertyMap&  input ) = 0;

    /**
     * This operation deletes the input objects.  In the case of <b>Item</b>, it also deletes
     * all <b>ItemRevision</b> objects,  associated <b>ItemMaster</b>, <b>ItemRevisionMaster</b>
     * forms, and <b>Dataset</b> objects.  The input object can be an <b>ImanRelation</b>.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model Types - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of Teamcenter PLM platform. This component defines Types
     * framework.
     *
     * @param objects
     *        A list of objects to be deleted
     *
     * @return
     *         The UID of the successfully deleted objects is returned in the deleted list of the
     *         <code>ServiceData</code>. Any errors that occur will be returned as a partial error
     *         with the source business object attached to the partial error.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData deleteObjects ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& objects ) = 0;

    /**
     * Creates the specified relation between the input objects (primary and secondary objects).
     * If the relation name is not specified then default relation name specified in either
     * the preference <b>ParentTypeName_ChildTypeName_default_relation</b> or<b> ParentTypeName_default_relation
     * </b>is considered as the relation name. In case none of these preferences are set
     * the relation between the primary and secondary object is not created. If the primary
     * object has a relation property by the specified relation name, then the secondary
     * object is associated with the primary object through the relation property.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * GRM - The Generic Relationship Manager (GRM) module supports the concept of explicit
     * relationships. One can define and enforce specific rules pertaining to relationships,
     * as well as separate the maintenance of relationships from the data itself.
     *
     * @param input
     *        A list of structures containing details of relationships to be created between primary
     *        and secondary objects with the given relation.
     *
     * @return
     *         The created relations. The partial error 214116 is returned for any requtest relation
     *         types that are not valid relation type name. The clientId is added to the partial
     *         error to identify which input element is incorrect.
     *
     */
    virtual Teamcenter::Services::Core::_2006_03::Datamanagement::CreateRelationsResponse createRelations ( const std::vector< Teamcenter::Services::Core::_2006_03::Datamanagement::Relationship >& input ) = 0;

    /**
     * Deletes the specified relation between the primary and secondary object for each
     * input structure.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * GRM - The Generic Relationship Manager (GRM) module supports the concept of explicit
     * relationships. One can define and enforce specific rules pertaining to relationships,
     * as well as separate the maintenance of relationships from the data itself.
     *
     * @param input
     *        A list of structures containing details of relationships to be deleted between primary
     *        and secondary objects with the given relation.
     *
     * @return
     *         The errors are returned with the index into the <code>Relationship</code> input mapped
     *         to the error message in the <code>ServiceData</code> list of partial errors.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData deleteRelations ( const std::vector< Teamcenter::Services::Core::_2006_03::Datamanagement::Relationship >& input ) = 0;


protected:
    virtual ~Datamanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/core/Core_undef.h>
#endif

