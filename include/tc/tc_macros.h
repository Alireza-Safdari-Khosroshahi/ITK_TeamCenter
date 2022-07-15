/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Include file to define macros used in Teamcenter
*/

/*  */

#ifndef TC_MACROS_H
#define TC_MACROS_H

#include <base_utils/Mem.h>
#include <tc/tc_startup.h>
#include <tc/emh.h>
#include <tc/tc_util.h>
#include <base_utils/Mem.h>
#include <fclasses/tc_stdarg.h>
#include <fclasses/tc_string.h>

/**
    @defgroup TC_MACROS Teamcenter Macros
    @ingroup TC
    @{
*/

/**
    This macro will return 1 if the given date is equal to #NULLDATE.
    pom.inc must be included before this macro can be properly expanded.
 */
#define DATE_IS_NULL(d1)                            \
    ((d1.year == NULLDATE.year ) ?                  \
      ((d1.month == NULLDATE.month) ?               \
          ((d1.day == NULLDATE.day  ) ?             \
            ((d1.hour == NULLDATE.hour) ?           \
            ((d1.minute  == NULLDATE.minute) ?      \
              ((d1.second  == NULLDATE.second) ? 1  \
                                               : 0) \
                                             : 0)   \
                                        : 0)        \
                                      : 0)          \
                                    : 0)            \
                                : 0)

#define STRLEN(a)       tc_strlen(a)

#define STRCPY(a, b)    tc_strcpy(a, b)

#define STRNCPY(a,b,s)  tc_strncpy(a, b, s)

#define ITKCALL( argument )                                             \
{                                                                       \
    int retcode = argument;                                             \
    if ( retcode != ITK_ok ) {                                          \
        char* s;                                                        \
        printf( " "#argument "\n" );                                    \
        printf( "  returns [%d]\n", retcode );                          \
        EMH_ask_error_text (retcode, &s);                               \
        TC_printf( "  Teamcenter ERROR: [%s]\n", s);           \
        printf( "  in file [" __FILE__ "], line [%d]\n\n", __LINE__ );    \
        if (s != 0) MEM_free (s);                                       \
    }                                                                   \
}

/** @} */

#define ITKCHECK(x) \
{ \
    if ( retCode == ITK_ok ) \
    { \
        if ( ( retCode = (x)) != ITK_ok ) \
        { \
            char *errstring = NULL; \
            EMH_ask_error_text ( retCode, &errstring ); \
            lprintf ( "+++ Error %d: %s\n", retCode , errstring ); \
            if ( errstring != NULL ) MEM_free ( errstring ); \
            lprintf ( "Function %s:  Line %d in %s\n ", #x, __LINE__, __FILE__); \
        } \
    } \
}

#endif
