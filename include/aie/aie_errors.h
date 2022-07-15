/*==================================================================================================

                    Copyright (c) 2000 Unigraphics Solutions, Inc.
                             Unpublished - All rights reserved

====================================================================================================
File description:

    Filename: aie_errors.h
    Module  : aie

    Defines error codes used with Application Integration Environment

====================================================================================================
   Date      Name                    Description of Change
21-Sep-2000  scottb                  files for new project name, "aie"
03-Oct-2000  bakerm                  Added AIE Registry
12-Oct-2000  scottb                  fix carriage return problem
30-Oct-2000  scobel                  Add AIE error codes
31-Oct-2000  scobel                  Add comments
16-Nov-2000  kimch                   Update export functions and new import functions
16-Nov-2000  scottb                  add some codes for xfiles
28-Nov-2000  Gopal                   Added error code range for application import
28-Nov-2000  Satish                  Added error code range for application export
30-Nov-2000  scobel                  Clean-up tabs, CRs
07-Dec-2000  kimch                   Add errors
15-Dec-2000  x_satish                Modification to add Export Code specific error codes
27-Dec-2000  x_gopala                Added error codes for application import (generic)
12-Jan-2001  scobel                  Transaction log, misc. clean-up
19-Jan-2001  kimch                   Add import errors
12-Feb-2001  scobel                  Augment transaction log
22-Feb-2001  kimch                   Add x-file error
07-Mar-2001  scottb                  add user overridden export message
30-Mar-2001  scottb                  add message for orphaned files in import operation
04-Apr-2001  kimch                   Add same name in diff. dataset error
09-Apr-2001  scobel                  File clean-up; Warning to keep in sync w/java file
16-Apr-2001  scottb                  remove hard tabs
14-May-2001  scottb                  add codes and messages for licensing
17-May-2001  kimch                   Add cancelled op.
22-May-2001  kimch                   Add no file to import
28-Jun-2001  scottb                  add "not implemented" message
22-Jul-2001  scottb                  add new code for missing bom line
25-Jul-2001  scottb                  new error codes for integration
29-Jul-2001  scottb                  add "object checked out" message
02-Aug-2001  scobel                  Add error checking when creating connection
03-Aug-2001  scobel                  Changes to create persistent connection
07-Aug-2001  scottb                  add some IM errors
15-Aug-2001  scottb                  add more export error messages
18-Aug-2001  scottb                  add unable to find file to open message
28-Aug-2001  scottb                  add error loading connection
02-Sep-2001  scottb                  add message for failure to delete file before export
04-Sep-2001  scobel                  Add some new error codes for import
06-Sep-2001  scottb                  add file missing from dataset message
07-Sep-2001  scobel                  New errors for AIE_im_cancel_checkout
08-Sep-2001  scottb                  add error saving conn file
09-Sep-2001  scottb                  add refresh no xml error
10-Sep-2001  scobel                  Add deletion of directory when delete connection
10-Sep-2001  scottb                  add logging errors
17-Sep-2001  scobel                  Added new import messages
18-Sep-2001  scobel                  Added another error code
18-Sep-2001  kimch                   Add BVR Update Error
21-Sep-2001  kimch                   Add error
25-Sep-2001  scobel                  Add an import error code
09-Oct-2001  scottb                  add export of unimported file message
10-Oct-2001  scottb                  add unimported file messages
16-Oct-2001  scobel                  Misc. minor import clean-up
26-Oct-2001  scobel                  Added AIE_IM_IMPORT_CANT_CHANGE_ITEM
05-Nov-2001  scottb                  merge from aie_se
13-Nov-2001  scobel                  Add messages for logging clean connection
28-Aug-2001  luf                     Changes for fcad
07-Jan-2002  luf                     Submit
25-Feb-2002  scobel                  Added message for unit of measure
28-Feb-2002  scobel                  Merge up from aim_v7.0
28-Mar-2002  scobel                  New error code for import
28-Mar-2002  scobel                  Merge from aim_v7.0
19-Jun-2002  scobel                  Added a couple of codes for Remote Manager import
26-Jun-2002  scobel                  Added AIE_incomplete_xml_tcinfo and AIE_incomplete_xml_importinfo
02-Jul-2002  kimch                   Add AIE_FILE_IN_USE
19-Jul-2002  Murali Chamarthy        Added AIE_EXPORT_FILE_ERROR and AIE_found_no_datasets
22-Jul-2002  Murali Chamarthy        merging from aie_v8.1
31-Jul-2002  scobel                  Added AIE_OPERATION_PENDING
16-Aug-2002  Murali Chamarthy        Added AIE_start_resend and AIE_finish_resend
22-Aug-2002  scobel                  Added messages for cancel checkouts
08-Sep-2002  Murali Chamarthy        Add new error strings for BOM Imp/Exp
12-Sep-2002  scobel                  Added new messages for JT file import
26-Jul-2002  Aaron Ruckman           libtc.dll split work.
28-Aug-2002  Aaron Ruckman           splitiman.dll project
03-Sep-2002  Aaron Ruckman           merge
25-Sep-2002  Aaron Ruckman           merge
06-Oct-2002  Murali Chamarthy        Add new error strings for deleting unused files after refresh
31-Oct-2002  Nigel Morse             Split DLL and rebase to Oracle9 Nx20 VC7
22-Nov-2002  Tim Baverstock          Normalise inclusion
06-May-2003  scobel                  Added new messages for import as supplier user
14-May-2003  scobel                  Added error code AIE_IM_IMPORT_STALE_XML_FILE
22-May-2003  scobel                  Merge from P9.0.0.0
10-Sep-2003  scobel                  Use correct message when overwriting existing dataset upon import
31-Oct-2003  larson                  adding messages for Batch Import/Export
31-Oct-2003  scobel                  PR 4853151 - implement calling Checkmate
12-Mar-2004  gezou                   support Fiat Enh project --- executing pre import/post export script
17-Mar-2004  gezou                   add more error message to support Fiat Enh project
24-Mar-2004  larson                  merged from larson_aie_p9.0.0.1
27-May-2004  gezou                   fix PR4976652, Fiat new request, run preImport script before File(s) need import dialog
01-Jul-2004  gezou                   fix 4960309:New added/configured components which are checked-out should refresh as Write privilege
03-Sep-2004  scottb                  add invalid tag error
17-Nov-2004  aputhenp                Added new error message for license module being unintialized
23-Feb-2005  gezou                   fix PR5096021: support property for LOV
21-Mar-2005  aputhenp                Fix for PR1387947 - error message will be presented if the connection dir and filespec dir are not the same.
13-Apr-2005  gezou                   add new error code AIE_cant_get_ds_family_name
03-Aug-2005  aputhenp                Added a new error code for invalid arguments
24-Aug-2005  aputhenp                Added error codes for template related issues
29-Aug-2005  narayanr                Added AIE_found_no_tmpl_datasets.
27-Sep-2005  aputhenp                Merge AIE velocity changes to V9.1.3
10-Feb-2006  aputhenp                Added AIE_no_ds_family_name_for_ds
10-Feb-2006  aputhenp                Merge to cvg aie velocity - Fix PR5395032
16-Feb-2006  Stan Sharpe             Add new error codes
$HISTORY$
==================================================================================================*/

/**************************************************************************************************
IMPORTANT!  IMPORTANT!  IMPORTANT!  IMPORTANT!  IMPORTANT!  IMPORTANT!  IMPORTANT!  IMPORTANT!

  IF YOU MAKE CHANGES TO THIS FILE, THEN BE SURE TO MAKE CORRESPONDING CHANGES TO aie_errors.uih!!!

  ALSO, BE SURE TO KEEP DUPLICATE CONSTANTS USED IN PORTAL CLIENT JAVA CODE, DEFINED IN
  \java\com\ugsolutions\iman\kernel\IMANComponentConnection.java, IN SYNC WITH THESE HERE!!!

  ALSO, MAKE SURE THE ERROR CODES DO NOT GO BEFORE 88000 NOR BEYOND 88999!!!

  Error codes 88000-88499 are reserved for use by the common so-called "Connection Manager" functions
  Error codes 88500-88999 are reserved for use by the generic application-specific functions

IMPORTANT!  IMPORTANT!  IMPORTANT!  IMPORTANT!  IMPORTANT!  IMPORTANT!  IMPORTANT!  IMPORTANT!
***************************************************************************************************/

#ifndef AIE_ERRORS_H
#define AIE_ERRORS_H

#include <common/emh_const.h>

#define AIE_CM_ERROR_BASE           EMH_AIE_error_base          /* 88000 */
#define AIE_APP_GENERIC_ERROR_BASE  EMH_AIE_error_base + 500    /* 88500 */
#define AIE_IMPORT_ERROR_BASE       EMH_AIE_error_base + 750    /* 88750 */
#define AIE_TEMPLATE_ERROR_BASE     EMH_AIE_error_base + 900    /* 88900 */

/*****************************************************************************\

  Add AIE (CM) error codes here

\*****************************************************************************/

/* Miscellaneous errors */
#define AIE_SUCCESS                         (0)
#define AIE_encap_list_not_empty            (AIE_CM_ERROR_BASE + 0)
#define AIE_tool_not_found                  (AIE_CM_ERROR_BASE + 1)
#define AIE_cannot_open_dataset             (AIE_CM_ERROR_BASE + 2)
#define AIE_NULL_reference                  (AIE_CM_ERROR_BASE + 3)
#define AIE_connection_not_found            (AIE_CM_ERROR_BASE + 4)
#define AIE_connection_in_operation         (AIE_CM_ERROR_BASE + 5)
#define AIE_conn_file_does_not_exist        (AIE_CM_ERROR_BASE + 6)
#define AIE_conn_file_not_found_by_name     (AIE_CM_ERROR_BASE + 7)
#define AIE_conn_file_not_found_by_tag      (AIE_CM_ERROR_BASE + 8)
#define AIE_xdata_file_not_found_by_name    (AIE_CM_ERROR_BASE + 9)
#define AIE_ERROR_WRITING_XACTION_LOG       (AIE_CM_ERROR_BASE + 10)
#define AIE_ERROR_WRITING_XFILES            (AIE_CM_ERROR_BASE + 11)
#define AIE_object_checked_out              (AIE_CM_ERROR_BASE + 12)
#define AIE_conn_name_not_unique            (AIE_CM_ERROR_BASE + 13)
#define AIE_root_dir_nonexistent            (AIE_CM_ERROR_BASE + 14)
#define AIE_cannot_create_export_dir        (AIE_CM_ERROR_BASE + 15)
#define AIE_cannot_load_connection          (AIE_CM_ERROR_BASE + 16)
#define AIE_action_confirmation             (AIE_CM_ERROR_BASE + 17)
#define AIE_action_read_only                (AIE_CM_ERROR_BASE + 18)
#define AIE_action_retry                    (AIE_CM_ERROR_BASE + 19)
#define AIE_UNRECOGNIZED_DATASETTYPE        (AIE_CM_ERROR_BASE + 20)
#define AIE_IM_FILE_NOT_IN_CONN_DIR         (AIE_CM_ERROR_BASE + 21)
#define AIE_IM_FILE_NOT_CHECKED_OUT         (AIE_CM_ERROR_BASE + 22)
#define AIE_IM_INCONSISTENT_CHECKOUT        (AIE_CM_ERROR_BASE + 23)
#define AIE_IM_CANNOT_CANCEL_CHECKOUT       (AIE_CM_ERROR_BASE + 24)
#define AIE_IM_NO_XML_FILE_FOUND            (AIE_CM_ERROR_BASE + 25)
#define AIE_IM_CANNOT_DELETE_EXPORT_DIR     (AIE_CM_ERROR_BASE + 26)
#define AIE_IM_CANNOT_GET_RES_INFO          (AIE_CM_ERROR_BASE + 27)
#define AIE_IM_ERROR_CREATING_LOG_FILE      (AIE_CM_ERROR_BASE + 28)
#define AIE_IM_NONEXISTENT_DIRECTORY        (AIE_CM_ERROR_BASE + 29)
#define AIE_error_creating_directory        (AIE_CM_ERROR_BASE + 30)
#define AIE_ok_message                      (AIE_CM_ERROR_BASE + 31)
#define AIE_incomplete_xml_tcinfo           (AIE_CM_ERROR_BASE + 32)
#define AIE_incomplete_xml_importinfo       (AIE_CM_ERROR_BASE + 33)
#define AIE_OPERATION_PENDING               (AIE_CM_ERROR_BASE + 34)
#define AIE_found_no_tmpl_datasets          (AIE_CM_ERROR_BASE + 35)
#define AIE_UGII_ROOT_DIR_not_defined       (AIE_CM_ERROR_BASE + 36)
#define AIE_TC_BIN_not_defined              (AIE_CM_ERROR_BASE + 37)
#define AIE_string_sanitizing_failure       (AIE_CM_ERROR_BASE + 38)
#define AIE_NX_DTDPATH_exceeds_max_length   (AIE_CM_ERROR_BASE + 39)
#define AIE_internal_error                  (AIE_CM_ERROR_BASE + 50)
#define AIE_no_such_export_operation        (AIE_CM_ERROR_BASE + 51)
#define AIE_no_such_import_operation        (AIE_CM_ERROR_BASE + 52)
#define AIE_no_such_root_dataset            (AIE_CM_ERROR_BASE + 53)
#define AIE_no_such_bom_line                (AIE_CM_ERROR_BASE + 54)
#define AIE_file_not_in_dataset             (AIE_CM_ERROR_BASE + 55)
#define AIE_dataset_not_accessible          (AIE_CM_ERROR_BASE + 56)
#define AIE_error_saving_conn_file          (AIE_CM_ERROR_BASE + 57)
#define AIE_error_on_refresh                (AIE_CM_ERROR_BASE + 58)
#define AIE_not_implemented                 (AIE_CM_ERROR_BASE + 60)
#define AIE_error_determining_files         (AIE_CM_ERROR_BASE + 61)
#define AIE_cannot_get_reference            (AIE_CM_ERROR_BASE + 62)
#define AIE_error_checking_out              (AIE_CM_ERROR_BASE + 63)
#define AIE_error_exporting_assoc           (AIE_CM_ERROR_BASE + 64)
#define AIE_error_saving_connection         (AIE_CM_ERROR_BASE + 65)
#define AIE_export_needs_confirmation       (AIE_CM_ERROR_BASE + 66)
#define AIE_export_name_conflict            (AIE_CM_ERROR_BASE + 67)
#define AIE_export_no_file_to_open          (AIE_CM_ERROR_BASE + 68)
#define AIE_export_error_deleting_file      (AIE_CM_ERROR_BASE + 69)
#define AIE_xml_element_not_found           (AIE_CM_ERROR_BASE + 70)
#define AIE_xml_bad_format                  (AIE_CM_ERROR_BASE + 71)
#define AIE_xml_error_creating              (AIE_CM_ERROR_BASE + 72)
#define AIE_xml_error_reading               (AIE_CM_ERROR_BASE + 73)
#define AIE_refresh_no_xml                  (AIE_CM_ERROR_BASE + 74)
#define AIE_xml_error_reading2              (AIE_CM_ERROR_BASE + 75)
#define AIE_delete_connection_msg           (AIE_CM_ERROR_BASE + 79)
#define AIE_create_connection_msg           (AIE_CM_ERROR_BASE + 80)
#define AIE_file_exported                   (AIE_CM_ERROR_BASE + 81)
#define AIE_file_exported_and_checkedout    (AIE_CM_ERROR_BASE + 82)
#define AIE_errors_during_operation         (AIE_CM_ERROR_BASE + 83)
#define AIE_end_errors_during_operation     (AIE_CM_ERROR_BASE + 84)
#define AIE_cancel_checkout_msg             (AIE_CM_ERROR_BASE + 85)
#define AIE_user_exit_invalid_ds_name       (AIE_CM_ERROR_BASE + 86)
#define AIE_found_no_datasets               (AIE_CM_ERROR_BASE + 87)
#define AIE_CANCEL_CHECKOUT_W_INFO_MSG      (AIE_CM_ERROR_BASE + 88)
#define AIE_CANCEL_CHECKOUT_ERROR           (AIE_CM_ERROR_BASE + 89)
#define AIE_error_writing_components_to_xml (AIE_CM_ERROR_BASE + 90)
#define AIE_dataset_not_found_in_filelist   (AIE_CM_ERROR_BASE + 91)
#define AIE_item_not_found_in_bvr           (AIE_CM_ERROR_BASE + 92)
#define AIE_cancelled_operation             (AIE_CM_ERROR_BASE + 99)
/* Miscellaneous errors index from 150 to 200 */
#define AIE_delete_file_missing             (AIE_CM_ERROR_BASE + 150)
#define AIE_delete_needs_confirmation       (AIE_CM_ERROR_BASE + 151)
#define AIE_error_deleting_conn_object      (AIE_CM_ERROR_BASE + 152)
#define AIE_deleted_conn_object             (AIE_CM_ERROR_BASE + 153)

#define AIE_INVALID_VALUE                   (AIE_CM_ERROR_BASE + 154)

/* Export errors */
#define AIE_EXPORT_SKIPPED                  (AIE_CM_ERROR_BASE + 100)
#define AIE_EXPORT_CLIENT_ERROR             (AIE_CM_ERROR_BASE + 101)
#define AIE_EXPORT_SERVER_ERROR             (AIE_CM_ERROR_BASE + 102)
#define AIE_EXPORT_OK                       (AIE_CM_ERROR_BASE + 103)
#define AIE_START_EXPORT                    (AIE_CM_ERROR_BASE + 104)
#define AIE_FINISH_EXPORT                   (AIE_CM_ERROR_BASE + 105)
#define AIE_EXPORT_FILE_ERROR               (AIE_CM_ERROR_BASE + 106)
#define AIE_EXPORT_ERROR_NO_USER_NAME       (AIE_CM_ERROR_BASE + 107)
#define AIE_EXPORT_ERROR_NO_USER_PASSWORD   (AIE_CM_ERROR_BASE + 108)
#define AIE_EXPORT__ERROR_NO_ITEM_REVISIONS (AIE_CM_ERROR_BASE + 109)
#define AIE_EXPORT_USER_OVERRIDDEN          (AIE_CM_ERROR_BASE + 110)
#define AIE_EXPORT_SAME_FILE_IN_DIFF_DATASETS          (AIE_CM_ERROR_BASE + 111)

/* Executing post export script errors */
#define AIE_EXPORT_POST_EXPORT_SCRIPT       (AIE_CM_ERROR_BASE + 112)
/* xxxx2 error/warning message same as xxxx, but it appends the detail
   infomation like script name, XFile name which shows on the log file */
#define AIE_SCRIPT_NOT_FOUND                (AIE_CM_ERROR_BASE + 113)
#define AIE_SCRIPT_NOT_FOUND2               (AIE_CM_ERROR_BASE + 114)
#define AIE_XFILE_NOT_FOUND_SKIP_SCRIPT     (AIE_CM_ERROR_BASE + 115)
#define AIE_error_checking_out_elsewhere    (AIE_CM_ERROR_BASE + 116)

#define AIE_start_refresh                   (AIE_CM_ERROR_BASE + 120)
#define AIE_finish_refresh                  (AIE_CM_ERROR_BASE + 121)
#define AIE_start_retry                     (AIE_CM_ERROR_BASE + 122)
#define AIE_finish_retry                    (AIE_CM_ERROR_BASE + 123)
#define AIE_start_resend                    (AIE_CM_ERROR_BASE + 124)
#define AIE_finish_resend                   (AIE_CM_ERROR_BASE + 125)
#define AIE_start_cancel_checkouts          (AIE_CM_ERROR_BASE + 126)
#define AIE_finish_cancel_checkouts         (AIE_CM_ERROR_BASE + 127)

#define AIE_BATCH_EXPORT_CREATED            (AIE_CM_ERROR_BASE + 128)
#define AIE_BATCH_EXPORT_STARTED            (AIE_CM_ERROR_BASE + 129)
#define AIE_BATCH_EXPORT_FINISHED           (AIE_CM_ERROR_BASE + 130)
#define AIE_BATCH_EXPORT_FAILED             (AIE_CM_ERROR_BASE + 131)

/* Import errors */
#define AIE_IMPORT_SKIPPED                  (AIE_CM_ERROR_BASE + 200)
#define AIE_IMPORT_CLIENT_ERROR             (AIE_CM_ERROR_BASE + 201)
#define AIE_IMPORT_SERVER_ERROR             (AIE_CM_ERROR_BASE + 202)
#define AIE_IMPORT_OK                       (AIE_CM_ERROR_BASE + 203)
#define AIE_IMPORT_NOT_OK                   (AIE_CM_ERROR_BASE + 204)
#define AIE_START_IMPORT                    (AIE_CM_ERROR_BASE + 205)
#define AIE_FINISH_IMPORT                   (AIE_CM_ERROR_BASE + 206)
#define AIE_NO_IMPORT                       (AIE_CM_ERROR_BASE + 207)
#define AIE_ERROR_IMPORTING_FILES           (AIE_CM_ERROR_BASE + 208)
#define AIE_FILE_IN_USE                     (AIE_CM_ERROR_BASE + 209)

#define AIE_IMPORT_TC_MODIFIED              (AIE_CM_ERROR_BASE + 210)
#define AIE_IMPORT_TC_DELETED               (AIE_CM_ERROR_BASE + 211)
#define AIE_IMPORT_TC_CHECKED_OUT           (AIE_CM_ERROR_BASE + 212)
#define AIE_SAME_FILE_EXISTS                (AIE_CM_ERROR_BASE + 213)

#define AIE_IMPORT_ORPHANED_FILE            (AIE_CM_ERROR_BASE + 220)

#define AIE_IM_IMPORT_NO_IMPORTINFO         (AIE_CM_ERROR_BASE + 230)
#define AIE_IM_IMPORT_NOT_CHECKED_OUT       (AIE_CM_ERROR_BASE + 231)
#define AIE_IM_IMPORT_NO_SOURCE_DEST        (AIE_CM_ERROR_BASE + 232)
#define AIE_IM_IMPORT_FILE_NOT_IN_CONN      (AIE_CM_ERROR_BASE + 233)
#define AIE_IM_IMPORT_NEW_FILE_IN_CONN      (AIE_CM_ERROR_BASE + 234)
#define AIE_IM_IMPORT_NO_SAVE_TARGET        (AIE_CM_ERROR_BASE + 235)
#define AIE_IM_IMPORT_IN_PROGRESS           (AIE_CM_ERROR_BASE + 236)
#define AIE_IM_IMPORT_CANNOT_INSERT         (AIE_CM_ERROR_BASE + 237)
#define AIE_IM_IMPORT_CANNOT_SAVE_ATTRS     (AIE_CM_ERROR_BASE + 238)
#define AIE_IM_IMPORT_CANNOT_CHECKOUT       (AIE_CM_ERROR_BASE + 239)
#define AIE_IM_IMPORT_CANNOT_CHECKIN        (AIE_CM_ERROR_BASE + 240)
#define AIE_IM_IMPORT_CANNOT_ADD_NR         (AIE_CM_ERROR_BASE + 241)
#define AIE_IM_CHECKED_IN_AND_IMPORTED      (AIE_CM_ERROR_BASE + 242)
#define AIE_IM_IMPORT_RE_CHECKED_OUT        (AIE_CM_ERROR_BASE + 243)
#define AIE_IM_IMPORT_NEW_FILE              (AIE_CM_ERROR_BASE + 244)
#define AIE_IM_BVR_FOUND_NO_FILE            (AIE_CM_ERROR_BASE + 245)
#define AIE_IM_BVR_FILE_NOT_IMPORTED        (AIE_CM_ERROR_BASE + 246)
#define AIE_IM_IMPORT_CANNOT_INSERT_FILE    (AIE_CM_ERROR_BASE + 247)
#define AIE_IM_IMPORT_NOT_IMPORTED          (AIE_CM_ERROR_BASE + 248)
#define AIE_IM_IMPORT_EXPORT_EXISTING       (AIE_CM_ERROR_BASE + 249)
#define AIE_IM_IMPORT_CANT_CHANGE_ITEM      (AIE_CM_ERROR_BASE + 250)

#define AIE_START_CLEANUP                   (AIE_CM_ERROR_BASE + 251)
#define AIE_FINISH_CLEANUP                  (AIE_CM_ERROR_BASE + 252)
#define AIE_REMOVED_FILE                    (AIE_CM_ERROR_BASE + 253)

#define AIE_IM_IMPORT_CANT_CHANGE_UOM       (AIE_CM_ERROR_BASE + 254)

#define AIE_IM_IMPORT_TO_NEW_SEPARATE_DS    (AIE_CM_ERROR_BASE + 255)
#define AIE_IM_IMPORT_TO_SEPARATE_DS        (AIE_CM_ERROR_BASE + 256)
#define AIE_IM_CANT_IMPORT_TO_SEPARATE_DS   (AIE_CM_ERROR_BASE + 257)

#define AIE_IM_IMPLICIT_CHECKOUT_DS             (AIE_CM_ERROR_BASE + 258)
#define AIE_IM_CANT_SET_DMGR_PRIV               (AIE_CM_ERROR_BASE + 259)
#define AIE_IM_IMPORT_CANT_IMPLICIT_CHECKOUT    (AIE_CM_ERROR_BASE + 260)
#define AIE_IM_IMPORT_STALE_XML_FILE            (AIE_CM_ERROR_BASE + 261)
#define AIE_IM_OVERWROTE_DATASET_AND_IMPORTED   (AIE_CM_ERROR_BASE + 262)

#define AIE_BATCH_IMPORT_CREATED            (AIE_CM_ERROR_BASE + 263)
#define AIE_BATCH_IMPORT_STARTED            (AIE_CM_ERROR_BASE + 264)
#define AIE_BATCH_IMPORT_FINISHED           (AIE_CM_ERROR_BASE + 265)
#define AIE_BATCH_IMPORT_FAILED             (AIE_CM_ERROR_BASE + 266)

/* Executing pre import script errors:
   xxxx2 error message same as xxxx, but it appends the detail
   infomation like the drawing filename, XFile name which shows on the log file */
#define AIE_IM_IMPORT_PRE_IMPORT_SCRIPT          (AIE_CM_ERROR_BASE + 267)
#define AIE_IM_IMPORT_PRE_IMPORT_SCRIPT2         (AIE_CM_ERROR_BASE + 268)
#define AIE_XFILE_NOT_FOUND_ABORT                (AIE_CM_ERROR_BASE + 269)
#define AIE_XFILE_NOT_FOUND_ABORT2               (AIE_CM_ERROR_BASE + 270)
#define AIE_IMPORT_SCRIPT_NOT_FOUND              (AIE_CM_ERROR_BASE + 271)
#define AIE_IMPORT_SCRIPT_NOT_FOUND2             (AIE_CM_ERROR_BASE + 272)
#define AIE_IMPORT_INVALID_CONN_FILE_TAG         (AIE_CM_ERROR_BASE + 273)
#define AIE_IMPORT_FILEDIR_NOTMATCHING_CONNDIR   (AIE_CM_ERROR_BASE + 274)

/* Registry errors */
#define AIE_reg_ok                          (0)
#define AIE_reg_error                       (AIE_CM_ERROR_BASE + 300)
#define AIE_reg_nokey                       (AIE_CM_ERROR_BASE + 301)
#define AIE_reg_missing                     (AIE_CM_ERROR_BASE + 302)
#define AIE_reg_duplicate                   (AIE_CM_ERROR_BASE + 303)

/* Licensing errors */
#define AIE_unlicensed                      (AIE_CM_ERROR_BASE + 320)
#define AIE_no_license_available            (AIE_CM_ERROR_BASE + 321)
#define AIE_license_error                   (AIE_CM_ERROR_BASE + 322)
#define AIE_license_init_error              (AIE_CM_ERROR_BASE + 323)

#define AIE_cant_get_ds_family_name        (AIE_CM_ERROR_BASE + 324)
#define AIE_no_ds_family_name_for_ds       (AIE_CM_ERROR_BASE + 325)

/* Application specific messages */
#define AIE_START_CHECKMATE                 (AIE_CM_ERROR_BASE + 400)
#define AIE_FINISH_CHECKMATE                (AIE_CM_ERROR_BASE + 401)
#define AIE_CHECKMATE_SETUP_ERROR           (AIE_CM_ERROR_BASE + 402)
#define AIE_CHECKMATE_FAILURES              (AIE_CM_ERROR_BASE + 403)

/* Reserved for licensing */
#define AIE_internal_reserved               (AIE_CM_ERROR_BASE + 499)

/*****************************************************************************\

  Add generic app-specific error codes here - should look somethink like:

#define AIE_APPGEN_ERROR_ONE        (AIE_APP_GENERIC_ERROR_BASE + 0)

\*****************************************************************************/

/* Add range of errors for Application Export */
#define AIE_check_out_error                 (AIE_APP_GENERIC_ERROR_BASE + 1)
#define AIE_child_dataset_not_found         (AIE_APP_GENERIC_ERROR_BASE + 2)
#define AIE_different_file_tags             (AIE_APP_GENERIC_ERROR_BASE + 3)
#define AIE_file_length_limit_exceeded      (AIE_APP_GENERIC_ERROR_BASE + 4)
#define AIE_ixfpath_length_limit_exceeded   (AIE_APP_GENERIC_ERROR_BASE + 5)
#define AIE_null_xml_attribute_name         (AIE_APP_GENERIC_ERROR_BASE + 6)
#define AIE_null_xml_element_name           (AIE_APP_GENERIC_ERROR_BASE + 7)
#define AIE_export_not_successful           (AIE_APP_GENERIC_ERROR_BASE + 8)
#define AIE_null_xml_element_value          (AIE_APP_GENERIC_ERROR_BASE + 9)
#define AIE_wrong_occ_xtransform            (AIE_APP_GENERIC_ERROR_BASE + 10)
#define AIE_INVALID_ARGUMENT                (AIE_APP_GENERIC_ERROR_BASE + 11)

/* Add range of errors for Application Import */
#define AIE_APP_IMPORT_ERR                  (AIE_APP_GENERIC_ERROR_BASE + 100)

#define AIE_file_tampered                   (AIE_APP_IMPORT_ERR + 1)
#define AIE_new_file_no_xml            (AIE_APP_IMPORT_ERR + 2)

/* Add range of errors for Datamodel service */
#define AIE_DMS_ERR                ( AIE_APP_GENERIC_ERROR_BASE + 200 )

#define AIE_dms_datasettype_not_supported   ( AIE_DMS_ERR + 1 )

/* Template related messages */
#define AIE_NO_TEMPLATE_FOLDER              (AIE_TEMPLATE_ERROR_BASE + 1)
#define AIE_NO_MATCHING_TEMPLATE_FOLDER     (AIE_TEMPLATE_ERROR_BASE + 2)

#endif
