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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ISMANUFACTURERATTRSTORAGE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ISMANUFACTURERATTRSTORAGE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/model/SpecmgrMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class CPManufacturer;


class TCSOASPECMGRMODELMNGD_API ISManufacturerAttrStorage : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    int get_manufacturer_id();
    int get_manufacturer_type_id();
    const std::string& get_trade_name();
    const std::string& get_product_code();
    const std::string& get_clearance_number();
    const Teamcenter::Soa::Common::DateTime& get_approval_date();
    const Teamcenter::Soa::Common::DateTime& get_audit_date();
    int get_audit_frequency();
    Teamcenter::Soa::Common::AutoPtr<CPManufacturer> get_spm0manufacturer();
    const std::string& get_spm0plant_no();
    const std::string& get_spm0plant_desc();
    const std::string& get_spm0part_manu_rev();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ISManufacturerAttrStorage")

   virtual ~ISManufacturerAttrStorage();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/SpecmgrMngd_undef.h>
#endif
