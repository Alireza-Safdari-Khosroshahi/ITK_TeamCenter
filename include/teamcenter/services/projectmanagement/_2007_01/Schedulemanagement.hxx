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

#ifndef TEAMCENTER_SERVICES_PROJECTMANAGEMENT__2007_01_SCHEDULEMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_PROJECTMANAGEMENT__2007_01_SCHEDULEMANAGEMENT_HXX

#include <teamcenter/soa/client/model/SchDeliverable.hxx>
#include <teamcenter/soa/client/model/Schedule.hxx>
#include <teamcenter/soa/client/model/ScheduleTask.hxx>
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
            namespace _2007_01
            {
                class Schedulemanagement;

class TCSOAPROJECTMANAGEMENTSTRONGMNGD_API Schedulemanagement
{
public:

    struct CreateBaselineContainer;
    struct CreateScheduleContainer;
    struct MembershipData;
    struct ScheduleCopyContainer;
    struct ScheduleDeliverableData;
    struct ScheduleObjDeleteContainer;
    struct StringValContainer;
    struct TaskDeliverableData;

    /**
     * The information to create a baseline.
     */
    struct CreateBaselineContainer
    {
        /**
         * The name of the baseline. Valid value- can not be null
         */
        std::string name;
        /**
         * The schedule to baseline. Valid value- tag of the schedule.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Schedule>  schedule;
        /**
         * The baseline to copy from. Valid value - can be null or tag of the schedule
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Schedule>  parentBaseline;
        /**
         * Is the new baseline active?
         */
        bool isActive;
        /**
         * Whether or not to baseline new tasks.
         */
        bool includeNewTasks;
        /**
         * Whether or not to update baselined schedule cost. (Not currently used)
         */
        bool updateScheduleBaselineCost;
        /**
         * A bitmask of which types of tasks to rebaseline (0=none, 1=non-started, 2=non-complete).
         */
        int taskRebaseOption;
    };

    /**
     * The container for a new schedule.
     */
    struct CreateScheduleContainer
    {
        /**
         * The name. Valid value- can not be null.
         */
        std::string name;
        /**
         * The description. Valid value- can be empty string.
         */
        std::string description;
        /**
         * The customer's name. Valid value- can be empty string.
         */
        std::string customerName;
        /**
         * The customer's ID. Valid value- can be empty string.
         */
        std::string customerNumber;
        /**
         * The start date.
         */
        Teamcenter::Soa::Common::DateTime startDate;
        /**
         * The finish date.
         */
        Teamcenter::Soa::Common::DateTime finishDate;
        /**
         * The priority. Valid values are {0-lowest,1-low,2-MediumLow,3-Medium,4-High,5-VeryHigh,6-Highest}
         */
        int priority;
        /**
         * The status. Valid values are { 0-Not started,1-InProgress,2-NeedsAttention,3-Complete,4-Abandoned,5-Late}
         */
        std::string status;
        /**
         * isPubished?
         */
        bool published;
        /**
         * areLinksAllowed?
         */
        bool linksAllowed;
        /**
         * areDatesLinked?
         */
        bool datesLinked;
        /**
         * isPercentLinked?
         */
        bool percentLinked;
        /**
         * isTemplate?
         */
        bool isTemplate;
        /**
         * The schedule type. Valid value (0-Standard)
         */
        int scheduleType;
        /**
         * isPublic?
         */
        bool isPublic;
        /**
         * A collection of additional attributes.(optional)
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2007_01::Schedulemanagement::StringValContainer > stringValueContainer;
    };

    /**
     * The information needed to create a new member in a schedule.
     */
    struct MembershipData
    {
        /**
         * The schedule for the new membership.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Schedule>  schedule;
        /**
         * The resource to add.  (This can be a UserLogin, Group, or Discipline).
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  resource;
        /**
         * The membership level in that schedule.
         */
        int membershipLevel;
    };

    /**
     * The information need to copy a schedule.
     */
    struct ScheduleCopyContainer
    {
        /**
         * The name of the new schedule.
         */
        std::string name;
        /**
         * The tag of the schedule to copy.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Schedule>  scheduleToCopy;
        /**
         * Flag to indicate whether or not to reset the tasks' execution data (%, status, work
         * complete, etc).
         */
        bool resetWork;
        /**
         * Flag to indicate whether or not to copy baselines.
         */
        bool copyBaselines;
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
    };

    /**
     * An object to delete.
     */
    struct ScheduleObjDeleteContainer
    {
        /**
         * A tag to the object to be deleted.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  object;
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
         * An integer to help determine the type of object represented by the value.
         */
        int type;
    };

    /**
     * The input information for a single task deliverable.
     */
    struct TaskDeliverableData
    {
        /**
         * The task which will contain this delievable.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ScheduleTask>  scheduleTask;
        /**
         * The ScheduleDeliverable to reference.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::SchDeliverable>  scheduleDeliverable;
        /**
         * The submit type  (3=Don't submit, 0=submit as target, 1=submit as reference).
         */
        int submitType;
    };




    /**
     * Add resources to the schedule with given membership levels.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param membershipData
     *        A collection of MembershipData structures to be added.
     *
     * @return
     *         The references to the created membership objects, partial errors and failures are
     *         updated and returned through this object.
     *
     * @deprecated
     *         As of Teamcenter 8.2, use the addMemberships operation from the the _2008_06 namespace.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 8.2, use the addMemberships operation from the the _2008_06 namespace."))
#endif
    virtual Teamcenter::Soa::Client::ServiceData addMemberships ( const std::vector< Teamcenter::Services::Projectmanagement::_2007_01::Schedulemanagement::MembershipData >& membershipData ) = 0;

    /**
     * This operation baselines or re-baselines a task's data in the context of an existing
     * schedule baseline. The updated objects or added task baselines are returned back
     * in the service data of the response. This operation throws a <code>ServiceException</code>
     * in case of failure. The service exception will contain the error message of the failure.
     * Additional errors will be returned in the list of partial errors in the <code>ServiceData</code>.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param scheduleTasks
     *        A list of tasks to rebaseline.
     *
     * @param scheduleBaseline
     *        The schedule baseline to update.
     *
     * @return
     *         <code>Teamcenter::Soa::Server::ServiceData</code>
     *         <br>
     *         The <b>POMRef</b> for the changed or added task baselines, partial errors, and failures
     *         are updated and returned through this object. If the input parameters are invalid
     *         or if sufficient conditions are not met for performing the baselineTasks operation,
     *         errors are returned.
     *         <br>
     *         <br>
     *         Following are some possible errors returned:
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;230002:&nbsp;&nbsp;&nbsp;&nbsp;One or more parameters passed
     *         to the function were invalid. See system
     *         <br>
     *         log details.
     *         <br>
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Soa::Client::ServiceData baselineTasks ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ScheduleTask>  >& scheduleTasks,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Schedule>  scheduleBaseline ) = 0;

    /**
     * Makes a deep copy of the schedule with options to reset work and copy existing baselines.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param scheduleCopyContainer
     *        A collection of ScheduleCopyContainer structures.
     *
     * @return
     *         POMRefs to the new schedules, partial errors and failures are updated and returned
     *         through this object.
     *
     * @deprecated
     *         As of tc2007.1, use the copySchedules operation from the _2007_06 namespace.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of tc2007.1, use the copySchedules operation from the _2007_06 namespace."))
#endif
    virtual Teamcenter::Soa::Client::ServiceData copySchedules ( const std::vector< Teamcenter::Services::Projectmanagement::_2007_01::Schedulemanagement::ScheduleCopyContainer >& scheduleCopyContainer ) = 0;

    /**
     * This operation creates a new schedule baselines possibly based on a previous baseline.
     * <br>
     * The created objects are returned back in the <code>ServiceData</code> of the response.The
     * information required to create new baseline is passed as input parameter to the operation
     * through <code>CreateBaselineContainer</code> data structure.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param createBaselineContainer
     *        A collection of <code>CreateBaselineContainer</code> structures. This structure contains
     *        the information to create new schedule baseline.
     *
     * @return
     *         The new baseline objects, partial errors and failures are updated and returned through
     *         <code>ServiceData</code>. If the input parameters are invalid or if sufficient conditions
     *         are not met for performing the <code>createNewBaselines</code> operation,errors are
     *         returned.
     *         <br>
     *         Following are some possible errors returned:
     *         <br>
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;230033:&nbsp;&nbsp;&nbsp;&nbsp;A Schedule Baseline with
     *         the given name already exists.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;230034:&nbsp;&nbsp;&nbsp;&nbsp;A Schedule Baseline without
     *         a Schedule.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;230045: You do not have the correct access privileges to
     *         modify one or more objects.
     *         <br>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData createNewBaselines ( const std::vector< Teamcenter::Services::Projectmanagement::_2007_01::Schedulemanagement::CreateBaselineContainer >& createBaselineContainer ) = 0;

    /**
     * Create new scheduling object based on the initial user's request to the Application
     * Interface.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param newSchedules
     *        A collection of CreateScheduleContainer structures.
     *
     * @return
     *         The references to the updated object.
     *
     * @deprecated
     *         As of Teamcenter 8.2, use the createSchedule operation from the _2008_06 namespace.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 8.2, use the createSchedule operation from the _2008_06 namespace."))
#endif
    virtual Teamcenter::Soa::Client::ServiceData createSchedule ( const std::vector< Teamcenter::Services::Projectmanagement::_2007_01::Schedulemanagement::CreateScheduleContainer >& newSchedules ) = 0;

    /**
     * Creates new schedule deliverable templates and relates them to the schedule.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param scheduleDeliverableData
     *        A collection of ScheduleDeliverableData structures.
     *
     * @return
     *         The references to the created ScheduleDeliverable objects, partial errors and failures
     *         are updated and returned through this object.
     *
     * @deprecated
     *         As of Teamcenter 8.2, use the createScheduleDeliverableTemplates operation from the
     *         _2008_06 namespace.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 8.2, use the createScheduleDeliverableTemplates operation from the _2008_06 namespace."))
#endif
    virtual Teamcenter::Soa::Client::ServiceData createScheduleDeliverableTemplates ( const std::vector< Teamcenter::Services::Projectmanagement::_2007_01::Schedulemanagement::ScheduleDeliverableData >& scheduleDeliverableData ) = 0;

    /**
     * Creates new task deliverable templates and relates them to the task.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param taskDeliverableData
     *        A collection of TaskDeliverableData structures.
     *
     * @return
     *         The references to the created TaskDeliverable objects, partial errors and failures
     *         are updated and returned through this object.
     *
     * @deprecated
     *         As of Teamcenter 8.2, use the createTaskDeliverableTemplates operation from the _2007_06
     *         namespace.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 8.2, use the createTaskDeliverableTemplates operation from the _2007_06 namespace."))
#endif
    virtual Teamcenter::Soa::Client::ServiceData createTaskDeliverableTemplates ( const std::vector< Teamcenter::Services::Projectmanagement::_2007_01::Schedulemanagement::TaskDeliverableData >& taskDeliverableData ) = 0;

    /**
     * The operation is used to delete a scheduling object which cannot be deleted by <code>deleteObjects</code>
     * operation. After the operation is called, the business logic determines whether to
     * delete the scheduling objects by examining the schedule preservation rule, <b>SM_PREVENT_DELETE_STATE</b>.
     * The <b>SM_PREVENT_DELETE_STATE</b> rule is optional and the system admin can remove
     * the rule from the system or set its value to an empty list. But if the rule is in
     * the system and set to any status or statuses then the value of the rule would be
     * applied.
     * <br>
     * The scheduling objects are <b>Schedule</b>, <b>ScheduleTask</b>, <b>TaskDependency</b>
     * and <b>ResourceAssignment</b>.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param scheduleObjDeleteContainer
     *        A collection of ScheduleObjDeleteContainer structures.
     *
     * @return
     *         The references to objects which were deleted,partial errors and failures are updated
     *         and returned through this object.
     *         <br>
     *         <br>
     *         Errors returned
     *         <br>
     *         <br>
     *         301150 - The <b>Schedule Task</b> "%1$" cannot be deleted because the <b>Schedule</b>
     *         "%2$" is in the following state: %3$.
     *         <br>
     *         301155 - The <b>Schedule Task</b> "%1$" cannot be deleted because the <b>Summary
     *         Task</b> "%2$" is in the following state: %3$.
     *         <br>
     *         <br>
     *         Throws:
     *         <br>
     *         The operation would throw service exception error if the schedule preservation rule
     *         is violated.
     *         <br>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData deleteSchedulingObjects ( const std::vector< Teamcenter::Services::Projectmanagement::_2007_01::Schedulemanagement::ScheduleObjDeleteContainer >& scheduleObjDeleteContainer ) = 0;


protected:
    virtual ~Schedulemanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/projectmanagement/ProjectManagement_undef.h>
#endif

