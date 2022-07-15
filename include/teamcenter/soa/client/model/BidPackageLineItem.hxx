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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_BIDPACKAGELINEITEM_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_BIDPACKAGELINEITEM_HXX

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
                class LineItemConfigContext;


class TCSOAVENDORMANAGEMENTMODELMNGD_API BidPackageLineItem : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    Teamcenter::Soa::Common::AutoPtr<LineItemConfigContext> get_configuration_context();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_part();
    double get_quantity();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_cust_line_item_attrs();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_part_quote_rel();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("BidPackageLineItem")

   virtual ~BidPackageLineItem();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/VendormanagementMngd_undef.h>
#endif
