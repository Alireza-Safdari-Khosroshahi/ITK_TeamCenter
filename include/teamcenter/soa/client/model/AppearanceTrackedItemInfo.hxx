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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_APPEARANCETRACKEDITEMINFO_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_APPEARANCETRACKEDITEMINFO_HXX

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
                class Item;
                class PSBOMView;


class TCSOACLIENTMNGD_API AppearanceTrackedItemInfo : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    Teamcenter::Soa::Common::AutoPtr<Item> get_tracked_item();
    Teamcenter::Soa::Common::AutoPtr<PSBOMView> get_bom_view();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AppearanceTrackedItemInfo")

   virtual ~AppearanceTrackedItemInfo();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
