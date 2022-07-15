/* Copyright 2020 Siemens Digital Industries Software
 ==================================================
 Copyright 2015
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2020 Siemens Digital Industries Software */

/**
    @file

    Include file to define errors for Teamcenter Email Polling.

*/

/*  */

#ifndef EMLPOLLING_ERRORS_H
#define EMLPOLLING_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup EMLPOLLING_ERRORS TC Email Polling Errors
    @ingroup EMLPOLLING
    @{
*/
/** The Email Polling Configuration with given configuration ID %1$ already exists. Please refer the value of the preference %2$*/
#define EMLPOLLING_config_id_exists                   ( EMH_EMLPOLLING_error_base + 2 )

/** Specified class %1$ signature is not correct.Please check the class signature.*/
#define EMLPOLLING_class_not_found                    ( EMH_EMLPOLLING_error_base + 3 )

/** Specified Method %1$ signature is not correct.Please check the method signature.*/
#define EMLPOLLING_method_not_found                   ( EMH_EMLPOLLING_error_base + 4 )

/** Specified Class %1$ signature for ResultMessage object is not correct.Please check the class signature. */
#define EMLPOLLING_result_object_not_created          ( EMH_EMLPOLLING_error_base + 5 )

/** The Email Polling connection %1$ to mail server is not established.Please check mail configuration details. */
#define EMLPOLLING_connection_failed                  ( EMH_EMLPOLLING_error_base + 6 )

/** Specified Download Directory %1$ is not found.Please check the preference. */
#define EMLPOLLING_invalid_dir_specified              ( EMH_EMLPOLLING_error_base + 7 )

/** Specified Response Record %1$ is not found in database .Please check the preference. */
#define EMLPOLLING_invalid_response_record_specified  ( EMH_EMLPOLLING_error_base + 8 )

/** The download of mail attachments from the specified mail server "%1$" has failed, possibly because the email does not contain any attachments. If email does contain attachments, the issue might be with the polling rule. */
#define EMLPOLLING_download_attachment_failed         ( EMH_EMLPOLLING_error_base + 9 )

/** @} */

#endif
