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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0LICENSEUSAGE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0LICENSEUSAGE_HXX

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


class TCSOACLIENTMNGD_API Fnd0LicenseUsage : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_fnd0user_id();
    int get_fnd0month();
    int get_fnd0year();
    int get_fnd0usage_days();
    double get_fnd0used_hours();
    int get_fnd0number_of_logins();
    int get_fnd0number_denials();
    const std::string& get_fnd0usage_violation_reason();
    double get_fnd0grace_hours();
    int get_fnd0grace_days();
    const Teamcenter::Soa::Common::DateTime& get_fnd0login_time();
    bool get_fnd0usage_violation();
    int get_fnd0grace_logins();
    const std::string& get_fnd0feature_keys();
    int get_fnd0not_released_lic_count();
    bool get_fnd0max_day_usage();
    const Teamcenter::Soa::Client::StringVector& get_fnd0max_value_reason();
    const Teamcenter::Soa::Common::DateTime& get_fnd0last_usage_record_date();
    double get_fnd0last_record_usage_hours();
    const std::string& get_fnd0seat_level();
    const std::string& get_fnd0home_site();
    const std::string& get_fnd0pseudo_user_id();
    const Teamcenter::Soa::Client::StringVector& get_fnd0license_bundles();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0LicenseUsage")

   virtual ~Fnd0LicenseUsage();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
