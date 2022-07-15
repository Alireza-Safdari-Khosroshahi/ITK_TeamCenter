/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2013.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

*/

#ifndef MDO_ERRORS_H
#define MDO_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup MDO_ERRORS Multi-Disciplinary Objects Errors
    @ingroup MDO
    @{
*/

#define MDO_ERROR_BASE                                             EMH_MDO_error_base

/**
   The Multi-Disciplinary Object input object is empty. Please refer to the Teamcenter server syslog file for more information.
*/
#define MDO_mdthread_input_empty                                   (MDO_ERROR_BASE + 1)

/**
   A relation already exists between the given primary "%1$" and secondary "%2$".
*/
#define MDO_mdthread_duplicate_relation                            (MDO_ERROR_BASE + 2)

/**
   The secondary input object is empty. Please refer to the Teamcenter server syslog file for more information.
*/
#define MDO_secondary_empty                                        (MDO_ERROR_BASE + 3)

/**
   The Multi-Disciplinary Object "%1$" is not checked-out.
*/
#define MDO_primary_not_checkedout                                 (MDO_ERROR_BASE + 4)

/**
   The logged-in user does not have the "%1$" privilege to author Multi-Disciplinary Objects. Please check with your system administrator.
*/
#define MDO_not_a_privilege_user                                   (MDO_ERROR_BASE + 5)

/**
   At least one design artifact associated with the Multi-Disciplinary Object "%1$" is consumed in a project.
*/
#define MDO_design_artifact_in_use                                 (MDO_ERROR_BASE + 6)

/**
   The design artifact "%1$" is consumed in the following projects: %2$.
*/
#define MDO_secondary_consumed                                     (MDO_ERROR_BASE + 7)

/**
   The Multi-Disciplinary Object "%1$" needs to be released first. Exchange is not allowed on unreleased Multi-Disciplinary Objects.
*/
#define MDO_is_not_released                                        (MDO_ERROR_BASE + 8)

/**
   The type of the provided design artifact "%1$" is not valid. Valid design artifacts are of one of the following types: %2$.
*/
#define MDO_invalid_design_artifact_type                           (MDO_ERROR_BASE + 9)

/**
   The provided design artifact "%1$" is not valid. The underlying Library Object of a Library Element should be of Item Revision type.
*/
#define MDO_invalid_library_element                                (MDO_ERROR_BASE + 10)

/**
   The following design instances cannot be linked, because some of them are already linked to different Multi-Disciplinary instances: %1$. Select only design instances that belong to one Multi-Disciplinary instance or that are not linked to any Multi-Disciplinary instance.
*/
#define MDO_already_in_mdinstance_group                            (MDO_ERROR_BASE + 11)

/**
   The following design instances cannot be unlinked, because they are not linked to any Multi-Disciplinary instances: %1$.
*/
#define MDO_no_mdinstances_found                                   (MDO_ERROR_BASE + 12)

/**
   The following design instances cannot be unlinked from each other, because they are not all linked to the same Multi-Disciplinary instance: %1$.
*/
#define MDO_multiple_mdinstances_found                             (MDO_ERROR_BASE + 13)

/**
   Either design instances or a valid context must be specified for searching.
*/
#define MDO_missing_search_parameters                              (MDO_ERROR_BASE + 14)

/**
   At least one Design Instance must be specified in the input.
*/
#define MDO_input_has_no_design_instances                          (MDO_ERROR_BASE + 15)

/**
   The Multi-Disciplinary Association relation type "%1$" is not found.
*/
#define MDO_relation_type_not_found                                (MDO_ERROR_BASE + 16)

/**
   The Multi-Disciplinary Object creation needs at least "%1$" design artifact(s).
*/
#define MDO_insufficient_design_artifact                           (MDO_ERROR_BASE + 17)

/**
   An error has occurred while associating the design artifacts to the Multi-Disciplinary Object "%1$". Please refer to the Teamcenter syslog file for more information.
*/
#define MDO_failed_to_create_relation                              (MDO_ERROR_BASE + 18)

/**
   The properties update of the Multi-Disciplinary Object "%1$" has failed. Please refer to the Teamcenter syslog file for more information.
*/
#define MDO_failed_to_update_mdo_property                          (MDO_ERROR_BASE + 19)

/**
   The creation of a Multi-Disciplinary Object has failed. Please refer to the Teamcenter syslog file for more information.
*/
#define MDO_mdo_creation_failed                                    (MDO_ERROR_BASE + 20)

/**
   Either design or a valid context must be specified for searching Multi-Disciplinary Object notifications.
*/
#define MDO_notification_search_parameter_empty                    (MDO_ERROR_BASE + 21)

/**
   Only a design or a valid context must be specified for searching Multi-Disciplinary Object notifications.
*/
#define MDO_notification_invalid_search_parameter                  (MDO_ERROR_BASE + 22)

/**
   At least one common context must be specified in the input.
*/
#define MDO_no_common_context_found                                (MDO_ERROR_BASE + 23)

/**
   No original design instance is provided.
*/
#define MDO_orig_design_instance_is_empty                          (MDO_ERROR_BASE + 24)

/**
   No target design instance is provided.
*/
#define MDO_target_design_instance_is_empty                        (MDO_ERROR_BASE + 25)

/**
   The provided design instances "%1$" and "%2$" must both be Model Elements.
*/
#define MDO_both_must_be_modelelements                             (MDO_ERROR_BASE + 26)

/**
   The provided design artifacts "%1$" and "%2$" are not revisions of the same item.
*/
#define MDO_not_revisions_of_same_item                             (MDO_ERROR_BASE + 27)

/**
   The provided design artifacts "%1$" and "%2$" must both be types of Item Revision.
*/
#define MDO_both_must_be_itemrev_types                             (MDO_ERROR_BASE + 28)

/**
   No original design artifact is provided.
*/
#define MDO_orig_design_artifact_is_empty                          (MDO_ERROR_BASE + 29)

/**
   No target design artifact is provided.
*/
#define MDO_target_design_artifact_is_empty                        (MDO_ERROR_BASE + 30)

/**
   The provided design elements "%1$" and "%2$" are not revisions of the same model element.
*/
#define MDO_not_revisions_of_same_model_element                    (MDO_ERROR_BASE + 31)

/**
   Either the MDThread, a design artifact, a design instance or the flag to query all the MDThread or MDInstance association needs to be specified for search.   
*/
#define MDO_no_search_input                                        (MDO_ERROR_BASE + 32)

/**   
   The following domain names are invalid because they are not listed in the preference "MECH_domain_list": %1$.
*/
#define MDO_domain_name_is_not_in_list                             (MDO_ERROR_BASE + 33)

/**
   No design artifact is provided.
*/
#define MDO_design_artifact_is_empty                               (MDO_ERROR_BASE + 34)

/**
   The following design artifacts are not linked to the same Multi-Disciplinary Object: %1$.
*/
#define MDO_no_mdthreads_found                                     (MDO_ERROR_BASE + 35)

/**
   All design artifacts are not the latest revisions.
*/
#define MDO_design_artifacts_are_not_latest_rev                    (MDO_ERROR_BASE + 36)

/**
   All design instances are not the latest revisions.
*/
#define MDO_design_instances_are_not_latest_rev                    (MDO_ERROR_BASE + 37)

/**
   The following design instances are not all linked to the same set of Multi-Disciplinary Instances: %1$.
*/
#define MDO_design_instances_not_all_linked_same_mdis              (MDO_ERROR_BASE + 38)

/**
   No design artifact or design instance is provided.
*/
#define MDO_design_artifact_or_instance_is_empty                   (MDO_ERROR_BASE + 39)

/**
  The following design instances are released and cannot be unlinked from the Multi-Disciplinary instance: %1$. 
*/
#define MDO_cannot_unlink_released_design_instances                (MDO_ERROR_BASE + 40)

/**
   The input design instance is not specified for searching.
*/
#define MDO_search_design_instance_is_empty                        (MDO_ERROR_BASE + 41)

/**
   The configured Item Revision for the input BVR Instance is empty.
*/
#define MDO_configured_item_revision_is_empty                      (MDO_ERROR_BASE + 42)

/**
   The top line Item Revision for BVR Assembly is empty for input BVR instance.
*/
#define MDO_topline_item_revision_is_empty                         (MDO_ERROR_BASE + 43)

/**
   The occurrence thread path for input BVR instance is empty.
*/
#define MDO_occurrence_thread_path_is_empty                        (MDO_ERROR_BASE + 44)

/**
   The BVR instance object creation has failed.
*/
#define MDO_bvr_instance_cannot_be_created                         (MDO_ERROR_BASE + 45)

/**
   The absolute occurrence of the input BVR instance is null.
*/
#define MDO_absolute_occurrence_is_null                            (MDO_ERROR_BASE + 46)

/**
   The PSInstance Object(s) cannot be deleted.
*/
#define MDO_cannot_delete_psinstance_object                        (MDO_ERROR_BASE + 47)

/** @} */

#endif

