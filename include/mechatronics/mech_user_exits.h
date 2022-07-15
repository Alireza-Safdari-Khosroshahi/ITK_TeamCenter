/*==================================================
*  Copyright 2015.
*  Siemens Product Lifecycle Management Software Inc.
*  All Rights Reserved.
*  ==================================================*/

/**
    @file

    Custom Exit implementation for getDomain

*/

#ifndef MECH_USER_EXITS_H
#define MECH_USER_EXITS_H

/**
    @defgroup MECH_USER_EXITS Mechatronics User Exits
    @ingroup TC

    Teamcenter has implemented USER_get_domain user exit
    which is invoked if the design artifact type is not listed in a MECH_domain_types_ preference.

    @{
*/

#include <unidefs.h>
#include <mechatronics/libmechatronics_exports.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
    Customizable implementation to retrieve the domain name of a Design Artifact object.

    The code can be customized by registering a callback on this user exit, as explained in the code sample.
    If the registered callback returns with #ITK_ok and a decision of #NO_CUSTOMIZATION, the Teamcenter implementation is executed.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#TYPE_invalid_type_name if the Mechatronics Domain relation is not defined.
    <li>Possibly other errors.
    </ul>

    Sample of code to override USER_get_domain:
    <ul>
    <li>file cust1_register_callbacks.c
    @code
    #include <stdarg.h>
    #include <ug_va_copy.h>
    #include <tccore/custom.h>
    #include <cust1_register_callbacks.h>
    extern DLLAPI int cust1_register_callbacks()
    {
    return CUSTOM_register_exit ("cust1", "USER_get_domain", (CUSTOM_EXIT_ftn_t) CUST1_get_domain);
    }
    @endcode
    </li>

    <li>file cust1_register_callbacks.h
    @code
    #include <stdarg.h>
    #include <ug_va_copy.h>
    #include <ict/ict_userservice.h>
    extern DLLAPI int CUST1_get_domain(int *decision, va_list args);
    @endcode
    </li>

    <li>file cust1_functions.c
    @code
    #include <tc/tc_startup.h>
    #include <tccore/custom.h>
    #include <tccore/tctype.h>
    #include <base_utils/Mem.h>
    #include <cust1_register_callbacks.h>
    extern DLLAPI int CUST1_get_domain (int *decision, va_list args)
    {
    tag_t  obj_tag = va_arg (args, tag_t);
    char** domain_name = va_arg (args, char **);

    int ifail = ITK_ok;
    if( obj_tag != NULLTAG )
    {
        tag_t item_type_tag = NULLTAG;
        tag_t obj_type_tag = NULLTAG;
        ifail = TCTYPE_ask_type( "ItemRevision", &item_type_tag );
        ifail = TCTYPE_ask_object_type( obj_tag, &obj_type_tag );
        if ( obj_type_tag == item_type_tag )
        {
            *domain_name = MEM_sprintf("CUST1handlesItemsOnly");
            *decision = ONLY_CURRENT_CUSTOMIZATION;
        }
    }
    return ifail;
    }
    @endcode
    </li>
    </ul>
*/
extern MECHATRONICS_API int USER_get_domain(
    tag_t  design_artifact_tag,  /**< (I) The Design Artifact to search for its domain. */
    char** domain_name           /**< (OF) The domain name of this Design Artifact. */
);

/**
    Customizable implementation to retrieve the username and password for Mentor Capital Webservice.

    The code can be customized by registering a callback on this user exit, as explained in the code sample.
    If the registered callback returns with #ITK_ok and a decision of #NO_CUSTOMIZATION, the Teamcenter implementation is executed.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>Possibly other errors.
    </ul>

    Sample of code to override USER_get_domain:
    <ul>
    <li>file cust1_register_callbacks.c
    @code
    #include <stdarg.h>
    #include <ug_va_copy.h>
    #include <tccore/custom.h>
    #include <cust1_register_callbacks.h>
    extern DLLAPI int cust1_register_callbacks()
    {
    return CUSTOM_register_exit ("cust1", "USER_get_mentor_capital_credential", (CUSTOM_EXIT_ftn_t) CUST1_get_capital_user_credential);
    }
    @endcode
    </li>

    <li>file cust1_register_callbacks.h
    @code
    #include <stdarg.h>
    #include <ug_va_copy.h>
    #include <ict/ict_userservice.h>
    extern DLLAPI int CUST1_get_capital_user_credential(int *decision, va_list args);
    @endcode
    </li>

    <li>file cust1_functions.c
    @code
    #include <tc/tc_startup.h>
    #include <tccore/custom.h>
    #include <tccore/tctype.h>
    #include <base_utils/Mem.h>
    #include <cust1_register_callbacks.h>
    extern DLLAPI int CUST1_get_capital_user_credential (int *decision, va_list args)
    {
        // implement custom code
        *decision = ONLY_CURRENT_CUSTOMIZATION;

    }
    return ifail;
    }
    @endcode
    </li>
    </ul>
*/
extern MECHATRONICS_API int USER_get_mentor_capital_credential(
    char** username,          /**< (OF) The username to be used for invoking Mentor Capital webservice. */
    char** password           /**< (OF) The password to be used for invoking Mentor Capital webservice. */
);

/** @} */

#ifdef __cplusplus
}
#endif

#include <mechatronics/libmechatronics_undef.h>
#endif
