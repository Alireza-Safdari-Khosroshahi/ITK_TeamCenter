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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MFG0BVRARCWELD_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MFG0BVRARCWELD_HXX

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


class TCSOACLIENTMNGD_API Mfg0BvrArcWeld : public Teamcenter::Soa::Client::Model::Mfg0BvrManufacturingFeature
{
public:
    const std::string& get_Mfg0id();
    const std::string& get_Mfg0weld_type();
    const std::string& get_Mfg0group_id();
    const std::string& get_Mfg0output_type();
    const std::string& get_Mfg0Size();
    const std::string& get_Mfg0Method();
    const std::string& get_Mfg0Weld_Volume();
    const std::string& get_Mfg0Penetration_depth_1();
    const std::string& get_Mfg0Contour_height_1();
    const std::string& get_Mfg0Height();
    const std::string& get_Mfg0Setup();
    const std::string& get_Mfg0Root_penetration();
    const std::string& get_Mfg0Root_opening();
    const std::string& get_Mfg0Contour();
    const std::string& get_Mfg0First_leg();
    const std::string& get_Mfg0Groove_angle();
    const std::string& get_Mfg0Plug_diameter();
    const std::string& get_Mfg0Process();
    const std::string& get_Mfg0Second_leg();
    const std::string& get_Mfg0Groove_radius();
    const std::string& get_Mfg0Weld_length();
    const std::string& get_Mfg0Depth();
    const std::string& get_Mfg0fillet_type();
    const std::string& get_Mfg0fillet();
    const std::string& get_Mfg0joint_type();
    const std::string& get_Mfg0groove_type();
    double get_Mfg0length();
    double get_Mfg0volume();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mfg0BvrArcWeld")

   virtual ~Mfg0BvrArcWeld();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
