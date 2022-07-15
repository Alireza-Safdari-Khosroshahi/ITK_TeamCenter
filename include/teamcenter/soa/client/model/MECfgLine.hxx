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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MECFGLINE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MECFGLINE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/RuntimeBusinessObject.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API MECfgLine : public Teamcenter::Soa::Client::Model::RuntimeBusinessObject
{
public:
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_me_cl_key();
    int get_me_cl_child_count();
    bool get_me_cl_has_children();
    const Teamcenter::Soa::Client::ModelObjectVector& get_me_cl_child_lines();
    bool get_me_cl_is_orphan();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_me_cl_get_actual_parent();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_me_cl_relation();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_me_cl_window();
    const Teamcenter::Soa::Client::ModelObjectVector& get_me_cl_descendant_lines();
    const std::string& get_me_cl_display_string();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_me_cl_parent();
    bool get_me_cl_is_descendant();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_me_cl_wso();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_me_cl_source();
    const std::string& get_me_cl_acl_bits();
    const std::string& get_me_cl_creation_date();
    const std::string& get_me_cl_archive_date();
    const std::string& get_me_cl_last_mod_date();
    const std::string& get_me_cl_backup_date();
    const std::string& get_me_cl_owning_group();
    const std::string& get_me_cl_last_mod_user();
    const std::string& get_me_cl_owning_user();
    const std::string& get_me_cl_timestamp();
    const std::string& get_me_cl_pid();
    const std::string& get_me_cl_object_properties();
    const std::string& get_me_cl_lsd();
    const std::string& get_me_cl_owning_site();
    const std::string& get_me_cl_object_name();
    const std::string& get_me_cl_object_desc();
    const std::string& get_me_cl_object_type();
    const std::string& get_me_cl_object_application();
    const std::string& get_me_cl_revision_number();
    const std::string& get_me_cl_revision_limit();
    const std::string& get_me_cl_process_stage_list();
    const std::string& get_me_cl_date_released();
    const std::string& get_me_cl_ip_classification();
    const std::string& get_me_cl_license_list();
    const std::string& get_me_cl_gov_classification();
    const std::string& get_me_cl_ead_paragraph();
    const std::string& get_me_cl_active_seq();
    const std::string& get_me_cl_release_status_list();
    const std::string& get_me_cl_wso_thread();
    const std::string& get_me_cl_owning_organization();
    const std::string& get_me_cl_project_list();
    const std::string& get_me_cl_owning_project();
    const std::string& get_me_cl_object_string();
    const std::string& get_me_cl_fnd0objectId();
    const std::string& get_me_cl_fnd0mfkinfo();
    const std::string& get_me_cl_IMAN_based_on();
    const std::string& get_me_cl_release_statuses();
    const std::string& get_me_cl_reservation();
    const std::string& get_me_cl_publication_sites();
    const std::string& get_me_cl_export_sites();
    const std::string& get_me_cl_project_ids();
    const std::string& get_me_cl_last_release_status();
    const std::string& get_me_cl_current_job();
    const std::string& get_me_cl_current_desc();
    const std::string& get_me_cl_checked_out_change_id();
    const std::string& get_me_cl_has_trace_link();
    const std::string& get_me_cl_process_stage();
    const std::string& get_me_cl_external_apps();
    const std::string& get_me_cl_projects_list();
    const std::string& get_me_cl_ics_subclass_name();
    const std::string& get_me_cl_ics_classified();
    const std::string& get_me_cl_based_on();
    const std::string& get_me_cl_item_revision();
    const std::string& get_me_cl_change();
    const std::string& get_me_cl_checked_out_user();
    const std::string& get_me_cl_is_modifiable();
    const std::string& get_me_cl_protection();
    const std::string& get_me_cl_current_name();
    const std::string& get_me_cl_proj_assign_mod_date();
    const std::string& get_me_cl_expl_checkout();
    const std::string& get_me_cl_checked_out();
    const std::string& get_me_cl_checked_out_date();
    const std::string& get_me_cl_ip_logged();
    const std::string& get_me_cl_user_can_unmanage();
    const std::string& get_me_cl_null_logical();
    const std::string& get_me_cl_null_string();
    const std::string& get_me_cl_FND_TraceLink();
    const std::string& get_me_cl_Fnd0ShapeRelation();
    const std::string& get_me_cl_Fnd0DiagramTmplRelation();
    const std::string& get_me_cl_Fnd0Diagram_Attaches();
    const std::string& get_me_cl_fnd0defining_objects();
    const std::string& get_me_cl_fnd0complying_objects();
    const std::string& get_me_cl_fnd0IsCheckoutable();
    const std::string& get_me_cl_Fnd0DiagramSnapshot();
    const std::string& get_me_cl_fnd0WorkflowAuditLogs();
    const std::string& get_me_cl_fnd0GeneralAuditLogs();
    const std::string& get_me_cl_fnd0LicenseExportAuditLogs();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("MECfgLine")

   virtual ~MECfgLine();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
