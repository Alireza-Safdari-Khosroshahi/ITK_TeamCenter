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

#ifndef PTN0_SERVICES_PARTITION_PARTITIONMANAGEMENTSERVICE_HXX
#define PTN0_SERVICES_PARTITION_PARTITIONMANAGEMENTSERVICE_HXX

#include <ptn0/services/partition/_2011_06/Partitionmanagement.hxx>
#include <ptn0/services/partition/_2013_05/Partitionmanagement.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <ptn0/services/partition/Partition_exports.h>

namespace Ptn0
{
    namespace Services
    {
        namespace Partition
        {
            class PartitionmanagementService;

/**
 * This service exposes operations related to <i>partition</i>s in Teamcenter.  Partitions
 * logically organize large sets of design elements into a hierarchy that permits the
 * CAD users to easily find their assigned data. Customers can represent functional
 * divisions of the product (for example, propulsion systems or avionics), or they can
 * represent physical divisions (for example, engine room or electronics bay). The nodes
 * in a physical partition <i>breakdown</i> represent placeholders that may be populated
 * by actual product content obtained from part releasing systems, CAD systems, or manufacturing
 * planning systems.
 * <br>
 * Partitions can be added to other <i>partitions</i>, typically to build a default
 * manufacturing process. For example, you can paste<i> partition P1</i> into <i>partition
 * P2</i>, where the content of <i>partition P1</i> represents a set of expected components
 * and the containing <i>partition P2</i> represents a generic manufacturing process
 * step. Pasting the generic physical <i>partition P1</i> into the generic process <i>partition
 * P2</i> implies that the components will be attached to P1 with the manufacturing
 * process represented by P2.
 * <br>
 * <br>
 * Partitions can be organized hierarchically into breakdowns. Partitions reference
 * a scheme that defines constraints for the partitions in this scheme, for example,
 * the list of partition types that you can arrange into a<i> partition breakdown </i>in
 * this scheme. The nodes in a physical <i>partition breakdown</i> represent placeholders
 * that may be populated by actual product content obtained from part releasing systems,CAD
 * systems or manufacturing planning systems. These hierarchies are built using child
 * parent links, where the child chooses the parent.
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libptn0soapartitionstrongmngd.dll
 * </li>
 * <li type="disc">libptn0soapartitiontypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class PTN0SOAPARTITIONSTRONGMNGD_API PartitionmanagementService
    : public Ptn0::Services::Partition::_2011_06::Partitionmanagement,
             public Ptn0::Services::Partition::_2013_05::Partitionmanagement
{
public:
    static PartitionmanagementService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * This operation is used to get configured or unconfigured child <i>Partitions</i>
     * of the input parent Partitions. Desired level of children and desired number of children
     * can be fetched by specifying the input parameters maximum level of children and maximum
     * number of children respectively.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * When user creates a <i>Partition</i> <i>Breakdown</i> with Parent Partitions and
     * child Partitions, he can select a single or multiple Partitions within this breakdown
     * and try to fetch their child Partitions.The maximum number of child Partitions and
     * level of child Partitions can be given as an optional input. User can get all or
     * desired number of configured or un configured children of input Partitions at all
     * levels or desired levels in a Partition Breakdown by supplying <b>ConfigurationContext</b>
     * object as input.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Partition Management - Defines Partition Management operation (add/modify/remove
     * members and child partitions),Partition Template creation and management and cloning
     * functionality and extends the search services in the AppModel component.
     *
     * @param inputs
     *        Vector of Structures containing the details of Parent Partitions, number and level
     *        of child Partitions to be fetched. Configured child Partitions can be obtained by
     *        specifying the <b>ConfigurationContext</b> object.
     *
     * @return
     *         <code>GetChildrenResponse</code> consists of <code>GetChildrenOutputInfo</code> and
     *         <code>serviceData</code> structures. Child Partitions along with their Parent Partitions
     *         are returned via <code>GetChildrenOutputInfo</code>.  If the input parameters are
     *         invalid, the errors are returned in <code>serviceData</code>.
     *
     *
     * @exception ServiceException
     *           Following possible error is returned in serviceData.
     *           <br>
     *           280001 Invalid objects are supplied as inputs to the operation
     *           <br>
     */
    virtual Ptn0::Services::Partition::_2011_06::Partitionmanagement::GetChildrenResponse getChildren ( const std::vector< Ptn0::Services::Partition::_2011_06::Partitionmanagement::GetChildrenInputInfo >& inputs ) = 0;

    /**
     * This operation is used to get configured or un configured members of the input <i>Partitions</i>.
     * All the members of a single or multiple Partitions can be fetched using this operation.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * When user creates a Partition Breakdown with Partitions and members (e.g., Design
     * Elements) , user can select a single or multiple Partitions within this breakdown
     * and try to fetch their members. User can get all configured or un configured members
     * of input Partitions by supplying <b>ConfigurationContext</b> object as input. Depending
     * on the use case, the user may get the dynamic members or static members or both or
     * depending on the default persistence mode of the Partition. An additional flag can
     * also be passed as input to load the graphic data that is associated with each member.
     * <br>
     * <br>
     * Use case 1:
     * <br>
     * When user adds members to a static Partition, system creates Membership links to
     * this Partition. These members can be fetched by specifying the content persistence
     * mode input argument as <code>STATIC_MODE</code>.
     * <br>
     * <br>
     * Use case 2:
     * <br>
     * When user adds members to a Partition dynamically, system updates recipe on Partition.
     * System will not create any persistent Membership links when Partitions are updated
     * dynamically. These dynamic members can be fetched by executing the recipe, by specifying
     * the content persistence mode input argument as <code>DYNAMIC_MODE</code>.
     * <br>
     * <br>
     * Use case 3:
     * <br>
     * Users can add members to Partitions statically by creating Memberships and dynamically
     * by creating the search recipe. Both these static members and dynamic members can
     * be fetched by specifying the content persistence mode input argument as <code>ALL_MODE</code>.
     * <br>
     * <br>
     * Use case 4:
     * <br>
     * Users can add members to Partitions statically by creating Memberships and also dynamically
     * by creating search recipe. The members can be fetched depending on the default persistence
     * mode of the Partition also i.e., if Partition is a dynamic Partition like a <code>Spatial
     * Partition</code>, then user can get dynamic members and if its a static Partition
     * like a<code> Functional Partition</code>,<b> </b>then user can fetch static members
     * by specifying the content persistence mode input argument as <code>AUTO_MODE.
     * <br>
     * </code>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Partition Management - Defines Partition Management operation (add/modify/remove
     * members and child partitions),Partition Template creation and management and cloning
     * functionality and extends the search services in the AppModel component.
     *
     * @param inputs
     *        Vector of Structures containing the details of Parent Partitions, number and level
     *        of child Partitions to be fetched. Configured child Partitions can be obtained by
     *        specifying the Configuration Context object.
     *
     * @return
     *         <code>GetMembersResponse</code> consists of <code>GetMembersOutputInfo</code> and
     *         <code>serviceData</code> structures. Partitions along with their members are returned
     *         via <code>GetMembersOutputInfo</code>.  If the input parameters are invalid, the
     *         errors are returned in <code>serviceData</code>.
     *
     *
     * @exception ServiceException
     *           Following possible error is returned in serviceData.
     *           <br>
     *           280001 Invalid objects are supplied as inputs to the operation.
     *           <br>
     */
    virtual Ptn0::Services::Partition::_2011_06::Partitionmanagement::GetMembersResponse getMembers ( const std::vector< Ptn0::Services::Partition::_2011_06::Partitionmanagement::GetMembersInputInfo >& inputs ) = 0;

    /**
     * This operation is used to get configured or un configured parent Partitions of the
     * input child Partitions.Desired level of parent Partitions and desired number of Parents
     * can be fetched by specifying the input parameters maximum level of parents and maximum
     * number of parents respectively.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * When user creates a <i>Partition Breakdown</i> with parent Partitions and child Partitions,
     * he can select a single or multiple child Partitions within this breakdown and try
     * to fetch their parent Partitions.  The maximum number of parent Partitions and level
     * of parent Partitions can be given as an optional input. User can get all or desired
     * number of configured or un configured parents of input child Partitions at all levels
     * or desired levels in a Partition breakdown by supplying <b>ConfigurationContext </b>object
     * as input.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Partition Management - Defines Partition Management operation (add/modify/remove
     * members and child partitions),Partition Template creation and management and cloning
     * functionality and extends the search services in the AppModel component.
     *
     * @param inputs
     *        Vector of Structures containing the details of child Partitions, number and level
     *        of parent Partitions to be fetched. Configured parent Partitions can be obtained
     *        by specifying the <b>ConfigurationContext</b> object.
     *
     * @return
     *         <code>GetParentsResponse</code> consists of <code>GetParentsOutputInfo</code> and
     *         <code>serviceData</code> structures. Parent Partitions along with their child Partitions
     *         are returned via <code>GetParentsOutputInfo</code>.  If the input parameters are
     *         invalid, the errors are returned in <code>serviceData</code>.
     *
     *
     * @exception ServiceException
     *           Following possible error is returned in serviceData.
     *           <br>
     *           280001 Invalid objects are supplied as inputs to the operation.
     *           <br>
     */
    virtual Ptn0::Services::Partition::_2011_06::Partitionmanagement::GetParentsResponse getParents ( const std::vector< Ptn0::Services::Partition::_2011_06::Partitionmanagement::GetParentsInputInfo >& inputs ) = 0;

    /**
     * <code>getPartitions </code>SOA<b> </b>operation<b> </b>is used for getting all the
     * Partitions from the Partition Scheme and Application Model given by user. User can
     * limit the number of Partitions in output by giving <code>maxpartitionCount</code>
     * in <code>GetPartitionsInputInfo</code>  input structure.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Use Case 1: Get All partitions from Application Model and Partition Scheme.
     * <br>
     * User can give Partition scheme and application model to find out partition lying
     * under it.
     * <br>
     * User has following structure created.
     * <br>
     * To get Partitions under the Partition Scheme and Application Model execute the <code>getPartitions</code>
     * SOA.
     * <br>
     * ModelA
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;|
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;SchemeA
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|_Partition1
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|_Partition2
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|_Partition3
     * <br>
     * <br>
     * After performing SOA operation with ModelA and SchemeA as input it returns Partition1,
     * Partition2 and Partition3 as output, provided <code>maxPartitionCount</code> is set
     * to 0 which mean all the results will be returned without truncating partition list.
     * <br>
     * <br>
     * Use Case 2: Get N Number of partition from Application Model and Scheme.
     * <br>
     * Consider structure in use case 1 but the only the difference is <code>maxPartitionCount</code>
     * set to 2 in this case. So performing same operation as above with this <code>maxPartitionCount</code>
     * truncates output result and gives only Partition1 and Partition2 in output.
     * <br>
     * <br>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createObjects
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Partition Management - Defines Partition Management operation (add/modify/remove
     * members and child partitions),Partition Template creation and management and cloning
     * functionality and extends the search services in the AppModel component.
     *
     * @param input
     *        Vector of the structure <code>GetPartitionsInputInfo</code>.
     *
     * @return
     *         <code>GetPartitionsResponse</code> contains the vector of the <code>GetPartitionsOutputInfo</code>
     *         and  <code>ServiceData</code>.
     *         <br>
     *         The exceptions occurred while performing the operation is returned in <code>serviceData</code>,
     *         output list of Partitions is added to the plain object list of the <code>serviceData</code>.
     *         <br>
     *
     */
    virtual Ptn0::Services::Partition::_2011_06::Partitionmanagement::GetPartitionsResponse getPartitions ( const std::vector< Ptn0::Services::Partition::_2011_06::Partitionmanagement::GetPartitionsInputInfo >& input ) = 0;

    /**
     * This operation is used to get all the Partition<b> </b>Schemes which are defined
     * under specified Application<b> </b>Model. Application Model object is provided as
     * the input parameter for this SOA.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User creates multiple Partition<b> </b>Schemes<b> </b>under the<b> </b>Application
     * Model<b>.</b>
     * <br>
     * <br>
     * Application Model (Model A)
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;| _ _ Partition
     * Scheme A<b>
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</b>|<b>
     * _ _ </b>Partition Scheme B<b>
     * <br>
     * </b>
     * <br>
     * To getSchemesInModel SOA user gives ModelA as input and SOA will return the list
     * containing values Partition Scheme A<b> </b>and Partition Scheme B<b>.</b>
     * <br>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createObjects
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Partition Management - Defines Partition Management operation (add/modify/remove
     * members and child partitions),Partition Template creation and management and cloning
     * functionality and extends the search services in the AppModel component.
     *
     * @param inputs
     *        Application Model object is supplied as input to SOA.
     *
     * @return
     *         <ul>
     *         <li type="disc">Contains<b> </b>output list of Partition Schemes and exceptions in
     *         service data.
     *         </li>
     *         <li type="disc">Service data is also populated with the plain objects list containing
     *         output partition schemes.
     *         </li>
     *         <li type="disc">Returns error if user provides <code>NULLTAG</code> in input for
     *         Application Model.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           The operation may return one of the following errors in serviceData
     *           <br>
     *           280005 wrong input supplied.
     */
    virtual Ptn0::Services::Partition::_2011_06::Partitionmanagement::GetSchemesInModelResponse getSchemesInModel ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Mdl0ApplicationModel>  >& inputs ) = 0;

    /**
     * This operation can be used to fetch top level partitions(<b>Ptn0Partition</b>) for
     * a Partition Schemes(<b>Ptn0PartitionScheme</b>)<i> </i>within an Application Model
     * e.g., a Collaborative Design (<b>Cpd0CollaborativeDesign</b>). This operation can
     * be used to get top level Partitions in bulk from multiple Partition Schemes in multiple
     * Application Models. Top level Partitions in a Partition scheme are the Partitions
     * which are not children of any other Partitions. Hence, there can be more than one
     * top level Partition in a scheme.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Use Case :  Get Top Level Partitions in a Partition Scheme</b>
     * <br>
     * In<i> </i>CPD Application, users can create Partition Breakdowns in a partition scheme
     * and may want to browse through this breakdown from top to down. In such cases, user
     * may start with top level Partition in a scheme and then can browse through its children.
     * <br>
     * <br>
     * Users can query for all the top level Partitions in a set of Partition Schemes within
     * corresponding  Application Models by specifying both the Partition Schemes and their
     * Application models as input parameters. Based on input Configuration Context , Configured
     * top level partitions are returned in response and a NULL Configuration Context<i>
     * </i>returns unconfigured  top level Partitions.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Partition Management - Defines Partition Management operation (add/modify/remove
     * members and child partitions),Partition Template creation and management and cloning
     * functionality and extends the search services in the AppModel component.
     *
     * @param inputs
     *        Vector of Structures containing the details of  Partition scheme and  Application
     *        model
     *
     * @return
     *         <code>GetTopLevelPartitionsResponse</code> consists of <code>GetTopLevelPartitionsOutputInfo</code>
     *         and <code>serviceData</code> structures. Top level Partitions along with the corresponding
     *         Partition Scheme are returned via <code>GetTopLevelPartitionsOutputInfo</code>.
     *         If the input parameters are invalid, the errors are returned in <code>serviceData</code>.
     *
     *
     * @exception ServiceException
     *           Following possible error is returned in <code>serviceData</code>.
     *           <br>
     *           280001 Invalid objects are supplied as inputs to the operation.
     *           <br>
     */
    virtual Ptn0::Services::Partition::_2011_06::Partitionmanagement::GetTopLevelPartitionsResponse getTopLevelPartitions ( const std::vector< Ptn0::Services::Partition::_2011_06::Partitionmanagement::GetTopLevelPartitionsInputInfo >& inputs ) = 0;

    /**
     * This service operation is used to create the snapshot of the members which are attached
     * to the input Partition dynamically. Inputs Partition and configuration context, are
     * used to get all the existing Members  of Partition. The members which are added in
     * dynamic mode are persisted by creating static Membership objects for them.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Use Case : <b>Persist Dynamic Members of input partition</b>.
     * <br>
     * <ul>
     * <li type="disc">Create<b> </b>Collaborative<b> </b>design<b> </b>in<b> </b>given
     * applica<b>t</b>ion<b> </b>model.
     * </li>
     * <li type="disc">Create<b> </b>Partition Scheme and configuration context in above
     * collaborative design.
     * </li>
     * <li type="disc">Create Partition and Design elements in Partition Scheme and collaborative
     * design
     * </li>
     * </ul>
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  respectively.
     * <br>
     * <ul>
     * <li type="disc">Update Partition with Members in dynamic mode by updating recipe.
     * </li>
     * <li type="disc">Call persist dynamic SOA using above Partition and configuration
     * context
     * </li>
     * </ul>
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  This use case will execute in following
     * sequence, to persist the dynamic members of given partition.
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1.
     * Use input Partition and the configuration context to get all the existing memberships
     * for this Partition.
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2.
     * Delete all the memberships got from step no. 1.
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;3.
     * Get dynamic members for input Partition.
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;4.
     * Create static memberships in bulk for all the dynamic members (from step 3) to
     * input Partition.
     * <br>
     * <br>
     * <ul>
     * <li type="disc">This will convert all the dynamic members in static ones by creating
     * a static Membership for all members updated in dynamic mode.
     * </li>
     * </ul>
     * <br>
     * <br>
     * All the dynamic Members of input Partition are now static after creating membership
     * objects in database.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createObjects
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Partition Management - Defines Partition Management operation (add/modify/remove
     * members and child partitions),Partition Template creation and management and cloning
     * functionality and extends the search services in the AppModel component.
     *
     * @param inputs
     *        Partition whose dynamic members need to be persisted as static memberships with isFromRecipe
     *        set to TRUE.
     *
     * @return
     *         Exception occurred while performing persist dynamic member operation. The errors
     *         are returned in <code>ServiceData</code>. There are no plain/updated/created objects
     *         returned in <code>ServiceData</code>.
     *         <br>
     *         If user does not have the required access privileges for performing operation it
     *         will return error.
     *
     *
     * @exception ServiceException
     *           Following are possible errors returned in ServiceData from partitions module
     *           while performing this operation.
     *           <br>
     *           <ul>
     *           <li type="disc">280001&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Partition internal
     *           error.
     *           </li>
     *           <li type="disc">280009&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Access privilege
     *           error.
     *           </li>
     *           </ul>
     *           <br>
     *           It may also contain error related to object delete and object creation errors.
     */
    virtual Teamcenter::Soa::Client::ServiceData persistDynamicMembers ( const std::vector< Ptn0::Services::Partition::_2011_06::Partitionmanagement::PersistDynamicMembersInputInfo >& inputs ) = 0;

    /**
     * This operation updates the given input Partition with the supplied input Partition<b>s</b>
     * list. Partitions can be added as children or parents for a given input Partition.
     * <br>
     * User performing this operation need update privileges ( ADD_CONTENT/ REMOVE_CONTENT
     * ) on Partitions or Model.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Update Parents/Children to Partitions</b>
     * <br>
     * To organize the design elements, user may want to partition these design elements.
     * In doing so, the Partitions can also be arranged in a hierarchies. This could be
     * done by adding children to a given partition or parent Partitions can be added for
     * an existing partition. User can also modify an existing Partition breakdown by removing/
     * replacing existing child or parent partitions.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Partition Management - Defines Partition Management operation (add/modify/remove
     * members and child partitions),Partition Template creation and management and cloning
     * functionality and extends the search services in the AppModel component.
     *
     * @param inputs
     *        Object of UpdateChildrenOrParentsInputInfo structure.
     *
     * @return
     *         The exception occurred during the operation are returned in ServiceData
     *
     *
     * @exception ServiceException
     *           Following errors specific to Partition are returned.
     *           <br>
     *           <br>
     *           <ul>
     *           <li type="disc">280009(Error)&nbsp;&nbsp;&nbsp;&nbsp;Access related error, user doesnot
     *           have required privileges to perform update child/parent operation.
     *           </li>
     *           <li type="disc">280001(Error)&nbsp;&nbsp;&nbsp;&nbsp;Partition interal error occurred.
     *           This error is occurred if valid Business Object constants are not deployed or removed.
     *           </li>
     *           <li type="disc">280002(Error)&nbsp;&nbsp;&nbsp;&nbsp;Invalid child or parent ( which
     *           is not a subtype of Partition)  when member is not of the expected business object
     *           type.
     *           </li>
     *           <li type="disc">280003(Error)&nbsp;&nbsp;&nbsp;&nbsp;Invalid allowed types of child
     *           or parent Partitions being added in a Partition Scheme.
     *           </li>
     *           <li type="disc">280013(Error)&nbsp;&nbsp;&nbsp;&nbsp;If child patitions being added
     *           are already children ( duplicate children)
     *           </li>
     *           <li type="disc">280014(Error)&nbsp;&nbsp;&nbsp;&nbsp;If parent Partitions being added
     *           are already parents( duplicate parents )
     *           </li>
     *           </ul>
     */
    virtual Teamcenter::Soa::Client::ServiceData updateChildrenOrParents ( const std::vector< Ptn0::Services::Partition::_2011_06::Partitionmanagement::UpdateChildrenOrParentsInputInfo >& inputs ) = 0;

    /**
     * This operation updates the given input Partition with the Members supplied in a members
     * list. Members can be added/removed/replaced for a given  Partition.
     * <br>
     * User performing this operation needs privileges on partition or members as ADD/REMOVE_CONTENT
     * or WRITE respectively, depending upon ownership of Membership object. If user does
     * not have required privileges or any of the validation fails it returns error in <code>serviceData</code>
     * along with failed members and error code for each failed member in <code>UpdateMemberRespose</code>
     * structure.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Use Case 1: <b>Add members to Partition</b>
     * <br>
     * <br>
     * User<b> </b>can<b> </b>add members to the partition as follows.
     * <br>
     * 1.&nbsp;&nbsp;&nbsp;&nbsp;Creates the Collaborative Design in a given application
     * model.
     * <br>
     * 2.&nbsp;&nbsp;&nbsp;&nbsp;Creates Partition Scheme under the collaborative design
     * created in step1.
     * <br>
     * 3.&nbsp;&nbsp;&nbsp;&nbsp;Creates Partition under Partition Scheme created in step2.
     * <br>
     * 4.&nbsp;&nbsp;&nbsp;&nbsp;Creates Design elements directly under Partition created
     * in step3.
     * <br>
     * 5.&nbsp;&nbsp;&nbsp;&nbsp;User can also configure the revision rule while performing
     * this operation and this rule will be passed to the SOA.
     * <br>
     * <br>
     * Operation code <i>ADD</i> will be used for this use case, user can define the way
     * memberships will be created in data base by selecting proper predefined value in
     * <code>contentPersistenceMode</code> parameter. That is <i>STATIC / DYNAMIC /AUTO
     * /ALL_MODE</i>.
     * <br>
     * <br>
     * Use Case 2: <b>Replace members of the input partition list</b>
     * <br>
     * Members of the existing Partition can be replaced with the new set of input members
     * list as follows.
     * <br>
     * 1.&nbsp;&nbsp;&nbsp;&nbsp;User has Partition and Design elements under it as created
     * in use case 1.
     * <br>
     * 2.&nbsp;&nbsp;&nbsp;&nbsp;Now Design element under the Partition need to be replaced
     * with different Design elements.
     * <br>
     * 3.&nbsp;&nbsp;&nbsp;&nbsp;User selects set of new design elements and paste it under
     * the existing partition.
     * <br>
     * 4.&nbsp;&nbsp;&nbsp;&nbsp;This operation will remove all the existing design elements
     * from the partition and replace with new design elements.
     * <br>
     * 5.&nbsp;&nbsp;&nbsp;&nbsp;User can also configure the revision rule and pass it to
     * this SOA.
     * <br>
     * Operation code <i>REPLACE</i> will be used for this use case, user can define the
     * way new membership objects will be created in database using <code>contentPersistenceMode</code>
     * parameter. That is user can select any of the modes from <i>STATIC/ DYNAMIC/ AUTO/
     * ALL_MODE</i>.
     * <br>
     * <br>
     * Use Case 3: <b>Remove members of the input partition list</b>
     * <br>
     * Members of the existing Partition can be removed with the set of input members list.
     * <br>
     * 1.&nbsp;&nbsp;&nbsp;&nbsp;User has created Partition with few design elements under
     * it same as use case1.
     * <br>
     * 2.&nbsp;&nbsp;&nbsp;&nbsp;Design elements are selected and deleted.
     * <br>
     * 3.&nbsp;&nbsp;&nbsp;&nbsp;This operation will remove the links between Partition
     * and Design elements by deleting  membership object or recipe.
     * <br>
     * Operation code <i>REMOVE</i> will be used in this use case.
     * <br>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createObjects
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Partition Management - Defines Partition Management operation (add/modify/remove
     * members and child partitions),Partition Template creation and management and cloning
     * functionality and extends the search services in the AppModel component.
     *
     * @param inputs
     *        Vector of <code>UpdateMembersInputInfo</code> containing following details to carry
     *        out operation
     *        <br>
     *        <ul>
     *        <li type="disc"><code>inputPartition</code>
     *        </li>
     *        <li type="disc"><code>membersList</code>
     *        </li>
     *        <li type="disc"><code>opCode</code>
     *        </li>
     *        <li type="disc"><code>contentPersistenceMode</code>
     *        </li>
     *        <li type="disc"><code>configurationContext</code>
     *        </li>
     *        </ul>
     *
     * @return
     *         The exception occurred during the operation are returned in <code>ServiceData</code>.It
     *         also returns failed member and corresponding error related to that failed member.
     *
     *
     * @exception ServiceException
     *           Following error specific to partition are returned.
     *           <br>
     *           <ul>
     *           <li type="disc">280009(Error)&nbsp;&nbsp;&nbsp;&nbsp; Access related error, user
     *           doesnot have required privileges to perform update member operation.
     *           </li>
     *           <li type="disc">280001(Error)&nbsp;&nbsp;&nbsp;&nbsp; Partition interal error occurred.
     *           </li>
     *           <li type="disc">280002(Error)&nbsp;&nbsp;&nbsp;&nbsp; Invalid member, member is not
     *           of the expected business object type.
     *           </li>
     *           </ul>
     */
    virtual Ptn0::Services::Partition::_2011_06::Partitionmanagement::UpdateMembersResponse updateMembers ( const std::vector< Ptn0::Services::Partition::_2011_06::Partitionmanagement::UpdateMembersInputInfo >& inputs ) = 0;

    /**
     * This operation is used to find the Partitions related to the given input Partitionable<b>.</b>
     * Operation performs a search on Membership object to find if any Partitions are attached
     * to input partitionable.It also requires  Application model object and Partition Scheme
     * object to limit the search scope within specified Application model and partition
     * scheme.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Find<b> </b>partition for a member in given application model and partition scheme<b>.</b>
     * <br>
     * <ul>
     * <li type="disc">User creates Partition scheme as SchemeA and ModelA as application
     * model.
     * </li>
     * <li type="disc">Partition1 is created under SchemeA and ModelA.
     * </li>
     * <li type="disc">User has a Design element Member1 as a partitionable under Partition1(it
     * creates   membership object)
     * </li>
     * </ul>
     * <br>
     * Execute wherePartitioned SOA with following details for above use case.
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;  WherePartitionedInputInfo.configurationContext = Revision
     * rule.
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;  WherePartitionedInputInfo.modelContext = ModelA.
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;  WherePartitionedInputInfo.partitionScheme = SchemeA.
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;  WherePartitionedInputInfo.partitionable = Member1.
     * <br>
     * <br>
     * After executing SOA with above details output will contain Partition1 and Member1
     * partitionable object.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createObjects
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Partition Management - Defines Partition Management operation (add/modify/remove
     * members and child partitions),Partition Template creation and management and cloning
     * functionality and extends the search services in the AppModel component.
     *
     * @param inputs
     *        Vector of a structure <code>WherePartitionedInputInfo</code> containing input application
     *        model, partition scheme, partition, revision rule and partitionable object.
     *
     * @return
     *         <ul>
     *         <li type="disc">Exception occurred while performing <code>wherePartition</code> SOA
     *         are returned in service data.
     *         </li>
     *         <li type="disc">Plain object of <code>ServiceData</code> is populated with the result
     *         object thats partition objects.
     *         </li>
     *         <li type="disc">There are no errors returned specifically from partitions module.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           The operation may return one of the following errors in serviceData
     *           <br>
     *           280005 wrong input supplied.
     */
    virtual Ptn0::Services::Partition::_2011_06::Partitionmanagement::WherePartitionedResponse wherePartitioned ( const std::vector< Ptn0::Services::Partition::_2011_06::Partitionmanagement::WherePartitionedInputInfo >& inputs ) = 0;

    /**
     * This operation clones partition breakdowns (<b>Ptn0Partition</b>) from a source Application
     * Model (<b>Mdl0ApplicationModel</b>) to a target Application Model. Source Application
     * Model may be a Partition Template (<b>Ptn0PartitionTemplateModel</b>) or Collaborative
     * Design (<b>Cpd0CollaborativeDesign</b>). This operation can optionally carry forward
     * variant expressions (<b>Fnd0VariantExpression</b>), effectivity expressions (<b>Fnd0EffectivityExpression</b>)
     * and attribute groups (<b>Mdl0AttributeGroup</b>) from source partitions to target
     * partitions.
     * <br>
     * <br>
     * Partition breakdowns from a source Application Model can be used as a template to
     * create similar partition breakdowns in target Application Model. After cloning the
     * user could re-orient or modify partition breakdown in the target Application Model.
     * Cloned partitions do not maintain any references to source partitions in source Application
     * Model.
     * <br>
     * <br>
     * When partition breakdowns are cloned in to an existing scheme in target model, and
     * if there are already Partitions present in this scheme with the same Multi Field
     * Key attributes then there will be a MFK uniqueness violation error reported for that
     * duplicate Partitions, but this error is presented to the user only after saving of
     * all non-duplicate Partitions.
     * <br>
     * <br>
     * Note: <code>createOrUpdateRealizedPartitions</code> operation should be used if one
     * wants to strictly maintain the child parent hierarchy of partitions in target Application
     * Model.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Partition breakdowns from an Application Model can be used to create similar Partition
     * schemes (<b>Ptn0PartitionScheme</b>) and partition breakdowns in other Application
     * Model. This can be done by cloning partitions from selected Partition schemes of
     * different Application Models or cloning the entire partition breakdown of the given
     * source Application Model. The user may also optionally carry over the variant expressions,
     * effectivity expressions and attribute groups optionally from source Application Model
     * to target Application Model. Since the cloned partition breakdowns in target Application
     * Model do not have any reference to source Application Model, it can be modified after
     * cloning.
     * <br>
     * <br>
     * Variant Expressions are carried forward only when dictionary of options and values
     * required for the Variant Expression are available for the target Partition otherwise
     * an error message will be thrown.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Partition Management - Defines Partition Management operation (add/modify/remove
     * members and child partitions),Partition Template creation and management and cloning
     * functionality and extends the search services in the AppModel component.
     *
     * @param inputs
     *        List of target Application Model, clone input options and source Application Model
     *        or source Partition schemes.
     *
     * @return
     *         List of partitions failed to clone, Partition schemes of the failed partitions, source
     *         Application Model of the failed partitions and the corresponding failure detail will
     *         be returned. Partial errors are returned in ServiceData
     *
     *
     * @exception ServiceException
     *           Following are possible errors returned in ServiceData while performing this operation.
     *           <br>
     *           <ul>
     *           <li type="disc">280011:&nbsp;&nbsp;&nbsp;&nbsp;A Partition of given Scheme type already
     *           exists with the given Partition ID in the current model. This could occur when trying
     *           to create a duplicate Partition in the same Partition.
     *           </li>
     *           <li type="disc">280006:&nbsp;&nbsp;&nbsp;&nbsp;A Partition of given type cannot be
     *           created within a Scheme of given type. This could occur when trying to create an
     *           un-allowed Partition type under a Partition scheme.
     *           </li>
     *           </ul>
     */
    virtual Ptn0::Services::Partition::_2013_05::Partitionmanagement::ClonePartitionsResponse clonePartitions ( const std::vector< Ptn0::Services::Partition::_2013_05::Partitionmanagement::ClonePartitionsInputInfo >& inputs ) = 0;

    /**
     * This operation realizes partition breakdowns (<b>Ptn0Partition</b>) from Partition
     * Template (<b>Ptn0PartitionTemplateModel</b>) to a target Application Model (<b>Mdl0ApplicationModel</b>)
     * and updates partition breakdowns from source Partition Templates. This operation
     * can optionally carry forward variant expressions (<b>Fnd0VariantExpression</b>),
     * effectivity expressions (<b>Fnd0EffectivityExpression</b>), attribute groups (<b>Mdl0AttributeGroup</b>)
     * and child Partitions from source Application Model to target Application Model. Realized
     * partitions in the target Application Model can be updated to reflect the changes
     * from source partitions.
     * <br>
     * <br>
     * Instantiated or realized partition breakdowns maintains reference to source partitions
     * in Partition Template. User can add a new partition to realized partition structure
     * in target application model. However, deleting an instantiated partition after realization
     * is allowed in target application model. Realization of a Partition maintains a strict
     * child parent hierarchy and will be same as that of its source Partition parent hierarchy.
     * During update of realized partitions Child-parent links are automatically established
     * in target application model wherever possible. Duplicate partitions will not be created
     * during update of realized partitions. But the partitions are updated with Variant
     * conditions and other related objects (based on Deep copy rules) from the source Partition
     * Template to the target application model.
     * <br>
     * <br>
     * Note: <code>clonePartitions</code> operation should be used if one wants to modify
     * the child parent hierarchy of partitions in target Application Model.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <br>
     * Use Case1:
     * <br>
     * Partition Templates can be used as blue print which can be reused to create partition
     * breakdowns in other Application Models (Collaborative Design (<b>Cpd0CollaborativeDesign</b>)
     * or Partition Template (<b>Ptn0PartitionTemplateModel</b>)). This enables users to
     * reuse Partition Templates and create similar Partition schemes (<b>Ptn0PartitionScheme</b>)
     * and partition breakdowns in other Application Models.  This can be done by copy/pasting
     * or drag/drop of Partitions from Partition Template to another Application Model in
     * RAC. The user may also want to optionally carry over the child Partitions, variant
     * expressions, and effectivity expressions and attribute groups.
     * <br>
     * <br>
     * Variant Expressions are carried forward only when dictionary of options and values
     * required for the Variant Expression are available for the target Partition otherwise
     * an error message will be thrown.
     * <br>
     * <br>
     * Use case2:
     * <br>
     * Once Partitions are realized from a Partition Template to other Application Model,
     * Partitions in source Partition Template may undergo changes and user may want to
     * bring these updates from Partition Template in to the target model.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Partition Management - Defines Partition Management operation (add/modify/remove
     * members and child partitions),Partition Template creation and management and cloning
     * functionality and extends the search services in the AppModel component.
     *
     * @param inputs
     *        List containing target Application Model, instantiation input options, Revision Rule,
     *        Variant Rule and source Application Model or source Partition schemes or source Partitions.
     *
     * @return
     *         Partial errors are returned in ServiceData when the operation failed to update given
     *         partitions.
     *
     *
     * @exception ServiceException
     *           Following are possible errors returned in ServiceData while performing this operation.
     *           <br>
     *           <br>
     *           <ul>
     *           <li type="disc">280011:&nbsp;&nbsp;&nbsp;&nbsp;A Partition of given Partition scheme
     *           type already exists with the given Partition ID in the current model. This error
     *           could occur when trying to create a duplicate Partition under the same Partition
     *           scheme.
     *           </li>
     *           <li type="disc">280006:&nbsp;&nbsp;&nbsp;&nbsp;A Partition of given type cannot be
     *           created within a Partition scheme of given type. This could occur when trying to
     *           create an un-allowed Partition type under a Partition scheme.
     *           </li>
     *           </ul>
     */
    virtual Teamcenter::Soa::Client::ServiceData createOrUpdateRealizedPartitions ( const std::vector< Ptn0::Services::Partition::_2013_05::Partitionmanagement::CreateOrUpdateRealizedPartitionsInputInfo >& inputs ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("PartitionmanagementService")

};
        }
    }
}


#pragma warning ( pop )

#include <ptn0/services/partition/Partition_undef.h>
#endif

