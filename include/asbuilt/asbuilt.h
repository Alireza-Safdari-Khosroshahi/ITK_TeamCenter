/*==============================================================================
                Copyright (c) 2008 Siemens PLM Software
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This header file declares all data types and constants to be used by clients of
    MRO module.
*/

#ifndef ASBUILT_H
#define ASBUILT_H

#include <mrocore/mrocore.h>

#include <asbuilt/libasbuilt_exports.h>

#ifdef __cplusplus
    extern "C"{
#endif

/**
    @defgroup ASBUILT As-Built

    The As-Built (AsBuilt) module implements the As-Built Structure management behaviour.

    @{
*/

/**
    Initializes the asbuilt module. You must call this function before calling any other ASBUILT functions.
*/
extern ASBUILT_API int ASBUILT_init_module();



/**
    ITK function to get Child Lines for selected Physical BOM Line
*/
extern ASBUILT_API int ASBUILT_line_ask_all_child_lines(
    tag_t          bom_line,           /**< (I) Tag of BOM Line */
    int*           count,              /**< (O) Count */
    tag_t**        children            /**< (OF) Tags of Child BOM Lines */
    );

/**
    ITK function to set top AsBuilt BOM Line in MRO BOM Window
*/
extern ASBUILT_API int ASBUILT_line_set_window_top(
    tag_t          window,                 /**< (I) Tag of MRO BOM Window */
    tag_t          physicalPart,           /**< (I) Tag of Physical Part */
    tag_t          physicalPartRevision,   /**< (I) Tag of Physical Part Revision */
    tag_t*         topBOMLine              /**< (O) Tag of top BOM Line */
    );


/**
    ITK function to generate AsBuilt Structure
*/
extern ASBUILT_API int ASBUILT_gen_phystruc(
    tag_t                       inLine,                 /**< (I) Parent BOM line whose children are wanted */
    GenerateStructureParams*    inParam,                /**< (I) Parent BOM line whose children are wanted */
    tag_t*                      phys_rev                /**< (O) count Returned lines */
    );

/**
    ITK function to get all open usage values
*/
extern ASBUILT_API int ASBUILT_get_all_open_usages(
    tag_t                       inLine,                      /**< (I) Selected AsBuiltBOMLine */
    tag_t                       physicalPartRevision,        /**< (I) Copied Physical Part Revision */
    char***                     openUsages,                  /**< (O) List of Occurrence Name */
    int*                        count,                       /**< (O) Count of Occurrence Name */
    tag_t**                     childBOMLine                 /**< (O) Child AsBuiltBOMLine */
    );


/**
    ITK function to get all open usage values
*/
extern ASBUILT_API int ASBUILT_get_all_open_usages_2(
    tag_t                       parentPhysPart,              /**< (I) Parent Physical Part */
    tag_t                       physicalPartRevision,        /**< (I) Copied Physical Part Revision */
    char***                     openUsages,                  /**< (O) List of Occurrence Name */
    int*                        count,                       /**< (O) Count of Occurrence Name */
    tag_t**                     childBOMLine                 /**< (O) Child AsBuiltBOMLine */
    );

/**
    ITK function to install AsBuilt Physical Part Revision in AsBuilt Structure
*/
extern ASBUILT_API int ASBUILT_install_asbuilt_part_revision(
    tag_t                       inLine,                      /**< (I) Selected AsBuiltBOMLine on which installation happens*/
    tag_t                       physicalPartRevision,        /**< (I) Child Physical Part Revision which needs to be installed*/
    tag_t                       selectedBOMLineImpl,         /**< (I) BOMLine with a PSOccurrence - Position on which the installation happens*/
    InstallPartParams           *inParams,                   /**< (I) Dialog Input*/
    tag_t*                      asbuiltStructure,            /**< (O) Create AsBuiltStructure relation */
    tag_t*                      installedLineTag             /**< (O) Installed AsBuiltBOMLine */
    );


/**
    ITK function to install AsBuilt Physical Part Revision in AsBuilt Structure
*/
extern ASBUILT_API int ASBUILT_install_asbuilt_part_revision_2(
    tag_t                       inLine,                      /**< (I) Selected AsBuiltBOMLine on which installation happens*/
    tag_t                       inParentPhysicalPartRev,     /**< (I) Parent Physical Part Revision */
    tag_t                       physicalPartRevision,        /**< (I) Child Physical Part Revision which needs to be installed*/
    tag_t                       selectedBOMLineImpl,         /**< (I) BOMLine with a PSOccurrence - Position on which the installation happens*/
    InstallPartParams           *inParams,                   /**< (I) Dialog Input*/
    tag_t*                      asbuiltStructure,            /**< (O) Create AsBuiltStructure relation */
    tag_t*                      installedLineTag             /**< (O) Installed AsBuiltBOMLine */
    );


/**
    ITK function to create compare descriptor for BOM Compare
*/
extern ASBUILT_API int ASBUILT_create_compare_desc();

/**
    ITK function for AsBuilt BOM Compare using AbsOcc ID
*/
extern ASBUILT_API int ASBUILT_bom_compare(
    tag_t* srcLines,            /**< (I) List of lines from source window. Structures rooted by each of them will be checked. */
    int srcLineCount,           /**< (I) Number of source lines. */
    tag_t* tarLines,            /**< (I) List of lines from target widnow. Checked will be done over the structures under these lines only. */
    int tarLineCount,           /**< (I) Number of target lines. */
    int options,                /**< (I) Options of accountability check. Expected to be any combination of the following:
                                    add 1 - For source lines with "stop" marks, if to check their children.
                                    add 2 - If to check source lines at the lowest level only, as opposed to at all levels.
                                    add 4 - If to search all contextes in target, as opposed to the current active context.
                                    add 8 - If to search by absolute occurrence ID's only, as opposed to strictly by absolute
                                            occurrence objects.
                                    add 16 - If to compare a pre-define list of additional properties during the check.
                                    add 32 - If to search for target lines connected via PublishLink
                                */
    tag_t assyCtxtLineTag,      /**< (I) Tag of context line */
    tag_t bomCtxtLineTag,       /**< (I) Tag of BOM Context Line */
    int* srcRetCount,           /**< (O) Number of source lines checked. */
    tag_t** srcRetTags,         /**< (OF) List of source lines checked. If not interested in this output, let *srcRetCount = -1 before calling. */
    int* matRetCount,           /**< (O) Number of matched target lines */
    tag_t** matRetTags          /**< (OF) List of matched target lines. If not interested in this output, let *matRetCount = -1 before calling.*/
    );

/**
    ITK function for AsBuilt BOM Compare
*/
extern ASBUILT_API int ASBUILT_bom_compare_no_context(
    tag_t       srcLine,            /**< (I)  Tag of Source Line */
    tag_t       tarLine,            /**< (I)  Tag of Target Line */
    const char  *mode_name,         /**< (I)  BOM Comapre Mode */
    int         output_to,          /**< (I)  Output to */
    int         *srcRetCount,       /**< (O)  Number of source lines checked. */
    tag_t       **srcRetTags,       /**< (OF) List of source lines checked.  */
    int         *matRetCount,       /**< (O)  Number of matched target lines */
    tag_t       **matRetTags,       /**< (OF) List of matched target lines. */
    int         *reportLength,      /**< (O)  Number of report lines*/
    char        ***report_lines     /**< (O)  Report lines */
    );

/**
    ITK function to create missing part AsBuilt structure
*/
extern ASBUILT_API int ASBUILT_create_missing_part_structure(
    tag_t selectedLineTag,     /**< (I) Tag of selected AsBuilt BOM Line */
    tag_t * replacedLineTag    /**< (I) Tag of replaced AsBuilt BOM Line */
    );

/**
    ITK function to replace Physical Part in an AsBuilt structure
*/
extern ASBUILT_API int ASBUILT_replace_physical_part(
    tag_t                     selectedAsbuiltBOMLline,    /**< (I) Selected AsBuiltBOMLine on which replace happens*/
    tag_t                     copiedPhysPartRevision,     /**< (I) Copied Physical Part Revision */
    InstallPartParams         *params,                    /**< (I) Dialog Input*/
    tag_t                     *replacerAsbuiltBOMLine     /**< (O) Replaced AsBuiltBOMLine */
    );

/**
    ITK function to revise As-Built Physical Part Revision
*/
extern ASBUILT_API int ASBUILT_build_physical_part_revision(
    tag_t   old_physical_part_revision,       /**< (I) Tag of Physical Part Revision to be revised */
    date_t  effective_from_date,              /**< (I) Effective From Date of new Revision */
    tag_t*  new_physical_part_revision        /**< (O) Tag of new Physical Element Revision */
    );

/**
    Structure used search installable physical part revisions.
    This structure will be used to store all valid preferred,
    alternate, substitute and deviated physical part revision
    and each valid count.
*/
typedef struct ASBUILT_API SearchInstallableAsbPhysPartParams
{
    int                        preferredCount;                 /**< Number of preferred installable physical part revision objects.*/
    tag_t*                     prefPhysPartRevs;               /**< List of preferred installable physical part revision objects.*/
    int                        alternateCount;                 /**< Number of alternate installable physical part revision objects. */
    tag_t*                     altPhysPartRevs;                /**< List of alternate installable physical part revision objects.*/
    int                        substituteCount;                /**< Number of substitute installable physical part revision objects. */
    tag_t*                     subPhysPartRevs;                /**< List of substitute installable physical part revision objects.*/
    int                        deviatedCount;                  /**< Number of deviated installable physical part revision objects. */
    tag_t*                     devPhysPartRevs;                /**< List of deviated installable physical part revision objects.*/
}SearchInstallableAsbPhysPartParams;


/**
    ITK function to search installable physical part revisions
*/
extern ASBUILT_API int ASBUILT_search_installable_physical_part_revisions(
    tag_t                                   selParentPhysBOMLine,               /**< (I) Selected parent  physical BOM line. */
    tag_t                                   selectedBOMLineImpl,                /**< (I) UsageBOMLine - PSOccurrence - Position on which the installation happens. */
    int                                     attrCount,                          /**< (I) Total number of attributes on which search will be performed. */
    char**                                  attributeNames,                     /**< (I) Attribute names for which search will be performed. */
    char**                                  attributeValues,                    /**< (I) Attribute values for which search will be performed. */
    SearchInstallableAsbPhysPartParams*     outParams                           /**< (O) Output structure with all preferred/deviated/substiture/ alternamte physical part revision and respective count. */
);

/**
    ITK function to rebuild AsBuilt Structure
*/
extern ASBUILT_API int ASBUILT_rebuild_asbuilt_structure(
    tag_t   inLine,                      /**< (I) Selected BOM line for rebuild */
    date_t  rebuildDate,                 /**< (I) Rebuild date for asbuilt structure */
    tag_t*  newPhysPartRev               /**< (O) Created AsBuilt Physical Part Revision */
    );

/**
    Converts UIDs into the matching BOM Lines.

    @note If any error has occurred, a #NULLTAG value will be provided for the matching offending UIDs.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#ASBUILT_invalid_uid if any input UID is invalid.
    <li>Possibly other errors
    </ul>
*/
extern ASBUILT_API int ASBUILT_convert_uids_into_bom_lines(
    int count,                          /**< (I) Number of UIDs. */
    const char** bom_line_uids,         /**< (I) BOM Line UIDs */
    tag_t** bom_lines                   /**< (OF) count The BOM Lines deducted from the provided UIDs.
                                        <br/>If an invalid UID is passed, the matching tag will be #NULLTAG. */
);

/**
    Generates a recipe for an ASBUILT BOM Line.
    <br>A recipe provides the properties required to make a Permanent ID for a runtime object unique.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if the BOM Line tag is invalid.
    <li>Possibly other errors
    </ul>
*/
extern ASBUILT_API int ASBUILT_generate_recipe(
    tag_t asbuilt_bom_line,                   /**< (I) Input ASBUILT BOM Line. */
    char** recipe                             /**< (OF) Recipe for input BOM Line. */
);

/**
    Converts UIDs into the matching BOM Lines with the untraced parts visibility on or off.

    @note If any error has occurred for an entry, a #NULLTAG value is provided for the matching offending UIDs and the other entries are processed.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#POM_invalid_tag if any input UID is invalid.
    <li>Possibly other errors
    </ul>
*/
extern ASBUILT_API int ASBUILT_convert_uids_into_bom_lines_with_flag(
    int count,                          /**< (I) Number of UIDs. */
    const char** bom_line_uids,         /**< (I) BOM Line UIDs */
    logical show_untraced_parts,        /**< (I) Untraced Parts Visibility*/
    tag_t** bom_lines                   /**< (OF) count The BOM Lines deducted from the provided UIDs.
                                        <br/>If a invalid UID is passed, the matching tag will be #NULLTAG. */
);

/** @} */

#ifdef __cplusplus
    }
#endif

#include <asbuilt/libasbuilt_undef.h>

#endif
