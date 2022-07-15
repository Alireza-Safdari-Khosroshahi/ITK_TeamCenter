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
    Abstract Color Rule   Error Codes Declaration
*/

#ifndef CLR0COLORAPPEARANCE_ERRORS_HXX
#define CLR0COLORAPPEARANCE_ERRORS_HXX

#include <common/emh_const.h>

/**
    @defgroup CLR0COLORAPPEARANCE_ERRORS Errors for Color Appearance application.
    @ingroup CLR0COLORAPPEARANCE
    @{
*/

#define EMH_CLR0COLORAPPEARANCE_ERROR_BASE                                                        EMH_CLR0COLORAPPEARANCE_error_base

/**
 * A name is required for the Color Appearance Group.
 */
#define CLR0COLORAPPEARANCE_empty_group_name_not_allowed                                          ( EMH_CLR0COLORAPPEARANCE_ERROR_BASE + 1 )

/**
 * A Surface Designator is required.
 */
#define CLR0COLORAPPEARANCE_empty_surface_designator_not_allowed                                  ( EMH_CLR0COLORAPPEARANCE_ERROR_BASE + 2 )

/**
 * The Revision Rule specified in the preference "Cbm0DefaultRevisionRule" is invalid.
 */
#define CLR0COLORAPPEARANCE_revision_rule_preference_undefined                                    ( EMH_CLR0COLORAPPEARANCE_ERROR_BASE + 3 )

 /**
 * The Product Appearance Breakdown root of the "%1$" object being pasted must be different from that of the destination objects.
 */
#define CLR0COLORAPPEARANCE_different_product_appearance_breakdown                                ( EMH_CLR0COLORAPPEARANCE_ERROR_BASE + 4 )

 /**
 * "%1$" already has a parent.
 */
#define CLR0COLORAPPEARANCE_parent_exists                                                         ( EMH_CLR0COLORAPPEARANCE_ERROR_BASE + 5 )

 /**
 * A Designator Assignments dataset with the same Product Appearance Breakdown root already exists on the Item Revision.
 */
#define CLR0COLORAPPEARANCE_designator_assignments_dataset_for_pab_root_exists                    ( EMH_CLR0COLORAPPEARANCE_ERROR_BASE + 6  )

 /**
 @}
 */

#endif
