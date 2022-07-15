/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    External header file containing constants and data structures for
    Product Data Interface (PDI) module. This file is included by pdi.h
*/

/*  */

#ifndef PDI_H_EXTERNAL
#define PDI_H_EXTERNAL

#ifdef __lint
#pragma uginclude only_in_error "pdi.h";
#endif

/**
    Has definition for Read, Write access - 'mode' parameter in PDI calls
*/
#if !WNT
    #include <unistd.h>
#endif

/**
    @defgroup PDI Product Data Interface
    @ingroup NXMGR
    @{
*/

/**
    @name PDI equivalents

    For values used when calling the unix access function
    @{
*/

/** Is it writable by caller */
#define PDI_W_OK                        2

/** Is it readable by caller */
#define PDI_R_OK                        4

/** @} */

#include <common/emh_const.h>
#include <nxmgr_im/libnxmgr_im_exports.h>

#define PDI_return_code_t               int

#define PDI_ok                          0

/** General failure error */
#define PDI_fail                        EMH_API_error_base

/** General RPC error */
#define PDI_rpc_fail                    EMH_API_error_base + 1

/** No objects found */
#define PDI_null                        EMH_API_error_base + 2

/** Bad tag as input */
#define PDI_invalid_tag                 EMH_API_error_base + 3

/** Access denied */
#define PDI_access_denied               EMH_API_error_base + 4

/** Trying to create an object with same id. */
#define PDI_object_exists               EMH_API_error_base + 5

/** Problems with logging into PDM */
#define PDI_login_failed                EMH_API_error_base + 6

/** PDM internal error */
#define PDI_pdm_internal                EMH_API_error_base + 7

/** Functionality not implemented */
#define PDI_not_implemented             EMH_API_error_base + 8

/** Object may not be modified */
#define PDI_read_only                   EMH_API_error_base + 9

/** Object is locked already */
#define PDI_object_locked               EMH_API_error_base + 10

/** Caller is not object locker */
#define PDI_not_locker                  EMH_API_error_base + 11

/** Object is not locked */
#define PDI_object_not_locked           EMH_API_error_base + 12

/** Delay return from this routine */
#define PDI_call_block                  EMH_API_error_base + 13

/** Invalid role name for encap GS */
#define PDI_invalid_role                EMH_API_error_base + 14

/** Unable to create export directory */
#define PDI_unable_to_create_dir        EMH_API_error_base + 15

/** Export directory does not exist */
#define PDI_no_export_directory         EMH_API_error_base + 16

/** Import fails to bring in files */
#define PDI_import_files_fail           EMH_API_error_base + 17

/** Deletion of the exported stuff fails */
#define PDI_cancel_export_fail          EMH_API_error_base + 18

/** Deletion of the exported stuff fails */
#define PDI_remove_export_dir_fail      EMH_API_error_base + 19

/** Copy files from old appdata to new one fails */
#define PDI_copy_appdata_fail           EMH_API_error_base + 20

/** Object Name cannot be set to a null value */
#define PDI_null_input_string           EMH_API_error_base + 21

/** Failure in database user exit called from PDI */
#define PDI_user_exit_failure           EMH_API_error_base + 22

/** Object has been deleted */
#define PDI_object_deleted              EMH_API_error_base + 23

/** No clipboard is available */
#define PDI_no_clipboard                EMH_API_error_base + 24

/** The Teamcenter Engineering attribute has no value */
#define PDI_attr_has_no_value           EMH_API_error_base + 25

/** The mapping cannot be resolved for the object */
#define PDI_invalid_mapping_for_object  EMH_API_error_base + 26

/** The object has been modified by some other process since we loaded it */
#define PDI_modified_elsewhere          EMH_API_error_base + 27

/** Not licensed to perform the function */
#define PDI_not_licensed                EMH_API_error_base + 28

/** @if DOX_IGNORE
    szheng 10-Feb-2000: dated revision rules
@endif */
#define PDI_invalid_date_format         EMH_API_error_base + 29

/** The object has already been added, e.g. when inserting into a folder */
#define PDI_object_already_added        EMH_API_error_base + 30

/** @if DOX_IGNORE
    szheng 14-Jul-2000: pr604226
@endif */
#define PDI_rdbms_error                 EMH_API_error_base + 31

#define PDI_foreign_object              EMH_API_error_base + 32

/** @if DOX_IGNORE
    (x_vivek) 18-Jul-2003 For Appuid NR in Alt-IDs proj
@endif */
#define PDI_more_than_one_objects       EMH_API_error_base + 33

/** @if DOX_IGNORE
    (RAB) 22-Jan-2004: ForAssy - Invalid TCEng preference scope given
@endif */
#define PDI_invalid_pref_scope          EMH_API_error_base + 34

/** @if DOX_IGNORE
    (x_tiruna) 24-Nov-2005 NXMGR Remote Checkout   
    if Remote Item is not checked out 
@endif */
#define PDI_remote_item_not_co          EMH_API_error_base + 35

/** @if DOX_IGNORE
 (x_tiruna) 24-Nov-2005 NXMGR Remote Checkout 
 If the given object is not remote
@endif */
#define PDI_not_remote                  EMH_API_error_base + 36

/** server disconnected or time out */
#define PDI_server_disconnected   EMH_API_error_base + 37

/** @if DOX_IGNORE
    <x_tiruna>:07-Dec-2006: Fix PR#5651823 ,PR#PR#5558583
                This indicates that the Item is already  registered
@endif */
#define PDI_item_already_registered     EMH_API_error_base + 38

/** Last used error token */
#define PDI_unused_error                EMH_API_error_base + 39


/** @if DOX_IGNORE
    (PDH) 28-Jun-96
    These error numbers are specific to TC. The NX half should not attempt to
    register text for them. At present the TC half does not either so when these are
    passed back, the NX half gets PDI_pdm_internal as the error code, then the
    explanation that TC provides is the text that went into the ERROR_raise. We
    could add text registration in the TC half at some point.
@endif */

#define PDI_tc_error_base             EMH_API_error_base + 1000

/** TC_NX_View_Type not present in pref file (pdi_im_rep.c) */
#define PDI_im_no_nx_view_type          PDI_tc_error_base + 1

/** Volume is full */
#define PDI_volume_full                 PDI_tc_error_base + 2

/** Cannot contact Tcfs */
#define PDI_tcfs_error                  PDI_tc_error_base + 3

/**
    @name Class IDs
    @{
*/
#define PDI_class_t                     int
#define PDI_class_p_t                   int*

#define PDI_none_class                  0
#define PDI_part_class                  1
#define PDI_partrev_class               2
#define PDI_rep_class                   3
#define PDI_reprev_class                4
#define PDI_appdata_class               5
#define PDI_appver_class                6
#define PDI_container_class             7
#define PDI_component_class             8
#define PDI_attribute_class             9
#define PDI_apptype_class               10
#define PDI_reltype_class               11
#define PDI_parttype_class              12
#define PDI_attr_mapping_class          13
#define PDI_lov_class                   14
#define PDI_opaque_object_class         15
#define PDI_unused_class                16
#define PDI_CLASS_COUNT                 17
/** @} */

/**
    @name File formats in Application Data Versions
    @{
*/
#define PDI_appver_format_t             int
#define PDI_appver_format_p_t           int*

#define PDI_none_format                 0
#define PDI_ascii_format                1
#define PDI_binary_format               2
#define PDI_unused_format               3
#define PDI_APPVER_FORMAT_COUNT         4
/** @} */

#ifdef __cplusplus
 extern "C"{
#endif

/**
    Corresponding names of format. Initialized in pdi_utils.c
*/
extern NXMGR_IM_API char* PDI_format_name(
    int                   format
    );

#ifdef __cplusplus
    }
#endif

/**
    @name Supported Machine types
    @{
*/
#define PDI_machine_type_t              int

#define PDI_none_machine_type           0
#define PDI_unix                        1
/** @if DOX_IGNORE
        PDI_vms                         2
@endif */
#define PDI_wnt                         3
#define PDI_unused_machine_type         4
#define PDI_MACHINE_TYPE_COUNT          5
/** @} */

/**
    @name Network Transports supported by RPC
    @{
*/
#define PDI_transport_t                 int

#define PDI_none_transport              0
#define PDI_sys5_msg                    1
#define PDI_tcpip                       2
#define PDI_sockets                     3
#define PDI_tc_ss                     4
/** @if DOX_IGNORE
        PDI_vms_mbx                     5
@endif */
#define PDI_unused_transport            6
#define PDI_TRANSPORT_COUNT             7
/** @} */

/**
    @name Possible values for lock status

    Returned by PDI_ask_appdata_lock_status()
    @{
*/
#define PDI_lock_status_t               int

#define PDI_not_locked                  0
#define PDI_locked_by_caller            1
#define PDI_locked_by_other             2
#define PDI_locked_and_exported         3
#define PDI_checked_out                 4
/** @} */

/**
    @name States of part number validity

    Returned from PDI_validate_part_rev_id()
    @{
*/
#define PDI_partno_validity_t           int

#define PDI_partno_valid                0
#define PDI_partno_invalid              1
#define PDI_partno_modified             2

/** @if DOX_IGNORE
    (Anurag) 30-Jun-1999 Fix for PR#1003853
@endif */
#define PDI_partno_override             3
/** @} */

/**
    @name Constants for use by the operations functions and their callers
    @{
*/
#define PDI_operation_ok                0
#define PDI_operation_failed            1

#define PDI_nx_load_operation           "Unigraphics Part Load"
#define PDI_nx_load_operation_NX3       "Part Load"
/** @} */

/**
    @name Bitmask for PDI_forget_var_configs
    @{
*/
#define PDI_DISPLAYED_PART_ROLE         ( 1 << 0 )
#define PDI_PROD_ASSY_ROLE              ( 1 << 1 )
/** @} */

/**
    @name Tokens for the PDI search functions
    @{
*/
#define PDI_SEARCH_FIND_MORE            0
#define PDI_SEARCH_FIND_ALL             -1

#define PDI_SEARCH_CONTEXT_ALL          0
#define PDI_SEARCH_CONTEXT_INFO         1
/** @} */

/**
    These correspond directly to TC's #LOV_usage_t.
*/
typedef enum
{
    PDI_LOV_unknown,
    PDI_LOV_exhaustive,
    PDI_LOV_suggested,
    PDI_LOV_bounded
} PDI_LOV_usage_t;

/**
    Values describing value types supported by attribute-synchronisation.
*/
typedef enum
{
    PDI_int_value,
    PDI_double_value,
    PDI_string_value,
    PDI_date_value,
    PDI_tag_value,
    PDI_logical_value,
    PDI_unknown_value,
    PDI_unsupported_value,
    PDI_strings_value
} PDI_value_t;

/**
    @name Flags

    Indicate which mass properties are actually specified for AppData objects
    @{
*/

/** An indication of how accurrately the values were calculated */
#define PDI_masspr_accuracy_defined     (1 << 0)

/** The Mass (and corresponding error) is defined */
#define PDI_masspr_mass_defined         (1 << 1)

/** The Volume (and corresponding error) is defined */
#define PDI_masspr_volume_defined       (1 << 2)

/** The Density is defined */
#define PDI_masspr_density_defined      (1 << 3)

/** The Surface Area (and corresponding error) is defined */
#define PDI_masspr_area_defined         (1 << 4)

/** The Center Of Mass vector [X,Y,Z] (and its error distance) is defined */
#define PDI_masspr_com_defined          (1 << 5)

/**
    Both the Moments Of Inertia [XX, YY, ZZ] and Products Of Inertia
    [XY, XZ, YZ] are defined (with its error range)
*/
#define PDI_masspr_inertia_defined      (1 << 6)

/** The minimum allowable mass for this part is defined */
#define PDI_masspr_min_mass_defined     (1 << 7)

/** The maximum allowable mass for this part is defined */
#define PDI_masspr_max_mass_defined     (1 << 8)
/** @} */

/**
    @name Indexes

    For the order in which the Mass Property values are passed
    @{
*/
#define PDI_masspr_accuracy_index       0
#define PDI_masspr_mass_index           1
#define PDI_masspr_mass_err_index       2
#define PDI_masspr_volume_index         3
#define PDI_masspr_volume_err_index     4
#define PDI_masspr_area_index           5
#define PDI_masspr_area_err_index       6
#define PDI_masspr_density_index        7
#define PDI_masspr_com_x_index          8
#define PDI_masspr_com_y_index          9
#define PDI_masspr_com_z_index         10
#define PDI_masspr_com_err_index       11
#define PDI_masspr_moi_xx_index        12
#define PDI_masspr_moi_yy_index        13
#define PDI_masspr_moi_zz_index        14
#define PDI_masspr_poi_xy_index        15
#define PDI_masspr_poi_xz_index        16
#define PDI_masspr_poi_yz_index        17
#define PDI_masspr_inertia_err_index   18
#define PDI_masspr_min_mass_index      19
#define PDI_masspr_max_mass_index      20

#define PDI_MASSPR_ARRAY_SIZE          21
/** @} */

/**
    @name Prototypes and global variables

    For error handling system in PDI module interface
    @{
*/

typedef PDI_return_code_t (*PDI_error_handler_t)(
    const char*             function_name,
    const PDI_return_code_t code
    );

#ifdef __cplusplus
 extern "C"{
#endif

extern NXMGR_IM_API void PDI_set_error_handler(
    PDI_error_handler_t  handler
    );

extern NXMGR_IM_API void PDI_allow_no_errors(void);

extern NXMGR_IM_API void PDI_allow_selected_errors(
    const int               error_count,
    const PDI_return_code_t errors[]
    );

extern NXMGR_IM_API void PDI_allow_all_errors(void);

/** @} */

/**
    @name Initialization routines for client and server processes
    @{
*/

typedef void (*PDI_input_callback_proc)(
    void*,        /**< (I) User defined data object */
    int*,         /**< (I) A file descriptor used in 'select' */
    void**        /**< (I) Returned from add input func */
    );

typedef void* (*PDI_add_input_func_t)(
    void*,                      /**< (I) (Motif) application context */
    int,                        /**< (I) A file descriptor used in 'select' */
    void*,                      /**< (I) Event type that triggers callback */
    PDI_input_callback_proc,    /**< (I) Routine to be called on event */
    void*                       /**< (I) User defined data object */
    );

typedef void (*PDI_remove_input_func_t)(
    void*       /**< (I) Returned from add input func */
    );

extern NXMGR_IM_API PDI_return_code_t PDI_init_server(
    char*                             process_id,       /**< (I) */
    void*                             ctxt,             /**< (I) */
    PDI_transport_t                   transport,        /**< (I) */
    char*                             ipcdata,          /**< (I) */
    PDI_add_input_func_t              AppAddInput,      /**< (I) */
    PDI_remove_input_func_t           RemoveInput       /**< (I) */
    );

extern NXMGR_IM_API PDI_return_code_t PDI_server_shutdown( void );

extern NXMGR_IM_API PDI_return_code_t PDI_init_client(
    char*                             process_id    /**< (I) */
    );

extern NXMGR_IM_API void PDI_version(
    char**               letters,       /**< (OF) */
    int*                 major_number,  /**< (O) */
    int*                 minor_number   /**< (O) */
    );

/** @} */

/** @} */

#ifdef __cplusplus
   }
#endif

#include <nxmgr_im/libnxmgr_im_undef.h>
#endif
