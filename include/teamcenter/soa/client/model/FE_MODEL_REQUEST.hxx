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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FE_MODEL_REQUEST_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FE_MODEL_REQUEST_HXX

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


class TCSOAGMOMODELMNGD_API FE_MODEL_REQUEST : public Teamcenter::Soa::Client::Model::Form
{
public:
    const std::string& get_requester_name();
    const std::string& get_requester_egm();
    const Teamcenter::Soa::Common::DateTime& get_req_completion_date();
    const std::string& get_division();
    const std::string& get_program();
    const std::string& get_model_line();
    const std::string& get_model_year();
    const std::string& get_job_desc();
    bool get_model_modify();
    bool get_model_type_hm();
    bool get_model_type_dyna();
    bool get_model_type_nastran();
    bool get_model_type_other();
    const std::string& get_model_type_other_str();
    bool get_model_data_attach();
    const std::string& get_fe_mod_file_name_1();
    const std::string& get_fe_mod_file_name_2();
    const std::string& get_fe_mod_file_location_1();
    const std::string& get_fe_mod_file_location_2();
    bool get_design_data_ug();
    bool get_design_data_iges();
    bool get_design_data_attach();
    const std::string& get_data_file_name_1();
    const std::string& get_data_file_name_2();
    const std::string& get_data_file_location_1();
    const std::string& get_data_file_location_2();
    bool get_file_format_dyna();
    bool get_file_format_nastran();
    bool get_file_format_other();
    const std::string& get_file_format_other_str();
    int get_model_size();
    int get_element_size();
    bool get_element_type_plates();
    bool get_element_type_solids();
    bool get_element_type_beams();
    const std::string& get_material_prop();
    const std::string& get_instructions();
    bool get_meet_modeler();
    const std::string& get_requester_signature();
    const std::string& get_requester_egm_signature();
    const std::string& get_modeler_name();
    const Teamcenter::Soa::Common::DateTime& get_mr_received_date();
    float get_estimated_hours();
    float get_actual_hours();
    float get_rework_hours();
    const Teamcenter::Soa::Common::DateTime& get_mod_start_date();
    const Teamcenter::Soa::Common::DateTime& get_mod_completion_date();
    const std::string& get_mod_stored_file_name();
    const std::string& get_mod_stored_file_location();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("FE_MODEL_REQUEST")

   virtual ~FE_MODEL_REQUEST();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
