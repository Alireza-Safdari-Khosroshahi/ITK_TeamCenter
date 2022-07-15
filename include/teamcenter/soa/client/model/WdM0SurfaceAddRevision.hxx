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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_WDM0SURFACEADDREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_WDM0SURFACEADDREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/PSConnectionRevision.hxx>

#include <teamcenter/soa/client/model/WeldmgmtMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAWELDMGMTMODELMNGD_API WdM0SurfaceAddRevision : public Teamcenter::Soa::Client::Model::PSConnectionRevision
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_Feature_Form_Relation();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0TCContextFeatureFormRel();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("WdM0SurfaceAddRevision")

   virtual ~WdM0SurfaceAddRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/WeldmgmtMngd_undef.h>
#endif
