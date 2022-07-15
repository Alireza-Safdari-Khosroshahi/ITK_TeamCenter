/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    ITK API for Tctrushape module
*/

/*  */

#ifndef TCTRUSHAPE_H
#define TCTRUSHAPE_H

#include <unidefs.h>

#include <ugmath_datatypes.h>

#include <tctrushape/libtctrushape_exports.h>

/**
    @defgroup TCTRUSHAPE TCTRUSHAPE
    @{
*/

/**
    @name Defines for spatial zone relative positions
    @{
*/
#define TCTRUSHAPE_no_zone_criteria      (0)
#define TCTRUSHAPE_inside_box            (1)
#define TCTRUSHAPE_outside_box           (2)
#define TCTRUSHAPE_interferes_with_box   (3)
#define TCTRUSHAPE_above_plane           (4)
#define TCTRUSHAPE_below_plane           (5)
#define TCTRUSHAPE_interferes_with_plane (6)
#define TCTRUSHAPE_interferes_outside_box (7)
#define TCTRUSHAPE_interferes_inside_box    (8)

#define TCTRUSHAPE_interferes_above_plane   (9)
#define TCTRUSHAPE_interferes_below_plane   (10)

/** @} */

/**
    @name Defines for bounding box and trushape extraction options
    @{
*/
#define TRUSHAPE_extract_bbox     1
#define TRUSHAPE_extract_tso      2
#define TRUSHAPE_extract_bbox_tso 3 
/** @} */


#ifdef __cplusplus
extern "C"{
#endif

/**
    Initializes TCTRUSHAPE module.
    Please note that this functional is called internally during overall system initialization,
    and doesn't have effect if called after that.

    If system has successfully initialized itself, this function always returns #ITK_ok.
*/
extern TCTRUSHAPE_API int TCTRUSHAPE_init_module(void);

/**
    Opens occupancy cache for read only (i.e. no update is allowed when cache is open in this mode).
*/
extern TCTRUSHAPE_API int TCTRUSHAPE_open_occupancy_cache_for_read(
    tag_t                   appearanceRoot  /**< (I) */
    );

/**
    Opens occupancy cache for update. New appearance records can be added when occupancy cache is open in this mode.
*/
extern TCTRUSHAPE_API int TCTRUSHAPE_open_occupancy_cache_for_write(
    tag_t                   appearanceRoot  /**< (I) */
    );

/**
    Flushes any unwritten data and closes occupancy cache. MUST be called before exiting application.
*/
extern TCTRUSHAPE_API int TCTRUSHAPE_close_occupancy_cache(
    tag_t                   appearanceRoot  /**< (I) */
    );

/**
    Creates occupancy cache for the appearance root and opens it for writing.
*/
extern TCTRUSHAPE_API int TCTRUSHAPE_create_occupancy_cache(
    tag_t                   appearanceRoot  /**< (I) */
    );

/**
    Checks if occupancy cache for this appearance root is open.
*/
extern TCTRUSHAPE_API int TCTRUSHAPE_is_occupancy_cache_open(
    tag_t                   appearanceRoot,     /**< (I) */
    logical*                open                /**< (O) */
    );

/**
    Checks if occupancy cache exists for this appearance set. Occupancy cache can be opened or closed.
*/
extern TCTRUSHAPE_API int TCTRUSHAPE_ask_occupancy_cache_exists(
    tag_t                   appearanceRoot,     /**< (I) */
    logical*                exists              /**< (O) */
    );

/**
    Deletes occupancy cache data associated with the appearance set
*/
extern TCTRUSHAPE_API int TCTRUSHAPE_delete_occupancy_cache(
    tag_t                   appearanceRoot      /**< (I) */
    );

/**
    Checks if occupancy data exists for this appearance.
    Occupancy cache must be opened for reading or writing.
*/
extern TCTRUSHAPE_API int TCTRUSHAPE_ask_appearance_occupancy_data_exists(
    tag_t                   appearanceRoot,     /**< (I) */
    tag_t                   appearance,         /**< (I) */
    logical*                exists              /**< (O) */
    );

/**
    Adds occupancy data for this appearance to occupancy cache. Cache must be opened for writing. 
    If corresponding item revision doesn't have occupancy data or occupancy data could not be generated,
    nothing will be written to occupancy cache.
*/
extern TCTRUSHAPE_API int TCTRUSHAPE_write_appearance_occupancy_data(
    tag_t                   appearanceRoot,     /**< (I) */
    tag_t                   appearance          /**< (I) */
    );

/**
    Returns union of extents of all appearances in this occupancy cache.
    Occupancy cache has to be opened for reading or writing.
    Note that this function takes into account all appearances ever existed in the occupancy cache.
*/
extern TCTRUSHAPE_API int TCTRUSHAPE_ask_occupancy_cache_extents(
    tag_t                   appearanceRoot,     /**< (I) */
    double                  bbox[6]             /**< (O) */
    );

/**
    Returns all appearances "distance" units away from "target" appearances. 
    Note, that this search doesn't take into account configuration rule,
    so it returns all appearances ever located in proximity of the target appearances.
*/
extern TCTRUSHAPE_API int TCTRUSHAPE_spatial_proximity_search(
    tag_t                   appearanceRoot,     /**< (I) */
    int                     numTargets,         /**< (I) */
    tag_t*                  targets,            /**< (I) */
    double                  distance,           /**< (I) */
    int*                    numAppearances,     /**< (O) */
    tag_t**                 appearances         /**< (O) */
    );

/**
    Returns all appearances "distance" units away from "target" appearances. 
    Note, that this search doesn't take into account configuration rule,
    so it returns all appearances ever located in proximity of the target appearances.
    It filters out filterTargets from the set returned. 
*/
extern TCTRUSHAPE_API int TCTRUSHAPE_spatial_filtered_proximity_search(
    tag_t                   appearanceRoot,     /**< (I) */
    int                     numTargets,         /**< (I) */
    tag_t*                  targets,            /**< (I) */
    int                     numFilterTargets,   /**< (I) */
    tag_t*                  filterTargets,      /**< (I) */
    double                  distance,           /**< (I) */
    int*                    numAppearances,     /**< (O) */
    tag_t**                 appearances         /**< (O) */
    );

/**
    Returns all appearances inside, outside or interfering with the specified 3d box.
    Allowed box relative positions values are:
    <UL>
    <LI>#TCTRUSHAPE_inside_box
    <LI>#TCTRUSHAPE_outside_box
    <LI>#TCTRUSHAPE_interferes_with_box
    </UL>
*/
extern TCTRUSHAPE_API int TCTRUSHAPE_spatial_3d_box_search(
    tag_t                   appearanceRoot,         /**< (I) Appearance set tag against which search is performed */
    int                     boxRelativePosition,    /**< (I) Box zone spatial relative position to products components */
    VEC3_t                  planeNormals[6],        /**< (I) Coordinates of 3d box zone. Note that no more than one proximity criteria 
                                                        (target proximity or zone) can be specified. If both of them are specified, 
                                                        then only target proximity search is performed. */
    double                  planeDisplacements[6],  /**< (I) */
    int*                    numAppearances,         /**< (O) */
    tag_t**                 appearances             /**< (OF) numAppearances Array of appearances matching box zone criteria */
    );

/**
    Returns all appearances above, below or interfering with the specified 3d plane.
    Allowed plane relative positions values are:
    <UL>
    <LI>#TCTRUSHAPE_above_plane
    <LI>#TCTRUSHAPE_below_plane
    <LI>#TCTRUSHAPE_interferes_with_plane
    </UL>
*/
extern TCTRUSHAPE_API int TCTRUSHAPE_spatial_3d_plane_search(
    tag_t                   appearanceRoot,         /**< (I) Appearance set tag against which search is performed */
    int                     planeRelativePosition,  /**< (I) Plane zone spatial relative position to products components */
    VEC3_p_t                planeNormal,            /**< (I) Coordinates of 3d plane zone. Note that no more than one proximity criteria
                                                        (target proximity or zone) can be specified. If both of them are specified,
                                                        then only target proximity search is performed. */
    double                  planeDisplacement,      /**< (I) */
    int*                    numAppearances,         /**< (O) */
    tag_t**                 appearances             /**< (OF) numAppearances Array of appearances matching plane zone criteria */
    );

/**
    Create end item search result object which can be queried for result BOM lines matching all the given criteria,
    i.e. the individual criteria are ANDed together with spatial criteria which are mutually exclusive.

    Possible box or plane zone relative positions are:
    <ul>
    <LI>#TCTRUSHAPE_no_zone_criteria
    <LI>#TCTRUSHAPE_inside_box
    <LI>#TCTRUSHAPE_outside_box
    <LI>#TCTRUSHAPE_interferes_with_box
    <LI>#TCTRUSHAPE_above_plane
    <LI>#TCTRUSHAPE_below_plane
    <LI>#TCTRUSHAPE_interferes_with_plane
    </ul>

    <b>Restrictions:</b>

    Spatial criteria (proximity, plane and box zones) are mutually exclusive. 
    If more than one spatial criteria is specified, function fails and returns an error condition.
*/
extern TCTRUSHAPE_API int TCTRUSHAPE_create_end_item_search_result_object(
    tag_t                   appearanceRoot,             /**< (I) Appearance set tag against which search is performed */
    tag_t                   revisionRule,               /**< (I) Revision rule tag (includes release date or effectivity date and/or number).
                                                            If #NULLTAG, context free (or "all history") search is performed. */
    tag_t                   bomWindow,                  /**< (I) Receiving BOM Window object for result BOM Lines */
    int                     numMappedAttributes,        /**< (I)  */
    char**                  mappedAttributeNames,       /**< (I) List of name/value pairs of attribute mapped to appearance objects 
                                                            (currently limited to the occurrence note strings), e.g. ATA number */
    char**                  mappedAttributeValues,      /**< (I)  */
    int                     numInClassClassNames,       /**< (I)  */
    char**                  inClassClassNames,          /**< (I) Classification class names, e.g. find all the Bolts and Brackets. */
    int                     numInClassAttributes,       /**< (I)  */
    int*                    inClassAttributeIDs,        /**< (I)  */
    char**                  inClassAttributeValues,     /**< (I) List of name/value pairs of Classification attributes. 
                                                            Applicable only if exactly one Classification class name is specified. 
                                                            E.g. give me all the Bolts longer than 6 millimeters. */
    tag_t                   savedQuery,                 /**< (I) Item or item revision saved query tag */
    int                     numEntries,                 /**< (I)  */
    char**                  entries,                    /**< (I) List of name/value pairs of saved query entries attributes.
                                                            Entry names should be a subset of attribute names defined in saved query. */
    char**                  values,                     /**< (I)  */
    int                     numTargets,                 /**< (I)  */
    tag_t*                  targets,                    /**< (I) Proximity search BOM line target tags */
    double                  distance,                   /**< (I) Proximity search distance */
    logical                 includeSubTree,             /**< (I) Add all descendents of target BOMlines to proximity target list. 
                                                            This option is not compatible with "all history" search. */
    int                     boxPlaneRelativePosition,   /**< (I) Plane/box zone spatial relative position to the products components */
    VEC3_t                  planeNormals[6],            /**< (I)  */
    double                  planeDisplacements[6],      /**< (I) Coordinates of 3d plane or box zone. Only one proximity criteria
                                                            (target or zone) can be specified. If both of them are specified,
                                                            then only target proximity search is performed.
                                                            If plane zone searching is requested, only first element of normal and 
                                                            displacement array is used. */
    tag_t*                  searchResultObject          /**< (O) Tag of the search result object which can be used to query for the
                                                            number of found BOM lines and for the groups of the BOM lines satisfying 
                                                            provided criteria. */
    );

/**
    Returns number of bom lines in this search result object.
*/
extern TCTRUSHAPE_API int TCTRUSHAPE_end_item_search_result_ask_bom_line_number(
    tag_t                   searchResultObject,     /**< (I) */
    int*                    numBOMLines             /**< (O) */
    );

/**
    Returns next "numBOMLines" BOM lines from this search result object.
    Note that when last bom line is returned, search result object is deleted and its tag is no longer valid.
*/
extern TCTRUSHAPE_API int TCTRUSHAPE_end_item_search_result_ask_next_bom_lines(
    tag_t                   searchResultObject,     /**< (I) */
    int                     groupNumber,            /**< (I) */
    int*                    numBOMLines,            /**< (O) */
    tag_t**                 bomLines                /**< (O) */
    );

/**
    Returns remaining Appearances from this search result object.
    Please note that after this call search result object is deleted and its tag is no longer valid.
*/
extern TCTRUSHAPE_API int TCTRUSHAPE_end_item_search_result_ask_all_apprs(
    tag_t                   searchResultObject,     /**< (I) */
    int*                    numApprs,            /**< (O) */
    tag_t**                 apprs                /**< (O) */
    );

/**
    Returns remaining BOM lines from this search result object.
    Please note that after this call search result object is deleted and its tag is no longer valid.
*/
extern TCTRUSHAPE_API int TCTRUSHAPE_end_item_search_result_ask_all_bom_lines(
    tag_t                   searchResultObject,     /**< (I) */
    int*                    numBOMLines,            /**< (O) */
    tag_t**                 bomLines                /**< (O) */
    );

/**
    Returns the remaining appearances from this search result object.
    Please note that after this call search result object is deleted and its tag is no longer valid.
*/
extern TCTRUSHAPE_API int TCTRUSHAPE_end_item_search_result_ask_next_apprs(
    tag_t                   searchResultObject,     /**< (I) */
    int                     groupNumber,            /**< (I) */
    int*                    numApprs,               /**< (O) */
    tag_t                   *bomwindow,             /**< (O) */
    tag_t**                 apprs                   /**< (O) */
    );

/**
    Extracts and saves Bounding box and Trushape from a given DirectModel dataset
*/
extern TCTRUSHAPE_API int TRUSHAPE__extract_bbox_trushape(
    tag_t            directmodel_dataset, /**< (I) */
    int              conversion_mode,     /**< (I) */  /* valid values are defined in TRUSHAPE_conversion_mode */
    double           bbox[6]              /**< (O) */
    );

/**
    Extracts the Bounding box information from the provided DirectModel dataset. 
    The bounding box information is not persisted in the database.

    The function returns:
    <ul>
    <li>#ITK_ok on success
    <li>#TCTRUSHAPE_translation_jt2tso_failed, if the bounding box extraction has failed due to any reason.
    </ul>
*/
extern TCTRUSHAPE_API int TRUSHAPE__extract_bbox_nosave(
    tag_t            directmodel_dataset, /**< (I)  tag value of the DirectModel dataset from which the bounding box will be extracted */
    double           bbox[6]              /**< (O)  Bounding box values extracted from the DirectModel dataset */
    );

/**
    Extracts and saves Bounding boxes and Trushape files, given DirectModel datasets.
*/
extern TCTRUSHAPE_API int TRUSHAPE__generate_bbox_trushape_from_jt(
    int num_datasets,                     /**< (I) */
    tag_t* directmodel_datasets,          /**< (I) */
    int conversion_mode,                  /**< (I) */
    int* num_out_datasets,                /**< (O) */
    tag_t** out_datasets,                 /**< (OF) num_out_datasets */
    int* num_error_datasets,              /**< (O) */
    tag_t ** error_datasets,              /**< (OF) num_error_datasets */
    int** error_codes                     /**< (OF) num_error_datasets */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <tctrushape/libtctrushape_undef.h>

#endif
