// Copyright 2020 Siemens Digital Industries Software
// ==================================================
// Copyright 2011.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2020 Siemens Digital Industries Software
 
/** 
    @file 
 
    Errors for the soa parameter management service
 
*/

#ifndef SOAPARAMETER_ERRORS_H
#define SOAPARAMETER_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup SOAPARAMETER_ERRORS TCWS Errors
    @ingroup SOAPARAMETER
    @{
*/

/** CAD Integration Services error code definitions */

/** NOTE: The error numbers assigned in this file must match those in the SOAPARAMETER_errors.xml file **/

/** getMemoryLayoutOrBlockInfo Service (0 - 19) **/
#define SOAPARAMETER_invalid_input_parameters                 (EMH_PARMMGMT_error_base +   0 )
#define SOAPARAMETER_invalid_object_tag                       (EMH_PARMMGMT_error_base +   1 )
#define SOAPARAMETER_invalid_object_type                      (EMH_PARMMGMT_error_base +   2 )
#define SOAPARAMETER_where_referenced_failed                  (EMH_PARMMGMT_error_base +   3 )
#define SOAPARAMETER_sm_dro_item_not_found                    (EMH_PARMMGMT_error_base +   4 )
#define SOAPARAMETER_invalid_group_type                       (EMH_PARMMGMT_error_base +   5 )
/** @} */


#endif

