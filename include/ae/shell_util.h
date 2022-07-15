/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This include file contains constants, data structure definitions,
    macro definitions and prototypes that will be common to most shells.
*/

/*  */

#ifndef SHELL_UTIL_H
#define SHELL_UTIL_H

#include <fclasses/tc_stdlib.h>
#include <tc/tc_startup.h>
#include <ae/ae.h>
#include <ae/libae_exports.h>

/**
    @defgroup SHELL_UTIL Shell Utilities
    @ingroup AE
    @{
*/

#define  COMMAND_SIZE           256
#define  FILENAME_SIZE          64

#define METRIC                  1
#define ENGLISH                 2

#define NX_MAX_LEN_FILENAME     132
#define NX_MAX_LEN_PATHNAME     256
#define NX_PART_EXT             "prt"
#define REV_ONE                 1

/**
    @name NX part file's named reference
    @{
*/
#define REF_NAME                "UGPART"
#define FORM_REF_NAME           "UGPART-ATTR"
#define FORM_NAME               "UGPART-ATTR"
#define FORM_DESC               "This is a form for UGPART"
#define CHECK_SCALE_PREF_NAME   "TC_NX_CHECK_SCALE"
#define UPDATE_ATTR_PREF_NAME   "TC_NX_UPDATE_ATTRIBUTES"
#define DEFAULT_PART_PREF_NAME  "TC_NX_DEFAULT_PART"
#define UGPART_DATASET_FORM     "TC_NX_ATTRIBUTES_FORM"
#define UGPART_ATTR_FORMTYPE    "UGPartAttr"
/** @} */

#ifdef __cplusplus
 extern "C"{
#endif

extern AE_API int NXSM_create_ugpart_form(
    tag_t,      /**< (I) */
    tag_t*      /**< (O) */
    );

extern int SHELL_change_volume(
    tag_t  dataset_tag,  /**< (I) */
    tag_t* old_volume    /**< (O) */
    );

extern int SHELL_restore_volume(
    tag_t  old_volume    /**< (I) */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <ae/libae_undef.h>
#endif
