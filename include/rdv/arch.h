/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Architecture function prototypes
*/

/*  */

#ifndef ARCH_H
#define ARCH_H

#include <unidefs.h>
#include <tccore/item.h>
#include <rdv/librdv_exports.h>

/**
    @defgroup ARCH Architecture
    @ingroup RDV
    @{
*/

#define ARCH_CLASS_NAME             "Architecture"
#define ARCH_TYPE_NAME              ARCH_CLASS_NAME
#define ArchClassName               ARCH_CLASS_NAME

#define ARCH_REV_CLASS_NAME         "ArchitectureRevision"
#define ARCH_REV_TYPE_NAME          ARCH_REV_CLASS_NAME
#define ArchRevisionClassName       ARCH_REV_CLASS_NAME

#define ARCH_MASTER_CLASS_NAME      "ArchitectureMaster"
#define ARCH_REV_MASTER_CLASS_NAME  "ArchitectureVersionMaster"

#define TC_GENERIC_ARCHITECTURE     "TC_Generic_Architecture"
#define TC_INSTANTIATION            "TC_Instantiation"

#define HAS_CONSISTENT_NVES            "has_consistent_nves"
#define HAS_HIERARCHICAL_VARIABILTY "has_hierarchical_variabilty"
#define IS_PARTIAL_BREAKDOWN        "is_partial_breakdown"
#define HAS_SHARED_NVES                "has_shared_nves"
#define HAS_BASEDON_PREEXIST_ELEMNT "has_basedon_preexist_elemnt"

#define ITEM_ID                        "item_id"
#define OBJECT_NAME                    "object_name"
#define GENERIC_COMPONENT_ID        "generic_component_id"
#define OBJECT_DESC                    "object_desc"

#define ARCH_gcid_size_c            132

#ifdef __cplusplus
    extern "C"{
#endif

typedef struct RDV_option_value_pair_s
{
    tag_t option_tag;
    int n_values;
    int *valueIndex;
} RDV_option_value_pair_t;
typedef struct RDV_goi_optiondata_s
{
    tag_t item_tag;
    int n_options;
    struct RDV_option_value_pair_s *option_values_pair;
} RDV_goi_optiondata_t;

typedef struct RDV_Optiondata_s
{
    tag_t    item_tag;
    tag_t    item_type;
    char    *item_name;
    tag_t    option_tag;
    tag_t    option_type;
    char    *option_name;
    int      n_option_values;
    char   **option_values; 
} RDV_Optiondata_t;

/**
    @note This itk will not save the object. AOM_save_with_extensions needs to be called separately to save the object.
*/
extern RDV_API int ARCH_create_arch(
    const char*    id,                        /**< (I) */
    const char*    revId,                     /**< (I) */
    const char*    type,                      /**< (I) */
    const char*    name,                      /**< (I) */
    const char*    gcid,                      /**< (I) */
    const char*    desc,                      /**< (I) */
    tag_t*         newArch,                   /**< (O) */
    tag_t*         newArchRev                 /**< (O) */
    );


extern RDV_API int ARCH_save_as_arch(
    tag_t       rev_tag,                /**< (I) */
    const char *id,                     /**< (I) */
    const char *revId,                  /**< (I) */
    const char *type,                   /**< (I) */
    const char *name,                   /**< (I) */
    const char *gcid,                   /**< (I) */
    const char *desc,                   /**< (I) */
    tag_t* newArch,                     /**< (O) */
    tag_t* newArchRev                   /**< (O) */
    );


extern RDV_API int ARCH_ask_named_variant_exprs(
    tag_t          arch,                      /**< (I) */
    int*           no_of_nves,                /**< (O) */
    tag_t**        named_variant_expressions  /**< (O) */
    );

extern RDV_API int ARCH_add_named_variant_expr(
    tag_t     arch_rev,                 /**< (I) */
    char*     code,                     /**< (I) */
    char*     description,              /**< (I) */
    tag_t     variant_expression,       /**< (I) */
    logical   ignore_duplicate,         /**< (I) */
    logical   implicit_save,            /**< (I) */
    int*      n_tags_to_save,           /**< (O) */
    tag_t**   tags_to_save,             /**< (OF) n_tags_to_save */
    tag_t*    new_nve_tag               /**< (O) */
    );

extern RDV_API int ARCH_add_nve_from_formula(
    tag_t  archrev_or_bomline,          /**< (I) */
    char*  code,                        /**< (I) */
    char*  description,                 /**< (I) */
    const char* productName,            /**< (I) */
    const char* productNamespace,       /**< (I) */
    const char* formula,                /**< (I) */
    logical ignore_duplicate,           /**< (I) */
    logical implicit_save,              /**< (I) */
    int*    n_tags_to_save,             /**< (O) */
    tag_t** tags_to_save,               /**< (OF) n_tags_to_save */
    tag_t*  new_nve_tag                 /**< (O) */
    );
extern RDV_API int ARCH_find_arch(
    const char*    gc_id,                     /**< (I) */
    const char*    type,                      /**< (I) */
    int*           count,                     /**< (O) */
    tag_t**        tags                       /**< (OF) count */
    );

extern RDV_API int ARCH_add_arch_element(
    tag_t          window,                    /**< (I) */
    tag_t          parent_bom_line,           /**< (I) */
    tag_t          item,                      /**< (I) */
    tag_t*         new_apprpathnode           /**< (O) */
    );

extern RDV_API int ARCH_is_toplevel(
    tag_t          arch_tag,                  /**< (I) */
    logical*       isTop                      /**< (I) */
    );

extern RDV_API int ARCH_find_arch_apn(
    tag_t          arch_tag,                  /**< (I) */
    tag_t          topItem,                   /**< (I) */
    int*           count,                     /**< (O) */
    tag_t**        apn                        /**< (OF) count */
    );

extern RDV_API int ARCH_determine_installation_assy(
    tag_t          apn,                       /**< (I) */
    int*           count,                     /**< (O) */
    tag_t**        itemrev_tags               /**< (OF) count */
    );

/**
    Finds named variant expressions by code and/or description and/or variants and/or expression literals

    @code
        n_options = 4;
        options[0] = opt1;
        options[1] = opt2;
        options[2] = opt3;
        options[3] = opt4;
        n_values = 3;
        opcodes[0] = 1005;
        opcodes[1] = -1;
        opcodes[2] = 1006;
        values[0]  = "0";
        values[1]  = NULL;
        values[2]  = "1";
    @endcode

    is the same as calling it with

    @code
        n_options = 4;
        options[0] = opt1;
        options[1] = opt3;
        options[2] = opt2;
        options[3] = opt4;
        n_values = 2;
        opcodes[0] = 1005;
        opcodes[1] = 1006;
        values[0]  = "0";
        values[1]  = "1";
    @endcode

    In both cases the function will return all named variant conditions on arch_item that
    <ul>
    <li>contain the variant expression literal "opt1 == value_at_index_0"   AND
    <li>contain the variant expression literal "opt3 != value_at_index_1"   AND
    <li>vary by option opt2                                                 AND
    <li>vary by option opt4
    </ul>
*/
extern RDV_API int ARCH_find_named_variant_expr(
    tag_t          arch_rev,                  /**< (I) */
    const char*    code,                      /**< (I) */
    const char*    desc,                      /**< (I) */
    int            n_options,                 /**< (I) */
    const tag_t*   options,                   /**< (I) */
    int            n_values,                  /**< (I) */
    const int*     opcodes,                   /**< (I) */
    const char**   values,                    /**< (I) */
    int*           n_found_nves,              /**< (O) */
    tag_t**        found_nves                 /**< (OF) n_found_nves */
    );


/**
 */
extern RDV_API int ARCH_ask_gcid2(
    tag_t          arch_item,                 /**< (I) */
    char           **gcid                     /**< (OF) */
    );

extern RDV_API int ARCH_set_gcid(
    tag_t          arch_item,                 /**< (I) */
    const char*    gcid                       /**< (I) */
    );

extern RDV_API int ARCH_get_associated_data(
    tag_t          arch_item,                 /**< (I) */
    tag_t          top_item ,                 /**< (I) */
    int*           node_count,                /**< (O) */
    tag_t**        nodes,                     /**< (OF) node_count */
    int*           ia_count,                  /**< (O) */
    tag_t**        iaRevs,                    /**< (OF) ia_count */
    int*           no_of_nves,                /**< (O) */
    tag_t**        nve_tags                   /**< (OF) no_of_nves */
    );

extern RDV_API int ARCH_get_nves(
    tag_t          apn,                       /**< (I) */
    tag_t          top_line_bvr,              /**< (I) */
    int*           nve_count,                 /**< (O) */
    tag_t**        nves                       /**< (OF) nve_count */
    );

extern RDV_API int ARCH_ask_veb(
    tag_t          arch_item,                 /**< (I) */
    tag_t*         veb                        /**< (O) */
    );

extern RDV_API int ARCH_set_veb(
    tag_t          arch_item,                 /**< (I) */
    tag_t          veb                        /**< (O) */
    );

extern RDV_API int ARCH_rev_ask_product_items(
    tag_t          arch_rev,                  /**< (I) */
    int*           n_product_items,           /**< (O) */
    tag_t**        product_items              /**< (OF) n_product_items */
    );

/**
    @note This itk will not save the object. AOM_save_with_extensions needs to be called separately to save the object.
*/
extern RDV_API int ARCH_create_arch_with_struct_info(
    const char *id,                           /**< (I) */
    const char *rev_id,                       /**< (I) */
    const char *type,                         /**< (I) */
    const char *name,                         /**< (I) */
    const char *gc_id,                        /**< (I) */
    const char *desc,                         /**< (I) */
    logical     has_consistent_nves,          /**< (I) */
    logical     has_heirarchical_variability, /**< (I) */
    logical     has_partial_breakdown,        /**< (I) */
    logical     has_shared_nves,              /**< (I) */
    tag_t      *new_arch,                     /**< (O) */
    tag_t      *rev                           /**< (O) */
    );

/**
    @note This itk will not save the object. AOM_save_with_extensions needs to be called separately to save the object.
*/
extern RDV_API int ARCH_create_generic_object(
    const char *id,                           /**< (I) */
    const char *rev_id,                       /**< (I) */
    const char *type,                         /**< (I) */
    const char *name,                         /**< (I) */
    const char *gc_id,                        /**< (I) */
    const char *desc,                         /**< (I) */
    logical     has_consistent_nves,          /**< (I) */
    logical     has_heirarchical_variability, /**< (I) */
    logical     has_partial_breakdown,        /**< (I) */
    logical     has_shared_nves,              /**< (I) */
    logical     has_based_on_preexist_elements,  /**< (I) */
    tag_t       instantiating_arch,           /**< (I) */
    tag_t      *new_go,                       /**< (O) */
    tag_t      *rev                           /**< (O) */
    );

extern RDV_API int ARCH_is_architecture(
    tag_t     arch_tag,                       /**< (I) */
    logical   *isArch                         /**< (O) */
    );

extern RDV_API int ARCH_has_shared_nves(
    tag_t arch_tag,                           /**< (I) */
    logical *has_shared_nve                   /**< (O) */
    );

extern  RDV_API int ARCH_set_shared_nves(
    tag_t arch_tag,                           /**< (I) */
    logical set_shared_nves                   /**< (I) */
    );

extern  RDV_API int ARCH_has_consistent_nves(
    tag_t arch_tag,                           /**< (I) */
    logical *has_consistent_nves              /**< (O) */
    );

extern  RDV_API int ARCH_set_consistent_nves(
    tag_t arch_tag,                           /**< (I) */
    logical set_consistent_nves               /**< (I) */
    );

extern  RDV_API int ARCH_has_heirarchical_variability(
    tag_t arch_tag,                           /**< (I) */
    logical *has_heirarchical_variability     /**< (O) */
    );

extern RDV_API int ARCH_set_heirarchical_variability(
    tag_t arch_tag,                           /**< (I) */
    logical set_heirarchical_variability      /**< (I) */
    );

extern RDV_API int ARCH_has_partial_breakdown(
    tag_t arch_tag,                           /**< (I) */
    logical *has_partial_breakdown            /**< (O) */
    );

extern RDV_API int ARCH_set_partial_breakdown(
    tag_t arch_tag,                           /**< (I) */
    logical set_partial_breakdown             /**< (I) */
    );

extern RDV_API int ARCH_has_preexist_break_elemnts(
    tag_t arch_tag,                           /**< (I) */
    logical *has_preexist_break_elemnts       /**< (O) */
    );

extern RDV_API int ARCH_ask_all_struct_state_parameters(
    tag_t arch_tag,                           /**< (I) */
    logical *has_consistent_nves,             /**< (O) */
    logical *has_heirarchical_variability,    /**< (O) */
    logical *has_partial_breakdown,           /**< (O) */
    logical *has_shared_nves,                 /**< (O) */
    logical *has_based_on_preexist_elements   /**< (O) */
    );

extern RDV_API int ARCH_set_all_struct_state_parameters(
    tag_t arch_tag,                           /**< (I) */
    logical has_consistent_nves,              /**< (I) */
    logical has_heirarchical_variability,     /**< (I) */
    logical has_partial_breakdown,            /**< (I) */
    logical has_shared_nves,                  /**< (I) */
    logical has_based_on_preexist_elements    /**< (I) */
    );

extern RDV_API int ARCH_save_as(
    tag_t          sourceItem,                /**< (I) Tag of an existing Generic Object Item */
    tag_t          sourceItemRevision,        /**< (I) Tag of revision to use, if null use the latest rev */
    const char*    new_item_id,               /**< (I) A null is allowed */
    const char*    new_item_rev,              /**< (I) A null is allowed */
    const char*    gcid,                      /**< (I) A null is allowed */
    const char*    name,                      /**< (I) A null is allowed */
    const char*    description,               /**< (I) A null is allowed */
    tag_t*         newItem                    /**< (O) Tag for identifying the new Generic Object */
    );


extern RDV_API int ARCH_is_generic_object(
    tag_t     arch_tag,                       /**< (I) */
    logical   *is_generic_object              /**< (O) */
    );

extern RDV_API int ARCH_paste (
    tag_t          selectedSourceItem,      /**< (I) Tag of an existing Generic Object> */
    tag_t          targetItem,              /**< (I) Tag of target for paste action> */
    logical        processChildren          /**< (I) Determine whether to include children in paste> */
    );

extern RDV_API int ARCH_get_nve_count(
    tag_t         arch_rev,             /**< (I) */
    const char  * code,                 /**< (I) */
    const char  * desc,                 /**< (I) */
    int           n_options,            /**< (I) */
    const tag_t * options,              /**< (I) */
    int           n_values,             /**< (I) */
    const int   * opcodes,              /**< (I) */
    const char ** values,               /**< (I) */
    int         * n_found_nves          /**< (O) */
    );

extern RDV_API int ARCH_paste_bomline(
    tag_t          selectedSourceBOMline,     /**< (I) Tag of bomline of an existing Generic Object */
    tag_t          targetBOMLineToBeUsed,     /**< (I) Tag of bomline of target for paste action */
    tag_t          sourceBOMLineToBeUsed,     /**< (I) Tag of bomline to use in copy/paste */
    int            noOfSourceParentBOMLines,  /**< (I) number of parent bomlines */
    tag_t         *sourceParentBomlines,      /**< (I) Array of parent bomlines of selectedSourceBOMline */
    logical        processParents,            /**< (I) Determine whether to include parents in paste */
    logical        processChildren            /**< (I) Determine whether to include children in paste */
    );

extern RDV_API int ARCH_getAuditedLines(
    int n_nodes,                    /**< (I) */
    tag_t *nodes,                   /**< (I) */
    tag_t rev_rule_tag,             /**< (I) */
    tag_t var_rule_tag,             /**< (I) */                     
    int *noOfAuditedLines,          /**< (O) */
    tag_t **targetAuditedLineTags   /**< (OF) */
    );

extern RDV_API int ARCH_getAuditData( 
    tag_t pReport, 
    tag_t   auditedLineTag,
    tag_t  *bom_line,
    int    *n_occurrences,
    tag_t **occurrences,
    int   **occmatch_types,
    int   **occmatch_info,
    char  **occ_nve_desc,
    char  **occ_pnum_desc,
    char  **occ_qty_desc,
    int    *overall_match_info,
    char  **nve_match_desc,
    char  **pnum_match_desc,
    char  **qty_match_desc,
    char  **audit_line_summary,
    char  **audit_score 
    );

extern RDV_API int ARCH_getDesignAuditData( 
    tag_t pReport, 
    tag_t   auditedLineTag,
    tag_t  *bom_line,
    int    *n_occurrences,
    tag_t **occurrences,
    int   **occmatch_types,
    int   **occmatch_info,
    char  **occ_nve_desc,
    char  **occ_pnum_desc,
    char  **occ_qty_desc,
    int    *overall_match_info,
    char  **nve_match_desc,
    char  **pnum_match_desc,
    char  **qty_match_desc,
    char  **audit_line_summary,
    char  **audit_score 
    );

extern RDV_API int  ARCH_clear_auditreport( 
    tag_t report_tag
    );
extern RDV_API int  ARCH_closeTargetWindow( 
    tag_t report_tag
    );
extern RDV_API int ARCH_get_options_optionvalues_for_goi(
    int *n_items,                     /**< (O) */
    RDV_Optiondata_t **goi_optiondata /**< (OF) n_items */ 
    );

extern RDV_API int ARCH_revise_arch(
      tag_t                         revTag,                    /**< (I) */
      const char                   *revisionId,                /**< (I) */
      const char                   *name,                      /**< (I) */
      const char                   *description,               /**< (I) */
      logical                       deepCopyRequired,          /**< (I) */
      int                           count,                     /**< (I) */
      const ITEM_deepcopy_info_t   *CopyInfo,                  /**< (I) */
      int                          *deepCopiedCount,           /**< (O) */    
      tag_t                       **deepCopiedTags,            /**< (OF) */
      tag_t                       **deepCopiedTypeTags,        /**< (OF) */
      tag_t                        *newRevTag,                 /**< (O) */
      tag_t                        *itemRevType                /**< (O) */
    );

extern RDV_API int ARCH_find_qualified_appgrp(
    tag_t                         apn_tag,                   /**< (I) */
    tag_t                         top_arch_rev,              /**< (I) */
    logical*                      is_shared,                 /**< (O) */
    tag_t*                        appgrp                     /**< (O) */
    );     

extern RDV_API int ARCH_find_create_qualified_appgrp(
    tag_t                         appgrp,                    /**< (I) */
    tag_t                         top_arch_rev,              /**< (I) */
    tag_t*                        new_appgrp                 /**< (O) */
    );    

extern RDV_API int ARCH_deep_copy_arch( 
    tag_t          tgt_bomline_tag,             /**< (I) */
    tag_t          src_bomline_tag,             /**< (I) */
    int            flag_value                   /**< (I) */
    );      

extern RDV_API int ARCH_carry_over_variability( 
    tag_t          src_bomline_tag,             /**< (I) */
    tag_t          tgt_bomline_tag              /**< (I) */
    );            

extern RDV_API int ARCH_carry_over_nves( 
    tag_t          src_bomline_tag,             /**< (I) */
    tag_t          tgt_bomline_tag              /**< (I) */
    );           

extern RDV_API int ARCH_carry_over_partsols( 
    tag_t          src_bomline_tag,             /**< (I) */
    tag_t          tgt_bomline_tag              /**< (I) */
    );            
extern RDV_API int ARCH_carry_over_defs_and_rulechecks( 
    tag_t          source_topline,              /**< (I) */
    tag_t          tgt_topline                  /**< (I) */
    );           

extern RDV_API int RDV_get_go_part_solutions( 
    tag_t           go_bomline,                 /**< (I) */
    int*            lou_num,                    /**< (O) */ 
    tag_t**         lou_bomline_tags,           /**< (OF) lou_num */
    tag_t*          bom_window_tag              /**< (O) */
    ); 

extern RDV_API int RDV_get_lou_bomline( 
    tag_t           bomwindow,                  /**< (I) */
    tag_t           top_rev_tag,                /**< (I) */
    char*           gc_id,                      /**< (I) */
    logical         is_arch,                    /**< (I) */
    int*            num_part,                   /**< (O) */
    tag_t**         part_bomline_list           /**< (OF) num_part */
    );                

extern RDV_API int RDV_find_abe_in_ab_assem( 
    tag_t           bom_win_tag,                /**< (I) */
    char*           gc_id,                      /**< (I) */
    logical*        valid_abe                   /**< (O) */
    );
extern RDV_API int RDV_create_svr(
    tag_t           drule,                      /**< (I) */
    const char*     name,                       /**< (I) */
    const char*     description,                /**< (I) */
    int             nOptions,                   /**< (I) */
    tag_t*          variants,                   /**< (I) */
    const char**    values,                     /**< (I) */
    tag_t           itemRev,                    /**< (I) */
    const char*     relationType,               /**< (I) */
    tag_t*          vrule                       /**< (O) */
    );

extern RDV_API int ARCH_ask_usages_of_arch_apn(
  tag_t      arch_apn,                    /**< (I) */
  tag_t      top_arch_rev,                /**< (I) */
  int*       n_usages,                    /**< (O) */
  tag_t**    usage_apns                   /**< (OF) n_usages */
  );
extern RDV_API int RDV_add_part_solution_to_ABEorGBE(
  tag_t      component,                     /**< (I) */
  tag_t      abe,                           /**< (I) */
  int        prodRevCount,                  /**< (I) */
  tag_t     *prodRevTags,                   /**< (I) */
  tag_t      abeApnTag,                     /**< (I) */
  int        n_authNVEs,                    /**< (I) */
  tag_t     *authNVEs,                      /**< (I) */
  int        quantity,                      /**< (I) */
  int        n_noteTexts,                   /**< (I) */
  char     **noteTypes,                     /**< (I) */
  char     **noteTexts,                     /**< (I) */
  tag_t     *partSolutionAPN                /**< (O) */
  );


/**
   This function allows creating an Arch type item with the given input 
   arguments which includes attribute names and their values.
   Below are the attribute names  which are passed to ARCH_create_generic_object2
   "item_id"
   "object_name"
   "generic_component_id"
   "object_desc"
   "has_consistent_nves"
   "has_hierarchical_variabilty"
   "is_partial_breakdown"
   "has_shared_nves"
   "has_basedon_preexist_elemnt"  

   @note This itk will not save the object. AOM_save_with_extensions needs to be called separately to save the object.
*/
extern RDV_API int ARCH_create_generic_object2(
    const char* item_type,                /**< (I) Type of Item to be created */
    int         numAttrs,                 /**< (I) Number of input attributes */
    char **     attrNames,                /**< (I) Names of input attributes  */
    char **    attrValues,                /**< (I) Values for the input attributes */
    const char* rev_id,                   /**< (I) Id for the revision */
    tag_t       instantiating_arch,       /**< (I) tag of instantiating_arch ,NULL is allowed*/
    tag_t*      item,                     /**< (O) The created item tag */
    tag_t*      rev                       /**< (O) The created item revision tag */
    );
/** @} */

#ifdef __cplusplus
    }
#endif

#include <rdv/librdv_undef.h>

#endif
