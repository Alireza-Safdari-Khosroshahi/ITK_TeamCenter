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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_BIDPACKAGECONTENT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_BIDPACKAGECONTENT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/WorkspaceObject.hxx>

#include <teamcenter/soa/client/model/VendormanagementMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class BidPackageLineItem;


class TCSOAVENDORMANAGEMENTMODELMNGD_API BidPackageContent : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    size_t count_line_item();
    Teamcenter::Soa::Common::AutoPtr<BidPackageLineItem> get_line_item_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("BidPackageContent")

   virtual ~BidPackageContent();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/VendormanagementMngd_undef.h>
#endif
