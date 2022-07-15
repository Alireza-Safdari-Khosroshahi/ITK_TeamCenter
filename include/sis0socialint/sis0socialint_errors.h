/*
Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright 2018.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file sis0socialint_errors.h

    SIS0SOCIALINT Error Codes Declaration

*/

#ifndef SIS0SOCIALINT_ERRORS_H
#define SIS0SOCIALINT_ERRORS_H
#include <common/tc_deprecation_macros.h>
/**
@defgroup SIS0SOCIALINT_ERRORS  Errors for Team Collaboration Integration functionality
*/

/**
@defgroup SIS0SOCIALINT_GENERAL General Errors
@ingroup SIS0SOCIALINT_ERRORS
@{
*/

/** @deprecated #SIS0_internal_error_posting_to_slack deprecated in Teamcenter 12.2. Use #SIS0_internal_error_posting_to_slack instead */
#define SIS0_internal_error_posting_to_slack                (EMH_SIS0SOCIALINT_error_base +   0 )
TC_DEPRECATED_PREPROCESSOR("12.2", SIS0_internal_error_posting_to_slack, "SIS0_internal_error_posting_to_slack" );

/**  An internal error has occurred while attempting to post to the social application via the Team Collaboration Integration. Please view the syslog file for details. */
#define SIS0_internal_error_posting_to_social               (EMH_SIS0SOCIALINT_error_base +   0 )

/** The URL to the Team Collaboration Integration could not be found. Please ensure that the value of the environment variable "SIS" is valid. */
#define SIS0_undefined_sis_url                              (EMH_SIS0SOCIALINT_error_base +   1 )

/** @deprecated #SIS0_undefined_slack_channel deprecated in Teamcenter 12.2. Use #SIS0_undefined_channel instead */
#define SIS0_undefined_slack_channel                        (EMH_SIS0SOCIALINT_error_base +   2 )
TC_DEPRECATED_PREPROCESSOR("12.2", SIS0_undefined_slack_channel, "SIS0_undefined_channel" );

/** No valid value is provided for the social application channel. */
#define SIS0_undefined_channel                              (EMH_SIS0SOCIALINT_error_base +   2 )

/** @deprecated #SIS0_undefined_slack_workspace_id deprecated in Teamcenter 12.2. Use #SIS0_undefined_id instead */
#define SIS0_undefined_slack_workspace_id                   (EMH_SIS0SOCIALINT_error_base +   3 )
TC_DEPRECATED_PREPROCESSOR("12.2", SIS0_undefined_slack_workspace_id, "SIS0_undefined_id" );

/** No valid value is provided for the social application integration ID. */
#define SIS0_undefined_id                                   (EMH_SIS0SOCIALINT_error_base +   3 )

/** No message is provided to be posted. */
#define SIS0_undefined_message                              (EMH_SIS0SOCIALINT_error_base +   4 )

/** The HMAC (Hash Message Authentication Code) cannot be generated to post to the Team Collaboration Integration. Please view the syslog file for details. */
#define SIS0_unable_to_generate_hmac                        (EMH_SIS0SOCIALINT_error_base +   5 )

/** No valid value is provided for the "TC_ZEUS_ACCESS_KEY_ID" environment variable. */
#define SIS0_undefined_tc_zeus_access_key_id                (EMH_SIS0SOCIALINT_error_base +   6 )

/** No valid value is provided for the "TC_ZEUS_ACCESS_PASSWORD_FILE" environment variable. */
#define SIS0_undefined_tc_zeus_access_password_file         (EMH_SIS0SOCIALINT_error_base +   7 )

/** Please contact your system administrator. The following error was returned from the TCI (Team Collaboration Integration) microservice: %1$ */
#define SIS0_error_returned_from_tci                        (EMH_SIS0SOCIALINT_error_base +   8 )

/** No valid value is provided for the social application type */
#define SIS0_undefined_social_app_type                      (EMH_SIS0SOCIALINT_error_base +   9 )

/** No valid value is provided for the redirect URI. */
#define SIS0_undefined_redirect_uri                         (EMH_SIS0SOCIALINT_error_base +   10 )

/** An error has occurred while invoking the TCI (Team Collaboration Integration) microservice. Please contact your system administrator. */
#define SIS0_error_invoking_tci                             (EMH_SIS0SOCIALINT_error_base +   11 )

/** @} */

#endif
