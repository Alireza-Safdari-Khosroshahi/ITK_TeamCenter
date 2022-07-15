/*
    Copyright 2020 Siemens Digital Industries Software
    ==================================================
    Copyright 2015.
    Siemens Product Lifecycle Management Software Inc.
    All Rights Reserved.
    ==================================================
    Copyright 2020 Siemens Digital Industries Software
*/

/** 
    @file 
 
    This file contains the definition of user exits for Visualization.
 
*/
#ifndef VIS_USER_EXIT_H
#define VIS_USER_EXIT_H

#include <unidefs.h>

#include <vis/libvis_exports.h>

/**
    @defgroup VISUALIZATION Visualization
    @ingroup TC
    
    This module implements the ITK methods exposed by the Visualization module.
    @{
*/

/**
    Provides new user exit to generate the MetadataStamp filename for an object.
*/
#define USER_VIS_get_metadata_filename_msg           "BMF_USER_VIS_get_metadata_filename"

/**
    Provides new user exit to generate the MetaDataStamp filename for an object with context.
*/
#define USER_VIS_get_metadata_filename_context_msg   "BMF_USER_VIS_get_metadata_filename_context"

/**
    Provides new user exit to generate the base document for an object to be visualized.
*/
#define USER_VIS_get_basedocument_msg                "BMF_USER_VIS_get_basedocument"


/** 
  Generic structure for holding key/value pairs.
*/
typedef struct VIS_additional_keyvalue_s
{
      char* key;             /**< Name of the key. */
      char* value;           /**< Its value. */
} VIS_additional_keyvalue_t,*VIS_additional_keyvalue_p_t;

/**
    Teamcenter object and its related information needed in order for the objects to be visualized.
    <br/>For example, to visualize Dataset, context information like its Item, ItemRevision may possibly be needed.
*/
typedef struct VIS_object_input_s
{
    tag_t   object;                                 /**< The object on which base document is retrieved. */
    int     n_context_tags;                         /**< The number of context objects. */
    tag_t*  context_tags;                           /**< Its list of context objects. It can be #NULLTAG(s).*/
    int       n_key_value;                          /**< The number of additional key/value pairs. */ 
    VIS_additional_keyvalue_p_t   additional_info;  /**< Array of length n_key_value that contains the additional key/value pairs. */
} VIS_object_input_t, *VIS_object_input_p_t;

/**
    The base document of the Teamcenter object will be loaded by Teamcenter Visualization.
    <br/>For example, if an Item is visualized, it is resolved to either BomView Revision, Dataset or VisStructureContext.
*/
typedef struct VIS_basedoc_output_s
{
       tag_t     base_doc;                             /**< The base document object. */
       tag_t     base_doc_item;                        /**< The Item  of the base document (if any). */
       tag_t     base_doc_itemrev;                     /**< The Item Revision  of the base document (if any).*/
       int       n_key_value;                          /**< The number of additional key/value pairs. */ 
       VIS_additional_keyvalue_p_t   additional_info;  /**< Array of length n_key_value that contains the additional key/value pairs. */
} VIS_basedoc_output_t, *VIS_basedoc_output_p_t;



#ifdef __cplusplus
    extern "C"{
#endif

/**
    Generates Metadata Stamp (MDS) file in the transient volume for the given object and returns the absolute path of the 
    MDS file.
    
    @returns
    <ul>
        <li>#ITK_ok on success
        <li>#TYPE_invalid_type_name if the object type is invalid
    </ul>
*/
extern VIS_API int USER_VIS_get_metadata_filename (
    tag_t                     object,           /**< (I)  Tag of object. */
    char**                    mds_file_path     /**< (OF) Absolute path of the MDS file in the transient volume. */
    );

    
/**
    Generates Metadata Stamp (MDS) file in the transient volume for the given object of type or sub-type of POM_object and its Context object.
    
    @returns
    <ul>
        <li>#ITK_ok on success.
        <li>#CXPOM_invalid_tag if @p object is #NULLTAG or invalid.
        <li>#POM_invalid_tag if @p object is not a type or subtype of POM_object.
        <li>Possibly other errors.
    </ul>
*/
extern VIS_API int USER_VIS_get_metadata_filename_context (
    tag_t                     object,           /**< (I)  The object. */
    tag_t                     context,          /**< (I)  Its Context object. It can be #NULLTAG. */
    char**                    mds_file_path     /**< (OF) Absolute path of the MDS file in the transient volume. */
    );


/**
    Resolves the base document of a given Teamcenter object, of runtime or persistent type, to be visualized in
    Teamcenter Visualization.
    
    @returns
    <ul>
        <li>#ITK_ok on success.
        <li>#CXPOM_invalid_tag if the object in @p vis_obj_struct is #NULLTAG or invalid.
        <li>Possibly other errors.
    </ul>

    @code
        VIS_object_input_t  vis_obj;
        VIS_basedoc_output_t*  basedocInfo;
        
        int ifail = USER_VIS_get_base_document ( &vis_obj, &basedocInfo );
        ...
        if ( ITK_ok == ifail && basedocInfo->additional_info != NULL )
        {
            for ( int x = 0; x < basedocInfo->n_key_value; x++ )
            {
                MEM_free( ((basedocInfo->additional_info)[x]).key );
                MEM_free( ((basedocInfo->additional_info)[x]).value );
            }
            MEM_free ( basedocInfo->additional_info );
            basedocInfo->additional_info = NULL;
        }
        MEM_free ( basedocInfo );
        basedocInfo = NULL;
    @endcode
*/
extern VIS_API int USER_VIS_get_base_document (
    const VIS_object_input_p_t    vis_obj_struct,     /**< (I)  The visualization structure.*/
    VIS_basedoc_output_p_t*       base_doc_struct     /**< (OF)  Its Base document structure. */
    );


/** @} */
#ifdef __cplusplus
}
#endif

#include <vis/libvis_undef.h>

#endif
