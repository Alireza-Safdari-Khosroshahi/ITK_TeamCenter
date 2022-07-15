//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright 2011.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software

/** 
    @file 

    Define error codes used with Tc Fnd0SoaMmv

*/

#ifndef SOAFND0MMV_ERRORS_H
#define SOAFND0MMV_ERRORS_H

#ifndef EMH_CONST_H
    #include <common/emh_const.h>
#endif


/**
    @defgroup SOAFND0MMV_ERRORS_H Massive model visualization Errors
    @ingroup FTX
    @{
*/

#define SOAFND0MMV_ERROR_BASE                     EMH_FND0SOAMMV_error_base

/** General errors - ALLOCATING 10 positions */
/** The Massive Model Visualization cursor options are not specified. */
#define SOAFND0MMV_cursor_options_not_specified   (SOAFND0MMV_ERROR_BASE + 1)
/** The number of specified cursor options exceeds the limit of %1$ options. */
#define SOAFND0MMV_cursor_options_exceeds_limits  (SOAFND0MMV_ERROR_BASE + 2)
/** The BOM window on the cursor does not match with the BOM window supplied for the retrieval of occurrences occupied in the cell. */
#define SOAFND0MMV_cursor_bomwindow_mismatch      (SOAFND0MMV_ERROR_BASE + 3)        
/** The number of occurrences associated to the Spatial Hierarchy exceeds the limit of %1$ records. */
#define SOAFND0MMV_hierarchy_exceed_limits        (SOAFND0MMV_ERROR_BASE + 4)        

/** @} */

#endif
