/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This header file declares all data types and constants to be used by clients of the
    GCR (General Component Relation) module.
*/

/*  */

#ifndef GCR_H
#define GCR_H

#include <stdarg.h>
#include <fclasses/tc_basic.h>
#include <tccore/grm.h>

/**
    @defgroup GCR General Component Relation (GCR)
    @ingroup PS
    @{
*/

#define GCR_class_name_c               "ComponentRelation"

#include <ps/libps_exports.h>

#ifdef __cplusplus
    extern "C"{
#endif

extern int GCR_exit_module();

extern int GCR__initialized();

extern int GCR__exit();

extern PS_API int GCR_create_relation(
    tag_t         primary_object,       /**< (I) */
    tag_t         secondary_object,     /**< (I) */
    tag_t         relation_type,        /**< (I) */
    tag_t         user_data,            /**< (I) */
    tag_t*        relation              /**< (O) */
    );

extern PS_API int GCR_save_relation(
    tag_t         relation      /**< (I) */
    );

extern PS_API int GCR_delete_relation(
    tag_t         relation      /**< (I) */
    );

extern PS_API int GCR_find_relation_type(
    const char*   typeName,         /**< (I) */
    tag_t*        relationType      /**< (O) */
    );

extern PS_API int GCR_set_relation_subtype(
    tag_t         relation,     /**< (I) */
    int           stype         /**< (I) */
    );

extern PS_API int GCR_ask_relation_subtype(
    tag_t         relation,     /**< (I) */
    int*          stype         /**< (O) */
    );

/** @} */

#ifdef __cplusplus
    }
#endif

#include <ps/libps_undef.h>

#endif
