/* Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright $2014.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software */

/**
    @file

    This file contains the ITK interface of UI Configuration.
*/

/**
    @defgroup UICONFIG UI Configuration
    @ingroup TC

    Teamcenter has implemented UI Configuration functions that
    allows users to customize the UI of clients (Active Workspace Client, Rich Client, etc.)

    Teamcenter makes use of this mechanism itself,
    and it also provides ITK level functions for programmers to make use of the same UI Configuration mechanism.

    @note Teamcenter may alter or obsolete UI Configuration codes as the product evolves.
    These changes will be documented in the Release Notes.

    The ITK UI Configuration functions include:
    <ul>
    <li>Functions to query the UI configuration.
    <li>Functions to save the UI configuration
    </ul>

    To use these functions, include uiconfig_itk.h.
    @{
*/
#ifndef TEAMCENTER_UICONFIG_ITK_H
#define TEAMCENTER_UICONFIG_ITK_H

#include <unidefs.h>
#include <uiconfig/libuiconfig_exports.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
   Creates the Fnd0ColumnConfig and its Fnd0ColumnDef objects if they do not exist, and update those object if they exist
   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#UICONFIG_invalid_column_config_id if the column configuration Id is invalid
   <li>#UICONFIG_invalid_column_def_id if the column definition Id is invalid
   <li>#UICONFIG_invalid_object_type_name if the object type name is invalid
   <li>#UICONFIG_invalid_property_name if the property name is invalid
   <li>#UICONFIG_invalid_pixel_width if the pixel width is invalid
   <li>#UICONFIG_invalid_sort_by_column if the sort by column is invalid
   <li>#UICONFIG_invalid_sort_direction if the sort direction is invalid
   <li>#UICONFIG_different_object_type_name if the object type name is different from the object type name of the column definition
   <li>#UICONFIG_different_property_name if the property name is different from the property name of the column definition
   </ul>
 */
extern UICONFIG_API int UICONFIG_save_column_configuration(
                                                             tag_t scope,                    /**< (I) Tag of scope ( user, role or group, NULLTAG if site scope )*/
                                                             tag_t client_scope,             /**< (I) Tag of Fnd0ClientScope object that the Fnd0ColumnConfig object should be attached to*/
                                                             const char* column_config_id,   /**< (I) Column configuration Id */
                                                             int column_def_count,           /**< (I) Number of columnDef */
                                                             const char **object_type_names, /**< (I) Object type names of column definitions  */
                                                             const char **property_names,    /**< (I) Property names of column definitions */
                                                             const int *pixel_widths,        /**< (I) Pixel widths of column definitions  */
                                                             int sort_by_column_def_index,   /**< (I) Index of column to sort by */
                                                             const char *sort_direction      /**< (I) Sort direction, valid values are Ascending and Descending */
                                                             );

/**
   Queries the column definitions
   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#POM_invalid_tag if column configuration tag or scope tag is invalid
   </ul>
 */
extern UICONFIG_API int UICONFIG_ask_column_definitions(
                                                           tag_t column_config,            /**< (I) Column configuration Tag */
                                                           logical query_by_scope,         /**< (I) TRUE if query by passed in scope, FALSE if query by login user */
                                                           tag_t scope,                    /**< (I) Scope tag if queryByScope is TRUE */
                                                           int *column_def_count,          /**< (O) Number of column definitions */
                                                           char *** object_type_names,     /**< (OF) column_def_count Type names of Fnd0ColumnDef objects. <br/>The array is packed, which means that the memory is deallocated by calling #MEM_free on the container only.  */
                                                           char *** property_names,        /**< (OF) column_def_count Property names of Fnd0ColumnDef objects. <br/>The array is packed, which means that the memory is deallocated by calling #MEM_free on the container only.  */
                                                           int **pixel_widths,             /**< (OF) column_def_count Pixel width of Fnd0ColumnDef objects */
                                                           int *sort_by_column_def_index,  /**< (O) Index of Fnd0ColumnDef object to sort by */
                                                           char **sort_direction           /**< (OF) Sort direction. Values can are Ascending and Descending */
                                                           );

/**
   Queries the column configs for a client scope
   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#UICONFIG_no_such_client_scope_uri, if the client scope URI does not exist
   </ul>
 */
extern UICONFIG_API int UICONFIG_ask_column_configurations(
                                                            tag_t client_scope,           /**< (I) Client scope Tag  */
                                                            int *column_config_count,     /**< (O) Number of column definition  */
                                                            tag_t **column_configs        /**< (OF) column_config_count Column configuration Tags  */
                                                            );


#ifdef __cplusplus
}
#endif

/** @} */

#include <uiconfig/libuiconfig_undef.h>

#endif
