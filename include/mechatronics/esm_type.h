/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This file contains the \#define for all new types, 
    and relations that will be introduced as part of ESM. The naming
    convention for these definitions is as followed:

    Definition with ESM_*_REL are all relations used by ESM
    
*/

/*  */

/**
    @defgroup ESM_TYPES ESM Types
    @ingroup MECHATRONICS

    This module has the definitions to various types and relations defined in ESM
    @{
*/

#ifndef ESM_TYPE_H
#define ESM_TYPE_H 

/**
    @name ESM Relations defined
    @{
*/

#define EMBEDS              "Embeds"
#define DEPENDENTON         "DependentOn"
#define GATEWAYOF           "GatewayOf"
/** @} */


/** @} */
/** 
    @name Categories for Software SubTypes 
    @{
*/
#define CALIBRATION_CAT             "Calibration"
#define APPSOFTWARE_CAT             "AppSoftware"
#define CONFIGFILE_CAT              "ConfigFile"
#define PRIMEBOOTLOADER_CAT         "PrimeBootloader"
#define SECBOOTLOADER_CAT           "SecBootloader"
/** @} */

#endif
