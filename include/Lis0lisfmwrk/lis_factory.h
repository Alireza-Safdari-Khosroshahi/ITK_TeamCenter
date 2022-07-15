/*
    Copyright 2020 Siemens Digital Industries Software
    ==================================================
    Copyright 2014.
    Siemens Product Lifecycle Management Software Inc.
    All Rights Reserved.
    ==================================================
    Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    This file implements LIS II - Lifecycle Interoperability Services (LIS) Registry ITks for all factory Actions.

*/

#ifndef LIS_FACTORY_H
#define LIS_FACTORY_H

#include <unidefs.h>
#include <epm/epm.h>
#include <common/tc_deprecation_macros.h>
#include <Lis0lisfmwrk/libLis0lisfmwrk_exports.h>

/**
    @defgroup LIS0LISFMWRK Lifecycle Interoperability Services (LIS) Factory Services ITKs
    The ITK functions in this module called for LIS factory service requests given from REST client
    @ingroup TC
    @{
*/

/**
   Defines structure of arguments used for quering property values from remote OSLC system like Polarion.
*/
struct RemoteOSLC_RequestArgs
{
    tag_t*      arrTcLDFTags;              /**< Array of remote links tag. */
    int         nTcLDFTags;               /**< Number of remote links tag. */
    char**      arrRemoteProperties;      /**< Array of remote properties to be queried. */
    int         nRemoteProperties;        /**< Number of remote properties to be queried. */
    char*       strRemoteUserName;        /**< Remote user name to be used. */
};

/**
   Encapsulates arrays of remote properties and their actual values together
*/
struct PropsVals
{
    char*  sProperties;                /**< Array of remote properties queried. */
    char*  sValues;                    /**< Array of their actual values. */
};

/**
   Defines structure of OSLC remote query response per remote link tag.
*/
struct RemoteQuery_Response
{
    tag_t    tagTcLDF;               /**< Tag of a remote link in TC. */
    int      nPropsVals;             /**< Number of property-value pairs returned for this tag_t. */
    PropsVals *PropsAndVals;         /**< Array of property-value pairs returned for this tag_t. */
};

/**
   Defines array of structure of OSLC remote query responses.
*/
struct  RemoteOSLC_ResponseArgs
{
    RemoteQuery_Response *  pRemoteQueryResponse;    /**< Array of remote query responses per TC remote link tag */
    int                     nRemoteQueryResponse;    /**< Number of remote query responses per TC remote link tag */
};

#ifdef __cplusplus
 extern "C"{
#endif

/**

@deprecated #LDF_sync_ldf_status deprecated in Teamcenter 11.5. Use #LDF-sync-ldf-status workflow handler instead.
<br/>Please use "LDF-sync-ldf-status" workflow handler instead of this ITK

 A Workflow Rule Handler that checks if specified remote properties match with specified expected values.
<br/>The handler is placed on complete action and allows completion of a task only when remote properties have expected values and applies status check.
@returns
<ul>
<li>#EPM_go on success.
<li>#EPM_nogo on failure
</ul>
*/
TC_DEPRECATED( "11.5", "LDF_sync_ldf_status", "LDF-sync-ldf-status workflow handler" )
extern LIS0LISFMWRK_API int LDF_sync_ldf_status(
                                                 EPM_rule_message_t msg  /**< (I) Handler Arguments and other handler related information. */
                                               );

/**
Retrieves the value of property specified.
<br/>This method is invoked to query properties values of remote object like Polarion Work Item.
<br/>The configured properties for remote object specified by argument is queried and returned.
@returns
<ul>
<li>#ITK_ok on success.
<li>#HTTPRESPONSE_NOTAUTHORIZED if an authorization failed.
<li>#HTTP_URL_NOTCONNECTABLE if remote system is not contactable.
<li>#LIS0LISFMWRK_remote_property_not_found if remote property is not found.
</ul>
*/
extern LIS0LISFMWRK_API int LIS_get_remote_properties(
                                                        const RemoteOSLC_RequestArgs*   remote_oslc_query_args,                       /**< (I) Data structure containing linked object tag, oslc prefix and corresponding properties to get from remote system. */
                                                        RemoteOSLC_ResponseArgs*        remote_oslc_response                         /**< (O) Data structure containing list of linked object tag along with sub-list of <property-retrieved value> pair for each linked object tag */
                                                     );

/**
Links a Teamcenter object to remote object (like a Polarion Work Item) and vice-versa. 
<br/>It first creates a forward link in Teamcenter to the remote object and then sends a backlink creation request to the remote system. 

@returns 
<ul>
<li>#ITK_ok on success.
<li>#HTTPRESPONSE_NOTAUTHORIZED if an authorization failed.
<li>#HTTP_URL_NOTCONNECTABLE if the remote system is not reachable.
<li>#LIS0LISFMWRK_invalid_relation_type_to_link if provided Open Services for Lifecycle Collaboration (OSLC) relation is invalid or not configured for given combination of source and remote semantic types.
<li>#LIS0LISFMWRK_remote_object_link_exists if link already exists on provided remote object with Open Services for Lifecycle Collaboration (OSLC) relation.
<li>#LIS0LISFMWRK_invalid_url_input if input remote object url or relation is empty or NULL.
<li>#LIS0LISFMWRK_url_not_authorized if the URL cannot be accessed because of authorization issues.
</ul> 
*/
extern LIS0LISFMWRK_API int LIS_link_remote_object( 
                                                        const char*    remote_object_url,                       /**< (I) URL of a remote workitem. */
                                                        const char*    oslc_relation,                           /**< (I) Relation used for creating a forward in Teamcenter to the remote object. */
                                                        const tag_t    src_object,                              /**< (I) Source item or item revision object tag to which remote object will be attached. */
                                                        const char*    remote_user_name,                        /**< (I) The username of the Remote System */
                                                        char**         response                                 /**< (OF) Response based on success or failure. */
                                                  );

/**
Creates remote objects in ALM (Application Lifecycle Management)from Teamcenter and provides the URL for the created remote object.

@returns
<ul>
<li>#ITK_ok on success. 
<li>#TCCORE_NULL_argument_passed if @p remote_object_type, @p creation_input or @p service_provider is invalid . 
<li>#LIS0LISFMWRK_url_not_authorized if the URL cannot be accessed because of authorization issues. 
<li>#HTTPRESPONSE_NOTAUTHORIZED if the remote system is not authorized to create remote objects. 
<li>#HTTP_URL_NOTCONNECTABLE if the remote system is not reachable.
<li>#LIS0LISFMWRK_no_factory_services_remote_type if no factory services have been defined for the remote WorkItem.
</ul>
*/
extern LIS0LISFMWRK_API int LIS_create_remote_object( const char* remote_object_type,           /**< (I) Type of remote WorkItem  */
                                                      const tag_t service_provider,             /**< (I) The Service Provider */
                                                      const char* creation_input,               /**< (I) Creation Data/Request Body used for creating the remote object*/
                                                      const char* request_format,               /**< (I) The Request Format used for creating remote WorkItem.
                                                                                                <br/>Supported Formats are application/rdf+xml,application/json*/
                                                      const char* remote_user_name,             /**< (I) The username of the Remote System */
                                                      char** url                                /**< (OF) The URL of the remote WorkItem */
                                                    );
/** @} */

#ifdef __cplusplus
}
#endif

#include <Lis0lisfmwrk/libLis0lisfmwrk_undef.h>

#endif
