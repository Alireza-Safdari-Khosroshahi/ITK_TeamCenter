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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MEUDMILLTOOL_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MEUDMILLTOOL_HXX

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


class TCSOACLIENTMNGD_API MEUDMillTool : public Teamcenter::Soa::Client::Model::MENXObject
{
public:
    int get_segment_no();
    const std::string& get_line_length_array();
    const std::string& get_start_angle_array();
    const std::string& get_arc_radius_array();
    const std::string& get_arc_sweep_array();
    const std::string& get_tool_dir();
    int get_tool_number();
    const std::string& get_cat_number();
    int get_holder_section_count();
    int get_tracking_points_count();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("MEUDMillTool")

   virtual ~MEUDMillTool();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
