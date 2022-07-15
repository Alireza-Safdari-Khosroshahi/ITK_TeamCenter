/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*  */

#ifndef TCFILE_CACHE_H
#define TCFILE_CACHE_H

#include <pom/pom/pom.h>
#include <ss/ss_const.h>
#include <ss/ss_types.h>
#include <sa/libsa_exports.h>

/**
    @defgroup IMF_CACHE Teamcenter File Cache
    @ingroup IMF
    @{
*/

#define  NO_SECURITY  0
#define  SOCKET_MODE  1

enum file_location_type{
    FC_cache,
    FC_temp,
    FC_volume
};

typedef struct IMF_file_data_s{
    tag_t                   fileTag;
    tag_t                   volumeTag;
    char*                   pathName;
    enum file_location_type file_loc;
    char*                   osfile_name;
    char*                   read_ticket;
    logical                 is_transient;
    char*                   orig_file_name;
}IMF_file_data_t;

typedef struct IMF_file_data_s* IMF_file_data_p_t;

#ifdef __cplusplus
extern "C"{
#endif

extern SA_API int IMF_get_cache_size (
    float*        cache_size    /**< (0) */
    );

extern SA_API int IMF_update_cache_size (
    float         bytes_to_add, /**< (I) */
    float*        cache_size    /**< (0) */
    );

extern SA_API void IMF_initialize_file_cache( );

/**
    This function returns a pointer to an #IMF_file_data_p_t structure 
    that will be used by the routine #IMF_get_filename.
    The purpose of the function is to provide access to the file referenced by the file_tag.
    The date_offset value is the time in seconds after January 1, 1970 that
    the modification date of the file should be set to.
    If you don’t care what the modification date of the file is set to,
    use a date_offset value of zero.
*/
extern SA_API int IMF_get_file_access(
    tag_t               file_tag,       /**< (I) */
    int                 date_offset,    /**< (I) */
    IMF_file_data_p_t*  file_data       /**< (O) */
    );

/**
    FMS-aware version of IMF_get_file_access() (see above)
*/
extern SA_API int IMF_fms_get_file_access(
    tag_t               file_tag,       /**< (I) */
    int                 date_offset,    /**< (I) */
    logical             using_fms,      /**< (I) */
    IMF_file_data_p_t*  file_data       /**< (O) */
    );

/**
    This function returns a pointer to a string to which the user has read access. 
    The input parameter is retrieved with a call to #IMF_get_file_access.
*/
extern SA_API int IMF_get_filename(
    IMF_file_data_p_t   file_data,      /**< (I) */
    char**              osfilename      /**< (O) */
    );

/**
    FMS-aware version of IMF_get_filename() (see above)
*/
extern SA_API int IMF_fms_get_filename(
    IMF_file_data_p_t   file_data,      /**< (I) */
    logical             using_fms,      /**< (I) */
    char**              osfilename,     /**< (O) */
    char**              read_ticket,    /**< (O) */
    logical*            is_transient,   /**< (O) */
    char**              orig_file_name  /**< (O) */
    );

/**
    This function is used to release any memory created by the call to #IMF_get_file_access.
    It also either sets the protection of files in the volumes back to
    no access or deletes any temporary files that were created. 
    The input parameter is retrieved with a call to #IMF_get_file_access.
*/
extern SA_API int IMF_release_file_access(
    IMF_file_data_p_t*  file_data   /**< (I/O) */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <sa/libsa_undef.h>

#endif
