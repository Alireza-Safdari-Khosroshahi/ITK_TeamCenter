/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Defines error codes used with MAIL.
*/

/*  */

#ifndef MAIL_ERRORS_H
#define MAIL_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup MAIL_ERRORS Errors
    @ingroup MAIL
    @{
*/

#define  MAIL_finding_distribution_list        (EMH_MAIL_error_base + 1)
#define  MAIL_no_subject                       (EMH_MAIL_error_base + 2)
#define  MAIL_class_cant_receive               (EMH_MAIL_error_base + 3)
#define  MAIL_refreshing_mailbox               (EMH_MAIL_error_base + 4)
#define  MAIL_inserting_to_mailbox             (EMH_MAIL_error_base + 5)
#define  MAIL_saving_mailbox                   (EMH_MAIL_error_base + 6)
#define  MAIL_no_receivers_in_pomtaglist       (EMH_MAIL_error_base + 7)
#define  MAIL_empty_group                      (EMH_MAIL_error_base + 8)
#define  MAIL_empty_dl                         (EMH_MAIL_error_base + 9)
#define  MAIL_invalid_arg                      (EMH_MAIL_error_base + 10)
#define  MAIL_no_receivers                     (EMH_MAIL_error_base + 11)
#define  MAIL_user_not_found                   (EMH_MAIL_error_base + 12)
#define  MAIL_cant_change_envelope_access      (EMH_MAIL_error_base + 13)
#define  MAIL_finding_alias_list               (EMH_MAIL_error_base + 14)
#define  MAIL_empty_al                         (EMH_MAIL_error_base + 15)
#define  MAIL_preferences_absent               (EMH_MAIL_error_base + 16)
#define  MAIL_no_alias_name                    (EMH_MAIL_error_base + 17)
#define  MAIL_no_alias_address                 (EMH_MAIL_error_base + 18)
#define  MAIL_duplicate_alias                  (EMH_MAIL_error_base + 19)
#define  MAIL_no_selection                     (EMH_MAIL_error_base + 20)
#define  MAIL_not_mailable                     (EMH_MAIL_error_base + 21)
#define  MAIL_only_datasets_allowed            (EMH_MAIL_error_base + 22)
#define  MAIL_no_namedreferences               (EMH_MAIL_error_base + 23)
#define  MAIL_duplicate_selection              (EMH_MAIL_error_base + 24)
#define  MAIL_no_Text_namedreferences          (EMH_MAIL_error_base + 25)
#define  MAIL_only_one_selection_include       (EMH_MAIL_error_base + 26)
#define  MAIL_invalid_object                   (EMH_MAIL_error_base + 27)
#define  MAIL_no_objects_selected              (EMH_MAIL_error_base + 28)
#define  MAIL_os_mail_failure                  (EMH_MAIL_error_base + 29)
#define  MAIL_recipient_not_found              (EMH_MAIL_error_base + 30)
#define  MAIL_user_email_address_not_found     (EMH_MAIL_error_base + 31)
#define  MAIL_server_name_not_found            (EMH_MAIL_error_base + 32)
#define  MAIL_OSMail_deactivated               (EMH_MAIL_error_base + 33)

/**
    @name Error codes for tc_mail_smtp utility

    Note that tc_mail_smtp returns error codes in the range 201-216.
    These are then mapped into the MAIL_SMTP_base range.
    @{
*/

#define  MAIL_SMTP_base                         (EMH_MAIL_error_base + 70)

#define  MAIL_SMTP_uo_att_list_file             (MAIL_SMTP_base + 1)
#define  MAIL_SMTP_uo_attachment_file           (MAIL_SMTP_base + 2)
#define  MAIL_SMTP_no_to_list                   (MAIL_SMTP_base + 3)
#define  MAIL_SMTP_uo_body_file                 (MAIL_SMTP_base + 4)
#define  MAIL_SMTP_no_data_to_send              (MAIL_SMTP_base + 5)
#define  MAIL_SMTP_invalid_file_format          (MAIL_SMTP_base + 6)
#define  MAIL_SMTP_u_create_socket              (MAIL_SMTP_base + 7)
#define  MAIL_SMTP_u_connect_server             (MAIL_SMTP_base + 8)
#define  MAIL_SMTP_u_get_user_name              (MAIL_SMTP_base + 9)
#define  MAIL_SMTP_uc_session_with_mail_server  (MAIL_SMTP_base + 10)
#define  MAIL_SMTP_all_receipents_unknown       (MAIL_SMTP_base + 11)
#define  MAIL_SMTP_u_command_line_argument      (MAIL_SMTP_base + 12)
#define  MAIL_SMTP_uo_session_with_mail_server  (MAIL_SMTP_base + 13)
#define  MAIL_SMTP_u_get_domain_name            (MAIL_SMTP_base + 14)
#define  MAIL_SMTP_u_send_data                  (MAIL_SMTP_base + 15)
#define  MAIL_SMTP_no_subject                   (MAIL_SMTP_base + 16)
#define  MAIL_SMTP_bad_recipient                (MAIL_SMTP_base + 17)
#define  MAIL_SMTP_uo_tolist_file               (MAIL_SMTP_base + 18)
#define  MAIL_SMTP_uo_body_file_length          (MAIL_SMTP_base + 19)

/**
* The mail server could not connect using the given SSL/TLS protocol.
*/
#define  MAIL_SMTP_ssl_connect_unknownprotocol  (MAIL_SMTP_base + 20)

/**
* The value for the SSL/TLS protocol as given by the preference "%1$" is incorrect.
*/
#define  MAIL_SMTP_ssl_protocol_input_invalid   (MAIL_SMTP_base + 21)

/**
* An unknown SSL error has occurred. Please contact your system administrator.
*/
#define  MAIL_SMTP_unknown_ssl_error            (MAIL_SMTP_base + 22)

/**
* The initialization of the Teamcenter System Crypto has failed. Please contact your system administrator.
*/
#define  MAIL_SMTP_ssl_crypto_failure           (MAIL_SMTP_base + 23)

/**
* The password file either does not exist or is empty.
*/
#define  MAIL_SMTP_auth_no_passwd               (MAIL_SMTP_base + 24)

/**
* The connection security using STARTTLS has failed. Verify the connection security configuration in the mail server.
*/
#define  MAIL_SMTP_starttls_with_mail_server_f  (MAIL_SMTP_base + 25)

/**
* Email authentication with the mail server has failed.
*/
#define  MAIL_SMTP_email_authentication_failed  (MAIL_SMTP_base + 26)

/**
* The value for the Authentication as given by the preference "%1$" is incorrect.
*/
#define  MAIL_SMTP_auth_input_invalid           (MAIL_SMTP_base + 27)

/**
* The value for the Connection Security as given by the preference "%1$" is incorrect.
*/
#define  MAIL_SMTP_conn_security_input_invalid  (MAIL_SMTP_base + 28)

/** @} */

/** @} */

#endif
