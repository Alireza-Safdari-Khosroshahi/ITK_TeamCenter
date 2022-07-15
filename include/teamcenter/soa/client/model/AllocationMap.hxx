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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ALLOCATIONMAP_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ALLOCATIONMAP_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Item.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class PSBOMView;
                class PSBOMView;
                class PSBOMView;


class TCSOACLIENTMNGD_API AllocationMap : public Teamcenter::Soa::Client::Model::Item
{
public:
    Teamcenter::Soa::Common::AutoPtr<PSBOMView> get_source_bv_tag();
    Teamcenter::Soa::Common::AutoPtr<PSBOMView> get_target_bv_tag();
    size_t count_product_rep_bvs_tag();
    Teamcenter::Soa::Common::AutoPtr<PSBOMView> get_product_rep_bvs_tag_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AllocationMap")

   virtual ~AllocationMap();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
