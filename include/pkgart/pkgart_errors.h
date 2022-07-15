/*=============================================================================
 Copyright 2020 Siemens Digital Industries Software
 ==================================================
 Copyright 2015
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2020 Siemens Digital Industries Software
 ===============================================================================*/

/**
    @file

    This file contains the published identifiers of error codes that can be
    generated by this module. Obtaining and using the numeric values of these
    manifest constants is not supported. We reserve the right to change the
    actual values as necessary.

*/

#ifndef PKGART_ERRORS_H
#define PKGART_ERRORS_H

#include <common/emh_const.h>

/* For objects of type %1$, only the ones with property %2$ of value %3$ can be related to the ones with the same property of value %4$ through a &apos;%5$&apos; relation. */
#define PKGART_error_InvalidRelation       ( EMH_PKGART_error_base + 1 )

/* "%1$" contact cannot be related to the brief. All contacts should belong to the same vendor. */
#define PKGART_error_InvalidContact        ( EMH_PKGART_error_base + 2 )

/* The brief and the digital assets cannot be assigned to any project because the vendor must be associated with one and only one project. Please contact system administrator. */
#define PKGART_only_one_project_allowed    ( EMH_PKGART_error_base + 3 )

/* Failure in instantiating the workflow because no Teamcenter user is associated with the contact. Please contact system administrator. */
#define PKGART_cannot_assign_task          ( EMH_PKGART_error_base + 4 )

/* The Panel cannot be revised because it is associated with third party integration. Please contact the system administrator. */
#define PKGART_cannot_revise_panel         ( EMH_PKGART_error_base + 5 )

#endif