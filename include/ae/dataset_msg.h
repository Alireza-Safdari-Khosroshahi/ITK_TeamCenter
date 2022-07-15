/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Dataset specific message definitions
*/

/*  */

#ifndef DATASET_MSG_H
#define DATASET_MSG_H

#include <ae/libae_exports.h>

/**
    @defgroup DATASET_MSG Dataset Messages
    @ingroup DATASET
    @{
*/

/**
    Creates a new Dataset instance

    @param[in] tag_t       datasetTypeTag       The Dataset Type
    @param[in] const char* datasetName          The Dataset name
    @param[in] const char* datasetDescription   The Dataset description, can be empty
    @param[in] const char* datasetID            The Dataset ID, can be empty
    @param[in] const char* datasetRevision      The Dataset revision, can be empty
    @param[out] tag_t       newDataset          The new Dataset

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#METAFRAMEWORK_businessObj_creation_fail if creation failed
    </ul>
*/
#define AE_create_dataset_msg   "AE_create_dataset"

/**
   Saves a Dataset instance

   @param[in] tag_t datasetTag  The Dataset instance to be saved
   @param[in] logical isNew     The flag of the Dataset instance is newly created.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#AE_cannot_save_dataset if save failed
   </ul>
*/
#define AE_save_dataset_msg     "AE_save_dataset"

/**
   Saves a Dataset instance without increasing the dataset version

   @param[in] tag_t datasetTag   The Dataset instance to be saved
   @param logical isNew          The flag of the Dataset instance is newly created.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#AE_cannot_save_dataset if save failed
   </ul>

*/
#define AE_save_myself_dataset_msg     "AE_save_myself_dataset"

/**
   Deletes a Dataset instance

   @param[in] tag_t datasetTag The Dataset instance to be deleted

   @returns
   <ul>
   <li>#ITK_ok on success    <li>#AE_cannot_delete_dataset if deletion failed
   </ul>
*/
#define AE_delete_dataset_msg   "AE_delete_dataset"

/**
   Downloads a file reference of an existing Dataset instance to specified file path.

   @note When the export operation is performed using a SOA client e.g. Rich Client , 
   the extension attached to the 'AE_export_file' will not be invoked. 
   However it will be invoked when using #AE_export_named_ref itk.

   @param[in] tag_t datasetTag        The Dataset instance
   @param[in] char* referenceName     The Dataset reference name 
   @param[in] char* destinationName   The file name of the reference

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#VM_NO_COPY if doenload failed
   </ul>
*/
#define AE_export_file_msg      "AE_export_file"

/**
   Imports a os file as a named reference to an existing Dataset instance.

   @note When a file is imported by calling the ITK API AE_import_named_ref the variable
   'osFullPathName' will contain the fully qualified path. When the file is imported from 
   the user interface (e.g., the Rich Admin Client) the variable 'osFullPathName' will 
   contain only the OS filename.
   
   @param[in] tag_t               datasetTag        The Dataset instance
   @param[in] char*               referenceName     The Dataset reference name
   @param[in] AE_reference_type_t referenceType     The Dataset reference type
   @param[in] char*               osFullPathName    The os full path to down load the file
   @param[in] char*               fileName          The file name
   @param[in] int                 fileTypeFlag      The ImanFile

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#BIER_fsc_proxy_error if import failed
   </ul>
*/
#define AE_import_file_msg      "AE_import_file"

/** @} */

#include <ae/libae_undef.h>
#endif
