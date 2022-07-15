/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This is now just a wrapper to include the new journal header file.  This 
    just ensures that code not controlled by tc unified which was making use
    of this header file will continue to work.  The code within tc unified 
    that was including this header file have been changed to point to the new
    header file location.
*/

/*  */

#ifdef WNT
#define TC_include_pom_journal_h_deprecated // define a unique deprecation macro name (having 63 chars or less)
#pragma deprecated( "TC_include_pom_journal_h_deprecated" ) // activate the deprecation warning when using the macro name
TC_include_pom_journal_h_deprecated // use the deprecated macro so that the compiler issues the deprecation warning/error
#endif // #ifdef WNT


#include "mld/journal/journal.h"

