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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_APPRSETROOTSTATUSPKG_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_APPRSETROOTSTATUSPKG_HXX

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


class TCSOACLIENTMNGD_API ApprSetRootStatusPkg : public Teamcenter::Soa::Client::Model::ApprUpdChangePkg
{
public:
    const Teamcenter::Soa::Common::DateTime& get_queue_date();
    Teamcenter::Soa::Common::AutoPtr<AppearanceRoot> get_appearance_root();
    int get_target_status();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ApprSetRootStatusPkg")

   virtual ~ApprSetRootStatusPkg();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
