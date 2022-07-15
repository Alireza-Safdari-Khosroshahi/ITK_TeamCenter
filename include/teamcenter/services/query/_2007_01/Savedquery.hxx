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

#ifndef TEAMCENTER_SERVICES_QUERY__2007_01_SAVEDQUERY_HXX
#define TEAMCENTER_SERVICES_QUERY__2007_01_SAVEDQUERY_HXX



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
            namespace _2007_01
            {
                class Savedquery;

class TCSOAQUERYSTRONGMNGD_API Savedquery
{
public:

    struct RetrieveQueryCriteriaResponse;
    struct SaveQueryCriteriaInfo;

    /**
     * RetrieveQueryCriteriaResponse
     */
    struct RetrieveQueryCriteriaResponse
    {
        /**
         * vector of SaveQueryCriteriaInfo
         */
        std::vector< Teamcenter::Services::Query::_2007_01::Savedquery::SaveQueryCriteriaInfo > output;
        /**
         * standard ServiceData member
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * SaveQueryCriteriaInfo
     */
    struct SaveQueryCriteriaInfo
    {
        /**
         * The name of the saved search.
         */
        std::string searchName;
        /**
         * The name of the query associated with this search.
         */
        std::string queryName;
        /**
         * The attribute names for the query.
         */
        std::vector< std::string > keys;
        /**
         * The attribute values for the query.
         */
        std::vector< std::string > values;
    };




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


protected:
    virtual ~Savedquery() {}
};
            }
        }
    }
}

#include <teamcenter/services/query/Query_undef.h>
#endif

