/* 
Copyright 2020 Siemens Digital Industries Software 
================================================== 
Copyright 2015. 
Siemens Product Lifecycle Management Software Inc. 
All Rights Reserved. 
================================================== 
Copyright 2020 Siemens Digital Industries Software 
*/ 

 
/** 
    @file 
    Defines the errors for the ConfigFilterCriteria module
*/

#ifndef FND0SOACONFIGFILTERCRITERIA_ERRORS_H
#define FND0SOACONFIGFILTERCRITERIA_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup FND0SOACONFIGFILTERCRITERIA_ERRORS FND0SOACONFIGFILTERCRITERIA Errors
    @ingroup FND0SOACONFIGFILTERCRITERIA
    @{
*/
#define FND0SOACONFIGFILTERCRITERIA_ERROR_BASE                     EMH_FND0SOACONFIGFILTERCRITERIA_error_base

/** An internal error has occurred in then "Fnd0SoaConfigFilterCriteria" module */
#define FND0SOACONFIGFILTERCRITERIA_internal_error               ( EMH_FND0SOACONFIGFILTERCRITERIA_error_base + 1 )

/** The Product Name and Product Namespace supplied to service operation "%1$" must not be empty. */
#define FND0SOACONFIGFILTERCRITERIA_productinfo_empty_error                 ( EMH_FND0SOACONFIGFILTERCRITERIA_error_base + 2 )

/** The operation "%1$" is not implemented in Teamcenter %2$. */
#define FND0SOACONFIGFILTERCRITERIA_operation_not_implemented               ( EMH_FND0SOACONFIGFILTERCRITERIA_error_base + 3 )

/** The value "%1$" is in an invalid numeric format. */
#define FND0SOACONFIGFILTERCRITERIA_invalid_numeric_format                  ( EMH_FND0SOACONFIGFILTERCRITERIA_error_base + 4 )

/** The date value "%1$" is not formatted according to ISO 8601, or is missing the time zone information. */
#define FND0SOACONFIGFILTERCRITERIA_invalid_date_format                     ( EMH_FND0SOACONFIGFILTERCRITERIA_error_base + 5 )

/** The logical data type families create a single value equal to the name of the Option Family.
    It is not permitted to create/add/update values for the Option Family "%1$" on the Item Revision "%2$".
*/
#define FND0SOACONFIGFILTERCRITERIA_logical_data_type_values_error          ( EMH_FND0SOACONFIGFILTERCRITERIA_error_base + 6 )

/**
    @}
*/

#endif
