/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Defines error codes used with application encapsulation.
*/

/*  */

#ifndef AE_ERRORS_H
#define AE_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup AE_ERRORS Errors
    @ingroup AE
    @{
*/

#define AE_ERROR_BASE                           EMH_AE_error_base

#define AE_tool_not_found                       (AE_ERROR_BASE + 8)
#define AE_dataset_archived                     (AE_ERROR_BASE + 9)

#define AE_datasettype_not_found                (AE_ERROR_BASE + 10)
#define AE_datasettype_not_loaded               (AE_ERROR_BASE + 11)

/**
    This error means that a tool was entered that is not in the list of
    tools that the input DatasetType understands.
*/
#define AE_datasettypetool_not_found            (AE_ERROR_BASE + 12)

#define AE_format_invalid                       (AE_ERROR_BASE + 13)

/** Error occurred in the update of the newstuff folder. */
#define AE_create_shell_error                   (AE_ERROR_BASE + 15)

/**
The named reference "%1$" cannot be added to the Dataset, because the reference already exists.
*/
#define AE_reference_already_exists             (AE_ERROR_BASE + 36)

/**
    The named reference, "%1$", cannot be added to the Dataset, because the reference does not exist.
*/
#define AE_reference_does_not_exist             (AE_ERROR_BASE + 37)

/**
    The Dataset type cannot be found.
*/
#define AE_finding_datasettype                  (AE_ERROR_BASE + 38)

/**
    The tool "%1$" cannot be found. Please contact your system administrator.
*/
#define AE_finding_tool                         (AE_ERROR_BASE + 39)

/**
    The Dataset cannot be found.
*/
#define AE_finding_dataset                      (AE_ERROR_BASE + 40)

/**
    This error means that #AE_init_module was not called prior to
    making calls to AE ITK routines.
*/
#define AE_not_initialized                      (AE_ERROR_BASE + 41)

/**
    This error will be returned when something goes wrong that never should.
    You should review the journal_file and will probably need to call client
    services.
*/
#define AE_unexplained_error                    (AE_ERROR_BASE + 42)

/**
    This error would occur if we attempted to delete a dataset that was either
    frozen or being referenced by something other than its anchor.
*/
#define AE_cannot_delete_dataset                (AE_ERROR_BASE + 43)

/**
    This error occurs when an error is encountered finding the child types
    of a Dasettype. It can also occur when finding root parents, since it
    is the same query, except the parent equals #NULLTAG.
*/
#define AE_finding_datasettype_children         (AE_ERROR_BASE + 44)

#define AE_cannot_freeze_reference              (AE_ERROR_BASE + 45)

/**
    Cannot freeze or unfreeze an object pointed to via a named reference.
*/
#define AE_cannot_unfreeze_reference            (AE_ERROR_BASE + 46)

#define AE_cannot_freeze_dataset                (AE_ERROR_BASE + 47)
#define AE_cannot_unfreeze_dataset              (AE_ERROR_BASE + 48)

/**
    Cannot make a revision copy of a dataset whose latest revision is frozen.
*/
#define AE_cannot_rev_copy_frozen_dataset       (AE_ERROR_BASE + 49)

/**
    This error is returned within the Dataset Window when an action is chosen
    that expects a tool to be defined, but nothing has been entered yet.
*/
#define AE_tool_not_entered                     (AE_ERROR_BASE + 50)

/**
    Somehow an action code was passed to the encapsulation mechanism
    that AE does not yet understand.
*/
#define AE_unknown_action                       (AE_ERROR_BASE + 51)

#define AE_invalid_load_method                  (AE_ERROR_BASE + 52)
#define AE_asking_registered_actions            (AE_ERROR_BASE + 53)
#define AE_setting_registered_actions           (AE_ERROR_BASE + 54)
#define AE_invalid_action                       (AE_ERROR_BASE + 55)
#define AE_listing_datasettype_refs             (AE_ERROR_BASE + 56)
#define AE_tool_name_not_unique                 (AE_ERROR_BASE + 57)

/**
    This error would occur if the system cannot perform the default print
    method on a Dataset for some reason, such as it is a multi-file
    Dataset, or it points to some class of object other than ImanFile.
*/
#define AE_cannot_print_dataset                 (AE_ERROR_BASE + 58)

#define AE_cannot_open_dataset                  (AE_ERROR_BASE + 59)

#define AE_no_grant_anchor_access               (AE_ERROR_BASE + 60)
#define AE_no_revoke_anchor_access              (AE_ERROR_BASE + 61)
#define AE_no_change_anchor_owner               (AE_ERROR_BASE + 62)
#define AE_no_grant_reference_access            (AE_ERROR_BASE + 63)
#define AE_no_revoke_reference_access           (AE_ERROR_BASE + 64)
#define AE_no_change_reference_owner            (AE_ERROR_BASE + 65)
#define AE_no_grant_dataset_access              (AE_ERROR_BASE + 66)
#define AE_no_revoke_dataset_access             (AE_ERROR_BASE + 67)
#define AE_no_change_dataset_owner              (AE_ERROR_BASE + 68)

/**
    The Dataset "%1$" cannot be refreshed.
*/
#define AE_no_refresh                           (AE_ERROR_BASE + 69)

#define AE_NULL_reference                       (AE_ERROR_BASE + 70)
#define AE_no_load_reference                    (AE_ERROR_BASE + 71)
#define AE_no_load_tool_desc                    (AE_ERROR_BASE + 72)
#define AE_no_load_program                      (AE_ERROR_BASE + 73)
#define AE_no_load_datasettype                  (AE_ERROR_BASE + 74)
#define AE_no_load_ref_desc                     (AE_ERROR_BASE + 75)
#define AE_parameters_not_loaded                (AE_ERROR_BASE + 76)
#define AE_parameter_already_set                (AE_ERROR_BASE + 77)
#define AE_parameter_not_set                    (AE_ERROR_BASE + 78)
#define AE_parameter_not_removed                (AE_ERROR_BASE + 79)
#define AE_no_save_parameters                   (AE_ERROR_BASE + 80)
#define AE_invalid_parameter                    (AE_ERROR_BASE + 81)
#define AE_invalid_token                        (AE_ERROR_BASE + 82)
#define AE_invalid_reference                    (AE_ERROR_BASE + 83)
#define AE_invalid_program                      (AE_ERROR_BASE + 84)
#define AE_invalid_datasettype                  (AE_ERROR_BASE + 85)
#define AE_invalid_format                       (AE_ERROR_BASE + 86)
#define AE_invalid_template                     (AE_ERROR_BASE + 87)
#define AE_invalid_data                         (AE_ERROR_BASE + 88)
#define AE_invalid_tool                         (AE_ERROR_BASE + 89)
#define AE_no_add_ref                           (AE_ERROR_BASE + 90)
#define AE_no_remove_ref                        (AE_ERROR_BASE + 91)
#define AE_no_save_refs                         (AE_ERROR_BASE + 92)
#define AE_duplicate_type_name                  (AE_ERROR_BASE + 93)
#define AE_no_create_type                       (AE_ERROR_BASE + 94)
#define AE_no_find_type                         (AE_ERROR_BASE + 95)
#define AE_invalid_type                         (AE_ERROR_BASE + 96)
#define AE_cannot_find_dataset                  (AE_ERROR_BASE + 97)

#define AE_no_save_datasettype                  (AE_ERROR_BASE + 99)
#define AE_references_not_loaded                (AE_ERROR_BASE + 100)
#define AE_no_class_type                        (AE_ERROR_BASE + 101)
#define AE_no_get_attrs                         (AE_ERROR_BASE + 102)
#define AE_no_create_enq                        (AE_ERROR_BASE + 103)
#define AE_enq_failed                           (AE_ERROR_BASE + 104)
#define AE_no_datasettypes                      (AE_ERROR_BASE + 105)
#define AE_invalid_file_limit                   (AE_ERROR_BASE + 106)
#define AE_no_delete_access                     (AE_ERROR_BASE + 107)
#define AE_cannot_get_first_obj                 (AE_ERROR_BASE + 108)
#define AE_cannot_get_next_obj                  (AE_ERROR_BASE + 109)
#define AE_no_next_obj                          (AE_ERROR_BASE + 110)
#define AE_cannot_get_prev_obj                  (AE_ERROR_BASE + 111)
#define AE_no_prev_obj                          (AE_ERROR_BASE + 112)
#define AE_cannot_get_tool                      (AE_ERROR_BASE + 113)

#define AE_save_dsparms_failed1                 (AE_ERROR_BASE + 120)
#define AE_save_dsparms_failed2                 (AE_ERROR_BASE + 121)
#define AE_get_parms_failed                     (AE_ERROR_BASE + 122)
#define AE_unlock_datasettype_failed            (AE_ERROR_BASE + 123)
#define AE_cannot_get_datasettype               (AE_ERROR_BASE + 124)
#define AE_cannot_clear_tool_parms              (AE_ERROR_BASE + 125)
#define AE_cannot_create_parm_obj               (AE_ERROR_BASE + 126)
#define AE_cannot_add_tool_parms                (AE_ERROR_BASE + 127)
#define AE_no_save_operations                   (AE_ERROR_BASE + 128)
#define AE_operation_exist_in_the_list          (AE_ERROR_BASE + 129)
#define AE_operation_not_defined                (AE_ERROR_BASE + 130)
#define AE_nothing_to_modify                    (AE_ERROR_BASE + 131)
#define AE_nothing_to_delete                    (AE_ERROR_BASE + 132)
#define AE_unable_to_get_parameters             (AE_ERROR_BASE + 133)
#define AE_cannot_remove_parameters             (AE_ERROR_BASE + 134)
#define AE_invalid_operator                     (AE_ERROR_BASE + 135)
#define AE_bad_rev_limit                        (AE_ERROR_BASE + 136)
#define AE_cannot_purge_dataset                 (AE_ERROR_BASE + 137)
#define AE_cannot_init_dataset                  (AE_ERROR_BASE + 138)
#define AE_cannot_save_dataset                  (AE_ERROR_BASE + 139)
#define AE_cannot_get_rev0_obj                  (AE_ERROR_BASE + 140)
#define AE_cannot_get_rev0_tag                  (AE_ERROR_BASE + 141)
#define AE_dataset_is_frozen                    (AE_ERROR_BASE + 142)
#define AE_bad_reference_tree                   (AE_ERROR_BASE + 143)
#define AE_no_access                            (AE_ERROR_BASE + 144)
#define AE_no_clear_anchor_access               (AE_ERROR_BASE + 145)
#define AE_no_clear_reference_access            (AE_ERROR_BASE + 146)
#define AE_no_clear_dataset_access              (AE_ERROR_BASE + 147)
#define AE_cannot_rev_copy                      (AE_ERROR_BASE + 148)
#define AE_cannot_get_references                (AE_ERROR_BASE + 149)
#define AE_invalid_operation                    (AE_ERROR_BASE + 150)

#define AE_lock_datasettype_failed              (AE_ERROR_BASE + 151)
#define AE_datasettype_renametool_failed        (AE_ERROR_BASE + 152)
#define AE_space_in_reference_name              (AE_ERROR_BASE + 153)
#define AE_nonfile_ref_to_file_ref              (AE_ERROR_BASE + 154)
#define AE_file_type_mismatch_ref               (AE_ERROR_BASE + 155)
#define AE_ALLOWED_REF_TYPE                     (AE_ERROR_BASE + 156)
#define AE_internal_error                       (AE_ERROR_BASE + 157)
#define AE_cannot_rename_dataset                (AE_ERROR_BASE + 158)
#define AE_cannot_modify_dataset_desc           (AE_ERROR_BASE + 159)
#define AE_cannot_insert_named_ref              (AE_ERROR_BASE + 160)
#define AE_cannot_replace_named_ref             (AE_ERROR_BASE + 161)
#define AE_empty_ro_dataset                     (AE_ERROR_BASE + 162)
#define AE_dataset_create_no_gen_name           (AE_ERROR_BASE + 163)
#define AE_dataset_copy_no_gen_name             (AE_ERROR_BASE + 164)
#define AE_cannot_export_dataset                (AE_ERROR_BASE + 165)
#define AE_cannot_replace_refs                  (AE_ERROR_BASE + 166)
#define AE_no_tools                             (AE_ERROR_BASE + 167)
#define AE_no_references                        (AE_ERROR_BASE + 168)

/**
    @name Error codes for the NX/Manager save-as non-master project
    @{
*/
#define AE_dataset_name_too_long                (AE_ERROR_BASE + 169)
#define AE_owner_preference_invalid             (AE_ERROR_BASE + 170)
#define AE_always_never_conflict                (AE_ERROR_BASE + 171)

#define AE_dataset_copy_error                   (AE_ERROR_BASE + 172)
#define AE_attempt_to_circular_ref              (AE_ERROR_BASE + 173)
#define AE_reference_stub_not_augmented         (AE_ERROR_BASE + 174)
/** @} */

#define AE_attached_dataset_cico_unco_error     (AE_ERROR_BASE + 175)
#define AE_attached_dataset_co_exported         (AE_ERROR_BASE + 176)

/** Some relations cannot be established between the Datasets and their associated containers. These Datasets, therefore, are placed under the "NewStuff" folder. */
#define AE_relate_to_dataset_newstuff_folder    (AE_ERROR_BASE + 177)

/**
    @name Error codes for Document Management's Digital Sign related.
    @{
*/

/**
    The "Undo Checked-Out" operation is not allowed on the Dataset object, because it is checked-out for signing.
    Please cancel, or complete, the signing operation.
*/
#define AE_sign_dataset_cannot_undo_checkout    (AE_ERROR_BASE + 178)

/**
    The "Transfer Checked-Out" operation is not allowed on the Dataset object, because it is checked-out for signing.
    Please cancel, or complete, the signing operation.
*/
#define AE_sign_dataset_cannot_tr_checkout      (AE_ERROR_BASE + 179)

/**
    The "Check-In" operation is not allowed on the Dataset object, because it is checked-out for signing.
    Please cancel, or complete, the signing operation.
*/
#define AE_sign_dataset_cannot_checkin          (AE_ERROR_BASE + 180)

/**
    The "Prune" operation cannot delete the named reference "%1$". Please refer to the Teamcenter server syslog file for more information.
*/
#define AE_cannot_prune_named_reference         (AE_ERROR_BASE + 181)

/**
    The "Prune" operation has failed unexpectedly. Please refer to the Teamcenter server syslog file for more information.
*/
#define AE_prune_operation_failed               (AE_ERROR_BASE + 182)

/**
    A Dataset with the name "%1$" already exists. Please give a different name to the Dataset.
*/
#define AE_CMS_dataset_duplicate_object_name    (AE_ERROR_BASE + 183)

/**
    The Dataset named reference file extention "%1$" is invalid. Please provide a different extension.
*/
#define AE_dataset_invalid_file_extension       (AE_ERROR_BASE + 184)
/**
    The Dataset file name "%1$" contains the following restricted characters: %2$. Please provide a different file name.
*/
#define AE_dataset_invalid_file_name_char       (AE_ERROR_BASE + 185)
/**
    The Dataset file name "%1$&" exceeds the maximum length of %2$ characters. Please provide a different file name.
*/
#define AE_dataset_file_name_too_long           (AE_ERROR_BASE + 186)
/**
    The Dataset file name "%1$" is less than the minimum length of %2$ characters. Please provide a different file name.
*/
#define AE_dataset_file_name_too_short          (AE_ERROR_BASE + 187)
/**
    The Dataset file name "%1$" matches the following restricted pattern: %2$. Please provide a different file name.
*/
#define AE_dataset_invalid_file_name_pattern    (AE_ERROR_BASE + 188)

/**
    The Dataset "%1$" cannot be marked as supporting multiple versions because either the Dataset cannot have multiple versions or the type constant "%2$" is set to false.
*/
#define AE_dataset_cannot_support_multi_version ( AE_ERROR_BASE + 189 )

/** @} */

/**
    @name Error codes for RevisionAnchor
    @{
*/
#define AE_revision_anchor_error_base           (AE_ERROR_BASE + 200)

#define AE_unable_to_load_rev_anchor            (AE_revision_anchor_error_base + 1)
/** @} */

/**
    @name Error codes for NamedRevisionAnchor
    @{
*/
#define AE_nra_error_base                       (AE_ERROR_BASE + 250)

#define AE_unable_to_find_nra_tag               (AE_nra_error_base + 1)
#define AE_unable_to_find_nra                   (AE_nra_error_base + 2)
/** @} */

/**
    @name Error codes for Dataset ID/Rev/Name Generation
    @{
*/
#define AE_idrev_error_base                     (AE_ERROR_BASE + 300)

#define AE_duplicate_id_rev                     (AE_idrev_error_base + 1)
#define AE_next_id_lock_failed                  (AE_idrev_error_base + 2)
#define AE_illegal_parameter                    (AE_idrev_error_base + 3)
#define AE_mem_alloc_failed                     (AE_idrev_error_base + 4)
#define AE_max_id_exceeded                      (AE_idrev_error_base + 5)
#define AE_create_id_gen_failed                 (AE_idrev_error_base + 6)
#define AE_copy_id_gen_failed                   (AE_idrev_error_base + 7)
#define AE_create_revid_gen_failed              (AE_idrev_error_base + 8)
#define AE_copy_revid_gen_failed                (AE_idrev_error_base + 9)
/**
    The generation of a Dataset name using Naming Rules is not supported.
*/
#define AE_create_name_gen_failed               (AE_idrev_error_base + 10)
/** @} */

/**
    @name Error codes for the Dataset ICT methods
    @{
*/
#define AE_ict_error_base                       (AE_ERROR_BASE + 350)

#define AE_ICT_invalid_version                  (AE_ict_error_base + 1)
/** @} */

/** @} AE_ERRORS */

#endif
