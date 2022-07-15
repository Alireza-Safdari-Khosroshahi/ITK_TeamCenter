/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Error codes associated with Workspace Objects.
*/

/*  */

#ifndef WORKSPACEOBJECT_ERRORS_H
#define WORKSPACEOBJECT_ERRORS_H

#include <common/emh_const.h>
#include <tccore/libtccore_exports.h>

/**
    @defgroup WSO_ERRORS Errors
    @ingroup WSO
    @{
*/

#define WSO_NoWriteAccess                   (EMH_WSO_error_base + 1)
#define WSO_NoReadAccess                 (EMH_WSO_error_base + 2)
#define WSO_WriteFailure                 (EMH_WSO_error_base + 3)
#define WSO_SaveBeforeChange               (EMH_WSO_error_base + 4)
#define WSO_Name32                        (EMH_WSO_error_base + 5)
#define WSO_Description240                  (EMH_WSO_error_base + 6)
#define WSO_ModifyFrozenWSO                 (EMH_WSO_error_base + 7)
#define WSO_DestroyFrozenWSO             (EMH_WSO_error_base + 8)
#define WSO_DestroyAcess                  (EMH_WSO_error_base + 9)
#define WSO_FreezeAcess                  (EMH_WSO_error_base + 10)
#define WSO_UnFreezeAcess                  (EMH_WSO_error_base + 11)
#define WSO_Archive                      (EMH_WSO_error_base + 12)
#define WSO_Restore                       (EMH_WSO_error_base + 13)
#define WSO_WriteLockFail                   (EMH_WSO_error_base + 14)
#define WSO_ReadLockFail                    (EMH_WSO_error_base + 15)
#define WSO_GetInfo                       (EMH_WSO_error_base + 16)
#define WSO_NeedWriteLock                   (EMH_WSO_error_base + 17)

/**
    Must freeze WSO first before giving WSO a ReleaseStatus
*/
#define WSO_FreezeBeforeAddStatus         (EMH_WSO_error_base + 18)

/**
    Cannot unfreeze a WSO which has a ReleaseStatus
*/
#define WSO_HasStatusCannotUnfreeze         (EMH_WSO_error_base + 19)

#define WSO_NoCopyAccess                 (EMH_WSO_error_base + 20)
#define WSO_NoAccess                  (EMH_WSO_error_base + 21)
#define WSO_NoFallbackAccess              (EMH_WSO_error_base + 22)
#define WSO_NoDestination                 (EMH_WSO_error_base + 23)
#define WSO_not_archived                 (EMH_WSO_error_base + 24)
#define WSO_already_archived                (EMH_WSO_error_base + 25)
/**
    The object "%1$" could not be loaded or refreshed. Please refer to the preceding errors in this error stack for more information.
*/
#define WSO_no_refresh                      (EMH_WSO_error_base + 26)
#define WSO_no_referencers                  (EMH_WSO_error_base + 27)
#define WSO_internal_error                  (EMH_WSO_error_base + 28)
#define WSO_no_based_on_rtype               (EMH_WSO_error_base + 29)
#define WSO_based_on_invalid_op             (EMH_WSO_error_base + 30)
#define WSO_wr_invalid_depth                (EMH_WSO_error_base + 31)

/**
    Cannot destroy the master copy of a replicated object
*/
#define WSO_no_destroy_exported_wso         (EMH_WSO_error_base + 32)

#define WSO_unable_to_export                (EMH_WSO_error_base + 33)

/**
    Cannot touch a released object
*/
#define WSO_no_touch_released_wso           (EMH_WSO_error_base + 34)

/**
    Cannot destroy a published object
*/
#define WSO_no_destroy_published_wso        (EMH_WSO_error_base + 35)

#define WSO_cant_get_type_of_status         (EMH_WSO_error_base + 36)

/**
    @name Effectivity Errors
    @{
*/
#define WSOM_bad_date_format                (EMH_WSO_error_base + 50)
#define WSOM_bad_unit_format                (EMH_WSO_error_base + 51)

#define WSOM_bad_effectivity_text_format    (EMH_WSO_error_base + 53)
#define WSOM_cannot_add_unit_to_range       (EMH_WSO_error_base + 54)
#define WSOM_range_overlap                  (EMH_WSO_error_base + 55)
#define WSOM_end_smaller_than_start         (EMH_WSO_error_base + 56)
#define WSOM_cannot_add_date_to_range       (EMH_WSO_error_base + 57)
#define WSOM_closed_status_open_range       (EMH_WSO_error_base + 58)
#define WSOM_open_status_closed_range       (EMH_WSO_error_base + 59)
#define WSOM_cannot_edit_protected          (EMH_WSO_error_base + 60)
#define WSOM_no_mixed_range_types           (EMH_WSO_error_base + 61)
#define WSOM_units_and_no_end_item          (EMH_WSO_error_base + 62)
#define WSOM_not_in_v7_effectivity_mode     (EMH_WSO_error_base + 63)
/**
        The operation has failed, because the Effectivity of ID "%1$" is a remote object owned by the site "%2$".
*/
#define WSOM_eff_is_remote_object           (EMH_WSO_error_base + 64)

#define WSOM_invalid_range                  (EMH_WSO_error_base + 65)
#define WSOM_cant_save_eff_with_no_rs       (EMH_WSO_error_base + 66)
#define WSOM_eff_with_more_than_one_rs      (EMH_WSO_error_base + 67)
#define WSOM_eff_already_contains_rs        (EMH_WSO_error_base + 68)
#define WSOM_cannot_destroy_eff             (EMH_WSO_error_base + 69)
#define WSOM_out_of_bounds_range_index      (EMH_WSO_error_base + 70)
#define WSOM_cannot_use_ask_status          (EMH_WSO_error_base + 71)
#define WSOM_invalid_eff                    (EMH_WSO_error_base + 72)
#define WSOM_eff_range_not_supplied         (EMH_WSO_error_base + 73)
/** @} */

/**
    @name Where Used Errors
    @{
*/
#define WSO_where_used_invalid_object       (EMH_WSO_error_base + 74)
/** @} */

/**
    @name EffectivityMode Errors
    @{
*/
#define WSOM_new_effs_already_exist         (EMH_WSO_error_base + 80)
/** @} */

/**
    @name Sequence Errors
    @{
*/
#define WSOM_make_immune_not_available             (EMH_WSO_error_base + 90)
#define WSOM_remove_immunity_not_available         (EMH_WSO_error_base + 91)
#define WSOM_unable_to_create_checkout_copy        (EMH_WSO_error_base + 92)
#define WSOM_unable_to_restore_from_checkout_copy  (EMH_WSO_error_base + 93)
/** @} */

/**
    @name EffectivityGroup Errors
    @{
*/
#define WSOM_invalid_effectivity_group_revision    (EMH_WSO_error_base + 94)
/** @} */

/**
    @name Work Space Commercial And Government Entity code related errors
    @{
*/
#define WSO_invalid_company_cage_code               (EMH_WSO_error_base  + 95)
/** @} */

/**
    @name Promote Private Edit error
    @{
*/
#define WSO_promote_private_edit_failed             (EMH_WSO_error_base + 96)
/** @} */

/**
    @name Validate for promote error
    @{
*/
#define WSO_validate_promote_failed                (EMH_WSO_error_base  + 97)
/** @} */

/**
    @name cparam configuration error
    @{
*/
#define WSO_cparam_not_private_latest              (EMH_WSO_error_base  + 98)
/** @} */

/**
    @name Thread errors
    @{
*/

/**
* The thread type is not configured for the Business Object "%1$".
*/
#define WSO_thread_not_configured                  (EMH_WSO_error_base + 99)

/**
* The provided CreateInput descriptor for the thread is of type "%1$". An object of type, or subtype of, "%2$" is expected.
*/
#define WSO_thread_not_valid_type                  (EMH_WSO_error_base + 100)


/**
  The current user does not have permission to delete "%1$".
*/
#define WSO_lock_for_delete_failed                 (EMH_WSO_error_base + 101)

/** @} */


/** @} */

#include <tccore/libtccore_undef.h>
#endif
