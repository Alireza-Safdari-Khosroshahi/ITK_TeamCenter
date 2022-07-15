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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_METURNTOOL_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_METURNTOOL_HXX

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


class TCSOACLIENTMNGD_API METurnTool : public Teamcenter::Soa::Client::Model::MENXObject
{
public:
    double get_holder_angle();
    double get_nose_angle();
    int get_thickness_option();
    double get_cut_edge_length();
    double get_orientation();
    int get_relief_angle_option();
    double get_thickness();
    double get_nose_rad();
    const std::string& get_cat_number();
    double get_holder_width();
    int get_tracking_point();
    int get_insert_position();
    double get_relief_angle();
    double get_button_diam();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("METurnTool")

   virtual ~METurnTool();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
