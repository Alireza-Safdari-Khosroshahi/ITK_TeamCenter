/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*  */

#ifndef GDE_H
#define GDE_H

#include <unidefs.h>
#include <tccoreext/libtccoreext_exports.h>

#ifdef __cplusplus
    extern "C"{
#endif

/**
    @defgroup GDE General Design Element (GDE)

    This module defines the required ITK interface for GeneralDesignElement related operations.

    @{
*/

/**
    This function will return the GDEBomViewRevision of the given GeneralDesignElement Object
*/
extern TCCOREEXT_API int GDE_ask_gde_bvr (
    tag_t                   gde_tag,        /**< (I) Tag of the GeneralDesignElement */
    tag_t*                  gde_bvr_tag     /**< (O) Tag of the GDEbvr */
    );

/**
    This function will return the parent Item Revision of a given GDEBomViewRevision.
*/
extern TCCOREEXT_API int GDE_ask_item_rev_of_bvr (
    tag_t                   gde_bvr_tag,    /**< (I) Tag of the GDEBvr */
    tag_t*                  item_rev_tag    /**< (O) Tag of the Item Revision */
    );

/**
    This function will return the child GDE Object of a given GDEOccurrence.
*/
extern TCCOREEXT_API int GDE_ask_occurrence_child (
    tag_t                   gde_occ_tag,    /**< (I) Tag  of the GDEOccurrence */
    tag_t*                  gde_child_tag   /**< (O) Tag of the child GeneralDesignElement referenced by the GDEOccurrence */
    );

/**
    This function returns the Occurrence name of a given GDEOccurrence.
*/
extern TCCOREEXT_API int GDE_ask_occurrence_name (
    tag_t                   gde_occ_tag,    /**< (I) Tag of the GDEOccurrence */
    char**                  gde_occ_name    /**< (OF) Occurrence name of the given GDEOccurrence */
    );

/**
    This function will return the Occurrence note text of a given GDEOccurrence.
*/
extern TCCOREEXT_API int GDE_ask_occurrence_note_text (
    tag_t                   gde_occ_tag,    /**< (I) Tag of the GDEOccurrence */
    tag_t                   note_type,      /**< (I) Tag of the Note Type */
    char**                  note_text       /**< (OF) Returns the text of the specified note */
    );

/**
    This function will return the Occurrence type of a given GDEOccurrence.:
*/
extern TCCOREEXT_API int GDE_ask_occurrence_type (
    tag_t                   gde_occ_tag,    /**< (I) Tag of the GDEOccurrence */
    tag_t*                  gde_occ_type    /**< (O) Tag of the Occurrence Type */
    );

/**
    This function will return  the view type of a given GDEBomViewRevision
*/
extern TCCOREEXT_API int GDE_ask_view_type (
    tag_t                   gde_bvr_tag,    /**< (I) Tag of the GDEBvr */
    tag_t*                  view_type_tag   /**< (O) Tag of the View Type */
    );

/**
    This function will create a GeneralDesignElement.
*/
extern TCCOREEXT_API int GDE_create(
    const char*             gde_name,       /**< (I) Name of the GeneralDesignElement */
    const char*             description,    /**< (I) Description of the GeneralDesignElement */
    const char*             gde_type,       /**< (I) Type of the GeneralDesignElement to be created */
    tag_t*                  gde_obj_tag     /**< (O) Tag of the newly created GeneralDesignElement */
);

/**
    This function will create a GDEBOMViewRevison

    <b>Restrictions:</b>

    There can be only one GDEBOMViewRevison for a given view type.
    If the GDEBOMViewRevison already exits for the given view type,
    this call returns the tag of the existing GDEBOMViewRevison.
*/
extern TCCOREEXT_API int GDE_create_gde_bvr(
    tag_t                   gde_tag,        /**< (I) Tag  of the GeneralDesignElement */
    tag_t                   view_type,      /**< (I) Tag of the View Type */
    tag_t*                  gde_bvr_tag     /**< (O) Tag of the newly created or existing GDEBvr */
);

/**
    This function will create a GDEOccurrence.
*/
extern TCCOREEXT_API int GDE_create_occurrence(
    tag_t                   gde_bvr_tag,        /**< (I) Tag of the GDEBvr */
    tag_t                   child_gde_tag,      /**< (I) Tag of the GeneralDesignElement for which GDEOccurrence is to be created */
    tag_t                   child_view_type,    /**< (I) Tag of the view type */
    tag_t                   occurrence_type,    /**< (I) Tag of the GDEOccurrence Type */
    double                  quantity,           /**< (I) Quantity to be set for the newly created GDEOccurrence */
    int                     instance_no,        /**< (I) Instance number to be set for the newly created GDEOccurrence */
    tag_t*                  gde_occ_tag         /**< (O) Tag of the newly created GDEOccurrence */
);


/**
   Deletes the Occurrence notes for a given GDEOccurrence.
*/
extern TCCOREEXT_API int GDE_delete_occurrence_note (
    tag_t                   gde_occ_tag,    /**< (I) Tag of the GDEOccurrence */
    tag_t                   note_type       /**< (I) Tag of the textual note to be deleted */
    );

/**
    This function will list all the Occurrence notes for a given GDEOccurrence
*/
extern TCCOREEXT_API int GDE_list_occurrence_notes (
    tag_t                   gde_occ_tag,    /**< (I) Tag of the GDEOccurrence */
    int*                    notes_count,    /**< (O) Number of notes defined for the given GDEOccurrence */
    tag_t**                 note_types      /**< (OF) notes_count Tags of the note types defined for the given GDEOccurrence */
    );

/**
    This function is used to list the occurrences of a given GDEBomViewRevision
*/
extern TCCOREEXT_API int GDE_list_occurrences_of_bvr (
    tag_t                   gde_bvr_tag,    /**< (I) Tag of the GDEBvr */
    int*                    occ_count,      /**< (O) Number of GDEOccurrences for the given GDEBvr */
    tag_t**                 gde_occs        /**< (OF) occ_count Tags of the GDEOccurrences */
    );

/**
    This function will remove the specified GDEOccurrences from the given GDEbvr.
*/
extern TCCOREEXT_API int GDE_remove_occurrences (
    tag_t                   gde_bvr_tag,    /**< (I) Tag of the GDEBvr */
    int                     occ_count,      /**< (I) Number of the GDEOccurrences to be removed */
    tag_t*                  gde_occs        /**< (I) Tags of the GDEOccurrences to be removed */
    );

/**
    This function will set the Occurrence child of GDE occurrence.
*/
extern TCCOREEXT_API int GDE_set_occurrence_child (
    tag_t                   gde_occ_tag,    /**< (I) Tag of the GDEOccurrence */
    tag_t                   gde_child_tag   /**< (I) Tag of the child GeneralDesignElement referenced by the GDEOccurrence */
    );

/**
    This function will set the Occurrence name of a given GDEOccurrence.
*/
extern TCCOREEXT_API int GDE_set_occurrence_name (
    tag_t                   gde_occ_tag,    /**< (I) Tag of the GDEOccurrence */
    const char*             gde_occ_name    /**< (I) Name to be set for the given GDEOccurrence */
    );

/**
    This function will set the Occurrence Note Text for a given GDEOccurrence
*/
extern TCCOREEXT_API int GDE_set_occurrence_note_text (
    tag_t                   gde_occ_tag,    /**< (I) Tag of the GDEOccurrence */
    tag_t                   note_type,      /**< (I) Tag of the Note Type for which note text is to be set */
    const char*             note_text       /**< (I) Note text to be set for the note type */
    );

/**
    This function will set the Occurrence type for a given GDEOccurrence.
*/
extern TCCOREEXT_API int GDE_set_occurrence_type (
    tag_t                   gde_occ_tag,    /**< (I) Tag of the GDEOccurrence */
    tag_t                   gde_occ_type    /**< (I) Tag of the Occurrence Type to be set for the given GDEOccurrence */
    );

/**
    This function will set the view type for a given GDEBomViewRevision.
*/
extern TCCOREEXT_API int GDE_set_view_type (
    tag_t                   gde_bvr_tag,    /**< (I) Tag of the GDEBvr */
    tag_t                   view_type_tag   /**< (I) Tag of the view type to be set for the GDEBvr */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <tccoreext/libtccoreext_undef.h>

#endif
