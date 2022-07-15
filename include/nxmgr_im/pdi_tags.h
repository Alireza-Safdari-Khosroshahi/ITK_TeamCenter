/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Typed tag definition for PDI interface to provide additional type checking
    while using the PDI interface. It is included by pdi.h
*/

/*  */

#ifndef PDI_TAGS_H_INCLUDED
#define PDI_TAGS_H_INCLUDED

#include <nxmgr_im/libnxmgr_im_exports.h>

#ifdef __lint
#pragma uginclude only_in_error "pdi.h";
#endif

/** @if DOX_IGNORE
    (PDH) 08-Oct-97
    Special definition code for UGMRPRIVATE and UGMRGLOBAL so that we get the right
    effect for IMAN or UG compilation. IMAN has no concept of this just now so we
    have to put it in for ourselves. This is the only place right now where this is
    needed.
@endif */

/** @if DOX_IGNORE
    (APB) 23-Dec-1997
    This file is different on the IMAN and UG side because of the UGMRGLOBAL stuff,
    so be careful when merging!
@endif */
#ifdef __lint
    #define UGMRGLOBAL extern __global(ugmr)
#elif !defined(WNT)
    #define UGMRGLOBAL extern
#elif IPLIB==libugmr
    #define UGMRGLOBAL extern
#else
    #define UGMRGLOBAL extern
#endif

#ifdef __lint
    #define UGMRPRIVATE extern __private(ugmr)
#else
    #define UGMRPRIVATE extern
#endif

/**
    @defgroup PDI_TAGS Product Data Interface Tags
    @ingroup PDI
    @{
*/

/**
    Basic PDI tag definition
*/
#define PDI_NULL_TAG    ((PDI_tag_t)0)

typedef unsigned int PDI_tag_t, *PDI_tag_p_t;

UGMRPRIVATE PDI_tag_t PDI_null_tag;

/**
    Class: Object
*/
typedef struct PDI_object_tag_s{
    PDI_tag_t  tag;
} PDI_object_tag_t, *PDI_object_tag_p_t;

UGMRPRIVATE PDI_object_tag_t PDI_null_object_tag;

/**
    Class: Model Object
*/
typedef struct PDI_modelobj_tag_s{
    PDI_tag_t  tag;
} PDI_modelobj_tag_t, *PDI_modelobj_tag_p_t;

UGMRPRIVATE PDI_modelobj_tag_t PDI_null_modelobj_tag;

/**
    Class: Part
*/
typedef struct PDI_part_tag_s{
    PDI_tag_t  tag;
} PDI_part_tag_t, *PDI_part_tag_p_t;

UGMRGLOBAL PDI_part_tag_t PDI_null_part_tag;

/**
    Class: Part Revision
*/
typedef struct PDI_partrev_tag_s{
    PDI_tag_t  tag;
} PDI_partrev_tag_t, *PDI_partrev_tag_p_t;

UGMRPRIVATE PDI_partrev_tag_t PDI_null_partrev_tag;

/**
    Class: Representation
*/
typedef struct PDI_rep_tag_s{
    PDI_tag_t  tag;
} PDI_rep_tag_t, *PDI_rep_tag_p_t;

UGMRPRIVATE PDI_rep_tag_t PDI_null_rep_tag;

/**
    Class: Representation Revision
*/
typedef struct PDI_reprev_tag_s{
    PDI_tag_t  tag;
} PDI_reprev_tag_t, *PDI_reprev_tag_p_t;

UGMRPRIVATE PDI_reprev_tag_t PDI_null_reprev_tag;

/**
    Class: Component
*/
typedef struct PDI_component_tag_s{
    PDI_tag_t  tag;
} PDI_component_tag_t, *PDI_component_tag_p_t;

UGMRPRIVATE PDI_component_tag_t PDI_null_component_tag;

/**
    Class: Application Data Object
*/
typedef struct PDI_appdata_tag_s{
    PDI_tag_t  tag;
} PDI_appdata_tag_t, *PDI_appdata_tag_p_t;

UGMRPRIVATE PDI_appdata_tag_t PDI_null_appdata_tag;

/**
    Class: Application Data Version
*/
typedef struct PDI_appver_tag_s{
    PDI_tag_t  tag;
} PDI_appver_tag_t, *PDI_appver_tag_p_t;

UGMRGLOBAL PDI_appver_tag_t PDI_null_appver_tag;

/**
    Class: Application Data Type
*/
typedef struct PDI_apptype_tag_s{
    PDI_tag_t  tag;
} PDI_apptype_tag_t, *PDI_apptype_tag_p_t;

UGMRPRIVATE PDI_apptype_tag_t PDI_null_apptype_tag;

/**
    Class: Relationship Type
*/
typedef struct PDI_reltype_tag_s{
    PDI_tag_t  tag;
} PDI_reltype_tag_t, *PDI_reltype_tag_p_t;

UGMRPRIVATE PDI_reltype_tag_t PDI_null_reltype_tag;

/**
    Class: Relationship
*/
typedef struct PDI_relation_tag_s{
    PDI_tag_t  tag;
} PDI_relation_tag_t, *PDI_relation_tag_p_t;

UGMRPRIVATE PDI_relation_tag_t PDI_null_relation_tag;

/**
    Class: Container Object
*/
typedef struct PDI_container_tag_s{
    PDI_tag_t  tag;
} PDI_container_tag_t, *PDI_container_tag_p_t;

UGMRPRIVATE PDI_container_tag_t PDI_null_container_tag;

/**
    Class: Containable Object
*/
typedef struct PDI_containable_tag_s{
    PDI_tag_t  tag;
} PDI_containable_tag_t, *PDI_containable_tag_p_t;

UGMRPRIVATE PDI_containable_tag_t PDI_null_containable_tag;

/**
    Class: Attribute Type
*/
typedef struct PDI_attrtype_tag_s{
    PDI_tag_t  tag;
} PDI_attrtype_tag_t, *PDI_attrtype_tag_p_t;

UGMRPRIVATE PDI_attrtype_tag_t PDI_null_attrtype_tag;

/**
    Class: Attribute
*/
typedef struct PDI_attribute_tag_s{
    PDI_tag_t  tag;
} PDI_attribute_tag_t, *PDI_attribute_tag_p_t;

UGMRPRIVATE PDI_attribute_tag_t PDI_null_attribute_tag;

/**
    Class: Part Type
*/
typedef struct PDI_parttype_tag_s{
    PDI_tag_t  tag;
} PDI_parttype_tag_t, *PDI_parttype_tag_p_t;

UGMRPRIVATE PDI_parttype_tag_t PDI_null_parttype_tag;

/**
    Class: Attribute Mapping Type
*/
typedef struct PDI_attr_mapping_tag_s{
    PDI_tag_t  tag;
} PDI_attr_mapping_tag_t, *PDI_attr_mapping_tag_p_t;

UGMRPRIVATE PDI_attr_mapping_tag_t PDI_null_attr_mapping_tag;

/**
    Class: LOV
*/
typedef struct PDI_lov_tag_s{
    PDI_tag_t  tag;
} PDI_lov_tag_t, *PDI_lov_tag_p_t;

UGMRPRIVATE PDI_lov_tag_t PDI_null_lov_tag;

/**
    Class: Opaque object
*/
typedef struct PDI_opaque_object_tag_s{
    PDI_tag_t  tag;
} PDI_opaque_object_tag_t, *PDI_opaque_object_tag_p_t;

UGMRPRIVATE PDI_opaque_object_tag_t PDI_null_opaque_object_tag;

/** @} */

#include <nxmgr_im/libnxmgr_im_undef.h>
#endif
