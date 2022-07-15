/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This report.h file should be included in every report program,
    and all the global definitions should reside here.
*/

/*  */

#ifndef REPORT_H
#define REPORT_H

#include <fclasses/tc_string.h>
#include <fclasses/tc_time.h>
#include <tc/tc_startup.h>
#include <sa/tcfile.h>
#include <tccore/workspaceobject.h>
#include <ae/ae.h>
#include <sa/sa.h>
#include <tc/folder.h>
#include <ss/ss_const.h>
#include <fclasses/tc_stat.h>
#include <fclasses/tc_errno.h>
#include <fclasses/tc_stdlib.h>
#include <fclasses/tc_stdio.h>


/**
    @defgroup REPORT Report
    @ingroup USER_EXITS
    @{
*/

/** Lines per page */
#define NEW_PAGE            64

#define EMPTY               -1

#define ITEM                0
#define ITEMREVISION        1

/**
    @name For Reports 9 through 12
    @{
*/
#define NULLERR             -11
#define NO_HDR              0
#define NEWPAGE_HDR         1
#define ADMIN_HDR           2
#define INFO_HDR            3
#define NULL_STRING         "\0"
/** @} */

/** Names of Attributes to Print */
#define WSOM_name           "Name"

/** @if DOX_IGNORE
                    Was "Item id"
@endif */
#define WSOM_item_id        "ID"

/** @if DOX_IGNORE
                    Was "Revision id"
@endif */
#define WSOM_revision_id    "Revision"

#define WSOM_description    "Description"
#define WSOM_date_created   "Date Created"
#define WSOM_group          "Group ID"

/**
    @name For Report on Items By Dataset
    @{
*/
#define WSOM_release_date   "Date Released"
#define WSOM_application    "Application"
#define WSOM_classn         "Classification"
#define WSOM_owner          "Owner ID"
#define WSOM_rel_status     "Release Status"
#define WSOM_obj_type       "Type"
#define WSOM_version        "Version Number"
/** @} */

/** @if DOX_IGNORE
                    Used in report10_itk.c
@endif */
#define REP10_spec_folder   "Specification Folder"

typedef struct report_entry
{
    const char* attr;
    int         index;
    int         indent;
    int         width;
    int         n_char;
} report_entry;


/** Structure for storing Admin. Data */
typedef struct admindata_s {
    char      Job_Name[WSO_name_size_c+1];
    char      Item_Crtd_Dt[WSO_name_size_c+1];
    char      Item_Owner[SA_user_size_c+1];
    char      Res_Uname[SA_user_size_c+1];
    char      Res_Dt[WSO_name_size_c+1];
    char      Res_Reason[WSO_name_size_c+1];
}AdminData;

/** Structure for storing report13 data */
typedef struct report13_s{
    char      Job_Name[WSO_name_size_c+1];
    char      Procedure[WSO_name_size_c+1];
    char      Target_object[WSO_name_size_c+1];
}Report13_Data;

#include <user_exits/libuser_exits_exports.h>

#ifdef __cplusplus
    extern "C"{
#endif

extern USER_EXITS_API void USER_set_print_hdr_flag(int flag);

extern USER_EXITS_API void USER_set_head_width(int width);

extern USER_EXITS_API void USER_set_rep4_header(const char *headerString, int index);

/** Group Name of Report #8 */
extern USER_EXITS_API void USER_set_rep8_group(const char *group_name);

/** Group Name used for Reports */
extern USER_EXITS_API void USER_set_rep_group_name(const char *group_name);

/** Owner Name used for Reports */
extern USER_EXITS_API void USER_set_rep_owner_name(const char *owner_name);

extern USER_EXITS_API int NonReleased_Item_Report (void);

/** @if DOX_IGNORE
                    report3_itk.c
@endif */

extern USER_EXITS_API int Released_Item_Report (
    logical               prompt_for_input, /**< (I) */
    const char*           tasktype_name     /**< (I) */
    );

/** @if DOX_IGNORE
                    report4_itk.c
@endif */

extern USER_EXITS_API int Employee_Sum_Report (
    logical               prompt_for_input, /**< (I) */
    int                   attr_ct,          /**< (I) */
    int*                  attr_array        /**< (I) */
    );

/** @if DOX_IGNORE
                    report5_itk.c
@endif */

extern USER_EXITS_API int Item_Summary_Report (void);

/** @if DOX_IGNORE
                    report6_itk.c
@endif */

extern USER_EXITS_API int By_Proj_Item_Summary_Report (void);

/** @if DOX_IGNORE
    report7_itk.c (in CXX) a C++ declaration needed for now!!!
@endif */

extern USER_EXITS_API int Users_and_Release_Levels_Report (
    const char*           group_name /**< (I) */
    );

/** @if DOX_IGNORE
                    report8_itk.c
@endif */

/**
    Produces the summary report for objects which are in process with 
    workflow process_templates and owned by requested group.
    <br>Report depicts one to one relationship between objects, process templates and tasks.
    <br><br><b>Restrictions:</b>
    The output device must be set through the call to #setOutputDevice, in order to print reports on the required device.
    <br><br><b>Return Values:</b>
    <ul> 
    <li>#ITK_ok on success: the requested group exists and the summary report is generated.</li>
    <li>#SA_group_not_found if no group exists with the requested name.</li>
    <li>#SA_finding_group if more than one group exist with the requested name.</li>
    </ul>
*/

extern USER_EXITS_API int Access_Levels_Report (
    const char*           group_name /**< (I) Name of the group for which summary report is asked */
    );

/** @if DOX_IGNORE
                    report9_itk.c
@endif */

extern USER_EXITS_API int Mass_Storage_Report (
    const char*           owner_name, /**< (I) */
    const char*           group_name  /**< (I) */
    );

/** @if DOX_IGNORE
                    report10_itk.c
@endif */

extern USER_EXITS_API int Object_Inquiry (
    const char*           item_folder_id, /**< (I) */
    const char*           item_version_id /**< (I) */
    );

extern USER_EXITS_API int Object_Search (
    tag_t                 ivf_tag /**< (I) */
    );

/** @if DOX_IGNORE
                    report11_itk.c
@endif */

extern USER_EXITS_API int ItemsByDataset (
    const char*           dsetName,   /**< (I) */
    const char*           dsetType,   /**< (I) */
    const char*           owner_name, /**< (I) */
    const char*           group_name  /**< (I) */
    );

extern USER_EXITS_API int Get_Item_AdminData(
    tag_t                 dset_tag,  /**< (I) */
    WSO_descriptor_t      info,      /**< (I) */
    AdminData*            admin_data /**< (O) */
    );

/** @if DOX_IGNORE
                    report12_itk.c
@endif */

extern USER_EXITS_API int Object_By_Group(
    char*                 group_name /**< (I) */
    );

/** @if DOX_IGNORE
                    report13_itk.c
@endif */




extern USER_EXITS_API int Job_Status(
    char*                 job_name /**< (I) */
    );

/**
    This is a not like the other reports that are shown on the
    list of reports at the UIF level so we will not give it a
    number. See Import_Export_Report function in replib_itk.c
    for details.
*/

extern USER_EXITS_API int Import_Export_Report( 
  const char*             reportStr /**< (I) */
  ); 


/** @if DOX_IGNORE
                    replib_itk.c
@endif */

extern USER_EXITS_API void store_entry_index (
    WSO_descriptor_t*      info,
    report_entry*          ps,
    int                    n_limit
    );

extern USER_EXITS_API int print_report (
    WSO_descriptor_t*      info,
    report_entry*          ps,
    int                    n_limit,
    int                    align_mode
    );

extern USER_EXITS_API int print_a_row (
    char*                  arow,
    report_entry*          ps,
    int                    n_limit
    );

extern USER_EXITS_API char* infoman_itoa (
    int                     n
    );

extern USER_EXITS_API void setNewReport(void);

extern USER_EXITS_API void setReportOption(
    int                    rpt_option_in /**< (I) */
    );

extern USER_EXITS_API void setOutputDevice(
    FILE*                  device_out
    );

extern USER_EXITS_API FILE* getOutputDevice(void);

extern USER_EXITS_API void Print_Item_AdminData(
    AdminData              admin_data,
    report_entry*          ps,
    int                    n_limit
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <user_exits/libuser_exits_undef.h>

#endif
