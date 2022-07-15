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

#ifndef TEAMCENTER_SERVICES_CHANGEMANAGEMENT__2008_06_CHANGEMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_CHANGEMANAGEMENT__2008_06_CHANGEMANAGEMENT_HXX

#include <teamcenter/soa/client/model/BOMEdit.hxx>
#include <teamcenter/soa/client/model/BOMSupersedure.hxx>
#include <teamcenter/soa/client/model/BOMWindow.hxx>
#include <teamcenter/soa/client/model/ChangeItem.hxx>
#include <teamcenter/soa/client/model/ChangeItemRevision.hxx>
#include <teamcenter/soa/client/model/PSBOMViewRevision.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/changemanagement/ChangeManagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Changemanagement
        {
            namespace _2008_06
            {
                class Changemanagement;

class TCSOACHANGEMANAGEMENTSTRONGMNGD_API Changemanagement
{
public:

    struct ConfigureChangeSearchData;
    struct CreateBOMEditInput;
    struct CreateBOMEditResponse;
    struct CreateChangeItemInputs;
    struct CreateChangeItemsOutput;
    struct CreateChangeItemsResponse;
    struct ExtendedAttributes;
    struct CreateSupercedureInput;
    struct CreateSupercedureOutput;
    struct CreateSupercedureResponse;
    struct FindContextDataInputs;
    struct FindContextDataOutput;
    struct FindContextDataResponse;
    struct FindSupersedureOutput;
    struct FindSupersedureResponse;
    struct GetAllChangeHomeFolderResponse;
    struct GetBOMEditInput;
    struct GetBOMEditOutput;
    struct GetBOMEditResponse;
    struct RelationshipData;
    struct UpdateChangeProperties;
    struct UpdateSupercedureData;

    /**
     * <code>ConfigureChangeSearchData</code> structure represents all the details of a
     * Change Home folder.
     */
    struct ConfigureChangeSearchData
    {
        /**
         * Name of the folder
         */
        std::string name;
        /**
         * Indicates if the folder is visible or not visible.
         */
        bool visible;
        /**
         * Indicates the name of the query.
         */
        std::string queryName;
        /**
         * Indicates the name of the saved search name.
         */
        std::string savedSearchName;
        /**
         * Indicates saved query criterias.
         */
        std::vector< std::string > queryCriteria;
        /**
         * Indicates saved query values.
         */
        std::vector< std::string > queryValues;
        /**
         * Indicates folder is site level or user level and default is user level which is false.
         */
        bool isFolderSiteLevel;
        /**
         * Indicates folder to be added or removed to add value should be Add and to delete
         * value should be Remove.
         */
        std::string operation;
    };

    /**
     * <code>CreateBOMEditInput</code> structure contains the object reference to the associated
     * change revision, and the object references to the two BOM windows.  The referenced
     * objects will provide the necessary details to create a number of BOMEdit objects
     * that represents the whole BOM Change.
     */
    struct CreateBOMEditInput
    {
        /**
         * A reference to the revision of the change item.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ChangeItemRevision>  changeRev;
        /**
         * A reference to the BOM window containing the BOM view Revision of Solution Item Revision
         * for the given change objects.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMWindow>  firstWindow;
        /**
         * A reference to the BOM window containing the BOM view Revision of Impacted Item Revision
         * for the given change objects.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMWindow>  secondWindow;
    };

    /**
     * CreateBOMEditResponse structure contains an empty output, and a standard ServiceData.
     */
    struct CreateBOMEditResponse
    {
        /**
         * A reference to list of BOMEdits.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMEdit>  > output;
        /**
         * Standard ServiceData member
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Input structure for holding create change item input.
     */
    struct CreateChangeItemInputs
    {
        /**
         * Tracking client invoking this method this information not persisted, Optional
         */
        std::string clientID;
        /**
         * iD
         */
        std::string iD;
        /**
         * The revision ID that will be set on the new object, Required
         */
        std::string revisionID;
        /**
         * Name that will be used on the new object, Required
         */
        std::string name;
        /**
         * Description that will be used on the new object, Required
         */
        std::string description;
        /**
         * This will be used to determine what type of change item that is to be created, Required
         */
        std::string type;
        /**
         * The list of objects and their relations to the change item, Optional
         */
        std::vector< Teamcenter::Services::Changemanagement::_2008_06::Changemanagement::RelationshipData > relationshipData;
        /**
         * The list of additional attributes that might be passed from a client, Optional
         */
        std::vector< Teamcenter::Services::Changemanagement::_2008_06::Changemanagement::ExtendedAttributes > extendedData;
    };

    /**
     * Output structure for createChangeItems operation
     */
    struct CreateChangeItemsOutput
    {
        /**
         * Identifier that helps the client to track the object(s) created.
         */
        std::string clientId;
        /**
         * Change item object reference that was created.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ChangeItem>  changeItem;
        /**
         * change item revision that is created.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ChangeItemRevision>  itemRev;
    };

    /**
     * Response structure for createItems operation
     */
    struct CreateChangeItemsResponse
    {
        /**
         * A list of CreateChangeItemsOutput
         */
        std::vector< Teamcenter::Services::Changemanagement::_2008_06::Changemanagement::CreateChangeItemsOutput > output;
        /**
         * Standard ServiceData member
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Input structure for createItems operation to support setting attribute values on
     * the created Item, ItemRevision, or corresponding master forms that may be created
     * with the objects.
     */
    struct ExtendedAttributes
    {
        /**
         * The name of the attribte to modify or change or update.
         */
        std::string attributeName;
        /**
         * Values for the attribute ateast must have one value.
         */
        std::vector< std::string > values;
    };

    /**
     * Input structure for createSupercedures operation
     */
    struct CreateSupercedureInput
    {
        /**
         * A unique client identifier. This is a unique string supplied by the caller. This
         * ID
         * <br>
         * is used to identify return data elements and partial errors associated with this
         * input structure.
         * <br>
         */
        std::string clientID;
        /**
         * This parameter represents a reference to the solution item BOM View Revision
         * <br>
         * (BVR) and is a required parameter. A solution item is a new component that replaces
         * an old component in the parent assembly. Solution items are supplementary components
         * that are involved in the solution the change is bringing about and the affected item
         * represents the final assembly product containing the solution items.
         * <br>
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PSBOMViewRevision>  solutionBvr;
        /**
         * This required parameter determines if the Supercedure created is a transfer type
         * <br>
         * Supercedure and takes in a boolean true or false value. Transfer Supercedures are
         * generated when a component is moved from one assembly to another.
         * <br>
         */
        bool isTransferred;
        /**
         * A list of BOM Adds which represents the additions made to the assembly. It is a
         * <br>
         * required input element.
         * <br>
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > bomAdds;
        /**
         * A list of BOM Cancels which denotes the deletions made from the assembly and
         * <br>
         * is a required input parameter.
         * <br>
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > bomCancels;
        /**
         * A placeholder for additional attributes and this is an optional parameter. i.e it
         * can be empty.
         * <br>
         */
        Teamcenter::Services::Changemanagement::_2008_06::Changemanagement::ExtendedAttributes extendedAttributes;
    };

    /**
     * Output structure for createSupercedures operation
     */
    struct CreateSupercedureOutput
    {
        /**
         * Identifier that helps the client to track the object(s) created.
         */
        std::string clientId;
        /**
         * List of tags to the supercedure reference that was created
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > supercedure;
    };

    /**
     * Response structure containing list of Supercedure objects and partial errors.
     */
    struct CreateSupercedureResponse
    {
        /**
         * This represents a list of created Supercedure objects.
         */
        std::vector< Teamcenter::Services::Changemanagement::_2008_06::Changemanagement::CreateSupercedureOutput > output;
        /**
         * The SOA framework object containing Supercedure objects that were created
         * <br>
         * based on the input and error information returned based on validations performed.
         * <br>
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * <code>FindContextDataInputs</code> structure contains an object reference to a change
     * revision, a pair of object references to any Business Object type, and a context
     * string which determines what and how the input objects will be used to obtain the
     * desired output objects.
     */
    struct FindContextDataInputs
    {
        /**
         * An object reference to a change revision.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ChangeItemRevision>  changeRev;
        /**
         * An object reference to any BO type.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  primaryContextInputData;
        /**
         * An object reference to any BO type.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  secondaryContextInputData;
        /**
         * A context string.
         */
        std::string contextRelName;
    };

    /**
     * <code>FindContextDataOutput</code> structure contains an object reference that can
     * be used to point to a change revision, a list that can be used to hold any number
     * of returned business objects, and a list of counts to help sort out the Adds and
     * the Cancels from the returned object list.
     */
    struct FindContextDataOutput
    {
        /**
         * A reference to change revision. Can be empty.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ChangeItemRevision>  changeRev;
        /**
         * A list to hold any number of returned business objects.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > contextOutputData;
        /**
         * A list of counts used to sort out the Adds and the Cancels.
         */
        std::vector< int > vBomEditCount;
    };

    /**
     * <code>FindContextDataResponse</code> structure contains a list of <code>FindContextDataOutput</code>
     * structures and a service data.
     */
    struct FindContextDataResponse
    {
        /**
         * A list of <code>FindContextDataOutput</code> structures.
         */
        std::vector< Teamcenter::Services::Changemanagement::_2008_06::Changemanagement::FindContextDataOutput > output;
        /**
         * A service data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Output structure find supercedure.
     */
    struct FindSupersedureOutput
    {
        /**
         * A list of reference to supersedure.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMSupersedure>  > findsupercedure;
        /**
         * A reference to BOMEdit to which a supersedure is associated to.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMEdit>  bomedit;
    };

    /**
     * Output structure for list of BOMSupersedure and ServiceData.
     */
    struct FindSupersedureResponse
    {
        /**
         * A reference to list of supersedures.
         */
        std::vector< Teamcenter::Services::Changemanagement::_2008_06::Changemanagement::FindSupersedureOutput > supersedureOutput;
        /**
         * The SOA framework object containing Supercedure objects that were
         * <br>
         * returned based on the input and error information returned based on validations performed.
         * <br>
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * <code>GetAllChangeHomeFolderResponse</code> structure encapsulates the list of returned
     * Change Home folders as a vector of <code>ConfigureChangeSearchData</code> structures,
     * in addition to the standard mandatory <code>ServiceData</code> structure.
     */
    struct GetAllChangeHomeFolderResponse
    {
        /**
         * A vector of <code>ConfigureChangeSearchData</code> structures which represent the
         * details of change home folders
         */
        std::vector< Teamcenter::Services::Changemanagement::_2008_06::Changemanagement::ConfigureChangeSearchData > output;
        /**
         * Standard ServiceData member
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * <code>GetBOMEditInput</code> structure represents a set of criteria for finding any
     * existing BOMEdit object(s) that satisfy the criteria.  It is possible that none satisfies
     * the input criteria.
     */
    struct GetBOMEditInput
    {
        /**
         * A reference to the revision of the change item, Required.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ChangeItemRevision>  changeRev;
        /**
         * Reference to PSBOMViewRevision of the affected item, Required
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PSBOMViewRevision>  affectedBvr;
        /**
         * The type of this BOMEdit valid integer values are 1 to 10. BOM_Add=1,BOM_Cancel=2,
         * BOM_Quantity_Change=3, BOM_Move=4,BOM_Reshape=5,BOM_Note_Change=6,BOM_Variant_Change=7,LBOM_Add=8,LBOM_Cancel=9,
         * and LBOM_Quantity_Change=10
         */
        int bomEditType;
    };

    /**
     * GetBOMEditOutput structure contains a list of BOMEdit objects and the associated
     * change revision object. The list contains the BOMEdit objects that satisfy the input
     * criteria as represented by the corresponding GetBOMEditInput structure, and it can
     * be empty.
     */
    struct GetBOMEditOutput
    {
        /**
         * The BOMEdit objects that satisfy the input criteria as represented by the corresponding
         * GetBOMEditInput structure. This can be empty.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMEdit>  > bomEdits;
        /**
         * The change revision associated with the returned BOMEdit object(s).
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ChangeItemRevision>  changeRev;
    };

    /**
     * <code>GetBOMEditResponse</code> structure contains a list of <code>GetBOMEditOutput</code>
     * structures and a standard ServiceData.
     */
    struct GetBOMEditResponse
    {
        /**
         * A vector of <code>GetBOMEditOutput</code> structures.  See <code>GetBOMEditOutput</code>
         * section below for more details.  This can be empty.
         */
        std::vector< Teamcenter::Services::Changemanagement::_2008_06::Changemanagement::GetBOMEditOutput > bomEditOutput;
        /**
         * Standard ServiceData member
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Input structure for holding relationship data.
     */
    struct RelationshipData
    {
        /**
         * List of object references used to hold the objects to put in the relationship, Required
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > tags;
        /**
         * Name of relationship to be created, Required
         */
        std::string relTypeName;
        /**
         * Flag indicating weather to add or remove relationship, Required
         */
        std::string operation;
    };

    /**
     * Input structure for updateChangeItems operation
     */
    struct UpdateChangeProperties
    {
        /**
         * A reference to the revision of the change item  that to be updated, Required
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ChangeItemRevision>  chgRev;
        /**
         * A vector of the property values, Optional
         */
        std::vector< Teamcenter::Services::Changemanagement::_2008_06::Changemanagement::ExtendedAttributes > newPropertyValues;
        /**
         * A vector of  of relationship data , Optional
         */
        std::vector< Teamcenter::Services::Changemanagement::_2008_06::Changemanagement::RelationshipData > newRelationshipData;
    };

    /**
     * Structure for <code>updateSupercedures</code> operation.
     */
    struct UpdateSupercedureData
    {
        /**
         * A flag value indicating if the update operation is to be carried out on
         * <br>
         * BOMAdds or BOMCancels. This parameter uses Change Management BOM_ADD or BOM_CANCEL
         * constants.
         * <br>
         */
        std::string bomAddOrCancleFlag;
        /**
         * A flag indicating whether to add or remove components from the
         * <br>
         * Supercedure. The parameter uses Change Management constants OPERARTION_TYPE_ADD or
         * OPERATION_TYPE_CANCEL.
         * <br>
         */
        std::string operation;
        /**
         * A list of tag values to be added or removed.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > tags;
        /**
         * This input element represents the tag for the Supercedure to be updated.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  supTag;
    };




    /**
     * Add or remove a change specific searches folder with the given inputs.  This operation
     * is created to support the Manage Saved Search capability for Change Home within Change
     * Manager.  It is important to note that, if called directly, there is a possibility
     * of overwriting any pre existing configurations for Change Home, at site and/or user
     * level.  So, <b>USE IT WITH CAUTION</b>.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Adding and Removing change home folder(s)</b>
     * <br>
     * This can be accomplished by calling the <code>configureChangeSearches</code> operation
     * with a list of <code>ConfigureChangeSearchData</code> structures which specify a
     * number of necessary attributes of the folders to be created or removed.  Each <code>ConfigureChangeSearchData</code>
     * structure will contain the name of the folder (which should be unique), a visible/invisible
     * indicator, the saved search/query associated with the folder, any query criteria
     * and their corresponding values, a site/user level indicator, and an add/remove operation
     * indicator.  A site level folder is available to all site users, whereas a user level
     * folder is available only to the user of the current user session.  The add/remove
     * operation indicator will determine if the operation is to add or to remove the folder.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Change Management - This Component is intended to identify all Operations and Services
     * under Change Management.
     *
     * @param input
     *        Structures containing the details of the folders to be added or removed.
     *
     * @return
     *         A standard Service data. Following are some possible errors returned in <code>ServiceData</code>:
     *         <br>
     *         <ul>
     *         <li type="disc">1023&nbsp;&nbsp;&nbsp;&nbsp;Unable to allocate memory
     *         </li>
     *         <li type="disc">1700&nbsp;&nbsp;&nbsp;&nbsp;Preference not found
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData configureChangeSearches ( const std::vector< Teamcenter::Services::Changemanagement::_2008_06::Changemanagement::ConfigureChangeSearchData >& input ) = 0;

    /**
     * This operation is to support the creation of BOM Change in Structure Manager.  A
     * number of <b>BOMEdit</b> objects are created when the solution item BOMViewRevision
     * (BVR) is saved and then compared to the impacted item BVR in two side by side BOM
     * windows.  Central to this operation is the change revision object that ties all the
     * <b>BOMEdit</b> objects together to represent the whole BOM Change.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Creating a BOM Change within the Structure Manager</b>
     * <br>
     * A change revision has been created with an identified impacted item.  A user working
     * on a solution will first revise the impacted item, relate the new revision to the
     * change revision as solution item, and then make structural changes to the new revision
     * in Structure Manager. When the work is complete, the solution item is saved.   The
     * save operation will detect if the object saved is associated with a change revision
     * as the solution item.  If it is, it will proceed to render the solution item and
     * the impacted item in two side by side BOM windows, and then invoke the <code>createBOMEdits</code>
     * operation via an instance of the <code>ChangeManagementService</code> with the <code>CreateBOMEditInput</code>
     * structure that contains the associated change revision and the two BOM windows .
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Change Management - This Component is intended to identify all Operations and Services
     * under Change Management.
     *
     * @param bomEditRequest
     *        A vector of <code>CreateBOMEditInput</code> structures, each providing the necessary
     *        input arguments for constructing a <b>BOMEdit</b> object.
     *
     * @return
     *         <code>CreateBOMEditResponse</code> which contains a list of <b>BOMEdit</b> object
     *         references and a standard <code>ServiceData</code>.  Following are some possible
     *         error(s) returned in ServiceData:
     *         <br>
     *         <ul>
     *         <li type="disc">233029&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The relation
     *         between the solution and the impacted is not found.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Changemanagement::_2008_06::Changemanagement::CreateBOMEditResponse createBOMEdits ( const std::vector< Teamcenter::Services::Changemanagement::_2008_06::Changemanagement::CreateBOMEditInput >& bomEditRequest ) = 0;

    /**
     * Creates an list of Change Items of specified type and any associated data with each
     * change item including Change Item Revision, Change Item Master Form, and Change Item
     * Revision Master form based on the input attribute structures. Also it creates relationship
     * between the objects passed as in input properties and assigns created change item
     * to a specified user as requestor, analyst, admin or role that is specified in the
     * input. It also updates any additional properties of the change item that is passed
     * in the input. If the relation data contains a change item an attempt will be made
     * to propagate values from this parent change item to the newly create item based on
     * the propagation rules defined in the change configuration also an attempt will be
     * made to create the prpoer types of relations between the change item that is created
     * and input objects. Incase of Problem Report (PR) if the CMRoles is empty the requestor
     * of the PR will be the same as the creator of the PR.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Change Management - This Component is intended to identify all Operations and Services
     * under Change Management.
     *
     * @param changeItemProps
     *        a list of CreateChangeItemInputs structures
     *
     * @return
     *         contains a list of CreateChangeItemsOutput structures (which contain the newly created
     *         change item and its revision and clientID). Any failure will be returned with client
     *         id mapped to error message in the standard ServiceData list of partial errors.
     *
     * @deprecated
     *         As of Teamcenter 10, this service operation is no longer needed as its purpose can
     *         be served by Teamcenter::Soa::Core::createObjects operation.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 10, this service operation is no longer needed as its purpose can be served by Teamcenter::Soa::Core::createObjects operation."))
#endif
    virtual Teamcenter::Services::Changemanagement::_2008_06::Changemanagement::CreateChangeItemsResponse createChangeItems ( const std::vector< Teamcenter::Services::Changemanagement::_2008_06::Changemanagement::CreateChangeItemInputs >& changeItemProps ) = 0;

    /**
     * This operation creates <b>Supercedure</b> objects for each <code>CreateSupercedureInput</code>
     * supplied. A Supercedure represents a relation that graphically displays the deleted
     * components and the new components that replace them. Transfer Supercedure is a specific
     * type that is created where a component is transferred from one assembly to another
     * level in a different assembly.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * An assembly modification results in the components being added to or removed from
     * the assembly. Supercedure is a component replacement where a user specifically marks
     * one or more added components with one or more removals. This use case is accomplished
     * by the <code>createSupercedure</code> operation. The Supercedure is created from:
     * <br>
     * <ul>
     * <li type="disc">The original product structure
     * </li>
     * <li type="disc">The new product structure which is currently being edited in response
     * to change.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Change Management - This Component is intended to identify all Operations and Services
     * under Change Management.
     *
     * @param supercedureProperties
     *        Input parameter that is a list of <code>CreateSupercedureInput</code> structure.
     *        This comprises of elements that contains input information necessary to create Supersedure
     *        objects.
     *
     * @return
     *         <code>CreateSupercedureResponse</code> object which contains clientID and created
     *         Supercedures (WSO). Any failure will be reported in the standard Service data under
     *         partial errors.
     *
     */
    virtual Teamcenter::Services::Changemanagement::_2008_06::Changemanagement::CreateSupercedureResponse createSupercedures ( const std::vector< Teamcenter::Services::Changemanagement::_2008_06::Changemanagement::CreateSupercedureInput >& supercedureProperties ) = 0;

    /**
     * This operation deletes the Supercedures specified as the input parameter. A Supercedure
     * defines the relationship between any number of additions or deletions implemented
     * within a Bill of Material (BOM) assembly. The <code>deleteSupercedures</code> enables
     * a user to remove a Supercedure or delete a BOM add/cancel from a Supercedure.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * A user can delete the supercedures by calling the <code>deleteSupercedures</code>
     * which takes in the list of Supercedure objects as input parameter.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Change Management - This Component is intended to identify all Operations and Services
     * under Change Management.
     *
     * @param supercedureTobeDeleted
     *        a list of Tags for Supercedures to be deleted.
     *
     * @return
     *         A standard Service data which contains a list of deleted objects (Supercedures).
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData deleteSupercedures ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& supercedureTobeDeleted ) = 0;

    /**
     * This operation provides a flexible way of retrieving objects or data for a variety
     * of contexts to satisfy the RichClient usability requirements for BOM Change, Supersedure,
     * and Genealogy in Teamcenter Structure Manager.  There are helper functions in the
     * RichClient to facilitate the consumption and conversion of the retrieved information.
     * In other words, this operation may pose challenges to users of this operation who
     * are unfamiliar with the intended usage of the returned details.  For RichClient developers,
     * it is better to use the helper functions instead.
     * <br>
     * The context is specified by the context string <code>contextRelName</code> of an
     * input structure, and based on the specified context, different input arguments can
     * be supplied via a change revision object reference, and/or a pair of generic business
     * object references.  The objects or data returned will be captured in an output structure.
     * The following are the possible values for the context string:
     * <br>
     * <ul>
     * <li type="disc">CM_impacted_of_solution
     * </li>
     * <li type="disc">CM_associated_change
     * </li>
     * <li type="disc">CM_supersedure_of_bomedit
     * </li>
     * <li type="disc">CM_bomedits_of_occ
     * </li>
     * <li type="disc">CM_supersedures_of_solution
     * </li>
     * <li type="disc">CM_get_supersedures_of_bomcancel
     * </li>
     * <li type="disc">CM_get_supersedures_of_bomadd
     * </li>
     * <li type="disc">CM_get_first_supersedure
     * </li>
     * <li type="disc">CM_get_pure_adds_cancels
     * </li>
     * <li type="disc">CM_get_supersedure_for_WU
     * </li>
     * <li type="disc">CM_get_pureAddsCancels_for_WU
     * </li>
     * <li type="disc">CM_get_change_of_supersedure
     * </li>
     * <li type="disc">CM_get_initial_rendering_details
     * </li>
     * <li type="disc">CM_refresh_rendering_without_supersedure
     * </li>
     * <li type="disc">CM_refresh_rendering_with_supersedure
     * </li>
     * <li type="disc">CM_get_bomline_adds
     * </li>
     * <li type="disc">CM_get_bomline_cancels
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Use Case 1: Finding the impacted item given a change revision and a solution item</b>
     * <br>
     * For the input structure <code>FindContextDataInputs</code>,use CM_impacted_of_solution
     * for <code>contextRelName</code>, supply the change revision as <code>changeRev</code>
     * and the solution item as <code>primaryContextInputData</code>.  The requested impacted
     * item can be found in the object list <code>contextOutputData</code> of the corresponding
     * output structure <code>FindContextDataOutput</code>.
     * <br>
     * <b>Use Case 2: Finding the associated change revision given a solution item</b>
     * <br>
     * For the input structure <code>FindContextDataInputs</code>,use CM_associated_change
     * for <code>contextRelName</code>, supply the solution item as <code>primaryContextInputData</code>.
     * The requested associated change revision can be found in the <code>changeRev</code>
     * of the corresponding output structure <code>FindContextDataOutput</code>.
     * <br>
     * <b>Use Case 3: Finding the supersedure given a BOMEdit object</b>
     * <br>
     * For the input structure <code>FindContextDataInputs</code>,use CM_supersedure_of_bomedit
     * for <code>contextRelName</code>, supply the BOMEdit object as <code>primaryContextInputData</code>.
     * The requested supersedure can be found in the object list of the corresponding output
     * structure <code>FindContextDataOutput</code>.
     * <br>
     * <b>Use Case 4: Finding all the BOMEdit objects associated with a given Occurrence</b>
     * <br>
     * For the input structure <code>FindContextDataInputs</code>,use CM_bomedits_of_occ
     * for <code>contextRelName</code>, supply the occurrence object as <code>primaryContextInputData</code>.
     * The requested BOMEdit object can be found in the object list of the corresponding
     * output structure <code>FindContextDataOutput</code>.
     * <br>
     * <b>Use Case 5: Finding all supersedures created for a given solution item</b>
     * <br>
     * For the input structure <code>FindContextDataInputs</code>,use CM_supersedures_of_solution
     * for <code>contextRelName</code>, supply the solution item as <code>primaryContextInputData</code>.
     * The requested supersedure objects can be found in the object list <code>contextOutputData</code>
     * of the corresponding output structure <code>FindContextDataOutput</code>.
     * <br>
     * <b>Use Case 6: Finding all the supersedures associated with a given BOMEdit of type
     * cancel</b>
     * <br>
     * For the input structure <code>FindContextDataInputs</code>,use CM_get_supersedures_of_bomcancel
     * for <code>contextRelName</code>, supply the BOMEdit object as <code>primaryContextInputData</code>.
     * The requested supersedure objects can be found in the object list <code>contextOutputData</code>
     * of the corresponding output structure <code>FindContextDataOutput</code>.
     * <br>
     * <b>Use Case 7: Finding all the supersedures associated with a given BOMEdit of type
     * add</b>
     * <br>
     * For the input structure <code>FindContextDataInputs</code>,use CM_get_supersedures_of_bomadd
     * for <code>contextRelName</code>, supply the BOMEdit object as <code>primaryContextInputData</code>.
     * The requested supersedure objects can be found in the object list <code>contextOutputData</code>
     * of the corresponding output structure <code>FindContextDataOutput</code>.
     * <br>
     * <b>Use Case 8: Finding the first supersedure given a change object and a BOM line</b>
     * <br>
     * For the input structure <code>FindContextDataInputs</code>,use CM_get_first_supersedure
     * for contextRelName, supply the change revision as changeRev and the BOM line as <code>primaryContextInputData</code>.
     * The requested first supersedure can be found in the object list <code>contextOutputData</code>
     * of the corresponding output structure <code>FindContextDataOutput</code>.
     * <br>
     * <b>Use Case 9: Finding the Pure Adds and Pure Cancels for a given BOM line</b>
     * <br>
     * For the input structure <code>FindContextDataInputs</code>,use CM_get_pure_adds_cancels
     * for <code>contextRelName</code>, supply the BOM line as <code>primaryContextInputData</code>.
     * The requested Pure Adds and Pure Cancels can be found in the object list <code>contextOutputData</code>
     * of the corresponding output structure <code>FindContextDataOutput</code>.  The list
     * of vBomEditCount can be used to sort out the Adds and the Cancels.
     * <br>
     * <b>Use Case 10: Finding the first supersedure for a given bom line in the context
     * of a whereused assembly</b>
     * <br>
     * For the input structure <code>FindContextDataInputs</code>,use CM_get_supersedure_for_WU
     * for <code>contextRelName</code>, supply the BOM line as <code>primaryContextInputData</code>
     * and the whereused assembly as <code>secondaryContextInputData</code>.  The requested
     * first supersedure can be found in the object list <code>contextOutputData</code>
     * of the corresponding output structure <code>FindContextDataOutput</code>.
     * <br>
     * <b>Use Case 11: Finding all the Pure Adds and Pure Cancels for a given bom line in
     * the context of a whereused assembly</b>
     * <br>
     * For the input structure <code>FindContextDataInputs</code>,use CM_get_pureAddsCancels_for_WU
     * for <code>contextRelName</code>, supply the BOM line as <code>primaryContextInputData</code>
     * and the whereused assembly as <code>secondaryContextInputData</code>.  The requested
     * Pure Adds and Pure Cancels can be found in the object list <code>contextOutputData</code>
     * of the corresponding output structure <code>FindContextDataOutput</code>.  The list
     * of vBomEditCount can be used to sort out the Adds and the Cancels.
     * <br>
     * <b>Use Case 12: Finding the associated change revision given a supersedure</b>
     * <br>
     * For the input structure <code>FindContextDataInputs</code>,use CM_get_change_of_supersedure
     * for <code>contextRelName</code>, supply the supersedure as <code>primaryContextInputData</code>.
     * The requested associated change revision can be found in the <code>changeRev</code>
     * of the corresponding output structure <code>FindContextDataOutput</code>.
     * <br>
     * <b>Use Case 13: Finding all the BOM lines and the supersedures given a change revision
     * and a pair of BOM windows representing the solution and the impacted items.</b>
     * <br>
     * For the input structure <code>FindContextDataInputs</code>,use CM_get_initial_rendering_details
     * for <code>contextRelName</code>, supply the change revision as <code>changeRev</code>,
     * the BOM windlow for the solution item as <code>primaryContextInputData</code> and
     * the BOM windlow for the impacted item as <code>secondaryContextInputData</code>.
     * The requested BOM lines can be found in the object list <code>contextOutputData</code>
     * of the corresponding output structure <code>FindContextDataOutput</code>.
     * <br>
     * <b>Use Case 14: Finding all the solution BOM lines and the impacted BOM lines given
     * a change revision and an Add line and a Cancel line without including the supersedure
     * data</b>
     * <br>
     * For the input structure <code>FindContextDataInputs</code>,use CM_refresh_rendering_without_supersedure
     * for contextRelName, supply the change revision as <code>changeRev</code>, the Add
     * line as <code>primaryContextInputData</code> and the Cancel line as <code>secondaryContextInputData</code>.
     * The requested BOM lines can be found in the object list of the corresponding output
     * structure.
     * <br>
     * <b>Use Case 15: Finding all the solution BOM lines and the impacted BOM lines given
     * a change revision and an Add line and a Cancel line including the supersedure data</b>
     * <br>
     * For the input structure <code>FindContextDataInputs</code>,use CM_refresh_rendering_with_supersedure
     * for <code>contextRelName</code>, supply the change revision as <code>changeRev</code>,
     * the Add line as <code>primaryContextInputData</code> and the Cancel line as <code>secondaryContextInputData</code>.
     * The requested BOM lines can be found in the object list of the corresponding output
     * structure.
     * <br>
     * <b>Use Case 16: Finding all the Add BOM lines for a given supersedure</b>
     * <br>
     * For the input structure <code>FindContextDataInputs</code>,use CM_get_bomline_adds
     * for <code>contextRelName</code>, supply the supersedure as <code>primaryContextInputData</code>.
     * The requested Add BOM lines can be found in the object list <code>contextOutputData</code>
     * of the corresponding output structure.
     * <br>
     * <b>Use Case 17: Finding all the Cancel BOM lines for a given supersedure</b>
     * <br>
     * For the input structure <code>FindContextDataInputs</code>,use CM_get_bomline_cancels
     * for <code>contextRelName</code>, supply the supersedure as <code>primaryContextInputData</code>.
     * The requested Cancel BOM lines can be found in the object list of the corresponding
     * output structure.
     * <br>
     * <br>
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Change Management - This Component is intended to identify all Operations and Services
     * under Change Management.
     *
     * @param findcontextRequest
     *        A list of <code>FindContextDataInputs</code> structures.
     *
     * @return
     *         <code>FindContextDataResponse</code> contains a list of <code>FindContextDataOutput</code>
     *         structures and a standard service data.
     *
     */
    virtual Teamcenter::Services::Changemanagement::_2008_06::Changemanagement::FindContextDataResponse findContextData ( const std::vector< Teamcenter::Services::Changemanagement::_2008_06::Changemanagement::FindContextDataInputs >& findcontextRequest ) = 0;

    /**
     * This operation finds the Supersedures based on the BOMEdits supplied as input. A
     * BOM change which encompasses a BOM Add or a BOM delete enables a Supersedure to be
     * created. A user can create a Supersedure which defines the additions and deletions
     * within a BOM.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Use case 1: Create Supercedures</b>
     * <br>
     * An assembly modification results in the components being added to or removed from
     * the assembly. Supercedure is a component replacement where a user specifically marks
     * one or more added components with one or more removals. The Supercedure is created
     * from:
     * <br>
     * <ul>
     * <li type="disc">The original product structure
     * </li>
     * <li type="disc">The new product structure which is currently being edited in response
     * to change.
     * </li>
     * </ul>
     * <br>
     * <b>Use case 2: Find Supersedures</b>
     * <br>
     * Finding a BOM Supersedure can be accomplished by calling the <code>findSupersedure</code>
     * for each input <code>bomeditRequest</code>.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Change Management - This Component is intended to identify all Operations and Services
     * under Change Management.
     *
     * @param bomedit
     *        Input structure that is a list of BOMEdits.
     *
     * @return
     *         The operation returns a <code>findSupersedureResponse</code> which contains a list
     *         of Supersedure objects and any failure will be reported in the standard Service data
     *         under partial errors.
     *
     */
    virtual Teamcenter::Services::Changemanagement::_2008_06::Changemanagement::FindSupersedureResponse findSupersedure ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMEdit>  >& bomedit ) = 0;

    /**
     * This operation returns a list of all Change Home folders.  This operation is created
     * to support the Change Home UI in Change Manager.  Change Home allows users to define
     * their own set of folders whose contents are determined by the searches/queries that
     * are executed when the folders are expanded.  When Change Home is being opened, this
     * operation is used to retrieve the folders that are defined for use by the current
     * user.  Change Home will then display them based on their settings.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Retreiving a list of all Change Home folders for the user</b>
     * <br>
     * Where there is a need to retrieve all the Change Home folders for the current user
     * session, this operation can be invoked via an instance of the <code>ChangeManagementService</code>.
     * No parameters are required.  The response of the operation is captured in the form
     * of <code>GetAllChangeHomeFolderResponse</code>.  It is important to note that the
     * folders retrieved will include BOTH those defined at the site level as well as those
     * defined at the user level.  Site level folders are available to all users, whereas
     * user level folders are only available to the current user.  The caller program can
     * make intelligent use of the list by inspecting the details of each individual folder
     * that are captured within the structure <code>ConfigureChangeSearchData</code>.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Change Management - This Component is intended to identify all Operations and Services
     * under Change Management.
     *
     * @return
     *         The list of Change Home folder(s) are returned as a vector of <code>ConfigureChangeSearchData</code>
     *         inside <code>GetAllChangeHomeFolderResponse</code> which also contains a <code>ServiceData</code>.
     *         On the occasions when Teamcenter preferences are corrupted or when the system is
     *         running out of memory, the errors are returned in <code>ServiceData</code>. Following
     *         are some possible errors returned in <code>ServiceData</code>:
     *         <br>
     *         <ul>
     *         <li type="disc">1023&nbsp;&nbsp;&nbsp;&nbsp;Unable to allocate memory
     *         </li>
     *         <li type="disc">1700&nbsp;&nbsp;&nbsp;&nbsp;Preference not found
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Changemanagement::_2008_06::Changemanagement::GetAllChangeHomeFolderResponse getAllChangeHomeFolders (  ) = 0;

    /**
     * This operation is to support the BOM Change tab in Change Manager which displays
     * the details of the BOM Change associated with the selected change revision in the
     * Open Change View.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Finding all BOMEdit objects for a given change revision</b>
     * <br>
     * When there is a need to find all BOMEdit objects of a certain type for a given change
     * revision, this operation can be invoked via an instance of the <code>ChangeManagementService</code>.
     * The caller program needs to be aware of all the possible types (as represented by
     * <code>bomEditType</code> in the <code>GetBOMEditInput</code> structure) of BOMEdit
     * in order to process the returned objects correctly.  It is important to note that
     * a <code>PSBOMViewRevision</code> object for the solution item will need to be located
     * and supplied as the <code>affectedBvr</code> element within the <code>GetBOMEditInput</code>
     * structure.  Any BOMEdit objects found will be captured in the list of <code>GetBOMEditOutput</code>
     * structures of the <code>GetBOMEditResponse</code>.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Change Management - This Component is intended to identify all Operations and Services
     * under Change Management.
     *
     * @param bomeditRequest
     *        A vector of <code>GetBOMEditInput</code> structures, each containing the necessary
     *        criteria for finding the corresponding BOMEdit object(s).  The criteria include the
     *        <i>change revision</i> object that the BOMEdit objects are associated with, the <i>BVR</i>
     *        object that represents the solution item of the change, and the <i>type</i> of the
     *        BOMEdit objects.
     *
     * @return
     *         <code>GetBOMEditResponse</code> which contains a list of <code>GetBOMEditOutput</code>
     *         structures and a standard <code>ServiceData</code>.
     *
     */
    virtual Teamcenter::Services::Changemanagement::_2008_06::Changemanagement::GetBOMEditResponse getBOMEdits ( const std::vector< Teamcenter::Services::Changemanagement::_2008_06::Changemanagement::GetBOMEditInput >& bomeditRequest ) = 0;

    /**
     * Updates a vector of change items by using the inputs provided in the argument returns
     * the updated objects via the services data.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Change Management - This Component is intended to identify all Operations and Services
     * under Change Management.
     *
     * @param updateProps
     *        a list of UpdateChangeItemsInput structures
     *
     * @return
     *         A standard Service data which contains a list of updated objects.
     *
     * @deprecated
     *         As of Teamcenter 10, this service operation is no longer needed as its purpose can
     *         be served by using a combination of setProperties, createRelations, and deleteRelations
     *         operations.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 10, this service operation is no longer needed as its purpose can be served by using a combination of setProperties, createRelations, and deleteRelations operations."))
#endif
    virtual Teamcenter::Soa::Client::ServiceData updateChangeItems ( const std::vector< Teamcenter::Services::Changemanagement::_2008_06::Changemanagement::UpdateChangeProperties >& updateProps ) = 0;

    /**
     * This operation updates Supercedures for each <code>UpdateSupercedureData</code> supplied.
     * The <code>UpdateSupercedureData</code> contains information for properties such as
     * <i>bomAddorCancelFlag</i>, <i>operation</i>, <i>tags</i> and the <i>supTag</i> which
     * specifies the <b>Supercedure</b> business object to be updated. A Supercedure represents
     * a relation that graphically displays the deleted components and new components that
     * replace them. Once a Supercedure is created, new BOM elements can be added or removed
     * which allows the user to indicate the Supercedure to be edited and updated.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Use case1: Create Supercedures</b>
     * <br>
     * An assembly modification results in the components being added to or removed from
     * the assembly. Supercedure is a component replacement where a user specifically marks
     * one or more added components with one or more removals. This use case is accomplished
     * by the operation createSupercedure with the input structure <code>CreateSupercedureInput</code>
     * utilizing a list of Supercedure properties. The Supercedure is created from:
     * <br>
     * <ul>
     * <li type="disc">The original product structure
     * </li>
     * <li type="disc">The new product structure which is currently being edited in response
     * to change.
     * </li>
     * </ul>
     * <br>
     * <b>Use case2: Update Supercedures</b>
     * <br>
     * An existing Supercedure can be updated at point in time and this is achieved by the
     * operation <code>updateSupercedures</code>. This operation checks if the operation
     * is of type ADD or CANCEL and correspondingly adds or deletes a list of business objects
     * from the Supercedure business object specified in the input parameter. The input
     * structure elements utilize the Change Management BOM_ADD/BOM_CANCEL and OPERARTION_TYPE_ADD/OPERATION_TYPE_CANCEL
     * constants in the SOA based on which a decision is made by the user to append or remove
     * components from the assembly.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Change Management - This Component is intended to identify all Operations and Services
     * under Change Management.
     *
     * @param supercedureTobeUpdated
     *        Input parameter that comprises of a list of <code>UpdateSupercedureData</code> structure
     *        elements.
     *        <br>
     *
     * @return
     *         A standard Service data which contains a list of updated objects (Supercedures).
     *         Invalid operation on supercedure or any other error will be returned under partial
     *         errors.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData updateSupercedures ( const std::vector< Teamcenter::Services::Changemanagement::_2008_06::Changemanagement::UpdateSupercedureData >& supercedureTobeUpdated ) = 0;


protected:
    virtual ~Changemanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/changemanagement/ChangeManagement_undef.h>
#endif

