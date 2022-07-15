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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SRP0SERVICEOFFERING_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SRP0SERVICEOFFERING_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/HierarchicalWSO.hxx>

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


class TCSOASERVICEREQUESTMODELMNGD_API SRP0ServiceOffering : public Teamcenter::Soa::Client::Model::HierarchicalWSO
{
public:
    const std::string& get_SRP0ServiceCode();
    const std::string& get_SRP0Narrative();
    Teamcenter::Soa::Common::AutoPtr<ActivityCost> get_SRP0ActivityCost();
    const std::string& get_SRP0ServiceOfferingNumber();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_srp0ServiceCatalog();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("SRP0ServiceOffering")

   virtual ~SRP0ServiceOffering();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ServicerequestMngd_undef.h>
#endif
