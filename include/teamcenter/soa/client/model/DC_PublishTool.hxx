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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DC_PUBLISHTOOL_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DC_PUBLISHTOOL_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/DC_ProcTool.hxx>

#include <teamcenter/soa/client/model/ContmgmtbaseMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACONTMGMTBASEMODELMNGD_API DC_PublishTool : public Teamcenter::Soa::Client::Model::DC_ProcTool
{
public:
    bool get_toolLocalIndicator();
    int get_toolNumberOfInstances();
    const std::string& get_toolActivation();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DC_PublishTool")

   virtual ~DC_PublishTool();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ContmgmtbaseMngd_undef.h>
#endif
