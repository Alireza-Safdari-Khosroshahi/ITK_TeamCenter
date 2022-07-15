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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_HSM_POLICY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_HSM_POLICY_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Migration_Policy.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API HSM_Policy : public Teamcenter::Soa::Client::Model::Migration_Policy
{
public:
    int get_migrate_from_tier();
    int get_migrate_to_tier();
    bool get_migrate_refile();
    bool get_un_migrate_file();
    int get_file_access_times();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("HSM_Policy")

   virtual ~HSM_Policy();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
