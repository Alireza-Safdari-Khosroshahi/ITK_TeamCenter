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

#ifndef TEAMCENTER_SERVICES_PROJECTMANAGEMENT__2007_06_SCHEDULEMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_PROJECTMANAGEMENT__2007_06_SCHEDULEMANAGEMENT_HXX

#include <teamcenter/soa/client/model/ResourceAssignment.hxx>
#include <teamcenter/soa/client/model/Schedule.hxx>
#include <teamcenter/soa/client/model/ScheduleTask.hxx>
#include <teamcenter/soa/client/model/TCCalendar.hxx>
#include <teamcenter/soa/client/model/TCCalendarEvent.hxx>
#include <teamcenter/soa/client/model/TaskDependency.hxx>
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
            namespace _2007_06
            {
                class Schedulemanagement;

class TCSOAPROJECTMANAGEMENTSTRONGMNGD_API Schedulemanagement
{
public:

    struct DeleteNotificationRuleContainer;
    struct GetNotificationRuleContainer;
    struct MultiScheduleCopyResponse;
    struct NotificationRuleContainer;
    struct NotificationRulesList;
    struct ScheduleCopyOptionsContainer;
    struct ScheduleCopyResponse;
    struct TaskDeliverableContainer;

    /**
     * The input information needed to delete an existing notification rule.
     */
    struct DeleteNotificationRuleContainer
    {
        /**
         * The tag  of  the Schedule  or ScheduleTask.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  target;
        /**
         * The tag of the subscriber.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  subscriber;
        /**
         * The type of rule to delete. Valid values-{ __Add_Task,__Delete_Task,__Near_Due,__Overdue,__Start_Date_Change,__Finish_Date_Change,__Status_Change,__Status_ChangeTo,__Priority_Change,__Priority_ChangeTo,__Work_Estimate_Change,__Work_Complete_Change,__Work_Ready,__User_Assigned}
         */
        std::string ruleType;
    };

    /**
     * The input information needed to find all notifications for a particular task or schedule.
     */
    struct GetNotificationRuleContainer
    {
        /**
         * The tag of a Schedule or ScheduleTask.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  target;
        /**
         * The tag of the subscriber.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  subscriber;
    };

    /**
     * Container to hold multiple ScheduleCopyResponse objects.
     */
    struct MultiScheduleCopyResponse
    {
        /**
         * A collection of the schedule responses.
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2007_06::Schedulemanagement::ScheduleCopyResponse > scheduleResponse;
        /**
         * The ServiceData.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The information needed for the creation of a single Notification rule.
     */
    struct NotificationRuleContainer
    {
        /**
         * The tag of a schedule or task
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  target;
        /**
         * The subscriber for this notification.  It is the Target object in the case of a notification
         * or a User object in the case of a subscription.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  subscriber;
        /**
         * Subject of the email. Valid value- can be empty string
         */
        std::string notificationSubject;
        /**
         * Message of the e-mail. Valid value- can be empty string
         */
        std::string notificationMessage;
        /**
         * The Users, groups, disciplines, or schedule members to be notified.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > recipient;
        /**
         * A semi-colon separated list of e-mail addresses. Valid value - can be empty string
         */
        std::string additionalEmails;
        /**
         * The condition data for notifications that are triggered conditionally.  E.g.  Schedule
         * Task near due. Valid value - can be empty string
         */
        std::string notificationCondition;
        /**
         * The type of rule to create. Valid values are {__Add_Task,__Delete_Task,__Near_Due,__Overdue,__Start_Date_Change,__Finish_Date_Change,__Status_Change,__Status_ChangeTo,__Priority_Change,__Priority_ChangeTo,__Work_Estimate_Change,__Work_Complete_Change,__Work_Ready,__User_Assigned
         * }
         */
        std::string ruleType;
        /**
         * Active or inactive status of the notification.
         */
        bool status;
        /**
         * Attempting to update an existing rule.
         */
        bool update;
    };

    /**
     * A collection of the single NotificationRuleContainer objects.
     */
    struct NotificationRulesList
    {
        /**
         * The collection of Notification Rules.
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2007_06::Schedulemanagement::NotificationRuleContainer > notificationRules;
        /**
         * The ServiceData.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The input information necessary to copy a schedule.
     */
    struct ScheduleCopyOptionsContainer
    {
        /**
         * The name of the new schedule.
         */
        std::string name;
        /**
         * The description of the new schedule.
         */
        std::string description;
        /**
         * The tag to the schedule to copy.
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
        /**
         * Flag to indicate whether or not to load the schedule in the response.
         */
        bool loadOnResponse;
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
     * The input information for a single task deliverable.
     */
    struct TaskDeliverableContainer
    {
        /**
         * The task which will contain this delievable. Tag of the task
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ScheduleTask>  scheduleTask;
        /**
         * The ScheduleDeliverable to reference. Tag of schedule deliverable.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  scheduleDeliverable;
        /**
         * The submit type  (3=Don't submit, 0=submit as target, 1=submit as reference).
         */
        int submitType;
    };




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


protected:
    virtual ~Schedulemanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/projectmanagement/ProjectManagement_undef.h>
#endif

