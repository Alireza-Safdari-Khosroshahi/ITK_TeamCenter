/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Types and definitions used in all Application Encapsulation headers.
*/

/*  */

#ifndef AE_TYPES_H
#define AE_TYPES_H

#include <fclasses/tc_stdlib.h>
#include <ae/libae_exports.h>

/**
    @defgroup AE_TYPES Types
    @ingroup AE
    @{
*/

#define AE_symbol_size_c            1024
#define AE_io_format_size_c         32
#define AE_siteclass_size_c         128
#define AE_vendor_name_size_c       32
#define AE_version_size_c           32
#define AE_reference_size_c         32
#define AE_parameter_size_c         32
#define AE_value_size_c             32
#define AE_dataset_id_size_c        32
#define AE_dataset_rev_size_c       32
#define AE_datasettype_name_size_c  32
#define AE_nra_name_size_c          32
#define AE_datasettype_desc_size_c  1400

typedef enum AE_action_e {
    ACTION_unknown              = 0,
    ACTION_create               = 1,
    ACTION_print                = 2,
    ACTION_open                 = 3,
    ACTION_open_using           = 4,
    ACTION_save_as              = 5,
    ACTION_destroy              = 6,
    ACTION_purge                = 7,
    ACTION_import               = 8,  /**< Currently will not call shell. */
    ACTION_print_using          = 9,
    ACTION_more                 = 10,
    ACTION_import_to_existing   = 11, /**< Currently will not call shell. */
    ACTION_send                 = 12
} AE_action_t;

#define AE_ACTION_COUNT             13

/** @} */

#include <ae/libae_undef.h>
#endif
