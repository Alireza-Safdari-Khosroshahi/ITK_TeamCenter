/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    OBJIO_SM specific Message definitions.

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

#ifndef OBJIO_SM_MSG_H
#define OBJIO_SM_MSG_H

/**
    @defgroup OBJIO_SM_MSG Messages
    @ingroup OBJIO_SM
    @{
*/

/**
    Create a new storage medium.

    @param const char* name
    @param const char* device
    @param const char* type
    @param tag_t*      new_media
*/
#define OBJIO_SM_create_msg           "OBJIO_SM_create"

/** @} */

#endif
