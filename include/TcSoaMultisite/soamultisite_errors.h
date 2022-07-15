/* =================================================================================================
           Copyright (c) 2014 Unigraphics Solutions Inc., A Siemens Company
                   Unpublished - All rights reserved

   THIS PROGRAM IS AN UNPUBLISHED WORK FULLY PROTECTED BY THE UNITED STATES
  COPYRIGHT LAWS AND IS CONSIDERED A TRADE SECRET BELONGING TO THE COPYRIGHT
                                   HOLDER.
====================================================================================================*/

/**
    @file

    Errors for the soa multisite services

*/

/** @if HISTORY_SECTION
====================================================================================================
   Date      Name                    Description of Change
19-Feb-2007  x_pattna                Initial Creation
$HISTORY$
==================================================================================================
@endif */

#ifndef SOAMULTISITE_ERRORS_H
#define SOAMULTISITE_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup SOAMULTISITE_ERRORS TCWS Errors
    @ingroup SOAMULTISITE
    @{
*/

/** MULTISITE Integration Services error code definitions */

/** NOTE: The error numbers assigned in this file must match those in the soacad_errors.xml file **/

/** ImportExport Service (0 - 9) **/

/**
    The input import options list is NULL.
*/
#define SOAMULTISITE_null_import_options_list                        (EMH_SOAMULTISITE_error_base +   0 )

/**
    The input import object is NULLTAG.
*/
#define SOAMULTISITE_null_input_object                               (EMH_SOAMULTISITE_error_base +   1 )

/**
    An invalid value is specified for the include contents import option.
*/
#define SOAMULTISITE_invalid_include_contents_option                 (EMH_SOAMULTISITE_error_base +   2 )

/**
    No input object is specified for the import operation.
*/
#define SOAMULTISITE_no_input_objects_for_import                     (EMH_SOAMULTISITE_error_base +   3 )

/**
    The owning site specified for the object "%1$" is invalid.
*/
#define SOAMULTISITE_invalid_owning_site                             (EMH_SOAMULTISITE_error_base +   4 )

/**
    The input export options list is not defined.
*/
#define SOAMULTISITE_null_export_options_list                        (EMH_SOAMULTISITE_error_base +   5 )

/**
    The Tag information could not be retrieved for the object "%1$".
*/
#define SOAMULTISITE_tag_could_not_be_fetched                        (EMH_SOAMULTISITE_error_base +   6 )

/**
    The object "%1$" is neither an already-imported object, nor a published object, nor a remote object.
*/
#define SOAMULTISITE_remote_import_not_supported                     (EMH_SOAMULTISITE_error_base +   7 )

/**
    A mismatch has been detected in the number of UIDs (%1$) and the number of owning sites (%2$) in the input. 
    One owning site per UID needs to be specified.
*/
#define SOAMULTISITE_import_input_UID_owning_site_count_mismatch     (EMH_SOAMULTISITE_error_base +   8 )

/**
    Multiple revision selectors have been specified by the caller. Only one revision selector can be specified.
*/
#define SOAMULTISITE_multiple_revision_selectors_specified           (EMH_SOAMULTISITE_error_base +   9 )


/** @} */


#endif

