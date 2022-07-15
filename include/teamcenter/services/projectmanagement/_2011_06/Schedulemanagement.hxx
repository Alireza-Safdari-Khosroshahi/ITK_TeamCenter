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

#ifndef TEAMCENTER_SERVICES_PROJECTMANAGEMENT__2011_06_SCHEDULEMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_PROJECTMANAGEMENT__2011_06_SCHEDULEMANAGEMENT_HXX

#include <teamcenter/services/projectmanagement/_2008_06/Schedulemanagement.hxx>
#include <teamcenter/soa/client/model/Fnd0ProxyTask.hxx>
#include <teamcenter/soa/client/model/ResourceAssignment.hxx>
#include <teamcenter/soa/client/model/Schedule.hxx>
#include <teamcenter/soa/client/model/ScheduleTask.hxx>
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
            namespace _2011_06
            {
                class Schedulemanagement;

class TCSOAPROJECTMANAGEMENTSTRONGMNGD_API Schedulemanagement
{
public:

    struct SchMgtOptions;
    struct LoadScheduleContainer;
    struct LockRequest;
    struct LockResponse;
    struct LockResponses;
    struct MasterMetaData;
    struct MultipleScheduleLoadResponses;
    struct ProxyTaskContainer;
    struct ProxyTaskResponse;
    struct ProxyTaskResponses;
    struct SchmgtClientCache;
    struct RefreshScheduleContainer;
    struct ScheduleCopyOptionsContainer;
    struct SchMgtOptionsAsync;
    struct ScheduleCopyOptionsContainerAsync;
    struct ScheduleDeepCopyinfoAsync;
    struct ScheduleLoadResponse;
    struct SchMgtIntegerOption;
    struct SchMgtIntegerOptionAsync;
    struct SchMgtLogicalOption;
    struct SchMgtLogicalOptionAsync;
    struct SchmgtNamedStringList;
    struct SchMgtStringOption;
    struct SchMgtStringOptionAsync;
    struct StringValContainerAsync;
    struct SubMasterMetaData;
    struct TaskExecUpdate;
    struct TypedAttributeContainerAsync;

    /**
     * Schedule Management Options
     */
    struct SchMgtOptions
    {
        /**
         * Logical options
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2011_06::Schedulemanagement::SchMgtLogicalOption > logicalOptions;
        /**
         * Integer Options
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2011_06::Schedulemanagement::SchMgtIntegerOption > integerOptions;
        /**
         * String Options
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2011_06::Schedulemanagement::SchMgtStringOption > stringOptions;
    };

    /**
     * Contain the schedule uids and options for loading schedules
     */
    struct LoadScheduleContainer
    {
        /**
         * The UIDs of the schedules.
         */
        std::vector< std::string > scheduleUids;
        /**
         * The options for loading. Integer Option: "SM_Structure_Partial_Context" Values: 0
         * =  load the full schedule including all sub schedules and their children . 1 =
         * load only schedule summaries partially     Integer Option:  "SM_Structure_Load_Context"
         * Values:  0 = loading schedule  1 = loading sub-schedule   4 = inserting sub schedule
         * by reference Integer Option: "SM_Structure_Client_Context" Values: 0 = RAC client
         * 1 = Server client (for Synchronous dispatcher) 2 = MSP plugin client
         */
        Teamcenter::Services::Projectmanagement::_2011_06::Schedulemanagement::SchMgtOptions schmgtOptions;
    };

    /**
     * A request structure to lock the schedule.
     */
    struct LockRequest
    {
        /**
         * The schedule for which the lock request is
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Schedule>  schedule;
        /**
         * The request to lock (true) or unlock (false)
         */
        bool requestLock;
    };

    /**
     * A Response for SOA "ManageScheduleLocks". This will indicate whether the lock request
     * is successful or not.
     */
    struct LockResponse
    {
        /**
         * The schedule locked or unlocked
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Schedule>  schedule;
        /**
         * The state of the lock (true=locked, false=not locked)
         */
        bool lockState;
        /**
         * Was the request successful. True if the request was a success.
         */
        bool requestSuccess;
    };

    /**
     * List of multiple "LockResponses".
     */
    struct LockResponses
    {
        /**
         * The service data
         */
        Teamcenter::Soa::Client::ServiceData data;
        /**
         * The individual responses
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2011_06::Schedulemanagement::LockResponse > responses;
    };

    /**
     * A container for the SubMasterMetaData.
     */
    struct MasterMetaData
    {
        /**
         * The uid of a master schedule.
         */
        std::string uid;
        /**
         * The Start Date of that master schedule.
         */
        Teamcenter::Soa::Common::DateTime start;
        /**
         * The Finish Date of that master schedule.
         */
        Teamcenter::Soa::Common::DateTime finish;
    };

    /**
     * A container for load schedule responses
     */
    struct MultipleScheduleLoadResponses
    {
        /**
         * Collection of the schedule load responses.
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2011_06::Schedulemanagement::ScheduleLoadResponse > scheduleData;
        /**
         * The ServiceData.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Container for Proxy Task
     */
    struct ProxyTaskContainer
    {
        /**
         * The schedule were the proxy is being created
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Schedule>  schedule;
        /**
         * Number of sublevels (if this should be mirrored in the sub schedules (-1 =  all,
         * 0 = only this schedule, 1= first level, 2 = 1st and 2nd level, etc)
         */
        int sublevels;
        /**
         * The real task being proxied.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ScheduleTask>  taskTag;
        /**
         * The reference task in the schedule
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  refTag;
    };

    /**
     * Response for createProxyTasks call.
     */
    struct ProxyTaskResponse
    {
        /**
         * The schedule of the proxy task.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Schedule>  schedule;
        /**
         * The proxy task
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Fnd0ProxyTask>  proxyTask;
        /**
         * A collection containing a ProxyTaskResponse for each sub schedules addition
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2011_06::Schedulemanagement::ProxyTaskResponse > subScheduleAdditions;
    };

    /**
     * A collection of ProxyTaskResponses returned for createProxyTasks call.
     */
    struct ProxyTaskResponses
    {
        /**
         * The service data
         */
        Teamcenter::Soa::Client::ServiceData data;
        /**
         * A collection of ProxyTaskResponse
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2011_06::Schedulemanagement::ProxyTaskResponse > responses;
    };

    /**
     * The list of names lists.
     */
    struct SchmgtClientCache
    {
        /**
         * Array of named string lists of components uid
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2011_06::Schedulemanagement::SchmgtNamedStringList > namedStringLists;
    };

    /**
     * Container for refreshing schedule
     */
    struct RefreshScheduleContainer
    {
        /**
         * The UID of the master schedule.
         */
        std::string masterScheduleUid;
        /**
         * The UID of the object to refresh
         */
        std::string componentUid;
        /**
         * The options for refresh. Integer Option: "SM_Structure_Partial_Context" Values: 0
         * =  load the full schedule including all sub schedules and their children . 1 =
         * load only schedule summaries partially     Integer Option:  "SM_Structure_Load_Context"
         * Values:  6 = refresh the schedule 7 = load all objects currently not in the client;
         * compliment  Integer Option: "SM_Structure_Client_Context" Values: 0 = RAC client
         * 1 = Server client (for Synchronous dispatcher) 2 = MSP plugin client
         */
        Teamcenter::Services::Projectmanagement::_2011_06::Schedulemanagement::SchMgtOptions refreshOptions;
        /**
         * List of currently loaded components for the object being refreshed.
         */
        Teamcenter::Services::Projectmanagement::_2011_06::Schedulemanagement::SchmgtClientCache clientCache;
        /**
         * The last modified date for the component represented by componentUID.
         */
        Teamcenter::Soa::Common::DateTime lastModifiedDate;
    };

    /**
     * Container for schedule copy options
     */
    struct ScheduleCopyOptionsContainer
    {
        /**
         * The name of the new schedule
         */
        std::string name;
        /**
         * The description of the new schedule. Valid value -can be empty string.
         */
        std::string description;
        /**
         * The ID of the new schedule.
         */
        std::string id;
        /**
         * The revId of the new schedule.
         */
        std::string revId;
        /**
         * The tag to the schedule to copy.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Schedule>  scheduleToCopy;
        /**
         * Copy schedule options 1) logical options  -{bool copyBaselines,bool loadOnResponse,bool
         * resetWork,bool copyProxyTasks,bool  copycrossScheduleDependencies } 2) integerOptions
         * -{ int ideepCopyCount } 3) stringOptions -{bool deepcopyrequired }
         */
        Teamcenter::Services::Projectmanagement::_2011_06::Schedulemanagement::SchMgtOptions options;
        /**
         * Additional attributes for the new schedule.(optional)
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2008_06::Schedulemanagement::StringValContainer > stringValueContainer;
        /**
         * Additional  attributes for the new schedule.(optional)
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2008_06::Schedulemanagement::TypedAttributeContainer > typedAttributesContainer;
        /**
         * Additional metadata for the copy.(optional)
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2008_06::Schedulemanagement::ScheduleDeepCopyinfo > copyInfo;
    };

    /**
     * SchMgtOptions for Async operation
     */
    struct SchMgtOptionsAsync
    {
        /**
         * Logical options
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2011_06::Schedulemanagement::SchMgtLogicalOptionAsync > logicalOptions;
        /**
         * Integer Options
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2011_06::Schedulemanagement::SchMgtIntegerOptionAsync > integerOptions;
        /**
         * String Options
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2011_06::Schedulemanagement::SchMgtStringOptionAsync > stringOptions;
    };

    /**
     * ScheduleCopyOptionsContainer for copySchedule
     */
    struct ScheduleCopyOptionsContainerAsync
    {
        /**
         * The name of the new schedule
         */
        std::string name;
        /**
         * The description of the new schedule. Valid value -can be empty string.
         */
        std::string description;
        /**
         * The ID of the new schedule.
         */
        std::string id;
        /**
         * The revId of the new schedule.
         */
        std::string revId;
        /**
         * The tag to the schedule to copy.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Schedule>  scheduleToCopy;
        /**
         * Copy schedule options 1) logical options  -{bool copyBaselines,bool loadOnResponse,bool
         * resetWork,bool copyProxyTasks,bool  copycrossScheduleDependencies } 2) integerOptions
         * -{ int ideepCopyCount } 3) stringOptions -{bool deepcopyrequired }
         */
        Teamcenter::Services::Projectmanagement::_2011_06::Schedulemanagement::SchMgtOptionsAsync options;
        /**
         * Additional  attributes for the new schedule.(optional)
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2011_06::Schedulemanagement::StringValContainerAsync > stringValueContainer;
        /**
         * Additional  attributes for the new schedule.(optional)
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2011_06::Schedulemanagement::TypedAttributeContainerAsync > typedAttributesContainer;
        /**
         * This parameter specifies any additional metadata for the copy of the schedule. This
         * <code>ScheduleDeepCopyinfoAsync</code> data structure holds the relevant information
         * regarding applicable deep copy rules. This is optional parameter.
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2011_06::Schedulemanagement::ScheduleDeepCopyinfoAsync > copyInfo;
    };

    /**
     * ScheduleDeepCopyinfoAsync container
     */
    struct ScheduleDeepCopyinfoAsync
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
     * Container for the load schedules response.
     */
    struct ScheduleLoadResponse
    {
        /**
         * The schedule
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Schedule>  schedule;
        /**
         * All the tasks in this schedule.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ScheduleTask>  > scheduleTasks;
        /**
         * All the resource assignments in this schedule.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ResourceAssignment>  > resourceAssignments;
        /**
         * All the task dependencies in this schedule.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TaskDependency>  > taskDependencies;
        /**
         * All the calendars referenced in this schedule.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TCCalendar>  > calendars;
        /**
         * All the calendar events referenced in the calendars.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TCCalendarEvent>  > calendarEvents;
        /**
         * The metadata for master-schedules of this schedule and all sub-schedules.
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2011_06::Schedulemanagement::SubMasterMetaData > submasterdata;
        /**
         * Currently used by refresh to return deleted objects to the client.
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2011_06::Schedulemanagement::SchmgtNamedStringList > namedStringLists;
    };

    /**
     * Schedule Manager Integer Option
     */
    struct SchMgtIntegerOption
    {
        /**
         * The name of the option
         */
        std::string name;
        /**
         * The value of the option
         */
        int value;
    };

    /**
     * SchMgtIntegerOptions for Async operation
     */
    struct SchMgtIntegerOptionAsync
    {
        /**
         * The name of the option
         */
        std::string name;
        /**
         * The value of the option
         */
        int value;
    };

    /**
     * Schedule Manager Logical Option
     */
    struct SchMgtLogicalOption
    {
        /**
         * The name of the option
         */
        std::string name;
        /**
         * The value of the option (True or False)
         */
        bool value;
    };

    /**
     * SchMgtLogicalOptions for Async operation
     */
    struct SchMgtLogicalOptionAsync
    {
        /**
         * The name of the option
         */
        std::string name;
        /**
         * The value of the option (True or False)
         */
        bool value;
    };

    /**
     * A vector of lists.
     */
    struct SchmgtNamedStringList
    {
        /**
         * A unique identifier for this list (possibly UID).
         */
        std::string name;
        /**
         * The list of  UIDs contained by this object.
         */
        std::vector< std::string > list;
        /**
         * Not Used
         */
        double aggregate;
    };

    /**
     * Schedule Manager String Option
     */
    struct SchMgtStringOption
    {
        /**
         * The name of the option
         */
        std::string name;
        /**
         * The value of the option.
         */
        std::string value;
    };

    /**
     * SchMgtStringOptions for Async operation
     */
    struct SchMgtStringOptionAsync
    {
        /**
         * The name of the option
         */
        std::string name;
        /**
         * The value of the option.
         */
        std::string value;
    };

    /**
     * string value container for Async operation
     */
    struct StringValContainerAsync
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
     * A container for the sub-schedule master MetaData.
     */
    struct SubMasterMetaData
    {
        /**
         * The tag of the sub schedule.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Schedule>  subschedule;
        /**
         * Collection of metadata for all master schedules of this schedule and it's sub-schedules.
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2011_06::Schedulemanagement::MasterMetaData > masterdata;
    };

    /**
     * The structure which would be used to send back and forth the data for execution view
     * for tasks.
     */
    struct TaskExecUpdate
    {
        /**
         * The task being updated.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ScheduleTask>  task;
        /**
         * Must be true when updating the Actual Start Date.
         */
        bool updateAS;
        /**
         * The new Actual Start Date to set (null is allowed). updateAS must also be to true
         * to update this value.
         */
        Teamcenter::Soa::Common::DateTime newAS;
        /**
         * Must be true when updating the Actual Finish Date.
         */
        bool updateAF;
        /**
         * The new Actual Finish Date to set (null is allowed). updateAF must also be to true
         * to update this value.
         */
        Teamcenter::Soa::Common::DateTime newAF;
        /**
         * The new percent complete for the task (0-100) (-1 for no  update)
         */
        double newPC;
        /**
         * The new status for the task. Valid values are the status strings listed in the status
         * LOV. ("" or null for no update)
         */
        std::string newStatus;
        /**
         * The new work complete to set (-1 means no update)
         */
        int newWC;
        /**
         * The new work remaining to set (-1 means no update)
         */
        int newWR;
    };

    /**
     * TypedAttributeContainerAsync conatiner for Async operation
     */
    struct TypedAttributeContainerAsync
    {
        /**
         * The object type
         */
        std::string type;
        /**
         * A collection of updates
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2011_06::Schedulemanagement::StringValContainerAsync > attributes;
    };




    /**
     * This operation makes a deep copy of the schedule with options to reset work and copy
     * existing baselines.
     * <br>
     * The following  are the options:  <code>resetWork</code> (false if not provided),
     * <br>
     * <code>copyBaselines</code> (false if not provided),
     * <br>
     * <code>copyProxyTasks</code> (false if not provided),
     * <br>
     * <code>copyCrossScheduleDependencies</code> (false if not provided )
     * <br>
     * <br>
     * The information needed to copy the schedule is specified in the <code>ScheduleCopyOptionsContainer</code>
     * structure. It returns <code>ScheduleCopyResponses</code> which will have information
     * of copied  schedules and <code>ServiceData</code>. Errors will be returned in the
     * list of partial errors in the <code>ServiceData</code>.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param containers
     *        <code>ScheduleCopyOptionsContainer</code>
     *        <br>
     *        A container specifying  the options that need to be considered while copying the
     *        schedule.
     *        <br>
     *        <br>
     *        <code>struct ScheduleCopyOptionsContainer
     *        <br>
     *        {
     *        <br>
     *        string name;
     *        <br>
     *        string description;
     *        <br>
     *        string id;
     *        <br>
     *        string revId;
     *        <br>
     *        BusinessObjectRef<Teamcenter::Schedule> scheduleToCopy;
     *        <br>
     *        bool resetWork;
     *        <br>
     *        bool copyBaselines;
     *        <br>
     *        bool loadOnResponse;
     *        <br>
     *        int iDeepCopyCount;
     *        <br>
     *        std::vector< StringValContainer > stringValueContainer;
     *        <br>
     *        std::vector< TypedAttributeContainer > typedAttributesContainer;
     *        <br>
     *        std::vector< ScheduleDeepCopyinfo > copyinfo;
     *        <br>
     *        }</code>
     *        <br>
     *
     * @return
     *         A list of <code>ScheduleCopyResponse</code>, one for each successfully copied <b>Schedule</b>
     *         , and a <code>ServiceData</code> element. The newly created <b>Schedule</b> is added
     *         to the created list of the ServiceData.If the input parameters are invalid or if
     *         sufficient conditions are not met for performing the <code>copySchedules</code> operation,errors
     *         are returned.
     *         <br>
     *         <br>
     *         Following are some possible errors returned:
     *         <br>
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;230003:&nbsp;&nbsp;&nbsp;&nbsp;A <b>Schedule</b> with the
     *         <b>ID</b> already exists.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;230004:&nbsp;&nbsp;&nbsp;&nbsp;A <b>Schedule Revision</b>
     *         with the <b>RevID</b> already exists.
     *         <br>
     *
     */
    virtual Teamcenter::Services::Projectmanagement::_2008_06::Schedulemanagement::ScheduleCopyResponses copySchedules ( const std::vector< Teamcenter::Services::Projectmanagement::_2011_06::Schedulemanagement::ScheduleCopyOptionsContainer >& containers ) = 0;

    /**
     * This operation copies schedule asynchronously. The information required to copy the
     * schedule asynchronously is passed as parameter to the operation as <code>ScheduleCopyOptionsContainerAsync</code>
     * data structure.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param schToCopy
     *        A vector of <code>ScheduleCopyOptionsContainerAsync</code> structures to copy schedule
     *        asynchronously.
     *
     * @return
     *         This operation returns boolean value which can be ignored. There are no specific
     *         business errors returned.
     *         <br>
     *
     */
    virtual bool copySchedulesAsyncClient ( const std::vector< Teamcenter::Services::Projectmanagement::_2011_06::Schedulemanagement::ScheduleCopyOptionsContainerAsync >& schToCopy ) = 0;

    /**
     * This operation creates proxy tasks. The information needed to create proxy tasks
     * are specified in the <code>ProxyTaskContainer</code> structure. It returns <code>ProxyTaskResponses</code>
     * which will have information of created proxy tasks and <code>ServiceData</code>.
     * Errors will be returned in the list of partial errors in the <code>ServiceData</code>
     * if operation fails to create proxy task.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param newProxyTasks
     *        Vector of <code>ProxyTaskContainer</code> structures to create proxy &nbsp;&nbsp;&nbsp;&nbsp;tasks.
     *        This structure will contain all necessory information to create new proxy task.
     *
     * @return
     *         <code>Teamcenter::Soa::ProjectManagement::_2011_06::ScheduleManagement::ProxyTaskResponses</code>
     *         <br>
     *         <br>
     *         This response structure will contain vector of <code>ProxyTaskResponse</code> and
     *         <code>ServiceData</code>. <code>ServiceData</code> will contain partial errors if
     *         operation fails to create proxy task. <code>ProxyTaskResponse</code> will have information
     *         on created proxy tasks.
     *         <br>
     *         <br>
     *         Following are some possible errors returned:
     *         <br>
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;230088:&nbsp;&nbsp;&nbsp;&nbsp;A task cannot be assigned
     *         a proxy in the same schedule .
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;230089:&nbsp;&nbsp;&nbsp;&nbsp;This task already has a proxy
     *         in this schedule.
     *         <br>
     *
     */
    virtual Teamcenter::Services::Projectmanagement::_2011_06::Schedulemanagement::ProxyTaskResponses createProxyTasks ( const std::vector< Teamcenter::Services::Projectmanagement::_2011_06::Schedulemanagement::ProxyTaskContainer >& newProxyTasks ) = 0;

    /**
     * Deletes the specified schedule asynchronously but will check that there is a connection
     * between client and server before performing the delete action. After the check is
     * performed successfully a call to <code>deleteScheduleAsync</code> operation is made
     * to finalize the deletion of the schedule. See operation <code>deleteScheduleAsync</code>
     * for more details.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param schToDelete
     *        The schedule to delete.
     *
     * @return
     *         Business Errors
     *         <br>
     *         1.&nbsp;&nbsp;&nbsp;&nbsp;Invalid Schedule. This indicates stale data schedules which
     *         has already been deleted or just bad input.
     *         <br>
     *         <br>
     *         Throws:
     *         <br>
     *         A Teamcenter service exception is thrown.
     *         <br>
     *         <br>
     *
     */
    virtual bool deleteScheduleAsyncClient ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Schedule>  schToDelete ) = 0;

    /**
     * The operation loads into memory all the objects belonging to a schedule. The objects
     * are those needed to manage and validate the schedule. The objects are can be  instances
     * of <b>Schedule</b>, <b>ScheduleTask</b>, <b>ResourceAssignment</b>, <b>TaskDependency</b>,
     * <b>TCCalendar</b> <b>TCCalendarEvents</b> and <code>SubMasterMetaData</code> .
     * <br>
     * This operation requires a load option which defines how it behaves, such as loading
     * sections of a structured schedule on demand or loading the full schedule if system
     * resources are available to accomplish request. The load option is defined by the
     * preference "<b>SM_Structure_Partial_Context</b>" which can be set to one of the following
     * values:
     * <br>
     * 1)&nbsp;&nbsp;&nbsp;&nbsp;0 -> load all the schedule objects
     * <br>
     * 2)&nbsp;&nbsp;&nbsp;&nbsp;1 -> load the schedule objects on demand.
     * <br>
     * The default load option is 0 (load all objects).
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param loadScheduleContainers
     *        Containers for information required to load schedules. A container has the schedule
     *        UID and load options.
     *
     * @return
     *         The operation returns a <code>MultipleScheduleLoadResponse</code>  containing a list
     *         an array of <code>ScheduleLoadResponse</code> .objects. Each <code>ScheduleLoadResponse</code>
     *         object contains all of the data for a schedule. This includes schedule, tasks, dependencies,
     *         assignments, and calendars objects. Partial errors and failures are updated and returned
     *         through this object via the <code>ServiceData</code> .
     *         <br>
     *         Some of the errors returned in the <code>ServiceData</code> are
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;Unable to load schedule.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;Invalid schedule tag.
     *         <br>
     *         <br>
     *         Throws:
     *         <br>
     *         The operation may throw service exception due to unchecked error. There are no other
     *         known specific conditions for failure.
     *         <br>
     *
     */
    virtual Teamcenter::Services::Projectmanagement::_2011_06::Schedulemanagement::MultipleScheduleLoadResponses loadSchedules ( const std::vector< Teamcenter::Services::Projectmanagement::_2011_06::Schedulemanagement::LoadScheduleContainer >& loadScheduleContainers ) = 0;

    /**
     * This is an operation that is used to manage concurrent access to schedule data. The
     * server concurrent access capability allows schedule data to be accessed simultaneously
     * from different sessions. To ensure data integrity, the server enforces a first-in-first-out
     * execution logic by locking out access to the same data from other sessions until
     * the lock is removed. During the lock period the session that owns the lock is allowed
     * to add and update the schedule data. For deferred save or bulk update, the operation
     * is used to purposely lock the schedule data until an unlock request is received.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param requests
     *        The LockRequests
     *
     * @return
     *         <code>Teamcenter</code><code>::</code><code>Soa</code><code>::</code><code>ProjectManagement</code><code>::_</code><code>2011_06</code><code>::</code><code>ScheduleManagement</code><code>::</code><code>LockResponses</code>
     *         <br>
     *         This structure will contain information whether the operation is successful or failed.
     *         <br>
     *         <br>
     *         Throws:
     *         <br>
     *         The operation may throw <code>ServiceException</code> due to unchecked error. There
     *         are no other known specific conditions for failure.
     *         <br>
     *         <br>
     *         <code>struct</code><code> </code><code>LockResponses</code><code>
     *         <br>
     *         {
     *         <br>
     *         </code><code>Teamcenter</code><code>::</code><code>Soa</code><code>::Server::ServiceData
     *         data;
     *         <br>
     *         </code><code>std</code><code>::vector< </code><code>LockResponse</code><code>
     *         > responses;
     *         <br>
     *         }</code>
     *         <br>
     *         <br>
     *         <code>&nbsp;&nbsp;&nbsp;&nbsp;data</code> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Service
     *         data
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;<code>responses</code>&nbsp;&nbsp;&nbsp;&nbsp;Vector of
     *         <code>LockResponse</code> objects
     *         <br>
     *         <br>
     *         <br>
     *         <code>struct</code><code> </code><code>LockResponse</code><code>
     *         <br>
     *         {
     *         <br>
     *         </code><code>BusinessObjectRef</code><code><</code><code>Teamcenter</code><code>::Schedule>
     *         schedule;
     *         <br>
     *         </code><code>bool</code><code> </code><code>lockState</code><code>;
     *         <br>
     *         </code><code>bool</code><code> </code><code>requestSuccess</code><code>;
     *         <br>
     *         };</code>
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;<code>schedule</code>&nbsp;&nbsp;&nbsp;&nbsp;          The
     *         schedule object that was locked or unlocked.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;<code>lockState</code>&nbsp;&nbsp;&nbsp;&nbsp;
     *         State of the lock (<code>TRUE</code> = locked, <code>FALSE</code> = not locked)
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;<code>requestSuccess</code>   Was the request successful.
     *         <code>TRUE</code> = success, <code>FALSE</code> = failure
     *         <br>
     *
     */
    virtual Teamcenter::Services::Projectmanagement::_2011_06::Schedulemanagement::LockResponses manageScheduleLocks ( const std::vector< Teamcenter::Services::Projectmanagement::_2011_06::Schedulemanagement::LockRequest >& requests ) = 0;

    /**
     * The server allows concurrent access to a schedule data and because of this capability
     * updates and additions can be added to the schedule data from other sessions apart
     * from a client session. This operation loads all the objects in a schedule since the
     * last modified date in the client session. The client can also specify the date from
     * which to begin the load. The operation would then return all schedule objects that
     * were modified from the specified date. It may also include objects modified in the
     * client's session. The objects are <b>Schedule</b>, <b>ScheduleTask</b>, <b>ResourceAssignment</b>,
     * <b>TaskDependency</b>, <b>TCCalendar TCCalendarEvents</b> and <b>SubMasterMetaData</b>.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param refreshScheduleContainer
     *        A container of schedule object, refresh operation options and last modified date
     *
     * @return
     *         The operation returns a <code>MultipleScheduleLoadResponse</code> containing an array
     *         of <code>ScheduleLoadResponse</code>. Each <code>ScheduleLoadResponse</code> object
     *         contains all of the data for a schedule. This includes schedule, tasks, dependencies,
     *         assignments, and calendars objects. Partial errors and failures are updated and returned
     *         through this object via the <code>ServiceData</code>.
     *         <br>
     *         <br>
     *         Throws:
     *         <br>
     *         The operation may throw <code>ServiceException</code> due to unchecked error. There
     *         are no other known specific conditions for failure.
     *         <br>
     *
     */
    virtual Teamcenter::Services::Projectmanagement::_2011_06::Schedulemanagement::MultipleScheduleLoadResponses refreshScheduleObject ( const Teamcenter::Services::Projectmanagement::_2011_06::Schedulemanagement::RefreshScheduleContainer&  refreshScheduleContainer ) = 0;

    /**
     * Updates the execution data attributes of <b>Schedule Tasks</b>. The updates are specified
     * through <code>TaskExecUpdate</code>  structures. <b>actual start date, actual finish
     * date, percent complete, status, work complete and work remaining</b> attributes on
     * schedule task can be updated through this operation.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param taskUpdateExec
     *        Vector of structures used to pass the new values to execution data attributes like
     *        actual start date, actual finish date, percent complete, status, work complete and
     *        work remaining.
     *
     * @return
     *         The modified data.
     *         <br>
     *         <br>
     *         Following are some possible errors returned:
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;230067&nbsp;&nbsp;&nbsp;&nbsp;The workflow attributes cannot
     *         be updated since the workflow process has started.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;230076 &nbsp;&nbsp;&nbsp;&nbsp;The actual start date cannot
     *         be set beyond the current time as per the <b>SM_EnforceActualDatesBeforeNow</b>
     *         preference settings.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;230077 &nbsp;&nbsp;&nbsp;&nbsp;The actual finish date cannot
     *         be set beyond the current time as per the <b>SM_EnforceActualDatesBeforeNow</b> preference
     *         settings.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;230078&nbsp;&nbsp;&nbsp;&nbsp;The percentage complete cannot
     *         be more than 100.
     *         <br>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData updateTaskExecution ( const std::vector< Teamcenter::Services::Projectmanagement::_2011_06::Schedulemanagement::TaskExecUpdate >& taskUpdateExec ) = 0;


protected:
    virtual ~Schedulemanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/projectmanagement/ProjectManagement_undef.h>
#endif

