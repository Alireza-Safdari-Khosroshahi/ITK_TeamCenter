/*==================================================================================================

                    Copyright (c) 2013 Siemens PLM Software
                             Unpublished - All rights reserved

====================================================================================================
File description:

    Errors for the TextServer module

====================================================================================================
   Date      Name                    Description of Change
07-Jan-2013  Johann Chemin-Danielson Creation
$HISTORY$
==================================================================================================*/
#ifndef TEXTSRV_ERRORS_H
#define TEXTSRV_ERRORS_H

#include <common/emh_const.h>
#include <textsrv/libtextsrv_exports.h>

/**
    @defgroup TEXTSRV_ERRORS Errors
    @ingroup TEXT_SERVER
    @{
*/

/** 
    @name Errors for RAC and SOA connections 
    @{
*/
/** The requested locale (%1$) cannot be used by the Teamcenter server process.
Connect in one of the following locales: %2$. Alternatively, limit data entry to characters from one of these locales. */
#define TEXTSRV_ERR_error_db                                 (EMH_TEXTSRV_error_base + 1)

/** The Teamcenter server does not have '%1$' localization files. */
#define TEXTSRV_ERR_warning_l10n                             (EMH_TEXTSRV_error_base + 2)

/** Your data entry must be done using the following locales: %1$. */
#define TEXTSRV_ERR_information_dataentry_from_pref          (EMH_TEXTSRV_error_base + 3)

/** Your data entry must be done using characters from the following locales: %1$. */
#define TEXTSRV_ERR_information_dataentry_from_db            (EMH_TEXTSRV_error_base + 4)

/** Your Teamcenter database is configured for English.
If you enter non-English characters, they might be changed, or lost, in the future. */
#define TEXTSRV_ERR_information_database_inconsistent_bypass (EMH_TEXTSRV_error_base + 5)

/** Though the requested locale "%1$" is supported by the system, the database encoding (%2$) is different from the Teamcenter server encoding (%3$). Always ensure that all entered characters exist in the "%4$" encoding. Failure to do so could mean that those characters will be changed or lost. */
#define TEXTSRV_ERR_information_database_slight_mismatch     (EMH_TEXTSRV_error_base + 6)

/** Warnings for Thin client connections */
/** The connection is served with language %1$ because of missing appropriate Teamcenter server localization for %2$. */
#define TEXTSRV_ERR_thinclient_warning_l10n                  (EMH_TEXTSRV_error_base + 10)

/** The connection is served with language %1$ because of mismatch with the supported encoding (%2$) for %3$. */
#define TEXTSRV_ERR_thinclient_warning_db                    (EMH_TEXTSRV_error_base + 11)

/** The connection is served with language %1$ because of the following reasons:\\n\\tmismatch with supported encoding (%2$): %3$.\\n\\tmissing appropriate Teamcenter server localization: %4$. */
#define TEXTSRV_ERR_thinclient_warning_l10n_and_db           (EMH_TEXTSRV_error_base + 12)

/** Your Teamcenter database is configured for English.\\nIf you enter non-English characters, they might be changed, or lost, in the future. */
#define TEXTSRV_ERR_thinclient_information_database_inconsistent_bypass (EMH_TEXTSRV_error_base + 13)

/** The connection has been forced by the administrator to be with the following language: %1$. */
#define TEXTSRV_ERR_thinclient_information_forcing_locale    (EMH_TEXTSRV_error_base + 14)

/** Though the requested locale "%1$" is supported by the system, the database encoding (%2$) is different from the Teamcenter server encoding (%3$).\\nAlways ensure that all entered characters exist in the "%4$" encoding. Failure to do so could mean that those characters will be changed or lost. */
#define TEXTSRV_ERR_thinclient_information_database_slight_mismatch     (EMH_TEXTSRV_error_base + 15)

/** @} */

/** 
    @name Thin client: Errors when connection is not allowed because of wrong desired locale.
     Since those are error messages, they will be displayed within some web page, so the
     formatting is using the html formatting conventions.                               
     @{
*/
/** The connection cannot be established because none of the locales specified in the URL and/or your browser's preferences matches the supported encoding (%1$): %2$.&lt;br/&gt;&lt;br/&gt;Change this and try logging-in again. */
#define TEXTSRV_ERR_thinclient_error_db                      (EMH_TEXTSRV_error_base + 20)

/** The connection cannot be established because none of the locales specified in the URL and/or your browser's preferences (%1$) have proper localization.&lt;br/&gt;&lt;br/&gt;Change this and try logging-in again. */
#define TEXTSRV_ERR_thinclient_error_l10n                    (EMH_TEXTSRV_error_base + 21)

/** The connection cannot be established because of the following problems with the locales specified in the URL and/or your browser's preferences:&lt;ul&gt;&lt;li&gt;mismatch with the supported encoding (%1$): %2$.&lt;/li&gt;&lt;li&gt;missing appropriate localization: %3$.&lt;/li&gt;&lt;/ul&gt;&lt;br/&gt;Change this and try logging-in again. */
#define TEXTSRV_ERR_thinclient_error_l10n_and_db             (EMH_TEXTSRV_error_base + 22)
/** @} */

/** The given file is not an entry for TextServer. */
#define TEXTSRV_ERR_bad_file_name                             (EMH_TEXTSRV_error_base + 25) 
/** Exception when initializing the TextServer module. */
#define TEXTSRV_ERR_no_xml4c2_system                          (EMH_TEXTSRV_error_base + 26) 
/** The key "%1$" could not be found in the TextServer text resource files. */
#define TEXTSRV_ERR_text_key_not_found                        (EMH_TEXTSRV_error_base + 27) 

/** No language is supported. */
#define TEXTSRV_ERR_no_supported_language                     (EMH_TEXTSRV_error_base + 30) 
/** The status does not have any display name. */
#define TEXTSRV_ERR_no_status_names                           (EMH_TEXTSRV_error_base + 31) 
/** The given status is not supported. */
#define TEXTSRV_ERR_unsupported_status                        (EMH_TEXTSRV_error_base + 32) 
/** No status is declared. */
#define TEXTSRV_ERR_no_declared_statuses                      (EMH_TEXTSRV_error_base + 33) 

/** The locale "%1$" is not supported. */
#define TEXTSRV_ERR_locale_not_supported                      (EMH_TEXTSRV_error_base + 34)

/** @} */
#include <textsrv/libtextsrv_undef.h>

#endif
