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

#ifndef TEAMCENTER_SERVICES_QUERY__2006_03_SAVEDQUERY_HXX
#define TEAMCENTER_SERVICES_QUERY__2006_03_SAVEDQUERY_HXX

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
            namespace _2006_03
            {
                class Savedquery;

class TCSOAQUERYSTRONGMNGD_API Savedquery
{
public:

    struct DescribeSavedQueriesResponse;
    struct ExecuteSavedQueryResponse;
    struct GetSavedQueriesResponse;
    struct SavedQueryFieldListObject;
    struct SavedQueryFieldObject;
    struct SavedQueryObject;

    /**
     * Holds the field data for each saved query.
     */
    struct DescribeSavedQueriesResponse
    {
        /**
         * A list of fields for each input query.
         */
        std::vector< Teamcenter::Services::Query::_2006_03::Savedquery::SavedQueryFieldListObject > fieldLists;
        /**
         * The standard ServiceData.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Holds the response for ExecuteSavedQuery. The number of objects found is the   total
     * number found and may be greater than the number return in the vector of   objects
     * if a limit was specified on executing the query.
     */
    struct ExecuteSavedQueryResponse
    {
        /**
         * The number of objects found by the query.
         */
        int nFound;
        /**
         * The objects returned.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > objects;
        /**
         * The standard service data which includes the returned objects.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Holds the response for GetSavedQueries
     */
    struct GetSavedQueriesResponse
    {
        /**
         * A list of SavedQueryObjects each of which contains the query, query name, and query
         * description for a saved query.
         */
        std::vector< Teamcenter::Services::Query::_2006_03::Savedquery::SavedQueryObject > queries;
        /**
         * Standard ServiceData
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * A  list of saved query fields for a saved query.
     */
    struct SavedQueryFieldListObject
    {
        /**
         * Holds one entry per clause
         */
        std::vector< Teamcenter::Services::Query::_2006_03::Savedquery::SavedQueryFieldObject > fields;
    };

    /**
     * The data for a field of a saved query.
     */
    struct SavedQueryFieldObject
    {
        /**
         * The attribute name for the clause.
         */
        std::string attributeName;
        /**
         * User entry name for clause.
         */
        std::string entryName;
        /**
         * Logical operator for clause
         */
        std::string logicalOperation;
        /**
         * Math operator for clause
         */
        std::string mathOperation;
        /**
         * Default value for clause
         */
        std::string value;
        /**
         * LOV for the clause
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  lov;
        /**
         * Attribute type for clause
         */
        int attributeType;
    };

    /**
     * The data for each saved query found.
     */
    struct SavedQueryObject
    {
        /**
         * The saved query.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ImanQuery>  query;
        /**
         * The name of the saved query.
         */
        std::string name;
        /**
         * The description of the saved query.
         */
        std::string description;
    };




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


protected:
    virtual ~Savedquery() {}
};
            }
        }
    }
}

#include <teamcenter/services/query/Query_undef.h>
#endif

