/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Application Interface errors.

This file contains Error Definitions related to Application Interface module.
*/

/*  */

#ifndef APPINTERFACE_ERRORS_H
#define APPINTERFACE_ERRORS_H

#include <common/emh_const.h>

#include <ai/libai_exports.h>

/**
    @defgroup AI_ERRORS AI Errors
    @ingroup APPINTERFACE
    @{
*/

/** The initialization of the Application Interface application has failed. Please contact your system administrator.*/
#define AI_initialization_failed                   (EMH_AI_error_base + 1)
/** The Transfer Mode "%1$" is not defined.*/
#define AI_no_tm_defined                           (EMH_AI_error_base + 2)
/** The Application Interface "%1$" is locked. Please ensure it is unlocked.*/
#define AI_is_locked                               (EMH_AI_error_base + 3)
/** The Request Object "%1$" does not belong to any Application Interface.*/
#define AI_standalone_request                      (EMH_AI_error_base + 4)
/** The project identifier "%1$" already exists.*/
#define AI_project_id_exist                        (EMH_AI_error_base + 5)
/** A pending "Sync" request exists.*/
#define AI_has_pending_sync                        (EMH_AI_error_base + 6)
/** A pending "Publish" request exists.*/
#define AI_has_pending_publish                     (EMH_AI_error_base + 7)
/** The Request Object "%1$" cannot be processed because there might be a pending request. The "AI_request_no_dependancy" preference can be set to "true" to avoid this error.*/
#define AI_can_not_process_request                 (EMH_AI_error_base + 8)
/**The file to be associated with Request Object "%1$", which is being processed, cannot be uploaded.*/
#define AI_fail_to_put_file                        (EMH_AI_error_base + 9)
/** The Application Interface of type "%1$" already exists.*/
#define AI_duplicate_type_name                     (EMH_AI_error_base + 10)
/** A "Sync" request cannot be added because a pending "Publish" request exists.*/
#define AI_can_not_add_sync                        (EMH_AI_error_base + 11)
/** A "Publish" request cannot be added because a pending "Sync" request exists.*/
#define AI_can_not_add_publish                     (EMH_AI_error_base + 12)
/** No Application Interface to be processed is selected.*/
#define AI_epm_no_ai                               (EMH_AI_error_base + 13)
/** No Request Object to be processed is selected.*/
#define AI_epm_no_req                              (EMH_AI_error_base + 14)
/** The base references on the Application Interface "%1$" could not be stored. Please check the Teamcenter syslog for error conditions.*/
#define AI_store_baseref_failed                    (EMH_AI_error_base + 15)
/** The data recorded during the deletion of a Master record object cannot be rolled-back. Please check the Teamcenter syslog for error conditions.*/
#define AI_rollback_master_rec_failed              (EMH_AI_error_base + 16)
/** The Master record object could not be saved. Please check the Teamcenter syslog for error conditions.*/
#define AI_save_master_rec_failed                  (EMH_AI_error_base + 17)
/** The type of selected object is not supported for Tool design export. The supported types are: MEStudy, CCObject.*/
#define AI_unsupported_obj_for_tdp_export          (EMH_AI_error_base + 18)
/** The Item Revision could not be loaded. This could be due to permission issue on the revision or configuration of the BOM structure.*/
#define AI_cannot_load_revision_for_tdp_export     (EMH_AI_error_base + 19)
/** The following Request Objects are rejected: %1$.*/
#define AI_rejected_rec_exist                      (EMH_AI_error_base + 20)
/** The following rejected Work Packages are blocking dependent Work Packages: "%1$". Dependent Work Packages cannot be processed until all rejection issues are resolved.*/
#define AI_pending_req_held_by_rejected_req        (EMH_AI_error_base + 21)
/** Searches by Work Package state are not allowed.*/
#define AI_search_by_state_not_allowed             (EMH_AI_error_base + 22)
/** Searches by Work Package type are not allowed.*/
#define AI_search_by_type_not_allowed              (EMH_AI_error_base + 23)
/** The reference to the Application "%1$" (label "%2$" and version "%3$") is invalid.*/
#define AI_invalid_app_ref                         (EMH_AI_error_base + 24)
/** At least one Application name must be provided.*/
#define AI_empty_app_name                          (EMH_AI_error_base + 25)
/** At least one Application reference must be provided.*/
#define AI_empty_app_ref                           (EMH_AI_error_base + 26)

/** @} */

#include <ai/libai_undef.h>
#endif
