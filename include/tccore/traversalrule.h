// Copyright 2020 Siemens Digital Industries Software
// ==================================================
// Copyright 2013.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2020 Siemens Digital Industries Software


/**
    @file

    This file contains the ANSI C interface to Teamcenter Engineering traversal rule related functions.

    Traversal rule related functions are function to handle traversal of Teamcenter data from one object to other object.
    We use source object and destination object to differentiate where the action started. Source object indicates
    the object where traversal action is started from and destination object is an object which is obtained by traversal.

    Traversal of data can happen using a relation or property. The traversal type name are also listed here as "Relation" to
    indicate traversal based on relation and "ReferenceProperty" to indicate traversal based on property.

    Traversal actions can be triggered from different operations in Teamcenter.Actions which are supported have message
    names which are listed in this file.All names are self explanatory e.g. CheckIn means Check-in action
    in Teamcenter.The action name "All" indicated is used to mean any of the actions will trigger traversal of
    the data.

    Traversal can happen in two directions from source object to destination object in Forward direction, or from destination
    object to source object in Reverse direction i.e. to indicate to obtain the source object by getting where it is referenced.
*/

#ifndef TRAVERSALRULE_H
#define TRAVERSALRULE_H

#include <tccore/libtccore_exports.h>

/** Value used for Check-In operation. */
#define TRAVERSALRULE_checkin_operation           "CheckIn"

/** Value used for Check-Out operation. */
#define TRAVERSALRULE_checkout_operation          "CheckOut"

/** Value used for Create operation. */
#define TRAVERSALRULE_create_operation            "Create"

/** Value used for Delete operation. */
#define TRAVERSALRULE_delete_operation            "Delete"

/** Value used for Export operation. */
#define TRAVERSALRULE_export_operation            "Export"

/** Value used for Import operation. */
#define TRAVERSALRULE_import_operation            "Import"

/** Value used for Revise operation. */
#define TRAVERSALRULE_revise_operation            "Revise"

/** Value used for Save operation. */
#define TRAVERSALRULE_save_operation              "Save"

/** Value used for SaveAs operation. */
#define TRAVERSALRULE_saveas_operation            "SaveAs"

/** Value used for All operation. */
#define TRAVERSALRULE_all_operation               "All"

/** Traversal direction indicating it is Forward, from source to destination object. */
#define TRAVERSALRULE_forward_direction         "Forward"

/** Traversal direction indicating it is Reverse, meaning we find Where source object is referenced. */
#define TRAVERSALRULE_reverse_direction         "Reverse"


/**< Type of traversal is based on Relation. */
#define TRAVERSALRULE_relation_type             "Relation"

/**< Type of traversal is based on Property. */
#define TRAVERSALRULE_reference_type            "ReferenceProperty"

/**
    @name Traversal operation types
*/
typedef enum TRAVERSALRULE_operation_type_e
{
    TRAVERSALRULE_null_operation_type     = 0,           /**< Null operation */
    TRAVERSALRULE_checkin_operation_type,                /**< Check-In operation */
    TRAVERSALRULE_checkout_operation_type,               /**< Check-Out operation */
    TRAVERSALRULE_create_operation_type,                 /**< Create operation */
    TRAVERSALRULE_delete_operation_type,                 /**< Delete operation */
    TRAVERSALRULE_export_operation_type,                 /**< Export operation */
    TRAVERSALRULE_import_operation_type,                 /**< Import operation */
    TRAVERSALRULE_revise_operation_type,                 /**< Revise operation */
    TRAVERSALRULE_save_operation_type,                   /**< Save operation */
    TRAVERSALRULE_saveas_operation_type,                 /**< SaveAs operation */
    TRAVERSALRULE_all_operation_type                     /**< All operation */
} TRAVERSALRULE_operation_type_t;

/**
    @name Traversal types
*/
typedef enum TRAVERSALRULE_property_type_e
{
    TRAVERSALRULE_relation = 0,               /**< Type of traversal is based on Relation. */
    TRAVERSALRULE_reference                   /**< Type of traversal is based on Reference Property. */
} TRAVERSALRULE_property_type_t;


/**
    @name Traversal direction types
*/
typedef enum TRAVERSALRULE_direction_e
{
    TRAVERSALRULE_forward = 0,          /**< Type of traversal direction is forward. */
    TRAVERSALRULE_reverse               /**< Type of traversal direction is reverse. */
} TRAVERSALRULE_direction_t;


#ifdef __cplusplus
    extern "C"{
#endif
/**
   Retrieves a valid #TRAVERSALRULE_operation_type_t object from the provided string operation name.
   <br>Valid values for the "operation_type" parameter are #TRAVERSALRULE_checkin_operation,
   #TRAVERSALRULE_checkout_operation, #TRAVERSALRULE_create_operation, #TRAVERSALRULE_delete_operation
   #TRAVERSALRULE_export_operation, #TRAVERSALRULE_import_operation, #TRAVERSALRULE_revise_operation,
   #TRAVERSALRULE_save_operation, #TRAVERSALRULE_saveas_operation and #TRAVERSALRULE_all_operation.
   <br>
   The function returns:
   <ul>
   <li>#ITK_ok on success
   <li>#TCCORE_traversalrule_unsupported_operation, if the operation type is invalid.
   </ul>
*/
extern TCCORE_API int TRAVERSALRULE_get_operationtype(
                          const char* operation_type,                    /**< (I) Valid operation type name. */
                          TRAVERSALRULE_operation_type_t *op_type        /**< (O) Valid operation type. */
                          );

/**
   Retrieves a valid #TRAVERSALRULE_direction_t from the provided string direction.
   <br>Valid values for the "direction" parameters are #TRAVERSALRULE_forward and #TRAVERSALRULE_reverse.
   <br>
   The function returns:
   <ul>
   <li>#ITK_ok on success
   <li>#TCCORE_traversalrule_unsupported_direction, if the direction is invalid.
   </ul>
*/
extern TCCORE_API int TRAVERSALRULE_get_direction(
                          const char* direction,                          /**< (I) Valid traversal direction name. */
                          TRAVERSALRULE_direction_t *direction_type       /**< (O) Valid traversal direction. */
                          );

/**
   Retrieves a valid #TRAVERSALRULE_property_type_t from the provided string property type.
   <br>Valid values for the "property_type" parameter are #TRAVERSALRULE_relation and #TRAVERSALRULE_reference.
   <br>
   The function returns:
   <ul>
   <li>#ITK_ok on success
   <li>#TCCORE_traversalrule_unsupported_referencetype, if the property type is invalid.
   </ul>
*/
extern TCCORE_API int TRAVERSALRULE_get_propertytype(
                          const char* property_type,                       /**< (I) Valid property type for traversal it can be either Relation or ReferenceProperty. */
                          TRAVERSALRULE_property_type_t *propType          /**< (O)  Valid traversal property type.  */
                          );

#ifdef __cplusplus
}
#endif
#include <tccore/libtccore_undef.h>
#endif


