/*==============================================================================
//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2011.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software
 ==============================================================================*/

/**
    @file

    This header file declares all data types and constants to be used by clients of
    Service Scheduling module.
*/

#ifndef SSS0SVCSCHEDULING_H
#define SSS0SVCSCHEDULING_H

#include <unidefs.h>
#include <sss0svcscheduling/libsss0svcscheduling_exports.h>

#ifdef __cplusplus
    extern "C"{
#endif

/**
    @defgroup SSS0SVCSCHEDULING Service Scheduling

    The Service Scheduling module.

    @{
*/

/**
    This structure is used to pass on the parameters for Record utilization action.
*/
typedef struct SSS0SVCSCHEDULING_API SSS0SVCSCHEDULING_characteristics_data_s
{
    tag_t       charDef;                            /**< Tag of Characteristics Definition */
    double      value;                              /**< Value for the Characteristic */
    date_t      dateValue;                          /**< Date Value for the Characteristic */
    logical     forPhysicalPart;                    /**< Boolean to indicate */
}SSS0SVCSCHEDULING_characteristics_data_s;


/**
    This structure is used to pass on the parameters for Record utilization action.
*/
typedef struct SSS0SVCSCHEDULING_API SSS0SVCSCHEDULING_utilization_data_s
{
    char*                       description;        /**< Description */
    date_t                      recordingTime;      /**< Recorded at */
    char*                       capturedBy;         /**< Captured by */
    logical                     propagate;          /**< Boolean to indicate Propagate the value to child physical part */
}SSS0SVCSCHEDULING_utilization_data_s;

/**
    ITK function for record utilization
*/
extern SSS0SVCSCHEDULING_API int SSS0SVCSCHEDULING_record_utilization(
    tag_t                                     activityRev,        /**< (I) Job Activity Revision Tag*/
    tag_t                                     logBook,            /**< (I) Log Book Tag*/
    SSS0SVCSCHEDULING_utilization_data_s      in_param,           /**< (I) Contains the utilization data to record for physical part*/
    SSS0SVCSCHEDULING_characteristics_data_s  *charValueParams,   /**< (I) List containing the Characteristics value for physical part*/
    int                                       count,              /**< (I) Number of Characteristic values for physical part*/
    tag_t*                                    logEntry            /**< (O) Log Entry Tag */
    );

/**
    ITK function for updating physical configuration by Job Task .
    This will perform part movements/rebase as applicable on
    the input Job Activity Revision
*/
extern SSS0SVCSCHEDULING_API int SSS0SVCSCHEDULING_update_configuration
(
    tag_t       activityRev,        /**< (I) Job Activity Revision Tag */
    date_t      rebaseDate          /**< (I) Upgrade/Rebase Date */
);


/** @} */

#ifdef __cplusplus
    }
#endif

#include <sss0svcscheduling/libsss0svcscheduling_undef.h>

#endif
