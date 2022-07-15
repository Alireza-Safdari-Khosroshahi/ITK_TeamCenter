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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MEFORMTOOL_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MEFORMTOOL_HXX

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


class TCSOACLIENTMNGD_API MEFormTool : public Teamcenter::Soa::Client::Model::MENXObject
{
public:
    const std::string& get_cat_number();
    double get_init_insert_angle();
    double get_init_edge_length();
    const std::string& get_nose_angle_array();
    double get_orientation();
    const std::string& get_edge_length_array();
    int get_nose_no();
    const std::string& get_nose_radius_array();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("MEFormTool")

   virtual ~MEFormTool();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
