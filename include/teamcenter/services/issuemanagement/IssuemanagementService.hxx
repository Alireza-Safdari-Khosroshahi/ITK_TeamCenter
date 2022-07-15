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

#ifndef TEAMCENTER_SERVICES_ISSUEMANAGEMENT_ISSUEMANAGEMENTSERVICE_HXX
#define TEAMCENTER_SERVICES_ISSUEMANAGEMENT_ISSUEMANAGEMENTSERVICE_HXX

#include <teamcenter/services/issuemanagement/_2009_06/Issuemanagement.hxx>
#include <teamcenter/services/issuemanagement/_2010_04/Issuemanagement.hxx>
#include <teamcenter/services/issuemanagement/_2011_06/Issuemanagement.hxx>
#include <teamcenter/services/issuemanagement/_2013_05/Issuemanagement.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/issuemanagement/IssueManagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Issuemanagement
        {
            class IssuemanagementService;

/**
 * This service exposes the functionalities of Teamcenter Issue Management to service
 * clients. Teamcenter Issue Management is an application that extends Teamcenter Change
 * Management. Before calling this service, user should make a decision on whether the
 * business use case should be based on Issue Management or Change Management.
 * <br>
 * A problem is a condition often identified as a result of multiple incidents that
 * exhibit common symptom. Problems can also be identified from a single significant
 * incident, indicative of a single error, for which the cause is unknown, but for which
 * the impact is significant. When a problem is captured and well documented in Teamcenter
 * Issue Management, it becomes an issue report and contains a wide array of data entities
 * that require attention or resolution. Typically these data entities are classified
 * as issue meta data that manages issue report lifecycle and issue context data that
 * describes and reloads issue report.
 * <br>
 * A Teamcenter change is an event that results in a new status of one or more configuration
 * nodes in product structure or functionality or features. A change may or may not
 * be originated from an issue report. A change may be initiated because a new variation
 * of product is requested by market. An issue report does not trigger change request
 * (therefore not initiated change management process) when resolving the issue report
 * does not involve creation of new configuration nodes or change of existing configuration.
 * <br>
 * While Teamcenter Issue Management aims to handle issue reports in an efficient way
 * to identify / capture / record issue scene, to classify issue category / risk level
 * / priority, to investigate issue root cause and develop issue resolution; change
 * management handles change in standardized methods and procedures to minimize the
 * impact of change related incidents upon process quality, and consequently improve
 * product quality.
 * <br>
 * Teamcenter Issue Management can also manage Design Review process. A Design Review
 * task is an issue report in Teamcenter Issue Management. Design Review leverages multiple
 * applications such as NX, standalone Vis as well as Teamcenter RAC embedded viewer.
 * Design Review process generates and consumes a wide array of data files including,
 * but not limited to, documents, 2D images, 3D structures as well as 2D/3D markups,
 * assembly configurations. Design Review workflow and dataflow can be standardized
 * and managed in Teamcenter Issue Management by leveraging Teamcenter workflow process.
 * <br>
 * The OOTB <b>issue lifecycle</b> workflow template can be tailored to fit a specific
 * issue management business process model. There are a few steps to follow when it
 * comes to customize Teamcenter Issue Management workflow template:
 * <br>
 * <ul>
 * <li type="disc">How many review tasks are needed in business process.  Review board
 * members must be identified for each review task.
 * </li>
 * <li type="disc">Assign reviewers as issue report participants for easy management.
 * With properly configured workflow template, participants can be auto assigned as
 * reviewers for each review task when workflow process starts.
 * </li>
 * <li type="disc">Where multiple reviewers (review board) are involved, the issue report
 * status change must be determined by review board decision.
 * </li>
 * <li type="disc">Workflow template has to be configured to allow multiple branch paths
 * following a task based on issue report review result or latest statuses.
 * </li>
 * </ul>
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoaissuemanagementstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoaissuemanagementtypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOAISSUEMANAGEMENTSTRONGMNGD_API IssuemanagementService
    : public Teamcenter::Services::Issuemanagement::_2009_06::Issuemanagement,
             public Teamcenter::Services::Issuemanagement::_2010_04::Issuemanagement,
             public Teamcenter::Services::Issuemanagement::_2011_06::Issuemanagement,
             public Teamcenter::Services::Issuemanagement::_2013_05::Issuemanagement
{
public:
    static IssuemanagementService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * A client calls this operation to create issue reports. An issue report contains two
     * categories of data to describe a problem: issue metadata which can be issue report
     * ID, title, description, severity level, disposition and so on; issue context data
     * which can be problem parts, issue scene setting (product view), view stat data, check
     * / analysis logs, images, screenshots and documentation. Issue report metadata is
     * managed as issue report item and revision attributes (mostly issue report revision
     * attributes) while issue report context data is managed as attachments to issue report
     * revisions under different pseudo-folders (relations). Customers can customize issue
     * report data model to manage issue metadata and context data to better fit different
     * issue management business process models. In the OOTB configuration, problem parts
     * are attached under the <b>CMHasProblemItem</b> relation, and issue images are attached
     * under the <b>ImageBeforeFix</b> or <b>ImageAfterFix</b> relation. Product view datasets
     * (snapshots) are attached under the <b>IsM0SnapshotBeforeFix</b> or <b>IsM0SnapshotAfterFix</b>
     * relation. General datasets can be attached under the <b>CMReferences</b> relation.
     * <br>
     * Issue report type, title, and description are required inputs to create new issue
     * report. When the issue report ID is not provided, the system generates a unique ID
     * according to the naming convention. When an issue report ID is provided and there
     * is an existing issue report with the same ID from Teamcenter, a new revision will
     * be created and populated with the provided issue metadata and issue context data.
     * This operation does not copy or reference any attributes or attached objects from
     * the existing issue report revision to the newly created issue report revision.
     * <br>
     * The client must call the Teamcenter FMS utility to upload the file and provide the
     * upload ticket along with the file name, dataset type, and named reference name to
     * create a new dataset or update an existing dataset. It is recommended that the client
     * application calls Visualization service to create and save a product view (snapshot
     * view) dataset and provide the product view dataset under the <b>relationData</b>
     * when creating or updating the issue report.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * The NX Check-Mate application integrates with Teamcenter Issue Management to log
     * an issue report when the part fails a Check-Mate check. The client provides an issue
     * title (that is related to the Check-Mate checker name), a description (that is related
     * to the Check-Mate checker description), a log file as a general dataset to be attached
     * under the <b>CMReferences</b> relation, and a part that is to be attached under the
     * <b>CMHasProblemItem</b> relation. The client can also capture the current assembly
     * / part scene as a product view dataset and attachs the dataset under the <b>IsM0SnapshotBeforeFix</b>
     * relation. In this use case, a log file is provided as <b>generalDatasets</b>, and
     * an issue scene dataset is provided as a <b>relationData</b> object.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Issue Management - Issue Management SOA service.
     *
     * @param inputs
     *        Inputs to create issues.
     *
     * @return
     *         Array of created issue report revisions.
     *
     */
    virtual Teamcenter::Services::Issuemanagement::_2009_06::Issuemanagement::CreateIssueItemsResponse createIssueItems ( const std::vector< Teamcenter::Services::Issuemanagement::_2009_06::Issuemanagement::CreateIssueInfo >& inputs ) = 0;

    /**
     * This operation/function provides a mechanism for issue review board members to cast
     * a vote on issue review and optionally perform workflow signoff task. The timing to
     * call this SOA is when issue management workflow process perform signoff task is started.
     * Each board member can cast one vote whether to defer or reject or approve an issue
     * (so the issue must be assigned and fixed) or approve issue fix or re-open issue or
     * close issue. Issue review board members are selected perform signoff users from issue
     * management workflow process review task. Only the votes from review board members
     * are counted by workflow action handler EPM-update-issue-status. Votes from non-members
     * are not counted. Final decision is rendered by simple majority of votes or a percentage
     * of votes as configured in issue management workflow template. Issue status is changed
     * based on final decision when review task completes. Calling this SOA function alone
     * will not change issue status directly (except that a reviewer can assign an issue
     * to a user). A reviewer can not change vote after his or her perform signoff task
     * is completed.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Issue Management - Issue Management SOA service.
     *
     * @param inputs
     *        Review issue inputs.
     *
     * @return
     *         Review issue response that contains a list of updated issue objects.
     *
     * @deprecated
     *         As of Teamcenter 9, this operation is deprecated in TC 9.0. Replaced by new operation
     *         castReviewDecisionOnIssues.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 9, this operation is deprecated in TC 9.0. Replaced by new operation castReviewDecisionOnIssues."))
#endif
    virtual Teamcenter::Services::Issuemanagement::_2009_06::Issuemanagement::ReviewIssueResp reviewIssues ( const std::vector< Teamcenter::Services::Issuemanagement::_2009_06::Issuemanagement::ReviewIssueInput >& inputs ) = 0;

    /**
     * Client calls this operation to update existing issue reports. An issue report may
     * be populated or updated by multiple applications during its life cycle. For example,
     * issue report metadata may be updated due to issue status changes, reviews and comments,
     * and so on. Issue report context data may be updated with new product view datasets,
     * documents, or markups. Out-of-date documents may be updated with new files. Irrelevant
     * attachments may be detached. The way to pack up data to update an issue report is
     * the same as to create an issue report.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * The NX application may call this operation to update the issue report with a new
     * Check-Mate log file, and issue scene dataset. The client provides the existing log
     * file dataset, the new log file (and its upload ticket) as generalDatasets data, the
     * new issue scene dataset as a relationData object to update the issue report for a
     * particular Check-Mate check failure.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Issue Management - Issue Management SOA service.
     *
     * @param inputs
     *        Inputs to update issues.
     *
     * @return
     *         Array of updated issue revisions.
     *
     */
    virtual Teamcenter::Services::Issuemanagement::_2009_06::Issuemanagement::UpdateIssueRevsResponse updateIssueItems ( const std::vector< Teamcenter::Services::Issuemanagement::_2009_06::Issuemanagement::UpdateIssueInfo >& inputs ) = 0;

    /**
     * The client calls this operation to create/update/delete issue list configuration.
     * <br>
     * The way to browse issue reports is to execute a query with properly defined query
     * conditions. With Teamcenter Issue Management, the query and conditions can be saved
     * as an issue list for re-use. An issue list is not a sub class of Teamcenter <b>Folder</b>.
     * The configuration data for an issue list is saved as a Teamcenter preference.
     * <br>
     * There are two levels of issue lists: a system level issue list that is created by
     * a Teamcenter administrative user and accessible to all users, or a user level issue
     * list that is created by a user and accessible to the owning user only. By default,
     * system level issue lists are saved in preference <b>ISSUE_issuelists_site</b> with
     * site protection scope. User level issue lists are saved in preference <b>ISSUE_issuelists_user</b>
     * with user protection scope. The services client can specify a different preference
     * name for system level or user level issue lists. An issue list can be set as visible
     * or invisible by its owning user. Visible issue lists are accessible. Invisible issue
     * lists can't be expanded (not accessible).
     * <br>
     * The Issue Management service client application should not assume that an issue report
     * can be created under a selected issue list. An issue list doesn't reference (or contain)
     * any issue reports till the query is executed. The client must refresh the issue list
     * (re-execute the query) whenever necessary.
     * <br>
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * The user can create an issue list to list all issues reported for a <b>Detail Review</b>
     * gate. The user can use saved query <b>__find_issue_objects</b>, set query condition
     * design review gate to <b>Detail Review</b>. Save the issue list as user level which
     * is accessible for owning user only.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Issue Management - Issue Management SOA service.
     *
     * @param inputs
     *        Inputs to configure issue lists.
     *
     * @return
     *         Array of issue list configurations.
     *
     */
    virtual Teamcenter::Services::Issuemanagement::_2010_04::Issuemanagement::ConfigIssueListsResp configureIssueLists ( const std::vector< Teamcenter::Services::Issuemanagement::_2010_04::Issuemanagement::IssueListConfigData >& inputs ) = 0;

    /**
     * The client calls this operation to get configuration data for all accessible issue
     * lists for the current user or to expand one issue list.
     * <br>
     * The client needs to get all accessible issue lists configuration data to construct
     * the issue list management UI for the current user. Accessible issue lists include
     * system level lists plus user level lists that are defined by current user. Invisible
     * issue lists are not returned because these issue lists are not accessible.
     * <br>
     * This operation can also be called to expand one issue list. Expanding an issue list
     * means to execute the query with the conditions configured for the issue list and
     * return issue report revision objects to the client. In cases where this may cause
     * performance degradation, and the client application is capable of lazy-loading issue
     * report revision objects, the client is recommended to leverage the Teamcenter query
     * service to get issue report revision object UIDs for an issue list.
     * <br>
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * NX Issue Tracking constructs a user interface showing accessible issue lists for
     * the current user. When the user clicks to expand a selected issue list, the client
     * code calls this operation with the selected issue list name and expandList = TRUE.
     * Issue report revision objects are returned to the NX application.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Issue Management - Issue Management SOA service.
     *
     * @param inputs
     *        Inputs to get or expand issue lists.
     *
     * @return
     *         Array of issue list configuration and issue objects.
     *
     */
    virtual Teamcenter::Services::Issuemanagement::_2010_04::Issuemanagement::GetIssueListsResp getExpandIssueLists ( const std::vector< Teamcenter::Services::Issuemanagement::_2010_04::Issuemanagement::GetIssueListInput >& inputs ) = 0;

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

    /**
     * This operation builds a BOM window based on the product view dataset, traverses the
     * BOM window and outputs a BomWriterExport flavored PLMXML file that lists visible
     * BOM lines and contains view stat data. The applications (for example, NX Bookmark
     * function) that support PLMXML in BomWriterExport format can download the generated
     * PLMXML and other files from the product view dataset to launch issue scene.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * NX Issue Tracking provides the functionalities to browse, capture and launch issue
     * reports from NX environment in managed mode. NX calls this function with a product
     * view dataset which is the snapshot for the issue. A generated BomWriterExport flavored
     * PLMXML and other files can be downloaded and launch into NX to re-build issue scene.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Issue Management - Issue Management SOA service.
     *
     * @param inputs
     *        Inputs to get issue scene files.
     *
     * @return
     *         This operation returns the named reference names and FMS tickets for downloading
     *         the requested files. The following partial error may be returned: 261001 - Retrieve
     *         configuration context failed or the named reference does not exist 261002 - Rebuild
     *         BOM window from configuration context failed. 261003 - Retrieve view stat data from
     *         pv-view xml file failed. 261004 - Retrieve pv-view xml file failed or the file does
     *         not exist. 261005 - Retrieve pv-structure xml file failed or the file does not exist.
     *         261006 - Generate BomWriterExport flavored PLMXML file failed. 261007 - Download
     *         file failed.
     *
     */
    virtual Teamcenter::Services::Issuemanagement::_2013_05::Issuemanagement::GetIssueSceneFileResp getIssueSceneFiles ( const std::vector< Teamcenter::Services::Issuemanagement::_2013_05::Issuemanagement::GetIssueSceneFileInput >& inputs ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("IssuemanagementService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/issuemanagement/IssueManagement_undef.h>
#endif

