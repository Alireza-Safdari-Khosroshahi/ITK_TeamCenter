/*
    Copyright 2020 Siemens Digital Industries Software
    ==================================================
    Copyright 2018.
    Siemens Product Lifecycle Management Software Inc.
    All Rights Reserved.
    ==================================================
    Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file
    Order Management Application Error Codes Declaration
*/

#ifndef ORD0ORDERMANAGEMENT_ERRORS_HXX
#define ORD0ORDERMANAGEMENT_ERRORS_HXX

#include <common/emh_const.h>

/**
    @defgroup ORD0ORDERMANAGEMENT_ERRORS Order Management Errors
    @ingroup ORD0ORDERMANAGEMENT
    @{
*/

#define EMH_ORD0ORDERMANAGEMENT_ERROR_BASE                                                 EMH_ORD0ORDERMANAGEMENT_error_base

/**
 * An internal error has occurred in the "Order Management" module: %1$. Please report this error to your system administrator.
 */
#define ORD0ORDERMANAGEMENT_internal_error                                                 ( EMH_ORD0ORDERMANAGEMENT_ERROR_BASE + 1 )

/**
 * The provided Thread "CreateInput" is of type "%1$" which is not supported. Only object of type or subtype of "%2$" is expected.
 */
#define ORD0ORDERMANAGEMENT_invalid_thread_type                                            ( EMH_ORD0ORDERMANAGEMENT_ERROR_BASE + 2 )

/**
 * "%1$" is of type "%2$" which is not supported. Only objects of type or subtype of "%3$" are expected.
 */
#define ORD0ORDERMANAGEMENT_invalid_object_type                                            ( EMH_ORD0ORDERMANAGEMENT_ERROR_BASE + 3 )

/**
 * The object "%1$" of type "%2$" does not contain the value "%3$" for the property "%4$". Only objects with this value for this property can be released.
 */
#define ORD0ORDERMANAGEMENT_not_release_ready                                              ( EMH_ORD0ORDERMANAGEMENT_ERROR_BASE + 4 )

 /**
 * The Line Item Delivery Package cannot be created, because the value of the property "%1$" on the Order Line Item object "%2$" is not "%3$".
 */
#define ORD0ORDERMANAGEMENT_lidp_not_create_ready                                          ( EMH_ORD0ORDERMANAGEMENT_ERROR_BASE + 5 )

/**

@}
*/

#endif
