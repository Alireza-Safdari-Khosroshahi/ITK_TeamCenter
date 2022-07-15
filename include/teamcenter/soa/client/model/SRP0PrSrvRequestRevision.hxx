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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SRP0PRSRVREQUESTREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SRP0PRSRVREQUESTREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/SRP0SrvRequestRevision.hxx>

#include <teamcenter/soa/client/model/ServicerequestMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOASERVICEREQUESTMODELMNGD_API SRP0PrSrvRequestRevision : public Teamcenter::Soa::Client::Model::SRP0SrvRequestRevision
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_SRP0DelgatesTo();
    const Teamcenter::Soa::Client::ModelObjectVector& get_SRP0IncludesActivity();
    const Teamcenter::Soa::Client::ModelObjectVector& get_CustomerContactFolder();
    const Teamcenter::Soa::Client::ModelObjectVector& get_DelegatesToFolder();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IncludesActivityFolder();
    const Teamcenter::Soa::Client::ModelObjectVector& get_LocationInCompanyFolder();
    const Teamcenter::Soa::Client::ModelObjectVector& get_MROProductFolder();
    const Teamcenter::Soa::Client::ModelObjectVector& get_PerformsFolder();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("SRP0PrSrvRequestRevision")

   virtual ~SRP0PrSrvRequestRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ServicerequestMngd_undef.h>
#endif
