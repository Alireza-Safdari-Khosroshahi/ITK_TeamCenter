/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This file contains the function declarations which form the
    ITK layer for the DMI module.
*/

/*  */

#ifndef DMI_ITK_H_INCLUDED
#define DMI_ITK_H_INCLUDED
#include <tccore/workspaceobject.h>
#include <dmi/dmi_const.h>
#include <dmi/libdmi_exports.h>

/** @if DOX_IGNORE

#ifndef DMI_CONST_H_INCLUDED
#define DMI_file_name_size_c            32
#define DMI_path_name_size_c            255
#endif

@endif */

#ifdef __cplusplus
    extern "C"{
#endif

/**
    @defgroup DMI Document Management Interface (DMI)
    @{
*/

/**
    Stores an image file to a dataset.
*/
extern DMI_API int DMI_store_image_file2 (
    tag_t          image,                                      /**< (I) Tag of a dataset that is used for storing image file */
    const char     *image_file_name,                           /**< (I) Name of a file to be stored in dataset */
    const char     *path_name                                  /**< (I) Directory path where the image_file_name located */
    );


/**
    Retrieves an image file from a dataset.
*/
extern DMI_API int DMI_fetch_image_file2 (
    tag_t          image,                                   /**< (I) Tag of a dataset that is used for storing image file */
    const char     *dest_dir ,                              /**< (I) Directory where the image file will be fetched to */
    char           **image_name                             /**< (OF) Retrieved image file name */
    );



extern DMI_API int DMI_store_thumbnail_file2 (
    tag_t          image,                                         /**< (I) */
    const char     *thumbnail_file_name,                          /**< (I) */
    const char     *path_name                                     /**< (I) */
    );



extern DMI_API int DMI_fetch_thumbnail_file2 (
    tag_t          image,                                         /**< (I) */
    const char     *dest_dir,                                     /**< (I) */
    char           **thumbnail_name                               /**< (OF) */
    );

/**
    Asks markups datasets that are associated to an image.
*/
extern DMI_API int DMI_ask_image_markups (
    tag_t          image,           /**< (I) Tag of an image dataset */
    tag_t          markup_type,     /**< (I) Tag of the markup type. If #NULLTAG is entered,
                                            the default markup type "Markup" will be used. */
    int*           n_markups,       /**< (O) Number of markups found */
    tag_t**        markups          /**< (OF) n_markups Array of markup tags */
    );


/**
   Retrieves all image and markup files.
*/
extern DMI_API int DMI_fetch_image_markup_files2 (
    tag_t          image,                                /**< (I) Tag of an image dataset */
    const char     *dest_dir,                            /**< (I) Directory path where all files will be fetched to */
    int*           n_files,                              /**< (O) Number of fetched files */
    char**         image_file,                           /**< (OF) Name of image file */
    char***        markup_files                          /**< (OF) n_files Array of markup filenames */
    );


/**
    Merges all markup files that are associated with an image into a new markup dataset.
*/
extern DMI_API int DMI_merge_image_markup_files (
    tag_t          image,            /**< (I) Tag of an image dataset */
    tag_t          markup_type,      /**< (I) Tag of the markup dataset type. If #NULLTAG is entered,
                                            the default markup type "Markup" is used. */
    tag_t*         new_markup        /**< (O) Tag of the new markup dataset */
    );

/**
    Verifies that a given dataset has a named reference that can be used for view/markup.
*/
extern DMI_API int DMI_verify_image (
    tag_t          image,            /**< (I) Tag of a dataset */
    logical*       answer            /**< (O) If true, then the input dataset can be used for view/markup.
                                            If false, the input dataset cannot be used for view/markup. */
    );

/**
    Deletes an image dataset and its associated markup datasets.
*/
extern DMI_API int DMI_delete_image(
    tag_t          image         /**< (I) Tag of a dataset */
    );

/**
    Creates a markup dataset.
*/
extern DMI_API int DMI_create_markup2 (
    tag_t          image,                             /**< (I) Tag of an image dataset which a markup will be created */
    const char     *markup_name,                      /**< (I) Name of the markup dataset */
    const char     *markup_desc,                      /**< (I) Description of the markup dataset */
    const char     *markup_type,                      /**< (I) Dataset type name that will be used for creating markup.
                                                            If no type name is entered, 
                                                            the default markup type "Markup" will be used. */
    tag_t*         markup                             /**< (O) Tag of the created markup dataset */
    );

/**
    Deletes a markup dataset.
*/
extern DMI_API int DMI_delete_markup (
    tag_t          markup               /**< (I) Tag of a markup dataset to be deleted */
    );

/**
    Updates the markup dataset by replacing its associated image with a newly revised image dataset.
*/
extern DMI_API int DMI_update_markup (
    tag_t          markup               /**< (I) Tag of a markup dataset to be updated */
    );


/**
   Retrieves a markup file and its associated image file.
*/
extern DMI_API int DMI_fetch_markup_file2 (
    tag_t          markup,                              /**< (I) Tag of a markup dataset */
    const char     *dest_dir,                           /**< (I) Directory path where markup and image files should be fetched to */
    char**         image_file,                          /**< (OF) Name of the fetched image file */
    char**         markup_file                          /**< (OF) Name of the fetched markup file */
    );


/**
    Stores markup file into a markup dataset.
*/
extern DMI_API int DMI_store_markup_file2 (
    tag_t          markup,                                        /**< (I) Tag of a markup dataset */
    const char     *markup_file_name,                             /**< (I) Name of markup file */
    const char     *path_name                                     /**< (I) Directory path name where the markup file located */
    );

/**
    Creates a new revision of image dataset.
*/
extern DMI_API int DMI_revise_image2 (
    tag_t          image,                                          /**< (I) Tag of an image dataset */
    const char     *image_file_name ,                              /**< (I) Name of image file */
    const char     *path_name ,                                    /**< (I) Directory path where the image file is located */
    tag_t*         new_image_rev                                   /**< (O) Tag of the image dataset revision */
    );


extern DMI_API int DMI_revise_thumbnail2 (
    tag_t          image,                                          /**< (I) */
    const char     *thumbnail_file_name ,                          /**< (I) */
    const char     *path_name ,                                    /**< (I) */
    tag_t*         new_image_rev                                   /**< (O) */
    );


/**
    Creates a new revision of image dataset.
*/
extern DMI_API int DMI_revise_markup2 (
    tag_t          markup,                                         /**< (I) Tag of a markup dataset */
    const char     *markup_file_name ,                             /**< (I) Name of a markup file */
    const char     *path_name ,                                    /**< (I) Directory path where the markup file is located */
    tag_t*         new_markup_rev                                  /**< (O) Tag of the markup dataset revision */
    );

/**
    Deletes a named reference of an image dataset.
*/
extern DMI_API int DMI_delete_image_named_ref (
    tag_t          image           /**< (I) Tag of an image dataset */
    );

/**
    Deletes a named reference of a markup dataset.
*/
extern DMI_API int DMI_delete_markup_named_ref (
    tag_t          markup          /**< (I) Tag of a markup dataset */
    );

extern DMI_API int DMI_delete_thumbnail_named_ref (
    tag_t          image           /**< (I) */
    );

/**
    Asks for all defined markup types that can be used for marking up a given image type.
*/
extern DMI_API int DMI_ask_markup_types2 (
    const char     *image_type_name,                        /**< (I) Name of the dataset type */
    int*           markuptypes_count,                       /**< (O) Number of markup types */
    char***        markuptypes_names                        /**< (OF) markuptypes_count Arrays of markup type names */
    );


/**
    Asks for temporary markup type of a given markup type.
*/
extern DMI_API int DMI_ask_tempmarkup_type2 (
    const char     *markup_type_name,                            /**< (I) Name of a markup type */
    char**         tempmarkup_type_name                          /**< (OF) Name of a temporary markup type */
    );

/**
    Asks for mapping types count.
*/
extern DMI_API int DMI_ask_mapping_types_count (
    int*           count         /**< (O) Number of mapping types */
    );

extern DMI_API int DMI_ask_dataset_ref (
    tag_t          dataset,         /**< (I) */
    char**         named_ref        /**< (OF) */
    );

/**
    Initializes the DMI module. No DMI functions will work unless the module is initialized.
    The initialization must be called after the login into Teamcenter Engineering is established.
*/
extern DMI_API int DMI_init_module (void);

/** @} */

#ifdef __cplusplus
}
#endif

#include <dmi/libdmi_undef.h>
#endif
