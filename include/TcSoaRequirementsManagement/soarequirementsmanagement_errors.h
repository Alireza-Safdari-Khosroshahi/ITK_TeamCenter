/* =================================================================================================
           Copyright (c) 1999,2000,2001,2003 Unigraphics Solutions Inc., An EDS Company
                   Unpublished - All rights reserved

   THIS PROGRAM IS AN UNPUBLISHED WORK FULLY PROTECTED BY THE UNITED STATES
  COPYRIGHT LAWS AND IS CONSIDERED A TRADE SECRET BELONGING TO THE COPYRIGHT
                                   HOLDER.
====================================================================================================*/

/**
    @file

    Errors for the soa requirementsmanagement services


*/

/** @if HISTORY_SECTION
====================================================================================================
22-May-2006  Chang Su         Error codes for soarequirementsmanagement
$HISTORY$
==================================================================================================
@endif */

#ifndef SOAREQUIREMENTSMANAGEMENT_ERRORS_H
#define SOAREQUIREMENTSMANAGEMENT_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup SOAREQUIREMENTSMANAGEMENT_ERRORS TCWS Errors
    @ingroup SOAREQUIREMENTSMANAGEMENT
    @{
*/

/** reuirements management error */
/** 
* A Requirements Management SOA error occurred.
*/
#define SOAREQUIREMENTSMANAGEMENT_bad_rm                                              (EMH_SOAREQUIREMENTSMANAGEMENT_error_base + 0)
/**
* The user does not have write permission.
*/
#define SOAREQUIREMENTSMANAGEMENT_no_write_access                                     (EMH_SOAREQUIREMENTSMANAGEMENT_error_base + 1)
/**
* The Replica object %1$ could not be modified.
* param1=object name
*/
#define SOAREQUIREMENTSMANAGEMENT_owningSite_mismatch                                 (EMH_SOAREQUIREMENTSMANAGEMENT_error_base + 2)
/**
* The released version of object %1$ could not be modified.
* param1=object name
*/
#define SOAREQUIREMENTSMANAGEMENT_has_release_status                                  (EMH_SOAREQUIREMENTSMANAGEMENT_error_base + 3)
/**
* The void case is not supported for Generic Relations.
*/
#define SOAREQUIREMENTSMANAGEMENT_GRM_voidcase_notsupported                           (EMH_SOAREQUIREMENTSMANAGEMENT_error_base + 4)
/**
* The object_name property is missing from object %1$.
* param1=object name
*/
#define SOAREQUIREMENTSMANAGEMENT_object_name_missing                                 (EMH_SOAREQUIREMENTSMANAGEMENT_error_base + 5)
/**
* The value for attribute %1$ is missing.
* param1=attribute name of object
*/
#define SOAREQUIREMENTSMANAGEMENT_attr_value_not_present                              (EMH_SOAREQUIREMENTSMANAGEMENT_error_base + 6)
/**
* The ParentChangeType value is missing from object %1$.
* param1=child object name
*/
#define SOAREQUIREMENTSMANAGEMENT_change_type_missing                                 (EMH_SOAREQUIREMENTSMANAGEMENT_error_base + 7)
/**
*error id-8= The input structure contains an invalid Note object.
*/
#define SOAREQUIREMENTSMANAGEMENT_invalid_note_object                                 (EMH_SOAREQUIREMENTSMANAGEMENT_error_base + 8)
/**
* The Item Type %1$ is not supported.
* param1=type of object.
*/
#define SOAREQUIREMENTSMANAGEMENT_type_not_supported                                  (EMH_SOAREQUIREMENTSMANAGEMENT_error_base + 9)
/**
* Creation of new ItemRevision is not supported.
*/
#define SOAREQUIREMENTSMANAGEMENT_new_revision_not_supported                          (EMH_SOAREQUIREMENTSMANAGEMENT_error_base + 10)
/**
* The folder UID %1$ does not exist in Teamcenter. Please provide a blank value to create a new folder.
* param1=UID of folder object.
*/
#define SOAREQUIREMENTSMANAGEMENT_invalid_folder_id                                   (EMH_SOAREQUIREMENTSMANAGEMENT_error_base + 11)
/**
* A null Object is passed to the function "%1$".
* param1=object name.
*/
#define SOAREQUIREMENTSMANAGEMENT_invalid_object                                      (EMH_SOAREQUIREMENTSMANAGEMENT_error_base + 12)
/**
* The object of type "%1$" is missing the required property "%2$".
* param1=name of object_type 
* param2=name of required property
*/
#define SOAREQUIREMENTSMANAGEMENT_required_property_missing                           (EMH_SOAREQUIREMENTSMANAGEMENT_error_base + 13)
/** @} */

#endif

