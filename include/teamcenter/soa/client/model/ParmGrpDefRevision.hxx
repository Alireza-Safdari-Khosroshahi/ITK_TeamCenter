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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PARMGRPDEFREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PARMGRPDEFREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/CalParmRevision.hxx>

#include <teamcenter/soa/client/model/CcdmMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACCDMMODELMNGD_API ParmGrpDefRevision : public Teamcenter::Soa::Client::Model::CalParmRevision
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_Ccd0HasInputSource();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Ccd0HasOutputFiles();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Ccd0HasMemoryLayout();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Ccd0HasOverrideContainer();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ParmGrpDefRevision")

   virtual ~ParmGrpDefRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CcdmMngd_undef.h>
#endif
