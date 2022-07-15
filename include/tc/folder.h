/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This header file declares data types and constants to be used by clients
    of the folder land module of Teamcenter Engineering
*/

/*  */

#ifndef FOLDER_H
#define FOLDER_H

#include <tc/folder_errors.h>
#include <tc/tc_startup.h>
#include <tccore/workspaceobject.h>

#include <tc/libtc_exports.h>

/**
    @defgroup FL Folder Manager

    The Folder Manager (FL) functions allow you to organize your Teamcenter Engineering data
    using a familiar folder metaphor.

    The first argument of the functions in this interface is usually
    the tag of the folder to be operated upon. Input arguments always precede output arguments.
    Therefore, in the case of create, the tag is the last argument.

    This module implements the methods of class Folder.
    The operations you can perform on a folder are:
    <ul>
    <li>Insert objects into a folder
    <li>Remove objects from a folder
    <li>Move objects in a folder (e.g., sort the objects) 
    </ul>

    A folder is accessible in memory after:
    <ol>
    <li>creating a new folder.
    <li>loading an existing folder.
    </ol>

    Folders are maintained in memory under all the supported sort criteria,
    it is therefore necessary for the client to specify the criteria.
    Ordering ascending/descending is not supported since all the client has
    to do is read the returned array backwards/forwards.

    <b>Restrictions:</b>
    
    All entries in a folder must be WorkspaceObjects.

    <b>Common Return Values</b>

    #CXPOM_invalid_tag - Invalid tag passed in.

    @{
*/

typedef enum FL_sort_criteria_e {
    FL_fsc_as_ordered,

    FL_fsc_by_name,
    FL_fsc_by_object,
    FL_fsc_by_type,
    FL_fsc_by_date_created,
    FL_fsc_by_date_modified,
    FL_fsc_by_date_released,

    FL_fsc_no_order,
    FL_fsc_bad

} FL_sort_criteria_t;

typedef enum FL_sort_order_e {

    FL_fso_ascending,
    FL_fso_descending,
    FL_fso_as_ordered,

    FL_fso_bad

} FL_sort_order_t;

#ifdef __cplusplus
    extern "C"{
#endif

/**
    Initializes the folder module. You must call this function before calling any other FL functions.

    This function is implicitly called when you call #ITK_init_module.
*/
extern TC_API int FL_init_module();

/**
    Cleans up and exits the Folder module. 
    This function should be called after all FL activity is complete.
    This function is implicitly called when you call #ITK_init_module.
*/
extern TC_API int FL_exit_module();


/**
    Creates a new folder with the specified name and description.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>Possibly some errors.
    </ul>
*/
extern TC_API int FL_create2(
    const char*     name,          /**< (I) The name of the folder. */
    const char*     description,   /**< (I) The description. */
    tag_t*          new_folder     /**< (O) The created folder. */
    );


/**
    Initializes a Folder object. 
    It is not saved to the database until an explicit call to #AOM_save occurs.
    You must specify a name and description.

    You normally use this function with a subclass of Folder.
    For example, if you defined a class special Folder, 
    you would first call #POM_create_instance to create the object in memory.
    Then you would use this function to initialize the attributes which were inherited from Folder.
    Finally, you would use additional POM calls to initialize the attributes comprising your specialization of Folder.
*/
extern TC_API int FL_initialize2(
    tag_t           folder_tag,                         /**< (I) */
    const char      *name,                              /**< (I) */
    const char      *description                        /**< (I) */
    );

/**
    Allocates an array of tags and stores in the array all folders in the database.
    The client is responsible for deallocating the array of folder_tags.
    Use #MEM_free to free the memory pointed to by folder_tags.

    <b>Restrictions:</b>

    To examine or manipulate the attributes of a folder with the tag returned from this function,
    you must have the proper access rights to the folder.
*/
extern TC_API int FL_extent(
    int*            num_of_folders,     /**< (O) Stores the size of the array */
    tag_t**         ppfolder_tags       /**< (OF) num_of_folders Points to the array of tags */
    );

/**
    The following functions manipulate the attributes of a folder in memory.
    Inserts an object reference into a folder at a specified index position. 
    The third argument "position" is zero based index, and that the input
    is larger than the number of objects in the folder, or using 999 to
    indicate the last position.
*/
extern TC_API int FL_insert(
    tag_t           folder_tag,             /**< (I) Folder where the object will be inserted */
    tag_t           workspaceobject_tag,    /**< (I) the object to be inserted */
    int             position                /**< (I) */
    );

/**
    Inserts more than one object reference into a folder at a specified index position.
    This function should be used when adding multiple object references at one time.

    @note If the index is less than 1, then reference is added at the top. 
    If the index is greater than the current number of references, the reference is appended to the list.
*/
extern TC_API int FL_insert_instances(
    tag_t           folder_tag,             /**< (I) Folder where object reference will be placed */
    int             nInstances,             /**< (I) Number of object references to be inserted */
    tag_t*          workspaceobject_tags,   /**< (I) nInstances Object references */
    int             position                /**< (I) */
    );

/**
    Removes a reference (specified by workspaceobject_tag) from a folder (specified by folder_tag).
*/
extern TC_API int FL_remove(
    tag_t           folder_tag,             /**< (I) */
    tag_t           workspaceobject_tag     /**< (I) */
    );

/**
    Moves a block of references from one position to another in the folder.
    Indexes are relative to zero (0).
    The range old_start_index to old_end_index is inclusive.
    The range is always inserted above the new_start_index (position in table).
    All indexes are relative to the original array.
    You can visualize the references and indexes as a two dimensional table consisting of
    values that reference objects and indexes that point to one of the values. 
    Your original table might look like the following:

    <table>
    <tr><td>Value</td><td>Index</td></tr>
    <tr><td>a    </td><td>0    </td></tr>
    <tr><td>b    </td><td>1    </td></tr>
    <tr><td>c    </td><td>2    </td></tr>
    <tr><td>d    </td><td>3    </td></tr>
    <tr><td>e    </td><td>4    </td></tr>
    <tr><td>f    </td><td>5    </td></tr>
    </table>

    If you consider the ordered triplet of integers, (old_start_index, old_end_index, new_start_index),
    and pass the following values as arguments (2,4,1),
    then you would be specifying the range of index numbers 2, 3, 4 and a starting index of 1.
    This means you would move the reference values c, d, and e above the value b.
    Your resultant table would look like the following:

    <table>
    <tr><td>Value</td><td>Index</td></tr>
    <tr><td>a    </td><td>0    </td></tr>
    <tr><td>c    </td><td>1    </td></tr>
    <tr><td>d    </td><td>2    </td></tr>
    <tr><td>e    </td><td>3    </td></tr>
    <tr><td>b    </td><td>4    </td></tr>
    <tr><td>f    </td><td>5    </td></tr>
    </table>
*/
extern TC_API int FL_move(
    tag_t           folder_tag,         /**< (I) */
    int             old_start_index,    /**< (I) */
    int             old_end_index,      /**< (I) */
    int             new_start_index     /**< (I) */
    );


/**
    Saves a copy of an existing folder to a new name as specified.
*/
extern TC_API int FL_copy2(
    tag_t           folder_tag,                             /**< (I) */
    const char      *new_folder_name,                       /**< (I) */
    tag_t*          new_folder_tag                          /**< (O) */
    );

/**
    Returns a list containing all the references in the folder by the given sort criteria.
    The client passes in an address to a pointer.
    This pointer is then assigned an allocated piece of memory that should subsequently be freed by calling #MEM_free. 
    Folders are maintained in memory under all the supported sort criteria. 
    It is therefore necessary for the client to specify the criteria.
*/
extern TC_API int FL_ask_references(
    tag_t               folder_tag,             /**< (I) */
    FL_sort_criteria_t  sort_criteria,          /**< (I) */
    int*                num_of_references,      /**< (O) */
    tag_t**             list_of_references      /**< (OF) num_of_references */
    );

/**
    Returns the index of a reference based on the sort criteria.
*/
extern TC_API int FL_ask_index(
    tag_t               folder_tag,             /**< (I) */
    tag_t               workspaceobject_tag,    /**< (I) */
    FL_sort_criteria_t  sort_criteria,          /**< (I) */
    int*                ref_index               /**< (O) */
    );

/**
    Sets the sort order attribute of the folder specified by folder_tag.
*/
extern TC_API int FL_set_sort_order(
    tag_t           folder_tag,     /**< (I) */
    FL_sort_order_t sort_order      /**< (I) */
    );

/**
    Gets the sort order attribute of the folder specified by folder_tag.
*/
extern TC_API int FL_ask_sort_order(
    tag_t               folder_tag,     /**< (I) */
    FL_sort_order_t*    sort_order      /**< (O) */
    );

/**
    Sets the sort criteria attribute of the folder specified by folder_tag.
*/
extern TC_API int FL_set_sort_criteria(
    tag_t               folder_tag,     /**< (I) */
    FL_sort_criteria_t  sort_criteria   /**< (I) */
    );

/**
    Gets the sort criteria attribute of the folder specified by folder_tag.
*/
extern TC_API int FL_ask_sort_criteria(
    tag_t               folder_tag,     /**< (I) */
    FL_sort_criteria_t* sort_criteria   /**< (O) */
    );

/**
    Returns the number of entries inside a folder.
*/
extern TC_API int FL_ask_size(
    tag_t           folder_tag,         /**< (I) */
    int*            number_of_entries   /**< (O) */
    );

/**
    This function inserts the specified workspaceobject_tag into the current user's Newstuff folder. 
*/
extern TC_API int FL_user_update_newstuff_folder (
    tag_t           folder_tag      /**< (I) */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <tc/libtc_undef.h>

#endif
