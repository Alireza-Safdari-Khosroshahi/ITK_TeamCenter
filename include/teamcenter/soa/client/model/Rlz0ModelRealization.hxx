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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_RLZ0MODELREALIZATION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_RLZ0MODELREALIZATION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Rlz0Realization.hxx>

#include <teamcenter/soa/client/model/RealizationMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class POM_object;
                class VariantRule;


class TCSOAREALIZATIONMODELMNGD_API Rlz0ModelRealization : public Teamcenter::Soa::Client::Model::Rlz0Realization
{
public:
    Teamcenter::Soa::Common::AutoPtr<POM_object> get_rlz0source_model();
    Teamcenter::Soa::Common::AutoPtr<VariantRule> get_rlz0variant_rule();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Rlz0ModelRealization")

   virtual ~Rlz0ModelRealization();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/RealizationMngd_undef.h>
#endif
