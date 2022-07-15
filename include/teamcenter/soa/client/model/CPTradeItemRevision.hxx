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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CPTRADEITEMREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CPTRADEITEMREVISION_HXX

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


class TCSOAFPMGMTMODELMNGD_API CPTradeItemRevision : public Teamcenter::Soa::Client::Model::ItemRevision
{
public:
    const std::string& get_brand_name();
    const std::string& get_target_market();
    int get_qty_trade_item_in_layer();
    int get_qty_layers_in_trade_item();
    const Teamcenter::Soa::Common::DateTime& get_reg_expiry_date();
    const std::string& get_unit_descriptor();
    const Teamcenter::Soa::Client::ModelObjectVector& get_CP_finished_products();
    const std::string& get_gtin();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CPTradeItemRevision")

   virtual ~CPTradeItemRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/FpmgmtMngd_undef.h>
#endif
