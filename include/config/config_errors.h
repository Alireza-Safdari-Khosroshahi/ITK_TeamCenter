/*=============================================================================
 Copyright 2020 Siemens Digital Industries Software
 ==================================================
 Copyright 2015
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2020 Siemens Digital Industries Software
 ===============================================================================*/

/** 
    @file 

    Teamcenter::Bob errors include file.

*/

#ifndef CONFIG_ERRORS_H
#define CONFIG_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup CONFIG_ERRORS CONFIG Errors
    @ingroup CONFIG
    @{
*/

#define CONFIG_internal_error                          (EMH_CONFIG_error_base +   0)
#define CONFIG_query_already_built                     (EMH_CONFIG_error_base +   1)
#define CONFIG_query_not_built                         (EMH_CONFIG_error_base +   2)
/** The following Config feature is not supported: %1$. */
#define CONFIG_feature_not_supported                   (EMH_CONFIG_error_base +   3)

/** @} */

#endif
