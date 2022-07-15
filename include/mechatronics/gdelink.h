/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*  */

#ifndef GDELINK_H_INCLUDED
#define GDELINK_H_INCLUDED

#include <unidefs.h>

/**
    @defgroup GDELINK General Design Element Link
    @ingroup MECHATRONICS

    This module defines the required ITK interface for GeneralDesignElementLink related operations.
    @{
*/

#define GDELINK_CLASS_NAME          "GeneralDesignElementLink"
#define GDELINK_TYPE_NAME           GDELINK_CLASS_NAME
#define GDELINK_STORAGE_CLASS_NAME  "GDELinkStorage"
#define GDELINK_STORAGE_TYPE_NAME   GDELINK_STORAGE_CLASS_NAME

/**
    Preference for GDELink type used when creating a new connection without an explicit given type 
*/
#define GDELINK_DEFAULT_TYPE        "GDELink_default_type"

/**
    The default Out of The Box GDELink type for creating a new connection 
*/
#define TC_LINK                     "TC_Link"

#include <mechatronics/libmechatronics_exports.h>

#ifdef __cplusplus
    extern "C"{
#endif

/**
    This Function is used to create a new GDELink
*/
extern MECHATRONICS_API int GDELINK_create (
    const char*             gdelink_name,   /**< (I) Name of the GDELink */
    const char*             gdelink_desc,   /**< (I) Description of the GDELink */
    const char*             gdelink_type,   /**< (I) Type of the GDELink to be created */
    tag_t*                  new_gdelink     /**< (O) Tag of the newly created GDELink */
    );

/**
    This function takes list of gde occurrences (gde bomline) and makes connection to existing gdelink line
*/
extern MECHATRONICS_API int GDELINK_add_to_connection (
    tag_t                   gdelink_line_tag,   /**< (I) Tag of the GDELink line */
    int                     gde_line_count,     /**< (I) Number of GDELines */
    tag_t*                  gde_line_tags       /**< (I) Tags of the GDELines */
    );

/**
    This function takes a list of gde occurrences (gde bomline)
    and makes a connection to an existing gdelink line
*/
extern MECHATRONICS_API int GDELINK_connect (
    const char*             gdelink_name,       /**< (I) Name of the GDELink */
    const char*             gdelink_desc,       /**< (I) Description of the GDELink  */
    const char*             gdelink_type,       /**< (I) Type of the GDELink to be created */
    int                     gde_line_count,     /**< (I) Number of GDE Lines to be connected */
    tag_t*                  gde_line_tags,      /**< (I) Tags of the GDE Lines */
    tag_t*                  gdelink_line_tag    /**< (O) Tag of the newly created GDELink */
    );

/**
    Disconnect the input occurrences from the gdelink line
*/
extern MECHATRONICS_API int GDELINK_remove_from_connection (
    tag_t                   gdelink_line_tag,   /**< (I) Tag of the GDELink Line */
    int                     gde_line_count,     /**< (I) Number of GDE Lines to be removed from connection */  
    tag_t*                  gde_line_tags       /**< (I) Tags of the GDE Lines */ 
    );

/**
    Disconnect all occurrences that are connected to a gdelink line
*/
extern MECHATRONICS_API int GDELINK_disconnect (
    tag_t                   gdelink_line_tag    /**< (I) Tag of the GDELink Line */
    );

/**
    This function list all the gde objects connected to the given GDELink
*/
extern MECHATRONICS_API int GDELINK_list_connected_gdes(
    tag_t                   gdelink_line_tag,   /**< (I) Tag of the GDELink Line */
    int*                    gde_line_count,     /**< (O) Number of GDE Lines to be removed from connection */  
    tag_t**                 gde_line_tags       /**< (OF) gde_line_count Tags of the GDE Lines */ 
    );

/**
    This function list all the realizedBy bomLines objects to the given BOMLine.
*/
extern MECHATRONICS_API int GDELINK_list_realizedBy(
    tag_t                   bom_line_tag,       /**< (I) Tag of the GDELink Line */
    int*                    gde_line_count,     /**< (O) Number of GDE Lines to be removed from connection */
    tag_t**                 gde_line_tags       /**< (O) Tags of the GDE Lines */
    );

/**
    This function list all the implementedBy bomLines objects to the given BOMLine.
*/
extern MECHATRONICS_API int GDELINK_list_implementedBy (
    tag_t                   gdelink_line_tag,   /**< (I) Tag of the GDELink Line */
    int*                    gde_line_count,     /**< (O) Number of GDE Lines to be removed from connection */  
    tag_t**                 gde_line_tags       /**< (OF) gde_line_count Tags of the GDE Lines */ 
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <mechatronics/libmechatronics_undef.h>

#endif
