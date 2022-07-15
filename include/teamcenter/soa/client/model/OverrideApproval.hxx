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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_OVERRIDEAPPROVAL_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_OVERRIDEAPPROVAL_HXX

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
                class User;
                class User;


class TCSOACLIENTMNGD_API OverrideApproval : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_override_type();
    const std::string& get_override_to_state();
    const std::string& get_override_request_state();
    const std::string& get_override_category();
    const std::string& get_override_reason();
    const std::string& get_override_reason_detail();
    const Teamcenter::Soa::Common::DateTime& get_override_request_date();
    Teamcenter::Soa::Common::AutoPtr<User> get_override_request_user();
    const Teamcenter::Soa::Common::DateTime& get_override_decision_date();
    Teamcenter::Soa::Common::AutoPtr<User> get_override_decision_user();
    const std::string& get_override_decision_comments();
    const std::string& get_fnd0decision_user();
    const std::string& get_fnd0request_user();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("OverrideApproval")

   virtual ~OverrideApproval();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
