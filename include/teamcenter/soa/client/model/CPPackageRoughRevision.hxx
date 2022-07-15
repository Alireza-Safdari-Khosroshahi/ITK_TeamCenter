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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CPPACKAGEROUGHREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CPPACKAGEROUGHREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/CPProductRoughRevision.hxx>

#include <teamcenter/soa/client/model/PkgartMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAPKGARTMODELMNGD_API CPPackageRoughRevision : public Teamcenter::Soa::Client::Model::CPProductRoughRevision
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_CP_Has_Graphical_Element();
    const Teamcenter::Soa::Client::ModelObjectVector& get_CP_Has_Package_Concept();
    const Teamcenter::Soa::Client::ModelObjectVector& get_CP_design_briefs();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CPPackageRoughRevision")

   virtual ~CPPackageRoughRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/PkgartMngd_undef.h>
#endif
