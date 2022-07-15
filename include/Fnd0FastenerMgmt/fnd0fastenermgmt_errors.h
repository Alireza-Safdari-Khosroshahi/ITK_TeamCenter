/*
Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright 2017
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software
*/
/**
    @file

    Errors for Fastener Management
*/

/*  */

#ifndef FND0FASTENERMGMT_ERRORS_H
#define FND0FASTENERMGMT_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup FND0FASTENERMGMT_ERRORS Fastener Management Errors
    @ingroup FND0FASTENERMGMT
    @{
*/

/**
 * An error has occurred in the initialization of the Fastener Management module. Please report this error to your system administrator.
 */
#define FND0FASTENERMGMT_unable_to_init_fastener_mgmt    (EMH_FND0FASTENERMGMT_error_base + 1)

/**
 * The Fastener Management library has failed to load. Please report this error to your system administrator.
 */
#define FND0FASTENERMGMT_no_load_library                 (EMH_FND0FASTENERMGMT_error_base + 2)

/**
 * The Fastener could not be created.
 */
#define FND0FASTENERMGMT_no_create                       (EMH_FND0FASTENERMGMT_error_base + 3)

/**
 * The Sealant "%1$" must be of type Item Revision.
 */
#define FND0FASTENERMGMT_sealant_must_be_an_item_rev     (EMH_FND0FASTENERMGMT_error_base + 4)

/**
 * The Joined Part "%1$" must be of type Item Revision.
 */
#define FND0FASTENERMGMT_joined_part_must_be_an_item_rev (EMH_FND0FASTENERMGMT_error_base + 5)

/**
 * The Hardware "%1$" must be of type Item Revision.
 */
#define FND0FASTENERMGMT_hardware_must_be_an_item_rev    (EMH_FND0FASTENERMGMT_error_base + 6)

/**
 * The Sealants must be set through the associated Fastener attribute form.
 */
#define FND0FASTENERMGMT_no_set_sealants                 (EMH_FND0FASTENERMGMT_error_base + 7)

/**
 * The Joined Parts must be set through the associated Fastener attribute form.
 */
#define FND0FASTENERMGMT_no_set_joined_parts             (EMH_FND0FASTENERMGMT_error_base + 8)

/**
 * The Hardware must be set through the associated Fastener Group attribute form.
 */
#define FND0FASTENERMGMT_no_set_hardware                 (EMH_FND0FASTENERMGMT_error_base + 9)

/**
 * Hardware included in a Fastener Group cannot be split.
 */
#define FND0FASTENERMGMT_no_split_hardware               (EMH_FND0FASTENERMGMT_error_base + 10)

/** @} */

#endif
