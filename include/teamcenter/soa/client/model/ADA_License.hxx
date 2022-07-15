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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ADA_LICENSE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ADA_LICENSE_HXX

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


class TCSOACLIENTMNGD_API ADA_License : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    const std::string& get_id();
    const std::string& get_reason();
    const Teamcenter::Soa::Common::DateTime& get_expiry();
    const Teamcenter::Soa::Client::StringVector& get_users();
    const Teamcenter::Soa::Client::StringVector& get_groups();
    const Teamcenter::Soa::Common::DateTime& get_lock_date();
    const std::string& get_qualifying_cfr();
    const std::string& get_fnd0license_category();
    const Teamcenter::Soa::Client::StringVector& get_fnd0user_citizenships();
    const Teamcenter::Soa::Client::ModelObjectVector& get_fnd0LicenseChangeAuditLogs();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ADA_License")

   virtual ~ADA_License();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
