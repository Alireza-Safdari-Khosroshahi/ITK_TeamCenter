// @<COPYRIGHT>@
// ==================================================
// Copyright 2021.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// @<COPYRIGHT>@

/*==============================================================================
File description:
    Definitions of constants for version information that can be shared
    between Windows resource files and source files. This file must be very simple
    as it needs to go through the RC version of the preprocessor which
    can't stringize things so we need both integer and string
    constants. Source files must actually verify these match at run time.

==============================================================================*/

#ifndef INCLUDE_TC_VER_INFO_H_INCLUDED
#define INCLUDE_TC_VER_INFO_H_INCLUDED

#define TC_LEGAL_COPYRIGHT      "Copyright 2021. All Rights Reserved."
#define TC_PRODUCT_NAME         "Teamcenter"

#define TC_MAJOR_VERSION        13000
#define TC_MINOR_VERSION        1
#define TC_MAINTENANCE_VERSION  1
#define TC_BUILD_NUMBER         11_2021030100

#define TC_DISPLAY_VERSION      "13.1.0.2(20210301.00)"

#define TC_BASELINE_INCREMENTATION 00
//The string must always be a valid directory name for Unix AND NT.
//So no special characters in there.
//For more information, check its usage
#define TC_VERSION_STRING       "V13000.1.0.11_20210301.00"

#endif // INCLUDE_TC_VER_INFO_H_INCLUDED
