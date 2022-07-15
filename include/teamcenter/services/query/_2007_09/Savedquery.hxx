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

#ifndef TEAMCENTER_SERVICES_QUERY__2007_09_SAVEDQUERY_HXX
#define TEAMCENTER_SERVICES_QUERY__2007_09_SAVEDQUERY_HXX

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
            namespace _2007_09
            {
                class Savedquery;

class TCSOAQUERYSTRONGMNGD_API Savedquery
{
public:

    struct QueryInput;
    struct QueryResults;
    struct SavedQueriesResponse;

    /**
     * The information about each Saved Query to be processed is provided  by way of the
     * SavedQueryInput data structure.
     */
    struct QueryInput
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
         * A specified maximum number of matches to be returned, 0 means no limit.
         */
        int maxNumToReturn;
        /**
         * The type of results expected from this operation: 0 (top-level objects only), 1 (top-level
         * objects plus children: Hierarchical/Indented results), 2 (default value as specified
         * on the query object).
         */
        int resultsType;
    };

    /**
     * Results of saved query  execution, including hierarchy information in a relation
     * map for Hierarchical/Indented execution.  Hierarchical/Indented execution example1:
     * If the query is: Find all Items where the Item Revisions have a Specification Dataset
     * with name = "xyz1", then results will be comprised of subsets, each containing: an
     * Item, a qualifying Item Revision and a qualifying Dataset. For each result subset,
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
    struct QueryResults
    {
        /**
         * Used only for Hierarchical/Indented execution. An integer array containing the hierarchy
         * level information which maps 1-to-1 to the returned list of objects which is ordered
         * as subsets. The integer code in the relation map indicates if the corresponding object
         * in the results set is a root object (=0), or a first-level child (=1), or a second-level
         * child (=2) and so on. In the case of child levels, the level information is with
         * respect to the immediately preceding root object entry in the mapping. The order
         * of returns is relevant.
         */
        std::vector< int > objectsRelMap;
        /**
         * The object UIDs returned from the search.
         */
        std::vector< std::string > objectUIDS;
    };

    /**
     * Contains a list of business objects found as well as the service data returned.
     */
    struct SavedQueriesResponse
    {
        /**
         * A set of QueryResults data structures.
         */
        std::vector< Teamcenter::Services::Query::_2007_09::Savedquery::QueryResults > arrayOfResults;
        /**
         * The service data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




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


protected:
    virtual ~Savedquery() {}
};
            }
        }
    }
}

#include <teamcenter/services/query/Query_undef.h>
#endif

