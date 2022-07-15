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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SRP0GNSRVREQUESTREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SRP0GNSRVREQUESTREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/GnChangeRequestRevision.hxx>

#include <teamcenter/soa/client/model/ServicerequestMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOASERVICEREQUESTMODELMNGD_API SRP0GnSrvRequestRevision : public Teamcenter::Soa::Client::Model::GnChangeRequestRevision
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_SRP0MROProduct();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_srp0MROSupervisor();
    const std::string& get_srp0ParentRequest();
    const std::string& get_SRP0MROSupervisorId();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("SRP0GnSrvRequestRevision")

   virtual ~SRP0GnSrvRequestRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ServicerequestMngd_undef.h>
#endif
