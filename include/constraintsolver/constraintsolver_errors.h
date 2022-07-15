/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2016.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file constraintsolver_errors.h

    This header file contains error codes for the Constraint Solver Module.
*/

#ifndef CONSTRAINTSOLVER_ERRORS_H
#define CONSTRAINTSOLVER_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup CONSTRAINTSOLVER_ERRORS Errors
    @ingroup CONSTRAINTSOLVER
    @{
*/

#define  CSLV_error_base                                        EMH_constraintsolver_error_base

/** An internal error has occurred in the module Constraint Solver: %1$. Please report this error to your system administrator. */
#define  CSLV_internal_error                                    (CSLV_error_base + 0)

/**  Range operators (>, <, >= or <=) are not allowed for the value of the data type "String". */
#define  CSLV_invalid_operation_string_family                   (CSLV_error_base + 1)

/** The provided severity token: %1$ is invalid. Please refer to the documentation for CFG_severity. */
#define  CSLV_invalid_severity_token                            (CSLV_error_base + 2)

/** The configurator constraint "%1$" cannot be converted into a constraint script because its type "%2$" does not support this operation. Please refer to the section "define free-form configurator rules" in the TDoc for a list of supported object types. */
#define  CSLV_invalid_operation_constraint_type                 (CSLV_error_base + 3)

/**

    @}
 */

#endif
