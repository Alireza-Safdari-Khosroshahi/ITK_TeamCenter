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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PWT_CRBDATA_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PWT_CRBDATA_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/model/GmoMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class User;
                class User;
                class User;
                class User;


class TCSOAGMOMODELMNGD_API PWT_CRBData : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    bool get_chng_exceed_limit();
    Teamcenter::Soa::Common::AutoPtr<User> get_appr_mgr_tag();
    bool get_chng_req_ctg_fund();
    Teamcenter::Soa::Common::AutoPtr<User> get_secton_lead_tag();
    Teamcenter::Soa::Common::AutoPtr<User> get_cfo_tag();
    const Teamcenter::Soa::Client::StringVector& get_affected_carlines();
    size_t count_product_mgr_tag();
    Teamcenter::Soa::Common::AutoPtr<User> get_product_mgr_tag_at( size_t inx );
    const Teamcenter::Soa::Client::StringVector& get_impact_natur();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("PWT_CRBData")

   virtual ~PWT_CRBData();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
