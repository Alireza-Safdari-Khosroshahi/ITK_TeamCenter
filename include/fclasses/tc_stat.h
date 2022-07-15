/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    An include file to handle system dependencies for the stat.h file 
*/

/*  */

#ifdef VMS
#include <stat.h>
#endif

#ifdef SUN
#include <sys/types.h>
#endif

#ifdef SGI
#include <sys/types.h>
#endif

#ifdef UNX
#include <sys/stat.h>
#endif
