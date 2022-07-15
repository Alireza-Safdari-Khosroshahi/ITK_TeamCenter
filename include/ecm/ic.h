/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Public ITK header file for Incremental Change module.

    Uses IncrementalChangeElement (ICE) object to link an 'affected object' into an Incremental Change.
    Each ICE either Adds or Removes the affected object. The Incremental Change is thus a collection of
    objects that must be added and removed at the same point to constitute a logical change.

    The Incremental Change is represented by an item revision, typically in implementations of an ECRevision
    (Engineering Change Revision), allowing the logical change itself to evolve through its own lifecycle.

    In the usual case the ICE references the affected object directly. But it can also be used to apply
    incremental change tracking to relationships that are not actually represented by an object in
    the Teamcenter Engineering database. Instead, the relationship is "implied" by a tag reference attribute
    from one object pointing to another object, for example Folder's "contents" attribute referencing an object
    to be "contained" by a folder. This we call the "pseudo-relation" case, the pseudo-relation
    being described by a combination of the parent (referencing) object, child (referenced) object,
    and a string (pseudo_reln_type) that uniquely identifies the referencing attribute and
    conventionally formatted as "<class_name>::<attr_name>", e.g. "Folder::contents"
    (examples used in core being predefined).
*/

/*  */

#ifndef IC_H
#define IC_H

#include <fclasses/tc_basic.h>

/**
    @defgroup IC Incremental Change (IC)
    @ingroup ECM

    <b>Common return values</b>

    <table>
    <tr><td>#IC_duplicate_ice</td>
        <td>An affected object cannot be linked more than once to the same IC revision.</td>
    </tr>
    <tr><td>#IC_no_write_ic_rev</td>
        <td>Creating an ICE requires write access to the parent IC revision.
            This error is returned if you do not have that access.</td>
    </tr>
    <tr><td>#IC_cannot_delete_affected_object</td>
        <td>The ICE was the only Add referencing the affected object,
            so an attempt was made to delete the affected object as well,
            but was blocked due to some other reason, e.g. another reference.</td>
    </tr>
    </table>
    @{
*/

typedef enum IC_change_type_e
{
    IC_add = 1,    /**< For backwards compatability with V8.1/V9.0 definitions. */
    IC_remove
} IC_change_type_t;

/*
** IC_list_type_t is used to describe the types of incremental changes
** made to an affected object.
** Currently not used by any IC ITK
*/
typedef enum IC_list_type_e
{
    IC_list_none = 0,
    IC_list_adds = 1,
    IC_list_removes = 2,
    IC_list_both = 3        /* IC_list_adds |  IC_list_removes */
} IC_list_type_t;


/**
    Predefined pseudo-relation type (PRT).
    Follow "<class_name>::<attr_name>" convention to ensure uniqueness.
*/
#define IC_PRT_folder_contents "Folder::contents"

/**
    Predefined pseudo-relation type (PRT).
    Follow "<class_name>::<attr_name>" convention to ensure uniqueness.
*/
#define IC_PRT_occ_predecessor "PSOccurrence::pred_list"

#include <ecm/libecm_exports.h>

#ifdef __cplusplus
    extern "C"{
#endif

/**
    Creates an IncrementalChangeElement (ICE) to add or remove the affected object as part of the specified IC revision.
*/
extern ECM_API int IC_create_ice(
    tag_t            ic_rev_tag,      /**< (I) Incremental Change (IC) revision that is to be the parent of this ICE */
    tag_t            affected_obj,    /**< (I) Target object of this ICE */
    IC_change_type_t change_type,     /**< (I) IC_add or IC_remove */
    tag_t*           ice              /**< (O) Tag of the newly created (unsaved) ICE */
    );

/**
    Creates an IncrementalChangeElement (ICE) to add or remove a "pseudo relationship",
    identified by the combination of parent, child, and pseudo-relation type.
*/
extern ECM_API int IC_create_ice_pr(
    tag_t            ic_rev_tag,          /**< (I) Incremental Change (IC) revision that is to be the parent of this IC */
    tag_t            child_obj,           /**< (I) Target child (i.e. referenced) object of the pseudo-relation
                                                to be affected by this ICE */
    tag_t            parent_obj,          /**< (I) Target parent (i.e. referencing) object of the pseudo-relation
                                                to be affected by this ICE */
    const char*      pseudo_reln_type,    /**< (I) String identifying the reference attribute of parent that
                                                references child; conventionally formatted as "<class_name>::<attr_name>" */
    IC_change_type_t change_type,         /**< (I) IC_add or IC_remove */
    tag_t*           ice                  /**< (O) Tag of the newly created (unsaved) ICE */
    );

/**
    Deletes a specific ICE. If the ICE is the sole remaining IC_add of an affected object,
    then it will also attempt to delete the affected object - and will error if it fails to do so.
*/
extern ECM_API int IC_delete_ice(
    tag_t          ice    /**< (I) ICE to be deleted */
    );

/**
    Identifies the object affected by an ICE.
    If parent_obj is #NULLTAG, then affected_obj gives the 'regular' affected object,
    and pseudo_reln_type may be ignored.
    Otherwise, this is a pseudo-relation, all three output values are required,
    affected_obj giving the child object.
*/
extern ECM_API int IC_ask_ice_affected_object(
    tag_t          ice,                /**< (I) Tag of the ICE in question */
    tag_t*         affected_obj,       /**< (O) Affected object (if parent_obj #NULLTAG), or child of pseudo-relation. */
    tag_t*         parent_obj,         /**< (O) If not #NULLTAG, this is the tag of the parent object of a pseudo-relation. */
    char**         pseudo_reln_type    /**< (OF) If parent_obj is not #NULLTAG, identifies the type of pseudo-relation affected. */
    );

/**
    Gives the change type (Add or Remove) of the ICE.
*/
extern ECM_API int IC_ask_ice_change_type(
    tag_t             ice,           /**< (I) Tag of the ICE in question */
    IC_change_type_t* change_type    /**< (O) #IC_add or #IC_remove */
    );

/**
    Finds the ICE identified by combination of IC revision and affected object
    ('regular' and pseudo-relation cases respectively).
*/
extern ECM_API int IC_find_ice(
    tag_t          ic_rev_tag,      /**< (I) IC revision */
    tag_t          affected_obj,    /**< (I) Affected object */
    tag_t*         ice              /**< (O) ICE found */
    );

/**
    Finds the ICE identified by combination of IC revision and affected pseudo-relation.
*/
extern ECM_API int IC_find_ice_pr(
    tag_t          ic_rev_tag,          /**< (I) IC revision */
    tag_t          child_obj,           /**< (I) Child of the affected pseudo-relation */
    tag_t          parent_obj,          /**< (I) Parent of the affected pseudo-relation */
    const char*    pseudo_reln_type,    /**< (I) Identifies the type of pseudo-relation */
    tag_t*         ice                  /**< (O) ICE found */
    );

/**
    List all ICEs belonging to an IC revision.
*/
extern ECM_API int IC_list_ices_of_ic_rev(
    tag_t          ic_rev_tag,    /**< (I) IC revision */
    int*           n_ices,        /**< (O) Number of ICEs found */
    tag_t**        ices           /**< (OF) n_ices Array of tags of the ICEs found */
    );

/**
    Find all ICEs affecting a given object ('regular' and pseudo-relation cases respectively).
*/
extern ECM_API int IC_find_ices_affecting_obj(
    tag_t          affected_obj,    /**< (I) Affected object */
    int*           n_ices,          /**< (O) Number of ICEs found */
    tag_t**        ices             /**< (OF) n_ices Array of tags of the ICEs found */
    );

/**
    Finds all ICEs affecting a given pseudo-relation.
*/
extern ECM_API int IC_find_ices_affecting_pr(
    tag_t          child_obj,           /**< (I) Child of the pseudo-relation */
    tag_t          parent_obj,          /**< (I) Parent of the pseudo-relation */
    const char*    pseudo_reln_type,    /**< (I) Identifies the type of pseudo-relation */
    int*           n_ices,              /**< (O) Number of ICEs found */
    tag_t**        ices                 /**< (OF) n_ices Array of tags of the ICEs found */
    );

/**
    Tells you if the affected object is configured by IC in context of the rev rule
    ('regular' affected object and pseudo-relation cases respectively).
*/
extern ECM_API int IC_is_configured(
    tag_t          affected_obj,    /**< (I) Affected object */
    tag_t          rev_rule,        /**< (I) Revision rule */
    logical*       is_configured    /**< (O) True if the affected object is configured in context of the rev rule */
    );

/**
    Tells you if the pseudo-relation is configured by IC in context of the revision rule.
*/
extern ECM_API int IC_is_configured_pr(
    tag_t          child_obj,           /**< (I) Child of the pseudo-relation */
    tag_t          parent_obj,          /**< (I) Parent of the pseudo-relation */
    const char*    pseudo_reln_type,    /**< (I) Identifies the type of pseudo-relation */
    tag_t          rev_rule,            /**< (I) Revision rule */
    logical*       is_configured        /**< (O) True if the pseudo-relation is configured in context of the rev rule */
    );

/**
    As #IC_is_configured, but when is_configured=true, how_configured references an object that
    describes how the revision rule decided the affected object is configured.
    Where 'competing' configured affected objects arise, these can be passed to #CFM_latest_of_latest
    which will tell you which one the revision rule considers to be 'latest'.

    <b>Special case:</b>

    If the target affected object is not qualified by any ICEs,
    then IC deems it to be 'always configured', regardless of revision rule.
    In this case is_configured=true and how_configured = #NULLTAG;
    this value should not be passed to #CFM_latest_of_latest,
    it should be handled by the caller of this function.
*/
extern ECM_API int IC_how_configured(
    tag_t          affected_obj,     /**< (I) Affected object */
    tag_t          rev_rule,         /**< (I) Revision rule */
    logical*       is_configured,    /**< (O) True if the affected object is configured in context of the rev rule */
    tag_t*         how_configured    /**< (O) Describes how the revision rule decided the affected object is configured */
    );

/**
    As #IC_is_configured_pr, but when is_configured=true, how_configured references an object that
    describes how the revision rule decided the pseudo-relation is configured.
    Where 'competing' configured affected objects arise, these can be passed to #CFM_latest_of_latest
    which will tell you which one the revision rule considers to be 'latest'.

    <b>Special case:</b>

    If the target pseudo-relation is not qualified by any ICEs, then IC deems it to be 'always configured',
    regardless of revision rule. In this case is_configured = true and how_configured = #NULLTAG;
    this value should not be passed to #CFM_latest_of_latest,
    it should be handled by the caller of this function.
*/
extern ECM_API int IC_how_configured_pr(
    tag_t          child_obj,           /**< (I) Child of the pseudo-relation */
    tag_t          parent_obj,          /**< (I) Parent of the pseudo-relation */
    const char*    pseudo_reln_type,    /**< (I) Identifies the type of pseudo-relation */
    tag_t          rev_rule,            /**< (I) Revision rule */
    logical*       is_configured,       /**< (O) True if the pseudo-relation is configured in context of the rev rule */
    tag_t*         how_configured       /**< (O) Describes how the revision rule decided the affected object is configured */
    );

/**
    Split the list of ices in incrememtal change ic_rev into incremental change ic_rev_target
*/
extern ECM_API int IC_split_ic(
    tag_t          ic_rev,             /**< (I) */
    int            n_ices,             /**< (I) */
    tag_t*         ices,               /**< (I) */
    tag_t          ic_rev_target       /**< (I) */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <ecm/libecm_undef.h>
#endif
