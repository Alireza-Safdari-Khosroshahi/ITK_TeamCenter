/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Messages are general actions e.g. save, delete.
    When a Message is sent to a specific Type or instance of a Type,
    then the Method registered with that Message/Type combination will be executed.
    See ITK documentation on Methods for further details.

    Each message has a unique set of parameters, which are defined here. 
    These parameters are passed in the varargs list of #METHOD_execute / #METHOD_execute_using,
    and received in the varargs list of action functions registered to perform methods.

    Generic system messages, e.g. save, delete are defined in tc_msg.h.
*/

/*  */

#ifndef TCTYPE_MSG_H
#define TCTYPE_MSG_H

#include <common/tc_deprecation_macros.h>
#include <tccore/libtccore_exports.h>

/**
    @defgroup TCTYPE_MSG Type Specific Messages
    @ingroup TCTYPE
    @{
*/

/**
    @deprecated #TCTYPE_create_msg deprecated in Teamcenter 8.3.
    <br/>Please create the Teamcenter Types from BMIDE.

    Create a new Teamcenter Type.

    @param const char* type_name
    @param const char* class_name
    @param tag_t*      new_type
*/
#define TCTYPE_create_msg             "IMANTYPE_create"
TC_DEPRECATED_PREPROCESSOR( "8.3", TCTYPE_create_msg, "" )

/**

    @deprecated #TCTYPE_init_user_props_msg deprecated in Teamcenter 8.3.
    <br/>Please perform the user-defined initialization for properties of Teamcenter Types from BMIDE.

    Performs user-defined initialization of properties on a type.
    Since properties on a type are generated at run-time, 
    the definition of the properties can be done programmatically in 
    a method registered against this message name.
    Examples of what might be done are:
    <ul>
    <li>Add a property
    <li>Register ask/set/init methods for a property
    <li>Remove a property
    <li>Change the definition of a property 
    </ul>
    Registration of methods for this message should be done through BMIDE.

    See smp_user_props.c for sample code.

    <b>type_tag</b> The tag for the type.
*/
#define TCTYPE_init_user_props_msg    "IMANTYPE_init_user_props"
TC_DEPRECATED_PREPROCESSOR( "8.3", TCTYPE_init_user_props_msg, "" )

/** 

    @deprecated #TCTYPE_createprops_msg deprecated in Teamcenter 8.3.
    <br/>Please create the properties for Teamcenter Types from BMIDE.
*/
#define TCTYPE_createprops_msg        "IMANTYPE_create_props"
TC_DEPRECATED_PREPROCESSOR( "8.3", TCTYPE_createprops_msg, "" )

/** 

    @deprecated #TCTYPE_viewerprops_msg deprecated in Teamcenter 8.3.
    <br/>Please view the properties for Teamcenter Types from BMIDE.
*/
#define TCTYPE_viewerprops_msg        "IMANTYPE_viewer_props"
TC_DEPRECATED_PREPROCESSOR( "8.3", TCTYPE_viewerprops_msg, "" )

/** @} */

#include <tccore/libtccore_undef.h>
#endif
