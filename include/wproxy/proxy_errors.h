/*=============================================================================
           Copyright (c) 1994 Electronic Data Systems Corporation
                   Unpublished - All rights reserved

   THIS PROGRAM IS AN UNPUBLISHED WORK FULLY PROTECTED BY THE UNITED STATES
  COPYRIGHT LAWS AND IS CONSIDERED A TRADE SECRET BELONGING TO THE COPYRIGHT
                                   HOLDER.
===============================================================================
H  File description:

    File   : proxy_errors.h
    Module : iman
===============================================================================
Date         Name                    Description of Change
====         ====                    =====================
03-Aug-2004  Ziv Israeli             Created
21-Sep-2004  Ziv Israeli             PROXY_push_to_master
07-Oct-2004  israeli                 More errors
15-Oct-2004  Ziv Israeli             Checking in
30-Nov-2004  israeli                 More msg's
06-Jan-2005  israeli                 generic error
28-Feb-2005  dasatish                merge
23-Mar-2005  israeli                 PROXY_generic_message_remotely
29-Mar-2005  israeli                 Msg
$HISTORY$
=============================================================================*/

#ifndef PROXY_ERRORS_H
#define PROXY_ERRORS_H

/**

    Error Conditions involving proxy are listed below.

*/


/**Failed contacting application registry. Either it is down or preference TC_external_app_reg_url is not set.*/
#define PROXY_contacting_app_reg                   (EMH_PROXY_error_base + 1)

/**The preference TC_external_app_reg_url is missing*/
#define PROXY_app_reg_preference                   (EMH_PROXY_error_base + 2)

/**The preference TC_external_local_app_guid is missing*/
#define PROXY_local_guid_preference                (EMH_PROXY_error_base + 3)

/**The application couldn't be found in the app.registry*/
#define PROXY_app_url_not_in_app_reg               (EMH_PROXY_error_base + 4)

/**Failed contacting the SOAP server. Soap error - %1$*/
#define PROXY_contacting_soap_server               (EMH_PROXY_error_base + 5)

/**The "push update" call failed*/
#define PROXY_push_update                          (EMH_PROXY_error_base + 6)

/**The "push update" call failed remotely with the error: %1$*/
#define PROXY_push_update_remotely                 (EMH_PROXY_error_base + 7)

/**The "object no longer referenced" call failed*/
#define PROXY_obj_no_longer_ref                    (EMH_PROXY_error_base + 8)

/**The "object no longer referenced" call failed remotely with the error: %1$*/
#define PROXY_obj_no_longer_ref_remotely           (EMH_PROXY_error_base + 9)

/**The "object deleted" call failed*/
#define PROXY_del_exp_obj                          (EMH_PROXY_error_base + 10)

/**The "object deleted" call failed remotely with the error: %1$*/
#define PROXY_del_exp_obj_remotely                 (EMH_PROXY_error_base + 11)

/**The "object referenced" call failed*/
#define PROXY_obj_referenced                       (EMH_PROXY_error_base + 12)

/**The "object referenced" call failed remotely with the error: %1$*/
#define PROXY_obj_referenced_remotely              (EMH_PROXY_error_base + 13)

/**The "push properties to master" call failed*/
#define PROXY_push_to_master                       (EMH_PROXY_error_base + 14)

/**The "push properties to master" call failed remotely with the error: %1$*/
#define PROXY_push_to_master_remotely              (EMH_PROXY_error_base + 15)

/**Failed to get a new authentication key*/
#define PROXY_new_auth_key                         (EMH_PROXY_error_base + 16)

/**The "get remote inbox" call failed*/
#define PROXY_get_remote_inbox                     (EMH_PROXY_error_base + 17)

/**The "get remote inbox" call failed remotely with the error: %1$*/
#define PROXY_get_remote_inbox_remotely            (EMH_PROXY_error_base + 18)

/**The "get remote properties" call failed*/
#define PROXY_get_remote_props                     (EMH_PROXY_error_base + 19)

/**The "get remote properties" call failed remotely with the error: %1$*/
#define PROXY_get_remote_props_remotely            (EMH_PROXY_error_base + 20)

/**Event parameters are missing*/
#define PROXY_event_params_are_missing             (EMH_PROXY_error_base + 21)

/**Posting event failed*/
#define PROXY_post_event                           (EMH_PROXY_error_base + 22)

/**Generic error*/
#define PROXY_generic_message                      (EMH_PROXY_error_base + 23)

/**The call %1$ failed remotely with the error: %2$*/
#define PROXY_generic_message_remotely             (EMH_PROXY_error_base + 24)

/**The "destroy process link" call failed*/
#define PROXY_destroy_process_link                 (EMH_PROXY_error_base + 25)

/**The "destroy process link" call failed remotely with the error: %1$*/
#define PROXY_destroy_process_link_remotely        (EMH_PROXY_error_base + 26)

/**The string received for a proxy call is not as expected. Please process the request again.*/
#define PROXY_xml_resp_rcvd_corrupted              (EMH_PROXY_error_base + 27)

/**An error has occurred while retrieving the SOA client for the site "%1$" in order to make a proxy call. Please process the request again.*/
#define PROXY_error_getting_soa_service            (EMH_PROXY_error_base + 28)

#endif
