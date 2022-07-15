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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_EPMTASKTEMPLATE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_EPMTASKTEMPLATE_HXX

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
                class ImanType;
                class EPMAction;


class TCSOACLIENTMNGD_API EPMTaskTemplate : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    const std::string& get_template_name();
    const Teamcenter::Soa::Client::StringVector& get_description();
    const std::string& get_icon_key();
    Teamcenter::Soa::Common::AutoPtr<EPMTaskTemplate> get_parent_task_template();
    size_t count_dependency_task_templates();
    Teamcenter::Soa::Common::AutoPtr<EPMTaskTemplate> get_dependency_task_templates_at( size_t inx );
    const Teamcenter::Soa::Client::IntVector& get_dependency_task_actions();
    int get_signoff_quorum();
    int get_stage();
    int get_template_classification();
    const std::string& get_location();
    Teamcenter::Soa::Common::AutoPtr<ImanType> get_object_type();
    bool get_show_in_process_stage();
    int get_wait_for_all_reviewers();
    const std::string& get_fnd0origin_uid();
    size_t count_actions();
    Teamcenter::Soa::Common::AutoPtr<EPMAction> get_actions_at( size_t inx );
    bool get_fnd0ExecuteAsync();
    const Teamcenter::Soa::Client::ModelObjectVector& get_resume_action_rules();
    const std::string& get_location1();
    const std::string& get_complete_node_location();
    const Teamcenter::Soa::Client::ModelObjectVector& get_add_attachment_action_handlers();
    const Teamcenter::Soa::Client::ModelObjectVector& get_abort_action_rules();
    const Teamcenter::Soa::Client::ModelObjectVector& get_start_action_handlers();
    const Teamcenter::Soa::Client::ModelObjectVector& get_action_handlers();
    const Teamcenter::Soa::Client::ModelObjectVector& get_assign_action_handlers();
    const Teamcenter::Soa::Client::ModelObjectVector& get_user_action_handlers();
    const Teamcenter::Soa::Client::ModelObjectVector& get_assignment_lists();
    const std::string& get_object_name();
    const Teamcenter::Soa::Client::ModelObjectVector& get_promote_action_handlers();
    const std::string& get_named_acl();
    const Teamcenter::Soa::Client::ModelObjectVector& get_assign_approver_action_rules();
    const Teamcenter::Soa::Client::ModelObjectVector& get_add_attachment_action_rules();
    const Teamcenter::Soa::Client::ModelObjectVector& get_perform_action_handlers();
    int get_template_stage();
    const Teamcenter::Soa::Client::ModelObjectVector& get_promote_action_rules();
    const Teamcenter::Soa::Client::ModelObjectVector& get_undo_action_handlers();
    const Teamcenter::Soa::Client::ModelObjectVector& get_rem_attachment_action_handlers();
    const Teamcenter::Soa::Client::StringVector& get_the_task_duration();
    const Teamcenter::Soa::Client::StringVector& get_path_type();
    const Teamcenter::Soa::Client::ModelObjectVector& get_refuse_action_rules();
    const Teamcenter::Soa::Client::ModelObjectVector& get_demote_action_rules();
    const Teamcenter::Soa::Client::ModelObjectVector& get_suspend_action_rules();
    const std::string& get_object_desc();
    const Teamcenter::Soa::Client::ModelObjectVector& get_start_successors();
    const Teamcenter::Soa::Client::ModelObjectVector& get_reject_action_handlers();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_based_on();
    const Teamcenter::Soa::Client::ModelObjectVector& get_remove_attachment_action_rules();
    bool get_has_subtask_template();
    const Teamcenter::Soa::Client::ModelObjectVector& get_successors();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_parent_task_template1();
    const Teamcenter::Soa::Client::ModelObjectVector& get_skip_action_rules();
    bool get_show_in_process_stage_list();
    const Teamcenter::Soa::Client::ModelObjectVector& get_suspend_action_handlers();
    const Teamcenter::Soa::Client::ModelObjectVector& get_demote_action_handlers();
    const Teamcenter::Soa::Client::ModelObjectVector& get_refuse_action_handlers();
    const Teamcenter::Soa::Client::ModelObjectVector& get_start_action_rules();
    const Teamcenter::Soa::Client::ModelObjectVector& get_perform_action_rules();
    const Teamcenter::Soa::Client::ModelObjectVector& get_complete_action_handlers();
    const Teamcenter::Soa::Client::ModelObjectVector& get_undo_action_rules();
    const Teamcenter::Soa::Client::ModelObjectVector& get_reject_action_rules();
    const Teamcenter::Soa::Client::ModelObjectVector& get_complete_predecessors();
    const Teamcenter::Soa::Client::ModelObjectVector& get_resume_action_handlers();
    const Teamcenter::Soa::Client::ModelObjectVector& get_complete_action_rules();
    const Teamcenter::Soa::Client::BoolVector& get_flowline_conditions();
    const Teamcenter::Soa::Client::ModelObjectVector& get_rules();
    const Teamcenter::Soa::Client::ModelObjectVector& get_abort_action_handlers();
    const Teamcenter::Soa::Client::ModelObjectVector& get_approve_action_rules();
    const Teamcenter::Soa::Client::ModelObjectVector& get_flowline_pred_tasks();
    const std::string& get_start_node_location();
    const Teamcenter::Soa::Client::ModelObjectVector& get_user_action_rules();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_process_template();
    const Teamcenter::Soa::Client::ModelObjectVector& get_predecessors();
    const Teamcenter::Soa::Client::ModelObjectVector& get_fail_predecessors();
    const Teamcenter::Soa::Client::ModelObjectVector& get_restart_predecessors();
    const Teamcenter::Soa::Client::ModelObjectVector& get_refail_predecessors();
    const Teamcenter::Soa::Client::ModelObjectVector& get_recipients();
    const Teamcenter::Soa::Client::ModelObjectVector& get_assign_action_rules();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_root_task_template();
    const Teamcenter::Soa::Client::ModelObjectVector& get_subtask_template();
    const std::string& get_task_type();
    const Teamcenter::Soa::Client::ModelObjectVector& get_approve_action_handlers();
    const Teamcenter::Soa::Client::ModelObjectVector& get_assign_approve_action_handlers();
    const Teamcenter::Soa::Client::ModelObjectVector& get_skip_action_handlers();
    bool get_parent_predecessor();
    const std::string& get_fnd0publication_sites();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("EPMTaskTemplate")

   virtual ~EPMTaskTemplate();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
