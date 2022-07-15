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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PRODUCTVARIANT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PRODUCTVARIANT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/CCObject.hxx>

#include <teamcenter/soa/client/model/ProductvariantMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class ItemRevision;


class TCSOAPRODUCTVARIANTMODELMNGD_API ProductVariant : public Teamcenter::Soa::Client::Model::CCObject
{
public:
    Teamcenter::Soa::Common::AutoPtr<ItemRevision> get_productCtxt();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ProductVariant")

   virtual ~ProductVariant();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ProductvariantMngd_undef.h>
#endif
