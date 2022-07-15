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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_UGDATUMMP_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_UGDATUMMP_HXX

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


class TCSOAGMOMODELMNGD_API UgDatumMP : public Teamcenter::Soa::Client::Model::UgDatumBasic
{
public:
    const std::string& get_measurement_point_name();
    double get_mpt_i_value();
    double get_mpt_j_value();
    double get_mpt_k_value();
    double get_mpt_x_value();
    double get_mpt_y_value();
    double get_mpt_z_value();
    const std::string& get_mpt_locating_target();
    const std::string& get_section_plane_name();
    double get_mpt_tol_upr_x();
    double get_mpt_tol_lwr_x();
    double get_mpt_tol_upr_y();
    double get_mpt_tol_lwr_y();
    double get_mpt_tol_upr_z();
    double get_mpt_tol_lwr_z();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("UgDatumMP")

   virtual ~UgDatumMP();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
