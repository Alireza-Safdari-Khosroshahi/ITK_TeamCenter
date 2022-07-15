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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SRP0RQSTACTIVITYREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SRP0RQSTACTIVITYREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/SRP0GnSrvRequestRevision.hxx>

#include <teamcenter/soa/client/model/ServicerequestMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class ActivityCost;


class TCSOASERVICEREQUESTMODELMNGD_API SRP0RqstActivityRevision : public Teamcenter::Soa::Client::Model::SRP0GnSrvRequestRevision
{
public:
    Teamcenter::Soa::Common::AutoPtr<ActivityCost> get_SRP0ActivityCost();
    const std::string& get_SRP0Notes();
    const std::string& get_SRP0Narrative();
    const Teamcenter::Soa::Common::DateTime& get_SRP0NeededByDate();
    const Teamcenter::Soa::Client::ModelObjectVector& get_SRP0ActivityDiscrepancy();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_srp0PhysicalElement();
    const Teamcenter::Soa::Client::ModelObjectVector& get_srp0ServiceOfferings();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_srp0ServiceRequest();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_SRP0RequestedActivity();
    const Teamcenter::Soa::Client::ModelObjectVector& get_ActivityDiscrepancyFolder();
    const Teamcenter::Soa::Client::ModelObjectVector& get_MROProductFolder();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("SRP0RqstActivityRevision")

   virtual ~SRP0RqstActivityRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ServicerequestMngd_undef.h>
#endif
