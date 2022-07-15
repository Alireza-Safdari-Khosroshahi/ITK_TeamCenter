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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PHYSICALBOMLINE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PHYSICALBOMLINE_HXX

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


class TCSOAMROCOREMODELMNGD_API PhysicalBOMLine : public Teamcenter::Soa::Client::Model::ImanItemLine
{
public:
    const std::string& get_phbl_serial_number();
    const std::string& get_phbl_lot_number();
    const std::string& get_phbl_part_number();
    const std::string& get_phbl_mfgr_org_id();
    const std::string& get_phbl_mfg_date();
    const std::string& get_phbl_physical_uid();
    const std::string& get_phbl_part_used_is();
    const std::string& get_phbl_installation_time();
    const std::string& get_phbl_part_usage_name();
    bool get_phbl_is_item_lot();
    bool get_phbl_is_item_serialized();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_phbl_lot_tag();
    const std::string& get_phbl_design_rev_id();
    bool get_phbl_is_standalone();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("PhysicalBOMLine")

   virtual ~PhysicalBOMLine();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/MrocoreMngd_undef.h>
#endif
