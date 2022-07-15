/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This header file declares all error constants to be used by UGSM.
*/

/*  */

#ifndef NXSM_ERRORS_H
#define NXSM_ERRORS_H

#include <common/emh_const.h>
#include <ae/libae_exports.h>

/**
    @defgroup NXSM_ERRORS NXSM Errors
    @ingroup NXSM
    @{
*/

#define UB                              EMH_NXSM_error_base

/**
    Unknown internal error in NXSM
*/
#define NXSM_unknown                    UB+  0

/**
    Cannot support multiple sessions
*/
#define NXSM_mult_sessions              UB+  1

/**
    Cannot initialize AE
*/
#define NXSM_init_ae                    UB+  2

#define NXSM_file_not_found             UB+  3

/**
    Cannot create file
*/
#define NXSM_create_file                UB+  4

/**
    Cannot execute command
*/
#define NXSM_exec_cmd                   UB+  5

/**
    Cannot initialize IPC
*/
#define NXSM_init_ipc                   UB+  6

/**
    Must be a number between 1 and 255
*/
#define NXSM_layer_invalid              UB+  7

/**
    Error creating dataset
*/
#define NXSM_create_dataset             UB+  8

/**
    Error creating datasetuif
*/
#define NXSM_create_datasetuif          UB+  9

/**
    No dataset associated with this object
*/
#define NXSM_no_dataset                 UB+ 10

/**
    Unable to get list of reference sets
*/
#define NXSM_get_refsets                UB+ 11

/**
    Saving selected refset and layer
*/
#define NXSM_save_reflyr                UB+ 12

/**
    Select one and only one
*/
#define NXSM_select_one                 UB+ 13

/**
    Not enough items selected in list
*/
#define NXSM_select_some                UB+ 14

/**
    ACS error occured
*/
#define NXSM_acs_error                  UB+ 15

/**
    User action invalid
*/
#define NXSM_invalid_action             UB+ 16

/**
    NX V10 startup error
*/
#define NX_startup_error                UB+ 19

/**
    NX V10 API initialization error
*/
#define API_init_error                  UB+ 20

/**
    NX V10 API find appdata error
*/
#define API_appdata_error               UB+ 21

/**
    NX V10 API startup error
*/
#define API_startup_error               UB+ 22

/**
    NX V10 API not supported on platform
*/
#define API_not_supported               UB+ 23

/**
    NX V10 API invalid role name
*/
#define API_invalid_role                UB+ 24

/**
    May have only one open active NX
*/
#define API_multiple_open               UB+ 25

/**
    Only one background drawing NX allowed
*/
#define API_multiple_dwg                UB+ 26

/**
    User is not auto logged in
*/
#define API_no_auto_login               UB+ 27

/**
    Plotting - no find_dwg.grx
*/
#define PLOT_no_finddwg                 UB+ 30

/**
    Plotting - no plot_dwg.grx
*/
#define PLOT_no_plotdwg                 UB+ 31

/**
    Plotting - plot log not created
*/
#define PLOT_no_plotlog                 UB+ 32

/**
    Plotting - can't create param file
*/
#define PLOT_paramfile_error            UB+ 33

/**
    Find drawing dialog destroyed before job completed
*/
#define PLOT_no_findraw_dialog          UB+ 34

//------------------------------------------------------------------------------
/**
 * @defgroup NX_MANAGER_ERRORS Errors for NX Manager utilities
 * @ingroup NXSM_ERRORS
 * @{
 */
//------------------------------------------------------------------------------
/**  The supplied dataset tag parameter information is invalid. */
#define NXMGR_invalid_dataset                   UB+ 41

/** The version of the dataset specified in the input command line string cannot be found. */
#define NXMGR_invalid_dataset_version           UB+ 42

/** The provided Item Revision tag parameter information is invalid. */
#define NXMGR_invalid_revision                  UB+ 43

/** The provided Item tag parameter information is invalid. */
#define NXMGR_invalid_item                      UB+ 44

/** The provided Dataset is not related to any object by the "GRM_relation" relation. */
#define NXMGR_no_relations                      UB+ 45

/** The value of the "Part Identifier" property is not set for the Item object specified in the input command line. */
#define NXMGR_no_mfk                            UB+ 46

/** The provided Dataset does not have any related Item Revision. */
#define NXMGR_no_revision                       UB+ 47

/** A unique command line interface string field separator cannot be selected. Please use one of the following characters: /@#$^&amp;()|[]{}*/
#define NXMGR_no_separator                      UB+ 48

/** An unexpected error has occurred. Please refer to the syslog file for more information. */
#define NXMGR_unexpected_error                  UB+ 49

/** The input parameter "%1$" is missing in the call to the function "%2$". */
#define NXMGR_missing_parameter                 UB+ 50

/** The input command line string does not contain any Multifield Key information. */
#define NXMGR_missing_mfk                       UB+ 51

/** The input command line string does not contain any Item Revision. */
#define NXMGR_missing_revision                  UB+ 52

/** The provided command line input string is incomplete. It should have more than 3 characters. */
#define NXMGR_cli_short                         UB+ 53

/** The input Dataset is not of a supported type. Supported dataset types are: %1$. */
#define NXMGR_no_cli_dataset_type_name          UB+ 54

/** The input Dataset is not related to an Item Revision by a supported Relation type. The supported Relation types are: %1$. */
#define NXMGR_no_relation_type_name             UB+ 55
//------------------------------------------------------------------------------
/**
 * @}
 */
//------------------------------------------------------------------------------



#define NXSM_cannot_supp_mult_sessions  NXSM_mult_sessions
#define NXSM_cannot_initialize_ae       NXSM_init_ae
#define NXSM_cannot_create_file         NXSM_create_file
#define NXSM_cannot_execute_command     NXSM_exec_cmd
#define NXSM_cannot_initialize_ipc      NXSM_init_ipc

/** @} */

#include <ae/libae_undef.h>
#endif
