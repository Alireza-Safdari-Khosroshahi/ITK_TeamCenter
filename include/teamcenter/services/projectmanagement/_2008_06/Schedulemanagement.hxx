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

#ifndef TEAMCENTER_SERVICES_PROJECTMANAGEMENT__2008_06_SCHEDULEMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_PROJECTMANAGEMENT__2008_06_SCHEDULEMANAGEMENT_HXX

#include <teamcenter/soa/client/model/BillRate.hxx>
#include <teamcenter/soa/client/model/ResourceAssignment.hxx>
#include <teamcenter/soa/client/model/Schedule.hxx>
#include <teamcenter/soa/client/model/ScheduleMember.hxx>
#include <teamcenter/soa/client/model/ScheduleTask.hxx>
#include <teamcenter/soa/client/model/SchedulingFixedCost.hxx>
#include <teamcenter/soa/client/model/TCCalendar.hxx>
#include <teamcenter/soa/client/model/TCCalendarEvent.hxx>
#include <teamcenter/soa/client/model/TaskDependency.hxx>
#include <teamcenter/soa/client/model/WorkspaceObject.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/projectmanagement/ProjectManagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Projectmanagement
        {
            namespace _2008_06
            {
                class Schedulemanagement;

class TCSOAPROJECTMANAGEMENTSTRONGMNGD_API Schedulemanagement
{
public:

    struct AddMembershipResponse;
    struct BillRateContainer;
    struct CreateBillRateResponse;
    struct CreateScheduleResponse;
    struct FixedCostContainer;
    struct MembershipData;
    struct NewScheduleContainer;
    struct ScheduleCopyOptionsContainer;
    struct ScheduleCopyResponse;
    struct ScheduleCopyResponses;
    struct ScheduleDeepCopyinfo;
    struct ScheduleDeliverableData;
    struct StringValContainer;
    struct TaskCostUpdate;
    struct TaskCostUpdateResponse;
    struct TypedAttributeContainer;
    struct UpdateTaskCostDataResponse;

    /**
     * The response when schedule members are added.
     */
    struct AddMembershipResponse
    {
        /**
         * The ServiceData.
         */
        Teamcenter::Soa::Client::ServiceData data;
        /**
         * The added members.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ScheduleMember>  > addedMembers;
    };

    /**
     * The container for a BillRate.
     */
    struct BillRateContainer
    {
        /**
         * The type: (0-Multiplier, 1-Custom Rate).
         */
        int type;
        /**
         * The name of the bill rate.
         */
        std::string name;
        /**
         * The new hourly rate or multiplier in the format *n.nnn (15.3  max).
         */
        std::string rate;
        /**
         * The ISO 4217 currency rate.
         */
        std::string currency;
    };

    /**
     * The response when BillRates are created.
     */
    struct CreateBillRateResponse
    {
        /**
         * The ServiceData.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * The added BillRates.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BillRate>  > rates;
    };

    /**
     * The response when new Schedule is created
     */
    struct CreateScheduleResponse
    {
        /**
         * The ServiceData
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * The created Schedules
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Schedule>  > schedules;
    };

    /**
     * The information need to create/update a Fixed Cost.
     */
    struct FixedCostContainer
    {
        /**
         * The name of fixed cost.
         */
        std::string name;
        /**
         * The estimated cost. Valid value can be empty string
         */
        std::string estimate;
        /**
         * The actual cost. Valid value can be empty string.
         */
        std::string actual;
        /**
         * ISO-4217 code for currency of the costs.
         */
        std::string currency;
        /**
         * Should accrual calculations use the "actual" cost?
         */
        bool useActual;
        /**
         * The billing code. Valid values are determined by the LOV  {unassigned, General, Management,
         * ProjectMgmt, Sales, Training, Travel, ProductDev, SoftwareDev}
         */
        std::string billCode;
        /**
         * The billing subcode. Valid values are determined by the LOV. Values are following
         * groups depending upon billcode.eg. If billcode is General then you can mentioned
         * subcode as either of following set (unassigned, Accounting, Clerical, CorpAdmin,
         * IT, Meetings, Other)                                             Following are the
         * list of billcode and corresponsing valid values for sub code.  For BillCode 'unassigned'
         * = { unassigned } For BillCode 'General' ={ unassigned, Accounting, Clerical, CorpAdmin,
         * IT, Meetings, Other }, For Bill code Management = { unassigned, Executive, ProjMgmt,
         * Design/Plan, Meetings, Training, Other} For BillCode 'ProiectMgmt' ={ unassigned,
         * Management, Meetings, Design/Plan, Training, Teaching, Clerical, Email, Other } For
         * BillCode 'Sales' ={ unassigned, MajorAccts, General, Admin, Training, Other } For
         * BillCode 'Training' ={ unassigned, Billable, Customer1, Customer2, Customer3, Region1,
         * Region2, Region3, Other } For BillCode 'Travel' ={ unassigned, Billable, Region1,
         * Region2, Region3, Other } For BillCode 'ProductDev' ={ unassigned, Planning, Design,
         * Development, ProcessMgt, Validation, Other } For BillCode 'SoftwareDev' ={unassigned,
         * Concept, Defination, Development, Introduction, Training, Other }
         */
        std::string subCode;
        /**
         * The billing type. Valid value are { unassigned, Billable, Billed, Standard, Unbillable}
         */
        std::string billingType;
        /**
         * The cost accrual type (0=start, 1=prorated, 2=end).
         */
        int accrualType;
        /**
         * A reference to the cost being updated (or null when newCost).
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::SchedulingFixedCost>  fixedCost;
    };

    /**
     * The information needed to create a new member in a schedule.
     */
    struct MembershipData
    {
        /**
         * The schedule for the new membership. Valid value- tag of the schedule.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Schedule>  schedule;
        /**
         * The resource to add.  (This can be a User, Group, or Discipline).valid value- tag
         * of the resource
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  resource;
        /**
         * The membership level in that schedule. Valid values are-{0-observer,1-participant,2-coordinator}
         */
        int membershipLevel;
        /**
         * The cost value (n.nnn (15.3 max))
         */
        std::string cost;
        /**
         * The ISO-4217 currency code.
         */
        std::string currency;
    };

    /**
     * The container for a new schedule.
     */
    struct NewScheduleContainer
    {
        /**
         * The name. Valid value can not be null
         */
        std::string name;
        /**
         * The description. Valid value can be empty string
         */
        std::string description;
        /**
         * id. Valid value can not be null
         */
        std::string id;
        /**
         * revID. Valid value can not be null
         */
        std::string revID;
        /**
         * The customer's name. Valid value can be empty string
         */
        std::string customerName;
        /**
         * The customer's ID. Valid value can be empty string
         */
        std::string customerNumber;
        /**
         * The start Date. Valid value can not be null
         */
        Teamcenter::Soa::Common::DateTime startDate;
        /**
         * The finishDate. Valid value can not be null
         */
        Teamcenter::Soa::Common::DateTime finishDate;
        /**
         * The priority. Valid values are {0-lowest,1-low,2-MediumLow,3-Medium,4-High,5-VeryHigh,6-Highest}
         */
        int priority;
        /**
         * The status. Valid values are  {0-Not started,1-In Progress,2-Needs Attention,3-Complete,4-Abandoned,5-Late}
         */
        int status;
        /**
         * Task fixed type. Valid values - FIXED_WORK = 0, FIXED_DURATION = 1, FIXED_RESOURCES=2
         */
        int taskFixedType;
        /**
         * Indicates whether the schedule is published. Valid values - true or false
         */
        bool published;
        /**
         * notificationsEnabled. Indicates whether notifications should be enabled. Valid values
         * - true or false
         */
        bool notificationsEnabled;
        /**
         * isPercentLinked? Indicates whether percentage complete should be linked to work complete.
         * Valid values - true, false
         */
        bool percentLinked;
        /**
         * isTemplate? Indicates whether the schedule is a template. Valid values - true, false
         */
        bool isTemplate;
        /**
         * Indicates whether the schedule is public. Valid values - true, false"
         */
        bool isPublic;
        /**
         * type. This is the object_type of the schedule being created. It could be "Schedule"
         * or any of the custom types created by the customer.
         */
        std::string type;
        /**
         * The billCode. Valid value can be empty string
         */
        std::string billCode;
        /**
         * The bill sub code. Valid value can be empty string
         */
        std::string billSubCode;
        /**
         * The bill type. Valid value can be empty string
         */
        std::string billType;
        /**
         * The bill rate. Valid value can be NULLTAG
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  billRate;
        /**
         * A collection of additional attributes (Optional)
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2008_06::Schedulemanagement::StringValContainer > stringValueContainer;
        /**
         * typedAttributesContainer. A container with type attribute -(optional)
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2008_06::Schedulemanagement::TypedAttributeContainer > typedAttributesContainer;
    };

    /**
     * The input information necessary to copy a schedule.
     */
    struct ScheduleCopyOptionsContainer
    {
        /**
         * The name of the new <b>Schedule</b> to be created.The name cannot be <code>NULL</code>
         * <br>
         */
        std::string name;
        /**
         * The description text for the new Schedule to be created.
         */
        std::string description;
        /**
         * The id of the new <b>Schedule</b> to be created. The id value cannot be NULL.
         */
        std::string id;
        /**
         * The <code>revID</code> of the new <b>ScheduleRevision</b> that will be created along
         * with the new schedule.
         * <br>
         * The <code>revID</code> value cannot be NULL.
         * <br>
         */
        std::string revId;
        /**
         * The tag to the schedule to copy.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Schedule>  scheduleToCopy;
        /**
         * This is the flag to indicate whether or not to reset the tasks' execution data (%,
         * status, work complete, etc)
         */
        bool resetWork;
        /**
         * Flag to indicate whether or not to copy baselines.
         */
        bool copyBaselines;
        /**
         * Flag to indicate whether or not to load the schedule in the response.
         */
        bool loadOnResponse;
        /**
         * This parameter stores the number of deep copied objects.
         */
        int iDeepCopyCount;
        /**
         * This parameter is  to collect additional attributes for the new schedule. The container
         * represents a single attribute's value.
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2008_06::Schedulemanagement::StringValContainer > stringValueContainer;
        /**
         * This parameter specifies  any additional attribute values to be set on the newly
         * created Schedule,scheduleRevision.
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2008_06::Schedulemanagement::TypedAttributeContainer > typedAttributesContainer;
        /**
         * This parameter specifies any additional metadata for the copy of the schedule. This
         * <code>DeepCopyData</code> data structure holds the relevant information regarding
         * applicable deep copy rules.
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2008_06::Schedulemanagement::ScheduleDeepCopyinfo > copyinfo;
    };

    /**
     * The response from a schedule copy call.  It includes all the data necessary to load
     * that schedule.
     */
    struct ScheduleCopyResponse
    {
        /**
         * The schedule.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Schedule>  schedule;
        /**
         * The schedule tasks.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ScheduleTask>  > scheduleTask;
        /**
         * The task assignments.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ResourceAssignment>  > resourceAssignment;
        /**
         * The task dependencies.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TaskDependency>  > taskDependency;
        /**
         * The calendars asssociated with the schedule and its members.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TCCalendar>  > calendar;
        /**
         * The calendar events associated with the calendars.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TCCalendarEvent>  > calendarEvent;
    };

    /**
     * Container to hold multiple ScheduleCopyResponse objects.
     */
    struct ScheduleCopyResponses
    {
        /**
         * A collection of ScheduleCopyResponses.
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2008_06::Schedulemanagement::ScheduleCopyResponse > scheduleResponse;
        /**
         * The ServiceData.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The DeepCopyData data structure holds the relevant information regarding applicable
     * deep copy rules.
     */
    struct ScheduleDeepCopyinfo
    {
        /**
         * A tag representing object on which the deep copy action need to be performed.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  objectComp;
        /**
         * A string representing the name the relation  that need to be deep copied. Valid value
         * can be IMANRelation.
         */
        std::string relation;
        /**
         * A string representing the new name for the new copy. of the object represented by
         * otherSideObjectTag. The value for the newName will be null if the 'action' is not
         * CopyAsObject or ReviseAndRelateToLatest.
         */
        std::string objName;
        /**
         * An integer representing the action to be performed on the object represented by 'otherSideObjectTag'.
         * The values for action are: CopyAsObjectType = 0, CopyAsRefType = 1, DontCopyType
         * =2, RelateToLatest = 3, ReviseAndRelateToLatest = 4
         */
        int operationType;
        /**
         * A Boolean representing whether the given item revision is a primary object in the
         * relation that need to be deep copied.
         */
        bool isTargetPrimary;
        /**
         * A Boolean representing whether the deep information is from a mandatory deep copy
         * rule configured by the administrator or not.
         */
        bool isRequired;
    };

    /**
     * A container for a new Schedule Deliverable.
     */
    struct ScheduleDeliverableData
    {
        /**
         * The schedule to contain this deliverable.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Schedule>  schedule;
        /**
         * The type of the deliverable.
         */
        std::string deliverableType;
        /**
         * The name of the deliverable.
         */
        std::string deliverableName;
        /**
         * A reference to the deliverable.(optional)
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  deliverableReference;
    };

    /**
     * The container represents a single attribute's value.  The name of the attribute is
     * represented by the key field.  The data type of the attribute is represented by the
     * type field. The type field can be one of the following; char = 0; date = 1; double
     * = 2; float = 3; int = 4; bool = 5; short = 6; string = 7; ModelObject = 8;
     */
    struct StringValContainer
    {
        /**
         * A string key identifying the attribute.
         */
        std::string key;
        /**
         * A string representation of the value of the attribute.
         */
        std::string value;
        /**
         * An integer to help determine the data type of the attribute. Valid values- { 1=String_type,2=Integer_type,3=Long_type,4=Double_type,5=Float_type,6=Boolean_type,7=Date_type,8=Cal_type
         * }
         */
        int type;
    };

    /**
     * The request container for fixed cost and costing meta data updates.
     */
    struct TaskCostUpdate
    {
        /**
         * The task which contains or will contain the fixed costs.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ScheduleTask>  task;
        /**
         * The information needed to create new fixed costs.
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2008_06::Schedulemanagement::FixedCostContainer > newCosts;
        /**
         * The information needed to update existing fixed costs.
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2008_06::Schedulemanagement::FixedCostContainer > updatedCosts;
        /**
         * A list of fixed costs to delete.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::SchedulingFixedCost>  > deletedCosts;
        /**
         * The bill code for the task. Valid values are determined by the LOV. Valid values
         * are {unassigned, General, Management, ProjectMgmt, Sales, Training, Travel, ProductDev,
         * SoftwareDev}
         */
        std::string billCode;
        /**
         * The bill subcode for the task. Valid values are determined by the LOV. Valid value
         * are following groups depending upon billcode.eg. If billcode is General then you
         * can mentioned subcode as either of following set (unassigned, Accounting, Clerical,
         * CorpAdmin, IT, Meetings, Other)                    Following are the list of billcode
         * and corresponsing valid values for sub code. For BillCode 'unassigned' = { unassigned
         * } For BillCode 'General' ={ unassigned, Accounting, Clerical, CorpAdmin, IT, Meetings,
         * Other }, For Bill code Management = { unassigned, Executive, ProjMgmt, Design/Plan,
         * Meetings, Training, Other} For BillCode 'ProiectMgmt' ={ unassigned, Management,
         * Meetings, Design/Plan, Training, Teaching, Clerical, Email, Other } For BillCode
         * 'Sales' ={ unassigned, MajorAccts, General, Admin, Training, Other } For BillCode
         * 'Training' ={ unassigned, Billable, Customer1, Customer2, Customer3, Region1, Region2,
         * Region3, Other } For BillCode 'Travel' ={ unassigned, Billable, Region1, Region2,
         * Region3, Other }                                       For BillCode 'ProductDev'
         * ={ unassigned, Planning, Design, Development, ProcessMgt, Validation,Other}
         * For BillCode 'SoftwareDev' ={unassigned,
         * Concept, Defination, Development, Introduction, Training, Other }
         */
        std::string subCode;
        /**
         * The billing type of the task. Valid values are determined by the LOV. Valid value
         * are { unassigned, Billable, Billed, Standard, Unbillable}
         */
        std::string billingType;
        /**
         * The name of the bill rate associated with the task. Valid value can be empty string
         */
        std::string billRate;
        /**
         * A tag to the bill rate to associate with this task. Valid value can be NULLTAG
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BillRate>  rate;
    };

    /**
     * The response container for fixed cost update.
     */
    struct TaskCostUpdateResponse
    {
        /**
         * The updated task.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ScheduleTask>  updatedTask;
        /**
         * The list of new fixed costs.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::SchedulingFixedCost>  > newCosts;
    };

    /**
     * A container which is used to update custom properties.
     */
    struct TypedAttributeContainer
    {
        /**
         * The object type. Valid values are {  ScheduleType,ScheduleRevisionType,ScheduleTaskType,ScheduleTaskRevisionType}
         */
        std::string type;
        /**
         * A collection of updates.(optional)
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2008_06::Schedulemanagement::StringValContainer > attributes;
    };

    /**
     * The response to the cost update.
     */
    struct UpdateTaskCostDataResponse
    {
        /**
         * The collection of individual task cost changes.
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2008_06::Schedulemanagement::TaskCostUpdateResponse > responses;
        /**
         * The ServiceData.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * This operation adds resources to the schedule with given membership levels.
     * <br>
     * <br>
     * The information required to add  new resource  to the schedule is passed to the function
     * through <code>MembershipData</code> structure.
     * <br>
     * <br>
     * The operation saves the references to the newly created membership objects and errors
     * if any in the <code>ServiceData</code> of the <code>MembershipDataResponse</code>
     * data structure.
     * <br>
     * 
     * <br>
     * When a resource that needs to be added doesnot exist,the operation returns and  the
     * error is saved in the <code>ServiceData</code> of the response.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param membershipData
     *        <code>struct  MembershipData
     *        <br>
     *        {
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;    BusinessObjectRef schedule;
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;BusinessObjectRef resource;
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;int membershipLevel;
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;string cost;
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;string currency;
     *        <br>
     *        }
     *        <br>
     *        </code>
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;schedule&nbsp;&nbsp;&nbsp;&nbsp;This represents the schedule
     *        for the new membership.
     *        <br>
     *        Valid value is  tag of the schedule.
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;resource&nbsp;&nbsp;&nbsp;&nbsp;The resource to add to the
     *        schedule.
     *        <br>
     *        The resource can be a User, Group, or Discipline.
     *        <br>
     *        Valid value is tag of the resource.
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;membershipLevel&nbsp;&nbsp;&nbsp;&nbsp;The membership level
     *        of the resource in the schedule.
     *        <br>
     *        Following are the valid values:
     *        <br>
     *        0-Observer,1-Participant,2-Coordinator.
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;cost&nbsp;&nbsp;&nbsp;&nbsp;This is the string representing
     *        the  cost value of the resource.
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;currency&nbsp;&nbsp;&nbsp;&nbsp;This is the string representing
     *        the ISO-4217 currency code.
     *        <br>
     *
     * @return
     *         The references to the created membership objects, partial errors and failures are
     *         updated and returned through this object. If the input parameters are invalid or
     *         if sufficient conditions are not met for performing the <code>addMemberships</code>
     *         operation,errors are returned.
     *         <br>
     *         Following are some possible errors returned:
     *         <br>
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;230002:&nbsp;&nbsp;&nbsp;&nbsp;One or more parameters passed
     *         to the function '%1$' were invalid. See system log for details
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;230012:&nbsp;&nbsp;&nbsp;&nbsp;Invalid resource passed.
     *         <br>
     *
     */
    virtual Teamcenter::Services::Projectmanagement::_2008_06::Schedulemanagement::AddMembershipResponse addMemberships ( const std::vector< Teamcenter::Services::Projectmanagement::_2008_06::Schedulemanagement::MembershipData >& membershipData ) = 0;

    /**
     * This operation makes a deep copy of the schedule with options to reset work and copy
     * existing baselines. The information needed to copy schedule is specified in the <code>ScheduleCopyOptionsContainer</code>
     * structure. It returns <code>ScheduleCopyResponses</code> which will have information
     * of copied  schedules and <code>ServiceData</code>. Errors will be returned in the
     * list of partial errors in the <code>ServiceData</code>.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param scheduleCopyContainer
     *        ScheduleCopyOptionsContainer
     *        <br>
     *        A container specifying  the options that need to be considered while copying the
     *        schedule.
     *        <br>
     *        <br>
     *        <code>struct ScheduleCopyOptionsContainer
     *        <br>
     *        {
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;string name;
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;string description;
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;string id;
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;string revId;
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;BusinessObjectRef scheduleToCopy;
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;bool resetWork;
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;bool copyBaselines;
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;bool loadOnResponse;
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;int iDeepCopyCount;
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;   std::vector stringValueContainer;
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;   std::vector typedAttributesContainer;
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;   std::vector copyinfo;
     *        <br>
     *        }
     *        <br>
     *        </code>
     *
     * @return
     *         A list of <code>ScheduleCopyResponse</code>, one for each successfully copied <b>Schedule</b>
     *         , and a <code>ServiceData</code> element. The newly created <b>Schedule</b> is added
     *         to the created list of the <code>ServiceData</code>.If the input parameters are invalid
     *         or if sufficient conditions are not met for performing the <code>copySchedules</code>
     *         operation,errors are returned.
     *         <br>
     *         <br>
     *         Following are some possible errors returned:
     *         <br>
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;230003:&nbsp;&nbsp;&nbsp;&nbsp;A Schedule with the ID already
     *         exists.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;230004:&nbsp;&nbsp;&nbsp;&nbsp;A Schedule Revision with
     *         the RevID already exists.
     *         <br>
     *
     */
    virtual Teamcenter::Services::Projectmanagement::_2008_06::Schedulemanagement::ScheduleCopyResponses copySchedules ( const std::vector< Teamcenter::Services::Projectmanagement::_2008_06::Schedulemanagement::ScheduleCopyOptionsContainer >& scheduleCopyContainer ) = 0;

    /**
     * This operation creates a new <b>BillRates</b>.<b> BillRate</b> is a business object
     * that is used to represent<b> Rate Modifiers</b>,which are used  with resource costing
     * information to calculate schedule and task costs and are defined by billing types,
     * rates and currency. This operation throws exceptions that are system and database
     * exceptions . There are no specific business logic errors. The created objects are
     * returned back in the service data of the response.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param rates
     *        A collection of <code>BillRateContainer</code> structures. This structure contains
     *        the information to create new bill rate.
     *        <br>
     *
     * @return
     *         The created bill rate objects, Partial errors and failures are returned through this
     *         object.
     *
     */
    virtual Teamcenter::Services::Projectmanagement::_2008_06::Schedulemanagement::CreateBillRateResponse createBillRates ( const std::vector< Teamcenter::Services::Projectmanagement::_2008_06::Schedulemanagement::BillRateContainer >& rates ) = 0;

    /**
     * This operation creates new schedule based on the initial user's request to the application
     * interface. The information needed to create <b>Schedule</b> is specified in the <code>NewScheduleContainer</code>
     * structure. It returns <code>CreateScheduleResponse</code> which will have information
     * of created schedules and <code>ServiceData</code>. Errors will be returned in the
     * list of partial errors in the <code>ServiceData</code>.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param newSchedules
     *        Vector of <code>NewScheduleContainer</code> structures. Each <code>NewScheduleContainer</code>
     *        structure holds information needed to create a single <b>Schedule</b>.
     *        <br>
     *
     * @return
     *         A list of <code>CreateScheduleResponse</code>, one for each successfully created
     *         schedule, and a <code>ServiceData</code> element. The newly created schedule is added
     *         to the created list of the <code>ServiceData</code>.If the input parameters are invalid
     *         or if sufficient conditions are not met for performing the <code>createSchedule</code>
     *         operation,errors are returned.
     *         <br>
     *         <br>
     *         Following are some possible errors returned:
     *         <br>
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;230003:&nbsp;&nbsp;&nbsp;&nbsp;A <b>Schedule</b> with the
     *         ID already exists.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;230004:&nbsp;&nbsp;&nbsp;&nbsp;A <b>Schedule Revision</b>
     *         with the <b>RevID</b> already exists.
     *         <br>
     *
     */
    virtual Teamcenter::Services::Projectmanagement::_2008_06::Schedulemanagement::CreateScheduleResponse createSchedule ( const std::vector< Teamcenter::Services::Projectmanagement::_2008_06::Schedulemanagement::NewScheduleContainer >& newSchedules ) = 0;

    /**
     * This operation creates new schedule deliverable. The created objects are returned
     * back in the <code>ServiceData</code> of the response. <code>ServiceData</code> will
     * contain partial errors in case of operation failure.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param scheduleDeliverableData
     *        Vector of ScheduleDeliverableData structures. This structure will have all information
     *        necessory to create a schedule deliverable
     *
     * @return
     *         <code>Teamcenter::Soa::Server::ServiceData</code>
     *         <br>
     *         <br>
     *         This operation returns the references to the created <b>ScheduleDeliverable</b> objects,
     *         partial errors and failures are updated and returned through this object. If the
     *         input parameters are invalid or if sufficient conditions are not met for performing
     *         the <code>createScheduleDeliverableTemplates</code>
     *         <br>
     *         operation,errors are returned.
     *         <br>
     *         <br>
     *         Following are some possible errors returned:
     *         <br>
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;230029:&nbsp;&nbsp;&nbsp;&nbsp;<b>ScheduleDeliverable</b>
     *         with the same display name already exists in the Schedule.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;230046:&nbsp;&nbsp;&nbsp;&nbsp;This type is not supported
     *         for <b>Schedule Deliverables</b>. Please consult the description of <b>ScheduleDeliverableWSOTypes</b>
     *         preference.
     *         <br>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData createScheduleDeliverableTemplates ( const std::vector< Teamcenter::Services::Projectmanagement::_2008_06::Schedulemanagement::ScheduleDeliverableData >& scheduleDeliverableData ) = 0;

    /**
     * This operation creates, updates and deletes fixed cost entries and task costing metadata
     * such as bill code, sub code etc. This operation throws exceptions that are system
     * and database exceptions. There are no specific business logic errors. The created
     * objects are returned back in the service data of the response.
     * <br>
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param updates
     *        A collection of <code>TaskCostUpdate</code>  structures. This structure is the request
     *        container for fixed cost and costing meta data updates.
     *        <br>
     *
     * @return
     *         The created and updated objects,partial errors and failures are returned through
     *         this object.There will be no business logic errors or failures.
     *         <br>
     *
     */
    virtual Teamcenter::Services::Projectmanagement::_2008_06::Schedulemanagement::UpdateTaskCostDataResponse updateTaskCostData ( const std::vector< Teamcenter::Services::Projectmanagement::_2008_06::Schedulemanagement::TaskCostUpdate >& updates ) = 0;


protected:
    virtual ~Schedulemanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/projectmanagement/ProjectManagement_undef.h>
#endif

