#ifndef PS_MSG_H
#define PS_MSG_H

/*
   @<COPYRIGHT_START>@
   ===============================================
   Copyright 2006 UGS Corp. All Rights Reserved.
   ===============================================
   @<COPYRIGHT_END>@
*/

/**
    @file

    Module:    PS
    Product Structure specific Message definitions.

    Messages are general actions e.g. save, delete. When a Message is sent to a
    specific Type or instance of a Type, then the Method registered with that
    Message/Type combination will be executed. See ITK documentation on Methods
    for further details.

    Each message has a unique set of parameters, which are defined here. These parameters are
    passed in the varargs list of #METHOD_execute / #METHOD_execute_using, and received in the varargs
    list of action functions registered to perform methods.

    Generic system messages, e.g. save, delete are defined in tc_msg.h.
    Messages specific to a particular module are defined in a header belonging
    to that module, e.g. #ITEM_create_msg is defined in item_msg.h.
*/

/**
    @defgroup PS_MSG Messages
    @ingroup PS
    @{
*/

/**
    This message is dispatched when new PS occurrences (Product Structure Occurrences) are created for a BVR (BOMViewRevision),
    e.g. when the ITK #PS_create_occurrences is called (with which this message shares its parameter list).

    @param[in]  tag_t parent_bvr         Tag to parent BVR
    @param[in]  tag_t child_item         Tag for either the child item or the source occurrence thread that is copied from one parent to another
    @param[in]  tag_t child_bom_view     Tag for child BOM view or for occurrence thread (which must be parent BVR for the source occurrence mentioned in the "child_item" parameter)
    @param[in]  int n_occurrences        Number of occurrences
    @param[out] tag_t** occ_thread_tags  Tag to occurrence thread.
    @param[in]  tag_t occ_create_input   Tag of the PSOccurrence CreateInput object.
*/
#define PS_bvr_create_occs_msg "PS_bvr_create_occs"

/**
    This message allows a Publish Link to be created from a source object to a target object.
    Publish Links are used to connect absolute occurrences.

    @param[in]  char* name          Name of the Publish Link to be created
    @param[in]  char* type          Type of the Publish Link
    @param[in]  int dataFlags       Integer representing which data is being published. It can be either Transform (0x1) or Shape (0x2)
    @param[in]  tag_t* source       MEAppearancePathNode as a source of Publish Link
    @param[in]  int target_count    Number of target MEAppearancePathNode
    @param[in]  tag_t* target       List of target MEAppearancePathNode(s)
    @param[out] tag_t* publishlink  New Publish Link object
*/
#define PUBLISHLINK_create_msg "PS_create_publishlink"

/**
    This message supports creating an occurrence based on the specific Occurrence Type.

    @param[in]  tag_t parent_bvr          Tag to parent BVR (BOM View Revision)
    @param[in]  tag_t child_item          Tag for either the child item or the source occurrence thread that is copied from one parent to another
    @param[in]  tag_t child_bom_view      Tag for child BOM view or for occurrence thread (which must be parent BVR for the source occurrence mentioned in the "child_item" parameter)
    @param[in]  int n_occurrences         Number of occurrences
    @param[out] tag_t** occ_thread_tags   Tag to occurrence thread.
    @param[in]  tag_t occ_type            Tag to occurrence type.
    @param[in]  tag_t occ_create_input    Tag of the PSOccurrence CreateInput object.
*/
#define PS_bvr_create_occs_with_occ_type_msg "PS_bvr_create_occs_with_occ_type"

/**
    This message is dispatched when an occurrence is being imported in GMS (Global Multisite)

    @param[in]  tag_t parent_bvr          Tag to parent BVR (BOM View Revision)
    @param[in]  tag_t child_item          Tag to child item
    @param[in]  tag_t child_bom_view      Tag to childBomview
    @param[in]  tag_t existing_occ_thread Tag to existing occurrence thread.
    @param[out] tag_t* occurrence         Tag to imported occurrence.
*/
#define PS_bvr_import_new_occ_msg "PS_bvr_import_new_occ"

/**
   This message supports copying data (transform or shape) from source BOM Line to target BOM Line(s).
   If Publish Link exists for the given source BOM Lines, all input target BOM Line(s) should belong to that Publish Link.
   If none exist, the new object is created.

    @param[in]  tag_t source_bl_tag         BOM Line as source of the Publish Link
    @param[in]  int n_targets               Number of target BOM Line(s)
    @param[in]  tag_t* target_bl_tags       List of target BOM Line(s)
    @param[in]  char* publishLinkName       Name of the Publish Link (used while creating a new Publish Link)
    @param[in]  char* publishLinkTypeName   Type of the Publish Link
    @param[in]  int dataFlags               Integer representing which data is being published. It can be either Transform (0x1) or Shape (0x2)
    @param[out] tag_t* publishlink          New Publish Link object
*/
#define PUBLISHLINK_publish_data_msg "PS_publishlink_publish_data"

/**
    Generates a unique ID, which is to be used as a persistent ID.
    A persistent ID is a key that uniquely identifies the boolean content of a Variant Expression. The same identifier will be assigned to logically equivalent expressions.
    The generated ID is consumed while authoring expression on Line of Usages.

    @param[out] generated persistent id
*/
#define BMF_FND_new_persistent_id_msg  "BMF_FND_new_persistent_id"

/** @} */

#endif /* PS_MSG_H */
