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

#ifndef TEAMCENTER_SERVICES_CORE_DATAMANAGEMENTSERVICE_HXX
#define TEAMCENTER_SERVICES_CORE_DATAMANAGEMENTSERVICE_HXX

#include <teamcenter/services/core/_2006_03/Datamanagement.hxx>
#include <teamcenter/services/core/_2007_01/Datamanagement.hxx>
#include <teamcenter/services/core/_2007_06/Datamanagement.hxx>
#include <teamcenter/services/core/_2007_09/Datamanagement.hxx>
#include <teamcenter/services/core/_2007_12/Datamanagement.hxx>
#include <teamcenter/services/core/_2008_05/Datamanagement.hxx>
#include <teamcenter/services/core/_2008_06/Datamanagement.hxx>
#include <teamcenter/services/core/_2009_10/Datamanagement.hxx>
#include <teamcenter/services/core/_2010_04/Datamanagement.hxx>
#include <teamcenter/services/core/_2010_09/Datamanagement.hxx>
#include <teamcenter/services/core/_2011_06/Datamanagement.hxx>
#include <teamcenter/services/core/_2012_02/Datamanagement.hxx>
#include <teamcenter/services/core/_2012_09/Datamanagement.hxx>
#include <teamcenter/services/core/_2013_05/Datamanagement.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/core/Core_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Core
        {
            class DatamanagementService;

/**
 * The <code>DataManagement</code> service provides a broad range of operations to manage
 * data throughout its life cycle in Teamcenter from data creation to data retrieval.
 * The applications or clients can create, store, retrieve and manipulate data using
 * the operations as organizational resource interactively. The data can be any business
 * object such as an <b>Item</b>, <b>ItemRevision</b>, <b>Dataset</b>, <b>Form</b>,
 * <b>Folder</b>, etc.
 * <br>
 * <br>
 * The operations in this service allow creation (or bulk creation), modification and
 * deletion of all business objects. This service also provides operations to revise,
 * save as, and query for all business objects, to get details of a specific business
 * object's information such as property values, to expand GRM relations for primary/secondary
 * business objects and to find where the business objects are used/referenced, etc.
 * <br>
 * <br>
 * The <code>DataManagement</code> service can be used for supporting following main
 * use-cases:
 * <br>
 * <ul>
 * <li type="disc">Create/update/delete a business object
 * </li>
 * <li type="disc">Load/unload/refresh/revise/save as/validate business object
 * </li>
 * <li type="disc">Find and expand business object GRM relationship
 * </li>
 * <li type="disc">Get details of a business object such as type info, attribute values,
 * next ids, dataset files, localized properties, <b>Organization</b> information, etc.
 * </li>
 * <li type="disc">Remove Named Reference from a <b>Dataset</b>
 * </li>
 * <li type="disc">Add and remove <b>Participants</b>, change ownership
 * </li>
 * <li type="disc">Generate UIDs/Revision Ids
 * </li>
 * </ul>
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoacorestrongmngd.dll
 * </li>
 * <li type="disc">libtcsoacoretypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOACORESTRONGMNGD_API DatamanagementService
    : public Teamcenter::Services::Core::_2006_03::Datamanagement,
             public Teamcenter::Services::Core::_2007_01::Datamanagement,
             public Teamcenter::Services::Core::_2007_06::Datamanagement,
             public Teamcenter::Services::Core::_2007_09::Datamanagement,
             public Teamcenter::Services::Core::_2007_12::Datamanagement,
             public Teamcenter::Services::Core::_2008_05::Datamanagement,
             public Teamcenter::Services::Core::_2008_06::Datamanagement,
             public Teamcenter::Services::Core::_2009_10::Datamanagement,
             public Teamcenter::Services::Core::_2010_04::Datamanagement,
             public Teamcenter::Services::Core::_2010_09::Datamanagement,
             public Teamcenter::Services::Core::_2011_06::Datamanagement,
             public Teamcenter::Services::Core::_2012_02::Datamanagement,
             public Teamcenter::Services::Core::_2012_09::Datamanagement,
             public Teamcenter::Services::Core::_2013_05::Datamanagement
{
public:
    static DatamanagementService* getService( Teamcenter::Soa::Client::Connection* );


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

    /**
     * Returns the secondary objects related to the input object for the given list of properties
     * / relations and other side object types.  If no properties/relations or other side
     * objects types are input, then all related objects will be returned.  In addition,
     * for performance, if an Item is the output of the expansion, then its associated Item
     * Revisions and the Datasets for those Item Revisions will be returned.  Similarly,
     * if an Item Revision is the output of the expansion, then its associated Datasets
     * will be returned.
     *
     * @param primaryObjects
     *        A Vector of Teamcenter primary objects
     *
     * @param pref
     *        Expand GRM Relations Preference
     *
     * @return
     *         Secondary objects related to the primary objects identified after filtering and ServiceData
     *
     */
    virtual Teamcenter::Services::Core::_2007_06::Datamanagement::ExpandGRMRelationsResponse expandGRMRelationsForPrimary ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& primaryObjects,
        const Teamcenter::Services::Core::_2007_06::Datamanagement::ExpandGRMRelationsPref&  pref ) = 0;

    /**
     * This will return type names implemented by the given classes. This is lightweight
     * way to get all displayable types by name rather than model object.
     *
     * @param classes
     *        A list of given base class name and exclusion list.
     *
     * @return
     *         A map of given base class name and its available instance types. Failure will be
     *         returned with error messages in service data.
     *
     */
    virtual Teamcenter::Services::Core::_2007_06::Datamanagement::GetAvailableTypesResponse getAvailableTypes ( const std::vector< Teamcenter::Services::Core::_2007_06::Datamanagement::BaseClassInput >& classes ) = 0;

    /**
     * Given a list of <b>ItemRevision</b> sequences, this opertion is used ot perform per
     * the following criteria:
     * <br>
     * <ul>
     * <li type="disc">If the input object is the latest sequence of an <b>ItemRevision</b>,
     * all previous sequences will be purged.
     * </li>
     * <li type="disc">If the input object is not the latest sequence of the <b>ItemRevision</b>
     * and the <code>validateLatestFlag</code> is false, the input object will be purged.
     * </li>
     * <li type="disc">If the input object is not the latest sequence of the <b>ItemRevision</b>
     * and the <code>validateLatestFlag</code> is true, the <code>ServiceData</code> will
     * be updated with an error.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model Item - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of Teamcenter PLM platform. This component defines the Item
     * Class and behavior.
     *
     * @param objects
     *        A list of the objects to be purged and a flag noting whether to validate the object
     *        is the latest sequence.
     *
     * @return
     *         This operation returns <code>ServiceData</code> containing successfully purged sequences
     *         in the <code>Delete</code> list and partial errors for any sequences which could
     *         not be purged. The following partial error may be returned:
     *         <br>
     *         <ul>
     *         <li type="disc">214110: The input object is not valid.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData purgeSequences ( const std::vector< Teamcenter::Services::Core::_2007_06::Datamanagement::PurgeSequencesInfo >& objects ) = 0;

    /**
     * This operation is used to add or remove immunity for each object in the input list
     * according to the value of the associated <code>setOrRemoveFlag</code>.  A value of
     * true indicates to apply immunity to the object.  A value of false indicates that
     * immunity should be removed from the object.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model Item - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of Teamcenter PLM platform. This component defines the Item
     * Class and behavior.
     *
     * @param objects
     *        A list of the <b>ItemRevision</b> sequence objects and a flag set true or false.
     *
     * @return
     *         Any errors that occur will be returned as a partial error with the source business
     *         object attached to the partial error. The following partial error may be returned:
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">214110: The input object is not valid.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData setOrRemoveImmunity ( const std::vector< Teamcenter::Services::Core::_2007_06::Datamanagement::SetOrRemoveImmunityInfo >& objects ) = 0;

    /**
     * This operation returns the named reference information for a set of dataset types.
     * Named references are Teamcenter objects that relate to a specific data file.
     * <br>
     * <br>
     * Any failure that occurs during this operation is returned in the <code>ServiceData</code>
     * list of partial errors with the dataset type name string mapped to error message.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User wants to see which file type is allowed for attaching to a dataset.
     * <br>
     * <br>
     * For this operation, the dataset type name is passed in the <code>datasetTypeNames</code>
     * input and the named reference information is returned.  The file extension, <code>fileExtension</code>,
     * is returned in <code>ReferenceInfo</code> and can be used to determine the supported
     * file type for the dataset.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model Types - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of Teamcenter PLM platform. This component defines Types
     * framework.
     *
     * @param datasetTypeNames
     *        List of dataset type names used to get the named reference information. An empty
     *        list will return information for all dataset types defined in Teamcenter.
     *
     * @return
     *         Named reference information for each input dataset type name.
     *         <br>
     *         <br>
     *         The following error originates from this operation:
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">214135: The input dataset type does not exist.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Core::_2007_06::Datamanagement::DatasetTypeInfoResponse getDatasetTypeInfo ( const std::vector< std::string >& datasetTypeNames ) = 0;

    /**
     * Validates the item ID and revision ID based on the naming rules and user exit callbacks.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Naming Rules - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of Teamcenter PLM platform. This component defines Naming
     * Rules and Revision Naming Rules.
     *
     * @param infos
     *        A List of item IDs, revision IDs, and item type for validation.
     *        <br>
     *
     * @return
     *         - the response object containts a list of ValidateIdsOutput and ServiceData. The
     *         ValidateIdsOutput contains validation statuses for Item Id and Revision Id. If the
     *         Ids are modified because of the Naming Rules, then the modified Item Id and Revision
     *         Id are returned. Any failure is returned in the ServiceData list of partial errors
     *         with index of ValidateIdsInfo mapped to error message.
     *
     * @deprecated
     *         As of Teamcenter 10.1, use the validateValues operation.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 10.1, use the validateValues operation."))
#endif
    virtual Teamcenter::Services::Core::_2007_06::Datamanagement::ValidateItemIdsAndRevIdsResponse validateItemIdsAndRevIds ( const std::vector< Teamcenter::Services::Core::_2007_06::Datamanagement::ValidateIdsInfo >& infos ) = 0;

    /**
     * Returns the primary objects related to the input object for the given list of properties
     * / relations and other side object types.  If no properties/relations or other side
     * objects types are input, then all related objects will be returned.  In addition,
     * for performance, if an Item is the output of the expansion, then its associated Item
     * Revisions and the Datasets for those Item Revisions will be returned.  Similarly,
     * if an Item Revision is the output of the expansion, then its associated Datasets
     * will be returned.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * GRM - The Generic Relationship Manager (GRM) module supports the concept of explicit
     * relationships. One can define and enforce specific rules pertaining to relationships,
     * as well as separate the maintenance of relationships from the data itself.
     *
     * @param secondaryObjects
     *        A Vector of Teamcenter secondary objects
     *
     * @param pref
     *        Expand GRM Relations Preference
     *
     * @return
     *         Primary objects related to the primary objects identified after filtering and ServiceData
     *
     */
    virtual Teamcenter::Services::Core::_2007_06::Datamanagement::ExpandGRMRelationsResponse expandGRMRelationsForSecondary ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& secondaryObjects,
        const Teamcenter::Services::Core::_2007_06::Datamanagement::ExpandGRMRelationsPref&  pref ) = 0;

    /**
     * Finds the objects that reference a given object by specific relation.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Use case 1: Use this operation to find the objects referencing the input object by
     * a specific relation.
     * <br>
     * Use case 2: Use this operation to find objects of a specific type that reference
     * the input object by a specific relation.
     * <br>
     * Use case 3: Use this operation to find objects of a specific type referencing the
     * input object.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * GRM - The Generic Relationship Manager (GRM) module supports the concept of explicit
     * relationships. One can define and enforce specific rules pertaining to relationships,
     * as well as separate the maintenance of relationships from the data itself.
     *
     * @param inputs
     *        A list of desired business objects and filters to find the referencing objects for
     *
     * @param numLevels
     *        The number of levels to search.  For example, if A references B, and B references
     *        C, a 1-level search from C produces just B, but a 2-level search produces both A
     *        and B. If -1, all levels are returned.
     *
     * @return
     *         The list of requested objects and the objects that reference them. The following
     *         partial errors may be returned:
     *         <br>
     *         <ul>
     *         <li type="disc">214110: The input object is not valid.
     *         </li>
     *         <li type="disc">214160: The input preference filter is NULL.
     *         </li>
     *         <li type="disc">214120: The input preference filter contains an empty or an invalid
     *         relation type name.
     *         </li>
     *         <li type="disc">214116: The input relation type name is not a valid relation type
     *         name.
     *         </li>
     *         <li type="disc">214117: No referencer matches the input relation type name.
     *         </li>
     *         <li type="disc">214119: No referencer matches the input other side object type name.
     *         </li>
     *         <li type="disc">214118: No referencer can be found for the given object.
     *         </li>
     *         <li type="disc">214111: Where Referenced operation failed.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Core::_2007_06::Datamanagement::WhereReferencedByRelationNameResponse whereReferencedByRelationName ( const std::vector< Teamcenter::Services::Core::_2007_06::Datamanagement::WhereReferencedByRelationNameInfo >& inputs,
        int numLevels ) = 0;

    /**
     * Load business objects into the client data model for each of the UIDs supplied. The
     * business objects are loaded from the Teamcenter server's in memory cache of business
     * objects or from the database. UIDs of runtime business objects (<b>BOMLines</b>)
     * that are not currently loaded in the Teamcenter server's memory will result in a
     * partial error being returned.
     *
     * @param uids
     *        An array of UIDs. These UID may come from an outside source or from other service
     *        operations such as executeSavedQuery.
     *
     * @return
     *         The objecs will be returned in the 'plain' slot of the ServiceData with partial errors
     *         for any UID that is not valid or references an object the user does not have asscess
     *         to.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData loadObjects ( const std::vector< std::string >& uids ) = 0;

    /**
     * This operation removes the specified named references from a dataset.
     * <br>
     * <br>
     * If the <code>NamedReferenceInfo.targetObject</code> input is not specified then all
     * named references of the type specified are removed from the dataset.  If the <code>NamedReferenceInfo.targetObject</code>
     * input is specified then only that named reference is removed from the dataset.  If
     * the <code>NamedReferenceInfo.deleteTarget</code> input is true then the <code>NamedReferenceInfo.targetObject</code>
     * will be deleted if it is no longer referenced.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User deletes a single named reference from a dataset that has multiple named references
     * of the same type.
     * <br>
     * <br>
     * For this operation, the dataset is passed in along with the named reference type
     * and object reference for the specific named reference to be removed from the dataset.
     * The specific named reference is removed from the dataset and the dataset is added
     * to the <code>ServiceData</code> list of updated objects.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model Dataset - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of Teamcenter PLM platform.  This component defines class
     * 'Dataset' behavior.
     *
     * @param inputs
     *        A list of datasets and the named references to be removed from the datasets.
     *
     * @return
     *         <code>ServiceData</code>&nbsp;&nbsp;&nbsp;&nbsp;   Datasets that were successfully
     *         modified will be returned in <code>ServiceData</code> updated objects.  If a target
     *         object is deleted, the target object UID is added to <code>ServiceData</code> deleted
     *         objects.  Error messages for problems are returned in the <code>ServiceData</code>
     *         partial errors.
     *         <br>
     *         <br>
     *         The following warning originates from this operation:
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">214125: Nothing matching the specified input was found to delete.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData removeNamedReferenceFromDataset ( const std::vector< Teamcenter::Services::Core::_2007_09::Datamanagement::RemoveNamedReferenceFromDatasetInfo >& inputs ) = 0;

    /**
     * This operation returns the secondary objects that are related to the input primary
     * objects.  Relation type names and secondary object types can be input as a filter
     * to reduce the set of returned secondary objects.  In the context of expanding primary
     * objects, secondary objects may be referred to as side objects. If no relation type
     * names or secondary object types are input, then all related objects will be returned.
     * <br>
     * <br>
     * For improved performance, if an item is the output of the expansion, then its associated
     * item revisions and the datasets for those item revisions will be returned.  Similarly,
     * if an item revision is the output of the expansion, then its associated datasets
     * will be returned.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User wants to see all the secondary objects related to the input primary item object.
     * <br>
     * <br>
     * For this operation, the item object is input in <code>primaryObjects</code> and the
     * filter preference <code>info</code> <code>relationTypeName</code> and <code>otherSideObjectTypes</code>
     * parameters are set to be empty.  All secondary objects that have a relation to the
     * item are returned in <code>ExpandGRMRelationsOutput2</code>  <code>relationshipData</code>.
     * The primary object, secondary objects and relation objects are returned as plain
     * objects in the <code>ServiceData</code>.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * GRM - The Generic Relationship Manager (GRM) module supports the concept of explicit
     * relationships. One can define and enforce specific rules pertaining to relationships,
     * as well as separate the maintenance of relationships from the data itself.
     *
     * @param primaryObjects
     *        The list of Teamcenter primary objects.
     *
     * @param pref
     *        The structure for setting specific preference input used by this operation.
     *
     * @return
     *         Secondary objects related to each input primary object identified after filtering.
     *         <br>
     *         <br>
     *         The following errors originate from this operation:
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">7007: The specified primary object is invalid.
     *         </li>
     *         <li type="disc">214160: The input preference filter is null.
     *         </li>
     *         <li type="disc">214231: The input object is not a valid Teamcenter object.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Core::_2007_09::Datamanagement::ExpandGRMRelationsResponse2 expandGRMRelationsForPrimary ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& primaryObjects,
        const Teamcenter::Services::Core::_2007_09::Datamanagement::ExpandGRMRelationsPref2&  pref ) = 0;

    /**
     * This operation returns the primary objects that are related to the input secondary
     * objects.  Relation type names and secondary object types can be input as a filter
     * to reduce the set of returned primary objects.  In the context of expanding secondary
     * objects, primary objects may be referred to as side objects.  If no relation type
     * names or secondary object types are input, then all related objects will be returned.
     * <br>
     * <br>
     * For improved performance, if an item is the output of the expansion, then its associated
     * item revisions and the datasets for those item revisions will be returned.  Similarly,
     * if an item revision is the output of the expansion, then its associated datasets
     * will be returned.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User wants to see all the primary objects related to the input secondary dataset
     * object.
     * <br>
     * <br>
     * For this operation, the dataset object is input in <code>secondaryObjects</code>
     * and the filter preference info <code>relationTypeName</code> and <code>otherSideObjectTypes</code>
     * parameters are set to be empty.  All primary objects that have a relation to the
     * dataset are returned in <code>ExpandGRMRelationsOutput2</code>  <code>relationshipData</code>.
     * The secondary object, primary objects and relation objects are returned as plain
     * objects in the <code>ServiceData</code>.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * GRM - The Generic Relationship Manager (GRM) module supports the concept of explicit
     * relationships. One can define and enforce specific rules pertaining to relationships,
     * as well as separate the maintenance of relationships from the data itself.
     *
     * @param secondaryObjects
     *        The list of Teamcenter secondary objects.
     *
     * @param pref
     *        The structure for setting specific preference input used by this operation.
     *
     * @return
     *         Primary objects related to each input secondary object identified after filtering.
     *         <br>
     *         <br>
     *         The following errors originate from this operation:
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">7007: The specified secondary object is invalid.
     *         </li>
     *         <li type="disc">214160: The input preference filter is null.
     *         </li>
     *         <li type="disc">214231: The input object is not a valid Teamcenter object.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Core::_2007_09::Datamanagement::ExpandGRMRelationsResponse2 expandGRMRelationsForSecondary ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& secondaryObjects,
        const Teamcenter::Services::Core::_2007_09::Datamanagement::ExpandGRMRelationsPref2&  pref ) = 0;

    /**
     * Create new alternate identifiers. Given an <code>IdContext</code>, an <code>IdentifierType</code>
     * and an <b>Item</b> ( and optionally an <b>ItemRevision</b> ), create <b>an Identifier</b>
     * object to display an option part number when the <code>IdContext</code> is valid.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User has a part number for an <b>Item</b> that is used to track the <b>Item</b>.
     * The manufacturer of the <b>Item</b> has a different part number. The sales department
     * has another part number. The user needs to keep all 3 part numbers with the <b>Item</b>
     * and display them at different times. The user can get a list of <code>IdContext</code>
     * and <code>IdentifierTypes</code> from the <code>getContextsAndIdentifierTypes</code>
     * operation. Using the <code>IdContext</code> and <code>IdentifierType</code>, the
     * client can create an <b>Identifer</b> for the <b>Item</b> and <b>ItemRevision</b>
     * to be displayed when the <code>IdContext</code> is valid.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * getContextsAndIdentifierTypes, listAlternateIdDisplayRules
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Identifier - Component to define Identifier and associate it with an Item or Item
     * Revision. An identifier can be an Alternate identifier for an object as well as an
     * Alias identifier for other objects at the same time.
     *
     * @param input
     *        This data describes the alternate identifiers to create.
     *
     * @return
     *         The <code>ServiceData</code> will contain the newly created objects of type <b>Identifier</b>
     *         for the <b>Item</b> and <b>ItemRevision</b> ( if requested ) in the created list
     *         and the updated objects of type <b>Identifier</b> for the <b>Item</b> and <b>ItemRevision</b>
     *         ( if requested ) will be in the updatedObjects section.. Error messages are returned
     *         in the ServiceData as partial errors, this service does not have any specific errors,
     *         just errors from the sub-system.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData createAlternateIdentifiers ( const std::vector< Teamcenter::Services::Core::_2007_12::Datamanagement::AlternateIdentifiersInput >& input ) = 0;

    /**
     * Returns the context and identifier types for the supplied identifiable types.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * A user has defined several <b>IdContexts</b> and <b>Idenitfiers</b> in preparation
     * for creating <b>AlternateIds</b>. This service returns the current <b>IdContext</b>
     * and Identifiers allowing the user to select the appropriate data for <b>AlternateId</b>
     * creation.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Identifier - Component to define Identifier and associate it with an Item or Item
     * Revision. An identifier can be an Alternate identifier for an object as well as an
     * Alias identifier for other objects at the same time.
     *
     * @param typeTags
     *        A list of <b>ImanType</b> objects.
     *
     * @return
     *         A map of identifiable types with their contexts and the identifier types for each
     *         context. This service will return partial error 9999 if a <code>typeTag</code> is
     *         invalid. Other error messages are for problems in the subsystem.
     *
     */
    virtual Teamcenter::Services::Core::_2007_12::Datamanagement::GetContextAndIdentifiersResponse getContextsAndIdentifierTypes ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ImanType>  >& typeTags ) = 0;

    /**
     * Return the current display rule. If the current user flag is set then also return
     * the display rules for the current user. If a list of users is supplied, then return
     * the display rules for the list of users; otherwise return the display rules for all
     * users.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Return the current display rule in effect and optionally return all the display rules
     * for the current user. Also return the display rules for all users or for a list of
     * users only.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Identifier - Component to define Identifier and associate it with an Item or Item
     * Revision. An identifier can be an Alternate identifier for an object as well as an
     * Alias identifier for other objects at the same time.
     *
     * @param input
     *        A <code>ListAlternateIdDisplayRulesInfo</code> data structure.
     *
     * @return
     *         A map of <b>User</b> objects to <code>IdDispRuleSpec</code>. Error messages for problems
     *         are returned in the <code>ServiceData</code> partial errors. This service throws
     *         no specific errors but the subsystem may.
     *
     */
    virtual Teamcenter::Services::Core::_2007_12::Datamanagement::ListAlternateIdDisplayRulesResponse listAlternateIdDisplayRules ( const Teamcenter::Services::Core::_2007_12::Datamanagement::ListAlternateIdDisplayRulesInfo&  input ) = 0;

    /**
     * Determines if the supplied alternateIds are valid. The USER exit USER_validate_alt_id
     * is used for validation. A "modified" alternate id is returned. If the alternate id
     * supplied is valid then the modified one returned is the same as the one supplied.
     * If the alternate id supplied is not valid, then the one returned is a valid one.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * The user has an alternate id that they wish to use for an object. The alternate id
     * is sent to this function to determine if the new alternate id conforms to the rules
     * defined by the user.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * getContextsAndIdentifierTypes
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Identifier - Component to define Identifier and associate it with an Item or Item
     * Revision. An identifier can be an Alternate identifier for an object as well as an
     * Alias identifier for other objects at the same time.
     *
     * @param inputs
     *        A list of <code>ValidateAlternateIdInput</code> data structures.
     *
     * @return
     *         A list giving the status and output id of each input. This service throws no errors
     *         explicitly but the system calls may generate errors. Error messages are returned
     *         in the <code>ServiceData</code> partial errors.
     *
     */
    virtual Teamcenter::Services::Core::_2007_12::Datamanagement::ValidateAlternateIdResponse validateAlternateIds ( const std::vector< Teamcenter::Services::Core::_2007_12::Datamanagement::ValidateAlternateIdInput >& inputs ) = 0;

    /**
     * This operation unloads Business Objects. If input contains one or more Business Objects
     * then it will call AOM_unload for each object otherwise it will call unloadAll  to
     * unload all the objects.
     * <br>
     * <br>
     * Note that unloadAll will unload both C++ along with POM objects.
     * <br>
     *
     * @param objsToUnload
     *        A list of model objects to unload.
     *
     * @return
     *         It will return partial error if any.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData unloadObjects ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& objsToUnload ) = 0;

    /**
     * Operation to retrieve sub Business Object Names for a Business Object that are displayable
     * to the login user in the object creation dialog. e.g File-new, select Item, what
     * types to be displayed for Item
     *
     * @param input
     *        - a list of input objects representing the BO type names for which the displayable
     *        types are to be retrieved
     *
     * @return
     *         contains a list of BO type names to be displayed for input
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Core::_2008_06::Datamanagement::DisplayableSubBOsResponse findDisplayableSubBusinessObjects ( const std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::BOWithExclusionIn >& input ) = 0;

    /**
     * This operation creates a list of <b>Dataset</b> objects and creates the specified
     * relation type between created <b>Dataset</b> and input container object.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model Dataset - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of Teamcenter PLM platform.  This component defines class
     * 'Dataset' behavior.
     *
     * @param input
     *        The information needed to create  <b>Dataset</b>
     *
     * @return
     *         Created <b>Datasets</b> and update container objects will be returned in the <code>ServiceData</code>
     *         lists of created and updated objects respectively.  Any failure will be returned
     *         with client id mapped to error message in the <code>ServiceData</code> list of partial
     *         errors. The error code of the failures can be any of follows:
     *         <br>
     *         <ul>
     *         <li type="disc">214122: Name or Type of the <b>Dataset</b> to be created is not provided
     *         </li>
     *         <li type="disc">525084: User does not have write privilege to the container object
     *         </li>
     *         <li type="disc">9010:  Unable to find type of <b>Dataset</b> to be created.
     *         </li>
     *         <li type="disc">9008: Specified Tool of the <b>Dataset</b> to be created is invalid.
     *         </li>
     *         <li type="disc">89015: Fail to create relation between the container object and the<b>
     *         Dataset</b> to be created.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Core::_2006_03::Datamanagement::CreateDatasetsResponse createDatasets2 ( const std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::DatasetProperties2 >& input ) = 0;

    /**
     * This operation returns <b>Items</b>, <b>ItemRevisions</b>, <b>Dataset</b> and <b>NamedReference</b>
     * information based on the input. Input is a list of <code>GetItemAndRelatedObjectsInfo</code>
     * structures each of which contains item uid or id, revison information and optionally
     * a list of filters to determine the datasets to be returned. For the <b>Datasets</b>
     * the client can request information about the <b>NamedReferences</b>. <b>NamedReferences</b>
     * are how <b>Data</b> files are attached to <b>Datasets</b>. The Data file is what
     * a CAD client is really interested in. The return is a <code>GetItemAndRelatedObjectsResponse</code>
     * which contains a list of <code>GetItemAndRelatedObjectsItemOutput</code> and a <code>ServiceData</code>.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * The client has an item of <b>ItemRevision</b> and needs to know what CAD data is
     * attached to the <b>ItemRevision</b>. The client fills in either the <b>Item</b> or
     * <b>ItemRevision</b> information along with the information about the types of <b>Dataset</b>
     * and <b>NamedReferences</b> the client is interested in. For the <b>NamedReferences</b>
     * the user can get the tickets which will allow the client retrieve the files attached
     * to the <b>Datasets</b>. The results of the query will give the client all the information
     * about the <b>Datasets</b> and <b>NamedReferences</b> and optional tickets.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model Item - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of Teamcenter PLM platform. This component defines the Item
     * Class and behavior.
     *
     * @param infos
     *        list of <code>GetItemAndRelatedObjectsInfo</code> structures.
     *
     * @return
     *         Contains found items, revisions and the datasets attached to the revision. Partial
     *         Errors will be returned as a map of input client id to error message.
     *
     */
    virtual Teamcenter::Services::Core::_2008_06::Datamanagement::GetItemAndRelatedObjectsResponse getItemAndRelatedObjects ( const std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::GetItemAndRelatedObjectsInfo >& infos ) = 0;

    /**
     * This operation provides the ability to revise the <b>ItemRevision</b> objects given
     * in the input list and carries forward relations to existing objects. When applying
     * deep copy rules, if user overridden deep copy information is provided in the input,
     * relations are propagated to the new <b>ItemRevision</b> based on that input. If no
     * deep copy information is provided in the input, the deep copy rules in the database
     * are used to propagate relations to the new <b>ItemRevision</b>.  If the input contains
     * property values for the master form, those values are set on the new <b>ItemRevision</b>
     * master form.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model Item - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of Teamcenter PLM platform. This component defines the Item
     * Class and behavior.
     *
     * @param info
     *        The necessary information to create the new revision
     *
     * @return
     *         This operation returns a <code>ReviseResponse2</code> structure for revise operation
     *         or errors. The following errors may be returned:
     *         <br>
     *         <ul>
     *         <li type="disc">214124: The Rev Properties has NULL values, the system default will
     *         be used.
     *         </li>
     *         <li type="disc">214127: Empty input values for Item master form properties.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Core::_2008_06::Datamanagement::ReviseResponse2 revise2 ( const std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::ReviseInfo >& info ) = 0;

    /**
     * This operation provides the capability to create one or more new <b>Item</b> objects
     * based on a list of existing <b>ItemRevision</b> objects. It optionally carries forward
     * <b>ItemRevision</b> relations based on the <code>deepCopyRequired</code> flag. When
     * applying deep copy rules, if user overridden deep copy information is provided in
     * the input, then old <b>ItemRevision</b> relations are propagated to the new <b>ItemRevision</b>
     * based on the input. If no deep copy rule information is provided in the input, the
     * deep rules in the database will be applied. If user provides new property values
     * for the <b>Item</b> and <b>ItemRevision</b> master forms in the input, then these
     * will be copied to the master forms of the newly created <b>Item</b> and <b>ItemRevision</b>.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model Item - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of Teamcenter PLM platform. This component defines the Item
     * Class and behavior.
     *
     * @param info
     *        The necessary information to create the new <b>Iitem</b> and <b>ItemRevision</b>
     *
     * @return
     *         A <code>SaveAsNewItemResponse2</code> structure which contains information about
     *         the new <b>Item</b>, <b>ItemRevision</b> and related objects as well as a <code>ServiceData</code>
     *         structure containing error information in the <code>PartialErrors</code> list. The
     *         following error may be returned:
     *         <br>
     *         <ul>
     *         <li type="disc">70007: Invalid object  - the requested object does not exist.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Core::_2008_06::Datamanagement::SaveAsNewItemResponse2 saveAsNewItem2 ( const std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::SaveAsNewItemInfo >& info ) = 0;

    /**
     * The operation generates the next id as per the input pattern in the attached Naming
     * Rule to the property of an object type. The type name, property name and pattern
     * are passed in the input structure. The input for this operation contains a  list
     * of this structure. The return structure contains the list of nextId along with the
     * service data member. In the case where no pattern is specified, a default ID will
     * be returned if the type, property combination is <b>Item</b> / item_id, <b>Dataset</b>
     * / pubr_object_id or <b>ItemRevision</b>/item_revision_id. For all other type, property
     * combinations, the operation will not generate a default ID.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation is called on click of "Assign" button in create, revise and save-as
     * dialogs to generate the next available options for item and revision ids. The generated
     * values are used as input for create, revise and save-as operations.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Naming Rules - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of Teamcenter PLM platform. This component defines Naming
     * Rules and Revision Naming Rules.
     *
     * @param vInfoForNextId
     *        Contains Type Name, Property Name and pattern.
     *
     * @return
     *         List containing nextId strings generated as per the pattern. Failure for any structure
     *         in the input list is indexed correspondingly along with error details and is stored
     *         in the service data member. If there are no failures, then size of input list and
     *         size of each output list are equal. If there are any errors then the size of output
     *         list is less than size of the input list and the Service data will contain the index
     *         of the element in input list for which the error occurred along with the error details.
     *         After getting response from the operation, loop through the input list and check
     *         if there is any error against the index of that list element. If there is no error
     *         then take the next set elements in the Response lists as output for that input list
     *         element.
     *         <br>
     *         <br>
     *         The following partial errors could be returned:
     *         <br>
     *         <ul>
     *         <li type="disc">74009&nbsp;&nbsp;&nbsp;&nbsp;Invalid system variable in pattern <code>vInfoForNextId[index].pattern</code>.
     *         </li>
     *         <li type="disc">74010&nbsp;&nbsp;&nbsp;&nbsp;Missing character after escape in pattern
     *         <code>vInfoForNextId[index].pattern</code>.
     *         </li>
     *         <li type="disc">74011&nbsp;&nbsp;&nbsp;&nbsp;Missing delimiter character in pattern
     *         <code>vInfoForNextId[index].pattern</code>.
     *         </li>
     *         <li type="disc">74012&nbsp;&nbsp;&nbsp;&nbsp;Rule/LOV variable <code>vInfoForNextId[index].pattern</code>
     *         is missing.
     *         </li>
     *         <li type="disc">74013&nbsp;&nbsp;&nbsp;&nbsp;LOV variable <code>vInfoForNextId[index].pattern</code>
     *         is not a string.
     *         </li>
     *         <li type="disc">74014&nbsp;&nbsp;&nbsp;&nbsp;Invalid variable type <code>X</code>
     *         in pattern <code>vInfoForNextId[index].pattern</code>.
     *         </li>
     *         <li type="disc">74015&nbsp;&nbsp;&nbsp;&nbsp;Invalid character in pattern <code>vInfoForNextId[index].pattern</code>.
     *         </li>
     *         <li type="disc">74016&nbsp;&nbsp;&nbsp;&nbsp;The counter value has reached its maximum
     *         for the given pattern. Please contact the system administrator to reset the counters.
     *         </li>
     *         <li type="disc">74017&nbsp;&nbsp;&nbsp;&nbsp;No counters Found.
     *         </li>
     *         <li type="disc">74018&nbsp;&nbsp;&nbsp;&nbsp;Autogen not set to create counters.
     *         </li>
     *         <li type="disc">74022&nbsp;&nbsp;&nbsp;&nbsp;The rule has nested too many times,
     *         pattern is <code>vInfoForNextId[index].pattern</code>.
     *         </li>
     *         <li type="disc">74029&nbsp;&nbsp;&nbsp;&nbsp;The auto-assignment cannot generate
     *         an ID. A Naming Rule without a counter has been configured on the property <code>vInfoForNextId[index].propName</code>.
     *         Please contact your system administrator.
     *         </li>
     *         </ul>
     *         <br>
     *         <br>
     *         Other than this, errors thrown from any of the following Teamcenter system calls
     *         may be caught and added to the ServiceData's error stack:
     *         <br>
     *         <ul>
     *         <li type="disc">TCTYPE_find_type()
     *         </li>
     *         <li type="disc">TCTYPE_is_type_of ()
     *         </li>
     *         <li type="disc">USER_new_item_id()
     *         </li>
     *         <li type="disc">USER_new_dataset_id()
     *         </li>
     *         <li type="disc">USER_new_revision_id()
     *         </li>
     *         </ul>
     *         <br>
     *         (This list may be incomplete, and is subject to change without notice.)
     *
     */
    virtual Teamcenter::Services::Core::_2008_06::Datamanagement::GetNextIdsResponse getNextIds ( const std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::InfoForNextId >& vInfoForNextId ) = 0;

    /**
     * This operation gives the list of Patterns which has counters along with preferred
     * patterns and conditions for the Naming Rule attached to the property of an object
     * Type. The Type name and the Property name are passed in the input structure. The
     * input for this operation contains a list of this structure. The return structure
     * contains the vector of patterns with counters, preferredPattern and condition, along
     * with the service data member.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation is used in create, revise or save-as dialogs to receive list of applicable
     * patterns for item and revision ids. The list of patterns returned is displayed in
     * these dialogs for user selection. After user selects a pattern and clicks "Assign"
     * button, an id is generated matching the pattern selected and populated in the corresponding
     * field's box.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Naming Rules - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of Teamcenter PLM platform. This component defines Naming
     * Rules and Revision Naming Rules.
     *
     * @param vAttachInfo
     *        Struct that contains Type Name and Property Name
     *
     * @return
     *         It returns patterns which has counters along with preferred patterns and conditions.
     *         Failure for any structure in the input vector is indexed correspondingly along with
     *         error details and is stored in the service data member. If there are no failures
     *         then input vector size and size of each output vector is equal. If there are any
     *         errors then the size of output vector is less than the input vector and the Service
     *         data will contain the index of input vector for which the error occurred along with
     *         the error details. After getting response from the operation loop through the input
     *         vector and check if there is any error against that vector element's index. If there
     *         is no error then take the next set elements in the Response vectors as output for
     *         that input vector element.
     *         <br>
     *         <br>
     *         This operation throws no errors internally. However, errors thrown from any of the
     *         following Teamcenter system calls may be caught and added to the ServiceData's error
     *         stack:
     *         <br>
     *         <ul>
     *         <li type="disc">AOM_ask_value_tag ()
     *         </li>
     *         <li type="disc">CE_ask_condition ()
     *         </li>
     *         <li type="disc">AOM_ask_value_tags ()
     *         </li>
     *         <li type="disc">PREF_ask_value_count ()
     *         </li>
     *         <li type="disc">PREF_ask_char_values ()
     *         </li>
     *         </ul>
     *         <br>
     *         (This list may be incomplete, and is subject to change without notice.)
     *
     */
    virtual Teamcenter::Services::Core::_2008_06::Datamanagement::GetNRPatternsWithCountersResponse getNRPatternsWithCounters ( const std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::NRAttachInfo >& vAttachInfo ) = 0;

    /**
     * This operation gets all the possible initial, secondary and supplemental revision
     * next Ids for an <b>ItemRevision</b> along with the available formats and the set
     * of excluded letters for revision. The Revision Type Name and the current revision
     * are passed in the input typeAndItemRevInfos structure. The input for this operation
     * contains a list of this structure. The return structure contains list of Initial
     * Revision details, Secondary Revision details, Supplemental Revision details and exclude
     * Skip letters along with the service data member.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation is used to get the next available options for revision id for a new
     * or existing object. User can select one of the values returned by this operation
     * and use as revision id input value for create, revise or save-as operation.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Naming Rules - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of Teamcenter PLM platform. This component defines Naming
     * Rules and Revision Naming Rules.
     *
     * @param typeAndItemRevInfos
     *        List of <code>TypeAndItemRevInfo</code> structs which contains <b>Item</b> and <b>ItemRevision</b>
     *        type name and the revision object.
     *
     * @return
     *         The return structure, <code>GetRevNRAttachResponse</code>, contains the list of Initial
     *         Revision details, Secondary Revision details, Supplemental Revision details and exclude
     *         Skip letters along with the service data member. Failure for any structure in the
     *         input list is indexed correspondingly along with error details and is stored in the
     *         service data member. If there are no failures then input list size and size of each
     *         output list is equal. If there are any errors then the size of output lists is less
     *         than size of input list and the Service data will contain the index of element in
     *         the input list for which the error occurred along with the error details. After getting
     *         response from the operation, loop through the input list and check if there is any
     *         error against that list element's index. If there is no error then take the next
     *         set elements in the Response lists as output for that input list element.
     *         <br>
     *         <br>
     *         The following partial errors could be returned:
     *         <br>
     *         <ul>
     *         <li type="disc">74027&nbsp;&nbsp;&nbsp;&nbsp;The initial, secondary and supplemental
     *         revisions IDs are exhausted. You may contact your System Administrator for assistance.
     *         </li>
     *         </ul>
     *         <br>
     *         <br>
     *         Other than this, errors thrown from any of the following Teamcenter system calls
     *         may be caught and added to the ServiceData's error stack:
     *         <br>
     *         <ul>
     *         <li type="disc">TCTYPE_find_type()
     *         </li>
     *         <li type="disc">TCTYPE_is_type_of ()
     *         </li>
     *         <li type="disc">TypeConstantAttachImpl::findTypeByTypeConstantAttachment()
     *         </li>
     *         <li type="disc">LOV_find()
     *         </li>
     *         <li type="disc">LOV_ask_values_char()
     *         </li>
     *         </ul>
     *         <br>
     *         (This list may be incomplete, and is subject to change without notice.)
     *
     */
    virtual Teamcenter::Services::Core::_2008_06::Datamanagement::GetRevNRAttachResponse getRevNRAttachDetails ( const std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::TypeAndItemRevInfo >& typeAndItemRevInfos ) = 0;

    /**
     * Creates the specified relation between the input objects (primary and secondary objects)
     * for each input structure. If the <code>sync</code> flag is specified, then if any
     * Generic Relationship Management (GRM) relations exist between the primary and secondary
     * objects and they are not specified in the input they will be deleted. If <code>sync</code>
     * flag is provided, the relations member of <code>CreateOrUpdateRelationsInfo</code>
     * is ignored.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Use Case 1: Create a relation based on the GRM rule definition.
     * <br>
     * <br>
     * One can create a relation specified by name of the relation in the input structure
     * between the primary and secondary object, when there exists a GRM rule between the
     * primary and secondary object with the given relation type.
     * <br>
     * <br>
     * Use Case 2: Update a relation based on the GRM rule definition.
     * <br>
     * <br>
     * One can update a relation specified by name of the relation in the input structure
     * between the primary and secondary object, when there exists a GRM rule between the
     * primary and secondary object with the given relation type.
     * <br>
     * <br>
     * Use Case 3: Remove a relation based on the GRM rule definition.
     * <br>
     * <br>
     * One can remove a relation by setting the sync to true and do not provide any relation
     * between the primary and secondary object in the input structure. When there exists
     * a GRM rule between the primary and secondary object with the given relation type,
     * and the sync flag is set to true, then if any GRM relations exist between the primary
     * and secondary objects and they are not specified in the input they will be deleted.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * GRM - The Generic Relationship Manager (GRM) module supports the concept of explicit
     * relationships. One can define and enforce specific rules pertaining to relationships,
     * as well as separate the maintenance of relationships from the data itself.
     *
     * @param infos
     *        A list of <code>CreateOrUpdateRelationsInfo</code> structures containing details
     *        of relationships to be created between primary and secondary objects with the given
     *        relation.
     *
     * @param sync
     *        If true then GRM relations in db and the number of secondary objects specified in
     *        the <code>input</code> will be synchronized. Note that in this case the <code>secondaryData</code>
     *        member of the <code>input</code> structure is used and not the <code>relations</code>
     *        member.
     *
     * @return
     *         A list of all the relation objects matching the primary and secondary passed in.
     *         Any failure will be returned with client id mapped to error message in the <code>ServiceData</code>
     *         list of partial errors.
     *
     */
    virtual Teamcenter::Services::Core::_2008_06::Datamanagement::CreateOrUpdateRelationsResponse createOrUpdateRelations ( const std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::CreateOrUpdateRelationsInfo >& infos,
        bool sync ) = 0;

    /**
     * Creates a list of <b>Connection</b> objects and any associated data (<b>ConnectionRevision</b>,
     * <b>ConnectionMaster</b> Form and <b>ConnectionRevision</b> Master Form) based on
     * the input properties structure. It also creates the specified relation type between
     * newly created <b>Connection</b> object and input container object. If container and
     * relation type are not supplied, none of the <b>Connection</b> objects will be related
     * to a container. If any destination to paste the newly created objects is desired
     * then it must be supplied as input.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation supports creation of single or multiple <b>Connection</b> objects.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Mechatronics - Core objects and relationships used by Mechatronics applications such
     * as ESM; Wire harness and Manufacturing applications.
     *
     * @param properties
     *        A <b>Connection</b> object is created for each ConnectionProperties in the list.
     *        The data on the ConnectionProperties is used to create initial values on the <b>Connection</b>
     *        and related objects
     *
     * @param container
     *        Object to which all the <b>Connection</b> objects created will be related to via
     *        the input relationType (Folder instance and contents relationType). If not specified
     *        the <b>Connection</b> will be created, but without a relation to a container object.
     *
     * @param relationType
     *        The name of the relation used to attach the created <b>Connection</b> objects to
     *        input container. This argument is used only when the container argument is present,
     *        optional.
     *
     * @return
     *         A <i>CreateConnectionsResponse</i> structure which contains a list of <i>ConnectionOutput</i>
     *         structures. The <i>ConnectionOutput</i> structure contains the created <b>Connection</b>
     *         and <b>ConnectionRevision</b> object. The newly created objects and the updated container
     *         object are added to the standard <i>ServiceData</i> lists of created and updated
     *         object respectively.  Any failure will be returned with client id mapped to the error
     *         message in the ServiceData list of partial errors. If the user does not have write
     *         permission to the container object, 000084 is returned as a Partial Error, the container
     *         object will be attached to the Partial Error. In this case, the <b>Connection</b>
     *         object will still be created, but will not be placed in any container.
     *
     */
    virtual Teamcenter::Services::Core::_2008_06::Datamanagement::CreateConnectionsResponse createConnections ( const std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::ConnectionProperties >& properties,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  container,
        const std::string&  relationType ) = 0;

    /**
     * Create and/or update <b>GeneralDesignElementLink</b>(<i>GDELink</i>) objects based
     * on the input properties structure. If the given <i>GDELink</i> object exists in Teamcenter
     * then the operation will be treated as an update based on the input properties structure
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation supports creation or updation of <i>GDELink</i> objects
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Mechatronics - Core objects and relationships used by Mechatronics applications such
     * as ESM; Wire harness and Manufacturing applications.
     *
     * @param gdeLinkInfos
     *        An input of vector of structures containing values necessary to create or update
     *        the Teamcenter Model Data representing the <i>GDELink</i>. If a reference to an existing
     *        <i>GDELink</i> is supplied then an update is assumed, otherwise a new <i>GDELink</i>
     *        is created. On update the <i>GDELink</i> name and description may be changed but
     *        not the type. After the <i>GDELink</i> is created, and if for an update the property
     *        values are supplied, the <i>GDELink</i> created will be updated with the properties.
     *
     * @return
     *         A map of the clientID of the input structure and the created or updated <i>GDELink</i>
     *         objects. All Object IDs that were successfully created or updated are added to <i>ServiceData</i>.
     *         Any failure will be returned in the <i>ServiceData</i> with the error message mapped
     *         to input client id
     *
     */
    virtual Teamcenter::Services::Core::_2008_06::Datamanagement::CreateOrUpdateGDELinksResponse createOrUpdateGDELinks ( const std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::GDELinkInfo >& gdeLinkInfos ) = 0;

    /**
     * Allows the user to create a new <b>GeneralDesignElement</b> (<i>GDE</i>) or its subtype
     * and set its properties. In the case of existing <i>GDE</i>, user can update the properties.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation can be used when user wants to create a <i>GDE</i> in a product structure
     * or wants to update the properties of an existing <i>GDE</i>. User has to pass unique
     * client Id, name and type when a new element has to be created. Whenever properties
     * of an existing <i>GDE</i> have to be updated the <i>itemElement</i> business object
     * and <i>itemElemAttributes</i> should be passed
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Mechatronics - Core objects and relationships used by Mechatronics applications such
     * as ESM; Wire harness and Manufacturing applications.
     *
     * @param properties
     *        This is a vector of <i>ItemElementProperties</i>. While creating a new element it
     *        shall contain a unique clientId, name and type. In the case of an existing <i>GDE</i>,
     *        this structure must contain <i>itemElemAttributes</i> to be modified and the <i>itemElement</i>
     *        whose properties have to be modified.
     *
     * @return
     *         A <i>CreateOrUpdateItemElementsResponse</i> structure contains clientId and <i>itemElement</i>
     *         business object newly created <b>GeneralDesignElement</b> object. The <i>serviceData</i>
     *         contains created/updated <i>GDE</i> and partial errors, if any, occurred during the
     *         operation.
     *         <br>
     *         <b>Partial Errors</b>
     *         <br>
     *         <i>Error Id. 214322  </i>Unable to create ItemElement: the input ItemElement name
     *         is null
     *         <br>
     *         <i>Error Id. 214323  </i>Error in creating %1$ ItemElement.
     *         <br>
     *         <i>Error Id. 214324 </i> Error in updating ItemElement properties.
     *         <br>
     *         <i>Error Id. 214325  </i>Invalid input for create or update of ItemElements
     *         <br>
     *
     */
    virtual Teamcenter::Services::Core::_2008_06::Datamanagement::CreateOrUpdateItemElementsResponse createOrUpdateItemElements ( const std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::ItemElementProperties >& properties ) = 0;

    /**
     * Generic operation for creation of Business Objects. This will also create any secondary(compounded)
     * objects that need to be created, assuming the CreateInput for the secondary object
     * is represented in the recursive CreateInput object e.g. <b>Item</b> is Primary Object
     * that also creates <b>Item Master</b> and <b>ItemRevision</b>. <b>ItemRevision</b>
     * in turn creates <b>ItemRevision Master</b>. The input for all these levels is passed
     * in through the recursive CreateInput object.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation to create an object is invoked after obtaining user input on the fields
     * of the create dialog. This call is typically preceded by a call to Teamcenter::Soa::Core::_2008_06::PropDescriptor::getCreateDesc
     * or to the SOA Client Metamodel layer to retrieve Create Descriptor for a Business
     * Object.
     * <br>
     * <br>
     * For example, to create an Item, client will get the Create Descriptor associated
     * with the Item from the client metamodel (The associated descriptor type can be found
     * by looking at the constant value for the CreateInput constant that is attached to
     * Item). Alternatively, for clients that do not use the SOA client metamodel, the Descriptor
     * for Item can be obtained by invoking getCreateDesc operation. The descriptor information
     * can then be used to populate the Create dialog for the Business Object. Once the
     * Create dialog is populated the createObjects operation can be called to create the
     * object.
     * <br>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * getCreateDesc
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Metamodel - Framework to define data model, operations, extensions and for autogeneration
     * of the underlying code for appropriate dispatching. It provides the framework for
     * codeless configuration and codeful customization.
     *
     * @param input
     *        This is a vector of CreateIn objects each one of which represents the CreateInput
     *        information used to create an object. Each CreateIn object has a client id and a
     *        CreateInput object which contains the information to create the object. The client
     *        id can be used to map to any partial errors in the ServiceData information returned
     *        in the output.
     *
     * @return
     *         A list of the business objects that were created. Any failure will be returned with
     *         client id mapped to error message in the ServiceData list of partial errors. The
     *         client id in the ServiceData can be mapped to the client id in the input to the operation
     *         to detect which object creation failed. For example, the input to createObjects (which
     *         is a vector of CreateIn) may be {{ "clientId1", createInput1},{"clientId2", createInput2}}.
     *         If the ServiceData contains clientId2 in the PartialList of errors, it is known that
     *         creation of the second object failed.
     *         <br>
     *         <br>
     *         One of the possible errors returned in ServiceData is:
     *         <br>
     *         214200 - Unable to create Business Object
     *         <br>
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Core::_2008_06::Datamanagement::CreateResponse createObjects ( const std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::CreateIn >& input ) = 0;

    /**
     * This operation creates the <b>Participant</b> objects and adds them to the input
     * Item Revision. If a <b>Participant</b> object with specified attributes already exists,
     * it is added to the Item Revision.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * For Change Management use cases, user may need to add different participants to the
     * change objects like analyst, change specialist etc. The creator of the change object
     * will assign the analyst for the change where this operation can be used.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Workflow - Component for Workflow elements
     *
     * @param addParticipantInfo
     *        Contains a list of <code>ParticipantInfo</code> structures with information about
     *        participants to be added and an Item Revision to add the participants to.
     *
     * @return
     *         The operation returns a list of participants structure and service data. Each element
     *         in the list contains an <b>ItemRevision</b> and a list of <b>Participant</b> objects
     *         that were added to it.
     *         <br>
     *         If the service fails to add the participant, it returns "SOACORE_failed_to_add_participants"
     *         error code.
     *         <br>
     *         If the service fails to create the participant, it returns "SOACORE_failed_to_create_participant"
     *         error code.
     *
     */
    virtual Teamcenter::Services::Core::_2008_06::Datamanagement::AddParticipantOutput addParticipants ( const std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::AddParticipantInfo >& addParticipantInfo ) = 0;

    /**
     * This operation allows the user to remove <b>Participant</b> objects associated with
     * specified Item Revision. If a participant being removed is no longer associated with
     * any other objects, it gets deleted.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation can be used to remove the assigned <b>Participant</b> objects like
     * Analyst, Proposed Reviewers etc. from the change objects. Change creator can use
     * <code>addParticipants</code> service operation to assign an analyst or use this operation
     * to remove an assigned analyst.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Workflow - Component for Workflow elements
     *
     * @param participants
     *        List of participants structures each containing a list of <b>Participant</b> objects
     *        to be removed and an Item Revision to remove the <b>Participant</b> objects from.
     *
     * @return
     *         The operation returns the service data. The updated Item Revision is added to the
     *         Updated list in the service data.
     *         <br>
     *         If the service fails to remove the participant, it returns "<code>SOACORE_failed_to_remove_participant</code>"
     *         error code.
     *         <br>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData removeParticipants ( const std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::Participants >& participants ) = 0;

    /**
     * This operation allows client applications to obtain the properties pertaining to
     * one or more <b>Table</b> Business Objects. Client developers will need to pass in
     * references to each <b>Table</b> that they need to query information on.  Note that
     * the input vector needs to contain only references to the Teamcenter Table business
     * object, this operation cannot be used to fetch properties of any other Business Objects.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation can be used by a client developer, when he/she deals with obtaining
     * specific <b>Table</b> Business Object specific properties. Typically, <b>Table</b>
     * Business Objects are not themselves visible in the Teamcenter workspace and appear
     * as properties of other owning objects that are visible in the workspace.  The typical
     * scenario in such cases is that a user attempts to obtain/view all properties of the
     * the owning object, which may have one or more reference properties pointing to a
     * Table.  A custom UI would need to display the Table related properties on the parent
     * object in such cases and rendering these properties would require the client applications
     * to obtain such information using the <i>getTableProperties</i> operation.
     * <br>
     * One such example of existing usage of this operation, is the existing Teamcenter
     * Rich Client functionality for viewing properties an Integer type of <i>Parameter
     * Definition</i> [ <b>ParmDefIntRevision</b> Business Object ]. This Business Object
     * and the functionality for viewing its properties are provided by the add on Calibration
     * and Configuration Data Management module, through custom stylesheets which render
     * a Table like UI for each referenced Table property.  At the time of rendering the
     * UI, the client operations call the <i>getTableProperties</i> operation to obtain
     * properties such as the number of rows, number of columns, labels for each row and
     * column, the type of the cells and cell values and descriptions for each cell in the
     * table.
     * <br>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * getProperties
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * CCDM - Calibration and Configuration Data Management
     *
     * @param table
     *        This is a vector of the Table Business Objects for which the properties need to be
     *        obtained.
     *
     * @return
     *         Returns GetTablePropertiesResponse
     *
     */
    virtual Teamcenter::Services::Core::_2009_10::Datamanagement::GetTablePropertiesResponse getTableProperties ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Table>  >& table ) = 0;

    /**
     * This operation allows client applications to set the properties pertaining to one
     * or more <b>Table</b> business objects. Client developers will need to set information
     * pertaining to the number of rows, columns, descriptions of each row and column, and
     * cell information for each cell of the <b>Table</b>. The cell information must contain
     * the type of cell, value to be placed in the cell, and optionally, a description of
     * those values. The current operation only works on cells of specific types and it
     * is mandatory that the type of the cells being set on the input structure corresponds
     * to one of the cell types defined in the database schema viewable through the BMIDE.
     * Supported valid types are:
     * <br>
     * <ul>
     * <li type="disc"><i>TableCellInt</i>
     * </li>
     * <li type="disc"><i>TableCellString</i>
     * </li>
     * <li type="disc"><i>TableCellDouble</i>
     * </li>
     * <li type="disc"><i>TableCellLogical</i>
     * </li>
     * <li type="disc"><i>TableCellHex</i>
     * </li>
     * <li type="disc"><i>TableCellSED</i>
     * </li>
     * <li type="disc"><i>TableCellBCD</i>
     * </li>
     * <li type="disc"><i>TableCellDate</i>
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation can be used by a client developer, when he/she deals with setting
     * <b>Table</b> Business Object specific properties. Typically, <b>Table</b> Business
     * Objects are not themselves visible in the Teamcenter workspace and appear as properties
     * of other owning objects that are visible in the workspace. Modification to the owning
     * objects, may involve changes to one or more of the Table properties that they reference
     * through the Table.  In such cases, the <i>setTableProperties</i> is to be called,
     * passing in the input structure which is setup to specify the modified values.
     * <br>
     * One such example of existing usage of this operation, is the existing Teamcenter
     * Rich Client functionality for modification of an Integer type of <i>Parameter Definition</i>
     * [ <b>ParmDefIntRevision</b> Business Object ]. This Business Object and the functionality
     * for its modification are provided by the add on Calibration and Configuration Data
     * Management module.  During modification, of the integer parameter definition object,
     * client code renders table like UI for each table property of the Parameter Definition,
     * gathers the input values from the UI and populates a vector of the input structure
     * of type <i>TableInfo</i>, sets the type of thecells to <i>TableCellInt</i> and makes
     * the operation call. Client code will then parse the Service Data returned from the
     * operation to obtain a handle to the updated <b>Table</b> Business Object. Errors,
     * if any were encountered during the operation execution, are handled via the Service
     * Data.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * CCDM - Calibration and Configuration Data Management
     *
     * @param tableData
     *        This vector contains a list of <i>TableInfo</i>, and each <i>TableInfo</i> contains
     *        information pertaining to the specific <b>Table</b> it references. The data present
     *        in the <i>TableInfo</i> structures are used to modify specific cell values and/or
     *        descriptions of the rows, columns or values.
     *
     * @return
     *         This operation returns a Service Data structure. The updated Table business objects
     *         are included in the updated service data member list, which contains any modifications
     *         to row and column descriptions and the size of the table. Any errors encountered
     *         at the time of modification are included as part of the Service Data errors.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData setTableProperties ( const std::vector< Teamcenter::Services::Core::_2009_10::Datamanagement::TableInfo >& tableData ) = 0;

    /**
     * This service retrieves <b>Item</b> and its related <b>ItemRevision</b> objects based
     * on the supplied attribute key-value pairs supplied in the <code>infos</code> list.
     * All the key-value pairs except for the <code>rev_id</code> key are used to create
     * a query for <b>Item</b> objects.
     * <br>
     * <br>
     * Once a set of <b>Item</b> objects have been retrieved, their <b>ItemRevision</b>
     * objects are retrieved based on the following rules:
     * <br>
     * <ul>
     * <li type="disc">If  <code>nRev</code> is a negative value then all the <b>ItemRevision</b>
     * objects are returned
     * </li>
     * <li type="disc">If <code>nRev</code> is a positive value then the <code>nRev</code>
     * most recent <b>ItemRevision</b> objects are returned. If <code>nRev</code> is greater
     * than the number of revisions then all of them are returned.
     * </li>
     * <li type="disc">If <code>nRev</code> is zero and a <code>rev_id</code> attribute
     * key was supplied in the attribute key-value pairs, then that <b>ItemRevision</b>
     * object is returned.
     * </li>
     * <li type="disc">If <code>nRev</code> is zero and rev ids values were supplied in
     * the <code>GetItemFromAttributeInfo</code> object then all of the specified rev ids
     * will be returned.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model Item - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of Teamcenter PLM platform. This component defines the Item
     * Class and behavior.
     *
     * @param infos
     *        The list of attribute value keys for the retrieval. The attributes must be the unique
     *        key attributes of the class. Currently, only item_id attribute should be used
     *
     * @param nRev
     *        Maximum number of <b>ItemRevision</b> objects to retrieve.
     *        <br>
     *        <ul>
     *        <li type="disc">nRev < 0        retrieve all available ItemRevision objects
     *        </li>
     *        <li type="disc">nRev = 0        retrieve no ItemRevision objects
     *        </li>
     *        <li type="disc">nRev > 0        retrieve the most recent nRev number of ItemRevision
     *        objects
     *        </li>
     *        </ul>
     *
     * @param pref
     *        <code>GetItemFromIdPref</code> object used to filter the returned <b>ItemRevision</b>
     *        objects. If a <b>Dataset</b> is found related to the <b>ItemRevision</b> with this
     *        relation type name and is one of the types specified in the list of object type names,
     *        return the <b>ItemRevision</b> object
     *
     * @return
     *         Retrieves the <b>Item</b> and <b>ItemRevision</b> objects.The following partial errors
     *         may be returned:
     *         <br>
     *         <ul>
     *         <li type="disc">48008 - If a specified item ID is not found
     *         </li>
     *         <li type="disc">48053 - If an item revision ID specified in the rev_id attribute
     *         key-value pair is not found
     *         </li>
     *         <li type="disc">48053 - If an item revision ID specified in the GetItemFromAttributeInfo
     *         revIds list is not found
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Core::_2009_10::Datamanagement::GetItemFromAttributeResponse getItemFromAttribute ( const std::vector< Teamcenter::Services::Core::_2009_10::Datamanagement::GetItemFromAttributeInfo >& infos,
        int nRev,
        const Teamcenter::Services::Core::_2007_01::Datamanagement::GetItemFromIdPref&  pref ) = 0;

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

    /**
     * This operation is provided to update Teamcenter object instances for the given name/value
     * pairs. This operation works for all supported property value types. Each object need
     * to be passed with its property name/value pairs.Passing options are <b>not</b> mandatory,
     * <b>empty</b> list is allowed. When <b>no</b> options are provided, it just updates
     * the objects as per the inputs. Alternatively you can pass following valid options
     * to control updating the data.
     * <br>
     * <ul>
     * <li type="disc"><b>QUERY</b>: option is used to define the overall behavior of object
     * properties setting from Excel Live and Word Live. Once this option is passed, server
     * honours the preference value of TC_setProperties. Please see the Preferences and
     * Environment Variables Reference documentation for preference TC_setProperties for
     * more information.
     * </li>
     * </ul>
     * <br>
     * Note:It must be the 0th element when set as in the option list.
     * <br>
     * <ul>
     * <li type="disc"><b>ENABLE_PSE_BULLETIN_BOARD</b>: To enable the generation of PSE
     * bulletin board events. These events are processed through Bulletin board callback
     * mechanism.
     * </li>
     * </ul>
     *
     * @param info
     *        List of PropInfo structure which consists of information about the objects and the
     *        property values to set.
     *
     * @param options
     *        To updating the objects in controlled manner. Valid options are:
     *        <br>
     *        <ul>
     *        <li type="disc"><b>No</b> options can be passed to update the objects as per the
     *        inputs.
     *        </li>
     *        <li type="disc"><b>QUERY</b> If this option is set please see the Preferences and
     *        Environment Variables Reference documentation for preference TC_setProperties for
     *        more information.
     *        </li>
     *        </ul>
     *        <br>
     *        Note: <b>QUERY</b> option must be the 0th element when set as in the option list.
     *        <br>
     *        <ul>
     *        <li type="disc"><b>ENABLE_PSE_BULLETIN_BOARD</b> To enable the generation of PSE
     *        bulletin board events.
     *        </li>
     *        </ul>
     *
     * @return
     *         Response structure for set Properties SOA.
     *
     */
    virtual Teamcenter::Services::Core::_2010_09::Datamanagement::SetPropertyResponse setProperties ( const std::vector< Teamcenter::Services::Core::_2010_09::Datamanagement::PropInfo >& info,
        const std::vector< std::string >& options ) = 0;

    /**
     * This operation checks if an extension exists on an operation of a specific type.
     *
     * @param extensionInfo
     *        The specific type, operation and extension information required to verify an extension
     *        exists.
     *
     * @return
     *         If extension exists.
     *
     */
    virtual Teamcenter::Services::Core::_2010_09::Datamanagement::VerifyExtensionResponse verifyExtension ( const std::vector< Teamcenter::Services::Core::_2010_09::Datamanagement::VerifyExtensionInfo >& extensionInfo ) = 0;

    /**
     * This creates a new Table along with Rows or updates an existing Table with rows and
     * their values based on input StaticTableInfo and created Table rows are added to the
     * Table. ServiceData is updated with newly created/updated Table.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation is used to create/update the data for TableProperties objects of Fnd0StaticTable
     * object. When user selects <b>Cdm0DataReqItemRevision</b> object, the attribute cdm0EventsList
     * is displayed in the summary as well as on View/Edit Properties menu in RAC. The attribute
     * cdm0EventsList is type referenced to <b>Fnd0StaticTable</b>.
     * <br>
     * User can add the data in columns for each row of the table or adds rows to the table
     * or deletes rows. After creation/updation of the table, user saves the object which
     * invokes this SOA operation.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * getStaticTableData
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Contract Data Management - Provides functionality to save or retrieve Event List
     * data for Data Requirement Item Revision
     *
     * @param staticTableInfo
     *        This represents static table object that needs to be created/updated.
     *
     * @param rowProperties
     *        Vector of RowData where each element is of type TableProperties
     *
     * @return
     *         Returns CreateOrUpdateStaticTableResponse with service data with table object which
     *         is created and created/updated row objects. This operation returns no errors internally.
     *         However, errors from following Teamcenter API calls are added to the ServiceData's
     *         error stack:
     *         <br>
     *         <ul>
     *         <li type="disc">POM_attr_id_of_attr()
     *         </li>
     *         <li type="disc">TCTYPE_ask_type()
     *         </li>
     *         <li type="disc">TCTYPE_ask_create_descriptor()
     *         </li>
     *         <li type="disc">TCTYPE_construct_create_input()
     *         </li>
     *         <li type="disc">TCTYPE_create_object()
     *         </li>
     *         <li type="disc">AOM_save_with_extensions()
     *         </li>
     *         <li type="disc">AOM_save()
     *         </li>
     *         <li type="disc">AttributeAccessor::appendTag()
     *         </li>
     *         <li type="disc">tableResponse.serviceData.addCreatedObject()
     *         </li>
     *         </ul>
     *         <br>
     *         (This list may be incomplete, and is subject to change without notice.)
     *
     */
    virtual Teamcenter::Services::Core::_2010_09::Datamanagement::CreateOrUpdateStaticTableDataResponse createOrUpdateStaticTableData ( const Teamcenter::Services::Core::_2010_09::Datamanagement::StaticTableInfo&  staticTableInfo,
        const std::vector< Teamcenter::Services::Core::_2010_09::Datamanagement::RowData >& rowProperties ) = 0;

    /**
     * Returns a list of objects of type TableProperties which are associated with <b>Fnd0StaticTable</b>
     * object. <b>Fnd0StaticTable</b> object has an attribute fnd0StaticTableData which
     * is an array of <b>TableProperties</b> objects.  Any failures will be returned with
     * the input object mapped to the error message in the ServiceData list of partial errors.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation is used to get the data for attribute fnd0StaticTableData of <b>Fnd0StaticTable</b>
     * object. Attribute fhd0StaticTableData is an array of TableProperties objects. When
     * user selects <b>Cdm0DataReqItemRevision</b> object, the attribute cdm0EventsList
     * is displayed in the summary as well as on View/Edit Properties menu in RAC. The attribute
     * cdm0EventsList is Typed Reference to <b>Fnd0StaticTable</b> object.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createOrUpdateStaticTableData
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Contract Data Management - Provides functionality to save or retrieve Event List
     * data for Data Requirement Item Revision
     *
     * @param staticTable
     *        StaticTable
     *
     * @return
     *         A list of <b>TableProperties</b> objects. One for each successfully created row of
     *         fnd0StaticTableData attribute of <b>Fnd0StaticTable</b> object. This operation returns
     *         no errors internally. However, errors from following Teamcenter API calls are added
     *         to the ServiceData's error stack:
     *         <br>
     *         <ul>
     *         <li type="disc">POM_attr_id_of_attr()
     *         </li>
     *         <li type="disc">AttributeAccessor::getTagValues()
     *         </li>
     *         <li type="disc">tableResponse.serviceData.addPlainObject()
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Core::_2010_09::Datamanagement::StaticTableDataResponse getStaticTableData ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Fnd0StaticTable>  staticTable ) = 0;

    /**
     * The <b>getEventTypes</b> operation retrieves the valid Auditable and Subscribable
     * events for each of the businessObject in the input <code>EventObject</code> vector.
     * When an event is auditable, you can audit actions on Teamcenter objects when that
     * event happens on the businessObject. When an event is Subscribable, that means subscriptions
     * can be created for that event. Partial failures, if any, will be returned in the
     * serviceData.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Subscription Management - Application that allows to subscribe to certain events
     * such as checkin etc on business objects.
     *
     * @param input
     *        A vector of <code>EventObject</code> structure consisting of list of Business Objects,
     *        for which the valid auditable and subscribable events are to be fetched.
     *
     * @return
     *         Output is a vector of eventsOutput structures packaged in a custom response. Partial
     *         failures will be returned in the ServiceData as a map of client id to error message.
     *
     */
    virtual Teamcenter::Services::Core::_2010_09::Datamanagement::EventTypesResponse getEventTypes ( const std::vector< Teamcenter::Services::Core::_2010_09::Datamanagement::EventObject >& input ) = 0;

    /**
     * This operation will post an event for each of the Teamcenter business objects in
     * the input list, with all the supplied information: <code>secondaryObject</code>,
     * properties to be logged, and the error details. . Partial failures will be returned
     * in the <code>serviceData</code>.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Most events are posted by Teamcenter server logic. Use this operation to make an
     * event known only to your client code recorded in Audit Manager or supported by Subscription
     * Manager.
     * <br>
     * <b>Use Case1</b>: Auditing events
     * <br>
     * This operation helps auditing Teamcenter objects history by logging audit records
     * when event eventTypeName occurs on primaryObject.
     * <br>
     * <ul>
     * <li type="disc">When site preference TC_audit_manager is set to ON and no Audit Definition
     * exists for object type primaryObject and the eventTypeName, no audit records will
     * be logged. Audit Definitions are Audit Manager Application configurations and can
     * be viewed in Audit Manager Application.
     * </li>
     * <li type="disc">When site preference TC_audit_manager is set to ON and Audit Definition
     * exists for object type primaryObject and the eventTypeName, audit records will be
     * logged with all the information provided in the structure PostEventObjectProperties
     * </li>
     * <li type="disc">No audit records are written when preference TC_audit_manager is
     * set to OFF or if the event posted is not defined as Auditable.
     * </li>
     * </ul>
     * <br>
     * <b>
     * <br>
     * Use Case2</b>: Subscription Notifications&nbsp;&nbsp;&nbsp;&nbsp;
     * <br>
     * the site preference TC_subscription is set to ON , users can create subscriptions
     * for notifications for certain events on Teamcenter Objects  The event posted must
     * be described as subscribable and there should also exist an associated subscription
     * object for the notification to occur.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Subscription Management - Application that allows to subscribe to certain events
     * such as checkin etc on business objects.
     *
     * @param input
     *        A vector of <code>ObjectProperties</code> structure. Each structure consists of Primary
     *        Business Object, a manadatory parameter, on which event has occurred, any secondary
     *        object to post its information, along with any additional properties and the values
     *        and error code while performing the event.
     *
     * @param eventTypeName
     *        Name of the event. This is a mandatory parameter and should be a valid auditable
     *        or subscribable event mapped for the primary object. List of valid event types could
     *        be found using command line utility: install_event_types
     *
     * @return
     *         <code>PostEventResponse</code>, a vector of <code>postEventOutput</code> structures
     *         packaged in a custom response of returning back the unique identifier <code>clientId</code>
     *         for tracking the operation with failure code(<code>ifailError</code>) if any. Success
     *         is defined by the return of ifailError for post event on each Business Object, primaryObject.
     *         If error is encountered while processing post event on elements in the set, it is
     *         reported as partial errors and processing continues for the remaining elements in
     *         the input set. Partial failures will be returned in the  serviceData.
     *
     *
     * @exception ServiceException
     *           Service Exception.
     *           <br>
     *           Throws ServiceException with error message, error code, error count and severity.
     *           Error code and message will be returned as per which audit or notification operation
     *           failed during processing.
     */
    virtual Teamcenter::Services::Core::_2010_09::Datamanagement::PostEventResponse postEvent ( const std::vector< Teamcenter::Services::Core::_2010_09::Datamanagement::PostEventObjectProperties >& input,
        const std::string&  eventTypeName ) = 0;

    /**
     * Validates and/or modifies the Revision Id based on the naming rules/revision naming
     * rules and user exit callbacks.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation is generally used to validate revision id before providing it as input
     * for create, revise and save-as operations.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Naming Rules - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of Teamcenter PLM platform. This component defines Naming
     * Rules and Revision Naming Rules.
     *
     * @param inputs
     *        A list of <code>ValidateRevIdsInfo</code> structures, each of which contain revId/itemObject/itemType
     *        that have to be validated.
     *
     * @return
     *         The response object containts a list of <code>ValidateRevIdsOutput</code> and <code>ServiceData</code>.
     *         The <code>ValidateRevIdsOutput</code> contains validation statuses for Revision Id.
     *         If the Ids are modified because of the Naming Rules/Revision Naming Rules, then the
     *         modified Revision Ids are returned. Any failure is returned in the <code>ServiceData</code>
     *         list of partial errors with index of <code>ValidateRevIdsInfo</code> mapped to error
     *         message.
     *         <br>
     *         <br>
     *         The following partial errors could be returned:
     *         <br>
     *         <ul>
     *         <li type="disc">74007&nbsp;&nbsp;&nbsp;&nbsp;Supplied item_revision_id value <code>inputs[index].revId</code>
     *         is invalid.
     *         </li>
     *         <li type="disc">74026&nbsp;&nbsp;&nbsp;&nbsp;Value must be between <code>Initial
     *         value</code> and <code>Maximum value</code>.
     *         </li>
     *         <li type="disc">74028&nbsp;&nbsp;&nbsp;&nbsp;The Revision ID cannot contain the following
     *         letters: <code>List of excluded letters</code>.
     *         </li>
     *         </ul>
     *         <br>
     *         <br>
     *         Other than this, errors thrown from any of the following Teamcenter system calls
     *         may be caught and added to the ServiceData's error stack:
     *         <br>
     *         <ul>
     *         <li type="disc">ITEM_ask_id()
     *         </li>
     *         <li type="disc">USER_validate_item_rev_id_3()
     *         </li>
     *         <li type="disc">ITEM_find_items_by_key_attributes()
     *         </li>
     *         </ul>
     *         <br>
     *         (This list may be incomplete, and is subject to change without notice.)
     *
     */
    virtual Teamcenter::Services::Core::_2011_06::Datamanagement::ValidateRevIdsResponse validateRevIds ( const std::vector< Teamcenter::Services::Core::_2011_06::Datamanagement::ValidateRevIdsInfo >& inputs ) = 0;

    /**
     * This operation is generic operation for saving of Business Objects. It will also
     * save any secondary objects that also need to be saved based on deep copy rule information
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Client constructs the SaveAs dialog for a Business Object using <code>OperationDescriptor.getSaveAsDesc</code>
     * operation.  The information returned by that operation allows client to construct
     * the SaveAs dialogs and DeepCopy panels for user input. Once the user input is received,
     * client can make subsequent invocation to this (<code>DataManagement.saveAsObjects</code>)
     * operation to execute SaveAs on the object.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * getSaveAsDesc
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Metamodel - Framework to define data model, operations, extensions and for autogeneration
     * of the underlying code for appropriate dispatching. It provides the framework for
     * codeless configuration and codeful customization.
     *
     * @param saveAsIn
     *        Input data containing target object and DeepCopyData of the attached objects
     *
     * @return
     *         The return contains a list of business objects representing the objects that were
     *         saved. Failure for any element in the input vector is returned as a Partial Error
     *         in the <code>ServiceData</code>. The Partial Error includes the index of the failed
     *         element from the input vector.
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Core::_2011_06::Datamanagement::SaveAsObjectsResponse saveAsObjects ( const std::vector< Teamcenter::Services::Core::_2011_06::Datamanagement::SaveAsIn >& saveAsIn ) = 0;

    /**
     * This operation will generate a Trace Report on the objects selected by user.  User
     * will get information about complying as well as defining objects which are connected
     * to selected object using <b> FND_TraceLink</b> or its subtype of GRM relation.
     * <br>
     * <br>
     * Trace links can be between following objects:
     * <br>
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1.&nbsp;&nbsp;&nbsp;&nbsp;Between
     * occurrences of an <b>ItemRevision</b>
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2.&nbsp;&nbsp;&nbsp;&nbsp;Between
     * <b>ItemRevisions</b>
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;3.&nbsp;&nbsp;&nbsp;&nbsp;Between
     * <b>Items</b>
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;4.&nbsp;&nbsp;&nbsp;&nbsp;Between
     * any two <b>WorkspaceObject</b>.
     * <br>
     * <br>
     * If indirect trace report flag is set to <b>true</b> during this operation, then user
     * will get trace report for <b>ItemRevision</b> if selected object is <b>Occurrence</b>,
     * and trace report for Items if selected objects is <b>ItemRevision</b> in addition
     * to direct trace report for the selected object.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Suppose user created trace link between Requirement R1 as start point and R2 as end
     * point and creates trace link from Requirement R3 as start and R1 as end point.
     * <br>
     * When user runs traceability report on R1 requirement he will get R2 object as complying
     * object and R3 will come as defining object.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Requirement Management - Application to manage Requirments in Tc
     *
     * @param input
     *        A TraceabilityInfoInput structure to generate a Trace Report.This input structure
     *        holds selected objects for which trace report needs to be generated, trace report
     *        type, if indirect report required, and base relation type.
     *
     * @return
     *         TraceabilityReportOutput structure holds vector of trace reports which gives the
     *         trace tree of defining and complying objects, including indirect tree if isIndirectTraceReportNeeded
     *         is true, and any failure is return in service data.
     *
     */
    virtual Teamcenter::Services::Core::_2011_06::Datamanagement::TraceabilityReportOutput getTraceReport ( const Teamcenter::Services::Core::_2011_06::Datamanagement::TraceabilityInfoInput&  input ) = 0;

    /**
     * This operation determines if the given <code>MultiFieldKey</code> properties are
     * unique based on the <code>MultiFieldKey</code> definition.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Use this operation before creating a new object to validate if the <code>MultiFieldKey</code>
     * property combination is already used.  This is an existence check rather than a true
     * validation. It does not validate the property values against Naming Rules.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model Item - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of Teamcenter PLM platform. This component defines the Item
     * Class and behavior.
     *
     * @param input
     *        A list of MultiFieldKey attribute/value pairs for the object to be created
     *
     * @return
     *         A list of <code>MultiFieldKey</code> attribute/value pairs for the object to be created.
     *
     */
    virtual Teamcenter::Services::Core::_2012_02::Datamanagement::ValidationResponse validateIdValue ( const std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::CreateIn >& input ) = 0;

    /**
     * This is a generic operation for bulk creation of Business Objects. This will create
     * instances of the given quantity of the specified type in their specified containing
     * folders. This will also create any secondary(compounded) objects that need to be
     * created, assuming the <code>CreateInput</code> for the secondary object is represented
     * in the recursive <code>CreateInput</code> object e.g. <b>Item</b> is Primary Object
     * that also creates<b> Item Master</b>, <b>ItemRevision</b> and <b>ItemRevision</b>
     * in turn creates <b>ItemRevision</b> <b>Master</b>. The input for all these levels
     * is passed in through the recursive <code>CreateInput</code> object. This operation
     * is applicable for bulk creation of <b>Item</b>, <b>Form</b> and <b>Dataset</b> Types
     * only.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * To create large number of objects of specified types namely <b>Item</b>, <b>Dataset</b>
     * and <b>Form</b> each of specified quantities and save them through a single transaction
     * to significantly reduce the number of sql queries incurred during object creation,
     * thus improving object creation performance and making object creation scalable.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createFolders
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Metamodel - Framework to define data model, operations, extensions and for autogeneration
     * of the underlying code for appropriate dispatching. It provides the framework for
     * codeless configuration and codeful customization.
     *
     * @param input
     *        A vector of <code>BulkCreIn</code> structures representing the <code>CreateInput</code>
     *        for the bulk creation of business objects of the specified quantity for each type.
     *
     * @return
     *         A list of newly created objects, one for each specified type of specified quantity
     *         in the input <code>BulkCreIn</code> structure. This operation does not support Partial
     *         Errors.
     *         <br>
     *         <br>
     *         For Example,  to create Items of quantity 5 and Documents of quantity 4, we specify
     *         an input vector of two <code>BulkCreIn</code> structures, one each refering to <b>Item</b>
     *         and <b>Document</b> business objects respectively.
     *
     */
    virtual Teamcenter::Services::Core::_2008_06::Datamanagement::CreateResponse bulkCreateObjects ( const std::vector< Teamcenter::Services::Core::_2012_02::Datamanagement::BulkCreIn >& input ) = 0;

    /**
     * The <code>whereUsed</code> service identifies all the parent <b>Item</b> and <b>ItemRevision</b>
     * objects in the structure where the input <b>Item</b> or <b>ItemRevision</b> is used.
     * User can provide <b>RevisionRule</b> to search for specific <b>ItemRevision</b> .
     * By default all <b>ItemRevision</b> objects are returned. The number of levels of
     * <code>whereUsed</code> search indicates, whether to return one or top or all levels
     * of assemblies. It supports <code>whereUsed</code> search on any <b>WorkspaceObject</b>
     * which implements the "<code>whereUsed</code>" interface.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * A user performs <code>whereUsed</code> search to find all the assemblies that contain
     * a particular <b>Item</b> or <b>ItemRevision</b>. User inputs <b>Item</b> or <b>ItemRevision</b>
     * and the search can be made with following options:
     * <br>
     * <ul>
     * <li type="disc"><b>RevisionRule</b>  This can be set to All, displaying all <b>ItemRevision</b>
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
     * @param input
     *        <code>WhereUsedInputData</code> object list
     *
     * @param configParams
     *        Additional Configuration Parameters if required. For example <code>tagMap</code>
     *        to specify the <b>RevisionRule</b>, <code>boolMap</code> to specify whereUsedPreciseFlag,
     *        and <code>intMap</code> tp specify number of levels .
     *
     * @return
     *         Contains input object and for each input object, the parent object(s) found and the
     *         level at which it was found.
     *         <br>
     *         Failure will be returned via <code>ServiceData</code> with original input object
     *         mapped to error message.
     *         <br>
     *         214110&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The
     *         input object is not valid
     *         <br>
     *         27074&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<code>whereUsed</code>
     *         funtionality is not supported for this object
     *         <br>
     *         <br>
     *
     */
    virtual Teamcenter::Services::Core::_2012_02::Datamanagement::WhereUsedResponse whereUsed ( const std::vector< Teamcenter::Services::Core::_2012_02::Datamanagement::WhereUsedInputData >& input,
        const Teamcenter::Services::Core::_2012_02::Datamanagement::WhereUsedConfigParameters&  configParams ) = 0;

    /**
     * This operation saves the given object and its related objects as new instances. Related
     * objects are identifed using deep copy rules. Optionally,this method relates the new
     * object to the input target object or to a default folder.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Metamodel - Framework to define data model, operations, extensions and for autogeneration
     * of the underlying code for appropriate dispatching. It provides the framework for
     * codeless configuration and codeful customization.
     *
     * @param saveAsInput
     *        The property values to be used for the new objects. The properties passed in should
     *        be defined in SaveAs descriptor.
     *
     * @param relateInfo
     *        The paste options used to relate the newly created object.
     *
     * @return
     *         A list of objects that are created through saveas operation, including children objects.
     *         CreatedList contains objects that are created by SaveAs operation.. It contains GRM
     *         relations created due to paste operation. UpdatedList contains target objects to
     *         which the newly created objects are related. Failure for any element in the input
     *         list is returned as a Partial Error in the ServiceData . The Partial Error includes
     *         the index of the failed element from the input list. 214424: SaveAs action succeeded.
     *         But server could not identify a suitable target object to relate the newly created
     *         object.. 214425:  When item revision is saved as new instance,server relates item
     *         to target folder. Presence of this error code indicates that server could not paste
     *         item and instead has pasted the created item revision. 214426: SaveAs operation on
     *         that specifc object has failed.
     *
     */
    virtual Teamcenter::Services::Core::_2011_06::Datamanagement::SaveAsObjectsResponse saveAsObjectAndRelate ( const std::vector< Teamcenter::Services::Core::_2011_06::Datamanagement::SaveAsIn >& saveAsInput,
        const std::vector< Teamcenter::Services::Core::_2012_09::Datamanagement::RelateInfoIn >& relateInfo ) = 0;

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


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DatamanagementService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/core/Core_undef.h>
#endif

