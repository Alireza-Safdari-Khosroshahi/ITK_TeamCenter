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

#ifndef TEAMCENTER_SERVICES_QUERY__2013_05_SAVEDQUERY_HXX
#define TEAMCENTER_SERVICES_QUERY__2013_05_SAVEDQUERY_HXX



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
            namespace _2013_05
            {
                class Savedquery;

class TCSOAQUERYSTRONGMNGD_API Savedquery
{
public:

    struct SavedQueryProperties;

    /**
     * Contains properties of the saved query to be created.
     */
    struct SavedQueryProperties
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify returned partial
         * errors associated with this input structure.
         */
        std::string clientId;
        /**
         * Name of the saved query to be created.
         */
        std::string queryName;
        /**
         * Description of the saved query to be created, may be an empty string.
         */
        std::string queryDesc;
        /**
         * The storage class name of the business object type this query will find object instances
         * of.
         */
        std::string queryClass;
        /**
         * Query clauses of the saved query to be created. To make sure the query clauses is
         * in correct formate, please use Export button in Query Builder to export the saved
         * query into a XML file, pick up the string value of QueryClause element in the XML,
         * replace all &quot; with " to get the final string, the final query clauses string
         * should be the same as seen in View Properties dialog.
         */
        std::string queryClauses;
    };




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


protected:
    virtual ~Savedquery() {}
};
            }
        }
    }
}

#include <teamcenter/services/query/Query_undef.h>
#endif

