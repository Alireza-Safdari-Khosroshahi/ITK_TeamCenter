/*==============================================================================
                Copyright (c) 2007 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file
    Metaframework errors
*/

/*  */

#ifndef METAFRAMEWORK_ERRORS_H
#define METAFRAMEWORK_ERRORS_H

#include <common/emh_const.h>


/** Meta Framework internal error %1$. */
#define METAFRAMEWORK_unknown                                       (EMH_METAFRAMEWORK_error_base + 0)

/** The specified tag %1$ has been deleted. The requested object cannot be found. */
#define METAFRAMEWORK_object_deleted                                (EMH_METAFRAMEWORK_error_base + 1)

/** The tag %1$ is invalid. The requested object does not exist. */
#define METAFRAMEWORK_invalid_tag                                   (EMH_METAFRAMEWORK_error_base + 2)

/** The class Id %1$ is invalid. */
#define METAFRAMEWORK_invalid_class_id                              (EMH_METAFRAMEWORK_error_base + 3)

/** The class name %1$ is invalid. */
#define METAFRAMEWORK_invalid_class_name                            (EMH_METAFRAMEWORK_error_base + 4)

/** The Business Object %1$ is invalid. */
#define METAFRAMEWORK_invalid_BusinessObject                        (EMH_METAFRAMEWORK_error_base + 5)

/** The parent of the Business Object %1$ does not exist. */
#define METAFRAMEWORK_no_parent_BusinessObj                         (EMH_METAFRAMEWORK_error_base + 6)

/** The registry of the Business Object %1$ cannot be found. */
#define METAFRAMEWORK_no_registry_info                              (EMH_METAFRAMEWORK_error_base + 7)

/** The object %1$ failed to be loaded. */
#define METAFRAMEWORK_load_object_fail                              (EMH_METAFRAMEWORK_error_base + 8)

/** Wrong Class Error: the class %1$ is given when %2$ is expected. */
#define METAFRAMEWORK_wrong_class                                   (EMH_METAFRAMEWORK_error_base + 9)

/** The constructor of the Business Object %1$ does not exist. */
#define METAFRAMEWORK_no_constructor                                (EMH_METAFRAMEWORK_error_base + 10)

/** The Business Operation type %1$ is unknown. */
#define METAFRAMEWORK_unknown_OpeationType                          (EMH_METAFRAMEWORK_error_base + 11)

/** The creation of the Business Object %1$ has failed. */
#define METAFRAMEWORK_businessObj_creation_fail                     (EMH_METAFRAMEWORK_error_base + 12)

/** The access to the Business Object generic property %1$ has failed. */
#define METAFRAMEWORK_generic_accessory_fail                        (EMH_METAFRAMEWORK_error_base + 13)

/** The input object %1$ to the Create operation failed for the Business Object %2$. */
#define METAFRAMEWORK_create_input_object_fail                      (EMH_METAFRAMEWORK_error_base + 14)

/** No library can be found for the Business Object %1$. */
#define METAFRAMEWORK_library_not_found                             (EMH_METAFRAMEWORK_error_base + 15)

/** The creation of the Business Object %1$ is not implemented. */
#define METAFRAMEWORK_create_not_implemented                        (EMH_METAFRAMEWORK_error_base + 16)

/** The library %1$ cannot be loaded. */
#define METAFRAMEWORK_unable_to_load_library                        (EMH_METAFRAMEWORK_error_base + 17)

/** The symbol %1$ in library %2$ cannot be executed. */
#define METAFRAMEWORK_unable_to_execute_symbol                      (EMH_METAFRAMEWORK_error_base + 18)

/** The symbol %1$ cannot be found in library %2$. */
#define METAFRAMEWORK_fail_to_found_symbol                          (EMH_METAFRAMEWORK_error_base + 19)

/** A license key has already been registered for %1$. */
#define METAFRAMEWORK_license_key_already_registered                (EMH_METAFRAMEWORK_error_base + 20)

/** The creation of the abstract class %1$ is prohibited. */
#define METAFRAMEWORK_prohibit_creating_abstract_class              (EMH_METAFRAMEWORK_error_base + 21)

/** The &quot;SaveAs&quot; operation is not implemented for the Business Object %1$. */
#define METAFRAMEWORK_SaveAs_not_implemented                        (EMH_METAFRAMEWORK_error_base + 22)

/** The &quot;PerformDeepCopy&quot; operation is not implemented for the Business Object %1$. */
#define METAFRAMEWORK_PerformDeepCopy_not_implemented               (EMH_METAFRAMEWORK_error_base + 23)

/** A null listener cannot be attached to the class &quot;%1$&quot;. */
#define METAFRAMEWORK_attach_null_listener                          (EMH_METAFRAMEWORK_error_base + 24)

/** The listener is already attached to the class &quot;%1$&quot;. */
#define METAFRAMEWORK_listener_already_attached                     (EMH_METAFRAMEWORK_error_base + 25)

/** The Business Object creation has failed for the abstract Business Object &quot;%1$&quot;. Please contact your site administrator. */
#define METAFRAMEWORK_cannot_create_abstract_BO                     (EMH_METAFRAMEWORK_error_base + 26)

/** The children could not be retrieved for the property &quot;%1$&quot;. */
#define METAFRAMEWORK_cannot_get_children_for_property              (EMH_METAFRAMEWORK_error_base + 27)

/** The deserialization of the Business Object &quot;%1$&quot; has failed. A serialized state of this object was found, but an unexpected error occurred during deserialization, and all unsaved changes are lost. Please contact your system administrator and check the following Teamcenter server log file: %2$. */
#define METAFRAMEWORK_deserialization_fail                          (EMH_METAFRAMEWORK_error_base + 28)

/** The creation of a shadow object for non-persistent Business Object &quot;%1$&quot; is prohibited. */
#define METAFRAMEWORK_prohibit_creating_shadow_non_persistent_BO    (EMH_METAFRAMEWORK_error_base + 29)

/** The context provider property contains an invalid configuration parameter set. */
#define METAFRAMEWORK_invalid_context                               (EMH_METAFRAMEWORK_error_base + 30)

/** The generation of Deep Copy Data has failed, because no traversal data is provided or no rule cache can be found. Please contact your site administrator. */
#define METAFRAMEWORK_traversal_no_data                             (EMH_METAFRAMEWORK_error_base + 31)

/** The generation of Deep Copy Data has failed, because the traversal contains the invalid relationship type "%1$". Please contact your site administrator. */
#define METAFRAMEWORK_traversal_invalid_relationship_type           (EMH_METAFRAMEWORK_error_base + 32)

/** The generation of Deep Copy Data has failed, because of the following error: %1$. Please contact your site administrator. */
#define METAFRAMEWORK_traversal_invalid_data                        (EMH_METAFRAMEWORK_error_base + 33)

/** The Smart UID "%1$" version %2$ is not supported by this version of Teamcenter. */
#define METAFRAMEWORK_smartuid_unsupported_version                  (EMH_METAFRAMEWORK_error_base + 34)

/** The Smart UID "%1$" is invalid. */
#define METAFRAMEWORK_smartuid_is_invalid                           (EMH_METAFRAMEWORK_error_base + 35)

/** The Smart UID "%1$" contains an invalid configuration block. */
#define METAFRAMEWORK_smartuid_invalid_config_block                 (EMH_METAFRAMEWORK_error_base + 36)

/** The Smart UID "%1$" contains an invalid object reference. */
#define METAFRAMEWORK_smartuid_invalid_object                       (EMH_METAFRAMEWORK_error_base + 37)

/** Smart UIDs do not support the input configuration parameter set. */
#define METAFRAMEWORK_smartuid_unsupported_cparam                   (EMH_METAFRAMEWORK_error_base + 38)

/** The Bulk Input object creation has failed. Please contact your site administrator. */
#define METAFRAMEWORK_create_bulk_input_object_fail                 (EMH_METAFRAMEWORK_error_base + 39)

/** The Bulk Data object creation has failed. Please contact your site administrator. */
#define METAFRAMEWORK_create_bulkdata_object_fail                   (EMH_METAFRAMEWORK_error_base + 40)

/** At least one of the object-based operations ("saveAsPost" and/or "performDeepCopy") for the "saveAs" operation is not refactored to be set-based for the Business Object type "%1$". Please implement the set-based operation corresponding to the object-based operation. */
#define METAFRAMEWORK_fnd0saveas_not_set_based                      (EMH_METAFRAMEWORK_error_base + 41)

/** At least one of the object-based operations ("revise", "revisePost" and/or "performDeepCopy") for the "revise" operation is not refactored to be set-based for the Business Object type "%1$". Please implement the set-based operation corresponding to the object-based operation. */
#define METAFRAMEWORK_fnd0revise_not_set_based                      (EMH_METAFRAMEWORK_error_base + 42)

/** The set-based operation ("%1$") is not refactored for the Business Object type "%2$". Please implement the set-based operation. */
#define METAFRAMEWORK_operation_not_set_based                       (EMH_METAFRAMEWORK_error_base + 43)

/** At least one of the object-based operations ("createPost") for the "create" operation is not refactored to be set-based for the Business Object type "%1$". Please implement the set-based operation corresponding to the object-based operation. */
#define METAFRAMEWORK_fnd0create_not_set_based                      (EMH_METAFRAMEWORK_error_base + 44)

/** The object provided is not a Runtime Business Object. */
#define METAFRAMEWORK_invalid_runtimebusinessobject                 (EMH_METAFRAMEWORK_error_base + 45)

/** The newly created object tag does not match the preallocated object tag. */
#define METAFRAMEWORK_preallocated_tag_mismatched                   (EMH_METAFRAMEWORK_error_base + 46)

#endif
