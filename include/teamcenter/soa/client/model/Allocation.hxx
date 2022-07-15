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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ALLOCATION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ALLOCATION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ManagedRelation.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class AbsOccurrence;
                class AbsOccurrence;
                class AllocationMapRevision;


class TCSOACLIENTMNGD_API Allocation : public Teamcenter::Soa::Client::Model::ManagedRelation
{
public:
    Teamcenter::Soa::Common::AutoPtr<AbsOccurrence> get_source_absOcc_tag();
    Teamcenter::Soa::Common::AutoPtr<AbsOccurrence> get_target_absOcc_tag();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_config_condition();
    Teamcenter::Soa::Common::AutoPtr<AllocationMapRevision> get_map_rev_tag();
    const std::string& get_alloc_reason_string();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Allocation")

   virtual ~Allocation();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
