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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CONDVALRESULT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CONDVALRESULT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ValidationResult.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class StructureContext;
                class Condition;
                class ValidationAgentRevision;


class TCSOACLIENTMNGD_API CondValResult : public Teamcenter::Soa::Client::Model::ValidationResult
{
public:
    Teamcenter::Soa::Common::AutoPtr<StructureContext> get_context();
    Teamcenter::Soa::Common::AutoPtr<Condition> get_condition();
    Teamcenter::Soa::Common::AutoPtr<ValidationAgentRevision> get_valagent_revision();
    const std::string& get_condition_desc();
    const std::string& get_condition_name();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_client_target();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CondValResult")

   virtual ~CondValResult();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
