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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MEMILLTOOL_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MEMILLTOOL_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/MENXObject.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API MEMillTool : public Teamcenter::Soa::Client::Model::MENXObject
{
public:
    double get_diameter();
    double get_rad_x1();
    int get_tool_number();
    double get_radius1();
    const std::string& get_cat_number();
    double get_length();
    double get_fl_length();
    double get_tip_angle();
    const std::string& get_tool_dir();
    double get_rad_y1();
    int get_num_flute();
    double get_tap_angle();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("MEMillTool")

   virtual ~MEMillTool();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
