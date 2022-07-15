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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_EPMTASK_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_EPMTASK_HXX

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


class TCSOACLIENTMNGD_API EPMTask : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    int get_state_value();
    int get_priority();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_task_template();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_parent_process();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_responsible_party();
    const std::string& get_task_name();
    Teamcenter::Soa::Common::AutoPtr<EPMTask> get_parent_task();
    const Teamcenter::Soa::Client::IntVector& get_attachment_types();
    const Teamcenter::Soa::Client::ModelObjectVector& get_attachments();
    const Teamcenter::Soa::Client::ModelObjectVector& get_viewed_by();
    bool get_late_flag();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_named_acl();
    const Teamcenter::Soa::Client::ModelObjectVector& get_recipients();
    const Teamcenter::Soa::Common::DateTime& get_due_date();
    int get_task_duration();
    int get_signoff_quorum();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_active_surrogate();
    const std::string& get_task_result();
    const std::string& get_comments();
    int get_wait_for_all_reviewers();
    const Teamcenter::Soa::Common::DateTime& get_fnd0StartDate();
    const Teamcenter::Soa::Common::DateTime& get_fnd0EndDate();
    int get_fnd0ActualDuration();
    const Teamcenter::Soa::Client::ModelObjectVector& get_valid_signoffs();
    const std::string& get_complete_node_location();
    const Teamcenter::Soa::Client::ModelObjectVector& get_target_attachments();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_root_task();
    bool get_has_surrogate();
    const Teamcenter::Soa::Client::ModelObjectVector& get_root_reference_attachments();
    const std::string& get_resp_party();
    const Teamcenter::Soa::Client::ModelObjectVector& get_comment_attachments();
    const Teamcenter::Soa::Client::StringVector& get_the_task_duration();
    const Teamcenter::Soa::Client::StringVector& get_path_type();
    const Teamcenter::Soa::Client::ModelObjectVector& get_reference_attachments();
    int get_condition_result();
    const Teamcenter::Soa::Client::ModelObjectVector& get_instruction_attachments();
    const Teamcenter::Soa::Client::ModelObjectVector& get_release_status_attachments();
    const Teamcenter::Soa::Client::ModelObjectVector& get_root_target_attachments();
    bool get_is_valid_surrogate();
    const Teamcenter::Soa::Client::ModelObjectVector& get_project_task_attachments();
    const std::string& get_parent_name();
    const Teamcenter::Soa::Client::ModelObjectVector& get_successors();
    const std::string& get_iconKey();
    const std::string& get_job_name();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_next_task();
    bool get_viewed_by_me();
    const Teamcenter::Soa::Client::ModelObjectVector& get_signoff_attachments();
    const Teamcenter::Soa::Client::ModelObjectVector& get_signoff_profiles();
    const std::string& get_task_state();
    const Teamcenter::Soa::Client::ModelObjectVector& get_child_tasks();
    const Teamcenter::Soa::Common::DateTime& get_due_date_project();
    const std::string& get_real_state();
    const std::string& get_start_node_location();
    int get_state();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_previous_task();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_WorkContext_Relation();
    const Teamcenter::Soa::Client::ModelObjectVector& get_epm_subprocesses();
    const Teamcenter::Soa::Client::ModelObjectVector& get_predecessors();
    const Teamcenter::Soa::Client::ModelObjectVector& get_interprocess_task_dependencies();
    const std::string& get_task_type();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_work_context();
    bool get_secure_task();
    const Teamcenter::Soa::Client::ModelObjectVector& get_conflict_tasks();
    const std::string& get_location();
    const Teamcenter::Soa::Client::ModelObjectVector& get_user_all_signoffs();
    bool get_my_signoff_completed();
    int get_num_targets();
    bool get_has_failure_paths();
    const Teamcenter::Soa::Client::StringVector& get_process_paths();
    const Teamcenter::Soa::Client::ModelObjectVector& get_sub_processes();
    const Teamcenter::Soa::Client::ModelObjectVector& get_parent_processes();
    const Teamcenter::Soa::Client::StringVector& get_sub_processes_states();
    const Teamcenter::Soa::Client::StringVector& get_parent_processes_states();
    int get_fnd0MyTaskExecutionStatus();
    const Teamcenter::Soa::Client::StringVector& get_fnd0TaskExecutionStatuses();
    const Teamcenter::Soa::Client::StringVector& get_fnd0MyTaskExecutionErrors();
    const Teamcenter::Soa::Client::ModelObjectVector& get_fnd0WorkflowTaskLogs();
    bool get_fnd0IsValidPerformer();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("EPMTask")

   virtual ~EPMTask();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
