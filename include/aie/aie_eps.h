/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*  */

#ifndef __EXPORT_PATH_SERVICE__
#define __EXPORT_PATH_SERVICE__

/**
    @defgroup AIE Application Integration Environment

    In order to hide the implementation of Export Path Service from other components,
    the following ITK interface is provided.
    All software must use the following API to find relative export path.

    <b>AIE_eps</b>

    This module is called Export Path Service, which comes under Application Integration Environment.
    The module comprises of all the generic interfaces that can be utilized for any third party integration.
    The following are public interfaces.

    @{
*/

/**
    This function outputs the absolute file spec after concatanation of connection directory name,
    relative file path and file name.
    If absolute file spec exceeds 240 chars the function will give error.
*/
extern int AIE_eps_ask_absolute_path(
    tag_t  connection_id,                               /**< (I) Tag of the connection */
    tag_t  file_tag,                                    /**< (I) Tag of the Teamcenter Engineering file */
    char*  file_name,                                   /**< (I) Name of the file as to be exported 
                                                                (Could be different from i-Man file name due to 
                                                                the use of renaming service) */
    char   file_spec[AIE_connection_filename_size_c+1]  /**< (O) Absolute file spec that includes connection export directory,
                                                                relative export path, and the name of the exported file. */
    );

/**
    This function outputs the directory path for writing the ixf_file_spec.
    If preference variable AIE_IXF_DIRECTORY is set to "YES",
    then this function concatenates the absolute file  with ".iman" to out put ixf_file_spec.
    If ixf_file_spec exceeds 240 chars the function will give error.
*/
extern int AIE_eps_ask_ixf_path(
    tag_t       connection_id,                                  /**< (I) Tag of connection _id */
    const char* absolute_file_spec,                             /**< (I) Absolute export path of file */
    char        ixf_file_spec[AIE_connection_filename_size_c+1] /**< (O) IXF export path of file */
    );

/** @} */

#endif
