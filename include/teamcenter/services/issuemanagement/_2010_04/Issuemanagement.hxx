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

#ifndef TEAMCENTER_SERVICES_ISSUEMANAGEMENT__2010_04_ISSUEMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_ISSUEMANAGEMENT__2010_04_ISSUEMANAGEMENT_HXX

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
            namespace _2010_04
            {
                class Issuemanagement;

class TCSOAISSUEMANAGEMENTSTRONGMNGD_API Issuemanagement
{
public:

    struct ConfigIssueListsResp;
    struct GetIssueListInput;
    struct IssueListConfigData;
    struct GetIssueListOutput;
    struct GetIssueListsResp;

    /**
     * Configure issue lists response.
     */
    struct ConfigIssueListsResp
    {
        /**
         * Service data. Teamcenter error stack content will be returned when error occurs.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * Issue List configuration data.
         */
        std::vector< Teamcenter::Services::Issuemanagement::_2010_04::Issuemanagement::IssueListConfigData > configData;
    };

    /**
     * Input to get configuration for accessible issue list or expand one issue list for
     * current user.
     */
    struct GetIssueListInput
    {
        /**
         * Client Id.
         */
        std::string clientId;
        /**
         * Issue list name. When name is NULL, this operation returns configuration data for
         * all accessible issue lists for the current user. The issue list name must be provided
         * when expanding an issue list.
         */
        std::string name;
        /**
         * Teamcenter preference name to save site level issue list configuration.
         */
        std::string siteLevel;
        /**
         * Teamcenter preference name to save user level issue list configuration.
         */
        std::string userLevel;
        /**
         * TRUE: expand issue list; FALSE: do not expand issue list.
         */
        bool expandList;
    };

    /**
     * Saved query and conditions and other data to create an issue list.
     */
    struct IssueListConfigData
    {
        /**
         * Issue list name.
         */
        std::string name;
        /**
         * TRUE: issue list is visible; FALSE: issue list is invisible.
         */
        bool visible;
        /**
         * Saved query name. Pre defined in Teamcenter.
         */
        std::string queryName;
        /**
         * Saved search name. When a saved search is provided, the saved query name and conditions
         * will be extracted automatically to create an issue list. When this input is provided,
         * the next three inputs (queryName, queryCriteria and queryValues are ignored).
         */
        std::string savedSearchName;
        /**
         * List of attribute names.
         */
        std::vector< std::string > queryCriteria;
        /**
         * List of attribute values.
         */
        std::vector< std::string > queryValues;
        /**
         * TRUE: issue list is site level (use this value only for system admin user); FALSE:
         * issue list is user level.
         */
        bool isFolderSiteLevel;
        /**
         * Teamcenter preference name to save issue list configuration data. When not provided,
         * the value set in the <b>ISSUE_issuelists_site</b> preference (for system level issue
         * lists) and the value set in the <b>ISSUE_issuelists_user</b> preference (for user
         * level issue lists) are assumed. The client can choose different names and use the
         * names consistently.
         */
        std::string prefName;
        /**
         * TRUE: create or update issue list; FALSE: delete issue list. When deleting an issue
         * list, only the issue list name is needed.
         */
        bool operation;
    };

    /**
     * It may contain configuration data for all accessible issue lists for current user
     * or issue report revision objects returned from expanding one issue list.
     */
    struct GetIssueListOutput
    {
        /**
         * Client Id.
         */
        std::string clientId;
        /**
         * Issue list configuration.
         */
        Teamcenter::Services::Issuemanagement::_2010_04::Issuemanagement::IssueListConfigData configData;
        /**
         * Issue report revision objects for given issue list.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ChangeItemRevision>  > results;
    };

    /**
     * Get issue list response.
     */
    struct GetIssueListsResp
    {
        /**
         * Service data. Teamcenter error stack content will be returned when error occurs.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * Output structures.
         */
        std::vector< Teamcenter::Services::Issuemanagement::_2010_04::Issuemanagement::GetIssueListOutput > outputStru;
    };




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


protected:
    virtual ~Issuemanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/issuemanagement/IssueManagement_undef.h>
#endif

