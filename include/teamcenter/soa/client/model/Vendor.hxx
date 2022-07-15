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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_VENDOR_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_VENDOR_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Item.hxx>

#include <teamcenter/soa/client/model/VendormanagementMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAVENDORMANAGEMENTMODELMNGD_API Vendor : public Teamcenter::Soa::Client::Model::Item
{
public:
    const std::string& get_supplier_addr();
    const std::string& get_web_site();
    const std::string& get_supplier_phone();
    const std::string& get_email_addr();
    const std::string& get_contact_name();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_vendor_group();
    const Teamcenter::Soa::Client::ModelObjectVector& get_commercialparts();
    const Teamcenter::Soa::Client::ModelObjectVector& get_vendorparts();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_Quality_Document();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Vendor")

   virtual ~Vendor();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/VendormanagementMngd_undef.h>
#endif
