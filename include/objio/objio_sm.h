/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*  */

#ifndef OBJIO_SM_H
#define OBJIO_SM_H

#include <unidefs.h>

#include <objio/libobjio_exports.h>

/**
    @defgroup OBJIO_SM Storage Media
    @ingroup OBJIO
    @{
*/

/**
    @name Constants

    The following are manifest constants for storage size in bytes of various
    small strings that can be returned by this module.
    @{
*/
#define OBJIO_SM_class_name_c                   "StorageMedia"
#define OBJIO_SM_Disk_Device                    "Disk"
#define OBJIO_SM_Tape_Device                    "Tape"
#define OBJIO_SM_name_size_c                    32
#define OBJIO_SM_description_size_c             240
/** @} */

#define OBJIO_SM_online_msg                         "OBJIO_SM_online"
#define OBJIO_SM_retrieve_msg                     "OBJIO_SM_retrieve"
#define OBJIO_SM_store_msg                         "OBJIO_SM_store"

#ifdef __cplusplus
    extern "C"{
#endif


/**
    Creates a storage media object.
    It is not saved to the database until an explicit call to #AOM_save occurs.

    <b>Restrictions:</b>

    This function is only valid when you are logged in as the system administrator.
*/
extern OBJIO_API int OBJIO_SM_create_media2(
    char             *media_name,             /**< (I) */
    char             *logical_device,         /**< (I) */
    char             *media_type,             /**< (I) */
    tag_t*           media_tag                /**< (O) */
    );

/**
    Sets the attributes of the storage media object.

    <b>Restrictions:</b>

    This function is only valid when you are logged in as the system administrator.
*/
extern OBJIO_API int OBJIO_SM_set_media_name2(
    tag_t            media_tag,                         /**< (I) */
    char             *media_name                        /**< (I) */
    );

/**
    Sets the attributes of the storage media object.

    <b>Restrictions:</b>

    This function is only valid when you are logged in as the system administrator.
*/
extern OBJIO_API int OBJIO_SM_set_logical_device2(
    tag_t            media_tag,                                     /**< (I) */
    char             *logical_device                                /**< (I) */
    );

/**
    Sets the attributes of the storage media object.

    <b>Restrictions:</b>

    This function is only valid when you are logged in as the system administrator.
*/
extern OBJIO_API int OBJIO_SM_set_description2(
    tag_t            media_tag,                                 /**< (I) */
    char             *description                               /**< (I) */
    );

/**
    Sets the attributes of the storage media object.

    <b>Restrictions:</b>

    This function is only valid when you are logged in as the system administrator.
*/
extern OBJIO_API int OBJIO_SM_set_media_type2(
    tag_t            media_tag,                         /**< (I) */
    char             *media_type                        /**< (I) */
    );

/**
    Returns the attributes of the storage media object.
*/
extern OBJIO_API int OBJIO_SM_ask_media_name2(
    tag_t            media_tag,                         /**< (I) */
    char             **media_name                       /**< (OF) */
    );

/**
    Returns the attributes of the storage media object.
*/
extern OBJIO_API int OBJIO_SM_ask_logical_device2(
    tag_t            media_tag,                                     /**< (I) */
    char             **logical_device                               /**< (OF) */
    );

/**
    Returns the attributes of the storage media object.
*/
extern OBJIO_API int OBJIO_SM_ask_description2(
    tag_t            media_tag,                                 /**< (I) */
    char             **description                              /**< (OF) */
    );

/**
    Returns the attributes of the storage media object.
*/
extern OBJIO_API int OBJIO_SM_ask_media_type2(
    tag_t            media_tag,                         /**< (I) */
    char             **media_type                       /**< (OF) */
    );

/**
    Finds a storage media object with the specified device name.
    If no storage media exists with the specified device name,
    then a zero returns on the stack and a #NULLTAG returns for the media_tag.
*/
extern OBJIO_API int OBJIO_SM_find_media2(
    char             *media_name,                           /**< (I) */
    tag_t*           media_tag                              /**< (O) */
    );

/**
    Allocates an array of tags and stores in the array all media in the database.
    The client is responsible for deallocating the array of media_tags.
    Use #MEM_free to free the memory pointed to by media_tags.
*/
extern OBJIO_API int OBJIO_SM_media_extent(
    int*             media_count,   /**< (O) Stores the size of the array */
    tag_t**          media_tags     /**< (OF) media_count Points to the array of tags */
    );

/**
    Returns a logical value that is true if the storage media is online, and false if it is not.
*/
extern OBJIO_API int OBJIO_SM_ask_if_online(
    tag_t            media_tag,     /**< (I) */
    logical*         online         /**< (O) */
    );

/**
    Stores the specified file, identified by a filename and source directory,
    to a storage media specified by a media_tag.
*/
extern OBJIO_API int OBJIO_SM_store2(
    tag_t            media_tag,                         /**< (I) */
    char             *filename,                         /**< (I) */
    char             *source_dir                        /**< (I) */
    );


/**

*/
extern OBJIO_API int OBJIO_SM_retrieve2(
    tag_t            media_tag,                                 /**< (I) */
    char             *filename,                                 /**< (I) */
    char             *destination_dir                           /**< (I) */
    );


extern OBJIO_API int OBJIO_SM_store_files(
    tag_t            media_tag, /**< (I) */
    int              count,     /**< (I) */
    tag_t*           tags_list  /**< (I) */
    );


/**
    Retrieves a file, specified by a filename, from a storage media, 
    specified by a media_tag, into a specified destination directory. 
*/

extern OBJIO_API int OBJIO_SM_retrieve_file(
    tag_t            media_tag, /**< (I) */
    tag_t            file_tag   /**< (I) */
    );

/**
   Checks if the file exists.
   
   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#CXPOM_invalid_tag if @p media does not represent a StorageMedia object.
   <li>Possibly other errors.
   </ul>
*/
extern OBJIO_API int OBJIO_SM_exists2(
    tag_t            media,                /**< (I) */
    char             *filename,            /**< (I) */
    int*             doesnt_exist_flag     /**< (O) @c 1 if the file <b>does not</b> exist, @c 0 otherwise. */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <objio/libobjio_undef.h>

#endif
