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

#ifndef TEAMCENTER_SERVICES_PROJECTMANAGEMENT_SCHEDULEMANAGEMENTSERVICE_HXX
#define TEAMCENTER_SERVICES_PROJECTMANAGEMENT_SCHEDULEMANAGEMENTSERVICE_HXX

#include <teamcenter/services/projectmanagement/_2007_01/Schedulemanagement.hxx>
#include <teamcenter/services/projectmanagement/_2007_06/Schedulemanagement.hxx>
#include <teamcenter/services/projectmanagement/_2007_12/Schedulemanagement.hxx>
#include <teamcenter/services/projectmanagement/_2008_06/Schedulemanagement.hxx>
#include <teamcenter/services/projectmanagement/_2009_10/Schedulemanagement.hxx>
#include <teamcenter/services/projectmanagement/_2011_02/Schedulemanagement.hxx>
#include <teamcenter/services/projectmanagement/_2011_06/Schedulemanagement.hxx>
#include <teamcenter/services/projectmanagement/_2011_12/Schedulemanagement.hxx>
#include <teamcenter/services/projectmanagement/_2012_02/Schedulemanagement.hxx>
#include <teamcenter/services/projectmanagement/_2012_09/Schedulemanagement.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/projectmanagement/ProjectManagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Projectmanagement
        {
            class SchedulemanagementService;

/**
 * The <code>ScheduleManagement</code> service provides a wide variety of operations
 * to for schedule management.  There are operations to support managing schedule, tasks,
 * assignments, dependencies, notification rules, and more.  There are also various
 * operations to support the most common functionalities needed in schedule management.
 * <br>
 * The <code>ScheduleManagement</code> service can be used for supporting following
 * use-cases:
 * <br>
 * <ul>
 * <li type="disc">Adding memberships to schedule
 * </li>
 * <li type="disc">Baselining to tasks
 * </li>
 * <li type="disc">Copying schedules
 * </li>
 * <li type="disc">Create new baselines
 * </li>
 * <li type="disc">Creating schedule deliverable templates
 * </li>
 * <li type="disc">Creating task deliverable templates
 * </li>
 * <li type="disc">Creating, updating, deleting and retrieving schedules
 * </li>
 * <li type="disc">Creating, updating, deleting, and retrieving notification rules
 * </li>
 * <li type="disc">Updating task cost data
 * </li>
 * <li type="disc">Creating, updating, and deleting tasks
 * </li>
 * <li type="disc">Special paste schedule tasks
 * </li>
 * <li type="disc">Creating proxy tasks
 * </li>
 * <li type="disc">Loading specified schedules
 * </li>
 * <li type="disc">Managing schedule locks
 * </li>
 * <li type="disc">Refreshing a schedule
 * </li>
 * <li type="disc">Creating, updating, and deleting dependencies
 * </li>
 * <li type="disc">Assigning, updating, and deleting resources
 * </li>
 * <li type="disc">Finding critical path tasks
 * </li>
 * <li type="disc">Launching schedule workflow
 * </li>
 * <li type="disc">Moving tasks within a schedule
 * </li>
 * <li type="disc">Shifting the schedule backward or forward
 * </li>
 * <li type="disc">Claiming an assignment
 * </li>
 * </ul>
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoaprojectmanagementstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoaprojectmanagementtypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOAPROJECTMANAGEMENTSTRONGMNGD_API SchedulemanagementService
    : public Teamcenter::Services::Projectmanagement::_2007_01::Schedulemanagement,
             public Teamcenter::Services::Projectmanagement::_2007_06::Schedulemanagement,
             public Teamcenter::Services::Projectmanagement::_2007_12::Schedulemanagement,
             public Teamcenter::Services::Projectmanagement::_2008_06::Schedulemanagement,
             public Teamcenter::Services::Projectmanagement::_2009_10::Schedulemanagement,
             public Teamcenter::Services::Projectmanagement::_2011_02::Schedulemanagement,
             public Teamcenter::Services::Projectmanagement::_2011_06::Schedulemanagement,
             public Teamcenter::Services::Projectmanagement::_2011_12::Schedulemanagement,
             public Teamcenter::Services::Projectmanagement::_2012_02::Schedulemanagement,
             public Teamcenter::Services::Projectmanagement::_2012_09::Schedulemanagement
{
public:
    static SchedulemanagementService* getService( Teamcenter::Soa::Client::Connection* );


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

    /**
     * Makes a deep copy of the schedule with options to reset work and copy existing baselines.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param scheduleCopyContainer
     *        A collection of ScheduleCopyOptionsContainer structures.
     *
     * @return
     *         It contains ScheduleCopyResponse structures partial errors and failures are also
     *         updated and returned through ServiceData of this object.
     *
     * @deprecated
     *         As of Teamcenter 8.2, use the copySchedules operation from the _2008_06 namespace.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 8.2, use the copySchedules operation from the _2008_06 namespace."))
#endif
    virtual Teamcenter::Services::Projectmanagement::_2007_06::Schedulemanagement::MultiScheduleCopyResponse copySchedules ( const std::vector< Teamcenter::Services::Projectmanagement::_2007_06::Schedulemanagement::ScheduleCopyOptionsContainer >& scheduleCopyContainer ) = 0;

    /**
     * Creates a list of notification rules for <b>Schedule</b> or <b>ScheduleTask</b> based
     * on the notifications container. You use notifications to notify individuals, including
     * yourself, of important events associated with selected objects. <b>Notifications</b>
     * utilize <b>Teamcenter</b> mail and the <b>Subscription Manager</b>. To receive notifications
     * and subscriptions, a system administrator must set the value of the <b>Mail_server_name
     * preferenc</b>e to a name of a valid mail server (this task needs only to be performed
     * once). The e-mail address in the <b>Person</b> object for every user that's expected
     * to receive a notification.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param notificationsContainers
     *        A collection of NotificationRuleContainers.
     *
     * @return
     *         The <code>ServiceData</code> which contains references to the created and updated
     *         objects.
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Soa::Client::ServiceData createOrUpdateNotificationRules ( const std::vector< Teamcenter::Services::Projectmanagement::_2007_06::Schedulemanagement::NotificationRuleContainer >& notificationsContainers ) = 0;

    /**
     * Creates new task deliverable template and relates them to the task. This is done
     * by going through each deliverable, checks if the user has write access on the specified
     * task, and then checking if the task deliverable already exists for the task.  If
     * it does not exist it will create an instance of the task deliverable and add to the
     * list of task deliverables.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param taskDeliverableData
     *        A collection of <code>TaskDeliverableContainer</code> structures that contain the
     *        schedule task, the schedule deliverable, and the submit type.
     *
     * @return
     *         The references to the created <b>TaskDeliverable</b> objects,partial errors and failures
     *         are also
     *         <br>
     *         updated and returned through <code>ServiceData</code> of this object.
     *         <br>
     *         <br>
     *         Throws:
     *         <br>
     *         SCHMGT_no_privilege_to_modify_object&nbsp;&nbsp;&nbsp;&nbsp;User doesn't privilage
     *         to modify task.
     *         <br>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData createTaskDeliverableTemplates ( const std::vector< Teamcenter::Services::Projectmanagement::_2007_06::Schedulemanagement::TaskDeliverableContainer >& taskDeliverableData ) = 0;

    /**
     * Delete notification rules for <b>Schedule</b> or <b>ScheduleTask</b> based on the
     * contents of the delete notifications container. After deleting the notification will
     * rule, the users attached to that rule will not receive any more notifications for
     * that specific action.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param notificationRuleContainer
     *        A collection of DeleteNotificationRuleContainers.
     *
     * @return
     *         The reference to the tag of the deleted objects.
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Soa::Client::ServiceData deleteNotificationRules ( const std::vector< Teamcenter::Services::Projectmanagement::_2007_06::Schedulemanagement::DeleteNotificationRuleContainer >& notificationRuleContainer ) = 0;

    /**
     * Get a list of notification rules for <b>Schedule</b> or <b>ScheduleTask</b> based
     * on the notifications container. Use notifications to notify individuals, including
     * yourself, of important events associated with selected objects. Notifications utilize
     * Teamcenter mail and the<b> Subscription Manager</b>. To receive notifications and
     * subscriptions, a system administrator must set the value of the <b>Mail_server_name
     * preference</b> to a name of a valid mail server (this task needs only to be performed
     * once). The e-mail address in the <b>Person</b> object for every user that's expected
     * to receive a notification.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param notificationRuleContainer
     *        A collection of <code>GetNotificationRuleContainers</code>.
     *        <br>
     *        <br>
     *        <code>NotificationRuleContainer
     *        <br>
     *        struct NotificationRuleContainer
     *        <br>
     *        {
     *        <br>
     *        BusinessObjectRef<Teamcenter::BusinessObject> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;target
     *        <br>
     *        BusinessObjectRef<Teamcenter::BusinessObject> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;subscriber
     *        <br>
     *        }</code>
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;<code>target</code>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
     *        The tag of a schedule or task
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;<code>subscriber</code>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The
     *        subscriber for this notification. It is the target object in the case of a notification
     *        or a User object in the case of a subscription.
     *        <br>
     *
     * @return
     *         A list of the notification rules attached to the schedule or schedule task. If there
     *         are no notification rules attached, the return will be an empty array.
     *         <br>
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Projectmanagement::_2007_06::Schedulemanagement::NotificationRulesList getNotificationRules ( const std::vector< Teamcenter::Services::Projectmanagement::_2007_06::Schedulemanagement::GetNotificationRuleContainer >& notificationRuleContainer ) = 0;

    /**
     * Calculates the demand profile data for a schedule based on the initial input request
     * to the Application Interface..
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param requests
     *        A collection of <code>DemandProfileRequest</code>'s to calculate.
     *        <br>
     *        <code>DemandProfileRequest</code>
     *        <br>
     *        <code>struct DemandProfileRequest
     *        <br>
     *        {
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;BusinessObjectRef<Teamcenter::Schedule> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;schedule
     *        <br>
     *        string &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;startPeriod
     *        <br>
     *        string &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;endPeriod
     *        <br>
     *        int&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;monthsInPeriod
     *        <br>
     *        string&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;currency
     *        <br>
     *        }</code>
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;<code>schedule</code>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
     *        Input schedule of which demand profile data will be calculated
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;<code>startPeriod</code>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
     *        Start of schedule Period to calculate data (MM-YYYY).
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;<code>endPeriod</code>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
     *        End of schedule Period to calculate data (MM-YYYY).
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;<code>monthsInPeriod</code>   Number of months in the period.
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;<code>currency</code> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
     *        Currency to calculate the cost (ISO 4217). (Not currently used)
     *        <br>
     *
     * @return
     *         The demand profile information and errors. The information includes the schedule,
     *         start period, end period, and months in period.
     *
     */
    virtual Teamcenter::Services::Projectmanagement::_2007_12::Schedulemanagement::DemandProfileResponses getDemandProfile ( const std::vector< Teamcenter::Services::Projectmanagement::_2007_12::Schedulemanagement::DemandProfileRequest >& requests ) = 0;

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

    /**
     * Not Implemented.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param scheduleModifyContainers
     *        Not Implemented
     *
     * @return
     *         Not Implemented
     *
     *
     * @exception ServiceException
     *           None
     * @deprecated
     *         As of Teamcenter 8.1, not Implemented
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 8.1, not Implemented"))
#endif
    virtual Teamcenter::Soa::Client::ServiceData modifySchedules ( const std::vector< Teamcenter::Services::Projectmanagement::_2009_10::Schedulemanagement::ScheduleModifyContainer >& scheduleModifyContainers ) = 0;

    /**
     * Updates Schedule Tasks. Note: You must use PERSIST for the ServiceType and ScheduleTaskUpdate
     * for the operationType inside the GenericAttributesContainers which are passed.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param updates
     *        vector of task updates
     *
     * @param scheduleUid
     *        Vector of scheduleUids. For batch updates, the scheduleUid attribute in the generic
     *        container must be provided.
     *
     * @return
     *         GenericResponseContainer structure: contains service data and updated schedule task
     *
     *
     * @exception ServiceException
     *           None
     * @deprecated
     *         As of Teamcenter 9.1, use the updateTasks operation from the _2012_02 namespace.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 9.1, use the updateTasks operation from the _2012_02 namespace."))
#endif
    virtual Teamcenter::Services::Projectmanagement::_2009_10::Schedulemanagement::GenericResponseContainer updateTasks ( const std::vector< Teamcenter::Services::Projectmanagement::_2009_10::Schedulemanagement::GenericAttributesContainer >& updates,
        const std::vector< std::string >& scheduleUid ) = 0;

    /**
     * Gets the selected Schedule and their tasks and paste it to target task as specified
     * by the options.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param copyContainer
     *        Container which consists of list of <code>FromSchedule</code> and a <code>ToSchedule</code>
     *
     * @return
     *         <code>MultiSchSpecialCopyResponse</code> is a container which contains list of created
     *         tasks, list of modified tasks, list of updated members, list of created deliverables,
     *         list of dependencies, list of created assignments and <code>ServiceData</code>.
     *         <br>
     *         Following are few errors returned by this operation,
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;230002 &nbsp;&nbsp;&nbsp;&nbsp;One or more parameters passed
     *         to the function  were invalid.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;230010 &nbsp;&nbsp;&nbsp;&nbsp;The task has an invalid parent
     *         attribute.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;230039 &nbsp;&nbsp;&nbsp;&nbsp;Copying of one or more tasks
     *         failed.
     *         <br>
     *         <br>
     *
     */
    virtual Teamcenter::Services::Projectmanagement::_2011_02::Schedulemanagement::MultiSchSpecialCopyResponse specialPasteScheduleTasks ( const Teamcenter::Services::Projectmanagement::_2011_02::Schedulemanagement::SpecialCopyContainer&  copyContainer ) = 0;

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

    /**
     * Creates Dependencies between tasks in the same schedule, between a task and a proxy
     * task in the same schedule, or between a tasks in different schedules (but in the
     * same master schedule).  It returns the created dependencies, created proxy tasks
     * (if any), and the ob
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param schedule
     *        The schedule where these dependencies will exist.
     *
     * @param newDependencies
     *        The new dependencies
     *
     * @return
     *         The created dependencies
     *
     *
     * @exception ServiceException
     *           None
     * @deprecated
     *         As of Teamcenter 9.1, use the createDependencies operation fro mthe _2012_02 namespace.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 9.1, use the createDependencies operation fro mthe _2012_02 namespace."))
#endif
    virtual Teamcenter::Services::Projectmanagement::_2011_12::Schedulemanagement::CreatedDependenciesContainer createDependencies ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Schedule>  schedule,
        const std::vector< Teamcenter::Services::Projectmanagement::_2011_12::Schedulemanagement::DependencyCreateContainer >& newDependencies ) = 0;

    /**
     * This operation assigns resources (<b>Users</b> and <b>Disciplines</b>) to tasks in
     * a given schedule. The operation returns the <code>CreatedObjectsContainer</code>
     * which will have information of created assignments, updated tasks and service data.The
     * operation throws a <code>ServiceException</code> in case of failure. The service
     * exception will contain the error message of the failure.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param schedule
     *        The schedule containing the tasks to be assigned.
     *
     * @param createAssignments
     *        <br>
     *        Each object in the array contains the following -
     *        <br>
     *        <b>User</b> to be assigned. It will be <b>NULL</b> in case <b>Discipline</b> being
     *        assigned. Task to which the assignment needs to be done. This is required input.
     *        <br>
     *        Percentage of the resource load. This is a required input. Defaults to 0 if not specified.
     *        <b>Discipline</b> of the assignee or the discipline itself which needs to be assigned
     *        (user is null in this case).
     *        <br>
     *
     * @return
     *         It returns the created assignments as well as objects affected by the change.
     *
     *
     * @exception ServiceException
     *           None
     * @deprecated
     *         As of Teamcenter 10, use the assignResources operation from the _2012_09 namespace.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 10, use the assignResources operation from the _2012_09 namespace."))
#endif
    virtual Teamcenter::Services::Projectmanagement::_2012_02::Schedulemanagement::CreatedObjectsContainer assignResources ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Schedule>  schedule,
        const std::vector< Teamcenter::Services::Projectmanagement::_2012_02::Schedulemanagement::AssignmentCreateContainer >& createAssignments ) = 0;

    /**
     * Creates <code>Dependencies</code> between tasks in the same schedule, between a task
     * and a proxy task in the same schedule, or between a tasks in different schedules
     * (but in the same master schedule).  It returns the created dependencies, created
     * proxy tasks (if any), and the objects affected by this change. This operation throws
     * a <code>ServiceException</code> in case of failure. The service exception will contain
     * the error message of the failure. Additional errors will be returned in the list
     * of partial errors in the <code>ServiceData</code>.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param schedule
     *        The schedule containing both the predecessor and successor tasks
     *
     * @param newDependencies
     *        Vector of <code>DependencyCreateContainer</code> structure(required input). Each
     *        object in the vector contains the following -
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;<b>Dependency</b> type - <code>0-FS, 1-FF, 2-SS, 3-SF.</code>
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;The lag time in minutes (480 ~ 1 day).
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;The predecessor task for the dependency.
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;The successor task for the dependency.
     *        <br>
     *
     * @return
     *         This operation return vector of <code>CreatedDependenciesContainer</code> structure.
     *         <br>
     *         <code>Teamcenter::Soa::ProjectManagement::_2012_02::ScheduleManagement::CreatedDependenciesContainer</code>
     *         <br>
     *         Following are the few possible error codes returned from this operation:
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;301103&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Task
     *         date out of schedule boundaries
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;301136&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Invalid
     *         dependency type
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;301082&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Invalid
     *         successor or predecessor task.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;301108&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Dependency
     *         already exists
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;301106&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Trying
     *         to create circular dependency.
     *         <br>
     *         Additional errors will be returned in the list of partial errors in the ServiceData.
     *         These errors may not be due to the business logic validation, but server errors which
     *         deal with input data integrity (for eg., invalid schedule tag, task not present etc)
     *         <br>
     *         Throws:
     *         <br>
     *         <code>com.teamcenter.schemas.soa._2006_03.exceptions.ServiceException</code>
     *         <br>
     *
     *
     * @exception ServiceException
     *           None
     */
    virtual Teamcenter::Services::Projectmanagement::_2012_02::Schedulemanagement::CreatedDependenciesContainer createDependencies ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Schedule>  schedule,
        const std::vector< Teamcenter::Services::Projectmanagement::_2012_02::Schedulemanagement::DependencyCreateContainer >& newDependencies ) = 0;

    /**
     * Creates the specified tasks in a given schedule. The information needed to create
     * task are specified in the <code>TaskCreateContainer</code> structure. It returns
     * <code>CreatedObjectsContainer</code> which will have information of created tasks,
     * updated tasks and <code>ServiceData</code>. Throws a <code>ServiceException</code>
     * in case of failure. The service exception will contain the error message of the failure.
     * Additional errors will be returned in the list of partial errors in the <code>ServiceData</code>.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param schedule
     *        The schedule in which to create the tasks.
     *
     * @param createContainers
     *        Vector of <code>TaskCreateContainer</code> structures. Each &nbsp;&nbsp;&nbsp;&nbsp;<code>TaskCreateContainer</code>
     *        structure holds information needed to create a single schedule task.
     *        <br>
     *
     * @return
     *         <code>CreatedObjectsContainer</code> is a data structure which holds the created
     *         schedule task objects, the tasks affected by the creation and <code>ServiceData</code>
     *         which is used to return sets of <b>Teamcenter</b> data model object from a service
     *         request.
     *         <br>
     *         <br>
     *         Following are some possible errors returned:
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;230005 &nbsp;&nbsp;&nbsp;&nbsp;A Schedule Task with this
     *         ID already exists.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;230010&nbsp;&nbsp;&nbsp;&nbsp;The task has an invalid parent
     *         attribute.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;230038 &nbsp;&nbsp;&nbsp;&nbsp;Creation of one or more tasks
     *         failed.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;301097 &nbsp;&nbsp;&nbsp;&nbsp;The Schedule Task start date
     *         is before the Schedule start date.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;301098 &nbsp;&nbsp;&nbsp;&nbsp;The Schedule Task finish
     *         date is after the Schedule finish date.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;301114&nbsp;&nbsp;&nbsp;&nbsp;The Schedule task name is
     *         too long.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;301115&nbsp;&nbsp;&nbsp;&nbsp;The Schedule task description
     *         is too long.
     *         <br>
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Projectmanagement::_2012_02::Schedulemanagement::CreatedObjectsContainer createTasks ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Schedule>  schedule,
        const std::vector< Teamcenter::Services::Projectmanagement::_2012_02::Schedulemanagement::TaskCreateContainer >& createContainers ) = 0;

    /**
     * This operation deletes resource assignments from the tasks in the given schedule.
     * It takes schedule from which assignments is to be deleted and array of resource assignments
     * to be deleted as input.
     * <br>
     * The deleted resource assignment objects are returned in the <code>deletedObjects</code>
     * of the <code>ServiceData</code>. Operation throws a <code>ServiceException</code>
     * in case of failure. The service exception will contain the error message of the failure.
     * Additional errors will be returned in the list of partial errors in the <code>ServiceData</code>.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param schedule
     *        The schedule containing the assignments to be deleted.
     *
     * @param assignmentDeletes
     *        Vector of <b>ResourceAssignment</b>. Each object in the vector represents a <b>ResourceAssignment</b>
     *        type object which is to be deleted from a given schedule (required input)
     *
     * @return
     *         <code>Teamcenter::Soa::Server::ServiceData</code>
     *         <br>
     *         <code>ServiceData</code> will hold deleted assignment object or partial errors in
     *         case of operation failure.
     *         <br>
     *         <br>
     *         Following are the few possible error codes returned from this operation:
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;301133&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Invalid
     *         assignment. This indicates stale data assignments which have already been deleted
     *         or just bad input.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;301003&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Invalid
     *         schedule. Schedule already deleted or bad input.
     *         <br>
     *         <br>
     *         Additional errors will be returned in the list of partial errors in the ServiceData.
     *         These errors may not be due to the business logic validation, but server errors which
     *         deal with input data integrity (for eg., invalid schedule tag, task not present etc).
     *         <br>
     *         <br>
     *         Throws:
     *         <br>
     *         com.teamcenter.schemas.soa._2006_03.exceptions.ServiceException
     *         <br>
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Soa::Client::ServiceData deleteAssignments ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Schedule>  schedule,
        const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ResourceAssignment>  >& assignmentDeletes ) = 0;

    /**
     * This operation deletes the dependencies between the tasks in a given <b>Schedule</b>.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param schedule
     *        The schedule containing the assignments to be deleted.
     *
     * @param dependencyDeletes
     *        The dependencies to be deleted.
     *
     * @return
     *         Deleted dependencies objects will be present in <code>ServiceData</code>.
     *         <br>
     *         The operation returns service data which will have information of deleted objects.
     *         The operation throws a <code>ServiceException</code> in case of failure. The service
     *         exception will contain the error message of the failure. Additional errors will be
     *         returned in the list of partial errors in the <code>ServiceData</code>.
     *         <br>
     *         <br>
     *         Throws:
     *         <br>
     *         <code>com.teamcenter.schemas.soa._2006_03.exceptions.ServiceException</code>
     *         <br>
     *         <br>
     *         Business Errors given by the operation -
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;Invalid schedule.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;Invalid dependency object.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;Dependency does not exist.
     *         <br>
     *         Additional errors will be returned in the list of partial errors in the <code>ServiceData</code>.
     *         These errors may not be due to the business logic validation, but server errors which
     *         deal with input data integrity (for eg., invalid schedule tag, task not present etc)
     *         <br>
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Soa::Client::ServiceData deleteDependencies ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Schedule>  schedule,
        const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TaskDependency>  >& dependencyDeletes ) = 0;

    /**
     * Deletes the requested tasks along with the sub tasks, assignments, dependencies,
     * and task deliverables.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param schedule
     *        The schedule containing the tasks to delete.
     *
     * @param deleteTasks
     *        The tasks or proxy tasks to be deleted.
     *
     * @return
     *         <code>DeleteTaskContainer</code>
     *         <br>
     *         <code>DeleteTaskContainer</code> is a data structure which holds the orphaned tasks,
     *         tasks updated due to delete and <code>ServiceData</code> which is used to return
     *         sets of Teamcenter data model object from a service request.
     *         <br>
     *         <br>
     *         <code>struct DeleteTaskContainer
     *         <br>
     *         {
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp; std::vector> orphaned;
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp; std::vector> updated;
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp; Teamcenter::Soa::Server::ServiceData serviceData;
     *         <br>
     *         }</code>;
     *         <br>
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;<code>orphaned</code>&nbsp;&nbsp;&nbsp;&nbsp;Tasks which
     *         were orphaned(as they could not be deleted).Orphaned task are those which are removed
     *         from schedule structure but not deleted from system due to some error. User can use
     *         manage orphaned task dialog to manage these orphaned tasks.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;<code>updated</code>&nbsp;&nbsp;&nbsp;&nbsp;Tasks updated
     *         due to the delete.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;<code>serviceData</code>&nbsp;&nbsp;&nbsp;&nbsp;The service
     *         data.
     *         <br>
     *         <br>
     *         Following are few sample error codes returned from this operation,
     *         <br>
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;230008 &nbsp;&nbsp;&nbsp;&nbsp;One or more tasks could not
     *         be deleted. See system log for details.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;230035 &nbsp;&nbsp;&nbsp;&nbsp;You do not have the correct
     *         access privileges to delete one or more objects.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;230087 &nbsp;&nbsp;&nbsp;&nbsp;Only orphan tasks can be
     *         deleted.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;301001 &nbsp;&nbsp;&nbsp;&nbsp;A scheduling object of type
     *         '%1$' could not be deleted.
     *         <br>
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Projectmanagement::_2012_02::Schedulemanagement::DeleteTaskContainer deleteTasks ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Schedule>  schedule,
        const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  >& deleteTasks ) = 0;

    /**
     * This operation finds and returns the tasks on the critical path of the schedule.
     * The critical path is the task or tasks that would likely affect the last task in
     * the schedule if they were completed late. The critical path is calculated by determining
     * the last task in the project (time wise). Any task where a slip would delay the last
     * task in the project is on the critical path. Tasks linked by dependencies have a
     * longer critical path (chain of tasks). The tasks on the critical path with the longest
     * sequence of dependent tasks merit the most attention to on-time completion in order
     * to avoid delays.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param schedule
     *        The schedule where the critical path is being calculated.
     *
     * @return
     *         Returns a list of tasks on the critical path contained in the <code>CriticalTasksContainer</code>.
     *         <br>
     *         No specific business errors are returned by the operation. Errors that can be returned
     *         will be the generic Teamcenter errors such as invalid schedule etc.
     *         <br>
     *         Structures:
     *         <br>
     *         <br>
     *         <code>CriticalTasksContainer</code>
     *         <br>
     *         <br>
     *         <code>struct CriticalTasksContainer
     *         <br>
     *         {
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;vector< BusinessObjectRef<Teamcenter::ScheduleTask> >  &nbsp;&nbsp;&nbsp;&nbsp;tasks
     *         <br>
     *         vector< BusinessObjectRef<Teamcenter::Fnd0ProxyTask> > &nbsp;&nbsp;&nbsp;&nbsp;proxyTasks
     *         <br>
     *         ServiceData &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;serviceData&nbsp;&nbsp;&nbsp;&nbsp;
     *         <br>
     *         }</code>
     *         <br>
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;<code>tasks</code>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
     *         The tasks on the critical path.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;<code>proxyTasks</code>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The
     *         proxy tasks on the critical path.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;<code>serviceData</code>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The
     *         service data.
     *         <br>
     *         <br>
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Projectmanagement::_2012_02::Schedulemanagement::CriticalTasksContainer findCriticalPathTasks ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Schedule>  schedule ) = 0;

    /**
     * A <b>Teamcenter</b> schedule  task can be configured in such a way that when certain
     * conditions are
     * <br>
     * met the associated workflow can be initiated. The triggering rules or conditions
     * <br>
     * create a workflow process. If there are updates to the workflow process tasks, a
     * <br>
     * notification is sent to the <b>Teamcenter</b> schedule task so that the schedule
     * task can be
     * <br>
     * updated. This operation launches workflows associated with the tasks .
     * <br>
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param tasks
     *        The tasks associated with the workflows to launch.
     *
     * @return
     *         <code>LaunchedWorkflowContainer</code>&nbsp;&nbsp;&nbsp;&nbsp;A launchedWorkflow
     *         container is returned if call is successful, or throws an exception if failed.
     *         <br>
     *         <br>
     *         Throws:
     *         <br>
     *         Teamcenter::Schemas::Soa::_2006_03::Exceptions::ServiceException
     *         <br>
     *         <br>
     *         Some of the errors returned by the operation
     *         <br>
     *         230099 - Workflows cannot be launched on "Phase" and "Summary" types of tasks.
     *         <br>
     *         230097 - No workflow template is associated with the task.
     *         <br>
     *         230098 - The workflow process on task has already been launched.
     *         <br>
     *         <br>
     *         <code>LaunchedWorkflowContainer</code>
     *         <br>
     *         <code>struct LaunchedWorkflowContainer
     *         <br>
     *         {
     *         <br>
     *         std::vector< BusinessObjectRef<Teamcenter::EPMJob> > launchedWorkflows;
     *         <br>
     *         Teamcenter::Soa::Server::ServiceData serviceData;
     *         <br>
     *         };</code>
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;<code>launchedWorkflows</code>&nbsp;&nbsp;&nbsp;&nbsp;Reference
     *         to launched workflow processes.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;<code>serviceData</code>                       The service
     *         data.
     *         <br>
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Projectmanagement::_2012_02::Schedulemanagement::LaunchedWorkflowContainer launchScheduledWorkflow ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ScheduleTask>  >& tasks ) = 0;

    /**
     * Allow schedule tasks and proxy tasks to be moved to a different location in the task
     * hierarchy.
     * <br>
     * The schedule task move requests are specified in the <code>MoveRequest</code> structure,
     * which store information about schedule task object, its new parent and its new previous
     * sibling. Additional errors during this operation will be returned in the list of
     * partial errors in the <code>ServiceData</code>.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param schedule
     *        The schedule containing the tasks to move.
     *
     * @param moveRequests
     *        The requests to move the tasks as <code>MoveRequest</code> structure &nbsp;&nbsp;&nbsp;&nbsp;which
     *        has information about task, its new parent  and new sibling.
     *        <br>
     *        <br>
     *        <code>struct MoveRequest
     *        <br>
     *        {
     *        <br>
     *        BusinessObjectRef<Teamcenter::WorkspaceObject> task;
     *        <br>
     *        BusinessObjectRef<Teamcenter::ScheduleTask> newParent;
     *        <br>
     *        BusinessObjectRef<Teamcenter::ScheduleTask> prevSibling;
     *        <br>
     *        };</code>
     *        <br>
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;<code>task</code> &nbsp;&nbsp;&nbsp;&nbsp;The task or proxy
     *        task to move.
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;<code>newParent</code> &nbsp;&nbsp;&nbsp;&nbsp;The new parent
     *        for the task.
     *        <br>
     *        &nbsp;&nbsp;&nbsp;&nbsp;<code>prevSibling</code>   The new previous sibling for
     *        the task (or the reference task in the case of a proxy).
     *        <br>
     *
     * @return
     *         Teamcenter::Soa::Server::ServiceData : ServiceData will contain updated tasks or
     *         partial errors if operation fails to move task.
     *         <br>
     *         <br>
     *         Following are the few possible error codes returned form this operation,
     *         <br>
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;230002&nbsp;&nbsp;&nbsp;&nbsp;One or more parameters passed
     *         to the function were invalid.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;230047&nbsp;&nbsp;&nbsp;&nbsp;The schedule summary task
     *         cannot be explicitly moved or deleted.&nbsp;&nbsp;&nbsp;&nbsp;
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;301102&nbsp;&nbsp;&nbsp;&nbsp;Cannot move Schedule Task
     *         with Fixed Constraint.
     *         <br>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData moveTasks ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Schedule>  schedule,
        const std::vector< Teamcenter::Services::Projectmanagement::_2012_02::Schedulemanagement::MoveRequest >& moveRequests ) = 0;

    /**
     * This operation performs the revalidation/rerunning of the business logic on the properties
     * of the schedule and its child objects based on the requested properties flag or ALL.
     * Interactive use of this operation is not recommended.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param schedule
     *        The schedule to be recalculated.
     *
     * @param recalcType
     *        The recalculation type:<code> 0-All, 1-Execution Data, 2-Scheduling Data</code>
     *
     * @param runAsync
     *        Schedule a <b>DispatcherServices</b> job for the recalcuation? <code>TRUE</code>-schedule
     *        a job and return.  <code>FALSE</code>-run full recalculation and return.
     *
     * @return
     *         The modified objects through <code>ServiceData</code>.
     *         <br>
     *         <br>
     *         Throws:
     *         <br>
     *         <code>com.teamcenter.schemas.soa._2006_03.exceptions.ServiceException</code>
     *         <br>
     *         <br>
     *         Following are few error codes returned from this operation,
     *         <br>
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;230002 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;One
     *         or more parameters passed to the function were invalid.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;301004 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The
     *         schedule with uid could not be loaded.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;301113&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Summary
     *         execution data update failed the pre-modification check.
     *         <br>
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Soa::Client::ServiceData recalculateScheduleNonInteractive ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Schedule>  schedule,
        int recalcType,
        bool runAsync ) = 0;

    /**
     * The scale schedule operation allows for the user to scale the schedule based on specified
     * lag time.
     * <br>
     * This operation throws a <code>ServiceException</code> in case of failure. The service
     * exception will contain the error message of the failure. Additional errors will be
     * returned in the list of partial errors in the <code>ServiceData</code>.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param schedule
     *        The schedule to scale.
     *
     * @param scaleFactor
     *        The scaling factor.
     *
     * @param options
     *        The scaling options: <code>scaleType-integer (1-scale work(default), 2-scale duration),
     *        checkState-boolean (true-check task state(default), false-ignore state)</code>
     *
     * @return
     *         <code>Teamcenter::Soa::Server::ServiceData</code>
     *         <br>
     *         This will have all objects updated by scaling or partial exception if operation fails
     *         to scale the schedule.
     *         <br>
     *         Throws:
     *         <br>
     *         com.teamcenter.schemas.soa._2006_03.exceptions.ServiceException
     *         <br>
     *         Errors returned -
     *         <br>
     *         301134 - The scaling factor must be greater than zero.
     *         <br>
     *         301135 - A schedule which contains started tasks cannot be scaled.
     *         <br>
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Soa::Client::ServiceData scaleScheduleNonInteractive ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Schedule>  schedule,
        double scaleFactor,
        const Teamcenter::Services::Projectmanagement::_2011_06::Schedulemanagement::SchMgtOptions&  options ) = 0;

    /**
     * Shifts the schedule forward or backwards to the new provided start/finish date.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param schedule
     *        The schedule to shift.
     *
     * @param newDate
     *        The new date/time to shift to.
     *
     * @param newFinish
     *        Is the <code>newDate</code> a new finish date?  <code>True</code> if it is a new
     *        finish date.  <code>False</code> if it is a new start date.
     *
     * @return
     *         The objects affected by the shift.
     *         <br>
     *         Throws a <code>ServiceException</code> in case of failure. The service exception
     *         will contain the error message of the failure. Additional errors will be returned
     *         in the list of partial errors in the <code>ServiceData</code>
     *         <br>
     *         Some of the errors given by the operation
     *         <br>
     *         230045  - You do not have the correct access privileges to modify one or more objects
     *         <br>
     *         230094  - Shifting of the schedule using a non-interactive way has failed.
     *         <br>
     *         Throws:
     *         <br>
     *         <code>com.teamcenter.schemas.soa._2006_03.exceptions.ServiceException</code>
     *         <br>
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Soa::Client::ServiceData shiftScheduleNonInteractive ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Schedule>  schedule,
        const Teamcenter::Soa::Common::DateTime&  newDate,
        bool newFinish ) = 0;

    /**
     * The operation updates the resource assignments in a given schedule. Only the resource
     * load of the assignment can be updated with this operation. It returns the <code>ServiceData</code>
     * which will have information of updated assignment objects. This operation throws
     * a <code>ServiceException</code> in case of failure. The service exception will contain
     * the error message of the failure. Additional errors will be returned in the list
     * of partial errors in the <code>ServiceData</code>.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param schedule
     *        The schedule in which the assignments are to be updated (Required input).
     *
     * @param assignmentUpdates
     *        Vector of <code>AssignmentUpdateContainer</code> structures. Each <code>AssignmentUpdateContainer</code>
     *        structure holds the assignment which is to be updated along with resource load of
     *        the assignment to be updated (required input).
     *
     * @return
     *         <code>Teamcenter::Soa::Server::ServiceData : ServiceData </code>will contain updated
     *         assignment, updated schedule task or partial exception in case of operation fails
     *         to update ResourceAssignment.
     *         <br>
     *         <br>
     *         Following are the few possible error codes returned from this operation:
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;230037 Invalid resource load.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;230108 Invalid resource assignment object.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;230109 Assignment already exists
     *         <br>
     *         <br>
     *         Additional errors will be returned in the list of partial errors in the <code>ServiceData</code>.
     *         These errors may not be due to the business logic validation, but server errors that
     *         deal with input data integrity (for example, invalid schedule tag, task not present,
     *         etc.).
     *         <br>
     *         Throws:
     *         <br>
     *         <code>com.teamcenter.schemas.soa._2006_03.exceptions.ServiceException</code>
     *         <br>
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Soa::Client::ServiceData updateAssignments ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Schedule>  schedule,
        const std::vector< Teamcenter::Services::Projectmanagement::_2012_02::Schedulemanagement::AssignmentUpdateContainer >& assignmentUpdates ) = 0;

    /**
     * This operation  updates the dependencies in a given schedule. It takes an array of
     * <code>DependencyUpdateContainer</code> objects in which the type of the dependency,
     * and lag time updates can be specified per dependency object.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param schedule
     *        The schedule containing the dependencies to be updated.
     *
     * @param dependencyUpdates
     *        The dependencies to update.
     *
     * @return
     *         The operation returns the <code>ServiceData</code> which will have information of
     *         updated dependency objects. The operation throws a <code>ServiceException</code>
     *         in case of failure. The service exception will contain the error message of the failure.
     *         <br>
     *         <br>
     *         Throws:
     *         <br>
     *         <code>com.teamcenter.schemas.soa._2006_03.exceptions.ServiceException.</code>
     *         <br>
     *         <br>
     *         Business errors given by the operation -
     *         <br>
     *         1.&nbsp;&nbsp;&nbsp;&nbsp;Attempting to move task out of schedule boundaries
     *         <br>
     *         2.&nbsp;&nbsp;&nbsp;&nbsp;Invalid dependency type
     *         <br>
     *         3.&nbsp;&nbsp;&nbsp;&nbsp;Invalid lag time
     *         <br>
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Soa::Client::ServiceData updateDependencies ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Schedule>  schedule,
        const std::vector< Teamcenter::Services::Projectmanagement::_2012_02::Schedulemanagement::DependencyUpdateContainer >& dependencyUpdates ) = 0;

    /**
     * Updates all the affected scheduling objects based on the initial users request to
     * the application interface.  Properties on the <b>Schedule</b> object like <b>object
     * name, description, start date, finish date, status, is schedule template, wbsformat,
     * customer name, customer number , published, is public and priority </b>etc can be
     * updated with  this operation.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param scheduleUpdates
     *        The schedules to update and the updates to make. Vector of <code>ObjectUpdateContainer</code>
     *        structures. Each &nbsp;&nbsp;&nbsp;&nbsp;<code>ObjectUpdateContainer</code> structure
     *        holds a schedule&nbsp;&nbsp;&nbsp;&nbsp;object,   <code>AttributeUpdateContainer</code>
     *        structure and&nbsp;&nbsp;&nbsp;&nbsp;<code>TypedAttributeUpdateContainer</code> structure.
     *        Each <code>AttributeUpdateContainer</code> structure holds &nbsp;&nbsp;&nbsp;&nbsp;attribute
     *        name, value and type.
     *
     * @return
     *         Returns the objects impacted by the update.
     *         <br>
     *         <code>Teamcenter::Soa::Server::ServiceData : ServiceData</code> will contain updated
     *         objects or partial error if operation fails to update schedule.
     *         <br>
     *         <br>
     *         Following are the few possible error codes returned form this operation
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;230045  &nbsp;&nbsp;&nbsp;&nbsp;user does not have access
     *         to update schedule
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;301117 &nbsp;&nbsp;&nbsp;&nbsp;Schedule pre modification
     *         check error: Name of Schedule is too long.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;301118&nbsp;&nbsp;&nbsp;&nbsp;Schedule pre modification
     *         check error: The description is too long.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;301122 &nbsp;&nbsp;&nbsp;&nbsp;schedule pre modification
     *         check error: start date is null.
     *         <br>
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Soa::Client::ServiceData updateSchedules ( const std::vector< Teamcenter::Services::Projectmanagement::_2012_02::Schedulemanagement::ObjectUpdateContainer >& scheduleUpdates ) = 0;

    /**
     * Updates the specified tasks in a given schedule. Task updates are specified in the
     * <code>ObjectUpdateContainer</code>  structure. All the scheduling data properties
     * and execution data properties on the schedule task can be updated. Updates on the
     * summary tasks are not allowed. This operation supports updating the custom attributes
     * of OOTB schedule tasks  as well as custom schedule tasks. The updated objects are
     * returned back in the service data of the response. This operation throws a <code>ServiceException</code>
     * in case of failure. The service exception will contain the error message of the failure.
     * Additional errors will be returned in the list of partial errors in the <code>ServiceData</code>.
     * <br>
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param schedule
     *        The schedule containing the tasks to be updated.
     *
     * @param updates
     *        Vector of <code>ObjectUpdateContainer</code> structures. Each <code>ObjectUpdateContainer</code>
     *        structure holds a schedule task object,   <code>AttributeUpdateContainerstructure</code>,
     *        and <code>TypedAttributeUpdateContainer</code> structure.  Each <code>AttributeUpdateContainer</code>
     *        structure holds attribute name, value and type.
     *        <br>
     *
     * @return
     *         The service data.
     *         <br>
     *         Following are the few possible error codes  returned form this operation:,
     *         <br>
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;230078&nbsp;&nbsp;&nbsp;&nbsp;The percentage complete cannot
     *         be more than 100.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;230067&nbsp;&nbsp;&nbsp;&nbsp;The workflow attributes cannot
     *         be updated since the workflow process has started.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;301097 &nbsp;&nbsp;&nbsp;&nbsp;The Schedule Task start date
     *         is before the Schedule start date.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;301098 &nbsp;&nbsp;&nbsp;&nbsp;The Schedule Task finish
     *         date is after the Schedule finish date.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;301112 &nbsp;&nbsp;&nbsp;&nbsp;Schedule task update failed
     *         the pre-modification check.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;301114&nbsp;&nbsp;&nbsp;&nbsp;The Schedule task name is
     *         too long.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;301115&nbsp;&nbsp;&nbsp;&nbsp;The Schedule task description
     *         is too long.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;301130 &nbsp;&nbsp;&nbsp;&nbsp;The validator cannot change
     *         value from X to Ybecause both values are the same.
     *         <br>
     *
     *
     * @exception ServiceException
     *           None
     */
    virtual Teamcenter::Soa::Client::ServiceData updateTasks ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Schedule>  schedule,
        const std::vector< Teamcenter::Services::Projectmanagement::_2012_02::Schedulemanagement::ObjectUpdateContainer >& updates ) = 0;

    /**
     * Assigns resources to tasks.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param schedule
     *        The schedule containing the tasks to be assigned.
     *
     * @param createAssignments
     *        The new assignments to be created.
     *
     * @return
     *         It returns the created assignments as well as objects affected by the change.
     *
     *
     * @exception ServiceException
     *           None
     */
    virtual Teamcenter::Services::Projectmanagement::_2012_02::Schedulemanagement::CreatedObjectsContainer assignResources ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Schedule>  schedule,
        const std::vector< Teamcenter::Services::Projectmanagement::_2012_09::Schedulemanagement::AssignmentCreateContainer >& createAssignments ) = 0;

    /**
     * Claims an assignment.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Schedule Management - Application in Teamcenter to manage project schedules
     *
     * @param task
     *        The task containing the assignment.
     *
     * @param assignment
     *        The assignment to claim.
     *
     * @return
     *         The new assignment and any cascading updates.
     *
     *
     * @exception ServiceException
     *           None
     */
    virtual Teamcenter::Services::Projectmanagement::_2012_02::Schedulemanagement::CreatedObjectsContainer claimAssignment ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ScheduleTask>  task,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ResourceAssignment>  assignment ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("SchedulemanagementService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/projectmanagement/ProjectManagement_undef.h>
#endif

