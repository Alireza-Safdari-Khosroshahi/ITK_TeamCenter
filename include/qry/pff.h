/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This file contains PFF ITK for general public.
*/

/*  */

#ifndef PFF_H
#define PFF_H

#include <unidefs.h>

/**
    @defgroup PFF Property Formatter and Finder (PFF)
    @ingroup QRY
    @{
*/

/**
    @name Define attribute size
    @{
*/
#define PFF_name_size_c               128
#define PFF_desc_size_c               240
#define PFF_class_size_c               32
#define PFF_clause_size_c             240
/** @} */

#include <qry/libqry_exports.h>

/**
    Defined for report writer user exits
*/
typedef int (* REPORT_user_column_function_t) (
    tag_t   pff_tag,
    tag_t*  obj_tags,
    int     n_tags,
    char**  output
    );

typedef struct REPORT_user_column_entry_s
{
    char*                           column_name;
    REPORT_user_column_function_t   user_method;
} REPORT_user_column_entry_t;

#ifdef __cplusplus
    extern "C"{
#endif

/**
   Retrieves the name
 */
extern QRY_API int PFF_ask_name2(
    tag_t          pff_tag,                     /**< (I) */
    char           **qname                      /**< (OF) */
    );


/**
   Sets the name
 */
extern QRY_API int PFF_set_name2(
    tag_t          pff_tag,                     /**< (I) */
    const char     *qname                       /**< (I) */
    );


/**
   Retrieves the description
 */
extern QRY_API int PFF_ask_description2(
    tag_t          pff_tag,                     /**< (I) */
    char           **qdesc                      /**< (OF) */
    );



/**
   Sets the description.
 */
extern QRY_API int PFF_set_description2(
    tag_t          pff_tag,                     /**< (I) */
    const char     *qdesc                       /**< (I) */
    );


/**
   Retrieves the class name.
*/
extern QRY_API int PFF_ask_class2(
    tag_t          pff_tag,                     /**< (I) */
    char           **qclass                     /**< (OF) */
    );


/**
   Sets the class name.
*/
extern QRY_API int PFF_set_class2(
    tag_t          pff_tag,                     /**< (I) */
    const char     *qclass                      /**< (I) */
    );

extern QRY_API int PFF_ask_clauses(
    tag_t          pff_tag,     /**< (I) */
    char**         qclauses     /**< (OF) */
    );

extern QRY_API int PFF_set_clauses(
    tag_t          pff_tag,     /**< (I) */
    const char*    qclauses     /**< (I) */
    );


/**
   Retrieves the saved query.
*/
extern QRY_API int PFF_find2(
    const char     *name,                       /**< (I) */
    tag_t*         pff_tag                      /**< (O) */
    );

extern QRY_API int PFF_extent(
    int*           pff_count,   /**< (O) */
    tag_t**        pff_tag      /**< (OF) pff_count */
    );

extern QRY_API int PFF_write_xml(
    tag_t          pff_tag,             /**< (I) */
    int            num_tuples,          /**< (I) */
    int            num_tags_per_tuple,  /**< (I) */
    tag_t*         tuples,              /**< (I) */
    char*          output_file_name     /**< (I) */
    );

extern QRY_API int PFF_write_xml_with_clauses(
    tag_t          pff_tag,             /**< (I) */
    int            num_tuples,          /**< (I) */
    int            num_tags_per_tuple,  /**< (I) */
    tag_t*         tuples,              /**< (I) */
    int            num_clauses,         /**< (I) */
    char**         clauses,             /**< (I) */
    char*          output_file_name     /**< (I) */
    );

extern QRY_API int PFF_describe_pff(
    tag_t          pff_tag,             /**< (I) */
    int*           num_clauses,         /**< (O) */
    char***        column_names,        /**< (OF) num_clauses */
    char***        relation_to_base     /**< (OF) num_clauses */
    );



/** 
    Creates a PFF.
*/
extern QRY_API int PFF_create2(
    const char     *name,                           /**< (I) */
    const char     *qdesc,                          /**< (I) */
    const char     *qclass,                         /**< (I) */
    const char*    qclauses,                        /**< (I) */ 
    tag_t*         pff_tag                          /**< (O) */
    );


extern QRY_API void PFF_register_user_columns (
    int                         n_columns,      /**< (I) */
    REPORT_user_column_entry_t* column_methods  /**< (I) */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <qry/libqry_undef.h>

#endif
