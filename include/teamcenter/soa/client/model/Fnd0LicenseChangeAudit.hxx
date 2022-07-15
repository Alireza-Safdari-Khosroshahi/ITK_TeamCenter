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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0LICENSECHANGEAUDIT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0LICENSECHANGEAUDIT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Fnd0AuditLog.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API Fnd0LicenseChangeAudit : public Teamcenter::Soa::Client::Model::Fnd0AuditLog
{
public:
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_fnd0Object();
    const std::string& get_object_name();
    const std::string& get_object_type();
    const std::string& get_id();
    const std::string& get_fnd0EventTypeName();
    const std::string& get_fnd0UserId();
    const std::string& get_fnd0GroupName();
    const std::string& get_fnd0RoleName();
    const Teamcenter::Soa::Common::DateTime& get_fnd0LoggedDate();
    const Teamcenter::Soa::Common::DateTime& get_lock_date();
    const Teamcenter::Soa::Common::DateTime& get_expiry();
    const Teamcenter::Soa::Client::StringVector& get_users();
    const Teamcenter::Soa::Client::StringVector& get_groups();
    const Teamcenter::Soa::Common::DateTime& get_lock_dateOvl();
    const Teamcenter::Soa::Common::DateTime& get_expiryOvl();
    const Teamcenter::Soa::Client::StringVector& get_usersOvl();
    const Teamcenter::Soa::Client::StringVector& get_groupsOvl();
    const std::string& get_fnd0ErrorMessage();
    int get_fnd0ErrorCode();
    const std::string& get_fnd0ObjectDisplayName();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0LicenseChangeAudit")

   virtual ~Fnd0LicenseChangeAudit();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
