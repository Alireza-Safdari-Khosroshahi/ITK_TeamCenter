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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ARCWELDFORMCLASS_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ARCWELDFORMCLASS_HXX

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


class TCSOACLIENTMNGD_API ArcWeldFormClass : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_Id();
    const std::string& get_Weld_type();
    const std::string& get_Setup();
    const std::string& get_Contour();
    const std::string& get_Method();
    const std::string& get_Process();
    const std::string& get_Group_id();
    const std::string& get_Weld_length();
    const std::string& get_Weld_volume();
    const std::string& get_First_leg();
    const std::string& get_Second_leg();
    const std::string& get_Output_type();
    const std::string& get_Connected_part_1();
    const std::string& get_Connected_part_2();
    const std::string& get_Connected_part_3();
    const std::string& get_Connected_part_4();
    const std::string& get_Connected_part_5();
    const std::string& get_Connected_part_6();
    const std::string& get_Connected_part_7();
    const std::string& get_Connected_part_8();
    const std::string& get_Connected_part_9();
    const std::string& get_Root_opening();
    const std::string& get_Root_penetration();
    const std::string& get_Penetration_depth_1();
    const std::string& get_Contour_height_1();
    const std::string& get_Height();
    const std::string& get_Depth();
    const std::string& get_Plug_diameter();
    const std::string& get_Size();
    const std::string& get_Groove_angle();
    const std::string& get_Groove_radius();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ArcWeldFormClass")

   virtual ~ArcWeldFormClass();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
