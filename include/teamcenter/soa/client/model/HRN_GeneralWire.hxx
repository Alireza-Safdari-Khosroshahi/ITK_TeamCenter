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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_HRN_GENERALWIRE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_HRN_GENERALWIRE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Item.hxx>

#include <teamcenter/soa/client/model/HrnMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAHRNMODELMNGD_API HRN_GeneralWire : public Teamcenter::Soa::Client::Model::Item
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_HRN_wire_length_data();
    double get_bend_radius();
    const std::string& get_cable_designator();
    double get_cover_thickness();
    double get_cross_section();
    const std::string& get_gauge();
    double get_height();
    double get_max_length();
    double get_min_length();
    double get_outside_dia();
    const std::string& get_part_type();
    const std::string& get_process_type();
    const std::string& get_process_value();
    double get_width();
    const std::string& get_wirespec();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("HRN_GeneralWire")

   virtual ~HRN_GeneralWire();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/HrnMngd_undef.h>
#endif
