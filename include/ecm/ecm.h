/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*  */

#ifndef ECM_H
#define ECM_H

#include <unidefs.h>
#include <ecm/ecm_errors.h>
#include <ecm/libecm_exports.h>

/**
    @defgroup ECM Engineering Change Management (ECM)
    @{
*/

/**
    @name Definitions required for CM installation

    Used by install types program
    @{
*/

#define EC_Item_Type_c                          "EngChange"
#define EC_Item_class_name_c                    "Item"
#define EC_Rev_Type_c                           "EngChange Revision"
#define EC_Rev_class_name_c                     "ItemRevision"
#define ECMIMPACTANALYSISTASK_TYPE_NAME         "ECMImpactAnalysisTask"
#define ECMPREPAREECOTASK_TYPE_NAME             "ECMPrepareECOTask"
#define ECMCHECKLISTTASK_TYPE_NAME              "ECMChecklistTask"
#define ECMIMPACTANALYSISTASKTEMPLATE_TYPE_NAME "ECMImpactAnalysisTaskTemplate"
#define ECMPREPAREECOTASKTEMPLATE_TYPE_NAME     "ECMPrepareECOTaskTemplate"
#define ECMCHECKLISTTASKTEMPLATE_TYPE_NAME      "ECMChecklistTaskTemplate"
#define ECM_COMPARE_MODE_NAME                   "ECM_compare_mode"
#define ECM_COMPARE_DESCRIPTOR_NAME             "CMP_std_descriptor_ecm_compare"

/** @} */

/**
    Keep track BOM changes
*/
typedef enum ECM_bom_change_type_e{
    BOM_unknown = 0,
    BOM_Add,               /**< New Type for supporting BOM Changes */
    BOM_Cancel,            /**< New Type for supporting BOM Changes */
    BOM_Quantity_Change,   /**< New Type for supporting Quantity Changes */
    BOM_Move,              /**< New Type for supporting BOM Changes */
    BOM_Reshape,           /**< New Type for supporting BOM Changes */
    BOM_Note_Change,       /**< New Type for supporting Note Changes */
    BOM_Variant_Change,    /**< New Type for supporting Variant Changes */
    LBOM_Add,              /**< New Type for supporting LBOM Changes */
    LBOM_Cancel,           /**< New Type for supporting LBOM Changes */
    LBOM_Quantity_Change   /**< New Type for supporting LBOM Changes */
} ECM_bom_change_type_t;

/**
    Output structure for new ITK calls of V9 Note Change project
*/
typedef struct ECM_note_change_info_s{
    tag_t      notechange_tag;        /**< Tag of note change */
    tag_t      ec_rev_tag;            /**< EC Revision tag */
    tag_t      aff_bvr_tag;           /**< Affected assembly tag */
    tag_t      prob_bvr_tag;          /**< Tag of problem assembly */
    int        no_of_note_changed;    /**< Number of changed note types */
    int        no_of_form_flds;       /**< Number of form types */
    char**     note_type_names;       /**< no_of_note_changed note type names */
    char**     before_values;         /**< no_of_note_changed note type values before change */
    char**     after_values;          /**< no_of_note_changed note type values after change */
    char**     form_fld_names;        /**< no_of_form_flds form type names */
    char**     form_fld_values;       /**< no_of_form_flds form type values */
} ECM_note_change_info_t;

/**
    Output Structure for new ITK Calls of V9.1 BOMChange based on Variant Condition Project
*/
typedef struct ECM_variant_change_info_s{
    tag_t      variantchange_tag;     /**< variant change tag */
    tag_t      ec_rev_tag;            /**< EC Revision tag */
    tag_t      aff_bvr_tag;           /**< Affected assembly tag */
    tag_t      prob_bvr_tag;          /**< Tag of problem assembly */
    int        no_of_form_flds;       /**< Number of form types */
    char*      before_value;          /**< VariantChange value before change */
    char*      after_value;           /**< VariantChange value After change */
    char**     form_fld_names;        /**< no_of_form_flds form type names */
    char**     form_fld_values;       /**< no_of_form_flds form type values */
} ECM_variant_change_info_t;

#ifdef __cplusplus
    extern "C"{
#endif

extern ECM_API int ECM_init_module( void );

/**
    Creates a new EC Item and EC Revision using the given EC ID, Revision ID, name and description.

    It also saves and unlocks newly created Items and Revisions.
    It is necessary to set the EC Type using #ECM_set_ec_type.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if @p ec_id or @p ec_rev_id is invalid
    <li>Possibly other ECM errors
    </ul>
*/
extern ECM_API int ECM_create_ec_item(
    const char*    ec_id,          /**< (I) EC Item ID */
    const char*    ec_rev_id,      /**< (I) EC Revision ID */
    const char*    ec_name,        /**< (I) EC Item name */
    const char*    ec_desc,        /**< (I) EC Item description */
    tag_t*         ec_item,        /**< (O) Tag of the new EC Item */
    tag_t*         ec_rev          /**< (O) Tag of the new EC Revision */
    );

/**
    Sets a new EC Type for the given EC Revision.

    It does not create a new set of EC forms as per the new EC Type.
    It is necessary to detach the old set of forms and attach the desired form(s)
    using ITK functions from the EC Type and Form modules.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if @p ec_rev is invalid
    <li>Possibly other ECM errors
    </ul>
*/
extern ECM_API int ECM_set_ec_type(
    tag_t          ec_rev,        /**< (I) EC Revision tag */
    const char*    ec_type        /**< (I) EC Type to set */
    );

/**
    Retrieves EC Type of the given EC Revision.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if @p ec_rev is invalid
    <li>Possibly other ECM errors
    </ul>
*/
extern ECM_API int ECM_get_ec_type(
    tag_t          ec_rev,        /**< (I) EC Revision tag */
    char**         ec_type        /**< (OF) EC Type */
    );

/**
    Finds the EC Revision, using the EC ID and the Revision ID as input.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if @p ec_id is invalid
    <li>Possibly other ECM errors
    </ul>
*/
extern ECM_API int ECM_find_ec_revision(
    const char*    ec_id,          /**< (I) EC Item ID */
    const char*    ec_rev_id,      /**< (I) EC Revision ID */
    tag_t*         ec_rev          /**< (O) EC Revision tag */
    );


/**
    Retrieves the corresponding Teamcenter Engineering Relation type name of the given EC Pseudo-folder name.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>Possibly other ECM errors
    </ul>
*/
extern ECM_API int ECM_get_relation_of_folder(
    const char*    folder_name,   /**< (I) EC folder name */
    char**         reln_name      /**< (OF) EC relation name */
    );

/**
    Retrieves all Pseudo-folders and corresponding Teamcenter Engineering Relation names
    defined for EC Revision in the "ECM_Pesudofolder_names" site preference.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>Possibly other ECM errors
    </ul>
*/
extern ECM_API int ECM_get_ec_pseudofolder_names(
    int*           n_folders,    /**< (O) Number of EC folder */
    char***        folder_names, /**< (OF) n_folders EC folder name
                                    <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only. */
    char***        reln_names    /**< (OF) n_folders EC relation names
                                    <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only. */
    );

/**
    Retrieves the problem assembly of the given affected assembly with the context of the given EC Revision.

    The relationship is obtained using the internal affected to problem relationship between the corresponding
    affected Revision and its related problem revision.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if @p ec_rev is invalid
    <li>#PS_invalid_bvr if @p bvr is invalid
    <li>Possibly other ECM errors
    </ul> 
*/
extern ECM_API int ECM_get_prev_bvr(
    tag_t          ec_rev,      /**< (I) EC Revision tag */
    tag_t          bvr,         /**< (I) Tag of affected assembly */
    tag_t*         prev_bvr     /**< (O) Tag of problem assembly */
    );

/**
    Retrieves the Teamcenter Engineering Relation type to be used while attaching EC Forms to the EC Revision.

    The Relation type is set by the site DBA in "ECM_form_relation" site preference.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>Possibly other ECM errors
    </ul>     
*/
extern ECM_API int ECM_get_form_relation(
    char**         formRelationType    /**< (O) Default relation type for EC forms */
    );

/**
    Retrieves all affected revisions for the given EC Revision.

    The affected revisions are searched using Teamcenter Engineering Relation type name/names
    mentioned in the "ECM_affected_item_relation" site preference.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if @p ec_rev is invalid
    <li>Possibly other ECM errors
    </ul>
*/
extern ECM_API int ECM_get_affected_items(
    tag_t          ec_rev,       /**< (I) EC Revision tag */
    int*           n_items,      /**< (O) Number of affected revisions */
    tag_t**        items         /**< (OF) n_items Array of affected revision tags */
    );


#ifdef __cplusplus
}
#endif

/** @} */

#include <ecm/libecm_undef.h>
#endif
