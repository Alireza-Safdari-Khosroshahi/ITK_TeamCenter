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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_LINEITEMCONFIGCONTEXT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_LINEITEMCONFIGCONTEXT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ConfigurationContext.hxx>

#include <teamcenter/soa/client/model/VendormanagementMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class PSViewType;


class TCSOAVENDORMANAGEMENTMODELMNGD_API LineItemConfigContext : public Teamcenter::Soa::Client::Model::ConfigurationContext
{
public:
    Teamcenter::Soa::Common::AutoPtr<PSViewType> get_view_type();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("LineItemConfigContext")

   virtual ~LineItemConfigContext();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/VendormanagementMngd_undef.h>
#endif
