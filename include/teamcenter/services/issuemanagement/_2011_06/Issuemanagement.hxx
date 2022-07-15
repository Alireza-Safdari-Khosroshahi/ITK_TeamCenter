/* 
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
 ==================================================
 Copyright 2012
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

 ==================================================

   Auto-generated source from service interface.
                 DO NOT EDIT

 ==================================================
*/

#ifndef TEAMCENTER_SERVICES_ISSUEMANAGEMENT__2011_06_ISSUEMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_ISSUEMANAGEMENT__2011_06_ISSUEMANAGEMENT_HXX

#include <teamcenter/soa/client/model/ChangeItemRevision.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/issuemanagement/IssueManagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Issuemanagement
        {
            namespace _2011_06
            {
                class Issuemanagement;

class TCSOAISSUEMANAGEMENTSTRONGMNGD_API Issuemanagement
{
public:

    struct CastDecisionInput;
    struct CastReviewDecisionOutput;
    struct CastReviewDecisionResp;

    /**
     * Issue review input such as review decision and comment.
     */
    struct CastDecisionInput
    {
        /**
         * Client Id.
         */
        std::string clientId;
        /**
         * The issue report revision object to be reviewed.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ChangeItemRevision>  targetIssue;
        /**
         * Review decision name. Get supported review decision names from the LOV <b>IsM0Issue
         * Review Decisions</b> and use the internal value (not localized value) as input.
         */
        std::string theDecision;
        /**
         * A short comment.
         */
        std::string theComment;
    };

    /**
     * The output from casting a review decision and comment on an issue report revision
     * object.
     */
    struct CastReviewDecisionOutput
    {
        /**
         * Client Id.
         */
        std::string clientId;
        /**
         * The issue report revision object just reviewed.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ChangeItemRevision>  theIssueObject;
    };

    /**
     * Response from casting review decision on the issue.
     */
    struct CastReviewDecisionResp
    {
        /**
         * Output from casting review decision on the issue.
         */
        std::vector< Teamcenter::Services::Issuemanagement::_2011_06::Issuemanagement::CastReviewDecisionOutput > resp;
        /**
         * Service data. Teamcenter error stack content will be returned to client when error
         * occurs.
         */
        Teamcenter::Soa::Client::ServiceData theServiceData;
    };




    /**
     * The client calls this operation to log an issue review decision and comment to the
     * target issue report, and to complete the issue management workflow process perform-signoff
     * task.
     * <br>
     * You may have multiple business processes to manage the issue life cycle (or design
     * review process). Issue management business process can be defined as a workflow template
     * that is configured with multiple tasks to model business tasks and handlers to update
     * issue report statuses at the completion of a task. Teamcenter users that participate
     * in issue life cycle management are issue report revision participants and can be
     * auto-assigned as workflow task assignees when the issue management workflow process
     * starts. Another option is to assign reviewers from the Teamcenter create new workflow
     * process dialog. Workflow review tasks are commonly used to dispatch an issue management
     * business task to selected users. Signing off on a workflow review task means that
     * the assigned user has successfully accomplished business task and wants to complete
     * the workflow review task. A business task may update issue report metadata or context
     * data which is completed with various tools outside of the workflow process. This
     * operation allows an assigned user to log the review decision and to comment on an
     * issue and complete the workflow review task.
     * <br>
     * When one review task is assigned to multiple users, the review task is called a board-review
     * task and each assigned user is a member of the review board. A review decision from
     * the review board is the decision from majority of board members. Each board member
     * calls this operation to cast a review decision and comment. When all board members
     * have signed off their respective review tasks, the workflow action handler <b>ISSUEMGT-update-issue-status</b>
     * updates issue the report status based on the review board decision. The way to configure
     * this handler is described in Issue Management User's Guide.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Please refer to the OOTB issue lifecycle workflow template. Users who are assignees
     * to the <b>Review Issue</b> and <b>Final Review</b> tasks will call this operation
     * to log the review decision and to comment on the target issue report. The rich client
     * or the thin client <b>Review Issue</b> dialog calls this operation.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Issue Management - Issue Management SOA service.
     *
     * @param inputs
     *        Inputs to cast review decisions and comments on issues.
     *
     * @return
     *         Cast review decision response.
     *
     */
    virtual Teamcenter::Services::Issuemanagement::_2011_06::Issuemanagement::CastReviewDecisionResp castReviewDecisionOnIssues ( const std::vector< Teamcenter::Services::Issuemanagement::_2011_06::Issuemanagement::CastDecisionInput >& inputs ) = 0;


protected:
    virtual ~Issuemanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/issuemanagement/IssueManagement_undef.h>
#endif

