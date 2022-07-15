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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ISPROPERTYATTRSTORAGE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ISPROPERTYATTRSTORAGE_HXX

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
                class UnitOfMeasure;
                class UOMWithConversion;
                class UnitOfMeasure;
                class CPPlant;


class TCSOASPECMGRMODELMNGD_API ISPropertyAttrStorage : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    int get_property_id();
    short get_property_revision();
    const std::string& get_property_name();
    int get_attribute_id();
    short get_attribute_revision();
    const std::string& get_attribute_name();
    const std::string& get_string1();
    const std::string& get_string2();
    const std::string& get_string3();
    const std::string& get_string4();
    const std::string& get_string5();
    const std::string& get_string6();
    bool get_boolean1();
    bool get_boolean2();
    bool get_boolean3();
    bool get_boolean4();
    const Teamcenter::Soa::Common::DateTime& get_date1();
    const Teamcenter::Soa::Common::DateTime& get_date2();
    double get_numeric1();
    double get_numeric2();
    double get_numeric3();
    double get_numeric4();
    double get_numeric5();
    double get_numeric6();
    double get_numeric7();
    double get_numeric8();
    double get_numeric9();
    double get_numeric10();
    int get_characteristic_id1();
    short get_characteristic_rev1();
    const std::string& get_characteristic_desc1();
    int get_characteristic_id2();
    short get_characteristic_rev2();
    const std::string& get_characteristic_desc2();
    int get_characteristic_id3();
    short get_characteristic_rev3();
    const std::string& get_characteristic_desc3();
    int get_association_id1();
    short get_association_rev1();
    const std::string& get_association_desc1();
    int get_association_id2();
    short get_association_rev2();
    const std::string& get_association_desc2();
    int get_association_id3();
    short get_association_rev3();
    const std::string& get_association_desc3();
    Teamcenter::Soa::Common::AutoPtr<UnitOfMeasure> get_uom();
    Teamcenter::Soa::Common::AutoPtr<UOMWithConversion> get_other_uom();
    double get_lower_limit();
    double get_upper_limit();
    const std::string& get_info();
    double get_min_quantity();
    double get_max_quantity();
    bool get_is_fixed_quantity();
    bool get_is_makeup_quantity();
    double get_calulated_quantity();
    int get_test_method_id();
    int get_test_method_revision();
    const std::string& get_test_method();
    int get_test_method_set_no();
    const std::string& get_method_detail();
    double get_test_method_details1();
    double get_test_method_details2();
    double get_test_method_details3();
    double get_test_method_details4();
    double get_yield();
    double get_assembly_scrap();
    const std::string& get_code();
    const std::string& get_international_equivalent();
    double get_quantity_bompct();
    Teamcenter::Soa::Common::AutoPtr<UnitOfMeasure> get_uom_bompct();
    Teamcenter::Soa::Common::AutoPtr<CPPlant> get_plant();
    const std::string& get_spm0item_category();
    const std::string& get_spm0item_category_desc();
    const std::string& get_spm0calculation_mode();
    int get_spm0lead_offset();
    bool get_spm0relevancy_costing();
    bool get_spm0bulk_material();
    double get_spm0component_scrap();
    const std::string& get_spm0issue_loaction();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ISPropertyAttrStorage")

   virtual ~ISPropertyAttrStorage();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/SpecmgrMngd_undef.h>
#endif
