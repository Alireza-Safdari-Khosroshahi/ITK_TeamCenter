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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CPFINISHPRODUCTREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CPFINISHPRODUCTREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ItemRevision.hxx>

#include <teamcenter/soa/client/model/FpmgmtMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class UnitOfMeasure;
                class UnitOfMeasure;


class TCSOAFPMGMTMODELMNGD_API CPFinishProductRevision : public Teamcenter::Soa::Client::Model::ItemRevision
{
public:
    const std::string& get_shelf_life();
    const Teamcenter::Soa::Client::StringVector& get_country_of_sale();
    const std::string& get_channel();
    const std::string& get_market_clearance_no();
    Teamcenter::Soa::Common::AutoPtr<UnitOfMeasure> get_dimension_unit();
    double get_height();
    double get_width();
    double get_depth();
    Teamcenter::Soa::Common::AutoPtr<UnitOfMeasure> get_weight_unit();
    double get_gross_weight();
    const std::string& get_currency();
    double get_price();
    const std::string& get_storage_conditions();
    const Teamcenter::Soa::Client::ModelObjectVector& get_CP_trade_item();
    const std::string& get_finished_product_code();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CPFinishProductRevision")

   virtual ~CPFinishProductRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/FpmgmtMngd_undef.h>
#endif
