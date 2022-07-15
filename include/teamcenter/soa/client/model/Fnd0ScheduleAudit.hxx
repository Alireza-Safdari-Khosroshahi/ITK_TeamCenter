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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0SCHEDULEAUDIT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0SCHEDULEAUDIT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Fnd0AuditLog.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API Fnd0ScheduleAudit : public Teamcenter::Soa::Client::Model::Fnd0AuditLog
{
public:
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_Discipline();
    const std::string& get_DisciplineDisp();
    bool get_dates_linked();
    int get_dependency_type();
    const Teamcenter::Soa::Common::DateTime& get_earliest_finish_date();
    bool get_end_date_scheduling();
    const std::string& get_fnd0ChangeID();
    const std::string& get_fnd0Reason();
    int get_lag_time();
    const Teamcenter::Soa::Common::DateTime& get_latest_start_date();
    const std::string& get_schedule_deliverable_list();
    const std::string& get_schedule_tagDisp();
    const std::string& get_schedulemember_taglist();
    const std::string& get_wbsformat();
    const std::string& get_wbsvalue();
    double get_resource_level();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_fnd0Object();
    const std::string& get_object_name();
    const std::string& get_object_type();
    const std::string& get_fnd0ObjectDisplayName();
    const std::string& get_fnd0EventTypeName();
    const std::string& get_fnd0UserId();
    const std::string& get_fnd0GroupName();
    const std::string& get_fnd0RoleName();
    const Teamcenter::Soa::Common::DateTime& get_fnd0LoggedDate();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_schedule_tag();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_workflow_process();
    int get_task_type();
    int get_schedule_type();
    const Teamcenter::Soa::Common::DateTime& get_start_date();
    const Teamcenter::Soa::Common::DateTime& get_finish_date();
    int get_work_complete();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_workflow_template();
    double get_complete_percent();
    const Teamcenter::Soa::Common::DateTime& get_actual_start_date();
    const Teamcenter::Soa::Common::DateTime& get_actual_finish_date();
    int get_fixed_type();
    const std::string& get_fnd0ErrorMessage();
    int get_fnd0ErrorCode();
    const std::string& get_item_id();
    const std::string& get_item_revision_id();
    int get_sequence_id();
    const std::string& get_fnd0state();
    const std::string& get_fnd0status();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_deliverable_inst();
    const std::string& get_deliverable_instDisp();
    const std::string& get_deliverable_name();
    const std::string& get_deliverable_type();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_schedule_deliverable();
    const std::string& get_schedule_deliverableDisp();
    int get_submit_type();
    int get_member_priv();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_resource_tag();
    const std::string& get_resource_tagDisp();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_schedule_as_member();
    const std::string& get_schedule_as_memberDisp();
    const std::string& get_customer_name();
    const std::string& get_customer_number();
    bool get_is_public();
    bool get_is_template();
    bool get_percent_linked();
    bool get_published();
    const std::string& get_user_name();
    const std::string& get_workflow_templateDisp();
    int get_constraint();
    int get_duration();
    int get_workflow_trigger_type();
    const std::string& get_wbs_code();
    const std::string& get_workflow_processDisp();
    const std::string& get_sch_task_deliverable_list();
    const std::string& get_sch_task_deliverable_listDp();
    int get_priority();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_privileged_user();
    const std::string& get_privileged_userDisp();
    const std::string& get_object_nameOvl();
    const std::string& get_schedulemember_taglistDisp();
    const std::string& get_sch_deliverable_listDisp();
    int get_work_estimate();
    const std::string& get_sch_task_deliv_listDisp();
    int get_approved_work();
    int get_work_remaining();
    const std::string& get_sch_task_del_listDisp();
    const std::string& get_sch_task_deli_list();
    const std::string& get_sch_task_deli_listDisp();
    const std::string& get_sch_task_deliv_list();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_activeschbaseline_tag();
    const std::string& get_activeschbsl_tagDisp();
    bool get_is_baseline();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_Primary_object();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_Secondary_object();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_schedule_deliverableOvl();
    const std::string& get_schedule_deliverableOvlDisp();
    int get_submit_typeOvl();
    const std::string& get_child_task_taglist();
    const std::string& get_child_task_taglistDisp();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_schedule();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_schedule_task();
    const std::string& get_cost();
    const std::string& get_currency();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_fnd0SecondaryObject();
    const std::string& get_fnd0SecondaryObjectType();
    const std::string& get_fnd0SecondaryObjectName();
    const std::string& get_fnd0SecondaryObjectID();
    const std::string& get_fnd0SecondaryObjectRevID();
    int get_fnd0SecondaryObjectSeqID();
    const std::string& get_fnd0SecondaryObjDispName();
    const std::string& get_schedule_taskDisp();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0ScheduleAudit")

   virtual ~Fnd0ScheduleAudit();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
