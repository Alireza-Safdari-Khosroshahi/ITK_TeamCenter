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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ISSUEREPORTREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ISSUEREPORTREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ProblemReportRevision.hxx>

#include <teamcenter/soa/client/model/IssuemgmtMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class User;
                class IssueReviewRecord;
                class Tool;


class TCSOAISSUEMGMTMODELMNGD_API IssueReportRevision : public Teamcenter::Soa::Client::Model::ProblemReportRevision
{
public:
    const std::string& get_design_review_gate();
    const std::string& get_issue_category();
    Teamcenter::Soa::Common::AutoPtr<User> get_assigned_user();
    const Teamcenter::Soa::Common::DateTime& get_due_date();
    size_t count_issue_review_records();
    Teamcenter::Soa::Common::AutoPtr<IssueReviewRecord> get_issue_review_records_at( size_t inx );
    const std::string& get_ism0RacApplicationId();
    const std::string& get_ism0RacPerspectiveId();
    Teamcenter::Soa::Common::AutoPtr<Tool> get_ism0NonembeddedApp();
    int get_ism0ClearanceId();
    const std::string& get_ism0ClearanceDbId();
    double get_ism0marker_X();
    double get_ism0marker_Y();
    double get_ism0marker_Z();
    const std::string& get_ism0status();
    const Teamcenter::Soa::Client::ModelObjectVector& get_ImageAfterFix();
    const Teamcenter::Soa::Client::ModelObjectVector& get_ImageBeforeFix();
    const Teamcenter::Soa::Client::ModelObjectVector& get_ism0CMImpactedItems();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IsM0SnapshotBeforeFix();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IsM0SnapshotAfterFix();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IsM0IssueSubset();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IsM0ValidationResults();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("IssueReportRevision")

   virtual ~IssueReportRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/IssuemgmtMngd_undef.h>
#endif
