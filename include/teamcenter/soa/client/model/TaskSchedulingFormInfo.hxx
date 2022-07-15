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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_TASKSCHEDULINGFORMINFO_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_TASKSCHEDULINGFORMINFO_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_application_object.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class SchTaskDeliverable;
                class TaskDeliverable;
                class EPMTaskTemplate;


class TCSOACLIENTMNGD_API TaskSchedulingFormInfo : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    const Teamcenter::Soa::Common::DateTime& get_start_date();
    const Teamcenter::Soa::Common::DateTime& get_finish_date();
    int get_work_estimate();
    int get_duration();
    int get_workflow_trigger_type();
    size_t count_sch_task_deliverable_list();
    Teamcenter::Soa::Common::AutoPtr<SchTaskDeliverable> get_sch_task_deliverable_list_at( size_t inx );
    const std::string& get_wbs_code();
    size_t count_task_deliverable_taglist();
    Teamcenter::Soa::Common::AutoPtr<TaskDeliverable> get_task_deliverable_taglist_at( size_t inx );
    Teamcenter::Soa::Common::AutoPtr<EPMTaskTemplate> get_workflow_template();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("TaskSchedulingFormInfo")

   virtual ~TaskSchedulingFormInfo();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
