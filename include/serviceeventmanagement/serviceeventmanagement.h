/*==============================================================================
                Copyright (c) 2008 Siemens PLM Software
                   Unpublished - All Rights Reserved
 ==============================================================================*/

//!
//! \file serviceeventmanagement.h
//!
//! This header file declares all data types and constants to be used by clients of
//! Service Event Management module.
//!

#ifndef SERVICEEVENTMANAGEMENT_H
#define SERVICEEVENTMANAGEMENT_H

#include <unidefs.h>
#include <serviceeventmanagement/libserviceeventmanagement_exports.h>

  
#ifdef __cplusplus
    extern "C"{
#endif

/**
    @defgroup SERVICEEVENTMANAGEMENT Service Event Management

    The Service Event Management module implements the basic set of classes and behaviour
    for serviceeventmanagement module.

    @{
*/

/**
    Initializes the serviceeventmanagement module. You must call this function before calling any other SERVICEEVENTMANAGEMENT functions.
*/
extern SERVICEEVENTMANAGEMENT_API int SERVICEEVENTMANAGEMENT_init_module();

/**
    ITK function to approve a service group, service event or service discrepancy
*/
extern SERVICEEVENTMANAGEMENT_API int SERVICEEVENTMANAGEMENT_approval (
    tag_t se_tag                    /**< (I) Tag of a service object */
    );

/** @} */

#ifdef __cplusplus
    }
#endif

#include <serviceeventmanagement/libserviceeventmanagement_undef.h>

#endif

