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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SCHEDULETASK_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SCHEDULETASK_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Item.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class Schedule;
                class TaskExecutionFormInfo;
                class TaskSchedulingFormInfo;
                class SchMgtCostFormStorage;


class TCSOACLIENTMNGD_API ScheduleTask : public Teamcenter::Soa::Client::Model::Item
{
public:
    const std::string& get_ms_integration_link();
    bool get_is_baseline();
    double get_baseline_var_cost();
    Teamcenter::Soa::Common::AutoPtr<ScheduleTask> get_original_task_tag();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_task_rev();
    Teamcenter::Soa::Common::AutoPtr<Schedule> get_schedule_tag();
    Teamcenter::Soa::Common::AutoPtr<TaskExecutionFormInfo> get_exec_form_info();
    Teamcenter::Soa::Common::AutoPtr<TaskSchedulingFormInfo> get_sch_form_info();
    Teamcenter::Soa::Common::AutoPtr<SchMgtCostFormStorage> get_cost_form_info();
    int get_duration();
    int get_sch_task_notification_count();
    int get_sch_task_subscription_count();
    int get_priority();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_workflow_process();
    const Teamcenter::Soa::Common::DateTime& get_actual_finish_date();
    int get_status();
    const Teamcenter::Soa::Client::ModelObjectVector& get_child_task_taglist();
    const std::string& get_workflow_template_name();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_workflow_template();
    const Teamcenter::Soa::Common::DateTime& get_actual_start_date();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_privileged_user();
    int get_constraint();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_parent_task_tag();
    bool get_auto_complete();
    const Teamcenter::Soa::Client::ModelObjectVector& get_task_deliverable_taglist();
    const Teamcenter::Soa::Client::ModelObjectVector& get_sch_task_deliverable_list();
    const Teamcenter::Soa::Common::DateTime& get_finish_date();
    const Teamcenter::Soa::Common::DateTime& get_start_date();
    double get_complete_percent();
    int get_task_type();
    int get_workflow_trigger_type();
    int get_fixed_type();
    int get_work_estimate();
    int get_work_complete();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TaskDependency();
    const Teamcenter::Soa::Client::ModelObjectVector& get_ResourceAssignment();
    int get_approved_work();
    const std::string& get_wbs_code();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_billrate_tag();
    const std::string& get_bill_type();
    const std::string& get_bill_code();
    const std::string& get_bill_sub_code();
    const Teamcenter::Soa::Client::ModelObjectVector& get_fixed_cost_taglist();
    const std::string& get_fnd0state();
    const Teamcenter::Soa::Client::ModelObjectVector& get_fnd0ScheduleAuditLogs();
    const std::string& get_fnd0status();
    const Teamcenter::Soa::Client::ModelObjectVector& get_fnd0Assignments();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_fnd0workflow_owner();
    int get_work_remaining();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ScheduleTask")

   virtual ~ScheduleTask();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
