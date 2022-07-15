/*==============================================================================
                 Copyright 2013 UGS Corp. All Rights Reserved.
==============================================================================
/**
    @file

    This file contains all user exits defined in requirement management
    module.
*/



#ifndef REQ_USER_EXITS_H
#define REQ_USER_EXITS_H

#include <unidefs.h>
#include <req/libreq_exports.h>

/**
    @defgroup REQ_USER_EXITS User Exits
    @ingroup REQ
    @{
*/

#ifdef __cplusplus
    extern "C"{
#endif

/** 
    Performs a search in the database based on the provided property names and values.
    <br/>It provides the ability to customize the search functionality through the user exits feature. 
    <br/>Custom user exits can be implemented using the string "USER_search".
    
    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#TYPE_invalid_type_name if an invalid object type is provided
    <li>#POM_invalid_attr_id if an invalid property is provided for the search
    </ul> 
*/
extern REQ_API int USER_search (
            const char** property_names,                 /**<(I) Array of property names*/
            const char** property_values,                /**<(I) Array of property values*/
            int property_count,                          /**<(I) Number of properties passed*/
            int* object_count,                           /**<(O) Number of objects found*/
            tag_t ** object_list                         /**<(OF) object_count Array of found objects*/
            );


/** 
    Performs creation and update of generic relation between defining and complying objects.
    <br/>It provides the ability to customize the creation and update using the user exits feature.
    <br/>Custom user exits can be implemented against the string "USER_create_tracelink".
    
    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#REQ_invalid_link_type error if the provided tracelink_type parameter is not a valid GRM
    <li>#GRM_no_write_permission_for_adding if write permission is denied for creating a GRM
    <li>#GRM_no_write_permission_for_removal if write permission is denied for deleting a GRM
    <li>#GRM_constraints_failed_creation if the GRM creation has failed due to GRM rules
    </ul> 
*/
extern REQ_API int USER_create_tracelink (
            const char* tracelink_type,                       /**< (I) Type of trace link */
            const char* tracelink_direction,                  /**< (I) Direction of trace link */
            int parent_object_count,                          /**< (I) Number of  parent objects */
            tag_t*  parent_objects,                     /**< (I) Array of parent objects */
            int child_object_count,                           /**< (I) Number of child objects*/
            tag_t*  child_objects                       /**< (I) Array of child objects*/
            );

#ifdef __cplusplus
}
#endif

/**
   @}
*/

#include <req/libreq_undef.h>
#endif
