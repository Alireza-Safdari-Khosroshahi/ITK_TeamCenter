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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_IMANVOLUME_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_IMANVOLUME_HXX

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


class TCSOACLIENTMNGD_API ImanVolume : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    const std::string& get_volume_name();
    const std::string& get_vms_path_name();
    const std::string& get_unix_path_name();
    const std::string& get_wnt_path_name();
    const std::string& get_node_name();
    int get_machine_type();
    int get_protection_mode();
    const Teamcenter::Soa::Client::ModelObjectVector& get_users();
    const Teamcenter::Soa::Client::ModelObjectVector& get_revoked_users();
    const Teamcenter::Soa::Client::StringVector& get_user_paths();
    const std::string& get_shadow_vms_path_name();
    const std::string& get_shadow_unix_path_name();
    const std::string& get_shadow_wnt_path_name();
    const std::string& get_shadow_node_name();
    const Teamcenter::Soa::Client::ModelObjectVector& get_fnd0OrganizationAuditLogs();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ImanVolume")

   virtual ~ImanVolume();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
