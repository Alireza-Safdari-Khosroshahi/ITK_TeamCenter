/*===============================================
   Copyright 2007 UGS Corp. All Rights Reserved.
   ===============================================*/

/** 
    @file
    
    This file contains the ITK functions for setting the Teamcenter volumes 
    in different backup modes for administering  hot Backup & Recovery.
*/

#ifndef TCFS_MODES_H
#define TCFS_MODES_H

/**
    @defgroup TCVOLUME Teamcenter Volumes
    @ingroup TC

    This set of functions enables you to set the Teamcenter volumes 
    in different backup modes for administering hot Backup & Recovery.
    Include backup_modes.h to use these functions.
    @{
*/

#define FS_NORMAL_MODE     28 /* Used for putting Teamcenter Volumes in normal mode */
#define FS_RDONLY_MODE     29 /* Used for putting Teamcenter Volumes in read only mode */
#define FS_BLOBBY_VOL_MODE 31 /* Redirect writes to a temporary volume location (blobby) during hot backup. */


#include <tc/libtc_exports.h>

/**
    Initializes the backup mode. 
    Valid values for the mode are NORMAL_MODE, RDONLY_MODE and BLOBBY_MODE. 
 */
extern TC_API int  TC_initialize_backup_mode(
    int           mode                          /**< (I) backup mode */
);

/**
    Sets the backup mode.
    Call the ITK method TC_initialize_backup_mode before setting backup modes. 
    Valid values for the mode are NORMAL_MODE, RDONLY_MODE and BLOBBY_MODE. 
 */
extern TC_API int  TC_set_backup_mode(
    int           mode                           /**< (I) backup mode */
);

/**
    Provides the count of the currently opened OS files for write/append operations.
 */
extern TC_API int  TC_get_osfile_open_count(
    int           *count                         /**< (O) count of open files */
);

/**
    Gets the current backup mode.
    Valid values for the mode are NORMAL_MODE, RDONLY_MODE and BLOBBY_MODE. 
 */
extern TC_API int  TC_get_current_backup_mode(
    int           *mode                          /**< (O) backup mode */
);
/** @} */

#include <tc/libtc_undef.h>
#endif
