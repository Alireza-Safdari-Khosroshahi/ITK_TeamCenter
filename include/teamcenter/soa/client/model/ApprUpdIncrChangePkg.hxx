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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_APPRUPDINCRCHANGEPKG_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_APPRUPDINCRCHANGEPKG_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ApprUpdStructureChangePkg.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class ItemRevision;


class TCSOACLIENTMNGD_API ApprUpdIncrChangePkg : public Teamcenter::Soa::Client::Model::ApprUpdStructureChangePkg
{
public:
    Teamcenter::Soa::Common::AutoPtr<ItemRevision> get_approved_incr_change_rev();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ApprUpdIncrChangePkg")

   virtual ~ApprUpdIncrChangePkg();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
