/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    ME specific Message definitions.

    Messages are general actions e.g. save, delete. When a Message is sent to a
    specific Type or instance of a Type, then the Method registered with that
    Message/Type combination will be executed. See ITK documentation on Methods
    for further details.

    Each message has a unique set of parameters, which are defined here. These
    parameters are passed in the varargs list of
    #METHOD_execute / #METHOD_execute_using, and received in the varargs list of
    action functions registered to perform methods.

    Generic system messages, e.g. save, delete are defined in tc_msg.h.
*/

/*  */

#ifndef ME_MSG_H
#define ME_MSG_H

/**
    @defgroup ME_MSG Messages
    @ingroup ME
    @{
*/

/**
    Create a new process operation object.

    @param const char* poName
    @param const char* poDesc
    @param tag_t*      newpo
*/
#define ME_create_po_msg         "ME_create_processoperation"

/**
    Create a new message for process cloning
    @param tag_t parent_tag: object to be cloned 
    @param tag_t parent_line_tag: bomline tag for the object to be cloned 
    @param tag_t new_object_tag: cloned object
    @param const char* name: name of the new object 
    @param const char* desc: desc of the new object 
    @param const char* id: id of the new object 
    @param const char* revid: revid of the new object
*/
#define ME_clone_template_action_msg         "ME_clone_template_action"



/** @} */

#endif
