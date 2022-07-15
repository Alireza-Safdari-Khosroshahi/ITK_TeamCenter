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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_APPRUPDBOOTSTRAPPKG_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_APPRUPDBOOTSTRAPPKG_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ApprUpdChangePkg.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class AppearanceRoot;


class TCSOACLIENTMNGD_API ApprUpdBootstrapPkg : public Teamcenter::Soa::Client::Model::ApprUpdChangePkg
{
public:
    Teamcenter::Soa::Common::AutoPtr<AppearanceRoot> get_appr_root();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ApprUpdBootstrapPkg")

   virtual ~ApprUpdBootstrapPkg();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
