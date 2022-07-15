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
    Configurator Partition Interface Error Codes Declaration
*/

#ifndef CFG1CONFIGURATOR_ERRORS_H
#define CFG1CONFIGURATOR_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup CFG1CONFIGURATOR_ERRORS Configurator Partition Interface Errors
    @ingroup CFG1CONFIGURATOR
    @{
*/

#define EMH_CFG1CONFIGURATOR_ERROR_BASE                                                 EMH_CFG1CONFIGURATOR_error_base

/**
 * An internal error has occurred in the Configurator Partition Interface (cfg1configurator) module: %1$. Please report this error to your system administrator.
 */
#define CFG1CONFIGURATOR_internal_error                                                 ( EMH_CFG1CONFIGURATOR_ERROR_BASE + 1 )

/**
* The object "%1$" of type "%2$" cannot be deleted, because it is associated to one or more Partition objects.
*/
#define CFG1CONFIGURATOR_partition_relation_exist                                       ( EMH_CFG1CONFIGURATOR_ERROR_BASE + 2 )

/**
    @}
 */
#endif
