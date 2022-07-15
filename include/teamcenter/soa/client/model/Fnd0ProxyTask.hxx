/* 
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
 ==================================================
 Copyright 2012
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

 ==================================================

  Auto-generated source from Teamcenter Data Model.
                 DO NOT EDIT

 ==================================================
*/

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0PROXYTASK_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0PROXYTASK_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/WorkspaceObject.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class WorkspaceObject;
                class ScheduleTask;
                class Schedule;


class TCSOACLIENTMNGD_API Fnd0ProxyTask : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    int get_fnd0constraint();
    const Teamcenter::Soa::Common::DateTime& get_fnd0finish_date();
    double get_fnd0percent_complete();
    double get_fnd0percent_work_complete();
    Teamcenter::Soa::Common::AutoPtr<WorkspaceObject> get_fnd0ref();
    const Teamcenter::Soa::Common::DateTime& get_fnd0start_date();
    const std::string& get_fnd0status();
    Teamcenter::Soa::Common::AutoPtr<ScheduleTask> get_fnd0task_tag();
    int get_fnd0type();
    Teamcenter::Soa::Common::AutoPtr<Schedule> get_fnd0schedule_tag();
    const std::string& get_fnd0sched_name();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0ProxyTask")

   virtual ~Fnd0ProxyTask();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
