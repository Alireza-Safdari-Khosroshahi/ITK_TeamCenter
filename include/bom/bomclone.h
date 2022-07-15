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

    The file contains the ITK calls and supporting type definitions for Duplicate functionality.
*/

#ifndef BOMCLONE_H
#define BOMCLONE_H

#include <unidefs.h>
#include <bom/libbom_exports.h>

/**
    @defgroup BOM_DUPLICATE Duplicate
    @ingroup BOM

    Teamcenter has implemented BOM structure duplication functionality that
    allows users to make cloned copies of the BOM structures in their environment.

    Detailed information is supplied for the following aspects of Duplicate functions:
    <ul>
    <li>Define default Item ID naming patterns.
    <li>Validate new Item IDs for part cloning.
    <li>Identify what parts in a BOM structure will be cloned or referenced.
    <li>Flag if new cloned parts should be assigned to specified projects.
    <li>Flag if specified projects should be validated before assigning new cloned parts to specified projects.
    <li>Flag if specified CAD dependencies should be included with BOM structure duplication.
    </ul>

    @note Duplicate functionality only supports NX and IPEM/ProE CAD integrations.

    Teamcenter makes use of this mechanism itself,
    and it also provides ITK level functions for programmers to make use of the same Duplicate mechanism.

    @note Teamcenter may alter or obsolete Duplicate codes as the product evolves.
    These changes will be documented in the Release Notes.

    The ITK Duplicate functions include:
    <ul>
    <li>A function to perform a validation and clone on a BOM structure to be duplicated.
    <li>A function to search for CAD dependent information in a BOM structure to be duplicated.
    </ul>

    To use these functions, include bomclone.h.

    @{
*/

/**
    @{
    CAD Dependency option values used by BOM duplicate API's.
    This options map to closure rules defined on BMIDE Global Constant "StructureCloneTransferModes".
    @note Duplicate requires the CAD integrations to install the closure rules for CAD Dependency searches in Teamcenter.
*/
#define BOM_DUPLICATE_CAD_DRAWINGS          "Drawings"          /**< Instructs duplicate to search for CAD Drawing Parts based on closure rules. */
#define BOM_DUPLICATE_CAD_REQUIRED          "Required"          /**< Instructs duplicate to search for CAD Required Parts based on closure rules. */
#define BOM_DUPLICATE_CAD_PARTFAMILYMASTER  "PartFamilyMaster"  /**< Instructs duplicate to search for CAD Family Master Parts based on closure rules. */
#define BOM_DUPLICATE_CAD_PARTFAMILYMEMBER  "PartFamilyMember"  /**< Instructs duplicate to search for CAD Family Member Parts based on closure rules. */
#define BOM_DUPLICATE_CAD_ALLDEP            "AllDep"            /**< Instructs duplicate to search for CAD Dependent Parts based on closure rules. */
#define BOM_DUPLICATE_CAD_INTERNAL          "Internal"          /**< Instructs CAD integration to search for CAD Parts that have CAD Internal Part links that are not published in Teamcenter. */
/** @} */

/**
    @{
    Defines the bitwise values used by BOM duplicate API's.
*/
#define BOM_DUPLICATE_SMART_SELECTION_FLAG            1    /**< Instructs duplicate to select components to be duplicated based on projects assigned to the top BOMLine being duplicated. */
#define BOM_DUPLICATE_RENAME_DATASETS_FLAG            2    /**< Instructs CAD integrations to rename there datasets, only used by ProE integration at this time. */
#define BOM_DUPLICATE_RETURN_CLONED_OBJECTS_FLAG      4    /**< Instructs duplicate to return the duplicated Item Revisions after duplication completes. */
#define BOM_DUPLICATE_BACKGROUND_FLAG                 8    /**< Instructs duplicate to run in background, not supported by the duplicate ITK API's. */
#define BOM_DUPLICATE_VALIDATE_ONLY_FLAG              16   /**< Instructs duplicate to only validate the structure, do not duplicate it. */
#define BOM_DUPLICATE_IGNORE_UNCONFIGURED_FLAG        32   /**< Instructs duplicate to ignore unconfigured occurrences. */
#define BOM_DUPLICATE_REFERENCE_AS_DEFAULT_FLAG       64   /**< Instructs duplicate to create reference if operation is not specified . */
#define BOM_DUPLICATE_PMA0_PROCESSING_CARRYOVER_FLAG  128  /**< Instructs duplicate not to clear the error store and clone helper when duplicate operation is invoked via Product Master Automation.*/
/** @} */

/**
    @{
    Duplicate operation values used by BOM duplicate API's.

    @note The following are basic steps to follow if wanting to manually override Item ID and Item Revision ID.

    For Clone Operation manual override Item ID and Item Revision ID:
    <ul>
    <li>Get SaveAs AbsOccData "item_tag" for the component.
    <li>Get the operation input from the AbsOccData property.
    <li>Assign "item_id" property value to operational input.
    <li>Add property "item_revision_id" and value to #BOM_duplicate_prop_value_map_t parameter.
    </ul>

    For Revise Operation manual override Item Revision ID:
    <ul>
    <li>Add property "item_revision_id" and value to #BOM_duplicate_prop_value_map_t parameter.
    </ul>

    For Replace Operation you will need to indicate the Item ID and Item Revision ID of the replacing component:
    <ul>
    <li>Get SaveAs AbsOccData "item_tag" for the component.
    <li>Get the operation input from the AbsOccData property.
    <li>Assign "item_id" property value to operational input.
    <li>Add property "item_revision_id" and value to #BOM_duplicate_prop_value_map_t parameter.
    </ul>
*/
#define BOM_DUPLICATE_OPERATION_CLONE           0   /**< Instructs duplicate to Clone the component. */
#define BOM_DUPLICATE_OPERATION_REFERENCE       1   /**< Instructs duplicate to Reference the component */
#define BOM_DUPLICATE_OPERATION_REVISE          2   /**< Instructs duplicate to Revise the component */
#define BOM_DUPLICATE_OPERATION_REPLACE         3   /**< Instructs duplicate to Replace the component */
#define BOM_DUPLICATE_OPERATION_IGNORE          5   /**< Instructs duplicate to Ignore the component */
#define BOM_DUPLICATE_OPERATION_CLONE_BELOW     6   /**< Instructs duplicate to Clone the component and its children. */
/** @} */

/**
    The property value mapping of property names to there values.
    @note This property mapping is used by save-as, revise and replace operations, also used for MFK identification.
*/
typedef struct BOM_duplicate_prop_value_map_s
{
    char   *prop_name;     /**< Property name to be used by either save-as, revise or replace operations. */
    char   *prop_value;    /**< Property value to be used by either save-as, revise or replace operations. */
} BOM_duplicate_prop_value_map_t;


/**
    The duplicate data mapping that instructions duplicate what to do with the components of the BOM structure it is going to duplicate.
    @note If a component is not defined in the map at time of duplication the default action will be duplicate component.
*/
typedef struct BOM_duplicate_data_map_s
{
    tag_t                            orig_item_rev;     /**< The original Item Revision to process. */
    int                              operation_type;    /**< The operation type to execute on the original Item Revision. */
    int                              n_prop_value_map;  /**< Number of property value pairs in property map. */
    BOM_duplicate_prop_value_map_t  *prop_value_map;    /**< n_prop_value_map List of property value pairs (property_name, property_value) to be used for save-as, revise and replace operations, also used for MFK support. */
    int                              n_deep_copy_data;  /**< Number of relational data attached to the original Item Revision. */
    tag_t                           *deep_copy_data;    /**< n_deep_copy_data List of relational data attached to the original Item Revision for save-as and revise operations. */
} BOM_duplicate_data_map_t;


/**
    The duplicate data mapping that instructs duplicate what to do with the BOMLine components of the BOM structure it is going to duplicate.
    @note If a component is not defined in the map at time of duplication the default action will be reference the BOMLine component.
*/
typedef struct BOM_duplicate_bomline_data_map_s
{
    tag_t                       bomline;    /**< The original BOMLine to process. */
    BOM_duplicate_data_map_t    data_map;   /**< The instructions on how to process the BOMLine component during the duplicate process. */
} BOM_duplicate_bomline_data_map_t;

/**
    The default naming options for generating new Item IDs.
    @note If the parameter @p autogen is set to "true", all other fields are ignored.
*/
typedef struct BOM_duplicate_default_name_s
{
    logical   autogen;  /**< Flag to auto generate the new Item ID. */
    char      *prefix;  /**< If populated will need to apply the prefix to the old Item ID. */
    char      *suffix;  /**< If populated will need to apply the suffix to the old Item ID. */
    char      *from;    /**< Old string to be replaced by @p to. */
    char      *to;      /**< New string to replace @p from. */
} BOM_duplicate_default_name_t;


/**
    Contains the project information to be used by Duplicate operation.
    @note This tells Duplicate operation if it needs to validate and assign cloned Items to specified projects.
*/
typedef struct BOM_duplicate_project_info_s
{
    logical  assign;       /**< Flag that indicates if new duplicated objects need to be assigned to projects. */
    logical  validate;     /**< Flag that indicates if validation needs to be performed on projects. */
    int      projectsCnt;  /**< Number of specified projects to be used or validated. */
    tag_t*   projects;     /**< projectsCnt List of specified projects to be used or validated. */
} BOM_duplicate_project_info_t;


/**
    Contains the mapping of the original Item Revision to the duplicated Item Revision.
*/
typedef struct BOM_duplicate_cloned_map_s
{
    tag_t   orignalObject;   /**< The original Item Revision that was used by duplication. */
    tag_t   clonedObject;    /**< The duplicated Item Revision that was cloned by duplication */
} BOM_duplicate_cloned_map_t;


/**
    Contains the mapping of the top BOMLine, original Item Revision, duplicated Item Revision, status and error message of BOMLine being processed.
*/
typedef struct BOM_duplicate_status_map_s
{
    tag_t    orig_bomline;       /**< BOMLine of original Item Revision that duplicate will process. */
    tag_t    orig_item_rev;      /**< The original Item Revision that was processed by duplicate. */
    tag_t    cloned_item_rev;    /**< The new duplicated Item Revision that was cloned from the orignal Item Revision. */
    int      status;             /**< The process status of the BOMLine to be processed by duplicate. */
    char    *message;            /**< Not used, will just return an empty string, for future use. */
} BOM_duplicate_status_map_t;


/**
    Contains the error information that occurred during a Duplicate operation.
*/
typedef struct BOM_error_item_revision_s
{
    tag_t   error_item_rev;  /**< Item Revision that the error occurred on. */
    int     error_num;       /**< Error number that was generated while processing the Item Revision. */
    char   *error_msg;       /**< Error message that was generated while processing the Item Revision. */
} BOM_error_item_revision_t;


#ifdef __cplusplus
extern "C"
{
#endif

/**
    Validates and duplicates a BOM structure being passed in at @p top_bomlines.

    During validation of a BOM structure the API will check to see if the structure can be duplicated based on the Default Item ID patterns provided at @p default_name.
    @note If Item ID's and Item Revision ID's are manually added to @p data_map these will also be validated.
    @note If CAD Dependency options are provided at @p cad_options the validation process will also validate Item ID patterns against any CAD dependencies found.
    <br/>If autogen is set to "false" a map of old to new Item IDs will be returned at the @p out_data_map parameter.
    <br/>If autogen is set to "true" the value passed into @p data_map parameter will be returned at the @p out_data_map parameter.
    <br/>If autogen is set to "true" the system will not auto-assign Item IDs until the actual duplicate takes place.
    <br/>If validation failures occur they will be return at the @p error_irs parameter.

    This API was designed to only support NX and IPEM/ProE CAD integrations and basic BOM structure duplications.
    <br/>If duplicate failures occur they will be returned at the @p error_irs parameter and the Item Revisions failing to duplicate will still be referenced in the new duplicated BOM structure.

    The following are CAD Dependency options for @p cad_options.
    <ul>
    <li>#BOM_DUPLICATE_CAD_DRAWINGS
    <li>#BOM_DUPLICATE_CAD_REQUIRED
    <li>#BOM_DUPLICATE_CAD_PARTFAMILYMASTER
    <li>#BOM_DUPLICATE_CAD_PARTFAMILYMEMBER
    <li>#BOM_DUPLICATE_CAD_ALLDEP
    <li>#BOM_DUPLICATE_CAD_INTERNAL
    </ul>
    @note The listed  CAD Dependency options are COTS options but any custom CAD "Additional Dependencies" can be entered here as well. If the @p cad_options is invalid the API will continue and ignore the invalid value.

    The following are bitwise duplicate options for @p duplicate_flags.
    <ul>
    <li>#BOM_DUPLICATE_SMART_SELECTION_FLAG
    <li>#BOM_DUPLICATE_RENAME_DATASETS_FLAG
    <li>#BOM_DUPLICATE_RETURN_CLONED_OBJECTS_FLAG
    <li>#BOM_DUPLICATE_VALIDATE_ONLY_FLAG
    <li>#BOM_DUPLICATE_IGNORE_UNCONFIGURED_FLAG
    <li>#BOM_DUPLICATE_REFERENCE_AS_DEFAULT_FLAG
    </ul>

    @note If @p data_map is null the API will assume all components of BOM structure and any CAD Dependencies will be duplicated. The naming of duplicated components will still be determined by @p default_name.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#PROJECT_fail_to_find_project if the specified project does not exist or fails validation.
    <li>#PROJECT_user_is_not_privileged if the current user does not have privileges to use the specified project.
    <li>#BOM_invalid_tag if the @p top_bomlines is invalid, make sure valid BOMLine tags are being passed in.
    <li>#BOM_no_item_rev if the Item Revision for @p top_bomlines are not valid, make sure a valid Item Revision is associated with the @p top_bomlines tags being passed in.
    </ul>

    @note All other partial errors will be return in @p error_irs and this API will return #ITK_ok. The overall status of the @p top_bomlines will be returned in @p bomline_status_map.
*/
extern BOM_API int BOM_clone_structure(
    int                                 n_top_bomlines,        /**< (I) Number of top level BOMLines to duplicate. */
    const tag_t*                        top_bomlines,          /**< (I) n_top_bomlines List of top level BOMLines to duplicate. */
    int                                 n_cad_options,         /**< (I) Number of cad dependency options selected for processing during duplicate. */
    const char**                        cad_options,           /**< (I) n_cad_options List of cad dependency options selected for processing during duplication. */
    int                                 n_data_map,            /**< (I) Number of entries in data_map with instructions on how to duplicate components of structure. */
    const BOM_duplicate_data_map_t*     data_map,              /**< (I) n_data_map List of components with instructions on how to be processed, components not in the data map will be duplicated by default using default_name. */
    const BOM_duplicate_default_name_t* default_name,          /**< (I) Default name patterns to use during clone, autogen, prefix, postfix and replace with from to strings. */
    const BOM_duplicate_project_info_t* projects,              /**< (I) User selected projects to validate and assign duplicated objects to, null is allowed. */
    tag_t                               default_folder,        /**< (I) Folder to add the cloned root line Item Revision into, NULLTAG allowed. */
    int                                 duplicate_flags,       /**< (I) Bitwise integer flag to set selected duplicate options. */
    int*                                n_out_data_map,        /**< (O) Number of entries in out_data_map with instructions on how to duplicate components of structure. */
    BOM_duplicate_data_map_t**          out_data_map,          /**< (OF) n_out_data_map List of components that went through validation, only populated when validation fails or validate only duplicate option is turned on. */
    int*                                n_cloned_object_map,   /**< (O) Number of entries in cloned_object_map. */
    BOM_duplicate_cloned_map_t**        cloned_object_map,     /**< (OF) n_cloned_object_map List of original and cloned Item Revisions, only populated if duplicate option to return duplicated objects is turned on. */
    int*                                n_bomline_status_map,  /**< (O) Number of bomline statuses in bomline_status_map. */
    BOM_duplicate_status_map_t**        bomline_status_map,    /**< (OF) n_bomline_status_map List of top_bomline statuses, returns validate or duplicated status of BOMLines passed in, if duplicated it will also contain the duplicated Item Revision for BOMLines. */
    int*                                n_error_irs,           /**< (O) Number of partial errors on Item Revisions that failed to process. */
    BOM_error_item_revision_t**         error_irs              /**< (OF) n_error_irs List of partial errors on Item Revisions with error numbers and messages that failed to validate or duplicate. */
);


/**
Validates and duplicates a BOM structure being passed in at @p top_bomlines.

During validation of a BOM structure the API will check to see if the structure can be duplicated based on the Default Item ID patterns provided at @p default_name.
@note If Item ID's and Item Revision ID's are manually added to @p data_map these will also be validated.
<br/>If autogen is set to "false" a map of old to new Item IDs will be returned at the @p out_data_map parameter.
<br/>If autogen is set to "true" the value passed into @p data_map parameter will be returned at the @p out_data_map parameter.
<br/>If autogen is set to "true" the system will not auto-assign Item IDs until the actual duplicate takes place.
<br/>If validation failures occur they will be return at the @p error_irs parameter.

This API was designed to only support BOMLine structure duplications. The duplication process will create new data based on the Save As Operation and its Deep Copy Rules.

<br/>If duplicate failures occur they will be returned at the @p error_irs parameter and the Item Revisions failing to duplicate will still be referenced in the new duplicated BOM structure.

@note CAD Dependency options are temporarely not support by this API, they are part of the API signature so they can be used in the future.

The following are bitwise duplicate options for @p duplicate_flags.
<ul>
<li>#BOM_DUPLICATE_RETURN_CLONED_OBJECTS_FLAG
<li>#BOM_DUPLICATE_VALIDATE_ONLY_FLAG
<li>#BOM_DUPLICATE_IGNORE_UNCONFIGURED_FLAG
</ul>

@note If @p data_map is null the API will assume all components of BOM structure will be referenced.

@returns
<ul>
<li>#ITK_ok on success.
<li>#PROJECT_fail_to_find_project if the specified project does not exist or fails validation.
<li>#PROJECT_user_is_not_privileged if the current user does not have privileges to use the specified project.
<li>#BOM_invalid_tag if @p top_bomlines is invalid
<li>#BOM_no_item_rev if the Item Revision for @p top_bomlines is not valid
</ul>

@note All other partial errors will be return in @p error_irs and this API will return #ITK_ok. The overall status of the @p top_bomlines will be returned in @p bomline_status_map.
*/
extern BOM_API int BOM_clone_bomlines(
    const int                                 n_top_bomlines,        /**< (I) Number of top level BOMLines to duplicate. */
    const tag_t*                              top_bomlines,          /**< (I) n_top_bomlines List of top level BOMLines to duplicate. */
    const int                                 n_cad_options,         /**< (I) Number of cad dependency options selected for processing during duplicate, future use. */
    const char**                              cad_options,           /**< (I) n_cad_options List of cad dependency options selected for processing during duplication, future use. */
    const int                                 n_data_map,            /**< (I) Number of entries in data_map with instructions on how to duplicate BOMLine components of structure. */
    const BOM_duplicate_bomline_data_map_t*   data_map,              /**< (I) n_data_map List of BOMLine components with instructions on how to be processed, BOMLine components not in the data map will be referenced by default. */
    const BOM_duplicate_default_name_t*       default_name,          /**< (I) Default name patterns to use during clone, autogen, prefix, postfix and replace with from to strings. */
    const BOM_duplicate_project_info_t*       projects,              /**< (I) User selected projects to validate and assign duplicated objects to. */
    tag_t                                     default_folder,        /**< (I) Folder to add the cloned root line Item Revision into, NULLTAG allowed. */
    int                                       duplicate_flags,       /**< (I) Bitwise integer flag to set selected duplicate options. */
    int*                                      n_out_data_map,        /**< (O) Number of entries in out_data_map with instructions on how to duplicate BOMLine components of structure. */
    BOM_duplicate_bomline_data_map_t**        out_data_map,          /**< (OF) n_out_data_map List of BOMLine components that went through validation, only populated when validation fails or validate only duplicate option is turned on. */
    int*                                      n_cloned_object_map,   /**< (O) Number of entries in cloned_object_map. */
    BOM_duplicate_cloned_map_t**              cloned_object_map,     /**< (OF) n_cloned_object_map List of original and cloned Item Revisions, only populated if duplicate option to return duplicated objects is turned on. */
    int*                                      n_bomline_status_map,  /**< (O) Number of bomline statuses in bomline_status_map. */
    BOM_duplicate_status_map_t**              bomline_status_map,    /**< (OF) n_bomline_status_map List of top_bomline statuses, returns validate or duplicated status of BOMLines passed in, if duplicated it will also contain the duplicated Item Revision for BOMLines. */
    int*                                      n_error,               /**< (O) Number of partial errors on BOMLines that failed to process. */
    BOM_error_item_revision_t**               error                  /**< (OF) n_error List of partial errors on BOMLines with error numbers and messages that failed to validate or duplicate. */
    );

/** @} */

#ifdef __cplusplus
}
#endif
#include <bom/libbom_undef.h>
#endif

