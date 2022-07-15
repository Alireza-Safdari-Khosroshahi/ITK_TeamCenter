/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This header file declares all functions to be used by RDV QPL Clients.
*/

/*  */

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#ifndef RDV_QPL_API_H
#define RDV_QPL_API_H

#include <rdv/rdv.h>
#include <rdv/librdv_exports.h>

/**
    @defgroup RDV_QPL_API QPL
    @ingroup RDV
    @{
*/

#define QPL_qpl_server_down    1
#define QPL_qpl_send_failure   2
#define QPL_socket_failure     3
#define QPL_connection_failure 4
#define QPL_out_of_space       5
#define QPL_qpl_bookmark_error 6
#define QPL_warning            7
#define QPL_license_failure    8
#define QPL_stale_qpl_server   9
#define QPL_qpl_config_error   10
#define QPL_qpl_server_busy    11

#ifdef __cplusplus
extern "C" {
#endif

extern RDV_API int RDV_getQPLBuilds(
    int*           buildCount,  /**< (O) */
    char***        buildInfo    /**< (OF) buildCount */
    );

extern RDV_API int RDV_getQPLSchema(
    RDV_search_engine_id_t  engine_id,  /**< (I) */
    int*                    attCount,   /**< (O) */
    char***                 attList     /**< (OF) attCount */
    );

extern RDV_API int RDV_executeQPLFilter(
    RDV_search_engine_id_t  engine_id,          /**< (I) */
    char*                   distance,           /**< (I) */
    char*                   booleanOperator,    /**< (I) */
    int                     attCount,           /**< (I) */
    char**                  attNames,           /**< (I) */
    char**                  attOps,             /**< (I) */
    char**                  attValues,          /**< (I) */
    int                     zoneAttrCount,      /**< (I) */
    char**                  zoneAttrNames,      /**< (I) */
    char**                  zoneAttrOps,        /**< (I) */
    int                     occCount,           /**< (I) */
    char**                  occTags,            /**< (I) */
    int*                    resOccCount,        /**< (O) */
    char***                 resOccTags          /**< (OF) resOccCount */
    );

extern RDV_API int RDV_getExecuteQPLFilterCount(
    RDV_search_engine_id_t  engine_id,          /**< (I) */
    char*                   distance,           /**< (I) */
    char*                   booleanOperator,    /**< (I) */
    int                     attCount,           /**< (I) */
    char**                  attNames,           /**< (I) */
    char**                  attOps,             /**< (I) */
    char**                  attValues,          /**< (I) */
    int                     zoneAttrCount,      /**< (I) */
    char**                  zoneAttrNames,      /**< (I) */
    char**                  zoneAttrOps,        /**< (I) */
    int                     occCount,           /**< (I) */
    char**                  occTags,            /**< (I) */
    int*                    resOccCount,        /**< (O) */
    char***                 resOccTags          /**< (OF) resOccCount */
    );

#ifdef __cplusplus
    }
#endif

/** @} */

#include <rdv/librdv_undef.h>

#endif
