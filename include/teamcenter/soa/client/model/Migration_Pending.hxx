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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MIGRATION_PENDING_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MIGRATION_PENDING_HXX

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
                class Migration_Policy;
                class ImanVolume;
                class ImanVolume;


class TCSOACLIENTMNGD_API Migration_Pending : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    Teamcenter::Soa::Common::AutoPtr<Migration_Policy> get_policy_tag();
    bool get_purge_immediately();
    int get_low_water_mark();
    int get_high_water_mark();
    int get_migrate_from_tier();
    int get_migrate_to_tier();
    Teamcenter::Soa::Common::AutoPtr<ImanVolume> get_src_vol_tag();
    Teamcenter::Soa::Common::AutoPtr<ImanVolume> get_dest_vol_tag();
    const Teamcenter::Soa::Common::DateTime& get_policy_last_mod_date();
    bool get_migrate_refile();
    const Teamcenter::Soa::Client::ModelObjectVector& get_file_tags();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Migration_Pending")

   virtual ~Migration_Pending();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
