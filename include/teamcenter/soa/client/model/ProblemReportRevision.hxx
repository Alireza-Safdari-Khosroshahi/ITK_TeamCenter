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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PROBLEMREPORTREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PROBLEMREPORTREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/GnProblemReportRevision.hxx>

#include <teamcenter/soa/client/model/CmMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACMMODELMNGD_API ProblemReportRevision : public Teamcenter::Soa::Client::Model::GnProblemReportRevision
{
public:
    const std::string& get_CMTechReviewPriority();
    const std::string& get_CMSeverityRating();
    const std::string& get_CMEnvironmentDescription();
    const std::string& get_CMVerification();
    const std::string& get_CMRamification();
    const std::string& get_CMSequenceOfEvents();
    const Teamcenter::Soa::Client::ModelObjectVector& get_CMProblemItems();
    const Teamcenter::Soa::Client::ModelObjectVector& get_CMReferenceItems();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ProblemReportRevision")

   virtual ~ProblemReportRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CmMngd_undef.h>
#endif
