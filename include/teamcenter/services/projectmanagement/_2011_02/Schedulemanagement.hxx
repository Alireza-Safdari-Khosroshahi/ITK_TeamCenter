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

#ifndef TEAMCENTER_SERVICES_PROJECTMANAGEMENT__2011_02_SCHEDULEMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_PROJECTMANAGEMENT__2011_02_SCHEDULEMANAGEMENT_HXX

#include <teamcenter/soa/client/model/ResourceAssignment.hxx>
#include <teamcenter/soa/client/model/SchDeliverable.hxx>
#include <teamcenter/soa/client/model/Schedule.hxx>
#include <teamcenter/soa/client/model/ScheduleMember.hxx>
#include <teamcenter/soa/client/model/ScheduleTask.hxx>
#include <teamcenter/soa/client/model/TaskDependency.hxx>


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
            namespace _2011_02
            {
                class Schedulemanagement;

class TCSOAPROJECTMANAGEMENTSTRONGMNGD_API Schedulemanagement
{
public:

    struct SchMgtOptions;
    struct FromSchedule;
    struct MultiSchSpecialCopyResponse;
    struct SchMgtIntegerOption;
    struct SchMgtLogicalOption;
    struct SchMgtStringOption;
    struct ToSchedule;
    struct SpecialCopyContainer;

    /**
     * Enums which describes where to paste the copied tasks.
     */
    enum PasteType{ PasteBeforeTask,
                 PasteUnderTask,
                 PasteAfterTask
                 };

    /**
     * Special copy-paste options
     */
    struct SchMgtOptions
    {
        /**
         * List of logical options
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2011_02::Schedulemanagement::SchMgtLogicalOption > logicalOptions;
        /**
         * List of integer options
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2011_02::Schedulemanagement::SchMgtIntegerOption > integerOptions;
        /**
         * List of string options
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2011_02::Schedulemanagement::SchMgtStringOption > stringOptions;
    };

    /**
     * The information regarding a schedule to copy from.
     */
    struct FromSchedule
    {
        /**
         * The schedule to copy from.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Schedule>  schedule;
        /**
         * The list of tasks in that schedule to copy.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ScheduleTask>  > tasks;
        /**
         * Option structure for list of logical, integer and string options IntegerOptions {
         * numberOfCopies - the number of copies } LogicalOptions { includeAssignments - copy
         * assignments,includeDependencies - copy dependencies,includeDeliverables - copy deliverables,useExistingDeliverables
         * - link copied to existing (by name), createMembership - copy missing members, resetDeliverableInstances
         * - reset the instance of Schedule Deliverables, copyWorkflowTemplate - copy workflow
         * template information, copyCostOfTask - copy costs, offsetBasedOnPositionInTemplate
         * - shift tasks relative of original offset, recalcAsyncDispatcher - recalculate in
         * asynchronously }
         */
        Teamcenter::Services::Projectmanagement::_2011_02::Schedulemanagement::SchMgtOptions schmgtOptions;
    };

    /**
     * Return type of SOA for special paste
     */
    struct MultiSchSpecialCopyResponse
    {
        /**
         * Created Tasks
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ScheduleTask>  > createdTasks;
        /**
         * Modified Tasks
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ScheduleTask>  > modifiedTasks;
        /**
         * Created Members
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ScheduleMember>  > createdMembers;
        /**
         * Created Schedule Deliverables
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::SchDeliverable>  > createdDeliverables;
        /**
         * Created Dependencies
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TaskDependency>  > createdDependencies;
        /**
         * Created Assignments
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ResourceAssignment>  > createdAssignments;
        /**
         * Service Data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Integer Options for special copy-paste
     */
    struct SchMgtIntegerOption
    {
        /**
         * The name of the option.
         */
        std::string name;
        /**
         * The integer value of the option.
         */
        int value;
    };

    /**
     * Logical options for special copy-paste
     */
    struct SchMgtLogicalOption
    {
        /**
         * The name of the option.
         */
        std::string name;
        /**
         * The value of logical option (True or False).
         */
        bool value;
    };

    /**
     * String Options for special copy-paste
     */
    struct SchMgtStringOption
    {
        /**
         * The name of the option.
         */
        std::string name;
        /**
         * The string value of the option
         */
        std::string value;
    };

    /**
     * Target Schedule under which tasks will be pasted.
     */
    struct ToSchedule
    {
        /**
         * The target Schedule
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Schedule>  targetSchedule;
        /**
         * The target Task
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ScheduleTask>  task;
        /**
         * Paste Type - PasteBeforeTask/PasteUnderTask/PasteAfterTask
         */
        PasteType pasteType;
    };

    /**
     * Input container
     */
    struct SpecialCopyContainer
    {
        /**
         * List of FromSchedules
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2011_02::Schedulemanagement::FromSchedule > fromSchedule;
        /**
         * Target Schedule
         */
        Teamcenter::Services::Projectmanagement::_2011_02::Schedulemanagement::ToSchedule toSchedule;
    };




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


protected:
    virtual ~Schedulemanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/projectmanagement/ProjectManagement_undef.h>
#endif

