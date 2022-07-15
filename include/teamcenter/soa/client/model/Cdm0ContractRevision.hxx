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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CDM0CONTRACTREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CDM0CONTRACTREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/DocumentRevision.hxx>

#include <teamcenter/soa/client/model/Cdm0contractmanagementMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class Schedule;


class TCSOACDM0CONTRACTMANAGEMENTMODELMNGD_API Cdm0ContractRevision : public Teamcenter::Soa::Client::Model::DocumentRevision
{
public:
    const std::string& get_cdm0Comments();
    double get_cdm0ContractCost();
    double get_cdm0ContractCostDelta();
    Teamcenter::Soa::Common::AutoPtr<Schedule> get_cdm0ContractEventSch();
    const std::string& get_cdm0ContractPricingModel();
    const Teamcenter::Soa::Common::DateTime& get_cdm0EffectiveDate();
    const std::string& get_cdm0OfficePrimaryResp();
    double get_cdm0PeriodOfPerformance();
    bool get_cdm0RecurringCost();
    bool get_cdm0SOWAffected();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Cdm0ListsContractDRI();
    const Teamcenter::Soa::Client::ModelObjectVector& get_cdm0ContractHasCorespondce();
    const Teamcenter::Soa::Client::ModelObjectVector& get_cdm0ContractScheduleTasks();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Cdm0ContractRevision")

   virtual ~Cdm0ContractRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/Cdm0contractmanagementMngd_undef.h>
#endif
