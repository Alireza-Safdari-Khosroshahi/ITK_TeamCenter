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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SCHEDULE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SCHEDULE_HXX

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
                class SchDeliverable;
                class ScheduleDeliverable;
                class Fnd0ProxyTask;
                class User;


class TCSOACLIENTMNGD_API Schedule : public Teamcenter::Soa::Client::Model::Item
{
public:
    Teamcenter::Soa::Common::AutoPtr<Schedule> get_activeschbaseline_tag();
    const std::string& get_customer_name();
    const std::string& get_customer_number();
    bool get_is_baseline();
    double get_base_schedule_cost();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_schedule_rev();
    size_t count_schedule_deliverable_list();
    Teamcenter::Soa::Common::AutoPtr<SchDeliverable> get_schedule_deliverable_list_at( size_t inx );
    size_t count_sch_deliverable_taglist();
    Teamcenter::Soa::Common::AutoPtr<ScheduleDeliverable> get_sch_deliverable_taglist_at( size_t inx );
    int get_priority();
    const Teamcenter::Soa::Client::ModelObjectVector& get_scheduletask_taglist();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_sch_summary_task();
    int get_schedule_type();
    int get_status();
    int get_sch_notification_count();
    int get_sch_subscription_count();
    bool get_is_public();
    bool get_notifications_enabled();
    bool get_recalc_schedule();
    int get_recalc_type();
    bool get_act_date_preference();
    bool get_is_template();
    bool get_dates_linked();
    bool get_percent_linked();
    int get_rights_mask();
    bool get_published();
    const Teamcenter::Soa::Common::DateTime& get_finish_date();
    const Teamcenter::Soa::Common::DateTime& get_start_date();
    bool get_links_allowed();
    const Teamcenter::Soa::Client::ModelObjectVector& get_schedulemember_taglist();
    const std::string& get_wbsformat();
    const Teamcenter::Soa::Common::DateTime& get_latest_start_date();
    const Teamcenter::Soa::Common::DateTime& get_earliest_finish_date();
    bool get_end_date_scheduling();
    const std::string& get_wbsvalue();
    const Teamcenter::Soa::Client::ModelObjectVector& get_fnd0ScheduleAuditLogs();
    const std::string& get_fnd0state();
    const std::string& get_fnd0status();
    bool get_fnd0allowExecUpdates();
    Teamcenter::Soa::Common::AutoPtr<Schedule> get_fnd0master_sched();
    size_t count_fnd0proxy_tasks();
    Teamcenter::Soa::Common::AutoPtr<Fnd0ProxyTask> get_fnd0proxy_tasks_at( size_t inx );
    Teamcenter::Soa::Common::AutoPtr<User> get_fnd0Schmgt_Lock();
    const std::string& get_fnd0sum_rollup_state();
    const std::string& get_fnd0sum_rollup_status();
    int get_sum_rollup_status();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Schedule")

   virtual ~Schedule();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
