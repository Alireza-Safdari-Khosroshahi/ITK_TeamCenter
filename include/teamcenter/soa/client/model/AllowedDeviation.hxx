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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ALLOWEDDEVIATION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ALLOWEDDEVIATION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ImanRelation.hxx>

#include <teamcenter/soa/client/model/MrocoreMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class AllowedDeviationData;


class TCSOAMROCOREMODELMNGD_API AllowedDeviation : public Teamcenter::Soa::Client::Model::ImanRelation
{
public:
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_deviationTag();
    bool get_isConsumed();
    size_t count_historicalData();
    Teamcenter::Soa::Common::AutoPtr<AllowedDeviationData> get_historicalData_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AllowedDeviation")

   virtual ~AllowedDeviation();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/MrocoreMngd_undef.h>
#endif
