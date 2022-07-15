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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SCHEDULEREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SCHEDULEREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ItemRevision.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class ScheduleTask;
                class ScheduleMember;
                class Fnd0ProxyTask;
                class Schedule;
                class User;


class TCSOACLIENTMNGD_API ScheduleRevision : public Teamcenter::Soa::Client::Model::ItemRevision
{
public:
    const Teamcenter::Soa::Common::DateTime& get_start_date();
    const Teamcenter::Soa::Common::DateTime& get_finish_date();
    int get_priority();
    int get_status();
    bool get_published();
    bool get_links_allowed();
    int get_rights_mask();
    bool get_dates_linked();
    bool get_percent_linked();
    bool get_is_template();
    int get_schedule_type();
    bool get_is_public();
    bool get_notifications_enabled();
    bool get_archive_notification_events();
    bool get_act_date_preference();
    int get_recalc_type();
    const std::string& get_wbsformat();
    const std::string& get_wbsvalue();
    bool get_end_date_scheduling();
    Teamcenter::Soa::Common::AutoPtr<ScheduleTask> get_sch_summary_task();
    const Teamcenter::Soa::Common::DateTime& get_latest_start_date();
    const Teamcenter::Soa::Common::DateTime& get_earliest_finish_date();
    size_t count_schedulemember_taglist();
    Teamcenter::Soa::Common::AutoPtr<ScheduleMember> get_schedulemember_taglist_at( size_t inx );
    const std::string& get_fnd0state();
    const std::string& get_fnd0status();
    size_t count_fnd0proxy_tasks();
    Teamcenter::Soa::Common::AutoPtr<Fnd0ProxyTask> get_fnd0proxy_tasks_at( size_t inx );
    Teamcenter::Soa::Common::AutoPtr<Schedule> get_fnd0master_sched();
    bool get_fnd0allowExecUpdates();
    Teamcenter::Soa::Common::AutoPtr<User> get_fnd0Schmgt_Lock();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ScheduleRevision")

   virtual ~ScheduleRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
