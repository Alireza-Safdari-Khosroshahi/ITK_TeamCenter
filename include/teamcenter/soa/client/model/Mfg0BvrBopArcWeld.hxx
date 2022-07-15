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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MFG0BVRBOPARCWELD_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MFG0BVRBOPARCWELD_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Mfg0BvrBopManufacturingFeature.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API Mfg0BvrBopArcWeld : public Teamcenter::Soa::Client::Model::Mfg0BvrBopManufacturingFeature
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
    double get_Mfg0StartPointX();
    double get_Mfg0StartPointY();
    double get_Mfg0StartPointZ();
    double get_Mfg0StartPointRX();
    double get_Mfg0StartPointRY();
    double get_Mfg0StartPointRZ();
    double get_Mfg0IntermediatePointX();
    double get_Mfg0IntermediatePointY();
    double get_Mfg0IntermediatePointRX();
    double get_Mfg0IntermediatePointRY();
    double get_Mfg0IntermediatePointZ();
    double get_Mfg0IntermediatePointRZ();
    double get_Mfg0EndPointX();
    double get_Mfg0EndPointY();
    double get_Mfg0EndPointZ();
    double get_Mfg0EndPointRX();
    double get_Mfg0EndPointRY();
    double get_Mfg0EndPointRZ();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mfg0BvrBopArcWeld")

   virtual ~Mfg0BvrBopArcWeld();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
