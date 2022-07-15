/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2017.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    Error codes for Consumer Product Management module.

*/

#ifndef PMG0CPMGMT_ERRORS_H
#define PMG0CPMGMT_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup PMG0CPMGMT_ERRORS Consumer Product Management Errors
    @ingroup PMG0CPMGMT
    @{
*/

/** A Dimension with name "%1$" already exists on product "%2$". Please review the dimension name.*/
#define PMG0CPMGMT_duplicate_dimension                          ( EMH_PMG0CPMGMT_error_base + 0 )

/**The "Effective To" date should be later than the "Effective From" date.*/
#define PMG0CPMGMT_effectiveto_less_than_effectivefrom          ( EMH_PMG0CPMGMT_error_base + 1 )

/**The creation of SKU "%1$" failed. SKU can only be created in the context of a Product.*/
#define PMG0CPMGMT_no_product_selected_for_sku                  ( EMH_PMG0CPMGMT_error_base + 2 )

/** @} */

#endif
