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

#ifndef TEAMCENTER_SERVICES_QUERY__2010_04_SAVEDQUERY_HXX
#define TEAMCENTER_SERVICES_QUERY__2010_04_SAVEDQUERY_HXX

#include <teamcenter/soa/client/model/ImanQuery.hxx>


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
            namespace _2010_04
            {
                class Savedquery;

class TCSOAQUERYSTRONGMNGD_API Savedquery
{
public:

    struct FindSavedQueriesCriteriaInput;
    struct FindSavedQueriesResponse;

    /**
     * Structure that contains the input criteria required to find the saved queries.
     */
    struct FindSavedQueriesCriteriaInput
    {
        /**
         * Names of saved queries to be found.
         */
        std::vector< std::string > queryNames;
        /**
         * Descrptions of saved queries to be found.
         */
        std::vector< std::string > queryDescs;
        /**
         * The type of the saved queries.
         */
        int queryType;
    };

    /**
     * Holds the response for FindSavedQueries.
     */
    struct FindSavedQueriesResponse
    {
        /**
         * A vector of Saved Query objects.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ImanQuery>  > savedQueries;
        /**
         * Standard ServiceData
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




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


protected:
    virtual ~Savedquery() {}
};
            }
        }
    }
}

#include <teamcenter/services/query/Query_undef.h>
#endif

