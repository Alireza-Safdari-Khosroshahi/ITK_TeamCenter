/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file 
    
    This file defines tokens that are used for RDV specific Queries.
    It starts with defining tokens after a certain value defined by pom_tokens.h file.
*/

/** @if DOX_IGNORE
    Caution:

    On the Client side, com.ugsolutions.iman.kernel.IMANQueryOperator.java file
    duplicates operators that are defined in this file to be used on the
    Client side. If any changes ( modifications to existing tokens or adding
    new ones ) are made to this file, please make sure that you change that file too
    otherwise inconsistent search results may be obtained.
@endif */

/*  */

#ifndef RDV_TOKENS_H_INCLUDED
#define RDV_TOKENS_H_INCLUDED

#include <pom/pom/pom_tokens.h>
#include <rdv/librdv_exports.h>

/**
    @defgroup RDV_TOKENS Tokens
    @ingroup RDV
    @{
*/

/**
    @name RDV object type tokens
    @{
*/
#define RDV_object_type_product_itemrev     ( 1 << 0 )
#define RDV_object_type_work_part_item      ( 1 << 1 )
#define RDV_object_type_eng_change          ( 1 << 2 )
#define RDV_object_type_workflow_process    ( 1 << 3 )
#define RDV_object_type_revision_rule       ( 1 << 4 )
#define RDV_object_type_variant_rule        ( 1 << 5 )
#define RDV_object_type_structurecontext    ( 1 << 6 )
#define RDV_object_type_configcontext       ( 1 << 7 )
#define RDV_object_type_appgrp              ( 1 << 8 )
#define RDV_object_type_all                 ( -1 )
/** @} */

/**
    @name RDV Search Result tokens
    @{
*/
#define RDV_return_old_search_results       0 
#define RDV_reevaluate_search_criteria      1 
/** @} */

/**
    @name Operator tokens for building enquiries
    @{
*/
#define RDV_within                          ( 1 << 21 )
#define RDV_outside                         ( 1 << 22 )
#define RDV_interferes                      ( 1 << 23 )
#define RDV_above                           ( 1 << 24 )
#define RDV_below                           ( 1 << 25 )
#define RDV_intersects                      ( 1 << 26 )
/** @} */

/** @} */

#include <rdv/librdv_undef.h>

#endif
