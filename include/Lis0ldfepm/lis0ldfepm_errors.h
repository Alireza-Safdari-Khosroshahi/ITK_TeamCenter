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

    @file lis0ldfepm_errors.h
    This file contains the declaration for LIS (Lifecycle Interoperability Services) EPM Error Codes.

**/

#ifndef LIS0LDFEPM_ERRORS_H
#define LIS0LDFEPM_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup LIS0LDFEPM_ERRORS Lifecycle Interoperability Services Errors
    @ingroup LIS0LDFEPM
    @{
*/

/** The property check has failed for the remote object "%3$" belonging to the Linked Data Framework Provider "%6$" and which is linked to the target Teamcenter object "%5$". The value "%1$" for the property "%2$" of "%3$" did not match the expected value "%4$". */
#define LIS0LDFEPM_remote_property_expected_actual_value_mismatch ( EMH_LIS0LDFEPM_error_base + 1 )

/** The check of the remote property "%2$" has failed because of the following error in the Rule Handler "LDF-sync-ldf-status": %1s. Please make sure that properties and their expected values are configured correctly. */
#define LIS0LDFEPM_incorrect_property_value_configuartion_mismatch ( EMH_LIS0LDFEPM_error_base + 2 )

/** The check of the remote property "%2$" has failed because of the following error in the Rule Handler "LDF-sync-ldf-status": %1s. An unexpected error has occurred. */
#define LIS0LDFEPM_unexpected_error_querying_remote_property       ( EMH_LIS0LDFEPM_error_base + 3 )

/** The following required arguments are missing for the Rule Handler "LDF-sync-ldf-status": %1$.*/
#define LIS0LDFEPM_missing_req_arg                                 ( EMH_LIS0LDFEPM_error_base + 4 )

/** An invalid argument was sent to the Handler "%2$" of type "%1$": %3$. Please check the argument and syntax.*/
#define LIS0LDFEPM_invalid_argument                                ( EMH_LIS0LDFEPM_error_base + 5 )

/** @} */
#endif
