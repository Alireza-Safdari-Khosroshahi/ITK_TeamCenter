/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*  */

#ifndef TC_PARAMETERS_H
#define TC_PARAMETERS_H

#include <tc/tc_startup.h>
#include <tccore/libtccore_exports.h>

/**
    @defgroup TCPARAMETERS Teamcenter Parameters
    @ingroup TC
    @{
*/

#define MAX_PARAMETER_ATTR_STRLEN       64
#define TC_PARAMETER_ARG_LIST_ATTR    "parameters"

#ifdef __cplusplus
extern "C"{
#endif

extern TCCORE_API int TC_ask_parameter_values(
    tag_t               tcParameter_tag,  /**< (I) Tag of TcParameter that requires details */
    int*                option_cnt,         /**< (O) Count of parameter values */
    char***             option_values       /**< (OF) option_cnt Parameter Values for the input TcParameter Tag */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <tccore/libtccore_undef.h>

#endif
