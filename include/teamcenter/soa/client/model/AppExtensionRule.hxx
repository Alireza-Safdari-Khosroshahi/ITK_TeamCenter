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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_APPEXTENSIONRULE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_APPEXTENSIONRULE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/BusinessElement.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class AppExtensionRuleType;
                class BusinessContext;


class TCSOACLIENTMNGD_API AppExtensionRule : public Teamcenter::Soa::Client::Model::BusinessElement
{
public:
    const std::string& get_id();
    Teamcenter::Soa::Common::AutoPtr<AppExtensionRuleType> get_rule_type();
    size_t count_contexts();
    Teamcenter::Soa::Common::AutoPtr<BusinessContext> get_contexts_at( size_t inx );
    bool get_secure();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AppExtensionRule")

   virtual ~AppExtensionRule();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
