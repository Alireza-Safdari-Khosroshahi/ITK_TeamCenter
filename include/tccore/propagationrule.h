/* Copyright 2020 Siemens Digital Industries Software
 ==================================================
 Copyright 2015
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2020 Siemens Digital Industries Software */

/**
    @file

    This file contains the ANSI C interface to Teamcenter Engineering propagation related functions.
    
*/

#ifndef PROPAGATIONRULE_H
#define PROPAGATIONRULE_H

#include <tccore/traversalrule.h>

#include <tccore/libtccore_exports.h>

/**
    @defgroup PROPAGATION_RULES Propagation Rules
    @ingroup TC
    
    Teamcenter has implemented propagation rule functions that allows users to customize the operating environment.

    Detailed information is supplied for the following aspects of propagation rule related functions:
    <ul>
    <li>Propagation styles and the codes associated with each style.
    <li>Propagation related functions to obtain propagation rules defined for a given type.
    </ul>

    Teamcenter makes use of this mechanism itself, and it also provides ITK level functions for programmers 
    to make use of the same propagation rule mechanism.
    
    <br>Programmers can read existing Teamcenter propagation rules defined on a given type.

    If you intend to add new propagation rule, we suggest that you define those rules in BMIDE..

    @note Teamcenter may alter or obsolete propagation rule styles as the product evolves.
    These changes will be documented in the Release Notes.

    The ITK propagation rule functions include:
    <ul>
    <li>Functions to retrieve specified propagation style code
    <li>A function to inquire on the number of propagation rules defined for a specified type
    </ul>

    To use these functions, include propagationrule.h.
    @{    
*/

/** Merge value for propagation style. */
#define PROPAGATIONRULE_merge_style               "Merge"

/** Ordered value for propagation style. */
#define PROPAGATIONRULE_ordered_style             "Ordered"

/** Overwrite value for propagation style. */
#define PROPAGATIONRULE_fill_style                "Fill"

/** Overwrite value for propagation style. */
#define PROPAGATIONRULE_overwrite_style           "Overwrite"

/**
   Propagation rule propagation style types
*/
typedef enum PROPAGATIONRULE_propagation_style_e
{
    PROPAGATIONRULE_merge = 0,                /**<Merge value        */
    PROPAGATIONRULE_ordered,                  /**<Ordered value      */
    PROPAGATIONRULE_fill,                     /**<Fill value         */
    PROPAGATIONRULE_overwrite                 /**<Overwrite value    */
} PROPAGATIONRULE_propagation_style_t;

/**
    Callback type to create propagation check in custom traversal rule
*/
#define PROPAGATION_CHECKIN_CUSTOM_TRAVERSAL "Propagation_CheckIn_CustomTraversal"

/**
    Callback type to create propagation check out custom traversal rule
*/
#define PROPAGATION_CHECKOUT_CUSTOM_TRAVERSAL "Propagation_CheckOut_CustomTraversal"

/**
    Callback type to create propagation create custom traversal rule
*/
#define PROPAGATION_CREATE_CUSTOM_TRAVERSAL "Propagation_Create_CustomTraversal"

/**
    Callback type to create propagation delete custom traversal rule
*/
#define PROPAGATION_DELETE_CUSTOM_TRAVERSAL "Propagation_Delete_CustomTraversal"

/**
    Callback type to create propagation export custom traversal rule
*/
#define PROPAGATION_EXPORT_CUSTOM_TRAVERSAL "Propagation_Export_CustomTraversal"

/**
    Callback type to create propagation import custom traversal rule
*/
#define PROPAGATION_IMPORT_CUSTOM_TRAVERSAL "Propagation_Import_CustomTraversal"

/**
    Callback type to create propagation revise custom traversal rule
*/
#define PROPAGATION_REVISE_CUSTOM_TRAVERSAL "Propagation_Revise_CustomTraversal"

/**
    Callback type to create propagation save custom traversal rule
*/
#define PROPAGATION_SAVE_CUSTOM_TRAVERSAL "Propagation_Save_CustomTraversal"

/**
    Callback type to create propagation save as custom traversal rule
*/
#define PROPAGATION_SAVEAS_CUSTOM_TRAVERSAL "Propagation_SaveAs_CustomTraversal"

/**
    Callback type to create propagation all operations custom traversal rule
*/
#define PROPAGATION_ALLOPERATIONS_CUSTOM_TRAVERSAL "Propagation_AllOperations_CustomTraversal"


#ifdef __cplusplus
    extern "C"{
#endif

/**
   Retrieves a valid #PROPAGATIONRULE_propagation_style_t object from the provided string style.

   <br>Valid values for the "style" parameters are #PROPAGATIONRULE_overwrite_style,#PROPAGATIONRULE_merge_style and #PROPAGATIONRULE_ordered_style.
   <br>
   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#TCCORE_propagationrule_unsupported_style, if the style is invalid.
   </ul>
*/
extern TCCORE_API int PROPAGATIONRULE_get_styletype(
                          const char* style,             /**< (I) Valid propagation style name. */
                          PROPAGATIONRULE_propagation_style_t *style_type  /**< (O) The associated propagation style type. */
                          );


/**
   Retrieves a valid "Fnd0PropagationRule" object from the provided source type and operation type.

   <br>Valid values for the "tag_source_type" could be any business object
   <br>
   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#TYPE_invalid_type_name, if invalid type.
   </ul>
*/
extern TCCORE_API int PROPAGATIONRULE_get_applicable_rules_by_type_tag(
                        tag_t          source_type_tag,                  /**< (I) Valid type tag, can be null. */
                        TRAVERSALRULE_operation_type_t  operation_type,  /**< (I) Valid Operation Type. */
                        int*    count_defined_rules,                     /**< (O) The number of associated propapagtion rules. If no Propagation rule objects found, the count is zero.*/
                        tag_t** defined_rules_tags                       /**< (OF) The associated propagation rules. */ );


/**
   Retrieves a valid "Fnd0PropagationRule" object from the provided source type and operation type.

   <br>Valid values for the "source_type" could be any business object name
   <br>
   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#TYPE_invalid_type_name, if invalid type.
   </ul>
*/
extern TCCORE_API int PROPAGATIONRULE_get_applicable_rules_by_type_name(
                        const char*    source_type,                      /**< (I) Valid type name, can be null. */
                        TRAVERSALRULE_operation_type_t  operation_type,  /**< (I) Valid Operation Type. */
                        int*    count_defined_rules,                     /**< (O) The number of associated propapagtion rules. If no Propagation rule objects found, the count is zero. */
                        tag_t** defined_rules_tags                       /**< (OF) The associated propagation rules. */ );


/**
   Retrieves a list of applicable Propagation Rules ("Fnd0PropagationRule") from the provided source type, propagation group and operation type.

   <br>Valid values for the "source_type" could be any business object type.
   <br>
   <br>Valid values for the "propagation_group_name" could be any of the propagation groups defined in propagation rules.
   <br>
   @returns
   <ul>
   <li>#ITK_ok on success
   <li>##TYPE_invalid_type_name if @p source_type is not NULLTAG and not a valid type.
   <li>##BMIDE_propagationrule_invalid_propagation_group if @p propagation_group_name is empty or not a valid group name.
   </ul>
*/
extern TCCORE_API int PROPAGATIONRULE_get_applicable_rules_by_type_group_and_operation(
                        tag_t          source_type,                             /**< (I) The type of a Business Object on which the Propagation Rule would apply. <br/>It can be #NULLTAG. */
                        const char *   propagation_group_name,                  /**< (I) The name of the Propagation Group that contains the rule. */
                        TRAVERSALRULE_operation_type_t  operation_type,         /**< (I) The Operation type on which the Propagation Rule would apply. */
                        int*    num_defined_rules,                              /**< (O) The number of found Propapation Rules. */
                        tag_t** propagation_rules                               /**< (OF) num_defined_rules The found Propagation Rules. */
                        );

/** @} */                        
#ifdef __cplusplus
}
#endif
#include <tccore/libtccore_undef.h>
#endif
