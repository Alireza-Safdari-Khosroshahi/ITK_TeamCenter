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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MEGROOVETOOL_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MEGROOVETOOL_HXX

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


class TCSOACLIENTMNGD_API MEGrooveTool : public Teamcenter::Soa::Client::Model::MENXObject
{
public:
    double get_insert_length();
    double get_right_y_off();
    double get_insert_width();
    double get_left_y_off();
    double get_min_face_diam();
    double get_side_angle();
    int get_preset_cutter();
    int get_right_tp();
    double get_max_face_diam();
    double get_max_toolreach();
    double get_radius();
    double get_right_angle();
    double get_orientation();
    double get_right_x_off();
    double get_max_depth();
    double get_thickness();
    double get_min_boring_diam();
    double get_left_angle();
    double get_tip_angle();
    double get_left_x_off();
    int get_left_tp();
    double get_left_radius();
    int get_insert_position();
    int get_insert_type();
    double get_right_radius();
    double get_nose_width();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("MEGrooveTool")

   virtual ~MEGrooveTool();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
