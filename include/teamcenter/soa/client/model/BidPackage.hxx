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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_BIDPACKAGE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_BIDPACKAGE_HXX

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


class TCSOAVENDORMANAGEMENTMODELMNGD_API BidPackage : public Teamcenter::Soa::Client::Model::Item
{
public:
    const std::string& get_bid_package_type();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("BidPackage")

   virtual ~BidPackage();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/VendormanagementMngd_undef.h>
#endif
