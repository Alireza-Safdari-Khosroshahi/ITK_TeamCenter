/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    CMP tokens
*/

/*  */

#ifndef CMP_TOKENS_H
#define CMP_TOKENS_H

#include <fclasses/tc_basic.h>
#include <unidefs.h>
#include <fclasses/libfclasses_exports.h>


#ifdef __cplusplus
    extern "C" {
#endif

/**
    @defgroup CMP_TOKENS Tokens
    @ingroup CMP
    @{
*/


typedef enum
{
    CMP_LHS,
    CMP_RHS
} CMP_side_e;

typedef enum
{
    CMP_primary_element,
    CMP_aggregate_element,
    CMP_display_element
} CMP_priority_e;

typedef enum
{
    CMP_property_element,
    CMP_external_element
} CMP_element_type_e;

typedef enum
{
    CMP_cache_auto = -2,    /**< Selects 'best' cache type based on property value type */
    CMP_cache_sync,         /**< Cache type matches property value type(primary value type only(e.g.int,double,float,char))*/
    CMP_cache_none,
    CMP_cache_char,
    CMP_cache_date,
    CMP_cache_double,
    CMP_cache_float,
    CMP_cache_integer,
    CMP_cache_logical,
    CMP_cache_short,
    CMP_cache_string,
    CMP_cache_tag,
    CMP_cache_char_array,
    CMP_cache_date_array,
    CMP_cache_tag_array,
    CMP_cache_string_array,
    CMP_cache_pointer
} CMP_cache_type_e;

/** @if DOX_IGNORE
    Keep this in step with IS_CMP_ORDER_E() below
@endif */
typedef enum
{
    CMP_order_by_value,
    CMP_order_by_length_and_value
} CMP_order_e;

#define IS_CMP_ORDER_E(a) ( ( CMP_order_by_value <= (a) ) && ( (a) <= CMP_order_by_length_and_value ) )

typedef int (CMP_compare_obj_method_t)(
    tag_t eim_object,
    tag_t compare_set,
    tag_t compare_element,
    int*  result
    );

typedef int (CMP_compare_agg_method_t)(
    tag_t compare_set,
    tag_t compare_element,
    int*  result
    );

typedef int (CMP_update_cache_method_t)(
    tag_t      compare_set,
    CMP_side_e side,
    tag_t      eim_object,
    tag_t      compare_element
    );

typedef int (CMP_uif_name_method_t)(
    tag_t  compare_element,
    char** display_name
    );

typedef int (CMP_uif_value_method_t)(
    tag_t      compare_set,
    CMP_side_e side,
    tag_t      compare_element,
    char**     display_value
    );

typedef int (CMP_free_cache_method_t)(
    void* externalCache,
    tag_t compare_element
    );

/** @} */

#ifdef __cplusplus
    }
#endif

#include <fclasses/libfclasses_undef.h>
#endif
