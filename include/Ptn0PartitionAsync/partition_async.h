/* Copyright 2020 Siemens Digital Industries Software
** ==================================================
** Copyright 2018.
** Siemens Product Lifecycle Management Software Inc.
** All Rights Reserved.
** ==================================================
** Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    This header file declares structures and asynchronous APIs to be used for Partition Management. 
*/


#ifndef TEAMCENTER_PARTITIONASYCN_H
#define TEAMCENTER_PARTITIONASYCN_H

#include <mdl0model/modelsearch_types.h>


#include <Ptn0PartitionAsync/libPtn0PartitionAsync_exports.h>

/**
    @defgroup PARTITIONASYNC Partition Template
    @ingroup TC

    Allows users to export search results to MS Excel in sync or async mode.

    @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/**
 Defines Partition scope for the search results arrangement. <code>PartitionScope</code>
 has a partition scheme name by which the results should be organized by and a flag
 that indicates whether immediate partitions should be considered or to consider the
 whole partition breakdown structure while returning back the partition groups.
*/
struct Ptn0PartitionScope
{
    tag_t   scheme;                             /**< Input partition scheme within which the partition results are required. */
    logical is_only_immediate_groups_required;  /**< Flag to indicate whether only Immediate hierarchy of Partition to members are required. Setting this flag to false, will return all the Partition hierarchy till the root. */
};

/**
    Performs a recipe-based search and exports the search results to an MS Excel file.

  @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#REQ_no_attributes_for_export,          if the column attributes to be exported are empty.
    <li>#REQ_applicaton_format_not_supported,   if the application format is not supported.
    <li>#MDL0MODEL_invalid_application_model,   if the application mode is not a sub type of Mdl0ApplicationModel
    </ul>
*/
extern PTN0PARTITIONASYNC_API int PARTITIONASYNC_execute_search_and_export (
    const Mdl0SearchOption      *search_option,         /**< (I) Serach option for the given search. */ 
    const Ptn0PartitionScope    *scope,                 /**< (I) Scope for search results arrangement. <br/> This parameter is ignored for the moment.*/ 
    const Mdl0SearchRecipe      *recipe,                /**< (I) Recipe for performing the search. */ 
    const Mdl0ExportOption      *export_option,         /**< (I) Mode of the export to be used. */ 
    tag_t                       *dataset                /**< (O) Dataset which contains the MS Excel file. It is returned only when run in INPROCESS mode. */ 
    );



#ifdef __cplusplus
}
#endif

/**
  @}
*/

#include <Ptn0PartitionAsync/libPtn0PartitionAsync_undef.h>
#endif
