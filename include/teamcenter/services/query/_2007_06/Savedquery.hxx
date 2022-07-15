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

#ifndef TEAMCENTER_SERVICES_QUERY__2007_06_SAVEDQUERY_HXX
#define TEAMCENTER_SERVICES_QUERY__2007_06_SAVEDQUERY_HXX

#include <teamcenter/soa/client/model/ImanQuery.hxx>
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
                class Savedquery;

class TCSOAQUERYSTRONGMNGD_API Savedquery
{
public:

    struct ExecuteSavedQueriesResponse;
    struct RetrieveSearchCriteriaResponse;
    struct SavedQueryInput;
    struct SavedQueryResults;
    struct SaveSearchCriteriaInfo;

    /**
     * Holds the response for executeSavedQueries.
     */
    struct ExecuteSavedQueriesResponse
    {
        /**
         * A set of SavedQueryResults data structures
         */
        std::vector< Teamcenter::Services::Query::_2007_06::Savedquery::SavedQueryResults > arrayOfResults;
        /**
         * serviceData
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Holds a vector of SavedSearchCriteriaInfo and a ServiceData.   To be used as a response
     * for operation "retrieveSearchCriteria"
     */
    struct RetrieveSearchCriteriaResponse
    {
        /**
         * A vector of SavedSearchCriteriaInfo
         */
        std::vector< Teamcenter::Services::Query::_2007_06::Savedquery::SaveSearchCriteriaInfo > output;
        /**
         * Standard ServiceData
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The information about each Saved Query to be processed is provided  by way of the
     * SavedQueryInput data structure.
     */
    struct SavedQueryInput
    {
        /**
         * The saved query object to be executed.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ImanQuery>  query;
        /**
         * Names of search criteria relevant to the query object.
         */
        std::vector< std::string > entries;
        /**
         * Values for the criteria.
         */
        std::vector< std::string > values;
        /**
         * A list of objects (optional) against which the search is conducted, if the list is
         * empty, search will be conducted against the database.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > limitList;
        /**
         * The size of the limitList.
         */
        int limitListCount;
        /**
         * A specified maximum number of matches to be returned, 0 means no limit.
         */
        int maxNumToReturn;
        /**
         * The type of results expected from this operation: 0 (top-level objects only), 1 (top-level
         * objects plus children: Hierarchical/Indented results), 2 (default value as specified
         * on the query object).
         */
        int resultsType;
        /**
         * The number of objects in the returned result that must  include properties: (-1)(all),
         * n (any positive integer less than or equal to the maxNumToReturn).
         */
        int maxNumToInflate;
    };

    /**
     * Results of Saved Query execution, number of objects returned and hierarchy information
     * in a relation map for Hierarchical/Indented execution.  Hierarchical/Indented execution
     * example1: If the query is: Find all Items where the Item Revisions have a Specification
     * Dataset with name = "xyz1", then results will be comprised of subsets, each containing:
     * an Item, a qualifying Item Revision and a qualifying Dataset. For each result subset,
     * the corresponding entries in the relation map would be 0 (for root Item), 1 (for
     * first-level Item Revision), 2 (for second-level Dataset).   Hierarchical/Indented
     * execution example2: If the query is: Find all Item Revisions that have a Specification
     * Dataset with name = "xyz1" AND Form of type Item Revision Master with user_data_1
     * = "xyz2", then the results will comprise of subsets, each containing: an Item Revision,
     * a qualifying Dataset, a qualifying Form and a qualifying Item Revision Master. For
     * each result subset, the corresponding entries in the relation map would be 0 (for
     * root Item Revision), 1 (for first-level Dataset), 1 (for first-level Form) and 2
     * (for second-level Item Revision Master).
     */
    struct SavedQueryResults
    {
        /**
         * The number of objects returned.
         */
        int numOfObjects;
        /**
         * Used only for Hierarchical/Indented execution. An integer array containing the hierarchy
         * level information which maps 1-to-1 to the the returned list of objects which is
         * ordered as subsets. The integer code in the relation map indicates if the corresponding
         * object in the results set is a root object (=0), or a first-level child (=1), or
         * a second-level child (=2) and so on. In the case of child levels, the level information
         * is with respect to the immediately preceding root object entry in the mapping. The
         * order of returns is relevant.
         */
        std::vector< int > objectsRelMap;
        /**
         * The objects returned from the search.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > objects;
    };

    /**
     * Holds the criteria information to be saved or retrieved for a  saved search, a collection
     * of which is known as "My Saved Searches".  A saved search stores the user's entries
     * for a particular saved query  execution so that it can be recalled and rerun in the
     * future.
     */
    struct SaveSearchCriteriaInfo
    {
        /**
         * A unique name for the saved search
         */
        std::string searchName;
        /**
         * The name of the saved query associated with the saved search
         */
        std::string queryName;
        /**
         * Unique keys associated with the "values" below - each key represents a criteria field
         */
        std::vector< std::string > keys;
        /**
         * The values associated with the "keys" above
         */
        std::vector< std::string > values;
        /**
         * The results type associated with the saved search
         */
        std::string resultsType;
        /**
         * The virtual folder the saved search belongs to
         */
        std::string virtualFolderPath;
    };




    /**
     * Executes a set of saved queries of following type:
     * <br>
     * <br>
     * <ul>
     * <li type="disc">QRY_RUN_BY_TC
     * </li>
     * <li type="disc">QRY_RUN_BY_USER_EXIT
     * </li>
     * <li type="disc">QRY_RUN_BY_KEYWORD_SEARCH
     * </li>
     * <li type="disc">QRY_RUN_BY_EINT_EXIT
     * </li>
     * <li type="disc">QRY_RUN_BY_TC_PLUS_PROCESS
     * </li>
     * </ul>
     * <br>
     * 
     * <br>
     * The saved queries can be executed to yield results in 2 modes:
     * <br>
     * <br>
     * <ul>
     * <li type="disc">Flat mode: In this traditional execution mode, only the first-level
     * objects (corresponding to &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;the queried
     * class) satisfying the query  are returned
     * </li>
     * <li type="disc">Hierarchical/Indented mode: This mode is only applicable for saved
     * queries that allow &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Hierarchical/Indented
     * results. In this execution mode, the first-level objects as well as any &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;sub-level
     * objects satisfying the query criteria are returned. The hierarchy level information
     * is &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;also returned so that result subsets
     * can be  re-constructed using the resulting objects.
     * </li>
     * </ul>
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This service will return the matched
     * object UIDs.   After fetching UIDs, client needs to call &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;DataManagementService.loadObjects
     * operation to load objects by pages.  See the &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;QueryInput
     * and QueryResults data structures for usage details.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Execute a set of saved queries of following types: QRY_RUN_BY_TC,  QRY_RUN_BY_KEYWORD_SEARCH
     * and QRY_RUN_BY_TC_PLUS_PROCESS etc.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Search - The capabilities to allow searching objects using the business object symantics
     * that have been persisted via the persistence management.
     *
     * @param input
     *        A set of QueryInput data structures.
     *
     * @return
     *         Contains (1) a set of QueryResults data structures and (2) a ServiceData. Partial
     *         errors are stored and referenced by input vector indexes. Following are some possible
     *         errors returned in
     *         <br>
     *         ServiceData:
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">217013&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Unsupported
     *         query type
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Query::_2007_06::Savedquery::ExecuteSavedQueriesResponse executeSavedQueries ( const std::vector< Teamcenter::Services::Query::_2007_06::Savedquery::SavedQueryInput >& input ) = 0;

    /**
     * Retrieve the corresponding search criteria for the given saved search names.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Search - The capabilities to allow searching objects using the business object symantics
     * that have been persisted via the persistence management.
     *
     * @param searchNames
     *        A set of saved search names for which their  corresponding search criteria are to
     *        be retrieved.
     *
     * @return
     *         RetrieveSearchCriteriaResponse contains (1) a set of SaveSearchCriteriaInfo data
     *         structures and (2) a ServiceData. Partial errors are stored and referenced by search
     *         names.
     *
     * @deprecated
     *         As of Teamcenter 8.1, refer to Release notes on how to retrieve My Saved Searches
     *         information.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 8.1, refer to Release notes on how to retrieve My Saved Searches information."))
#endif
    virtual Teamcenter::Services::Query::_2007_06::Savedquery::RetrieveSearchCriteriaResponse retrieveSearchCriteria ( const std::vector< std::string >& searchNames ) = 0;

    /**
     * Save a set of search criteria.  Each search criteria pertains to   a saved search,
     * a collection of which is known as "My Saved Searches".
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Search - The capabilities to allow searching objects using the business object symantics
     * that have been persisted via the persistence management.
     *
     * @param searchCriteria
     *        A set of SaveSearchCriteriaInfo to be saved.
     *
     * @return
     *         ServiceData     Partial errors are stored and referenced by search names.
     *
     * @deprecated
     *         As of Teamcenter 8.1, use createObjects on a SavedSearch business object.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 8.1, use createObjects on a SavedSearch business object."))
#endif
    virtual Teamcenter::Soa::Client::ServiceData saveSearchCriteria ( const std::vector< Teamcenter::Services::Query::_2007_06::Savedquery::SaveSearchCriteriaInfo >& searchCriteria ) = 0;


protected:
    virtual ~Savedquery() {}
};
            }
        }
    }
}

#include <teamcenter/services/query/Query_undef.h>
#endif

