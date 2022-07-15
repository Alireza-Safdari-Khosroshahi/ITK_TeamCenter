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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MANUFACTURERPART_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MANUFACTURERPART_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Part.hxx>

#include <teamcenter/soa/client/model/VendormanagementMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class Vendor;
                class CompanyLocation;


class TCSOAVENDORMANAGEMENTMODELMNGD_API ManufacturerPart : public Teamcenter::Soa::Client::Model::Part
{
public:
    Teamcenter::Soa::Common::AutoPtr<Vendor> get_vm0vendor_ref();
    Teamcenter::Soa::Common::AutoPtr<CompanyLocation> get_vm0company_location();
    const Teamcenter::Soa::Client::ModelObjectVector& get_vendors();
    const Teamcenter::Soa::Client::ModelObjectVector& get_commercialparts();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_Quality_Document();
    const Teamcenter::Soa::Client::ModelObjectVector& get_ProvidedFrom();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_vm0location();
    const std::string& get_vendor_id();
    const std::string& get_vendor_locations();
    const std::string& get_vendor_name();
    const std::string& get_vendor_part_num();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ManufacturerPart")

   virtual ~ManufacturerPart();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/VendormanagementMngd_undef.h>
#endif
