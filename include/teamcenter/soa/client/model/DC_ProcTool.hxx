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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DC_PROCTOOL_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DC_PROCTOOL_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/DC_Tool.hxx>

#include <teamcenter/soa/client/model/ContmgmtbaseMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class DCt_GraphicPriority;


class TCSOACONTMGMTBASEMODELMNGD_API DC_ProcTool : public Teamcenter::Soa::Client::Model::DC_Tool
{
public:
    const std::string& get_grphcPrioReference();
    bool get_toolDlGraphics();
    bool get_toolDlSchema();
    bool get_toolDlStyleSheet();
    const std::string& get_toolProcInstr();
    Teamcenter::Soa::Common::AutoPtr<DCt_GraphicPriority> get_ctm0GraphicPriorityTagref();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DC_ProcTool")

   virtual ~DC_ProcTool();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ContmgmtbaseMngd_undef.h>
#endif
