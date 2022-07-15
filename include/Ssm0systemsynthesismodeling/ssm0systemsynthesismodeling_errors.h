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

System Synthesis Modeling Error Codes Declaration

*/

#ifndef SSM0SYSTEMSYNTHESISMODELING_ERRORS_H
#define SSM0SYSTEMSYNTHESISMODELING_ERRORS_H

#include <common/emh_const.h>

/**
@defgroup SSM0SYSTEMSYNTHESISMODELING_ERRORS Errors for the System Synthesis Modeling solution
@ingroup SSM0SYSTEMSYNTHESISMODELING
@{
*/

#define SSM0SYSTEMSYNTHESISMODELING_ERROR_BASE                                         EMH_SSM0SYSTEMSYNTHESISMODELING_error_base

/** The Template "%1$" is not modifiable, because the associated Template Container is not modifiable.*/
#define SSM0SYSTEMSYNTHESISMODELING_template_not_modifiable                            ( SSM0SYSTEMSYNTHESISMODELING_ERROR_BASE + 1 )

/** The Template cannot be created, because the associated Template Container is not modifiable.*/
#define SSM0SYSTEMSYNTHESISMODELING_template_creation_failed                           ( SSM0SYSTEMSYNTHESISMODELING_ERROR_BASE + 2 )

/** The Model cannot be created, because the associated Model Container is not modifiable.*/
#define SSM0SYSTEMSYNTHESISMODELING_model_creation_failed                              ( SSM0SYSTEMSYNTHESISMODELING_ERROR_BASE + 3 )

/** The Study cannot be created, because the associated Project is not modifiable.*/
#define SSM0SYSTEMSYNTHESISMODELING_study_creation_failed                              ( SSM0SYSTEMSYNTHESISMODELING_ERROR_BASE + 4 )

/** The Simulation Application cannot be created, because the associated Project is not modifiable.*/
#define SSM0SYSTEMSYNTHESISMODELING_simulation_application_creation_failed             ( SSM0SYSTEMSYNTHESISMODELING_ERROR_BASE + 5 )

/** The object "%1$" cannot be deleted, because it is referenced by the following objects: %2$.*/
#define SSM0SYSTEMSYNTHESISMODELING_object_deletion_failed_reference                   ( SSM0SYSTEMSYNTHESISMODELING_ERROR_BASE + 6 )

/** The object "%1$" cannot be deleted, because the following secondary objects cannot be deleted: %2$.*/
#define SSM0SYSTEMSYNTHESISMODELING_object_deletion_failed_secondary                   ( SSM0SYSTEMSYNTHESISMODELING_ERROR_BASE + 7 )

/** The Simulation Application cannot be created, because the URL is invalid */
#define SSM0SYSTEMSYNTHESISMODELING_simulation_application_creation_failed_invalid_url ( SSM0SYSTEMSYNTHESISMODELING_ERROR_BASE + 8 )

/** The license "%1$" for the System Synthesis module is not available. Please contact the system administrator.*/
#define SSM0SYSTEMSYNTHESISMODELING_validate_license_failed                            ( SSM0SYSTEMSYNTHESISMODELING_ERROR_BASE + 9 )


/** @} */

#endif
