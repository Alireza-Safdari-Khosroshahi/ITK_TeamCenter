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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_NAMERULE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_NAMERULE_HXX

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
                class NameRulePattern;


class TCSOACLIENTMNGD_API NameRule : public Teamcenter::Soa::Client::Model::BusinessRule
{
public:
    const std::string& get_rule_name();
    size_t count_name_patterns();
    Teamcenter::Soa::Common::AutoPtr<NameRulePattern> get_name_patterns_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("NameRule")

   virtual ~NameRule();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
