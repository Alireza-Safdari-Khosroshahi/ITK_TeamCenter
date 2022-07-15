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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MEASUREMENTLOCATION_FORM_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MEASUREMENTLOCATION_FORM_HXX

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


class TCSOAGMOMODELMNGD_API MeasurementLocation_Form : public Teamcenter::Soa::Client::Model::Form
{
public:
    const std::string& get_type_();
    const std::string& get_db_part_name();
    const std::string& get_db_part_no();
    const std::string& get_db_part_rev();
    const std::string& get_connected_parts();
    const std::string& get_section_plane_name();
    const std::string& get_body_section_line();
    const std::string& get_mature();
    const std::string& get_fixed_location();
    const std::string& get_direction_of_check();
    const std::string& get_standard();
    const std::string& get_override_();
    const std::string& get_relationships();
    const std::string& get_mlf_name();
    double get_mlf__i_value();
    double get_mlf__j_value();
    double get_mlf__k_value();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("MeasurementLocation_Form")

   virtual ~MeasurementLocation_Form();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
