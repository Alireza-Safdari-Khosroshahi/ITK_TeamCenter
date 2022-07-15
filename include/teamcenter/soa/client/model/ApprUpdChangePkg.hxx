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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_APPRUPDCHANGEPKG_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_APPRUPDCHANGEPKG_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class ApprUpdByApprRootPkg;
                class ReleaseStatus;


class TCSOACLIENTMNGD_API ApprUpdChangePkg : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    int get_processing_status();
    bool get_processing_blocked();
    const Teamcenter::Soa::Common::DateTime& get_order_by_date();
    const Teamcenter::Soa::Common::DateTime& get_run_date();
    size_t count_secondary_queues();
    Teamcenter::Soa::Common::AutoPtr<ApprUpdByApprRootPkg> get_secondary_queues_at( size_t inx );
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_cloned_for_appearance_root();
    Teamcenter::Soa::Common::AutoPtr<ReleaseStatus> get_release_status();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ApprUpdChangePkg")

   virtual ~ApprUpdChangePkg();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
