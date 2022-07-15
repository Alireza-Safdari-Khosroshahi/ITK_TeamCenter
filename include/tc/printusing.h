/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*  */

#ifndef PRINTUSING_H
#define PRINTUSING_H

#include <ae/shell_util2.h>
#include <tc/libtc_exports.h>

/**
    @defgroup PRINTUSING Print Using
    @ingroup TC
    @{
*/

#ifdef __cplusplus
 extern "C"{
#endif

extern TC_API int find_dwg (
    char*           file_name,
    char*           grip_file,
    int*            sts,
    void*           args
    );

extern TC_API void remove_files(void);

extern TC_API void GS_nx_find_dwg(
    char*            grip_file,
    void*            args
    );

extern TC_API void GS_nx_plot_dwg(
    char*            grip_file,
    char*            params_file_buf
    );

extern TC_API int plot_dwg(
    char*           file_name,
    char*           grip_file,
    char*           plotter,
    NAME_1          dwg_name[],
    char*           job_name,
    int*            sts
    );

extern TC_API void* find_drawing_handler(
    void*             args
    );

extern TC_API void PrintUsing(
    tag_t*           file_tag,
    const char*      dataset_name
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <tc/libtc_undef.h>
#endif
