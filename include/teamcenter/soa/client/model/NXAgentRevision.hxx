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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_NXAGENTREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_NXAGENTREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ValToolAgentRevision.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class ClosureRule;


class TCSOACLIENTMNGD_API NXAgentRevision : public Teamcenter::Soa::Client::Model::ValToolAgentRevision
{
public:
    Teamcenter::Soa::Common::AutoPtr<ClosureRule> get_validation_closure_rule();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("NXAgentRevision")

   virtual ~NXAgentRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
