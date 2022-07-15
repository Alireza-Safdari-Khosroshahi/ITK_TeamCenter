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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_NEUTRALBOMLINE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_NEUTRALBOMLINE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ImanItemLine.hxx>

#include <teamcenter/soa/client/model/MrocoreMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAMROCOREMODELMNGD_API NeutralBOMLine : public Teamcenter::Soa::Client::Model::ImanItemLine
{
public:
    bool get_npbl_is_item_serialized();
    bool get_npbl_is_item_lot();
    bool get_npbl_is_item_traceable();
    bool get_npbl_is_item_rotable();
    bool get_npbl_is_item_consumable();
    bool get_npbl_preserve_quantity();
    bool get_npbl_life_limited();
    const std::string& get_phbl_part_number();
    const std::string& get_phbl_part_usage_name();
    const std::string& get_phbl_part_used_is();
    const std::string& get_phbl_design_rev_id();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("NeutralBOMLine")

   virtual ~NeutralBOMLine();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/MrocoreMngd_undef.h>
#endif
