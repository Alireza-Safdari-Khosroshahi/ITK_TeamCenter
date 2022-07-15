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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_EXTENSIONPOINT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_EXTENSIONPOINT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/BusinessRule.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class ExtensionDescriptor;


class TCSOACLIENTMNGD_API ExtensionPoint : public Teamcenter::Soa::Client::Model::BusinessRule
{
public:
    const std::string& get_name();
    bool get_is_overrideable();
    bool get_single_extension_only();
    int get_extpnt_type();
    size_t count_ext_descriptors();
    Teamcenter::Soa::Common::AutoPtr<ExtensionDescriptor> get_ext_descriptors_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ExtensionPoint")

   virtual ~ExtensionPoint();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
