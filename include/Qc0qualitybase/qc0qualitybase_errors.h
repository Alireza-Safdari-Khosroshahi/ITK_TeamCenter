/*
  Copyright 2020 Siemens Digital Industries Software
  ==================================================
  Copyright $2018.
  Siemens Product Lifecycle Management Software Inc.
  All Rights Reserved.
  ==================================================
  Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    Quality Center Base Error Codes Declaration

*/

#ifndef QC0QUALITYBASE_ERRORS_H
#define QC0QUALITYBASE_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup QC0QUALITYBASE_ERRORS_H Quality Center Base Errors
    @ingroup QC0QUALITYBASE
    @{
*/

/**
 *  A Characteristics Group "%1$" already exists.
 */
#define QC0QUALITYBASE_char_group_exists                                ( EMH_QC0QUALITYCENTERBASE_error_base + 1 )

/**
 *  A Characteristic cannot be created because it already exists with similar values.
 */
#define QC0QUALITYBASE_char_specification_exists                              ( EMH_QC0QUALITYCENTERBASE_error_base + 2 )

/**
 *  "%1$" was not added because it already exists in "%2$".
 */
#define QC0QUALITYBASE_failure_specification_exists                           ( EMH_QC0QUALITYCENTERBASE_error_base + 3 )

/**
 *  "%1$" was not added because it already exists.
 */
#define QC0QUALITYBASE_failure_catalogue_exists                               ( EMH_QC0QUALITYCENTERBASE_error_base + 4 )
  
/**
 *  "%1$" is not latest specification.
 */ 
#define QC0QUALITYBASE_specification_is_not_latest                            ( EMH_QC0QUALITYCENTERBASE_error_base + 5 )

/**
 *  Failure specification with failure ID "%1$" and Version info "%2$" exists.
 */
#define QC0QUALITYBASE_specification_version_exists                           ( EMH_QC0QUALITYCENTERBASE_error_base + 6 )

 /**
  *  "%1$" was not moved because all or part of it already exists within "%2$".
  */
#define QC0QUALITYBASE_specification_not_moved_bcoz_cyclic_dependency_exists  ( EMH_QC0QUALITYCENTERBASE_error_base + 7 )

/**
  *  "%1$" was not moved because it is not active.
  */
#define QC0QUALITYBASE_specification_not_moved_bcoz_not_active                ( EMH_QC0QUALITYCENTERBASE_error_base + 8 )

/**
  *  "%1$" was not moved because "%2$" is not active.
  */
#define QC0QUALITYBASE_parent_specification_not_moved_bcoz_not_active         ( EMH_QC0QUALITYCENTERBASE_error_base + 9 )

 /**
 *  A Characteristic "%1$" with version information "%2$" already exists.
 */
#define QC0QUALITYBASE_char_specification_version_exists                      ( EMH_QC0QUALITYCENTERBASE_error_base + 10 )

 /**
 *  "%1$" was not deleted because it has children.
 */
#define QC0QUALITYBASE_parent_specification_cannot_delete                     ( EMH_QC0QUALITYCENTERBASE_error_base + 11 )

 /**
 *  "%1$" was not moved because it is not the latest.
 */
#define QC0QUALITYBASE_specification_not_moved_bcoz_not_latest                ( EMH_QC0QUALITYCENTERBASE_error_base + 12 )

 /**
 *  "%1$" was not moved because "%2$" is not the latest.
 */
#define QC0QUALITYBASE_specification_not_moved_bcoz_parent_not_latest         ( EMH_QC0QUALITYCENTERBASE_error_base + 13 )

/** @} */
#endif
