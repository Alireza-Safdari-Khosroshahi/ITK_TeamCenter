/* Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright 2010.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software */

/**
@file

TraceLink errors
*/

/*  */

#ifndef TRACELINK_ERRORS_H
#define TRACELINK_ERRORS_H

#include <common/emh_const.h>
#include <common/tc_deprecation_macros.h>

/**
@defgroup TRACELINK_ERRORS Errors
@ingroup TraceLink
@{
*/

/** An invalid primary or secondary object was selected for the relation. */
#define TL_invalid_object_type                  (EMH_TRACELINK_error_base + 1)

/** The conversion from Appearance Path Node to BOM Line has failed. */
#define TL_APN_TO_BOMLINE_CONVERT_FAILED        (EMH_TRACELINK_error_base + 2)

/** The primary BOM View is missing from the Tracelink object. */
#define TL_primary_bom_view_missing             (EMH_TRACELINK_error_base + 3)

/** The secondary BOM View is missing from Tracelink object. */
#define TL_secondary_bom_view_missing           (EMH_TRACELINK_error_base + 4)

/** A NULL value is passed to the function "%1$". */
#define TL_null_value_passed                    (EMH_TRACELINK_error_base + 5)

/** @deprecated #TL_primary_released deprecated in Teamcenter 12.2. Use #TL_primary_baselined instead. */
#define TL_primary_released                     (EMH_TRACELINK_error_base + 6)
TC_DEPRECATED_PREPROCESSOR( "12.2", TL_primary_released, "TL_primary_baselined" )

/** The Tracelink object "%1$" cannot be deleted because its primary object is baselined. */
#define TL_primary_baselined                     (EMH_TRACELINK_error_base + 7)

/** @deprecated #TL_secondary_released deprecated in Teamcenter 12.2. Use #TL_secondary_baselined instead. */
#define TL_secondary_released                   (EMH_TRACELINK_error_base + 8)
TC_DEPRECATED_PREPROCESSOR( "12.2", TL_secondary_released, "TL_secondary_baselined" )

/** The Tracelink object "%1$" cannot be deleted because its secondary object is baselined */
#define TL_secondary_baselined                   (EMH_TRACELINK_error_base + 9)

/** @deprecated #TL_both_released deprecated in Teamcenter 12.2. Use #TL_both_baselined instead. */
#define TL_both_released                        (EMH_TRACELINK_error_base + 10)
TC_DEPRECATED_PREPROCESSOR( "12.2", TL_both_released, "TL_both_baselined" )

/** The Tracelink object "%1$" cannot be deleted because both primary and secondary objects of the Tracelink are baselined. */
#define TL_both_baselined                        (EMH_TRACELINK_error_base + 11)

/** The Tracelink of type "%1$" cannot be created because its primary object is baselined. */
#define TL_create_primary_baselined              (EMH_TRACELINK_error_base + 12)

/** The Tracelink of type "%1$" cannot be created because its secondary object is baselined. */
#define TL_create_secondary_baselined            (EMH_TRACELINK_error_base + 13)

/** The Tracelink of type "%1$" cannot be created because both its primary and secondary objects are baselined. */
#define TL_create_both_baselined                 (EMH_TRACELINK_error_base + 14)

/** @} */

#endif
