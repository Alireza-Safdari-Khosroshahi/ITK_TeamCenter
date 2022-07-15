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

#ifndef TEAMCENTER_SERVICES_PROJECTMANAGEMENT__2009_10_SCHEDULEMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_PROJECTMANAGEMENT__2009_10_SCHEDULEMANAGEMENT_HXX

#include <teamcenter/services/projectmanagement/_2008_06/Schedulemanagement.hxx>
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
            namespace _2009_10
            {
                class Schedulemanagement;

class TCSOAPROJECTMANAGEMENTSTRONGMNGD_API Schedulemanagement
{
public:

    struct GenericAttributesContainer;
    struct GenericResponseContainer;
    struct ScheduleModifyContainer;

    /**
     * Enumerator for service actions
     */
    enum ServiceAction{ GET,
                 POST,
                 VALIDATE,
                 PERSIST,
                 ANALYSE
                 };

    /**
     * Enumerator for translator operations
     */
    enum TranslatorOperation{ AssignmentAssign,
                 AssignmentUnassign,
                 AssignmentUpdate,
                 AssignmentDelegate,
                 AssignmentReplace,
                 AssignmentRevert,
                 ResourceGetAssignments,
                 DependencyCreate,
                 DependencyUpdate,
                 DependencyDelete,
                 ScheduleCreate,
                 ScheduleDelete,
                 ScheduleRecalculate,
                 ScheduleModify,
                 ScheduleTaskCreate,
                 ScheduleTaskDelete,
                 ScheduleTaskUpdate,
                 ScheduleGetCriticalPath,
                 ScheduleShift,
                 ScheduleScale,
                 ScheduleTaskMove,
                 Undefined
                 };

    /**
     * A collection of KeyValContainers or StringValContainers reprenting the create or
     * updates for a single object, such as Schedule, ScheduleTask, TaskDependency, or ResourceAssignment
     */
    struct GenericAttributesContainer
    {
        /**
         * The service type. Valid values are "GET" or "POST","VALIDATE" or "PERSIST"
         */
        ServiceAction serviceType;
        /**
         * The operation type (may be set by the system if the API does not have multiple contracts)
         */
        TranslatorOperation operationType;
        /**
         * the schedule uid. This is required for batch updates in multiple schedules.
         */
        std::string scheduleUid;
        /**
         * The tag to the object being updated
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  object;
        /**
         * A collection of updates. Valid values are  key = property name which is to be updated
         * eg "priority"  value = value of the property eg. "2"
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2008_06::Schedulemanagement::StringValContainer > stringValContainer;
        /**
         * A collection of updates for extended properties if there are any (optional)
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2008_06::Schedulemanagement::TypedAttributeContainer > typedAttributesContainer;
    };

    /**
     * This is the generic response container
     */
    struct GenericResponseContainer
    {
        /**
         * The ServiceData
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * The list of objects uid
         */
        std::vector< std::string > objectUids;
        /**
         * The list of objects
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > objects;
    };

    /**
     * The information necessary to update a schedule.  It contains information about new,
     * updated, and deleted tasks, resource assignments, and task dependencies.
     */
    struct ScheduleModifyContainer
    {
        /**
         * the schedule uid
         */
        std::string scheduleUid;
        /**
         * The service action
         */
        ServiceAction serviceType;
        /**
         * the schedule updates
         */
        Teamcenter::Services::Projectmanagement::_2009_10::Schedulemanagement::GenericAttributesContainer scheduleUpdates;
        /**
         * Delete all tasks flag
         */
        bool deleteAllTasks;
        /**
         * The new tasks to add
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2009_10::Schedulemanagement::GenericAttributesContainer > newTasks;
        /**
         * The new dependencies
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2009_10::Schedulemanagement::GenericAttributesContainer > newDependencies;
        /**
         * The new assignments
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2009_10::Schedulemanagement::GenericAttributesContainer > newAssignments;
        /**
         * The existing task updates
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2009_10::Schedulemanagement::GenericAttributesContainer > taskUpdates;
        /**
         * The existing dependencies updates
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2009_10::Schedulemanagement::GenericAttributesContainer > dependenciesUpdate;
        /**
         * The existing assignment updates
         */
        std::vector< Teamcenter::Services::Projectmanagement::_2009_10::Schedulemanagement::GenericAttributesContainer > assignmentUpdates;
        /**
         * The deleted tasks
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > deletedTasks;
        /**
         * The deleted dependencies
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > deletedDependencies;
        /**
         * The deleted assignments
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > deletedAssignments;
    };




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


protected:
    virtual ~Schedulemanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/projectmanagement/ProjectManagement_undef.h>
#endif

