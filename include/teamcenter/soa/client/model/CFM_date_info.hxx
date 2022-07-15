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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CFM_DATE_INFO_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CFM_DATE_INFO_HXX

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
                class POM_user;


class TCSOACLIENTMNGD_API CFM_date_info : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_id();
    const Teamcenter::Soa::Common::DateTime& get_auth_date();
    const Teamcenter::Soa::Common::DateTimeVector& get_eff_date();
    Teamcenter::Soa::Common::AutoPtr<POM_user> get_auth_user();
    const std::string& get_effectivity_id();
    const std::string& get_range_text();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CFM_date_info")

   virtual ~CFM_date_info();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
