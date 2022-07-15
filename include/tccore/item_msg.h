/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    ITEM specific Message definitions.

    Messages are general actions e.g. save, delete. When a Message is sent to a
    specific Type or instance of a Type, then the Method registered with that
    Message/Type combination will be executed. See ITK documentation on Methods
    for further details.

    Each message has a unique set of parameters, which are defined here. These
    parameters are passed in the varargs list of #METHOD_execute /
    #METHOD_execute_using, and received in the varargs list of
    action functions registered to perform methods.

    Generic system messages, e.g. save, delete are defined in tc_msg.h

/*  */

#ifndef ITEM_MSG_H
#define ITEM_MSG_H

#include <tccore/libtccore_exports.h>

/**
    @defgroup ITEM_MSG Messages
    @ingroup ITEM
    @{
*/

/**
    Create a new item with initial working revision.

    @param const char* item_id
    @param const char* item_name
    @param const char* type_name
    @param const char* rev_id
    @param tag_t*      new_item
    @param tag_t*      new_rev
    @param tag_t       item_master_form
    @param tag_t       item_rev_master_form
*/
#define ITEM_create_msg                 "ITEM_create"

/**
    Creates a new item based on an existing item revision.

    @param tag_t       old_item
    @param tag_t       old_rev
    @param const char* new_item_id
    @param const char* new_rev_id
    @param tag_t*      new_item
    @param tag_t*      new_rev
    @param const char* new_name
    @param const char* new_description
    @param tag_t       item_master_form
    @param tag_t       item_rev_master_form
*/
#define ITEM_create_from_rev_msg        "ITEM_create_from_rev"

/**
    Derives selected change management item_revs to a new change management item and item_rev.

    Process includes optional propagation of objects related to selected item_revs and relation    properties
    based on deep copy rules, propagation of object properties from selected item_revs based on business
    object constant CopyFromOriginal and relation of selected item_revs to the new item_rev.

    @param std::vector<Teamcenter::BulkInput*>   *deriveInput   A vector of data that contains reference information to the object to be dervied 
    @param Teamcenter::BulkData                  *bulkData      A data structure to store objects and other information relevant for set-based operation
*/
#define ITEM_operation_derive_msg  "cm0DeriveChange#std::vector<Teamcenter::BulkInput>,*,*$Teamcenter::BulkData,*"

/**
    Creates a new (empty) working revision for an existing item.

    @param tag_t       item
    @param const char* rev_id
    @param tag_t*      new_rev
    @param tag_t       item_rev_master_form
*/
#define ITEM_create_rev_msg             "ITEM_create_rev"

/**
    Produces a new working revision based on the given existing revision.
    
    If item_rev_master_form is passed as NULL then new form is not created. And it will only be created while 
    performing ITEM_perform_deepcopy. Hence if a post action requires to access Itemrevision Master form then
    it should be attached to ITEM_deep_copy instead of ITEM_copy_rev.
    
    @param tag_t       source_rev
    @param const char* rev_id
    @param tag_t*      new_rev
    @param tag_t       item_rev_master_form
*/
#define ITEM_copy_rev_msg               "ITEM_copy_rev"

/**
    This is for reading the Site Preference Rule set for DeepCopy operation and
    based on the copy rules set for each of the Item revision attachments,
    the copy operation will be carried out as

    <table>
    <tr><td>copy_as_object   </td><td>A brand new object will be created from the existing attachment object.
                                      The newly created object has distinct behavior than its parent.</td></tr>
    <tr><td>copy_as_reference</td><td>A symbolic link will be created between the attachment of
                                      the parent item revision and newly created Item revision.
                                      If the attachment of parent changes the newly created Item rev's
                                      corresponding attachment also changes</td></tr>
    <tr><td>no_copy          </td><td>The Attachment will be detached from the newly created ITem Revision</td></tr>
    </table>

    @param tag_t                    new_rev           The Tag of the newly created Item Revision
    @param char*                    operation         Whether the operation is Save As/Revise
    @param tag_t                    parent_rev        The Tag of the Item Revision over which Save As/Revise operation will be performed
    @param int                      copyCount         Number of deep copy rules set
    @param ITEM_deepcopy_info_t*    copyInfo          Deep Copy Rule Information
    @param int*                     count             Number of Datasets attached
    @param tag_t**                  copied_objects    The tags of the deep copied attachments
*/
#define ITEM_deep_copy_msg              "ITEM_deep_copy"

/**
    Produces a new baseline for the given existing revision.

    @param tag_t       base_rev_tag
    @param const char* baseline_rev_id
    @param const char* description
    @param const char* rel_proc_name
    @param const char* job_name
    @param const char* job_description
    @param logical     dryrun
    @param tag_t*      new_rev
    @param int*        deepCopiedObjectCount
    @param tag_t**     deepCopiedObjects
*/
#define ITEM_baseline_rev_msg           "ITEM_baseline_rev"

/**
    Produces a new Revision from an existing ItemRevision based on the preference Allow_copy_as_rev.
    If this preference is set to true or 1, this will copy the contents of one Item revision
    below an item to a newly created Item Revision below another existing item,
    else it will create a Brand new Item.

    @param tag_t       revTag               Tag of the Parent Item Revision
    @param const char* new_rev_id           The RevId of the Revision to be created.
    @param const char* name                 Name of the new revision
    @param const char* description          The description of new revision
    @param tag_t       item_tag             Tag of the existing Item
    @param tag_t*       new_rev             Tag of the Newly created Revision.
    @param tag_t       item_rev_master_form Tag of Newly created Item Revision Master form
*/
#define ITEM_copy_rev_to_existing_msg   "ITEM_copy_rev_to_existing"

/** @} */

#include <tccore/libtccore_undef.h>
#endif
