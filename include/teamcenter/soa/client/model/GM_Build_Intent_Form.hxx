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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_GM_BUILD_INTENT_FORM_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_GM_BUILD_INTENT_FORM_HXX

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


class TCSOAGMOMODELMNGD_API GM_Build_Intent_Form : public Teamcenter::Soa::Client::Model::Form
{
public:
    const std::string& get_veh_ord_no();
    const std::string& get_engn_no();
    const std::string& get_num_blds();
    const std::string& get_mktg_div();
    const std::string& get_bld_phase();
    const std::string& get_bld_reqd_dte();
    const std::string& get_bld_start_dte();
    const std::string& get_bld_comp_dte();
    const std::string& get_bdy_in_wh_dte();
    const std::string& get_mtl_reqd_dte();
    const std::string& get_pt_drs_ht_dte();
    const std::string& get_bld_func_cde();
    const std::string& get_prod_yr();
    const std::string& get_prod_line_cde();
    const std::string& get_veh_mdl_dsgtr_sak();
    const std::string& get_engng_div_cde();
    const std::string& get_bld_trmt_site_cde();
    const std::string& get_bld_type_cde();
    const std::string& get_bld_type_cde_desc();
    const std::string& get_bld_site_name();
    const std::string& get_status_code();
    const std::string& get_program_code();
    const Teamcenter::Soa::Common::DateTime& get_first_trmt_dte();
    const Teamcenter::Soa::Common::DateTime& get_last_trmt_dte();
    const std::string& get_assm_exp_only();
    bool get_partial_build();
    const std::string& get_build_from_base();
    const std::string& get_assembly_number();
    const std::string& get_assembly_upc_fna();
    const std::string& get_vas_note();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("GM_Build_Intent_Form")

   virtual ~GM_Build_Intent_Form();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
