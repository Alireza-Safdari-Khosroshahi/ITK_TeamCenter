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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FUNCTIONALITYRULE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FUNCTIONALITYRULE_HXX

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
                class ConditionSignature;


class TCSOACLIENTMNGD_API FunctionalityRule : public Teamcenter::Soa::Client::Model::BusinessElement
{
public:
    const std::string& get_display_name();
    bool get_enabledForVerificationRules();
    const Teamcenter::Soa::Client::StringVector& get_type_scope();
    const std::string& get_subGroupLOV();
    size_t count_condition_signatures();
    Teamcenter::Soa::Common::AutoPtr<ConditionSignature> get_condition_signatures_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("FunctionalityRule")

   virtual ~FunctionalityRule();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
