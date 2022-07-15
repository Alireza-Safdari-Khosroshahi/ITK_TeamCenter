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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_VM_POLICY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_VM_POLICY_HXX

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
                class ImanVolume;
                class ImanVolume;


class TCSOACLIENTMNGD_API VM_Policy : public Teamcenter::Soa::Client::Model::Migration_Policy
{
public:
    Teamcenter::Soa::Common::AutoPtr<ImanVolume> get_src_vol_tag();
    Teamcenter::Soa::Common::AutoPtr<ImanVolume> get_dest_vol_tag();
    int get_migration_option();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("VM_Policy")

   virtual ~VM_Policy();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
