/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Workspace Object specific Message definitions.

    <b>IMPORTANT NOTE:</b> For the time being the only message defined here is copy, and the code for
    allowing customization by Methods of this message is currently only supported for Types of the
    Form class. This was specifically introduced for support of the upcoming IMAN-MRP Generic
    Interface Toolkit. As and when required more message/type combinations will be supported, at
    such time that full coverage of basic Workspace Object messages is available use of this
    facility will be more widely publicized. In the meantime however please note that the
    message/type combinations as documented in this header file are a fully supported part of the
    Teamcenter Engineering public ITK.

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

/*  */

#ifndef WSO_MSG_H
#define WSO_MSG_H

/**
    @defgroup WSO_MSG Messages
    @ingroup WSO
    @{
*/

/**
    Create a new WSO based on the given existing wso, as invoked by ITK function #WSOM_copy.

    @param tag_t       wso
    @param const char* new_name
    @param tag_t*      new_wso

    @note Customization of response to this message by Methods is currently only supported for
    Types of the Form class. Please refer to the IMPORTANT NOTE in the header of this file.
*/
#define WSO_copy_msg "WSO_copy"

#define WSO_create_msg "WSO_create"

/** @} */

#endif
