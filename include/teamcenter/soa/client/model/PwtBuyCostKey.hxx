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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PWTBUYCOSTKEY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PWTBUYCOSTKEY_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/model/GmoMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class PwtCostElement;


class TCSOAGMOMODELMNGD_API PwtBuyCostKey : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_plant();
    const std::string& get_supplier();
    const std::string& get_percentage();
    size_t count_cost_elem_list();
    Teamcenter::Soa::Common::AutoPtr<PwtCostElement> get_cost_elem_list_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("PwtBuyCostKey")

   virtual ~PwtBuyCostKey();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
