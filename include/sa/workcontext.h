/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This header file declares all the functions to be used
    by clients of the Work Context class.

    <b>Restrictions:</b>

    This include file should not generally be used by anyone.
    Normally sa.h should be included instead.
*/

/*  */

#ifndef WORKCONTEXT_H 
#define WORKCONTEXT_H

#include <sa/sa.h>

#include <sa/libsa_exports.h>

/**
    @defgroup WORKCONTEXT WorkContext
    @ingroup SA
    @{
*/

#ifdef __cplusplus
    extern "C"{
#endif

/**
    Create a new work context with the given name, desc, group, role, user, project.
*/
extern SA_API int SA_create_work_context (
    const char*    name,               /**< (I) */
    const char*    desc,               /**< (I) */
    tag_t          group,              /**< (I) */
    tag_t          role,               /**< (I) */
    tag_t          user,               /**< (I) */
    tag_t          project,            /**< (I) */
    logical allowSubgroups,            /**< (I) */
    logical settingModifiable,         /**< (I) */
    tag_t*         newWorkContext      /**< (O) */
);

/**
    Assign the given workcontext to the given target.
*/
extern SA_API int SA_assign_work_context (
    tag_t          workcontext,              /**< (I) */
    tag_t          target                    /**< (I) */
);

/**
    remove the given workcontext from the given target.
*/
extern SA_API int SA_remove_work_context (
    tag_t          workcontext,              /**< (I) */
    tag_t          target                    /**< (I) */
);

/**
    set the given workcontext as Current Work Context for the session.
*/
extern SA_API int SA_set_current_work_context (
    tag_t          workcontext              /**< (I) */
);

/**
    set the given project as Current Project for the session.
*/
extern SA_API int SA_set_current_project (
    tag_t          project              /**< (I) */
);

/**
    return the Current Work Context for the session.
*/
extern SA_API int SA_ask_current_work_context (
    tag_t          *workcontext              /**< (O) */
);

/**
    return the Current Project for the session.
*/
extern SA_API int SA_ask_current_project (
    tag_t          *project              /**< (O) */
);

/**
    return the work contexts associated with the user's workflow tasks (Tasks to Perform) or their targets .
*/
extern SA_API int SA_ask_user_work_contexts (
    tag_t          user,                     /**< (I) */
    int            *n_workcontexts,          /**< (O) */
    tag_t          **workcontexts            /**< (OF) n_workcontexts */
);

/**
    set the given organization/group as Current Organization for the session.
*/
extern SA_API int SA_set_current_organization (
    tag_t          organizationTag            /**< (I) */
);

/**
    return the Current Organization for the session.
*/
extern SA_API int SA_ask_current_organization (
    tag_t          *organizationTag           /**< (O) */
);

/**
    return the Current LocationCode for the session.
*/
extern SA_API int SA_ask_current_location_code  (
    char          **locCodePref           /**< (OF) */
);

/**
    set the Current LocationCode for the session
*/
extern SA_API int SA_set_current_location_code  (
    char          *locCodePref            /**< (I) */
);

/**
    Retrieves the current User Context of the session.
    Returns ITK_ok, always
*/
extern SA_API int SA_ask_current_user_context (
    tag_t          *user_context              /**< (O)  The session current User Context */
);

/** @} */

#ifdef __cplusplus
}
#endif

#include <sa/libsa_undef.h>
#endif


