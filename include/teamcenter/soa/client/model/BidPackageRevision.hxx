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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_BIDPACKAGEREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_BIDPACKAGEREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ItemRevision.hxx>

#include <teamcenter/soa/client/model/VendormanagementMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class BidPackageContent;


class TCSOAVENDORMANAGEMENTMODELMNGD_API BidPackageRevision : public Teamcenter::Soa::Client::Model::ItemRevision
{
public:
    const Teamcenter::Soa::Common::DateTime& get_reqd_date();
    const std::string& get_req_purpose();
    Teamcenter::Soa::Common::AutoPtr<BidPackageContent> get_bid_package_content();
    const Teamcenter::Soa::Client::ModelObjectVector& get_lineitems();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("BidPackageRevision")

   virtual ~BidPackageRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/VendormanagementMngd_undef.h>
#endif
