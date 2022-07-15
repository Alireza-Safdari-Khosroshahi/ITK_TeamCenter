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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ACTIVITYCOST_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ACTIVITYCOST_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/WorkspaceObject.hxx>

#include <teamcenter/soa/client/model/TransactionprocessingMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOATRANSACTIONPROCESSINGMODELMNGD_API ActivityCost : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    double get_estimated_total_cost();
    double get_estimated_total_charge();
    double get_actual_total_charge();
    double get_estimated_labor_hours();
    double get_actual_labor_hours();
    double get_estimated_labor_cost();
    double get_actual_labor_cost();
    double get_estimated_labor_charge();
    double get_actual_labor_charge();
    double get_estimated_material_cost();
    double get_actual_material_cost();
    double get_estimated_material_charge();
    double get_actual_material_charge();
    double get_actual_total_cost();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ActivityCost")

   virtual ~ActivityCost();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/TransactionprocessingMngd_undef.h>
#endif
