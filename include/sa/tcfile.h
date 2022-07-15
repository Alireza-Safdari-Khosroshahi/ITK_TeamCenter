/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This file contains the C ITK functions for the TCFile class.
*/

/*  */

#ifndef TCFILE_H
#define TCFILE_H

#include <pom/pom/pom.h>
#include <ss/ss_const.h>
#include <ss/ss_types.h>
#include <sa/libsa_exports.h>

/**
    @defgroup IMF Teamcenter File
    @ingroup SA

    We use tags to refer to file objects.
    However, we use file descriptors when actually manipulating the file.
    A file descriptor is only valid between the time a file is created or
    the descriptor is asked for and the time that the file is closed.
    AOM functions work with Teamcenter Files because they are POM application objects.
    Include ss_const.h and tcfile.h to pass the correct SS_ constants to IMF routines.

    Teamcenter enforces a rule where operating system files are never modified;
    instead, new revisions of them are created.
    Teamcenter does not let you open an existing file for write.
    You must first make a copy, then open the copy for write.
    @{
*/

#define IMF_filename_size_c           132
#define IMF_relative_path_size_c      240
#define IMF_external_id_c             256

/**
    Obtains the File classification code for the given file from the corresponding Dataset.
    <br/>See tc_msg.h for details on messages and methods.

    @param tag_t   file_tag
    @param char*   file_classification_code
*/
#define IMF_dlp_classification_code_msg      "BMF_IMF_dlp_classification_code"

typedef void* IMF_file_t;
typedef  SS_file_status  IMF_file_status;



#ifdef __cplusplus
extern "C"{
#endif

/**
    Creates a new file object in the database. An operating system file is not created.
    It is the responsibility of the application to create the file using
    the path name returned from #IMF_ask_file_pathname2.
    The file can also be created with the correct parameters with #IMF_open_file.
    It returns both the tag and the file descriptor.
*/
extern SA_API int IMF_create_file(
    const char*   filename,         /**< (I)  Not NULL - the string is used as the name of the file
                                            (if that name does not already exist). <br>
                                            NULL - a unique file name is automatically generated. */
    int           file_type,        /**< (I) #SS_TEXT <br>
                                            #SS_BINARY <br>
                                            #SS_TRANSLATE | #SS_BINARY */
    tag_t*        file_tag,         /**< (O) */
    IMF_file_t*   file_descriptor   /**< (O) */
    );

/**
    Creates a new file in the operating system and a new file object in
    the database that is a copy of the original file.
    This function leaves the file opened for read/write and locked.
    It returns both the tag and the file descriptor.

    If new_filename is not NULL, then the string is used as the name of the file
    (if that name does not already exist).
    If new_filename is NULL, then a unique file name is automatically generated.
*/
extern SA_API int IMF_copy_file(
    tag_t         file_tag,         /**< (I) */
    const char*   new_filename,     /**< (I) */
    tag_t*        new_file_tag,     /**< (O) */
    IMF_file_t*   file_descriptor   /**< (O) */
    );

/**
    Pre-requisite: The Preference Fms_BootStrap_Urls should be pointing to the FSC
    process serving the TC Volume.
    This function is used to bring existing files under the control of Teamcenter.
    It creates a new file in the operating system and a new TcFile object in the database,
    where the new operating system file is a copy of the input OS file.
    The new file is closed and TcFile Object is locked for further modification. It returns
    both the tag and the file descriptor.
*/
extern SA_API int IMF_import_file(
    const char*   osFileName,       /**< (I) */
    const char*   newFilename,      /**< (I) Not NULL - the string is used as the name of the file
                                            (if that name does not already exist). <br>
                                            NULL - a unique file name is automatically generated. */
    int           fileType,         /**< (I) #SS_TEXT <br>
                                            #SS_BINARY <br>
                                            #SS_TRANSLATE | #SS_BINARY */
    tag_t*        newFileTag,       /**< (O) */
    IMF_file_t*   fileDescriptor    /**< (O) */
    );

/**
    Puts an TcFile into the operating system at the input pathname.
    The pathname can be relative to the current working directory.
*/
extern SA_API int IMF_export_file(
    tag_t         file_tag,     /**< (I) */
    const char*   pathname      /**< (I) */
    );

/**
    Returns the file descriptor for the database file object.
*/
extern SA_API int IMF_ask_file_descriptor(
    tag_t         file_tag,         /**< (I) */
    IMF_file_t*   file_descriptor   /**< (O) */
    );

/**
    Returns the tag of the database object for the given file descriptor.
*/
extern SA_API int IMF_ask_file_tag(
    IMF_file_t    file_descriptor,  /**< (I) */
    tag_t*        file_tag          /**< (O) */
    );


/**
   Retrieves the full pathname of the physical file on disk associated with the given TcFile.
   The format of the pathname will depend on the value of machine_type,
   it will be either #SS_WNT_MACHINE or #SS_UNIX_MACHINE.
*/
extern SA_API int IMF_ask_file_pathname2(
    tag_t         file_tag,                 /**< (I) */
    int           mach_type,                /**< (I) */
    char          **pathname                /**< (OF) */
    );

/**
    Opens the file for read or write.

    @note Teamcenter does not let you open an existing file for write.
    You must first make a copy, then open the copy for write.
*/
extern SA_API int IMF_open_file(
    IMF_file_t    file_descriptor,      /**< (I) */
    int           ss_file_access_mode   /**< (I) #SS_RDONLY, #SS_WRONLY, #SS_APPEND or #SS_RDWRITE */
    );

/**
    Closes a file.
*/
extern SA_API int IMF_close_file(
    IMF_file_t    file_descriptor   /**< (I) */
    );


/**
    Reads a line of text from an ASCII text file.
    The text up to and including the terminating newline character will
    be returned.  The initial call to this function will return the first
    line in the text file.  Each subsequent call will return the next line
    in the file.  SS_EOF will be returned on calls following the last line
    of valid data.
*/
extern SA_API int IMF_read_file_line2(
    IMF_file_t    file_descriptor,          /**< (I) */
    char          **text_line               /**< (OF) */
    );


/**
    Writes a line of text to an ASCII text file.
*/
extern SA_API int IMF_write_file_line2(
    IMF_file_t    file_descriptor,          /**< (I) */
    const char    *text_line                /**< (I) */
    );

/**
    Reads a block of data from a file where a block is the number of
    bytes specified by the datatype_count parameter.

    For data types SS_VOID, SS_CHAR, SS_WCHAR, and SS_BYTE this is the
    actual number of bytes specified by datatype_count.  For all other
    data types it is datatype_count times the sizeof() the data_type.

    The items_read parameter will return a pointer to the items retrieved.
    The items_read_count parameter will return the actual number of bytes
    read from the file.

    Can only be used if the file referenced by file_descriptor is a binary file.
    Determination of the file type (i.e., text vs binary) is based upon how the
    file was created (e.g., using IMF_create_file or IMF_fmsfile_import).
    An attempt to read a text file with this will result in a VM_NO_READ error.
*/
extern SA_API int IMF_read_file(
    IMF_file_t    file_descriptor,      /**< (I) The file descriptor for the database file object.*/
    int           datatype_count,       /**< (I) The number of bytes to read.*/
    int           data_type,            /**< (I) #SS_VOID, #SS_CHAR, #SS_WCHAR, #SS_BYTE, <br>
                                                #SS_SHORT, #SS_LONG, #SS_FLOAT, #SS_DOUBLE */
    int*          items_read_count,     /**< (O) The number of bytes read from the file.*/
    void*         items_read            /**< (O) A pointer to the items read from the file.*/
    );

/**
    Writes items to a file.
    If the actual number of items written is not datatype_count, then an error is returned.
*/
extern SA_API int IMF_write_file(
    IMF_file_t    file_descriptor,      /**< (I) */
    int           datatype_count,       /**< (I) */
    int           data_type,            /**< (I) */
    void*         items_to_write,       /**< (I) */
    int*          items_written_count   /**< (O) The actual number of bytes written to the file */
    );

/**
    Routine to expand a path.
    Any environment variables in the pathname are translated to their literal values.
*/
extern SA_API int IMF_expand_path(
    const char*   oldpath,      /**< (I) Path (with environment variables) you wish to expand */
    char*         newpath       /**< (O) Expanded path name of the file */
    );

/**
    Gets the status of a file.
    The status includes the owner id, group id, protection mode,
    file type (file or directory), creation date, date last modified,
    file format (text or binary), file size, and the full path name of the file.
*/
extern SA_API int IMF_stat(
    const char*         path,   /**< (I) Path of the file */
    IMF_file_status*    stats   /**< (O) Status of the file */
    );

/**
    Returns the current security level for a file system.

    0 Normal file management <br>
    1 Full security <br>
    2 Partially secure (allows ITK routines to read files directly).
*/
extern SA_API int IMF_ask_security_level( void );

/**
    Returns the volume tag for the database file object.
*/
extern SA_API int IMF_ask_volume(
    tag_t         fileTag,      /**< (I) */
    tag_t*        volumeTag     /**< (O) */
    );

/**
    Moves the file to the given volume.
*/
extern SA_API int IMF_move_file(
    tag_t         fileTag,      /**< (I) */
    tag_t         volumeTag     /**< (I) */
    );

/**
    This method replaces the existing volume file associated with @p file_tag
    with a new OS file located under @p new_file_pathname. The replacement will
    not alter the volume path and file UID of @p file_tag.

    If @p retain_orig_filename is set to true, it sets the original file name
    of a given TcFile to the original file name of file_tag. No new ImanFile
    UID is created in the database.

    This is intended for use with UG/Manager refile.  Otherwise, the function
    #IMF_replace_file_and_get_new_tag should be used.

*/
extern SA_API int IMF_replace_file(
    tag_t         file_tag,                 /**< (I) */
    const char*   new_file_pathname,        /**< (I) */
    logical       retain_orig_filename      /**< (I) */
    );

/**
    This method should be used in place of #IMF_replace_file.  This method imports
    an OS file located under @p new_file_pathname to @p new_file_tag. The volume and
    sd_path_location attributes of @p new_file_tag will be the same as that of
    @p old_file_tag. If @p retain_orig_filename is set to true, it sets the original
    file name of a given TcFile to the original file name of @p old_file_tag.

    If the old file tag represents a standalone ImanFile object then nothing
    further needs to be done. If it represents the ImanFile object that is
    associated with a dataset then the following calls need to be made:

    <ul>
    <li>AOM_lock(dataset);
    <li>AE_replace_dataset_named_ref2(dataset, file_tag, reference_name, reference_type, new_file_tag);
    <li>AE_save_myself(dataset);
    <li>AOM_unlock(dataset);
    </ul>

    @p old_file_tag needs to be locked before calling this function.
    Furthermore, @p old_file_tag can be deleted if it is not referenced anywhere.
*/
extern SA_API int IMF_replace_file_and_get_new_tag(
    tag_t         old_file_tag,             /**< (I) */
    const char*   new_file_pathname,        /**< (I) */
    logical       retain_orig_filename,     /**< (I) */
    tag_t*        new_file_tag              /**< (O) */
    );


/**
    Sets the original file name of a given TcFile.
    Teamcenter uses this original file name when exporting the file.

    <b>Restrictions:</b>
    The file name should not exceed 30 characters long if the
    preference TC_truncate_file_name is set. Otherwise the limit
    should be the CFI limit of 132 chars.
*/
extern SA_API int IMF_set_original_file_name2 (
    tag_t         file_tag,                         /**< (I) */
    const char    *name                             /**< (I) */
    );


/**
    Asks for the original name of a file.

    <b>Restrictions:</b>
    The file name should not exceed 30 characters long if the
    preference TC_truncate_file_name is set. Otherwise the limit
    should be the CFI limit of 132 chars.
*/
extern SA_API int IMF_ask_original_file_name2 (
    tag_t         file_tag,                         /**< (I) */
    char          **name                            /**< (OF) */
    );



/**
    Sets the relative path attribute of a given TcFile.
    Teamcenter uses this relative path when exporting the file
    using AIE (Application Integration Environment).

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>Possibly other error codes.
    </ul>

    <b>Restrictions:</b>
    The relative should not exceed #IMF_relative_path_size_c chars.
*/
extern SA_API int IMF_set_relative_path2 (
    tag_t         file,                                         /**< (I)  Volume file */
    const char    *relative_path                                /**< (I)  Relative path to AIE connection directory */
    );


/**
    Asks for the relative path attribute value of a file.
    Teamcenter uses this relative path when exporting the file
    using AIE (Application Integration Environment).

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>Possibly other error codes.
    </ul>
*/
extern SA_API int IMF_ask_relative_path2 (
    tag_t         file,                                         /**< (I)  Volume file */
    char          **relative_path                               /**< (OF) Relative path to AIE connection directory */
    );

/**
    Pre-requisite: The Preference Fms_BootStrap_Urls should be pointing to the FSC
    process serving the TC Volume.
    This function is used to bring existing files under the control of Teamcenter.
    It creates a new file in the operating system and a new TcFile object in the database,
    where the new operating system file is a copy of the input OS file. Further both
    new file and TcFile Object will be saved after successful import. It returns both the
    tag and the file descriptor.
*/
extern SA_API int IMF_fmsfile_import(
    const char*   osFileName,       /**< (I) */
    const char*   newFilename,      /**< (I) Not NULL - the string is used as the name of the file
                                            (if that name does not already exist). <br>
                                            NULL - a unique file name is automatically generated. */
    int           fileType,         /**< (I) #SS_TEXT <br>
                                            #SS_BINARY <br>
                                            #SS_TRANSLATE | #SS_BINARY */
    tag_t*        newFileTag,       /**< (O) */
    IMF_file_t*   fileDescriptor    /**< (O) */
    );


/**
   Exports a TcFile into the operating system at the input pathname.
   The pathname can be relative to the current working directory.

   @note The Preference "Fms_BootStrap_Urls" must be set and pointing
   to the File Server Cache (FSC) process serving the TC Volume.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PF_NOTFOUND if the preference "Fms_BootStrap_Urls" is not set.
    <li>Possibly other error codes.
    </ul>
*/
extern SA_API int IMF_fmsfile_export(
    tag_t         file,         /**< (I) Volume file */
    const char*   pathname      /**< (I) Absolute file path denoting export location */
    );


/**
    Obtains an FMS read ticket for a file in a transient volume.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#VM_INVALID_TVRD_PATH if the Transient Volume absolute file path is not found.
    <li>#VM_INVALID_SERVER_MODE if an invalid value was passed in the parameter @p server_mode.
    </ul>
*/
extern SA_API int IMF_get_transient_file_read_ticket(
    int file_type,                                /**< (I) Valid values are #SS_TEXT and #SS_BINARY. */
    int server_mode,                              /**< (I) 2 for a 2-tier ticket, 4 for a 4-tier ticket. */
    logical deleteSW,                             /**< (I) true to delete file from transient volume after reading it,
                                                         false to retain file in transient volume after reading it.*/
    const char* transient_volume_file_path,       /**< (I) The absolute path to the file in the transient volume
                                                         that is to be downloaded.*/
    char** transient_volume_file_read_ticket      /**< (OF) The FMS ticket generated from the above information.*/
    );

/**
    Obtains an FMS write ticket for a file in a transient volume.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#VM_INVALID_TVRD_PATH if the Transient Volume absolute file path is not found.
    <li>#VM_INVALID_SERVER_MODE if an invalid value was passed in the parameter @p server_mode.
    </ul>
*/
extern SA_API int IMF_get_transient_file_write_ticket(
    int file_type,                                /**< (I) Valid values are #SS_TEXT and #SS_BINARY. */
    int server_mode,                              /**< (I) 2 for a 2-tier ticket, 4 for a 4-tier ticket. */
    const char* transient_volume_file_path,       /**< (I) The absolute path to the file in the transient volume
                                                         that is to be downloaded. */
    char** transient_volume_file_write_ticket     /**< (OF) The FMS ticket generated from the above information. */
    );

/**
    This function obtains the Transient Volume Root Directory for the specified tier.
*/
extern SA_API int IMF_get_transient_volume_root_dir(
    int tier,                                     /**< (I) The tier type to be used when requesting the Transient Volume
                                                        Root Directory.  Must be 2 or 4. */
    char** transientVolRootDir                   /**< (OF) The Transient Volume Root Directory for the specified tier. */
    );

/**
    This function extracts the absolute path of the transient volume file from a ticket string.

    An error VM_INVALID_SERVER_MODE (14164) will be returned if the value of the tier argument is neither 2 nor 4.
    An error VM_INVALID_TRANSIENT_TICKET (14150) will be returned if the ticket_string argument is not a valid FMS transient file ticket.
    An error PF_NOTFOUND (1700) will be returned if the preference Transient_Volume_RootDir does not exist.
*/
extern SA_API int IMF_get_absolute_transient_volume_file_path(
    int tier,                                   /**< (I) The tier type to be used when requesting the Transient Volume
                                                        Root Directory.  Must be 2 or 4. */
    char*  ticket_string,                       /**< (I) The ticket string in its original form. */
    char** ticket_file_path                     /**< (OF) The extracted absolute file path of the transient volume file. */
    );

/**
    Obtains File Management System (FMS) read tickets for a set of supplied ImanFile objects.
    <br/>The supplied tickets are used to transfer files from a Teamcenter volume to local storage.
    <br/>The files input parameter contains a list of the ImanFile objects to be read from the
    Teamcenter volume and transferred to local storage.

    <br/>FMS requires tickets for all file transfers to and from Teamcenter volumes.
    An FMS read ticket is required to obtain a file from a Teamcenter volume,
    while an FMS write ticket is needed to place a file in the Teamcenter volume.
    <br/>It is often times more expedient to request several tickets at one time,
    especially if it is known ahead of time that many files will need to be moved.
    <br/>For this reason, the caller may supply multiple ImanFile objects,
    for which FMS tickets are desired, in the input vector.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#SS_NOMEM if available memory is insufficient to generate the file tickets(s).
    </ul>
*/
extern SA_API int IMF_get_read_file_tickets (
    int n_file_tags,                            /**< (I) The number of file_tags in the array pointed to by file_tags. */
    const tag_t* file_tags,                     /**< (I) A pointer to an array of file tags. */
    const char* application,                    /**< (I) A string denoting whether the tickets are to be used in a multisite environment.
                                                     <br/>If so, it should be set to a value of "Multisite".
                                                     <br/>Otherwise, the value is arbitrary.  It can be left blank, if desired. */
    int** ifails,                               /**< (OF) n_file_tags An array of integers containing ifail codes for the corresponding
                                                        element in each generated ticket in the ticket_infos array. */
    char*** ticket_infos                        /**< (OF) n_file_tags A character array containing each ticket generated in this request.
                                                        If a ticket request is in error the associated ifail will contain a value other
                                                        than ITK_ok. ITK_ok will be returned for all tickets that are correct.
                                                        The returned array is packed, and therefore only the container needs to be freed
                                                        using #MEM_free.*/
    );

/**
    Downloads a TcFile into the operating system at the input path name.

    @note The Preference "Fms_BootStrap_Urls" must be pointing to the FSC process
    serving the TC Volume.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PF_NOTFOUND if the preference "Fms_BootStrap_Urls" is not set.
    <li>#VM_INVALID_READ_TICKET if an invalid read ticket is supplied as input.
    <li>#BIER_fsc_proxy_error  if a connection cannot be established with FSC process for downloading a file.
    </ul>
*/
extern SA_API int IMF_download_file(
    const char*   read_ticket,  /**< (I) A URL encoded valid read file ticket. */
    const char*   pathname      /**< (I) Platform specific absolute file path denoting download location. */
    );

/**
    Obtains the File classification code for the given file from the corresponding Dataset.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>Possibly a BMF (Business Modeler Framework) error if there are any issues with the customization for this method.
    </ul>
*/
extern SA_API int IMF_dlp_classification_code(
    tag_t         file_tag,                     /**< (I) The file tag for which classification code is required */
    char*         file_classification_code      /**< (O) A single character that represents the classification code for the file. <br/>
                                                         The default value returned is a space ' '. <br/>
                                                         Customizations can choose to return any single character value other than space and NULL. */
    );

/**
    Sets the ID of the given file in the external system.

    @note Teamcenter uses this external ID when constructing FMS ticket.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>Possibly other error codes.
    </ul>
*/
extern SA_API int IMF_set_external_id (
    tag_t         file,                         /**< (I)  Volume file */
    const char    *external_id                  /**< (I)  External ID */
    );

/**
    Obtains the ID of the given file in the external system.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>Possibly other error codes.
    </ul>
*/
extern SA_API int IMF_ask_external_id (
    tag_t         file,                         /**< (I)  Volume file */
    char          **external_id                 /**< (OF) External ID */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <sa/libsa_undef.h>

#endif
