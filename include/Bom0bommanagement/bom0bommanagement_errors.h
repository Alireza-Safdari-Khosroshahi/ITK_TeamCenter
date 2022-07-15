/* Copyright 2020 Siemens Digital Industries Software
#===============================================================================
# Copyright 2014.
# Siemens Product Lifecycle Management Software Inc.
# All Rights Reserved.
#===============================================================================
# Copyright 2020 Siemens Digital Industries Software
*/
/**
    @file
    Product Master Error Codes Declaration
*/

#ifndef BOM0BOMMANAGEMENT_ERRORS_H
#define BOM0BOMMANAGEMENT_ERRORS_H


#include <common/emh_const.h>

/**
    @defgroup BOMMGMT_ERRORS Errors
    @ingroup BOMMGMT
    @{
*/

/**
* An internal error has occurred in the Product Master module: %1$. Report this error to your system administrator.
*/
#define BOM0BOMMANAGEMENT_internal_error                                   (EMH_BOM0BOMMANAGEMENT_error_base + 1)

/**
 * "%1$" cannot be revised, because "%2$" does not have a status.
 */
#define BOM0BOMMANAGEMENT_object_has_no_status                             (EMH_BOM0BOMMANAGEMENT_error_base + 2)

/**
 * An object of type "%1$" already exists with properties "%2$". Specify at least one unique value.
 */
#define BOM0BOMMANAGEMENT_inst_violates_unique                             (EMH_BOM0BOMMANAGEMENT_error_base + 3)

/**
 * The creation of a "Part Breakdown Element" object has failed because the "Parent Part" and the "Child Part" cannot be the same.
 */
#define BOM0BOMMANAGEMENT_pbe_same_parent_child                            (EMH_BOM0BOMMANAGEMENT_error_base + 4)

/**
 * "%1$" is not related to "%2$".
 */
#define BOM0BOMMANAGEMENT_no_relation_exists                               (EMH_BOM0BOMMANAGEMENT_error_base + 5)

/**
* The following input is invalid: %1$.
*/
#define BOM0BOMMANAGEMENT_invalid_input                                    (EMH_BOM0BOMMANAGEMENT_error_base + 6)

/**
* The selected object "%1$" of type "%2$" and the target object "%3$" of type "%4$" are already related.
*/
#define BOM0BOMMANAGEMENT_already_related                                  (EMH_BOM0BOMMANAGEMENT_error_base + 9)

/**
* New structure cannot be carried over to "%1$", because it already contains a structure.
*/
#define BOM0BOMMANAGEMENT_has_structure                                    (EMH_BOM0BOMMANAGEMENT_error_base + 11)

/**
* Part cannot be replaced if objects have different parts.
*/
#define BOM0BOMMANAGEMENT_different_part                                   (EMH_BOM0BOMMANAGEMENT_error_base + 12)

/**
* "%1$" and "%2$" are revisions of the same Part.
*/
#define BOM0BOMMANAGEMENT_same_part                                        (EMH_BOM0BOMMANAGEMENT_error_base + 13)

/**
* The Part on the Part Usage "%1$" cannot be replaced, because it does not contain any Part.
*/
#define BOM0BOMMANAGEMENT_replace_part_pu_without_part                     (EMH_BOM0BOMMANAGEMENT_error_base + 14)

/**
* An invalid option is specified for "Part Where Used".
*/
#define BOM0BOMMANAGEMENT_invalid_part_where_used_option                   (EMH_BOM0BOMMANAGEMENT_error_base + 16)

/**
* An error has occurred because a recursion is detected. The parent Part "%1$" is a descendent of the child Part "%2$" in the "Part Breakdown Element" tree.
*/
#define BOM0BOMMANAGEMENT_recursion_is_detected                            (EMH_BOM0BOMMANAGEMENT_error_base + 17)

/**
* The following objects cannot be released, because no revision of the associated part for each object is in the released state nor present as the target object in the current workflow process: %1$.
*/
#define BOM0BOMMANAGEMENT_associated_part_not_released_for_pu              (EMH_BOM0BOMMANAGEMENT_error_base + 18)

/**
* The current user does not have the "%1$" access privilege on "%2$".
*/
#define BOM0BOMMANAGEMENT_no_access_privilege                              (EMH_BOM0BOMMANAGEMENT_error_base + 19)

/**
* "%1$" is not modifiable.
*/
#define BOM0BOMMANAGEMENT_object_not_modifiable                            (EMH_BOM0BOMMANAGEMENT_error_base + 20)

/**
* No Part could be found using the "%1$" Revision Rule.
*/
#define BOM0BOMMANAGEMENT_part_not_found                                   (EMH_BOM0BOMMANAGEMENT_error_base + 21)

/**
* The Part Structure for Part "%1$" needs to be unpacked.
*/
#define BOM0BOMMANAGEMENT_part_structure_not_unpacked                      (EMH_BOM0BOMMANAGEMENT_error_base + 22)

/**
* The quantity cannot be decreased for "%1$".
*/
#define BOM0BOMMANAGEMENT_cannot_decrease_quantity                         (EMH_BOM0BOMMANAGEMENT_error_base + 24)

/**
* The following selected objects should belong to the same model as the target reference "%2$": %1$.
*/
#define BOM0BOMMANAGEMENT_model_mismatch_error                             (EMH_BOM0BOMMANAGEMENT_error_base + 25)

/**
* "%1$" is not aligned to "%2$".
*/
#define BOM0BOMMANAGEMENT_bom_design_not_aligned                           (EMH_BOM0BOMMANAGEMENT_error_base + 26)

/**
* The value for the preference "%1$" is invalid.
*/
#define BOM0BOMMANAGEMENT_invalid_alignment_preference_value               (EMH_BOM0BOMMANAGEMENT_error_base + 31)

/**
* "%1$" is already aligned with "%2$" in context of "%3$".
*/
#define BOM0BOMMANAGEMENT_part_structure_already_aligned                   (EMH_BOM0BOMMANAGEMENT_error_base + 32)

/**
* The business key for "%1$" already exists for "%2$".
*/
#define BOM0BOMMANAGEMENT_partusage_duplicate_business_key                 (EMH_BOM0BOMMANAGEMENT_error_base + 33)

/**
* The object "%1$" is not supported because it is packed.
*/
#define BOM0BOMMANAGEMENT_packed_line_not_supported                        (EMH_BOM0BOMMANAGEMENT_error_base + 34)

/**
* No part revision is configured for the top line with the selected configuration context.
*/
#define BOM0BOMMANAGEMENT_no_part_revision_for_topline                     (EMH_BOM0BOMMANAGEMENT_error_base + 35)

/**
* The following objects cannot be released, because, for each object, no revision of the parent part or child part is in the released state nor present as the target object in the current workflow process: %1$.
*/
#define BOM0BOMMANAGEMENT_associated_part_not_released_for_pbe             (EMH_BOM0BOMMANAGEMENT_error_base + 36)

/**
* The Part Occurrence alignment operation cannot be performed because duplicate Part Occurrences are specified.
*/
#define BOM0BOMMANAGEMENT_duplicate_pbe_line_for_alignment                 (EMH_BOM0BOMMANAGEMENT_error_base + 37)

/**
* "%1$" cannot be deleted because it is aligned.
*/
#define BOM0BOMMANAGEMENT_instance_referenced_by_alignment                 (EMH_BOM0BOMMANAGEMENT_error_base + 38)

/**
* An alignment cannot be performed with the top line of a Part Structure or a Design Structure.
*/
#define BOM0BOMMANAGEMENT_top_line_for_alignment                           (EMH_BOM0BOMMANAGEMENT_error_base + 39)

/**
* All objects of type "%1$" cannot be removed from "%2$". Instead, perform the delete operation on "%2$".
*/
#define BOM0BOMMANAGEMENT_cannot_remove_de                                 (EMH_BOM0BOMMANAGEMENT_error_base + 40)

/**
* The following selected object should be of type, or subtype of "%1$": %2$.
*/
#define BOM0BOMMANAGEMENT_invalid_type_of_input                            (EMH_BOM0BOMMANAGEMENT_error_base + 41)

/**
* No input is specified.
*/
#define BOM0BOMMANAGEMENT_no_input_specified                               (EMH_BOM0BOMMANAGEMENT_error_base + 42)

/**
* Only 1 Part and 1 Item Revision should be attached to the workflow.
*/
#define BOM0BOMMANAGEMENT_incorrect_attachments_to_workflow                (EMH_BOM0BOMMANAGEMENT_error_base + 43)

/**
* The Part "%1$" cannot be added as substitute because it is present as a primary part on "%2$".
*/
#define BOM0BOMMANAGEMENT_invalid_part_for_substitute                      (EMH_BOM0BOMMANAGEMENT_error_base + 44)

/**
* The Part "%1$" cannot be set as primary part on "%2$" because it is set as a substitute.
*/
#define BOM0BOMMANAGEMENT_part_existing_as_substitute                      (EMH_BOM0BOMMANAGEMENT_error_base + 45)

/**
* The Part "%1$" cannot be replaced on "%2$", because it is not configured for the given Configuration Context.
*/
#define BOM0BOMMANAGEMENT_configured_part_revision_not_found_for_replace   (EMH_BOM0BOMMANAGEMENT_error_base + 46)

/**
* The top line "%1$" of a Part Structure cannot be deleted.
*/
#define BOM0BOMMANAGEMENT_topline_cannot_be_deleted                        (EMH_BOM0BOMMANAGEMENT_error_base + 47)

/**
* The Design Line %1$" cannot be deleted in a Part Structure view.
*/
#define BOM0BOMMANAGEMENT_designline_cannot_be_deleted                      (EMH_BOM0BOMMANAGEMENT_error_base + 48)

/**
* The search cannot be performed for both Composite and Non-Composite objects at the same time.
*/
#define BOM0BOMMANAGEMENT_mixed_type_searches_not_supported                 (EMH_BOM0BOMMANAGEMENT_error_base + 49)

/**
* The sort attribute "%1$" is not selected in the search query.
*/
#define BOM0BOMMANAGEMENT_sort_attribute_not_selected                      (EMH_BOM0BOMMANAGEMENT_error_base + 50)

/**
 * The return type "%1$" is invalid for the search.
 */
#define BOM0BOMMANAGEMENT_invalid_return_type                              (EMH_BOM0BOMMANAGEMENT_error_base + 51)

/**
 * The property "%1$" is not available for Logical Object search on "%2$".
 */
#define BOM0BOMMANAGEMENT_invalid_logical_object_property_for_search       (EMH_BOM0BOMMANAGEMENT_error_base + 52)

/**
 * The column information required to perform a configured search for column "%1$" is not set.
 */
#define BOM0BOMMANAGEMENT_configured_search_missing_required_column        (EMH_BOM0BOMMANAGEMENT_error_base + 53)

/**
 * "%1$" does not allow this alignment because the alignment mode is set to "%2$".
 */
#define BOM0BOMMANAGEMENT_pu_alignment_wrong_design_type                   (EMH_BOM0BOMMANAGEMENT_error_base + 54)

/**
* The object "%1$" cannot be compared, because it contains subsets having different logical objects. Please select individual subset elements to compare.
*/
#define BOM0BOMMANAGEMENT_recipe_returntype_not_same                       (EMH_BOM0BOMMANAGEMENT_error_base + 55)

/**
* The effectivity of "%1$" ( %2$ ) is not completely within the range of effectivity of "%3$" ( %4$ ).
*/
#define BOM0BOMMANAGEMENT_effectivity_conformance_check_failed             (EMH_BOM0BOMMANAGEMENT_error_base + 56)

/**
* "%1$" was not replaced because it already exists.
*/
#define BOM0BOMMANAGEMENT_same_part_for_replace                            (EMH_BOM0BOMMANAGEMENT_error_base + 57)

/**
* "%1$" was replaced but Substitutes could not be removed.
*/
#define BOM0BOMMANAGEMENT_substitutes_not_removed_on_replace               (EMH_BOM0BOMMANAGEMENT_error_base + 58)

/**
* "%1$" was replaced but Designs could not be removed.
*/
#define BOM0BOMMANAGEMENT_alignments_not_removed_on_replace                (EMH_BOM0BOMMANAGEMENT_error_base + 59)

/**
* Part occurrence for "%1$" cannot be created, because unit of measure is not configuerd to have multiple occurrences.
*/
#define BOM0BOMMANAGEMENT_multiple_partoccurrences_not_allowed       (EMH_BOM0BOMMANAGEMENT_error_base + 60)

/**
* The selection was not submitted.
*/
#define BOM0BOMMANAGEMENT_single_object_cannot_be_submitted_in_workflow          (EMH_BOM0BOMMANAGEMENT_error_base + 61)

/**
* The selections were not submitted.
*/
#define BOM0BOMMANAGEMENT_multiple_objects_cannot_be_submitted_in_workflow       (EMH_BOM0BOMMANAGEMENT_error_base + 62)

/** @} */
#endif
