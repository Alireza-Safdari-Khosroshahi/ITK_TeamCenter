/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2014.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/** 
    @file 
    Defines the errors for the Teamcenter Integration Framework module
*/
#ifndef TCIF_ERRORS_H
#define TCIF_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup TCIF_ERRORS Teamcenter Integration Framework Errors
    @ingroup TCIF
    @{
*/
#define TCIF_ERROR_BASE                           EMH_TCIF_error_base


/** 
    Failed to login to Teamcenter Integration Framework.
*/
#define TCIF_login_failure                                            (TCIF_ERROR_BASE + 1)

/**
    The Teamcenter Integration Framework event for the object with ID "%$1" cannot be found. Please contact your system administrator.
*/
#define TCIF_event_not_found                                        (TCIF_ERROR_BASE + 2)

/**
    One or more SOAP errors were returned from Teamcenter Integration Framework server. Verify that the Teamcenter Integration server is started and try sending the message again.
 */
#define TCIF_soap_error                                                (TCIF_ERROR_BASE + 3)

/**
    The creation of a Teamcenter Integration Framework event object has failed due to errors in the input arguments.
*/
#define TCIF_create_input_failure                                    (TCIF_ERROR_BASE + 4)

/**
    The deletion of the object with ID "%1$" has failed due to a pre-condition mismatch. Please check the object deletion privilege.
*/
#define TCIF_delete_not_allowed                                        (TCIF_ERROR_BASE + 5)

/**
    An event state "%1$" was expected from the Teamcenter Integration Framework server, but an event state %2$ was received instead. Please contact your system administrator.
*/
#define TCIF_event_state_unexpected                                    (TCIF_ERROR_BASE + 6)

/**
    The Teamcenter event type "%1$" cannot be found. Please verify that the Teamcenter event type is defined.
*/
#define TCIF_event_type_not_found                                    (TCIF_ERROR_BASE + 7)

/**
    The logging-in into Teamcenter Integration Framework has failed due to missing or invalid value in preference %1$ .
*/
#define TCIF_login_failure_invalid_pref                                (TCIF_ERROR_BASE + 8)

/**
    The logging-in into Teamcenter Integration Framework has failed due to the failure to obtain its SSO token from TcSS.
*/
#define TCIF_failed_to_obtain_sso_token                                (TCIF_ERROR_BASE + 9)

/**
    The login process has failed during REST request: %1$
*/
#define TCIF_rest_request_login_failure                                (TCIF_ERROR_BASE + 10)

/**
    The login process has failed during REST request: HTTP response code %1$
*/
#define TCIF_rest_request_login_failure_http_res_code                (TCIF_ERROR_BASE + 11)

/**
    REST request has failed: %1$
*/
#define TCIF_rest_request_failure                                    (TCIF_ERROR_BASE + 12)

/**
    REST request has failed: HTTP response code %1$
*/
#define TCIF_rest_request_failure_http_res_code                        (TCIF_ERROR_BASE + 13)

/**
    The logout process has failed during REST request: %1$
*/
#define TCIF_rest_request_logout_failure                            (TCIF_ERROR_BASE + 14)

/**
    The logout process has failed during REST request: HTTP response code %1$
*/
#define TCIF_rest_request_logout_failure_http_res_code              (TCIF_ERROR_BASE + 15)

/**
    Prior to Teamcenter Integration Framework REST request, message initialization has failed due to GSOAP data binding error code %1$
*/
#define TCIF_rest_message_init_failure                                (TCIF_ERROR_BASE + 16)

/**
    Commencement of Teamcenter Integration Framework workflow has failed at Teamcenter site %1$ for object %2$ due to: \n%3$
*/
#define TCIF_rest_workflow_commencement_failure                        (TCIF_ERROR_BASE + 17)

/** @} */

#endif
