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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_HRN_GENERALWIREMASTER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_HRN_GENERALWIREMASTER_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/HRN_PartMaster.hxx>

#include <teamcenter/soa/client/model/HrnMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAHRNMODELMNGD_API HRN_GeneralWireMaster : public Teamcenter::Soa::Client::Model::HRN_PartMaster
{
public:
    double get_bend_radius();
    const std::string& get_cable_designator();
    double get_cross_section();
    double get_outside_dia();
    double get_min_length();
    double get_max_length();
    const std::string& get_wirespec();
    double get_width();
    double get_height();
    double get_cover_thickness();
    const std::string& get_gauge();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("HRN_GeneralWireMaster")

   virtual ~HRN_GeneralWireMaster();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/HrnMngd_undef.h>
#endif
