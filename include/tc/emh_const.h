/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Include file to define constants for eim error handling

    @deprecated It will be removed from Tc11.0.
    <br/>The new format is \#include \<common/emh_const.h\> instead of \#include \<tc/emh_const.h\>.
*/

/*  */

#ifndef EMH_CONST_H
#define EMH_CONST_H

/**
   @file

   @deprecated This file will be removed in Tc13.
*/
#include <pom/pom/pom_errors.h>
#include <tc/emh.h>

/**
    @defgroup EMH_CONST Constants
    @ingroup EMH
    @{
*/

/**
    @name Button values
    @{
*/
#define EMH_Ok                          0x0001
#define EMH_Acknowledge                 0x0002
#define EMH_Yes                         0x0004
#define EMH_No                          0x0008
#define EMH_Continue                    0x0010
#define EMH_Retry                       0x0020
#define EMH_Abort                       0x0040
#define EMH_Cancel                      0x0080
#define EMH_More                        0x0100
#define EMH_Help                        0x0200
/** @} */

/**
    @name Verbosity values
    @{
*/
#define EMH_VERBOSE                     1
#define EMH_TERSE                       2
/** @} */

/** Uid file */
#define EMH_LANG_FILE                   "emh_text.xml"

#define EMH_NUM_MODULES                 82

#ifdef WNT
/** Defines a unique deprecation macro name (having 63 chars or less) */
#define TC_include_tc_emh_const_h_deprecated 
/** Activates the deprecation warning when using the macro name */
#pragma deprecated( "TC_include_tc_emh_const_h_deprecated" ) 
TC_include_tc_emh_const_h_deprecated /** use the deprecated macro so that the compiler issues the deprecation warning */

#endif

/** @} */

#include <common/emh_const.h>

/*  */
#include <tc/iman_emh_const.h>

#endif

