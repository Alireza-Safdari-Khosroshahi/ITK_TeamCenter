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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PWT_REVISION_FORM_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PWT_REVISION_FORM_HXX

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


class TCSOAGMOMODELMNGD_API PWT_Revision_Form : public Teamcenter::Soa::Client::Model::Form
{
public:
    bool get_is_after_sales();
    bool get_co_design();
    bool get_logo_reqd();
    const std::string& get_broadcast_code();
    const std::string& get_part_status();
    const std::string& get_resp_engineer();
    const std::string& get_engineer_code();
    const std::string& get_engg_resp_site();
    bool get_homologation();
    const std::string& get_legal_constraints();
    bool get_qual_extension();
    bool get_re_qual_reqd();
    const std::string& get_qual_ext_dwg_nm();
    const std::string& get_qual_number();
    const std::string& get_denom_field();
    const std::string& get_codesign_name();
    const std::string& get_gp11_level();
    const std::string& get_modification_type();
    const std::string& get_pls();
    const Teamcenter::Soa::Client::StringVector& get_process_resp_engineer();
    const std::string& get_dwg_emission_dept();
    const std::string& get_mat_in_imds();
    const Teamcenter::Soa::Client::StringVector& get_plant();
    const Teamcenter::Soa::Client::FloatVector& get_manpower_time();
    const Teamcenter::Soa::Client::StringVector& get_cost_centers();
    const std::string& get_labour_cost();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("PWT_Revision_Form")

   virtual ~PWT_Revision_Form();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
