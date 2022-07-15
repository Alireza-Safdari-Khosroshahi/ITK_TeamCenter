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

    Define error codes used with Tc Fnd0mmv

*/

#ifndef FND0MMV_ERRORS_H
#define FND0MMV_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup FND0MMV Errors for massive model visualization
    @ingroup FTX
    @{
*/

#define MMV_ERROR_BASE                                   EMH_FND0MMV_error_base
/** An internal error has occurred in the "Fnd0mmv" module */
#define FND0MMV_internal_error                          (MMV_ERROR_BASE + 1)
/** The supplied Spatial Hierarchy dataset is invalid. */
#define FND0MMV_invalid_sphier_tag                      (MMV_ERROR_BASE + 2)
/** The supplied Massive Model Visualization cursor is invalid. */
#define FND0MMV_invalid_cursor                          (MMV_ERROR_BASE + 3)
/** Th MMV spatial cell index not harvested for the given revision rule. */
#define FND0MMV_config_not_harvested                    (MMV_ERROR_BASE + 4)
/** The  Massive Model Visualization cursor not specified */
#define FND0MMV_cursor_not_specified                    (MMV_ERROR_BASE + 5)
/** An invalid object */
#define FND0MMV_invalid_object_tag                      (MMV_ERROR_BASE + 6)

/** View locking errors - ALLOCATING 20 positions */
/** The Spatial Hierarchy dataset version is already locked for viewing by the current session. */
#define FND0MMV_already_locked_by_curr_sess             (MMV_ERROR_BASE + 11)
/** The Spatial Hierarchy dataset version is already locked for viewing by a session. */
#define FND0MMV_already_locked_by_sess                  (MMV_ERROR_BASE + 12)
/** The Spatial Hierarchy dataset version is not locked for viewing. */
#define FND0MMV_not_locked_for_viewing                  (MMV_ERROR_BASE + 13)
/* No Spatial Hierarchy dataset was found for the Product */
#define FND0MMV_spatialhier_dataset_not_found           (MMV_ERROR_BASE + 14)
/** The supplied BOM line is not the top line of the BOM Window. */
#define FND0MMV_not_a_top_bom_line                      (MMV_ERROR_BASE + 15)


/** SpatialCellIndex  table insert/update related errors - ALLOCATING 10 positions */
/** The database operation has failed during its execution */
#define FND0MMV_failed_execute_database_operation       (MMV_ERROR_BASE + 31)
/** The spatial cell indexes could not be created. */
#define FND0MMV_cannot_create_spatial_cell_indexes      (MMV_ERROR_BASE + 32)
/** The spatial cell indexes could not be deleted. */
#define FND0MMV_cannot_delete_spatial_cell_indexes      (MMV_ERROR_BASE + 33)
/** The equivalent thread records could not be created. */
#define FND0MMV_cannot_create_equiv_thread_record       (MMV_ERROR_BASE + 34)
/** The equivalent thread records could not be deleted. */
#define FND0MMV_cannot_delete_equiv_thread_record       (MMV_ERROR_BASE + 35)

/** @} */

#endif
