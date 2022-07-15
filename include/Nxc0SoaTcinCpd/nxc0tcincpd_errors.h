/*Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright $2015.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software*/

/**
    @file

    TCINCPD Error Codes Declaration

*/

#ifndef NXC0TCINCPD_ERRORS_H
#define NXC0TCINCPD_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup TCINCPD_ERRORS Teamcenter Integration 4th Generation Design Errors
    @ingroup TCINCPD
    @{
*/

/**
 * An internal xml parser error has occurred in the Teamcenter Integration 4th Generation Design geometric constriant module.
 */
#define TCINCPD_constraint_status_xml_parser_error                ( EMH_NXC0TCINCPD_error_base + 0 )

/**
 * An internal xml unkown error has occurred in the Teamcenter Integration 4th Generation Design geometric constriant module.
 */
#define TCINCPD_constraint_status_xml_unknown_error               ( EMH_NXC0TCINCPD_error_base + 1 )

/**
 * The constraint status xml file does not exist in the Teamcenter Integration 4th Generation Design geometric constriant module.
 */
#define TCINCPD_constraint_status_xml_not_exist_error             ( EMH_NXC0TCINCPD_error_base + 2 )

/**
 * The corresponding bucket of the constraint owner cannot be retrieved in the Teamcenter Integration 4th Generation Design geometric constriant module.
 */
#define TCINCPD_constraint_owner_bucket_retrieve_error            ( EMH_NXC0TCINCPD_error_base + 3 )

/**
 * The corresponding iteration of the constraint owner cannot be retrieved in the Teamcenter Integration 4th Generation Design geometric constriant module.
 */
#define TCINCPD_constraint_owner_iteration_error                  ( EMH_NXC0TCINCPD_error_base + 4 )

/**
 * The corresponding up-to-date status of the owner does not exist in the Teamcenter Integration 4th Generation Design geometric constriant module.
 */
#define TCINCPD_constraint_owner_uptodate_error                   ( EMH_NXC0TCINCPD_error_base + 5 )


/** @} */
#endif
