/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This header file declares the STEP itk functions (OBJIO_STEP).
*/

/*  */

#ifndef OBJIO_STEP_H
#define OBJIO_STEP_H

#include <objio/objio.h>
#include <step/objio_step_errors.h>
#include <pom/pom/pom.h>
#include <step/libstep_exports.h>

/**
    @defgroup OBJOI_STEP Teamcenter/STEP Translator Functions
    @ingroup OBJIO
    @{
*/

#define STEP_file_size 100

typedef enum OBJIO_df_e {
    OBJIO_STEP_AP203,
    OBJIO_STEP_AP214,
    OBJIO_STEP_IMAN
} OBJIO_df_t;

#ifdef __cplusplus
 extern "C"{
#endif

/**
    Creates a new STEP manager object.
*/
extern STEP_API int OBJIO_STEP_create(
    int             operation_type,     /**< (I) Either #OBJIO_export_type or #OBJIO_import_type */
    const char*     path_name,          /**< (I) Complete directory path 
                                            (to write to for #OBJIO_export_type and to read from for #OBJIO_import_type) */
    tag_t*          manager_tag         /**< (O) Returned tag of the newly created manager object */
    );

/**
    Deletes an existing STEP manager object.
*/
extern STEP_API int OBJIO_STEP_delete(
    tag_t           manager_tag     /**< (I) Tag of an existing STEP manager object */
    );

/**
    Sets the STEP data format for exported data.
*/
extern STEP_API int OBJIO_STEP_set_data_format(
    tag_t           manager_tag,    /**< (I) Tag of an existing STEP manager object */
    OBJIO_df_t      data_format     /**< (I) Enumeration identifying the output data format.
                                            Allowable values are: <br>
                                            #OBJIO_STEP_AP203 <br>
                                            #OBJIO_STEP_AP214 <br>
                                            #OBJIO_STEP_IMAN */
    );

/**
    Sets whether to export only the top-level or whole assembly.
*/
extern STEP_API int OBJIO_STEP_set_full_assembly(
    tag_t           manager_tag,    /**< (I) Tag of an existing STEP manager object */
    logical         full_assy       /**< (I) TRUE = export entire assembly with all sub-parts/assemblies. <br>
                                             FALSE = export only the top-level of the assembly. */
    );

/**
    Sets whether to export all versions of a dataset.
*/
extern STEP_API int OBJIO_STEP_set_dataset_all_vers(
    tag_t           manager_tag,    /**< (I) Tag of an existing STEP manager object */
    logical         ds_all_vers     /**< (I) TRUE = export all dataset versions. <br>
                                               FALSE = export only dataset version-0. */
    );

/**
    Sets STEP data exchange comments.
*/
extern STEP_API int OBJIO_STEP_set_comments(
    tag_t           manager_tag,    /**< (I) Tag of an existing STEP manager object */
    const char*     comments        /**< (I) Comments placed into the STEP Part 21 file FILE_DESCRIPTION section */
    );

extern STEP_API int OBJIO_STEP_set_log_file_path(
    tag_t           manager_tag,    /**< (I) */
    const char*     log_file_path   /**< (I) */
    );

extern STEP_API int OBJIO_STEP_get_log_file_path(
    tag_t           manager_tag,    /**< (I) */
    char**          log_file_path   /**< (O) */
    );

extern int OBJIO_STEP_set_geo_config_file(
    tag_t       manager_tag,        /**< (I) */
    const char* geo_confg_file      /**< (I) */
    );

/**
    Exports specified objects to the specified location in the specified format.
*/
extern STEP_API int OBJIO_STEP_export(
    tag_t           manager_tag,    /**< (I) Tag of an existing STEP manager object */
    const char*     filename,       /**< (I) Name of the output file (10303-21 format) with .stp extension */
    int             n_objects,      /**< (I) Number of exported objects */
    tag_t*          object_tags     /**< (I) Tags of exported objects. In the case of datasets, 
                                            we will supply an ImanRelation tag to help uniquely identify the dataset. */
    );

/**
    Imports data from the specified part-21 file.
*/
extern STEP_API int OBJIO_STEP_import(
    tag_t           manager_tag,            /**< (I) Tag of an existing STEP manager object */
    const char*     filename,               /**< (I) Name of the input file (10303-21 format) */
    int*            n_new_objects,          /**< (O) Number of new WorkspaceObjects created */
    tag_t**         new_object_tags,        /**< (OF) n_new_objects Tags of newly created WorkspaceObjects */
    int*            n_modified_objects,     /**< (O) Number of WorkspaceObjects modified */
    tag_t**         modified_object_tags    /**< (OF) n_modified_objects Tags of WorkspaceObjects modified */
    );

/**
    Sets the tags of excluded relation types and the number of excluded relation types during a STEP export.
*/
extern STEP_API int OBJIO_STEP_exclude_relation_types(    
    int             n_type_tags,    /**< (I) Number of excluded relation types */
    tag_t*          type_tags,      /**< (I) Tags of excluded relation types */
    tag_t           manager_tag     /**< (I) Tag of an existing STEP manager object */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <step/libstep_undef.h>

#endif
