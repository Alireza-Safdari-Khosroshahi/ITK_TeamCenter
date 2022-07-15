/*  
    Copyright 2020 Siemens Digital Industries Software
    ==================================================
    Copyright 2014.
    Siemens Product Lifecycle Management Software Inc.
    All Rights Reserved.
    ==================================================
    Copyright 2020 Siemens Digital Industries Software
*/
/** 
    @file partition_user_exits.h
 
    Custom Exit implementation for the getRealizedPartitions SOA operation.
*/

#ifndef TEAMCENTER_PARTITION_USER_EXITS_HXX
#define TEAMCENTER_PARTITION_USER_EXITS_HXX

/**
    @defgroup PARTITION_USER_EXITS Partition User Exits
    @ingroup TC

    Teamcenter has implemented USER_realized_partition_validations user exit 
    which is invoked post the getRealizedPartitions SOA operation. 
    
    It will allow the SOA customers (e.g. PMM) to apply additional validations on the template 
    and/or corresponding realized Partitions.
@{
*/

#include <unidefs.h>
#include <ptn0partition/libptn0partition_exports.h>

/**
    Operation name for the legacy operation to be implemented to provide custom validations
    on the getRealizedPartitions SOA operation output
*/
#define PTN_validate_realized_ptns_msg  "BMF_PTN_validate_realized_ptns"


#ifdef __cplusplus
extern "C"
{
#endif

/**
    User exit implementation for the USER_realized_partition_validations exit
    <br/>It will call the base action registered against it, if any. The base action
    can perform additional filtering of the getRealizedPartitions SOA output by applying 
    further validations and business rules on the Partitions.
    <br/>In case no custom implementation is registered, the input data is copied into the 
    output variables and sent back as it is.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#PTN0PARTITION_internal_error when the operation fails due to any error.
    </ul>
*/
extern PTN0PARTITION_API int USER_realized_partition_validations( 
    int ptn_count,              /**< (I) The count of input template Partitions   */
    const tag_t* template_ptns, /**< (I) ptn_count The template Partitions having realized Partitions */
    const tag_t* realized_ptns, /**< (I) ptn_count The realized Partitions corresponding to template Partitions */
    int* out_ptn_count,         /**< (O) Number of filtered template Partitions */
    tag_t** out_template_ptns,  /**< (OF) out_ptn_count Filtered template Partitions */
    tag_t** out_realized_ptns   /**< (OF) out_ptn_count Filtered realized Partitions corresponding to template Partitions */
);
/** @} */

#ifdef __cplusplus
}
#endif

#include <ptn0partition/libptn0partition_undef.h>
#endif
