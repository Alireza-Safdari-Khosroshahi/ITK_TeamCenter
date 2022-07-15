/*Copyright 2020 Siemens Digital Industries Software
 ==================================================
 Copyright 2014.
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2020 Siemens Digital Industries Software

     @file
     This file contains error messages for ProductLinePlan.
*/

#ifndef PRODLINEPLAN_ERRORS_H
#define PRODLINEPLAN_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup PRODLINEPLAN_ERRORS Errors for the ProductLinePlanning application
    @ingroup PRODLINEPLAN
    @{
*/

/**
   The provided create usage type name is "%1$" when a type name "%2$" is expected. Please contact your system administrator to ensure that the value of   the Business Object constant "Plp0ProductLinePlanUsageType" matches the supplied usage type name.
*/
#define PRODLINEPLAN_usagetype_mismatch              ( EMH_PRODLINEPLAN_error_base + 1 )


/**
   Usage objects of type name "%1$" already exist in the Line Plan "%2". Please contact your system administrator to ensure that the value of the   
   Business  Object constant "Plp0ProductLinePlanUsageType" matches the existing usage type name.
*/
#define PRODLINEPLAN_usagetype_already_exist         ( EMH_PRODLINEPLAN_error_base + 2 )

/**
   An invalid Product Line Plan object is provided.
*/
#define PRODLINEPLAN_invalid_lineplan                ( EMH_PRODLINEPLAN_error_base + 3 )

/**
   The supplied period "%1$" for this usage does not match any of the valid periods for a Product Line Plan. 
*/
#define PRODLINEPLAN_invalid_period                  ( EMH_PRODLINEPLAN_error_base + 4 )


/** @} */

#endif
