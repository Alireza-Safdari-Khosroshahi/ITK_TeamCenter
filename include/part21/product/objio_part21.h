/*================================================================================

                           Copyright 2013.
              Siemens Product Lifecycle Management Software Inc.
                        All Rights Reserved.
 ==============================================================================*/

/**
    @file

    This header file declares the PART21 itk functions (OBJIO_PART21).
*/

/*  */

#ifndef OBJIO_PART21_H
#define OBJIO_PART21_H

#include <objio/objio.h>
#include <step/objio_step_errors.h>

#include <part21/product/libpart21product_exports.h>

/**
    @defgroup OBJOI_PART21 Teamcenter/PART21 Translator Functions
    @ingroup OBJIO
    @{
*/


#ifdef __cplusplus
 extern "C"{
#endif


/**
    Imports data from the specified p21 files which contains manufacturing cutting tool data

    @returns
    <ul>
    <li>#ITK_ok on success.</li>
    <li>#OBJIO_STEP_os_file_error, if the system cannot open log file.</li>
    <li>#OBJIO_STEP_log_file_not_initialized, if the log file is not initialized.</li>
    <li>#OBJIO_STEP_file_write_error, if the log file can not be written.</li>
    <li>#OBJIO_STEP_invalid_schema, if step schema file is invalid.</li>
    </ul>

*/

extern PART21PRODUCT_API int OBJIO_PART21_import_files(
    const char *source_dir,        /**< (I) The directory that contains p21 files */
    const char  *filename,         /**< (I) The p21 file name */
    const char  *map_file,         /**< (I) The mapping file name - mapping between p21 attribute name to Teamcenter name*/
    const char  *assortment_file,  /**< (I) The assortment file name */
    const char *class_id,          /**< (I) The tool class ID to be imported */
    logical import_all,            /**< (I) Whether or not to import all p21 files indicated in the assortment file */
    logical dry_run                /**< (I) Whether or not to dry run */
    );


/** @} */

#ifdef __cplusplus
}
#endif

#include <part21/product/libpart21product_undef.h>

#endif
