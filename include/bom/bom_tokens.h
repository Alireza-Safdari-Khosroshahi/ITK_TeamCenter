/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Defines tokens used by the BOM ITK interface.
*/

/*  */

#ifndef BOM_TOKENS_H
#define BOM_TOKENS_H

#include <unidefs.h>
#include <ps/ps_tokens.h>
#include <bom/libbom_exports.h>

/**
    @defgroup BOM_TOKENS Tokens
    @ingroup BOM
    @{
*/

/**
    @name BOM_window_ask_state_logical() tokens
    @{
*/
#define BOM_WINDOW_STATE_PACK_ALL               1
#define BOM_WINDOW_STATE_SHOW_VARIANTS          2
#define BOM_WINDOW_STATE_SHOW_UNCONFIG          3
#define BOM_WINDOW_STATE_SHOW_ALTS              4
/** @} */

/** May take any integer value */
#define BOM_option_mode_int                     PS_variant_option_mode_unknown

/** Has a set of defined string values */
#define BOM_option_mode_enum                    PS_variant_option_mode_dynamic_comparison
#define BOM_variant_op_rhs_is_string            PS_variant_op_rhs_is_string
#define BOM_variant_operator_declare            PS_variant_operator_declare
#define BOM_variant_operator_assy_uses          PS_variant_operator_assy_uses
#define BOM_variant_operator_assign             PS_variant_operator_assign
#define BOM_variant_operator_default            PS_variant_operator_default
#define BOM_variant_operator_is_equal           PS_variant_operator_is_equal
#define BOM_variant_operator_not_equal          PS_variant_operator_not_equal
#define BOM_variant_operator_error_if           PS_variant_operator_error_if
#define BOM_variant_operator_comment            PS_variant_operator_comment
#define BOM_variant_operator_load_if            PS_variant_operator_load_if
#define BOM_variant_operator_and                PS_variant_operator_and
#define BOM_variant_operator_or                 PS_variant_operator_or
#define BOM_variant_operator_if                 PS_variant_operator_if

/** Greater than */
#define BOM_variant_operator_gt                 PS_variant_operator_gt

/** Less than */
#define BOM_variant_operator_lt                 PS_variant_operator_lt

/** Greater than or equal */
#define BOM_variant_operator_gt_eq              PS_variant_operator_gt_eq

/** Less than or equal */
#define BOM_variant_operator_lt_eq              PS_variant_operator_lt_eq

#define BOM_variant_operator_brackets           PS_variant_operator_brackets

/** Saved variant rule */
#define BOM_variant_operator_rule_set           PS_variant_operator_rule_set

/** Named Variant Expression */
#define BOM_variant_operator_named_expr         PS_variant_operator_named_expr

/** NVE Meta-expression */
#define BOM_variant_operator_meta_expr          PS_variant_operator_meta_expr

/** NVE Reference */
#define BOM_variant_operator_nve_ref            PS_variant_operator_nve_ref

/** Not - ONLY SUPPORTED IN META-EXPRESSIONS */
#define BOM_variant_operator_not                PS_variant_operator_not


/** @if DOX_IGNORE (PDJ)  06-Nov-1997
    Changed this public enum to have the correct module prefix.
    Old names supported for legacy.
@endif */
typedef enum
{
     BOM_option_unset,
     BOM_option_unset_derivable,
     BOM_option_derived,            /**< OVESelOptionSet::Set */
     BOM_option_defaulted,          /**< OVESelOptionSet::Default */
     BOM_option_set_by_user,        /**< OVESelOptionSet::UserSet */
     BOM_option_set_by_rule,
     BOM_option_fixed,         /* OVESelOptionSet::Fixed */
     BOM_option_fixed_by_user, /* OVESelOptionSet::UserFixed */
     BOM_option_variant_item,   /* OVESelOptionSet::VariantItem */
     BOM_option_external        /* OVESelOptionSet::External */
} BOM_option_how_set_t;

typedef BOM_option_how_set_t                    OptionHowSet_e;
#define OPTION_UNSET                            BOM_option_unset
#define OPTION_UNSET_DERIVABLE                  BOM_option_unset_derivable
#define OPTION_DERIVED                          BOM_option_derived
#define OPTION_DEFAULTED                        BOM_option_defaulted
#define OPTION_SET_BY_USER                      BOM_option_set_by_user
#define OPTION_SET_BY_RULE                      BOM_option_set_by_rule
#define OPTION_SET_EXTERNAL                     BOM_option_external

/**
    @name BOM Line Forced Configuration states
    @{
*/
#define BOM_LINE_FORCE_NONE             0
#define BOM_LINE_FORCE_CONFIGURE_IN     1
#define BOM_LINE_FORCE_CONFIGURE_OUT    2
/** @} */

/**
    @name BOM Line Variant Configuration states
    @{
*/
#define BOM_LINE_VARIANT_NONE           0
#define BOM_LINE_VARIANT_LOADED         1
#define BOM_LINE_VARIANT_SUPPRESSED     2
#define BOM_LINE_VARIANT_UNDEFINED      3
/** @} */


/**
    @name Standard BOM Compare modes' names

    Use them with BOM_compare_execute(), and don't use BOM_compare() in new code.
    @{
*/
extern BOM_API const char* const BOM_std_compare_single_level_name;
extern BOM_API const char* const BOM_std_compare_single_level_seq_name;
extern BOM_API const char* const BOM_std_compare_lowest_level_name;
extern BOM_API const char* const BOM_std_compare_lowest_level_seq_name;
extern BOM_API const char* const BOM_std_compare_var_level_name;
extern BOM_API const char* const BOM_std_compare_var_level_seq_name;
extern BOM_API const char* const BOM_std_compare_ext_var_level_name;
extern BOM_API const char* const BOM_std_compare_ext_var_level_seq_name;
extern BOM_API const char* const LBOM_std_compare_var_level_name;
extern BOM_API const char* const LBOM_std_compare_single_level_name;  
extern BOM_API const char* const LBOM_std_compare_lowest_level_name;
extern BOM_API const char* const LBOM_std_compare_var_level_occ_name;
extern BOM_API const char* const LBOM_std_compare_single_level_occ_name;
/** @} */

/**
    @name Numeric modes
    
    - For accessing the standard compare modes through BOM_compare().


      DO NOT USE BOM_compare() in new code: use BOM_compare_execute() with the
      *_names defined above.

    - Also used as traversal modes when defining/querying new compare modes using
      BOM_compare_define_mode() and BOM_compare_ask_mode_info().
    @{
*/
#define BOM_compare_singlelevel                 0
#define BOM_compare_lowestlevel                 1
#define BOM_compare_multilevel                  2

/**
    The following is a traversal mode only, there is no extended multi level compare mode.
    This traversal mode continues traversing through minor changes (ie. aggregate compare elements).
*/
#define BOM_compare_extmultilevel               3
/**
    This traversal mode compares every single line in a BOM.
*/
#define BOM_compare_everylevel                  4

/** @} */

/**
    @name BOM Compare output destinations

    These values can be added together to output to all of them
    @{
*/
#define BOM_compare_output_bomline              1
#define BOM_compare_output_userexit             2
#define BOM_compare_output_report               4
/** @} */


/**
    @name BOM Compare application flags
    
    These flags can be used to mark compare elements for special processing.
     Flags 0-15 are reserved for system defined flags.
     Flags 16-31 can be used by customers for passing simple flags into
                 their custom compare methods.
    @{
*/
/**
   Force BOM Compare to treat aggregate element as a display element when
   generating multi-level report output.
*/
#define BOM_compare_display_aggregate 0
/**
   Stop extended multi-level traversal if aggregate element is different.
   Normally used on Item Id element on Occurrence based compares.
*/
#define BOM_compare_stop_if_diff 1
/**
    By default, display elements report adds in the form "()->XYZ" (where
    XYZ is the value from the added object). However, this is undesirable
    in some elements. Setting this flag on an element will force it to
    report adds in the form "XYZ". Genuine changes in value will still be
    reported in the form "ABC->XYZ".
*/
#define BOM_compare_dont_report_adds 2
/** @} */


/**
    @name BOM Compare differences
    @{
*/
#define BOM_cmp_diff_add                        1
#define BOM_cmp_diff_qty                        2
#define BOM_cmp_diff_rev                        4
#define BOM_cmp_diff_chg                        8
/** @} */

/**
    This is a C macro that extracts the state of individual difference flags from 
    the value returned by #BOM_compare_list_diffs, #BOM_compare_list_diffs_context or #BOM_compare_ask_difference.

    Returns true if none of the difference flags are set.

    FLAGS - Differences between the two BOMs relating to a compare item.
*/
#define BOM_cmp_no_diff(FLAGS) ((FLAGS)==0)

/**
    This is a C macro that extracts the state of individual difference flags from
    the value returned by #BOM_compare_list_diffs, #BOM_compare_list_diffs_context or #BOM_compare_ask_difference.

    Returns true if the added difference flag is set.

    FLAGS - Differences between the two BOMs relating to a compare item.
*/
#define BOM_cmp_added(FLAGS)   (((FLAGS)&(BOM_cmp_diff_add))!=0)

/**
    This is a C macro that extracts the state of individual difference flags from
    the value returned by #BOM_compare_list_diffs, #BOM_compare_list_diffs_context or #BOM_compare_ask_difference.

    #BOM_cmp_chg_qty returns true if the quantity change difference flag is set.

    FLAGS - Differences between the two BOMs relating to a compare item.
*/
#define BOM_cmp_chg_qty(FLAGS) (((FLAGS)&(BOM_cmp_diff_qty))!=0)

/**
    This is a C macro that extracts the state of individual difference flags from
    the value returned by #BOM_compare_list_diffs, #BOM_compare_list_diffs_context or #BOM_compare_ask_difference.

    #BOM_cmp_chg_rev returns true if the revision change difference flag is set.
*/
#define BOM_cmp_chg_rev(FLAGS) (((FLAGS)&(BOM_cmp_diff_rev))!=0)

#define BOM_cmp_changed(FLAGS) (((FLAGS)&(BOM_cmp_diff_chg))!=0)

/**
    @name BOM Compare quantity special cases
    @{
*/
#define BOM_cmp_asreq(Q) (((Q)>(-1.5))&&((Q)<(-0.5)))
#define BOM_cmp_undef(Q) (((Q)>(-2.5))&&((Q)<(-1.5)))
/** @} */

/**
    @name BOM Compare visitor function types
    @{
*/

typedef int (BOM_compare_engine_visitor_t)(
    tag_t bomcompareengine,
    tag_t compareset,
    int   depth,
    void* user_data
    );

typedef int (BOM_compare_set_visitor_t)(
    tag_t compareset,
    int   depth,
    void* user_data
    );

/** @} */

/**
    @name Variant Condition Clause List - Valid Operation Macros
    @{
*/
#define BOM_vc_op_details                       1
#define BOM_vc_op_append                        2
#define BOM_vc_op_insert                        4
#define BOM_vc_op_replace                       8
#define BOM_vc_op_delete                        16
#define BOM_vc_op_mv_up                         32
#define BOM_vc_op_mv_dn                         64
#define BOM_vc_op_add_brackets                  128
#define BOM_vc_op_rm_brackets                   256
/** @} */

/** 
    Returns true if the clause selection passed into #BOM_variant_clause_valid_ops
    is valid for passing to #BOM_variant_clause_details.

    <b>Arguments</b>

    OP_FLAGS - The bit encoded integer returned by #BOM_variant_clause_valid_ops.
     

    <b>Return Values</b>

    true - Selection is valid for the Details operation. <br>
    false - Selection is not valid for the Details operation.
*/
#define BOM_variant_clause_op_details(OP_FLAGS)      (((OP_FLAGS)&BOM_vc_op_details) != 0)


#define BOM_variant_clause_op_append(OP_FLAGS)       (((OP_FLAGS)&BOM_vc_op_append) != 0)

/**
    Returns true if the clause selection passed into #BOM_variant_clause_valid_ops is
    valid for passing to #BOM_variant_clause_insert.

    <b>Arguments</b>

    OP_FLAGS - The bit encoded integer returned by #BOM_variant_clause_valid_ops.
     
    <b>Return Values</b>

    true - Selection is valid for the Insert operation. <br>
    false - Selection is not valid for the Insert operation.
*/
#define BOM_variant_clause_op_insert(OP_FLAGS)       (((OP_FLAGS)&BOM_vc_op_insert) != 0)

/**
    Returns true if the clause selection passed into #BOM_variant_clause_valid_ops is
    valid for passing to #BOM_variant_clause_replace.

    <b>Arguments</b>

    OP_FLAGS - The bit encoded integer returned by #BOM_variant_clause_valid_ops.
     
    <b>Return Values</b>

    true - Selection is valid for the Replace operation. <br>
    false - Selection is not valid for the Replace operation.
*/
#define BOM_variant_clause_op_replace(OP_FLAGS)      (((OP_FLAGS)&BOM_vc_op_replace) != 0)

/**
    Returns true if the clause selection passed into #BOM_variant_clause_valid_ops is
    valid for passing to #BOM_variant_clause_delete.

    <b>Arguments</b>

    OP_FLAGS - The bit encoded integer returned by #BOM_variant_clause_valid_ops.
     
    <b>Return Values</b>

    true - Selection is valid for the Delete operation. <br>
    false - Selection is not valid for the Delete operation.
*/
#define BOM_variant_clause_op_delete(OP_FLAGS)       (((OP_FLAGS)&BOM_vc_op_delete) != 0)

/**
    Returns true if the clause selection passed into #BOM_variant_clause_valid_ops is
    valid for passing to #BOM_variant_clause_move_up.

    <b>Arguments</b>

    OP_FLAGS - The bit encoded integer returned by #BOM_variant_clause_valid_ops.
     
    <b>Return Values</b>

    true - Selection is valid for the Move Up operation. <br>
    false - Selection is not valid for the Move Up operation.
*/
#define BOM_variant_clause_op_mv_up(OP_FLAGS)        (((OP_FLAGS)&BOM_vc_op_mv_up) != 0)

/**
    Returns true if the clause selection passed into #BOM_variant_clause_valid_ops is 
    valid for passing to #BOM_variant_clause_move_down.

    <b>Arguments</b>

    OP_FLAGS - The bit encoded integer returned by #BOM_variant_clause_valid_ops.
     
    <b>Return Values</b>

    true - Selection is valid for the Move Down operation. <br>
    false - Selection is not valid for the Move Down operation.
*/
#define BOM_variant_clause_op_mv_dn(OP_FLAGS)        (((OP_FLAGS)&BOM_vc_op_mv_dn) != 0)

/**
    Returns true if the clause selection passed into #BOM_variant_clause_valid_ops is
    valid for passing to #BOM_variant_clause_toggle_brackets.
    
    @note There are separate entries for checking the validity of adding and
    removing brackets although they are implemented via the same toggle brackets operation.
    This allows a user interface to implement a tri-state bracketing button 
    (indented if able to add, not indented if able to remove, disabled if neither).

    <b>Arguments</b>

    OP_FLAGS - The bit encoded integer returned by #BOM_variant_clause_valid_ops.

    <b>Return Values</b>

    true - Selection is valid for the Toggle Brackets operation. <br>
    false - Selection is not valid for the Toggle Brackets operation.
*/
#define BOM_variant_clause_op_add_brackets(OP_FLAGS) (((OP_FLAGS)&BOM_vc_op_add_brackets) != 0)

/**
    Returns true if the clause selection passed into #BOM_variant_clause_valid_ops is
    valid for passing to #BOM_variant_clause_toggle_brackets.

    @note There are separate entries for checking the validity of adding and removing
    brackets although they are implemented via the same toggle brackets operation.
    This allows a user interface to implement a tri-state bracketing button 
    (indented if able to add, not indented if able to remove, disabled if neither).

    <b>Arguments</b>

    OP_FLAGS - The bit encoded integer returned by #BOM_variant_clause_valid_ops.

    <b>Return Values</b>

    true - Selection is valid for the Toggle Brackets operation. <br>
    false - Selection is not valid for the Toggle Brackets operation.
*/
#define BOM_variant_clause_op_rm_brackets(OP_FLAGS)  (((OP_FLAGS)&BOM_vc_op_rm_brackets) != 0)

/**
    BOM Variant Rule - Cross-BOMWindow Copy Actions
*/
typedef enum
{
    BOM_variant_rule_src,
    BOM_variant_rule_src_and_dest,
    BOM_variant_rule_dest
} BOM_variant_rule_copy_action_t;

/**
    @name BOMLine load states
    @{
*/
#define BOM_line_loaded                         0
#define BOM_line_remote                         1
#define BOM_line_no_read_access                 2
/** @} */

/**
    @name OVE stuff
    @{
*/

/** Enum - single value */
#define BOM_OVE_ENUM_VALUE                      1

/**
   MinInc  - minimum (inclusive) value (max will be undefined )
*/
#define BOM_OVE_MIN_INC_VALUE                   2

/**
   MaxInc  - maximum (inclusive) value (min will be undefined )
*/
#define BOM_OVE_MAX_INC_VALUE                   3

/**
   Min  - minimum (exclusive) value (max will be undefined )
*/
#define BOM_OVE_MIN_VALUE                       4

/**
   Max  - maximum (exclusive) value (min will be undefined )
*/
#define BOM_OVE_MAX_VALUE                       5

/**
   Range - inclusive range from min to max
*/
#define BOM_OVE_RANGE_VALUE                     6

#define BOM_OVE_INFO                            0
#define BOM_OVE_WARN                            1
#define BOM_OVE_ERROR                           2
#define BOM_OVE_IGNORE_ALL                      9999
/** @} */

/**
    @name How Sets
    @{
*/
#define BOM_OVE_DEFAULT                         0
#define BOM_OVE_USERSET                         1
#define BOM_OVE_SET                             2
#define BOM_OVE_USERFIXED                       3
#define BOM_OVE_FIXED                           4
#define BOM_OVE_EXTERNAL                        5
#define BOM_OVE_VARIANTITEM                     6
#define BOM_OVE_LEGACY                          100
/** @} */

/**
    @name Value types
    @{
*/
#define BOM_OVE_UNSET                           0
#define BOM_OVE_BOOL                            1
#define BOM_OVE_INT                             2
#define BOM_OVE_REAL                            3
#define BOM_OVE_STRING                          4
/** @} */

/**
    The option being presented option is not from a direct child module and will have no effect
*/
#define BOM_OVE_PRES_OPTION_NOT_CHILD           0

/**
    The path to the option being presented does not lead to a child module and will have no effect
*/
#define BOM_OVE_PRES_OPTION_NO_PATH             1

/**
    The MVL on a module or node gets or sets a option that cannot be
*/
#define BOM_OVE_MODULE_MVL_OUT_OF_SCOPE_OPTION  2

/**
    Seen within this module, and therefore will have no effect
*/
#define BOM_OVE_CONDITION_OUT_OF_SCOPE_OPTION   3


/**
    @name BOM Variant Configuration Mode
    @{
*/
/** The Variant Configuration will be referenced. */
#define BOM_VARIANT_CONFIG_REF                  0

/** The Variant Configuration will be copied. */
#define BOM_VARIANT_CONFIG_COPY                 1

/** The Variant Configuration will be managed. */
#define BOM_VARIANT_CONFIG_MANAGED              2

/** The Variant Configuration will be deep copied. */
#define BOM_VARIANT_CONFIG_DEEP                 4
/** @} */

/**
    @name BOM DB SOS query operators
    @{
*/
#define BOM_DB_SOS_OP_LIKE                      0
#define BOM_DB_SOS_OP_NOT_LIKE                  1
#define BOM_DB_SOS_OP_EQ                        2
#define BOM_DB_SOS_OP_NE                        3
#define BOM_DB_SOS_OP_LT                        4
#define BOM_DB_SOS_OP_GT                        5
#define BOM_DB_SOS_OP_LTEQ                      6
#define BOM_DB_SOS_OP_GTEQ                      7
#define BOM_DB_SOS_OP_IN                        8
#define BOM_DB_SOS_OP_OUT                       9
/** @} */

/**
    @name BOM DB SOS option types
    @{
*/
#define BOM_DB_SOS_UNDEFINED_OPTION             0
#define BOM_DB_SOS_MODULAR_OPTION               1
#define BOM_DB_SOS_LEGACY_OPTION                2
/** @} */

/**
    @name BOM DB SOS value types
    @{
*/
#define BOM_DB_SOS_UNDEFINED                    0
#define BOM_DB_SOS_LOGICAL                      1
#define BOM_DB_SOS_INTEGER                      2
#define BOM_DB_SOS_DOUBLE                       3
#define BOM_DB_SOS_STRING                       4
/** @} */

/**
    @name BOM DB SOS how set
    @{
*/
#define BOM_DB_SOS_SET                          0
#define BOM_DB_SOS_FIXED                        1
#define BOM_DB_SOS_INFO                         2
/** @} */

/**
    Used by BOM_create_bomsetlines_for_input_lines
    Members :
     tag_t** bomset_lines_chain - multiple chains of bomlines as parent->lineToBeExpanded 
     int** bomset_line_chain_count - array of size counts of all chains
     int** bomset_rollup_numbers - array of child roll up counts of lineToBeExpanded
     int*  num_bomset_chains - total number of chains
*/
typedef struct BOM_bomset_input_info {
    tag_t** bomset_lines_chain; 
    int** bomset_line_chain_count;
    int** bomset_rollup_numbers;
    int*  num_bomset_chains;
} BOM_bomset_input_info_t;

/**
    Used by BOM_create_bomsetlines_for_input_lines
    Members :
     BOMSET_avl_sys_memory_limit - avaialble system memory 
     BOMSET_max_lines - maximum size a BomSet can have
     BOMSET_percent_struct_size - maximum BomSet size as % of total structure size
*/
typedef enum BOM_bomset_criteria_e {
    BOMSET_avl_sys_memory_limit           = 1,
    BOMSET_max_lines                      = 2,
    BOMSET_percent_struct_size            = 4
} BOM_bomset_criteria_t;

/**
    Used by BOM_create_bomsetlines_for_input_lines
    Members :
     criteria_type - BomSet creation criteria as value/combination of values in BOM_bomset_output_info_t 
     max_lines_in_bomset - maximum no. of lines a BomSet can have. Populte when criteria_type = BOMSET_max_lines
     percentage_struct_size_bomset - maximum BomSet size as % of total structure size.
                                      Populte when criteria_type = BOMSET_percent_struct_size  
*/
typedef struct BOM_bomset_create_criteria {
    int criteria_type;
    int max_lines_in_bomset;
    int percentage_struct_size_bomset;
} BOM_bomset_create_criteria_t;

/**
    Used by BOM_expand_bomset_lines
    Members :
     tag_t* bomset_expanded_lines - Tag array of lines expanded 
     int* bomset_expanded_line_count - size of above array
*/
typedef struct BOM_bomset_output_info {
    tag_t* bomset_expanded_lines; 
    int* bomset_expanded_line_count; 
} BOM_bomset_output_info_t;

/**
    @name BOM Variant Configuration Mode
    @{
*/
/**
    Used by #BOM_window_set_varconfig_mode and #BOM_window_ask_varconfig_mode. A BOMWindow
    can have one of three variant configuration modes.<br>
*/
typedef enum
{
    BOM_var_config_singlerule_singlevalue,  /**< Window can have a single Variant Rule allowing one value per option     */
    BOM_var_config_singlerule_multivalue,   /**< Window can have a single Variant Rule allowing one or more values per option     */
    BOM_var_config_overlay,                 /**< Window can have multiple Variant Rules allowing one or more values per option     */
    BOM_var_multiple_rule_distinct_context  /**< Support for multiple rules evaluation. If we have,  we need to evaluate each rule individually
                              except evaluation against variant condition (opcode 9). For all other scenarios the evalute will be done    */
} BOM_var_config_mode_t;


/** @} */

/**
    @name Saved Variant Rule Action Integer Values.
    Used by service operation VariantManagementImpl::getBOMVariantRules
    @{
*/
/** Value to be used in order to retrieve the variant rule from the window. */
#define VRACTION_GET_RULE  0

/** Value to be used in order to apply or add a new Saved Variant Rule in case of #BOM_var_config_overlay */
#define SVRACTION_OVERLAY_ADD_RULE  1

/** Value to be used in order to remove existing Saved Variant Rule in case of #BOM_var_config_overlay */
#define SVRACTION_OVERLAY_REMOVE_RULE  2

/** Value to be used in order to override existing BOM window Variant Rule by Saved Variant Rule in case of #BOM_var_config_singlerule_singlevalue and #BOM_var_config_singlerule_multivalue */
#define SVRACTION_OVERRIDE_RULE  3

/** Value to be used in order to update existing BOM window Variant Rule by Saved Variant Rule in case of #BOM_var_config_singlerule_singlevalue and #BOM_var_config_singlerule_multivalue */
#define SVRACTION_UPDATE_RULE  4

/** @} */


/**
   Represents a BOM Effectivity information which contains Effectivity Formula and Shared Effectivity Objects.
   It is used with #BOM_occ_effectivity_info struct to get Relative and In-Context Effectivity Information for a perticular BOM Line.
*/
typedef struct BOM_effectivity_info
{
    char *    formula;                       /**< Effectivity Formula. */
    int       n_shared_effectivity_objects;  /**< Number of Shared Effectivity objects. */ 
    tag_t *   shared_effectivity_objects;    /**< n_shared_effectivity_objects Shared Effectivity objects. */ 
} BOM_effectivity_info_t;

/**
   Represents a BOM Effectivity information for given bomline. contains Effectivity information of relative expressiona and incontext expression.
   This struct also stores the error code if any while processing the effectivity expression formula.  
*/
typedef struct BOM_occ_effectivity_info
{
    tag_t bom_line;                                /**< The BOM Line. */
    int error;                                     /**< Code for the error that occurred during the operation for a particular BOMLine.*/
    BOM_effectivity_info_t* effectivity;           /**< Effectivity information. */

} BOM_occ_effectivity_info_t;

/**
    Structure encapsulates BOM occurrence alignment. 
*/
typedef struct BOM_part_design_occurrence_alignment_data_s
{
    tag_t part_line;                  /**< Part BOM Line */
    tag_t design_line;                /**< Design BOM Line */
    tag_t part_context_line;          /**< Part Context BOM Line. If @p part_context_line is #NULLTAG, its parent BOM Line will be treated as a Part Context BOM Line.*/
    tag_t design_context_line;        /**< Design Context BOM Line. If @p design_context_line is #NULLTAG, its parent BOM Line will be treated as a Design Context BOM Line.*/
} BOM_part_design_occurrence_alignment_data_t;

/** @} */

#include <bom/libbom_undef.h>
#endif
