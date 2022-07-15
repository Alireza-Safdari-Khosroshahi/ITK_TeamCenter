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

#ifndef TEAMCENTER_SERVICES_QUERY__2008_06_SAVEDQUERY_HXX
#define TEAMCENTER_SERVICES_QUERY__2008_06_SAVEDQUERY_HXX

#include <teamcenter/services/query/_2007_09/Savedquery.hxx>
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
            namespace _2008_06
            {
                class Savedquery;

class TCSOAQUERYSTRONGMNGD_API Savedquery
{
public:

    struct QueryInput;

    /**
     * The information about each Saved Query to be processed is provided  by way of this
     * data structure.
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
        /**
         * Unique ID used to register the query execution task.
         */
        std::string requestId;
        /**
         * Client identifier for routing purposes.
         */
        std::string clientId;
    };




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


protected:
    virtual ~Savedquery() {}
};
            }
        }
    }
}

#include <teamcenter/services/query/Query_undef.h>
#endif

