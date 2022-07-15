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

    Lifecycle Interoperability Services Framework BMIDE Error Codes Declaration

*/

#ifndef LIS0LISFMWRKBMIDE_ERRORS_H
#define LIS0LISFMWRKBMIDE_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup LIS0LISFMWRKBMIDE_ERRORS  Errors for Lifecycle Interoperability Services BMIDE framework
    @ingroup LIS0LISFMWRKBMIDE
    @{
*/

#define LIS0LISFMWRK_BMIDE_BMIDE_ERROR_BASE                                   EMH_LIS0LISFMWRK_BMIDE_error_base

/** The Protocol &quot;%1$&quot; already exists in the database. */
#define LIS0LISFMWRK_BMIDE_lisprotocol_already_exists                        ( EMH_LIS0LISFMWRK_BMIDE_error_base + 1 )

/** The Protocol &quot;%1$&quot; does not exist in the database */
#define LIS0LISFMWRK_BMIDE_lisprotocol_does_not_exist                        ( EMH_LIS0LISFMWRK_BMIDE_error_base + 2 )

/** The Create Release &quot;%1$&quot; does not exist for the Protocol &quot;%2$&quot;. */
#define LIS0LISFMWRK_BMIDE_lisprotocol_create_release_does_not_exist         ( EMH_LIS0LISFMWRK_BMIDE_error_base + 3 )

/** The Provider Catalog &quot;%1$&quot; already exists in the database. */
#define LIS0LISFMWRK_BMIDE_liscatalog_already_exists                         ( EMH_LIS0LISFMWRK_BMIDE_error_base + 4 )

/** The Provider Catalog &quot;%1$&quot; does not exist in the database. */
#define LIS0LISFMWRK_BMIDE_liscatalog_does_not_exist                         ( EMH_LIS0LISFMWRK_BMIDE_error_base + 5 )

/** The Create Release &quot;%1$&quot; does not exist for the Provider Catalog &quot;%2$&quot;. */
#define LIS0LISFMWRK_BMIDE_liscatalog_create_release_does_not_exist          ( EMH_LIS0LISFMWRK_BMIDE_error_base + 6 )

/** The Protocol &quot;%1$&quot; does not exist for the Provider Catalog &quot;%2$&quot;. */
#define LIS0LISFMWRK_BMIDE_liscatalog_protocol_does_not_exist                 ( EMH_LIS0LISFMWRK_BMIDE_error_base + 7 )

/** The Provider &quot;%1$&quot; already exists in the database. */
#define LIS0LISFMWRK_BMIDE_lisprovider_already_exists                         ( EMH_LIS0LISFMWRK_BMIDE_error_base + 8 )

/** The Provider &quot;%1$&quot; does not exist in the database. */
#define LIS0LISFMWRK_BMIDE_lisprovider_does_not_exist                         ( EMH_LIS0LISFMWRK_BMIDE_error_base + 9 )

/** The Create Release &quot;%1$&quot; does not exist for the Provider &quot;%2$&quot;. */
#define LIS0LISFMWRK_BMIDE_lisprovider_create_release_does_not_exist          ( EMH_LIS0LISFMWRK_BMIDE_error_base + 10 )

/** The Provider Catalog &quot;%1$&quot; does not exist for the Provider &quot;%2$&quot;. */
#define LIS0LISFMWRK_BMIDE_lisprovider_catalog_does_not_exist                 ( EMH_LIS0LISFMWRK_BMIDE_error_base + 11 )

/** The Dialog Service &quot;%1$&quot; already exists in the database. */
#define LIS0LISFMWRK_BMIDE_lisdialogservice_already_exists                    ( EMH_LIS0LISFMWRK_BMIDE_error_base + 12 )

/** The Dialog Service &quot;%1$&quot; does not exist in the database. */
#define LIS0LISFMWRK_BMIDE_lisdialogservice_does_not_exist                    ( EMH_LIS0LISFMWRK_BMIDE_error_base + 13 )

/** The Create Release &quot;%1$&quot; does not exist for the Dialog Service &quot;%2$&quot;. */
#define LIS0LISFMWRK_BMIDE_lisdialogservice_create_release_does_not_exist     ( EMH_LIS0LISFMWRK_BMIDE_error_base + 14 )

/** The Provider &quot;%1$&quot; does not exist for the Dialog Service &quot;%2$&quot; */
#define LIS0LISFMWRK_BMIDE_lisdialogservice_provider_does_not_exist            ( EMH_LIS0LISFMWRK_BMIDE_error_base + 15 )

/** The Factory Service &quot;%1$&quot; already exists in the database. */
#define LIS0LISFMWRK_BMIDE_lisfactoryservice_already_exists                    ( EMH_LIS0LISFMWRK_BMIDE_error_base + 16 )

/** The Factory Service &quot;%1$&quot; does not exist in the database. */
#define LIS0LISFMWRK_BMIDE_lisfactoryservice_does_not_exist                    ( EMH_LIS0LISFMWRK_BMIDE_error_base + 17 )

/** The Create Release &quot;%1$&quot; does not exist for the Factory Service &quot;%2$&quot;. */
#define LIS0LISFMWRK_BMIDE_lisfactoryservice_create_release_does_not_exist     ( EMH_LIS0LISFMWRK_BMIDE_error_base + 18 )

/** The Provider &quot;%1$&quot; does not exist for the Factory Service &quot;%2$&quot; */
#define LIS0LISFMWRK_BMIDE_lisfactoryservice_provider_does_not_exist           ( EMH_LIS0LISFMWRK_BMIDE_error_base + 19 )

/** The Operation &quot;%1$&quot; already exists in the database */
#define LIS0LISFMWRK_BMIDE_lisoperation_already_exists                         ( EMH_LIS0LISFMWRK_BMIDE_error_base + 20 )

/** The Operation &quot;%1$&quot; does not exist in the database */
#define LIS0LISFMWRK_BMIDE_lisoperation_does_not_exist                         ( EMH_LIS0LISFMWRK_BMIDE_error_base + 21 )

/** The Create Release &quot;%1$&quot; does not exist for the Operation &quot;%2$&quot;. */
#define LIS0LISFMWRK_BMIDE_lisoperation_create_release_does_not_exist          ( EMH_LIS0LISFMWRK_BMIDE_error_base + 22 )

/** The Service &quot;%1$&quot; does not exist for the Operation &quot;%2$&quot;. */
#define LIS0LISFMWRK_BMIDE_lisoperation_service_does_not_exist                 ( EMH_LIS0LISFMWRK_BMIDE_error_base + 23 )

/** The Library &quot;%1$&quot; does not exist for the Operation &quot;%2$&quot;. */
#define LIS0LISFMWRK_BMIDE_lisoperation_library_does_not_exist                 ( EMH_LIS0LISFMWRK_BMIDE_error_base + 24 )

/** The type &quot;%1$&quot; specified in the Included Types list for the Provider Catalog &quot;%2$&quot; does not exist. */
#define LIS0LISFMWRK_BMIDE_catalog_lisincludedtypes_does_not_exist             ( EMH_LIS0LISFMWRK_BMIDE_error_base + 25 )

/** The type &quot;%1$&quot; specified in the Excluded Types list for the Provider Catalog &quot;%2$&quot; does not exist. */
#define LIS0LISFMWRK_BMIDE_catalog_lisexcludedtypes_does_not_exist             ( EMH_LIS0LISFMWRK_BMIDE_error_base + 26 )

/** The Deprecated Release &quot;%1$&quot; does not exist for the Operation &quot;%2$&quot;. */
#define LIS0LISFMWRK_BMIDE_lisoperation_deprecated_release_does_not_exist      ( EMH_LIS0LISFMWRK_BMIDE_error_base + 27 )

/** The instance &quot;%1$&quot; does not exist */
#define LIS0LISFMWRK_BMIDE_instance_does_not_exist                             ( EMH_LIS0LISFMWRK_BMIDE_error_base + 28 )


/** @} */


#endif
