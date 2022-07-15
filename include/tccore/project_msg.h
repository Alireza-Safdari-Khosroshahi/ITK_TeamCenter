/*==============================================================================
                Copyright (c) 2020 Siemens PLM Software
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    PROJECT specific Message definitions.

    Messages are general actions e.g. save, delete. When a Message is sent to a
    specific Type or instance of a Type, then the Method registered with that
    Message/Type combination will be executed. See ITK documentation on Methods
    for further details.

    Each message has a unique set of parameters, which are defined here. These
    parameters are passed in the varargs list of #METHOD_execute /
    #METHOD_execute_using, and received in the varargs list of
    action functions registered to perform methods.

    Generic system messages, e.g. save, delete are defined in tc_msg.h.
*/

#ifndef PROJ_MSG_H
#define PROJ_MSG_H

/**
    @defgroup PROJ_MSG Messages
    @ingroup PROJECT
    @{
*/

/**
    Callback is invoked when a new project is created 

    @param const char*   project_id              The id of project
    @param const char*   project_name            The name of project
    @param const char*   project_desc            The description of project
    @param const logical program_security        Program security flag
    @param const char*   parent_project_id       Parent Program
    @param const int     allow_team_inheritance  Allow team inheritance
    @param tag_t*        new_project             Tag of newly created project
    
*/
#define PROJECT_create_msg    "PROJECT_create"

/** @} */

#endif
