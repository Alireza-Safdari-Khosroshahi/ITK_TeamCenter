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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_WORKSPACEOBJECT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_WORKSPACEOBJECT_HXX

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
                class ReleaseStatus;
                class WorkspaceObjectThread;
                class Group;
                class Project;
                class Project;


class TCSOACLIENTMNGD_API WorkspaceObject : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    const std::string& get_object_name();
    const std::string& get_object_desc();
    const std::string& get_object_type();
    const std::string& get_object_application();
    int get_revision_number();
    int get_revision_limit();
    const Teamcenter::Soa::Client::ModelObjectVector& get_process_stage_list();
    const Teamcenter::Soa::Common::DateTime& get_date_released();
    const std::string& get_ip_classification();
    const Teamcenter::Soa::Client::ModelObjectVector& get_license_list();
    const std::string& get_gov_classification();
    const Teamcenter::Soa::Client::StringVector& get_ead_paragraph();
    int get_active_seq();
    size_t count_release_status_list();
    Teamcenter::Soa::Common::AutoPtr<ReleaseStatus> get_release_status_list_at( size_t inx );
    Teamcenter::Soa::Common::AutoPtr<WorkspaceObjectThread> get_wso_thread();
    Teamcenter::Soa::Common::AutoPtr<Group> get_owning_organization();
    size_t count_project_list();
    Teamcenter::Soa::Common::AutoPtr<Project> get_project_list_at( size_t inx );
    Teamcenter::Soa::Common::AutoPtr<Project> get_owning_project();
    const Teamcenter::Soa::Client::ModelObjectVector& get_release_statuses();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_reservation();
    const std::string& get_publication_sites();
    const std::string& get_export_sites();
    const std::string& get_project_ids();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_last_release_status();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_current_job();
    const std::string& get_current_desc();
    const std::string& get_checked_out_change_id();
    bool get_has_trace_link();
    const std::string& get_process_stage();
    const Teamcenter::Soa::Client::ModelObjectVector& get_external_apps();
    const std::string& get_projects_list();
    const std::string& get_ics_subclass_name();
    const std::string& get_ics_classified();
    const std::string& get_based_on();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_item_revision();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_change();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_checked_out_user();
    bool get_is_modifiable();
    const std::string& get_protection();
    const std::string& get_current_name();
    const Teamcenter::Soa::Common::DateTime& get_proj_assign_mod_date();
    const std::string& get_expl_checkout();
    const std::string& get_checked_out();
    const Teamcenter::Soa::Common::DateTime& get_checked_out_date();
    bool get_ip_logged();
    bool get_user_can_unmanage();
    const std::string& get_null_logical();
    const std::string& get_null_string();
    const Teamcenter::Soa::Client::ModelObjectVector& get_FND_TraceLink();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Fnd0ShapeRelation();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Fnd0DiagramTmplRelation();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Fnd0Diagram_Attaches();
    const Teamcenter::Soa::Client::ModelObjectVector& get_fnd0defining_objects();
    const Teamcenter::Soa::Client::ModelObjectVector& get_fnd0complying_objects();
    bool get_fnd0IsCheckoutable();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Fnd0DiagramSnapshot();
    const Teamcenter::Soa::Client::ModelObjectVector& get_fnd0WorkflowAuditLogs();
    const Teamcenter::Soa::Client::ModelObjectVector& get_fnd0GeneralAuditLogs();
    const Teamcenter::Soa::Client::ModelObjectVector& get_fnd0LicenseExportAuditLogs();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("WorkspaceObject")

   virtual ~WorkspaceObject();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
