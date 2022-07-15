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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CPGRAWMATERIALREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CPGRAWMATERIALREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/RawMaterialRevision.hxx>

#include <teamcenter/soa/client/model/CpgmaterialsMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACPGMATERIALSMODELMNGD_API CPGRawMaterialRevision : public Teamcenter::Soa::Client::Model::RawMaterialRevision
{
public:
    const std::string& get_product_number();
    const std::string& get_catalog_number();
    const std::string& get_trade_name();
    const std::string& get_NFPA_HFR_rating();
    const std::string& get_Japan_tricode();
    const std::string& get_material_characteristic();
    const std::string& get_material_function();
    const std::string& get_feedstock_origin();
    int get_shelf_life();
    const Teamcenter::Soa::Common::DateTime& get_expiry_date();
    bool get_kosher();
    double get_projected_volume();
    const std::string& get_supplier_transport();
    const std::string& get_experimental_id();
    const std::string& get_CAS_number();
    const std::string& get_CAS_name();
    const std::string& get_CAS_number_alternative();
    const std::string& get_CAS_name_alternative();
    const std::string& get_EC_number();
    const std::string& get_EC_name();
    const std::string& get_IUPAC_name();
    const std::string& get_INCI_name_US();
    const std::string& get_INCI_name_EC();
    const std::string& get_INCI_name_Japan();
    const std::string& get_color_index();
    const std::string& get_r_s_phrases_manufacturer();
    const std::string& get_r_s_phrases_internal();
    const std::string& get_storage_and_handling();
    const std::string& get_TSCA_bans_restrictions();
    const std::string& get_REACH_number();
    double get_cost();
    double get_max_ingredient_level();
    const std::string& get_regulatory_restrictions();
    const std::string& get_transport_information();
    const std::string& get_state();
    const std::string& get_molecular_formula();
    const std::string& get_molecular_structure();
    double get_molecular_weight();
    double get_pH_value();
    double get_water_solubility();
    double get_oil_water_ratio();
    double get_boiling_point();
    double get_flash_point();
    double get_vapor_pressure();
    double get_specific_gravity();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CPGRawMaterialRevision")

   virtual ~CPGRawMaterialRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CpgmaterialsMngd_undef.h>
#endif
