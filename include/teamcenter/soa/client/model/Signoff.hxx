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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SIGNOFF_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SIGNOFF_HXX

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
                class GroupMember;
                class GroupMember;


class TCSOACLIENTMNGD_API Signoff : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    int get_decision();
    const Teamcenter::Soa::Common::DateTime& get_decision_date();
    const std::string& get_comments();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_accessor();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_resource_pool();
    int get_originated_from();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_origin_profile();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_origin();
    Teamcenter::Soa::Common::AutoPtr<GroupMember> get_group_member();
    Teamcenter::Soa::Common::AutoPtr<GroupMember> get_active_surrogate();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_profile();
    const std::string& get_object_name();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_signoff_member();
    bool get_user_access();
    int get_signoff_type();
    bool get_is_valid_surrogate();
    bool get_is_mine_to_perform();
    const std::string& get_object_type();
    int get_signoff_action();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Signoff")

   virtual ~Signoff();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
