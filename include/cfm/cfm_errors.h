/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    The error codes for CFM
*/

/*  */

#ifndef CFM_ERRORS_H
#define CFM_ERRORS_H

#include <common/emh_const.h>
#include <common/tc_deprecation_macros.h>

/**
    @defgroup CFM_ERRORS Errors
    @ingroup CFM
    @{
*/

#define CFM_error_base                   EMH_CFM_error_base
#define CFM_ok                           0

/**
    @name General error codes
    @{
*/
#define CFM_internal_error               (CFM_error_base + 1)
#define CFM_module_not_initialized       (CFM_error_base + 3)
#define CFM_has_been_deleted             (CFM_error_base + 4)

#define CFM_invalid_name                 (CFM_error_base + 9)
#define CFM_invalid_tag                  (CFM_error_base + 10)

#define CFM_value_not_found              (CFM_error_base + 15)
#define CFM_index_out_of_range           (CFM_error_base + 16)

#define CFM_pom_not_started              (CFM_error_base + 20)
#define CFM_out_of_memory                (CFM_error_base + 21)
#define CFM_timeout                      (CFM_error_base + 22)
#define CFM_database_full                (CFM_error_base + 23)
#define CFM_access_denied                (CFM_error_base + 24)
#define CFM_db_prevents_rollback         (CFM_error_base + 25)
#define CFM_inst_references_unsaved      (CFM_error_base + 26)
#define CFM_class_is_uninstantiable      (CFM_error_base + 27)
#define CFM_inst_locked                  (CFM_error_base + 28)
#define CFM_inst_referenced              (CFM_error_base + 29)
#define CFM_inst_selected                (CFM_error_base + 30)
/** @} */

/**
    @name New Rev Rules Error Codes
    @{
*/
#define CFM_add_child_to_non_group_entry (CFM_error_base + 40)
#define CFM_cant_find_rev_rule           (CFM_error_base + 41)
#define CFM_duplicate_rev_rule           (CFM_error_base + 42)
#define CFM_entry_not_in_rule            (CFM_error_base + 43)
#define CFM_entry_already_in_rule        (CFM_error_base + 44)
#define CFM_entry_not_in_group           (CFM_error_base + 45)
#define CFM_entry_already_in_group       (CFM_error_base + 46)
#define CFM_insufficient_privilege       (CFM_error_base + 47)
#define CFM_invalid_entry_type           (CFM_error_base + 48)
#define CFM_invalid_status_entry_type    (CFM_error_base + 49)
#define CFM_rule_entry_mismatch          (CFM_error_base + 50)
#define CFM_old_cfm_function             (CFM_error_base + 51)
#define CFM_duplicate_date_entry         (CFM_error_base + 52)
#define CFM_duplicate_unitno_entry       (CFM_error_base + 53)
#define CFM_entry_is_not_groupable       (CFM_error_base + 54)
#define CFM_null_override_folder         (CFM_error_base + 55)
#define CFM_invalid_date                 (CFM_error_base + 56)
#define CFM_invalid_unit_number          (CFM_error_base + 57)
#define CFM_invalid_status_date_combo    (CFM_error_base + 58)
#define CFM_no_default_rule_pref         (CFM_error_base + 59)
#define CFM_cant_move_entry_in_group     (CFM_error_base + 60)
#define CFM_invalid_status_type          (CFM_error_base + 61)
#define CFM_invalid_latest_entry_type    (CFM_error_base + 62)
/** @} */

/**
    @name Configuration errors
    @{
*/
#define CFM_invalid_configuration_object (CFM_error_base + 65)
#define CFM_override_list_deleted        (CFM_error_base + 66)
/** @} */

/**
    @name Effectivity errors
    @{
*/
#define CFM_date_not_installed           (CFM_error_base + 70)
#define CFM_date_not_initialised         (CFM_error_base + 71)
#define CFM_bad_date_info_tag            (CFM_error_base + 72)
#define CFM_no_such_date_info            (CFM_error_base + 73)
#define CFM_invalid_range                (CFM_error_base + 74)
#define CFM_date_attr_null               (CFM_error_base + 75)
#define CFM_date_attr_empty              (CFM_error_base + 76)
#define CFM_date_internal_error          (CFM_error_base + 77)
#define CFM_cant_edit_root_line          (CFM_error_base + 78)
#define CFM_duplicate_effectivity_name   (CFM_error_base + 79)
/** @} */

/**
    @name v7 Effectivity integration
    @{
*/
#define CFM_duplicate_end_item_entry     (CFM_error_base + 80)
#define CFM_no_rev_for_end_item          (CFM_error_base + 81)
#define CFM_no_rev_for_unitno            (CFM_error_base + 82)
#define CFM_no_rev_for_date              (CFM_error_base + 83)
#define CFM_no_rev_for_qualification     (CFM_error_base + 84)
#define CFM_no_rev_for_status            (CFM_error_base + 85)
/** @} */

/*
 * @deprecated #CFM_multiple_revs_one_status deprecated in Teamcenter 13.1.
 */
#define CFM_multiple_revs_one_status     (CFM_error_base + 86)
TC_DEPRECATED_PREPROCESSOR( "13.1", CFM_multiple_revs_one_status, "" )

#define CFM_intent_needs_name            (CFM_error_base + 87)
#define CFM_entry_incompatible_w_group   (CFM_error_base + 88)

/** The Branch Entry cannot be added to the Revision Rule "%1$", because it already has one. */
#define CFM_duplicate_branch_entry                              (CFM_error_base + 89)

/** A Branch with name "%1$" already exists. A Branch name must be unique. */
#define CFM_duplicate_branch_name                               (CFM_error_base + 90)

/** The Branch "%1$" is inactive. Item Revisions or other Branches cannot be associated to a Branch in inactive state. */
#define CFM_inactive_branch                                     (CFM_error_base + 91)

/** The Branch "%1$" cannot be deleted, because it is associated to other Branch objects. Please remove all Branch relations before deleting the object. */
#define CFM_branch_has_branch_relation                          (CFM_error_base + 92)

/** The operation has failed, because only Item Revisions or other Branches can be associated to the Branch "%1$" as a secondary objects. */
#define CFM_invalid_type_for_branch_relation                    (CFM_error_base + 93)

/** The operation has failed, because Branch Content relation supports only Item Revisions as a secondary objects associated to the Branch "%1$". */
#define CFM_invalid_type_for_branch_content                     (CFM_error_base + 94)

/** The operation has failed, because it would create a circular Branch hierarchy. */
#define CFM_circular_branch                                     (CFM_error_base + 95)

/** The end date could not be set to the value "%1$", because it is earlier than the start date (%2$).*/
#define CFM_invalid_branch_end_date                             (CFM_error_base + 96)

/** The operation has failed, because this associated to the Branch "%1$" as a secondary objects will cause an invalid multiparent scenario. */
#define CFM_invalid_multiparent_branch_relation                 (CFM_error_base + 97)

/** The operation has failed, because the selected Branch "%1$" has a secondary Branch "%2$" with multiple parents. Deletion of this Branch relation would cause an invalid multi-parent scenario. */
#define CFM_invalid_cut_for_multiparent_scenario                (CFM_error_base + 98)

/** The provided Revision Rule "%1$" is not supported, because it should contain the "Has Status" or the "Any Status". */
#define CFM_rev_rule_not_supported                              (CFM_error_base + 99)

/** The Occurrence Type is invalid and cannot, therefore, be added to the Revision Rule "%1$". */
#define CFM_invalid_occurrence_type                             (CFM_error_base + 100)

/** Invalid Revision Rule. */
#define CFM_invalid_revision_rule                               (CFM_error_base + 101)

/** Invalid group occurrence type revision rule entry. */
#define CFM_invalid_group_occurrence_type_entry                 (CFM_error_base + 102)

/** The revision rule "%1$" contains an invalid clause for configuring major revisions. Valid values are "Working", "Status" and "Latest(By Creation Date, Alphanumeric Rev ID, Numeric Rev ID)". */
#define CFM_invalid_revision_rule_clause                        (CFM_error_base + 103)

/** The Effectivity Group Object has object based effectivity and cannot be modified using expression based effectivity. Please remove the existing object based effectivity to author an expression based effectivity. */
#define CFM_has_object_based_eff_cant_have_expr_based_eff       (CFM_error_base + 104)

/** The Effectivity Group Object has expression based effectivity and cannot be modified using object based effectivity. Please remove the existing expression based effectivity to author an object based effectivity. */
#define CFM_has_expr_based_eff_cant_have_object_based_eff       (CFM_error_base + 105)

#define CFM_error_ceiling                                       (CFM_error_base + 105)
/** @} */

#endif
