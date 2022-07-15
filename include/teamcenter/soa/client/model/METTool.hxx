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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_METTOOL_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_METTOOL_HXX

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


class TCSOACLIENTMNGD_API METTool : public Teamcenter::Soa::Client::Model::MENXObject
{
public:
    double get_diameter();
    int get_tool_number();
    const std::string& get_cat_number();
    double get_length();
    double get_shank_diam();
    double get_fl_length();
    const std::string& get_tool_dir();
    double get_upper_rad();
    double get_lower_rad();
    int get_num_flute();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("METTool")

   virtual ~METTool();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
