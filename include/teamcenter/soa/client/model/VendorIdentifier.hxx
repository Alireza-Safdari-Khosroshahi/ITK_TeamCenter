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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_VENDORIDENTIFIER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_VENDORIDENTIFIER_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Identifier.hxx>

#include <teamcenter/soa/client/model/VendormanagementMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class Item;


class TCSOAVENDORMANAGEMENTMODELMNGD_API VendorIdentifier : public Teamcenter::Soa::Client::Model::Identifier
{
public:
    Teamcenter::Soa::Common::AutoPtr<Item> get_part();
    const std::string& get_preferred_status();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("VendorIdentifier")

   virtual ~VendorIdentifier();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/VendormanagementMngd_undef.h>
#endif
