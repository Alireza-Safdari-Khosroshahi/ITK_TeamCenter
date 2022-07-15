//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2012.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software

/**
    @file

    ClientServices Error Codes Declaration

*/

#ifndef CLIENTSERVICES_ERRORS_H
#define CLIENTSERVICES_ERRORS_H

/*================================================================================================*/
#ifndef EMH_CONST_H
    #include <common/emh_const.h>
#endif

#include <clientservices/libclientservices_exports.h>

/*================================================================================================*/

#define CLIENTSERVICES_ERROR_BASE                                    EMH_CLIENTSERVICES_error_base

/** A severe internal error has occurred in the Client Services module. Please check the Teamcenter server syslog file for more information. */
#define CLIENTSERVICES_internal_error                                (EMH_CLIENTSERVICES_error_base + 1)

/** The XRT file for the dataset "%1$" could not be read. Please contact your system administrator. */
#define CLIENTSERVICES_failure_to_read_xrt                           (EMH_CLIENTSERVICES_error_base + 2)

/** The HTML output for the element type "%1$" could not be generated. Please contact your system administrator. */
#define CLIENTSERVICES_failure_generating_html_for_element           (EMH_CLIENTSERVICES_error_base + 3)

/** An internal error has occurred: the output stream must be set prior to invoking the "toHTML" function. Please check the Teamcenter server syslog file for more information, and report the error to your system administrator. */
#define CLIENTSERVICES_undefined_output_stream                       (EMH_CLIENTSERVICES_error_base + 4)

/** An unknown XRT element was encountered: %1$. Please contact your system administrator. */
#define CLIENTSERVICES_unknown_xrt_element                           (EMH_CLIENTSERVICES_error_base + 5)

/** The preference "%1$"used for finding shared common client libraries does not have any proper value. Please contact your system administrator. */
#define CLIENTSERVICES_undefined_shared_library_preference           (EMH_CLIENTSERVICES_error_base + 6)

/** Multiple common client shared library datasets of name "%1$" were encountered. Please contact your system administrator. */
#define CLIENTSERVICES_multiple_shared_library_dataset_found         (EMH_CLIENTSERVICES_error_base + 7)

/** No common client shared library dataset of name "%1$" could be found. Please contact your system administrator. */
#define CLIENTSERVICES_no_shared_library_dataset_found               (EMH_CLIENTSERVICES_error_base + 8)

/** The common client shared library dataset of name "%1$" is not owned by the "DBA" group. Please contact your system administrator. */
#define CLIENTSERVICES_shared_library_dataset_not_owned_by_dba       (EMH_CLIENTSERVICES_error_base + 9)

/** The HTML file for the dataset "%1$" could not be read. Please contact your system administrator. */
#define CLIENTSERVICES_failure_to_read_html                          (EMH_CLIENTSERVICES_error_base + 10)

/** The rendering hint "%1$" is not supported in HTML stylesheets. Please contact your system administrator. */
#define CLIENTSERVICES_unsupported_rendering_hint                    (EMH_CLIENTSERVICES_error_base + 11)

/** An internal error has occurred: an invalid input has been provided to the "ClientServices::getStylesheet" method. Please report this error to your system administrator. */
#define CLIENTSERVICES_getStylesheet_invalid_input                      (EMH_CLIENTSERVICES_error_base + 12)

#include <clientservices/libclientservices_undef.h>
#endif
