/*=============================================================================
           Copyright (c) 1994 Electronic Data Systems Corporation
                   Unpublished - All rights reserved

   THIS PROGRAM IS AN UNPUBLISHED WORK FULLY PROTECTED BY THE UNITED STATES
  COPYRIGHT LAWS AND IS CONSIDERED A TRADE SECRET BELONGING TO THE COPYRIGHT
                                   HOLDER.
===============================================================================
H  File description:

    File   : exportedproxylink_errors.h
    Module : iman
===============================================================================
Date         Name                    Description of Change
====         ====                    =====================
18-Nov-2003  Ziv Israeli             Created
02-Jan-2004  Ziv Israeli             EPL_more_than_one_instance
26-Jan-2004  Ziv Israeli             A fix
28-Oct-2004  Ziv Israeli             Checking in
$HISTORY$
=============================================================================*/

#ifndef EPL_ERRORS_H
#define EPL_ERRORS_H

#include <wproxy/libwproxy_exports.h>

/**

    Error Conditions involving Exported Proxy Links are listed below.

    */

/** Exported Proxy Links cannot be created, because an error is encountered during execution of one of the scenarios: Checking if a similar object already exists; Creating the object; Setting properties on the newly created object. Please check the Teamcenter syslog file for more information. */
#define EPL_no_create                          (EMH_EPL_error_base + 1)
/** Multiple Exported Proxy Links are found for the object with application GUID as "%1$" and exported object UID as "%2$". This is an error because only one object should exist for this combination. */
#define EPL_more_than_one_instance             (EMH_EPL_error_base + 2)
/** The Exported Proxy Link cannot be created from the object with application GUID as "%1$" and exported object UID as "%2$", because it is not of type Workspace Object. */
#define EPL_obj_not_wso                        (EMH_EPL_error_base + 3)
/** An Exported Proxy Link already exists for the object with application GUID as "%1$" and exported object UID as "%2$". */
#define EPL_obj_already_exists                 (EMH_EPL_error_base + 4)
/** Several Exported Proxy Links already exist for the object with application GUID as "%1$" and exported object UID as "%2$". */
#define EPL_objs_already_exist                 (EMH_EPL_error_base + 5)
/** An error has occurred while converting the UID of the object to be exported "%1$" into a tag. */
#define EPL_failed_converting_uid_to_tag       (EMH_EPL_error_base + 6)
/** No proper value is specified for the preference "TC_external_proxiable_object_props_remote_wkf". */
#define EPL_preference_problem                 (EMH_EPL_error_base + 7)
/** No Exported Proxy Link could be found for the object "%1$ and the exported site "%2$". */
#define EPL_obj_not_found                      (EMH_EPL_error_base + 8)


#include <wproxy/libwproxy_undef.h>
#endif
