/*=============================================================================
           Copyright (c) 1994 Electronic Data Systems Corporation
                   Unpublished - All rights reserved

   THIS PROGRAM IS AN UNPUBLISHED WORK FULLY PROTECTED BY THE UNITED STATES
  COPYRIGHT LAWS AND IS CONSIDERED A TRADE SECRET BELONGING TO THE COPYRIGHT
                                   HOLDER.
===============================================================================
H  File description:

    File   : exportedproxylink_errors.h
    Module : iman
===============================================================================
Date         Name                    Description of Change
====         ====                    =====================
18-Nov-2003  Ziv Israeli             Created
02-Jan-2004  Ziv Israeli             PL_invalid_date
06-Jan-2004  Ziv Israeli             PL_subscription_failed
13-Jan-2004  Ziv Israeli             PL_prop_update_failed
31-Jan-2004  Ziv Israeli             Preference errors
07-Oct-2004  israeli                 More errors
$HISTORY$
=============================================================================*/

#ifndef PL_ERRORS_H
#define PL_ERRORS_H

/**

    Error Conditions involving proxylink are listed below.

*/

/**Proxy creation failed*/
#define PL_no_create                          (EMH_PL_error_base + 1)

/**Invalid date*/
#define PL_invalid_date                       (EMH_PL_error_base + 3)

/**Property update failed*/
#define PL_prop_update_failed                 (EMH_PL_error_base + 5)

/**A proxy of that kind already exists*/
#define PL_obj_already_exists                 (EMH_PL_error_base + 6)

/**A few proxies of that kind already exist. Contact your sys.admin*/
#define PL_objs_already_exist                 (EMH_PL_error_base + 7)

/**A wrong type application name is provided*/
#define PL_wrong_type_name                    (EMH_PL_error_base + 8)

/**The requested object wasn't found*/
#define PL_obj_not_found                      (EMH_PL_error_base + 9)

/**A preference problem*/
#define PL_preference                         (EMH_PL_error_base + 10)

/**A preference problem (external properties)*/
#define PL_preference_prop_ext                (EMH_PL_error_base + 11)

/**A preference problem (internal properties)*/
#define PL_preference_prop_int                (EMH_PL_error_base + 12)

/**Number of ext/int property names doesn't match*/
#define PL_preference_ext_int_match           (EMH_PL_error_base + 13)

/**A proxy related type is missing*/
#define PL_type_is_missing                    (EMH_PL_error_base + 14)

/**The Teamcenter sites registered for linking or Remote Inbox Subscription could not be obtained.*/
#define PL_get_reg_eng_sites                  (EMH_PL_error_base + 15)

#endif
