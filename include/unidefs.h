/*HEAD UNIDEFS HHH INCLUDE */

#ifndef UNIDEFS_H_INCLUDED
#define UNIDEFS_H_INCLUDED

/*
 *  Common definitions for Unigraphics programming.
 *
 *  NOTE: This file is for use with ANSI compliant (or nearly so in the VMS
 *        case) compilers.  Keywords like "const" are always available and
 *        function prototyping is now expected to work.
 *
 *  See the "C Programming Standards" for details about the types and symbols
 *  defined here.
 *
 *  REVISIONS -
 *   RV DATE    WHO PR    REASON FOR CHANGE
 *   01 16MAR88 RDB       ADD NULENT, PI, TWOPI, RADEG, DEGRA
 *   02 14SEP88 RDB       Add EXIT_SUCCESS, EXIT_FAILURE and Upper case
 *			  names for UG types
 *   03 06JUN89 RDB       Correct definitions of FLOGICAL and FTRUE
 *   04 30MAY90 kdh       define FTCOMMON
 *   05 11JUN90 RDB       Add typedef for PVOID, define DEC and PROTO
 *   06 28JUN90 RDB       Combine all versions into one, using sysident.h,
 *                        and define BIG_ENDIAN or LITTLE_ENDIAN
 *   07 06JUL90 RDB       Remove lower case typedefs, disable prototypes on HP
 *   08 16JUL90 JLM       Restore lower case typedefs for one phase (II)
 *   09 05SEP90 KEJ       Remove EXIT_... definitions, add "const" {by corvese}
 *   10 09OCT90 KEJ       Correctly ifdef'ed FENTRY, added FCALL {by corvese}
 *   11 01NOV90 KEJ       Added SET_FPTR() and USE_FPTR() to be used when
 *                        passing a func to a FTN callable routine {by corvese}
 *   12 13NOV90 KEJ       Redid *_FPTR for dumb AOSVS C compiler {by corvese}
 *   13 04DEC90 KEJ       Support S700 (S300 front end compiler) {by corvese}
 *   14 30MAY91 TRS       DG Macro corrections (by smith)
 *   15 06JUN91 CVK       Add typedef for FSINGLE
 *   16 16SEP91 JLM       Add FTN macro for Fortran callability
 *   16 16SEP91 JLM       Add conditional inclusion for UNIDEFS
 *   16 23OCT91 JLM       Convert to 32 bit integers
 *   17 28FEB92 JLM       Make basic types 'int' instead of 'long'
 *   17 28FEB92 JLM       Add FSHORTINT type
 *   18 06MAR92 JLM       Make FENTITY unsigned
 *   19 03APR92 JLM       FTRUE s/b 1 instead of ~0 on HP Risc
 *   20 06APR92 JLM       Change FLONGINT to 'int' from 'long'
 *   21 04JUN92 RDB       Map the PROTO macro into a real prototype whenever
 *                           __STDC__ is 1;  remove AOSVS stuff
 *   22 13Jul92 jeh       Add typedef for caddr_t
 *   23 13Jul92 sch       check if type caddr_t defined or not before
 *                        doing typedef for it
 *   24 06Apr93 cdc       Used ANSI constructs to clean up definitions, fixed
 *                        SET_FPTR and USE_FPTR for ANSI, removed "extern" in
 *                        FT_COMMON(), created generic token pasting macro,
 *                        removed const define, always set PROTO() to work,
 *                        remove SYS card, and added IBM RS6000 dependencies.
 *   25 02May93 dn        Include stddef.h and do not define NULL here
 *   26 15May93 Reger     Removed BIG_ENDIAN/LITTLE_ENDIAN defines (use
 *                        DMAN/MACH code instead)
 *   27 26jun93 kdh       make it work on vms remove backslash
 *   28 03Jul93 Reger     OSF needs underscores from FTN macro
 *      21Jul93 BJS       Add logical, byte and tag typedefs
 *   29 23Sep93 KDH       For V10.2 remove sysident.h, use compile line switches
 *   29 29Sep93 KDH       Use intrinsic symbols where possible for machine type
 *   30 11oct93 kdh       change sgi to __sgi - sgi is only defined in K&R land
 *   31 13oct93 kdh       Workaround VAXC problem with FTRUE and FFALSE
 *   32 19Jul94 kdh       define TRUE and FALSE as 1 and 0
 *   33 25Jul94 jlm       remove _SOLARIS_SOURCE and _IRIX_SOURCE
 *   33                   condition token pasting on __STDC__ not VMS
 *   33                   do not mask redefinition of MACHINE_KNOWN
 *   33                   if qaz/lint define FLOGICAL as on VAX
 *   33                   remove hp +ppu compilation support
 *      24Jun94 MRA       Add date_t, true, false, constant, generic_routine_t
 *                                    conditional definitions (ready for obsoletion of basic.h)
 *                                    Also pick up definitions for SunOS (still used by IMan)
 *      29Jun94 MRA       Move null_date into clock.h to prevent shared library problems
 *      04Jul94 MRA       Don't define constant macro
 *      08Aug94 DRD       ip1 integration
 *      09Aug94 DRD       Macro paste done by comment hack on SunOS
 *      16Aug94 BJS       Add MAX and MIN macros
 *                          Force this to be "needed" for cc_check's dependency analysis
 *      26Aug94 MRA       Remove UNI_PASTE per Jack Marr
 *   34 05Aug94 dn        Remove extern modifier from FTCOMMON, thereby
 *                        restoring the FORTRAN COMMON storage model for
 *                        FCOMMON's within C object files: this is needed
 *                        by loadable modules
 *      30Aug94 DRD       define SUN to __sun on Solaris
 *   35 23Sep94 JLM       Windows NT (WNT) port
 *   36 02May95 Wei Liu   Redefine FTN()
 *   37 31May95 Wei Liu   Replace the definition of FTCOMMON for Bernie Solomon
 *   38 31May95 Wei Liu   Give a number -- 1 to WNT
 *   39 20Jun95 JLM       Add N_ELEMENTS macro
 *   40 30Jun95 JLM       Windows NT Intel port
 *   41 16Aug95 kdh       change msgtxt definition so that cc_check won't
 *			  complain, also drop logical cast from true and false
 *   42 10Aug95 JLM       WNTI: convert to append '_' in FTN
 *   43 17Jan96 kdh       Add CHECKING stuff
 *   44 16Aug96 BJS       Revise FLOGICAL types for qaz purposes
 *   45 10Apr97 Reger     Add F2C friendly definitions for tags
 *   46 24Sep97 JLM       Move FTCOMMON to ugextern.h, include that here
 *   47 24Feb98 Reger     Obsolete FSINGLE as a data type
 *   48 30May98 Reger     Remove checks for HP/CISC, SunOS, and VMS (all
 *                        obsolete); remove 'FCALL'/'fcall', 'FENTRY/fentry',
 *                        'USE_FPTR', 'SET_FPTR', 'FSHORTINT',
 *                        'FULONGINT/fulongint', 'FUINTEGER/fuinteger',
 *                        'flogical'
 *   49 16Jun98 Reger     Remove 'flongint'/'fentity'/'freal'
 *   50 31Jul98 Reger     Remove 'finteger'
 *   51 26Aug98 Reger     Remove 'FLONGINT'
 *   52 12Jan99 Reger     Remove 'FENTITY'
 *   53 14Jan99 JLM       Remove 'PROTO'
 *   54 21Jan99 JLM       Add qaz/cc_check definition of logical
 *   55 17Feb99 Reger     Add 'UGEXPORT' for Windows/NT
 *   56 22Mar99 Reger     Remove 'FINTEGER'/'FREAL'
 *   57 16Aug99 Reger     Relocate to generic INCLUDE product
 *   58 15Oct99 Reger     Remove 'ugextern.h' and 'checking.h'
 *   59 07Jun00 Jaskot    Added code for IA64 port
 *   60 25Oct2000 Reger   Obsolete WNTA; abandon WNTI -- use WNT instead;
 *                        abandon UGEXPORT in favor of DLL specific decorators
 *   61 25Oct00 JLM       Warn about nested inclusion
 *   62 05Jun01 HRT       Define HP64 for 64 bit
 *   63 24Jul2001 Reger   Retire OSF
 *   64 10Sep01 JLM       Add tag_pc_t
08-Apr-2003  Steve Kunkee            ARCH0015a: C++ compatibility
                                     add code to set up C_LINKAGE and C_LINKAGE_CPP
16-Apr-2003  Steve Kunkee            change CPLUSPLUS_COMPILE to __cplusplus
03-Jun-2003  KHafen                  Remove F2C_FILE
10-Jun-2003   Jack Marr              Test for wnt platform via _WIN32/_WIN64
24-Jul-2003  Jack Marr               Add HP IPF platform as HPI
24-Mar-2004  Keith Jaskot            Ported to x64 platform
03-Sep-2004  Jack Marr               Define FORCEINLINE
10-Sep-2004  jdh                     logical to bool project
20-Sep-2004  jdh                     more logical to bool project
21-Sep-2004  jdh                     fix comments for FTN macro
02-Nov-2004  Keith Jaskot	     Ported to SUSE Linux
 *$HISTORY$
 */

/*  <BJS> 15-Aug-94
    Force cc_check's dependency analysis to always assume
    unidefs.h is needed so it never warns to remove it.
    <JLM> 13-Sep-00
    The UG C Standards (Appendix C) require that unidefs.h be included by
    source files.  The top_level_only pragma will cause an error if the 
    first time this file is included is via nested header.  Fix this by
    including unidefs.h first in your source file (or after extended_source.h
    in those few files where that is required).  Eventually we'll 
    want to move the top_level_only pragma outside of the #ifndef 
    UNIDEFS_H_INCLUDED clause so as to warn about every nested inclusion, 
    not just when a source file doesn't directly include it.
*/
#ifdef __lint
#pragma uginclude needed
#pragma uginclude top_level_only
#pragma uginclude after_only "extended_source.h";
#endif

#include <stddef.h>

/* use the command line definition of symbols to define the platform we're on */
#if defined(__hpux)
/* We are on an HPUX system, define UNX and either HPP (PA-RISC) or HPI (Itanium) */
#define UNX   		1
#define HPUX   		1
#define MACHINE_KNOWN   1

/* <JLM> 18-Jun-02  Distinguish PA-RISC and IPF (Itanium Processor Family) */
#if defined(__hppa)
#define HPP             1
#elif defined(__ia64)
#define HPI             1
#else
#error Unknown flavor of HP-UX
#endif

/* <HRT> 05-Jun-01 
   This is for 64 bit HP Unix for all HP supported architectures.  This should only be defined 
   when +DA2.0W compile flag is used.
   <JLM> 17-Aug-01
   Move this bit inside of HPP test.  Also define HPP32.
   <JLM> 18-Jun-02
   HPP64 should be defined when +DA2.0W or +DD64 compile flags are used.
 */
#ifdef __LP64__
#define HPP64
#else
#define HPP32
#endif

#endif

#ifdef __sgi
/* We are on an SGI system, define UNX and SGI */
#ifndef SGI
#define SGI             6
#endif
#ifndef UNX
#define UNX   		1
#endif
#define MACHINE_KNOWN 1
#endif

#ifdef __sun
/* We are on a Solaris system, define UNX, SUN and SOLARIS */
#ifndef SUN
#define SUN             __sun
#endif
#ifndef SOLARIS
#define SOLARIS         1
#endif
#ifndef UNX
#define UNX   		1
#endif
#define MACHINE_KNOWN 1

/* <JLM> 17-Aug-01  Symbols to reveal data model. */
#ifdef _LP64
#define SOL64
#else
#define SOL32
#endif

#endif

#ifdef _AIX
/* We are on an IBM system, define UNX and IBM_AIX */
#ifndef IBM_AIX
#define IBM_AIX         5
#endif
#ifndef UNX
#define UNX   		1
#endif
#define MACHINE_KNOWN 1
#endif

/*
 Windows NT definitions

 WNT        - All Windows NT platforms (IA32 (Intel Pentium 32 bit),
              IA64 (Intel Itanium 64 bit)
 WNTI32     - Windows NT IA32 Pentium 32 bit ONLY
 WNTI64     - Windows NT IA64 Itanium 64 bit ONLY
 WNTX64     - Windows NT x64 Opteron or Coyote 64 bit ONLY
*/

/* <JLM> 10-Jun-03  
 * Changed test back to _WIN32 vs _WIN64 in order to support other 
 * compilers, specifically the gcc/g++ compiler used for qxdb generation 
 * and eventually qaz checking.  _WIN64 needs to be tested first since
 * _WIN32 is defined in both the _M_IX86 and _M_IA64 regimes.
 */

#if defined(_WIN64)
#if defined(_M_IA64)
/* We are on a 64 bit Itanium Intel system, define WNT and WNTI64 */
#define WNT           1
#define WNTI64		1
#define MACHINE_KNOWN 1

#elif defined(_M_AMD64)
/* We are on a 64 bit Opteron system, define WNT and WNTX64 */
#define WNT           1
#define WNTX64		1
#define MACHINE_KNOWN 1
#endif

#elif defined(_WIN32)
/* We are on a 32 bit Pentium Intel system, define WNT and WNTI32 */
#define WNT           1
#define WNTI32		1
#define MACHINE_KNOWN 1
#endif

/*
 SUSE Linux Definitions

 UNX Unix or Linux
 LNX64 SUSE Linux x86_64 only
*/

#if defined(__linux__) && defined(__x86_64__)
#define UNX             1
#define LNX64           1
#define MACHINE_KNOWN   1
#endif

#ifndef MACHINE_KNOWN
#error Sorry, you have to change unidefs.h to make this work on this machine
#endif

/* Using strict POSIX compliance on HP's, the caddr_t typedef is hidden. 
 * However it is defined in the Posix.1 namespace on all of our other platforms
 * and is used fairly widely, so we opt to explicitly define it here for hp.
 */
#if defined(HPP) && !defined(_CADDR_T)
#define _CADDR_T
typedef char *caddr_t;
#elif defined(WNT)
typedef char *caddr_t;
#endif

#ifndef TAG_T_DEFINED
#define TAG_T_DEFINED

typedef unsigned int tag_t, *tag_p_t;

typedef const tag_t * tag_pc_t;

#endif

/* <JLM> 25-Jul-94
 * For qaz/lint let's use the VMS definition of FLOGICAL
 * so as to catch circumvention of the typedef
 * <BJS> 16-Aug-96
 * Revise qaz/lint version of FLOGICAL to use special
 * type known to cc_check
 */
#if defined(__lint)
typedef __FLOGICAL      FLOGICAL;
#elif defined(WNT)
typedef int             FLOGICAL;
#else
typedef unsigned int    FLOGICAL;
#endif

/* Definition of TRUE and FALSE for FORTRAN when used from C */
/* <BJS> 16-Aug-96
 * Revise qaz/lint version of FTRUE/FFALSE to use special
 * definition known to cc_check
 */
#if defined(__lint)
#define FTRUE           __FTRUE
#define FFALSE          __FFALSE
#else
#define FTRUE           ((FLOGICAL) 1)
#define FFALSE          ((FLOGICAL) 0)
#endif

typedef void *PVOID;

/*  <BJS> 21-Jul-93
    The typedefs for logical, tag_t and byte have been copied
    here from basic.h and are individually protected against
    multiple definition. Reduces reliance on basic.h.
    <JLM> 20-Jan-99
    Use special definition of logical for cc_check purposes.
    <JDH> 06-sep-2004
    Change over to bool type.
*/
#ifndef LOGICAL_DEFINED
#define LOGICAL_DEFINED
#ifdef __cplusplus
typedef bool logical;
#else
typedef unsigned char logical;
#endif /* __cplusplus */
#endif /* LOGICAL_DEFINED */

#ifndef BYTE_DEFINED
#define BYTE_DEFINED
typedef unsigned char byte;
#endif

/* Postpend an '_' on FORTRAN symbols referenced from C (if needed) and QAZ.
 * <JLM> 27-Oct-03
 * Remove FTN test so we can detect redefinition, and add symbol to minimize
 * need to port code that needs to know about the need for an underscore.
 *
 * <JDH> no-op the FTN macro because we no longer support FORTRAN.
 */
#ifndef FTN
#define FTN(name) name
#endif

/*  <MRA> 24-Jun-94
    Definitions of true and false copied over from basic.h
    ready for its obsoletion.
    <KDH> 06-Sep-95
    Drop the logical cast for true and false, so they match TRUE and FALSE
*/
#ifndef __cplusplus
#ifndef true
#define true 1
#endif
#ifndef false
#define false 0
#endif
#endif
/*
    <KDH> 07-Jul-94
    Add definition of TRUE and FALSE
*/
#ifndef TRUE
#define TRUE  1
#endif
#ifndef FALSE
#define FALSE 0
#endif

/*  <BJS> 15-Aug-94
    And definitions of the common MIN/MAX macros.
*/
#ifndef MIN
#define MIN(a,b) (((a)<(b))?(a):(b))
#endif
#ifndef MAX
#define MAX(a,b) (((a)>(b))?(a):(b))
#endif

#define NULENT 0

#define PI     3.14159265358979324
#define TWOPI  6.28318530717958648
#define RADEG 57.29577951308235
#define DEGRA   .01745329251994328

/*  <MRA> 24-Jun-94
    Definitions of the null tag copied over from basic.h ready
    for basic.h's obsoletion.
*/
#ifndef NULL_TAG
#define NULL_TAG      ((tag_t)0)
#endif
#ifndef null_tag
#define null_tag      ((tag_t)0)
#endif

#ifndef DATE_T_DEFINED
#define DATE_T_DEFINED
/*  Structure for holding dates
    When saved this ought to be in GMT/UTC

    Now values are:
        year   - 1989
        month  - 0..11
        day    - 1..28/29/30/31
        hour   - 0..23
        minute - 0..59
        second - 0..59

    <MRA> 24-Jun-94
    Copied over from basic.h ready for basic.h's obsoletion.

    <MRA> 29-Jun-94
    null_date now in clock.h instead to prevent shared library
    confusion.
*/

typedef struct date_s
   { short year;
     byte month;
     byte day;
     byte hour;
     byte minute;
     byte second;
   } date_t, *date_p_t;
#endif

/*  <ARMB>  7-May-93
    Casting to void* does not necessarily work for function pointers,
    but all function pointer types can be cast to each other, so long as they
    are correctly cast back before using to call.
    Here is a type for things that take different function pointers to be cast
    too.

    <MRA> 24-Jun-94
    Copied over from basic.h ready for basic.h's obsoletion.
*/
#ifndef GENERIC_ROUTINE_T_DEFINED
#define GENERIC_ROUTINE_T_DEFINED
typedef void* (*generic_routine_t)(void);
#endif

/*  <MRA> 12-Feb-93
    This macro is wrapped around UG strings that need to be converted to
    users' native languages (NLM).  Since some of these strings are present
    in the OM error reporting code, the definition needs to be in a file
    available to all UG code and to Infomanager code too.

    <MRA> 24-Jun-94
    Copied over from basic.h ready for basic.h's obsoletion.
    <kdh> 16-Aug-95
    MSGTXT used to be defined as MSGTXT(s) (s)  This caused qaz errors, so
    we have simplified the definition.
    <JLM> 17-Aug-01
    Remove redefinition protection, since we really want to know about that.
*/

#define MSGTXT(s) s

/* 
 *  <JLM> 20-Jun-95
 *  Macro N_ELEMENTS which determines the number of elements in an
 *  array of any type.  Example usage:
 *	qsort(list, N_ELEMENTS(list), sizeof(list[0]), compare);
 *	for (indx=0; indx<N_ELEMENTS(list); indx++) {
 */
#define N_ELEMENTS(array) (sizeof(array)/sizeof(array[0]))

/*  <SDK> 24-Feb-2003
    These macros are used to ensure that under a C++ compile the symbols
    found in LDR_find_symbol calls are C linkage.  C_LINKAGE must always
    be defined, either "C" or empty.
*/
#ifdef __cplusplus
#define C_LINKAGE "C"
#else
#define C_LINKAGE
#endif

/*  <JLM> 03-Sep-04
 *  Macro FORCEINLINE *mandates* that a function be inlined on platforms that
 *  support such a feature (currently only Windows).  This macro should be 
 *  used sparingly.  In general you should use the "inline" keyword to *ask* 
 *  that a function be inlined, rather than mandate it.  
 *
 *  From the MS documentation:
 *	The __forceinline keyword overrides the cost/benefit analysis 
 *	and relies on the judgment of the programmer instead. Exercise 
 *	caution when using __forceinline. Indiscriminate use of 
 *	__forceinline can result in larger code with only marginal 
 *	performance gains or, in some cases, even performance losses 
 *	(due to increased paging of a larger executable, for example).
 */
#ifndef FORCEINLINE
#if (_MSC_VER >= 1200)
#define FORCEINLINE __forceinline
#elif defined(__cplusplus)
#define FORCEINLINE inline
#else
#define FORCEINLINE
#endif
#endif

#endif /* UNIDEFS_H_INCLUDED */
