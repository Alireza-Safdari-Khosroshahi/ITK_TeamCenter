/*
    Copyright 2020 Siemens Digital Industries Software
    ==================================================
    Copyright 2016.
    Siemens Product Lifecycle Management Software Inc.
    All Rights Reserved.
    ==================================================
    Copyright 2020 Siemens Digital Industries Software
*/

#ifndef APS0APSCORE_ERRORS_H
#define APS0APSCORE_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup APS0APSCORE_ERRORS Advanced PLM Services (APS) Core Errors
    @ingroup APS0APSCORE
    @{
*/

#define APS0APSCORE_ERROR_BASE                                   EMH_APS0APSCORE_error_base

/**
 * An internal error has occurred in the module Advanced PLM Services (APS) Core. Please contact your system administrator.
 */
#define APS0APSCORE_internal_error                                    ( APS0APSCORE_ERROR_BASE + 1 )

/**
 *  The provided tag is null.
 */
#define APS0APSCORE_null_tag                                          ( APS0APSCORE_ERROR_BASE + 2 )

/**
 * The user "%1$" does not have the needed privilege to access the Managed Attribute Group (MAG) Object "%2$".
 */
#define APS0APSCORE_no_access_privilege                               ( APS0APSCORE_ERROR_BASE + 3 )

/**
 * An object of type "%2$" is expected instead of a type "%1$".
 */
#define APS0APSCORE_type_not_expected                                 ( APS0APSCORE_ERROR_BASE + 4 )

/**
 * The object "%1$" cannot be revised because it does not have any status.
 */
#define APS0APSCORE_object_has_no_status                              ( APS0APSCORE_ERROR_BASE + 5 )

/**
 * The object "%1$" cannot be modified because it has been obsoleted.
 */
#define APS0APSCORE_obsolete_object_not_modifiable                    ( APS0APSCORE_ERROR_BASE + 6 )

/**
 * The object "%1$" cannot be checked-out because it has been obsoleted.
 */
#define APS0APSCORE_obsolete_object_not_checkoutable                  ( APS0APSCORE_ERROR_BASE + 7 )

/**
 * The Deep Copy Data for the selected object "%1$" cannot be retrieved.
 * Please refer to the following Teamcenter server syslog file for more information: %2$
 */
#define APS0APSCORE_object_deepcopy_data_cannot_be_retrieved          ( APS0APSCORE_ERROR_BASE + 8 )

/**
 * The object type "%1$" is not configured to allow the Revise operation.
 * If this is needed, please contact your system administrator to make the needed changes in Business Modeler IDE (BMIDE).
 */
#define APS0APSCORE_revise_not_supported                              ( APS0APSCORE_ERROR_BASE + 9 )

/**
 * The provided argument "%1$" is invalid.
 */
#define APS0APSCORE_invalid_input                                     ( APS0APSCORE_ERROR_BASE + 10 )

/**
 * The operation has no object to work on because either the supplied input objects are invalid or the supplied subset definition is empty.
 */
#define APS0APSCORE_no_objects_found_to_perform_the_operation         ( APS0APSCORE_ERROR_BASE + 11 )

/**
 * The following unsupported objects of type "%1$" are ignored for the operation: %2$.
 */
#define APS0APSCORE_unsupported_objects_ignored                       ( APS0APSCORE_ERROR_BASE + 12 )

/**
 * The processing of pending attachments has failed because attribute groups of type "%1$" can not be created with the relation type "%2$"
 */
#define APS0APSCORE_objecttype_or_relationtype_missing                ( APS0APSCORE_ERROR_BASE + 13 )

/**
 * All the revisions must be selected to carry out this operation. Please select all revisions.
 */
#define APS0APSCORE_all_revisions_not_selected                        ( APS0APSCORE_ERROR_BASE + 14 )

/**
 * The object "%1$" cannot be revised because it was created in a markup or change space.
 */
#define APS0APSCORE_cannot_revise_objects_created_in_space            ( APS0APSCORE_ERROR_BASE + 15 )

/**
 * The object "%1$" cannot be created because it does not have primary business object.
 */
#define APS0APSCORE_cannot_create_objects_without_primary_bo          ( APS0APSCORE_ERROR_BASE + 16 )

/**
 * The provided Configuration Context is invalid.
 */
#define APS0APSCORE_invalid_configuration_context                     ( APS0APSCORE_ERROR_BASE + 17 )

/**
 * The object "%1$" already exists with the properties "%2$". Please specify at least one unique value to create "%3$".
 */
#define APS0APSCORE_inst_violates_unique                              ( APS0APSCORE_ERROR_BASE + 18 )

/** @} */
#endif
