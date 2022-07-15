/* 
 Copyright 2020 Siemens Digital Industries Software
 ==================================================
 Copyright 2017
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file cbaext.h

    The CBAEXT module presents a high level interface to a remote Teamcenter 
    Product Master Management system.  It supports basic services for alignment and
    publish of PMM objects like Part, Line of Usage and Line of Assembly.
*/


#ifndef CBAEXT_H_INCLUDED
#define CBAEXT_H_INCLUDED

#include <cba/pmm.h>
#include <cba1cbaext/libcbaext_exports.h>


/**
    @defgroup CBAEXT CBAEXT

    This module provides implementation for all the ITKs to be used by the customers of CAD BOM Alignment.

    To use these ITK functions, include the cbaext.h file in the source code.
    @{
*/

#ifdef __cplusplus
    extern "C" {
#endif

/**
    Contains an Item Revision and a Part that are to be aligned or unaligned. This structure 
    is passed as input to #CBAEXT_align_item_revisions_and_parts and #CBAEXT_unalign_item_revisions_and_parts.
*/
typedef struct  CBAEXT_item_revision_part_info_s
{
    tag_t                    item_revision;     /**< Item Revision tag */
    tag_t                    part;              /**< Part tag */
    int                      client_id;         /**< A unique identifier that is used to identify the input records that fail */
} CBAEXT_item_revision_part_info_t;

/**
    Contains an Item Revision and a client ID that is used to identify the Item Revisions that fail the operation.
    This structure is passed as input to #CBAEXT_publish_item_revisions and #CBAEXT_find_solutions_linked_to_design_occurrences.
*/
typedef struct CBAEXT_item_revision_info_s
{
    tag_t            item_revision;         /**< Item Revision tag */
    int              client_id;             /**< A unique identifier that is used to identify the input records that fail */  
} CBAEXT_item_revision_info_t;

/**
    Contains a BOMLine and a client ID that is used to identify the BOMLines that fail the operation.
    This structure is passed as input to #CBAEXT_publish_cad_occurrences and #CBAEXT_find_solutions_linked_to_design_occurrences.
*/
typedef struct CBAEXT_cad_occurrence_info_s
{
    tag_t            bomline;           /**< A unique identifier that is used to identify the input records that fail */
    int              client_id;         /**< A unique identifier that is used to identify the input records that fail */
} CBAEXT_cad_occurrence_info_t;

/**
   Contains a set of aligned Assembly Component Tree Lines.
   This structure is returned by #CBAEXT_find_aligned_act_lines_for_designs_with_stream.
*/
typedef struct CBAEXT_set_of_aligned_act_lines_s 
{     
    int n_actlines;       /**< Number of Assembly Component Tree Lines */
    tag_t* actlines;      /**< List of Assembly Component Tree Lines that are aligned to a single BOM Line */
} CBAEXT_set_of_aligned_act_lines_t;

 /** 
   The structure contains an Assembly Component Tree Line and the BOMLine that is aligned to it.
   This structure is returned by #CBAEXT_find_bomlines_for_act_lines.
*/
typedef struct CBAEXT_act_line_to_bomline_s
{
    tag_t actline;    /**< Aligned Assembly Component Tree Lines */
    tag_t bomline;    /**< Aligned BOMLine */
} CBAEXT_act_line_to_bomline_t;

/** 
   Contains a Part and the Item Revision tags that are aligned to this Part.
   This structure is returned by #CBAEXT_find_item_revisions_linked_to_parts and #CBAEXT_find_drawing_revisions_linked_to_parts.
*/
typedef struct CBAEXT_item_revision_primary_publish_info_s
{
    tag_t     design;                  /**< Item revision tag */
    logical   primary_flag;            /**< Primary indicator */
    logical   publish_flag;            /**< Published indicator */
} CBAEXT_item_revision_primary_publish_info_t;


/** 
   Contains a Part and the Item Revision tags that are aligned to this Part.
   This structure is returned by #CBAEXT_find_item_revisions_linked_to_parts and #CBAEXT_find_drawing_revisions_linked_to_parts.
*/
typedef struct CBAEXT_item_revision_to_part_info_s
{
    tag_t                                         part;                 /**< Part tag */
    int                                           n_item_revisions;     /**< Number of Item Revision Tags */
    CBAEXT_item_revision_primary_publish_info_t*  item_revisions;       /**< List of Item Revision tags */
} CBAEXT_item_revision_to_part_info_t;

/** 
   Contains an Item Revision and the Part tags that are aligned to this Item Revision.
   This structure is returned by #CBAEXT_find_parts_linked_to_item_revisions and #CBAEXT_find_parts_linked_to_drawing_revisions.
*/
typedef struct CBAEXT_part_to_item_revision_info_s
{
    tag_t   item;                       /**< Item Revision tag */
    int     n_part_revisions;           /**< Number of Part tags */
    tag_t*  part_revisions;             /**< List of Part tags */
} CBAEXT_part_to_item_revision_info_t;

/** 
   Encapsulates the data that defines a Solution. This structure is used to pass in 
   the input for #CBAEXT_find_design_occurrences_linked_to_solutions.
*/
typedef struct CBAEXT_solution_information_s
{
    tag_t solution;              /**< Solution tag */
    int   client_id;             /**< A unique identifier that is used to identify the input records that fail */
} CBAEXT_solution_information_t;

/** 
   Encapsulates the data for a Solution and a BOMLine. This structure is returned by
   #CBAEXT_find_design_occurrences_linked_to_solutions and #CBAEXT_find_solutions_linked_to_design_occurrences.
*/
typedef struct CBAEXT_design_occurrence_solution_info_s
{     
    tag_t bomLine;              /**< BOMLine tag */
    tag_t solution;             /**< Solution tag */
    int   client_id;            /**< A unique identifier that is used to identify the input records that fail */
} CBAEXT_design_occurrence_solution_info_t;

 /**
   Contains the Name-value pair for property  
*/
typedef struct CBAEXT_related_object_info_s
{
    char *table_name;                         /**< Table name for related object */
    char *action;                             /**< Action name to be performed */
    char *related_object_tuid;                /**< TUID for related object */
    int  n_attributes;                        /**< Number of attributes. */
    char **related_object_attributes;         /**< n_attributes Attributes names for Related Object */
    char **related_object_attribute_values;   /**< n_attributes Attributes values for Related Object */
}CBAEXT_related_object_info_t;

/** 
   Encapsulates the data for a Solution and a BOMLine.
*/
typedef struct CBAEXT_cad_occurrence_solution_information_s 
{     
    tag_t                               bomline;                /**< BOMLine tag */
    tag_t                               solution;               /**< Solution tag */
    int                                 n_attributes;           /**< Number of attributes. */
    char**                              solution_attr;          /**< n_attributes Attributes names for Solution */
    char**                              solution_attr_values;   /**< n_attributes Attributes values for Solution */
    int                                 n_related_objects;      /**< Number of related objects. */
    CBAEXT_related_object_info_t*       related_objects;        /**< n_related_objects Relational object information. */
    char *                              client_id;              /**< A unique identifier that is used to identify the input records that fail */
} CBAEXT_cad_occurrence_solution_infomation_t;

/**
    Contains a Item Revision and a client ID that is used to identify the Item Revision that fail the operation.
*/
typedef struct CBAEXT_design_info_s
{
    tag_t            item_revision;         /**< Item Revision tag */
    char *           client_id;             /**< A unique identifier that is used to identify the input records that fail */
} CBAEXT_design_info_t;

/** 
   Contains a Part and the Item Revision tags that are aligned to this Part.
*/
typedef struct CBAEXT_design_to_part_information_s
{
    tag_t                               part;                   /**< Part tag to align*/
    int                                 n_item_revisions;       /**< Number of Item Revision Tags to align with Part */
    CBAEXT_design_info_t*               design_info;            /**< n_item_revisions List of Item Revision tags and ClientIDs */
    int                                 n_attributes;           /**< Number of attributes for mofification. */
    char**                              part_attr;              /**< n_attributes Attributes names for Part to be modified */
    char**                              part_attr_values;       /**< n_attributes Attributes values for for Part to be modified */
    int                                 n_related_objects;      /**< Number of related objects to process with alignment/unalignment. */
    CBAEXT_related_object_info_t*       related_objects;        /**< n_related_objects Relational object information. */
} CBAEXT_design_to_part_information_t;


/**
    Contains a Part for which the primary representation needs to be found. This structure 
    is passed as input to #CBAEXT_ask_primary_representations.
*/
typedef struct CBAEXT_part_info_s
{
    tag_t                    part;          /**< Part tag */
    int                      client_id;     /**< A unique identifier that is used to identify the input records that fail. 
                                                <br>The client_id is populated in the error map returned by #CBAEXT_ask_primary_representations and helps 
                                                to correlate the error and the input. */
} CBAEXT_part_info_t;

/** 
   Encapsulates the data for a Solution and an ACTLine. This structure is passed as input to
   #CBAEXT_link_set_of_design_occ_and_act_line and #CBAEXT_unalign_set_of_design_occ_and_act_line
*/
typedef struct CBAEXT_design_occurrence_act_line_info_s
{     
    tag_t bom_line;             /**< BOMLine tag */
    tag_t act_line;             /**< ACTLine tag */
    int   client_id;            /**< A unique identifier that is used to identify the input records that fail */
} CBAEXT_design_occurrence_act_line_info_t;

/**
    @name CBAEXT Setup Functions
    @{
*/

/**
    Initializes the CBAEXT module.
    This function must be called before using any other CBAEXT module functions.
    This function will be called by the standard ITK startup code.
    The ITK programmer can ignore this function.

    @note A second call is ignored.
*/
extern CBAEXT_API int CBAEXT_init_module( void );

/** @} CBAEXT Setup Functions */

/**
    @name CBAEXT Utility Functions
    @{
*/

/**
    Indicates if the CAD BOM Alignment (CBA) module is configured to work with the Product Master Management (PMM) server.
*/
extern CBAEXT_API int CBAEXT_is_cba_enabled(
    logical         *is_enabled         /**< (O) True if the CBA module is configured to work with the PMM server */
    );

/** @} CBAEXT Utility Functions */

/**
    @name CBAEXT Alignment Functions
    @{
*/

/**
    Aligns CAD/Drawing Item Revisions to Parts in Usage Server. The input should be a homogeneous set of 
    CAD Revisions or Drawing Revisions. An error is returned if both CAD and Drawing Revisions are 
    passed as input during a single invocation of the method.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PMM_mismatch_of_item_rev_and_part if the input contains a mixture of Item Revisions and Drawing Revisions.
    <li>#PMM_null_consistency_stamp if the consistency stamp is not defined on the input Part.
    </ul>
*/
extern CBAEXT_API int CBAEXT_align_item_revisions_and_parts(
        const int                               n_links,                            /**< (I) Number of CAD/Drawing item revisions to align */
        const CBAEXT_item_revision_part_info_t  *alignment_info,                    /**< (I) n_links List of CAD/Drawing item revisions and PMM parts to be aligned */
        int                                     *n_errors,                          /**< (O) Number of errors in the operation */
        PMM_error_store_map_t                   **error_map                         /**< (OF) n_errors List of structures containing error details.
                                                                                                <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only. */
        );

/**
    Aligns CAD/Drawing Item Revisions to Parts in Usage Server. 
    <br/>The input should be a homogeneous set of CAD Revisions or of Drawing Revisions and Engineering Change Order information. 

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PMM_mismatch_of_item_rev_and_part if the input contains a mixture of Item Revisions and Drawing Revisions.
    <li>#PMM_invalid_input_empty_part_design_auth if any of the input is invalid.
    <li>#PMM_null_consistency_stamp if the consistency stamp is not defined on the input Part.
    </ul>
*/
extern CBAEXT_API int CBAEXT_align_item_revisions_and_parts_eco(
        const unsigned int                        n_links,                           /**< (I) Number of Parts to align.*/
        const CBAEXT_design_to_part_information_t *alignment_info,                   /**< (I) n_links List of Designs and Part to align.*/
        const char                                *eco,                              /**< (I) Engineering Change Order information for alignment.
                                                                                                <br/>Engineering Work Order(EWO) object name created in Product Master Management.*/
        const logical                             auto_commit,                       /**< (I) Auto-commit flag for alignment.*/
        int                                       *n_parts,                          /**< (O) Number of Parts retrieved after alignment.*/
        tag_t                                     **parts,                           /**< (OF) n_parts Part response after alignment.*/
        int                                       *n_errors,                         /**< (O) Number of errors in the operation. */
        PMM_error_store_map_t                     **error_map                        /**< (OF) n_errors List of structures containing error details.
                                                                                            <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only. */
        );

/**
    Unaligns CAD/Drawing Item Revisions from Parts in Usage Server. The input should be a homogeneous set of 
    CAD Revisions or Drawing Revisions. An error is returned if both CAD and Drawing Revisions are 
    passed as input during a single invocation of the method.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PMM_mismatch_of_item_rev_and_part if the input contains a mixture of Item Revisions and Drawing Revisions.
    <li>#PMM_null_consistency_stamp if the consistency stamp is not defined on the input Part.
    </ul>
*/
extern CBAEXT_API int CBAEXT_unalign_item_revisions_and_parts(
        const int                                 n_links,                          /**< (I) Number of CAD/Drawing item revisions to unalign */
        const CBAEXT_item_revision_part_info_t    *alignment_info,                  /**< (I) List of CAD/Drawing item revisions and PMM parts to be unaligned */
        int                                       *n_errors,                        /**< (O) Number of errors in the operation */
        PMM_error_store_map_t                     **error_map                       /**< (OF) n_errors List of structures containing error details.
                                                                                            <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only. */
        );

/**
    Unaligns CAD/Drawing Item Revisions from Parts in Usage Server.
    <br/>The input should be a homogeneous set of CAD Revisions or Drawing Revisions.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PMM_mismatch_of_item_rev_and_part if the input contains a mixture of Item Revisions and Drawing Revisions.
    <li>#PMM_null_consistency_stamp if the consistency stamp is not defined on the input Part.
    </ul>
*/
extern CBAEXT_API int CBAEXT_unalign_item_revisions_and_parts_eco(
        const unsigned int                          n_links,                           /**< (I)  Number of Parts to align */
        const CBAEXT_design_to_part_information_t   *alignment_info,                   /**< (I)  n_links list of Designs and Part to align */
        const char                                  *eco,                              /**< (I)  ECO information for alignment 
                                                                                                    <br/>Engineering Work Order(EWO) object name created in Product Master Management.*/                    
        const logical                               auto_commit,                       /**< (I)  Auto commit flag for alignment */
        int                                         *return_part_count,                /**< (O)  Number of Parts returned after alignment */
        tag_t                                       **return_part_tag,                 /**< (OF) Part tag response after alignment */
        int                                         *n_errors,                         /**< (O)  number of errors in the operation */
        PMM_error_store_map_t                       **error_map                        /**< (OF) n_errors List of structures containing error details.
                                                                                                <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only. */
        );

/**
    Publishes CAD/Drawing Item Revisions to Usage Server.
    The input should be a homogeneous set of CAD Revisions or Drawing Revisions.
    An error is returned if both CAD and Drawing Revisions are passed as input during a single invocation of the method.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PMM_mismatch_of_item_rev_and_part if the input contains a mixture of Item Revisions and Drawing Revisions.
    <li>#PMM_design_rev_has_no_rendering if the CAD Item Revision does not have a Rendering dataset attached to it.
    <li>#PMM_assembly_with_embedded_jt if an assembly to be published contains a JT dataset in a non-leaf node.
    <li>#PMM_drawing_rev_has_no_specification_dataset if the Drawing Revision to be published does not have a Specification dataset attached to it.
    </ul>
*/
extern CBAEXT_API int CBAEXT_publish_item_revisions(
        const int                       n_item_revs,    /**< (I) Number of CAD item revisions to publish */
        CBAEXT_item_revision_info_t     *publish_info,  /**< (I) CAD Item Revision and client Id for each record */
        int                             *n_errors,      /**< (O) Number of errors in the operation */
        PMM_error_store_map_t           **error_map     /**< (OF) n_errors List of structures containing error details.
                                                                <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only. */
        );

/**
    Sets the default CAD representations for Parts in the Usage Server. The default representation will be displayed when the Part is visualized.
    
    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PMM_design_rev_has_no_rendering if the CAD Item Revision does not have a Rendering dataset attached to it.
    <li>#PMM_null_consistency_stamp if the consistency stamp is not defined on the input Part.
    </ul>
*/
extern CBAEXT_API int CBAEXT_set_default_cad_representations_for_parts(
        const int                           n_item_revs,        /**< (I) Number of CAD item revisions */
        CBAEXT_item_revision_part_info_t    *make_primary_info, /**< (I) List of CAD item revisions and PMM parts for which the default representation is to be set */
        int                                 *n_errors,          /**< (O) Number of errors in the operation */
        PMM_error_store_map_t               **error_map         /**< (OF) n_errors List of structures containing error details.
                                                                        <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only. */ 
        );

/**
    Sets the default CAD representations for Parts in the Usage Server using eco. 
    <br/>The default representation will be displayed when the Part is visualized.
    
    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PMM_invalid_input_empty_part_design_auth If the input is invalid.
    <li>#PMM_design_rev_has_no_rendering if the CAD Item Revision does not have a Rendering dataset attached to it.
    </ul>
*/
extern CBAEXT_API int CBAEXT_set_default_cad_representations_for_parts_eco(
        const unsigned int                          n_links,                /**< (I) Number of Parts to align.*/
        const CBAEXT_design_to_part_information_t   *alignment_info,        /**< (I) n_links List of Designs and Part to align.*/
        const char                                  *eco,                   /**< (I)  Engineering Change Order information for Make Primary.
                                                                                        <br/>Engineering Work Order(EWO) object name created in Product Master Management*/
        const logical                               auto_commit,            /**< (I)  Auto-commit flag for Make Primary. */
        int                                         *n_parts,               /**< (O)  Number of Parts retrieved after Make Primary operation. */
        tag_t                                       **parts,                /**< (OF) n_parts Part response after Make Primary operation. */
        int                                         *n_errors,              /**< (O)  Number of errors in the operation. */
        PMM_error_store_map_t                       **error_map             /**< (OF) n_errors List of structures containing error details.
                                                                                    <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only. */
        );

/**
    Aligns CAD Occurrences to Solutions in Usage Server. 
    <br/>The Solution is defined by providing a Line of Usage and a Sub-usage belonging to the Line of Usage.
    <br/>A Position Designator can be optionally provided, in which case the alignment is performed with the input Position Designator. If the Position Designator
    is not explicitly provided as input, the alignment is performed with the first available Position Designator belonging to the Line of Usage.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PMM_cannot_align_a_topline if the top BOMLine from a CAD structure is selected for aligning to a Solution.
    <li>#PMM_null_consistency_stamp if the consistency stamp is not defined on the input Line of Usage.
    <li>#PMM_bomline_not_in_context_of_ia if the input BOMLine is not part of an installation assembly.
    <li>#BOM_line_null_pathnode if the Appearance Path Node could not be determined for the input BOMLine
    </ul>
*/
extern CBAEXT_API int CBAEXT_link_cad_occs_and_solutions_eco(
        const unsigned int                                  n_cad_occ,              /**< (I)  Number of CAD occurrences to align. */
        const CBAEXT_cad_occurrence_solution_infomation_t   *alignment_info,        /**< (I)  n_cad_occ CAD occurrences and Solutions to align. */
        const char                                          *eco,                   /**< (I)  Engineering Change Order information for alignment.
                                                                                                <br/>Engineering Work Order(EWO) object name created in Product Master Management.*/
        const logical                                       auto_commit,            /**< (I)  Auto commit flag for alignment. */
        int                                                 *n_solutions,           /**< (O)  Number of Solution after alignment. */
        tag_t                                               **solutions,            /**< (OF) n_solutions Solutions response after alignment */
        int                                                 *n_errors,              /**< (O)  Number of errors in the operation. */
        PMM_error_store_map_t                               **error_map             /**< (OF) n_errors structures containing error details. 
                                                                                                <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only. */
        );

/**
    Unaligns CAD Occurrences and Solutions in Usage Server. 
    <br/>The Solution is defined by providing a Line of Usage, a Sub-usage belonging to the Line of Usage 
    and a Position Designator also belonging to the Line of Usage.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PMM_null_consistency_stamp if the consistency stamp is not defined on the input Line of Usage.
    <li>#PMM_bomline_not_in_context_of_ia if the input BOMLine is not part of an installation assembly.
    <li>#BOM_line_null_pathnode if the Appearance Path Node could not be determined for the input BOMLine
    </ul>
*/
extern CBAEXT_API int CBAEXT_unlink_cad_occs_and_solutions_eco(
        const unsigned int                                  n_cad_occ,              /**< (I)  Number of CAD occurrences to unalign */
        const CBAEXT_cad_occurrence_solution_infomation_t   *alignment_info,        /**< (I)  n_cad_occ CAD occurrences and Solutions to unalign. */
        const char                                          *eco,                   /**< (I)  Engineering Change Order information for unalignment.
                                                                                                <br/>Engineering Work Order(EWO) object name created in Product Master Management.*/
        const logical                                       auto_commit,            /**< (I)  Auto commit flag for unalignment. */
        int                                                 *n_solutions,           /**< (O)  Number of solutions after unalignment */
        tag_t                                               **solutions,            /**< (OF) n_solutions solutions response after unalignment */
        int                                                 *n_errors,              /**< (O)  Number of errors in the operation */
        PMM_error_store_map_t                               **error_map             /**< (OF) n_errors structures containing error details. 
                                                                                            <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only. */
    );

/**
    Publishes CAD occurrences to Usage Server.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PMM_design_rev_has_no_rendering if the CAD Item Revision does not have a Rendering dataset attached to it.
    <li>#PMM_assembly_with_embedded_jt if an assembly to be published contains a JT dataset in a non-leaf node.
    </ul>
*/
extern CBAEXT_API int CBAEXT_publish_cad_occurrences(
        const int                           n_cad_occ,          /**< (I) Number of CAD occurrences to publish */
        const CBAEXT_cad_occurrence_info_t  *publish_info,      /**< (I) List of CAD occurrences to publish */
        int                                 *n_errors,          /**< (O) Number of errors in the operation */
        PMM_error_store_map_t               **error_map         /**< (OF) n_errors List of structures containing error details.
                                                                            <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only.*/
        );



/**
    Aligns CAD Design Occurrences to Assembly Component Tree (ACT) Lines in Usage Server.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PMM_mismatch_of_selected_lines if the number of design occurrences and ACT Lines are different.
    <li>#PMM_selected_lines_packed if the Assembly Component Tree Lines that are input are packed.
    <li>#PMM_cannot_align_a_topline if the top BOMLine from a CAD structure is selected for aligning to a Solution. 
    <li>#PMM_bomline_not_in_context_of_ia if the input BOMLine is not part of an installation assembly.
    <li>#PMM_bomline_not_representation_of_act_topline if the Item Revision underlying the top BOMLine is not aligned to a Part.
    </ul>
*/
extern CBAEXT_API int CBAEXT_link_set_of_design_occ_and_act_line(
        const unsigned int                              n_design_occ,    /**< (I) Number of CAD occurrences to align */
        const CBAEXT_design_occurrence_act_line_info_t  *alignment_info, /**< (I) n_design_occ CAD occurrences and Assembly Component Tree Lines to align */
        int                                             *n_errors,       /**< (O) Number of errors in the operation */
        PMM_error_store_map_t                           **error_map      /**< (OF) n_errors of structures containing error details.
                                                                                <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only. */
        );

/**
    Unaligns CAD occurrences from Assembly Component Tree Lines in Usage Server.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PMM_mismatch_of_selected_lines if the number of design occurrences and ACT Lines are different.
    <li>#PMM_selected_lines_packed if the Assembly Component Tree Lines that are input are packed.
    <li>#PMM_bomline_not_in_context_of_ia if the input BOMLine is not part of an installation assembly.
    </ul>
*/
extern CBAEXT_API int CBAEXT_unalign_set_of_design_occ_and_act_line(
        const unsigned int                              n_design_occ,    /**< (I) Number of CAD occurrences to unalign */
        const CBAEXT_design_occurrence_act_line_info_t  *alignment_info, /**< (I) n_design_occ CAD occurrences and Assembly Component Tree Lines to unalign */
        int                                             *n_errors,       /**< (O) Number of errors in the operation */
        PMM_error_store_map_t                           **error_map      /**< (OF) n_errors of structures containing error details.
                                                                                <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only. */
        );

/** @} CBAEXT Alignment Functions */

/**
    @name CBAEXT Query Functions
    @{
*/

/**
    Finds the aligned Assembly Component Tree (ACT) Lines in Usage Server for the given CAD Design Occurrences with effectivity stream criteria.
    <br/>A design occurrence (BOMLine) may have alignment to multiple ACT Lines.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PMM_find_aligned_act_for_cad_failed if no ACT Line is aligned to the input design occurrence.
    <li>#PMM_effectivity_point_date_not_specified if @p effective_date or @p effective_point is not specified.
    <li>#PMM_empty_design_object_information if @p design_occs list is empty or contain invalid tags.
    <li>#PMM_effectivity_stream_not_specified if @p db_query_stream is not specified.
    </ul>
*/
extern CBAEXT_API int CBAEXT_find_aligned_act_lines_for_designs_with_stream(
        const unsigned int                n_design_occurrences,    /**< (I) Number of Design Occurrences. */
        const tag_t                       *design_occs,            /**< (I) n_design_occurrences Design Occurrences */
        const char                        *effective_date,         /**< (I) Effective date in the dd-mmm-yyyy format (eg:02-Jan-2020) for the aligned assembly component tree */
        const char                        *effective_point,        /**< (I) Effective point for the aligned assembly component tree */
        const char                        *db_query_stream,        /**< (I) Effective stream for the aligned assembly component tree */
        int                               *n_set_of_act_lines,     /**< (O) Number of sets of ACT lines */
        CBAEXT_set_of_aligned_act_lines_t **set_of_act_lines,      /**< (OF) n_set_of_act_lines Set of ACTLine lists that are aligned to each input BOMLine */
        int                               *n_error,                /**< (O)  Number of errors in the operation */
        PMM_error_store_map_t             **error_map              /**< (OF) n_error structures containing error details.
                                                                            <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only. */      
        );


/**
    Finds BomLines that are aligned to the given ACTLines.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PMM_act_no_alignedcad if no ACT Line is aligned to the input design occurrence.
    </ul>
*/
extern CBAEXT_API int  CBAEXT_find_bomlines_for_act_lines(
        const int                        n_actlines,               /**< (I) Number of ACTLines */
        const tag_t*                     actlines,                 /**< (I) List of ACTLines */
        CBAEXT_act_line_to_bomline_t**   actline_to_bomline        /**< (OF) n_actlines List of aligned BOMLines and ACTLines.
                                                                             <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only. */
        );

/**
    Expands the CAD structure that is below the input BOMLine to all lower levels.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOB_internal_error if the operation failed to expand the CAD structure.
    </ul>
*/
extern CBAEXT_API int CBAEXT_design_expand_below_all_levels(
        tag_t       line,                   /**< (I)  Tag for the top line */
        int         *child_lines_count,     /**< (O)  Total number of children */
        tag_t       **child_lines           /**< (OF) childLinesCount Child design lines tag */
        );

/**
    Finds the Item Revisions that are aligned to the input Parts.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PMM_invalid_object if an invalid part tag is input.
    </ul>
*/
extern CBAEXT_API int CBAEXT_find_item_revisions_linked_to_parts(
        const unsigned int                      n_parttags,     /**< (I) Number of Parts */
        const CBAEXT_part_info_t*               inp_part_info,  /**< (I) List of Parts tags */
        CBAEXT_item_revision_to_part_info_t**   item_info       /**< (OF) n_parttags List of structures containing Part tag and the aligned Item Revision tags.
                                                                          <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only. */  
        );

/**
    Finds the Drawing Revisions that are aligned to the input Parts.
    
    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PMM_invalid_object if an invalid part tag is input.
    </ul>
*/
extern CBAEXT_API int CBAEXT_find_drawing_revisions_linked_to_parts(
    const unsigned int                      n_parttags,      /**< (I) Number of Parts */
    const CBAEXT_part_info_t*               inp_part_info,   /**< (I) List of Parts tags */
    CBAEXT_item_revision_to_part_info_t**   drawing_info     /**< (OF) n_parttags List of structures containing Part tag and the aligned Drawing Revision tags.
                                                                       <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only. */    
    );

/**
    Finds the Parts that are aligned to the input CAD Item Revisions.
    
    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PMM_invalid_object if an invalid item revision tag is input.
    </ul>
*/
extern CBAEXT_API int CBAEXT_find_parts_linked_to_item_revisions(
    const int                               n_itemtags,     /**< (I) Number of Item Revisions */
    const tag_t*                            item_tags,      /**< (I) List of Item Revision tags */
    CBAEXT_part_to_item_revision_info_t**   part_info       /**< (OF) n_itemtags List of structures containing the Item Revision tag and the aligned Part tags.
                                                                 <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only. */ 
    );

/**
    Finds the Parts that are aligned to the input Drawing Revisions.
   
    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PMM_invalid_object if an invalid item revision tag is input.
    </ul>
*/
extern CBAEXT_API int CBAEXT_find_parts_linked_to_drawing_revisions(
    const int                               n_itemtags,     /**< (I) Number of Drawing Revisions */
    const tag_t*                            item_tags,      /**< (I) List of Drawing Revision tags */
    CBAEXT_part_to_item_revision_info_t**   part_info       /**< (OF) n_itemtags List of structures containing the Drawing Revision and the aligned Part tags.
                                                                 <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only. */   
    );

/**
    Finds Solutions by selecting design Occurrences.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PMM_bomline_not_in_context_of_ia if the input BOMLine is not part of an installation assembly.
    <li>#BOM_line_null_pathnode if the Appearance Path Node could not be  determined for the input BOMLine
    </ul>
*/
extern CBAEXT_API int CBAEXT_find_solutions_linked_to_design_occurrences(
        const unsigned int                          n_cad_occ,        /**< (I) Number of CAD occurrences */
        const CBAEXT_cad_occurrence_info_t          *cadocc_info,     /**< (I) List of CAD occurrences */
        int                                         *n_solutions,     /**< (O) Number of aligned Solutions */
        CBAEXT_design_occurrence_solution_info_t    **solution_output,/**< (OF) n_solutions List of structures containing the CAD Occurrence and the aligned Solution */
        int                                         *n_errors,        /**< (O)  Number of errors in the operation */
        PMM_error_store_map_t                       **error_map       /**< (OF) n_errors List of structures containing error details. 
                                                                                <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only. */
    );

/**
    Finds Solutions by selecting CAD occurrences.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PMM_remote_alignedcad if the aligned cad occurrence belongs to a different Teamcenter site.
    <li>#PMM_invalid_object if an invalid tag is input.
    </ul>
*/
extern CBAEXT_API int CBAEXT_find_design_occurrences_linked_to_solutions(
        const unsigned int                         n_solutions,         /**< (I) Number of Solutions*/
        const CBAEXT_solution_information_t        *solution_info,      /**< (I) List of Solutions */
        int                                        *n_cad_occs,         /**< (O) Number Of CAD occurrences */
        CBAEXT_design_occurrence_solution_info_t   **solution_output,   /**< (OF) n_cad_occs List of structures containing the Solution and the aligned CAD occurrence */
        int                                        *n_errors,           /**< (O)  Number of errors in the operation */
        PMM_error_store_map_t                      **error_map          /**< (OF) n_errors List of structures containing error details.
                                                                                <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only. */
    );
        
/**
    Finds the primary representations for the input Parts.
   
    @returns
    <ul>
    <li>#ITK_ok on success. <br>If an item revision which is the primary representation is found for a part, the item revision tag is populated in the output and the return code #ITK_ok is added to the error_map parameter.</li>
    <li>#PMM_mandatory_fields_not_specified if the input parameter n_parts is less than or equal to zero or part_info is NULL.</li>
    <li>#PMM_no_primary_representation_found if no primary representation is found for at least one of the Corporate Parts. The value #PMM_no_primary_representation_found is then added to the error_map parameters for the failing parts. 
    <br>The default primary representation on a part can be set using the ITK #CBAEXT_set_default_cad_representations_for_parts.</li>
    <li>#PMM_internal_error if an invalid part tag is processed.</li>
    </ul>
*/
extern CBAEXT_API int CBAEXT_ask_primary_representations(
    const unsigned int                      n_parts,             /**< (I) Number of parts for which the primary representation needs to be found. */
    const CBAEXT_part_info_t                *part_info,          /**< (I) n_parts parts for which the primary representation needs to be found.*/
    CBAEXT_item_revision_part_info_t        **output,            /**< (OF)n_parts Structures containing part and the aligned Item Revision.
                                                                                  <br>If no representation is found for a given part, the associated 
                                                                                  entry in the list will be a null pointer */
    PMM_error_store_map_t                   **error_map          /**< (OF)n_parts Structures containing error details.
                                                                                  <br>If no error has occurred for a given part, 
                                                                                  the associated entry in the list will be populated with clientId and ifail with ITK_ok.
                                                                                  <br>If an error has occurred for a given part, the associated entry in the list
                                                                                  will be pointer to a #PMM_error_store_map_t structure that contains more details. 
                                                                                    <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only. */
    );

/** @} CBAEXT Query Functions */

/** @} */

#ifdef __cplusplus
}
#endif


#include <cba1cbaext/libcbaext_undef.h>
#endif

