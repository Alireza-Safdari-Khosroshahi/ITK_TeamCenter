/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Function callback for generic aiws interface

This file contains ITK API related to Application Interface module.
*/

/*  */

#ifndef AIWS_USERDATARW__H
#define AIWS_USERDATARW__H

#include <tc/tc_startup.h>

#include <ai/libai_exports.h>

/**
    @defgroup UDATARW AIWS User Data Reader/Writer
    @ingroup PIE
    @{
*/

#ifdef __cplusplus
    extern "C"{
#endif

extern AI_API int AIWS_reader_init(
    const char*    xmlIn,   /**< (I) */
    tag_t*         id       /**< (O) */
    );

extern AI_API int AIWS_reader_num_sections(
    tag_t          id,          /**< (I) */
    int*           numSections  /**< (O) */
    );

extern AI_API int AIWS_reader_find_section(
    tag_t          id,          /**< (I) */
    const char*    key,         /**< (I) */
    int*           sectionNum   /**< (O) */
    );

extern AI_API int AIWS_reader_get_token_value(
    tag_t          id,          /**< (I) */
    int            sectionNum,  /**< (I) */
    const char*    key,         /**< (I) */
    char*          value,       /**< (I,O) */
    size_t         valSize      /**< (I)   */
    );

extern AI_API int AIWS_reader_get_token_values(
    tag_t          id,          /**< (I) */
    int            sectionNum,  /**< (I) */
    const char*    key,         /**< (I) */
    char***        values,      /**< (OF) numValues */
    size_t*        numValues    /**< (O) */
    );

extern AI_API int AIWS_reader_release(
    tag_t          id
    );

extern AI_API int AIWS_writer_init(
    tag_t*         id
    );

extern AI_API int AIWS_writer_startSection(
    tag_t          id,      /**< (I) */
    const char*    section  /**< (I) */
    );

extern AI_API int AIWS_writer_write_kv(
    tag_t          id,          /**< (I) */
    const char*    key,         /**< (I) */
    const char*    value,       /**< (I) */
    int            bCreateNew   /**< (I) */
    );

extern AI_API int AIWS_writer_endSection(
    tag_t          id   /**< (I) */
    );

extern AI_API int AIWS_writer_result(
    tag_t          id,      /**< (I) */
    char**         xmlOut   /**< (OF) */
    );

extern AI_API int AIWS_writer_release(
    tag_t id
    );

#ifdef __cplusplus
}
#endif

/** @} */

#include <ai/libai_undef.h>

#endif
