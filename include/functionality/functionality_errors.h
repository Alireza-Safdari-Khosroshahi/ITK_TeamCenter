// Copyright 2020 Siemens Digital Industries Software
// ==================================================
// Copyright 2009.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2020 Siemens Digital Industries Software

/**
    @file

    This file contains the published identifiers of error codes that can be
    generated by this functionality module. Obtaining and using the numeric values of these
    manifest constants is not supported. We reserve the right to change the
    actual values as necessary.
*/


#ifndef FUNCTIONALITY_ERRORS_H
#define FUNCTIONALITY_ERRORS_H

#ifndef EMH_CONST_H
    #include <common/emh_const.h>
#endif

#include <functionality/libfunctionality_exports.h>

/**
    @defgroup FUNCTIONALITY_ERRORS FUNCTIONALITY Errors
    @ingroup FUNCTIONALITY
    @{
*/
#define FUNCTIONALITY_ERROR_BASE                    EMH_FUNCTIONALITY_error_base

#define FUNCTIONALITY_internal_error                (FUNCTIONALITY_ERROR_BASE + 1)
#define FUNCTIONALITY_unable_to_create              (FUNCTIONALITY_ERROR_BASE + 2)
#define FUNCTIONALITY_unable_to_initial             (FUNCTIONALITY_ERROR_BASE + 3)
#define FUNCTIONALITY_unable_to_build               (FUNCTIONALITY_ERROR_BASE + 4)
#define FUNCTIONALITY_input_error                   (FUNCTIONALITY_ERROR_BASE + 5)
#define FUNCTIONALITY_get_VRules_error              (FUNCTIONALITY_ERROR_BASE + 6)
#define FUNCTIONALITY_cannot_retrieve_vr            (FUNCTIONALITY_ERROR_BASE + 7)
#define FUNCTIONALITY_cannot_retrieve_functionality (FUNCTIONALITY_ERROR_BASE + 8)
#define FUNCTIONALITY_cannot_retrieve_condition     (FUNCTIONALITY_ERROR_BASE + 9)
#define FUNCTIONALITY_expected_size_mismatch        (FUNCTIONALITY_ERROR_BASE + 10)
#define FUNCTIONALITY_functionality_name_mismatch   (FUNCTIONALITY_ERROR_BASE + 11)
#define FUNCTIONALITY_typename_mismatch             (FUNCTIONALITY_ERROR_BASE + 12)
#define FUNCTIONALITY_condition_name_mismatch       (FUNCTIONALITY_ERROR_BASE + 13)
#define FUNCTIONALITY_subgrouplov_name_mismatch     (FUNCTIONALITY_ERROR_BASE + 14)
#define FUNCTIONALITY_undefined_test_name           (FUNCTIONALITY_ERROR_BASE + 15)

/** @} */

#include <functionality/libfunctionality_undef.h>
#endif  /* FUNCTIONALITY_ERRORS_H */

