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

#ifndef TEAMCENTER_SERVICES_PROJECTMANAGEMENT__2012_09_SCHEDULEMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_PROJECTMANAGEMENT__2012_09_SCHEDULEMANAGEMENT_HXX

#include <teamcenter/services/projectmanagement/_2012_02/Schedulemanagement.hxx>
#include <teamcenter/soa/client/model/Discipline.hxx>
#include <teamcenter/soa/client/model/POM_object.hxx>
#include <teamcenter/soa/client/model/ResourceAssignment.hxx>
#include <teamcenter/soa/client/model/Schedule.hxx>
#include <teamcenter/soa/client/model/ScheduleTask.hxx>


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
            namespace _2012_09
            {
                class Schedulemanagement;

class TCSOAPROJECTMANAGEMENTSTRONGMNGD_API Schedulemanagement
{
public:

    struct AssignmentCreateContainer;

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
         * The resource (User, Group, Role, Resource Pool) being assigned (or null if discipline
         * assignment).
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::POM_object>  resource;
        /**
         * The discipline of the assignee (if User) or the discipline for the assignment.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Discipline>  discipline;
        /**
         * The percentage effort being assigned (I.E. 50.0 == 50%)
         */
        double assignedPercent;
    };




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


protected:
    virtual ~Schedulemanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/projectmanagement/ProjectManagement_undef.h>
#endif

