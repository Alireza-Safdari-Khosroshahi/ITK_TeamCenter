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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_METHREADTOOL_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_METHREADTOOL_HXX

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


class TCSOACLIENTMNGD_API METhreadTool : public Teamcenter::Soa::Client::Model::MENXObject
{
public:
    double get_insert_length();
    double get_y_offset();
    double get_insert_width();
    double get_right_angle();
    double get_orientation();
    double get_x_offset();
    double get_max_depth();
    double get_thickness();
    double get_nose_rad();
    const std::string& get_cat_number();
    double get_left_angle();
    int get_insert_position();
    int get_insert_type();
    double get_nose_width();
    double get_tip_offset();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("METhreadTool")

   virtual ~METhreadTool();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
