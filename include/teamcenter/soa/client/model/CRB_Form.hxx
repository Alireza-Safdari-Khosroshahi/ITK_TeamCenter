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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CRB_FORM_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CRB_FORM_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Form.hxx>

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


class TCSOAGMOMODELMNGD_API CRB_Form : public Teamcenter::Soa::Client::Model::Form
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


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CRB_Form")

   virtual ~CRB_Form();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
