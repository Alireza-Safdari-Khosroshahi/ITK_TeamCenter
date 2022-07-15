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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CFGACTIVITYLINE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CFGACTIVITYLINE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/CfgAttachmentLine.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API CfgActivityLine : public Teamcenter::Soa::Client::Model::CfgAttachmentLine
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_al_activity_tool_bl_list();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_al_activity_oper_bl();
    double get_al_activity_duration_time();
    double get_al_activity_work_time();
    const std::string& get_al_activity_acl_bits();
    const std::string& get_al_activity_creation_date();
    const std::string& get_al_activity_archive_date();
    const std::string& get_al_activity_last_mod_date();
    const std::string& get_al_activity_backup_date();
    const std::string& get_al_activity_owning_group();
    const std::string& get_al_activity_last_mod_user();
    const std::string& get_al_activity_owning_user();
    const std::string& get_al_activity_timestamp();
    const std::string& get_al_activity_pid();
    const std::string& get_al_activity_object_properties();
    const std::string& get_al_activity_lsd();
    const std::string& get_al_activity_owning_site();
    const std::string& get_al_activity_object_name();
    const std::string& get_al_activity_object_desc();
    const std::string& get_al_activity_object_type();
    const std::string& get_al_activity_object_application();
    const std::string& get_al_activity_revision_number();
    const std::string& get_al_activity_revision_limit();
    const std::string& get_al_activity_process_stage_list();
    const std::string& get_al_activity_date_released();
    const std::string& get_al_activity_ip_classification();
    const std::string& get_al_activity_license_list();
    const std::string& get_al_activity_gov_classification();
    const std::string& get_al_activity_ead_paragraph();
    const std::string& get_al_activity_active_seq();
    const std::string& get_al_activity_release_status_list();
    const std::string& get_al_activity_wso_thread();
    const std::string& get_al_activity_owning_organization();
    const std::string& get_al_activity_project_list();
    const std::string& get_al_activity_owning_project();
    const std::string& get_al_activity_sort_order();
    const std::string& get_al_activity_sort_criteria();
    const std::string& get_al_activity_contents();
    const std::string& get_al_activity_time();
    const std::string& get_al_activity_start_time();
    const std::string& get_al_activity_pred_list();
    const std::string& get_al_activity_tool_list();
    const std::string& get_al_activity_act_location();
    const std::string& get_al_activity_long_description();
    const std::string& get_al_activity_seq_no();
    const std::string& get_al_activity_time_system_code();
    const std::string& get_al_activity_time_system_category();
    const std::string& get_al_activity_simulated_time();
    const std::string& get_al_activity_time_system_unit_time();
    const std::string& get_al_activity_time_system_frequency();
    const std::string& get_al_activity_Mfg0equivalence_id();
    const std::string& get_al_activity_Mfg0has_origin();
    const std::string& get_al_activity_object_string();
    const std::string& get_al_activity_fnd0objectId();
    const std::string& get_al_activity_fnd0mfkinfo();
    const std::string& get_al_activity_release_statuses();
    const std::string& get_al_activity_reservation();
    const std::string& get_al_activity_publication_sites();
    const std::string& get_al_activity_export_sites();
    const std::string& get_al_activity_project_ids();
    const std::string& get_al_activity_last_release_status();
    const std::string& get_al_activity_current_job();
    const std::string& get_al_activity_current_desc();
    const std::string& get_al_activity_checked_out_change_id();
    const std::string& get_al_activity_has_trace_link();
    const std::string& get_al_activity_process_stage();
    const std::string& get_al_activity_external_apps();
    const std::string& get_al_activity_projects_list();
    const std::string& get_al_activity_ics_subclass_name();
    const std::string& get_al_activity_ics_classified();
    const std::string& get_al_activity_based_on();
    const std::string& get_al_activity_item_revision();
    const std::string& get_al_activity_change();
    const std::string& get_al_activity_checked_out_user();
    const std::string& get_al_activity_is_modifiable();
    const std::string& get_al_activity_protection();
    const std::string& get_al_activity_current_name();
    const std::string& get_al_activity_proj_assign_mod_date();
    const std::string& get_al_activity_expl_checkout();
    const std::string& get_al_activity_checked_out();
    const std::string& get_al_activity_checked_out_date();
    const std::string& get_al_activity_ip_logged();
    const std::string& get_al_activity_user_can_unmanage();
    const std::string& get_al_activity_null_logical();
    const std::string& get_al_activity_null_string();
    const std::string& get_al_activity_fnd0defining_objects();
    const std::string& get_al_activity_fnd0complying_objects();
    const std::string& get_al_activity_fnd0IsCheckoutable();
    const std::string& get_al_activity_fnd0WorkflowAuditLogs();
    const std::string& get_al_activity_fnd0GeneralAuditLogs();
    const std::string& get_al_activity_fnd0LicenseExportAuditLogs();
    const std::string& get_al_activity_IMAN_based_on();
    const std::string& get_al_activity_FND_TraceLink();
    const std::string& get_al_activity_Fnd0ShapeRelation();
    const std::string& get_al_activity_Fnd0DiagramTmplRelation();
    const std::string& get_al_activity_Fnd0Diagram_Attaches();
    const std::string& get_al_activity_Fnd0DiagramSnapshot();
    const std::string& get_al_activity_IMAN_external_object_link();
    const std::string& get_al_activity_min_start_time();
    const std::string& get_al_activity_calc_time();
    const std::string& get_al_activity_calc_start_time();
    const std::string& get_al_activity_nc_tool_number();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CfgActivityLine")

   virtual ~CfgActivityLine();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
