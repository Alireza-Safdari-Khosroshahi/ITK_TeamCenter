/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Appearance errors
*/

/*  */

#ifndef APPR_ERRORS_H
#define APPR_ERRORS_H

#include <common/emh_const.h>
#include <appr/libappr_exports.h>

/**
    @defgroup APPR_ERRORS Errors
    @ingroup APPR
    @{
*/

/** There should be an instance of the class AppearanceRootPool. */
#define APPR_missing_pool                           (EMH_APPR_error_base + 1)

/** There should be precisely one instance of the class AppearanceRootPool. */
#define APPR_duplicate_pools                        (EMH_APPR_error_base + 2)

/** You must specify an End Item. */
#define APPR_missing_end_item                       (EMH_APPR_error_base + 3)

/** Not supported yet. */
#define APPR_not_supported                          (EMH_APPR_error_base + 4)

/** The revision-rules, in-dates and out-dates arrays should be the same length. */
#define APPR_array_length_mismatch                  (EMH_APPR_error_base + 5)

/** You may not set the final out-date if it is not currently a null-date. */
#define APPR_final_out_date_must_be_null            (EMH_APPR_error_base + 6)

/** You may not add an in-date if the current final out-date is a null-date. */
#define APPR_final_out_date_must_not_be_null        (EMH_APPR_error_base + 7)

/** The supplied revision rule is absent from the appearance's list of revision-rules. */
#define APPR_revision_rule_absent                   (EMH_APPR_error_base + 8)

/** When adding a date, it must be chronologically later than the final in-date. */
#define APPR_date_must_be_after_final_in_date       (EMH_APPR_error_base + 9)

/** When adding a date, it must be chronologically later than the final out-date. */
#define APPR_date_must_be_after_final_out_date      (EMH_APPR_error_base + 10)

/**
    Specified rule is not supported for use as an Appearance context.
    Following errors explains why:

    #APPR_needs_v7_eff_mode <br>
    #APPR_non_status_rule_entry <br>
    #APPR_cant_mix_date_and_unit_eff <br>
    #APPR_cant_mix_date_eff_and_rel <br>
    #APPR_rev_rule_is_nested
*/
#define APPR_unsuitable_rev_rule                    (EMH_APPR_error_base + 11)

/** When setting the in-date, it must be chronologically earlier than the out-date. */
#define APPR_in_date_must_be_before_out_date        (EMH_APPR_error_base + 12)

/** When setting the out-date, it must be chronologically later than the in-date. */
#define APPR_out_date_must_be_after_in_date         (EMH_APPR_error_base + 13)

/** When setting the in-unit-no, it must be \<= than the out-unit-no. */
#define APPR_in_unit_no_must_be_le_out_unit_no      (EMH_APPR_error_base + 14)

/** When setting the out-unit-no, it must be >= than the in-unit-no. */
#define APPR_out_unit_no_must_be_ge_in_unit_no      (EMH_APPR_error_base + 15)

/** When creating a context, all inputs must be non-null. */
#define APPR_null_context_info_not_allowed          (EMH_APPR_error_base + 16)

/** The query-entries and query-values arrays should be the same length. */
#define APPR_query_array_length_mismatch            (EMH_APPR_error_base + 17)

/** Appearances disabled (by ACS, or by preference). */
#define APPR_error_disabled                         (EMH_APPR_error_base + 18)

/**
    A rev rule referenced by an appearance set cannot have entries other
    than date and unit added to or removed from it.
*/
#define APPR_rev_rule_edits_not_allowed             (EMH_APPR_error_base + 19)

/**
    It makes no sense to extend a WHERE clause by adding something of the
    form "AND value IN empty-list".
*/
#define APPR_empty_where_clause                     (EMH_APPR_error_base + 20)

/**
    Appearance does not support context rev rules configuring by a mixture
    of date and unit effectivity. Unit effectivity + release date is the
    only mixed configuration mode supported.
*/
#define APPR_cant_mix_date_and_unit_eff             (EMH_APPR_error_base + 21)

/**
    Appearance does not support context rev rules configuring by a mixture
    of date effectivity and release date. Unit effectivity + release date
    is the only mixed configuration mode supported.
*/
#define APPR_cant_mix_date_eff_and_rel              (EMH_APPR_error_base + 22)

/**
    A valid Appearance context must contain only "Has Status" and "End Item" entries,
    optionally grouped together.
*/
#define APPR_non_status_rule_entry                  (EMH_APPR_error_base + 23)

/** The appearance root is associated with corrupt appearances. */
#define APPR_corrupt_root                           (EMH_APPR_error_base + 24)

/**
    You may not set this property on an appearance root
    that is associated with any appearances.
*/
#define APPR_cannot_set_prop_when_populated         (EMH_APPR_error_base + 25)

/**
    Internal error: a bootstrap package cannot be processed for an appearance root
    that is associated with any appearances.
*/
#define APPR_unable_to_bootstrap_when_populated     (EMH_APPR_error_base + 26)

/** Some internal error occurred. */
#define APPR_internal_error                         (EMH_APPR_error_base + 27)

/** The appearance's validity range is outside that of its parent. */
#define APPR_validity_outside_parent                (EMH_APPR_error_base + 28)

/** The appearance's validity overlaps that of a matching appearance. */
#define APPR_validity_overlap                       (EMH_APPR_error_base + 29)

/**
    In order to use a revision rule which contains effectivity entries, you
    need to be in V7 effectivity mode.
*/
#define APPR_needs_v7_eff_mode                      (EMH_APPR_error_base + 30)

/**
    A valid Appearance context must contain only "Has Status" and "End Item" entries,
    optionally grouped together.
*/
#define APPR_unit_eff_needs_end_item_entry          (EMH_APPR_error_base + 31)

/** An Appearance callback function failed. */
#define APPR_callback_failed                        (EMH_APPR_error_base + 32)

/** No licenses available for searching or all licenses have been used up */
#define APPR_no_more_search_licenses                (EMH_APPR_error_base + 33)

/**
    Specified rule is not supported for use with Pre-Release Appearances,
    since for such use it must contain only "Has Status (some pre-release
    status) By Release Date" entries, but it has some other type of entry.
*/
#define APPR_unsuitable_pre_release_rev_rule        (EMH_APPR_error_base + 34)

/**
    Specified rule is not supported for use with Pre-Release Appearances,
    since for such use it must contain only "Has Status (some pre-release
    status) By Release Date" entries, but it contains an entry with some
    other (non-pre-release) status.
*/
#define APPR_unsuitable_pre_release_rev_rule_entry  (EMH_APPR_error_base + 35)

/**
    Specified rule is not supported for use with Pre-Release Appearances,
    since for such use it must contain only "Has Status (some pre-release
    status) By Release Date" entries, but the System Administrator has not
    defined any such statuses.
*/
#define APPR_no_defined_pre_release_statuses        (EMH_APPR_error_base + 36)

/**
    A valid Appearance context must, if using the Precise entry,
    place that entry ahead of all others and ungrouped.
*/
#define APPR_invalid_precise_entry_usage            (EMH_APPR_error_base + 37)

/**
    A Precise Appearance must reference the correct component item revision.
*/
#define APPR_precise_no_component_item_rev          (EMH_APPR_error_base + 38)

/**
    Appearances cannot be generated for revision rules that use nested
    effectivity.
*/
#define APPR_rev_rule_is_nested                     (EMH_APPR_error_base + 39)

/**
    An AppearanceRoot cannot be created for a revision rule that is currently
    locked.
*/
#define APPR_rev_rule_is_locked                     (EMH_APPR_error_base + 40)


/**
    @name Appearances Attribute Errors
    @{
*/

/**
    Returned by the appearance attribute update user exit when no logic
    has been written yet.
*/
#define APPR_no_mapping_logic_defined               (EMH_APPR_error_base + 50)

/**
    Appearance attribute names must be unique. An attempt has been made to
    create a new attribute with the same name as an existing attribute.
*/
#define APPR_attribute_name_not_unique              (EMH_APPR_error_base + 51)

/** The attr-names and attr-values arrays should be the same length. */
#define APPR_attribute_array_length_mismatch        (EMH_APPR_error_base + 52)

/**
    Returned by the appearance attribute query method if an invalid attribute name is input.
*/
#define APPR_invalid_attribute_name                 (EMH_APPR_error_base + 53)

/**
    Returned by the appearance attribute query method if an invalid attribute name is input.
*/
#define APPR_invalid_attribute_name                 (EMH_APPR_error_base + 53)

/**
    Returned by the appearance attribute query method if an attribute index is not valid.
*/
#define APPR_invalid_attribute_index                (EMH_APPR_error_base + 54)

/**
    Returned by the appearance mapping create Instance method if an attribute of new mapping is already mapped.
*/
#define APPR_attribute_already_mapped           (EMH_APPR_error_base + 55)

/** @} */

/**
    @name Appearances Update Errors
    @{
*/

/** Appearances updater needs a release status */
#define APPR_updater_rel_stat_cannot_be_nulltag     (EMH_APPR_error_base + 101)

/**
    Any item revision added to an appearances updater must have a release status
    the same as that of the updater.
*/
#define APPR_updater_rel_stat_not_on_item_rev       (EMH_APPR_error_base + 102)

/** When two appearances that are supposed to be the same aren't. */
#define APPR_inconsistent_roots                     (EMH_APPR_error_base + 103)

/** Secondary queue should always have at least one element. */
#define APPR_empty_secondary_queue                  (EMH_APPR_error_base + 104)

/** Tag supplied is not that of an existing or valid update package object. */
#define APPR_invalid_update_package_tag             (EMH_APPR_error_base + 105)

/**
    Tag supplied is not that of an existing or valid appearance validation entity object.
*/
#define APPR_invalid_appr_validation_entity_tag     (EMH_APPR_error_base + 106)

/**
    Tag supplied is not that of an existing or valid appearances validator object.
*/
#define APPR_invalid_appr_validator_tag             (EMH_APPR_error_base + 107)

/**
    New appearances are not consistent with those expected by the validator.
*/
#define APPR_new_aps_not_consistent_with_validator  (EMH_APPR_error_base + 108)

/**
    Validation entity needs either a parent appearance or a parent bom line.
*/
#define APPR_validation_entity_without_parent       (EMH_APPR_error_base + 109)

/**
    Need to have parent appearance and appearance root set to
    invoke isMatchingAppearance.
*/
#define APPR_cannot_ask_is_matching_appearance      (EMH_APPR_error_base + 110)

/**
    Validator needs at least one appearance validation entity for which
    the parent appearance is known.
*/
#define APPR_no_entity_exists_with_parent_ap        (EMH_APPR_error_base + 111)

/** Cannot execute update package that is already processed. */
#define APPR_already_processed                      (EMH_APPR_error_base + 112)

/** Tag supplied is not that of an existing or valid occurrence change object. */
#define APPR_invalid_occurrence_change_tag          (EMH_APPR_error_base + 113)

/** Cannot select a primary object whilst another is in process */
#define APPR_cannot_select_primary_yet              (EMH_APPR_error_base + 114)

/** Another process already has the primary locked */
#define APPR_primary_already_locked                 (EMH_APPR_error_base + 115)

/** No primary has been selected yet */
#define APPR_no_primary_selected                    (EMH_APPR_error_base + 116)

/** Cannot complete the primary as it has secondaries waiting to be processed. */
#define APPR_primary_not_finished                   (EMH_APPR_error_base + 117)

#define APPR_no_primary_in_process                  (EMH_APPR_error_base + 118)

/** The updater doesn't recognise the supplied task. */
#define APPR_unknown_task                           (EMH_APPR_error_base + 119)

/** Processing the package generated some noteworthy errors. */
#define APPR_noteworthy_errors_occurred             (EMH_APPR_error_base + 120)

/** The SA has been notified (by email) about the errors. */
#define APPR_notified_sa                            (EMH_APPR_error_base + 121)

/** @} */

/**
    @name Appearances Update Manager Errors
    @{
*/

/** @if DOX_IGNORE
    Do not change the order of this first block of errors.
    These are required to map onto the error codes of the Update Manager messaging system.
@endif */
#define APPR_update_mgr_socket_error                (EMH_APPR_error_base + 150)
#define APPR_update_mgr_marshalling_failed          (EMH_APPR_error_base + 151)
#define APPR_update_mgr_wrong_message               (EMH_APPR_error_base + 152)
#define APPR_update_mgr_message_truncated           (EMH_APPR_error_base + 153)
#define APPR_update_mgr_buffer_overflow             (EMH_APPR_error_base + 154)
/** @if DOX_IGNORE
                    End of Update Manager messaging errors
@endif */

#define APPR_update_mgr_query_failed                (EMH_APPR_error_base + 155)
#define APPR_update_mgr_connection_broken           (EMH_APPR_error_base + 156)
#define APPR_update_mgr_unexpected_reply            (EMH_APPR_error_base + 157)
#define APPR_update_mgr_winsock_failed              (EMH_APPR_error_base + 158)
#define APPR_update_mgr_invalid_host                (EMH_APPR_error_base + 159)
#define APPR_update_mgr_connection_failed           (EMH_APPR_error_base + 160)
#define APPR_update_mgr_timed_out                   (EMH_APPR_error_base + 161)
#define APPR_update_mgr_connection_rejected         (EMH_APPR_error_base + 162)
#define APPR_update_mgr_external_app_failed         (EMH_APPR_error_base + 163)
#define APPR_update_mgr_unauthorized_user           (EMH_APPR_error_base + 164)
#define APPR_update_mgr_no_config_file              (EMH_APPR_error_base + 165)
#define APPR_update_mgr_syntax_error_in_config      (EMH_APPR_error_base + 166)
#define APPR_update_mgr_no_admin_email              (EMH_APPR_error_base + 167)

#define APPR_background_updater_has_never_run           (EMH_APPR_error_base + 180)
#define APPR_background_updater_has_not_run_recently    (EMH_APPR_error_base + 181)
#define APPR_background_updater_too_many_failures       (EMH_APPR_error_base + 182)

/** @} */

/** @if DOX_IGNORE
    These are internal errors used for testing the update manager
@endif */
#define APPR_update_mgr_idle_but_queue_not_empty    (EMH_APPR_error_base + 200)
#define APPR_update_mgr_idle_but_processing         (EMH_APPR_error_base + 201)
#define APPR_update_mgr_not_idle_but_nothing_to_do  (EMH_APPR_error_base + 202)
#define APPR_update_mgr_timedout_waiting_for_finish (EMH_APPR_error_base + 203)

#define APPR_validation_failed                      (EMH_APPR_error_base + 300)

/** @} */

#include <appr/libappr_undef.h>
#endif

