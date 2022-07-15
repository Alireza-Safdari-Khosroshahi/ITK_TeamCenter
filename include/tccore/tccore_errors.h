/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2015.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    Error codes returned by some applications in tccore module.
*/

/*  */
#ifndef TCCORE_ERRORS_H
#define TCCORE_ERRORS_H

#include <common/emh_const.h>
#include <common/tc_deprecation_macros.h>
#include <tccore/libtccore_exports.h>

/**
    @defgroup TCCORE_ERRORS TCCORE Errors
    @ingroup TCCORE
    @{
*/

/* VLAAdapter errors */
#define VLAAdapter_VLA_has_no_locale             (EMH_TCCORE_error_base + 0)
#define VLAAdapter_VLA_has_no_master_locale      (EMH_TCCORE_error_base + 1)
#define VLAAdapter_requested_locale_not_in_VLA   (EMH_TCCORE_error_base + 2)

#define VLAAdapter_negative_sequence_number      (EMH_TCCORE_error_base + 3)
#define VLAAdapter_outofbounds_sequence_number   (EMH_TCCORE_error_base + 4)

#define VLAAdapter_no_localization_passed        (EMH_TCCORE_error_base + 5)
#define VLAAdapter_undefined_VLA_row             (EMH_TCCORE_error_base + 6)

#define VLAAdapter_wrong_status                  (EMH_TCCORE_error_base + 7)

/* Reorder errors */
#define VLAAdapter_reorder_incorrect_parameters  (EMH_TCCORE_error_base + 8)
#define VLAAdapter_reorder_incorrect_new_start   (EMH_TCCORE_error_base + 9)

/* VLA errors */
#define VLAAdapter_VLA_has_no_master             (EMH_TCCORE_error_base + 10)
#define VLAAdapter_string_is_improper_VLA        (EMH_TCCORE_error_base + 11)

#define LOCALE_NOT_SUPPORTED                     (EMH_TCCORE_error_base + 20)

/* Base starting at 25 - other errors */
#define TCCORE_NULL_argument_passed              (EMH_TCCORE_error_base + 25)

/** The &quot;Save&quot; operation was called for the transient object &quot;%2$&quot; of type &quot;%1$&quot;. However, transient objects cannot be saved. */
#define TCCORE_cannot_save_transient_object      (EMH_TCCORE_error_base + 26)

/* Expression based property evaluation Framework errors. starts at 31 */
#define Expression_malformed_expression          (EMH_TCCORE_error_base + 31)
#define Expression_invalid_function_syntax       (EMH_TCCORE_error_base + 32)
#define Expression_invalid_property              (EMH_TCCORE_error_base + 33)
#define Expression_invalid_function_argument     (EMH_TCCORE_error_base + 34)
#define Expression_internal_error                (EMH_TCCORE_error_base + 35)
#define TCCORE_id_missed_in_createinput          (EMH_TCCORE_error_base + 36)

/* DeferredHelper errors starts at 41 */
#define DeferredHelper_mixed_save_delete         (EMH_TCCORE_error_base + 41)

/* DeepCopy errors starts at 51 */
#define DeepCopy_no_saveasinput                  (EMH_TCCORE_error_base + 51)
#define DeepCopy_allow_or_items                  (EMH_TCCORE_error_base + 52)

/**
    The &quot;Create&quot; operation was called for the object &quot;%2$&quot; of type &quot;%1$&quot;. The required call to the &quot;Save&quot; operation is missing for this object. Refer to the Business Modeler IDE guide &quot;Refactor create operations&quot; for more details.
*/
#define DeferredSaveHelper_missing_save          (EMH_TCCORE_error_base + 61)

/**
    The bulk creation of objects of type &quot;%1$&quot; is not supported.
*/
#define TCCORE_bulk_create_not_supported         (EMH_TCCORE_error_base + 62)

/**
    A key with the same value "%1$" already exists in this object status. Please refer to the Teamcenter server log file for details and contact your system administrator.
*/
#define TCCORE_ERROR_key_already_exists          (EMH_TCCORE_error_base + 71)

/**
    The key "%1$" was not found in the object status. Please refer to the Teamcenter server log file for details and contact your system administrator.
*/
#define TCCORE_ERROR_key_not_found               (EMH_TCCORE_error_base + 72)

/**
    The following objects are not configured to allow the revise operation: %1$. If this is needed, please contact your system administrator to make the needed changes using the Business Modeler IDE (BMIDE).
*/
#define TCCORE_revise_not_supported              (EMH_TCCORE_error_base + 82)

/**
    The given operation "%1$" is not supported.
*/
#define TCCORE_traversalrule_unsupported_operation            (EMH_TCCORE_error_base + 91)

/**
    The given direction "%1$" is not supported.
*/
#define TCCORE_traversalrule_unsupported_direction            (EMH_TCCORE_error_base + 92)

/**
    The given propagation style "%1$" is not supported.
*/
#define TCCORE_propagationrule_unsupported_style              (EMH_TCCORE_error_base + 93)

/**
    The given reference type "%1$" is not supported.
*/
#define TCCORE_traversalrule_unsupported_referencetype        (EMH_TCCORE_error_base + 94)

/**
    The Traversal rule definition cannot be created with the given inputs. Please check the error log file for more details, or contact your system administrator.
*/
#define TCCORE_failed_to_create_traversalrule_definition      (EMH_TCCORE_error_base + 95)

/**
    The Propagation rule definition cannot be created with the given inputs. Please check the error log file for more details, or contact your system administrator.
*/
#define TCCORE_failed_to_create_propagationrule_definition    (EMH_TCCORE_error_base + 96)

/**
    The following objects are not configured to allow the "Save As" operation: %1$. If this is needed, please contact your system administrator to make the needed changes using the Business Modeler IDE (BMIDE).
*/
#define TCCORE_saveas_not_supported                           (EMH_TCCORE_error_base + 97)

/**
    The "Save" operation is not supported on the shadow object "%2$" of type "%1$", because shadow objects are transient objects.
*/
#define TCCORE_cannot_save_shadow_object                      (EMH_TCCORE_error_base + 98)

/** @deprecated #TCCORE_inst_context_locked deprecated in Teamcenter 11.2.3. */
#define TCCORE_inst_context_locked                            (EMH_TCCORE_error_base + 99)
TC_DEPRECATED_PREPROCESSOR( "11.2.3", TCCORE_inst_context_locked, "" )
/**
    The object creation in the Change Context "%1$" has failed, because the current user does not have write access to this Change Context.
*/
#define TCCORE_no_write_access_to_create_in_context           (EMH_TCCORE_error_base + 100)

/**
    The Relation cannot be created, because it is configured for a "public" context, which means that both the primary and the secondary objects must be configured for "public" context. The primary object "%1$" is configured for the context "%2$", and the secondary object "%3$" is configured for the context "%4$".
*/
#define TCCORE_failed_to_create_rel_in_public                 (EMH_TCCORE_error_base + 101)

/**
    The Relation cannot be created, because it is configured for the context "%1$", which means that the primary and the secondary objects must be configured either for the "public" context or for the context of the Relation. The primary object "%2$" is configured for the context "%3$", and the secondary object "%4$" is configured for the context "%5$".
*/
#define TCCORE_failed_to_create_rel_in_context                (EMH_TCCORE_error_base + 102)

/**
    The "revise" operation has failed, because the current user does not have access privileges on the Change Context "%1$".
*/
#define TCCORE_no_write_access_to_revise_in_context           (EMH_TCCORE_error_base + 103)

/**
    The "save as" operation has failed, because the current user does not have access privileges on the Change Context "%1$".
*/
#define TCCORE_no_write_access_to_saveas_in_context           (EMH_TCCORE_error_base + 104)

/** @deprecated #TCCORE_invalid_for_edit_in_context deprecated in Teamcenter 11.2.3. */
#define TCCORE_invalid_for_edit_in_context                    (EMH_TCCORE_error_base + 105)
TC_DEPRECATED_PREPROCESSOR( "11.2.3", TCCORE_invalid_for_edit_in_context, "" )

/**
    The properties of the object "%1$" do not satisfy the Multi-field Key attributes "%2$".
*/
#define TCCORE_object_violates_mfk_property                   (EMH_TCCORE_error_base + 106)

/**
    The properties of the object "%1$" do not satisfy the Multi-field Key attributes "%2$" and the unique attributes "%3$".
*/
#define TCCORE_inst_violates_unique_property_and_mfk_property (EMH_TCCORE_error_base + 107)

/**
    The properties of the object "%1$" do not satisfy the unique attributes "%2$".
*/
#define TCCORE_inst_violates_unique_property                  (EMH_TCCORE_error_base + 108)

/**
    The reference property "%1$" cannot be set, because "%2$" and "%3$" are present in the non-related contexts "%4$" and "%5$" respectively.
*/
#define TCCORE_violates_reference_rule                        (EMH_TCCORE_error_base + 109)

/**
    The check-out has been canceled but the re-import of the data has failed. Please correct the issue, and re-import the data.
*/
#define TCCORE_reimport_warning                               (EMH_TCCORE_error_base + 110)

/**
    The reference property "%1$" is either not present on the specified operation input or does not exist in "%2$".
*/
#define TCCORE_improper_inference_property                    (EMH_TCCORE_error_base + 111)

/**
    The creation of "%1$" is not supported because the property constant "Fnd0SpaceEnabled" is set to "false".
*/
#define TCCORE_space_creation_not_supported                   (EMH_TCCORE_error_base + 112)

/**
    Discontinuing an object during a "Create" operation is prohibited.
*/
#define TCCORE_cannot_discontinue_on_create                   (EMH_TCCORE_error_base + 113)

/**
    Discontinuing an object during a "Save As" operation is prohibited.
*/
#define TCCORE_cannot_discontinue_on_saveas                   (EMH_TCCORE_error_base + 114)

/**
    The object of type "%1$" cannot be created because the create input descriptor is empty.
*/
#define TCCORE_empty_create_input                             (EMH_TCCORE_error_base + 115)

/**
    The creation of object of type "%1$" has failed.
*/
#define TCCORE_unable_to_create                               (EMH_TCCORE_error_base + 116)

/**
    Public objects (like "%1$") cannot be edited in-context of a change.
*/
#define TCCORE_public_object_cannot_be_edited_in_exclusive_space         (EMH_TCCORE_error_base + 117)

/**
    No callback function has been registered for "%1$". Please report this error to your system administrator.
*/
#define TCCORE_callback_function_missing                      (EMH_TCCORE_error_base + 118)

/**
    The dynamic type "%1$" could not be saved to the database.
*/
#define TCCORE_cannot_save_dynamic_type                       (EMH_TCCORE_error_base + 119)

/**
    The expression effectivity authoring is not supported for type "%1$".
*/
#define TCCORE_exp_eff_authoring_not_supported                 (EMH_TCCORE_error_base + 120)

/** @name Markpoint Bulletin Board Errors
@{ */
/**
     An error has occurred while handling the Markpoint Bulletin Board. Please contact your system administrator.
*/
#define TCCORE_markpoint_bulletin_board_error                 (EMH_TCCORE_error_base + 200 )
/** @} */
/** @} */


#include <tccore/libtccore_undef.h>
#endif
