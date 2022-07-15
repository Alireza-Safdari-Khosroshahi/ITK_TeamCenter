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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_HSM_INFO_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_HSM_INFO_HXX

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


class TCSOACLIENTMNGD_API HSM_Info : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_policy_name();
    bool get_migrate_refile();
    int get_migrate_from_tier();
    int get_migrate_to_tier();
    int get_accessed_times();
    const Teamcenter::Soa::Common::DateTime& get_last_migrated_date();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("HSM_Info")

   virtual ~HSM_Info();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
