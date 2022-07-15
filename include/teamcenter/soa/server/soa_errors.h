/*
Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright 2013
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software
*/

#ifndef SOA_ERRORS_H
#define SOA_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup SOA_ERRORS TCWS Errors
    @ingroup  SOA
    @{
*/

/*
EMH_SOA_error_base is defined in core/tc/ehm_const.h
We have room for 99 messages.
core/textsrv/xml/emh_text.xml loads
core/textsrv/xml/soa_errors.xml which has the actual messages.
Copy emh_text.xml and soa_errors.xml to <ref unit>\wnti32\kits\tc_cdrom\tc2007\lang\textserver\en
until changes to these files are promoted to release branch and avail able in ref unit
*/



/** User does not have READ permissions to this object.*/
#define SOA_FRAMEWORK_tag_read_permission                              (EMH_SOA_error_base + 0)
/** Error stack is empty. The cause of this error is unknown.*/
#define SOA_FRAMEWORK_empty_error_stack_msg                            (EMH_SOA_error_base + 2)
/** The most likely cause of the empty stack is a programming error. The service operation has thrown a ServiceException or PartialError  without adding a message to the stack.*/
#define SOA_FRAMEWORK_empty_error_stack_reason                         (EMH_SOA_error_base + 3)
/** Please see the log file '%1$' for more information.*/
#define SOA_FRAMEWORK_see_log_file                                      (EMH_SOA_error_base + 4)
/** The service operation is attempting to return more property values than the maximum allowed (%1$ vs. %2$).*/
#define SOA_FRAMEWORK_exceed_return_size                                (EMH_SOA_error_base + 5)
/**  An error occurred in XML parsing. */
#define SOA_FRAMEWORK_xml_parsing_error                                 (EMH_SOA_error_base + 6)
/**  An error occurred in DOM parsing. */
#define SOA_FRAMEWORK_dom_parsing_error                                 (EMH_SOA_error_base + 7)
/** A ServiceExcpetion was thrown unexpectedly.*/
#define SOA_FRAMEWORK_unexpected_service_exception                      (EMH_SOA_error_base + 8)
/** An IFail was thrown unexpectedly.*/
#define SOA_FRAMEWORK_unexpected_ifail                                  (EMH_SOA_error_base + 9)
/** A std::exception was thrown unexpectedly.*/
#define SOA_FRAMEWORK_std_exception                                     (EMH_SOA_error_base +10)
/** %1$*/
#define SOA_FRAMEWORK_any_error                                         (EMH_SOA_error_base +11)
/** The current service operation attempted to return more than the maximum allowable properties.*/
#define SOA_FRAMEWORK_max_properties_returned                           (EMH_SOA_error_base +12)
/** The operation '%1$' does not exist in the service '%2$'.*/
#define SOA_FRAMEWORK_operation_does_not_exist                          (EMH_SOA_error_base +13)
/** The desired Object Property Policy is not in the server's cache.*/
#define SOA_FRAMEWORK_policy_not_in_memory                              (EMH_SOA_error_base +14)
/** The Object Property Policy '%1$' already exists.*/
#define SOA_FRAMEWORK_duplicate_policy_id                               (EMH_SOA_error_base +15)
/** The server was reassigned.*/
#define SOA_FRAMEWORK_server_reassignment                               (EMH_SOA_error_base +16)
/** Attempt to reconnect to a server using a different user name or password.*/
#define SOA_FRAMEWORK_server_reconnect                                  (EMH_SOA_error_base +17)
/** The client version can only be set once.*/
#define SOA_FRAMEWORK_client_version_set                                (EMH_SOA_error_base +18)
/** The value for the property "%1$" could not be retrieved.*/
#define SOA_FRAMEWORK_failed_to_get_property                            (EMH_SOA_error_base +19)
/** The JSON request envelope could not be parsed. The service request will not be performed.*/
#define SOA_FRAMEWORK_failed_to_parse_JSON_envelope                     (EMH_SOA_error_base +20)
/** The XML request envelope could not be parsed. The service request will not be performed.*/
#define SOA_FRAMEWORK_failed_to_parse_XML_envelope                      (EMH_SOA_error_base +21)
/**  An error has occurred during the JSON parsing. */
#define SOA_FRAMEWORK_json_parsing_error                                (EMH_SOA_error_base +22)
/**The service request "%$1.%$2" was not executed, because its integrity cannot be trusted. 
     Its digital signature does not match the data in the request, which indicates that the 
     service request has been modified in transit between the client and the server. 
     If this problem persists, contact your system administrator to determine where the integrity breach occurs. */
#define SOA_FRAMEWORK_invalid_digital_signature                         (EMH_SOA_error_base +23)
/** Failed to restore session state for %$1 (%$2). */
#define SOA_FRAMEWORK_failed_restore_session_state                      (EMH_SOA_error_base +24)


/** Failed to obtain a Tc SSO session key: %1$.*/
#define SOA_FRAMEWORK_async_no_tcsso_session_key                        (EMH_SOA_error_base +57)
/** No valid Tc SSO session. Failed to obtain a Tc SSO token for the remote operation.*/
#define SOA_FRAMEWORK_async_tcsso_session_invalid                       (EMH_SOA_error_base +58)
/** Tc SSO session has expired. Cannot obtain a Tc SSO token for the remote operation.*/
#define SOA_FRAMEWORK_async_tcsso_session_expired                       (EMH_SOA_error_base +59)
/** Asynchronous operations on remote sites are not supported without Tc SSO.*/
#define SOA_FRAMEWORK_async_unsupported_wo_tcsso                        (EMH_SOA_error_base +60)
/** Connection Error: %1$*/
#define SOA_FRAMEWORK_async_connection_error                            (EMH_SOA_error_base +62)
/** The server returned a protocol error: %1$*/
#define SOA_FRAMEWORK_async_protocol_error                              (EMH_SOA_error_base +63)
/** The server returned an internal error: %1$*/
#define SOA_FRAMEWORK_async_internal_server_error                       (EMH_SOA_error_base +64)
/** Invalid credentials from current session.*/
#define SOA_FRAMEWORK_async_invalid_credentials                         (EMH_SOA_error_base +65)
/** Invalid user from current session.*/
#define SOA_FRAMEWORK_async_invalid_user                                (EMH_SOA_error_base +66)
/** Remote site %1$ has no SOA URL. Remote operations cannot be supported.*/
#define SOA_FRAMEWORK_async_no_soa_url                                  (EMH_SOA_error_base +67)
/** Remote operations cannot be executed in INPROCESS mode.*/
#define SOA_FRAMEWORK_async_remote_inprocess                            (EMH_SOA_error_base +68)
/** The asynchronous proxy password is not found.*/
#define SOA_FRAMEWORK_async_proxy_pw                                    (EMH_SOA_error_base +69)
/** The asynchronous mode is not allowed with the current configuration. Please contact your system administrator.*/
#define SOA_FRAMEWORK_async_mode_not_allowed                            (EMH_SOA_error_base + 70)
/** The Teamcenter Services configuration file, %1$, appears to have an invalid line, %2$. This must be corrected for all service operations to function. */
#define SOA_FRAMEWORK_invalid_file_format                               (EMH_SOA_error_base + 75)
/** The Teamcenter Services configuration file, %1$, could not be opened for reading. This must be corrected for all service operations to function. */
#define SOA_FRAMEWORK_missing_serviceMap                                (EMH_SOA_error_base + 76)
/** Failed to load the library %1$. Please ensure that the library is installed in the library path.*/
#define SOA_FRAMEWORK_library_load_error                                (EMH_SOA_error_base + 77)
/** Failed to find the skeleton for the service operation %1$ in the loaded library. Please ensure the library is built correctly.*/
#define SOA_FRAMEWORK_missing_service_skeleton                          (EMH_SOA_error_base + 78)

/* errors 79,80 have been moved to Polling functionality in fclasses */

/**The requested service "%1$" does not exist.*/
#define SOA_FRAMEWORK_service_not_exist                                (EMH_SOA_error_base + 81)
/** The service request "%1$::%2$" has been received after a logout request. This service operation will be ignored. */
#define SOA_FRAMEWORK_after_logout                                     (EMH_SOA_error_base + 82)
/** The data structure element "%1$" was expected. */
#define SOA_FRAMEWORK_missingExpectedXmlElement                        (EMH_SOA_error_base + 83)
/** An invalid enumeration value "%1$" is provided for "%2$". Legal values are %3$. */ 
#define SOA_FRAMEWORK_invalidEnum                                      (EMH_SOA_error_base + 84)
/** Operations from the service "%1$" will not be available because the service cannot be registered. */
#define SOA_FRAMEWORK_skeleton_registration_error                      (EMH_SOA_error_base + 85)


/** Test of ServiceException. */
#define SOATEST_service_exception                                       (EMH_SOA_error_base + 90)
/**Test of Partial Error. */
#define SOATEST_partial_error                                           (EMH_SOA_error_base + 91)

/** @} */

#endif

