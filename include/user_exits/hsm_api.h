/* 
   @<COPYRIGHT_START>@
   ===============================================
   Copyright 2007 UGS Corp. All Rights Reserved.
   ===============================================
   @<COPYRIGHT_END>@
*/

/** 
    @file 

    This contains all HSM(Hierarchical Storage Management) API functions for third party 
     integrations with Teamcenter.
*/

#ifndef HSM_H

#include <tc/tc_startup.h>

#include <user_exits/libuser_exits_exports.h>

#ifdef __cplusplus
extern "C"{
#endif
    extern USER_EXITS_API int  HSM_migrate_file_to_tier(
        const char  *           enterpriseId,          /* <I>  */
        logical                 purge_immediately,     /* <I>  */
        int                     high_water_mark,       /* <I> */
        int                     low_water_mark,        /* <I> */
        int                     migrate_from_tier,     /* <I> */
        int                     migrate_to_tier,       /* <I> */
        const char *            absolute_file_path     /* <I> */
        );


#ifdef __cplusplus
}
#endif
#include <user_exits/libuser_exits_undef.h>
#endif

