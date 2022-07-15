/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2009.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    productvariant errors

*/

#ifndef PRODUCTVARIANT_ERRORS_H
#define PRODUCTVARIANT_ERRORS_H

#include <common/emh_const.h>

#include <productvariant/libproductvariant_exports.h>

/**
    @defgroup PRODUCTVARIANT_ERRORS PRODUCTVARIANT Errors
    @ingroup PRODUCTVARIANT
    @{
*/

#define PRODUCTVARIANT_ERROR_BASE                               EMH_PRODUCTVARIANT_error_base
#define PRODUCTVARIANT_GENERAL_ERROR                            (PRODUCTVARIANT_ERROR_BASE + 0)

#define PRODUCTVARIANT_deserialize_productvariant_obj_failed_no_productcontext    (PRODUCTVARIANT_ERROR_BASE + 1)
#define PRODUCTVARIANT_deserialize_productvariant_obj_failed_no_configcontext     (PRODUCTVARIANT_ERROR_BASE + 2)

#define PRODUCTVARIANT_empty_productContext                     (PRODUCTVARIANT_ERROR_BASE + 3)
#define PRODUCTVARIANT_empty_configContext                      (PRODUCTVARIANT_ERROR_BASE + 4)
#define PRODUCTVARIANT_empty_contents                           (PRODUCTVARIANT_ERROR_BASE + 5)
#define PRODUCTVARIANT_invalidate_intent                        (PRODUCTVARIANT_ERROR_BASE + 6)
#define PRODUCTVARIANT_set_intent_failed                        (PRODUCTVARIANT_ERROR_BASE + 7)
#define PRODUCTVARIANT_only_one_intent                          (PRODUCTVARIANT_ERROR_BASE + 8)

#define PRODUCTVARIANTINTENT_deserialize_productvariantintent_obj_failed_no_content (PRODUCTVARIANT_ERROR_BASE + 9)
#define PRODUCTVARIANT_incorrect_productContext                 (PRODUCTVARIANT_ERROR_BASE + 10)
#define PRODUCTVARIANT_productContext_not_product               (PRODUCTVARIANT_ERROR_BASE + 11)

#define PRODUCTVARIANTINTENT_failed_to_fetch_config_details     (PRODUCTVARIANT_ERROR_BASE + 12)

#define PRODUCTVARIANT_intent_no_variant_rule                   (PRODUCTVARIANT_ERROR_BASE + 13)
#define PRODUCTVARIANT_cc_no_variant_rule                       (PRODUCTVARIANT_ERROR_BASE + 14)
#define PRODUCTVARIANT_invalid_variant_rule                     (PRODUCTVARIANT_ERROR_BASE + 15)
/** @} */

#include <productvariant/libproductvariant_undef.h>

#endif
