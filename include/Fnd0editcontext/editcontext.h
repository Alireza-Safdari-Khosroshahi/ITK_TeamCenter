/*
    Copyright 2020 Siemens Digital Industries Software
    ==================================================
    Copyright 2014.
    Siemens Product Lifecycle Management Software Inc.
    All Rights Reserved.
    ==================================================
    Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    ITK definitions for EditContext module.
*/

#ifndef TEAMCENTER_EDITCONTEXT_H
#define TEAMCENTER_EDITCONTEXT_H

#include <unidefs.h>

#include <Fnd0editcontext/libfnd0editcontext_exports.h>

/**
    @defgroup EDITCONTEXT Edit Context
    @ingroup TC

    This module implements the ITK methods exposed by the EditContext module.

    The EditContext module provides functionality to perform edits in a non-public space,
    such that the public version of the edited objects is not changed. This functionality
    is useful for sharing changes with other users who have access to the edited
    objects, while users without access will continue to work with the public version of
    the objects.

    @{
*/

#ifdef __cplusplus
    extern "C" {
#endif

/**
    Generates Edit Context ID for the given object type.
    If a naming rule is attached, then it is used to generate the new ID.

    @returns
    <ul>
        <li>#ITK_ok on success
        <li>#TYPE_invalid_type_name on error if the object type is invalid
    </ul>
*/
extern FND0EDITCONTEXT_API int EDITCONTEXT_new_edit_context_id (
    tag_t object_type,  /**< (I)  Tag of an object type. */
    char **id           /**< (OF) Generated Edit Context ID. */
    );

/** @} */
#ifdef __cplusplus
                }
#endif

#include <Fnd0editcontext/libfnd0editcontext_undef.h>

#endif
