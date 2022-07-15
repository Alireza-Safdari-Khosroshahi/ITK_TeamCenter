/*==============================================================================
                Copyright (c) 2009 Siemens Inc
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This file contains the publish identifiers of error codes that can be
    generated by eda module. Obtaining and using the numeric values of these
    manifest constants is not supported. We reserve the right to change the
    actual values as necessary.
*/

/*  */

#ifndef EDA_ERRORS_H
#define EDA_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup EDA_ERRORS EDA Errors
    @ingroup EDA
    @{
*/

/**An internal error occurred in the EDA module "%1$".*/
#define EDA_internal_error                                                       (EMH_EDA_error_base + 1)

/**The EDA derived data "%1$" cannot be created.*/
#define EDA_DERIVED_DATA_unable_to_create                                        (EMH_EDA_error_base + 2)

/**The EDA derived Item "%1$" cannot be created.*/
#define EDA_DERIVED_ITEM_unable_to_create                                        (EMH_EDA_error_base + 3)

/**The EDA derived Dataset "%1$" cannot be created.*/
#define EDA_DERIVED_DATASET_unable_to_create                                     (EMH_EDA_error_base + 4)

/**"%1$" cannot be published. Please register publish intent before publishing.*/
#define EDA_no_reserve                                                           (EMH_EDA_error_base + 5)

/**"%1$" cannot be published because it is reserved for "%2$".*/
#define EDA_reserved_for_different_intent                                        (EMH_EDA_error_base + 6)

/**IDX Baseline cannot be published because the domain "%1$" is publishing a new IDX Increment.*/
#define EDA_baseline_publish_not_allowed_reserved_for_increment                  (EMH_EDA_error_base + 7)

/**"%1$" cannot be published because the preceding IDX increment is being processed.*/
#define EDA_increment_in_process                                                 (EMH_EDA_error_base + 8)

/**"%1$" cannot be published because the preceding IDX increment has an IDX response to be processed.*/
#define EDA_response_in_process                                                  (EMH_EDA_error_base + 9)

/**IDX Baseline cannot be published, because the IDX Increment from the other domain is in published state.*/
#define EDA_baseline_publish_not_allowed_increment_in_published_state            (EMH_EDA_error_base + 10)

/**IDX Increment cannot be published, because the IDX Increment from the other domain is in published state.*/
#define EDA_increment_publish_not_allowed_by_other_domain                        (EMH_EDA_error_base + 11)

/**"%1$" cannot be published because there are more than one active IDX Baseline for the same domain.*/
#define EDA_more_than_one_active_increment_exists                                (EMH_EDA_error_base + 12)

/**"%1$" cannot be published because there are more than one active IDX Increment for the same domain.*/
#define EDA_more_than_one_active_baseline_exists                                 (EMH_EDA_error_base + 13)

/**IDX Response cannot be published, because the IDX Increment is not downloaded for review. Please download the IDX Increment for processing.*/
#define EDA_publish_response_not_allowed                                         (EMH_EDA_error_base + 14)

/**"HasRelatedIDX" relation cannot be created because it is not supported for the given primary and secondary type.*/
#define EDA_has_related_idx_relation_not_allowed                                 (EMH_EDA_error_base + 15)

/**IDX cannot be published because an IDX file exists on the dataset.*/
#define EDA_named_reference_upload_not_allowed                                   (EMH_EDA_error_base + 16)

/**IDX Response cannot be published because the IDX Increment is owned by same domain.*/
#define EDA_publish_response_not_allowed_wrong_domain                            (EMH_EDA_error_base + 17)

/**IDX Increment cannot be published because the domain "%1$" is publishing a new IDX Baseline.*/
#define EDA_increment_publish_not_allowed_reserved_for_baseline                  (EMH_EDA_error_base + 18)

/**The input design is invalid.*/
#define EDA_invalid_design                                                       (EMH_EDA_error_base + 19)

/**The intent for publishing "%1$" cannot be registered because the intent is invalid. The valid values are "IDXBaseline" or "IDXIncrement"*/
#define EDA_invalid_intent                                                       (EMH_EDA_error_base + 20)

/**The intent for publishing "%1$" cannot be registered because there is no IDX Baseline associated with the design.*/
#define EDA_no_non_obsolete_baseline                                             (EMH_EDA_error_base + 21)

/**The intent for publishing "%1$" cannot be registered because the IDX Baseline is reserved by other domain.*/
#define EDA_baseline_reserved_by_other_domain                                    (EMH_EDA_error_base + 22)

/**The intent for publishing "%1$" cannot be registered because the preceding IDX increment from the same domain is being processed.*/
#define EDA_register_not_allowed_preceding_increment_in_process                  (EMH_EDA_error_base + 23)

/**The intent for publishing "%1$" cannot be registered because the preceding IDX increment from the same domain has an IDX Response to be processed. Please download the IDX Response for processing.*/
#define EDA_register_not_allowed_preceding_increment_has_response_in_process     (EMH_EDA_error_base + 24)

/**The intent for publishing the IDX Baseline cannot be registered because there is an unprocessed IDX Increment from other domain which is not processed yet. Please download the IDX Increment for processing.*/
#define EDA_baseline_register_not_allowed_unprocessed_increment_by_other_domain  (EMH_EDA_error_base + 25)

/**The intent for publishing "%1$" is registered successfully. However, there exists an IDX Increment published by your domain, which would be marked obsolete, if you proceed to publish the IDX object. Please cancel the registered intent if this is not intended.*/
#define EDA_increment_published_by_same_domain_would_be_obsolete                 (EMH_EDA_error_base + 26)

/**The intent for publishing "%1$" is already registered successfully. Please proceed to publish the IDX object.*/
#define EDA_intent_already_registered                                            (EMH_EDA_error_base + 27)

/**The intent for publishing the IDX Increment is registered successfully. However, the IDX Baseline is not downloaded by the collaborating domain. If you choose to publish a new IDX Baseline instead of an IDX Increment please cancel publish intent and subsequently call this operation with the "IDXBaseline" as the publish intent value.*/
#define EDA_baseline_not_downloaded_by_other_domain                              (EMH_EDA_error_base + 28)

/**The value provided for "%1$" is empty.*/
#define EDA_empty_input_value                                                    (EMH_EDA_error_base + 29)

/**The value "%1$" provided for the IDX Object Type is invalid. The valid values are "IDXBaseline", "IDXIncrement" or "IDXResponse".*/
#define EDA_invalid_idx_object_type                                              (EMH_EDA_error_base + 30)

/**The Object Type "%1$" is invalid. The valid values are "Eda0IDXBaseline", "Eda0IDXIncrement", "Eda0IDXResponse" or "ChangeItem".*/
#define EDA_invalid_object_type                                                  (EMH_EDA_error_base + 31)

/**The filter criteria "%1$" is invalid. The valid values are "includeObsolete", "includePendingReview" or an empty string.*/
#define EDA_invalid_filter_criteria                                              (EMH_EDA_error_base + 32)

/**The IDX data cannot be returned because there exists more than one IDX Baseline for the state "%1$".*/
#define EDA_more_than_one_active_baseline_exists_for_state                       (EMH_EDA_error_base + 33)

/**The IDX data cannot be returned because there exists more than one IDX Increment for the state "%1$".*/
#define EDA_more_than_one_active_increment_exists_for_state                      (EMH_EDA_error_base + 34)

/**The intent for publishing the IDX Object cannot be cancelled because there is no publish intent registered by "%1$".*/
#define EDA_no_intent_registered_by_calling_domain                               (EMH_EDA_error_base + 35)

/**Unable to cancel process change because there is no IDX Increment in process by the calling domain.*/
#define EDA_no_increment_in_process_by_calling_domain                            (EMH_EDA_error_base + 36)

/**The input domain "%1$" is invalid. The valid values are "%2$" and "%3$"*/
#define EDA_invalid_calling_domain                                               (EMH_EDA_error_base + 37)

/**The intent for deleting the IDX Object cannot be completed because there is no published IDX Baseline or IDX Increment which can be deleted by the calling domain.*/
#define EDA_idx_cannot_be_deleted                                                (EMH_EDA_error_base + 38)

/**The design "%1$" is not participating in any collaboration*/
#define EDA_design_with_no_collaboration                                         (EMH_EDA_error_base + 39)

/**Collaboration object to be updated is not found*/
#define EDA_collaboration_object_not_found                                       (EMH_EDA_error_base + 40)

/**The object to be attached to Collaboration is not found*/
#define EDA_design_to_attach_not_found                                           (EMH_EDA_error_base + 41)

/**The object to be detached from Collaboration is not found*/
#define EDA_design_to_detach_not_found                                           (EMH_EDA_error_base + 42)

/**The input bomlines cannot be empty.*/
#define EDA_bom_lines_empty                                                      (EMH_EDA_error_base + 43)

/**No 3D Model part files exist for the "%1$" design.*/
#define EDA_design_with_no_3d_models                                             (EMH_EDA_error_base + 44)

/**Collaboration object 'Eda0EDMDCollaboration' is not the primary object of IMAN CCContext*/
#define EDA_collaboration_not_primary                                            (EMH_EDA_error_base + 45)

/**"%1$" cannot be added to the collaboration, as two designs have already been associated with the collaboration.  */
#define EDA_collaboration_already_has_two_participating_designs                  (EMH_EDA_error_base + 46)

/**"%1$" cannot be removed because there are one or more active IDX increments*/
#define EDA_cannot_remove_designs_containing_active_increment                    (EMH_EDA_error_base + 47)

/**The collaboration data cannot be fetched because the IDX Baseline is reserved.*/
#define EDA_cannot_fetch_baseline_collab_data                                    (EMH_EDA_error_base + 48)

/**"%1$" already participates in a collaboration  */
#define EDA_design_already_participated_in_collaboration                         (EMH_EDA_error_base + 49)

/**The EDA license check failed. There is no valid license to access the ECAD MCAD Collaboration functionality.*/
#define EDA_no_valid_license                                                     (EMH_EDA_error_base + 50)

/** @} */

#endif
