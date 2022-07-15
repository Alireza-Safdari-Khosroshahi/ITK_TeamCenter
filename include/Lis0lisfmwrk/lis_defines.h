/*
    Copyright 2020 Siemens Digital Industries Software
    ==================================================
    Copyright 2017.
    Siemens Product Lifecycle Management Software Inc.
    All Rights Reserved.
    ==================================================
    Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    This file contains the HTTP (HyperText Transfer Protocol) Error Codes

*/

#ifndef LIS_DEFINES_H
#define LIS_DEFINES_H

/**
    @ingroup LIS0LISFMWRK
    @{
*/

/**
    The HTTP Request has succeeded.
*/
#define  HTTPRESPONSE_OK                          200

/**
    The HTPP request has been fulfilled and has resulted in one or more new resources being created.
*/
#define  HTTPRESPONSE_OK_CREATED                  201

/**
    The HTPP request has not been applied because it lacks valid authentication credentials for the target resource.
*/
#define  HTTPRESPONSE_NOTAUTHORIZED               401

/**
    The server encountered an unexpected condition that prevented it from fulfilling the request.
*/
#define  HTTPRESPONSE_INTERNALSEVERERROR          500

/**
    The server did not receive a complete request message within the time that it was prepared to wait.
*/
#define  HTTP_URL_NOTCONNECTABLE                  -1

/**
    The origin server did not find a current representation for the target resource or is not willing to disclose that one exists.
*/
#define  HTTP_PROPERTY_NOT_FOUND                  -2

/**
The server refuses to accept the request because the payload format is in an unsupported format
*/
#define HTTP_UNSUPPORTED_MEDIA_TYPE                415

/**
The server can only generate a response that is not accepted by the client.
*/
#define HTTP_NOT_ACCEPTABLE                        406

/** @} */

#endif
