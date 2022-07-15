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

#ifndef TEAMCENTER_SERVICES_ALLOCATIONS_ALLOCATIONSERVICE_HXX
#define TEAMCENTER_SERVICES_ALLOCATIONS_ALLOCATIONSERVICE_HXX

#include <teamcenter/services/allocations/_2007_01/Allocation.hxx>
#include <teamcenter/services/allocations/_2011_06/Allocation.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/allocations/Allocations_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Allocations
        {
            class AllocationService;

/**
 * The <b>Allocation</b> service exposes operations that are used to establish and maintain
 * complex one to many, many to one and many to many relationships between items in
 * the Teamcenter system. Common uses for allocations include requirements management,
 * systems engineering, and other application domains that require these types of complex
 * relationships. These operations can also be used in product configuration applications
 * to ensure that design constraints and mandatory selections on product options are
 * satisfied.
 * <br>
 * <br>
 * This service provides the following allocation use cases for the specified set of
 * Teamcenter product structures such as requirements, functional, and manufacturing
 * structures.
 * <br>
 * <br>
 * <ul>
 * <li type="disc">Creation of new <b>Allocation</b> between one or more BOMLine objects
 * of two or more product structures.
 * </li>
 * <li type="disc">Modification of existing Allocation objects, <b>AllocationContext</b>.
 * </li>
 * <li type="disc">Query <b>Allocation</b> objects and allocated product structures.
 * </li>
 * <li type="disc">Deletion of <b>Allocation</b> objects.
 * </li>
 * <li type="disc">Work with <b>Allocation</b> objects in Incremental Context change
 * mode by setting incremental Change context object.
 * </li>
 * </ul>
 * .
 * <br>
 * <br>
 * <b>Dependencies:</b>
 * <br>
 * StructureManagement
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoaallocationsstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoaallocationstypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOAALLOCATIONSSTRONGMNGD_API AllocationService
    : public Teamcenter::Services::Allocations::_2007_01::Allocation,
             public Teamcenter::Services::Allocations::_2011_06::Allocation
{
public:
    static AllocationService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * The operation is used to create new <b>AllocationLine</b> objects between <b>BOMLine</b>
     * objects of different product structures. This operation needs an <b>AllocationWindow</b>
     * object with an associated <b>AllocationMapRevision</b> object, for which <b>AllocationLine</b>
     * will be created and a list of structure <i>AllocationLineInfo</i> which consists
     * of name, type and reason for creation <b>AllocationLine</b> with from and to <b>BOMLines</b>
     * from different structure. This operation will return created <b>AllocationLine</b>
     * objects in the service data as created objects. If <b>BOMLine</b> is same for source
     * and target, then error will be reported and stored as service data error.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>AllocationLine</b> is a runtime representation of an <b>Allocation</b> object
     * as well as it provides runtime properties. It will maintain sources and targets information
     * for Allocation. When you want traceability between different aspects of a product,
     * you can use this operation to create <b>AllocationLine</b> objects.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createAllocationContext
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Allocations - Provides the functionality to map occurrences between two or more structures.
     * Currently used in Mechatronics to map logical schematic structures to physical 3D
     * structures.
     *
     * @param allocWindowInput
     *        <b>AllocationWindow</b> Object for which <b>AllocationLine</b> objects are to be
     *        added.
     *
     * @param inputAllocationLines
     *        A list of <i>AllocationLineInfo</i> structures which have information of <b>AllocationLine</b>
     *        objects which user wants to create.
     *
     * @return
     *         The created <b>AllocationLine</b> objects are added in created objects list of the
     *         ServiceData element. Any errors encountered at the time of creation of <b>AllocationLine</b>
     *         objects are included as part of the Service Data errors.
     *         <br>
     *         <br>
     *         This operation may return these partial errors:
     *         <br>
     *         <ul>
     *         <li type="disc">104335&nbsp;&nbsp;&nbsp;&nbsp;The specified target  BOMLine for
     *         AllocationLine is from the same BOMWindow of source bom line.
     *         </li>
     *         <li type="disc">104336&nbsp;&nbsp;&nbsp;&nbsp;The specified source BOMLine for AllocationLine
     *         is from the same BOMWindow of target BOMLine
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData addAllocationLines ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AllocationWindow>  allocWindowInput,
        const std::vector< Teamcenter::Services::Allocations::_2007_01::Allocation::AllocationLineInfo >& inputAllocationLines ) = 0;

    /**
     * The operation allows modifying the <b>BOMWindow</b> business objects associated to
     * the <b>AllocationWindow</b> while working with Allocation functionality. Allows user
     * to add new <b>BOMWindow</b> objects to the <b>AllocationWindow</b> and remove any
     * existing <b>BOMWindow</b> objects from the <b>AllocationWindow</b>. Once the <b>BOMWindow</b>
     * objects associated are modified, the <b>AllocationLine</b> objects for the context
     * of <b>AllocationWindow</b> are returned to the client. Any errors encountered will
     * be returned as part of partial errors in ServiceData element.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>To modify the </b><b>BOMWindows</b><b> associated to an </b><b>AllocationWindow</b>
     * <br>
     * While working in allocation functionality, if the user wants to work with an additional
     * product structure in addition to one which is opened already, or to close some unwanted
     * product structure, the user can achieve this using this operation by providing the
     * required <b>BOMWindow</b> business objects in <i>addBOMWindowList</i> and <i>removeBOMWindowList</i>.
     * <br>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * openAllocationWindow
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Allocations - Provides the functionality to map occurrences between two or more structures.
     * Currently used in Mechatronics to map logical schematic structures to physical 3D
     * structures.
     *
     * @param allocWindowInput
     *        <b>AllocationWindow</b> business object for which the <b>BOMWindow</b> objects have
     *        to be modified by adding any new <b>BOMWindows</b> or removing any existing <b>BOMWindow</b>
     *        objects.
     *
     * @param addBOMWindowList
     *        List of <b>BOMWindow</b> objects which have to be added to <b>AllocationWindow</b>
     *        input. It is an optional input.
     *
     * @param removeBOMWindowList
     *        List of <b>BOMWindow</b> objects which have to be removed from <b>AllocationWindow</b>
     *        input. It is an optional input.
     *
     * @return
     *         The modified <b>AllocationWindow</b> business object is returned after adding or
     *         removing the<b> </b><b>BOMWindow</b> objects provided as inputs in updated objects
     *         list of ServiceData element. A list of <b>AllocationLine</b> objects for the modified
     *         <b>AllocationWindow</b> is returned as updated objects of ServiceData element. Any
     *         errors during the operation will be returned as Partial Errors of ServiceData element.
     *
     */
    virtual Teamcenter::Services::Allocations::_2007_01::Allocation::GetAllocationWindowResponse changeAllocatedBOMWindows ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AllocationWindow>  allocWindowInput,
        const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMWindow>  >& addBOMWindowList,
        const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMWindow>  >& removeBOMWindowList ) = 0;

    /**
     * This operation is used to change the context object an <b>AllocationMapRevision</b>
     * business object of the input <b>AllocationWindow</b>. This operation requires <b>AllocationMapRevision</b>
     * object which user wants to set on <b>AllocationWindow</b>. This operation also sets
     * the <b>RevisionRule</b> for <b>AllocationWindow</b> and Incremental Change object
     * for the <b>AllocationWindow</b>.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Sets a new allocation context, Incremental Change context, <b>RevisionRule</b> for
     * an <b>AllocationWindow</b> and reloads the allocations for the given set context.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Allocations - Provides the functionality to map occurrences between two or more structures.
     * Currently used in Mechatronics to map logical schematic structures to physical 3D
     * structures.
     *
     * @param allocWindowInput
     *        <b>AllocationWindow</b> Object which is associated to an <b>AllocationMapRevision</b>
     *        object which user wants to change.
     *
     * @param allocationContext
     *        <b>AllocationMapRevision</b> object which user wants to set on input <b>AllocationWindow</b>.
     *
     * @param allocationRule
     *        <b>RevisionRule</b> to be set on <b>AllocationWindow</b> and load the allocations
     *        accordingly.
     *
     * @param icContext
     *        Incremental Change Context object to be set on the <b>AllocationWindow</b> (optional).
     *
     * @return
     *         Returns <b>AllocationWindow</b> object and a list of <b>AllocationLine</b> objects
     *         after the new context is set on <b>AllocationWindow</b> and the <b>RevisionRule</b>
     *         is applied on the <b>AllocationWindow</b>. Updated <b>AllocationWindow</b> is returned
     *         as part of update objects list of the Servicedata element and the loaded <b>AllocationLine</b>
     *         objects are returned as part of the created objects list of the ServiceData element.
     *         Any errors during the operation will be returned as part of partial errors of the
     *         ServiceData element.
     *         <br>
     *         <br>
     *         Following are some possible errors returned in ServiceData:
     *         <br>
     *         <ul>
     *         <li type="disc">104331&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Revision rule
     *         is not set for the specified AllocationWindow.
     *         </li>
     *         <li type="disc">104332&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Allocation
     *         Context is not set for the specified AllocationWindow.
     *         </li>
     *         <li type="disc">104333&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;No BOM Windows
     *         are associated to the specified AllocationWindow.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Allocations::_2007_01::Allocation::GetAllocationWindowResponse changeAllocationContext ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AllocationWindow>  allocWindowInput,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AllocationMapRevision>  allocationContext,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::RevisionRule>  allocationRule,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  icContext ) = 0;

    /**
     * Sets the <b>Incremental Change</b> context for an <b>AllocationWindow</b>. Used to
     * set a new Incremental Change context or remove the already set Incremental Change
     * context set on an <b>AllocationWindow</b>. Once the Incremental Change is set, the
     * <b>AllocationLine</b> objects for the context of <b>AllocationWindow</b> is returned
     * to the client.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Use </b><b>case 1</b><b>:  Set a new Incremental Change Context on Allocation
     * Window</b>
     * <br>
     * <ul>
     * <li type="disc">Set a new Incremental Change context for the <b>AllocationWindow</b>.
     * When the Incremental Change context is set on an <b>AllocationWindow</b>, the changes
     * made to the <b>AllocationWindow</b> like adding a new Allocation, deleting any existing
     * Allocation or modifying any Allocation will be captured in the IC context set. This
     * Incremental Change context can be used later to get all the modification made for
     * the given Incremental Change context object.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Use </b><b>Case 2</b><b>:  Remove the Incremental Change Context set on Allocation
     * Window</b>
     * <br>
     * <ul>
     * <li type="disc">Remove any set Incremental Change context for the <b>AllocationWindow</b>.
     * By passing an <i>NULL</i> input to the operation for Incremental Change context will
     * unset the Incremental Change and there after any modifications made to <b>AllocationWindow</b>
     * will not be captured incrementally.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * openAllocationWindow
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Allocations - Provides the functionality to map occurrences between two or more structures.
     * Currently used in Mechatronics to map logical schematic structures to physical 3D
     * structures.
     *
     * @param allocWindowInput
     *        <b>AllocationWindow</b> object for which Incremental changes like adding an new allocation,
     *        removing an existing allocation, or modifying an allocation has  to be captured.
     *
     * @param icContextRev
     *        Incremental Change Revision object which is set on <b>AllocationWindow</b> . If <i>NULL</i>
     *        is provided as the input, and the <b>AllocationWindow</b> has any Incremental Change
     *        context set, it will be removed.
     *
     * @return
     *         A list of <b>AllocationLine</b> objects for the given <b>AllocationWindow</b> is
     *         returned as plain Objects in the ServiceData element. The <b>AllocationWindow</b>
     *         object for which the Incremental Change object is set is returned as part of updated
     *         Object of the ServiceData element.  Any errors during the operation will be returned
     *         as Partial Errors of the ServiceData element.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData changeICContext ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AllocationWindow>  allocWindowInput,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  icContextRev ) = 0;

    /**
     * The operation closes the <b>AllocationWindow</b> and returns the unique identifier
     * string of the <b>AllocationWindow</b> business Object in the deleted object list
     * of ServiceData.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Use case </b><b>1</b><b>: Close Allocation Window after create </b>
     * <br>
     * <ul>
     * <li type="disc">Create new <b>AllocationWindow</b>, and adding allocations between
     * multiple product structure and save, modify further and the <b>AllocationWindow</b>
     * will be closed. Any unsaved <b>Allocation</b> changes will not be saved to Teamcenter
     * before close.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Use case </b><b>2</b><b>: Close Allocation Window after Open</b>
     * <br>
     * <ul>
     * <li type="disc">Open an <b>AllocationWindow</b> using an existing <b>AllocationMapRevsion</b>
     * object. Add necessary <b>Allocation</b> objects, modify any existing <b>Allocation</b>
     * objects, delete any unwanted Allocation. Save the <b>AllocationWindow</b>. Close
     * the <b>AllocationWindow</b>. Any unsaved <b>Allocation</b> changes will not be saved
     * to Teamcenter when the <b>AllocationWindow</b> closes.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createAllocationContext
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Allocations - Provides the functionality to map occurrences between two or more structures.
     * Currently used in Mechatronics to map logical schematic structures to physical 3D
     * structures.
     *
     * @param allocWindowInput
     *        <b>AllocationWindow</b> object which has changes has to be saved.
     *
     * @param force
     *        For future use.
     *
     * @return
     *         The unique identifier of the closed <b>AllocationWindow</b> business object will
     *         be returned as part of the deleted object list of the ServiceData element. Any errors
     *         during the operation will be returned as Partial Errors of the ServiceData element.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData closeAllocationWindow ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AllocationWindow>  allocWindowInput,
        bool force ) = 0;

    /**
     * This operation is used to create an <b>AllocationMap</b> and <b>AllocationMapRevision</b>
     * object  from the  <i>AllocationContextInput</i> structure.<b> </b><b>AllocationContextInput</b>
     * consists of Name, id, Revision, type, list  of BOM (Bill of Material) Windows for
     * which allocations has to be created. In this operation, it will create an <b>AllocationMapRevision</b>
     * and sets it window to said context.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Allocation allows to map one or more <b>BOMLine</b> objects of two or more product
     * structures. An <b>AllocationMap</b> is a business object that specifies how two structures
     * are tied together by a set of allocations that exist between two structures. Defining
     * such an <b>AllocationMap</b> needs allocation context which is carried out by this
     * operation.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Allocations - Provides the functionality to map occurrences between two or more structures.
     * Currently used in Mechatronics to map logical schematic structures to physical 3D
     * structures.
     *
     * @param input
     *        Structures containing the details of the <b>AllocationMap</b> and <b>AllocationMapRevision</b>
     *        object to be created.
     *
     * @return
     *         Created <b>AllocationWindow</b> is returned from this operation. Service Data contains
     *         <b>AllocationMap</b> and <b>AllocationMapRevision</b>, <b>AllocationWindow</b> as
     *         part of created objects list.
     *         <br>
     *         <br>
     *         Following are some possible errors returned in ServiceData
     *         <br>
     *         <ul>
     *         <li type="disc">104330&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Failed to create
     *         AllocationWindow, Internal error.
     *         </li>
     *         <li type="disc">104331&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Revision rule
     *         is not set for the specified AllocationWindow.
     *         </li>
     *         <li type="disc">104332&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Allocation
     *         Context is not set for the specified AllocationWindow.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Allocations::_2007_01::Allocation::GetAllocationWindowResponse createAllocationContext ( const Teamcenter::Services::Allocations::_2007_01::Allocation::AllocationContextInput&  input ) = 0;

    /**
     * The operation is used to delete <b>AllocationLine</b> objects created between <b>BOMLine</b>
     * objects of different product structures. This operation needs an <b>AllocationWindow</b>
     * object with an associated <b>AllocationMapRevision</b> object, also a list of <b>AllocationLine</b>
     * objects which  are going to be deleted. This operation will return deleted <b>AllocationLine</b>
     * objects unique identifier string in the service data as deleted objects. The deletion
     * of <b>AllocationLine</b> objects are only allowed  on a Teamcenter Master site and
     * if this operation is attempted from a Replica site then an error will be reported
     * and stored as a service data error. If the <b>AllocationWindow</b> has any Incremental
     * Context object set, the deletion of <b>AllocationLine</b> will be captured in the
     * IncrementalChange business object.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>AllocationLine</b> is a runtime representation of an <b>Allocation</b> object
     * as well as it provides runtime properties. It will maintain source and target information
     * for an <b>Allocation</b>. Use this operation to delete Allocation between different
     * aspects of a product.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createAllocationContext
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Allocations - Provides the functionality to map occurrences between two or more structures.
     * Currently used in Mechatronics to map logical schematic structures to physical 3D
     * structures.
     *
     * @param allocWindowInput
     *        <b>AllocationWindow</b> Parent object  from which to remove <b>AllocationLine</b>
     *        objects.
     *
     * @param inputAllocationLines
     *        A list of <b>AllocationLine</b> objects to be deleted from the <b>AllocationWindow</b>.
     *
     * @return
     *         The deleted <b>AllocationLine</b> objects unique identifier string are added  to
     *         the deleted objects list of the ServiceData element. Any errors encountered at the
     *         time of deletion of <b>AllocationLine</b> objects are included as part of the Service
     *         Data errors.
     *         <br>
     *         <br>
     *         Following are some possible errors returned in ServiceData:
     *         <br>
     *         <ul>
     *         <li type="disc">104337&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Invalid Allocation
     *         line does not represent a valid Allocation object.
     *         </li>
     *         <li type="disc">104338&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Invalid Allocation
     *         Window specified by the Allocation line.
     *         </li>
     *         <li type="disc">104339&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Invalid Allocation
     *         line specified as input.
     *         </li>
     *         <li type="disc">104347&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The deletion
     *         of object XXX (Name of object) failed because deletion of replica Allocation objects
     *         is not allowed.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData deleteAllocationLines ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AllocationWindow>  allocWindowInput,
        const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AllocationLine>  >& inputAllocationLines ) = 0;

    /**
     * The operation identifies all the <b>PSBOMView</b> BusinessObjects that are associated
     * to the input <b>PSBOMView</b> Business Object in context of any <b>AllocationMap</b>
     * object.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Find any BOMViews which are associated to the input BOMView for Allocation functionality</b>
     * <br>
     * One or more BOMViews in the Product Structure are mapped using Allocation functionality
     * in context of the <b>AllocationMap</b> object. <b>Allocation</b> objects are created
     * between the <b>BOMLine</b> objects of a ProductStructure. If the user needs to identify
     * the <b>PSBOMView</b> object which has any allocations associated with the input <b>PSBOMView</b>
     * , the operation returns such associated <b>PSBOMView</b> Objects.
     * <br>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createAllocationContext
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Allocations - Provides the functionality to map occurrences between two or more structures.
     * Currently used in Mechatronics to map logical schematic structures to physical 3D
     * structures.
     *
     * @param bomView
     *        <b>PSBOMView</b> business object for which associated <b>PSBOMView</b> business object
     *        in context of <b>AllocationMap</b> object are to be returned.
     *
     * @return
     *         A list of <i>GetAllocatedBOMViewInfo</i> , one for each identified <b>AllocationMap</b>
     *         object which have the input <b>PSBOMView</b> business object as one of the associated
     *         <b>PSBOMView</b> objects in the Allocation context. Also a ServiceData element is
     *         returned. Errors encountered are added to Partial Error of the ServiceData element.
     *         <br>
     *         
     *         <br>
     *         Following partial errors are possible
     *         <br>
     *         <ul>
     *         <li type="disc">104215&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The tag of
     *         the AllocationMap specified is invalid.
     *         </li>
     *         <li type="disc">104026&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Memory error
     *         has occurred in input object.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Allocations::_2007_01::Allocation::GetAllocatedBOMViewResponse findAllocatedBOMViews ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PSBOMView>  bomView ) = 0;

    /**
     * The operation identifies the <b>AllocationMap</b> Business objects which are used
     * as context for the given input <b>PSBOMView</b> Business objects.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Find </b><b>AllocationMap</b><b> objects which are used as context for input </b><b>PSBOMView</b><b>
     * objects for Allocation functionality</b>
     * <br>
     * Two or more <b>PSBOMView</b> of Product Structure are mapped using <b>Allocation</b>
     * functionality in context of <b>AllocationMapRevision</b> object. <b>Allocation</b>
     * objects are created between the <b>BOMLine</b> objects of ProductStructure. If user
     * needs to identify for a given list of <b>PSBOMView</b> objects what are all the AllocationMap
     * Business Objects which are used as context, the operation returns such <b>AllocationMapRevision</b>
     * Objects.
     * <br>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createAllocationContext
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Allocations - Provides the functionality to map occurrences between two or more structures.
     * Currently used in Mechatronics to map logical schematic structures to physical 3D
     * structures.
     *
     * @param bomViews
     *        List of <b>PSBOMView</b> objects, for which the Allocation context has to be returned.
     *
     * @return
     *         A list of <b>AllocationMap</b> business objects which are the context for the given
     *         list of <b>PSBOMView</b> business objects is returned in Plain Objects of the ServiceData
     *         element. Errors encountered are added to the  Partial Error of ServiceData element.
     *         <br>
     *         <br>
     *         Following partial errors are possible
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">104215&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The tag of
     *         the AllocationMap specified is invalid
     *         </li>
     *         <li type="disc">104026&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Memory error
     *         has occured in input object
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData findAllocationContexts ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PSBOMView>  >& bomViews ) = 0;

    /**
     * In allocation functionality in context of an <b>AllocationMapRevision</b> object,
     * allocations are created between  two or more product structures. This operation returns
     * the <b>PSBOMView</b> objects associated to the given <b>AllocationMapRevision</b>
     * object.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * For the given <b>AllocationMapRevision</b> object, the <b>PSBOMView</b> objects associated
     * to the <b>AllocationWindow</b> object to create allocations are identified and returned.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createAllocationContext
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Allocations - Provides the functionality to map occurrences between two or more structures.
     * Currently used in Mechatronics to map logical schematic structures to physical 3D
     * structures.
     *
     * @param allocationContext
     *        <b>AllocationMapRevision</b> object for which the associated <b>PSBOMView</b> objects
     *        are to be identified.
     *
     * @return
     *         A list of <b>PSBOMView</b> objects with a given <b>AllocationMapRevision</b> as context
     *         is returned in the plain objects of ServiceData. Any errors during the operation
     *         will be returned in the Partial Errors of ServiceData element.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData getBOMViews ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AllocationMapRevision>  allocationContext ) = 0;

    /**
     * The operation is used to modify <b>AllocationLine</b> objects created between <b>BOMLine</b>
     * objects of different product structures which are already present in an <b>AllocationWindow</b>.
     * This operation needs an <b>AllocationWindow</b> object with an associated <b>AllocationMapRevision</b>
     * object, for which <b>AllocationLine</b> will be modified for source or target <b>BOMLine</b>
     * objects and a list of structure AllocationLineInput which consists of AllocationLine
     * object and structure <i>AllocationLineInfo</i>. An AllocationLineInfo object information
     * like from and to <b>BOMLine</b> objects are used for this modification purpose. This
     * operation will return the modified <b>AllocationLine</b> objects in the service data
     * as updated objects. If the <b>BOMLine</b> is the same for both source and target,
     * then an error will be reported and stored as a service data error.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>AllocationLine</b> is a runtime representation of an <b>Allocation</b> object
     * as well as it provides runtime properties. It will maintain source and target information
     * for an <b>Allocation</b>. Use this operation to modify <b>AllocationLine</b> objects
     * between different aspects of a product.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createAllocationContext
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Allocations - Provides the functionality to map occurrences between two or more structures.
     * Currently used in Mechatronics to map logical schematic structures to physical 3D
     * structures.
     *
     * @param allocWindowInput
     *        <b>AllocationWindow</b> parent object for which the <b>AllocationLine</b> objects
     *        be modified.
     *
     * @param inputAllocationLines
     *        A list of <b>AllocationLine</b> object inputs and their attributes to be modified.
     *
     * @return
     *         The modified <b>AllocationLine</b> objects are added to the updated objects list
     *         of the ServiceData element. Any errors encountered at the time of creation of <b>AllocationLine</b>
     *         objects are included as part of the Service Data errors.
     *         <br>
     *         <br>
     *         This operation may return these parial errors:
     *         <br>
     *         <ul>
     *         <li type="disc">104335&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The specified
     *         target bom line for Allocation line is from the same bom window of source bom line.
     *         </li>
     *         <li type="disc">104336&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The specified
     *         source bom line for Allocation line is from the same bom window of target bom line
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData modifyAllocationLines ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AllocationWindow>  allocWindowInput,
        const std::vector< Teamcenter::Services::Allocations::_2007_01::Allocation::AllocationLineInput >& inputAllocationLines ) = 0;

    /**
     * The operation creates an <b>AllocationWindow</b> for the given allocation context
     * object. After creating the <b>AllocationWindow</b> object, the operation opens the
     * <b>AllocationWindow</b> and sets the <b>RevisionRule</b> and the incremental change
     * context on the opened <b>AllocationWindow</b>. The operation finds all the configured
     * AllocationLine objects corresponding to the given <b>BOMWindow</b> objects and returns
     * them to the user along with the <b>AllocationWindow</b> object.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * The <b>AllocationWindow</b> is usually created and opened to find different allocations
     * between two or more BOM View objects. For example the user wants to find various
     * functions defined in the functional model of a product allocated to different ECUs
     * in the logical model. In this case an <b>AllocationWindow</b> for given allocation
     * context is created and opened. All the function to ECU allocations relevant to the
     * opened functional and logical model for the given revision rule and incremental change
     * context are fetched and displayed to the user in the form of <b>AllocationLine</b>
     * objects.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createAllocationContext
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Allocations - Provides the functionality to map occurrences between two or more structures.
     * Currently used in Mechatronics to map logical schematic structures to physical 3D
     * structures.
     *
     * @param allocWindowInput
     *        An <i>AllocationWindowInfo</i> object, which contains the allocation context, <b>RevisionRule</b>
     *        and the list of relevant <b>BOMWindow</b> objects.
     *
     * @param icContext
     *        An Optional parameter which is a reference to the incremental change context object.
     *
     * @return
     *         The configured <b>AllocationLine</b> objects, a reference to the newly created <b>AllocationWindow</b>
     *         are returned. The <b>AllocationLine</b> objects are returned as part of created
     *         objects of service data object.
     *         <br>
     *         This operation may return these partial errors:
     *         <br>
     *         <ul>
     *         <li type="disc">104330&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Failed to create
     *         AllocationWindow.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Allocations::_2007_01::Allocation::GetAllocationWindowResponse openAllocationWindow ( const Teamcenter::Services::Allocations::_2007_01::Allocation::AllocationWindowInfo&  allocWindowInput,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  icContext ) = 0;

    /**
     * Saves any modifications made in the <b>AllocationWindow</b>. Newly created <b>Allocation</b>
     * objects will be saved to Teamcenter. <b>Allocation</b> objects which are deleted
     * will be removed from Teamcenter. Any modification made to the Allocation will be
     * updated in Teamcenter. If any new Incremental Change objects were created in this
     * <b>AllocationWindow</b>, they will be saved to Teamcenter. If any <b>AllocationLine</b>
     * objects are removed and if it is part of an Incremental Change object, it will be
     * removed from Teamcenter. All changes made in the <b>AllocationWindow</b> will be
     * saved and after save the <b>AllocationLine</b> objects of the <b>AllocationWindow</b>
     * will be returned to the client.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Use case </b><b>1</b><b>: Save Allocation Window after create and add allocations</b>
     * <br>
     * <ul>
     * <li type="disc">After creation of a new <b>AllocationWindow</b> new AllocationLine
     * objects can be added. After creating necessary allocations, the <b>AllocationWindow</b>
     * is saved to save the changes to Teamcenter.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Use case </b><b>2</b><b>: Save Allocation Window after open and modification</b>
     * <br>
     * <ul>
     * <li type="disc">After creation of a new <b>AllocationWindow</b> or opening an existing
     * <b>AllocationWindow</b>, new <b>AllocationLine</b> objects can be added, existing
     * allocations can be removed or modified for both source and target. After making necessary
     * changes, the <b>AllocationWindow</b> is saved to save the changes to Teamcenter.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createAllocationContext
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Allocations - Provides the functionality to map occurrences between two or more structures.
     * Currently used in Mechatronics to map logical schematic structures to physical 3D
     * structures.
     *
     * @param allocWindowInput
     *        <b>AllocationWindow</b> object for which changes are to be saved.
     *
     * @return
     *         A list of <b>AllocationLine</b> objects for the given <b>AllocationWindow</b> is
     *         returned in plain objects of ServiceData element.  An <b>AllocationWindow</b> object
     *         for which the save is performed will be returned as an updated object of the ServiceData
     *         element. Any errors during the operation will be returned as Partial Errors of the
     *         ServiceData element.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData saveAllocationWindow ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AllocationWindow>  allocWindowInput ) = 0;

    /**
     * The operation creates an <b>AllocationMap</b> object for the given name, id and attribute
     * map input. This operation has Multi field key support for <b>AllocationMap</b> business
     * object creation. The created <b>AllocationMap</b> object is saved to Teamcenter.
     * It creates an <b>AllocationWindow</b> with the <b>AllocationMapRevision</b> object
     * as context. It adds the input <b>BOMWindow</b> objects as the <b>BOMWindow</b> objects
     * for the <b>AllocationWindow</b>. The created <b>AllocationMap</b>, <b>AllocationRevision</b>,
     * <b>AllocationWindow</b> are returned as created objects list in ServiceData Element.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Create </b><b>AllocationMap</b><b> object with Multi field key support</b>
     * <br>
     * The <b>AllocationMap</b> object can be created with full Multi field key support
     * using this operation. If the business constant of MFK for the <b>AllocationMap</b>
     * object has item_id and any other attribute, then the user can create <b>AllocationMap</b>
     * with same item id as well.
     * <br>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createBOMWindows
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Allocations - Provides the functionality to map occurrences between two or more structures.
     * Currently used in Mechatronics to map logical schematic structures to physical 3D
     * structures.
     *
     * @param input
     *        An <b>AllocationMap</b> business object is created using the input using the id,
     *        name, revision, type,<b> </b><b>BOMWindows</b>, extended attribute values provided
     *        in attrValuemap.
     *
     * @return
     *         Returns the <b>AllocationWindow</b> created, as created Objects list of the ServiceData
     *         Element.  The created <b>AllocationMap</b>, <b>AllocationMapRevision</b> business
     *         object are also returned as part of created objects list of the ServiceData element.
     *         Any errors during the operation will be returned as Partial Errors of the ServiceData
     *         element.
     *
     */
    virtual Teamcenter::Services::Allocations::_2007_01::Allocation::GetAllocationWindowResponse createAllocationContext2 ( const Teamcenter::Services::Allocations::_2011_06::Allocation::AllocationContextInput2&  input ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AllocationService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/allocations/Allocations_undef.h>
#endif

