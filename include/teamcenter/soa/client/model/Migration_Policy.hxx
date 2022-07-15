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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MIGRATION_POLICY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MIGRATION_POLICY_HXX

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
                class ImanQuery;


class TCSOACLIENTMNGD_API Migration_Policy : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    const std::string& get_policy_name();
    const std::string& get_policy_description();
    bool get_is_active();
    bool get_purge_immediately();
    int get_low_water_mark();
    int get_high_water_mark();
    bool get_migrate_checkedout_file();
    bool get_migrate_inprocess_file();
    bool get_migrate_remote_file();
    const Teamcenter::Soa::Common::DateTime& get_file_accessed_before();
    const Teamcenter::Soa::Common::DateTime& get_file_accessed_after();
    int get_file_range_from();
    int get_file_range_to();
    int get_file_size_units();
    Teamcenter::Soa::Common::AutoPtr<ImanQuery> get_query_tag();
    const Teamcenter::Soa::Client::StringVector& get_query_entries();
    const Teamcenter::Soa::Client::StringVector& get_query_values();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Migration_Policy")

   virtual ~Migration_Policy();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
