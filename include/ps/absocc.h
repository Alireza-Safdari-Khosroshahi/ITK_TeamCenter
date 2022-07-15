/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    ABSOCC - Absolute Occurences
*/

/*  */

#ifndef ABSOCC_H
#define ABSOCC_H

#include <fclasses/tc_basic.h>
#include <ps/libps_exports.h>

/**
    @defgroup ABSOCC Absolute Occurences
    @ingroup PS

    AppearancePathNode related functions
    @{
*/

#define ME_meappearancepathnode_class_name_c    "MEAppearancePathNode"
#define ME_meappearancepathroot_class_name_c    "MEAppearancePathRoot"
#define ME_appearance_group_class_name_c        "AppearanceGroup"
#define ABSOCC_max_attribute_name_length        60


typedef enum ABSOCC_dataTypes
{
    ABSOCC_childItem,
    ABSOCC_flags,
    ABSOCC_gdeobject,
    ABSOCC_grm,
    ABSOCC_instanceNo,
    ABSOCC_name,
    ABSOCC_note,
    ABSOCC_quantity,
    ABSOCC_seqNo,
    ABSOCC_type,
    ABSOCC_variantCondition,
    ABSOCC_xform,
    ABSOCC_posRef,
    ABSOCC_archRef,
    ABSOCC_source,
    ABSOCC_UoM,
    ABSOCC_isDesInPlace,
    ABSOCC_reqPosDesign,
    ABSOCC_effectivity,

    ABSOCC_NUM_TYPES
} ABSOCC_dataTypes_t;

#ifdef __cplusplus
    extern "C"{
#endif

/**
    Given an AppearanceCache, find the corresponding MEAppearancePathNodes.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if the input tag is invalid
    <li>Possibly other POM errors
    </ul>
*/
extern PS_API int ME_get_meapprpathnode_from_appearance(
    tag_t         comp,             /**< (I) Tag of Appearance */
    tag_t*        new_apprpathnode  /**< (O) Pathnode corresponding to the Appearance */
    );

/**
    Given a BOMLine, find the corresponding MEAppearancePathNodes.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if the input tag is invalid
    <li>Possibly other POM errors
    </ul>
*/
extern PS_API int ME_get_meapprpathnode_from_bomline(
    tag_t         comp,             /**< (I) Tag of BOMLine */
    tag_t*        new_apprpathnode  /**< (O) Pathnode corresponding to the BOMLine */
    );

/**
    Given a BOMLine, and a designated rootLine, find the corresponding MEAppearancePathNodes.
    The rootLine will be considered as EndItem.
    If rootLine is NULL, window topLine will be the rootLine

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if the input tag is invalid
    <li>Possibly other POM errors
    </ul>
*/
extern PS_API int ME_get_meapprpathnode_with_root_line(
    tag_t         comp,             /**< (I) Tag of BOMLine */
    tag_t         root_line,        /**< (I) BOMLine considered as root */
    tag_t*        new_apprpathnode  /**< (O) Pathnode corresponding to the BOMLine */
    );

/**
    Create an MEAppearancePathNode, setting its parent, path_root, occ_thread,
    attributes to the given arguments.

    @note This function does not save the new Appearance. Use #AOM_save for that.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if the input tag is invalid
    <li>Possibly other POM errors
    </ul>
 */
extern PS_API int ME_create_meapprpathnode(
    tag_t         path_root,        /**< (I) The MEAppearancePathRoot */
    tag_t         parent,           /**< (I) The parent MEAppearancePathNode */
    tag_t         occ_thread,       /**< (I) The occurrence thread for the new MEAppearancePathNode */
    tag_t*        new_apprpathnode  /**< (O) The created new MEPPrPathNode */
    );

/**
    Given an AppearanceCache, create the corresponding MEAppearancePathNodes.
    <ol>
    <li>PathNode for this Appearance Cache will be created if it doesn't exist
    <li>All PathNodes corresponding to parent lines Appearance Cache Parent
        will be created if they don't exist
    </ol>

    @note This function WILL save the new Path Nodes.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if the input tag is invalid
    <li>Possibly other POM errors
    </ul>
*/
extern PS_API int ME_create_meapprpathnode_from_appearance(
    tag_t         comp,             /**< (I) Tag of Appearance */
    tag_t*        new_apprpathnode  /**< (O) Pathnode corresponding to the comp */
    );

/**
    Given a BOM Line, create the corresponding MEAppearancePathNodes.
    <ol>
    <li>PathNode for this BOMLine will be created if it doesn't exist
    <li>All PathNodes corresponding to parent lines
        will be created if they don't exist
    </ol>

    @note This function WILL save the new Path Nodes.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if the input tag is invalid
    <li>Possibly other POM errors
    </ul>
*/
extern PS_API int ME_create_meapprpathnode_from_bomline(
    tag_t         line_tag,         /**< (I) Tag of BOMLine */
    tag_t*        new_apprpathnode  /**< (O) Pathnode corresponding to the comp */
    );

/**
    Given a BOM Line, and a designated rootLine, create the corresponding
    MEAppearancePathNodes.
    <ol>
    <li>root_line will be used as End Item
    <li>PathNode for this BOMLine will be created if it doesn't exist
    <li>All PathNodes corresponding to parent lines
        will be created if they don't exist
    </ol>

    @note This function WILL save the new Path Nodes.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if the input tag is invalid
    <li>Possibly other POM errors
    </ul>
*/
extern PS_API int ME_create_meapprpathnode_with_root_line(
    tag_t         line_tag,         /**< (I) Tag of BOMLine */
    tag_t         root_line,        /**< (I) BOMLine considered as End Item */
    tag_t*        new_apprpathnode  /**< (O) Pathnode corresponding to the comp */
    );

/**
    Given a BOM Line, update the corresponding MEAppearancePathNodes.
    <ol>
    <li>PathNode for this BOMLine will be created if it doesn't exist
    <li>All PathNodes corresponding to parent lines
        will be created if they don't exist
    <li>All child PathNodes which correspond to child lines
        will be created
    </ol>

    @note This function WILL save the new Path Nodes.
    @note Calls ME__update_apn_from_bomline without populating AbsOccID.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if the input tag is invalid
    <li>Possibly other POM errors
    </ul>
 */
extern PS_API int ME_update_meapprpathnode_from_bomline(
    tag_t         bom_line,         /**< (I) Tag of BOMLine */
    tag_t*        new_apprpathnode  /**< (O) Pathnode corresponding to the comp */
    );

/**
    Given a BOM Line, and a rootLine, update the corresponding MEAppearancePathNodes.
    <ol>
    <li>PathNode for this BOMLine will be created if they don't exist
    <li>All PathNodes corresponding to parent lines
        will be created if they don't exist
    <li>All child PathNodes which correspond to child lines
        will be created
    <li>All pathNodes are related to the rootLine as End Item
    </ol>

    @note This function WILL save the new Path Nodes.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if the input tag is invalid
    <li>Possibly other POM errors
    </ul>
 */
extern PS_API int ME_update_meapprpathnode_with_root_line(
    tag_t         bom_line,         /**< (I) Tag of BOMLine */
    tag_t         root_line,        /**< (I) BOMLine considered as End Item */
    tag_t*        new_apprpathnode  /**< (O) Pathnode corresponding to the comp */
    );

/**
    Retrieves the parent MEAppearancePathNode of a given MEAppearancePathNode.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if the input tag is invalid
    <li>Possibly other POM errors
    </ul>
 */
extern PS_API int ME_meapprpathnode_ask_parent(
    tag_t         path_node,    /**< (I) The MEAppearancePathNode */
    tag_t*        parent        /**< (O) The parent */
    );

/**
    Retrieves the root MEAppearancePathNode of a given MEAppearancePathNode.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if the input tag is invalid
    <li>Possibly other POM errors
    </ul>
 */
extern PS_API int ME_meapprpathnode_ask_pathroot(
    tag_t         path_node,     /**< (I) The MEAppearancePathNode */
    tag_t*        path_root      /**< (O) The root */
    );

/**
    Retrieves the occurrence thread of a given MEAppearancePathNode.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if the input tag is invalid
    <li>Possibly other POM errors
    </ul>
 */
extern PS_API int ME_meapprpathnode_ask_occurrence(
    tag_t         path_node,     /**< (I) The MEAppearancePathNode */
    tag_t*        occ_thread     /**< (O) The occurrence thread */
    );

/**
    Retrieves the appearances of a given MEAppearancePathNode.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if the input tag is invalid
    <li>Possibly other POM errors
    </ul>
 */
extern PS_API int ME_meapprpathnode_ask_apprs(
    tag_t         path_node,    /**< (I) The MEAppearancePathNode */
    int*          num_apprs,    /**< (O) The number of appearances */
    tag_t**       appearances   /**< (OF) numApprs The appearances */
    );

/**
    Retrieves the configured appearance of a given MEAppearancePathNode.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if the input tag is invalid
    <li>Possibly other POM errors
    </ul>
 */
extern PS_API int ME_meapprpathnode_ask_config_appr(
    tag_t         path_ode,    /**< (I) The MEAppearancePathNode */
    tag_t         rev_rule,     /**< (I) The revision rule to configure the appearance */
    tag_t*        appearance    /**< (O) The configured appearance */
    );

/**
    Retrieves the child MEAppearancePathNodes of a given MEAppearancePathNode.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if the input tag is invalid
    <li>Possibly other POM errors
    </ul>
 */
extern PS_API int ME_meapprpathnode_ask_childnodes(
    tag_t         path_node,    /**< (I) The MEAppearancePathNode */
    int*          num_children, /**< (O) The number of child MEAppearancePathNodes */
    tag_t**       children      /**< (OF) numChildren The child MEAppearancePathNodes */
    );

/**
    Remove the appearance from a given MEAppearancePathNode.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if the input tag is invalid
    <li>Possibly other POM errors
    </ul>

 */
extern PS_API int ME_meapprpathnode_remove_appr(
    tag_t         path_node,     /**< (I) The MEAppearancePathNode */
    tag_t         appearance    /**< (I) The appearance to remove */
    );

/**
    Retrieves configured item revision of a given MEAppearancePathNode.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if the input tag is invalid
    <li>Possibly other POM errors
    </ul>

 */
extern PS_API int ME_meapprpathnode_ask_item_revision(
    tag_t         path_node,     /**< (I) The MEAppearancePathNode */
    tag_t         rev_rule,     /**< (I) The revision rule to configure the item */
    tag_t*        item_rev      /**< (O) The configured item revision */
    );

/**
    Creates an MEAppearancePathRoot. It will check whether PathRoot exists.
    Creates PathRoot only if there is no existing PathRoot

    @note This function WILL save the new Path root if got created.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if the input tag is invalid
    <li>Possibly other POM errors
    </ul>

*/
extern PS_API int ME_create_meapprpathroot(
    tag_t         tracked_item,     /**< (I) End item */
    tag_t         tracked_bv,       /**< (I) BOMView of the EndItem */
    tag_t*        new_apprpathroot  /**< (O) Pathroot found or created */
    );

/**
    Retrieves the MEAppearancePathRoot for given tracked item and BOMView.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if the input tag is invalid
    <li>Possibly other POM errors
    </ul>

 */
extern PS_API int ME_get_meapprpathroot(
    tag_t         tracked_item,     /**< (I) The tracked item */
    tag_t         tracked_bv,       /**< (I) The tracked BOMView */
    tag_t*        appr_path_root    /**< (O) The MEAppearancePathRoot */
    );

/**
    Creates an MEAppearancePathRoot. It will check whether PathRoot exists.
    Creates PathRoot only if there is no existing PathRoot.

    @note This function WILL save the new Path root if got created.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if the input tag is invalid
    <li>Possibly other POM errors
    </ul>

*/
extern PS_API int ME_create_meapprpathroot_from_apprroot(
    tag_t         appr_root,        /**< (I) Appearance Set */
    tag_t*        new_apprpathroot  /**< (O) Pathroot found or created */
    );

/**
    Retrieves the MEAppearancePathRoot from a given AppearanceRoot.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if the input tag is invalid
    <li>Possibly other POM errors
    </ul>
 */
extern PS_API int ME_get_meapprpathroot_from_apprroot(
    tag_t         appr_root,      /**< (I) The appearance root */
    tag_t*        appr_path_root  /**< (O) The MEAppearancePathRoot */
    );

/**
    Updates an MEAppearancePathRoot given an Appearance Set. It will check whether
    PathRoot exists. Create PathRoot only if there is no existing PathRoot.
    Also, it will create all PathNode corresponding to the Appearance set.

    @note This function WILL save the new Path root if got created.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if the input tag is invalid
    <li>Possibly other POM errors
    </ul>
*/
extern PS_API int ME_update_meapprpathroot(
    tag_t         appr_root,        /**< (I) Appearance Set */
    tag_t*        new_apprpathroot  /**< (O) Pathroot found or created */
    );

/**
    Create or Update an MEAppearancePathRoot given a BOMWindow;
    The Top Line of the window will be used to create PathRoot if not exists.
    Create and add all PathNodes which are not created according to each child lines

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if the input tag is invalid
    <li>Possibly other POM errors
    </ul>
*/
extern PS_API int ME_create_meapprpathroot_from_window(
    tag_t         bom_window,       /**< (I) The BOM window */
    tag_t*        new_apprpathroot, /**< (O) The new apperance path root */
    tag_t*        top_pathnode      /**< (O) The new root MEAppearancePathNode */
    );

/**
    Retrieves the item of a given MEAppearancePathRoot.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if the input tag is invalid
    <li>Possibly other POM errors
    </ul>
 */
extern PS_API int ME_meapprpathroot_ask_item(
    tag_t         path_root,/**< (I) The MEAppearancePathRoot */
    tag_t*        item      /**< (O) The item */
    );

/**
    Retrieves the BOMView of a given MEAppearancePathRoot.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if the input tag is invalid
    <li>Possibly other POM errors
    </ul>
 */
extern PS_API int ME_meapprpathroot_ask_bomview(
    tag_t         path_root, /**< (I) The MEAppearancePathRoot */
    tag_t*        bom_view   /**< (O) The BOMView */
    );

/**
    Retrieves all MEAppearancePathNodes of a given MEAppearancePathRoot.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if the input tag is invalid
    <li>Possibly other POM errors
    </ul>
 */
extern PS_API int ME_meapprpathroot_ask_pathnodes(
    tag_t         path_root,    /**< (I) The MEAppearancePathRoot */
    int*          child_count,  /**< (O) The number of MEAppearancePathNodes */
    tag_t**       path_nodes    /**< (OF) childCount The MEAppearancePathNodes of the MEAppearancePathRoot */
    );

/**
    Retrieves the item of a given MEAppearancePathNode.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if the input tag is invalid
    <li>Possibly other POM errors
    </ul>
 */
extern PS_API int ME_get_path_node_item(
    tag_t         p1,       /**< (I) The MEAppearancePathNode */
    tag_t*        p1_item   /**< (O) The item */
    );

/**
    Retrieves the parent hierarchy of a given MEAppearancePathNode.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if the input tag is invalid
    <li>Possibly other POM errors
    </ul>
 */
extern PS_API int ME_get_appr_path_node_parent_hierarchy(
    tag_t         p1,               /**< (I) The MEAppearancePathNode */
    tag_t**       parent_path_nodes,/**< (OF) parentCount The ancester MEAppearancePathNodes */
    tag_t**       parent_items,     /**< (OF) parentCount The items of the ancester MEAppearancePathNodes */
    tag_t**       parent_threads,   /**< (OF) parentCount The occurrence threads of the ancester MEAppearancePathNodes */
    int*          parent_count      /**< (O) The number of ancesters of the given MEAppearancePathNode */
    );

/**
    Retrieves all MEAppearancePathNodes for given item and the top item.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if the input tag is invalid
    <li>Possibly other POM errors
    </ul>
 */
extern PS_API int ME_get_appr_path_nodes_for_component(
    tag_t         component_item,   /**< (I) The item */
    tag_t         top_item,         /**< (I) The top item of the structure */
    tag_t**       path_nodes,       /**< (OF) The MEAppearancePathNodes for the given item and top item */
    int*          path_count        /**< (O) The number of MEAppearancePathNodes */
    );

/** @} */

#ifdef __cplusplus
    }
#endif

#include <ps/libps_undef.h>

#endif
