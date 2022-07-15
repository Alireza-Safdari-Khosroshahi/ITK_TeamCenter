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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_COMMON_ENGINEERING_FORM_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_COMMON_ENGINEERING_FORM_HXX

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


class TCSOAGMOMODELMNGD_API Common_Engineering_Form : public Teamcenter::Soa::Client::Model::Form
{
public:
    const std::string& get_chng_category();
    const std::string& get_engg_proj_num();
    const std::string& get_engg_proj_desc();
    const std::string& get_temp_ar_num();
    const std::string& get_temp_ar_desc();
    const std::string& get_final_ar_num();
    const std::string& get_final_ar_desc();
    const std::string& get_chng_subject();
    const std::string& get_chng_reason();
    const std::string& get_chng_priority();
    const Teamcenter::Soa::Client::StringVector& get_chng_desc();
    const std::string& get_chng_resp_engineer();
    const std::string& get_resp_engineer_site();
    const Teamcenter::Soa::Common::DateTime& get_tar_impl_date();
    const Teamcenter::Soa::Common::DateTime& get_rev_impl_date();
    const Teamcenter::Soa::Client::StringVector& get_eff_point();
    const Teamcenter::Soa::Client::StringVector& get_eff_point_mod();
    const Teamcenter::Soa::Client::StringVector& get_product();
    const Teamcenter::Soa::Client::StringVector& get_family();
    const Teamcenter::Soa::Client::StringVector& get_year();
    const Teamcenter::Soa::Client::StringVector& get_drd();
    const Teamcenter::Soa::Client::StringVector& get_chng_comments();
    const Teamcenter::Soa::Client::StringVector& get_chng_reason_desc();
    const Teamcenter::Soa::Client::StringVector& get_doc_id();
    const Teamcenter::Soa::Client::StringVector& get_doc_type();
    const Teamcenter::Soa::Client::StringVector& get_ref_doc_comments();
    const std::string& get_chng_leader();
    const std::string& get_issue_date();
    const std::string& get_change_initiator();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Common_Engineering_Form")

   virtual ~Common_Engineering_Form();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
