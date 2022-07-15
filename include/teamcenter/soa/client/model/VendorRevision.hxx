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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_VENDORREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_VENDORREVISION_HXX

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
                class VendorRole;


class TCSOAVENDORMANAGEMENTMODELMNGD_API VendorRevision : public Teamcenter::Soa::Client::Model::ItemRevision
{
public:
    const std::string& get_comments();
    size_t count_vendor_role_list();
    Teamcenter::Soa::Common::AutoPtr<VendorRole> get_vendor_role_list_at( size_t inx );
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_Quality_Document();
    const Teamcenter::Soa::Client::ModelObjectVector& get_vendor_role_info();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("VendorRevision")

   virtual ~VendorRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/VendormanagementMngd_undef.h>
#endif
