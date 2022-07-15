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
    @file specification_datatypes.h

    This file contains the definition of data structures used by Specification APIs
*/

#ifndef SPECIFICATION_DATATYPES_H
#define SPECIFICATION_DATATYPES_H

#include <Lbr0librarymgmt/liblbr0librarymgmt_exports.h>

/**
 * Specification Management Object types.
 * Types being used for Internal purpose
 */
typedef enum LBR_specification_object_type_e
{
    LBR_TYPE_invalid = -1,                  /**< Invalid type.              */
    LBR_TYPE_specification = 0,             /**< Specification              */
    LBR_TYPE_specification_element,         /**< Specification Element      */
    LBR_TYPE_specification_rule,            /**< Specification Rule         */
    LBR_TYPE_action_definition,             /**< Action Definition          */
    LBR_TYPE_application_data,              /**< Application Data           */
    LBR_TYPE_action_set                     /**< Action Set                 */
} LBR_specification_object_type_t;

/**
 *  Specification Element types
 */
typedef enum LBR_specification_element_type_e
{
    LBR_SPEC_ELEM_TYPE_specification_rule = 0,  /**< Specification Element of type Specification Rule.  */
    LBR_SPEC_ELEM_TYPE_action_set,              /**< Specification Element of type Action Set.          */
    LBR_SPEC_ELEM_TYPE_action_definition,       /**< Specification Element of type Action Definition.   */
    LBR_SPEC_ELEM_TYPE_application_data         /**< Specification Element of type Application Data.    */
} LBR_specification_element_type_t;

/**
 *  Specification Rule types
 */
typedef enum LBR_specification_rule_type_e
{
    LBR_SPEC_RULE_TYPE_specification = 0,           /**< Specification Rule representing basic rules used in searches.  */
    LBR_SPEC_RULE_TYPE_action,                      /**< Specification Rule representing Action rules.                  */
    LBR_SPEC_RULE_TYPE_interface_constraint         /**< Specification Rule representing Interface Constraint.          */
} LBR_specification_rule_type_t;


/**
* Action Set types
*/
typedef enum LBR_action_set_type_e
{
    LBR_ACTION_SET_TYPE_post_placement = 0,             /**< Action Set type representing generic post-placement.   */
    LBR_ACTION_SET_TYPE_connection_compatibility        /**< Action Set type representing connection compatibility. */
} LBR_action_set_type_t;

/**
 * Types of operations on Specification objects.
 */
typedef enum LBR_specification_operation_type_e
{
    LBR_OPERATION_invalid = -1,                  /**< Invalid operation.                     */
    LBR_OPERATION_create_specification = 0,      /**< Create Specification                   */
    LBR_OPERATION_update_specification,          /**< Update Specification                   */
    LBR_OPERATION_read_specification,            /**< Read Specification                     */
    LBR_OPERATION_delete_specification,          /**< Delete Specification                     */
    LBR_OPERATION_revise_specification,          /**< Revise Specification                   */
    LBR_OPERATION_copy_specification,            /**< Copy Specification                     */
    LBR_OPERATION_share_specification,           /**< Share Specification with Library       */
    LBR_OPERATION_unshare_specification          /**< Un-share Specification from Library    */
} LBR_specification_operation_type_t;

#include <Lbr0librarymgmt/liblbr0librarymgmt_undef.h>
#endif 
