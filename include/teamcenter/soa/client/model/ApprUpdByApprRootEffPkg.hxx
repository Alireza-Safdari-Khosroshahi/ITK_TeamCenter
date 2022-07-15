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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_APPRUPDBYAPPRROOTEFFPKG_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_APPRUPDBYAPPRROOTEFFPKG_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ApprUpdByApprRootPkg.hxx>

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
                class ApprRevRelation;


class TCSOACLIENTMNGD_API ApprUpdByApprRootEffPkg : public Teamcenter::Soa::Client::Model::ApprUpdByApprRootPkg
{
public:
    Teamcenter::Soa::Common::AutoPtr<AppearanceRoot> get_appr_root();
    size_t count_impacted_arros();
    Teamcenter::Soa::Common::AutoPtr<ApprRevRelation> get_impacted_arros_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ApprUpdByApprRootEffPkg")

   virtual ~ApprUpdByApprRootEffPkg();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
