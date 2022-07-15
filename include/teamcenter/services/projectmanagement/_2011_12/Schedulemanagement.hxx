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

#ifndef TEAMCENTER_SERVICES_PROJECTMANAGEMENT__2011_12_SCHEDULEMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_PROJECTMANAGEMENT__2011_12_SCHEDULEMANAGEMENT_HXX

#include <teamcenter/soa/client/model/Schedule.hxx>
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
            namespace _2011_12
            {
                class Schedulemanagement;

class TCSOAPROJECTMANAGEMENTSTRONGMNGD_API Schedulemanagement
{
public:

    struct CreatedDependenciesContainer;
    struct DependencyCreateContainer;

    /**
     * The created dependencies
     */
    struct CreatedDependenciesContainer
    {
        /**
         * The new dependencies
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TaskDependency>  > createdDependencies;
        /**
         * The updated tasks
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ScheduleTask>  > updatedTasks;
        /**
         * The service data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Creates Dependencies between tasks in the same schedule.
     */
    struct DependencyCreateContainer
    {
        /**
         * The predecessor task for the dependency
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ScheduleTask>  predTask;
        /**
         * The successor task for the dependency
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ScheduleTask>  succTask;
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


protected:
    virtual ~Schedulemanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/projectmanagement/ProjectManagement_undef.h>
#endif

