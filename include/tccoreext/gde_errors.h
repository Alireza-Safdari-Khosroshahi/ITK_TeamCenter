/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    General Design Element errors
*/

/*  */

#ifndef GDE_ERRORS_H
#define GDE_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup GDE_ERRORS Errors
    @ingroup GDE
    @{
*/

/**
    GDE internal error
*/
#define GDE_internal_error                 (EMH_GDE_error_base + 1)
/**
    Cardinality must be greater or equal to zero
*/
#define GDE_invalid_cardinality            (EMH_GDE_error_base + 2)
/**
    The target BVR's view type is not an allowed view type for this GDEType
*/
#define GDE_disallowed_view_type           (EMH_GDE_error_base + 3)
/**
    The given view type is invalid or NULLTAG
*/
#define GDE_invalid_view_type              (EMH_GDE_error_base + 4)
/**
    A GDETypeDefinition object must be attached to a GDE type to create a GDE Bomview Revision
*/
#define GDE_bvr_deftype_does_not_exist     (EMH_GDE_error_base + 5)
/**
    Object is not locked
*/
#define GDE_object_is_not_locked           (EMH_GDE_error_base + 6)
/**
    GDEBomViewRevision already exists for the given GDE
*/
#define GDE_bvr_already_exist              (EMH_GDE_error_base + 7)
/**
    Cannot remove the occurrence, it references incremental changes
*/
#define GDE_cant_cut_occurrence            (EMH_GDE_error_base + 8)  
/**
    Cannot add Object of type - %1$, since the maximum allowed occurrences is set to %2$
*/
#define GDE_cardinality_reached            (EMH_GDE_error_base + 9)
/** @} */

#endif
