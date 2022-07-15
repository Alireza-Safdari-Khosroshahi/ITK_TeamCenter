/* Copyright 2020 Siemens Digital Industries Software
 ==================================================
 Copyright 2013
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2020 Siemens Digital Industries Software */

/**
    @file

    This header file declares all functions,  data types and constants to be used by MDConnectivity.

*/

#ifndef MDC0MDC_MDC0MDC_H
#define MDC0MDC_MDC0MDC_H

#include <unidefs.h>
#include <Mdc0mdc/libmdc0mdc_exports.h>


/**
    @defgroup MDC0MDC Multi-Disciplinary Connectivity (MDC)
    @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/**

This structure is used to pass on the parameters for Create or Update Ordered Element Groups objects.

*/
typedef struct MDC0MDC_API MDC0_ordered_element_group_info_s
{
    tag_t           ceg_tag;             /**< (I) Tag of the Conditional Element Group object */
    tag_t           model_object_tag;    /**< (I) Tag of Application Model */
    const char*     bo_type;             /**< (I) Business object type, should be Ordered Element Group object*/
    int             att_size;            /**< (I) The size of the att_name and att_value arrays */
    const char**    att_name;            /**< (I) att_size Attribute info name array */
    const char**    att_value;           /**< (I) att_size Attribute info value array */
    tag_t           oreg_tag;            /**< (I) Tag of the Ordered Element Group object */
    tag_t           start_element_tag;   /**< (I) Tag of the Conditional Element start element */
    tag_t           end_element_tag;     /**< (I) Tag of the Conditional Element end element */
    int             count;               /**< (I) The size of the element_tags array */
    const tag_t*    element_tags;        /**< (I) count Tag array of the Conditional Element ordered elements */
    tag_t           spec_tag;            /**< (I) Tag of the Specification object */
    date_t          date_guard;          /**< (I) The date time guard */
} MDC0_ordered_element_group_info_t, *MDC0_ordered_element_group_info_p_t;


/**

Retrieves the identity of an element.

@returns
<ul>
<li>#ITK_ok when the operation is successfully executed, even if no instance is found.
<li>#MDC0MDC_no_unique_model_element if the object was a member of more than one partition.
</ul>


*/
extern MDC0MDC_API int MDC_get_identity(
        tag_t  element,                     /**< (I) Tag of the Model element object */
        tag_t  model_object,                /**< (I) Tag of the Model Object */
        tag_t  context,                     /**< (I) Tag of the Configuration Object */
        char** identity                     /**< (OF) The identity of an element */
    );

/**


Creates an Ordered Element Group.

@returns
<ul>
<li>#ITK_ok on success.
<li>#MDC0MDC_object_is_modified if object was previously modified by another user in a different session.
<li>#MDC0MDC_no_ordered_element if Ordered Element Group object was not provided.
</ul>

*/
extern MDC0MDC_API int MDC_create_or_update_ordered_element_groups (
        const MDC0_ordered_element_group_info_p_t input,   /**< (I) Structure of parms to create/update Mdc0OrderedElementGroup object */
        tag_t*                             ret_oreg_tag    /**< (O) Tag of the Ordered Element Group object */
    );

/**

Inserts a model element into a Ordered Element Group.

@returns
<ul>
<li>#ITK_ok on success.
<li>#MDC0MDC_no_connection_element if connection element object was not provided.
<li>#MDC0MDC_no_ordered_element if Ordered Element Group object was not provided.
</ul>

*/
extern MDC0MDC_API int MDC_insert_connection_element (
        tag_t           me_tag,              /**< (I) Tag of the Model Element object */
        tag_t           port1_tag,           /**< (I) Tag of the first Port Artifact object */
        tag_t           port2_tag,           /**< (I) Tag of the second Port Artifact object */
        int             att_size,            /**< (I) The size of the att_name and att_value arrays */
        const char**    att_name,            /**< (I) att_size Attribute info name array */
        const char**    att_value,           /**< (I) att_size Attribute info value array */
        tag_t           ce_tag,              /**< (I) Tag of the existing Connection Element object */
        tag_t           oeg_tag,             /**< (I) Tag of the Ordered Element Group object */
        tag_t*          created_ce_tag       /**< (OF) The tag of the created Connnection Element object */
    );

/**

Inserts elements into an Ordered Element Group.

@returns
<ul>
<li>#ITK_ok on success.
<li>#MDC0MDC_object_is_modified if object was previously modified by another user in a different session.
<li>#MDC0MDC_no_ordered_element if Ordered Element Group object was not provided.
<li>#MDC0MDC_empty_insert_element_list if ordered element list to insert is empty.
<li>#MDC0MDC_invalid_insert_index if index to insert list is negative.
</ul>

*/
extern MDC0MDC_API int MDC_insert_ordered_element_group_elements (
        tag_t           oreg_tag,            /**< (I) Tag of the Ordered Element Group object */
        int             count,               /**< (I) The size of the element_tags array */
        const tag_t*    element_tags,        /**< (I) count Tag array of the Conditional Element objects to be inserted */
        int             start_index,         /**< (I) Start index to insert elements */
        const date_t*   date_guard           /**< (I) The date time guard */
    );

/**

Retrieves the parent Ordered Element Group object and Conditional Element Group object associated with
a Conditional Element object.

@returns
<ul>
<li>#ITK_ok on success.
<li>#MDC0MDC_no_conditional_element_provided if the Conditional Element object was not provided.
</ul>

*/
extern MDC0MDC_API int MDC_find_parent_groups (
        const tag_t     me_tag,              /**< (I) Tag of the Conditional Element object */
        tag_t           config_ctxt_tag,     /**< (I) Tag of the Configuration Context */
        int*            o_count,             /**< (O) The size of the oeg_tags array */
        tag_t**         oeg_tags,            /**< (OF) o_count The tags of the Ordered Element Group objects */
        int*            c_count,             /**< (O) The size of the ceg_tags array */
        tag_t**         ceg_tags             /**< (OF) c_count The tags of the Conditional Element Group objects */
    );

/**

Retrieves the Model Element objects associated with a Connection Element object.

@returns
<ul>
<li>#ITK_ok on success.
<li>#MDC0MDC_no_connection_element if connection element object was not provided.
</ul>

*/
extern MDC0MDC_API int MDC_find_all_model_elements_of_connection (
        const tag_t     ce_tag,              /**< (I) Tag of the Connection Element object */
        int*            count,               /**< (O) The size of the me_tags array */
        tag_t**         me_tags              /**< (OF) count The tags of the Model Element objects */
    );

/**

Splits an Ordered Element Group object into two Ordered Element Group objects.

@returns
<ul>
<li>#ITK_ok on success.
<li>#MDC0MDC_object_is_modified if object was previously modified by another user in a different session.
<li>#MDC0MDC_no_ordered_element if Ordered Element Group object was not provided.
<li>#MDC0MDC_invalid_split_index if the index is greater than the length of the list minus one which leaves insufficient elements to split.
<li>#MDC0MDC_no_model_element if the model element is not provided.
<li>#MDC0MDC_no_ordered_list_to_split if there are no elements in the ordered element list to split.
<li>#MDC0MDC_no_split_connection_invalid if the object to split is either empty or not a connection element.
<li>#MDC0MDC_split_index_less_than_one if the split index is less than one.
<li>#MDC0MDC_no_conditional_element_provided if conditional element object is empty.
</ul>

*/
extern MDC0MDC_API int MDC_split_ordered_element_group_elements  (
        tag_t           oreg_tag,            /**< (I) Tag of the existing Ordered Element Group object */
        int             index,               /**< (I) The index to split the Ordered Element Group object ordered list at. */
        tag_t           ceg_tag,             /**< (I) Tag of the Conditional Element Group object*/
        const date_t*   date_guard,          /**< (I) The date time guard */
        tag_t*          new_oreg_tag         /**< (O) Tag of the created Ordered Element Group Object */
    );

/**
Reverses elements in an Ordered Element Group object.

@returns
<ul>
<li>#ITK_ok on success.
<li>#MDC0MDC_object_is_modified if object was previously modified by another user in a different session.
<li>#MDC0MDC_no_ordered_element if Ordered Element Group object was not provided.
</ul>

*/
extern MDC0MDC_API int MDC_reverse_ordered_element_group_elements   (
        tag_t           oreg_tag,            /**< (I) Tag of the Ordered Element Group object */
        const date_t*   date_guard           /**< (I) The date time guard */
    );

/**
Retrieves Model Elements associated with an Ordered Element Group object for a given
Partition object and configuration context and filtered by discipline type.

@returns
<ul>
<li>#ITK_ok on success.
<li>#MDC0MDC_no_oeg object if object provided is not of type Ordered Element Group.
<li>#MDC0MDC_no_partition_provided if the Partition object is not provided when querying objects in a partition.
</ul>

*/
extern MDC0MDC_API int MDC_query_ordered_element_group_by_partition    (
        const char*     discipline,         /**< (I) The discipline string */
        tag_t           oreg_tag,           /**< (I) Tag of the Ordered Element Group object */
        tag_t           partition_tag,      /**< (I) The tag of the Partition object */
        tag_t           ctxt_obj,           /**< (I) The tag of the configuration context object */
        int*            element_count,      /**< (O) The size of the element_tags array */
        tag_t**         element_tags        /**< (OF) element_count The tag array of the Model Element objects */
    );

/**
Retrieves the Conditional Element Group for given Ordered Element group.

@returns
<ul>
<li>#ITK_ok when the operation is successfully executed, even if no instance is found.
<li>#MDC0MDC_no_oeg object if object provided is not of type Ordered Element Group.
</ul>


*/
extern MDC0MDC_API int MDC_get_conditional_element_groups(
        const tag_t     oeg_tag,             /**< (I) Tag of the Ordered Element Group */
        int*            count,               /**< (O) The size of the Conditional Element Group objects */
        tag_t**         ceg_tags             /**< (OF) count The tags of the Conditional Element Group objects*/
    );


/**
Retrieves the Ordered Element Group objects for given set of elements.

@returns
<ul>
<li>#ITK_ok when the operation is successfully executed, even if no instance is found.
<li>Possibly other errors.
</ul>


*/
extern MDC0MDC_API int MDC_get_ordered_element_groups(
        int        count,                    /**< (I) The size of the element_tags array */
        const tag_t*  element_tags,          /**< (I) Tag array of the Model Element objects */
        int*       ocg_count,                /**< (O) The size of the ocg_tags array */
        tag_t**    ocg_tags                  /**< (OF) ocg_count The tags of the ordered connection group objects */
    );

/**
Retrieves the Connection Element Group objects for given set of elements.

@returns
<ul>
<li>#ITK_ok when the operation is successfully executed, even if no instance is found.
<li>Possibly other errors.
</ul>


*/
extern MDC0MDC_API int MDC_get_conditional_element_groups_with_elements(
        int        count,                    /**< (I) The size of the element_tags array */
        const tag_t*  element_tags,          /**< (I) Tag array of the Model Element objects */
        int*       ceg_count,                /**< (O) The size of the ceg_tags array */
        tag_t**    ceg_tags                  /**< (OF) ceg_count The tags of the Connection Element Group objects*/
    );

/**
Retrieves all the instances of Conditional Element Groups in a given Partition.

@returns
<ul>
<li>#ITK_ok when the operation is successfully executed, even if no instance is found.
<li>#MDC0MDC_no_partition_provided  if the Partition object is not provided when querying objects in a partition.
</ul>

*/
extern MDC0MDC_API int MDC_get_all_cegs_in_partition(
        tag_t   partition_tag,               /**< (I) Tag of the Partition object */
        tag_t   config_ctxt,                 /**< (I) Tag of the Configuration Context */
        int *   ceg_count,                   /**< (O) Size of the ceg_tags array */
        tag_t   ** ceg_tags                  /**< (OF) ceg_count Tag array of the Conditional Element Group objects */
    );

/**
Retrieves all model elements of a given Conditional Element Group object.

@returns
<ul>
<li>#ITK_ok on success.
<li>#MDC0MDC_no_conditional_element if The Conditional Element Group object was not provided.
</ul>

*/
extern MDC0MDC_API int MDC_get_all_model_elements_of_ceg(
        tag_t         ceg_tag,                     /**< (I) Tag of the Conditional Element Group object */
        tag_t         config_ctxt,                 /**< (I) Tag of the Configuration Context */
        int           obj_types_size,              /**< (I) The size of the obj_types array */
        const char**  obj_types,                   /**< (I) obj_types_size The business object types to filter the results on */
        int*          elem_count,                  /**< (O) Size of the element_tags array */
        tag_t**       element_tags                 /**< (OF) elem_count Tag array of the Model Element objects */
    );

/**
Retrieves all the Orded Element Groups of a given Conditional Element Group by applying effectivity on the Conditional Element object.

@returns
<ul>
<li>#ITK_ok on success.
<li>#MDC0MDC_ceg_not_effective if the Conditional Element Group object is not effective.
</ul>

*/

extern MDC0MDC_API int MDC_get_oegs_of_ceg(
        tag_t   ceg_tag,                     /**< (I) Tag of the Conditional Element Group object */
        tag_t   config_ctxt,                 /**< (I) Tag of the Configuration Context */
        int*    oeg_count,                   /**< (O) Size of the oeg_tags array */
        tag_t** oeg_tags                     /**< (OF) oeg_count Tag array of Ordered Element Group objects */
    );

/**
Retrieves the Element, Connection, Ordered Element Group, and Conditional Element Group associated with the input Port.

@returns
<ul>
<li>#ITK_ok on success.
<li>#MDC0MDC_no_port_artifact_provided if the Port Artifact object is not provided.
</ul>

*/
extern MDC0MDC_API int MDC_find_ports_groups (
        const tag_t     port_tag,            /**< (I) The tag of the Port Artifact object */
        tag_t           config_ctxt_tag,     /**< (I) Tag of the Configuration Context */
        tag_t*          element_tag,         /**< (O) The tag of the Port?s element */
        tag_t*          conn_tag,            /**< (O) The tag of the Port?s Connection */
        int*            ord_grp_count,       /**< (O) The size of the ord_grp_tags array */
        tag_t**         ord_grp_tags,        /**< (OF) ord_grp_count The tag of the Port?s Ordered Element Groups */
        int*            cnd_grp_count,       /**< (O) The size of the cnd_grp_tags array */
        tag_t**         cnd_grp_tags         /**< (OF) cnd_grp_count The tag of the Port?s Conditional Element Groups */
    );


/**
Retrieves the Connection that contains the input Port.

@returns
<ul>
<li>#ITK_ok on success.
<li>#MDC0MDC_no_port_artifact_provided if the Port Artifact object is not provided.
</ul>

*/
extern MDC0MDC_API int MDC_find_connections_on_port (
        const tag_t     port_tag,            /**< (I) The tag of the Port Artifact object */
        tag_t           config_ctxt_tag,     /**< (I) Tag of the Configuration Context */
        tag_t*          conn_tag             /**< (O) The tag of the Port?s Connection */
    );

/**
Retrieves the list of all connections that contain the input Port. If the ConfigurationContext is NULLTAG or invalid, it won't apply configuration context to connections and returns the list of connections.

@returns
<ul>
<li>#ITK_ok on success.
<li>#MDC0MDC_no_port_artifact_provided if @p port is #NULLTAG or invalid.
</ul>

*/
extern MDC0MDC_API int MDC_find_all_connections_on_port (
        const tag_t     port,                              /**< (I) The Port Artifact object */
        const tag_t     configuration_context,             /**< (I) The Configuration Context */
        int*            n_connections,                     /**< (O) The number of found connections */
        tag_t**         connections                        /**< (OF) n_connections The connections on the given Port */
    );

/**
Retrieves all ports associated with the input element or partition. The results can be further filtered by port discipline and/or port direction. The results are sorted into two arrays: one for unconnected/free ports and one for connected ports.

@returns
<ul>
<li>#ITK_ok on success.
<li>#MDC0MDC_no_element_or_partition_provided if either the Logical Element or the Partition is not provided when querying ports.
<li>#MDC0MDC_no_logical_element_provided if the Logical Element object is not provided when querying ports.
<li>#MDC0MDC_no_partition_provided if the Partition object is not provided when querying objects in a partition.
<li>#MDC0MDC_invalid_port_discipline_value if the provided Port Discipline value is not a valid member of the discipline list of values.
<li>#MDC0MDC_invalid_port_direction_value if the provided Port Direction value is not a valid member of the direction list of values.
</ul>


*/
extern MDC0MDC_API int MDC_find_ports (
        const tag_t     element_tag,         /**< (I) The tag of the element object to find ports on*/
        const tag_t     partition_tag,       /**< (I) The tag of the Partition object to find ports on */
        const tag_t     context_tag,         /**< (I) The tag of the configuration context object */
        const char*     discipline,          /**< (I) The Port Discipline to search for */
        const char*     direction,           /**< (I) The Port Direction to search for */
        int*            free_count,          /**< (O) The size of the free_tags array */
        tag_t**         free_tags,           /**< (OF) free_count The tag array of the unconnected Port objects */
        int*            conn_count,          /**< (O) The size of the conn_tags array */
        tag_t**         conn_tags            /**< (OF) conn_count The tag array of the connected Port objects */
    );

/**
Retrieves all the logical elements realized from the given Item Revision.
The given configuration context is applied on the elements to get the effective elements.

@returns
<ul>
<li>#ITK_ok on success.
<li>#MDC0MDC_no_model_element if the Model Element object is not provided.
<li>#MDC0MDC_no_source_object if the source object object is not provided.
</ul>


 */

extern MDC0MDC_API int MDC_get_item_realizations(
        tag_t    item_rev_tag,               /**< (I) The tag of the Item Revision object */
        tag_t    model_object_tag,           /**< (I) The tag of the Model Element object */
        tag_t    config_ctxt,                /**< (I) The tag of the Configuration Context object */
        int*     me_count,                   /**< (O) The size of the me_tags array */
        tag_t**  me_tags                     /**< (OF) me_count The tag array of the logical elements realized from the item_rev_tag object */
    );

#ifdef __cplusplus
}
#endif

/** @} */

#include <Mdc0mdc/libmdc0mdc_undef.h>
#endif
