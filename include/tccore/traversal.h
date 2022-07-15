// Copyright 2020 Siemens Digital Industries Software
// ==================================================
// Copyright 2013.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2020 Siemens Digital Industries Software

/**
@file

This file contains the function signatures for traversing from source object
for specified relation or reference to get the destination objects
*/

#ifndef TRAVERSAL_H
#define TRAVERSAL_H

#include <unidefs.h>
#include <tccore/libtccore_exports.h>

/**
    @defgroup TRAVERSAL_RULES Traversal Rules
    @ingroup TC
   
    Teamcenter has implemented traversal functions that allow users to traverse Teamcenter data.

    
    Detailed information is supplied for the following aspects of traversal rule related functions:
    <ul>
    <li>Traversal of data by property directly or indirectly.
    <li>Traversal of Teamcenter data by relation directly or indirectly.
    </ul>

    Teamcenter makes use of this mechanism itself, and it also provides ITK level functions for programmers 
    to make use of the same traversal.
    
   
    @note Teamcenter may alter or obsolete traversal related functions defined here as the product evolves.
    These changes will be documented in the Release Notes.

    The ITK traversal rule functions include:
    <ul>
    <li>Functions to retrieve objects related by a relation.
    <li>Functions to retrieve objects related by a reference.
    </ul>

    To use these functions, include traversal.h.
    @{
*/


#ifdef __cplusplus
    extern "C"{
#endif


/**
   Retrieves destination objects of a given destination object type which contain references to the source object.

   <br>Valid values for the "source_object" could be any business object tag.
   <br>Valid values for the "destination_obj_type"  any business object type tag.
   <br>
   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#TYPE_unknown_type, if invalid type.
   </ul>
*/
extern TCCORE_API int TRAVERSAL_get_destination_objects_where_reference (
    tag_t    source_object,           /**< (I)  Tag of the source object */
    tag_t    destination_obj_type,    /**< (I)  Object type to filter the destination object list */
    int*     count,                   /**< (O)  Final count of destination objects after filtering. If no destination objects found, the count is zero. */
    tag_t**  destination_object_list  /**< (OF) count Array of destination objects after filtering */
    );

/**
   Retrieves the destination objects for given source object using where reference for a given property on the destination object.

   <br>Valid values for the "source_object" could be any business object tag.
   <br>Valid values for the "destination_obj_type"  any business object type tag.
   <br>
   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#TYPE_unknown_type, if invalid type.
   <li>#PROP_not_found, if property cannot be found.   
   </ul>
*/
extern TCCORE_API int TRAVERSAL_get_destination_objects_where_reference_property (
    tag_t          source_object,           /**< (I)  Tag of the source object */
    const char*    prop_name,               /**< (I)  Property name which references the destination object */
    tag_t          destination_obj_type,    /**< (I)  Object type to filter the destination object list */
    int*           count,                   /**< (O)  Final count of destination objects after filtering. If no destination objects found, the count is zero */
    tag_t**        destination_object_list  /**< (OF) count Array of destination objects after filtering */
    );

/**
   Retrieves the destination objects for given source object using the property refering to the destination object.

   <br>Valid values for the "source_object" could be any business object tag.
   <br>Valid values for the "prop_name"  valid property on source object.
   <br>Valid values for the "destination_obj_type"  any business object type tag.
   <br>
   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#TYPE_unknown_type, if invalid type.
   <li>#PROP_not_found, if property cannot be found.   
   </ul>
*/
extern TCCORE_API int TRAVERSAL_get_destination_objects_for_reference_property (
    tag_t    source_object,           /**< (I)  Tag of the source object */
    const char*    prop_name,               /**< (I)  Property name which references the destination object */
    tag_t    destination_obj_type,    /**< (I)  Object type to filter the destination object list */
    int*           count,                   /**< (O)  Final count of destination objects after filtering. If no destination objects found, the count is zero */
    tag_t**        destination_object_list  /**< (OF) count Array of destination objects after filtering */
    );

/**
   Retrieves the destination objects for given source object using relation.

   <br>Valid values for the "source_object" could be any business object tag.
   <br>Valid values for the "relation_type"  valid relation type.
   <br>Valid values for the "destination_obj_type"  any business object type tag.
   <br>
   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#TYPE_unknown_type, if invalid type.
   <li>#GRM_undefined_relation_type, if the relation type does not exist.   
   <li>#GRM_invalid_primary_object, if the source object type is invalid.
   <li>#GRM_invalid_secondary_object, if the destination object type is invalid.   
   </ul>
*/
extern TCCORE_API int TRAVERSAL_get_destination_objects_for_relation (
    tag_t source_object,           /**< (I)  Tag of the source object */
    tag_t relation_type,           /**< (I)  Tag of relation */
    tag_t destination_obj_type,    /**< (I)  Object type to filter the destination object list */
    int*    count,                         /**< (O)  Final count of destination objects after filtering. If no destination objects found, the count is zero */
    tag_t** destination_object_list        /**< (OF) count Array of destination objects after filtering */
     );

/**
   Retrieves the destination objects for given source object using reverse relation.

   <br>Valid values for the "source_object" could be any business object tag.
   <br>Valid values for the "relation_type"  valid relation type.
   <br>Valid values for the "destination_obj_type"  any business object type tag.
   <br>
   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#TYPE_unknown_type, if invalid type.
   <li>#GRM_undefined_relation_type, if the relation type does not exist.   
   <li>#GRM_invalid_primary_object, if the source object type is invalid.
   <li>#GRM_invalid_secondary_object, if the destination object type is invalid.   
   </ul>
*/
extern TCCORE_API int TRAVERSAL_get_destination_objects_for_relation_reverse (
    tag_t source_object,         /**< (I)  Tag of the source object */
    tag_t relation_type,         /**< (I)  Tag of relation */
    tag_t destination_obj_type,  /**< (I)  Object type to filter the destination object list */
    int*    count,                       /**< (O)  Final count of destination objects after filtering. If no destination objects found, the count is zero */
    tag_t** destination_object_list      /**< (OF) count Array of destination objects after filtering */
    );

/** @} */
#ifdef __cplusplus
}
#endif
#include <tccore/libtccore_undef.h>
#endif
