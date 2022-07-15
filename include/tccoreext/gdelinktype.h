/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*  */

#ifndef GDELINKTYPE_H_INCLUDED
#define GDELINKTYPE_H_INCLUDED

#include <tccoreext/libtccoreext_exports.h>

#ifdef __cplusplus
    extern "C"{
#endif

/**
    @defgroup GDELINKTYPE Link Type
    @ingroup GDE

    This module defines the required ITK interface for managing the GeneralDesignElementLinkType.
    @{
*/

/**
    This function returns the default class name that is set for a given GDELink Type.
*/
extern TCCOREEXT_API int GDELinkType_ask_def_class_name(
    tag_t                   gde_link_type_tag,  /**< (I) Tag of the GDELink Type */
    char**                  def_class_name      /**< (OF) Default class name that is set for the GDELink Type */
    );

/** @} */

#ifdef __cplusplus
    }
#endif

#include <tccoreext/libtccoreext_undef.h>

#endif
