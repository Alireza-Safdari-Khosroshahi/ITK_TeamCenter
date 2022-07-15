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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_VERIFICATIONRULE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_VERIFICATIONRULE_HXX

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
                class FunctionalityRule;
                class Condition;


class TCSOACLIENTMNGD_API VerificationRule : public Teamcenter::Soa::Client::Model::BusinessRule
{
public:
    Teamcenter::Soa::Common::AutoPtr<FunctionalityRule> get_functionality();
    const std::string& get_type();
    const std::string& get_subGroup();
    Teamcenter::Soa::Common::AutoPtr<Condition> get_context_filter();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("VerificationRule")

   virtual ~VerificationRule();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
