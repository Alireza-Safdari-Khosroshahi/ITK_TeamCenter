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

#ifndef TEAMCENTER_SERVICES_QUERY_SAVEDQUERYSERVICE_HXX
#define TEAMCENTER_SERVICES_QUERY_SAVEDQUERYSERVICE_HXX

#include <teamcenter/services/query/_2006_03/Savedquery.hxx>
#include <teamcenter/services/query/_2007_01/Savedquery.hxx>
#include <teamcenter/services/query/_2007_06/Savedquery.hxx>
#include <teamcenter/services/query/_2007_09/Savedquery.hxx>
#include <teamcenter/services/query/_2008_06/Savedquery.hxx>
#include <teamcenter/services/query/_2010_04/Savedquery.hxx>
#include <teamcenter/services/query/_2010_09/Savedquery.hxx>
#include <teamcenter/services/query/_2013_05/Savedquery.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/query/Query_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Query
        {
            class SavedqueryService;

/**
 * The SavedQuery service provides operations to operate saved queries such as create
 * a set of saved queries, find saved query, execute a set of saved queries and execute
 * a Business Object Search (Simple Search).
 * <br>
 * 
 * <br>
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoaquerystrongmngd.dll
 * </li>
 * <li type="disc">libtcsoaquerytypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOAQUERYSTRONGMNGD_API SavedqueryService
    : public Teamcenter::Services::Query::_2006_03::Savedquery,
             public Teamcenter::Services::Query::_2007_01::Savedquery,
             public Teamcenter::Services::Query::_2007_06::Savedquery,
             public Teamcenter::Services::Query::_2007_09::Savedquery,
             public Teamcenter::Services::Query::_2008_06::Savedquery,
             public Teamcenter::Services::Query::_2010_04::Savedquery,
             public Teamcenter::Services::Query::_2010_09::Savedquery,
             public Teamcenter::Services::Query::_2013_05::Savedquery
{
public:
    static SavedqueryService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * Returns the description of each of the input saved queries.The description for each
     * query includes all the clause information (the attribute name, entry name, operation
     * for each clause, the math operation for each clause, the ListOfValues for related
     * clause if it has, and the attribute type).
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User can get the description for queries by this service and then can show the details
     * in search view so that user can execute the query.
     * <br>
     * <br>
     * User can get the description for queries by this service and then show the details
     * in query builder so that user can see the definition for the query or update the
     * query.
     * <br>
     * <br>
     * User can get the description for queries by this service and then use it to get the
     * saved searches.
     * <br>
     * <br>
     * User can get the description for queries by this service and then use it to get the
     * search history.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Search - The capabilities to allow searching objects using the business object symantics
     * that have been persisted via the persistence management.
     *
     * @param queries
     *        A list of ImanQuery objects for which the description is requested.
     *
     * @return
     *         The description for each quested saved query (<b>ImanQuery</b>). If an  error is
     *         encountered while processing an input <b>ImanQuery</b> object, the error will be
     *         returned as a partial error with the <b>ImanQuery</b> object attached to the partial
     *         error.
     *
     */
    virtual Teamcenter::Services::Query::_2006_03::Savedquery::DescribeSavedQueriesResponse describeSavedQueries ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ImanQuery>  >& queries ) = 0;

    /**
     * Executes a single saved query by input query with entries and values. If the returned
     * result number is larger than the input limit(when limit > 0), then only the input
     * limit result number objects will be returned; otherwise all results will be returned.
     * The number of objects found is also returned; it may be larger than the limit number.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * The user opens the search view, selects a query from the system defined queries or
     * user defined queries, then fills in some input criteria, clicks the Execute button
     * to run this query. The result objects will be returned in the search result view.
     * If the total result objects number is larger than the limit number which is used
     * to prevent loading too many objects in memory considering the performance issue(when
     * limit > 0), then only return the limit number result objects for the query. The total
     * search result objects number is displayed in the search result view.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Search - The capabilities to allow searching objects using the business object symantics
     * that have been persisted via the persistence management.
     *
     * @param query
     *        The saved query to be executed which includes the query tag for the query.
     *
     * @param entries
     *        The user entries.
     *
     * @param values
     *        Values for the user entries
     *
     * @param limit
     *        The maximum number of objects to be returned. If limit <=0, then it means no limit
     *        for the results.
     *
     * @return
     *         The ExecuteSavedQueryResponse object contains the number objects found, the objects
     *         found, and serviceData.
     *
     *
     * @exception ServiceException
     *           
     * @deprecated
     *         As of tc2007, use the executeSavedQueries operation from the _2007_06 namespace.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of tc2007, use the executeSavedQueries operation from the _2007_06 namespace."))
#endif
    virtual Teamcenter::Services::Query::_2006_03::Savedquery::ExecuteSavedQueryResponse executeSavedQuery ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ImanQuery>  query,
        const std::vector< std::string >& entries,
        const std::vector< std::string >& values,
        int limit ) = 0;

    /**
     * Gets a list of all saved queries with query, query name, and query description information.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * The user can open the search view and can select a query from the Change Search dialog
     * which shows all available saved queries.
     * <br>
     * The user can open the Query Builder to load all the saved queries, and then do the
     * modification, deletion, and creation.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Search - The capabilities to allow searching objects using the business object symantics
     * that have been persisted via the persistence management.
     *
     * @return
     *         The GetSavedQueriesResponse object contains a list of SavedQueryObject  which contains
     *         the query, query name, and query description for each saved query. Failure will be
     *         return via the ServiceData. When it gets errors while getting the saved queries,
     *         the error message will be returned by the service data.
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Query::_2006_03::Savedquery::GetSavedQueriesResponse getSavedQueries (  ) = 0;

    /**
     * Delete saved searches with given names.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Delete specified saved searches.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Search - The capabilities to allow searching objects using the business object symantics
     * that have been persisted via the persistence management.
     *
     * @param queryCriteriaNames
     *        A list of saved search names to delete.
     *
     * @return
     *         Standard ServiceData. The client id of the partial error inside ServiceData is the
     *         saved search name for which the delete failed.
     *         <br>
     *         <br>
     *         Following are some possible errors returned in ServiceData:
     *         <br>
     *         <br>
     *         217015 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The saved search cannot be
     *         deleted based on the name: multiple saved searches were found for the given name.
     *         <br>
     *
     *
     * @exception ServiceException
     *           
     * @deprecated
     *         As of Teamcenter 8.1, use the deleteObjects operation.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 8.1, use the deleteObjects operation."))
#endif
    virtual Teamcenter::Soa::Client::ServiceData deleteQueryCriterias ( const std::vector< std::string >& queryCriteriaNames ) = 0;

    /**
     * Reorder the saved Query Criterias in the MySavedSearches List:   The new order of
     * query criteria names specified in the input list will be stored in the MySavedSearches
     * list.    The input list should contain only existing query criteria names    If a
     * query criteria name in the list is not located, it will not be stored in the list.
     * The number of entries in the input list should match the number entries in the
     * MySavedSearches list.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Search - The capabilities to allow searching objects using the business object symantics
     * that have been persisted via the persistence management.
     *
     * @param queryCriteriaNames
     *        - vector of query criteria names with the new order.
     *
     * @return
     *         ServiceData - The client id of the partial error   is the name of the Query Criteria
     *         which are either missing from or   not present in the "MySavedSearches" list.
     *
     *
     * @exception ServiceException
     *           
     *           <ul>
     *           <li type="disc">When input argument is not specified
     *           </li>
     *           <li type="disc">When input vector is empty
     *           </li>
     *           </ul>
     * @deprecated
     *         As of Teamcenter 8.1, there is no replacement.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 8.1, there is no replacement."))
#endif
    virtual Teamcenter::Soa::Client::ServiceData reorderSavedQueryCriterias ( const std::vector< std::string >& queryCriteriaNames ) = 0;

    /**
     * Retrieve the information on the saved search by the search name.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Search - The capabilities to allow searching objects using the business object symantics
     * that have been persisted via the persistence management.
     *
     * @param queryCriteriaNames
     *        A vector of search names for which to retrieve the information.
     *
     * @return
     *         RetrieveQueryCriteriaResponse - contains a vector of SaveQueryCriteriaInfo where
     *         each member corresponds an input queryCriteriaName.  The response also contains
     *         a standard ServiceData member.  Partial errors contain a client id which is the queryCriteriaName
     *         mapped to the error message.
     *
     *
     * @exception ServiceException
     *           
     * @deprecated
     *         As of tc2007.1, use the retrieveSearchCriteria operation from  the _2007_06 namespace.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of tc2007.1, use the retrieveSearchCriteria operation from  the _2007_06 namespace."))
#endif
    virtual Teamcenter::Services::Query::_2007_01::Savedquery::RetrieveQueryCriteriaResponse retrieveQueryCriterias ( const std::vector< std::string >& queryCriteriaNames ) = 0;

    /**
     * Saves a saved search with search name, query name, entry names, and entry values.
     * If search name is not provided, the criteria keys or the criteria values size is
     * 0, or the criteria keys size does not equal to the criteria values size, or if error
     * happens while creating the saved search, the related error information will be added
     * to the error stack. If the search criteria size is no more than 0, ServiceException
     * will throw out of this service. The created saved search objects will be returned.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User selects a query and fills in some criterias, and then save the search from thin
     * client with a search name.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Search - The capabilities to allow searching objects using the business object symantics
     * that have been persisted via the persistence management.
     *
     * @param queryCriterias
     *        A list of SaveQueryCriteriaInfo representing saved searches to be saved to the database.
     *
     * @return
     *         ServiceData - The created saved search objects will be returned by service data,
     *         the related error information will also be returned from the error stack. If search
     *         name is not provided, the criteria keys or the criteria values size is 0, or the
     *         criteria keys size does not equal to the criteria values size, or if error happens
     *         while creating the saved search, the related error information will be added to the
     *         error stack.
     *
     *
     * @exception ServiceException
     *           
     * @deprecated
     *         As of tc2007.1, use the saveSearchCriteria operation from the _2007_06 namespace.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of tc2007.1, use the saveSearchCriteria operation from the _2007_06 namespace."))
#endif
    virtual Teamcenter::Soa::Client::ServiceData saveQueryCriterias ( const std::vector< Teamcenter::Services::Query::_2007_01::Savedquery::SaveQueryCriteriaInfo >& queryCriterias ) = 0;

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

    /**
     * Executes a set of saved queries of following types: QRY_RUN_BY_TC, QRY_RUN_BY_KEYWORD_SEARCH.
     * The saved queries can be executed to yield results in 2 modes:  (1) Flat mode:
     * In this traditional execution mode, only the first-level objects (corresponding to
     * the queried class) satisfying the query are returned (2) Hierarchical/Indented mode:
     * This mode is only applicable for saved queries that allow Hierarchical/Indented results.
     * In this execution mode, the first-level objects as well as any sub-level objects
     * satisfying the query criteria are returned. The hierarchy level information is also
     * returned so that result subsets can be reconstructed using the resulting objects.
     * This service will retun the matched object UIDs. After fetching UIDs, client need
     * to call DataManagementService.loadObjects operation to load objects by pages.
     * See the QueryInput and QueryResults data structures for usage details.
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
     *         errors are stored and referenced by input vector indexes.
     *
     * @deprecated
     *         As of Tc 8, use the executeSavedQueries operation from the _2008_06 namespace.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Tc 8, use the executeSavedQueries operation from the _2008_06 namespace."))
#endif
    virtual Teamcenter::Services::Query::_2007_09::Savedquery::SavedQueriesResponse executeSavedQueries ( const std::vector< Teamcenter::Services::Query::_2007_09::Savedquery::QueryInput >& input ) = 0;

    /**
     * Executes a set of saved queries of following type  QRY_RUN_BY_TC, QRY_RUN_BY_KEYWORD_SEARCH.
     * The saved queries can be executed to yield results in 2 modes:  - Flat mode: In
     * this traditional execution mode, only the first-level  objects (corresponding to
     * the queried class) satisfying the query  are returned  - Hierarchical/Indented mode:
     * This mode is only applicable for  saved queries that allow Hierarchical/Indented
     * results. In this  execution mode, the first-level objects as well as any sub-level
     * objects satisfying the query criteria are returned. The hierarchy  level information
     * is also returned so that result subsets can be  re-constructed using the resulting
     * objects.   This service will retun the matched object UIDs.   After fetching UIDs,
     * client need to call DataManagementService.loadObjects operation  to load objects
     * by pages.  See the QueryInput and QueryResults data structures for  usage details.
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
     *         contains (1) a set of QueryResults  data structures and (2) a ServiceData.  Partial
     *         errors are stored and referenced by input vector indexes.
     *
     */
    virtual Teamcenter::Services::Query::_2007_09::Savedquery::SavedQueriesResponse executeSavedQueries ( const std::vector< Teamcenter::Services::Query::_2008_06::Savedquery::QueryInput >& input ) = 0;

    /**
     * The user can find the saved queries of interest by passing in the criteria such as
     * query name and description. The queries that are matching the input criteria will
     * be returned back to the user.  This operation can be sued to find the queries with
     * a given name(s) or description(s) or combination of name(s) and description(s). This
     * operation returns the queries matching the input criteria names and descriptions.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Find saved queries by given saved query name(s) and description(s).
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Search - The capabilities to allow searching objects using the business object symantics
     * that have been persisted via the persistence management.
     *
     * @param inputCriteria
     *        Structure that contains the input criteria required to find the saved queries.
     *
     * @return
     *         Returns the saved queries found matching the given input criteria.
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Query::_2010_04::Savedquery::FindSavedQueriesResponse findSavedQueries ( const std::vector< Teamcenter::Services::Query::_2010_04::Savedquery::FindSavedQueriesCriteriaInput >& inputCriteria ) = 0;

    /**
     * Execute business object searches (Simple Search) and return search results.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Execute business object searches (Simple Search).
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Search - The capabilities to allow searching objects using the business object symantics
     * that have been persisted via the persistence management.
     *
     * @param inputs
     *        Business object query inputs
     *
     * @return
     *         Contains (1) a set of QueryResults data structures and (2) a ServiceData. Partial
     *         errors are stored and referenced by input vector indexes.
     *
     */
    virtual Teamcenter::Services::Query::_2007_09::Savedquery::SavedQueriesResponse executeBusinessObjectQueries ( const std::vector< Teamcenter::Services::Query::_2010_09::Savedquery::BusinessObjectQueryInput >& inputs ) = 0;

    /**
     * Creates a list of saved queries based on the input properties structure.
     *
     * @param inputs
     *        A saved query is created for each <code>SavedQueryProperties</code> in the list.
     *
     * @return
     *         The newly created saved queries are added to the Created list of the <b>ServiceData</b>.
     *         Partial Errors are returned in the <b>ServiceData</b> with <code>clientId</code>
     *         when creating saved query fails. Following are possible errors returned:
     *         <br>
     *         <ul>
     *         <li type="disc">3001 Invalid class name %1$.
     *         </li>
     *         <li type="disc">3024 No class was specified.
     *         </li>
     *         <li type="disc">3028 Cannot create a saved query.
     *         </li>
     *         <li type="disc">3038 Query name exists. Name must be unique.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData createSavedQueries ( const std::vector< Teamcenter::Services::Query::_2013_05::Savedquery::SavedQueryProperties >& inputs ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("SavedqueryService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/query/Query_undef.h>
#endif

