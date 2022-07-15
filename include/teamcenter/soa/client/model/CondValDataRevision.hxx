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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CONDVALDATAREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CONDVALDATAREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ValDataRevision.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class VerificationRule;


class TCSOACLIENTMNGD_API CondValDataRevision : public Teamcenter::Soa::Client::Model::ValDataRevision
{
public:
    size_t count_verificationRules();
    Teamcenter::Soa::Common::AutoPtr<VerificationRule> get_verificationRules_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CondValDataRevision")

   virtual ~CondValDataRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
