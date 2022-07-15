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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SERVICEDISCREPANCY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SERVICEDISCREPANCY_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ServiceActivity.hxx>

#include <teamcenter/soa/client/model/ServiceprocessingMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class FaultCode;


class TCSOASERVICEPROCESSINGMODELMNGD_API ServiceDiscrepancy : public Teamcenter::Soa::Client::Model::ServiceActivity
{
public:
    const std::string& get_severity();
    bool get_is_failure();
    const std::string& get_discovered_by();
    const Teamcenter::Soa::Common::DateTime& get_discovery_date();
    size_t count_fault_code();
    Teamcenter::Soa::Common::AutoPtr<FaultCode> get_fault_code_at( size_t inx );
    const Teamcenter::Soa::Client::ModelObjectVector& get_CorrectiveAction();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ServiceDiscrepancy")

   virtual ~ServiceDiscrepancy();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ServiceprocessingMngd_undef.h>
#endif
