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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SCHMGTCOSTFORMSTORAGE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SCHMGTCOSTFORMSTORAGE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class BillRate;
                class SchedulingFixedCost;


class TCSOACLIENTMNGD_API SchMgtCostFormStorage : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_bill_code();
    const std::string& get_bill_sub_code();
    const std::string& get_bill_type();
    Teamcenter::Soa::Common::AutoPtr<BillRate> get_billrate_tag();
    size_t count_fixed_cost_taglist();
    Teamcenter::Soa::Common::AutoPtr<SchedulingFixedCost> get_fixed_cost_taglist_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("SchMgtCostFormStorage")

   virtual ~SchMgtCostFormStorage();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
