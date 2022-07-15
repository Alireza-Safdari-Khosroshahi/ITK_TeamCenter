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

#ifndef TEAMCENTER_SERVICES_QUERY__2010_09_SAVEDQUERY_HXX
#define TEAMCENTER_SERVICES_QUERY__2010_09_SAVEDQUERY_HXX

#include <teamcenter/services/query/_2007_09/Savedquery.hxx>


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
            namespace _2010_09
            {
                class Savedquery;

class TCSOAQUERYSTRONGMNGD_API Savedquery
{
public:

    struct BusinessObjectQueryClause;
    struct BusinessObjectQueryInput;

    /**
     * Business object query clause
     */
    struct BusinessObjectQueryClause
    {
        /**
         * Property Name.
         */
        std::string propName;
        /**
         * Property Value.
         */
        std::string propValue;
        /**
         * Math Operator.  Legal math operators can be =, !=, >, >=, <, <=, Contain, IS_NULL
         * or IS_NOT_NULL according to the property type.
         */
        std::string mathOperator;
        /**
         * Logic Operator.  Legal logic operators are "AND" and "OR".
         */
        std::string logicOperator;
    };

    /**
     * Business Object Query Input
     */
    struct BusinessObjectQueryInput
    {
        /**
         * Name of business object type
         */
        std::string typeName;
        /**
         * Query clauses in serach criteria.
         */
        std::vector< Teamcenter::Services::Query::_2010_09::Savedquery::BusinessObjectQueryClause > clauses;
        /**
         * Specified maximum number of objects to return.
         */
        int maxNumToReturn;
        /**
         * Unique ID used to register execution task
         */
        std::string requestId;
        /**
         * Client identifier for routing purpose
         */
        std::string clientId;
    };




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


protected:
    virtual ~Savedquery() {}
};
            }
        }
    }
}

#include <teamcenter/services/query/Query_undef.h>
#endif

