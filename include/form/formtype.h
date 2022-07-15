/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Contains a macro and some defines for form_types
*/

/*  */

#ifndef FORMTYPE_H
#define FORMTYPE_H

#include <form/libform_exports.h>

#ifdef __cplusplus
    extern "C"{
#endif

/**
    @defgroup FORM_TYPES Types
    @ingroup FORM
    @{
*/

/**
    Retrieves the form definition class name of the specified FormType.

    Returns a zero-length string if a POM storage class is not defined.
*/
extern FORM_API int FORMTYPE_ask_def_class_name(
    tag_t           form_type_tag,          /**< (I) */
    char**          def_class_name          /**< (OF) */
    );

/** @} */
#ifdef __cplusplus
}
#endif

#include <form/libform_undef.h>
#endif
