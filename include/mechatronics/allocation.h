/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This header file contains ITK API definitions for Allocations related functionality.
*/

/*  */

#ifndef ALLOCATION_H
#define ALLOCATION_H

#include <unidefs.h>
#include <mechatronics/libmechatronics_exports.h>

/**
    @defgroup ALLOC Allocations
    @ingroup MECHATRONICS

    This module defines the required ITK interface for Allocation related operations.
    @{
*/


#ifdef __cplusplus
    extern "C"{
#endif
/** 
   This function creates an allocation map between a source BOM view and a target BOM view.
   This will also create an initial revision of the allocation map.

   @note This itk will not save the object. AOM_save_with_extensions needs to be called separately to save the object.
*/
extern MECHATRONICS_API int ALLOC_create_map (
    const char *id,        /**< (I) Id of allocation map */
    const char *name,      /**< (I) Allocation map name */
    const char *type,      /**< (I) Allocation map type */
    const char *rev_id,    /**< (I) Revision string */
    tag_t source_bv_tag,   /**< (I) Tag of source BOM view */
    tag_t target_bv_tag,   /**< (I) Tag of target BOM view */
    tag_t *map,            /**< (O) Tag of allocation map created */
    tag_t *map_rev         /**< (O) Tag of allocation map revision created */
);

/** 
   This function returns the source BOM view for a given allocation map.
*/
extern MECHATRONICS_API int ALLOC_ask_map_source (
    tag_t map,                  /**< (I) Tag of allocation map */
    tag_t *source_bv_tag        /**< (O) Tag of source BOM view */
);

/** 
   This function returns the target BOM view for a given allocation map.
*/
extern MECHATRONICS_API int ALLOC_ask_map_target (
    tag_t map,                  /**< (I) Tag of allocation map */
    tag_t *target_bv_tag        /**< (O) Tag of target BOM view */
);

/** 
   This function revises an existing allocation map to create a new revision.
   On setting the preference ALLOC_map_copy_allocations to value 'Revise',
   the new revision will get a copy of all allocations from the existing revision.

   @note This itk will not save the object. AOM_save_with_extensions needs to be called separately to save the object.
*/
extern MECHATRONICS_API int ALLOC_create_map_rev (
    tag_t   map,            /**< (I) Tag of allocation map */
    const char   *rev_id,   /**< (I) Allocation map revision to be copied */
    tag_t  *new_rev         /**< (O) Tag of new revision created */
);


/** 
   This function creates a copy of the allocation map object and points to the 
   the same list of bomviews as the given allocation map. The copied allocation
   map revision will contain all allocations if the prefernece ALLOC_map_copy_allocations
   has value 'copy'.
*/
extern MECHATRONICS_API int ALLOC_copy_map (
    tag_t map_rev,                /**< (I) Tag of allocation map revision to be copied */
    const char *new_map_id,       /**< (I) Allocation map id for copy */
    const char *new_map_rev_id,   /**< (I) Revision string for copy */
    tag_t *new_map,               /**< (O) Tag of copied allocation map */
    tag_t *new_map_rev            /**< (O) Tag of copied allocation map revision */
);

/** 
   This function searches the database for allocation map objects that refer to a given
   view as source view and a given view as target view. NULLTAGs can be specified
   for source view and target view to indicate wildcards (meaning any).
*/
extern MECHATRONICS_API int ALLOC_find_map (
    tag_t   source_bv_tag,      /**< (I) Tag of source BOM view */
    tag_t   target_bv_tag,      /**< (I) Tag of target BOM view */
    int     *map_count,         /**< (O) Number of allocation maps found */
    tag_t   **map_tags          /**< (OF) Tag array of allocations maps found */
);


/**
   This function searches for allocation objects in the database that point to a given
   map rev as the owning map rev.
*/
extern MECHATRONICS_API int ALLOC_ask_allocations (
    tag_t map_rev,          /**< (I) Tag of allocation map revision */
    int *allocation_count,  /**< (O) Number of allocations found */
    tag_t **alloc_tags      /**< (OF) Tag array of allocations found */
);

/** 
   This function searches for all configured allocation objects in the database that point
   to the given map rev as the owning map rev.
*/
extern MECHATRONICS_API int ALLOC_ask_configured_allocations (
    tag_t   map_rev,                 /**< (I) Tag of allocation map revision */
    tag_t revision_rule,             /**< (I) Tag of revision rule to be used for configuring allocations */
    int     *allocation_count,       /**< (O) Number of configured allocations */
    tag_t   **allocation_tags        /**< (OF) Array of configured allocation tags */
);

/** 
   This function creates a new allocation object with a single source 
   and target bomline
*/
extern MECHATRONICS_API int ALLOC_create_allocation (
    const char *name,           /**< (I) Name of allocation to be created */
    const char *type,           /**< (I) Type of allocation to be created */
    tag_t source_bom_line,      /**< (I) Tag of source BOM line */
    tag_t target_bom_line,      /**< (I) Tag of target BOM line */
    tag_t map_rev,              /**< (I) Tag of allocation map revision */
    tag_t *allocation           /**< (O) Tag of allocation created */
);

/** 
   This function assigns the reason string to allocation that explains
   the purpose of creating this allocation.
*/
extern MECHATRONICS_API int ALLOC_set_reason (
    tag_t allocation_tag,       /**< (I) Tag of allocation */
    const char  *reason         /**< (I) Reason to be assigned */
); 

/** This function returns the reason string specified on an allocation.  */ 
extern MECHATRONICS_API int ALLOC_ask_reason ( 
    tag_t allocation_tag,       /**< (I) Tag of allocation */ 
    char **reason               /**< (OF) Reason assigned to the allocation */
); 

/** 
   This function searches for all allocation objects in the database that
   point to the given BOM line as source BOM line and point to the given
   map rev as the owning map rev. NULLTAG is treated as wild card (meaning any).
*/
extern MECHATRONICS_API int ALLOC_find_allocations_for_source (
    tag_t source_bom_line,      /**< (I) Tag of source BOM line */
    tag_t map_rev,              /**< (I) Tag of allocation map revision */
    int *allocationCount,       /**< (O) Number of allocations found */
    tag_t **alloc_tags          /**< (OF) Array of allocation tags */
);

/** 
   This function searches for all allocation objects in the database that
   point to the given BOM line as target BOM line and point to the given 
   map rev as the owning map rev. NULLTAG is treated as wild card (meaning any).
*/
extern MECHATRONICS_API int ALLOC_find_allocations_for_target (
    tag_t target_bom_line,      /**< (I) Tag of target BOM line */
    tag_t map_rev,              /**< (I) Tag of allocation map revision */
    int *allocationCount,       /**< (O) Number of allocations found */
    tag_t **alloc_tags          /**< (OF) Array of allocation tags */
);

/** 
   This function returns the source BOM line for a given allocation. 
*/
extern MECHATRONICS_API int ALLOC_ask_source (
    tag_t allocation,           /**< (I) Allocation tag */
    tag_t source_bom_window,    /**< (I) BOMWindow of interest for source  */
    tag_t *source_bom_line      /**< (O) Tag of source BOM line */
);

/** 
   This function returns the target BOM line for a given allocation. 
*/
extern MECHATRONICS_API int ALLOC_ask_target (
    tag_t allocation,           /**< (I) Allocation tag */
    tag_t target_bom_window,    /**< (I) BOMWindow of interest for target  */
    tag_t *target_bom_line      /**< (O) Tag of target BOM line */
);

/** 
   This function sets the target BOM line for a given allocation. 
*/
extern MECHATRONICS_API int ALLOC_set_target (
    tag_t allocation,           /**< (I) Tag of allocation */
    tag_t target_bom_line       /**< (I) Tag of target BOM line */
);

/** 
   This function sets the source BOM line for a given allocation. 
*/
extern MECHATRONICS_API int ALLOC_set_source (
    tag_t allocation,           /**< (I) Tag of allocation */
    tag_t source_bom_line       /**< (I) Tag of source BOM line */
);


/** 
   This function changes the target BOM line for a given allocation using incremental change.
*/
extern MECHATRONICS_API int ALLOC_change_target (
    tag_t allocation,           /**< (I) Tag of allocation */
    tag_t target_bom_line,      /**< (I) Tag of target BOM line */
    tag_t ic_rev                /**< (I) Tag of incremental change revision */
);

/** 
   This function returns the owning allocation map revision for a given allocation. 
*/
extern MECHATRONICS_API int ALLOC_ask_map_rev (
    tag_t allocation,           /**< (I) Allocation map tag */
    tag_t *map_rev_tag          /**< (O) Tag of corresponding allocation map revision */
);


/** 
   This function returns the configuration condition for a given allocation.
*/
extern MECHATRONICS_API int ALLOC_ask_condition (
    tag_t allocation,           /**< (I) Allocation tag */
    tag_t *condition            /**< (O) Tag of configuration condition defined on the allocation */
);

/** 
   This function sets the configuration condition for a given allocation.
*/
extern MECHATRONICS_API int ALLOC_set_condition (
    tag_t allocation,           /**< (I) Allocation tag */
    tag_t condition             /**< (I) Tag of configuration condition to set on allocation */
);

/** 
   This function changes the configuration condition for a given allocation using incremental change.
*/
extern MECHATRONICS_API int ALLOC_change_condition (
    tag_t allocation,           /**< (I) Allocation tag */
    tag_t condition,            /**< (I) Tag of configuration condition to set on allocation */
    tag_t ic_rev                /**< (I) Tag of incremental change revision */
);

/** 
   This function returns the target BOM line tags allocated for a source BOM line.
*/
extern MECHATRONICS_API int ALLOC_ask_allocated_to (
    tag_t source_bom_line,              /**< (I) Tag of source BOM line */
    tag_t alloc_map_rev,                /**< (I) Tag of allocation map revision */
    tag_t target_bom_window,            /**< (I) Tag of target BOMWindow */
    tag_t revision_rule,                /**< (I) Tag of revision rule to be used for configuring allocations */
    int  *bom_line_count,               /**< (O) Number of BOM lines */
    tag_t **allocated_to_bom_lines      /**< (OF) Array of target BOM lines allocated to given source BOM line*/
);

/** 
   This function returns the source BOM line tags allocated for a target BOM line.
*/
extern MECHATRONICS_API int ALLOC_ask_allocated_from (
    tag_t target_bom_line,              /**< (I) Tag of target BOM line */
    tag_t alloc_map_rev,                /**< (I) Tag of allocation map revision */
    tag_t source_bom_window,            /**< (I) Tag of source BOMWindow */
    tag_t revision_rule,                /**< (I) Tag of revision rule to be used for configuring allocations */
    int  *bom_line_count,               /**< (O) Number of BOM lines */
    tag_t **allocated_from_bom_lines    /**< (OF) Array of source BOM lines from which the target BOM line is allocated */
    );


/** 
   This function creates an allocation map pointing to a set of bomviews.
   This will also create an initial revision of the allocation map.

   @note This itk will not save the object. AOM_save_with_extensions needs to be called separately to save the object.
*/
extern MECHATRONICS_API int ALLOC_create_allocation_map (
    const char *id,                     /**< (I) Id of allocation map */
    const char *name,                   /**< (I) Allocation map name */
    const char *type,                   /**< (I) Allocation map type */
    const char *rev_id,                 /**< (I) Revision string */
    int bomview_count,                  /**< (I) Bomview count   */
    tag_t *bomviews,                    /**< (I) All bomviews that will be associated with the allocation map */
    tag_t *map,                         /**< (O) Tag of allocation map created */
    tag_t *map_rev                      /**< (O) Tag of allocation map revision created */
);

/** 
   This function will get all bomviews associated to the allocation map object.
*/
extern MECHATRONICS_API int ALLOC_map_ask_bomviews (
    tag_t alloc_map,                    /**< (I) Tag of the allocation map object */
    int *bomview_count,                 /**< (O) Count of bomviews returned */
    tag_t **bomviews                    /**< (OF) Tag list of bomviews that are associated to the allocation map */
);

/** 
  This function will add the bomviews to the allocation map object.
*/
extern MECHATRONICS_API int ALLOC_map_add_bomviews (
    tag_t alloc_map,                    /**< (I) Tag of the allocation map object */
    int bomview_count,                  /**< (I) Count for bomview */
    tag_t *bomviews                     /**< (I) Tag list of bomviews that needs to be associated to the allocation map */
);

/** 
   This function will remove the bomviews from the allocation map object
*/
extern MECHATRONICS_API int ALLOC_map_remove_bomviews (
    tag_t alloc_map,                    /**< (I) Tag of the allocation map object */
    int bomview_count,                  /**< (I) Count of bomviews */
    tag_t *bomviews                     /**< (I) Tag list of bomviews that needs to be removed from the allocation map */
);

/** 
   This function will get all allocation maps that are associated to the bomview tag 
*/
extern MECHATRONICS_API int ALLOC_find_all_maps_for_bomview (
    tag_t bomview,                      /**< (I)  Tag of the bomview */
    int *allocation_map_count,          /**< (O)  Count of allocation map objects returned*/
    tag_t **allocation_maps             /**< (OF) Tag list of all allocations that associates the bomview */
);

/** 
   This function creates a new allocation object between multiple source and targets that span between multiple bomviews.
*/
extern MECHATRONICS_API int ALLOC_create_new_allocation (
    const char *name,                   /**< (I) Name of allocation to be created */
    const char *type,                   /**< (I) Type of allocation to be created */
    int source_count,                   /**< (I) Count of Source APNs to be associated to the allocation*/
    tag_t *sources,                     /**< (I) Tag list of source APNs for the allocation*/
    int target_count,                   /**< (I) Count of Target APNs to be associated to the allocation*/
    tag_t *targets,                     /**< (I) Tag list of target APNs for the allocation*/
    tag_t map_rev,                      /**< (I) Tag of allocation map revision*/
    tag_t *allocation                   /**< (O) Tag of allocation created*/
);

/** 
   This function returns the source apns associated for a given allocation
*/
extern MECHATRONICS_API int ALLOC_ask_sources (
    tag_t allocation,                   /**< (I) Allocation tag */
    int *source_count,                  /**< (O) Count of source APNs returned*/
    tag_t **sources                     /**< (OF) Tag list of all source APNs associated to the allocation*/
);

/** 
   This function sets the source apns for a given allocation. This method will replace
   the existing list of sources for the allocation with the new sources passed.
*/
extern MECHATRONICS_API int ALLOC_set_sources (
    tag_t allocation,                   /**< (I) Tag of allocation*/
    int source_count,                   /**< (I) Count of source APNs*/
    tag_t *sources                      /**< (I) Tag list of source APNs to be associated to the allocation*/
);

/** 
   This function adds the input sources to the existing sources for a given allocation
*/
extern MECHATRONICS_API int ALLOC_add_sources (
    tag_t allocation,                   /**<  (I) Tag of allocation*/
    int source_count,                   /**<  (I) Count of source APNs to be added*/
    tag_t *sources                      /**<  (I) Tag list of the source APNs that needs to be added to the allocation*/
);

/** 
   This function removes the input sources from the existing sources for a given allocation
*/
extern MECHATRONICS_API int ALLOC_remove_sources (
    tag_t allocation,                   /**<  (I) Tag of allocation*/
    int source_count,                   /**<  (I) Count of source APNs*/
    tag_t *sources                      /**<  (I) Tag list of source APNs to be removed from the allocation*/
);

/** 
   This function returns the target apns associated to the given allocation
*/
extern MECHATRONICS_API int ALLOC_ask_targets (
    tag_t allocation,                   /**<  (I) Allocation tag*/
    int *target_count,                  /**<  (O) Count of target APNs returned*/
    tag_t ** targets                    /**<  (OF) Tag list of target APNs associated to the allcoation*/
);

/** 
   This function sets the target apns for a given allocation. This method will replace
   the existing list of targets for the allocation with the new targets passed.
*/
extern MECHATRONICS_API int ALLOC_set_targets (
    tag_t allocation,                   /**< (I) Allocation tag*/
    int target_count,                   /**< (I) Count of target APNs returned*/
    tag_t *targets                      /**< (I) Tag list of target APNs associated to the allcoation*/
);

/** 
   This function adds the input targets to the existing targets for a given allocation
*/
extern MECHATRONICS_API int ALLOC_add_targets (
    tag_t allocation,                   /**< (I) Tag of allocation*/
    int target_count,                   /**< (I) Count of target APNs to be added*/
    tag_t *targets                      /**< (I) Tag list of the target APNs that needs to be added to the allocation*/
);

/** 
   This function removes the input targets from the existing targets for a given allocation
*/
extern MECHATRONICS_API int ALLOC_remove_targets (
    tag_t allocation,                   /**< (I) Tag of allocation*/
    int target_count,                   /**< (I) Count of target APNs*/
    tag_t *targets                      /**< (I) Tag list of target APNs to be removed from the allocation*/
);

/** 
   This function searches for all allocation objects in the database that point to
   the given allocation map rev as the owning map rev and having any of the given 
   sources as the associated source apns.
   NULLTAG is treated as wild card (meaning any)
*/
extern MECHATRONICS_API int ALLOC_find_allocations_for_sources (
    int source_count,                   /**< (I) Number of source APNs*/
    tag_t *sources,                     /**< (I) List of source APNs*/
    tag_t map_rev,                      /**< (I) Tag of allocation map revision*/
    int *allocation_count,              /**< (O) Number of allocations found*/
    tag_t **allocation_tags             /**< (OF) Array of allocation tags */
);

/** 
  This function searches for all allocation objects in the database that point to
  the given allocation map rev as the owning map rev and having any of the given 
  targets as the associated target apns.
  NULLTAG is treated as wild card (meaning any).
*/
extern MECHATRONICS_API int ALLOC_find_allocations_for_targets (
    int target_count,                   /**< (I) Count of target APNs*/
    tag_t *targets,                     /**< (I) List of target APNs*/
    tag_t map_rev,                      /**< (I) Tag of allocation map revision*/
    int *allocation_count,              /**< (O) Number of allocations found*/
    tag_t **allocation_tags             /**< (OF) Array of allocation tags */
);

/** 
   This function searches for all targets that are associated to the set of source apns 
   and the map revision passed as input.
   NULLTAG is treated as wild card (meaning any).
*/
extern MECHATRONICS_API int ALLOC_find_allocated_to ( 
    int source_count,                   /**< (I) Number of source APNs*/
    tag_t *sources,                     /**< (I) List of source APNs*/
    tag_t map_rev,                      /**< (I) Tag of allocation map revision*/
    int *target_count,                  /**< (O) Number of target APNs found*/
    tag_t **targets                     /**< (OF) Array of target APN tags*/
);

/** 
   This function searches for all source apns that are associated to the set of target 
   apns and the map revision passed as input.
   NULLTAG is treated as wild card (meaning any).
*/
extern MECHATRONICS_API int ALLOC_find_allocated_from (
    int target_count,                   /**< (I) Number of target APNs */
    tag_t *targets,                     /**< (I) List of target APNs*/
    tag_t map_rev,                      /**< (I) Tag of allocation map revision*/
    int *source_count,                  /**< (O) Number of source APNs found*/
    tag_t **sources                     /**< (OF) Array of source APN tags */
);

/** 
   This function changes the targets for the given allocation based on IC revision.
   The target apns from target_to_remove will be removed and the targets from
   target_to_add will be added to the existing list of target apns for the allocation.
*/
extern MECHATRONICS_API int ALLOC_change_targets(
    tag_t allocation,                   /**< (I) Input allocation tag */
    int target_remove_count,            /**< (I) Number of target APNs to be removed*/ 
    tag_t *targets_to_remove,           /**< (I) APN target tags to be removed*/
    int target_add_count,               /**< (I) Number of new target APNs to be added*/
    tag_t *targets_to_add,              /**< (I) List of new APN tags to be added*/
    tag_t ic_rev                        /**< (I) Incremental change revision */
);

/** 
   This function changes the sources for the given allocation based on IC revision.
   The source apns from sources_to_remove will be removed from the existing source list
   and sources_to_add will be added to the existing list of source apns for the allocation.
*/
extern MECHATRONICS_API int ALLOC_change_sources(
    tag_t allocation,                   /**< (I)  Input allocation tag */
    int source_remove_count,            /**< (I)  Number of source APNs to be removed*/ 
    tag_t *sources_to_remove,           /**< (I)  Source APN tags to be removed*/
    int source_add_count,               /**< (I)  Number of new APNs to be added*/
    tag_t *sources_to_add,              /**< (I)  List of new source APN tags to be added*/
    tag_t ic_rev                        /**< (I)  Incremental change revision */
);

/** 
   This API provides a means for users to hook-up thier business logic to 
   define what a complete Allocation can be in Teamcenter.
   By-default this API returs a True value, in other words it is
   users who are to decide what it means for a Allocation to be complete.
   The Input parameter of allocation window is Optional.
*/
extern MECHATRONICS_API int ALLOC_is_allocation_complete(
    tag_t allocation,                   /**< (I) Input allocation tag */
    tag_t allocation_window,            /**< (I) Input allocation window tag - Optional */
    logical *is_complete                /**< (O) Flag indicating whether this allocation Object is a complete or not*/
);

/** 
   This API provides a means for users to hook-up thier business logic to 
   define what a correct Allocation can be in Teamcenter.
   By-default this API returs a True value, in other words it is
   users who are to decide what it means for a Allocation to be correct.
   The Input parameter of allocation window is Optional!
*/
extern MECHATRONICS_API int ALLOC_is_allocation_correct(
    tag_t allocation,                   /**< (I) Input allocation tag */
    tag_t allocation_window,            /**< (I) Input allocation window tag - Optional */
    logical *is_correct                 /**< (O) Flag indicating whether this allocation Object is a complete or not*/
);


/**
 * Determines if an Incremental Change Element (ICE) needs to be created for a change on a Allocation line.
 * @returns 
 * <ul>
 * <li>#ITK_ok on success.
 * <li>#BOM_invalid_tag if an invalid tag if provided for Allocation line.
 * <li>Possibly other errors, as the extension functions are implemented by customers.
 * </ul>
 */
extern MECHATRONICS_API int MECHATRONICS_should_create_ice(
    tag_t line,                        /**< (I) Tag of Allocation line */
    logical* track                     /**< (O) If ICE needs to be created */
    );
/** @} */

#ifdef __cplusplus
}
#endif

#include <mechatronics/libmechatronics_undef.h>
#endif
