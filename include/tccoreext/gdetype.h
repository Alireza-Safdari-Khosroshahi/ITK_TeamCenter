/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*  */

#ifndef GDETYPE_H_INCLUDED
#define GDETYPE_H_INCLUDED

#include <tccoreext/libtccoreext_exports.h>

#ifdef __cplusplus
    extern "C"{
#endif

/**
    @defgroup GDETYPE Type Functions
    @ingroup GDE

    This module defines the required ITK interface for GDEType
    @{
*/

/**
    This function returns the name of the storage class associated with the input GDEType
*/
extern TCCOREEXT_API int GDETYPE_ask_def_class_name(
    tag_t                   gde_type_tag,       /**< (I) Tag of the GDEType Object to be modified */
    char**                  def_class_name      /**< (OF) Name of the Storage class */
    );

/**
    This function returns the list of GDETypes defined in the database.
*/
extern TCCOREEXT_API int GDETYPE_get_types (
    int*                    type_count,     /**< (O) Number of GDETypes */
    tag_t**                 type_tags       /**< (OF) type_count Tags of the GDEType */
    );

/**
    This function will get the GDEType Definition object associated with the GDEType
*/
extern TCCOREEXT_API int GDETYPE_ask_typedefinition(
    tag_t  gde_type_tag,             /**< (I) Tag of the GDEType object */
    tag_t  *gde_typedefinition_tag   /**< (O) Tag of the GDEType Definition object associated with the GDE */
    );

/**
    This function will get the number of occurences that this GDEType object can have using the GDEType Definition
*/
extern TCCOREEXT_API int GDETYPEDEF_get_cardinality(
    tag_t gde_typedefinition,           /**< (I) Tag of GDE Type Definition */
    int *cardinality                    /**< (O) Number of occurrences GDE Object of this GDEType can have*/ 
    );

/**
    This function will get the view types that are associated with this GDEType based on the GDEType Definition
*/
extern TCCOREEXT_API int GDETYPEDEF_get_view_types(
    tag_t gde_typedefinition,           /**< (I) Tag of GDE Type Definition*/
    int *numOfAllowableViewTypes,       /**< (O) Number of allowed view types for this GDEType*/
    tag_t **allowableViewTypes          /**< (OF)  View types tags*/
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <tccoreext/libtccoreext_undef.h>

#endif
