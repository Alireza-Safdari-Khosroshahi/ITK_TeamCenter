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

#ifndef MDL0_SERVICES_MODELCORE_DATAMANAGEMENTSERVICE_HXX
#define MDL0_SERVICES_MODELCORE_DATAMANAGEMENTSERVICE_HXX

#include <mdl0/services/modelcore/_2011_06/Datamanagement.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <mdl0/services/modelcore/ModelCore_exports.h>

namespace Mdl0
{
    namespace Services
    {
        namespace Modelcore
        {
            class DatamanagementService;

/**
 * This service contains utilities which augment the Teamcenter core data management
 * services.  Specifically this service provides:
 * <br>
 * <ul>
 * <li type="disc">A bulk delete operation for removing model elements (<b>Mdl0ModelElement</b>)
 * from
 * </li>
 * </ul>
 * <br>
 * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  application models (<b>Mdl0ApplicationModel</b>)
 * <br>
 * <ul>
 * <li type="disc">An operations to support revising conditional elements (<b>Mdl0ConditionalElement</b>)
 * 
 * </li>
 * </ul>
 * <br>
 * <br>
 * <b>Use case:</b>
 * <br>
 * <br>
 * Please see the <code>deleteModelContent</code> operation documentation for delete
 * use cases.
 * <br>
 * Please see the <code>reviseObjects</code> operation documentation for revise use
 * cases.
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libmdl0soamodelcorestrongmngd.dll
 * </li>
 * <li type="disc">libmdl0soamodelcoretypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class MDL0SOAMODELCORESTRONGMNGD_API DatamanagementService
    : public Mdl0::Services::Modelcore::_2011_06::Datamanagement
{
public:
    static DatamanagementService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * Deletes <b>Mdl0ModelElement</b> objects from an <b>Mdl0ApplicationModel.</b>This
     * operation will attempt to delete as many objects as it can and returns a list of
     * any objects that could not be deleted.Order of objects in the input list is not important.This
     * operation handles the case when one input object has a non circular reference to
     * another input object; deletion of the referenced object will occur after its referencing
     * object is deleted.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This API supports model element authoring use cases, specifically the bulk deletion
     * of objects within a model.
     * <br>
     * the following steps can be used for deleting model elements from a model.
     * <br>
     * <ul>
     * <li type="disc">Find through query or navigate the model elements to be deleted.
     * </li>
     * <li type="disc">Call the delete operation <code>deleteModelContent</code> to delete
     * a list of existing model elements from a model.
     * </li>
     * </ul>
     * <br>
     * Note:  <code>deleteObjects</code> operation can also be used, but requires proper
     * ordering of input   elements to handle the case when one model element in the input
     * list references another model element in the input list.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Model Elements - Defines the basic data management operations(revise,saveAs,deepcopy)
     * for Application Model Elements,defines operations to create search expressions and
     * execute search on Model Elements in an Application Model.
     *
     * @param objectsToDelete
     *        The input list of model elements to be deleted.
     *
     * @return
     *         The response (<code>DeleteModelContentResponse</code>) contains list of any input
     *         objects that could not be deleted.The service data contains any errors and list of
     *         objects deleted by the operation.
     *         <br>
     *
     */
    virtual Mdl0::Services::Modelcore::_2011_06::Datamanagement::DeleteModelContentResponse deleteModelContent ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Mdl0ModelElement>  >& objectsToDelete ) = 0;

    /**
     * Gets a save as descriptor for a revise operation.Clients may use the output of this
     * call to construct generic UI dialogs to collect user input for the revise operation.This
     * operation takes in a list of objects to be revised, and returns save as descriptors
     * and deep copy for each object input.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * See the <code>reviseObjects</code> operation documentation for applicable use cases.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * getReviseDesc, reviseObjects
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Model Elements - Defines the basic data management operations(revise,saveAs,deepcopy)
     * for Application Model Elements,defines operations to create search expressions and
     * execute search on Model Elements in an Application Model.
     *
     * @param targetObjects
     *        Input list of objects to be revised. It must be a subtype of <b>Mdl0ConditionalElement</b>
     *
     * @return
     *         The response contains a map of business object types to their save as descriptor
     *         (used for revise operations as well), and a map of the deep copy data for each of
     *         input objects.
     *
     */
    virtual Mdl0::Services::Modelcore::_2011_06::Datamanagement::SaveAsDescResponse getReviseDesc ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& targetObjects ) = 0;

    /**
     * Revises a set of input objects and performs a deep copy of related objects.New objects
     * are saved in the Teamcenter database and returned in the response.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This API supports the authoring use case where an object or a set of objects requires
     * a new revision. Objects which are a subtype of <b>Mdl0ConditionalElement</b> support
     * the concept of revise.   The elements are first created by a user, undergo edits,
     * and then are approved through a workflow and given status. At this point, a new revision
     * of the object must be created to further modify it.
     * <br>
     * The <code>reviseObjects</code>  operation is used to create the new revision.  Deep
     * copy rules, defined in BMIDE and deployed to Teamcenter, control the sub object copy
     * process during the revise operation.  The operation <code>getReviseDesc</code> is
     * called prior to calling <code>reviseObjects</code> to construct the deep copy information
     * and descriptors for the objects to be revised.
     * <br>
     * Use Case :<b> Revise a conditional element  </b>
     * <br>
     * The following assumes an initial revision has been created and released.
     * <br>
     * <ul>
     * <li type="disc">Construct list of existing, released objects to be revised (objects
     * must be valid subtypes of <b>Mdl0ConditionalElement</b>).
     * </li>
     * <li type="disc">Construct deep copy data and get saveAs descriptors for the input
     * set of objects by using operation <code>getReviseDesc</code>.
     * </li>
     * <li type="disc">Revise the objects in Teamcenter by using the <code>reviseObjects</code>
     * operation.
     * </li>
     * <li type="disc">Post process / display new object revisions in client
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * getReviseDesc
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Model Elements - Defines the basic data management operations(revise,saveAs,deepcopy)
     * for Application Model Elements,defines operations to create search expressions and
     * execute search on Model Elements in an Application Model.
     *
     * @param saveAsIn
     *        List of input data  containing object to be revised and its deep copy data.
     *
     * @return
     *         A list of objects that were created and saved during the revise operation. Any failure
     *         will be returned with Business object mapped to error message in the ServiceData
     *         list of partial errors.
     *
     */
    virtual Mdl0::Services::Modelcore::_2011_06::Datamanagement::SaveAsObjectsResponse reviseObjects ( const std::vector< Mdl0::Services::Modelcore::_2011_06::Datamanagement::SaveAsIn >& saveAsIn ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DatamanagementService")

};
        }
    }
}


#pragma warning ( pop )

#include <mdl0/services/modelcore/ModelCore_undef.h>
#endif

