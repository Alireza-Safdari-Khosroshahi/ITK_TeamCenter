
/*==================================================================================================

                    Copyright (c) 2004,2007 Electronic Data Systems Corporation
                             Unpublished - All rights reserved

====================================================================================================
File description:  gms_itk.h

    This file contains the  Global Multisite Distribution ITK interface
    prototypes and typedefs for the ITK interface

====================================================================================================
   Date      Name                    Description of Change
08-Nov-2006  Yatish Patel            initial
$HISTORY$
==================================================================================================*/

#ifndef GMS_PUBLICATION_ITK_HHH
#define GMS_PUBLICATION_ITK_HHH

#include <tc/tc_startup.h>
#include <tccore/aom.h>

#ifdef __cplusplus
extern "C" {
#endif

#include <publication/libpublication_exports.h>

/**
   @defgroup GMS_PUBLICATION Global Multi Site Publication
   @ingroup GMS
   @{
*/

/**
   Launches a remote export.
   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#GMS_offline_cannot_transfer_ownership if the site ownership cannot be changed in the offline transfer mode.
   <li>#PIE_transferoptionset_not_retrieved if the TransferOptionSets cannot be retrieved from the database.
   <li>#GMS_fail_to_login_to_global_services if an error has occurred while logging into Global Services.
   </ul>
*/
extern PUBLICATION_API int GMS_request_remote_export (
                          int        n_items,               /**< (I) Number of objects to be exported.*/
                          tag_t *    objects,               /**< (I) n_items Objects to be exported.
                                                            <br/> If an invalid object is provided, it is ignored.*/
                          int        n_sites,               /**< (I) The number of sites to which objects are to be exported.
                                                            <br/> If value of n_sites is 0, it does not launches a remote export.*/
                          tag_t *    target_sites,          /**< (I) n_sites Sites to which objects are to be exported.
                                                            <br/> If an invalid site is provided, it is ignored.*/
                          char  *    reason,                /**< (I) The Reason for export. This can be a null pointer.*/
                          tag_t      option_set,            /**< (I) The object of type "TransferOptionSet".*/
                          int        n_options,             /**< (I) The number of transfer options whose values need to different than in "TransferOptionSet".*/
                          char **    option_names,          /**< (I) n_options Option names.
                                                            <br/> If same options given as in "TransferOptionSet" then values of options will be override.
                                                            <br/>Some of the valid values are:
                                                            <ul>
                                                            <li>opt_do_struct       (True/False)</li>
                                                            <li>opt_rev_select      (latestRevisionOnly/allReleasedRevisionsOnly/ etc)</li>
                                                            <li>opt_entire_bom      (True/False)</li>
                                                            </ul>
                                                            <br/>For the extensive list, please refer to the documentation of the PLM XML Export Import administration tool. */
                          char **    option_values,         /**< (I) n_options Option values.
                                                             <br/>If an invalid value is provided, the default value of the option is used.*/
                          int        n_session_options,     /**< (I) The number of session options.*/
                          char **    session_option_names,  /**< (I) n_session_options Session option names
                                                            <br/> If same options given as in "TransferOptionSet" provided, the values of session options are overrided.
                                                            <br/>Some of the valid values are:
                                                            <ul>
                                                            <li>modified_objects_only        (True/False)</li>
                                                            <li>continue_on_error            (True/False)</li>
                                                            <li>unmanaged                    (True/False)</li>
                                                            <li>dry_run                      (True/False)</li>
                                                            <li>transfer_site_ownership      (True/False)</li>
                                                            </ul>
                                                            <br/>For the extensive list, please refer to the documentation of the PLM XML Export Import administration tool. */
                          char **    session_option_values, /**< (I) n_session_options Session option values.
                                                            <br/>If an invalid value is provided, the default value of the session option is used.*/
                          int        priority,              /**< (I) Priority to schedule the call of export.
                                                            <br/>Some of the valid values are:
                                                            <ul>
                                                            <li>PRIORITY_IMMEDIATE (-1)       </li>
                                                            <li>PRIORITY_OFFHOURS  (-2)       </li>
                                                            </ul>
                                                            <br/> If an invalid value is provided, the default value PRIORITY_OFFHOURS is used.*/
                          logical    email_notification,    /**< (I) The boolean value indicates that should sent email or not.*/
                          int        n_email_addrs,         /**< (I) Number of email recipients.
                                                            <br> If n_email_addresses is set to a value of -1, this will get the email address from the Person object of the logged in user.*/
                          char **    email_addrs,           /**< (I) n_email_addrs Email addresses.
                                                            <br/> If an invalid address is provided, no mail is sent to this recipient.*/
                          int   *    n_msg_ids,             /**< (O) The number of message IDs.*/
                          char ***   msg_ids                /**< (OF) n_msg_ids Message IDs that need to passed to Global Services to enable the end user to identify and monitor a remote import or export request.
                                                            <br/> The format of the generated a message ID is as : &lt;object id&gt; [&lt;remote_site&gt;] &lt;time stamp&gt; */
                        );

/**
For Remote Export in GMS environment
Parameters:
option_names (option_values)
    Example:
    opt_do_struct       (True/False),
    opt_rev_select      (latestRevisionOnly/allReleasedRevisionsOnly/ etc)
    opt_entire_bom      (True/False)
for extensive list, please see PLM XML Export Import Administration Tool

session_option_names(session_option_values) are following
    modified_objects_only   (True/False)
    continue_on_error       (True/False)
    dry_run                 (True/False)
    offline                 (True/False)
    transfer_site_ownership (True/False)
*/

/**
   Sends SOAP request to to Global Services framework for importing object(s).

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#PIE_transferoptionset_not_retrieved if transfer option set is invalid.
   <li>#ITK_internal_error if objects are not valid
   <li>EIM_get_site_id_failed (#EMH_EIM_error_base + 11) if error occurs while retrieving local site ID.
   </ul>
*/
extern PUBLICATION_API int GMS_request_remote_import(
                          int        n_items,                /**< (I) Number of objects to import */
                          tag_t *    n_objects,              /**< (I) Objects to import  */
                          int   *    owning_site_ids,        /**< (I) Owning site ID for the objects */
                          char  *    reason,                 /**< (I) Reason for import */
                          tag_t      option_set_tag,         /**< (I) Transfer option set to be used during import */
                          int        n_options,              /**< (I) Number of options */
                          char **    option_names,           /**< (I) Option names  */
                          char **    option_values,          /**< (I) Option values  */
                          int        n_session_options,      /**< (I) Number of session options */
                          char **    session_option_names,   /**< (I) Session option names */
                          char **    session_option_values,  /**< (I) Session option values  */
                          int        priority,               /**< (I) Priority of the request. For immediate processing value is -1, for offline hours value is -2 */
                          logical    email_notification,     /**< (I) True/False. If True, e-mail notification is sent */
                          int        n_email_addrs,          /**< (I) Number of users to whom e-mail notification is sent */
                          char **    email_addrs,            /**< (I) Specifies e-mail address to which ownership change notification is sent */
                          int   *    n_msg_ids,              /**< (O) Number of message IDs */
                          char ***   msg_id                  /**< (OF) n_msg_ids Array of message ID. The array is packed, which means the memory is deallocated by calling #MEM_free on the container only. */
                        );


/**
   Sends SOAP request to Global Services framework for checking if replicas are out of date.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>EIM_get_site_id_failed (#EMH_EIM_error_base + 11) if error occurs while retrieving local site ID.
   </ul>
*/
extern PUBLICATION_API int GMS_check_replica_sync_state(
                          int                  n_items,     /**< (I) Number of replica objects for which sync status needs to be checked */
                          tag_t *              n_objects,   /**< (I) Replica objects for which synchronization status needs to be checked */
                          AOM_sync_type_t      sync_type,   /**< (I) Synchronization types. Valid values are #OBJECT_SYNC, #COMPONENT_SYNC, #ASSEMBLY_SYNC */
                          AOM_sync_state_t **  sync_state,  /**< (OF) n_items Synchronization states per object */
                          int **               ifails       /**< (OF) n_items Errors if any per object */
                        );


/**
   Sends SOAP notification to owning site when replica gets deleted via Global Services framework.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#GMS_fail_to_login_to_global_services if login to global services fails.
   <li>#LM_GMS_DELETE_REPLICA if global services URL is not found.
   </ul>
*/
extern PUBLICATION_API int GMS_send_replica_deletion_notification(
    tag_t owning_site,                     /**< (I)  Owning site to which replica deletion notification is sent */
    int n_replica_gs_identity_strings,     /**< (I)  Number of replica objects that got deleted  */
    char** replica_gs_identity_strings,    /**< (I)  GSIdentity strings for replica objects */
    int n_stub_gs_identity_strings,        /**< (I)  Number of stubbed objects that got deleted  */
    char** stub_gs_identity_strings        /**< (I)  GSIdentity strings for stubbed objects */
);


/**
   For Remote Export in GMS environment
   Parameters:
   option_names (option_values)
   Example:
   opt_do_struct       (True/False),
    opt_rev_select      (latestRevisionOnly/allReleasedRevisionsOnly/ etc)
    opt_entire_bom      (True/False)
for extensive list, please see PLM XML Export Import Administration Tool

session_option_names(session_option_values) are following
    modified_objects_only   (True/False)
    continue_on_error       (True/False)
    dry_run                 (True/False)
    offline                 (True/False)
    transfer_site_ownership (True/False)
*/

/**
   Sends SOAP request to Global Services framework for importing offline package(briefcase).

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#GMS_fail_to_login_to_global_services if login to global services fails.
   <li>#GMS_fail_to_invoke_global_services_method if import request to global services fails.
   </ul>
*/
extern PUBLICATION_API int GMS_request_import_from_offline_package(
        const char *     offline_package_file_path,  /**< (I) Path where offline package that needs to be imported resides */
        tag_t            option_set_tag,             /**< (I) Transfer option set to be used during import */
        int              n_options,                  /**< (I) Number of options */
        const char **    option_names,               /**< (I) Option names */
        const char **    option_values,              /**< (I) Option values */
        int              n_session_options,          /**< (I) Number of session options */
        const char **    session_option_names,       /**< (I) Session option names */
        const char **    session_option_values,      /**< (I) Session option values */
        int              priority,                   /**< (I) Priority of the request. For immediate processing value is -1, for offline hours value is -2 */
        logical          email_notification,         /**< (I) True/False. If True, e-mail notification is sent */
        int              n_email_addrs,              /**< (I) Number of users to whom e-mail notification is sent */
        const char **    email_addrs,                /**< (I) Specifies e-mail address to which ownership change notification is sent */
        char **          msg_id                      /**< (OF) Message ID of the request */
    );



/**
   Sends ownership transfer SOAP request to Global Services framework.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#GMS_fail_to_login_to_global_services if login to global services fails
   <li>#ITK_internal_error if site is invalid
   </ul>
*/
extern PUBLICATION_API int GMS_request_ownership_transfer_using_date_range(
    tag_t      change_ownership_to_site, /**< (I) Target site to which ownership needs to be transferred */
    logical    dry_run,                  /**< (I) True/False. If True, generates report of objects that are candidate for ownership transfer */
    logical    is_source_site_extinct,   /**< (I) True/False. If True, generates list of objects which are owned by source site */
    logical    email_notification,       /**< (I) True/False. If True, e-mail notification is sent */
    int        n_email_addrs,            /**< (I) Number of users to whom e-mail notification is sent */
    char **    email_addrs,              /**< (I) Specifies e-mail address to which ownership change notification is sent */
    const char *start_date,              /**< (I) This option is valid only in case of dry run option. This generates a report between startDate and endDate. DATE FORMAT is MM/DD/YYYY */
    const char *end_date,                /**< (I) This option is valid only in case of dry run option. This generates a report between startDate and endDate. DATE FORMAT is MM/DD/YYYY */
    char **    msg_id                    /**< (OF) Message ID of the request */
  );

/** @} */
#ifdef __cplusplus
}
#endif

#include <publication/libpublication_undef.h>
#endif

