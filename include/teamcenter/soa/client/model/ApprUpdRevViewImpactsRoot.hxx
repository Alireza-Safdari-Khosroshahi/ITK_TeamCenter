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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_APPRUPDREVVIEWIMPACTSROOT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_APPRUPDREVVIEWIMPACTSROOT_HXX

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
                class Appearance;
                class ItemRevision;
                class PSBOMView;


class TCSOACLIENTMNGD_API ApprUpdRevViewImpactsRoot : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    Teamcenter::Soa::Common::AutoPtr<AppearanceRoot> get_ap_root();
    size_t count_parent_aps();
    Teamcenter::Soa::Common::AutoPtr<Appearance> get_parent_aps_at( size_t inx );
    const Teamcenter::Soa::Common::DateTime& get_release_date();
    Teamcenter::Soa::Common::AutoPtr<ItemRevision> get_changed_item_revision();
    Teamcenter::Soa::Common::AutoPtr<PSBOMView> get_bom_view();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ApprUpdRevViewImpactsRoot")

   virtual ~ApprUpdRevViewImpactsRoot();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
