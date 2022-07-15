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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MIGRATION_DISTRIBUTION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MIGRATION_DISTRIBUTION_HXX

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


class TCSOACLIENTMNGD_API Migration_Distribution : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    const Teamcenter::Soa::Common::DateTime& get_files_migrated_before();
    const Teamcenter::Soa::Common::DateTime& get_files_migrated_after();
    const std::string& get_src_vol_name();
    const std::string& get_dest_vol_name();
    int get_migrate_from_tier();
    int get_migrate_to_tier();
    const Teamcenter::Soa::Client::StringVector& get_policy_names();
    const Teamcenter::Soa::Client::IntVector& get_num_files();
    const Teamcenter::Soa::Client::DoubleVector& get_policy_migration();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Migration_Distribution")

   virtual ~Migration_Distribution();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
