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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CPGFORMULAMATERREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CPGFORMULAMATERREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/MaterialBaseRevision.hxx>

#include <teamcenter/soa/client/model/CpgmaterialsMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACPGMATERIALSMODELMNGD_API CPGFormulaMaterRevision : public Teamcenter::Soa::Client::Model::MaterialBaseRevision
{
public:
    const std::string& get_material_characteristic();
    const std::string& get_material_function();
    const std::string& get_feedstock_origin();
    int get_shelf_life();
    const Teamcenter::Soa::Common::DateTime& get_expiry_date();
    bool get_kosher();
    double get_projected_volume();
    const std::string& get_supplier_transport();
    const std::string& get_experimental_id();
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
    const Teamcenter::Soa::Client::ModelObjectVector& get_FND_Tracelink_reverse();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CPGFormulaMaterRevision")

   virtual ~CPGFormulaMaterRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CpgmaterialsMngd_undef.h>
#endif
