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

#ifndef TEAMCENTER_SERVICES_MANUFACTURING_DATAMANAGEMENTSERVICE_HXX
#define TEAMCENTER_SERVICES_MANUFACTURING_DATAMANAGEMENTSERVICE_HXX

#include <teamcenter/services/manufacturing/_2008_06/Datamanagement.hxx>
#include <teamcenter/services/manufacturing/_2009_10/Datamanagement.hxx>
#include <teamcenter/services/manufacturing/_2011_06/Datamanagement.hxx>
#include <teamcenter/services/manufacturing/_2012_02/Datamanagement.hxx>
#include <teamcenter/services/manufacturing/_2012_09/Datamanagement.hxx>
#include <teamcenter/services/manufacturing/_2013_05/Datamanagement.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/manufacturing/Manufacturing_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Manufacturing
        {
            class DatamanagementService;

/**
 * Contains DataManagement Services
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoamanufacturingstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoamanufacturingtypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOAMANUFACTURINGSTRONGMNGD_API DatamanagementService
    : public Teamcenter::Services::Manufacturing::_2008_06::Datamanagement,
             public Teamcenter::Services::Manufacturing::_2009_10::Datamanagement,
             public Teamcenter::Services::Manufacturing::_2011_06::Datamanagement,
             public Teamcenter::Services::Manufacturing::_2012_02::Datamanagement,
             public Teamcenter::Services::Manufacturing::_2012_09::Datamanagement,
             public Teamcenter::Services::Manufacturing::_2013_05::Datamanagement
{
public:
    static DatamanagementService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * Allows the user to create and/or update a MEActivityFolder.  If the given MEActivity
     * object exists but the input attribute values that differ from those already set,
     * an attempt is made to update the values if possible. If multiple level of sub activities
     * are to be created those activities can be passed in as the objects if they already
     * exist in database. The created folder and updated folders are returned to the client
     * through the createdObjects and updatedObject list of the service data respectively.
     *
     * @param activityInfos
     *        Input is a vector of MEActivityFolderInfo structs. A Boolean value part of the structure
     *        signifying if the input data represents the complete representation of the folder
     *        tools, predecessors, and contents or if it represents objects to be appended to the
     *        existing folder tools, predecessors, and contents (folder context information) if
     *        complete is true, then the expectation is that the entire folder context information
     *        is supplied and any folder context not supplied that currently exist in Teamcenter
     *        will be removed from the folder context, if complete is false, the input context
     *        elements will be appended to the input folder.
     *
     * @return
     *         contains map between the index of the input structure and the created or updated
     *         object, All Object ids that were successfully created or updated are added to ServiceData.
     *         Objects/object ids that failed the find are returned in a list of failures in the
     *         ServiceData with its index.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2008_06::Datamanagement::CreateOrUpdateMEActivityFolderResponse createOrUpdateMEActivityFolders ( const std::vector< Teamcenter::Services::Manufacturing::_2008_06::Datamanagement::MEActivityFolderInfo >& activityInfos ) = 0;

    /**
     * Allows the user to create and/or update a MENXObject. If the given MENXObject object
     * exists but the input attribute values that differ from those already set, an attempt
     * is made to update the values if possible.
     *
     * @param meObjectInfos
     *        Input is a vector of MENXObjectInfo structs.
     *
     * @param container
     *        The folder into which the created objects are to be placed. This can be a NULLTAG
     *        in which case the created objects will not be inserted into any folder.
     *
     * @return
     *         contains map between the index of the input structure and the created or updated
     *         object, All Object ids that were successfully created or updated are added to ServiceData.
     *         Objects/object ids that failed the find are returned in a list of failures in the
     *         ServiceData with its index.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2008_06::Datamanagement::CreateOrUpdateMENXObjectResponse createOrUpdateMENXObjects ( const std::vector< Teamcenter::Services::Manufacturing::_2008_06::Datamanagement::MENXObjectInfo >& meObjectInfos,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Folder>  container ) = 0;

    /**
     * Generic operation for creation of manufacturing objects. This will also create any
     * secondary(compounded) objects that need to be created, assuming the CreateInput for
     * the secondary object is represented in the recursive CreateInput object e.g. Item
     * is Primary Object that also creates ItemMasterForm, ItemRevision and ItemRevision
     * in turn creates ItemRevisionMasterForm. The input for all these levels is passed
     * in through the recursive CreateInput object. This operation creates the persistent
     * objects and the runtime objects accordingly. This operation also connects the created
     * objects to the specified target. The connection will be done by the relation defined
     * as default.
     *
     * @param input
     *        a list of CreateIn objects representing the Create Input for Business Objects to
     *        be created
     *
     * @return
     *         Contains a list of tags representing the objects that were created. Any failure will
     *         be returned with client id mapped to error message in the ServiceData list of partial
     *         errors.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2009_10::Datamanagement::CreateResponse createObjects ( const std::vector< Teamcenter::Services::Manufacturing::_2009_10::Datamanagement::CreateIn >& input ) = 0;

    /**
     * Generic operation to disconnect objects.
     *
     * @param input
     *        A list of disconnectInput objects for the objects to disconnect
     *
     * @return
     *         Any failure will be returned with client id mapped to error message in the ServiceData
     *         list of partial errors.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData disconnectObjects ( const std::vector< Teamcenter::Services::Manufacturing::_2009_10::Datamanagement::DisconnectInput >& input ) = 0;

    /**
     * This method is used to close contexts (base view windows). For each context, this
     * method closes the base view window and all the open views (OG windows) associated
     * to it
     *
     * @param contexts
     *        A vector with the contexts (top lines of the windows) to close
     *
     * @return
     *         The service data of the operation
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData closeContexts ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& contexts ) = 0;

    /**
     * This method is used to close opened views (OG windows).
     *
     * @param structureContext
     *        The structure context containing the views. Can be NULL if not using structire context.
     *
     * @param views
     *        A vector with the open views (top lines of the OG windows) to close
     *
     * @return
     *         The service data of the operation
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData closeViews ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  structureContext,
        const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& views ) = 0;

    /**
     * This method is used to open existing objects in new base view windows.
     *
     * @param input
     *        A list of OpenContextInput representing the objects to open
     *
     * @return
     *         The response of the operation
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2011_06::Datamanagement::OpenContextsResponse openContexts ( const std::vector< Teamcenter::Services::Manufacturing::_2011_06::Datamanagement::OpenContextInput >& input ) = 0;

    /**
     * This method is used to open views (OG windows) for an already opened context (base
     * view window).
     *
     * @param context
     *        The context (top line of the base view window) for which the views will be opened
     *
     * @param structureContext
     *        The structure context containing the context. This can be null
     *
     * @param views
     *        A vector with the views to open
     *
     * @return
     *         The response of the operation
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2011_06::Datamanagement::OpenViewsResponse openViews ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  context,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  structureContext,
        const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& views ) = 0;

    /**
     * Generic operation for setting different kinds of associations. It could be between
     * Plant BOP and Product BOP (Leading Plant BOP in the future), Product (root) and Process
     * (root) structures, regular Plant (Workarea) (root) and Process (root) structures,
     * EBOM-MBOM. For now we will use it as threshold for Plant BOP and Product BOP. Other
     * types are defined as target. This SOA will be used for add operation. Remove/disconnect
     * (future) will be implemented in separate SOA.
     *
     * @param input
     *        list of AddAssociationInput BOMLines for the contexts to be associated.
     *
     * @return
     *         ServiceData
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData addAssociatedContexts ( const std::vector< Teamcenter::Services::Manufacturing::_2012_02::Datamanagement::AddAssociationInput >& input ) = 0;

    /**
     * This function is the second function call in case a preview is required for automatic
     * allocation this function does the actual allocation from Source Product BOP to a
     * Target Plant BOP on the basis of a Reference Product BOP. This is done by passing
     * the allocation map back to the server which we recived in the  automaticAllocatePreview
     * command. This function also associates the Source Product BOP with the Target Plant
     * BOP in case they are not associated. This function can throw the following exceptions,
     * Reference Product BOP is not linked to the Target Plant BOP and Some allocation from
     * the source structure to the target structure were unsuccessful please see the log
     * for more details. Both these error messages will have the severity level of error.
     *
     * @param input
     *        Input specifying source, target and reference objects.
     *
     * @param allocationMap
     *        Map of allocations from the source structure to the target structure.
     *
     * @return
     *         Response containing the log file ticket and service data.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2012_02::Datamanagement::AssociateAndAllocateResponse associateAndAllocateByPreview ( const Teamcenter::Services::Manufacturing::_2012_02::Datamanagement::AssociateAndAllocateInput&  input,
        const AllocationMap&  allocationMap ) = 0;

    /**
     * This function is the first function call in case a preview is required for automatic
     * allocation from Source Product BOP to a Target Plant BOP on the basis of a Reference
     * Product BOP. This function finds the allocated lines from the reference product BOP
     * to the Plant BOP and equivalent lines in the source Product BOP and generates a preview
     * for the automatic allocation in CSV format . Also this function returns an allocationMap,
     * which needs to be sent back to server in case the user wants to go ahead with the
     * allocation , for which it calls the second server call associateAndAllocateMap command
     * . This function can throw the following exceptions, Reference Product BOP is not
     * linked to the Target Plant BOP . This error messages will have severity level of
     * error.
     *
     * @param input
     *        Input specifying source, target and reference objects.
     *
     * @return
     *         Response containing allocation map, CSV file ticket and service data.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2012_02::Datamanagement::AutomaticAllocatePreviewResponse automaticAllocatePreview ( const Teamcenter::Services::Manufacturing::_2012_02::Datamanagement::AssociateAndAllocateInput&  input ) = 0;

    /**
     * This function is a single call function that does the allocation from Source Product
     * BOP to a Target Plant BOP on the basis of a Reference Product BOP. This function
     * finds the allocated lines from the reference product BOP to the Plant BOP and equivalent
     * lines in the source Product BOP and does the allocation from the Source Product BOP
     * to the Target Plant BOP in a single call. This function also associates the Source
     * Product BOP with the Target Plant BOP in case they are not associated. This function
     * can throw the following exceptions, Reference Product BOP is not linked to the Target
     * Plant BOP and Some allocation from the source structure to the target structure were
     * unsuccessful please see the log for more details. Both these error messages will
     * have the severity level of error.
     *
     * @param input
     *        Input specifying source, target and reference objects.
     *
     * @return
     *         Response containing the service data and log file path.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2012_02::Datamanagement::AssociateAndAllocateResponse automaticAssociateAndAllocate ( const Teamcenter::Services::Manufacturing::_2012_02::Datamanagement::AssociateAndAllocateInput&  input ) = 0;

    /**
     * Generic operation for connecting MFG nodes       int        quantityNum - number
     * of BOMLines to create (used in paste special). Default value is 1. int        occurrenceNumber
     * - for packed lines. Number of occurrences to create (used in paste special). Default
     * value is 1. int        findNumber - find number. Always passed by client.
     *
     * @param input
     *        A list of ConnectInput BOMLines for the nodes to connect
     *
     * @return
     *         Generic operation for connecting MFG nodes
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2012_02::Datamanagement::ConnectObjectResponse connectObjects ( const std::vector< Teamcenter::Services::Manufacturing::_2012_02::Datamanagement::ConnectObjectsInputData >& input ) = 0;

    /**
     * Disconnects objects and their children from their origin relation. Origin relation
     * is created when the objects are assigned from the Product BOP/Generic BOP to the
     * Plant BOP/Product BOP. This functionality removes the origin relation created during
     * the assignment. Also this functionality can be called recursively for the processes
     * below. This functionality can return an error in the following conditions, the object
     * on which disconnect function was called called does not have an origin in case of
     * non-recursive calls. This error will have a severity level of information. And This
     * functionality is not available on this type of object only ProcessAreas, WorkAreas,
     * Partitions, Processes and Operations type objects are expected.
     *
     * @param inputVector
     *        Vector of DisconnectFromOriginInputData specifying the lines to be disconnected and
     *        whether the children are to be recursively disconnected too.
     *
     * @return
     *         Service data containing the errors that occurred during the disconnect command.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData disconnectFromOrigin ( const std::vector< Teamcenter::Services::Manufacturing::_2012_02::Datamanagement::DisconnectFromOriginInputData >& inputVector ) = 0;

    /**
     * Returns associated contexts with the input context.
     *
     * @param input
     *        input
     *
     * @return
     *         Returns associated contexts with the input context
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Manufacturing::_2012_02::Datamanagement::AssociationResponse getAssociatedContexts ( const std::vector< Teamcenter::Services::Manufacturing::_2012_02::Datamanagement::GetAssociatedContextsInputData >& input ) = 0;

    /**
     * Apply configuration objects to applicable business objects.
     *
     * @param input
     *        Input parameters for applying configuration objects
     *
     * @return
     *         Service Data
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData applyConfigObjects ( const std::vector< Teamcenter::Services::Manufacturing::_2012_09::Datamanagement::ApplyConfigInput >& input ) = 0;

    /**
     * Creates or updates the configuration objects based on the input data.
     *
     * @param input
     *        Vector of CreateConfigInput structure which contains the information for creating
     *        or updating context objects.
     *
     * @return
     *         Contains the created or updated object and the service data.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2012_09::Datamanagement::CreateConfigResponse createOrUpdateConfigObjects ( const std::vector< Teamcenter::Services::Manufacturing::_2012_09::Datamanagement::CreateConfigInput >& input ) = 0;

    /**
     * This service operation creates the attachment objects for a business object(s).
     * <br>
     * The operation considers the Incremental Change applied on the window of the object
     * for which attachment is to be created.
     * <br>
     * The operation takes following inputs.
     * <br>
     * <ul>
     * <li type="disc"><b>clientId</b> - Unique client Identifier.
     * </li>
     * <li type="disc"><b>context</b> - The business objects of the <b>BOM Line</b>. The
     * IC applied on the window of this line is considered while creating the attachment.
     * </li>
     * <li type="disc"><b>target</b> - The business object which is used as primary object
     * to connect the newly created object.
     * </li>
     * <li type="disc"><b>relation name</b> - The name of the relation used to connect the
     * target.
     * </li>
     * <li type="disc"><b>data</b> - Input data for create operation.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MPP - Core objects and relationships used by the Manufacturing Process Planner application.
     *
     * @param input
     *        A list of CreateIn objects representing the Create Input for Business Objects to
     *        be created.
     *
     * @return
     *         Contains a list of tags representing the objects that were created. Any failure will
     *         be returned with client id mapped to error message in the ServiceData list of partial
     *         errors. The possible errors reported are:
     *         <br>
     *         <ul>
     *         <li type="disc"><b>251024</b> - The creation of the new object has failed. Please
     *         contact your system administrator.
     *         </li>
     *         <li type="disc"><b>253012</b> - No property is specified.
     *         </li>
     *         <li type="disc"><b>253036</b> - The attribute '%1$' does not exist.
     *         </li>
     *         <li type="disc"><b>251046</b> - The relation type "%1$" is not defined. Please contact
     *         your system administrator.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2009_10::Datamanagement::CreateResponse createAttachments ( const std::vector< Teamcenter::Services::Manufacturing::_2009_10::Datamanagement::CreateIn >& input ) = 0;

    /**
     * This service operation sets the attributes of objects attached to the business object(s).
     * For example, if some attributes of a <b>Form</b> attached to an <b>Item</b> needs
     * to be edited, this operation can be used.
     * <br>
     * The operation considers the Incremental Change applied on the window of the object
     * whose attachment is to be edited.
     * <br>
     * The operation takes the business objects of the <b>BOMLine</b> and its attached object
     * which is to be edited. Along with that, it takes the name(s) of attributes  and their
     * corresponding values to be set.
     * <br>
     * This operation can set multiple attributes of multiple attached objects.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MPP - Core objects and relationships used by the Manufacturing Process Planner application.
     *
     * @param input
     *        The input structure contains object(s) to be edited and the details of the attributes
     *        or relations which need to be edited.
     *
     * @return
     *         The ServiceData containing partial errors if any. The possible errors reported are:
     *         <br>
     *         <ul>
     *         <li type="disc"><b>253126</b> - The target object "%1$" cannot be modified, because
     *         the user does not have write access.
     *         </li>
     *         <li type="disc"><b>253012</b> - No property is specified.
     *         </li>
     *         <li type="disc"><b>253036</b> - The attribute '%1$' does not exist.
     *         </li>
     *         <li type="disc"><b>251046</b> - The relation type "%1$" is not defined. Please contact
     *         your system administrator.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData setAttributes ( const std::vector< Teamcenter::Services::Manufacturing::_2013_05::Datamanagement::ObjectAttributesInput >& input ) = 0;

    /**
     * This operation synchronizes a Simulation Study with the source BOP structure it is
     * associated with.
     *
     * @param input
     *        The Mfg0BvrStudy objects to synchronize and the direction to synchronize (to/from
     *        the study).
     *
     * @return
     *         The FMS file ticket to the log file for the study synchronization.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2013_05::Datamanagement::SyncStudyResponse syncStudyAndSource ( const std::vector< Teamcenter::Services::Manufacturing::_2013_05::Datamanagement::SyncStudyInput >& input ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DatamanagementService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/manufacturing/Manufacturing_undef.h>
#endif

