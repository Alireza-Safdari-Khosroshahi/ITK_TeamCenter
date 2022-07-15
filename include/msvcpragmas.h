/*HEAD MSVCPRAGMAS HHH INCLUDE */
/*SYS WNT */
/*==============================================================================

             Copyright (c) 1999,2000 Unigraphics Solutions Inc.
                     Unpublished - All rights reserved

================================================================================
File description:

    This header is included on Windows NT at the beginning of every
    source file via the Forced Include mechanism (compiler option /FI).
    It provides a means of adjusting warning levels for Visual C++
    compiler warning messages so that some messages may be made more
    (or less) visible.

==============================================================================*/

#ifndef MSVCPRAGMAS_H_INCLUDED
#define MSVCPRAGMAS_H_INCLUDED

/*
 * The intent is to eventually make each of the following messages an error.
 * This has not been done yet in order to minimize the impact on development.
 */

#pragma warning (  error : 4002 ) /* too many actual parameters for macro */
#pragma warning (  error : 4003 ) /* not enough actual parameters for macro */
#pragma warning (  error : 4005 ) /* macro redefinition */
#pragma warning (  error : 4013 ) /* function undefined (no prototype seen) */
#pragma warning (  error : 4016 ) /* assuming func returns int (no prototype seen) */
#pragma warning (  error : 4018 ) /* signed/unsigned mismatch */
#pragma warning (  error : 4020 ) /* too many arguments in definition vs proto */
#pragma warning (  error : 4021 ) /* too few arguments in definition vs proto */
#pragma warning (  error : 4022 ) /* argument mismatch esp. w/pointers */
#pragma warning (  error : 4024 ) /* argument mismatch */
#pragma warning (  error : 4028 ) /* formal parameter differs from declaration */
#pragma warning (  error : 4031 ) /* 2nd paramter list longer (conflicting proto) */
#pragma warning (  error : 4033 ) /* no return value for function */
#pragma warning (  error : 4035 ) /* no return value for function */
#pragma warning (  error : 4047 ) /* differing levels of indirection */
#pragma warning (  error : 4048 ) /* differently declared array subscripts */
#pragma warning (  error : 4060 ) /* switch statement contains no ‘case’ or ‘default’ labels */
#pragma warning (  error : 4065 ) /* switch has default but no case statements */
#pragma warning (  error : 4070 ) /* return of void expression */
#pragma warning (  error : 4071 ) /* no function prototype given */
#pragma warning (  error : 4090 ) /* different qualifiers */
#pragma warning (  error : 4100 ) /* unreferenced formal parameter */
#pragma warning (  error : 4101 ) /* unreferenced local variable */
#pragma warning (  error : 4102 ) /* unreferenced label */
#pragma warning (  error : 4113 ) /* function pointer arg list differs */
#pragma warning (  error : 4129 ) /* unrecognized character escape sequence */
#pragma warning (  error : 4130 ) /* logical op on address of string constant */
#pragma warning (  error : 4150 ) /* deletion of pointer to incomplete type ‘type’; no destructor called */
#pragma warning (  error : 4131 ) /* uses old-style (K&R) declarator */
#pragma warning (  error : 4133 ) /* incompatible types */
#pragma warning (  error : 4138 ) /* nested comment */
#pragma warning (  error : 4172 ) /* returning address of local variable */
#pragma warning (  error : 4189 ) /* local variable initialized but never used */
#pragma warning (  error : 4190 ) /* 'identifier1' has C-linkage specified, but returns UDT 'identifier2' which is incompatible with C */
#pragma warning (  error : 4197 ) /* ‘type’ : top-level volatile in cast is ignored */
#pragma warning (  error : 4243 ) /* inaccesible type cast conversion */
#pragma warning (  error : 4244 ) /* ‘conversion’ conversion from ‘type1’ to ‘type2’, possible loss of data */
#pragma warning (  error : 4273 ) /* inconsistent DLL linkage */
#pragma warning (  error : 4275 ) /* non – DLL-interface classkey ‘identifier’ used as base for DLL-interface classkey ‘identifier’ */
#pragma warning (  error : 4290 ) /* C++ exception specification ignored except to indicate a function is not __declspec(nothrow) */
#pragma warning (  error : 4291 ) /* no matching delete; memory will not be freed if initialization throws */
#pragma warning (  error : 4293 ) /* new in default argument will not free memory if initialization throws an exception */
#pragma warning (  error : 4297 ) /* ‘function’ : function assumed not to throw an exception but does */
#pragma warning (  error : 4301 ) /* overriding virtual function differs in qualifier */
#pragma warning (  error : 4305 ) /* ‘identifier’ : truncation from ‘type1’ to ‘type2’ */
#pragma warning (  error : 4309 ) /* ‘conversion’ : truncation of constant value */
#pragma warning (  error : 4310 ) /* cast truncates constant value */
#pragma warning (  error : 4311 ) /* ‘variable’ : pointer truncation from ‘type’ to ‘type */
#pragma warning (  error : 4312 ) /* ‘operation’ : conversion from ‘type1’ to ‘type2’ of greater size */
#pragma warning (  error : 4313 ) /* pointer type mismatch in printf-like statements */
#pragma warning (  error : 4318 ) /* zero length used in memset */
#pragma warning (  error : 4333 ) /* ‘operator’ : right shift by too large amount, data loss */
#pragma warning (  error : 4351 ) /* new behavior: elements of array ‘array’ will be default initialized */
#pragma warning (  error : 4355 ) /* 'this' : used in base member initializer list */
#pragma warning (  error : 4373 ) /* previous versions of the compiler did not override when parameters only differed by const/volatile qualifiers */
#pragma warning (  error : 4390 ) /* empty statement following control statement */
#pragma warning (  error : 4407 ) /* cast between different pointer to member representations, compiler may generate incorrect code */
#pragma warning (  error : 4503 ) /* 'identifier' : decorated name length exceeded, name was truncated */
#pragma warning (  error : 4505 ) /* unreferenced local function */
#pragma warning (  error : 4522 ) /* ‘class’ : multiple assignment operators specified */
#pragma warning (  error : 4535 ) /* calling _set_se_translator() requires /EHa */
#pragma warning (  error : 4550 ) /* expression evaluates to function missing argument list */
#pragma warning (  error : 4553 ) /* operator has no effect */
#pragma warning (  error : 4554 ) /* possible operator precedence error */
#pragma warning (  error : 4700 ) /* variable used without being initialized */
#pragma warning (  error : 4701 ) /* variable may be used without being init'd */
#pragma warning (  error : 4706 ) /* assignment in conditional (i = 0 instead of i == 0) */
#pragma warning (  error : 4715 ) /* not all paths return a value */
#pragma warning (  error : 4716 ) /* function must return a value */
#pragma warning (  error : 4717 ) /* infinite recursion */
#pragma warning (  error : 4761 ) /* integral mismatch; conversion supplied */
#pragma warning (  error : 4789 ) /* destination of memory copy is too small */
#pragma warning (  error : 4800 ) /* forcing value to bool (performance warning) */
#pragma warning (  error : 4804 ) /* ‘operation’ : unsafe use of type ‘bool’ in operation */
#pragma warning (  error : 4805 ) /* ‘operation’ : unsafe mix of type ‘type’ and type ‘type’ in operation */
#pragma warning (  error : 4809 ) /* switch statement has redundant ‘default’ label; all possible ‘case’ labels are given */
#pragma warning (  error : 4822 ) /* ‘member’ : local class member function does not have a body */
#pragma warning (  error : 4930 ) /* ‘prototype’: prototyped function not called (was a variable definition intended?) */
/* Demoted the warning 4995 from error because we need to display warning 4995 when any usage of
   a deprecated preprocessor directive is encountered during compilation. */
/* #pragma warning (  error : 4995 )  deprecated streams usage  */


/* This is frequently generated when using STL.  MSDN suggests disabling. */
#pragma warning ( disable: 4786 ) /* identifier truncated in debugger/browser */

/* disable these -- at least for now ... */
#pragma warning ( disable: 4250 ) /* inheritance via dominance */
#pragma warning ( disable: 4251 ) /* non-DLL interface with STL involved */
#pragma warning ( disable: 4267 ) /* possible loss of data on conversion */

#endif /* MSVCPRAGMAS_H_INCLUDED */
