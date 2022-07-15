/*=============================================================================
 Copyright 2020 Siemens Digital Industries Software
 ==================================================
 Copyright 2015
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2020 Siemens Digital Industries Software
 ===============================================================================*/

/**
    @file

    This header file declares all error codes to be used by Dia0Diagramming.

*/

#ifndef DIAGRAMMING_ERRORS_H
#define DIAGRAMMING_ERRORS_H

#include <common/emh_const.h>


/**
    @defgroup DIAGRAMMING_ERRORS Diagramming Errors
    @ingroup DIA0DIAGRAMMING
    @{
*/

#define DIAGRAMMING_ERROR_BASE                                  EMH_DIAGRAMMING_error_base

/**
    A partition object must be specified in order to find unassociated partition elements of a diagram.
*/
#define DIAGRAMMING_missing_partition                           (DIAGRAMMING_ERROR_BASE + 1)

/**
    The specified object is not of the correct type.
    Valid types are "Model Element", "Ordered Element Group" or "Conditional Element Group".
*/
#define DIAGRAMMING_find_diagram_invalid_bo_type                (DIAGRAMMING_ERROR_BASE + 2)


/**
    Elements cannot be queried without a Schematic Sheet object.
*/
#define DIAGRAMMING_missing_sheet                               (DIAGRAMMING_ERROR_BASE + 3)

/** @} */

#endif

