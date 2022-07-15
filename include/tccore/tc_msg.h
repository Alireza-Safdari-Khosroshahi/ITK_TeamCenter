/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Teamcenter generic Message definitions.

    Messages are general actions e.g. save, delete. When a Message is sent to a
    specific Type or instance of a Type, then the Method registered with that
    Message/Type combination will be executed. See ITK documentation on Methods
    for further details.

    Each message has a unique set of parameters, which are defined here. These
    parameters are passed in the varargs list of #METHOD_execute /
    #METHOD_execute_using, and received in the varargs list of
    action functions registered to perform methods.

    Messages specific to a particular module are defined in a header belonging
    to that module, e.g. #ITEM_create_msg is defined in item_msg.h.
*/

/*  */

#ifndef TC_MSG_H
#define TC_MSG_H

#include <tccore/libtccore_exports.h>

/**
    @defgroup TC_MSG Teamcenter Messages
    @ingroup TC
    @{
*/

/**
    Removes the given object from the database.

    @param tag_t object
*/
#define TC_delete_msg     "IMAN_delete"

/**
    @param tag_t manager
    @param tag_t object
*/
#define TC_export_msg     "IMAN_export"

/**
    @param tag_t manager
    @param tag_t object
*/
#define TC_import_msg     "IMAN_import"

/**
    Reloads (or loads if not previously loaded) the given object from the database.
    If lock is true, the object will be locked for modification, if false the object is loaded no-lock.

    @param tag_t   object
    @param logical lock
*/
#define TC_refresh_msg    "IMAN_refresh"

/**
    Saves the given object to the database.
    <br/>The "isNew" flag is not implemented in the case of the "Save As" operation.

    @param tag_t    object
    @param logical  isNew
*/
#define TC_save_msg       "IMAN_save"

/**
     Assign single object to a project

     @param tag_t   item_tag
     @param tag_t   proj_tag
     @param int    *errorCode
     @param logical alwaysPropagate
     @param TagList projObjList
     @param TagList wsoObjList
*/
#define TC_assign_primary_obj_to_project_msg "TC_assign_primary_obj_to_project"

/**
     Remove single object from a project

     @param tag_t   item_tag
     @param tag_t   proj_tag
     @param int    *errorCode
     @param TagList projObjList
     @param TagList wsoObjList
*/
#define TC_remove_primary_obj_from_project_msg "TC_remove_primary_obj_from_project"
/** @} */

#include <tccore/libtccore_undef.h>
#endif
