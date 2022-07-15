/*===============================================================================
Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright $2017.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    This file contains the error codes for the MESBVRINTEG module
*/

#ifndef COMPOSITES_ERRORS_H
#define COMPOSITES_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup COMPOSITES_ERRORS Composites Errors
    @ingroup COMPOSITES
    @{
*/

/** An internal error has occurred in the Composite module. Please contact your system administrator. */
#define COMPOSITES_internal_error                                                   (EMH_COMPOSITES_error_base + 1)

/** The target object "%1$" is not the type of Item Revision. */
#define COMPOSITES_incorrect_selection_type                                         (EMH_COMPOSITES_error_base + 2)

/** The workflow "TcMfg Composites Automation" has failed due to missing or incorrect Datasets and relations of the attached Datasets on the Item Revision "%1$". The fsencapta.xml using "Composite Manufacturing Datase" and "Composite Manufacturing Relation" and the dxf file using "Composite 2D Dataset" and "Composite Laser Projection Relation" are required. */
#define COMPOSITES_no_composite_mfg_dataset                                         (EMH_COMPOSITES_error_base + 3)

/** The workflow "TcMfg Composites Automation" has failed because no dataset can be found with the Item Revision "%1$" and a Drawing Exchange Format (DXF) file references attached to it. */
#define COMPOSITES_no_composite_2d_drawing_dataset                                  (EMH_COMPOSITES_error_base + 4)

/** @} */
#endif