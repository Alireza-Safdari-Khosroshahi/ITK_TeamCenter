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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PRODUCTVARIANTINTENT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PRODUCTVARIANTINTENT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/StructureContext.hxx>

#include <teamcenter/soa/client/model/ProductvariantMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAPRODUCTVARIANTMODELMNGD_API ProductVariantIntent : public Teamcenter::Soa::Client::Model::StructureContext
{
public:
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_product_variant();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ProductVariantIntent")

   virtual ~ProductVariantIntent();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ProductvariantMngd_undef.h>
#endif
