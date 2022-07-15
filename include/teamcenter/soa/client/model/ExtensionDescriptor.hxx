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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_EXTENSIONDESCRIPTOR_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_EXTENSIONDESCRIPTOR_HXX

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
                class Extension;
                class ImanParameters;


class TCSOACLIENTMNGD_API ExtensionDescriptor : public Teamcenter::Soa::Client::Model::BusinessRule
{
public:
    const std::string& get_condition();
    int get_priority();
    Teamcenter::Soa::Common::AutoPtr<Extension> get_extn();
    Teamcenter::Soa::Common::AutoPtr<ImanParameters> get_args();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ExtensionDescriptor")

   virtual ~ExtensionDescriptor();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
