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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_UGDATUMDP_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_UGDATUMDP_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/UgDatumBasic.hxx>

#include <teamcenter/soa/client/model/GmoMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAGMOMODELMNGD_API UgDatumDP : public Teamcenter::Soa::Client::Model::UgDatumBasic
{
public:
    const std::string& get_datum_point_name();
    double get_dpt_i_value();
    double get_dpt_j_value();
    double get_dpt_k_value();
    double get_dpt_x_value();
    double get_dpt_y_value();
    double get_dpt_z_value();
    const std::string& get_section_plane_name();
    const std::string& get_direction_of_check();
    const std::string& get_dp_locator_type();
    const std::string& get_dp_pin_type();
    double get_dp_pin_size();
    const std::string& get_dp_opening_type();
    double get_dp_opening_size();
    const std::string& get_dp_action();
    const std::string& get_dp_characteristic();
    const std::string& get_dp_tool_id();
    int get_dp_clamp_sequence();
    const std::string& get_dp_locator_class();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("UgDatumDP")

   virtual ~UgDatumDP();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
