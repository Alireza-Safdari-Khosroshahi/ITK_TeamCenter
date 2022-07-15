// Copyright 2020 Siemens Digital Industries Software
// ==================================================
// Copyright 2014.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2020 Siemens Digital Industries Software

/**
    @file
    design Guidelines Error Codes Declaration
*/

#ifndef PDG0PTNDESIGNGDLINES_ERRORS_HXX
#define PDG0PTNDESIGNGDLINES_ERRORS_HXX

#include <common/emh_const.h>

/**
    @defgroup PDG0PTNDESIGNGDLINES_ERRORS Errors for the Partitioned Design Guidelines Module
    @ingroup PDG0PTNDESIGNGDLINES
    @{
*/

#define EMH_PDG0PTNDESIGNGDLINES_ERROR_BASE                                                 EMH_PDG0PTNDESIGNGDLINES_error_base

/**
 * An internal error has occurred in the module Partitioned Design Guidelines: %1$. Please report this error to your system administrator.
 */
#define PDG0PTNDESIGNGDLINES_internal_error                                                 ( EMH_PDG0PTNDESIGNGDLINES_ERROR_BASE + 1 )

/**
 * The object "%1$" of type "%2$" cannot have null input context.
 */
#define PDG0PTNDESIGNGDLINES_product_context_is_null                                        ( EMH_PDG0PTNDESIGNGDLINES_ERROR_BASE + 2 )

/**
 * The provided "%1$" object is of type "%2$". An object of type "%3$" is expected.
 */
#define PDG0PTNDESIGNGDLINES_invalid_product_context_type                                    ( EMH_PDG0PTNDESIGNGDLINES_ERROR_BASE + 3 )

/**
 * The object "%1$" of type "%2$" has invalid input context, because the input context "%3$" is not the same as the admissibility context object "%4$".
 */
#define PDG0PTNDESIGNGDLINES_invalid_product_context                                         ( EMH_PDG0PTNDESIGNGDLINES_ERROR_BASE + 4 )


/**
    @}
*/

#endif
