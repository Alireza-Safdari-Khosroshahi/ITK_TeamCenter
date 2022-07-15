/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Contains utility functions for the EPM and CR action handlers
*/

/*  */

#ifndef EPM_TOOLKIT_UTILS_H
#define EPM_TOOLKIT_UTILS_H

#include <base_utils/Mem.h>
#include <pom/pom/pom.h>
#include <epm/epm.h>
/** @if DOX_IGNORE
#include <epm/epm_toolkit_tc_utils.h>
@endif */

/**
    @defgroup EPM_TOOLKIT_UTILS EPM (Enterprise Process Modeling) Toolkit Utilities 
    @ingroup USER_EXITS
    @{
*/

#define IS_A_TARGET                    (1)
#define GROUP_DATA_TYPE                "Group"
#define ROLE_DATA_TYPE                 "Role"
#define USER_DATA_TYPE                 "User"
#define PERSON_DATA_TYPE               "Person"
#define ADLIST_DATA_TYPE               "AddressList"
#define ALLMEMBERS_DATA_TYPE           "Allmembers"
#define RESOURCEPOOL_DATA_TYPE         "RESOURCEPOOL"

#define SAFE_SM_FREE( a )   \
do                          \
{                           \
    if ( (a) != NULL )      \
    {                       \
        MEM_free( (a) );    \
        (a) = NULL;         \
    }                       \
}                           \
while ( 0 )

struct counted_list_s{
    int      count;
    char**   list;
};

typedef struct counted_list_s counted_list_t;

extern const counted_list_t NULL_COUNTED_LIST;

struct counted_tag_list_s{
    int     count;
    tag_t*  list;
};

typedef struct counted_tag_list_s counted_tag_list_t;

extern const counted_tag_list_t NULL_COUNTED_TAG_LIST;

#include <user_exits/libuser_exits_exports.h>

#ifdef __cplusplus
    extern "C"{
#endif

#if 0
extern USER_EXITS_API int EPM__get_task_and_att(
    const char*           value,            /**< (I) */
    tag_t                 curr_task,        /**< (I) */
    tag_t*                task_tag,         /**< (O) */
    int*                  attachment_type   /**< (O) */
    );
#endif

extern USER_EXITS_API int EPM__ask_if_target(
    tag_t                 related_objects,  /**< (I) */
    tag_t*                target_objects,   /**< (I) */
    int                   target_count      /**< (I) */
    );

extern USER_EXITS_API int EPM__ask_data_type_and_value(
    const char*           normal_value,     /**< (I) */
    char**                data_type,        /**< (OF) */
    char**                value             /**< (OF) */
    );

#if 0
extern USER_EXITS_API int EPM__display_form_should_show(
    EPM_action_message_t  msg,        /**< (I) */
    int*                  n_forms,    /**< (O) */
    tag_t**               forms       /**< (OF) n_forms */
    );
#endif

/**
   This function will append the @p tag at the end of the @p tag_list.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#SS_NOMEM if fails to allocate memory dynamically for new tag
   </ul>
   @note Here @p tag_list should point to a dynamically allocated memory block of size 16xsizeof(tag_t) before calling to add 
   first tag to @p tag_list. When user go on adding tags and list size exeeds 16 tnen this API allocate memory dynamically for new tag.
*/

extern USER_EXITS_API int EPM__add_to_tag_list(
    tag_t                 tag,      /**< (I) The tag to append at the end of @p tag_list */
    counted_tag_list_t*   tag_list  /**< (OF) List of tags */
    );

extern USER_EXITS_API int EPM__parse_string(
                             const char   *pszInputString,     /**< (I) */
                             char   *pszSeparator,       /**< (I) */
                             int    *piStringCount,      /**< (O) */
                             char ***pppStringList       /**< (OF) */
                      );




extern USER_EXITS_API int EPM_register_toolkit_handlers(void);

#ifdef __cplusplus
}
#endif

/** @} */

#include <user_exits/libuser_exits_undef.h>

#endif

