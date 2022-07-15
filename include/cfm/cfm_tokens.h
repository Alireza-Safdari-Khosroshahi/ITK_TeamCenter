/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Token definitions for the CFM module
*/

/*  */

#ifndef CFM_TOKENS_H
#define CFM_TOKENS_H

#ifdef __cplusplus

#endif

#include <pom/pom/pom.h>
#include <cfm/libcfm_exports.h>

/**
    @defgroup CFM_TOKENS Tokens
    @ingroup CFM
    @{
*/

/**
    @name Configuration Rules
    @{
*/
#define CFM_MIN_CONFIG_RULE                 1
#define CFM_specific                        1
#define CFM_latest                          2
#define CFM_latest_status                   3
#define CFM_latest_date_effective           4
#define CFM_latest_num_effective            5
#define CFM_latest_num_or_date_effective    6
#define CFM_MAX_CONFIG_RULE                 6
/** @} */

#define CFM_null_date                       (POM_null_date())
#define CFM_null_unit_number                -1

/** @} */

#include <cfm/libcfm_undef.h>

#ifdef __cplusplus

#endif

#endif
