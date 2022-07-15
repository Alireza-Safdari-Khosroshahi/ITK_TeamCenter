/*

@<COPYRIGHT_START>@
===============================================
Copyright 2018.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
===============================================
@<COPYRIGHT_END>@
*/


/**
    @defgroup MSARCHIVE TCXML Multisite Archive/Restore

    @file
    Declaration of the Multi-Site Archive/Restore API
*/

#ifndef MS_AR_ITK_H
#define MS_AR_ITK_H

#include <msarchive/libmsarchive_exports.h>

#ifdef __cplusplus
extern "C"{
#endif

/**
    TCXML_AR_failue_info_s contains error information for the archive or restore operation
*/
typedef struct TCXML_AR_failue_info_s{
    tag_t principal_object;     /**< Principal failing object. 0 if the entire operation failed */
    int n_errors;               /**< Number of errors and error_strings */
    int* errors;                /**< List of error codes */
    char** error_strings;       /**< List of error strings */
}TCXML_AR_failue_info_t;

/**
    Invokes TCXML Multi-Site archive process. Archive is governed by the optionset,
    if user does not provide any optionset then the default "TcArchiveRestoreDefaultTOS" optionset is used.
    Using the default optionset is recommended.

    TCXML_AR_failue_info_s is used to report back the details of failures.

    The possible values for @p sessionOptionNames are:
    <table>
    <tr><td>useBackground</td><td>Start archive in the background.</td></tr>
    <tr><td>dryrun</td><td>Simulate archive operation. Use with genReport.</td></tr>
    <tr><td>includeBOM</td><td>Includes assembly components of the BOM to all levels for processing.</td></tr>
    <tr><td>genReport</td><td>Request archive report.</td></tr>
    </table>
    The @p sessionOptionVals are either True or False.

    <b>Scenario(s):</b>
    <ol>
      <li> Archive - The object(s) are exported to archive site and then removed. </li>
      <li> Archive with exclusions - The object(s) are exported to archive site and then removed. However underlying objects in
                                     the exclude list will not be archived </li>
     </ol>

   @returns
   <ul>
    <li> ITK_ok on success
    <li> #OBJIO_no_archive_site if Multisite is not enabled.
    <li> #OBJIO_object_in_recovery_state if an object is in recovery state.
    <li> #OBJIO_object_already_exists if a duplicate object exist at archive site.
    <li> #OBJIO_connection_failure if connection to ODS serrver is failed.
    <li> #OBJIO_delete_replica_failure if failure occurs during replica deletion
   </ul>
*/

extern MSARCHIVE_API int TCXML_AR_archive (
    const char*                 optionSetName,      /**< (I) Name of the optionset. Specify NULL to use the default. */
    const int                   n_archive,          /**< (I) Number of archiveObjs to be archived. */
    const tag_t*                archiveObjs,        /**< (I) List of objects to be archived. */
    const int                   n_exclude,          /**< (I) Number of excludeObjs to be excluded from archving. */
    const tag_t*                excludeObjs,        /**< (I) List of objects excluded from archiving. */
    const int                   n_options,          /**< (I) Number of optionNames and optionVals. */
    const char**                optionNames,        /**< (I) List of option names. */
    const char**                optionVals,         /**< (I) List of values for the coresponding option names. */
    const int                   n_sessionOptions,   /**< (I) Number of sessionOptionNames and sessionOptionValues. */
    const char**                sessionOptionNames, /**< (I) List of session option names. */
    const char**                sessionOptionVals,  /**< (I) List of values for the corrsponding session option names. */
    char**                      reportFileFullPath, /**< (OF) Full path to the report file. */
    int*                        n_failures,         /**< (O) Number of failures returned. */
    TCXML_AR_failue_info_t***   failures            /**< (OF) List of TCXML_AR_failue_info_t structures. */
);

/**
    Invokes TCXML Multi-Site restore process. Resore is governed by the optionset,
    if user does not provide any optionset then the default "TcArchiveRestoreDefaultTOS" optionset is used.
    Using the default optionset is recommended.

    TCXML_AR_failue_info_s is used to report back the details of failures.

    The possible values for @p sessionOptionNames are:
    <table>
    <tr><td>useBackground</td><td>Start restore in the background.</td></tr>
    <tr><td>dryrun</td><td>Simulate restore operation. Use with genReport.</td></tr>
    <tr><td>includeBOM</td><td>Includes assembly components of the BOM to all levels for processing.</td></tr>
    <tr><td>genReport</td><td>Request archive report.</td></tr>
    </table>
    The @p sessionOptionVals are either True or False.

    <b>Scenario(s):</b>
    <ol>
       <li> Restore from archive site via search -
       This ITK only accepts an input list of PublishedObject business objects.
       QRY_execute_at_site run against the archive ODS will return a list of PublishedObject objects.
       That list can than be restored from the archive site with this ITK. </li>
     </ol>

   @returns
   <ul>
    <li> ITK_ok on success
    <li> #OBJIO_no_archive_site if Multisite is not enabled.
    <li> #OBJIO_object_in_recovery_state if an object is in recovery state.
    <li> #OBJIO_no_archived_objects_found if the criteria evaluates to no archived instances.
    <li> #OBJIO_connection_failure if connection to ODS serrver is failed.
   </ul>
******************************************************************************/

extern MSARCHIVE_API int TCXML_AR_restore (
    const char*                 optionSetName,      /**< (I) Name of the optionset. Specify NULL to use the default. */
    const int                   n_restore,          /**< (I) Number of restoreObjs to be restored. */
    const tag_t*                restoreObjs,        /**< (I) List PublishedObject business objects to be restored. */
    const int                   n_options,          /**< (I) Number of optionNames and optionVals. */
    const char**                optionNames,        /**< (I) List of option names. */
    const char**                optionVals,         /**< (I) List of values for the coresponding option names. */
    const int                   n_sessionOptions,   /**< (I) Number of sessionOptionNames and sessionOptionValues. */
    const char**                sessionOptionNames, /**< (I) List of session option names. */
    const char**                sessionOptionVals,  /**< (I) List of values for the corrsponding session option names. */
    char**                      reportFileFullPath, /**< (OF) Full path to the report file. */
    int*                        n_failures,         /**< (O) Number of failures returned. */
    TCXML_AR_failue_info_t***   failures            /**< (OF) List of TCXML_AR_failue_info_t structures. */
);


#ifdef __cplusplus
}
#endif

#include <msarchive/libmsarchive_undef.h>
#endif
