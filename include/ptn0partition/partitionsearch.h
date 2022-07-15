/* Copyright 2020 Siemens Digital Industries Software
 ==================================================
 Copyright 2014.
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2020 Siemens Digital Industries Software */

/**
    @file partitionsearch.h

    This header file declares all ITK APIs required to create a partition search recipe.
    
*/

#ifndef PARTITION_PARTITIONSEARCH_H
#define PARTITION_PARTITIONSEARCH_H

#include <unidefs.h>

#include <ptn0partition/libptn0partition_exports.h>

/**
    @defgroup PARTITIONSEARCH Search

    PartitionSearch provides the ITK developers the ability to create a partition search expression.<br/>
    A partition search expression is used to find members of a partition in a given Application Model.<br/>
    4GD uses this search expression in a Search Recipe to find out design elements that are members of 
    a particular Partition (or sets of partitions).<br/>
    This search expression could be used in combination with the other search expressions that are created
    in the ModelSearch to form a group search expression.

    @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/**
Creates a partition member search expression, that could be used along with other search expressions to create a search recipe.
@returns
<ul>
<li>#ITK_ok on success.
<li>#PTN0PARTITION_search_has_no_valid_criteria if both the partition_search_expr and partition_rev_expr are NULLTAG.
</ul>
*/
extern PTN0PARTITION_API int PARTITIONSEARCH_create_partition_expression(
  tag_t          partition_search_expr,      /**< (I) Search definition tag that would find partitions */
  tag_t          partition_rev_expr,         /**< (I) Search definition tag that would find partition revisions */
  logical        include_child,              /**< (I) Flag indicating whether to include child partitions */
  tag_t*         partition_expression        /**< (O) Tag of the partition member search expression */
  );

#ifdef __cplusplus
}
#endif

/**
  @}
*/

#include <ptn0partition/libptn0partition_undef.h>
#endif
