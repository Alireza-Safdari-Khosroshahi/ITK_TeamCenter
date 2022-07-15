/*
    Copyright 2020 Siemens Digital Industries Software
    ==================================================
    Copyright 2015.
    Siemens Product Lifecycle Management Software Inc.
    All Rights Reserved.
    ==================================================
    Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    Error codes that are used by the Edit Context module

*/

#ifndef TEAMCENTER_FND0EDITCONTEXT_ERRORS_H
#define TEAMCENTER_FND0EDITCONTEXT_ERRORS_H

#include <common/emh_const.h>
#include <common/tc_deprecation_macros.h>

/**
    @defgroup EDITCONTEXT_ERRORS Edit Context Errors
    @ingroup EDITCONTEXT
    @{
*/

/**
 * An internal error has occurred: %1$. Please report it to your system administrator.
 */
#define FND0EDITCONTEXT_internal_error                                  ( EMH_FND0EDITCONTEXT_error_base + 0 )

/**
 * The following objects could not be deactivated, because they are not Edit Context objects: %1$.
 */
#define FND0EDITCONTEXT_invalid_objects_for_inactivation                ( EMH_FND0EDITCONTEXT_error_base + 1 )

/**
 * The Change Space creation has failed, because locks could not be created for the public versions of the Markup Space contents.
 */
#define FND0EDITCONTEXT_change_space_lock_creation_failed               ( EMH_FND0EDITCONTEXT_error_base + 2 )

/**
 * The Change Space creation has failed, because the user does not have access to the following Markup Space objects: %1$.
 */
#define FND0EDITCONTEXT_user_denied_access_to_markup_space_contents     ( EMH_FND0EDITCONTEXT_error_base + 3 )

/**
 * No Edit Context can be found for the POM Space with UID "%1$". Please report this error to your system administrator.
 */
#define FND0EDITCONTEXT_pom_space_without_edit_context                  ( EMH_FND0EDITCONTEXT_error_base + 4 )

/** @deprecated #FND0EDITCONTEXT_objects_locked_by_different_change_space deprecated in Teamcenter 11.2.3. */
#define FND0EDITCONTEXT_objects_locked_by_different_change_space        ( EMH_FND0EDITCONTEXT_error_base + 5 )
TC_DEPRECATED_PREPROCESSOR( "11.2.3", FND0EDITCONTEXT_objects_locked_by_different_change_space, "" )

/**
 * The operation getReferencerEditContexts has failed to return the referencing edit contexts. Please consult the Teamcenter syslog for more information.
 */
#define FND0EDITCONTEXT_get_referencers_failed                          ( EMH_FND0EDITCONTEXT_error_base + 6 )

/**
 * The promote operation has failed, because the following objects are checked-out in public: %1$.
 */
#define FND0EDITCONTEXT_objects_checked_out_in_public                   ( EMH_FND0EDITCONTEXT_error_base + 7 )

/**
 * The promote operation has failed, because there are no contents for the Edit Context "%1$".
 */
#define FND0EDITCONTEXT_empty_edit_context                              ( EMH_FND0EDITCONTEXT_error_base + 8 )

/**
 * "%1$" is not a valid Edit Context.
 */
#define FND0EDITCONTEXT_invalid_edit_context                            ( EMH_FND0EDITCONTEXT_error_base + 9 )

/**
 * The operation setChangeContext has failed to configure the input objects. Please consult the Teamcenter syslog for more information.
 */
#define FND0EDITCONTEXT_set_change_context_failed                       ( EMH_FND0EDITCONTEXT_error_base + 10 )

/**
 * "%2$" is of type "%1$", which is not a valid type for configuring objects for editing in spaces.
 */
#define FND0EDITCONTEXT_invalid_change_context                          ( EMH_FND0EDITCONTEXT_error_base + 11 )

/**
 * The input object "%1$" cannot be configured for the Space "%2$", because it is not a valid object in this Space.
 */
#define FND0EDITCONTEXT_object_not_configurable_for_space               ( EMH_FND0EDITCONTEXT_error_base + 12 )

/**
 * The content of the target object "%1$" cannot be promoted to the "public" state, because this object is not a Change Context.
 */
#define FND0EDITCONTEXT_invalid_object_for_promote                      ( EMH_FND0EDITCONTEXT_error_base + 13 )

/**
 * "%1$" is not a valid Edit Context type.
 */
#define FND0EDITCONTEXT_invalid_edit_context_type                      ( EMH_FND0EDITCONTEXT_error_base + 14 )

/**
 * The input argument is invalid.
 */
#define FND0EDITCONTEXT_invalid_argument                               ( EMH_FND0EDITCONTEXT_error_base + 15 )

 /**
 * The Change Proposal creation is disabled. Please contact your administrator.
 */
#define FND0EDITCONTEXT_change_proposal_creation_is_disabled           ( EMH_FND0EDITCONTEXT_error_base + 16 )

/**
    @}
*/

#endif
