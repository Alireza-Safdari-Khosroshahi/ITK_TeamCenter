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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_APPRITEMREVORDER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_APPRITEMREVORDER_HXX

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
                class AppearanceRoot;
                class ItemRevision;
                class Item;


class TCSOACLIENTMNGD_API ApprItemRevOrder : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    Teamcenter::Soa::Common::AutoPtr<AppearanceRoot> get_appr_root();
    const Teamcenter::Soa::Common::DateTimeVector& get_mod_dates();
    size_t count_ordered_revs();
    Teamcenter::Soa::Common::AutoPtr<ItemRevision> get_ordered_revs_at( size_t inx );
    Teamcenter::Soa::Common::AutoPtr<Item> get_item();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ApprItemRevOrder")

   virtual ~ApprItemRevOrder();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
