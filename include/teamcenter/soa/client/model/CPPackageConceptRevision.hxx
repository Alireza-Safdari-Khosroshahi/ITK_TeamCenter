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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CPPACKAGECONCEPTREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CPPACKAGECONCEPTREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/DocumentRevision.hxx>

#include <teamcenter/soa/client/model/PkgartMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAPKGARTMODELMNGD_API CPPackageConceptRevision : public Teamcenter::Soa::Client::Model::DocumentRevision
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_CP_design_briefs();
    const Teamcenter::Soa::Client::ModelObjectVector& get_CP_tech_briefs();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CPPackageConceptRevision")

   virtual ~CPPackageConceptRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/PkgartMngd_undef.h>
#endif
