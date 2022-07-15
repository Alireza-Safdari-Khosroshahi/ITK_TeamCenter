/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Define error codes used for the ECM in Teamcenter Engineering
*/

/*  */

#ifndef ECM_ERRORS_H
#define ECM_ERRORS_H

#include <common/emh_const.h>
#include <ecm/libecm_exports.h>

/**
    @defgroup ECM_ERRORS Errors
    @ingroup ECM
    @{
*/

#define ECM_ERROR_BASE                      EMH_ECM_error_base

/** Internal error in ECM module %1$. */
#define ECM_internal_error                 (ECM_ERROR_BASE +1)

/** Cannot create change type %1$. */
#define ECM_unable_to_create_type          (ECM_ERROR_BASE +2)

/** Cannot append formtypes list for change type. */
#define ECM_unable_to_add_formtype         (ECM_ERROR_BASE +3)

/** Cannot append process template list for change type. */
#define ECM_unable_to_add_process          (ECM_ERROR_BASE +4)

/** Cannot modify change type name %1$. */
#define ECM_unable_to_set_typename         (ECM_ERROR_BASE +5)

/** Cannot get change type name. */
#define ECM_unable_to_get_typename         (ECM_ERROR_BASE +6)

/** Cannot set ID format. */
#define ECM_unable_to_set_idformat         (ECM_ERROR_BASE +7)

/** Cannot get ID format. */
#define ECM_unable_to_get_idformat         (ECM_ERROR_BASE +8)

/** Cannot set Revision Id format. */
#define ECM_unable_to_set_revidformat      (ECM_ERROR_BASE +9)

/** Cannot get Revision format. */
#define ECM_unable_to_get_revidformat      (ECM_ERROR_BASE +10)

/** Cannot save change type data. */
#define ECM_unable_to_save_type            (ECM_ERROR_BASE +11)

/** Cannot delete change type. */
#define ECM_unable_to_delete_type          (ECM_ERROR_BASE +12)

/** Cannot get Supersedure. */
#define ECM_unable_to_get_supercedure      (ECM_ERROR_BASE +13)

/** Cannot get Problem assembly. */
#define ECM_unable_to_get_ec               (ECM_ERROR_BASE +14)

/** Cannot get EC Revision. */
#define ECM_unable_to_get_problem_bvr      (ECM_ERROR_BASE +15)

/** Invalid Affected Item : %1$. */
#define ECM_invalid_affected_item          (ECM_ERROR_BASE +16)

/** Invalid argument %1$ in handler %2$. */
#define ECM_invalid_argument_in_handler    (ECM_ERROR_BASE +17)

/** Affected Item %1$ not released. */
#define ECM_affected_item_not_released     (ECM_ERROR_BASE +18)

/** Affected Item %1$ neither released nor target. */
#define ECM_item_not_target_or_released    (ECM_ERROR_BASE +19)

/** EC Revision not attached as target. */
#define ECM_ec_not_attached                (ECM_ERROR_BASE +20)

/** %1$ not a problem item. */
#define ECM_not_problem_item               (ECM_ERROR_BASE +21)

/** Affected Item relation type %1$ not found. */
#define ECM_affected_item_reln_not_found   (ECM_ERROR_BASE +22)

/** Affected to Problem relation type %1$ not found. */
#define ECM_aff_to_prob_reln_not_found     (ECM_ERROR_BASE +23)

/** Cannot remove formtype. */
#define ECM_unable_to_remove_formtype      (ECM_ERROR_BASE +24)

/** Cannot remove process template. */
#define ECM_unable_to_remove_process       (ECM_ERROR_BASE +25)

/** Cannot create duplicate change type %1$. */
#define ECM_duplicate_change_type          (ECM_ERROR_BASE +26)

/** Process template %1$ is not valid for EC type. */
#define EC_invalid_process_template        (ECM_ERROR_BASE +27)

/** %1$ already pasted as EC Relation. */
#define ECM_duplicate_item_pasted          (ECM_ERROR_BASE +28)

/** Unable to get the Revision Rule. */
#define ECM_unable_to_get_revrule          (ECM_ERROR_BASE +29)

/** Unable to get Pure Adds and Cancels. */
#define ECM_unable_to_get_pure_addscancels (ECM_ERROR_BASE +30)

/** Invalid Change Type %1$ in ECM_note_types_to_track site preference. */
#define ECM_wrong_change_type_in_pref      (ECM_ERROR_BASE +31)

/** Invalid Note Type %1$ mentioned for Change Type %2$ in ECM_note_types_to_track site preference. */
#define ECM_invalid_notetype_in_pref       (ECM_ERROR_BASE +32)

/** Invalid BomChange Form Property %1$ entered in site preference %2$. */
#define ECM_invalid_bomchange_form_prop    (ECM_ERROR_BASE +33)

/** Entry not found for Change Type %1$ in ECM_note_types_to_track site preference. */
#define ECM_invalid_notchange_pref         (ECM_ERROR_BASE +34)

/** Invalid value  %1$ for argument %2$. */
#define ECM_invalid_type_passed_as_arg     (ECM_ERROR_BASE +35)

/** Invalid argument value. */
#define ECM_invalid_argument_value         (ECM_ERROR_BASE +36)  /* 72036 */

/** Null date value in the property %1$. */
#define ECM_null_date_in_property          (ECM_ERROR_BASE +37)  /* 72037 */

/** Affected Item %1$ has no %2$ effectivity defined. */
#define ECM_aff_item_has_no_effectivity    (ECM_ERROR_BASE +38)  /* 72038 */

/** Failed to create snapshot for the selected EngChange Revision. */
#define ECM_failed_to_create_snapshot      (ECM_ERROR_BASE +39)  /* 72039 */

/** Mismatch of affected item type. */
#define ECM_affected_item_mismatch         (ECM_ERROR_BASE +40)  /* 72040 */

/** Invalid Stylesheet file %1$. Either the file does not exist or user has no read access. */
#define ECM_invalid_stylesheet_file        (ECM_ERROR_BASE +41)  /* 72041 */

/** Failed to apply stylesheet %1$. */
#define ECM_failed_to_apply_stylesheet     (ECM_ERROR_BASE +42)

/** Invalid engineering change revision. */
#define ECM_invalid_engg_change_rev        (ECM_ERROR_BASE +43)

/** @} */
#include <ecm/libecm_undef.h>
#endif
