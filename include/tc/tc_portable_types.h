/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This header file provides symbols to facilitate the development of
    machine, operating system and language dependent code.
*/

/*  */

#ifndef TC_PORTABLE_TYPES_H
#define TC_PORTABLE_TYPES_H

#ifdef VMS 

    #define VAX                 1

    #ifndef __MACHINE_VAX
        #define __MACHINE_VAX   1
    #endif

    #define EXIT_FAILURE        1
    #define EXIT_SUCCESS        0

#endif

#endif

