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

#ifndef TEAMCENTER_SERVICES_PROJECTMANAGEMENT__2012_02_SCHEDULEMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_PROJECTMANAGEMENT__2012_02_SCHEDULEMANAGEMENT_HXX

#include <teamcenter/services/projectmanagement/_2011_06/Schedulemanagement.hxx>
#include <teamcenter/soa/client/model/Discipline.hxx>
#include <teamcenter/soa/client/model/EPMJob.hxx>
#include <teamcenter/soa/client/model/Fnd0ProxyTask.hxx>
#include <teamcenter/soa/client/model/POM_object.hxx>
#include <teamcenter/soa/client/model/ResourceAssignment.hxx>
#include <teamcenter/soa/client/model/Schedule.hxx>
#include <teamcenter/soa/client/model/ScheduleTask.hxx>
#include <teamcenter/soa/client/model/TaskDependency.hxx>
#include <teamcenter/soa/client/model/User.hxx>
#include <teamcenter/soa/client/model/WorkspaceObject.hxx>


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
            namespace _2012_02
            {
                class Schedulemanagement;

class TCSOAPROJECTMANAGEMENTSTRONGMNGD_API Schedulemanagement
{
public:

    struct AssignmentCreateContainer;
    struct AssignmentUpdateContainer;
    struct AttributeUpdateContainer;
    struct CreatedDependenciesContainer;
    struct CreatedObjectsContainer;
    struct CriticalTasksContainer;
    struct DeleteTaskContainer;
    struct DependencyCreateContainer;
    struct DependencyUpdateContainer;
    struct LaunchedWorkflowContainer;
    struct MoveRequest;
    struct ObjectUpdateContainer;
    struct TaskCreateContainer;
    struct TypedAttributeUpdateContainer;

    /**
     * The information needed to create a new assignment to a task.
     */
    struct AssignmentCreateContainer
    {
        /**
         * The task to assign the resource.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ScheduleTask>  task;
        /**
         * The user being assigned (or null if discipline assignment).
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::User>  user;
        /**
         * The discipline of the assignee or the discipline for the assignment.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Discipline>  discipline;
        /**
         * The percentage effort being assigned (I.E. 50.0 == 50%)
         */
        double assignedPercent;
    };

    /**
     * Container for assignment updates.
     */
    struct AssignmentUpdateContainer
    {
        /**
         * The assignment to update
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ResourceAssignment>  assignment;
        /**
         * The new % effort of that assignee.
         */
        double newEffort;
    };

    /**
     * Holds the name and value of an attribute.
     */
    struct AttributeUpdateContainer
    {
        /**
         * The name of the attribute.
         */
        std::string attrName;
        /**
         * The value of the attribute.
         */
        std::string attrValue;
        /**
         * An integer to help determine the data type of the attribute. Valid values- { 1=String_type,2=Integer_type,3=Long_type,4=Double_type,5=Float_type,6=Boolean_type,7=Date_type,8=Cal_type
         * }
         */
        int attrType;
    };

    /**
     * New  dependencies container
     */
    struct CreatedDependenciesContainer
    {
        /**
         * The dependencies created
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TaskDependency>  > createdDependencies;
        /**
         * The created proxy tasks
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Fnd0ProxyTask>  > createdProxyTasks;
        /**
         * The tasks which were updated due to
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ScheduleTask>  > updatedTasks;
        /**
         * The SOA service data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The container of created objects
     */
    struct CreatedObjectsContainer
    {
        /**
         * The objects which were created.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::POM_object>  > createdObjects;
        /**
         * The tasks affected by the creation.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ScheduleTask>  > updatedTasks;
        /**
         * The service data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The tasks on the critical path.
     */
    struct CriticalTasksContainer
    {
        /**
         * The tasks on the critical path.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ScheduleTask>  > tasks;
        /**
         * The proxy tasks on the critical path.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Fnd0ProxyTask>  > proxyTasks;
        /**
         * The service data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Information about the deleted tasks.
     */
    struct DeleteTaskContainer
    {
        /**
         * Tasks which were orphaned(as they could not be deleted).
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ScheduleTask>  > orphaned;
        /**
         * Tasks updated due to the delete.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ScheduleTask>  > updated;
        /**
         * The service data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Creates Dependencies between tasks in the same schedule, between a task and a proxy
     * task in the same schedule, or between a tasks in different schedules (but in the
     * same master schedule).  It returns the created dependencies, created proxy tasks
     * (if any), and the objects affected by this change
     */
    struct DependencyCreateContainer
    {
        /**
         * The predecessor task for the dependency.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  predTask;
        /**
         * The successor task for the dependency.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  succTask;
        /**
         * The type of dependency: 0-FS, 1-FF, 2-SS, 3-SF
         */
        int depType;
        /**
         * The lag time in minutes (480 ~ 1 day)
         */
        int lagTime;
    };

    /**
     * Update dependency container
     */
    struct DependencyUpdateContainer
    {
        /**
         * The dependency to update.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TaskDependency>  dependency;
        /**
         * The new type for the dependency.
         */
        int newType;
        /**
         * The new lag for the dependnecy.
         */
        int newLag;
    };

    /**
     * Information about the launced workflows.
     */
    struct LaunchedWorkflowContainer
    {
        /**
         * The launched workflow processes.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::EPMJob>  > launchedWorkflows;
        /**
         * The service data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The information required to move a task.
     */
    struct MoveRequest
    {
        /**
         * The task or proxy task to move.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  task;
        /**
         * The new parent for the task.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ScheduleTask>  newParent;
        /**
         * The new previous sibling for the task (or the reference task in the case of a proxy).
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ScheduleTask>  prevSibling;
    };

    /**
     * Information to update an object.
     */
    struct ObjectUpdateContainer
    {
        /**
         * The object being updated.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::POM_object>  object;
        /**
         * The updates to the main type.
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2012_02::Schedulemanagement::AttributeUpdateContainer > updates;
        /**
         * Updates for a custom type.
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2012_02::Schedulemanagement::TypedAttributeUpdateContainer > typedUpdates;
    };

    /**
     * The information needed to create a task.
     */
    struct TaskCreateContainer
    {
        /**
         * The name.
         */
        std::string name;
        /**
         * The description.
         */
        std::string desc;
        /**
         * The type to create (typically "ScheduleTask").
         */
        std::string objectType;
        /**
         * The start date and time.
         */
        Teamcenter::Soa::Common::DateTime start;
        /**
         * The finish date and time.
         */
        Teamcenter::Soa::Common::DateTime finish;
        /**
         * The work estimate in minutes.
         */
        int workEstimate;
        /**
         * The summary task to create the new task under.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ScheduleTask>  parent;
        /**
         * The task to create this new task after.  Must currently exist under the parent.
         * Can be null.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ScheduleTask>  prevSibling;
        /**
         * Additional optional attributes: priority
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2012_02::Schedulemanagement::AttributeUpdateContainer > otherAttributes;
        /**
         * Other attributes required to create the objectType specified.
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2012_02::Schedulemanagement::TypedAttributeUpdateContainer > typedOtherAttributes;
    };

    /**
     * Updates for a certain type of object.
     */
    struct TypedAttributeUpdateContainer
    {
        /**
         * The object type containing the attributes.
         */
        std::string objectType;
        /**
         * The list of attributes and their values.
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2012_02::Schedulemanagement::AttributeUpdateContainer > updates;
    };




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


protected:
    virtual ~Schedulemanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/projectmanagement/ProjectManagement_undef.h>
#endif

