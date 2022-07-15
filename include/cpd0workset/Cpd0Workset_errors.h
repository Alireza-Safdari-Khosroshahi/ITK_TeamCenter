/*Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright $2010.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software*/

/**
    @file Cpd0Workset_errors.h

    Collaborative Design Error Codes Declaration

*/

#ifndef CPD0WORKSET_ERRORS_H
#define CPD0WORKSET_ERRORS_H

#include<common/emh_const.h>

/**
    @defgroup CPD0WORKSET_ERRORS CPD0WORKSET Errors
    @ingroup CPD0WORKSET
    @{
*/

#define CPD0WORKSET_ERROR_BASE                                             EMH_CPD0WORKSET_error_base

/**
 * An internal error has occurred in the Workset module.
 */
#define CPD0WORKSET_internal_error                                         ( EMH_CPD0WORKSET_error_base + 1 )

/**
 * The selected Workset Revision "%1$" is not the latest revision.
 */
#define CPD0WORKSET_not_latest_revision_error                              ( EMH_CPD0WORKSET_error_base + 2 )

/**
 * The reuse input for the creation of a Subset (internal name Cpd0DesignSubsetElement) object is not specified.
 */
#define CPD0WORKSET_reuse_subsetelement_error                              ( EMH_CPD0WORKSET_error_base + 3 )

/**
 * The input list of subordinate Design Elements to be deleted does not contain the complete hierarchy.
 * It is most likely caused by a programming error.
 * Please refer to the Teamcenter server syslog file for missing Design Elements.
 */
#define CPD0WORKSET_subordinate_de_list_invalid                            ( EMH_CPD0WORKSET_error_base + 4 )

/**
 * An invalid argument was input to a function. It is most likely caused by an invalid user input, but could be caused
 * by a programming error. The Teamcenter server syslog file may contain additional notes regarding the error.
 */
#define CPD0WORKSET_invalid_input                                          ( EMH_CPD0WORKSET_error_base + 5 )

/**
 * The Workset cannot be compared by the "4GD to 4GD compare and accountability" functionality, because it contains subset elements belonging to more than one Application Model. Please select individual subset elements to compare.
 */
#define CPD0WORKSET_subset_different_models_error                          ( EMH_CPD0WORKSET_error_base + 6 )

/**
 * The input "%1$" is not a Workset Revision.
 */
#define CPD0WORKSET_not_workset_revision                                   ( EMH_CPD0WORKSET_error_base + 7 )

/**
 * Failed to create CAD structure due to internal error. Please refer to the Teamcenter server syslog file for more details.
 */
#define CPD0WORKSET_cadlayout_creation_error                               ( EMH_CPD0WORKSET_error_base + 8 )

/**
 * The "%1$" inclusion mode on subset item revision is not supported for creating CAD structure.
 */
#define CPD0WORKSET_cadlayout_inclusionmode_not_supported                  ( EMH_CPD0WORKSET_error_base + 9 )

/**
 * The number of objects in Design Contexts exceeds the maximum number specified by the preference "CPD_design_context_maximum_size".
 */
#define CPD_design_context_size_exceed_maximum                             ( EMH_CPD0WORKSET_error_base + 10 )

/**
 * Invalid object provided as Subset.
 */
#define CPD_invalid_subset                                                 ( EMH_CPD0WORKSET_error_base + 11 )

/**
 * Invalid object provided as Partition Scheme.
 */
#define CPD_invalid_partition_scheme                                      ( EMH_CPD0WORKSET_error_base + 12 )

/**
 * Invalid object provided as Partition.
 */
#define CPD_invalid_partition                                             ( EMH_CPD0WORKSET_error_base + 13 )

/**
 * The Partition is not valid for the current configuration of the Subset.
 */
#define CPD_partition_not_configured                                      ( EMH_CPD0WORKSET_error_base + 14 )

/**
 * The Partition has no content for the current configuration of the Subset.
 */
#define CPD_partition_has_no_content                                      ( EMH_CPD0WORKSET_error_base + 15 )

/**
 * A Clearance Calculation "%1$" with identical configuration and recipe already exists on the Product "%2$".
 */
#define CPD_duplicate_clearance_calculation                               ( EMH_CPD0WORKSET_error_base + 16 )

/**
 * It is mandatory to select Include presented parents option for clearance calculation prior to export.
 * Include presented parents option is not selected in search options of Clearance Calculation "%1$" in the Product "%2$".
 * Please select the Include presented parent option and try export again.
 */
#define CPD_clearance_calculation_include_presented_parent_not_selected   ( EMH_CPD0WORKSET_error_base + 17 )

/**
    @}
*/

#endif
