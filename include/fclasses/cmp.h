/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*  */

#ifndef CMP_H
#define CMP_H

#include <fclasses/cmp_errors.h>
#include <fclasses/cmp_tokens.h>
#include <fclasses/tc_basic.h>
#include <fclasses/libfclasses_exports.h>

#ifdef __cplusplus
    extern "C" {
#endif

/**
    @defgroup CMP Compare (CMP)
    @{
*/
        
/** 
   @note Use #CMP_get_std_descriptor_p_id_seq_a_rev_qty_name to retrieve its value. 
*/
extern FCLASSES_API const char* const CMP_std_descriptor_P_id_seq_A_rev_qty_name;
        
/**
   @note Use #CMP_get_std_descriptor_p_id_a_rev_qty_name to retrieve its value. 
*/
extern FCLASSES_API const char* const CMP_std_descriptor_P_id_A_rev_qty_name;

/**
   @note Use #CMP_get_std_descriptor_appr_compare_name to retrieve its value. 
*/
extern FCLASSES_API const char* const CMP_std_descriptor_appr_compare_name;

/**
   @note Use #CMP_get_std_descriptor_lbom_compare_name to retrieve its value. 
*/
extern FCLASSES_API const char * const CMP_std_descriptor_LBOM_compare_name;

/** 
   @note Use #CMP_get_std_descriptor_lbom_withocc_compare_name to retrieve its value. 
*/
extern FCLASSES_API const char * const CMP_std_descriptor_LBOM_withocc_compare_name;

/* END OF HEADER */

/**
    Creates a new compare engine based on the given compare descriptor.
*/
extern FCLASSES_API int CMP_create (
    tag_t               compare_desc,  /**< (I) Compare descriptor, as returned by #CMP_find_desc. */
    tag_t*              engine         /**< (O) New compare engine. */
    );

/**
    Adds @p new_object to @p side (left or right) of the @p engine.
    Values for @p side can be 0 (CMP_LHS) or 1 (CMP_RHS).

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CMP_invalid_tag if @p engine is #NULLTAG
    <li>#ERROR_INTERNAL_ERROR_CODE if @p engine is invalid.
    </ul>
*/
extern FCLASSES_API int CMP_add_object (
    tag_t                engine,       /**< (I) The compare engine. */
    tag_t                new_object,   /**< (I) The new object to be added. */
    int                  side          /**< (I) The side of @p engine to add @p new object.This should be either CMP_LHS (0) or CMP_RHS(1). */
    );

/**
    Deletes @p engine. The engine should be deleted before deleting the compare descriptor.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CMP_invalid_tag if @p engine has already been deleted or #NULLTAG
    <li>#ERROR_INTERNAL_ERROR_CODE if @p engine is invalid.
    </ul>
*/
extern FCLASSES_API int CMP_delete_engine (
    tag_t                engine         /**< (I) The compare engine to be deleted. */
    );

/**
    Destroys @p compare_desc.
    <br/>All engines must be deleted before the compare descriptor can be deleted. Failure to delete all the engines will result in a #CMP_descriptor_is_locked error.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CMP_descriptor_delete_failed if @p compare_desc deletion failed.
    <li>#CMP_descriptor_is_locked if @p compare_desc is locked by any compare engine.
    <li>#CMP_invalid_tag if @p compare_desc has already deleted or #NULLTAG.
    <li>#ERROR_INTERNAL_ERROR_CODE if @p compare_desc is invalid.
    </ul>

*/
extern FCLASSES_API int CMP_delete_desc (
    tag_t                compare_desc     /**< (I) The compare descriptor to be deleted. */
    );

/**
    Returns the named compare descriptor.
*/
extern FCLASSES_API int CMP_find_desc (
    const char*         name,          /**< (I) Name of descriptor to find. */
    tag_t*              compare_desc   /**< (O) Compare descriptor. */
    );

/**
    Sets the compare engine�s application data pointer. 
    The application data pointer is intended to provide a mechanism for
    passing important data into your external logic methods.
*/
extern FCLASSES_API int CMP_set_app_data (
    tag_t               engine,     /**< (I) Compare engine. */
    void*               app_data    /**< (I) Pointer to some vital piece of data. */
    );

/**
    Purges all sets that do not contain any differences from the given compare engine. 
*/
extern FCLASSES_API int CMP_cull_compare_sets (
    tag_t               engine  /**< (I) Compare engine from which to cull non-different sets. */
    );

/**
    Purges the given set from its compare engine, if that set does not contain any differences. 
*/
extern FCLASSES_API int CMP_cull_compare_set (
    tag_t               set  /**< (I) Compare set to cull from its owning engine. */
    );

/**
    Returns an array of the sets that exist inside the compare engine. 
*/
extern FCLASSES_API int CMP_ask_sets (
    tag_t               engine,  /**< (I) Compare engine to query. */
    int*                n,       /**< (O) Number of sets in the engine. */
    tag_t**             sets     /**< (OF) n Array of sets in the engine. */
    );

/**
    Returns an array of the sets that contain differences that exist inside the compare engine. 
*/
extern FCLASSES_API int CMP_ask_diff_sets (
    tag_t               engine,    /**< (I) Compare engine to query. */
    int*                n,         /**< (O) Number of sets containing differences in the engine. */
    tag_t**             diff_sets  /**< (OF) n Array of sets containing differences in the engine. */
    );

/**
    Returns an overview of the type of differences that a set contains. 
*/
extern FCLASSES_API int CMP_ask_diff (
    tag_t               set,           /**< (I) Compare set to query. */
    logical*            is_added,      /**< (O) Returned as true if this set only contains objects on one side. 
                                            Returned as false if there are objects on both sides of the set. */
    int*                added_to_side, /**< (O) If is_added is true, then this will define which side contains objects.
                                            It will be set to either #CMP_LHS or #CMP_RHS. */
    logical*            is_changed     /**< (O) Returned as true if there are objects on both sides but 
                                            some aggregate element differs between the two sides. */
    );

/**
    Returns a list of the compare elements that differ between the two sides of the given set. 
*/
extern FCLASSES_API int CMP_ask_diff_elements (
    tag_t               set,      /**< (I) Compare set to query. */
    int*                n,        /**< (O) Number of elements that are different. */
    tag_t**             elements  /**< (OF) n Array of elements that are different. */
    );

/**
    Returns the display value on the given side of the compare set for a specific element.
*/
extern FCLASSES_API int CMP_ask_element_value (
    tag_t               set,      /**< (I) Compare set to query. */
    int                 side,     /**< (I) Which side of the compare set to query. Set this to either #CMP_LHS or #CMP_RHS. */
    tag_t               element,  /**< (I) Element to query. */
    char**              value     /**< (OF) Value as a string. */
    );

/**
    Returns the value on the given side of the compare set for a specific element.
    
    <b>Restrictions:</b>
    
    These functions are only valid for property elements and cached external elements.
    It will fail for uncached external elements, as the system has no mechanism for obtaining the values of such elements.
*/
extern FCLASSES_API int CMP_ask_element_value_char(
    tag_t               set,      /**< (I) Compare set to query. */
    int                 side,     /**< (I) Which side of the compare set to query. Set this to either #CMP_LHS or #CMP_RHS. */
    tag_t               element,  /**< (I) Element to query. */
    char*               value     /**< (O) Value. */
    );

/**
    Returns the value on the given side of the compare set for a specific element.
    
    <b>Restrictions:</b>
    
    These functions are only valid for property elements and cached external elements.
    It will fail for uncached external elements, as the system has no mechanism for obtaining the values of such elements.
*/
extern FCLASSES_API int CMP_ask_element_value_date(
    tag_t               set,      /**< (I) Compare set to query. */
    int                 side,     /**< (I) Which side of the compare set to query. Set this to either #CMP_LHS or #CMP_RHS. */
    tag_t               element,  /**< (I) Element to query. */
    date_t*             value     /**< (O) Value. */
    );

/**
    Returns the value on the given side of the compare set for a specific element.
    
    <b>Restrictions:</b>
    
    These functions are only valid for property elements and cached external elements.
    It will fail for uncached external elements, as the system has no mechanism for obtaining the values of such elements.
*/
extern FCLASSES_API int CMP_ask_element_value_double(
    tag_t               set,      /**< (I) Compare set to query. */
    int                 side,     /**< (I) Which side of the compare set to query. Set this to either #CMP_LHS or #CMP_RHS. */
    tag_t               element,  /**< (I) Element to query. */
    double*             value     /**< (O) Value. */
    );

/**
    Returns the value on the given side of the compare set for a specific element.
    
    <b>Restrictions:</b>
    
    These functions are only valid for property elements and cached external elements.
    It will fail for uncached external elements, as the system has no mechanism for obtaining the values of such elements.
*/
extern FCLASSES_API int CMP_ask_element_value_int(
    tag_t               set,      /**< (I) Compare set to query. */
    int                 side,     /**< (I) Which side of the compare set to query. Set this to either #CMP_LHS or #CMP_RHS. */
    tag_t               element,  /**< (I) Element to query. */
    int*                value     /**< (O) Value. */
    );

/**
    Returns the value on the given side of the compare set for a specific element.
    
    <b>Restrictions:</b>
    
    These functions are only valid for property elements and cached external elements.
    It will fail for uncached external elements, as the system has no mechanism for obtaining the values of such elements.
*/
extern FCLASSES_API int CMP_ask_element_value_logical(
    tag_t               set,     /**< (I) Compare set to query. */
    int                 side,    /**< (I) Which side of the compare set to query. Set this to either #CMP_LHS or #CMP_RHS. */
    tag_t               element, /**< (I) Element to query. */
    logical*            value    /**< (O) Value. */
    );

/**
    Returns the value on the given side of the compare set for a specific element.

    The value parameter for the scalar type string (char*) needs to be MEM_free()d where it�s an output parameter.

    <b>Restrictions:</b>

    These functions are only valid for property elements and cached external elements.
    It will fail for uncached external elements, as the system has no mechanism for obtaining the values of such elements.
*/
extern FCLASSES_API int CMP_ask_element_value_string(
    tag_t               set,      /**< (I) Compare set to query. */
    int                 side,     /**< (I) Which side of the compare set to query. Set this to either #CMP_LHS or #CMP_RHS. */
    tag_t               element,  /**< (I) Element to query. */
    char**              value     /**< (OF) Value. */
    );

/**
    Returns the value on the given side of the compare set for a specific element.
    
    <b>Restrictions:</b>
    
    These functions are only valid for property elements and cached external elements.
    It will fail for uncached external elements, as the system has no mechanism for obtaining the values of such elements.
*/
extern FCLASSES_API int CMP_ask_element_value_tag(
    tag_t               set,      /**< (I) Compare set to query. */
    int                 side,     /**< (I) Which side of the compare set to query. Set this to either #CMP_LHS or #CMP_RHS. */
    tag_t               element,  /**< (I) Element to query. */
    tag_t*              value     /**< (O) Value. */
    );

/**
    Returns the values on the given side of the compare set for a specific element.
    
    <b>Restrictions:</b>
    
    These functions are only valid for property elements and cached external elements.
    It will fail for uncached external elements, as the system has no mechanism for obtaining the values of such elements.
*/
extern FCLASSES_API int CMP_ask_element_value_char_array (
    tag_t               set,      /**< (I) Compare set to query. */
    int                 side,     /**< (I) Which side of the compare set to query. Set this to either #CMP_LHS or #CMP_RHS. */
    tag_t               element,  /**< (I) Element to query. */
    int*                n,        /**< (O) */
    char**              value     /**< (OF) n Value. */
    );

/**
    Returns the values on the given side of the compare set for a specific element.
    
    <b>Restrictions:</b>
    
    These functions are only valid for property elements and cached external elements.
    It will fail for uncached external elements, as the system has no mechanism for obtaining the values of such elements.
*/
extern FCLASSES_API int CMP_ask_element_value_date_array (
    tag_t               set,     /**< (I) Compare set to query. */
    int                 side,    /**< (I) Which side of the compare set to query. Set this to either #CMP_LHS or #CMP_RHS. */
    tag_t               element, /**< (I) Element to query. */
    int*                n,       /**< (O) */
    date_t**            value    /**< (OF) n Value. */
    );

/**
    Returns the values on the given side of the compare set for a specific element.
    
    <b>Restrictions:</b>
    
    These functions are only valid for property elements and cached external elements.
    It will fail for uncached external elements, as the system has no mechanism for obtaining the values of such elements.
*/
extern FCLASSES_API int CMP_ask_element_value_tag_array (
    tag_t               set,      /**< (I) Compare set to query. */
    int                 side,     /**< (I) Which side of the compare set to query. Set this to either #CMP_LHS or #CMP_RHS. */
    tag_t               element,  /**< (I) Element to query. */
    int*                n,        /**< (O) */
    tag_t**             value     /**< (OF) n Value. */
    );

/**
    Returns the values on the given side of the compare set for a specific element.
    
    <b>Restrictions:</b>
    
    These functions are only valid for property elements and cached external elements.
    It will fail for uncached external elements, as the system has no mechanism for obtaining the values of such elements.
*/
extern FCLASSES_API int CMP_ask_element_value_string_array (
    tag_t               set,      /**< (I) Compare set to query. */
    int                 side,     /**< (I) Which side of the compare set to query. Set this to either #CMP_LHS or #CMP_RHS. */
    tag_t               element,  /**< (I) Element to query. */
    int*                n,        /**< (O) */
    char***             value     /**< (OF) n Value. */
    );

/**
    Returns the objects on the given side of the compare set.
*/
extern FCLASSES_API int CMP_ask_objects_in_set (
    tag_t               set,      /**< (I) Compare set to query. */
    int                 side,     /**< (I) Which side of the compare set to query. Set this to either #CMP_LHS or #CMP_RHS. */
    int*                n,        /**< (O) Number of objects on given side of the set. */
    tag_t**             objects   /**< (OF) n Array of objects on given side of the set. */
    );

/**
    Creates a new compare descriptor with the supplied name.
*/
extern FCLASSES_API int CMP_create_desc (
    const char*         name,       /**< (I) New name */
    tag_t*              desc        /**< (O) New compare descriptor. */
    );

/**
    Creates a new external compare element.
*/
extern FCLASSES_API int CMP_create_element (
    tag_t               desc,            /**< (I) Compare descriptor to add the new element to. */
    int                 priority,        /**< (I) Set this to #CMP_primary_element, #CMP_aggregate_element, or #CMP_display_element. */
    int                 cache_type,      /**< (I) Defines data type for caching element values. Can be set to #CMP_cache_none. */
    const char*         name,            /**< (I) Internationalized name for this element. */
    logical             suppress_value,  /**< (I) Defines whether an application should display the element value or not. 
                                            This is used to flag that a particular value is too verbose for output to a compare report. */
    tag_t*              element          /**< (O) Newly created element. */
    );

/**
    Creates a new compare property element.
*/
extern FCLASSES_API int CMP_create_prop_element (
    tag_t               desc,            /**< (I) Compare descriptor to add the new element to. */
    int                 priority,        /**< (I) Set this to #CMP_primary_element, #CMP_aggregate_element, or #CMP_display_element. */
    int                 cache_type,      /**< (I) Defines data type for caching element values. Can be set to #CMP_cache_none.
                                                Can be set to #CMP_cache_sync to force it to match the property data type,
                                                or #CMP_cache_auto to perform a best fit guess. */
    const char*         name,            /**< (I) Internationalized name for this element. This will supersede the property name. 
                                                This feature is useful if the property name is too verbose for output to a compare report. */
    logical             suppress_value,  /**< (I) Defines whether an application should display the element value or not.
                                                This is used to flag that a particular value is too verbose for output to a compare report. */
    tag_t               type_tag,        /**< (I) Imantype of the object that the property is defined against. */
    const char*         prop_name,       /**< (I) Name of the property that this element represents. */
    const char*         disp_prop_name,  /**< (I) Name of an alternative property that is used for display purposes
                                                in preference to the actual compared property.
                                                For example, you might want to compare on Item Tag but display Item Id. */
    tag_t*              element          /**< (O) Newly created element. */
    );

/**
    By default, elements are reported to users in the order in which they were defined in the compare descriptor.
    This call allows users to have their elements returned in a different order through the #CMP_ask_ordered_elements function.

    For example, when performing a BOMCompare which uses both Item Id and Sequence Number as primary elements,
    users would expect the list of changed BOMLines returned to be sorted by Sequence Number and then by Item Id.
    To achieve this they must define Sequence Number before Item Id in the compare descriptor. 
    However, this would result in the BOMCompare report output displaying the Sequence Number column before the Item Id Column.
    The use of this function will allow users to reverse these two elements for output purposes.
*/
extern FCLASSES_API int CMP_set_element_display_order (
    tag_t               desc,            /**< (I) */
    int                 n,               /**< (I) Number of elements. */
    tag_t*              elements         /**< (I) n Array of all elements in the order in which they should be displayed. */
    );

/**
    Sets the aggregated data type for a compare property element.
    By default, the aggregate type will be the same as the property type.
    However, in some cases this is not appropriate. For example, 
    if your aggregate property has a tag data type then combining multiple tags into a single aggregate tag is meaningless.
    In this situation you would want to change the aggregate type to be a tag array.

    <b>Restrictions:</b>

    This function is only valid for property elements. It will fail if called against an external element.

    All compare cache types are valid, except for #CMP_cache_none, #CMP_cache_sync, and #CMP_cache_auto.

    This function will fail if a cache is being used for the element. 
    This function should only be called if the element�s cache type is set to #CMP_cache_none.
    If a cache is being used for an element, then the aggregate type will, and indeed must, match the cache type.
*/
extern FCLASSES_API int CMP_set_aggregate_type (
    tag_t               prop_element,       /**< (I) Compare property element to set the aggregate type of. */
    int                 aggregate_type      /**< (I) Data type of the aggregated values. */
    );

extern FCLASSES_API int CMP_set_prop_element_order (
    tag_t               prop_element,       /**< (I) */
    int                 order               /**< (I) */
    );

/**
    Sets a specific application flag for the given compare element.
    See bom_tokens.h for a list of standard application flags.
*/
extern FCLASSES_API int CMP_set_element_application_flag (
    tag_t   element,         /**< (I) */
    int     app_flag,        /**< (I) */
    logical value            /**< (I) */
    );


/** @if DOX_IGNORE
    (TB) 26-Sep-2001 This directive introduces the header containing various
    CMP_compare_*_method_t typedefs required by the auto-generated journalling
    code. The <p> directive marks a non-void black-box pointer, in this case, a
    function pointer. Customers needn't worry about such lower-case flags.

    ##include fclasses/cmp_tokens.h

@endif */

/**
    Registers a method for comparing an object against a compare set, based on the specified element.
*/
extern FCLASSES_API int CMP_register_compare_obj_method (
    tag_t                     element,      /**< (I) Compare element to register the method against. */
    CMP_compare_obj_method_t* method        /**< (Ip) Method to register. */
    );

/**
    Registers a method for comparing the two sides of a compare set, based on the specified compare element.
*/
extern FCLASSES_API int CMP_register_compare_agg_method (
    tag_t                     element,      /**< (I) Compare element to register the method against. */
    CMP_compare_agg_method_t* method        /**< (Ip) Method to register. */
    );

/**
    Registers a method for updating this element�s cached value when a new object is added to a set.
*/
extern FCLASSES_API int CMP_register_update_cache_method (
    tag_t                      element,     /**< (I) Compare element to register the method against. */
    CMP_update_cache_method_t* method       /**< (Ip) Method to register. */
    );

/**
    Registers a method for obtaining the display name for the given compare element.
    This method is used (if defined) instead of the internationalized name that is stored on the element itself.
*/
extern FCLASSES_API int CMP_register_uif_name_method (
    tag_t                  element,     /**< (I) Compare element to register the method against. */
    CMP_uif_name_method_t* method       /**< (Ip) Method to register. */
    );

/**
    Registers a method for obtaining the display value of the given compare element.
*/
extern FCLASSES_API int CMP_register_uif_value_method (
    tag_t                   element,    /**< (I) Compare element to register the method against. */
    CMP_uif_value_method_t* method      /**< (Ip) Method to register. */
    );

/**
    Registers a method for releasing any memory associated with an externally defined cache on the given compare element.
    This method is only invoked if the element cache type is set to #CMP_cache_pointer.
*/
extern FCLASSES_API int CMP_register_free_cache_method (
    tag_t                    element,   /**< (I) Compare element to register the method against. */
    CMP_free_cache_method_t* method     /**< (Ip) Method to register. */
    );

/**
    Returns a list of the elements of a compare descriptor.
*/
extern FCLASSES_API int CMP_ask_elements (
    tag_t               desc,       /**< (I) Compare descriptor to query. */
    int*                n,          /**< (O) Number of elements. */
    tag_t**             elements    /**< (OF) n Array of elements. */
    );

/**
    Returns a list of the elements of a compare descriptor,
    in the display order (defined by #CMP_set_element_display_order). 
    If no display order has been defined for the descriptor,
    then the elements are returned in their definition order (same as #CMP_ask_elements).
*/
extern FCLASSES_API int CMP_ask_ordered_elements (
    tag_t               desc,      /**< (I) Compare descriptor to query. */
    int*                n,         /**< (O) Number of elements. */
    tag_t**             elements   /**< (OF) n Array of elements. */
    );

/**
    Returns details about the given element.
*/
extern FCLASSES_API int CMP_ask_element_info (
    tag_t               element,         /**< (I) Compare element to query. */
    int*                element_type,    /**< (O) Defines whether it is a property element or an external element.
                                            Set to either #CMP_property_element or #CMP_external_element. */
    int*                priority,        /**< (O) Set to #CMP_primary_element, #CMP_aggregate_element, or #CMP_display_element. */
    int*                cache_type,      /**< (O) Defines data type for caching element values. */
    char**              uif_name,        /**< (OF) Internationalized name for this element. */
    logical*            suppress_value   /**< (O) Defines whether an application should display the element value or not.
                                            This is used to flag that a particular value is too verbose for output to a compare report. */
    );

/**
    Returns details about the given property element.

    <b>Restrictions:</b>

    This function is only valid for property elements.
    It will fail if called against an external element.
*/
extern FCLASSES_API int CMP_ask_prop_element_info (
    tag_t               prop_element,    /**< (I) Compare property element to query. */
    int*                aggregate_type,  /**< (O) Data type for aggregated values. */
    char**              prop_name,       /**< (OF) Name of the property that this element represents. */
    char**              disp_prop_name   /**< (OF) Name of an alternative property that is used for display purposes
                                                in preference to the actual compared property. 
                                                For example, you might want to compare on Item Tag but display Item Id. */
    );

extern FCLASSES_API int CMP_ask_prop_element_order (
    tag_t               prop_element,    /**< (I) */
    int*                order            /**< (O) */
    );

/**
    Returns the element�s method pointers.
*/
extern FCLASSES_API int CMP_ask_element_methods (
    tag_t                       element,       /**< (I) Compare element to query. */
    CMP_compare_obj_method_t**  obj_method,    /**< (Op) Method for comparing an EIM object against a compare set. */
    CMP_compare_agg_method_t**  agg_method,    /**< (Op) Method for comparing the two sides against a compare set. */
    CMP_update_cache_method_t** cache_method,  /**< (Op) Method for updating the data cache following an 
                                                    EIM object�s insertion into a set. */
    CMP_uif_name_method_t**     name_method,   /**< (Op) Method to return the display name for an element. */
    CMP_uif_value_method_t**    value_method,  /**< (Op) Method to return the display value for an element. */
    CMP_free_cache_method_t**   free_method    /**< (Op) Method to release an externally defined data cache. */
    );


/**
    Returns a specific application flag for the given compare element.
    See bom_tokens.h for a list of standard application flags.
*/
extern FCLASSES_API int CMP_ask_element_application_flag (
  tag_t      element,         /**< (I) */
  int        app_flag,        /**< (I) */
  logical *  value            /**< (O) */
);


/**
    Returns the compare set�s engine.
*/
extern FCLASSES_API int CMP_ask_engine_of_set (
    tag_t               set,        /**< (I) */
    tag_t*              engine      /**< (O) */
    );

/**
    Returns the compare engine�s application data pointer.
    The application data pointer is intended to provide a mechanism for 
    passing important data into your external logic methods.
*/
extern FCLASSES_API int CMP_ask_app_data (
    tag_t               engine,     /**< (I) Compare engine to query. */
    void**              app_data    /**< (Op) Pointer to some vital piece of data. */
    );

/**
    Returns the data cache for the given element in a particular set.
    This is intended for use by cache update methods registered with #CMP_register_update_cache_method.
*/
extern FCLASSES_API int CMP_ask_data_cache (
    tag_t               set,        /**< (I) Compare set to query. */
    tag_t               element,    /**< (I) Compare element to query. */
    int                 side,       /**< (I) */
    int*                cache_type, /**< (O) Data type of the cache. 
                                        Will be set to #CMP_cache_none if no cache exists for this element of the given set. */
    tag_t*              cache       /**< (O) Tag of the cache. */
    );

/**
    Returns the value stored in the given data cache.
    This is intended for use by cache update methods registered with #CMP_register_update_cache_method
*/
extern FCLASSES_API int CMP_ask_cached_char (
    tag_t               cache,      /**< (I) Data cache to query, as returned by #CMP_ask_data_cache. */
    char*               value       /**< (O) Cached value. */
    );

/**
    Returns the value stored in the given data cache.
    This is intended for use by cache update methods registered with #CMP_register_update_cache_method
*/
extern FCLASSES_API int CMP_ask_cached_date (
    tag_t               cache,      /**< (I) Data cache to query, as returned by #CMP_ask_data_cache. */
    date_t*             value       /**< (O) Cached value. */
    );

/**
    Returns the value stored in the given data cache.
    This is intended for use by cache update methods registered with #CMP_register_update_cache_method
*/
extern FCLASSES_API int CMP_ask_cached_double (
    tag_t               cache,      /**< (I) Data cache to query, as returned by #CMP_ask_data_cache. */
    double*             value       /**< (O) Cached value. */
    );

/**
    Returns the value stored in the given data cache.
    This is intended for use by cache update methods registered with #CMP_register_update_cache_method
*/
extern FCLASSES_API int CMP_ask_cached_int (
    tag_t               cache,      /**< (I) Data cache to query, as returned by #CMP_ask_data_cache. */
    int*                value       /**< (O) Cached value. */
    );

/**
    Returns the value stored in the given data cache.
    This is intended for use by cache update methods registered with #CMP_register_update_cache_method
*/
extern FCLASSES_API int CMP_ask_cached_logical (
    tag_t               cache,      /**< (I) Data cache to query, as returned by #CMP_ask_data_cache. */
    logical*            value       /**< (O) Cached value. */
    );

/**
    Returns the value stored in the given data cache.
    This is intended for use by cache update methods registered with #CMP_register_update_cache_method
*/
extern FCLASSES_API int CMP_ask_cached_tag (
    tag_t               cache,      /**< (I) Data cache to query, as returned by #CMP_ask_data_cache. */
    tag_t*              value       /**< (O) Cached value. */
    );

/**
    Returns the value stored in the given data cache.
    This is intended for use by cache update methods registered with #CMP_register_update_cache_method
*/
extern FCLASSES_API int CMP_ask_cached_pointer (
    tag_t               cache,      /**< (I) Data cache to query, as returned by #CMP_ask_data_cache. */
    void**              value       /**< (Op) Cached value. */
    );

/**
    Returns the value stored in the given data cache.
    This is intended for use by cache update methods registered with #CMP_register_update_cache_method
*/
extern FCLASSES_API int CMP_ask_cached_string (
    tag_t               cache,      /**< (I) Data cache to query, as returned by #CMP_ask_data_cache. */
    char**              value       /**< (OF) Cached value. */
    );

/**
    Returns the value stored in the given data cache.
    This is intended for use by cache update methods registered with #CMP_register_update_cache_method
*/
extern FCLASSES_API int CMP_ask_cached_char_array (
    tag_t               cache,      /**< (I) Data cache to query, as returned by #CMP_ask_data_cache. */
    int*                n,          /**< (O) */
    char**              value       /**< (OF) n Cached value. */
    );

/**
    Returns the value stored in the given data cache.
    This is intended for use by cache update methods registered with #CMP_register_update_cache_method
*/
extern FCLASSES_API int CMP_ask_cached_date_array (
    tag_t               cache,      /**< (I) Data cache to query, as returned by #CMP_ask_data_cache. */
    int*                n,          /**< (O) */
    date_t**            value       /**< (OF) n Cached value */
    );

/**
    Returns the value stored in the given data cache.
    This is intended for use by cache update methods registered with #CMP_register_update_cache_method
*/
extern FCLASSES_API int CMP_ask_cached_tag_array (
    tag_t               cache,      /**< (I) Data cache to query, as returned by #CMP_ask_data_cache. */
    int*                n,          /**< (O) */
    tag_t**             value       /**< (OF) n Cached value */
    );

/**
    Returns the value stored in the given data cache.
    This is intended for use by cache update methods registered with #CMP_register_update_cache_method
*/
extern FCLASSES_API int CMP_ask_cached_string_array (
    tag_t               cache,      /**< (I) Data cache to query, as returned by #CMP_ask_data_cache. */
    int*                n,          /**< (O) */
    char***             value       /**< (OF) n Cached value */
    );

/**
    Sets the value stored in the given data cache.
    This is intended for use by cache update methods registered with #CMP_register_update_cache_method.
*/
extern FCLASSES_API int CMP_set_cached_char (
    tag_t               cache,      /**< (I) Data cache to set, as returned by #CMP_ask_data_cache. */
    char                value       /**< (I) Cached value. */
    );

/**
    Sets the value stored in the given data cache.
    This is intended for use by cache update methods registered with #CMP_register_update_cache_method.
*/
extern FCLASSES_API int CMP_set_cached_date (
    tag_t               cache,      /**< (I) Data cache to set, as returned by #CMP_ask_data_cache. */
    date_t              value       /**< (I) Cached value. */
    );

/**
    Sets the value stored in the given data cache.
    This is intended for use by cache update methods registered with #CMP_register_update_cache_method.
*/
extern FCLASSES_API int CMP_set_cached_double (
    tag_t               cache,      /**< (I) Data cache to set, as returned by #CMP_ask_data_cache. */
    double              value       /**< (I) Cached value. */
    );

/**
    Sets the value stored in the given data cache.
    This is intended for use by cache update methods registered with #CMP_register_update_cache_method.
*/
extern FCLASSES_API int CMP_set_cached_int (
    tag_t               cache,      /**< (I) Data cache to set, as returned by #CMP_ask_data_cache. */
    int                 value       /**< (I) Cached value. */
    );

/**
    Sets the value stored in the given data cache.
    This is intended for use by cache update methods registered with #CMP_register_update_cache_method.
*/
extern FCLASSES_API int CMP_set_cached_logical (
    tag_t               cache,      /**< (I) Data cache to set, as returned by #CMP_ask_data_cache. */
    logical             value       /**< (I) Cached value. */
    );

/**
    Sets the value stored in the given data cache.
    This is intended for use by cache update methods registered with #CMP_register_update_cache_method.
*/
extern FCLASSES_API int CMP_set_cached_string (
    tag_t               cache,      /**< (I) Data cache to set, as returned by #CMP_ask_data_cache. */
    char*               value       /**< (I) Cached value. */
    );

/**
    Sets the value stored in the given data cache.
    This is intended for use by cache update methods registered with #CMP_register_update_cache_method.
*/
extern FCLASSES_API int CMP_set_cached_tag (
    tag_t               cache,      /**< (I) Data cache to set, as returned by #CMP_ask_data_cache. */
    tag_t               value       /**< (I) Cached value. */
    );

/**
    Sets the value stored in the given data cache.
    This is intended for use by cache update methods registered with #CMP_register_update_cache_method.
*/
extern FCLASSES_API int CMP_set_cached_pointer (
    tag_t               cache,      /**< (I) Data cache to set, as returned by #CMP_ask_data_cache. */
    void*               value       /**< (I) Cached value. */
    );

/**
    Sets the value stored in the given data cache.
    This is intended for use by cache update methods registered with #CMP_register_update_cache_method.
*/
extern FCLASSES_API int CMP_set_cached_char_array (
    tag_t               cache,      /**< (I) Data cache to set, as returned by #CMP_ask_data_cache. */
    int                 n,          /**< (I) */
    char*               value       /**< (I) n Cached value. */
    );

/**
    Sets the value stored in the given data cache.
    This is intended for use by cache update methods registered with #CMP_register_update_cache_method.
*/
extern FCLASSES_API int CMP_set_cached_date_array (
    tag_t               cache,      /**< (I) Data cache to set, as returned by #CMP_ask_data_cache. */
    int                 n,          /**< (I) */
    date_t*             value       /**< (I) n Cached value. */
    );

/**
    Sets the value stored in the given data cache.
    This is intended for use by cache update methods registered with #CMP_register_update_cache_method.
*/
extern FCLASSES_API int CMP_set_cached_tag_array (
    tag_t               cache,      /**< (I) Data cache to set, as returned by #CMP_ask_data_cache. */
    int                 n,          /**< (I) */
    tag_t*              value       /**< (I) n Cached value. */
    );

/**
    Sets the value stored in the given data cache.
    This is intended for use by cache update methods registered with #CMP_register_update_cache_method.
*/
extern FCLASSES_API int CMP_set_cached_string_array (
    tag_t               cache,      /**< (I) Data cache to set, as returned by #CMP_ask_data_cache. */
    int                 n,          /**< (I) */
    char**              value       /**< (I) Cached value. */
    );

/**
    Adds the given value to the previously cached value. 
    This is intended for use by cache update methods registered with #CMP_register_update_cache_method.
    The exact meaning of this operation depends on the data type of the cache.
    For example, an integer cache will simply add the 2 values.
    A string cache will concatenate the values. A logical cache will AND the values. 
    If the default behavior is not appropriate to a specific situation then a combination of
    #CMP_ask_cached_char and #CMP_set_cached_char allows complete control over the cache update. 
*/
extern FCLASSES_API int CMP_add_cached_char (
    tag_t               cache,      /**< (I) Data cache to set, as returned by #CMP_ask_data_cache. */
    char                value       /**< (I) Value to add to the already cached value. */
    );

/**
    Adds the given value to the previously cached value. 
    This is intended for use by cache update methods registered with #CMP_register_update_cache_method.
    The exact meaning of this operation depends on the data type of the cache.
    For example, an integer cache will simply add the 2 values.
    A string cache will concatenate the values. A logical cache will AND the values. 
    If the default behavior is not appropriate to a specific situation then a combination of
    #CMP_ask_cached_date and #CMP_set_cached_date allows complete control over the cache update. 
*/
extern FCLASSES_API int CMP_add_cached_date (
    tag_t               cache,      /**< (I) Data cache to set, as returned by #CMP_ask_data_cache. */
    date_t              value       /**< (I) Value to add to the already cached value. */
    );

/**
    Adds the given value to the previously cached value. 
    This is intended for use by cache update methods registered with #CMP_register_update_cache_method.
    The exact meaning of this operation depends on the data type of the cache.
    For example, an integer cache will simply add the 2 values.
    A string cache will concatenate the values. A logical cache will AND the values. 
    If the default behavior is not appropriate to a specific situation then a combination of
    #CMP_ask_cached_double and #CMP_set_cached_double allows complete control over the cache update. 
*/
extern FCLASSES_API int CMP_add_cached_double (
    tag_t               cache,      /**< (I) Data cache to set, as returned by #CMP_ask_data_cache. */
    double              value       /**< (I) Value to add to the already cached value. */
    );

/**
    Adds the given value to the previously cached value. 
    This is intended for use by cache update methods registered with #CMP_register_update_cache_method.
    The exact meaning of this operation depends on the data type of the cache.
    For example, an integer cache will simply add the 2 values.
    A string cache will concatenate the values. A logical cache will AND the values. 
    If the default behavior is not appropriate to a specific situation then a combination of
    #CMP_ask_cached_int and #CMP_set_cached_int allows complete control over the cache update. 
*/
extern FCLASSES_API int CMP_add_cached_int (
    tag_t               cache,      /**< (I) Data cache to set, as returned by #CMP_ask_data_cache. */
    int                 value       /**< (I) Value to add to the already cached value. */
    );

/**
    Adds the given value to the previously cached value. 
    This is intended for use by cache update methods registered with #CMP_register_update_cache_method.
    The exact meaning of this operation depends on the data type of the cache.
    For example, an integer cache will simply add the 2 values.
    A string cache will concatenate the values. A logical cache will AND the values. 
    If the default behavior is not appropriate to a specific situation then a combination of
    #CMP_ask_cached_logical and #CMP_set_cached_logical allows complete control over the cache update. 
*/
extern FCLASSES_API int CMP_add_cached_logical (
    tag_t               cache,      /**< (I) Data cache to set, as returned by #CMP_ask_data_cache. */
    logical             value       /**< (I) Value to add to the already cached value. */
    );

/**
    Adds the given value to the previously cached value. 
    This is intended for use by cache update methods registered with #CMP_register_update_cache_method.
    The exact meaning of this operation depends on the data type of the cache.
    For example, an integer cache will simply add the 2 values.
    A string cache will concatenate the values. A logical cache will AND the values. 
    If the default behavior is not appropriate to a specific situation then a combination of
    #CMP_ask_cached_string and #CMP_set_cached_string allows complete control over the cache update. 
*/
extern FCLASSES_API int CMP_add_cached_string (
    tag_t               cache,      /**< (I) Data cache to set, as returned by #CMP_ask_data_cache. */
    char*               value       /**< (I) Value to add to the already cached value. */
    );

/**
    Adds the given value to the previously cached value. 
    This is intended for use by cache update methods registered with #CMP_register_update_cache_method.
    The exact meaning of this operation depends on the data type of the cache.
    For example, an integer cache will simply add the 2 values.
    A string cache will concatenate the values. A logical cache will AND the values. 
    If the default behavior is not appropriate to a specific situation then a combination of
    #CMP_ask_cached_tag and #CMP_set_cached_tag allows complete control over the cache update. 
*/
extern FCLASSES_API int CMP_add_cached_tag (
    tag_t               cache,      /**< (I) Data cache to set, as returned by #CMP_ask_data_cache. */
    tag_t               value       /**< (I) Value to add to the already cached value. */
    );

/** @if DOX_IGNORE
    Doesn't exist:
    extern FCLASSES_API int CMP_add_cached_pointer
@endif */

/** @} */

/*================================================================================================*/

#ifdef __cplusplus
    }
#endif

#include <fclasses/libfclasses_undef.h>
#endif
