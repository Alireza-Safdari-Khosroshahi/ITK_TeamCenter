// Copyright 2020 Siemens Digital Industries Software
// ==================================================
// Copyright 2013.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2020 Siemens Digital Industries Software

/**
    @file

    Experimental interface definition for some functions in the POM module.
    Functions declared in this header file are supplied with no guarantee of 
    support or being present in subsequent Teamcenter releases.
*/


#ifndef POM_EXPERIMENTAL_H_INCLUDED
#define POM_EXPERIMENTAL_H_INCLUDED

#include <pom/pom/libpom_exports.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
    Replace all references (the typed and untyped reference attribute values) to an instance (inst) 
    with a replacement reference to another instance.

    The function returns:
    <ul>
    <li>#ITK_ok on success
    <li>#POM_insufficient_privilege, if the user performing this action is not properly privileged, i.e., is not a system administrator.
    <li>#POM_op_not_supported, if the reference to be replaced is a reference from a class.
    </ul>

    The following classes are excluded from having reference attribute values replaced:
    <ul>
    <li>CFM_configuration_object
    <li>IMAN_relation
    <li>ItemVersionFolder
    </ul>
*/

POMAPI int POM_replace_reference(
    tag_t  inst,        /**< (I) The instance whose references will be replaced. */
    tag_t  replacement  /**< (I) The reference replacing inst. */
    );


#ifdef __cplusplus
}
#endif

#include <pom/pom/libpom_undef.h>

#endif /* POM_EXPERIMENTAL_H_INCLUDED */
