/*===============================================================================
Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright $2010.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software
================================================================================*/


/**
    @file

    This file contains the error codes for the MESINTEG module
*/

/*  */

#ifndef MESINTEG_ERRORS_H
#define MESINTEG_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup MESINTEG_ERRORS MESINTEG Errors
    @ingroup MESINTEG
    @{
*/

/** The newly created Work Package will depend on the following rejected Work Packages: %1$ */
#define CMTMESINTEG_depend_on_rejected_work_package                 (EMH_CMTMESINTEG_error_base + 1)

/** Provide a top line. */
#define CMTMESINTEG_topline_absent                                  (EMH_CMTMESINTEG_error_base + 2)

/** Provide a valid Change object. */
#define CMTMESINTEG_change_object_absent                            (EMH_CMTMESINTEG_error_base + 3)

/** Provide an Execution Plan. */
#define CMTMESINTEG_execution_plan_absent                           (EMH_CMTMESINTEG_error_base + 4)

/** Nothing is found to be exported.*/
#define CMTMESINTEG_nothing_to_export                               (EMH_CMTMESINTEG_error_base + 5)

/** The Item Revision &quot;%1$&quot; in the Change Object &quot;%2$&quot; cannot be found in the configured structure.*/
#define CMTMESINTEG_incorrect_item_revision                         (EMH_CMTMESINTEG_error_base + 6)

/** No Master Application Interface (AI) exists.*/
#define CMTMESINTEG_master_ai_absent                                (EMH_CMTMESINTEG_error_base + 7)

/** A full release of master plans is required to release an order plan to the Manufacturing Execution System (MES) application.*/
#define CMTMESINTEG_release_master_plan_first                       (EMH_CMTMESINTEG_error_base + 8)

/** The "ValidateReleaseAndExport" task found more than one "%1$" object attached to the workflow, when only one such object is allowed.*/  
#define CMTMESINTEG_more_than_one_object                            (EMH_CMTMESINTEG_error_base + 9)

/** The "ValidateReleaseAndExport" task requires one "%1$" object to be attached to the workflow. No such object is attached.*/   
#define CMTMESINTEG_no_object_found                                 (EMH_CMTMESINTEG_error_base + 10)

/** The preference "MEMESProductionChangeObjectTypes" contains an invalid type: %1$.*/
#define CMTMESINTEG_preference_with_invalid_type                    (EMH_CMTMESINTEG_error_base + 11)

/** The Configuration Context object on the "ValidateReleaseAndExport" workflow does not match the Configuraton Context object attached to the Application Interface (AI) object "%1$". */
#define CMTMESINTEG_cc_objects_do_not_match                         (EMH_CMTMESINTEG_error_base + 12)

/** An Execution Plan must be attached to the workflow.*/
#define CMTMESINTEG_cc_object_not_attached                          (EMH_CMTMESINTEG_error_base + 13)

/** No target site is specified in order to release to Manufaturing Execution System (MES). Please use the "MEMESSites" preference to specify the target site.*/
#define CMTMESINTEG_no_mes_target_site                              (EMH_CMTMESINTEG_error_base + 14)

/** The creation of the Request object has failed. Please provide a valid Application Interface object.*/
#define CMTMESINTEG_not_created_request_object                      (EMH_CMTMESINTEG_error_base + 15)

/** The creation of an Application Interface object has failed because the preference "MEMESWorkflowAndApplicationInterfaceType" is not set to specify the Application Interface object type.*/
#define CMTMESINTEG_not_created_ai_object                           (EMH_CMTMESINTEG_error_base + 16)

/**The creation of the Visual Structure Context has failed due to an invalid context BOM Line.*/
#define CMTMESINTEG_not_created_vis_sc_object                       (EMH_CMTMESINTEG_error_base + 17)

/** @} */
#endif
