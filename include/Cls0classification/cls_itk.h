#ifndef CLS_ITK_H
#define CLS_ITK_H

#include <tc/tc_startup.h>
#include <base_utils/Mem.h>
#include <common/tc_deprecation_macros.h>
#include <Cls0classification/libcls0classification_exports.h>

/**
   @defgroup CLS0CLASSIFICATION Next Generation Classification Foundation (presentation layer)
   @ingroup TC

   Next generation Classification foundation provides the ability to separate the Representation hierarchy from the underlying
   Storage Class hierarchy.

   @{
*/
#ifdef __cplusplus
extern "C"
{
#endif
    /**
       @name Context
       @{
    */
    /**
       Retrieves the default Classification context object. If not present, the system will create it.

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are
       passed in as null pointer
       </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_get_default_context(
        tag_t *     default_context_tag         /**< (O) Reference of the default Classification context
                                                   object. This is a mandatory parameter. */
        );
    /**
       @}
    */

    /**
       @name Scheme
       @{
    */
    /**
       Retrieves the default Classification scheme associated to the default Classification context.
       If not present, the system will create it.

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#CLS_err_missing_parameter if any of the mandatory input parameters are not specified or are nulls
       <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are passed in as null pointer
       </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_get_default_scheme(
        tag_t   default_context_tag,            /**< (I) Default Context tag. This is a mandatory parameter. */
        tag_t * default_scheme_tag,             /**< (O) Tag of the Default scheme object.
                                                   <br/>This is a mandatory parameter. */
        tag_t * default_scheme_type_tag         /**< (O) Type tag for Default scheme. */
        );
    /**
       @}
    */

    /**
       @name Hierarchy views
       @{
    */
    /**
       Retrieves default Classification hierarchy (root) object. If not found, creates one.

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#CLS_err_missing_parameter if any of the mandatory input parameters are not specified or are nulls
       <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are passed in as null pointer
       </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_get_default_view(
        tag_t   default_context_tag,            /**< (I) Tag of the context object under which a default hierarchy view object
                                                   is being searched for. This is a mandatory parameter. */
        tag_t * default_hierarchy_tag           /**< (O) Reference of the found hierarchy view object. This is a mandatory parameter. */
        );

    /**
       Retrieves all the hierarchy nodes associated with the default Classification hierarchy.

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are passed in as null pointer
       </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_get_all_nodes(
        int *    num_of_nodes,                  /**< (O)  The number of hierarchy nodes found.
                                                   <br/>This is a mandatory parameter. */
        tag_t ** node_tags                      /**< (OF) theNumOfNodes The tags of retrieved hierarchy nodes. */
        );

    /**
       Retrieves all the top level hierarchy nodes associated with the default Classification hierarchy.

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are passed in as null pointer
       </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_get_all_toplevel_nodes(
        int *    num_toplevel_nodes,            /**< (O)  The number of toplevel nodes found. This is a mandatory parameter. */
        tag_t ** toplevel_node_tags             /**< (OF) theNumOfFoundObjs The tags of the so found toplevel hierarchy nodes. */
        );
    /**
       @}
    */


    /**
       @name Hierarchy nodes
       @{
    */

    /**
       Creates a Group node for providing a folder like container for sub-hierarchy of nodes.

       @returns
       <ul>
       <li>#ITK_ok on success
       <li>#CLS_err_missing_parameter if any of the mandatory input parameters are not specified
       <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are passed in as null pointers
       </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_create_group_node
    (
        const char *    theNodeId,              /**< (I) Id of the group node being created. This is a mandatory parameter. */
        const char *    theNodeName,            /**< (I) Name of the group node being created. This is a mandatory parameter. */
        const char *    theNodeDescr,           /**< (I) Description for the group node object being created. */
        tag_t           theParentNodeTag,       /**< (I) Tag of the parent node for this group node object. This is a mandatory parameter. */
        tag_t           theHierarchyTag,        /**< (I) Tag of the hierarchy view object under which this group node object
                                                   is to be created. */
        logical         theIsLeafNode,          /**< (I) Flag indicating whether this node object is a leaf node or not. */
        int             theNodeSortLevel,       /**< (I) Sort level value for this group node object being created.
                                                   Indicates the position of this node among its peers. */
        tag_t *         theCreatedNodeTag       /**< (O) Reference of the newly created group node object. This is a mandatory parameter. */
        );

    /**
       Creates a Master node for representing legacy Classification storage classes.

       @returns
       <ul>
       <li>#ITK_ok on success
       <li>#CLS_err_missing_parameter if any of the mandatory input parameters are not specified
       <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are passed in as null pointers
       </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_create_master_node(
        const char * theNodeId,                 /**< (I) Id of the master node object being created. This is a mandatory parameter. */
        const char * theNodeName,               /**< (I) Name of the master node object being created. This is a mandatory parameter. */
        const char * theNodeDescr,              /**< (I) Description for the master node object being created. */
        tag_t        theParentNodeTag,          /**< (I) Tag of the parent node object for this master node object. This is a mandatory parameter. */
        tag_t        theHierarchyTag,           /**< (I) Tag of the hierarchy view object under which this master node object
                                                   is to be created. */
        logical      theIsLeafNode,             /**< (I) Flag indicating whete this master node object is a leaf node or not. */
        const char * theStorageTypeName,        /**< (I) The internal name of the class this master node is linked to. */
        int          theNodeSortLevel,          /**< (I) Sort level value for this master node object being created.
                                                   Indicates the position of this node among its peers. */
        tag_t *      theMasterNodeTag           /**< (O) Reference of the newly created master node object. This is a mandatory parameter. */
        );

    /**
       Creates a new Master node supporting Standard taxonomy.

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#CLS_err_missing_parameter if any of the mandatory input parameters are not specified or are nulls
       <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are passed in as null pointers
       </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_create_cst_master_node(
        const char*     node_id,            /**< (I) Id of the node object being created. This is a mandatory parameter. */
        const char*     node_name,          /**< (I) Name of the node object being created. This is a mandatory parameter. */
        const char*     node_desc,          /**< (I) Description for the node object being created. */
        tag_t           node_parent_tag,    /**< (I) Reference of the parent node object for this node object. */
        tag_t           hierarchy_tag,      /**< (I) Reference of the Classification hierarchy root. */
        logical         node_is_leaf,       /**< (I) Flag indicating whether this node is a leaf node or not. */
        const char*     class_namespace,    /**< (I) Namespace of the Storage class associated with this node. */
        const char*     class_id,           /**< (I) Id of the Storage class associated with this node. */
        const char*     class_revision,     /**< (I) Revision of the Storage class associated with this node. */
        int             node_peer_index,    /**< (I) Peer index value for the node being created.
                                            Indicates the position of this node among its peers. */
        tag_t*          created_node_tag    /**< (O) Reference of the newly created node object. This is a mandatory parameter. */
        );

    /**
       Creates an entire classification hierarchy from the root class id.

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#CLS_err_missing_parameter if any of the mandatory input parameters are not specified or are nulls
       <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are passed in as null pointer
       </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_create_node_hierarchy(
        const char *    root_storage_class_id   /**< (I) The name of the root class based on which a hierarchy is created. This is a mandatory parameter. */
        );

    /**
       Queries for any type of hierarchy node with given Id, under default context and hierarchy view.

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#CLS_err_missing_parameter if any of the mandatory input parameters are not specified or are nulls
       <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are passed in as null pointer
       </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_ask_node(
        const char *    node_id,                /**< (I)  The Id of the hierarchy node being searched for. This is a mandatory parameter. */
        tag_t *         node_tag                /**< (O)  The tag of the found node. This is a mandatory parameter. */
        );

    /**
       Finds a hierarchy node of given Id, under a given context and hierarchy view

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#CLS_err_missing_parameter if any of the mandatory input parameters are not specified or are nulls
       <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are passed in as null pointer
       </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_find_node(
        const char *    node_id,                /**< (I) Id of the hierarchy node being searched for. This is a mandatory parameter. */
        tag_t *         node_tag                /**< (O) Reference of the hierarchy node object found. This is a mandatory parameter. */
        );

    /**
       Searches for hierarchy nodes based on the specified ID or set of MFK attributes:

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#CLS_err_missing_parameter if any of the mandatory input parameters are not specified or are nulls
       <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are passed in as null pointer
       </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_search_nodes(
        const char*     bo_name,                /**< (I) The Business Object type name. This is a mandatory parameter. */
        int             num_attributes,         /**< (I) The number of MFK attributes. This is a mandatory parameter. */
        const char**    attribute_names,        /**< (I) num_attributes The MFK attribute names. This is a mandatory parameter. */
        const char**    attribute_values,       /**< (I) num_attributes The MFK attribute values. This is a mandatory parameter. */
        int*            num_objects,            /**< (O) The number of nodes found. This is a mandatory parameter. */
        tag_t**         objects                 /**< (OF) num_objects The nodes found. */
        );

    /**
       Deletes the specified hierarchy node with option to delete the children.

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#CLS_err_missing_parameter if any of the mandatory input parameters are not specified or are nulls
       <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are passed in as null pointer
       </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_delete_node(
        tag_t       node_tag,                   /**< (I) Reference of the Hierarchy node to be deleted. This is a mandatory parameter. */
        logical     delete_child_nodes,         /**< (I) Flag indicating whether the children node of this node
                                                   are also to be deleted. */
        logical     continue_on_error           /**< (I) Flag indicating whether the deletion process should go
                                                   ahead with other hierarchy node objects in case of error
                                                   with this hierarchy node. */
        );
    /**
       @}
    */

    /**
       @name Hierarchy node attachments
       @{
    */
    /**
       Creates an icon datset object and attaches it with the given hierarchy node object.

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#CLS_err_missing_parameter if any of the mandatory input parameters are not specified or are nulls
       <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are passed in as null pointer
       </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_import_hierarchy_node_icon(
        tag_t        node_tag,                  /**< (I) Tag of the hierarchy node with which the created icon dataset object is to
                                                   be attached. This is a mandatory parameter. */
        const char * os_full_path_name,         /**< (I) Path to the file for icon object. This is a mandatory parameter. */
        const char * new_file_name,             /**< (I) Name of the icon file. This is a mandatory parameter. */
        logical      do_update,                 /**< (I) Flag indicating whether the icon dataset object attached to theHierarchyNodeTag,
                                                   if it exists already, is to be updated or not. */
        tag_t *      created_icon_ds_tag        /**< (O) Reference of the newly created icon dataset object. This is a mandatory parameter. */
        );

    /**
       Retrieves the icon dataset object attached to a given hierarchy node object.

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#CLS_err_missing_parameter if any of the mandatory input parameters are not specified or are nulls
       <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are passed in as null pointer
       </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_get_hierarchy_node_icon (
        tag_t   node_tag,                       /**< (I) Tag of the hierarchy node object whose icon datset object is being accessed. This is a mandatory parameter. */
        tag_t*  created_icon_ds_tag             /**< (O) Reference of the icon datset object attached to theHierarchyNodeTag. This is a mandatory parameter. */
        );

    /**
       Removes or optionally deletes, attached icon dataset object to a given hierarchy node.

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#CLS_err_missing_parameter if any of the mandatory input parameters are not specified or are nulls
       <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are passed in as null pointer
       </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_remove_hierarchy_node_icon(
        tag_t   node_tag,                       /**< (I) Tag of the hierarchy node object from which the attached icon datset object
                                                   is to be removed. This is a mandatory parameter. */
        logical delete_dataset                  /**< (I) Flag indicating whether the icon dataset object should be deleted as well
                                                   on top of being detached from hierarchy node object. */
        );

    /**
       Attaches an existing icon datset object to a given hierarchy node object.

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#CLS_err_missing_parameter if any of the mandatory input parameters are not specified or are nulls
       <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are passed in as null pointer
       </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_add_hierarchy_node_icon(
        tag_t   node_tag,                       /**< (I)  The tag of the hierarchy node for which an icon
                                                   dataset object is to be attached. This is a mandatory parameter. */
        tag_t   icon_dataset_tag,               /**< (I)  The tag of the icon dataset object being added. This is a mandatory parameter. */
        logical do_update,                      /**< (I)  Flag to indicate whether existing icon dataset
                                                   is to be replaced by theIconDatasetTag. */
        tag_t * cls0nodeicon_relation_tag       /**< (O)  Reference of the newly created relation object between theIconDatasetTag
                                                   and theHierarchyNodeTag. This is a mandatory parameter. */
        );

    /**
       Creates an images datset object and attaches it with the given hierarchy node object.

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#CLS_err_missing_parameter if any of the mandatory input parameters are not specified or are nulls
       <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are passed in as null pointer
       </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_import_hierarchy_node_image(
        tag_t        node_tag,                  /**< (I) Tag of the hierarchy node object for which an image
                                                   dataset object is to be attached. This is a mandatory parameter. */
        const char * os_full_path_name,         /**< (I) Path to the image file. This is a mandatory parameter. */
        const char * new_file_name,             /**< (I) Name of the image file. This is a mandatory parameter. */
        logical      do_update,                 /**< (I) Flag to indicate whether existing primary image dataset objet
                                                   is to be replaced by this dataset object being created. */
        logical      is_primary_image,          /**< (I) Flag indicating whether this image datset object represent
                                                   the primary image the hierarchy node object is attached to. */
        tag_t *      created_image_ds_tag       /**< (O) Refernce of the image datset object attached to theHierarchyNodeTag. This is a mandatory parameter. */
        );

    /**
       Attaches an existing image dataset object to a given hierarchy node object.

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#CLS_err_missing_parameter if any of the mandatory input parameters are not specified or are nulls
       <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are passed in as null pointer
       </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_add_hierarchy_node_image(
        tag_t       node_tag,                   /**< (I) Tag of the hierarchy node objct for which an image
                                                   datset object is to be added as it image datasets. This is a mandatory parameter. */
        tag_t       image_ds_tag,               /**< (I) Tag of an existing image dataset object. This is a mandatory parameter. */
        logical     do_update,                  /**< (I) Flag indicating whether this image dataset object should replace
                                                   the existing primary image datset object. */
        logical     is_primary,                 /**< (I) Flag indicating whether this image datset object is to be
                                                   made the primary image dataset object for theHierarchyNodeTag. */
        tag_t *     cls0nodeimage_relation_tag  /**< (O) Reference of the newly created relation object between theImageDatasetTag
                                                   and theHierarchyNodeTag. This is a mandatory parameter. */
        );

    /**
       Obtains the primary image dataset object attached to a given hierarchy node object.

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#CLS_err_missing_parameter if any of the mandatory input parameters are not specified or are nulls
       <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are passed in as null pointer
       </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_get_hierarchy_node_image (
        tag_t   theHierarchyNodeTag,            /**< (I) Tag of the hierarchy node object whose primary image dataset if being
                                                   searched for. This is a mandatory parameter. */
        tag_t*  theImageDatasetTag              /**< (O) Reference of the image dataset object of theHierarchyNodeTag (primary). This is a mandatory parameter. */
        );

    /**
       Obtains all image datasetes attached to a given hierarchy node object.

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#CLS_err_missing_parameter if any of the mandatory input parameters are not specified or are nulls
       <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are passed in as null pointer
       </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_get_hierarchy_node_images (
        tag_t    node_tag,                      /**< (I)  Tag of the hierarchy node objct whose attached image datset objects
                                                   beings searched for. This is a mandatory parameter. */
        int *    num_image_datasets,            /**< (O)  The number of attached image datset object found for theHierarchyNodeTag. This is a mandatory parameter. */
        tag_t ** image_dataset_tags             /**< (OF) theNumImageDatasets Image dataset tags. This is a packed array. */
        );

    /**
       Removes or optionally deletes, existing image dataset object attached to a given hierarchy node object.

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#CLS_err_missing_parameter if any of the mandatory input parameters are not specified or are nulls
       <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are passed in as null pointer
       </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_remove_hierarchy_node_image(
        tag_t   node_tag,                       /**< (I) Tag of the hierarchy node object from which the attached image dataset object
                                                   is to be removed. This is a mandatory parameter. */
        tag_t   image_dataset_tag,              /**< (I) Tag of the image dataset object to be detached from theHierarchyNodeTag. This is a mandatory parameter. */
        logical delete_dataset                  /**< (I) Flag indicating whether the image dataset object should be deleted as well on
                                                   top of being detached from theHierarchyNodeTag. */
        );
    /**
       @}
    */

    /**
       @name Introspection on Hierarchy nodes
       @{
    */
    /**
       Finds all the storage class properties for a given hierarchy node object.

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#CLS_err_missing_parameter if any of the mandatory input parameters are not specified or are nulls
       <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are passed in as null pointer
       </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_ask_node_class_properties(
        tag_t    node_tag,                      /**< (I)  Tag of the hierarchy node whose class properties are being queried. This is a mandatory parameter. */
        int *    num_class_properties,          /**< (O)  Number of class properties found. This is a mandatory parameter. */
        tag_t ** class_properties               /**< (OF) thePropertyCount property tags */
        );

    /**
       Finds all the Classification Attributes for the specified Teamcenter Type that represents a Classification Class.

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#CLS_err_missing_parameter if any of the mandatory input parameters are not specified or are nulls
       <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are passed in as null pointer
       </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_ask_classification_properties_for_type(
        const char  * type_name,                /**< (I)  TcType name representing a Classification Class. This is a mandatory parameter.   */
        int         * num_classification_props, /**< (O)  Number of class properties found. This is a mandatory parameter.                  */
        tag_t       ** classification_props     /**< (OF) num_classification_props property descriptors for Classification Attributes.      */
        );

    /**
       Finds a given storage class property for a given hierarchy node object.

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#CLS_err_missing_parameter if any of the mandatory input parameters are not specified or are nulls
       <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are passed in as null pointer
       </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_ask_node_class_property(
        tag_t         node_tag,                 /**< (I)  Tag of the hierarchy node object for which a particular
                                                   class property is being queried for. This is a mandatory parameter. */
        const char *  property_name,            /**< (I)  Name of the property being queried. This is a mandatory parameter. */
        tag_t *       property_tag              /**< (O)  Reference of the tag of thePropertyName. This is a mandatory parameter. */
        );

    /**
       Retrieves the Storage class type tag for the specified Hierarchy node

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#CLS_err_missing_parameter if any of the mandatory input parameters are not specified or are nulls
       <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are passed in as null pointer
       </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_ask_node_class_type(
        tag_t         node_tag,                 /**< (I)  The tag of master node, associated class of which
                                                   is to be found out. This is a mandatory parameter. */
        tag_t *       storage_class_type_tag    /**< (O)  Reference of the type tag for the class that the
                                                   master node theNodeTag refers to. This is a mandatory parameter. */
        );

    /**
       Finds the parent node for a given hierarchy node object.

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#CLS_err_missing_parameter if any of the mandatory input parameters are not specified or are nulls
       <li>#CLS_err_node_not_found if theNodeTag parameter is a NULLTAG
       <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are passed in as null pointer
       </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_ask_node_parent(
        tag_t   node_tag,                       /**< (I)  The tag of the node whose parent node is to be found out.
                                                   This is a mandatory parameter. */
        tag_t*  parent_node_tag                 /**< (O)  The tag of the fetched parent hierarchy node object. */
        );

    /**
       Finds all or certain types of children for a given hierarchy node.

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#CLS_err_missing_parameter if any of the mandatory input parameters are not specified or are nulls
       <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are passed in as null pointer
       </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_ask_node_children(
        tag_t    node_tag,                      /**< (I)  The tag of the node whose children nodes are to be found. This is a mandatory parameter. */
        int      child_node_type,               /**< (I)  Filter value indicating the type of children nodes being
                                                   searched for.
                                                   CLS_NODE_group
                                                   CLS_NODE_master
                                                   CLS_NODE_all*/
        int*     num_child_nodes,               /**< (O)  The number of children nodes found. This is a mandatory parameter. */
        tag_t ** child_node_tags                /**< (OF) theChildCount Child node tags */
        );

    /**
       Finds the ancestor nodes for a given hierarchy node.

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#CLS_err_missing_parameter if any of the mandatory input parameters are not specified or are nulls
       <li>#CLS_err_node_not_found if theNodeTag is invalid
       <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are passed in as null pointer
       </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_ask_node_ancestors(
        tag_t    node_tag,                      /**< (I)  The hierarchy node tag whose ancestors nodes are to be found.
                                                   This is a mandatory parameter. */
        int *    num_ancestor_nodes,            /**< (O)  The number of ancestor nodes found. This is a mandatory parameter. */
        tag_t ** ancestor_node_tags             /**< (OF) theAncestorCount The tags of the found ancestor nodes. */
        );

    /**
       Checks whether a given hierarchy node is a top level node or not.

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#CLS_err_missing_parameter if any of the mandatory input parameters are not specified or are nulls
       <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are passed in as null pointer
       </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_is_top_level_node(
        tag_t     node_tag,                     /**< (I)  The tag of the hierarchy node object which we are interested
                                                   in finding whether it is a toplevel node or not. This is a mandatory parameter. */
        logical * is_toplevel_node              /**< (O)  A logical value indicating whether theNodeTag is a top level
                                                   node or not. This is a mandatory parameter. */
        );

    /**
       Checks whether the given node is a descendent of the specified parent node.

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#CLS_err_missing_parameter if any of the mandatory input parameters are not specified or are nulls
       <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are passed in as null pointer
       </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_is_descendent_node(
        tag_t     node_tag,                     /**< (I)  The tag of the hierarchy node object which we are interested
                                                   in finding whether it is a descendent of another hierarchy node
                                                   theAncestorTag. This is a mandatory parameter. */
        tag_t     ancestor_tag,                 /**< (I)  The tag of a hierarchy node which is the ancestor node is question
                                                   for theNodeTag. This is a mandatory parameter. */
        logical * is_descendent_verdict           /**< (O)  Logical value indicating whether theNodeTag is descendent of
                                                     theAncestorTag node object or not. This is a mandatory parameter. */
        );

    /**
       Finds the hierarchy node type for a given hierarchy node object.

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#CLS_err_missing_parameter if any of the mandatory input parameters are not specified or are nulls
       <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are passed in as null pointer
       </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_ask_node_type(
        tag_t node_tag,                         /**< (I)  The tag of the hierarchy node whose type is being asked for. This is a mandatory parameter.  */
        int * node_type                         /**< (O)  Integer value indicating the type of the hierarchy node theNodeTag. This is a mandatory parameter. */
        );

    /**
       Finds the classified instances for a given hierarchy node object.

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#CLS_err_missing_parameter if any of the mandatory input parameters are not specified or are nulls
       <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are passed in as null pointer
       </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_ask_node_instances(
        tag_t    node_tag,                      /**< (I)  The tag of the hierarchy node whose classified instances are being
                                                   searched for. This is a mandatory parameter. */
        logical  include_children,              /**< (I)  Flag indicating whether children of theNodeTag should be included
                                                   in the query or not. */
        int *    num_instances,                 /**< (O)  The number of instances found for the hierarchy node theNodeTag. This is a mandatory parameter. */
        tag_t ** instance_tags                  /**< (OF) theInstanceCount Instance tags */
        );

    /**
        @deprecated #CLS_describe_node deprecated in Teamcenter 12.0. Use #CLS_describe_node2 instead.

        Describes a given Hierarchy node in terms of the its properties: Node Id, name, description, Parent node reference and node type.
        All output parameters are optional, however atleast one parameter must be supplied for this operation to return any data.

        @returns
        <ul>
          <li>#ITK_ok on success.
          <li>#CLS_err_missing_parameter if any of the mandatory input parameters are not specified or are nulls
          <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are passed in as null pointer
        </ul>
    */
    TC_DEPRECATED("12.0","CLS_describe_node","CLS_describe_node2")
    extern CLS0CLASSIFICATION_API int CLS_describe_node(
        tag_t   node_tag,                       /**<  (I) The tag of the hierarchy node whose properties are being asked for. This is a mandatory parameter. */
        char ** node_id,                        /**< (OF) The ID of this hierarchy node. */
        char ** node_name,                      /**< (OF) The name of this hierarchy node. */
        char ** node_desc,                      /**< (OF) The description of this hierarchy node. */
        tag_t * node_parent_tag,                /**<  (O) Reference of the parent node. For top level nodes, this will return a NULLTAG. */
        int *   node_type                       /**<  (O) Integer value indicating the type of this hierarchy node. See #Cls0NodeType_e for possible values. */
        );

    /**
       Describes a given Hierarchy node in terms of the its properties: Node Id, name, description, Parent node reference and node type.
       All output parameters are optional, however atleast one parameter must be supplied for this operation to return any data.

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#CLS_err_missing_parameter if any of the mandatory input parameters are not specified or are nulls
       <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are passed in as null pointer
       </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_describe_node2(
        tag_t      node_tag,                 /**<  (I) The tag of the hierarchy node whose properties are being asked for. This is a mandatory parameter. */
        char**     node_id,                  /**< (OF) The ID of this hierarchy node. */
        char**     node_name,                /**< (OF) The name of this hierarchy node. */
        char**     node_desc,                /**< (OF) The description of this hierarchy node. */
        tag_t*     node_parent_tag,          /**<  (O) Reference of the parent node. For top level nodes, this will return a NULLTAG. */
        int*       node_type,                /**<  (O) Integer value indicating the type of this hierarchy node. See #Cls0NodeType_e for possible values. */
        logical*   node_is_abstract          /**<  (O) Flag indicating whether the Node is marked as abstract or not */
    );

    /**
       Checks whether certain characteristics defined in Cls0NodeCharacteristicType_e
       are set or unset for a given node.

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#CLS_err_missing_parameter if any of the mandatory input parameters are not specified or are nulls
       <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are passed in as null pointer
       </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_ask_node_characteristic(
        tag_t       node_tag,                   /**< (I) The tag of the hierarchy node whose characteristic is being queried. */
        int         node_characteristic,        /**< (I) The characteristic value being queried. See #Cls0NodeCharacteristicType_e for possible values. */
        logical *   node_characteristic_value   /**< (O) Flag that represents whether the given characteristic is set or not for
                                                   theHierarchyNodeTag. */

        );
    /**
       @}
    */

    /**
       @name Search
       @{
    */
    /**
       Creates an enquiry on a given hierarchy node object.

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#CLS_err_missing_parameter if any of the mandatory input parameters are not specified or are nulls
       <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are passed in as null pointer
       </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_enquiry_create_node_enquiry(
        const char * query_name,            /**< (I)  Unique name for a query. This is a mandatory parameter. */
        tag_t        node_tag,              /**< (I)  The tag of the hierarchy node. This is a mandatory parameter. */
        int          options,               /**< (I)  Query options */
        char**       node_expression        /**< (OF) Combined expression created for theHierarchyNode. This is a mandatory parameter. */
        );

    /**
       Creates a search expression for a given query.

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#CLS_err_missing_parameter if any of the mandatory input parameters are not specified or are nulls
       <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are passed in as null pointer
       </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_enquiry_create_cls_expression(
        const char *  query_name,           /**< (I) Unique name for a query. */
        const char *  expression_name,      /**< (I) Unique name of expression for enquiry creation. */
        tag_t         node_tag,             /**< (I) Hierarchy node object to which the enquiry is attached to. */
        int           num_properties,       /**< (I) Number of properties. */
        const char ** property_names,       /**< (I) Array of property names to create expression on. */
        const char ** property_expression,  /**< (I) Array of expression for each property name. */
        int           options               /**< (I) Option values. */
        );

    /**
       Creates a search expression for a given hierarchy node object.

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#CLS_err_missing_parameter if any of the mandatory input parameters are not specified or are nulls
       <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are passed in as null pointer
       </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_enquiry_create_node_expression(
        const char * query_name,            /**< (I)  Unique name for a query */
        tag_t        node_tag,              /**< (I)  Tag of the hierarchy node */
        char **      property_names         /**< (OF) List of property names*/
        );

    /**
       Searches for classification objects.
       The ITK returns an ID to a Result Set container, which can then be traversed using #CLS_get_search_result to get
       hold of the search results.

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#CLS_err_missing_parameter if any of the mandatory input parameters are not specified or are nulls
       <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are passed in as null pointer
       </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_search_classification_objects(
        tag_t          node_tag,                    /**< (I)  Tag of the hierarchy node whose classified objects are being searched for. */
        int            property_count,              /**< (I)  Number of properties in this query. */
        const char **  property_names,              /**< (I)  Array of the property names of the classification storage class. */
        const char**   property_expressions,        /**< (I)  Array of experession for thePropertyNames*/
        int            options,                     /**< (I)  Search options */
        int            num_sort_order_properties,   /**< (I)  Number of properties to be used to sorting the result. */
        int *          sort_order_for_properties,   /**< (I)  Sort order for each of the specified property in theOrderPropertyNames */
        const char **  sort_property_names,         /**< (I)  List of property names to be used in the sort. */
        int            object_list_size,            /**< (I)  Number of objects found in previous search operation. */
        tag_t*         object_list,                 /**< (I)  List of objects found in previous search operation upon which the current search is to be run. */
        int *          total_num_objects_found,     /**< (O)  Total number of rows retrieved */
        int *          num_objects_returned,        /**< (O)  Number of rows being sent to the user */
        char **        result_set_id                /**< (OF) theNumRow The obtained resultset of size theNumRow */
        );

    /**
       Discards the Result set returned by earlier search on Classification objects.
       This Result set can is uniquely identified using Result set ID returned by the earlier search.

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#CLS_err_missing_parameter if any of the mandatory input parameters are not specified or are nulls
       </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_discard_search_result(
        const char* result_set_id           /**< (I)  The result set ID to discard. This is a mandatory parameter. */
        );

    extern CLS0CLASSIFICATION_API int CLS_get_search_result(
        const char* result_set_id,          /**< (I)  The result ID to discard */
        int         start_position,         /**< (I)  The result position in the Result Set to start fetching the object from */
        int         num_objects_to_fetch,   /**< (I)  The number of objects to fetch from the Result Set */
        int*        num_objects,            /**< (O)  The number of objects fetched. If lesser than theNumObjects, it could be that the end of the Result Set has been reached.*/
        tag_t**     object_tags             /**< (OF) theNumFetchedObjects The number of objects fetched from the query */
        );
    /**
       @}
    */

    /**
       @name Classification objects (data)
       @{
    */
    /**
       Creates a classification object.

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#CLS_err_missing_parameter if any of the mandatory input parameters are not specified or are nulls
       <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are passed in as null pointer
       </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_create_classification_object(
        const char * object_id,                 /**< (I) Id of the classification object to be created. */
        const char * object_name,               /**< (I) Name of the classification object to be created. */
        const char * object_desc,               /**< (I) Description for the classification object to be created. */
        tag_t        node_tag,                  /**< (I) Tag of the hierarchy node object under which this
                                                   classification object is to be created. */
        tag_t        object_to_classify,        /**< (I) Tag of the workspace object being classified. */
        tag_t *      classification_object_tag  /**< (O) Reference of the created classification object. */
        );

    /**
       Creates a classification object.

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#CLS_err_missing_parameter if any of the mandatory input parameters are not specified or are nulls
       <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are passed in as null pointer
       <li>#CLS_err_cannot_classify_to_abstract_node if Storage Class associated to the Hierarchy node is either missing or Abstract
       </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_create_classification_object2(
        const char  * object_id,                    /**< (I) Id of the classification object to be created. */
        const char  * object_name,                  /**< (I) Name of the classification object to be created. */
        const char  * object_description,           /**< (I) Description for the classification object to be created. */
        tag_t         hierarchy_node_tag,           /**< (I) Tag of the hierarchy node object under which this
                                                             classification object is to be created. */
        const char  * storage_type_name,            /**< (I) Storage Type name representing the storage Class associated to the specified hierarchy_node_tag.
                                                             This optional parameter should be used, when the Storage Type to be used is different from the
                                                             default Storage type associated to the hierarchy_node_tag. */
        tag_t         wso_tag,                      /**< (I) Tag of the workspace object being classified. */
        tag_t       * classification_Object         /**< (O) Reference of the created classification object. */
    );
    /**
       Asks for associated Classification object for the specified Teamcenter object.
       If the Teamcenter object is not classified, a NULLTAG will be returned back.

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#CLS_err_missing_parameter if any of the mandatory input parameters are not specified or are nulls
       <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are passed in as null pointer
       </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_ask_classified_object(
        tag_t    classification_object_tag,    /**< (I) Tag of the classified object being queried for. This is a mandatory parameter. */
        tag_t*   classified_object_tag         /**< (O) Reference of the found classified object. This is a mandatory parameter. */
        );

    /**
       Retrieves the Classification objects classified under the specified Hierarchy node.

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#CLS_err_missing_parameter if any of the mandatory input parameters are not specified or are nulls
       <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are passed in as null pointer
       </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_get_classification_objects(
        tag_t    node_tag,              /**< (I)  The hierarchy node to query. This is a mandatory parameter. */
        int      search_option,         /**< (I)  Options to search hierarchical or local. Valid values are CLS_SEARCH_default and CLS_SEARCH_in_class_only.*/
        int*     num_objects,           /**< (O)  The number of objects returned by query. This is a mandatory parameter. */
        tag_t ** object_tags            /**< (OF) theNumObjects Objects returned by query. */
        );

    /**
       @deprecated #CLS_find_classification_object deprecated in Teamcenter 11.5. Use #CLS_find_classification_objects instead.

       Finds the classification object for the specified object ID.

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#CLS_err_missing_parameter if any of the mandatory input parameters are not specified or are nulls
       <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are passed in as null pointer
       </ul>
    */
    TC_DEPRECATED("11.5","CLS_find_classification_object","CLS_find_classification_objects")
    extern CLS0CLASSIFICATION_API int CLS_find_classification_object(
        const char * object_id,                 /**< (I) The Id of the classification object being searched for. This is a mandatory parameter. */
        tag_t *      classification_object_tag  /**< (O) The tag of the found classification object. This is a mandatory parameter. */
        );

    /**
        Finds the classification objects for the specified object ID.

        @returns
        <ul>
        <li>#ITK_ok on success.
        <li>#CLS_err_missing_parameter if any of the mandatory input parameters are not specified or are nulls
        <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are passed in as null pointer
        </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_find_classification_objects(
        const char * object_id,                  /**< (I) The Id of the classification object being searched for. This is a mandatory parameter. */
        int *        num_classification_objects, /**< (O) The number of found classification objects. */
        tag_t**      classification_object_tags  /**< (OF) num_classification_objects The tags of the found classification objects. This is a mandatory parameter. */
        );


    /**
        Finds property recoreds using a JSON request string, and outputs a JSON response string containing the objects and any errors.

        @returns
        <ul>
        <li>#ITK_ok on success.
        <li>Possibly other errors.
        </ul>

        @note Errors are returned through the JSON response if any are present, which the caller needs to handle.
    */
    extern CLS0CLASSIFICATION_API int CLS_find_property_records(
        const char* request,                     /**< (I) The JSON request. */
        char** response                          /**< (OF) The information on found objects in JSON string format and any error response */
        );

   /**
       Asks the owning node for a provided Classification object.
       If the owning node exists, its tag is returned. If not, a NULLTAG is returned.

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>#CLS_err_missing_parameter if any of the mandatory input parameters are not specified or are nulls
       <li>#CLS_err_missing_mandatory_output_param if any of the mandatory output parameters are passed in as null pointer
       </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_ask_owning_node(
        tag_t      classification_object,          /**< (I)  The tag of the Classification object whose owning node is requested. */
        tag_t*     owning_node                     /**< (O)  Tag of Hierarchy node that owns the specified Classification object. */
        );
    /**
       @}
    */

    /**
       @name Classification Standard Taxonomy
       @{
    */
    /**
       Creates or updates keylov definitions using a passed in JSON request string, outputs any errors through a JSON response string

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>Possibly other errors.
       </ul>

       @note Errors are returned through the JSON response if any are present, which the caller needs to handle.
    */
    extern CLS0CLASSIFICATION_API int CLS_save_keylov_definitions(
        const char* request,                                                /**< (I) The JSON request. */
        char** response                                                     /**< (OF) Output for any error response regarding the objects or JSON */
        );

    /**
        Searches classification definitions using the criteria provided in the input JSON string and outputs a JSON string containing search results.

        @returns
        <ul>
        <li>#ITK_ok on success.
        <li>Possibly other errors.
        </ul>

        @note Errors are returned through the JSON response if any are present, which the caller needs to handle.
    */
    extern CLS0CLASSIFICATION_API int CLS_search_classification_definitions(
        const char* request,    /**< (I) The JSON request string. */
        char** response         /**< (OF) The JSON response containing search results. */
        );

    /**
       Retrieves keylov definitions using a JSON request string, and outputs a JSON response string containing the objects and any errors.
       Input file in JSON must follow the format specified in Classification_IRDIRequest.schema.json.

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>Possibly other errors.
       </ul>

       @note Errors are returned through the JSON response if any are present, which the caller needs to handle.
    */
    extern CLS0CLASSIFICATION_API int CLS_get_keylov_definitions(
        const char* request,                                                 /**< (I) The JSON request that contains the key LOV definitions. */
        char** response                                                      /**< (OF) JSON-formatted string containing the information on the found objects and any potential response error.*/
        );

    /**
    Finds keylov definitions using a JSON request string, and outputs a JSON response string containing the objects and any errors.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>Possibly other errors.
    </ul>

    @note Errors are returned through the JSON response if any are present, which the caller needs to handle.
    */
    extern CLS0CLASSIFICATION_API int CLS_find_keylov_definitions(
        const char* request,                                                /**< (I) The JSON request. */
        char** response                                                     /**< (OF) The information on found objects in JSON string format and any error response */
    );

    /**
       Deletes keylov definitions using a JSON request string, outputs any errors through a JSON response string

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>Possibly other errors.
       </ul>

       @note Errors are returned through the JSON response if any are present, which the caller needs to handle.
    */
    extern CLS0CLASSIFICATION_API int CLS_delete_keylov_definitions(
        const char* request,                                                   /**< (I) The JSON request. */
        char** response                                                        /**< (OF) Output for any error response regarding the objects or JSON */
        );

    /**
       Creates or updates property definitions using a passed in JSON request string, outputs any errors through a JSON response string

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>Possibly other errors.
       </ul>

       @note Errors are returned through the JSON response if any are present, which the caller needs to handle.
    */
    extern CLS0CLASSIFICATION_API int CLS_save_property_definitions(
        const char* request,                                                   /**< (I) The JSON request. */
        char** response                                                        /**< (OF) Output for any error response regarding the objects or JSON */
        );

    /**
       Finds property definitions using a JSON request string, and outputs a JSON response string containing the objects and any errors.

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>Possibly other errors.
       </ul>

       @note Errors are returned through the JSON response if any are present, which the caller needs to handle.
    */
    extern CLS0CLASSIFICATION_API int CLS_find_property_definitions(
        const char* request,                                                 /**< (I) The JSON request. */
        char** response                                                      /**< (OF) The information on found objects in JSON string format and any error response */
        );

    /**
    Retrieves property definitions using a JSON request string, and outputs a JSON response string containing the objects and any errors.
    Input file in JSON must follow the format specified in Classification_IRDIRequest.schema.json.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>Possibly other errors.
    </ul>

    @note Errors are returned through the JSON response if any are present, which the caller needs to handle.
    */
    extern CLS0CLASSIFICATION_API int CLS_get_property_definitions(
        const char* request,                                                 /**< (I) The JSON request that contains the property definitions. */
        char** response                                                      /**< (OF) JSON-formatted string containing the information on the found objects and any potential response error.*/
    );

    /**
       Deletes property definitions using a JSON request string, outputs any errors through a JSON response string

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>Possibly other errors.
       </ul>

       @note Errors are returned through the JSON response if any are present, which the caller needs to handle.
    */
    extern CLS0CLASSIFICATION_API int CLS_delete_property_definitions(
        const char* request,                                                   /**< (I) The JSON request. */
        char** response                                                        /**< (OF) Output for any error response regarding the objects or JSON */
        );

    /**
       Creates or updates class definitions using a passed in JSON request string, outputs any errors through a JSON response string

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>Possibly other errors.
       </ul>

       @note Errors are returned through the JSON response if any are present, which the caller needs to handle.
    */
    extern CLS0CLASSIFICATION_API int CLS_save_class_definitions(
        const char* request,                                                   /**< (I) The JSON request. */
        char** response                                                        /**< (OF) Output for any error response regarding the objects or JSON */
        );

    /**
       Finds class definitions using a JSON request string, and outputs a JSON response string containing the objects and any errors.

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>Possibly other errors.
       </ul>

       @note Errors are returned through the JSON response if any are present, which the caller needs to handle.
    */
    extern CLS0CLASSIFICATION_API int CLS_find_class_definitions(
        const char* request,                                                /**< (I) The JSON request. */
        char** response                                                     /**< (OF) The information on found objects in JSON string format and any error response */
        );

    /**
    Retrieves class definitions using a JSON request string, and outputs a JSON response string containing the objects and any errors.
    Input file in JSON must follow the format specified in Classification_IRDIRequest.schema.json.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>Possibly other errors.
    </ul>

    @note Errors are returned through the JSON response if any are present, which the caller needs to handle.
    */
    extern CLS0CLASSIFICATION_API int CLS_get_class_definitions(
        const char* request,                                                   /**< (I) The JSON request that contains the class definitions. */
        char** response                                                        /**< (OF) JSON-formatted string containing the information on the found objects and any potential response error.*/
    );



    /**
       Deletes class definitions using a JSON request string, outputs any errors through a JSON response string

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>Possibly other errors.
       </ul>

       @note Errors are returned through the JSON response if any are present, which the caller needs to handle.
    */
    extern CLS0CLASSIFICATION_API int CLS_delete_class_definitions(
        const char* request,                                                   /**< (I) The JSON request. */
        char** response                                                        /**< (OF) Output for any error response regarding the objects or JSON */
        );

    /**
       Updates status of object definitions using a passed in JSON request string, outputs any errors through a JSON response string

       Please refer to JSON schema file !!! TODO: add schema once available !!!

       Valid values in the request for a new status are "Develop", "Released" and "Retired".
       You can only change the status:
       <ul>
       <li>from "Develop" to "Released" or "Retired"
       <li>from "Released" to "Retired"
       </ul>

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>Possibly other errors.
       </ul>

       @note Errors are returned through the JSON response if any are present, which the caller needs to handle.
    */
    extern CLS0CLASSIFICATION_API int CLS_update_status_on_objects(
        const char* request,                                                   /**< (I) The JSON request. */
        char** response                                                        /**< (OF) Output for any error response regarding the objects or JSON */
        );

    /**
       Creates or updates node definitions using a passed in JSON request string, outputs
       any errors through a JSON response string

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>Possibly other errors.
       </ul>

       @note Errors are returned through the JSON response if any are present, which the caller needs to handle.
    */
    extern CLS0CLASSIFICATION_API int CLS_save_node_definitions(
        const char* request,                                                   /**< (I) The JSON request. */
        char** response                                                        /**< (OF) Output for any error response regarding the objects or JSON */
        );

    /**
       Deletes node definitions using a passed in JSON request string, outputs any errors
       through a JSON response string

       @returns
       <ul>
       <li>#ITK_ok on success.
       <li>Possibly other errors.
       </ul>

       @note Errors are returned through the JSON response if any are present, which the caller needs to handle.
    */
    extern CLS0CLASSIFICATION_API int CLS_delete_node_definitions(
        const char* request,                                                   /**< (I) The JSON request. */
        char** response                                                        /**< (OF) Output for any error response regarding the objects or JSON */
        );

    /**
        Creates or updates view definitions using a passed in JSON request string, outputs any errors through a JSON response string.

        @returns
        <ul>
        <li>#ITK_ok on success.
        <li>#CST_err_no_valid_json if @p request is not a valid JSON file.
        <li>#CST_err_schema_validation if the JSON schema validation of @p request fails.
        <li>Possibly other errors. More information about the error will be in @p response.
        </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_create_view_definitions(
        const char*     request,        /**< (I) The request in a JSON format. If this is not a valid JSON request, it is treated to be valid precise class definition IRDI (International Registration Data Identifier). */
        logical         force_switch,   /**< (I) The force switch. Its value will be honored only if @p request is empty.
                                                 If @c true, BaseViews will be created for all class definitions of type "Application Class" and status "Released" in the system.
                                                 If @c false, BaseViews will be created for class definitions of type "Application Class" and status "Released" in the system which do not have BaseViews. */
        char**          response        /**< (OF) The response in a JSON format for the creation of the objects. */
        );

    /**
        Finds view definitions using a JSON request string, and outputs a JSON response string containing the objects and any errors.

        @returns
        <ul>
        <li>#ITK_ok on success.
        <li>#CST_err_no_valid_json if @p request is not a valid JSON file.
        <li>#CST_err_schema_validation if the JSON schema validation of @p request fails.
        <li>Possibly other errors. More information about the error will be in @p response.
        </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_get_view_definitions(
        const char*     request,    /**< (I) The request in a JSON format. */
        char**          response    /**< (OF) The information on found objects in JSON format and any error response. */
        );

    /**
        Deletes view definitions using a passed in JSON request string, outputs any errors through a JSON response string.

        @returns
        <ul>
        <li>#ITK_ok on success.
        <li>#CST_err_no_valid_json if @p request is not a valid JSON file.
        <li>#CST_err_schema_validation if the JSON schema validation of @p request fails.
        <li>Possibly other errors. More information about the error will be in @p response.
        </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_delete_view_definitions(
        const char*     request,    /**< (I) The request in a JSON format. */
        char**          response    /**< (OF) The response in a JSON format for the deletion of the objects. */
       );


    /**
        Saves classification objects using the input JSON request string and returns a JSON response with information about the saved objects along with any errors.
        @note An error will be returned if the operation could not be completed successfully and information about the error will be in @p response.

        @returns
        <ul>
        <li>#ITK_ok on success.
        </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_save_classification_objects(
        const char* request,                                                   /**< (I) The request in a JSON format. */
        char** response                                                        /**< (OF) The response in a JSON format for the saved classification objects. */
       );

    /**
        Gets classification objects and their properties using the input JSON request and outputs a JSON response with this information along with any errors.
        @note An error will be returned if the operation could not be completed successfully and information about the error will be in @p response.

        @returns
        <ul>
        <li>#ITK_ok on success.
        </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_get_classification_properties(
        const char* request,                                                   /**< (I) The request in a JSON format. */
        char** response                                                        /**< (OF) The response in a JSON format for the properties of the objects. */
    );

    /**
        Deletes the classification objects using the input JSON request and outputs a JSON response with information about deleted objects along any errors.
        @note An error will be returned if the operation could not be completed successfully and information about the error will be in @p response.

        @returns
        <ul>
        <li>#ITK_ok on success.
        </ul>
    */
    extern CLS0CLASSIFICATION_API int CLS_delete_classification_objects(
        const char* request,                                                   /**< (I) The request in a JSON format. */
        char** response                                                        /**< (OF) The response in a JSON format for the deletion of the objects. */
    );

    /**
    Imports node definitions using a passed in JSON request string, outputs any errors through a JSON response string

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>Possibly other errors.
    </ul>

    @note Errors are returned through the JSON response if any are present, which the caller needs to handle.
    */
    extern CLS0CLASSIFICATION_API int CLS_import_classification_definitions(
        const char* request,                                                   /**< (I) The request in a JSON format. */
        logical     dry_run,                                                   /**< (I) Validate the input json without creating classification definitions if it is set to true otherwise definitions will get created */
        char**      response                                                   /**< (OF) The retrieved classification definitions in Json string format. */
    );

     /**
   @}
 */

#ifdef __cplusplus
}
#endif

/** @} */

#include <Cls0classification/libcls0classification_undef.h>
#endif /* CLS_ITK_H */
