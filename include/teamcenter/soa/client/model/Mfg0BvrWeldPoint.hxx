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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MFG0BVRWELDPOINT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MFG0BVRWELDPOINT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Mfg0BvrManufacturingFeature.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API Mfg0BvrWeldPoint : public Teamcenter::Soa::Client::Model::Mfg0BvrManufacturingFeature
{
public:
    int get_Mfg0number_of_sheets_welded();
    const std::string& get_Mfg0output_type();
    const std::string& get_Mfg0weld_type();
    const std::string& get_Mfg0weld_class();
    int get_Mfg0tol();
    const std::string& get_Mfg0standard();
    const std::string& get_Mfg0id();
    const std::string& get_Mfg0group_id();
    int get_Mfg0num_of_welds_in_group();
    double get_Mfg0weld_i_value();
    double get_Mfg0weld_j_value();
    double get_Mfg0weld_k_value();
    const std::string& get_Mfg0spot_dimensional_ctrl();
    const std::string& get_Mfg0spot_process_ctrl();
    const std::string& get_Mfg0spot_kpc();
    const std::string& get_Mfg0spot_kpc_justification();
    double get_Mfg0cool_time1();
    double get_Mfg0cool_time2();
    const std::string& get_Mfg0feat_comment();
    const std::string& get_Mfg0gov_mtl_thk();
    double get_Mfg0hold_time();
    double get_Mfg0max_current();
    const std::string& get_Mfg0metal_comb();
    double get_Mfg0min_current1();
    double get_Mfg0min_current2();
    double get_Mfg0nugget_dia();
    int get_Mfg0pulse_num1();
    int get_Mfg0pulse_num2();
    double get_Mfg0pulse_time1();
    double get_Mfg0pulse_time2();
    double get_Mfg0resistance();
    double get_Mfg0squeeze_time();
    const std::string& get_Mfg0stackup();
    double get_Mfg0weld_force();
    int get_Mfg0weld_group_min();
    int get_Mfg0weld_group_total();
    double get_Mfg0weld_time();
    const std::string& get_Mfg0designation();
    const std::string& get_Mfg0symbol_name();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mfg0BvrWeldPoint")

   virtual ~Mfg0BvrWeldPoint();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
