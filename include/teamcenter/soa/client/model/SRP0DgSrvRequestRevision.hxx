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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SRP0DGSRVREQUESTREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SRP0DGSRVREQUESTREVISION_HXX

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


class TCSOASERVICEREQUESTMODELMNGD_API SRP0DgSrvRequestRevision : public Teamcenter::Soa::Client::Model::SRP0SrvRequestRevision
{
public:
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_SRP0PrimaryServiceRequest();
    const Teamcenter::Soa::Client::ModelObjectVector& get_SRP0RequestedActivity();
    const Teamcenter::Soa::Client::ModelObjectVector& get_SRP0PerformsServiceRequest();
    const Teamcenter::Soa::Client::ModelObjectVector& get_CustomerContactFolder();
    const Teamcenter::Soa::Client::ModelObjectVector& get_LocationInCompanyFolder();
    const Teamcenter::Soa::Client::ModelObjectVector& get_MROProductFolder();
    const Teamcenter::Soa::Client::ModelObjectVector& get_PerformsFolder();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("SRP0DgSrvRequestRevision")

   virtual ~SRP0DgSrvRequestRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ServicerequestMngd_undef.h>
#endif
