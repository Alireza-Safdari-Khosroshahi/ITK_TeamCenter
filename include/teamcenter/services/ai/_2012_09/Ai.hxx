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

#ifndef TEAMCENTER_SERVICES_AI__2012_09_AI_HXX
#define TEAMCENTER_SERVICES_AI__2012_09_AI_HXX

#include <teamcenter/services/ai/_2006_03/Ai.hxx>
#include <teamcenter/soa/client/model/AppInterface.hxx>
#include <teamcenter/soa/client/model/RequestObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/ai/Ai_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Ai
        {
            namespace _2012_09
            {
                class Ai;

class TCSOAAISTRONGMNGD_API Ai
{
public:

    struct ProjectFilter;
    struct FindRequestsFilter;
    struct FindRequestsResponse;
    struct GetProjectsInfo2Response;
    struct GetRequestsInfo2Response;
    struct ProjectInfo;
    struct RequestDetail;
    struct RequestInfo;

    /**
     * string to string map.
     */
    typedef std::map< std::string, std::string > StrToStrMap;

    /**
     * Structure to specify the filter when using getProjects  method.
     */
    struct ProjectFilter
    {
        /**
         * name of the AppliationInterface Object
         */
        std::string name;
        /**
         * description of the ApplicationInterface Object
         */
        std::string description;
        /**
         * type of the ApplicationInterface Object. The type must be a valid type of AI Object.
         */
        std::string type;
        /**
         * userId to filter on (maps to owning user)
         */
        std::string userId;
        /**
         * filter on AI objects using groupName
         */
        std::string groupName;
        /**
         * filtering by Date
         */
        Teamcenter::Soa::Common::DateTime createdBefore;
        /**
         * filtering by Date
         */
        Teamcenter::Soa::Common::DateTime createdAfter;
        /**
         * filtering by Date
         */
        Teamcenter::Soa::Common::DateTime modifiedBefore;
        /**
         * filtering by Date
         */
        Teamcenter::Soa::Common::DateTime modifiedAfter;
        /**
         * filtering by Date
         */
        Teamcenter::Soa::Common::DateTime releasedBefore;
        /**
         * filtering by Date
         */
        Teamcenter::Soa::Common::DateTime releasedAfter;
        /**
         * maps to the context string of AI object's Export TransferMode.
         */
        std::string contextString;
        /**
         * valid site names to be used to search for ApplicationInterface objects.
         */
        std::vector< std::string > targetSiteIds;
        /**
         * if an application stamps a targetAppProject id using the setProjectsInfo method -
         * they can use this for filtering.
         */
        std::string targetAppProjectId;
    };

    /**
     * structure that captures the filtering options for getting the Request Objects. This
     * will include the AppInterface filter options too.
     */
    struct FindRequestsFilter
    {
        /**
         * structure to capture the filter options on parent(s) ApplicationInterfaces of the
         * RequestObject(s)
         */
        Teamcenter::Services::Ai::_2012_09::Ai::ProjectFilter aiQryParams;
        /**
         * vector  representing the requeststates to use for filtering. Currently, the only
         * valid values are unique combinations of (case sensitive): Processing, Pending, Communicating,
         * Completed, Rejected
         */
        std::vector< std::string > requestState;
        /**
         * vector of strings representing the statuses on the request to search for. Currently,
         * the valid values are a combination of (case sensitive): Normal,  Warning, Severe,
         * Abort
         */
        std::vector< std::string > requestStatus;
        /**
         * state description to use for searching for RequestObject.
         */
        std::string stateDescription;
        /**
         * status message by which to filter for RequestObjects.
         */
        std::string statusDescription;
        /**
         * vector of strings that have the custom key and value pair to search on.
         */
        StrToStrMap customStrings;
        /**
         * the type of request - valid values:Publish, Sync. Empty vector if this filter option
         * is not needed.
         */
        std::vector< std::string > requestType;
    };

    /**
     * structure containing the response from findRequests method. partial failures are
     * captured in the serviceData and found Requests are captured in RequestDetails.
     */
    struct FindRequestsResponse
    {
        /**
         * list of found requests based on the input query.
         */
        std::vector< Teamcenter::Services::Ai::_2012_09::Ai::RequestDetail > requests;
        /**
         * Any partial errors are reported in this member.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * get the ProjectInfo structure for each of the specified ApplicationInterfaceObjects.
     */
    struct GetProjectsInfo2Response
    {
        /**
         * info about the ApplicationInterface objects
         */
        std::vector< Teamcenter::Services::Ai::_2012_09::Ai::ProjectInfo > infos;
        /**
         * partial errors are returned in this structure.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * get the details on the input RequestObject.
     */
    struct GetRequestsInfo2Response
    {
        /**
         * details about the input RequestObjects. If there is an error getting info for any
         * RequestObject, it will not be in this vector, but failure details will be in the
         * serviceData.
         */
        std::vector< Teamcenter::Services::Ai::_2012_09::Ai::RequestDetail > details;
        /**
         * serviceData to capture any partialErrors. client id used will be the position in
         * the input vector.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Structure to specify ApplicationInterface information.
     */
    struct ProjectInfo
    {
        /**
         * The ApplicationInterfaceObject for which the info is relevant.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AppInterface>  ai;
        /**
         * The projectId string recorded on the ApplicationInterface Object
         */
        std::string targetAppProjectId;
        /**
         * name of the AppliationInterface Object
         */
        std::string name;
        /**
         * description of the ApplicationInterface Object
         */
        std::string description;
        /**
         * The list of names of targetSiteIds to be set on the ApplicationInterface Object.
         * Entries must be valid site names.
         */
        std::vector< std::string > targetSiteIds;
    };

    /**
     * Structure representing the details of the RequestObject
     */
    struct RequestDetail
    {
        /**
         * the request object for which the details are being provided.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::RequestObject>  ro;
        /**
         * name of the RequestObject
         */
        std::string name;
        /**
         * description of the RequestObject
         */
        std::string description;
        /**
         * description on the state of the RequestObject.
         */
        std::string stateDesc;
        /**
         * the status fields of the RequestObject
         */
        Teamcenter::Services::Ai::_2006_03::Ai::StatusInfo status;
        /**
         * 2 values are possible:  0(whole)- no ExternalReference elements will be found in
         * plmxml. Partial(1) then there will be ExternalReference elements in plmxml.
         */
        int rscope;
        /**
         * used to specify an incremental update. possible values are 0 (Full), 1 ( delta).
         */
        int rupdate;
        /**
         * key value pairs associated with the RequestObject. These would have been populated
         * via the setRequestsInfo call.
         */
        StrToStrMap kvPairs;
    };

    /**
     * structure representing gettable/settable information on a RequestObject by clients
     * for a given RequestObject.
     */
    struct RequestInfo
    {
        /**
         * the object for which the data is being or retrieved.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::RequestObject>  ro;
        /**
         * The string to set/get for the RequestObject's state_msg property.
         */
        std::string stateMessage;
        /**
         * Structure to set the status and status_msg attributes of RequestObject. These typically
         * are used to provide the TC user information about what happened in the relevant client
         * application.
         */
        Teamcenter::Services::Ai::_2006_03::Ai::StatusInfo statusInfo;
        /**
         * key value pairs of strings to allow clients to set custom properties on the RequestObject.
         * Limit of 64 bytes on key and 256 bytes on value.
         */
        StrToStrMap kvPairs;
    };




    /**
     * method to find request objects based on the input criteria.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param filter
     *        Mandatory input field for filtering Request objects as per the input criteria.
     *
     * @return
     *         list of found requests and any  partial errors.
     *
     */
    virtual Teamcenter::Services::Ai::_2012_09::Ai::FindRequestsResponse findRequests ( const Teamcenter::Services::Ai::_2012_09::Ai::FindRequestsFilter&  filter ) = 0;

    /**
     * get the Application Interface objects based on a optional filter.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param filter
     *        optional filter used to narrow down the number of ApplicationInterface Objects.
     *
     * @return
     *         ServiceData object that has the ApplicationInterface objects that were found (returned
     *         as plain objects).
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData getProjects ( const Teamcenter::Services::Ai::_2012_09::Ai::ProjectFilter*  filter ) = 0;

    /**
     * set the info on the ApplicationInterface Objects.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param infos
     *        info to be set on the ApplicationInterface Object. The Ai object is part of the structure.
     *
     * @return
     *         ServiceData object that returns the objects on which setting the data succeeded,
     *         and partial failures for those that failed.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData setProjectsInfo ( const std::vector< Teamcenter::Services::Ai::_2012_09::Ai::ProjectInfo >& infos ) = 0;

    /**
     * method to allow caller to set the fields on the RequestObject.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param infos
     *        vector of info elements to set data on respective RequestObject.
     *
     * @return
     *         ServiceData that captures partial failures, and also list of updated objects if data
     *         is set successfully.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData setRequestsInfo ( const std::vector< Teamcenter::Services::Ai::_2012_09::Ai::RequestInfo >& infos ) = 0;

    /**
     * return the projectInfo information for each of the supplied ApplicationInterface
     * Objects.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param projects
     *        list of Application Interface objects for which the details are needed.
     *
     * @return
     *         return the info for the provided Application Interface Objects, and any partial errors
     *         - the Application Interface Objects position in the passed in vector will be used
     *         as the clientId for errors
     *
     */
    virtual Teamcenter::Services::Ai::_2012_09::Ai::GetProjectsInfo2Response getProjectsInfo2 ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AppInterface>  >& projects ) = 0;

    /**
     * get details about specific RequestObjects. These include state desc,status info,
     * custom key value pairs.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param robjects
     *        input vector of RequestObjects for which details are needed.
     *
     * @return
     *         vector or RequestDetails. The size of this vector may not be same as input vector.
     *         Partial errors are recorded in serviceData.
     *
     */
    virtual Teamcenter::Services::Ai::_2012_09::Ai::GetRequestsInfo2Response getRequestsInfo2 ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::RequestObject>  >& robjects ) = 0;


protected:
    virtual ~Ai() {}
};
            }
        }
    }
}

#include <teamcenter/services/ai/Ai_undef.h>
#endif

