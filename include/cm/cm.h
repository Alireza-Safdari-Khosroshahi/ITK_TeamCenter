/*=======================================================================================

                             Copyright (c) 2007 UGS Corporation
                             Unpublished - All rights reserved

=========================================================================================

File description:

    Filename: cm.h
    Module  : Change Management (cm)
    Description:

       This file contains declaration of ITK functions corresponding to Change Managment,
       BidPackage classes for Change Management Module.


=========================================================================================
   Date                   Name                    Description of Change
   05-Mar-2008    Yared Estifanos     Initial Version

$HISTORY$
=======================================================================================*/

#ifndef CM_H
#define CM_H


#include <tc/tc_startup.h>
#include <cm/cm_errors.h>
#include <cm/libcm_exports.h>

/**
    @defgroup CM Change Management
    @ingroup TC

    Tool to help user Problem Reports, Change Requests and Change Noticess to manage change of objects through review and approval process.
    @{
*/

/** 
     Enumeration for identifying add or remove operation
*/
typedef enum AddType{ ADD = 0,  REMOVE }AddType_t;

/**
    Structure for Update input relationship data.
*/
typedef struct RelationshipDataList
{
    tag_t **businessObjects;                   /**<  The array of tags for which relationship is to be updated or created  */
    int busObjCount;                           /**<  The count of business items  */
    char* relTypeName;                         /**<  The relationship type name - this can be blank in which case we will determin what the type should be */
    AddType_t addType;                         /**<   Indicates if you are adding or removing a relationship */
}RelationshipDataList_lst;

/**
    Structure for Update input attribute name value pair.
*/
typedef struct AttributeNameValueList
{
    char *       propertyName;                 /**<  The name of the property to be updated  */
    char        **newValues;                   /**<  The new values for the property  */
    int          valueCount;                   /**<  The new values count 1 if it is non-array  */
}AttributeNameValueList_lst;

/**
   Structure for tracking the BomChanges
*/

typedef enum CM_bom_change_type_e{
    CMBOM_unknown = 0,             /**< BOM change of other type. */
    CMBOM_Add,                     /**< BOM change of Add type. */
    CMBOM_Cancel,                  /**< BOM change of Cancel type. */
    CMBOM_Quantity_Change,         /**< BOM Quantity change type. */
    CMBOM_Move,                    /**< BOM change of type Move. */
    CMBOM_Reshape,                 /**< BOM change of Reshape type. */
    CMBOM_Note_Change,             /**< BOM change of Note type. */
    CMBOM_Variant_Change,          /**< BOM variant change type. */
    CMLBOM_Add,                    /**< LBOM change of Add type. */
    CMLBOM_Cancel,                 /**< LBOM change of Cancel type. */
    CMLBOM_Quantity_Change,        /**< LBOM change of Quantity type. */ 
    CMBOM_Property_Change           /**< BOM change of Property Change type. */ 
} CM_bom_change_type_t;

/**
    Structure for Note Changes tracking
*/
typedef struct CM_note_change_info_s{
    tag_t      notechangeTag;            /**< The Note Change. */
    tag_t      chngRevtag;               /**< The Change Revision. */
    tag_t      solBvrTag;                /**< The Solution BVR. */
    tag_t      impBvrTag;                /**< The Impacted BVR. */
    int        noOfNoteChanged;          /**< Number of Notes changed. */
    int        noOfFormFlds;             /**< Number of Form fields. */
    char**     noteTypeNames;            /**< Array of note type names. */
    char**     beforeValues;             /**< Array of note values before change. */
    char**     afterValues;              /**< Array of note values after change. */
    char**     formFldNames;             /**< Names from the Form Field name-value pair. */
    char**     formFldValues;            /**< Values from the Form Field name-value pair. */ 
} CM_note_change_info_t;

#ifdef __cplusplus
    extern "C"{
#endif

/**
   Retrieves the problem assembly of a given impacted assembly with the context
   of the given change Revision. 
   <br/>The relationship is obtained using the internal affected to
   problem relationship between the corresponding impacted Revision and its related problem revision.
*/
extern CM_API int CM_get_prev_bvr( tag_t   change_revision,  /**< (I) The Change Revision. */
                                   tag_t   bvr,              /**< (I) The impacted assembly. */
                                   tag_t*  prev_bvr          /**< (O) The problem assembly. */
                                  );



/**
   Retrieves all BomChange objects of a specified type for the
   specified affected assembly and Change Revision combination.
   <br/>The output also includes all derived BomChange objects.
    
   @note Only three types are currently supported: #CMLBOM_Add, #CMLBOM_Cancel and #CMLBOM_Quantity_Change.
*/
extern CM_API int CM_get_bomedits ( tag_t                  change_revision,  /**< (I) Change Revision. */
                                    tag_t                  affected_bvr,     /**< (I) Affected assembly. */
                                    CM_bom_change_type_t   bomch_type,       /**< (I) Type of BOMEdit requested */
                                    int*                   n_of_bomch,       /**< (O) The number of BOMEdit objects found */
                                    tag_t**                bomch             /**< (OF) n_of_bomch The array of BOMEdit tags found */
                                  );


/**
   Saves a BOMEdit.
*/
extern CM_API int CM_save_BOMEdits( tag_t   change_revision,     /**< (I) The Change object. */
                                    tag_t   bom_window ,         /**< (I) The solution BOMWindow. */
                                    tag_t   problem_bom_window,  /**< (I) The impacted BOMWindow. */
                                    int*    n_bom_tags,          /**< (O) Number of BOMEdits.  */
                                    tag_t** bom_changes          /**< (OF) n_bom_tags The BOMEdits. */
                                   );

/**
   Retrieves the Occurrence object associated to a given BOMEdit object.
*/
extern CM_API int CM_get_occurrence_of_bomedit( tag_t  bomch,      /**< (I) The BomEdit object */
                                                tag_t* occurrence  /**< (O) Occurrence. */
    );
                                               


/**
    Retrieves the Note Change details for a given Note Change object.
    <br/>Information includes the list of changed note types, their values in impacted and solution assembly.
    Form field related members of the output structure wouldn�t be filled as output of this ITK method.
    They are reserved for future use.

    <b>Restrictions:</b>
    If the input BOMEdit object is not a solution side BOMEdit, this ITK will return an error code.
*/
extern CM_API int CM_get_note_change_details(
                                             tag_t                   note_change,         /**< (I) Note Change. */
                                             CM_note_change_info_t*  note_change_details  /**< (O) The Note Change details. */
                                             );


/**
    Frees all the memory associated to an instance of the #CM_note_change_info_t structure
*/
extern CM_API void CM_free_notechange_info_struct( CM_note_change_info_t  info    /**< (I) Note Change Info to be freed */
                                                  );

/**
   Retrieves all the relations to propagate from source objects to derived objects.
   
   <br/>The propagation is based on the source object type and the value of the preference "CM_automate_derive_propagation" for a derive change operation.
   <br/>If the value of the preference is true, this ITK will return all the relations specified as the value of a preference "CM_&lt;SourceObjectType&gt;_Relations_To_Propagate",
   where &lt;SourceObjectType&gt; is the type name of the object pointed by the parameter @p source_object_tag.
   
   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#PF_NOTFOUND if the preference "CM_automate_derive_propagation" is not set.
   </ul>
   
*/
extern CM_API int CM_get_relations_to_propagate( tag_t source_object,             /**< (I) The source object */
                                                 int * n_relations,               /**< (O) Number of relations to propagate */
                                                 char ***relations_to_propagate,  /**< (OF) n_relations Array of relation names.
                                                                                     <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container.
                                                                                     <br/>This will also deallocate the memory for its elements. */
                                                 logical *propagation_enabled     /**< (O) Set to true if propagation is enabled by preference. */
);

/**
    Retrieves all solution revisions of a given ChangeItemRevision.
    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#TYPE_invalid_type_name if solution type is not found.
    </ul>
*/
extern CM_API int CM_ask_solution_items_for_change_item_revision( tag_t change_revision, /**< (I)  The ChangeItemRevision. */
                                                                  int   *n_items,        /**< (O)  The number of solution items. */
                                                                  tag_t **items          /**< (OF) n_items The array of solution items. */
    );

/**
    Retrieves all impacted revisions of the given ChangeItemRevision
    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#TYPE_invalid_type_name if impacted type is not found.
    </ul>
*/
extern CM_API int CM_ask_impacted_items_for_change_item_revision( tag_t change_revision,  /**< (I)  The ChangeItemRevision.*/
                                                                  int   *n_items,         /**< (O)  The number of impacted items. */
                                                                  tag_t **items           /**< (OF) n_items The array of impacted items. */
    );

/**
   Creates a CMSolutionToImpacted relation between all the solution
   Items and all the impacted Items for a ChangeNoticeRevision and then assign
   a group ID to them. 
   <br/>To determine the group ID, the CMSolutionToImpacted relations
   are traversed for ChangeNoticeRevision and then find the largest group ID
   number present for this ChangeNoticeRevision in context. The new group ID
   is the next incremented number. This group number is assigned to all the CMSolutionToImpacted
   relations created for the input data.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#CM_solution_or_impacted_invalid if no tag or an invalid tag is provided for @p solution_items or @p impacted_items.
   <li>#CM_solution_items_attached_to_multiple_ecns if not all solution Items are already attached to the same Change Notice Revision.
   <li>#CM_impacted_items_attached_to_multiple_ecns if not all the impacted Items are attached to the same Change Notice Revision.
   <li>#CM_no_ecn_for_impacted_items if some impacted Items do not contain any attached Change Notice Revision.
   <li>#CM_no_ecn_for_solution_items if some solution Items do not contain any attached Change Notice Revision.
   </ul>
*/
extern CM_API int CM_create_change_lineage( int n_solution_items,             /**< (I) Number of solution Item Revisions.   */
                                            const tag_t *solution_items,      /**< (I) n_solution_items Solution Item Revisions.             */
                                            int n_impacted_items,             /**< (I) Number of impacted Item Revisions.   */
                                            const tag_t *impacted_items,      /**< (I) n_impacted_items Impacted Item Revisions.             */
                                            int   *n_relations,               /**< (O) Number of relations created.         */
                                            tag_t **relations                 /**< (OF) n_relations The created relations.    */
);

/**
   Deletes the change lineage by deleting the relations between a group
   of solution items and their respective impacted items that are associated with the
   lineage group.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#CM_invalid_change_object if #NULLTAG or an invalid Change Notice Revision tag is provided.
   <li>#CM_no_lineage_group if none of the input objects have the lineage.
   <li>#CM_not_solution_or_impacted if any input objects is not a solution or impacted item for the Change Notice Revision in context.
   </ul>
*/
extern CM_API int CM_delete_change_lineage( const tag_t change_notice_revision,         /**< (I) The Change Notice Revision.                        */
                                            int n_objects,                              /**< (I) Number of input Item Revisions.                    */
                                            const tag_t *objects                        /**< (I) n_objects Solution or impacted Item Revisions.     */
    );


/**
    Retrieves the concurrent and preceding Change Notice Revisions for a given Change Notice Revision.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CM_invalid_change_object if #NULLTAG or an invalid Change Notice Revision tag is provided.    
    </ul>
*/
extern CM_API int CM_get_preceding_and_concurrent_ecns ( const tag_t source_ecn,                     /**< (I)  The Change Notice Revision. */
                                                         const logical return_concurrent_relations,  /**< (I)  Determines if concurrent relations needs to be retrieved. */
                                                         const logical return_preceding_relations,   /**< (I)  Determines if preceding relations needs to be retrieved. */
                                                         int   *n_concurrent_ecns,                   /**< (O)  Number of concurrent Change Notice Revisions. */
                                                         tag_t **concurrent_ecns,                    /**< (OF) n_concurrent_ecns Concurrent Change Notice Revisions. */
                                                         int   *n_preceding_ecns,                    /**< (O)  Number of preceding Change Notice Revisions. */
                                                         tag_t  **preceding_ecns                     /**< (OF) n_preceding_ecns Preceding Change Notice Revisions. */
);

/** @name Derive Change
@{ */

/**
   Derives the selected Change Item Revisions. It will also create a new Change Item and Change Item Revision.
   Relates the new Change Item Revision to the derivied Change Item revision using the implements relation.
   <br\>Propagates existing relations and relation properties from the selected objects based on deep copy rules
   and the user selection in the derive dialog. 
   <br\>Propagates the existing object properties from the selected objects based on copy from the original Business    
   Object constant.
   <br\>If @p submit_to_workflow is true it will submit to workflow.
   <br\>If @p workflow_template_name is NULL or invalid the new object will be submitted to the default workflow.
   
   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#CM_invalid_change_object if @p derive_input is #NULLTAG or is an invalid Change Item Revision.
   </ul>
*/
extern CM_API int CM_derive_change(const tag_t derive_input,               /**< (I) The derived input data.                                                                                                                 */
                                   const int n_deep_copy_data_objs,        /**< (I) Number of deep dopy data objects.                                                                                                       */
                                   const tag_t *deep_copy_data_objs,       /**< (I) n_deep_copy_data_objs of the deep copy data objects.                                                                                    */
                                   const char* workflow_template_name,     /**< (I) The name of the workflow template to submit the new object. If NULL or invalid the new object will be submitted to the default workflow.*/
                                   const logical propagate_relation,       /**< (I) Indicates if relations should be propagated from the selected objects to the new object.                                                */
                                   const logical submit_to_workflow,       /**< (I) Indicates if the new object should be submitted to the default workflow.                                                                */
                                   tag_t *derived_change_item,             /**< (O) The new derived Change Item.                                                                                                            */
                                   tag_t *derived_change_item_revision     /**< (O) The new derived Change Item Revsion.                                                                                                    */
);

/** @} */

#ifdef __cplusplus
}
#endif

/** @} */

#include <cm/libcm_undef.h>
#endif
