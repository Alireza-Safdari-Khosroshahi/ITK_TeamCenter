/*=============================================================================
Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright 2019
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software
===============================================================================*/

/**
@file

Cla0classification Error Codes Declaration

*/

#ifndef CLA0CLASSIFICATION_ERRORS_H
#define CLA0CLASSIFICATION_ERRORS_H

#include <common/emh_const.h>

/**
@defgroup CLA0CLASSIFICATION_ERRORS_H CLA Errors
@ingroup CLA
@{
*/

#define CLA0CLASSIFICATION_ERROR_BASE                                        EMH_CLA_error_base


/**
@name Parameter validation errors
@{
*/
/** The schema file "%1$" could not be found. */
#define CLA_err_schema_file_not_found                                      ( CLA0CLASSIFICATION_ERROR_BASE + 1 )

/** The schema validation has failed. The path to the violated rule in the schema file is "%1$" and the violated schema keyword is "%2$". */
#define CLA_err_schema_validation                                          ( CLA0CLASSIFICATION_ERROR_BASE + 2 )

/** The input request is not a valid JSON file. */
#define CLA_err_no_valid_json                                              ( CLA0CLASSIFICATION_ERROR_BASE + 3 )

/** The JSON data could not be parsed. */
#define CLA_err_parse_json_error                                           ( CLA0CLASSIFICATION_ERROR_BASE + 4 )

/** The specified classification node with ID "%1$" cannot be found. */
#define CLA_err_node_not_found                                             ( CLA0CLASSIFICATION_ERROR_BASE + 5 )

/** The specified classification object with ID "%1$" cannot be found. */
#define CLA_err_missing_classification_object                              ( CLA0CLASSIFICATION_ERROR_BASE + 6 )

/** "%1$" cannot be used for classification. Please use a unique object ID or a name for classification. */
#define CLA_err_object_to_classify_not_unique                              ( CLA0CLASSIFICATION_ERROR_BASE + 7 )

/** Classification nodes from multiple classification systems are not currently supported in save objects request. */
#define CLA_err_mixed_nodes_not_supported                                  ( CLA0CLASSIFICATION_ERROR_BASE + 8 )

/** Classification objects from multiple classification systems are not currently supported in get or delete objects request. */
#define CLA_err_mixed_classification_objects_not_supported                 ( CLA0CLASSIFICATION_ERROR_BASE + 9 )

/** The required "Library Management" template is not installed. Please contact your system administrator. */
#define CLA_err_librarymgmt_not_installed                                  ( CLA0CLASSIFICATION_ERROR_BASE + 10 )

/** The context information is not valid, because the specified "%1$" with ID "%2$" cannot be found. Please provide the ID of an existing "%1$". */
#define CLA_err_context_not_valid                                          ( CLA0CLASSIFICATION_ERROR_BASE + 11 )

/** Save operation is not allowed on a Library Node "%1$" because it is not referenced to any Classification Node. Please contact your system administrator. */
#define CLA_err_not_a_classifying_node                                     ( CLA0CLASSIFICATION_ERROR_BASE + 12 )

/** The json file could not be found in transient volume. */
#define CLA_err_file_not_found_in_transient_volume                         ( CLA0CLASSIFICATION_ERROR_BASE + 13 )

/** The Save operation could not be completed because the ClassificationObject at index "%1$" is missing one or more required items ID, NodeID, or UnitySystem. */
#define CLA_err_invalid_object                                             ( CLA0CLASSIFICATION_ERROR_BASE + 14 )

/** The Save operation could not be completed because the ClassificationProperty belonging to "%1$" at index "%2$" is missing one or more required items DataType or ID. */
#define CLA_err_invalid_property                                           ( CLA0CLASSIFICATION_ERROR_BASE + 15 )

/** The input object ID list cannot be empty in get or delete objects request. */
#define CLA_err_input_IDs_empty                                            ( CLA0CLASSIFICATION_ERROR_BASE + 16 )

/** The save operation could not be completed because the input Classification object list is empty. */
#define CLA_err_input_empty                                                ( CLA0CLASSIFICATION_ERROR_BASE + 17 )

/** @} */
/** @} */

#endif
