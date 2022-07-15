/*==============================================================================
//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2008.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software
 ==============================================================================*/

/**
    @file

    This header file declares all data types and constants to be used by clients of
    AsMaintained module.
*/

#ifndef ASMAINTAINED_H
#define ASMAINTAINED_H

#include <mrocore/mrocore.h>

#include <asmaintained/libasmaintained_exports.h>


/**
    @defgroup ASMAINTAINED As-Maintained
    @ingroup TC
    The As-Maintained (AsMaintained) module implements the As-Maintained Structure management behaviour.

    @{
*/

/** Structure containing query information */
typedef struct ASMAINTAINED_API ASMAINTAINED_saved_queries_info_s {

    tag_t pom_query;       /**< POM query object */
    char * name;           /**< Query name */
    char * desc;           /**< Query description */
} ASMAINTAINED_saved_queries_info_t;

/**
    This structure is used to pass on the parameters for Generate Physical Structure action.
*/
typedef struct ASMAINTAINED_API GenerateAsmStructureParams
{
    char*       partNumber;         /**< Item Id of Neutral Part */
    char*       serialNumber;       /**< Serial Number */
    char*       lotNumber;          /**< Lot Number */
    char*       manufacturerId;     /**< Manufacturer Id */
    char*       structureContext;   /**< Structure Context Name */
    char*       locationName;       /**< Location Name */
    char*       dispositionType;    /**< Disposition Type */
    date_t      installationDate;   /**< Installation Date of Physical Part */
    date_t      manufactureDate;    /**< Manufacturer Date of Physical Part */
    date_t      effectiveFromDate;  /**< Effective From Date */
    date_t      effectiveToDate;    /**< Effective To Date */
    logical     useSrlNoGen;        /**< Use Serial Number Generator flag */
    int         numberOfLevels;     /**< Number of Levels for Structure Generation */
    double      physicalQuantity;   /**< Physical Part Quantity */
}GenerateAsmStructureParams;

/**
    This structure is used to pass on thInstallAsmPhysPartParamse parameters for Install AsMaintained Physical Part
*/
typedef struct ASMAINTAINED_API InstallAsmPhysPartParams
{
    char*   usagePropertyValue;     /**< Usage Name */
    date_t  installationDate;       /**< Installtion Date of Physical Part */
}InstallAsmPhysPartParams;

/**
    This structure is used to pass on the parameters for Un-Install AsMaintained Physical Part
*/
typedef struct ASMAINTAINED_API ASMAINTAINED_uninstall_params_s
{
    char*   dispositionName;            /**< Disposition Value */
    char*   locationName;               /**< Location Name */
    date_t  unInstallDate;              /**< Un-Installtion Date of Physical Part */
}ASMAINTAINED_uninstall_params_s;

/**
    Structure used as a output of ASMAINTAINED_get_children API
*/
typedef struct ASMAINTAINED_physical_children_s
{
    tag_t     childPhysPart;          /**< Child Physical Part*/
    tag_t     childPhysPartRev;       /**< Child Physical Part Revisions */
    tag_t     asmStrucRelation;       /**< As-Maintained Structure Relation */
} ASMAINTAINED_physical_children_t;

/**
    Structure used search installable physical part revisions.
    <br/>This structure will be used to store all valid preferred,
    alternate, substitute and deviated physical part revision
    and each valid count.
*/
typedef struct ASMAINTAINED_API SearchInstallableAsmPhysPartParams
{
    int                        preferredCount;                 /**< (O)  Number of preferred installable physical part revision objects.*/
    tag_t*                     prefPhysPartRevs;               /**< (OF) List of preferred installable physical part revision objects.*/
    int                        alternateCount;                 /**< (O)  Number of alternate installable physical part revision objects. */
    tag_t*                     altPhysPartRevs;                /**< (OF) List of alternate installable physical part revision objects.*/
    int                        substituteCount;                /**< (O)  Number of substitute installable physical part revision objects. */
    tag_t*                     subPhysPartRevs;                /**< (OF) List of substitute installable physical part revision objects.*/
    int                        deviatedCount;                  /**< (O)  Number of deviated installable physical part revision objects. */
    tag_t*                     devPhysPartRevs;                /**< (OF) List of deviated installable physical part revision objects.*/
}SearchInstallableAsmPhysPartParams;

#ifdef __cplusplus
    extern "C"{
#endif

/**
    ITK function to set top AsMaintained BOM Line in MRO BOM Window
*/
extern ASMAINTAINED_API int ASMAINTAINED_line_set_window_top(
    tag_t          window,                 /**< (I) Tag of MRO BOM Window */
    tag_t          physicalPart,           /**< (I) Tag of Physical Part */
    tag_t          physicalPartRev,        /**< (I) Tag of Physical Part Revision */
    tag_t*         topBOMLine              /**< (O) Tag of top BOM Line */
    );

/**
    ITK function to get Child Lines for selected Physical BOM Line
*/
extern ASMAINTAINED_API int ASMAINTAINED_line_ask_all_child_lines(
    tag_t          bom_line,           /**< (I) Tag of BOM Line */
    int*           count,              /**< (O) Count */
    tag_t**        children            /**< (OF) Tags of Child BOM Lines */
    );

/**
    ITK function to generate AsMaintained Structure
*/
extern ASMAINTAINED_API int ASMAINTAINED_gen_phystruc(
    tag_t                       inLine,       /**< (I) Neutral BOM line */
    GenerateAsmStructureParams* inParam,      /**< (I) Generate Asm Structure Params */
    tag_t*                      phys_rev      /**< (O) Created Physical Part Revision */
    );

/**
    ITK function to create compare descriptor for BOM Compare
*/
extern ASMAINTAINED_API int ASMAINTAINED_create_compare_desc();

/**
    ITK function for AsMaintained BOM Compare using AbsOcc ID
*/
extern ASMAINTAINED_API int ASMAINTAINED_bom_compare(
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
    ITK function for AsMaintained BOM Compare using BOM Compare Engine
*/
extern ASMAINTAINED_API int ASMAINTAINED_bom_compare_no_context(
    tag_t       srcLine,            /**< (I)  Tag of Source Line */
    tag_t       tarLine,            /**< (I)  Tag of Target Line */
    const char  *mode_name,         /**< (I)  BOM Comapre Mode */
    int         output_to,          /**< (I)  Output to */
    int         * srcRetCount,       /**< (O)  Number of source lines checked. */
    tag_t       ** srcRetTags,       /**< (OF) List of source lines checked.  */
    int         * matRetCount,       /**< (O)  Number of matched target lines */
    tag_t       ** matRetTags,       /**< (OF) List of matched target lines. */
    int         * reportLength,      /**< (O)  Number of report lines */
    char        *** report_lines     /**< (OF) Report lines */
    );

/**
    ITK function for AsMaintained Get All Open usage
    First parameter is AsMaintainedBOMLine
*/
extern ASMAINTAINED_API int ASMAINTAINED_get_all_open_usage(
    tag_t       inLine,                 /**< (I)  Selected AsMaintained Line */
    tag_t       childPhysicalPart,      /**< (I)  Copied Physical Part */
    char***     openUsages,             /**< (OF) List of Usage Name */
    int*        count,                  /**< (O)  Count of Usage Name. */
    tag_t**     childBOMLine            /**< (OF) Child NeutralBOMLine */
    );


/**
    ITK function for AsMaintained Get All Open usage
    First parameter is Physical Part Revision
*/
extern ASMAINTAINED_API int ASMAINTAINED_get_all_open_usage_2(
    tag_t       parentPhysicalPartRevision,     /**< (I)  Parent Physical Part Revision */
    tag_t       childPhysicalPart,              /**< (I)  Copied Physical Part */
    char***     openUsages,                     /**< (OF) List of Usage Name */
    int*        count,                          /**< (O)  Count of Usage Name. */
    tag_t**     childBOMLine                    /**< (OF) Child NeutralBOMLine */
    );

/**
    ITK function to install Physical Part in AsMaintained Structure
*/
extern ASMAINTAINED_API int ASMAINTAINED_install_physical_part(
    tag_t                           selectedAsMaintainedLine,       /**< (I) Selected AsMaintainedBOMLine on which installation happens */
    tag_t                           copiedPhysicalPart,             /**< (I) Child Physical Part which needs to be installed*/
    tag_t                           usageBOMLineImpl,               /**< (I) BOMLine with a PSOccurrence - Position on which the installation happens */
    InstallAsmPhysPartParams*       inParams,                       /**< (I) Dialog Input */
    tag_t*                          asMaintainedStructure,          /**< (O) Create AsMaintainedStructure relation */
    tag_t*                          installedLineTag                /**< (O) Installed AsMaintainedBOMLine */
    );

/**
    ITK function to un-install Physical Part in AsMaintained Structure
*/
extern ASMAINTAINED_API int ASMAINTAINED_uninstall_physical_part(
    tag_t                                   selectedAsMaintainedLine,       /**< (I) Selected AsMaintainedBOMLine which is uninstalled */
    ASMAINTAINED_uninstall_params_s*        inParams,                       /**< (I) Dialog Input */
    tag_t*                                  replacerLine                    /**< (O) Installed AsMaintainedBOMLine (missing asmaintained bom line) */
    );

/**
    ITK function to set top Physical Location BOM Line in MRO BOM Window
*/
extern ASMAINTAINED_API int ASMAINTAINED_physlocationline_set_window_top(
    tag_t          window,                 /**< (I) Tag of MRO BOM Window */
    tag_t          physicalLocation,       /**< (I) Tag of Physical Location */
    tag_t*         topBOMLine              /**< (O) Tag of top BOM Line */
    );

/**
    ITK function to get effective Physical Part Revision by effective date
*/
extern ASMAINTAINED_API int ASMAINTAINED_get_effective_physical_part_revision(
    tag_t   physPart,                /**< (I) Physical Part */
    date_t  effectiveDate,           /**< (I) Date Time (NULL implies Today) */
    tag_t*  physPartRev              /**< (O) Effective Physical Part Revision */
    );

/**
    ITK function to create MRO BOM Window
*/
extern ASMAINTAINED_API int ASMAINTAINED_create_window(
    tag_t*   window                  /**< (O) Tag of MRO BOM Window */
    );

/**
    ITK function to get child Physical Parts in As-Mainatained Structure
*/
extern ASMAINTAINED_API int ASMAINTAINED_get_children(
    tag_t                               physPart,       /**< (I)  Physical Part or Physical Part Revision */
    date_t                              effectiveDate,  /**< (I)  Date Time (NULL allowed implies Today) */
    ASMAINTAINED_physical_children_t**  children,       /**< (OF) List of Physical Part Revisions and
                                                                  As-Maintained Relations */
    int*                                childCount      /**   (O) Count of effective children and
                                                                  As-Maintained Relations */
    );

/**
    ITK function to apply Revision Rule
*/
extern ASMAINTAINED_API int ASMAINTAINED_apply_revision_rule(
    tag_t    topLine,                      /**< (I) As-Maintained BOM Line */
    tag_t    mroRevRule,                   /**< (I) MRO Revision Rule */
    tag_t*   configuredTopLine             /**< (O) Configured As-Maintained BOM Line */
    );

/**
    ITK function to get the immediate Physical Part parent in As-Maintained Structure
*/
extern ASMAINTAINED_API int ASMAINTAINED_get_physical_part_parent(
    tag_t   physPart,           /**< (I) Physical Part or Physical Part Revision */
    date_t  effectiveDate,      /**< (I) Date Time (NULL allowed) */
    tag_t*  parentPhysPartRev,  /**< (O) Parent Physical Part Revision */
    tag_t*  asmStrucRel         /**< (O) As-Maintained Structure Relation */
    );

/**
    ITK function to get the Root Physical Part parent in As-Maintained Structure
*/
extern ASMAINTAINED_API int ASMAINTAINED_get_root_physical_part(
    tag_t   physPart,           /**< (I) Physical Part or Physical Part Revision */
    date_t  effectiveDate,      /**< (I) Date Time (NULL allowed) */
    tag_t*  rootPhysPartRev     /**< (O) Root Physical Part Revision */
    );

/**
    ITK function to revise As-Maintained Physical Part Revision
*/
extern ASMAINTAINED_API int ASMAINTAINED_maintain_physical_part_revision(
    tag_t   oldPhysPartRevTag,          /**< (I) Tag of Physical Part Revision to be revised */
    date_t  effectiveFromDate,          /**< (I) Effective From Date of new Revision */
    tag_t*  outPhysPartRevTag           /**< (O) Tag of new Physical Element Revision */
    );
/**
    ITK function to replace Physical Part in AsMaintained Structure
*/
extern ASMAINTAINED_API int ASMAINTAINED_replace_physical_part(
    tag_t                            selectedAsMaintainedLine,       /**< (I) Selected AsMaintainedBOMLine on which installation happens */
    tag_t                            copiedPhysicalPart,             /**< (I) Child Physical Part which needs to be installed */
    ASMAINTAINED_uninstall_params_s  * inParams,                       /**< (I) Dialog Input */
    tag_t*                           asMaintainedStructure,          /**< (O) Create AsMaintainedStructure relation */
    tag_t*                           replacedLineTag                 /**< (O) Replaced AsMaintainedBOMLine */
    );

/**
    ITK function to change the physical part disposition state
*/
extern ASMAINTAINED_API int ASMAINTAINED_change_physical_part_disposition(
    tag_t   physPart,            /**< (I) Physical Part or Physical Part Revision */
    tag_t   disposition,         /**< (I) new disposition */
    date_t  dispStartDate,       /**< (I) start date for new disposition */
    tag_t*  dispRelation         /**< (O) relation */
    );

/**
    ITK function to change Physical Part location
*/
extern ASMAINTAINED_API int ASMAINTAINED_move_physical_part(
    tag_t physPart,             /**< (I) Physical Part or Physical Part Revision */
    tag_t location,             /**< (I) location */
    date_t inTime,              /**< (I) Date to move */
    tag_t *relation             /**< (O) relation */
    );

/**
    ITK function to search installable physical part revisions
*/
extern ASMAINTAINED_API int ASMAINTAINED_search_installable_physical_part_revisions(
    tag_t                               selParentPhysBOMLine,           /**< (I) Selected parent  physical BOM line. */
    tag_t                               selectedBOMLineImpl,            /**< (I) BOMLine with a PSOccurrence - Position on which the installation/replace happens. */
    int                                 attrCount,                      /**< (I) Total number of attributes on which search will be performed. */
    char**                              attributeNames,                 /**< (I) Attribute names for which search will be performed. */
    char**                              attributeValues,                /**< (I) Attribute values for which search will be performed. */
    SearchInstallableAsmPhysPartParams* outParams                       /**< (O) Output structure with all preferred/deviated/substiture/ alternamte physical part revision and respective count. */
);

/**
    Finds the current location of given physical part revision
    @returns
        <ul>
            <li>#ITK_ok on success
            <li>#POM_invalid_tag if the parameter @p physical_part_revision is not a valid Physical Part Revision.
        </ul>
*/
extern ASMAINTAINED_API int ASMAINTAINED_get_current_physical_part_location(
    tag_t physical_part_revision,           /**< (I) tag of the Physical Part Revision. */
    tag_t* location,                        /**< (O) Output current location of the physical part revision */
    tag_t* relation                         /**< (O) Output relation of the the physical part revision with the location. */
);

/**
    Finds the current disposition of given physical part revision
    @returns
        <ul>
            <li>#ITK_ok on success
            <li>#POM_invalid_tag if the parameter @p physical_part_revision is not a valid Physical Part Revision.
        </ul>
*/
extern ASMAINTAINED_API int ASMAINTAINED_get_current_physical_part_disposition(
    tag_t physical_part_revision,         /**< (I) tag of the Physical Part Revision. */
    tag_t* disposition,                   /**< (O) Output current disposition of the physical part revision */
    tag_t* relation                       /**< (O) Output relation of the the physical part revision with the disposition. */
);

/**
    Converts UIDs into the matching AsMaintained BOM Lines.

    @note If any error has occurred, a #NULLTAG value will be provided for the matching offending UIDs.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#POM_invalid_tag if any input UID is invalid.
    <li>Possibly other errors
    </ul>
*/
extern ASMAINTAINED_API int ASMAINTAINED_convert_uids_into_bom_lines(
    int count,                          /**< (I) Number of UIDs. */
    const char** bom_line_uids,         /**< (I) BOM Line UIDs */
    tag_t** bom_lines                   /**< (OF) count The BOM Lines deducted from the provided UIDs.
                                        <br/>If a invalid UID is passed, the matching tag will be #NULLTAG. */
);

/**
    Generates a recipe for an ASMAINTAINED BOM Line.
    <br>A recipe provides the properties required to make a Permanent ID for a runtime object unique.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#ASMAINTAINED_invalid_uid if the BOM Line tag is invalid.
    <li>Possibly other errors
    </ul>
*/
extern ASMAINTAINED_API int ASMAINTAINED_generate_recipe(
    tag_t asmaintained_bom_line,                   /**< (I) Input ASMAINTAINED BOM Line. */
    char** recipe                                  /**< (OF) Recipe for input BOM Line. */
);

/**
    Retrieves the saved queries for location and disposition.

    @code
    int num_queries = 0;
    ASMAINTAINED_saved_queries_info_t** queries = 0;
    if( ITK_ok == ASMAINTAINED_get_saved_queries_info( &num_queries, &queries ))
    {
        [...]
        for(int index=0; index<num_queries; ++index)
        {
            MEM_free(queries[index]->name);
            MEM_free(queries[index]->desc);
            MEM_free(queries[index]);
        }
        SM_free(queries);
    }
    @endcode

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>Possibly any POM error or other errors
    </ul>
*/
extern ASMAINTAINED_API int ASMAINTAINED_get_saved_queries_info(
    int *num_queries,                              /**< (O) Number of queries retrieved  */
    ASMAINTAINED_saved_queries_info_t*** queries   /**< (OF) num_queries The saved queries.<br/>The memory needs to be deallocated in the same fashion as in the code sample above.  */
);

/**
    Retrieves the neutral part children list from a Neutral BOM Line.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>Possibly other errors
    </ul>
*/
extern ASMAINTAINED_API int ASMAINTAINED_get_neutral_part_children_list(
    tag_t    neutral_bom_line,         /**< (I) Neutral part BOM Line */
    int*     count_lines,              /**< (O) Number of child Neutral BOM Lines */
    tag_t**  child_bom_lines,          /**< (OF) count_lines Child Neutral BOM Lines */
    tag_t**  occurrence_tags           /**< (OF) count_lines Child Neutral occurrence BOM Lines */
);

/**
    Retrieves the physical part children list from a Physical BOM Line

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>Possibly other errors
    </ul>
*/
extern ASMAINTAINED_API int ASMAINTAINED_get_physical_part_children_list(
    tag_t   physical_bom_line,         /**< (I) Physical part BOM Line */
    int*    count_lines,               /**< (O) Number of child Physical BOM Lines*/
    tag_t** child_bom_lines,           /**< (OF) count_lines Child Physical BOM Lines */
    tag_t** occurrence_tags            /**< (OF) count_lines Child Physical occurrence BOM Lines */
);

/**
    Retrieves the display names for the properties "plbl_location_name"  and "dispositionValue".

    @returns #ITK_ok always
*/
extern ASMAINTAINED_API int ASMAINTAINED_get_locale_location_and_disposition(
   char**  location_prop_name,        /**< (OF) Location name */
   char**  disposition_prop_name      /**< (OF) Disposition name */
);

/**
      Performs validations required for replace action.
      @returns
      <ul>
      <li>#ITK_ok on success
      <li>#POM_invalid_tag if parent_physical_part_item or parent_physical_part_item_revision or selected_asmaintained_bom_line is a NULLTAG
      <li>#MROCORE_installation_date_error if installation_date is NULLDATE or invalid.      
      </ul>
*/
extern ASMAINTAINED_API int ASMAINTAINED_validation_for_replace(
   tag_t parent_physical_part_item,            /**< (I) Tag of Parent Physical Part*/ 
   tag_t parent_physical_part_item_revision,   /**< (I) Tag of Parent Physical Part Revision*/
   tag_t copied_physical_item_rev,             /**< (I) Tag of Physical Part Revision that will be used to replace. If this is NULLTAG, part will be considered as a new part.*/
   tag_t selected_asmaintained_bom_line,       /**< (I) Tag of AsMaintained bomline that will get replaced*/
   date_t installation_date,                   /**< (I) Installation date for the part used to replace. Cannot be NULLDATE.*/
   date_t validation_manf_date                 /**< (I) Manufacturing date of the new part. Should be given as an input if copied_physical_item_rev is NULLTAG. Can be NULLDATE otherwise*/ 
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
extern ASMAINTAINED_API int ASMAINTAINED_convert_uids_into_bom_lines_with_flag(
    int count,                          /**< (I) Number of UIDs. */
    const char** bom_line_uids,         /**< (I) BOM Line UIDs */
    logical show_untraced_parts,        /**< (I) Untraced Parts Visibility*/
    tag_t** bom_lines                   /**< (OF) count The BOM Lines deducted from the provided UIDs.
                                        <br/>If a invalid UID is passed, the matching tag will be #NULLTAG. */
);

#ifdef __cplusplus
    }
#endif


/** @} */
#include <asmaintained/libasmaintained_undef.h>

#endif
