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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_RLZ0REALIZATION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_RLZ0REALIZATION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_application_object.hxx>

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
                class RevisionRule;


class TCSOAREALIZATIONMODELMNGD_API Rlz0Realization : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    Teamcenter::Soa::Common::AutoPtr<POM_object> get_rlz0target_model();
    Teamcenter::Soa::Common::AutoPtr<RevisionRule> get_rlz0revision_rule();
    const Teamcenter::Soa::Client::StringVector& get_rlz0revrule_strings();
    bool get_rlz0sync_variant_exprs();
    bool get_rlz0sync_effectivity_exprs();
    bool get_rlz0sync_source_object_attr();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Rlz0Realization")

   virtual ~Rlz0Realization();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/RealizationMngd_undef.h>
#endif
