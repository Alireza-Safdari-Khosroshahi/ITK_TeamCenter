/*==============================================================================
//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2009.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software
 ==============================================================================*/

#ifndef ASBASMALIGNMENT_ERRORS_H
#define ASBASMALIGNMENT_ERRORS_H

#include <common/emh_const.h>
#include <asbasmalignment/libasbasmalignment_exports.h>

/**
    @defgroup ASBASMALIGNMENT_ERRORS Errors
    @ingroup ASBASMALIGNMENT
    @{
*/

#define ASBASMALIGNMENT_error_base                                          EMH_ASBASMALIGNMENT_error_base

/**
    An AsBuilt Structure cannot be generated from an AsBuilt
    Physical Part.
*/
#define ASBASMALIGNMENT_cannot_generate_asbuilt_from_asbuilt                       (ASBASMALIGNMENT_error_base + 1)

/**
    An AsMaintained Structure cannot be generated from an AsMaintained
    Physical Part.
*/
#define ASBASMALIGNMENT_cannot_generate_asmaintained_from_asmaintained             (ASBASMALIGNMENT_error_base + 2)

/**
    An AsMaintained Structure is not released
*/
#define ASBASMALIGNMENT_asmaintained_structure_is_not_released                      (ASBASMALIGNMENT_error_base + 3)

/**
    An AsBuilt Structure is not released
*/
#define ASBASMALIGNMENT_asbuilt_structure_is_not_released                           (ASBASMALIGNMENT_error_base + 4)

/**
    Rebuild date can not be earlier than last install date
*/
#define ASBASMALIGNMENT_rebuild_date_cannot_be_earlier_than_previous_install_date   (ASBASMALIGNMENT_error_base + 5)

/**
    Rebuild date can not be future date.
*/
#define ASBASMALIGNMENT_rebuild_date_cannot_be_future_date                          (ASBASMALIGNMENT_error_base + 6)

/**
    Maturity status for physical part revision is not defined
*/
#define ASBASMALIGNMENT_maturity_status_not_defined                                 (ASBASMALIGNMENT_error_base + 7)


/** @} */

#include <asbasmalignment/libasbasmalignment_undef.h>

#endif
