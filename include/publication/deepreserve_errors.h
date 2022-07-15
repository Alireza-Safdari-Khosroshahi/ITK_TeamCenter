// @<COPYRIGHT_START>@
// ===============================================
// Copyright 2013.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ===============================================
// @<COPYRIGHT_END>@

/**
    @file

    Errors for TIE island based local/remote check-in/check-out functionality

====================================================================================================
   Date      Name                    Description of Change
17-Dec-2013  wuche                 Initial Version
$HISTORY$
==================================================================================================*/

#ifndef DEEP_RESERVE_ERRORS_H
#define DEEP_RESERVE_ERRORS_H

#include <common/emh_const.h>

/**The current operation cannot be completed, because the operation "%3$" is already processing the object "1%" and its principal object "%2".*/
#define DEEP_RESERVE_object_under_other_reserve_operation       (EMH_TIE_ISLAND_CICO_error_base + 1  )

/**The replica object "%1$" does not support the "%2$" operation.*/
#define DEEP_RESERVE_object_operation_not_allowed               (EMH_TIE_ISLAND_CICO_error_base + 2  )

#endif
