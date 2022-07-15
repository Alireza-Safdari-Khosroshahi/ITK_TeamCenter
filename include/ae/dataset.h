/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This header file declares all data types and constants to be used by clients of
    the Dataset class which is part of the Application Encapsulation module of Teamcenter Engineering.

    <b>Restrictions:</b>

    This include file should not generally be used by anyone. Normally ae.h should be included instead.
*/

/*  */

#ifndef DATASET_H
#define DATASET_H

#include <ae/ae_types.h>
#include <tccore/workspaceobject.h>
#include <common/tc_deprecation_macros.h>
#include <ae/libae_exports.h>

/**
    @defgroup DATASET Dataset
    @ingroup AE

    A complete list of named references defined for a tool may not necessarily exist in all instances
    of datasets created by that tool or datasets that can be read by that tool.

    @warning Do not pass the const char reference_name[AE_reference_size_c + 1] argument
    to #AE_add_dataset_named_ref2 or #AE_remove_dataset_named_ref2 by handing to them a character pointer which
    points to a reference name and which is returned by another Teamcenter Engineering routine
    (like a pointer returned by #AE_ask_dataset_named_ref2 or by other ITK routines).
    Unpredictable results can happen this way which can be difficult to trace down.
    We strongly recommend that you always make a copy of the reference name into a local character array before
    passing it to these two ITK functions as follows:

    @code
    your_ITK_routine()
    {
        char my_local_copy_refname[AE_reference_size_c + 1];
        char my_other_refname[AE_reference_size_c + 1];

        tag_t my_dataset;
        tag_t my_other_dataset;

        AE_reference_type_t my_ref_type;
        AE_reference_type_t my_other_ref_type;

        tag_t my_ref_object;
        tag_t my_other_ref_object;

        .... other stuff ...

        strcpy(my_local_copy_refname, "UGPART");
        AE_add_dataset_named_ref2(my_dataset, my_local_copy_refname, myref_type, my_ref_object);

        strcpy(my_local_copy_refname, "CLS");
        AE_add_dataset_named_ref2(my_dataset, my_local_copy_refname, my_other_ref_type, my_other_ref_object);

        .... other stuff ...

        strcpy(my_other_refname, "EXPERT");
        AE_ask_dataset_named_ref2(my_other_dataset, my_other_refname, & my_other_ref_type, & my_other_ref_object);

        strcpy(my_local_copy_refname, my_other_refname);
        AE_add_dataset_named_ref2(my_dataset, my_local_copy_refname, my_other_ref_type, my_other_ref_object);

        .... other stuff ...

        strcpy(my_local_copy_refname, "UGPART");
        AE_remove_dataset_named_ref2(my_dataset, my_local_copy_refname);

        .... other stuff ...

    }
    @endcode

    #AE_reference_type_t can be either #AE_ASSOCIATION or #AE_PART_OF.
    @{
*/

typedef enum AE_reference_type_e
{
             AE_BAD_REF_TYPE = 0,
             AE_ASSOCIATION,    /**< Referenced objects are not a logical part of the dataset and will not be deleted with the dataset.*/
             AE_PART_OF         /**< Referenced objects are an integral part of the dataset and will be deleted with the dataset.*/
} AE_reference_type_t;

#ifdef __cplusplus
    extern "C"{
#endif

/**
    Returns the tags of all of the datasets currently in the database.
    The memory for datasets should be freed with #MEM_free .
*/
extern AE_API int AE_dataset_extent(
    int*          n_instances,        /**< (O) */
    tag_t**       instances           /**< (OF) n_instances */
    );


/**
   From Tc9.0 onwards, please use generic creation of BusinessObject (i.e createBusinessObject (C++) or #TCTYPE_create_object).
*/
extern AE_API int AE_create_dataset_with_revanchor(
    tag_t        type,                               /**< (I) The type of the dataset. */
    const char*  name,                               /**< (I) The name. */
    const char*  description,                        /**< (I) The description. */
    const char*  id,                                 /**< (I) The ID. */
    const char*  revision,                           /**< (I) The revision. */
    tag_t        revision_anchor,                    /**< (I) The associated anchor. */
    tag_t*       new_dataset                         /**< (O) The created dataset. */
    );


/** 
    Retrieves a proposed name to give to a Dataset instance.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if @p owning_item is #NULLTAG.
    <li>#POM_invalid_tag if @p owning_item or @p dataset_type are not valid tags.
    <li>#CXPOM_wrong_class if @p owning_item does not represent an Item or ItemRevision, or if @p dataset_type does not represent a Dataset type.
 </ul>
*/
extern AE_API int AE_new_dataset_name(
    const tag_t owning_item,     /**< (I) Item/ItemRevision under which the Dataset is to be created. */
    const tag_t dataset_type,    /**< (I) Type of the Dataset to be created. 
                                    <br/>It can be NULLTAG if the type is not known. */
    char**      dataset_name     /**< (OF) The proposed Dataset name. */ 
    );


/**
    Returns the Tag of the dataset with the input name.
    Dataset names are not necessarily unique.
    This function always returns the Tag of the latest revision.
    Use the revision anchor to get the precise dataset desired.
    When the dataset is found, it will not be loaded for modify.
    Call #AOM_refresh or #AOM_lock to set it for modify.
    For more complicated searches, use #WSOM_search .
*/
extern AE_API int AE_find_dataset2(
    const char    *dataset_name,                          /**< (I) */
    tag_t*        dataset                                 /**< (O) */
    );


/**
    Finds all the datasets in the database that match the input name.
*/
extern AE_API int AE_find_all_datasets2(
    const char    *dataset_name,                          /**< (I) Dataset name being used for searching the database. */
    int*          nFound,                                 /**< (O) Total number of tags that are found (i.e., the total
                                                                number of elements in the output tag list datasets).
                                                                nFound will be 0 if there is no match.*/
    tag_t**       dataset                                 /**< (OF) nFound A pointer to an array of tags.
                                                                They are the tags of all the dataset versions of all the
                                                                datasets that match the input name dsName.
                                                                Content of datasets (i.e., in C, that means *datasets)
                                                                will be NULL if there is no match. */
    );


/**
    Returns the default revision limit for newly created datasets as set by the system administrator.
    This value is in the AE_dataset_default_keep_limit preference.
*/
extern AE_API int AE_ask_dataset_def_rev_limit(
    int*          default_rev_limit     /**< (O) */
    );



/**
    Returns the tool attribute for the input dataset.
*/
extern AE_API int AE_ask_dataset_tool(
    tag_t         dataset,           /**< (I) */
    tag_t*        tool               /**< (O) */
    );


/**
    Returns the format attribute for the input dataset.
*/
extern AE_API int AE_ask_dataset_format2(
    tag_t         dataset,                               /**< (I) */
    char          **format_name                          /**< (OF) */
    );


/**
    Returns the site classification attribute for the input dataset.
*/
extern AE_API int AE_ask_dataset_siteclass2(
    tag_t         dataset,                                        /**< (I) */
    char          **site_classification                           /**< (OF) */
    );


/**
    Returns the datasettype attribute for the input dataset.
*/
extern AE_API int AE_ask_dataset_datasettype(
    tag_t         dataset,           /**< (I) */
    tag_t*        datasettype        /**< (O) */
    );

/**
    Sets the tool attribute for the input dataset.
*/
extern AE_API int AE_set_dataset_tool(
    tag_t         dataset,           /**< (I) */
    tag_t         tool               /**< (I) */
    );



/**
    Sets the format attribute for the input dataset.

    These functions ask or set a dataset named reference operating system file format.
    Allowed file formats are:

    #TEXT_REF - ASCII text files <br>
    #BINARY_REF - Binary files.
*/
extern AE_API int AE_set_dataset_format2(
    tag_t         dataset,                               /**< (I) */
    const char    *format_name                           /**< (I) */
    );



/**
    Sets the site classification attribute for the input dataset.
*/
extern AE_API int AE_set_dataset_siteclass2(
    tag_t         dataset,                                        /**< (I) */
    const char    *site_classification                            /**< (I) */
    );

/**
    Sets the datasettype attribute for the input dataset.
*/
extern AE_API int AE_set_dataset_datasettype(
    tag_t         dataset,      /**< (I) */
    tag_t         datasettype   /**< (I) */
    );

/**
    Saves any changes made to the dataset mydataset directly to itself.
    This function differs from #AOM_save which saves your changes into a new dataset version.
    #AE_save_myself saves your changes directly into the mydataset dataset version without creating any new dataset version.
    We recommend you use #AE_save_myself whenever you make changes to the attributes or owner/group of a dataset.
*/
extern AE_API int AE_save_myself(
    tag_t         dataset       /**< (I) */
    );

/**
    Saves a list of Datasets without creating new versions.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#AE_cannot_save_dataset if any dataset in @p datasets could not be saved.
    <li>Potentially other errors
    </ul>

    @note The ITK is transactional, which means that if any error is returned, none of the Datasets are saved.
*/
extern AE_API int AE_save_myself_in_bulk(
    int                 n_datasets,   /**< (I) The number of datasets  */ 
    const tag_t*        datasets      /**< (I) n_datasets Datasets to save */ 
    );


/**
    Adds named references to datasets.
*/
extern AE_API int AE_add_dataset_named_ref2(
    tag_t                   dataset,                                  /**< (I) */
    const char              *reference_name,                          /**< (I) */
    AE_reference_type_t     reference_type,                           /**< (I) */
    tag_t                   previously_saved_object                   /**< (I) */
    );

/**
    @name Revision Anchor
    @{
*/

/**
    This function is used to replace an existing named reference with a new named reference for a dataset.
*/
extern AE_API int AE_replace_dataset_named_ref2(
    tag_t                   dataset,                                  /**< (I) */
    tag_t                   old_referenced_object,                    /**< (I) */
    const char              *reference_name,                          /**< (I) */
    AE_reference_type_t     reference_type,                           /**< (I) */
    tag_t                   previously_saved_object                   /**< (I) */
    );



/**
    This function is used to insert a new named reference at the specified position (index) for a dataset.
    The index starts at 0.
*/
extern AE_API int AE_insert_dataset_named_ref2(
    tag_t                   dataset,                                  /**< (I) */
    int                     index,                                    /**< (I) */
    const char              *reference_name,                          /**< (I) */
    AE_reference_type_t     reference_type,                           /**< (I) */
    tag_t                   previously_saved_object                   /**< (I) */
    );

/** @} */



/**
    Finds named references in datasets.
*/
extern AE_API int AE_find_dataset_named_ref2(
    tag_t                   dataset,                                 /**< (I) */
    int                     instance,                                /**< (I) */
    char                    **reference_name,                        /**< (OF) */
    AE_reference_type_t*    reference_type,                          /**< (O) */
    tag_t*                  referenced_object                        /**< (O) */
    );

extern AE_API int AE_ask_dataset_ref_count(
    tag_t         dataset,             /**< (I) */
    int*          reference_count      /**< (O) */
    );


extern AE_API int AE_ask_dataset_named_ref2(
    tag_t                   dataset,                                 /**< (I) */
    const char              *reference_name,                         /**< (I) */
    AE_reference_type_t*    reference_type,                          /**< (O) */
    tag_t*                  referenced_object                        /**< (O) */
    );


/**
    @deprecated #AE_ask_all_dataset_named_refs deprecated in Teamcenter 10.0. Use #AE_ask_all_dataset_named_refs2 instead.

    This function finds all the named reference objects of the dataset dsTag that match the name refName.
*/
TC_DEPRECATED("10.0","AE_ask_all_dataset_named_refs","AE_ask_all_dataset_named_refs2")
extern AE_API int AE_ask_all_dataset_named_refs(
    tag_t         dataset,                                 /**< (I) Tag of the dataset that owns the named reference objects. */
    const char    reference_name[AE_reference_size_c + 1], /**< (I) Name being used for searching the named reference objects in the database.*/
    int*          nFound,                                  /**< (O) Total number of tags that are found (i.e., the total number
                                                                of elements in the output tag list refObjs).
                                                                nFound will be 0 if there is no match. */
    tag_t**       referenced_object                        /**< (OF) nFound A pointer to an array of tags.
                                                                They are the tags of all the named reference objects of dataset dsTag
                                                                that match the input name refName. Content of refObjs
                                                                (i.e., in C, that means *refObjs) will be NULL if there is no match.
                                                                Also, the user is responsible to free the done
                                                                (hence, the notation (OF)).*/
    );

/**
    This function finds all the named reference objects of the dataset dsTag that match the name refName.
*/
extern AE_API int AE_ask_all_dataset_named_refs2(
    tag_t         dataset,                                 /**< (I) Tag of the dataset that owns the named reference objects. */
    const char    *reference_name,                         /**< (I) Name being used for searching the named reference objects in the database.*/
    int*          n_found,                                  /**< (O) Total number of tags that are found (i.e., the total number
                                                                of elements in the output tag list refObjs).
                                                                nFound will be 0 if there is no match. */
    tag_t**       referenced_object                        /**< (OF) n_found A pointer to an array of tags.
                                                                They are the tags of all the named reference objects of dataset dsTag
                                                                that match the input name refName. Content of refObjs
                                                                (i.e., in C, that means *refObjs) will be NULL if there is no match.
                                                                Also, the user is responsible to free the done
                                                                (hence, the notation (OF)).*/
    );


extern AE_API int AE_remove_dataset_named_ref2(
    tag_t         dataset,                                         /**< (I) */
    const char    *reference_name                                  /**< (I) */
    );



/**
    Removes named references from datasets.
*/
extern AE_API int AE_remove_dataset_named_ref_by_tag2(
    tag_t         dataset,                                  /**< (I) */
    const char    *reference_name,                          /**< (I) */
    tag_t         referenced_object                         /**< (I) */
    );


/**
    Determines if the dataset name (dsName) is unique in the database.
    <br/>For purposes of this discussion unique means that two or more datasets cannot have
    the name dsName and that different versions of the same dataset are not considered to be different datasets
    - they are merely back up versions of the same dataset.
*/
extern AE_API int AE_is_dataset_unique2 (
    const char    *dataset_name,                       /**< (I) Dataset name being used for searching the database. */
    logical*      result                               /**< (O) Value "True" if uniqueness is confirmed. "False", otherwise. */
    );

/**
    Retrieves the total number of versions for the specified dataset.
*/
extern AE_API int AE_ask_dataset_num_revs(
    tag_t         dataset,  /**< (I) Tag of the input dataset being used for counting the total number of versions. */
    int*          count     /**< (O) Total number of versions for the dataset. */
    );

/**
    Deletes all unreferenced dataset revisions except the latest revision.
*/
extern AE_API int AE_purge_dataset_revs(
    tag_t         dataset   /**< (I) */
    );

/**
    Deletes all revisions of a dataset that are not referenced by some other object in the database.
    <br/>If none of the revisions are referenced,
    then the dataset and its revision anchor will be removed from the database completely.
*/
extern AE_API int AE_delete_all_dataset_revs(
    tag_t         dataset   /**< (I) */
    );

/**
    Returns the revision anchor for any revision of a dataset.
    The anchor can be used to perform more sophisticated revisioning tasks on a dataset.
*/
extern AE_API int AE_ask_dataset_anchor(
    tag_t         dataset,          /**< (I) */
    tag_t*        revision_anchor   /**< (O) */
    );

/**
    Retrieves the dataset based on the creation order you specified
    (i.e., first dataset, second dataset, third dataset, ... N(th) dataset).
    Notice that the index is relative to 1.

    If you have dataset versions: 1, 2, 3, 4 and 5, then an index of 4 returns dataset version 4.

    If you have dataset versions: 1, 5, 7, 90 and 99, then an index of 4 returns dataset version 90.
*/
extern AE_API int AE_ask_dataset_at(
    tag_t         dataset,          /**< (I) The input dataset. */
    int           index_name,       /**< (I) Index to locate the desired dataset version. */
    tag_t*        dataset_version   /**< (O) The desired dataset version. */
    );

/**
    Returns the tag of the highest revision dataset.
*/
extern AE_API int AE_ask_dataset_latest_rev(
    tag_t         dataset,          /**< (I) */
    tag_t*        latest_dataset    /**< (O) */
    );

/**
    Retrieves the oldest version (i.e., version 1) of the specified dataset.
*/
extern AE_API int AE_ask_dataset_first_rev(
    tag_t         dataset,          /**< (I) Specified dataset being used for getting its oldest version. */
    tag_t*        first_dataset     /**< (O) The oldest version (i.e. version 1). */
    );

/**
    Retrieves the latest version of the specified dataset (version0).
*/
extern AE_API int AE_ask_dataset(
    tag_t         dataset,          /**< (I) Specified dataset being used for getting its latest version. */
    tag_t*        last_dataset      /**< (O) The latest version (i.e. version 0) */
    );

/**
    Retrieves the next version relative to the specified dataset.
*/
extern AE_API int AE_ask_dataset_next_rev(
    tag_t         dataset,          /**< (I) Specified dataset being used for getting its next version. */
    tag_t*        next_dataset      /**< (O) The next version (i.e. version 1). */
    );

/**
    Retrieves the previous version relative to the specified dataset.
*/
extern AE_API int AE_ask_dataset_prev_rev(
    tag_t         dataset,          /**< (I) Specified dataset being used for getting its previous version. */
    tag_t*        previous_dataset  /**< (O) The previous version (i.e. version 1). */
    );


extern AE_API int AE_ask_dataset_named_refs(
    tag_t         dataset,       /**< (I) */
    int*          n_found,       /**< (O) */
    tag_t**       ref_object     /**< (OF) n_found */
    );


/**
    @name Dataset Identification
    @{
*/

/**
    Finds the id and revision for a specified Dataset.
*/
extern AE_API int AE_ask_dataset_id_rev(
    tag_t         dataset,           /**< (I) The Dataset. */
    char**        dataset_id,        /**< (OF) The Dataset ID. */
    char**        dataset_revision   /**< (OF) The Dataset revision. */
    );

/**
    Sets the ID and revision for a specified Dataset.
*/
extern AE_API int AE_set_dataset_id_rev(
    tag_t         dataset,           /**< (I) The Dataset. */
    const char*   dataset_id,        /**< (I) The Dataset ID. */
    const char*   dataset_revision   /**< (I) The Dataset revision. */
    );

/**
    Retrieves the Dataset tag, type, id, and rev that matches the specified id and rev.
*/
extern AE_API int AE_find_dataset_by_id_rev(
    tag_t         dataset_type,       /**< (I) The Dataset type used to search the database. */
    const char*   dataset_id,         /**< (I) The Dataset ID. */
    const char*   dataset_revision,   /**< (I) The Dataset revision. */
    tag_t*        dataset             /**< (O) The found Dataset. */
    );


/**
    Finds all of the datasets in the database that match the specified Dataset type name and Dataset id.
*/
extern AE_API int AE_find_all_datasets_by_id(
    tag_t         dataset_type,     /**< (I) The Dataset type used to search the database. */
    const char*   dataset_id,       /**< (I) The Dataset ID. */
    int*          n_found,          /**< (O) The total number of found Datasets.
                                       <br/>@p n_found is 0 if there is no match.*/
    tag_t**       datasets          /**< (OF) n_found The found Datasets that match the specified dataset type and ID.
                                       <br/>@p datasets is NULL if there is no match.*/
    );

/**
    Creates a Dataset by specified type, name, description, id, and rev.
*/
extern AE_API int AE_create_dataset_with_id(
    tag_t         dataset_type,         /**< (I) The Dataset type. */
    const char*   dataset_name,         /**< (I) The new user-defined Dataset name. */
    const char*   dataset_description,  /**< (I) The new user-defined Dataset description. */
    const char*   dataset_id,           /**< (I) The Dataset ID. */
    const char*   dataset_revision,     /**< (I) The Dataset revision.*/
    tag_t*        new_dataset           /**< (O) The new Dataset. */
    );

/**
    Initializes the newly created dataset by the type, name, description, id, and rev specified.
*/
extern AE_API int AE_initialize_dataset_with_id(
    tag_t         dataset,               /**< (I) The specified Dataset to be initialized. */
    tag_t         dataset_type,          /**< (I) The Dataset type used to create the dataset. */
    const char*   dataset_name,          /**< (I) The new user-defined Dataset name. */
    const char*   dataset_description,   /**< (I) The new user-defined Dataset description. */
    const char*   dataset_id,            /**< (I) The Dataset ID. */
    const char*   dataset_revision       /**< (I) The Dataset revision. */
    );


/**
   Copies a dataset and uses the Dataset tag, the new dataset name, id, and rev.
*/
extern AE_API int AE_copy_dataset_with_id(
    tag_t         dataset,          /**< (I) The Dataset to be copied. */
    const char*   dataset_name,     /**< (I) The new user-defined Dataset name. */
    const char*   dataset_id,       /**< (I) The new Dataset ID. */
    const char*   dataset_revision, /**< (I) The new Dataset revision. */
    tag_t*        new_dataset       /**< (O) The new Dataset. */
    );

/** @} */

/**
    Imports the specified file, os_full_path_name, into Teamcenter, creating a new ImanFile using the name specified by new_file_name
    and associates that ImanFile object with the specified dataset object.


    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#AE_attempt_to_circular_ref if adding the dataset tag as a named reference and attempting to create a circular reference.
    <li>#AE_file_type_mismatch_ref if the file type of the new_file_name is neither #SS_BINARY nor #SS_TEXT.
    <li>#AE_nonfile_ref_to_file_ref if it cannot add a non-file reference to dataset expecting a file reference.
    <li>#AE_no_add_ref if the named reference to be imported is not an ImanFile.
    </ul>

*/
extern AE_API int AE_import_named_ref(
    tag_t         dataset,            /**< (I) The target dataset for which a named reference is added to. */
    const char*   reference_name,     /**< (I) Name of the reference used for associating the file and dataset. */
    const char*   os_full_path_name,  /**< (I) Full path of the source file in the operating system. */
    const char*   new_file_name,      /**< (I) Name of the file for creating a new file in the volume. 
                                         <br/>It includes the file extension along with the file name.
                                         <br/>If the string is empty, the file name is autogenerated with the extension
                                         based on @p file_type.*/
    int           file_type_flag      /**< (I) Specifies the file type. 
                                         <br/>Valid values are #SS_TEXT (for text files) and #SS_BINARY (for binary files).
                                         <br/>If #SS_TEXT, the file is created with the @c .txt extension. 
                                         <br/>If #SS_BINARY, the file is created with the @c .bin extension. */
    );


/**
    Exports the ImanFile object that is associated with the dataset by named reference.
*/
extern AE_API int AE_export_named_ref(
    tag_t         datasetTag,       /**< (I) The target dataset on or through which the operation is being performed. */
    const char*   referenceName,    /**< (I) Name of the reference used for associating the file and dataset. */
    const char*   destPathName      /**< (I) The path to the destination to which the file is copied. */
    );

extern AE_API int AE_set_bounding_boxes(
    tag_t     dataset,                  /**< (I) The Dataset which defines boundingbox */
    tag_t     file,                     /**< (I) The imanFile */
    int       n_bounding_boxes,         /**< (I) Number of Bounding Boxes */
    const double* bounding_boxes        /**< (I) n_bounding_boxes The Bounding Boxes information */
    );

/**
    Sets the boundingBox information for given AbsOccData, Dataset and ImanFile.
*/
extern AE_API int AE_set_absOcc_bounding_boxes(
    tag_t     absolute_occurrence_data, /**< (I) The absOccData */
    tag_t     dataset,                  /**< (I) The dataset which defines boundingbox */
    tag_t     file,                     /**< (I) The imanFile */
    int       n_bounding_boxes,         /**< (I) Number of Bounding Boxes */
    const double* bounding_boxes        /**< (I) n_bounding_boxes The Bounding Boxes information */
    );

/**
   Retrieves the number of bounding boxes and bounding box information for a given Dataset.
*/
extern AE_API int AE_get_bounding_boxes(
    tag_t dataset,             /**< (I) The Dataset */
    int* n_bounding_boxes,     /**< (O) Number of Bounding Boxes */
    double** bounding_boxes    /**< (OF) n_bounding_boxes The Bounding Boxes information */
    );

/**
    Deletes the bounding box information for a given Dataset.
*/
extern AE_API int AE_delete_bounding_boxes(
    tag_t dataset             /**< (I) The Dataset */
    );


/**
    Prunes a list of Datasets named references from their Datasets

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>Potentially other errors
    </ul>
*/
extern AE_API int AE_prune_named_references(
    int           n_named_refs_to_be_pruned,   /**< (I)  Number of named references to be pruned */
    const tag_t*  named_refs_to_be_pruned,     /**< (I)  Named references to be pruned. */
    int*          n_nm_fail_to_be_pruned,      /**< (O)  Number of named references have failed to be pruned*/
    tag_t**       nm_fail_to_be_pruned,        /**< (OF) n_nm_fail_to_be_pruned The named references that fail to be pruned */
    int*          n_deleted_dataset,           /**< (O)  Number of Datasets that have been deleted */
    tag_t**       deleted_datasets             /**< (OF) n_deleted_dataset The Datasets that have been deleted */
    );

#ifdef __cplusplus
}
#endif

/** @} */

#include <ae/libae_undef.h>
#endif
