/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Include file to handle system dependencies for types.h
*/

/*  */

#ifdef VMS
#include <types.h>
#else
#include <sys/types.h>
#endif
