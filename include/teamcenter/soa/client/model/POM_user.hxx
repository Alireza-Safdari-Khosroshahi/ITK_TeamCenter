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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_POM_USER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_POM_USER_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_system_class.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API POM_user : public Teamcenter::Soa::Client::Model::POM_system_class
{
public:
    const std::string& get_user_id();
    const std::string& get_password();
    const std::string& get_newpassword();
    const std::string& get_user_name();
    int get_status();
    int get_def_acl();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_default_group();
    const Teamcenter::Soa::Common::DateTime& get_last_login_time();
    const Teamcenter::Soa::Common::DateTime& get_user_last_sync_date();
    int get_user_data_source();
    int get_license_level();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("POM_user")

   virtual ~POM_user();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
