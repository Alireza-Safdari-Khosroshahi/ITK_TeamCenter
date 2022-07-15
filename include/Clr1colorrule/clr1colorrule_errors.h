/* 
 Copyright 2020 Siemens Digital Industries Software
 ==================================================
 Copyright 2014
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file
    Abstract Color Rule Error Codes Declaration
*/

#ifndef CLR1COLORRULE_ERRORS_HXX
#define CLR1COLORRULE_ERRORS_HXX

#include <common/emh_const.h>

/**
    @defgroup CLR1COLORRULE_ERRORS Errors for Color Rule application.
    @ingroup CLR1COLORRULE
    @{
*/

#define EMH_CLR1COLORRULE_ERROR_BASE                                                EMH_CLR1COLORRULE_error_base

/**
 * No appearance is attached to the Color Rule object "%1$".
 */
#define CLR1COLORRULE_appearance_not_found                                          ( EMH_CLR1COLORRULE_error_base + 1 )

/**
 * A valid expression needs to be attached to the Color Rule "%1$".
 */
#define CLR1COLORRULE_empty_expression                                              ( EMH_CLR1COLORRULE_error_base + 2 )

/**
 * The expression attached to the Color Rule "%1$" of type "%2$"is invalid, because it conflicts with configurator constraints.
 */
#define CLR1COLORRULE_invalid_expression                                            ( EMH_CLR1COLORRULE_error_base + 3 )

/**
 * The Revision Rule "%1$" specified in the preference "ColorRuleReleaseRevisionRulePref" could not be found.
 */
#define CLR1COLORRULE_invalid_revision_rule_pref                                    ( EMH_CLR1COLORRULE_error_base + 4 )

/**
 * No Revision Rule is specified for the preference "ColorRuleReleaseRevisionRulePref" used to validate expressions attached to Color Rules.
 */
#define CLR1COLORRULE_no_revision_rule_pref                                         ( EMH_CLR1COLORRULE_error_base + 5 )

/**
 * The object "%1$" cannot be revised, because it is not released.
 */
#define CLR1COLORRULE_object_not_released                                           ( EMH_CLR1COLORRULE_error_base + 6 )

/**
 * The Abstract Color Rule Thread "%1$" is not configured.
 */
#define CLR1COLORRULE_thread_not_configured                                         ( EMH_CLR1COLORRULE_error_base + 7 )

/**
 * The Abstract Color Rule Thread "%1$" is not configured with a valid type.
 */
#define CLR1COLORRULE_thread_not_valid_type                                         ( EMH_CLR1COLORRULE_error_base + 8 )

/**
 * The specified Product Context is invalid.
 */
#define CLR1COLORRULE_invalid_context                                               ( EMH_CLR1COLORRULE_error_base + 9 )

/**
    @}
*/

#endif
