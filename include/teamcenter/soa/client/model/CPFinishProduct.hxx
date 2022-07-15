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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CPFINISHPRODUCT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CPFINISHPRODUCT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Item.hxx>

#include <teamcenter/soa/client/model/FpmgmtMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAFPMGMTMODELMNGD_API CPFinishProduct : public Teamcenter::Soa::Client::Model::Item
{
public:
    const std::string& get_finished_product_code();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CPFinishProduct")

   virtual ~CPFinishProduct();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/FpmgmtMngd_undef.h>
#endif
