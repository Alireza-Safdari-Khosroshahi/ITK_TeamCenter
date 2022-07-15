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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DISPOSITIONAPPLICABILITY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DISPOSITIONAPPLICABILITY_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ImanRelation.hxx>

#include <teamcenter/soa/client/model/AsmaintainedMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class DispApplicabilityData;


class TCSOAASMAINTAINEDMODELMNGD_API DispositionApplicability : public Teamcenter::Soa::Client::Model::ImanRelation
{
public:
    const Teamcenter::Soa::Common::DateTime& get_dispStartTime();
    const Teamcenter::Soa::Common::DateTime& get_dispEndTime();
    size_t count_historicalData();
    Teamcenter::Soa::Common::AutoPtr<DispApplicabilityData> get_historicalData_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DispositionApplicability")

   virtual ~DispositionApplicability();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/AsmaintainedMngd_undef.h>
#endif
