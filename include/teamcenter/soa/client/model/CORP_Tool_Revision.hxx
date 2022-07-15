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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CORP_TOOL_REVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CORP_TOOL_REVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ItemRevision.hxx>

#include <teamcenter/soa/client/model/GmoMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class Person;
                class Role;


class TCSOAGMOMODELMNGD_API CORP_Tool_Revision : public Teamcenter::Soa::Client::Model::ItemRevision
{
public:
    const std::string& get_ec_approver_name();
    const std::string& get_ec_release_date();
    const std::string& get_ec_nums();
    const std::string& get_gm_area();
    const std::string& get_gm_plant();
    const std::string& get_gm_const_source_new();
    const std::string& get_gm_station_operation();
    const std::string& get_gm_machine_equipment();
    const std::string& get_gm_major_area();
    const std::string& get_gm_project_program();
    const std::string& get_gm_model();
    const std::string& get_ir_approver_name();
    const std::string& get_style();
    const std::string& get_gm_associated_product();
    const std::string& get_alternate_description();
    const Teamcenter::Soa::Client::StringVector& get_area();
    const Teamcenter::Soa::Client::StringVector& get_change_desc();
    const std::string& get_const_source();
    const Teamcenter::Soa::Client::StringVector& get_const_source_new();
    const std::string& get_content_type();
    const std::string& get_design_source();
    const std::string& get_design_source_new();
    const std::string& get_drawing_number();
    const std::string& get_engineer();
    const Teamcenter::Soa::Common::DateTime& get_Estimated_Completion_Date();
    const Teamcenter::Soa::Common::DateTime& get_Estimated_Completion_Date__MS1_();
    const Teamcenter::Soa::Common::DateTime& get_Estimated_Completion_Date__MS2_();
    const Teamcenter::Soa::Common::DateTime& get_Estimated_Completion_Date__MS3_();
    const std::string& get_Event();
    const std::string& get_field_data1();
    const std::string& get_gm_alternate_description();
    const std::string& get_gm_content_type();
    const std::string& get_gm_design_source_new();
    const std::string& get_gm_drawing_number();
    const std::string& get_gm_engineer();
    const std::string& get_gm_product_subsystem();
    const std::string& get_gm_product_system();
    const std::string& get_hand_designation();
    const std::string& get_local_tool_id();
    const Teamcenter::Soa::Client::StringVector& get_machine_equipment();
    const Teamcenter::Soa::Client::StringVector& get_major_area();
    const std::string& get_material();
    const std::string& get_Milestone_1();
    const std::string& get_Milestone_2();
    const std::string& get_Milestone_3();
    const Teamcenter::Soa::Client::StringVector& get_model();
    size_t count_persontag();
    Teamcenter::Soa::Common::AutoPtr<Person> get_persontag_at( size_t inx );
    const Teamcenter::Soa::Client::StringVector& get_plant();
    const std::string& get_prelim_data();
    const std::string& get_product_subsystem();
    const std::string& get_product_system();
    const Teamcenter::Soa::Client::StringVector& get_project_program();
    const std::string& get_purchase_option();
    const std::string& get_purchase_order();
    const std::string& get_release_level();
    const Teamcenter::Soa::Common::DateTime& get_Required_Completion_Date();
    const Teamcenter::Soa::Common::DateTime& get_Required_Completion_Date__MS1_();
    const Teamcenter::Soa::Common::DateTime& get_Required_Completion_Date__MS2_();
    const Teamcenter::Soa::Common::DateTime& get_Required_Completion_Date__MS3_();
    size_t count_roletag();
    Teamcenter::Soa::Common::AutoPtr<Role> get_roletag_at( size_t inx );
    const Teamcenter::Soa::Client::StringVector& get_station_operation();
    const std::string& get_tool_level();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CORP_Tool_Revision")

   virtual ~CORP_Tool_Revision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
