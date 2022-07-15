/*==================================================================================================

                          Copyright (c) 2001 EDS
                       Unpublished - All rights reserved

====================================================================================================
File description:

    TcTrushape errors.

====================================================================================================
   Date      Name                    Description of Change
30-Oct-2001  Max Ishutin             TCTRUSHAPE module is born
07-Nov-2001  Max Ishutin             Add more error codes
06-Feb-2002  Max Ishutin             Add trushape library error codes
21-May-2002  Max Ishutin             Reflect actual error codes in the commentaries (83xxx to 85xxx)
31-May-2002  Max Ishutin             Add error codes for item revision post procssing
24-Jun-2002  kao                     added error code
06-Aug-2002  Aaron Ruckman           Split libtc.dll project
28-Aug-2002  Aaron Ruckman           splittc.dll project
05-Sep-2002  Aaron Ruckman           Update headers as part of dll splittc project
22-Nov-2002  Tim Baverstock          Normalise inclusion
01-Apr-2003  Max Ishutin             JT based spatial search
08-Aug-2003  Max Ishutin             Update spatial search ITK interface
13-Feb-2006  Johann Chemin-Danielson  de-Imanization
$HISTORY$
==================================================================================================*/


#ifndef TCTRUSHAPE_ERRORS_H
#define TCTRUSHAPE_ERRORS_H

#include <common/emh_const.h>
#include <tctrushape/libtctrushape_exports.h>

/*
 * ----------------------------------------------------------------------------
 * Appearances Search Errors
 * ----------------------------------------------------------------------------
 */

#define TCTRUSHAPE_invalid_end_item_search_result_tag   (EMH_TCTRUSHAPE_error_base + 1) /* 85001 */
    /* Tag supplied is not that of an existing or valid search result object
     */

#define TCTRUSHAPE_proximity_search_failed              (EMH_TCTRUSHAPE_error_base + 2) /* 85002 */
    /* Proximity spatial search has failed. More detailed information is available on the error stack
     */

#define TCTRUSHAPE_3dbox_search_failed                  (EMH_TCTRUSHAPE_error_base + 3) /* 85003 */
    /* 3D box spatial search has failed. More detailed information is available on the error stack
     */

#define TCTRUSHAPE_appearance_extent_search_failed      (EMH_TCTRUSHAPE_error_base + 4) /* 85004 */
    /* Appearance extent call has failed.
     */

#define TCTRUSHAPE_appearance_bomline_mapping_failed    (EMH_TCTRUSHAPE_error_base + 5) /* 85005 */
    /* BoMLine-Appearance mapping failed
     */

#define TCTRUSHAPE_invalid_bom_window_tag               (EMH_TCTRUSHAPE_error_base + 6) /* 85006 */
    /* Tag supplied is not that of an existing or valid bomWindow object
     */

#define TCTRUSHAPE_failed_to_find_appearance_set        (EMH_TCTRUSHAPE_error_base + 7) /* 85007 */
    /* Supplied information is not enough to find suitable appearance set
     */

#define TCTRUSHAPE_failed_to_open_occupancy_cache       (EMH_TCTRUSHAPE_error_base + 8) /* 85008 */
    /* Failed to find or open occupancy cache for the passed appearance set
     */

#define TCTRUSHAPE_item_name_search_failed              (EMH_TCTRUSHAPE_error_base + 9) /* 85009 */
    /* Item name search failed
     */

#define TCTRUSHAPE_occupancy_cache_file_error           (EMH_TCTRUSHAPE_error_base + 10) /* 85010 */
    /* Error encountered when handling occupancy data files
     */

#define TCTRUSHAPE_can_not_write_to_cache_opened_for_read (EMH_TCTRUSHAPE_error_base + 11) /* 85011 */
    /* Can not write to cache opened for read
     */

#define TCTRUSHAPE_can_not_reopen_occupancy_cache       (EMH_TCTRUSHAPE_error_base + 12) /* 85012 */
    /* Error encountered when trying to reopen file with different access type
     */

#define TCTRUSHAPE_failed_to_initialize                 (EMH_TCTRUSHAPE_error_base + 13) /* 85013 */
    /* Failed to initialize TcTrushape module
     */

#define TCTRUSHAPE_failed_to_retrieve_trushape_file_tag (EMH_TCTRUSHAPE_error_base + 14) /* 85014 */
    /* Failed to retrieve trushape file tag
     */

#define TCTRUSHAPE_out_of_memory                        (EMH_TCTRUSHAPE_error_base + 15) /* 85015 */
    /* Failed to allocate memory
     */

#define TCTRUSHAPE_bad_index_file_header                (EMH_TCTRUSHAPE_error_base + 16) /* 85016 */
    /* Index file header is not "IT"
     */

#define TCTRUSHAPE_incompatible_version                 (EMH_TCTRUSHAPE_error_base + 17) /* 85017 */
    /* Occupancy cache was created in the version of software
     * that is later AND incompatible with the current one
     */

#define TCTRUSHAPE_internal_error                       (EMH_TCTRUSHAPE_error_base + 18) /* 85018 */
    /* Internal error - Report to UGS
     */

#define TCTRUSHAPE_failed_to_recreate_existing_cache     (EMH_TCTRUSHAPE_error_base + 19) /* 85019 */
    /* Failed to recreate existing occupancy cache
     */

#define TCTRUSHAPE_failed_to_create_index_file           (EMH_TCTRUSHAPE_error_base + 20) /* 85020 */
    /* Failed to create occupance cache index file
     */

#define TCTRUSHAPE_failed_to_create_data_file            (EMH_TCTRUSHAPE_error_base + 21) /* 85021 */
    /* Failed to create occupance cache date file
     */

#define TCTRUSHAPE_failed_to_open_index_file             (EMH_TCTRUSHAPE_error_base + 22) /* 85022 */
    /* Failed to open occupance cache index file
     */

#define TCTRUSHAPE_failed_to_open_data_file              (EMH_TCTRUSHAPE_error_base + 23) /* 85023 */
    /* Failed to open occupance cache date file
     */

#define TCTRUSHAPE_failed_to_find_cache_to_open          (EMH_TCTRUSHAPE_error_base + 24) /* 85024 */
    /* Failed to find occupance cache
     */

#define TCTRUSHAPE_failed_to_create_occupancy_cache      (EMH_TCTRUSHAPE_error_base + 25) /* 85025 */
    /* Failed to create occupance cache
     */

#define TCTRUSHAPE_failed_to_check_occupancy_cache_existence (EMH_TCTRUSHAPE_error_base + 26) /* 85026 */
    /* Failed to check occupancy cache existence
     */

#define TCTRUSHAPE_failed_to_write_appearance_occupancy_data (EMH_TCTRUSHAPE_error_base + 27) /* 85027 */
    /* Failed to wrire appearance occupancy data
     */

#define TCTRUSHAPE_failed_to_close_occupancy_cache           (EMH_TCTRUSHAPE_error_base + 28) /* 85028 */
    /* Failed to close occupancy cache
     */

#define TCTRUSHAPE_failed_to_search_with_update_in_progress  (EMH_TCTRUSHAPE_error_base + 29) /* 85029 */
    /* Search is unavailable when occupancy cache is being updated
     */

#define TCTRUSHAPE_failed_to_search_unopened_cache           (EMH_TCTRUSHAPE_error_base + 30) /* 85030 */
    /* Search is unavailable if occupancy cache is not open
     */

#define TCTRUSHAPE_failed_to_retrieve_cache_extents          (EMH_TCTRUSHAPE_error_base + 31) /* 85031 */
    /* Failed to retrieve cache extents
     */

#define TCTRUSHAPE_trushape_library_not_found                (EMH_TCTRUSHAPE_error_base + 32) /* 85032 */
    /* Failed to find/load trushape library
     */

#define TCTRUSHAPE_item_revision_post_processing_failed      (EMH_TCTRUSHAPE_error_base + 33) /* 85033 */
    /* Failed to post process item revisions
     */

#define TCTRUSHAPE_spatial_data_already_exists                (EMH_TCTRUSHAPE_error_base + 34) /* 85034 */

#define TCTRUSHAPE_spatial_data_already_opened                (EMH_TCTRUSHAPE_error_base + 35) /* 85035 */

#define TCTRUSHAPE_spatial_data_not_opened                    (EMH_TCTRUSHAPE_error_base + 36) /* 85036 */

#define TCTRUSHAPE_unsupported_spatial_data_access_mode       (EMH_TCTRUSHAPE_error_base + 37) /* 85037 */

#define TCTRUSHAPE_spatial_data_not_found                     (EMH_TCTRUSHAPE_error_base + 38) /* 85038 */

#define TCTRUSHAPE_jt2ug_load_failure                         (EMH_TCTRUSHAPE_error_base + 39) /* 85039 */
    /* Failed to load jt2ug module
     */

#define TCTRUSHAPE_jt_file_load_failure                       (EMH_TCTRUSHAPE_error_base + 40) /* 85040 */
    /* Failed to load jt file
     */

#define TCTRUSHAPE_invalid_zone_relative_position             (EMH_TCTRUSHAPE_error_base + 41) /* 85041 */
    /* ITK was passed unsupported zone relative position
     */

#define TCTRUSHAPE_unsupported_search_criteria_combination    (EMH_TCTRUSHAPE_error_base + 42) /* 85042 */
    /* ITK was passed unsupported zone relative position
     */

#define TCTRUSHAPE_translation_jt2tso_failed                  (EMH_TCTRUSHAPE_error_base + 43) /* 85043 */
     /* failed to translate the trushape file from JT file
     */

#define TCTRUSHAPE_failed_to_open_file                        (EMH_TCTRUSHAPE_error_base + 44) /* 85044 */
     /* failed to open a file for either read or write
     */

#define TCTRUSHAPE_dataset_multiple_jt_files                  (EMH_TCTRUSHAPE_error_base + 45) /* 85045 */
     /* directmodel dataset with multiple JT files
     */

#define TCTRUSHAPE_dataset_no_jt_file                         (EMH_TCTRUSHAPE_error_base + 46) /* 85046 */
     /* directmodel dataset with no JT files
     */
#define TCTRUSHAPE_err_max_cells_exceeded                     (EMH_TCTRUSHAPE_error_base + 47) /* 85047 */
     /* Number of cells exceeds allowable spacemap size limits.
     */
#include <tctrushape/libtctrushape_undef.h>
#endif /* TCTRUSHAPE_ERRORS_H */

