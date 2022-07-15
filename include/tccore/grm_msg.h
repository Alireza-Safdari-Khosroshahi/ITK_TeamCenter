/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    GRM specific Message definitions.

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

#ifndef GRM_MSG_H
#define GRM_MSG_H

/**
    @defgroup GRM_MSG Messages
    @ingroup GRM
    @{
*/

/**
    Create a new GRM relation of the given type,
    linking the specified primary and secondary objects.

    @param tag_t  primary_object
    @param tag_t  secondary_object
    @param tag_t  relation_type
    @param tag_t  user_data
    @param tag_t* new_relation
*/
#define GRM_create_msg           "GRM_create"

/**
    Copy the old GRM relation to a new relation of the given type,
    linking the specified primary and secondary objects.

    @param tag_t  tag()
    @param tag_t  primary_object
    @param tag_t  secondary_object
    @param tag_t  relation_type
    @param tag_t  user_data
    @param tag_t* new_relation
*/
#define GRM_copy_msg           "GRM_copy"

/** @} */

#endif
