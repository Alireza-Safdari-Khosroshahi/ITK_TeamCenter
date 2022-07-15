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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_WDM0SURFACEADDREVISIONMASTER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_WDM0SURFACEADDREVISIONMASTER_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/PSConnectionRevision_Master.hxx>

#include <teamcenter/soa/client/model/WeldmgmtMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAWELDMGMTMODELMNGD_API WdM0SurfaceAddRevisionMaster : public Teamcenter::Soa::Client::Model::PSConnectionRevision_Master
{
public:
    const std::string& get_MajorFeatureVersion();
    const std::string& get_MinorFeatureVersion();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("WdM0SurfaceAddRevisionMaster")

   virtual ~WdM0SurfaceAddRevisionMaster();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/WeldmgmtMngd_undef.h>
#endif
