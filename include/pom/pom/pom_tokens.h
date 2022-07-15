/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Tokens for use in Interface functions.
*/

/** @if DOX_IGNORE
    Do not produce any #defines for macros in this file. The defines
    here are used in generating the 'filter_out_pom_tokens' mangler.

    On the Client side, com.ugsolutions.iman.kernel.IMANQueryOperator.java
    file and com.ugsolutions.iman.kernel.IMANAttribute.java files
    duplicates operators that are defined in this file to be used on the
    Client side. If any changes ( modifications to existing tokens or adding
    new ones ) are made to this file, please make sure that you change those
    files accordingly too otherwise inconsistent search results may be
    obtained.
@endif */

/*  */

#ifndef POM_TOKENS_H_INCLUDED
#define POM_TOKENS_H_INCLUDED

#include <common/tc_deprecation_macros.h>

/** @if DOX_IGNORE
    Token definitions
    If you add a new token, please alter pom_token_conversion.c appropriately
    otherwise POM_describe_token won't recognise the new one.
@endif */

/**
    @defgroup POM_TOKENS Tokens
    @ingroup POM
    This section contains a complete list of the tokens that can be handed to,
    or returned by, a POM function.

    Conjunction Tokens (for combining enquiries):

    #POM_and <br>
    #POM_nand <br>
    #POM_nor <br>
    #POM_or <br>

    Type Tokens (for attributes):

    #POM_char <br>
    #POM_date <br>
    #POM_double <br>
    #POM_float <br>
    #POM_int <br>
    #POM_logical <br>
    #POM_short <br>
    #POM_string <br>
    #POM_typed_reference <br>
    #POM_untyped_reference <br>
    #POM_external_reference <br>
    #POM_note
    #POM_long_string

    Switch Tokens (for setting environment)

    #POM_ds_checking_switch <br>
    #POM_rollback_switch <br>
    #POM_arg_checking_switch <br>
    #POM_journaling_switch <br>
    #POM_error_traceback_switch <br>
    #POM_log_sql_switch <br>
    #POM_timeout_strategy <br>
    #POM_timeout_interval <br>
    #POM_enable_set_attr_callbacks<br>
    #POM_timeout_strategy_flat <br>
    #POM_timeout_strategy_linear <br>
    #POM_timeout_strategy_exp
    #POM_check_space_uniqueness_switch <br>

    Attribute Tokens (for attribute properties) These can be added to combine properties.

    #POM_has_initial_value <br>
    #POM_has_lowerbound <br>
    #POM_has_upperbound <br>
    #POM_is_classvariable <br>
    #POM_is_unique <br>
    #POM_is_unique <br>
    #POM_null_is_valid <br>
    #POM_cannot_be_frozen <br>
    #POM_public_read <br>
    #POM_public_write <br>
    #POM_public

    Operator Tokens (for building enquiries)

    #POM_is_equal_to <br>
    #POM_is_greater_than <br>
    #POM_is_less_than <br>
    #POM_is_null <br>
    #POM_is_like <br>
    #POM_is_referenced_by <br>
    #POM_has_reference_to <br>
    #POM_not <br>
    #POM_case_insensitive

    Order Tokens (for specifying the order of the result of an enquiry)

    #POM_order_ascending <br>
    #POM_order_descending

    Class Tokens (for class properties). These can be added to combine properties.

    #POM_uninstantiable_class <br>
    #POM_uninheritable_class

    Where-to-Search Tokens (for referencers_of_instance)

    #POM_in_ds_only <br>
    #POM_in_db_only <br>
    #POM_in_ds_and_db

    Attribute Array Type Tokens

    #POM_large_array <br>
    #POM_small_array <br>
    #POM_variable_length_array <br>
    #POM_non_array <br>
    #POM_any_array

    Data Conversion Tokens

    #POM_gmt_to_local <br>
    #POM_local_to_gmt

    @{
*/

/**
    @name Type tokens for attributes
    @{
*/
#define POM_MIN_type_token                  2001
#define POM_char                            2001
#define POM_date                            2002
#define POM_double                          2003
#define POM_float                           2004
#define POM_int                             2005
#define POM_logical                         2006
#define POM_short                           2007
#define POM_string                          2008
#define POM_typed_reference                 2009
#define POM_untyped_reference               2010
#define POM_external_reference              2011
#define POM_note                            2012
#define POM_long_string                     2013
#define POM_MAX_type_token                  2013
/** @} */

/**
    @name Switch tokens for setting environment
    @{
*/
#define POM_MIN_env_token                   3001
#define POM_ds_checking_switch              3001
#define POM_rollback_switch                 3002
#define POM_arg_checking_switch             3003
#define POM_journaling_switch               3004
#define POM_error_traceback_switch          3005
#define POM_log_sql_switch                  3006
#define POM_timeout_strategy                3007
#define POM_timeout_interval                3008
#define POM_bypass_access_check             3010
#define POM_bypass_attr_update              3011
#define POM_wildcard_character_any          3012
#define POM_wildcard_character_one          3013
#define POM_transmit_directory              3014
#define POM_import_mode                     3015
#define POM_import_to_user                  3016
#define POM_import_to_group                 3017
#define POM_disable_api                     3018
#define POM_escape_character                3019
#define POM_update_timestamp                3020
#define POM_enable_set_attr_callbacks       3021

/** @deprecated #POM_check_private_uniqueness_switch deprecated in Teamcenter 11.2.3. Use #POM_check_space_uniqueness_switch instead. */
#define POM_check_private_uniqueness_switch   3022
TC_DEPRECATED_PREPROCESSOR( "11.2.3", POM_check_private_uniqueness_switch, "POM_check_space_uniqueness_switch" )

#define POM_check_space_uniqueness_switch   3022
#define POM_MAX_env_token                   3022

#define POM_MIN_timeout_strategy            4000
#define POM_timeout_strategy_none           4000
#define POM_timeout_strategy_flat           4001
#define POM_timeout_strategy_linear         4002
#define POM_timeout_strategy_exp            4003
#define POM_timeout_strategy_count          4004
#define POM_MAX_timeout_strategy            4004
/** @} */

/**
    @name Attribute tokens for attribute properties

    These may be added; note there is no MIN or MAX, but SUM = all-bits-set.
    @{
*/
#define POM_has_initial_value               ( 1 << 0 )
#define POM_has_lowerbound                  ( 1 << 1 )
#define POM_has_upperbound                  ( 1 << 2 )
#define POM_is_classvariable                ( 1 << 3 )
#define POM_is_unique                       ( 1 << 5 )
#define POM_null_is_valid                   ( 1 << 6 )
#define POM_cannot_be_frozen                ( 1 << 7 )
#define POM_public_read                     ( 1 << 8 )
#define POM_public_write                    ( 1 << 9 )
#define POM_transient                       ( 1 << 10 )
#define POM_attr_is_candidate_key           ( 1 << 11 )
#define POM_attr_follow_on_export           ( 1 << 12 )
#define POM_attr_export_as_string           ( 1 << 13 )
#define POM_attr_ignore_export_errors       ( 1 << 14 )
#define POM_attr_may_not_be_stubbed         ( 1 << 15 )
#define POM_attr_no_pom_backpointer         ( 1 << 16 )
#define POM_attr_prop_optional              ( 1 << 17 )
#define POM_public                          ( POM_public_read | POM_public_write )
#define POM_SUM_attr_tokens                                                     \
        ( POM_has_initial_value | POM_has_lowerbound | POM_has_upperbound |     \
        POM_is_classvariable | POM_is_unique |                                  \
        POM_null_is_valid | POM_cannot_be_frozen | POM_public | POM_transient | \
        POM_attr_is_candidate_key | POM_attr_follow_on_export |                 \
        POM_attr_export_as_string | POM_attr_no_pom_backpointer | POM_attr_prop_optional )
/** @} */

/**
    @name Bit flags for the bit mask attribute on POM object

    These may be added; note there is no MIN or MAX, but SUM = all-bits-set.
    @{
*/
#define POM_object_mask_frozen              ( 1 << 0 )
#define POM_object_mask_has_ixr             ( 1 << 1 )
#define POM_object_mask_is_locked           ( 1 << 2 )

/** @deprecated #POM_object_mask_not_changed deprecated in Teamcenter 11.2.3. */
#define POM_object_mask_not_changed         ( 1 << 3 )
TC_DEPRECATED_PREPROCESSOR( "11.2.3", POM_object_mask_not_changed, "" )

#define POM_object_mask_is_bulkcheckedout   ( 1 << 4 )
#define POM_object_mask_has_ds              ( 1 << 5 )

#define POM_SUM_object_tokens                                                     \
        ( POM_object_mask_frozen | POM_object_mask_has_ixr | POM_object_mask_is_locked | \
        POM_object_mask_is_bulkcheckedout | POM_object_mask_has_ds )

/** @} */

/**
@name Operator tokens for building enquiries ( to be used with ITK POM_create_enquiry/POM_old_create_enquiry...) but not with POM_enquiry_xxxx ITK.
@{
*/
#define POM_not                             ( 1 << 0 )
#define POM_and                             ( 1 << 1 )
#define POM_or                              ( 1 << 2 )
#define POM_is_equal_to                     ( 1 << 3 )
#define POM_is_greater_than                 ( 1 << 4 )
#define POM_is_less_than                    ( 1 << 5 )
#define POM_is_null                         ( 1 << 6 )
#define POM_is_like                         ( 1 << 7 )
#define POM_has_reference_to                ( 1 << 8 )
#define POM_is_referenced_by                ( 1 << 9 )
#define POM_case_insensitive                ( 1 << 10 )
#define POM_contains                        ( 1 << 11 )
#define POM_contains_lt                     ( 1 << 15 )
#define POM_contains_gt                     ( 1 << 16 )
#define POM_contains_between                ( 1 << 17 )
#define POM_contains_like                   ( 1 << 18 )
#define POM_array_length_equals             ( 1 << 19 )
#define POM_tonumber                        ( 1 << 20 )

/** @if DOX_IGNORE
    Tokens from ( 1 << 21 ) to ( 1 << 26 ) have been defined in
    /vobs/src/rdv/code/rdv_tokens.h file.
    Please define new tokens from 1 << 27 onwards.
@endif */

#define POM_nand                            ( POM_not | POM_and )
#define POM_nor                             ( POM_not | POM_or )
#define POM_is_not_equal_to                 ( POM_not | POM_is_equal_to )
#define POM_is_not_greater_than             ( POM_not | POM_is_greater_than )
#define POM_is_not_less_than                ( POM_not | POM_is_less_than )
#define POM_is_not_null                     ( POM_not | POM_is_null )
#define POM_is_not_like                     ( POM_not | POM_is_like )
#define POM_contains_other_than             ( POM_not | POM_contains )
#define POM_contains_not_like               ( POM_not | POM_contains_like )
#define POM_contains_not_gt                 ( POM_not | POM_contains_gt )
#define POM_contains_not_lt                 ( POM_not | POM_contains_lt )
#define POM_contains_not_between            ( POM_not | POM_contains_between )
#define POM_array_length_not_equals         ( POM_not | POM_array_length_equals )

#define POM_SUM_operator_tokens                                                         \
        ( POM_not | POM_and | POM_or | POM_is_equal_to | POM_is_greater_than |          \
        POM_is_less_than | POM_is_null | POM_is_like | POM_has_reference_to |           \
        POM_is_referenced_by | POM_case_insensitive | POM_contains |                    \
        POM_contains_lt | POM_contains_gt | POM_contains_between | POM_contains_like |  \
        POM_array_length_equals | POM_tonumber)
/** @} */

/**
    @name Date conversion tokens
    @{
*/
#define POM_MIN_date_conversion_token       6001
#define POM_gmt_to_local                    6001
#define POM_local_to_gmt                    6002
#define POM_MAX_date_conversion_token       6002
/** @} */

/**
    @name Instance state tokens
    @{
*/
#define POM_MIN_instance_state_token        7001
#define POM_inst_is_not_loaded              7001
#define POM_inst_is_loaded                  7002
#define POM_inst_is_loaded_for_modify       7003
#define POM_inst_is_new                     7004
#define POM_inst_is_modified                7005
#define POM_inst_is_selected                7006
#define POM_inst_is_selected_modified       7007
#define POM_inst_is_being_deleted           7008
#define POM_MAX_instance_state_token        7008
/** @} */

/**
    @name Order tokens

    For specifying the order of the result of an enquiry
    @{
*/
#define POM_MIN_order_token                 8001
#define POM_order_ascending                 8001
#define POM_order_descending                8002
#define POM_order_ascending_asnumber        8003
#define POM_order_descending_asnumber       8004
#define POM_MAX_order_token                 8004
/** @} */

/** @if DOX_IGNORE
    Class tokens (for class properties)
    These may be added; note there is no MIN or MAX, but SUM = all-bits-set.
    (MSF) 08-Dec-1993 BE WARNED!!! POM_class_is_exportable is the highest
    bit in a 32-bit word - if you want to add any more class tokens, use
    lower bits!
@endif */

/**
    @name Class tokens for class properties
    @{
*/
/**
Note:- Bits 0x01000000, 0x02000000 and 0x04000000 are used by other tokens.
*/
#define POM_uninstantiable_class            0x10000000
#define POM_uninheritable_class             0x20000000
#define POM_class_requires_sa               0x40000000
#define POM_class_is_exportable             0x80000000
#define POM_class_is_versionable            0x00200000
#define POM_can_have_versionable_subclasses 0x00800000
#define POM_class_prop_has_flat_tables      0x00010000
#define POM_class_not_referenceable         0x00400000

/* Deprecated: These tokens are deprecated and will be removed in tc12. Replaced by POM_class_is_versionable etc */
#define POM_class_is_revisable              0x00200000
#define POM_can_have_revisable_subclasses   0x00800000

#define POM_SUM_class_tokens                0xf0e10000



/** @} */

/** @if DOX_IGNORE
    Action tokens (for auditing)
    (There aren't any of these yet so we set MIN > MAX
    to avoid recognising any!)
@endif */

#define POM_MIN_action_token                1
#define POM_MAX_action_token                0

/**
    @name Where_to_search tokens for referencers_of_instance
    @{
*/
#define POM_MIN_search_token                9001
#define POM_in_ds_only                      9001
#define POM_in_db_only                      9002
#define POM_in_ds_and_db                    9003
#define POM_MAX_search_token                9003
/** @} */

/**
    @name Attribute array type tokens for generating sql
    @{
*/
#define POM_MIN_array_type_token            0x01000000
#define POM_large_array                     0x01000000
#define POM_small_array                     0x02000000
#define POM_variable_length_array           0x04000000
#define POM_non_array                       0x08000000
#define POM_any_array       (POM_large_array | POM_small_array | POM_variable_length_array)
#define POM_SUM_array_type_token            (POM_any_array | POM_non_array)
#define POM_MAX_array_type_token            0x08000000
/** @} */

/**
    @name Lock type tokens
    @{
*/
#define POM_MIN_lock_type_token             0
#define POM_no_lock                         0
#define POM_modify_lock                     1
#define POM_read_lock                       2
#define POM_delete_lock                     3
#define POM_MAX_lock_type_token             3
/** @} */

/**
    @name Space type tokens
    @{
*/
#define POM_MIN_space_type_token            0
#define POM_space_markup                    0
#define POM_space_change                    1
#define POM_space_staging                   2
#define POM_MAX_space_type_token            2


/** @deprecated #POM_space_non_exclusive deprecated in Teamcenter 11.3. Use #POM_space_markup instead. */
#define POM_space_non_exclusive             0
TC_DEPRECATED_PREPROCESSOR( "11.3", POM_space_non_exclusive, "POM_space_markup" )

/** @deprecated #POM_space_exclusive deprecated in Teamcenter 11.3. Use #POM_space_change instead. */
#define POM_space_exclusive                 1
TC_DEPRECATED_PREPROCESSOR( "11.3", POM_space_exclusive, "POM_space_change" )

/** @deprecated #POM_space_private deprecated in Teamcenter 11.2.3. */
#define POM_space_private                   2
TC_DEPRECATED_PREPROCESSOR( "11.2.3", POM_space_private, "" )

/** @} */

/**
    @name tokens for reasons for losing locks
    @{
*/
#define POM_MIN_lost_lock_token             0
#define POM_lost_lock_session_gone          0
#define POM_lost_lock_session_killed        1
#define POM_lost_lock_stolen                2
#define POM_lost_lock_dont_know             3
#define POM_MAX_lost_lock_token             3
/** @} */

/**
    @name Auditable action tokens
    @{
*/
#define POM_AUDIT_purge_audit               "POM_AUDIT_purge_audit"
#define POM_AUDIT_bad_password_login        "POM_AUDIT_bad_password_login"
#define POM_AUDIT_bad_password_check        "POM_AUDIT_bad_password_check"
#define POM_AUDIT_change_password           "POM_AUDIT_change_password"
/** @} */

/**
    @name Machine type tokens
    @{
*/
#define POM_MIN_machine_token               10001
#define POM_UNKNOWN                         10001
#define POM_APOLLO                          10002
#define POM_VAX                             10003
#define POM_HP_68K                          10004
#define POM_HP_RISC                         10005
#define POM_SUN_68K                         10006
#define POM_SUN_SPARC                       10007
#define POM_DEC_5000                        10008
#define POM_DEC_ALPHA_OSF                   10009
#define POM_DEC_ALPHA_VMS                   10010
#define POM_SGI                             10011
#define POM_IBM_MVS                         10012
#define POM_IBM_RS6000                      10013
#define POM_DEC_ALPHA_NT                    10014
#define POM_INTEL_NT                        10015
#define POM_MAX_machine_token               10015
/** @} */

/**
    @name Schema conversion tokens
    @{
*/
#define POM_MIN_conv_class_token            11001
#define POM_conv_class_changed              11001
#define POM_conv_class_removed              11002
#define POM_MAX_conv_class_token            11002

#define POM_MIN_conv_attr_token             12001
#define POM_conv_attr_new                   12001
#define POM_conv_attr_removed               12002
#define POM_MAX_conv_attr_token             12002
/** @} */

/**
    @name Import ownership tokens
    @{
*/
#define POM_MIN_import_token                13001
#define POM_import_raise_error              13001
#define POM_import_always_map               13002
#define POM_import_default_to_map           13003
#define POM_import_default_to_current       13004
#define POM_import_default_as_apt           13005
#define POM_MAX_import_token                13005
/** @} */

/**
    @name POM_site_config_file tokens
    @{
*/
#define POM_site_config_file_preferences    1
#define POM_site_config_file_overlay        2
#define POM_site_config_file_definition     3
#define POM_site_config_definition_runtime  4
/** @} */

/**
@name Operator tokens for building new enquiries( ITK provided in enq.h POM_enquiry_xxx). These operator cannot use logical '|' and cannot be combined.
@{
*/
#define POM_enquiry_asc_order               0
#define POM_enquiry_desc_order              1
#define POM_enquiry_const_value             0
#define POM_enquiry_bind_value              1
/** @} */

/**
    @name Logical operators
    @{
*/
#define POM_enquiry_not                     14000
#define POM_enquiry_and                     14001
#define POM_enquiry_and_filter              14002
#define POM_enquiry_or                      14003
/** @} */

/**
    @name Comparative operators
    @{
*/
#define POM_enquiry_equal                   15000
#define POM_enquiry_greater_than            15001
#define POM_enquiry_greater_than_or_eq      15002
#define POM_enquiry_less_than               15003
#define POM_enquiry_less_than_or_eq         15004
#define POM_enquiry_not_equal               15005
#define POM_enquiry_not_between             15006
#define POM_enquiry_between                 15007

#define POM_enquiry_join                    15008
#define POM_enquiry_left_outer_join         15009
#define POM_enquiry_right_outer_join        15010
#define POM_enquiry_full_outer_join         15011

#define POM_enquiry_nvl                     15012
/** @} */

/**
    @name Unary operators
    @{
*/
#define POM_enquiry_is_null                 15500
#define POM_enquiry_is_not_null             15502
/** @} */

/**
    @name wild_card_operator
    @{
*/
#define POM_enquiry_like                    16001
#define POM_enquiry_not_like                16002
/** @} */

/**
    @name list_operators
    @{
*/
#define POM_enquiry_in                      16501
#define POM_enquiry_not_in                  16502
/** @} */

/**
    @name existantial_operator
    @{
*/
#define POM_enquiry_exists                  17001
#define POM_enquiry_not_exists              17002
/** @} */

/**
    @name vla_operators
    @{
*/
#define POM_enquiry_contains                17501
#define POM_enquiry_contains_lt             17502
#define POM_enquiry_contains_gt             17503
#define POM_enquiry_contains_between        17504
#define POM_enquiry_contains_like           17505
#define POM_enquiry_contains_other_than     17506
#define POM_enquiry_contains_not_like       17507
#define POM_enquiry_contains_not_gt         17508
#define POM_enquiry_contains_not_lt         17509
#define POM_enquiry_contains_not_between    17510
/** @} */

/**
    @name set_operators
    @{
*/
#define POM_enquiry_union                   18001
#define POM_enquiry_unionall                18002
#define POM_enquiry_difference              18003
#define POM_enquiry_intersection            18004
/** @} */

/**
    @name string_function
    @{
*/
#define POM_enquiry_substr                  18500
#define POM_enquiry_ltrim                   18501
#define POM_enquiry_rtrim                   18502
#define POM_enquiry_concat                  18503
#define POM_enquiry_ascii                   18504
#define POM_enquiry_lower                   18505
#define POM_enquiry_upper                   18506
#define POM_enquiry_length                  18507
/** @} */

/**
    @name Aggregate function
    @{
*/
#define POM_enquiry_max                     19000
#define POM_enquiry_min                     19001
#define POM_enquiry_sum                     19002
#define POM_enquiry_avg                     19004

#define POM_enquiry_count                   19300
#define POM_enquiry_countall                19301
#define POM_enquiry_countdist               19302
/** @} */

/**
    @name Conversion function
    @{
*/
#define POM_enquiry_tonumber                19500
#define POM_enquiry_tc_to_number            19501
#define POM_enquiry_todate                  19502
/** @} */

/**
    @name Arithmetic operators
    @{
*/
#define POM_enquiry_plus                    19800
#define POM_enquiry_minus                   19801
#define POM_enquiry_multiply                19802
#define POM_enquiry_divide                  19803
#define POM_enquiry_mod                     19804
/** @} */

#define POM_enquiry_uid_of                  19900
#define POM_enquiry_cpid_of                 19901
#define POM_array_length_lt                 19903
#define POM_array_length_gt                 19904
#define POM_array_length                    19905

/**
    @name Procedure argument tokens
    @{
*/
#define POM_MIN_procedure_arg_token         20001
#define POM_proc_mode_in                    20001
#define POM_proc_mode_out                   20002
#define POM_proc_mode_inout                 20003
#define POM_MAX_procedure_arg_token         20003
/** @} */

/**
    @name Custom function
    @{
*/
#define POM_enquiry_configure_eblck         20101
#define POM_enquiry_configure_cnf           20102
/** @} */

/**
    @name Functional index tokens.
    @{
*/
#define POM_index_func_upper            "UPPER"
#define POM_index_func_substr           "SUBSTR"
#define POM_index_func_coalesce         "COALESCE"
/** @} */

/**
    Sponsored user login defines.
*/
#define POM_sponsor_group       "Sponsor"
#define POM_SPONSORABLE 1
#define POM_SPONSORABLE_OFF 0
/**
    @name Site flag tokens.
    @{
*/
/**
    Token to represent ODS site
*/
#define POM_site_ODS                    ( 1 << 1 )
/**
    Token to represent Hub site
*/
#define POM_site_Hub                    ( 1 << 2 )
/**
    Token to represent Http site
*/
#define POM_site_Http                   ( 1 << 3 )
/**
    Token to represent tcxml site
*/
#define POM_site_TCXML                  ( 1 << 4 )
/**
    Token to represent offline site
*/
#define POM_site_Offline                ( 1 << 5 )
/**
    Token to represent master delete allowed
*/
#define POM_site_master_delete_allowed  ( 1 << 6 )
/**
    Token to represent unmanaged site
*/
#define POM_site_unmanaged              ( 1 << 7 )
/**
    Token to represent application type
*/
#define POM_site_external_application   ( 15 << 8 )
/**
    Token to represent unknown site
*/
#define POM_site_unknown                ( 1 << 12 )
/**
    Token to represent test environment
*/
#define POM_site_test_env               ( 1 << 13 )

/**
    Token to represent archive site
*/
#define POM_site_archive               ( 1 << 14 )

/**
    Token to represent unmanaged briefcase browser site
*/
#define POM_briefcase_browser          ( 1 << 15 )

/**
    Token to represent unmanaged biefcase browser with plugin site
*/
#define POM_briefcase_browser_with_plugin ( 1 << 16 )

/** @} */

/** @} */

#endif
