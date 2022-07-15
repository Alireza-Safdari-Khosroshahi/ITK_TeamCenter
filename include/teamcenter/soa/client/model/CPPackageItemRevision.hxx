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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CPPACKAGEITEMREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CPPACKAGEITEMREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ItemRevision.hxx>

#include <teamcenter/soa/client/model/PkgartMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class UnitOfMeasure;
                class UnitOfMeasure;


class TCSOAPKGARTMODELMNGD_API CPPackageItemRevision : public Teamcenter::Soa::Client::Model::ItemRevision
{
public:
    const std::string& get_package_priority();
    int get_case_count();
    double get_height();
    double get_width();
    double get_depth();
    double get_gross_weight();
    const std::string& get_currency();
    double get_cost();
    const std::string& get_packaging_level();
    const std::string& get_shape();
    bool get_is_lead_package();
    Teamcenter::Soa::Common::AutoPtr<UnitOfMeasure> get_dimension_unit();
    Teamcenter::Soa::Common::AutoPtr<UnitOfMeasure> get_weight_unit();
    const Teamcenter::Soa::Client::StringVector& get_country_of_sale();
    const std::string& get_package_type();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CPPackageItemRevision")

   virtual ~CPPackageItemRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/PkgartMngd_undef.h>
#endif
