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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_APPRQUERYAUDITPKG_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_APPRQUERYAUDITPKG_HXX

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


class TCSOACLIENTMNGD_API ApprQueryAuditPkg : public Teamcenter::Soa::Client::Model::ApprUpdChangePkg
{
public:
    Teamcenter::Soa::Common::AutoPtr<AppearanceRoot> get_appearance_root();
    const Teamcenter::Soa::Common::DateTime& get_queued_date();
    const Teamcenter::Soa::Common::DateTime& get_query_date_arg();
    bool get_query_search_on_unit_no_arg();
    int get_query_unit_no_arg();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ApprQueryAuditPkg")

   virtual ~ApprQueryAuditPkg();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
