/*=============================================================================
           Copyright (c) 1992 Electronic Data Systems Corporation

                   Unpublished - All rights reserved
   THIS PROGRAM IS AN UNPUBLISHED WORK FULLY PROTECTED BY THE UNITED STATES
  COPYRIGHT LAWS AND IS CONSIDERED A TRADE SECRET BELONGING TO THE COPYRIGHT
                                   HOLDER.
===============================================================================
File description:

    Filename: singlefilerecovery.h
    Module  : iman


====================================================================================================
   Date      Name                    Description of Change

21-Nov-2001  Katte Satish            Initial Creation
23-Nov-2001  Bobby Ljubic            Merge to project integration branch
06-Aug-2002  Aaron Ruckman           Split libtc.dll project
10-Mar-2004  Brendan Brolly          Reword of extern C linkage as part of NX3 rebase.
$HISTORY$
===================================================================================================*/

#ifndef SINGLEFILERECOVERY_H

#include <tc/tc_startup.h>

#include <user_exits/libuser_exits_exports.h>

#ifdef __cplusplus
    extern "C"{
#endif

/**
    On recovery command issued by the user, the below SFR API will contact the 3rd party 
    Backup software vendors based on this Backup label for restoration of files under the 
    respective volumes. This requires the integration of 3rd party backup application 
    libraries with TCE.
   
    Once the files are restored under the respective volumes, the tcserver will create a 
    new dataset under newstuff folder and add the the recovered files as named references
    to the dataset. 
*/
    
extern USER_EXITS_API int SFR_recover_files_to_location (
    const char*             dstClient,      /**< (I)  volume host(node) name */        
    const char*             destination,    /**< (I)  volume name */    
    int                     no_of_files,    /**< (I)  Number of files to be recovered from the backup set */
    char *                  bkup_lab,       /**< (I)  Backup Label associated with the files to be recovered */
    char **                 vol_paths       /**< (I)  Volume paths of the recovered files */
);

#ifdef __cplusplus
}
#endif
#include <user_exits/libuser_exits_undef.h>
#endif

