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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CPDESIGNBRIEFREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CPDESIGNBRIEFREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/CPBriefRevision.hxx>

#include <teamcenter/soa/client/model/PkgartMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAPKGARTMODELMNGD_API CPDesignBriefRevision : public Teamcenter::Soa::Client::Model::CPBriefRevision
{
public:
    const std::string& get_competition();
    const std::string& get_design_objectives();
    const std::string& get_design_strategy();
    const std::string& get_priority_of_communication();
    const std::string& get_success_criteria();
    const std::string& get_inspiration();
    double get_target_direct_cost();
    const std::string& get_packing_instructions();
    const std::string& get_fmot();
    const std::string& get_smot();
    const std::string& get_consumer_insight();
    const std::string& get_currency();
    const Teamcenter::Soa::Client::ModelObjectVector& get_CP_Results_In_Package_Rough();
    const Teamcenter::Soa::Client::ModelObjectVector& get_CP_Has_Graphical_Element();
    const Teamcenter::Soa::Client::ModelObjectVector& get_CP_marketing_briefs();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CPDesignBriefRevision")

   virtual ~CPDesignBriefRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/PkgartMngd_undef.h>
#endif
