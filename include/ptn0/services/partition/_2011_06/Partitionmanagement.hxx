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

#ifndef PTN0_SERVICES_PARTITION__2011_06_PARTITIONMANAGEMENT_HXX
#define PTN0_SERVICES_PARTITION__2011_06_PARTITIONMANAGEMENT_HXX

#include <teamcenter/soa/client/model/ConfigurationContext.hxx>
#include <teamcenter/soa/client/model/Mdl0ApplicationModel.hxx>
#include <teamcenter/soa/client/model/POM_object.hxx>
#include <teamcenter/soa/client/model/Ptn0Partition.hxx>
#include <teamcenter/soa/client/model/Ptn0PartitionScheme.hxx>
#include <teamcenter/soa/client/model/WorkspaceObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <ptn0/services/partition/Partition_exports.h>

namespace Ptn0
{
    namespace Services
    {
        namespace Partition
        {
            namespace _2011_06
            {
                class Partitionmanagement;

class PTN0SOAPARTITIONSTRONGMNGD_API Partitionmanagement
{
public:

    struct ErrorValuesStruct;
    struct FailedMemberErrorStruct;
    struct GetChildrenInputInfo;
    struct GetChildrenOutputInfo;
    struct GetChildrenResponse;
    struct GetMembersInputInfo;
    struct GetMembersOutputInfo;
    struct GetMembersResponse;
    struct GetParentsInputInfo;
    struct GetParentsOutputInfo;
    struct GetParentsResponse;
    struct GetPartitionsInputInfo;
    struct GetPartitionsOutputInfo;
    struct GetPartitionsResponse;
    struct GetSchemesInModelOutputInfo;
    struct GetSchemesInModelResponse;
    struct GetTopLevelPartitionsInputInfo;
    struct GetTopLevelPartitionsOutputInfo;
    struct GetTopLevelPartitionsResponse;
    struct PersistDynamicMembersInputInfo;
    struct UpdateChildrenOrParentsInputInfo;
    struct UpdateMembersInputInfo;
    struct UpdateMembersOutputInfo;
    struct UpdateMembersResponse;
    struct WherePartitionedInputInfo;
    struct WherePartitionedOutputInfo;
    struct WherePartitionedResponse;

    /**
     * Static, Dynamic, Auto or All mode.
     */
    enum ContentPersistenceMode{ STATIC_MODE,
                 DYNAMIC_MODE,
                 AUTO_MODE,
                 ALL_MODE
                 };

    /**
     * Contains the severity of the error corresponding to failed member.
     */
    enum ErrorSeverity{ Error_severity_information,
                 Error_severity_warning,
                 Error_severity_error
                 };

    /**
     * Add, Replace and Remove opcode.
     */
    enum OpCode{ ADD,
                 REPLACE,
                 REMOVE
                 };

    /**
     * Contains the mapping between parent and child partitions.
     */
    typedef std::map< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Ptn0Partition> , std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Ptn0Partition>  > > ChildParentPartitionMap;

    /**
     * ErrorValuesStruct structure contains the error details which occurred while updating
     * member.
     * <br>
     * For each failed member this structure is populated with details such as error code,
     * error message and error level.
     */
    struct ErrorValuesStruct
    {
        /**
         * integer value representing error code.
         */
        int code;
        /**
         * string representing error message.
         */
        std::string message;
        /**
         * level represents the error crititicality.
         */
        ErrorSeverity level;
    };

    /**
     * FailedMemberErrorStruct structure contains the member and errorVal structure which
     * stores all the information about failed member.
     */
    struct FailedMemberErrorStruct
    {
        /**
         * Member failed to update.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  member;
        /**
         * Stores all the data about error which occurred while updating member.
         */
        Ptn0::Services::Partition::_2011_06::Partitionmanagement::ErrorValuesStruct errorVal;
    };

    /**
     * <code>GetChildrenInputInfo</code> structure represents the details of <b>ConfigurationContext</b>
     * , Parent Partition for which child Partitions are to be fetched.  It also represents
     * the desired maximum level count and maximum child Partitions that have to be fetched.
     */
    struct GetChildrenInputInfo
    {
        /**
         * Configuration Context object which configures the output child Partitions with the
         * effectivity condition or revision rule attached to it.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ConfigurationContext>  configurationContext;
        /**
         * parent Partition object  for which the children Partitions are to be fetched.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Ptn0Partition>  parentPartition;
        /**
         * Integer specifying the number of levels of child Partitions that have to be fetched.
         * When this count is set to 0, you will get all levels of child Partitions in that
         * Partition Breakdown for a given Parent Partition.
         */
        int maxLevelCount;
        /**
         * Integer specifying the number of  child Partitions that have to be fetched. When
         * this count is set to 0, you will get all child Partitions in that Partition Breakdown
         * for a given parent Partition.
         */
        int maxChildCount;
    };

    /**
     * <code>GetChildrenOutputInfo</code> structure represents the map of the Parent Partition
     * and vector of its child Partitions, number of Partition level s traversed in the
     * operation and also a Boolean indicating if children list is truncated as per the
     * input <code>maxChildCount</code>.
     */
    struct GetChildrenOutputInfo
    {
        /**
         * Map of Parent Partition and list of its child Partitions. Parent Partition is the
         * key in the map and vector of Partitions is its value.
         */
        ChildParentPartitionMap parentChildMap;
        /**
         * Number of Partition levels that are traversed while executing this operation. This
         * value depends up on the maximum level count that is supplied as input parameter.
         */
        int expandedLevelCount;
        /**
         * Boolean flag which indicates that the child Partition list is truncated or not. This
         * value depends up on the input maximum child count that is supplied as input parameter.
         */
        bool childPartitionListTruncated;
    };

    /**
     * <code>GetChildrenResponse</code> structure represents vector of <code>GetChildrenOutputInfo</code>
     * consisting the child Partitions, their corresponding parent Partition ( i.e., a Map
     * of Parent Partition and list of its Child  Partitions ) , number of Partition levels
     * traversed in the breakdown, total number of child Partitions found in the operation
     * and also the errors via <code>serviceData</code> if invalid input parameters are
     * supplied.
     */
    struct GetChildrenResponse
    {
        /**
         * Vector of <code>GetChildrenOutputInfo</code> structures for corresponding vector
         * of input <code>GetChildrenInputInfo</code> structure.
         */
        std::vector< Ptn0::Services::Partition::_2011_06::Partitionmanagement::GetChildrenOutputInfo > output;
        /**
         * consists the errors returned if any.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * <code>GetMembersInputInfo</code> structure represents the details of <b>ConfigurationContext</b>,
     * Partition for which members are to be fetched.  It also represents content persistence
     * mode and a Boolean flag to indicate to load the CAD data or not.
     */
    struct GetMembersInputInfo
    {
        /**
         * <b>ConfigurationContext</b> object which configures the output members with the effectivity
         * condition or revision rule attached to it.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ConfigurationContext>  configurationContext;
        /**
         * Partition object  for which the members are to be fetched.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Ptn0Partition>  partition;
        /**
         * Enumerator indicating the content persistence mode.This parameter can be any one
         * of the four following values which can be passed to this enumerator depending on
         * the use case.
         * <br>
         * <br>
         * <ul>
         * <li type="disc"><code>STATIC_MODE </code>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This
         * mode can be used when only static members are required.
         * </li>
         * <li type="disc"><code>DYNAMIC_MODE</code><i> </i>&nbsp;&nbsp;&nbsp;&nbsp;This mode
         * can be used when only dynamic members are required.
         * </li>
         * <li type="disc"><code>ALL_MODE </code>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This
         * mode can be used when both static and dynamic members are required.
         * </li>
         * <li type="disc"><code>AUTO_MODE&nbsp;&nbsp;&nbsp;&nbsp;</code>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This
         * mode can be used when members are fetched depending on&nbsp;&nbsp;&nbsp;&nbsp;the
         * default persistence mode of the Partition&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
         * </li>
         * </ul>
         */
        ContentPersistenceMode contentPersistenceMode;
        /**
         * Boolean flag indicating, whether the graphic data such as JT data has to be loaded
         * when members are fetched.
         */
        bool isGraphicDataToBeLoaded;
    };

    /**
     * <code>GetMembersOutputInfo</code> structure represents the input Partitions and vector
     * of its members.
     */
    struct GetMembersOutputInfo
    {
        /**
         * Input Partition object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Ptn0Partition>  inputPartition;
        /**
         * Vector of member objects of the input Partition.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::POM_object>  > membersList;
    };

    /**
     * <code>GetMembersResponse</code> structure represents vector of <code>GetMembersOutputInfo</code>
     * consisting the child Partitions, their corresponding parent Partition ( i.e., a Map
     * of parent Partition and list of its child  Partitions ) , number of Partition levels
     * traversed in the breakdown, total number of child Partitions found in the operation
     * and also the errors via <code>serviceData</code> if invalid input parameters are
     * supplied.
     */
    struct GetMembersResponse
    {
        /**
         * Vector of <code>GetMembersOutputInfo</code> structures for corresponding vector of
         * input <code>GetMembersInputInfo</code> structure.
         */
        std::vector< Ptn0::Services::Partition::_2011_06::Partitionmanagement::GetMembersOutputInfo > output;
        /**
         * consists the errors returned if any.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * <code>GetParentsInputInfo</code> structure represents the details of <b>ConfigurationContext</b>,
     * child Partition for which parent Partitions are to be fetched.  It also represents
     * the desired maximum level count and maximum parent Partitions that have to be fetched.
     */
    struct GetParentsInputInfo
    {
        /**
         * Configuration Context object which configures the output  parent <b>Partitions</b>
         * with the effectivity condition or revision rule attached to it.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ConfigurationContext>  configurationContext;
        /**
         * child Partition object  for which the parent Partitions are to be fetched.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Ptn0Partition>  childPartition;
        /**
         * Integer specifying the number of levels of parent Partitions that have to be fetched.
         * When this count is set to 0, you will get all levels of parent Partitions in that
         * Partition Breakdown for a given child Partition.
         */
        int maxLevelCount;
        /**
         * Integer specifying the number of  parent Partitions that have to be fetched. When
         * this count is set to 0, you will get all parent Partitions in that Partition Breakdown
         * for a given child Partition.
         */
        int maxParentCount;
    };

    /**
     * <code>GetParentsOutputInfo</code> structure represents the map of the child Partition
     * and vector of its parent Partitions, number of parent Partition levels traversed
     * in the operation and also a Boolean indicating if parent list is truncated as per
     * the input <code>maxParentCount</code>.
     */
    struct GetParentsOutputInfo
    {
        /**
         * Map of child Partition and vector of its parent Partitions. Child Partition is the
         * key in the map and vector of parent Partitions is its value.
         */
        ChildParentPartitionMap childParentMap;
        /**
         * Number of parent Partition levels that are traversed while executing this operation.
         * This value depends up on the maximum level count that is supplied as input parameter.
         */
        int expandedLevelCount;
        /**
         * Boolean flag which indicates that the parent Partition list is truncated or not.
         * This value depends up on the input maximum parent count that is supplied as input
         * parameter.
         */
        bool parentPartitionListTruncated;
    };

    /**
     * <code>GetParentsResponse</code> structure represents vector of <code>GetParentsOutputInfo</code>
     * consisting the parent Partitions, their corresponding child Partition ( i.e., a Map
     * of child Partition and vector of its parent  Partitions ), number of parent Partition
     * levels traversed in the breakdown, total number of parent Partitions found in the
     * operation and also the errors via <code>serviceData</code> if invalid input parameters
     * are supplied.
     */
    struct GetParentsResponse
    {
        /**
         * Vector of <code>GetParentsOutputInfo</code> structures for corresponding vector of
         * input <code>GetParentsInputInfo</code> structure.
         */
        std::vector< Ptn0::Services::Partition::_2011_06::Partitionmanagement::GetParentsOutputInfo > output;
        /**
         * consists the errors returned if any.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * <code>GetPartitionsInputInfo</code> structure is input to the <code>getPartitions</code>
     * SOA.It contains the details of <code>configuration context, Application Model, Partition
     * Scheme</code> and <code>maxPartitionCount</code>.
     * <br>
     */
    struct GetPartitionsInputInfo
    {
        /**
         * The<b> RevisionRule</b> as per the users requirement which will be used for configuring
         * output.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ConfigurationContext>  configurationContext;
        /**
         * Application Model object for which partitions to be searched.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Mdl0ApplicationModel>  modelCntxt;
        /**
         * Partition Scheme object  as another search limit for partitions.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Ptn0PartitionScheme>  partitionScheme;
        /**
         * Its a integer variable used to truncate the output list of <b>Partition</b>.
         */
        int maxPartitionCount;
    };

    /**
     * <code>GetPartitionsOutputInfo</code> Structure contains details of output result
     * also partition scheme to which this output belongs to, and the Boolean to reflect
     * the value if output list was truncated due to <code>maxPartitionCount</code>.
     */
    struct GetPartitionsOutputInfo
    {
        /**
         * Input<b> </b>Partition<b> </b>Scheme for which SOA was operated
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Ptn0PartitionScheme>  paritionScheme;
        /**
         * List of partitions result of the SOA operation
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Ptn0Partition>  > partitions;
        /**
         * Variable set to true if output list of partition was truncated because of <code>maxPartitionCount</code>
         * setting, otherwise its set to false.
         */
        bool isListTruncated;
    };

    /**
     * <code>GetPartitionsResponse</code> contains result of the soa operation and exception
     * data.
     */
    struct GetPartitionsResponse
    {
        /**
         * Vector of <code>GetpartitionsOutputInfo</code> structure which contains the actual
         * result of the SOA operation that is list of partitions for given<b> </b>Application
         * Model<b> </b>and<b> </b>Partition Scheme.
         */
        std::vector< Ptn0::Services::Partition::_2011_06::Partitionmanagement::GetPartitionsOutputInfo > output;
        /**
         * Any  exception occurred while performing SOA is returned in service data also the
         * list of output partitions are added to plain object list of service data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * <code>GetSchemesInModelOutputInfo</code>  structure contains the list of partition
     * schemes which are output of SOA operation and input application model to which schemes
     * belongs.
     */
    struct GetSchemesInModelOutputInfo
    {
        /**
         * Application Model object which was input to the SOA operation.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Mdl0ApplicationModel>  model;
        /**
         * List of<b> </b>Partition<b> </b>schemes result of the SOA operation.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Ptn0PartitionScheme>  > partitionSchemes;
    };

    /**
     * Output contains list of Partition Scheme and Application Model. Service data is populated
     * with any exception occurred while performing operation and partition scheme objects.
     */
    struct GetSchemesInModelResponse
    {
        /**
         * This is vector of  <code>GetSchemesInModelOutputInfo</code> structure which contains
         * the<b> </b>Partition scheme<b> </b>list and Application model<b>.</b>
         */
        std::vector< Ptn0::Services::Partition::_2011_06::Partitionmanagement::GetSchemesInModelOutputInfo > output;
        /**
         * Contains exception occurred while performing operation. Plain object list is populated
         * with the resulted partition scheme object.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * <code>GetTopLevelPartitionsInputInfo</code> structure represents the details of Application
     * model Context ,  Partition scheme  and Configuration context, for which top level
     * Partitions are to be fetched.
     */
    struct GetTopLevelPartitionsInputInfo
    {
        /**
         * Configuration Context object which configures the output top level <b>Partitions</b>
         * with the effectivity condition or revision rule attached to it.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ConfigurationContext>  configurationContext;
        /**
         * Application Model object for which the top level Partitions are to be fetched.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Mdl0ApplicationModel>  modelCntxt;
        /**
         * Partition Scheme object for which the top level Partitions are to be fetched.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Ptn0PartitionScheme>  partitionScheme;
    };

    /**
     * <code>GetTopLevelPartitionsOutputInfo</code> structure represents the list of top
     * level Partitions returned corresponding to a input Partition Scheme supplied.
     */
    struct GetTopLevelPartitionsOutputInfo
    {
        /**
         * Input  Partition Scheme to which this structures output partitions belong to.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Ptn0PartitionScheme>  paritionScheme;
        /**
         * Configured top level Partitions as per the Configuration Context and supplied input
         * Partition Scheme and Application Model.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Ptn0Partition>  > topLevelPartitions;
    };

    /**
     * <code>GetTopLevelPartitionsResponse</code> structure represents the list of <code>GetTopLevelPartitionsOutputInfo</code>
     * consisting of the top level Partitions, their corresponding scheme structure and
     * also the errors via serviceData if invalid input parameters are supplied.
     */
    struct GetTopLevelPartitionsResponse
    {
        /**
         * List of <code>GetTopLevelPartitionsOutputInfo</code> structures for corresponding
         * list of input <code>GetTopLevelPartitionsInputInfo</code> structures.
         */
        std::vector< Ptn0::Services::Partition::_2011_06::Partitionmanagement::GetTopLevelPartitionsOutputInfo > output;
        /**
         * consists of the errors returned if any.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * <code>PersistDynamicMembersInputInfo</code> structure is input parameter for the
     * SOA. This structure provides partition for which members should be persisted, structure
     * also contains the configuration context representing revision rule.
     */
    struct PersistDynamicMembersInputInfo
    {
        /**
         * Revision rule or user defined rule. Passing <code>NULLTAG</code> in this parameter
         * is not allowed.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ConfigurationContext>  configurationContext;
        /**
         * Partition to persist Members.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Ptn0Partition>  partition;
    };

    /**
     * <code>UpdateChildrenOrParentsInputInfo</code> structure consists the input of Partition
     * to be updated,  Partitions to be updated as children or parents, enumerator to indicate
     * what kind of update is to be performed and a Boolean flag to indicate whether adding
     * children or parents to given input Partition.
     */
    struct UpdateChildrenOrParentsInputInfo
    {
        /**
         * Input Partition business object, to which the members wil be updated.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Ptn0Partition>  partition;
        /**
         * List of Partitions to  be updated for input  Partition based on the opCodevalue.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Ptn0Partition>  > partitionList;
        /**
         * Its a enum variable which will be taking <i>ADD</i>, <i>REMOVE</i> and <i>REPLACE</i>
         * as values.As per the value of this parmeter, input partitions  list is added/ removed/
         * replaced as children/ parens to the input Partition.
         */
        OpCode opCode;
        /**
         * Boolean flag to indicate whether the input Partition being updated is a parent partition
         * or child Partition.
         */
        bool isParent;
    };

    /**
     * <code>UpdateMembersInputInfo</code> structure hold the information required to carry
     * out SOA operation.
     * <br>
     * Vector of this structure is passed as input to SOA operation to do the bulk operation
     * for more than one Partition
     * <br>
     */
    struct UpdateMembersInputInfo
    {
        /**
         * Holds the Partition business object. updateMember SOA will operate on this input
         * based on the operation code and partition business object is updated accordingly.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Ptn0Partition>  inputPartition;
        /**
         * List of members to add, remove or replace membership object for a partition based
         * on the opCodevalue.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::POM_object>  > membersList;
        /**
         * Its a enum variable which will be taking <i>ADD</i>, <i>REMOVE</i> and <i>REPLACE</i>
         * as values.As per the value of this parmeter inputPartition is updated with members.
         */
        OpCode opCode;
        /**
         * Its Enum variable which has following allowed values.
         * <br>
         * <ul>
         * <li type="disc"><code>STATIC_MODE</code>:  Updates Partition by creating memberships
         * in database for input members.
         * </li>
         * <li type="disc"><code>DYNAMIC_MODE: </code>Updates Partition Recipe to include the
         * input members
         * </li>
         * <li type="disc"><code>AUTO_MODE : </code>Selectes default mode set by user from remaining
         * three modes.
         * </li>
         * <li type="disc"><code>ALL_MODE: </code>Updates Partition by creating static memberships
         * in databse for input members and updates recipe on partion.
         * </li>
         * </ul>
         */
        ContentPersistenceMode contentPersistenceMode;
        /**
         * Configuration context value by user, this is the business object representing user
         * defined revision rule. If user pass the <i>NULLTAG</i>  it will load a default revision
         * rule from database and proceed.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ConfigurationContext>  configurationContext;
    };

    /**
     * This structure holds update member failed with failed members and error details.
     */
    struct UpdateMembersOutputInfo
    {
        /**
         * Structure containing information related to failed member and corresponding error
         * occurred while performing update member operation.
         */
        std::vector< Ptn0::Services::Partition::_2011_06::Partitionmanagement::FailedMemberErrorStruct > memberErrorVector;
        /**
         * Input partition of which update member operation failed.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Ptn0Partition>  inputPartition;
    };

    /**
     * UpdateMembersResponse structure contains ServiceData for storing the exception occurred
     * while performing update member operation and UpdateMembersOutputInfo structure.
     */
    struct UpdateMembersResponse
    {
        /**
         * Service data for update member operation it stores the error/ exception if it occurres
         * while performing operation. There are no plain object, created object or deleted
         * objects returned in servicedata.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * It returns failed members and errors corresponding to it..
         */
        std::vector< Ptn0::Services::Partition::_2011_06::Partitionmanagement::UpdateMembersOutputInfo > output;
    };

    /**
     * <code>WherePartitionedInputInfo</code> is input parameter to <code>wherePartitioned</code>
     * SOA.
     */
    struct WherePartitionedInputInfo
    {
        /**
         * <b>RevisionRule</b> business object or any user defined rule to configure the output
         * as per the rule.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ConfigurationContext>  configurationContext;
        /**
         * <b>ApplicationModel</b> business object it limits search scope for SOA operation.
         * This parameter cannot be <i>NULLTAG</i>.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Mdl0ApplicationModel>  modelContext;
        /**
         * Partition Scheme as another search criteria for the SOA, user can give <i>NULLTAG</i>
         * value for this parameter.For <i>NULLTAG</i> search scope will be  application model
         * itself.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Ptn0PartitionScheme>  partitionScheme;
        /**
         * An element for which corresponding partition is searched.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::POM_object>  partitionable;
    };

    /**
     * SOA operation output that is partition list for the partitionable is returned along
     * with the input partitionable in above structure.
     */
    struct WherePartitionedOutputInfo
    {
        /**
         * Input Partitionable provided while performing operation
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::POM_object>  partitionable;
        /**
         * List of output partitions for partitionables.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Ptn0Partition>  > partitions;
    };

    /**
     * <code>WherePartitionedResponse</code> structure is returned as the result of the
     * SOA operation.
     */
    struct WherePartitionedResponse
    {
        /**
         * List of a type <code>WherePartitionedOutputInfo</code> containing output partition
         * and given input partitionable to SOA.
         */
        std::vector< Ptn0::Services::Partition::_2011_06::Partitionmanagement::WherePartitionedOutputInfo > output;
        /**
         * Exception occurred while performing SOA operation is put into <code>serviceData</code>.
         * Results of SOA that is partition list is added to plain object list of <code>serviceData</code>.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




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


protected:
    virtual ~Partitionmanagement() {}
};
            }
        }
    }
}

#include <ptn0/services/partition/Partition_undef.h>
#endif

