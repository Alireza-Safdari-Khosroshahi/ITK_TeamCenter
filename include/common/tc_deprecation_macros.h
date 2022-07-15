/* 
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2020.
   Siemens Digital Industries Software.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/*==============================================================================
File description:
    Definitions of macros to handle deprecation.

==============================================================================*/

#ifndef INCLUDE_TC_DEPRECATION_MACROS_H
#define INCLUDE_TC_DEPRECATION_MACROS_H

#if defined(_MSC_VER)
#pragma once
#pragma warning(1:4996)
#pragma warning(1:4995)
#define TC_DEPRECATED(version,current,replacement) __declspec(deprecated(#current " deprecated in Teamcenter " #version "; Use " #replacement " instead.")) 
#define TC_DEPRECATED_WITH_DEPRECATION_INFO(version,current,replacement) __declspec(deprecated(#current " deprecated in " #version "; " #replacement ))
#define TC_DEPRECATED_NO_REPLACEMENT(version,current) __declspec(deprecated(#current " deprecated in Teamcenter " #version "; Please refer API documentation for alternate." )) 
#define TC_DEPRECATED_PREPROCESSOR( version,current,replacement )  __pragma(deprecated(#current))
#elif __GNUC__  
#define TC_DEPRECATED(version,current,replacement) __attribute__((deprecated(#current " deprecated in Teamcenter " #version "; Use " #replacement " instead.")))
#define TC_DEPRECATED_WITH_DEPRECATION_INFO(version,current,replacement) __attribute__((deprecated(#current " deprecated in " #version "; " #replacement)))
#define TC_DEPRECATED_NO_REPLACEMENT(version,current) __attribute__((deprecated(#current " deprecated in " #version "; Please refer API documentation for alternate." )))
#define TC_DEPRECATED_PREPROCESSOR( version,current,replacement )
#else
#define TC_DEPRECATED(version,current,replacement) 
#define TC_DEPRECATED_WITH_DEPRECATION_INFO(version,current,replacement)
#define TC_DEPRECATED_NO_REPLACEMENT(version,current) 
#define TC_DEPRECATED_PREPROCESSOR( version,current,replacement )
#endif


#endif /* INCLUDE_TC_DEPRECATION_MACROS_H */
