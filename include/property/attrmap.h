/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    ITK for Attribute-mapping
*/

/*  */

#ifndef ATTRMAP_H
#define ATTRMAP_H

#include <unidefs.h>
#include <tc/preferences.h>
#include <property/libproperty_exports.h>

/**
    @defgroup ATTRMAP Attribute Mapping
    @ingroup PROP
    @{
*/

typedef enum ATTRMAP_mapping_type_e
{
    ATTRMAP_unknown,
    ATTRMAP_property,
    ATTRMAP_constant,
    ATTRMAP_preference,
    ATTRMAP_attribute
} ATTRMAP_mapping_type_t;

#ifdef __cplusplus
extern "C"{
#endif

extern PROPERTY_API int ATTRMAP_init_module ( void );

extern PROPERTY_API int ATTRMAP_refresh_mappings ( void );

extern PROPERTY_API int ATTRMAP_in_test_mode(
    logical*            verdict     /**< (O) */
    );

extern PROPERTY_API int ATTRMAP_assert_in_test_mode(
    logical             state   /**< (I) */
    );

/**
Retrieves mappings defined within the context of @p dataset_type and @p item_type. 
<br/>Any ICS_CREATE mappings are at the begining of the @p mappings array.
@returns 
<ul> 
<li>#ITK_ok on success 
<li>#CXPOM_invalid_tag if the input @p obj is not NULLTAG and invalid.
</ul>
*/
extern PROPERTY_API int ATTRMAP_list_mappings(
    tag_t               obj,            /**< (I) Dataset (optional). <br/>If #NULLTAG, the supplied @p dataset_type and @p item_type 
                                                 values are used. <br/>Otherwise, the supplied @p dataset_type and @p item_type values are overridden by
                                                 values deduced from the dataset object @p obj and its relations. */
    tag_t               dataset_type,   /**< (I) Dataset type context for mapping, can be NULLTAG indicating global context. */
    tag_t               item_type,      /**< (I) Item type context for mapping, can be NULLTAG indicating global context. */
    logical             exact,          /**< (I) If set to @c true, only mappings for exactly the supplied (or deduced) dataset type and item type combination are retrieved.
                                                 <br/>If set to @c false, the relevant more general mappings (e.g. the global ones) are also retrieved. */
    int*                num_mappings,   /**< (O) Number of mappings found */
    tag_t**             mappings        /**< (OF) num_mappings Array of mappings found */
    );

extern PROPERTY_API int ATTRMAP_list_all_mappings(
    int*                num_mappings,   /**< (O) */
    tag_t**             mappings        /**< (OF) num_mappings */
    );

/**
    Retrieves mapping with the given title, Dataset type scope and Item type scope.<br>
    For one-to-many mapping definitions, it is the first mapping defined sequentially in the imported mapping file.
*/
extern PROPERTY_API int ATTRMAP_find_mapping(
    const char*         title,          /**< (I) Mapping title */
    tag_t               dataset_type,   /**< (I) Dataset type scope */
    tag_t               item_type,      /**< (I) Item type scope */
    tag_t*              mapping         /**< (O) Found mapping */
    );

/**
    Retrieves all mappings defined with the given title, Dataset type scope and Item type scope.
    <br>For one-to-many mapping definitions, mappings[0] is the first mapping defined sequentially in the imported mapping file.
*/
extern PROPERTY_API int ATTRMAP_find_mappings(
    const char*         title,          /**< (I) Mapping title */
    tag_t               dataset_type,   /**< (I) Dataset type scope */
    tag_t               item_type,      /**< (I) Item type scope */
    int*                num_mappings,   /**< (O) Number of mappings found */
    tag_t**             mappings        /**< (OF) num_mappings Array of mappings found */
    );

extern PROPERTY_API int ATTRMAP_ask_mapping_attr_title(
    tag_t               mapping,    /**< (I) */
    char**              result      /**< (OF) */
    );

extern PROPERTY_API int ATTRMAP_ask_mapping_dataset_type(
    tag_t               mapping,    /**< (I) */
    tag_t*              result      /**< (O) */
    );

extern PROPERTY_API int ATTRMAP_ask_mapping_item_type(
    tag_t               mapping,    /**< (I) */
    tag_t*              result      /**< (O) */
    );

extern PROPERTY_API int ATTRMAP_ask_mapping_cad_master(
    tag_t               mapping,    /**< (I) */
    logical*            result      /**< (O) */
    );

extern PROPERTY_API int ATTRMAP_ask_mapping_iman_master(
    tag_t               mapping,    /**< (I) */
    logical*            result      /**< (O) */
    );

extern PROPERTY_API int ATTRMAP_ask_mapping_freezable(
    tag_t               mapping,    /**< (I) */
    logical*            result      /**< (O) */
    );

extern PROPERTY_API int ATTRMAP_ask_mapping_required(
    tag_t               mapping,    /**< (I) */
    logical*            result      /**< (O) */
    );

extern PROPERTY_API int ATTRMAP_ask_mapping_write_once(
    tag_t               mapping,    /**< (I) */
    logical*            result      /**< (O) */
    );

extern PROPERTY_API int ATTRMAP_ask_mapping_allow_null_value(
    tag_t               mapping,    /**< (I) */
    logical*            result      /**< (O) */
    );

extern PROPERTY_API int ATTRMAP_ask_mapping_description(
    tag_t               mapping,    /**< (I) */
    char**              result      /**< (OF) */
    );

extern PROPERTY_API int ATTRMAP_ask_mapping_default_value(
    tag_t               mapping,    /**< (I) */
    char**              result      /**< (OF) */
    );

extern PROPERTY_API int ATTRMAP_ask_mapping_map_type(
    tag_t                   mapping,    /**< (I) */
    ATTRMAP_mapping_type_t* result      /**< (O) */
    );

/**
    Convenience function lumping together many of the above; of course if we
    ever extend the possible information then we'll need another call to get
    more.
*/
extern PROPERTY_API int ATTRMAP_ask_mapping_attr_all(
    tag_t                   mapping,        /**< (I) */
    char**                  title,          /**< (OF) */
    tag_t*                  dataset_type,   /**< (O) */
    tag_t*                  item_type,      /**< (O) */
    logical*                cad_master,     /**< (O) */
    logical*                iman_master,    /**< (O) */
    logical*                freezable,      /**< (O) */
    logical*                required,       /**< (O) */
    logical*                write_once,     /**< (O) */
    char**                  description,    /**< (OF) */
    char**                  default_value,  /**< (OF) */
    ATTRMAP_mapping_type_t* map_type        /**< (O) */
    );

extern PROPERTY_API int ATTRMAP_ask_mapping_whole_string(
    tag_t               mapping,    /**< (I) */
    char**              result      /**< (OF) */
    );

extern PROPERTY_API int ATTRMAP_ask_mapping_all_qualifiers(
    tag_t               mapping,    /**< (I) */
    char**              result      /**< (OF) */
    );

extern PROPERTY_API int ATTRMAP_ask_mapping_hard_coded(
    tag_t               mapping,    /**< (I) */
    logical*            result      /**< (O) */
    );

/**
    Normally, "obj_to_lock" is the object to which "actual_property" is
    attached; the one current exception is when the property is on a Form's
    data-file, when locking the data-file itself isn't enough to persuade the
    property to admit to being read-write - you have to lock the Form instead!
*/
extern PROPERTY_API int ATTRMAP_resolve_mapping(
    tag_t                   obj,                /**< (I) */
    tag_t                   mapping,            /**< (I) */
    ATTRMAP_mapping_type_t* type,               /**< (O) */
    tag_t*                  obj_to_lock,        /**< (O) */
    tag_t*                  actual_property     /**< (O) */
    );

/** @if DOX_IGNORE
    This function added for solving the UG/Manger Attr sync problem
    added the additional argument which is Item Revision tag.
    PR : 1099151
@endif */
extern PROPERTY_API int ATTRMAP_resolve_mapping_with_ir(
    tag_t                   obj,                /**< (I) */
    tag_t                   mapping,            /**< (I) */
    tag_t                   itemRevTag,         /**< (I) */
    ATTRMAP_mapping_type_t* type,               /**< (O) */
    tag_t*                  obj_to_lock,        /**< (O) */
    tag_t*                  actual_property     /**< (O) */
    );


/**
    Sometimes obj may be useful when finding a property-descriptor.
*/
extern PROPERTY_API int ATTRMAP_ask_propdesc(
    tag_t               obj,        /**< (I) */
    tag_t               mapping,    /**< (I) */
    tag_t*              propdesc    /**< (O) */
    );

/** @if DOX_IGNORE
    This function added for solving the UG/Manger Attr sync problem
    added the additional argument which is Item Revision tag.
    PR : 1099151
@endif */
extern PROPERTY_API int ATTRMAP_ask_propdesc_with_ir(
    tag_t               obj,            /**< (I) */
    tag_t               mapping,        /**< (I) */
    tag_t               itemRevTag,     /**< (I) */
    tag_t*              propdesc        /**< (O) */
    );

extern PROPERTY_API int ATTRMAP_ask_constant(
    tag_t               mapping,    /**< (I) */
    char**              value       /**< (OF) */
    );

extern PROPERTY_API int ATTRMAP_ask_preference(
    tag_t                           mapping,    /**< (I) */
    TC_preference_search_scope_t*   scope,      /**< (O) */
    char**                          name        /**< (OF) */
    );

#ifdef __cplusplus
}
#endif

/**
    ATTRMAP_resolve_mappings does the same job as ATTRMAP_resolve_mapping,
    except on an array of mappings instead of just one mapping.  It returns
    4 result arrays.  The first three are arrays of the same return values 
    you would get from ATTRMAP_resolve_mapping.  They are not in the same order,
    however, as the input array of mappings.  Instead they are sorted by
    "objs_to_lock".  This allows the caller to be more efficient in refreshing
    and locking when there are multiple poperties on the same object that have
    been mapped.  The 4th array (xref) is the index into the input mappings
    array of the corresponding result.  This allows the caller to easily match
    the results arrays to the input mappings array.

    This function itself is generally more efficient than multiple calls to
    ATTRMAP_resolve_mapping.  If there are many mappings that refer to attributes
    on the same object, the savings can be quite large.
*/
extern PROPERTY_API int ATTRMAP_resolve_mappings
(   tag_t                       obj,                /**< (I) */
    tag_t *                     mappings,           /**< (I) */
    int                         mappings_count,     /**< (I) */
    ATTRMAP_mapping_type_t **   types,              /**< (OF) */
    tag_t **                    objs_to_lock,       /**< (OF) */
    tag_t **                    actual_properties,  /**< (OF) */
    int **                      xref                /**< (OF) */
);

/** @} */

#include <property/libproperty_undef.h>
#endif

