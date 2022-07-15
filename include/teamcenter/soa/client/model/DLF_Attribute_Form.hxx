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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DLF_ATTRIBUTE_FORM_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DLF_ATTRIBUTE_FORM_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Form.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API DLF_Attribute_Form : public Teamcenter::Soa::Client::Model::Form
{
public:
    double get_Dlf_i_value();
    double get_Dlf_j_value();
    double get_Dlf_k_value();
    const std::string& get_Type();
    const std::string& get_Section_plane_name();
    const std::string& get_Id();
    const std::string& get_Control_direction();
    bool get_Fixed_location();
    bool get_Mature();
    const std::string& get_Direction_of_check();
    const std::string& get_Body_section_line();
    const std::string& get_Connected_part_1();
    const std::string& get_Connected_part_2();
    const std::string& get_Connected_part_3();
    const std::string& get_Connected_part_4();
    const std::string& get_Connected_part_5();
    const std::string& get_Connected_part_6();
    const std::string& get_Connected_part_7();
    const std::string& get_Connected_part_8();
    const std::string& get_Connected_part_9();
    double get_Mfg0CSYS_i_value();
    double get_Mfg0CSYS_j_value();
    double get_Mfg0CSYS_k_value();
    const std::string& get_Mfg0Datum_Type();
    const std::string& get_Mfg0Major_cntl_coordinate();
    double get_Mfg0x_pos();
    double get_Mfg0y_pos();
    double get_Mfg0z_pos();
    bool get_Mfg0cntrl_i_direction();
    bool get_Mfg0cntrl_j_direction();
    bool get_Mfg0cntrl_k_direction();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DLF_Attribute_Form")

   virtual ~DLF_Attribute_Form();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
