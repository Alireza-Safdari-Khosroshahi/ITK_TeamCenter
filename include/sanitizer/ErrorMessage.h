/*==================================================================================================

                          Copyright (c) 2020 Siemens Product Lifecycle Management Software Inc.

====================================================================================================
Filename: ErrorMessage.h

File description: This file has an error message in English as the default language. User has 
to convert these error message in to localization as per error code.
==================================================================================================*/
#ifndef TEAMCENTER_ERROR_MESSAGE_H
#define TEAMCENTER_ERROR_MESSAGE_H

#include <string>

/**
* Error for invalid string which is provided as input command.
* Available Substitutions: Invalid token present in command.
* The error code for this error string is -1.
*/
const std::string Sanitizer_INVALID_COMMAND_TOKEN = "Command contains invalid string:";
const int INVALID_COMMAND_TOKEN = -1;

/**
* Error for untrusted path which is absolute.
* Available Substitutions: Invalid input path.
* The error code for this error string is -2.
*/
const std::string Sanitizer_PATH_UNTRUSTED = "Untrusted absolute path:";
const int PATH_UNTRUSTED = -2;

/**
* Error for input path which have path traversal detected.
* Available Substitutions: Invalid input path.
* The error code for this error string is -3.
*/
const std::string Sanitizer_PATH_TRAVERSAL = "Path traversal detected:";
const int PATH_TRAVERSAL = -3;

/**
* Error for input path which is invalid.
* The error code for this error string is -4.
*/
const std::string Sanitizer_PATH_INVALID_INPUT_PATH = "The input path is invalid:";
const int PATH_INVALID_INPUT_PATH = -4;

/**
* Error for input path which is falied due to not finding whitelist provided by users.
* The error code for this error string is -7.
*/
const std::string Sanitizer_PATH_INVALID_IN_WHITELIST = "Input file string does not contain valid path";
const int PATH_INVALID_IN_WHITELIST = -7;

/**
* Error for input path which is falied due to not finding the extension list provided by users.
* The error code for this error string is -8.
*/
const std::string Sanitizer_PATH_INVALID_IN_FILEEXTENSIONS = "Input file string does not contain valid file extension";
const int PATH_INVALID_IN_FILEEXTENSIONS = -8;

/**
* Error for command or path if it is empty.
* The error code for this error string is -9.
*/
const std::string Sanitizer_INPUT_ILLEGAL_ARGUMENTS = "Input string for sanitization cannot be empty";
const int INPUT_ILLEGAL_ARGUMENTS = -9;

/**
* API sanitizePathWithWhiteList expect White list or Valid extension list. If not provided then user will get below error.
* The error code for this error string is -10.
*/
const std::string Sanitizer_PATH_ILLEGAL_ARGUMENTS = "At least one of white list and valid extensions must be provided";
const int PATH_ILLEGAL_ARGUMENTS = -10;

#endif
