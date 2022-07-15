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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0SECONDARYAUDIT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0SECONDARYAUDIT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API Fnd0SecondaryAudit : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_fnd0Object();
    const std::string& get_object_type();
    const std::string& get_object_name();
    int get_sequence_id();
    const std::string& get_fnd0ObjectDisplayName();
    const std::string& get_cost();
    const std::string& get_currency();
    int get_lag_time();
    int get_dependency_type();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_Primary_object();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_Secondary_object();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_schedule_tag();
    const std::string& get_schedule_tagDisp();
    const Teamcenter::Soa::Common::DateTime& get_start_date();
    const std::string& get_os_username();
    const Teamcenter::Soa::Common::DateTime& get_finish_date();
    int get_task_type();
    int get_priority();
    int get_constraint();
    int get_fixed_type();
    const std::string& get_fnd0status();
    const std::string& get_fnd0state();
    int get_duration();
    int get_work_estimate();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_workflow_template();
    const std::string& get_workflow_templateDisp();
    int get_workflow_trigger_type();
    const std::string& get_wbs_code();
    const Teamcenter::Soa::Common::DateTime& get_actual_start_date();
    const Teamcenter::Soa::Common::DateTime& get_actual_finish_date();
    double get_complete_percent();
    int get_approved_work();
    int get_work_complete();
    int get_work_remaining();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_workflow_process();
    const std::string& get_workflow_processDisp();
    const std::string& get_sch_task_deli_list();
    const std::string& get_sch_task_deli_listDisp();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_discipline();
    const std::string& get_disciplineDisp();
    double get_resource_level();
    const std::string& get_user_id();
    const std::string& get_user_name();
    bool get_all_members();
    const std::string& get_role_name();
    const std::string& get_discipline_name();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_group();
    const std::string& get_groupDisp();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_role();
    const std::string& get_roleDisp();
    const std::string& get_name();
    const std::string& get_resourcepool_name();
    const std::string& get_fnd0PrimaryObjectID();
    const std::string& get_fnd0PrimaryObjectRevID();
    int get_fnd0constraint();
    const Teamcenter::Soa::Common::DateTime& get_fnd0finish_date();
    double get_fnd0percent_complete();
    double get_fnd0percent_work_complete();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_fnd0ref();
    const std::string& get_fnd0refDisp();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_fnd0schedule_tag();
    const std::string& get_fnd0schedule_tagDisp();
    const Teamcenter::Soa::Common::DateTime& get_fnd0start_date();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_fnd0task_tag();
    const std::string& get_fnd0task_tagDisp();
    int get_fnd0type();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0SecondaryAudit")

   virtual ~Fnd0SecondaryAudit();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
