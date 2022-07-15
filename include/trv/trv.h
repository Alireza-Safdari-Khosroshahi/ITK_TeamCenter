/* Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright 2015.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software */

/**
    @file

    TRV module definitions file
*/

#ifndef TEAMCENTER_TRV_TRV_H
#define TEAMCENTER_TRV_TRV_H

#include <unidefs.h>

#include <trv/libtrv_exports.h>

/**
   Holds a generic name-value pair of strings 
*/
typedef struct TIE_option_values_s
{
    char *name;                             /**< Name of the option */
    char *value;                            /**< Value of the option */
} TIE_option_value_t;

/**
   Describes the status for the BOMLines to be indexed
*/
typedef enum TRV_cfg_delta_status_e
{
    BL_DELTA_STATUS_SKIP,         /**< The line will be skipped for indexing */
    BL_DELTA_STATUS_MODIFY,       /**< The line is modified */
    BL_DELTA_STATUS_ADD,          /**< The line is added */
    BL_DELTA_STATUS_DELETE        /**< The line is deleted */
} TRV_cfg_delta_status_t;

/**
   Message to register the user exit for filtering out lines to traverse.
*/
#define TRV_filter_lines_to_traverse_msg      "TRV_filter_lines_to_traverse"

#ifdef __cplusplus
extern "C"
{
#endif

/**
  User exit to filter out the lines to traverse for indexing.<br/>
  Custom implementation can be provided by registering with the message #TRV_filter_lines_to_traverse_msg. All the BOMLines 
  that need to be synchronized are passed in and the custom implementation has to update the directive values. 
  <br/>Setting the directive as false means to skip the line for the traversal for indexing.
  
  @returns
  <ul>
  <li>#ITK_ok on success.
  <li>#ITK_not_initialized if ITK initialization has failed.
  <li>#ITK_invalid_name if a non-existent function is registered for the #TRV_filter_lines_to_traverse_msg message
  </ul>
*/
    extern TRV_API int TRV_filter_lines_to_traverse( 
        int n_lines,                                        /**< (I) Number of lines identified for synchronization at a level */
        const tag_t* bomlines,                              /**< (I) n_lines BOMLines identified for synchronization at a level */
        const TRV_cfg_delta_status_t*  line_delta_status,   /**< (I) n_lines Delta status of the lines (Skip, Modify, Add, Delete) */
        logical** directive,                                /**< (OF) n_lines Values set by the custom implementation of the message #TRV_filter_lines_to_traverse_msg to 
                                                               indicate if each of the BOMLines are to be traversed or skipped for indexing. 
                                                               <br/>The values are: 
                                                               <ul> 
                                                               <li>true: the line is to be traversed. This is the value returned if no customization is in place. 
                                                               <li>false: the line is not to be traversed.
                                                               </ul> */ 
        logical* user_exit_defined                          /**< (O) Indicates if a custom code was executed. */
        );
    
#ifdef __cplusplus
}
#endif
#include <trv/libtrv_undef.h>
#endif
