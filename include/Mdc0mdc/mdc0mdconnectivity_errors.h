/*=============================================================================
 Copyright 2020 Siemens Digital Industries Software
 ==================================================
 Copyright 2015
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2020 Siemens Digital Industries Software
 ===============================================================================*/

/**
    @file

    This header file declares all error codes to be used by MDConnectivity.

*/

#ifndef MDC0MDC_ERRORS_H
#define MDC0MDC_ERRORS_H

#include <common/emh_const.h>


/**
    @defgroup MDC0MDC_ERRORS Errors
    @ingroup MDC0MDC
    @{
*/

#define MDC0MDC_ERROR_BASE                                  EMH_MDCONNECTIVITY_error_base

/** The "Model Element" object belongs to more than one "Partition" object. Hence a unique name cannot be generated for it. */
#define MDC0MDC_no_unique_model_element                     (MDC0MDC_ERROR_BASE + 1)

/** The creation or modification of an "Ordered Element Group" object requires a valid "Conditional Element Group" object. */
#define MDC0MDC_no_conditional_element                      (MDC0MDC_ERROR_BASE + 2)

/** The "Connection Element" object cannot be empty. */
#define MDC0MDC_no_connection_element                       (MDC0MDC_ERROR_BASE + 3)

/** The "Conditional Element Group" "%1$" cannot be deleted, because an "Ordered Element Group" object already exists for it. Delete the "Ordered Element Group" object first. */
#define MDC0MDC_cannot_delete_conditional_element           (MDC0MDC_ERROR_BASE + 4)

/** The "Application Model" object must be provided to create the object */
#define MDC0MDC_missing_appmodel_object                     (MDC0MDC_ERROR_BASE + 5)

/** The object &quot;%1$&quot; cannot be updated because it has been modified in a different session. Refresh the object before making any new modifications. */
#define MDC0MDC_object_is_modified                          (MDC0MDC_ERROR_BASE + 6)

/** The "Ordered Element Group" object must be provided to modify the object. */
#define MDC0MDC_no_ordered_element                          (MDC0MDC_ERROR_BASE + 7)

/** The specified index &quot;%1$&quot; to split the "Ordered Element Group" object is greater than the length of the list minus one which leaves insufficient elements to split. */
#define MDC0MDC_invalid_split_index                         (MDC0MDC_ERROR_BASE + 8)

/** The "Model Element" object cannot be empty. */
#define MDC0MDC_no_model_element                            (MDC0MDC_ERROR_BASE + 9)

/** The ordered element list to split does not contain any elements. */
#define MDC0MDC_no_ordered_list_to_split                    (MDC0MDC_ERROR_BASE + 10)

/** The object to split is either empty or not a connection element. */
#define MDC0MDC_no_split_connection_invalid                 (MDC0MDC_ERROR_BASE + 11)

 /** The element list to insert into the Ordered Element Group is empty. */
#define MDC0MDC_empty_insert_element_list                   (MDC0MDC_ERROR_BASE + 12)

/** The provided index to insert into the Ordered Element Group cannot be less than or equal to zero. */
#define MDC0MDC_invalid_insert_index                        (MDC0MDC_ERROR_BASE + 13)

/** The provided index to split the Ordered Element Group cannot be less than one. */
#define MDC0MDC_split_index_less_than_one                   (MDC0MDC_ERROR_BASE + 14)

/** The "Conditional Element" object cannot be empty. */
#define MDC0MDC_no_conditional_element_provided             (MDC0MDC_ERROR_BASE + 15)

/** The "Ordered Element Group" object &quot;%1$&quot; is not part of any Conditional element group, and cannot therefore be removed*/
#define MDC0MDC_cannot_remove_ordered_element               (MDC0MDC_ERROR_BASE + 16)

/** At least one BOM Line object contains a quantity value on an occurrence. Carrying forward of quantity values to Logical Elements is not supported*/
#define MDC0MDC_source_has_quantity_value                   (MDC0MDC_ERROR_BASE + 17)

/** An object of type Ordered Element Group must be provided.*/
#define MDC0MDC_no_oeg                                      (MDC0MDC_ERROR_BASE + 18)

/** The Conditional Element Group "%1$" is not effective for the given configuration. Please provide the correct configuration. */
#define MDC0MDC_ceg_not_effective                           (MDC0MDC_ERROR_BASE + 19)

/** The object of type Port Artifact cannot be empty. */
#define MDC0MDC_no_port_artifact_provided                   (MDC0MDC_ERROR_BASE + 20)

/** Either the Logical Element or the Partition must be provided when querying ports. */
#define MDC0MDC_no_element_or_partition_provided            (MDC0MDC_ERROR_BASE + 21)

/** The Logical Element object must be provided to query port objects. */
#define MDC0MDC_no_logical_element_provided                 (MDC0MDC_ERROR_BASE + 22)

/** The "Partition" object must be provided when querying objects in a partition. */
#define MDC0MDC_no_partition_provided                       (MDC0MDC_ERROR_BASE + 23)

/** The provided Port Discipline value is not a valid member of the discipline list of values. Please contact your system administrator.*/
#define MDC0MDC_invalid_port_discipline_value               (MDC0MDC_ERROR_BASE + 24)

/** The provided Port Direction value is not a valid member of the direction list of values. Please contact your system administrator.*/
#define MDC0MDC_invalid_port_direction_value                (MDC0MDC_ERROR_BASE + 25)

/** An internal error has occurred in the MD Connectivity module. Report this error to your system administrator.*/
#define MDC0MDC_internal_error                              (MDC0MDC_ERROR_BASE + 26)

/** The source object must be provided for item realizations */
#define MDC0MDC_no_source_object                            (MDC0MDC_ERROR_BASE + 27)

/** The realization updater could not find a parent Logical Element while creating the subordinate Logical Element for it. This is most likely an issue with the source structure setup. Please contact your system administrator. */
#define MDC0MDC_null_parent_logical_element_for_subordinate (MDC0MDC_ERROR_BASE + 28)

/** The realization updater could not find any Logical Element object for the parent BOM Line "%1$" while creating the child Logical Element object. This is most likely an issue with the source structure setup. Please contact your system administrator. */
#define MDC0MDC_parent_logical_element_does_not_exist       (MDC0MDC_ERROR_BASE + 29)

/** The "Logical Element" object could not be created. Please refer to the Teamcenter server syslog file for a possible cause of error */
#define MDC0MDC_could_not_create_logical_element            (MDC0MDC_ERROR_BASE + 30)

/** The "Port Artifact" object could not be created. Please refer to the Teamcenter server syslog file for a possible cause of error */
#define MDC0MDC_could_not_create_port_artifact              (MDC0MDC_ERROR_BASE + 31)

/** The object &quot;%1$&quot; cannot be deleted because it contains children. Please expand the object and delete all its children first */
#define MDC0MDC_element_has_children                        (MDC0MDC_ERROR_BASE + 32)


/** @} */

#endif
