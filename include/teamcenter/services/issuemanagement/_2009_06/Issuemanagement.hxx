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

#ifndef TEAMCENTER_SERVICES_ISSUEMANAGEMENT__2009_06_ISSUEMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_ISSUEMANAGEMENT__2009_06_ISSUEMANAGEMENT_HXX

#include <teamcenter/soa/client/model/ChangeItem.hxx>
#include <teamcenter/soa/client/model/ChangeItemRevision.hxx>
#include <teamcenter/soa/client/model/ConfigurationContext.hxx>
#include <teamcenter/soa/client/model/Dataset.hxx>
#include <teamcenter/soa/client/model/PSBOMViewRevision.hxx>
#include <teamcenter/soa/client/model/User.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


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
            namespace _2009_06
            {
                class Issuemanagement;

class TCSOAISSUEMANAGEMENTSTRONGMNGD_API Issuemanagement
{
public:

    struct SnapshotViewInfo;
    struct CreateIssueInfo;
    struct CreateIssueItemsResponse;
    struct DatasetInfo;
    struct NamedReferenceAndFile;
    struct DatasetInput;
    struct ExtendedAttribute;
    struct IssueItemsOutput;
    struct RelationshipData;
    struct ReviewIssueInput;
    struct ReviewIssueOutput;
    struct ReviewIssueResp;
    struct UpdateIssueInfo;
    struct UpdateIssueRevsResponse;
    struct UpdateRevisionOutput;

    /**
     * Deprecated.
     */
    enum IssueReviewDecisions{ defer,
                 reject,
                 assign,
                 approveFix,
                 close,
                 reopen,
                 approveIssue,
                 noDecision
                 };

    /**
     * Deprecated.
     */
    enum WfSignoffDecisions{ approveSignoff,
                 rejectSignoff,
                 noDecisionOnSignoff,
                 donotPerformSignoff
                 };

    /**
     * The data to create issue scene 3D snapshot view dataset. This interface was defined
     * before visualization SOA was available and it exposes snapshot view data model to
     * Issue Management service client. It is recommended to create snapshot view dataset
     * by calling visualization service and provide the dataset as object to be attached
     * under issue report revision with <b>IsM0SnapshotBeforeFix</b> or <b>IsM0SnapshotAfterFix</b>
     * relation.
     */
    struct SnapshotViewInfo
    {
        /**
         * Relation name from issue report revision to this snapshot view dataset.
         */
        std::string relationToIssue;
        /**
         * Existing snapshot view dataset to be updated. Should be NULL when creating a new
         * snapshot dataset.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  existingSnapshot;
        /**
         * Snapshot view dataset name. This serves as issue scene name.
         */
        std::string sceneName;
        /**
         * Assembly configuration context object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ConfigurationContext>  configContext;
        /**
         * Top assembly node <b>BVR</b>.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PSBOMViewRevision>  topNodeBVR;
        /**
         * Snapshot files and named reference names to create 3D snapshot view dataset. Client
         * needs to provide thumbnail image, view file (plmxml) and structure file (xml) to
         * create a valid snapshot view dataset.
         */
        std::vector< Teamcenter::Services::Issuemanagement::_2009_06::Issuemanagement::NamedReferenceAndFile > refAndFiles;
    };

    /**
     * Inputs to create a new issue object. The issue title is the issue item name. The
     * issue description is the issue item description.
     */
    struct CreateIssueInfo
    {
        /**
         * Client Id.
         */
        std::string clientId;
        /**
         * Issue report item ID. Can be auto generated.
         */
        std::string id;
        /**
         * Issue report item type. Must be <b>IssueReport</b> or a sub class from <b>IssueReport</b>.
         */
        std::string type;
        /**
         * Issue report item name.
         */
        std::string title;
        /**
         * Issue report revision ID. Can be auto generated.
         */
        std::string revId;
        /**
         * Issue report item description. This is a short description when an issue is captured.
         */
        std::string desc;
        /**
         * Issue report revision attributes. The structure supports multiple values for an attribute.
         */
        std::vector< Teamcenter::Services::Issuemanagement::_2009_06::Issuemanagement::ExtendedAttribute > attributes;
        /**
         * Attachment object, relation from issue report revision to the attachment object,
         * and operation to add or remove the attachment object. Use this structure to update
         * issue report attachments.
         */
        std::vector< Teamcenter::Services::Issuemanagement::_2009_06::Issuemanagement::RelationshipData > relationData;
        /**
         * Issue scene information. This structure contains data to create a product view dataset
         * (snapshot view dataset). This interface was defined before the visualization service
         * was available and it exposes the product view dataset data model to the client code.
         * When possible, it is recommended to leverage the visualization service to create
         * the product view dataet and use the <b>relationData</b> to attach the dataset to
         * the issue report revision.
         */
        Teamcenter::Services::Issuemanagement::_2009_06::Issuemanagement::SnapshotViewInfo reviewSetting;
        /**
         * List of information to create or update datasets.
         */
        std::vector< Teamcenter::Services::Issuemanagement::_2009_06::Issuemanagement::DatasetInput > generalDatasets;
        /**
         * Issue before fix image file name.
         */
        std::string capturedImageFile;
        /**
         * Issue before fix image file upload ticket.
         */
        std::string capturedImageFileTicket;
    };

    /**
     * Create issue response.
     */
    struct CreateIssueItemsResponse
    {
        /**
         * Array of issue report revisions created.
         */
        std::vector< Teamcenter::Services::Issuemanagement::_2009_06::Issuemanagement::IssueItemsOutput > output;
        /**
         * Service data. Teamcenter error stack content will be returned to client when error
         * occurs.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Create dataset info.
     */
    struct DatasetInfo
    {
        /**
         * Dataset tool.
         */
        std::string tool;
        /**
         * Dataset type.
         */
        std::string type;
        /**
         * Dataset name.
         */
        std::string name;
        /**
         * Dataset description.
         */
        std::string description;
    };

    /**
     * File and named reference pair to create a dataset.
     */
    struct NamedReferenceAndFile
    {
        /**
         * File type (text or binary). Optional.
         */
        std::string fileType;
        /**
         * File name.
         */
        std::string fileName;
        /**
         * File upload ticket obtained by calling FMS client utility.
         */
        std::string fileTicket;
        /**
         * Named reference name in dataset.
         */
        std::string refName;
    };

    /**
     * Info to create or update a dataset and relation to attach the dataset to issue report
     * revision.
     */
    struct DatasetInput
    {
        /**
         * Dataset info. Ignored when updating existing dataset.
         */
        Teamcenter::Services::Issuemanagement::_2009_06::Issuemanagement::DatasetInfo dsInfo;
        /**
         * Data file info.
         */
        Teamcenter::Services::Issuemanagement::_2009_06::Issuemanagement::NamedReferenceAndFile fileInfo;
        /**
         * Existing dataset to be updated. NULL to create a new dataset.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  existingDS;
        /**
         * Relation name from issue revision to dataset.
         */
        std::string relationToContainer;
    };

    /**
     * This structure contains issue report revision attribute name versus attribute values
     * pairs to update an issue report revision.
     */
    struct ExtendedAttribute
    {
        /**
         * Issue report revision attribute name.
         */
        std::string name;
        /**
         * Issue report revision attribute values. The structure supports multiple values for
         * an issue report revision attribute. Attribute value is in char string (C++) or String
         * (Java/C#). Teamcenter object can be passed as UID string (obtained from <b>POM_tag_to_string</b>()).
         * Numbers (integer or long or double) can be passed in as string as well. Logical value
         * is passed in as TRUE or FALSE string.
         */
        std::vector< std::string > values;
    };

    /**
     * It contains the newly created issue report item and revision, snapshot dataset or
     * general datasets.
     */
    struct IssueItemsOutput
    {
        /**
         * Client Id.
         */
        std::string clientId;
        /**
         * Issue report item created.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ChangeItem>  changeItem;
        /**
         * Issue report revision created.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ChangeItemRevision>  itemRev;
        /**
         * Snapshot view dataset created.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  viewDataset;
        /**
         * General attachment datasets created.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  > generalDatasets;
    };

    /**
     * It contains the attachments (existing Teamcenter objects), relation that the attachments
     * are to be attached to (or de attached from) issue report revision. This is the way
     * that client updates issue context data.
     */
    struct RelationshipData
    {
        /**
         * Attachment objects. Can be any Teamcenter Workspace Objects.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > tags;
        /**
         * Relation name (from issue revision to attachment).
         */
        std::string relationName;
        /**
         * Add or REMOVE.
         */
        std::string operation;
    };

    /**
     * Deprecated.
     */
    struct ReviewIssueInput
    {
        /**
         * Client Id.
         */
        std::string clientId;
        /**
         * The target issue object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  theIssue;
        /**
         * Review issue decision.
         */
        IssueReviewDecisions reviewIssueDecision;
        /**
         * Workflow perform signoff decision.
         */
        WfSignoffDecisions performSignoffDecision;
        /**
         * The Teamcenter user who is responsible to fix the issue.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::User>  assignedUser;
        /**
         * Comments.
         */
        std::string comment;
    };

    /**
     * Deprecated.
     */
    struct ReviewIssueOutput
    {
        /**
         * Client Id.
         */
        std::string clientId;
        /**
         * Updated issue object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ChangeItemRevision>  theIssue;
    };

    /**
     * Deprecated.
     */
    struct ReviewIssueResp
    {
        /**
         * List of review issue outputs.
         */
        std::vector< Teamcenter::Services::Issuemanagement::_2009_06::Issuemanagement::ReviewIssueOutput > resp;
        /**
         * SOA service data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Data and files to update an issue.
     */
    struct UpdateIssueInfo
    {
        /**
         * Client Id.
         */
        std::string clientId;
        /**
         * Existing issue report revision to be updated.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ChangeItemRevision>  existingIssueRev;
        /**
         * Attributes and values.
         */
        std::vector< Teamcenter::Services::Issuemanagement::_2009_06::Issuemanagement::ExtendedAttribute > attributes;
        /**
         * Attachments to be updated.
         */
        std::vector< Teamcenter::Services::Issuemanagement::_2009_06::Issuemanagement::RelationshipData > relationData;
        /**
         * Issue scene snapshot.
         */
        Teamcenter::Services::Issuemanagement::_2009_06::Issuemanagement::SnapshotViewInfo reviewSetting;
        /**
         * General dataset attachments.
         */
        std::vector< Teamcenter::Services::Issuemanagement::_2009_06::Issuemanagement::DatasetInput > generalDatasets;
        /**
         * Image file name when issue is fixed.
         */
        std::string fixedImageFile;
        /**
         * Image file ticket when issue is fixed.
         */
        std::string fixedImageFileTicket;
    };

    /**
     * Update issue report revision response.
     */
    struct UpdateIssueRevsResponse
    {
        /**
         * Array of update issue report revisions.
         */
        std::vector< Teamcenter::Services::Issuemanagement::_2009_06::Issuemanagement::UpdateRevisionOutput > output;
        /**
         * Service data. Teamcenter error stack content will be returned when error occurs.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Update issue report revision output.
     */
    struct UpdateRevisionOutput
    {
        /**
         * Client Id.
         */
        std::string clientId;
        /**
         * Issue report revision updated.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ChangeItemRevision>  itemRev;
        /**
         * Snapshot view dataset updated.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  viewDataset;
        /**
         * General datasets updated.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  > generalDatasets;
    };




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


protected:
    virtual ~Issuemanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/issuemanagement/IssueManagement_undef.h>
#endif

