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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_WDM0SURFACEADDATTRIBUTEFORM_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_WDM0SURFACEADDATTRIBUTEFORM_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Form.hxx>

#include <teamcenter/soa/client/model/WeldmgmtMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAWELDMGMTMODELMNGD_API WdM0SurfaceAddAttributeForm : public Teamcenter::Soa::Client::Model::Form
{
public:
    const std::string& get_wdm0connected_part_1();
    const std::string& get_wdm0connected_part_2();
    const std::string& get_wdm0connected_part_3();
    const std::string& get_wdm0connected_part_4();
    const std::string& get_wdm0connected_part_5();
    const std::string& get_wdm0connected_part_6();
    const std::string& get_wdm0connected_part_7();
    const std::string& get_wdm0connected_part_8();
    const std::string& get_wdm0connected_part_9();
    const std::string& get_wdm0weld_process();
    double get_wdm0volume();
    double get_wdm0thickness();
    const std::string& get_wdm0surface_type();
    const std::string& get_wdm0surfaceadd_type();
    double get_wdm0segment_length();
    const std::string& get_wdm0id();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("WdM0SurfaceAddAttributeForm")

   virtual ~WdM0SurfaceAddAttributeForm();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/WeldmgmtMngd_undef.h>
#endif
