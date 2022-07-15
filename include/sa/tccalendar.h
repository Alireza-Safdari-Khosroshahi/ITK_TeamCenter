/* 
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2016.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/


/** 
    @file tccalendar.h
    library exports header file

*/

#ifndef TCCALENDAR_H
#define TCCALENDAR_H

#include <unidefs.h>
#include <sa/sa.h>
#include <sa/libsa_exports.h>


#ifdef __cplusplus
    extern "C"{
#endif

/**
    @defgroup TCCALENDAR Calendar
    @ingroup SA

    This module defines the required ITK interface for TCCalendar related operations.
    @{
*/

#define TCCALENDAR_name_size_c                       256

/**
   Creates a tccalendar. 
*/
int SA_API TCCALENDAR_create_tccalendar (
    int tccal_type,                     /**< (I) The calendar type (Base/Schedule/Resource/Schedule member) */
    tag_t base_calendar,                /**< (I) The uid of basecalendar */
    tag_t schedule,                     /**< (I) The uid of schedule */
    tag_t resource,                     /**< (I) The unique Object schedule/resource ID */
    const char* tccal_name,             /**< (I) The name of calendar */
    const char* tccal_desc,             /**< (I) The description of calendar */
    int  num_sun_ranges,                /**< (I) no of time ranges in tha week */
    tag_t * sun_ranges,                 /**< (I) The default working mins for Sunday */
    int num_mon_ranges,                 /**< (I) no of time ranges in tha week */
    tag_t * mon_ranges,                 /**< (I) The default working mins for Monday */
    int num_tue_ranges,                 /**< (I) no of time ranges in tha week */
    tag_t * tue_ranges,                 /**< (I) The default working mins for Tuesday */
    int num_wed_ranges,                 /**< (I) no of time ranges in tha week */
    tag_t * wed_ranges,                 /**< (I) The default working mins for Wednesday */
    int num_thu_ranges,                 /**< (I) no of time ranges in tha week */
    tag_t * thu_ranges,                 /**< (I) The default working mins for Thursday */
    int num_fri_ranges,                 /**< (I) no of time ranges in tha week */
    tag_t * fri_ranges,                 /**< (I) The default working mins for Friday */
    int num_sat_ranges,                 /**< (I) no of time ranges in tha week */
    tag_t * sat_ranges,                 /**< (I) The default working mins for Saturday*/
    const char* time_zone,              /**< (I) time zone */
    tag_t* newtccalendar                /**< (O) The newly created calendar */
    );

/**
   Deletes a tccalendar. 
*/
extern SA_API int TCCALENDAR_delete_tccalendar (
    tag_t tccalendar                      /**< (I) Calendar to be deleted */
    );

/**
   Retrieves the base tccalendar.  
*/
extern SA_API int TCCALENDAR_get_base_tccalendar (
    tag_t* tccalendar                     /**< (O) Base Calendar */
    );

/**
   Retrieves the resource calendar.  
*/
extern SA_API int TCCALENDAR_get_resource_tccalendar(
    tag_t resource,                  /**< (I) Resource whose calendar is to be retrieved */  
    tag_t* tccalendar                /**< (O) Resource calendar */
    );

/**
   Retrieves the schedule calendar.  
*/
extern SA_API int TCCALENDAR_get_schedule_tccalendar(
    tag_t  schedule,                  /**< (I) Schedule whose calendar is to be retrieved */  
    tag_t* tccalendar                /**< (O) Resource calendar */
    );


/**
   Retrieves the resource calendar.  
*/
extern SA_API int TCCALENDAR_get_tccalendar_by_name2(
    const char *tccalname,           /**< (I) name whose calendar is to be retrieved */
    tag_t* tccalendar                /**< (O) Resource calendar */
    );

/**
   Retrieves the resource calendar.  
*/
extern SA_API int TCCALENDAR_get_tccalendar_name(
    tag_t     tccal,                   /**< (I) Calendar Tag */  
    char **   tccalName                /**< (O) Name of Calendar */
    );

/**
   Updates the calendar. 
*/
extern SA_API int TCCALENDAR_update_tccalendar (
    tag_t tccalendar,                   /**< (I) The calendar to be updated */
    int  num_sun_ranges,                /**< (I) no of time ranges in tha week */
    tag_t * sun_ranges,                 /**< (I) The default working mins for Sunday */
    int num_mon_ranges,                 /**< (I) no of time ranges in tha week */
    tag_t * mon_ranges,                 /**< (I) The default working mins for Monday */
    int num_tue_ranges,                 /**< (I) no of time ranges in tha week */
    tag_t * tue_ranges,                 /**< (I) The default working mins for Tuesday */
    int num_wed_ranges,                 /**< (I) no of time ranges in tha week */
    tag_t * wed_ranges,                 /**< (I) The default working mins for Wednesday */
    int num_thu_ranges,                 /**< (I) no of time ranges in tha week */
    tag_t * thu_ranges,                 /**< (I) The default working mins for Thursday */
    int num_fri_ranges,                 /**< (I) no of time ranges in tha week */
    tag_t * fri_ranges,                 /**< (I) The default working mins for Friday */
    int num_sat_ranges,                 /**< (I) no of time ranges in tha week */
    tag_t * sat_ranges                 /**< (I) The default working mins for Saturday*/
    );

/**
   Retrieves the user's non working dates if user has his own calendar
   else return non working dates of default base calendar.     
*/
extern SA_API int TCCALENDAR_get_resource_non_working_dates(
    tag_t resource,                                 /**< (I) Resource whose calendar is to be retrieved */
    char *fromDate,                                 /**< (I) starting date in "yyyy-mm-dd hh:mm:ss" from whose non working dates is to be retrieved */
    char *toDate,                                   /**< (I) ending date in "yyyy-mm-dd hh:mm:ss" from whose non working dates is to be retrieved  */
    int *no_of_nonwd,                               /**< (O) non working dates of Resource calendar */
    char ***nonWorkingDates                         /**< (OF) no_of_nonwd non working dates of Resource calendar */
    );



/**

   Computes the end date based on the calendar of the given user, the start date and the duration.
   <br/>It also leverages the values specified in the preference "SM_Hours_Per_Day_Preference", "SM_Hours_Per_Week_Preference", "SM_Hours_Per_Year_Preference" to determine respectively the working hours per day, working hours per week and working hours per year.
   <br/>If the @p user_tag is NULLTAG, the default calendar is used.
        
   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#SA_tccalendar_invalid_calendar_input error if the start date is null or invalid (if the month is greater than 12, the day is greater than 31, the hour is greater than 23, the minute is greater than 59, the second is greater than 59). 
   <li>#SA_tccalendar_duration_too_long if either number of years, weeks, days, hours or minutes is too large, i.e. years greater than 98, weeks greater than 7144, days greater than 35716, hours greater than 285728, minutes greater than 17143680.
   </ul>
*/
extern SA_API int  TCCALENDAR_find_end_date (
                           date_t start_date,       /**< (I)  The start date in local server time zone. */                                            
                           tag_t user_tag,          /**< (I)  The user which calendar is used
                                                    <br/>If the provided user is not specified or the user calendar is not set, the default calendar is used. */
                           unsigned int years,      /**< (I) Duration in years. It must be less than 98*/  
                           unsigned int weeks,      /**< (I) Duration in weeks. It must be less than 7144*/ 
                           unsigned int days,       /**< (I) Duration in days. It must be less than 35716*/ 
                           unsigned int hours,      /**< (I) Duration in hours. It must be less than 285728*/ 
                           unsigned int minutes,    /**< (I) Duration in minutes. It must be less than 17143680*/ 
                           date_t* end_date         /**< (O)  The computed end date in local server time zone.*/
                           );

/** @} */

#ifdef __cplusplus
}
#endif

#include <sa/libsa_undef.h>
#endif
