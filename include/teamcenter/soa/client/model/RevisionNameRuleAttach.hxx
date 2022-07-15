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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_REVISIONNAMERULEATTACH_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_REVISIONNAMERULEATTACH_HXX

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
                class RevisionNameRule;


class TCSOACLIENTMNGD_API RevisionNameRuleAttach : public Teamcenter::Soa::Client::Model::BusinessRule
{
public:
    const std::string& get_type_name();
    int get_case();
    Teamcenter::Soa::Common::AutoPtr<RevisionNameRule> get_rev_rule_tag();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("RevisionNameRuleAttach")

   virtual ~RevisionNameRuleAttach();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
