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

#ifndef TEAMCENTER_SERVICES_QUERY__2007_06_FINDER_HXX
#define TEAMCENTER_SERVICES_QUERY__2007_06_FINDER_HXX

#include <teamcenter/soa/client/model/WorkspaceObject.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/query/Query_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Query
        {
            namespace _2007_06
            {
                class Finder;

class TCSOAQUERYSTRONGMNGD_API Finder
{
public:

    struct FindWorkspaceObjectsOutput;
    struct FindWorkspaceObjectsResponse;
    struct WSOFindCriteria;
    struct WSOFindSet;

    /**
     * Scope of search:  WSO_scope_All = entire database,  WSO_scope_Approved = searches
     * for objects that have at least one approval status.oval status.
     */
    enum WSOscopeType{ WSO_scope_All,
                 WSO_scope_Approved
                 };

    /**
     * FindWorkspaceObjectsOutput
     */
    struct FindWorkspaceObjectsOutput
    {
        /**
         * The index of FindSet that generated the output.
         */
        int findSetIndex;
        /**
         * The WorkspaceObject business objects matching the search criteria.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  > foundObjects;
    };

    /**
     * FindWorkspaceObjectsResponse
     */
    struct FindWorkspaceObjectsResponse
    {
        /**
         * A list of found workspace objects.
         */
        std::vector< Teamcenter::Services::Query::_2007_06::Finder::FindWorkspaceObjectsOutput > outputList;
        /**
         * The service data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * WSOFindCriteria
     */
    struct WSOFindCriteria
    {
        /**
         * If set, must be set to the corresponding class name . If not set, this criteria will
         * be ignored by the search.
         */
        std::string objectType;
        /**
         * Name of object  Can contain wild card characters.  The percent sign and underscore
         * are the only valid wild card characters,  where:  % Represents any set of characters
         * in the substring.  _ (Underscore) Represents any single character in the substring.
         */
        std::string objectName;
        /**
         * The owning <b>User</b> to limit found objects for. A null value will expand the search
         * to all users.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  owner;
        /**
         * The owning <b>Group</b> to limit found objects for. A null value will expand the
         * search to all groups.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  group;
        /**
         * The maximum creation date to limit found objects. A null value will not limit the
         * results.
         */
        Teamcenter::Soa::Common::DateTime createdBefore;
        /**
         * The maximum last modified date to limit found objects. A null value will not limit
         * the results.
         */
        Teamcenter::Soa::Common::DateTime modifiedBefore;
        /**
         * The maximum released date to limit found objects. A null value will not limit the
         * results.
         */
        Teamcenter::Soa::Common::DateTime releasedBefore;
        /**
         * The minimum creation date to limit found objects. A null value will not limit the
         * results.
         */
        Teamcenter::Soa::Common::DateTime createdAfter;
        /**
         * The minimum last modified date to limit found objects. A null value will not limit
         * the results.
         */
        Teamcenter::Soa::Common::DateTime modifiedAfter;
        /**
         * The minimum released date to limit found objects. A null value will not limit the
         * results.
         */
        Teamcenter::Soa::Common::DateTime releasedAfter;
        /**
         * Scope of search,  WSO_scope_All = entire database,  WSO_search_Approved = searches
         * for objects that have at least  one status of approval.
         */
        WSOscopeType scope;
    };

    /**
     * WSOFindSet
     */
    struct WSOFindSet
    {
        /**
         * A list of FindCriteria to search with.
         */
        std::vector< Teamcenter::Services::Query::_2007_06::Finder::WSOFindCriteria > criterias;
    };




    /**
     * Query the database for <b>WorkspaceObjects</b>. A collection of WSOFindSets are used
     * to do the queries. For each WSOFindSet , a FindWorkspaceObjectsOutput will be generated
     * if any <b>WorkspaceObjects</b> are found that meet all the criteria.  Each FindWorkspaceObjectsOutput
     * will contain the tags of the <b>WorkspaceObjects</b> that meet all the criteria and
     * the index of the WSOFindSet in the findList that generated the output.  If an error
     * is encountered, then no FindWorkspaceObjectsOutput will be generated for that WSOFindSet
     * (no partial data returned) and the index for the WSOFindSet in the findList will
     * be the client ID in the partial error.  If no WSOFindSet generates any output, a
     * null outputList is returned.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Find workspace object using basic attributes such as object type, object name, owner,
     * group, created before, created after etc.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Business Intelligence - Capability to create and manage report definitions and generate
     * reports
     *
     * @param findList
     *        A list of WSOFindSet used to find workspace objects.
     *
     * @return
     *         Contains a list of FindWorkspaceObjectsOutput structures (which contain the found
     *         workspace objects). Any found workspace objects will be sent back in the standard
     *         ServiceData list of plain objects. Any failure will be returned as partial errors
     *         in ServiceData with index for the WSOFindSet in the findList.
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Query::_2007_06::Finder::FindWorkspaceObjectsResponse findWorkspaceObjects ( const std::vector< Teamcenter::Services::Query::_2007_06::Finder::WSOFindSet >& findList ) = 0;


protected:
    virtual ~Finder() {}
};
            }
        }
    }
}

#include <teamcenter/services/query/Query_undef.h>
#endif

