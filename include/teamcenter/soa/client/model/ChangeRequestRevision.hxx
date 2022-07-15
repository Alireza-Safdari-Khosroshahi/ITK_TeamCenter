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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CHANGEREQUESTREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CHANGEREQUESTREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/GnChangeRequestRevision.hxx>

#include <teamcenter/soa/client/model/CmMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACMMODELMNGD_API ChangeRequestRevision : public Teamcenter::Soa::Client::Model::GnChangeRequestRevision
{
public:
    const Teamcenter::Soa::Client::StringVector& get_Cm0impact_types();
    bool get_Cm0is_warranty_affected();
    const std::string& get_CMReason();
    const std::string& get_CMTechReviewPriority();
    double get_CMRecurringCost();
    double get_CMNonrecurringCost();
    const Teamcenter::Soa::Common::DateTime& get_CMTechRecommDate();
    const std::string& get_CMTestResultsAttached();
    const std::string& get_CMProposedSolution();
    const std::string& get_CMTimingFactors();
    const std::string& get_CMTechnicalRecommendation();
    const std::string& get_CMTechnicalReview();
    const Teamcenter::Soa::Client::ModelObjectVector& get_CMImpactedItems();
    const Teamcenter::Soa::Client::ModelObjectVector& get_CMImplement();
    const Teamcenter::Soa::Client::ModelObjectVector& get_CMProblemItems();
    const Teamcenter::Soa::Client::ModelObjectVector& get_CMReferenceItems();
    const Teamcenter::Soa::Client::ModelObjectVector& get_CMWorkBreakdown();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ChangeRequestRevision")

   virtual ~ChangeRequestRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CmMngd_undef.h>
#endif
