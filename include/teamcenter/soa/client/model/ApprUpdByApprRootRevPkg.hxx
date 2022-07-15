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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_APPRUPDBYAPPRROOTREVPKG_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_APPRUPDBYAPPRROOTREVPKG_HXX

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
                class ApprUpdRevViewImpactsRoot;


class TCSOACLIENTMNGD_API ApprUpdByApprRootRevPkg : public Teamcenter::Soa::Client::Model::ApprUpdByApprRootPkg
{
public:
    size_t count_aurvir_list();
    Teamcenter::Soa::Common::AutoPtr<ApprUpdRevViewImpactsRoot> get_aurvir_list_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ApprUpdByApprRootRevPkg")

   virtual ~ApprUpdByApprRootRevPkg();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
