/*
Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright 2017
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    Massive Model Visualization errors for the CPD module

*/

#ifndef CPD0MMV_ERRORS_H
#define CPD0MMV_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup CPD0MMV_ERRORS Errors for Massive Model Visualization module.
    @ingroup CPD0MMV
    @{
*/

/**
 * The Export Records key cannot be empty for the generation of a Massive Model Visualization file.
 */
#define CPD_MMV_export_key_empty                                     ( EMH_CPD0MMV_error_base + 0 )

/**
 * An invalid Collaborative Design is provided for the generation of the Massive Model Visualization file.
 */
#define CPD_MMV_invalid_collaborative_design                         ( EMH_CPD0MMV_error_base + 1 )

 /**
 * A file location must be provided for the generation of a Massive Model Visualization file.
 */
#define CPD_MMV_file_location_empty                                  ( EMH_CPD0MMV_error_base + 2 )

 /**
 * A Configuration Context must be provided for the generation of a Massive Model Visualization file.
 */
#define CPD_MMV_configuration_context_null                           ( EMH_CPD0MMV_error_base + 3 )

 /**
 * The Massive Model Visualization File "%1$" could not be created because there is no write access on directory "%2$".
 */
#define CPD_MMV_no_access_to_file_location                           ( EMH_CPD0MMV_error_base + 4 )

/**
    @}
*/

#endif
