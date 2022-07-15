/*
Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright 2018.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software
*/

#ifndef SIS_H
#define SIS_H

#include <unidefs.h>
#include <sis0socialint/libsis0socialint_exports.h>

/**
    @defgroup SIS0SOCIALINT Team Collaboration Integration APIs
    @ingroup TC

    All published Team Collaboration Integration APIs will be exposed through this unified interface.

    @{
*/
#ifdef __cplusplus
extern "C"
{
#endif

    /**
       Posts to the configured Slack Workspace and channel as a system level user (chatbot).
       
       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#SIS0_internal_error_posting_to_social if an internal error has occurred.
       <li>#SIS0_undefined_sis_url if the environment variable SIS is undefined.
       <li>#SIS0_undefined_channel if the channel parameter is undefined or empty.
       <li>#SIS0_undefined_id if the workspace_id parameter is undefined or empty.
       <li>#SIS0_undefined_message if the message parameter is undefined or empty.
       <li>#SIS0_unable_to_generate_hmac if the HMAC cannot be generated.
       <li>#SIS0_undefined_tc_zeus_access_key_id if the TC_ZEUS_ACCESS_KEY_ID environment variable is undefined.
       <li>#SIS0_undefined_tc_zeus_access_password_file if the TC_ZEUS_ACCESS_PASSWORD_FILE environment variable is undefined.
       <li>#SIS0_error_returned_from_tci if the TCI (Team Collaboration Integration) micrservice encounters any errors.
       </ul>
    */
    extern SIS0SOCIALINT_API int SIS0_post_to_slack(
        const char* workspace_id,         /**< (I) The Slack workspace ID as configured in the Team Collaboration Integration microservice. */
        const char* channel,             /**< (I) The Slack channel to post to. */
        const char* message              /**< (I) The message to post. */
    );
        
    /**
       Posts to the configured social application and channel as a slack user.
       
       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#SIS0_internal_error_posting_to_social if an internal error has occurred.
       <li>#SIS0_undefined_sis_url if the environment variable @c SIS is undefined.
       <li>#SIS0_undefined_channel if @p channel parameter is undefined or empty.
       <li>#SIS0_undefined_id if @p id parameter is undefined or empty.
       <li>#SIS0_undefined_social_app_type if @p social_app_type parameter is undefined or empty.
       <li>#SIS0_undefined_message if @p message parameter is undefined or empty.
       <li>#SIS0_unable_to_generate_hmac if the hash message authentication code cannot be generated.
       <li>#SIS0_undefined_tc_zeus_access_key_id if the @c TC_ZEUS_ACCESS_KEY_ID environment variable is undefined.
       <li>#SIS0_undefined_tc_zeus_access_password_file if the @c TC_ZEUS_ACCESS_PASSWORD_FILE environment variable is undefined.
       <li>#SIS0_error_returned_from_tci if the TCI (Team Collaboration Integration) micrservice encounters any errors.
       </ul>
    */
    extern SIS0SOCIALINT_API int SIS0_post_to_social(
        const char* id,                  /**< (I) The social integration ID as configured in the Team Collaboration Integration microservice. */
        const char* social_app_type,       /**< (I) The social app type to post to, may be "slack" or "msTeams". */
        const char* channel,             /**< (I) The Slack channel to post to. */
        const char* message,             /**< (I) The message to post. */
        const logical as_user            /**< (I) If @c true, it will post as user instead of bot. */
    );    
    
    /**
       Registers the social user in the TCI microservice.
       
       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#SIS0_internal_error_posting_to_social if an internal error has occurred.
       <li>#SIS0_undefined_sis_url if the environment variable @c SIS is undefined.
       <li>#SIS0_undefined_social_app_type if @p social_app_type parameter is undefined or empty.
       <li>#SIS0_undefined_redirect_uri if @p redirect_uri parameter is undefined or empty.
       <li>#SIS0_unable_to_generate_hmac if the hash message authentication code cannot be generated.
       <li>#SIS0_undefined_tc_zeus_access_key_id if the @c TC_ZEUS_ACCESS_KEY_ID environment variable is undefined.
       <li>#SIS0_undefined_tc_zeus_access_password_file if the @c TC_ZEUS_ACCESS_PASSWORD_FILE environment variable is undefined.
       <li>#SIS0_error_returned_from_tci if the TCI (Team Collaboration Integration) micrservice encounters any errors.
       </ul>
    */
    extern SIS0SOCIALINT_API int SIS0_register_social_user(
        const char* social_app_type,     /**< (I) The social app type to post to, may be "slack" or "msTeams". */
        const char* redirect_uri,        /**< (I) The redirect URI which was used to request the token. */
              char** key                 /**< (OF) The key for the newly created social user's record */
    );

    /**
       Retrieves the ID of the applications configured in TCI in JSON format.
       
       The schema for the JSON response is:
       {
         "ids": [{
             "id": "string",
             "displayName": "string",
             "socialAppType": "string",
             "appType": "string",
             "appUserId": "string"
         }]
       }
       
       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#SIS0_internal_error_posting_to_social if an internal error has occurred.
       <li>#SIS0_undefined_sis_url if the environment variable @c SIS is undefined.
       <li>#SIS0_unable_to_generate_hmac if the hash message authentication code cannot be generated.
       <li>#SIS0_undefined_tc_zeus_access_key_id if the @c TC_ZEUS_ACCESS_KEY_ID environment variable is undefined.
       <li>#SIS0_undefined_tc_zeus_access_password_file if the @c TC_ZEUS_ACCESS_PASSWORD_FILE environment variable is undefined.
       <li>#SIS0_error_returned_from_tci if the TCI (Team Collaboration Integration) microservice encounters any errors.
       </ul>
    */
    extern SIS0SOCIALINT_API int SIS0_query_app_ids (
        const char* social_app_type,    /**< (I) The social app type to post to, may be "slack" or "msTeams". (OPTIONAL - If undefined, then all configured application IDs for the user are returned.) */
              char** app_ids            /**< (OF) The IDs of the social applications which are configured in TCI in JSON format.*/
    );
    
    /**
       Deletes configured keys in TCI.
       
       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#SIS0_internal_error_posting_to_social if an internal error has occurred.
       <li>#SIS0_undefined_sis_url if the environment variable @c SIS is undefined.
       <li>#SIS0_undefined_id if @p id parameter is undefined or empty.
       <li>#SIS0_undefined_social_app_type if @p social_app_type parameter is undefined or empty.       
       <li>#SIS0_unable_to_generate_hmac if the hash message authentication code cannot be generated.
       <li>#SIS0_undefined_tc_zeus_access_key_id if the @c TC_ZEUS_ACCESS_KEY_ID environment variable is undefined.
       <li>#SIS0_undefined_tc_zeus_access_password_file if the @c TC_ZEUS_ACCESS_PASSWORD_FILE environment variable is undefined.
       <li>#SIS0_error_returned_from_tci if the TCI (Team Collaboration Integration) microservice encounters any errors.
       </ul>
    */
    extern SIS0SOCIALINT_API int SIS0_delete_keys (
        const char* id,                    /**< (I) The application ID to delete. */
        const char* social_app_type,       /**< (I) The social application type associated with the ID, may be "slack" or "msTeams". */
        const logical uninstall            /**< (I) Whether to uninstall the APP from the social application. */
    );
    
    /**
       Retrieves the specified social app channels from TCI.
       
       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#SIS0_internal_error_posting_to_social if an internal error has occurred.
       <li>#SIS0_undefined_sis_url if the environment variable @c SIS is undefined.
       <li>#SIS0_undefined_id if @p id parameter is undefined or empty.
       <li>#SIS0_undefined_social_app_type if @p social_app_type parameter is undefined or empty.       
       <li>#SIS0_unable_to_generate_hmac if the hash message authentication code cannot be generated.
       <li>#SIS0_undefined_tc_zeus_access_key_id if the @c TC_ZEUS_ACCESS_KEY_ID environment variable is undefined.
       <li>#SIS0_undefined_tc_zeus_access_password_file if the @c TC_ZEUS_ACCESS_PASSWORD_FILE environment variable is undefined.
       <li>#SIS0_error_returned_from_tci if the TCI (Team Collaboration Integration) microservice encounters any errors.
       </ul>
    */
    extern SIS0SOCIALINT_API int SIS0_get_channels (
        const char* id,                    /**< (I) The application ID for which to query channels. */
        const char* social_app_type,       /**< (I) The social application type associated with the ID, may be "slack" or "msTeams". */
              char** channels              /**< (OF) The channels which are configured for TCI in the social applications */
    );    
    
    /**
       Rotates the tokens for the specified social application. 
       <br/>Token rotation is the disposal of the existing token in the TCI microservice and retrieval of a new one from the configured social application.

       @note Some social applications do not support token rotation, in which case the error #SIS0_error_returned_from_tci error would be returned.    
       
       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#SIS0_internal_error_posting_to_social if an internal error has occurred.
       <li>#SIS0_undefined_sis_url if the environment variable @c SIS is undefined.
       <li>#SIS0_undefined_id if @p id parameter is undefined or empty.
       <li>#SIS0_undefined_social_app_type if @p social_app_type parameter is undefined or empty.       
       <li>#SIS0_unable_to_generate_hmac if the hash message authentication code cannot be generated.
       <li>#SIS0_undefined_tc_zeus_access_key_id if the @c TC_ZEUS_ACCESS_KEY_ID environment variable is undefined.
       <li>#SIS0_undefined_tc_zeus_access_password_file if the @c TC_ZEUS_ACCESS_PASSWORD_FILE environment variable is undefined.
       <li>#SIS0_error_returned_from_tci if the TCI (Team Collaboration Integration) microservice encounters any errors.
       </ul>
    */
    extern SIS0SOCIALINT_API int SIS0_rotate_token (
        const char* id,                    /**< (I) The application ID for which to rotate the token. */
        const char* social_app_type        /**< (I) The social application type associated with the ID, may be "slack" or "msTeams". */
    );              
    
#ifdef __cplusplus
}
#endif

/** @} */

#include <sis0socialint/libsis0socialint_undef.h>
#endif

