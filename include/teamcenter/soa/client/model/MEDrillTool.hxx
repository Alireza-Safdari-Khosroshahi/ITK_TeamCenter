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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MEDRILLTOOL_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MEDRILLTOOL_HXX

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


class TCSOACLIENTMNGD_API MEDrillTool : public Teamcenter::Soa::Client::Model::MENXObject
{
public:
    double get_diameter();
    int get_tool_number();
    double get_radius1();
    double get_point_angle();
    const std::string& get_cat_number();
    double get_length();
    double get_fl_length();
    double get_z_offset();
    const std::string& get_tool_dir();
    int get_num_flute();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("MEDrillTool")

   virtual ~MEDrillTool();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
