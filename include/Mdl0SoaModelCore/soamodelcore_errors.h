/*
Copyright 2020 Siemens Digital Industries Software
/==================================================
/Copyright 2011.
/Siemens Product Lifecycle Management Software Inc.
/All Rights Reserved.
/==================================================
/Copyright 2020 Siemens Digital Industries Software
*/

#ifndef SOAMODELCORE_ERRORS_H
#define SOAMODELCORE_ERRORS_H

#include <common/emh_const.h>

#define SOAMODELCORE_ERROR_BASE                                 EMH_SOA_MODELCORE_error_base   /* 284000 */

/**
 * No type could be found for the given name.
 */
#define SOAMODELCORE_no_tctype_found                                                               ( SOAMODELCORE_ERROR_BASE + 1 )

/**
 * The Business Object could not be created. Please check the syslog file for more information.
 */
#define SOAMODELCORE_object_not_created                                                            ( SOAMODELCORE_ERROR_BASE + 2 )

/**
 * Revisioning is not supported for the Business Object.
 */
#define SOAMODELCORE_revise_not_supported_for_BO                                                   ( SOAMODELCORE_ERROR_BASE + 3 )

/**
 * No target Application Model was provided as input.
 */
#define SOAMODELCORE_clone_no_target_applicationmodel_provided_as_input                            ( SOAMODELCORE_ERROR_BASE + 4 )

/**
 * No source Application Model was provided as input.
 */
#define SOAMODELCORE_clone_no_source_applicationmodel_provided_as_input                            ( SOAMODELCORE_ERROR_BASE + 5 )

/**
 * The relation attribute is not yet implemented. Only the attribute mdl0cs_id is currently supported.
 */
#define SOAMODELCORE_relation_attribute_not_implemented                                            ( SOAMODELCORE_ERROR_BASE + 6 )

/**
 * An invalid relation traversal input is specified. The source object cannot be NULL.
 */
#define SOAMODELCORE_invalid_relation_traversal_input_s                                            ( SOAMODELCORE_ERROR_BASE + 7 )

/**
 * An invalid relation traversal input is specified. The type does not exist.
 */
#define SOAMODELCORE_invalid_relation_traversal_input_i                                            ( SOAMODELCORE_ERROR_BASE + 8 )

/**
 * An invalid relation traversal input is specified. The attribute type can only be a string and the attribute values can only have string values.
 */
#define SOAMODELCORE_invalid_relation_traversal_input_a                                            ( SOAMODELCORE_ERROR_BASE + 9 )

/**
 * Either an invalid or an empty constraint collection is sent to the "update" operation.
 */
#define SOAMODELCORE_invalid_or_null_constraint_collection_for_update                              ( SOAMODELCORE_ERROR_BASE + 10 )

/**
 * An internal error has occurred: %1$.
 */
#define SOAMODELCORE_internal_error                                                                ( SOAMODELCORE_ERROR_BASE + 11 )

/**
 * An object of type "%1$" is required to create a group.
 */
#define SOAMODELCORE_missing_model_object_for_group                                                ( SOAMODELCORE_ERROR_BASE + 12 )

/**
 * A value of type "%1$" is required to create a group.
 */
#define SOAMODELCORE_missing_logical_id_for_group                                                  ( SOAMODELCORE_ERROR_BASE + 13 )

/**
 * An object cannot be both the start and the end of a geometric link.
 */
#define SOAMODELCORE_link_to_self                                                                   ( SOAMODELCORE_ERROR_BASE + 14 )

/**
 * The operation is not supported for this release.
 */
#define SOAMODELCORE_operation_not_supported                                                        ( SOAMODELCORE_ERROR_BASE + 15 )

/**
 * The calculation of the Effectivity has failed. Please consult the Teamcenter syslog for more information.
 */
#define SOAMODELCORE_get_calculated_effectivity_failed                                              ( SOAMODELCORE_ERROR_BASE + 16 )

#endif  /* SOAMODELCORE_ERRORS_H */
