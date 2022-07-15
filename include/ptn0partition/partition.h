/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2010.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file partition.h

    This header file declares all data types and constants to be used by the APS (Partitions) Team.
*/

/*  */

#ifndef PARTITION_PARTITION_H
#define PARTITION_PARTITION_H
#include <common/tc_deprecation_macros.h>
#include <ptn0partition/libptn0partition_exports.h>

/**
    @defgroup PTN0PARTITION PARTITION
    @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/**
 * Name of the default Revision Rule preference to configure partitions
 */
#define PREF_PARTITION_DEFAULT_REVRULE "PTN_Default_Partition_RevRule"

/**
 * ActionCode is the enum used to update/get children or members for a Partition
*/
typedef enum ActionCode{
    ADD_PARTITION = 0,  /**< Adds child Partitions to a parent Partition or adds parent Partition to  a child Partition or adds members to a Partition. */
    REPLACE_PARTITION,  /**< Replaces an existing child partition in a parent partition or replaces parent Partition in a child Partition or replaces members of a Partition.  */
    REMOVE_PARTITION    /**< Removes an existing child partition from a parent partition or removes parent Partition from a child Partition or removes members of a Partition.
                             Note: that REMOVE_PARTITION does NOT delete the child partition. It just simply removes it from the parent. */
}ActionCode_t;

/**
 * Used to re-parent children partition
*/
typedef enum PARTITION_reparent_partition_action_code_e{
    MOVE_REPARENTING_PARTITION = 0, /**< Move an existing child partition from a source parent partition to target parent partition.
                                         Note that MOVE_REPARENTING_PARTITION remove the child partition present under source parent partition only if it gets added successfully under target parent partition */
    REPLACE_REPARENTING_PARTITION   /**< Replace all existing child partition which are currently present under target parent partition
                                         using given child partitions. Note that REPLACE_REPARENTING_PARTITION remove the child partition present under source parent partition only if it gets replaced successfully under target parent partition */
}PARTITION_reparent_partition_action_code_t;

/**
* Defines the possible options for the #PARTITION_get_mapped_partitions ITK.
*/
typedef enum PARTITION_get_mapped_ptns_input_option_e
{
    PARTITION_include_child_of_mapped_partitions = 0        /**< Option to include child Partitions during getting the mapped Partitions */
} PARTITION_get_mapped_ptns_input_option_t;

/**
* Holds the possible option for #PARTITION_get_mapped_partitions ITK and its corresponding value.
*/
typedef struct PARTITION_get_mapped_input_option_s
{
    PARTITION_get_mapped_ptns_input_option_t     input_option;    /**< Option to get mapped Partitions */
    logical                                      value;           /**< Option value */
} PARTITION_get_mapped_input_option_t;

/**
 * ContentPersistenceMode is the enum used to update/get members for a Partition.
*/
typedef enum ContentPersistenceMode{
    STATIC_MODE  = 0, /**< Members of Partition are saved using persistent Membership option. */
    DYNAMIC_MODE,     /**< Memberships are dynamic and it is defined by a search recipe on the Partition. */
    AUTO_MODE,        /**< Based on the definition of the Partition the mode is determined to be either STATIC or DYNAMIC. */
    ALL_MODE,         /**< Static Memberships are also created/searched for dynamic Partitions. */
    BULK_MODE         /**< Static Memberships are created in bulk. This mode is not supported for Remove and Replace Actions. */
}ContentPersistenceMode_t;

/**
Finds and returns the array of top level partitions in a given Partition Scheme.
@returns
<ul>
<li>#ITK_ok on success.
<li>#PTN0PARTITION_wrong_input_supplied if the partition_scheme_tag is not a proper scheme tag.
<li>#CXPOM_invalid_tag if configuration_context tag is invalid.
</ul>
*/
extern PTN0PARTITION_API int PARTITION_get_toplevel_partitions(
    tag_t          configuration_context,      /**< (I) Configuration context tag */
    tag_t          model_tag,                  /**< (I) Application model tag */
    tag_t          partition_scheme_tag,       /**< (I) Partition scheme tag */
    int*           top_level_partitions_count, /**< (O) Count of top level Partitions */
    tag_t**        top_level_partitions        /**< (OF) top_level_partitions_count Array of tags of top level Partitions */
    );

/**
Finds and returns the partition schemes in a given application model.
@returns
<ul>
<li>#ITK_ok on success.
<li>#CXPOM_invalid_tag if model_tag is invalid.
</ul>
*/
extern PTN0PARTITION_API int PARTITION_get_schemes_in_model(
    tag_t            model_tag,                  /**< (I) Application model tag */
    int*             list_of_schemes_count,      /**< (O) Number of partition schemes */
    tag_t**          list_of_schemes             /**< (OF) list_of_schemes_count Array of partition scheme tags */
    );

/**
Finds and returns the partition objects where a given member is partitioned.
@returns
<ul>
<li>#ITK_ok on success.
<li>#CXPOM_invalid_tag if model_tag or configuration_context is invalid.
</ul>
*/
extern PTN0PARTITION_API int PARTITION_where_partitioned(
    tag_t        configuration_context,     /**< (I) Configuration context tag */
    tag_t        model_tag,                 /**< (I) Application model tag */
    tag_t        scheme_tag,                /**< (I) Partition scheme tag */
    tag_t        member_tag,                /**< (I) Member tag for which the where_partitioned is performed */
    int*         partitions_count,          /**< (O) Number of partitions */
    tag_t**      partitions                 /**< (OF) partitions_count Array of partition tags */
    );

/**
Finds all the associated Partitions for the given members
@returns
<ul>
<li>#ITK_ok on success
<li>#PTN0PARTITION_wrong_input_supplied when the operation fails due to input NULL model tag.
<li>#POM_inst_has_empty_attr if any other input parameter value is invalid.
</ul>
*/
extern PTN0PARTITION_API int PARTITION_where_partitioned_bulk(
    tag_t           configuration_context,  /**< (I)  Configuration context */
    tag_t           model_tag,              /**< (I)  Model tag */
    tag_t           scheme_tag,             /**< (I)  Scheme type tag */
    int             num_members,            /**< (I)  Number of input members */
    const tag_t *   members,                /**< (I)  num_members member tags */
    int *           partitions_count,       /**< (O)  Number of partitions to the input member */
    int **          indexes,                /**< (OF) partitions_count indexes */
    tag_t **        partitions              /**< (OF) partitions_count Array of partition tags */
);
/**
Finds the partition template model with the given Model Id.
@returns
<ul>
<li>#ITK_ok on success.
<li>#PTN0PARTITION_internal_error on invalid model_id.
</ul>
*/
extern PTN0PARTITION_API int PARTITION_find_model_with_id(
    char *       model_id,                  /**< (I) Input model ID */
    tag_t*       model_tag                  /**< (O) Model tag */
    );

/**
Gets Partitions in a given Application Model for the given input Partition Scheme.
@returns
<ul>
<li>#ITK_ok on success.
<li>#PTN0PARTITION_wrong_input_supplied if the partition_scheme_tag is not a proper scheme tag.
<li>#CXPOM_invalid_tag if configuration_context tag is invalid.
</ul>
*/
extern PTN0PARTITION_API int PARTITION_get_partitions(
    tag_t        configuration_context,     /**< (I) Configuration context tag */
    tag_t        model_tag,                 /**< (I) Application model tag */
    tag_t        scheme_tag,                /**< (I) Partition scheme tag */
    int          max_partition_count,       /**< (I) Maximum number of partitions to be returned */
    int*         num_partitions,            /**< (O) Number of the returned partitions */
    tag_t**      partitions                 /**< (OF) num_partitions Array of partition tags */
    );

/**
Updates members and child partitions of a given partition and tracks the failure per member.
@returns
<ul>
<li>#ITK_ok on success.
<li>#PTN0PARTITION_internal_error when updateMembers or updateChildren fails.
</ul>
*/
extern PTN0PARTITION_API int PARTITION_update_members_and_child_partitions(
  tag_t                       partition,                  /**< (I) Partition tag */
  int                         member_count,               /**< (I) Count of new members */
  tag_t                      *members,                    /**< (I) Array of member tags */
  int                         child_count,                /**< (I) Count of children */
  tag_t                      *children,                   /**< (I) Array of child partition tags */
  ActionCode_t                action_code,                /**< (I) 1-ADD, 2-REPLACE, 3-REMOVE */
  ContentPersistenceMode_t    content_persistence_mode,   /**< (I) 1-STATIC, 2-DYNAMIC */
  const tag_t                 configuration_context,      /**< (I) Input configuration context */
  int                        *failed_members_count,       /**< (O) Count of failed members */
  tag_t                     **failed_members,             /**< (OF) failed_members_count Array of member tags that failed to update on a target partition */
  int                        *failed_children_count,      /**< (O) Count of failed children */
  tag_t                     **failed_children,            /**< (OF) failed_children_count Array of child partitions that failed to update */
  int                        *error_count,                /**< (O) Count of the error codes */
  int                       **error_codes                 /**< (OF) error_count Array of error codes for failed member updates */
  );

/**
Updates members and child Partitions of a given partition and tracks the failure and its error messages per member and per partition children.
@returns
<ul>
<li>#ITK_ok on success.
<li>#PTN0PARTITION_internal_error if the update of members or children has failed.
<li>#PTN0PARTITION_invalid_input when @p partition is #NULLTAG
<li>#PTN0PARTITION_invalid_input when @p members is a null pointer and @p member_count is not @c 0.
<li>#PTN0PARTITION_invalid_input when @p children is a null pointer and @p child_count is not @c 0.
<li>#PTN0PARTITION_duplicate_members if any member in @p members is already part of @p partition.
<li>#PTN0PARTITION_duplicate_children if any child in @p children is already part of @p partition.
</ul>

@note If this ITK returns #PTN0PARTITION_duplicate_members or #PTN0PARTITION_duplicate_children
(due to any member/child already part of the partition), it still proceeds to the next member/child
in the list to process remaining members/children.
*/
extern PTN0PARTITION_API int PARTITION_update_members_and_child_partitions_with_error_messages(
  const tag_t                       partition,                  /**< (I) Partition tag */
  const int                         n_members,                  /**< (I) Number of new members */
  const tag_t                      *members,                    /**< (I) n_members New members */
  const int                         n_children,                 /**< (I) Number of children */
  const tag_t                      *children,                   /**< (I) n_children Child Partitions */
  const ActionCode_t                action_code,                /**< (I) Action to apply on the members or child Partitions */
  const ContentPersistenceMode_t    content_persistence_mode,   /**< (I) Modes to update the members */
  const tag_t                       configuration_context,      /**< (I) Input configuration context */
  int                              *n_failed_members,           /**< (O) Number of failed members */
  tag_t                           **failed_members,             /**< (OF) n_failed_members The members that failed to update on the target Partition  */
  int                              *n_failed_children,          /**< (O) Number of failed children */
  tag_t                           **failed_children,            /**< (OF) n_failed_children The child Partitions that failed to update on the target Partition*/
  int                              *n_errors,                   /**< (O) Number of error codes */
  int                             **error_codes,                /**< (OF) n_errors Error codes for failed member or failed children updates */
  char ***                          error_messages              /**< (OF) n_errors Error messages for failed member or failed children updates.
                                                                <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only. */
  );

/**
Reparents child partitions of a given parent partition to a new parent partition
and tracks the failure per member.
@returns
<ul>
<li>#ITK_ok on success.
<li>#PTN0PARTITION_internal_error when reparenting fails.
</ul>
*/
extern PTN0PARTITION_API int PARTITION_reparent_partitions(
    tag_t                                       current_parent,         /**< (I) Partition tag */
    int                                         child_count,            /**< (I) Count of children */
    const tag_t *                               children,               /**< (I) Array of child partition tags */
    PARTITION_reparent_partition_action_code_t  action_code,            /**< (I) MOVE_REPARENTING_PARTITION = 0, REPLACE_REPARENTING_PARTITION = 1 */
    tag_t                                       target_parent,          /**< (I) Partition tag: new parent */
    int *                                       failed_children_count,  /**< (O) Count of failed children */
    tag_t **                                    failed_children,        /**< (OF) failed_children_count Array of child partitions that failed to update */
    int *                                       error_count,            /**< (O) Count of the error codes */
    int **                                      error_codes,            /**< (OF) error_count Array of error codes for failed member updates */
    char ***                                    error_messages          /**< (OF) error_count Array of packed error messages for failed member updates */
);

/**
@deprecated #PARTITION_find_all_history_sync_changes deprecated in Teamcenter 11.2.3.
    <br/>Starting Teamcenter 11.2.3, history versions are always in sync, and therefore this
    function always gives @c n_changes = 0.

Compare mdl0HistorySyncStatus for the content of all subset definitions.
<br/>Where content is out of sync, add the content to the workflow as a target.
<br/>An Mdl0ModelElement is in sync whenever the mdl0HistorySyncStatus is.

If schema_names is non empty, partitions in the given partition schemes will also be attached if:
<ul>
<li> The partition is configured by the subset definition.
<li> the partition itself is out of sync.
<li> the partition lies on the path from subset definition content to the root partitions.
</ul>

If schema_names = "*"|"all"|"any" all the partitions are returned

@returns
<ul>
<li>#ITK_ok on success.
<li>#PTN0PARTITION_wrong_input_supplied if the subset_definitions are not a proper subset definition tags.
</ul>
*/
TC_DEPRECATED_NO_REPLACEMENT( "11.2.3", "PARTITION_find_all_history_sync_changes" )
extern PTN0PARTITION_API int PARTITION_find_all_history_sync_changes(
    int             n_subset_definitions,   /**< (I)  Number of subset definitions */
    const tag_t*    subset_definitions,     /**< (I)  Array of subset definition tags */
    int             n_schemas,              /**< (I)  Number of schemas */
    const char**    schema_names,           /**< (I)  Array of names of the partition schemas */
    int*            n_changes,              /**< (O)  Number of changed elements */
    tag_t**         changes                 /**< (OF) n_changes tags of changed elements */
    );

/**
    Retrieves Mapped Partitions corresponding to the given input Partitions.
    <br/>Since several Mapped Partitions can be retrieved for a given input Partition, the Owning Partition is also repeated as an output parameter.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#PTN0PARTITION_invalid_input if the operation fails due to invalid input (invalid value for @p app_model_reference or @p input_partitions or @p partition_schemes)
    <li>#PTN0PARTITION_internal_error if the operation fails due to any other internal error.
    </ul>
    @note No errors are returned if one or more entries in @p partition_schemes is invalid or if @p configuration_context is invalid.
    <br/>Only the Mapped Partitions which satisfy the provided @p partition_schemes and having no Configuration Context are retrieved.
    <br/>If @p input_options is not provided or incorrect, no children of Mapped Partitions are retrieved and no error is returned.
*/
extern PTN0PARTITION_API int PARTITION_get_mapped_partitions(
    int                          num_of_input_partitions,             /**< (I)  Number of input Partitions */
    const tag_t *                input_partitions,                    /**< (I)  num_of_input_partitions Partitions for which mapped Partitions to be searched */
    int                          num_of_partition_schemes,            /**< (I)  Number of input Partitions Schemes */
    const tag_t *                partition_schemes,                   /**< (I)  num_of_partition_schemes Partitions Schemes from which mapped Partition needs to be retrieved */
    tag_t                        app_model_reference,                 /**< (I)  Application Model tag */
    tag_t                        configuration_context,               /**< (I)  Configuration Context tag to configure the mapped Partitions */
    int                          num_of_input_options,                /**< (I)  Number of input options */
    const PARTITION_get_mapped_input_option_t *   input_options,      /**< (I)  num_of_input_options Array of input options structure */
    int *                        num_of_partitions,                   /**< (O)  Number of mapped Partitions retrieved */
    tag_t **                     owning_partitions,                   /**< (OF) num_of_partitions Owning Partitions for which mapped Partitions are found */
    tag_t **                     mapped_partitions                    /**< (OF) num_of_partitions Retrieved mapped Partitions corresponding to Owning Partitions */
);

/**
    Retrieves Owning Partitions corresponding to the given input Target Partitions.
    <br/>Since several Owning Partitions can be retrieved for a given input Target Partition, the Target Partition is also repeated as an output parameter.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#PTN0PARTITION_invalid_input if the operation fails due to invalid input (@p app_model_reference or any element in @p input_target_partitions)
    <li>#PROP_invalid_object if the operation fails due to one or more non-existent @p input_target_partitions.
    <li>#PTN0PARTITION_internal_error if the operation fails due to any other internal error.
    </ul>
*/
extern PTN0PARTITION_API int PARTITION_get_owning_partitions(
    int               num_of_input_target_partitions,        /**< (I)  Number of input Target Partitions */
    const tag_t *     input_target_partitions,               /**< (I)  num_of_input_target_partitions Target Partitions for which Owning Partitions to be searched */
    tag_t             app_model_reference,                   /**< (I)  Application Model */
    tag_t             configuration_context,                 /**< (I)  Configuration Context used to configure the Owning Partitions*/
    int *             num_of_partitions,                     /**< (O)  Number of Owning Partitions retrieved */
    tag_t **          target_partitions,                     /**< (OF) num_of_partitions Target Partitions for which Owning Partitions are found */
    tag_t **          owning_partitions                      /**< (OF) num_of_partitions Retrieved Owning Partitions corresponding to mapped Target Partitions */
);

/**
    Extracts the child Partitions for given parent Partitions.
    <br/>Let us consider the structure to be as below, and requesting the child partitions of the { a01, b01} partitions:

    <br/>a01
    <br/>&nbsp;&nbsp;a11
    <br/>&nbsp;&nbsp;&nbsp;&nbsp;a21
    <br/>&nbsp;&nbsp;a12
    <br/>&nbsp;&nbsp;&nbsp;&nbsp;a22
    <br/>&nbsp;&nbsp;&nbsp;&nbsp;a23
    <br/>b01
    <br/>&nbsp;&nbsp;b11
    <br/>&nbsp;&nbsp;b12
    <br/>&nbsp;&nbsp;&nbsp;&nbsp;b22

    <br/><br/> The Output from the API would be:
    <table border="1" style="width:100%">
    <tr>
      <td>Partition</td>
      <td>a01</td>
      <td>b01</td>
      <td>a11</td>
      <td>a12</td>
      <td>b11</td>
      <td>b12</td>
      <td>a21</td>
      <td>a22</td>
      <td>a23</td>
      <td>b22</td>
    </tr>
    <tr>
      <td>partition_indexes</td>
      <td>0</td>
      <td>1</td>
      <td>0</td>
      <td>0</td>
      <td>1</td>
      <td>1</td>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>1</td>
    </tr>
    <tr>
      <td>parent_indexes</td>
      <td>n/a</td>
      <td>n/a</td>
      <td>0</td>
      <td>0</td>
      <td>1</td>
      <td>1</td>
      <td>2</td>
      <td>3</td>
      <td>3</td>
      <td>5</td>
    </tr>
    <tr>
      <td>levels</td>
      <td>0</td>
      <td>0</td>
      <td>1</td>
      <td>1</td>
      <td>1</td>
      <td>1</td>
      <td>2</td>
      <td>2</td>
      <td>2</td>
      <td>2</td>
    </tr>
    </table>

    The parameter @p partition_indexes gives the index of the original
    input Partition (so the source for each result can be identified)
    and the parameter @p parent_indexes gives the index of the parent
    <br/>For "n/a" (as mentioned in the table above), the value "-1" is used.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#MDL0MODEL_invalid_ConfigurationContext if @p configuration_context is invalid
    <li>#MDL0MODEL_invalid_application_model if @p model is invalid
    <li>#PTN0PARTITION_invalid_schemetype if @p scheme_type is invalid
    <li>#PTN0PARTITION_invalid_input when @p partition is #NULLTAG
    <li>#PTN0PARTITION_invalid_input if any member of @p partitions is not a valid Partition.
    <li>#PTN0PARTITION_internal_error if a mismatch occurs in parallel vectors
    </ul>
*/
extern PTN0PARTITION_API int PARTITION_ask_child_partitions(
    const logical      active_only,                      /**< (I) To retrieve only active partitions */
    const tag_t        configuration_context,            /**< (I) Configuration context */
    const tag_t        model,                            /**< (I) Model */
    const tag_t        scheme_type,                      /**< (I) Scheme type */
    const int          n_partitions,                     /**< (I) Number of Partitions */
    const tag_t *      partitions,                       /**< (I) n_partitions Input Partitions */
    const int *        max_levels,                       /**< (I) n_partitions Defines how many levels to search. A value smaller than 1 means "without limit" */
    const int *        max_num_children,                 /**< (I) n_partitions Defines how many descendants to allow. A value smaller than 1 means "without limit" */
    int *              n_descendants,                    /**< (O) Total number of descendants */
    int **             parent_indexes,                   /**< (OF) n_descendants Parent Partition indexes */
    tag_t **           descendants,                      /**< (OF) n_descendants Descendant Partitions */
    logical **         truncated,                        /**< (OF) n_partitions Indicates if the descendant partitions are truncated */
    int **             levels                            /**< (OF) n_descendants Levels of descendant Partitions */
);

/**
Constructs Partition Scheme Create Input in bulk.
<br/>The process to construct Partition Schemes is:
<ol>
    <li>Construct Create Inputs for the Partition Schemes
    <li>Set any custom attributes on the Create Input for each Partition Scheme
    <li>Call to TCTYPE_create_object (input, partition scheme) for each Create Input
</ol>

@returns
<ul>
<li>#ITK_ok on success.
<li>#CXPOM_invalid_tag if the Application Model does not evaluate to a valid object.
<li>#TYPE_unknown_type if any Partition Scheme type is not valid.
<li>#PTN0PARTITION_invalid_input if the Application Model or Partition Scheme types are valid objects but of incorrect types.
</ul>
*/

extern PTN0PARTITION_API int PARTITION_construct_partition_scheme_create_input (
    const tag_t         application_model,        /**< (I) Application Model to create Partition Schemes */
    const unsigned int  n_schemes,                /**< (I) Number of Partition Scheme Inputs to construct */
    const char**        scheme_types,             /**< (I) n_schemes Partition Scheme Types */
    const char**        scheme_names,             /**< (I) n_schemes Partition Scheme Names */
    tag_t**             scheme_create_inputs      /**< (OF) n_schemes Partition Scheme Create Inputs */
);

/**
Constructs Partition Create Input in bulk.
<br/>The process to construct Partitions is:
<ol>
    <li>Construct Create Inputs for the Partitions
    <li>Set any custom attributes on the Create Input for each Partition
    <li>Call to TCTYPE_create_object (input, partition) for each Create Input
</ol>

@returns
<ul>
<li>#ITK_ok on success.
<li>#CXPOM_invalid_tag if the Application Model or Partition Schemes do not evaluate to valid objects.
<li>#TYPE_unknown_type if any Partition type is not valid.
<li>#PTN0PARTITION_invalid_input if the Application Model, Partition Schemes or Partition types are valid objects but of incorrect types.
<li>#PTN0PARTITION_invalid_schemetype if the Partition type cannot be created under the corresponding Partition Scheme.
</ul>
*/
extern PTN0PARTITION_API int PARTITION_construct_partition_create_input (
    const tag_t         application_model,          /**< (I) Application Model to create Partition */
    const unsigned int  n_partitions,               /**< (I) Number of Partition Inputs to construct */
    const tag_t*        scheme_tags,                /**< (I) n_partitions Partition Schemes in which Partition should be created */
    const char**        partition_types,            /**< (I) n_partitions Partition Types */
    const char**        partition_ids,              /**< (I) n_partitions Partition IDs */
    const char**        partition_names,            /**< (I) n_partitions Partition Names */
    tag_t**             partition_create_inputs     /**< (OF) n_partitions Partition Create Inputs */
);

/**
    Extracts the static members for given Partitions.
    Suppose we asks the static members of { a01, b01 } partitions and we have

    <br>a01
    <br>&nbsp;&nbsp;de1
    <br>&nbsp;&nbsp;de2
    <br>&nbsp;&nbsp;de3
    <br>b01
    <br>&nbsp;&nbsp;de4
    <br>&nbsp;&nbsp;de5

    <table border="1" style="width:100%">
    <tr>
      <td>static_members</td>
      <td>de1</td>
      <td>de2</td>
      <td>de3</td>
      <td>de4</td>
      <td>de5</td>
    </tr>
    <tr>
      <td>parent_partition</td>
      <td>a01</td>
      <td>a01</td>
      <td>a01</td>
      <td>b01</td>
      <td>b01</td>
    </tr>
    </table>

    i.e. static_members and parent_partitions will gives us mapping between parent Partition and their static member

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PROP_invalid_object if the input partition is invalid.
    <li>#PTN0PARTITION_internal_error if the mismatch occurs in parallel vectors
    </ul>
*/
    extern PTN0PARTITION_API int PARTITION_get_static_members(
        tag_t           config_context,         /**< (I) Configuration context */
        tag_t           model,                  /**< (I) Model */
        tag_t           scheme_type,            /**< (I) Scheme type */
        int             num_partitions,         /**< (I) Number of Partitions */
        const tag_t *   partitions,             /**< (I) Input Partitions */
        int *           num_static_members,     /**< (O) Total number of descendants */
        tag_t **        static_members,         /**< (OF) num_static_members Static members returned */
        tag_t **        parent_partitions       /**< (OF) num_static_members Parent Partitions */
    );

/**
Replay the recipes of the input dynamic partitions and update their memberships.
<br>If input contains static partitions, they will be ignored without warnings.
<br>If input contains none partitions, will 
@returns
<ul>
<li>#ITK_ok on success.
<li>#PTN0PARTITION_invalid_partition_not_dynamic The object is not dynamic partition. There is no recipe to replay to update its memberships.
</ul>
*/

    extern PTN0PARTITION_API int PARTITION_persist_dynamic_partition_members(
        int             num_partitions,         /**< (I)  Number of Partitions */
        const tag_t *   partitions,             /**< (I)  num_partitions Input Partitions */
        int *           num_errors,             /**< (O)  Number of errors */
        tag_t **        failed_partitions,      /**< (OF) num_errors Dynamic partitions that failed  membership update */
        int **          error_codes             /**< (OF) num_errors Error codes for failed dynamic partition replay */
    );

#ifdef __cplusplus
}
#endif

/**
  @}
*/

#include <ptn0partition/libptn0partition_undef.h>
#endif /* PARTITION_PARTITION_H     */
