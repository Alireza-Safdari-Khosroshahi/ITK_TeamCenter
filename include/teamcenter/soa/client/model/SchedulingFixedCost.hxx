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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SCHEDULINGFIXEDCOST_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SCHEDULINGFIXEDCOST_HXX

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
                class CostValue;
                class CostValue;


class TCSOACLIENTMNGD_API SchedulingFixedCost : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_cost_name();
    bool get_use_actual_cost();
    int get_accrual_type();
    const std::string& get_bill_code();
    const std::string& get_bill_sub_code();
    const std::string& get_bill_type();
    Teamcenter::Soa::Common::AutoPtr<CostValue> get_act_costvalue_form_tag();
    Teamcenter::Soa::Common::AutoPtr<CostValue> get_est_costvalue_form_tag();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("SchedulingFixedCost")

   virtual ~SchedulingFixedCost();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
