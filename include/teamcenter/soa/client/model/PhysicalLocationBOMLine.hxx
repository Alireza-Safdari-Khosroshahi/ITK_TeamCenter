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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PHYSICALLOCATIONBOMLINE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PHYSICALLOCATIONBOMLINE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ImanItemLine.hxx>

#include <teamcenter/soa/client/model/AsmaintainedMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAASMAINTAINEDMODELMNGD_API PhysicalLocationBOMLine : public Teamcenter::Soa::Client::Model::ImanItemLine
{
public:
    const std::string& get_plbl_location_name();
    const std::string& get_plbl_location_description();
    const std::string& get_plbl_location_type();
    const std::string& get_plbl_company_street();
    const std::string& get_plbl_company_city();
    const std::string& get_plbl_company_state_province();
    const std::string& get_plbl_company_postal_code();
    const std::string& get_plbl_company_country();
    const std::string& get_plbl_company_region();
    const std::string& get_plbl_company_url();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("PhysicalLocationBOMLine")

   virtual ~PhysicalLocationBOMLine();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/AsmaintainedMngd_undef.h>
#endif
