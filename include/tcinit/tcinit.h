/*
  Copyright 2020 Siemens Digital Industries Software
 ==================================================
 Copyright 2009.
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file tcinit.h

    This file contains the prototypes for basic top level Teamcenter ITK usage.
    It also contains a few include files that contain the prototypes that
    almost every ITK program will use.
*/

/*  */

#ifndef WEBITKAOS_H

#ifndef TCINIT_H
#define TCINIT_H


#include <tc/tc_startup.h>
#include <tcinit/libtcinit_exports.h>

/**
    @mainpage Introduction to the ITK Function Reference

    <H2>General Notes</H2>

    Function input arguments always precede output arguments.

    All ITK functions return the token #ITK_ok if successful and an integer error code if not successful.
    This allows a C program to test the return value as if it were a logical value, although in this case,
    0 (false) means success, and non-zero (true) means error.

    Many functions return data in memory which has been allocated internally.
    The relevant arguments are marked as:

    <B>(OF)</B>

    This data should be discarded when no longer needed, by calling #MEM_free with the relevant argument.

    If a function fails,
    it will usually return a <B>NULL</B> in the relevant argument instead of a pointer to valid data.
    This <B>NULL</B> need not be handed to the function #MEM_free as no internal allocation has occurred.
    However, since #MEM_free ignores <b>NULL</b> values, it is safe to pass it the <b>(OF)</b> argument
    whether the function failed or succeeded.

    Many functions perform the same operation on several instances,
    either explicitly listed ones or those resulting from the execution of an enquiry.
    If the operation fails on any one of the instances,
    then the function has no effect on any of the instances.

    Functions that fail while acting upon many instances will return the failure code associated with
    the first detected cause of failure and will immediately abort the operation.

    The naming convention for functions is:

    <B>XXX_name_definition</B>

    Where, <B>XXX</B> is the CAPITALIZED abbreviation for the module
    (e.g., POM for Persistent Object  Manager),
    <B>name</B> is an action and <B>definition</B> is an action modifier or object type.

    <H2>ITK Families and Generic Placeholders</H2>

    ITK contains many groupings of calls that can best be described as "families"
    because all members of the <I>family</I> perform the same function,
    but each member acts on a different type of data.

    In order to minimize redundancies and to promote usability,
    a generic placeholder \<type\> is consistently used to represent different
    <I>data types</I> in function names and in the arguments passed to these functions.

    Because of minor differences in the way memory is allocated to each data type,
    the actual substitutions for the generic placeholder (\<type\>) in
    arguments is often slightly different than the actual name of the data type.
    For example, consider the following ITK family:

    <B>PROP_set_value_\<type\></B>

    In order to call the function to set a <I>string</I> value,
    the data type <I>string</I> must be substituted for the generic placeholder
    <B>\<type\></B> in the function name. Therefore, the actual function name is:
    #AOM_set_value_string

    However, the argument passed to this function (as shown in the synopsis) is:
    <B>const char* value (I)</B>

    <H2>Generic Placeholder Substitution Table</H2>

    The following table lists each data type used by ITK families and provides the
    proper generic placeholder substitutions for both the function name and arguments.

    <TABLE>
    <TR><TD><b>Name</b>   </TD><TD><P><b>Argument</b> </TD><TD><b>Description</b>                     </TD></TR>
    <TR><TD><B>char</B>   </TD><TD><B>char</B>        </TD><TD>Single character                       </TD></TR>
    <TR><TD><B>date</B>   </TD><TD><B>date_t</B>      </TD><TD>Date                                   </TD></TR>
    <TR><TD><B>double</B> </TD><TD><B>double</B>      </TD><TD>Double-precision floating point decimal</TD></TR>
    <TR><TD><B>int</B>    </TD><TD><B>int</B>         </TD><TD>Integer                                </TD></TR>
    <TR><TD><B>logical</B></TD><TD><B>logical</B>     </TD><TD>Logical                                </TD></TR>
    <TR><TD><B>string</B> </TD><TD><B>char*</B><BR>
                                   <B>const char*</B> </TD><TD><P>Character string or note. The recommended practice is to use
                                                               <B>char*</B> for output arguments and <B>const char*</B> for
                                                               input arguments.                       </TD></TR>
    <TR><TD><B>tag</B></TD>    <TD><B>tag_t</B>       </TD><TD>Unique identifier of a reference (typed, untyped, or external )
                                                               or a relation (typed or untyped)       </TD></TR>
    </TABLE>

    @note Some ITK modules may not accept all of the above data types as substitutions for
    the \<type\> generic placeholder. These exceptions will be documented for each ITK module.
*/

/**
    @defgroup TC Integration Tool Kit
    @{
*/

/**
    @name Error message constants
    @{
*/
#define ITK_ok                  0
/** @} */

/** Default Text Mode for ITK Batch Program */
#define ITK_BATCH_TEXT_MODE     0


#ifdef __cplusplus
extern "C"
{
#endif

/**
    Attempts a login with the passed-in information.
*/
extern TCINIT_API int ITK_init_module(
    const char*     user_id,           /**< (I) The ID of the user to log-in */
    const char*     user_password,     /**< (I) The associated password */
    const char*     user_group         /**< (I) The group in which to log-in the user */
    );


/**
    Attempts an automatic login first by assuming sufficient data is available on the command line.

    @note If the site system administrator has set the TC_auto_login preference variable
    to TRUE in the site .tc_env preference file, the user does not need to enter in a user name,
    password, or group in the command line. The operating system user name is assumed.
    However, if the user wants to use a login name other than their operating system name,
    they may use the command line format:

    <b>your_program -u=\<user_id\> -p=\<password\> -g=\<group\> </b>
*/
extern TCINIT_API int ITK_auto_login(void);

/**
    This function initializes the Teamcenter environment for all ITK programs.

    <b>Restrictions:</b>

    If an ITK program has its own main() routine,
    this ITK function must be called before any other ITK routines.
    Otherwise, the ITK program must linked with the ITK_main.o module which
    performs the same function as this routine.
*/
extern TCINIT_API int ITK_init_from_cpp(
    int             argc,   /**< (I) Argument count from the main() routine */
    char**          argv    /**< (I) argc Array of arguments from the main() routine */
    );

extern TCINIT_API void ITK__initialise_tc(
    int  argc,                  /* <I> */
    char **  argv               /* <I> */
    );

/**
    This function can be used to print command line arguments  in syslog for ITK programs.
*/
extern TCINIT_API void ITK_log_cmdline_args(
    int             argc,   /**< (I) Argument count from the main() routine */
    char**          argv    /**< (I) argc Array of arguments from the main() routine */
    );


#ifdef __cplusplus
}
#endif

#include <tcinit/libtcinit_undef.h>

/** @} */

#endif
#endif
