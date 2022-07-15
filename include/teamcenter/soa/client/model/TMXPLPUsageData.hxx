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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_TMXPLPUSAGEDATA_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_TMXPLPUSAGEDATA_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Form.hxx>

#include <teamcenter/soa/client/model/CmtemserverMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACMTEMSERVERMODELMNGD_API TMXPLPUsageData : public Teamcenter::Soa::Client::Model::Form
{
public:
    const std::string& get_tool_type();
    const std::string& get_control_direction_x();
    const std::string& get_control_direction_y();
    const std::string& get_control_direction_z();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("TMXPLPUsageData")

   virtual ~TMXPLPUsageData();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CmtemserverMngd_undef.h>
#endif
