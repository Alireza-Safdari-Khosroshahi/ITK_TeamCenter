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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_VALIDATIONRESULT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_VALIDATIONRESULT_HXX

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
                class Dataset;
                class ValDataRevision;
                class ValidationData;
                class ValidationParams;
                class OverrideApproval;


class TCSOACLIENTMNGD_API ValidationResult : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    bool get_validation_result();
    int get_validation_status();
    const std::string& get_validation_comments();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_validation_target();
    const Teamcenter::Soa::Common::DateTime& get_validation_date();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_validation_user();
    bool get_validation_is_adhoc();
    size_t count_validation_report();
    Teamcenter::Soa::Common::AutoPtr<Dataset> get_validation_report_at( size_t inx );
    const std::string& get_validation_id();
    const std::string& get_validation_user_n();
    const std::string& get_object_name();
    int get_result_state_flag();
    Teamcenter::Soa::Common::AutoPtr<ValDataRevision> get_valdata_revision();
    Teamcenter::Soa::Common::AutoPtr<ValidationData> get_validation_data_obj();
    Teamcenter::Soa::Common::AutoPtr<ValidationParams> get_validation_parameters();
    Teamcenter::Soa::Common::AutoPtr<OverrideApproval> get_override_approval_data();
    const Teamcenter::Soa::Client::StringVector& get_fnd0child_valdata_names();
    const Teamcenter::Soa::Client::StringVector& get_fnd0child_validation_ids();
    const Teamcenter::Soa::Client::BoolVector& get_fnd0child_results();
    const std::string& get_validation_utility_name();
    const std::string& get_validation_application();
    bool get_validation_is_up_to_date();
    const std::string& get_validation_name();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_Validation();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_target_item_rev();
    const std::string& get_override_type();
    const std::string& get_override_to_state();
    const std::string& get_override_request_state();
    const std::string& get_override_category();
    const std::string& get_override_reason();
    const std::string& get_override_reason_detail();
    const Teamcenter::Soa::Common::DateTime& get_override_request_date();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_override_request_user();
    const Teamcenter::Soa::Common::DateTime& get_override_decision_date();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_override_decision_user();
    const std::string& get_override_decision_comments();
    const std::string& get_fnd0_valdata_checker_name();
    bool get_fnd0_final_val_result();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_fnd0_owning_obj_of_result();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ValidationResult")

   virtual ~ValidationResult();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
