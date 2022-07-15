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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_VENDORROLE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_VENDORROLE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/model/VendormanagementMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class Form;


class TCSOAVENDORMANAGEMENTMODELMNGD_API VendorRole : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_vendor_role_name();
    const std::string& get_description();
    Teamcenter::Soa::Common::AutoPtr<Form> get_vendor_role_info();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("VendorRole")

   virtual ~VendorRole();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/VendormanagementMngd_undef.h>
#endif
