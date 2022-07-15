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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0VALDATARESULT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0VALDATARESULT_HXX

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
                class OverrideApproval;


class TCSOACLIENTMNGD_API Fnd0ValDataResult : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    const std::string& get_fnd0parent_valdata_name();
    const std::string& get_fnd0parent_validation_id();
    const std::string& get_fnd0valdata_name();
    const std::string& get_fnd0validation_id();
    bool get_fnd0validation_result();
    int get_fnd0validation_status();
    const std::string& get_fnd0validation_comments();
    Teamcenter::Soa::Common::AutoPtr<OverrideApproval> get_fnd0override_approval_data();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_fnd0_owning_obj_of_result();
    bool get_fnd0_final_val_result();
    const std::string& get_fnd0override_to_state();
    const std::string& get_fnd0override_request_state();
    const std::string& get_fnd0override_category();
    const std::string& get_fnd0override_reason();
    const std::string& get_fnd0override_reason_detail();
    const Teamcenter::Soa::Common::DateTime& get_fnd0override_request_date();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_fnd0override_request_user();
    const Teamcenter::Soa::Common::DateTime& get_fnd0override_decision_date();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_fnd0override_decision_user();
    const std::string& get_fnd0override_decision_comments();
    const std::string& get_fnd0override_type();
    const std::string& get_fnd0request_user();
    const std::string& get_fnd0decision_user();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0ValDataResult")

   virtual ~Fnd0ValDataResult();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
