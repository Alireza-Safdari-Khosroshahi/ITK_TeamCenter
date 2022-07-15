/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*  */

#ifndef MELINE_H_INCLUDED
#define MELINE_H_INCLUDED

#include <bom/bom_attr.h>
#include <bom/bom_errors.h>
#include <bom/bom_tokens.h>
#include <fclasses/tc_basic.h>
#include <me/libme_exports.h>
/* END OF HEADER */

#ifdef __cplusplus
    extern "C"{
#endif

/**
    @defgroup MELINE BOP Line Functions
    @ingroup ME
    @{
*/

/**
    Link current bom_line to a corresponding appearance for appline.
    This is done for a consumed item for Manufacturing Process Planning using
    a relation type of IMAN_MEProductAppearance.
*/
extern ME_API int BOP_line_link_to_appearance(
    tag_t         bom_line,     /**< (I) */
    tag_t         appline,      /**< (I) */
    logical       asRequired    /**< (I) */
    );

/**
    Remove a GRM from current line to its appearance

    @note The appearance is linked for a consumed item for
    Manufacturing Process Planning using a relation type of IMAN_MEProductAppearance.
*/
extern ME_API int BOP_line_remove_appearance(
    tag_t         bom_line,     /**< (I) */
    tag_t         appearance,   /**< (I) */
    logical       asRequired    /**< (I) */
    );

extern ME_API int BOP_line_ask_appearance(
    tag_t         bomline,      /**< (I) */
    int*          count,        /**< (O) */
    tag_t*        appearance    /**< (O) count */
    );

/**
    Find all linked appearances to this line.
*/
extern ME_API int BOP_line_ask_linked_appearances(
    tag_t         bom_line,         /**< (I) */
    logical       requiredOnly,     /**< (I) */
    int*          count,            /**< (O) */
    tag_t**       appearances       /**< (OF) count */
    );

/**
    Find all occurrences linked to this line's appearance.
*/
extern ME_API int BOP_line_ask_appearance_links(
    tag_t         bom_line,         /**< (I) */
    char*         relation_type,    /**< (I) */
    int*          count,            /**< (O) */
    tag_t**       appearances       /**< (OF) count */
    );

/**
    Adds a new component to given line.
*/
extern ME_API int BOP_line_add(
    tag_t         bom_line,             /**< (I) Bomline to add to */
    tag_t         item_folder,          /**< (I) Item to add, ignored if rev specified */
    tag_t         item_revision_folder, /**< (I) Item rev to add.
                                           For specifying the revision when adding to precise bvrs,
                                           if null the item's configured revision is used. */
    tag_t         bv,                   /**< (I) The child's bom view, if any, 
                                           to be shown if the new child is expanded. Optional. */
    tag_t*        new_line              /**< (O) The new bomline */
    );

/**
    Adds a new component to given line.
*/
extern ME_API int BOP_line_add_with_occ_type(
    tag_t         bom_line,             /**< (I) Bomline to add to */
    tag_t         item_folder,          /**< (I) Item to add, ignored if rev specified */
    tag_t         item_revision_folder, /**< (I) Item rev to add.
                                           For specifying the revision when adding to precise bvrs,
                                           if null the item's configured revision is used. */
    tag_t         bv,                   /**< (I) The child's bom view, if any,
                                           to be shown if the new child is expanded. Optional. */
    char*         occType,              /**< (I) */
    tag_t*        new_line              /**< (O) The new bomline */
    );

/**
    Adds a new line as a substitute to the given preferred/non-substitute line.
    If the given line currently has no substitutes, the given line becomes the 'preferred' substitute.
    See #BOP_line_add for description of arguments.
*/
extern ME_API int BOP_line_add_substitute(
    tag_t         bom_line,         /**< (I) */
    tag_t         item,             /**< (I) */
    tag_t         item_revision,    /**< (I) */
    tag_t         bom_view,         /**< (I) */
    tag_t*        new_line          /**< (O) */
    );
/**
    Deprecated this will be obsoleted. Use BOP_line_add_substitute.
*/
extern ME_API int BOP_line_add_alternate(
    tag_t         bom_line,         /**< (I) */
    tag_t         item,             /**< (I) */
    tag_t         item_revision,    /**< (I) */
    tag_t         bom_view,         /**< (I) */
    tag_t*        new_line          /**< (O) */
    );

/**
    Adds a new appearance group bop line to the given line.
*/
extern ME_API int BOP_line_add_app_group(
    tag_t         parent,           /**< (I) */
    tag_t         app_group,        /**< (I) */
    logical       as_substitute,    /**< (I) If True, the appropriate error is generated */
    tag_t*        new_bom_line      /**< (O) */
    );

/**
    Adds a new appearance group bop line to the given line.
*/
extern ME_API int BOP_line_add_app_group_with_occ_type(
    tag_t         parent,           /**< (I) */
    tag_t         app_group,        /**< (I) */
    logical       as_substitute,    /**< (I) If True, the appropriate error is generated */
    char*         occType,          /**< (I) */
    tag_t*        new_bom_line      /**< (O) */
    );

/**
    Create an assembly tree from the input process line.
*/
extern ME_API int BOP_line_create_assembly_tree(
    tag_t         bopline,      /**< (I) */
    logical       onOperation,  /**< (I) */
    logical       updateOnly,   /**< (I) True: update assembly tree <br>
                                        False: create assembly tree */
    tag_t*        viewTag       /**< (I/O) When viewTag is #NULLTAG,
                                        the system will create a view with default name onOperation, where: <br>
                                        True: create assembly tree based on operations only <br>
                                        False: Create assembly tree based on processes only */
    );

/**
    Updates an assembly tree from the input process line.
*/
extern ME_API int BOP_line_update_workpiece(
    tag_t         bopline,      /**< (I) */
    logical       selfOnly      /**< (I) True: only update workpiece on the input bopline <br>
                                        False: update the workpieces from the input bopline to the top line */
    );

/** 
    Re-order sequence number for all immediate children of input process line.
*/
extern ME_API int BOP_line_change_sequence_number(
    tag_t         bopline,      /**< (I) */
    int           startNum,     /**< (I) Start sequence number */
    int           incrNum       /**< (I) Incremental sequence number */
    );

/** 
    Show bopline based on the occurrence type filter 
*/
extern ME_API int BOP_window_show_occ_type_filter(
    tag_t         bopWindow     /**< (I) The BOP window tag */
    );

/** 
    Show all boplines (not based on occ type filter)  
*/
extern ME_API int BOP_window_hide_occ_type_filter(
    tag_t         bopWindow     /**< (I) The BOP window tag */
    );

extern ME_API int BOP_window_set_occ_type_filter(
    tag_t         window_tag,   /**< (I) */
    int           count,        /**< (I) */
    char**        typeList      /**< (I) */
    ); 

extern ME_API int BOP_window_get_occ_type_filter(
    tag_t         window_tag,   /**< (I) */
    int*          count,        /**< (O) */
    char***       typeList      /**< (OF) count */
    );

extern ME_API int APPGRP_line_add(
    tag_t         appGrpLine_tag,       /**< (I) > */
    tag_t         child_tag             /**< (I) > */
);

extern ME_API int BOPLine_set_occ_group_base_mode(
    tag_t bopline_tag,           /**< (I) > */ 
    logical view_mode_in_base    /**< (I) > */
    );

/**
 * Determines if an Incremental Change Element (ICE) needs to be created for a change on a Attachment line.
 * @returns 
 * <ul>
 * <li>#ITK_ok on success.
 * <li>#BOM_invalid_tag if an invalid tag if provided for Attachment line.
 * <li>Possibly other errors, as the extension functions are implemented by customers.
 * </ul>
 */
extern ME_API int ME_should_create_ice(
    tag_t line,                        /**< (I) Tag of Attachment line */
    logical* track                     /**< (O) If ICE needs to be created */
    );


/** @} */

#ifdef __cplusplus
}
#endif

#include <me/libme_undef.h>

#endif
