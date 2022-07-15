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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SPOTWELDFORMCLASS_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SPOTWELDFORMCLASS_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API SpotWeldFormClass : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    int get_Number_of_sheets_welded();
    double get_X_pos();
    double get_Y_pos();
    double get_Z_pos();
    const std::string& get_Output_type();
    const std::string& get_Weld_type();
    const std::string& get_Weld_class();
    int get_Tol();
    const std::string& get_Standard();
    const std::string& get_Id();
    const std::string& get_Group_id();
    int get_Number_of_welds_in_group();
    double get_Weld_i_value();
    double get_Weld_j_value();
    double get_Weld_k_value();
    const std::string& get_Connected_part_1();
    const std::string& get_Connected_part_2();
    const std::string& get_Connected_part_3();
    const std::string& get_Connected_part_4();
    const std::string& get_Spot_dimensional_ctrl();
    const std::string& get_Spot_process_ctrl();
    const std::string& get_SPOT_KPC();
    const std::string& get_Spot_kpc_justification();
    const std::string& get_Weld_designation();
    double get_Cool_time1();
    double get_Cool_time2();
    const std::string& get_Feat_comment();
    const std::string& get_Gov_mtl_thk();
    double get_Hold_time();
    double get_Max_current();
    const std::string& get_Metal_comb();
    double get_Min_current1();
    double get_Min_current2();
    double get_Nugget_dia();
    int get_Pulse_num1();
    int get_Pulse_num2();
    double get_Pulse_time1();
    double get_Pulse_time2();
    double get_Resistance();
    double get_Squeeze_time();
    const std::string& get_Stackup();
    double get_Weld_force();
    int get_Weld_group_min();
    int get_Weld_group_total();
    double get_Weld_time();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("SpotWeldFormClass")

   virtual ~SpotWeldFormClass();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
