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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CORP_TOOLREVMASTER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CORP_TOOLREVMASTER_HXX

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
                class Role;
                class Person;


class TCSOAGMOMODELMNGD_API CORP_ToolRevMaster : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_release_level();
    const std::string& get_prelim_data();
    const std::string& get_design_source();
    const std::string& get_const_source();
    const std::string& get_purchase_order();
    const std::string& get_material();
    const std::string& get_hand_designation();
    const std::string& get_purchase_option();
    const std::string& get_field_data1();
    const Teamcenter::Soa::Client::StringVector& get_change_desc();
    const std::string& get_alternate_description();
    const std::string& get_content_type();
    const Teamcenter::Soa::Client::StringVector& get_project_program();
    const Teamcenter::Soa::Client::StringVector& get_model();
    const Teamcenter::Soa::Client::IntVector& get_style();
    const std::string& get_engineer();
    const Teamcenter::Soa::Client::StringVector& get_plant();
    const Teamcenter::Soa::Client::StringVector& get_major_area();
    const Teamcenter::Soa::Client::StringVector& get_area();
    const Teamcenter::Soa::Client::StringVector& get_station_operation();
    const std::string& get_product_system();
    const std::string& get_product_subsystem();
    const std::string& get_drawing_number();
    const std::string& get_design_source_new();
    const Teamcenter::Soa::Client::StringVector& get_const_source_new();
    const Teamcenter::Soa::Client::StringVector& get_associated_product();
    const Teamcenter::Soa::Client::StringVector& get_machine_equipment();
    size_t count_roletag();
    Teamcenter::Soa::Common::AutoPtr<Role> get_roletag_at( size_t inx );
    size_t count_persontag();
    Teamcenter::Soa::Common::AutoPtr<Person> get_persontag_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CORP_ToolRevMaster")

   virtual ~CORP_ToolRevMaster();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
