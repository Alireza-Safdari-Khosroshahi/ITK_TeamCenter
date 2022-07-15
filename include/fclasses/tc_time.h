/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Include file to handle machine dependencies for time.h
*/

/*  */

#ifndef TC_TIME_H
#define TC_TIME_H

#include <time.h>

#ifdef UNX
extern time_t mktime( struct tm* );
#endif

#endif
