/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2008.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

#ifndef SERVICEEVENTMANAGEMENT_ERRORS_H
#define SERVICEEVENTMANAGEMENT_ERRORS_H

#include <common/emh_const.h>
#include <serviceeventmanagement/libserviceeventmanagement_exports.h>

/**
    @defgroup SERVICEEVENTMANAGEMENT_ERRORS Errors
    @ingroup SERVICEEVENTMANAGEMENT
    @{
*/

#define SERVICEEVENTMANAGEMENT_error_base                                  EMH_SERVICEEVENTMANAGEMENT_error_base

/**
    The Service Event cannot be created without an In Progress relation to a Physical Part.
*/
#define SERVICEEVENTMANAGEMENT_service_event_not_related_to_physical_part  (SERVICEEVENTMANAGEMENT_error_base + 1)

/**
    The physical part can not be found.
*/
#define SERVICEEVENTMANAGEMENT_physical_part_not_found  (SERVICEEVENTMANAGEMENT_error_base + 2)

/**
    The physical part revision can not be found.
*/
#define SERVICEEVENTMANAGEMENT_physical_part_revision_not_found  (SERVICEEVENTMANAGEMENT_error_base + 3)

/**
    The Service Event cannot be created because Physical Part not found.
*/
#define SERVICEEVENTMANAGEMENT_se_plmxml_physical_part_revision_not_found  (SERVICEEVENTMANAGEMENT_error_base + 4)

/**
    Physical Part Revision URI not found.
*/
#define SERVICEEVENTMANAGEMENT_se_plmxml_physical_part_revision_uri_not_found  (SERVICEEVENTMANAGEMENT_error_base + 5)

/**
    The Service Group cannot be created.
*/
#define SERVICEEVENTMANAGEMENT_se_plmxml_service_group_cannot_be_created  (SERVICEEVENTMANAGEMENT_error_base + 6)

/**
    The Service Event cannot be created.
*/
#define SERVICEEVENTMANAGEMENT_se_plmxml_service_event_cannot_be_created  (SERVICEEVENTMANAGEMENT_error_base + 7)

/**
    Unable to resolve Contains URI.
*/
#define SERVICEEVENTMANAGEMENT_se_plmxml_unable_to_resolve_contains_URI  (SERVICEEVENTMANAGEMENT_error_base + 8)

/**
    Unable to resolve Part Movement URI.
*/
#define SERVICEEVENTMANAGEMENT_se_plmxml_unable_to_resolve_part_movement_URI  (SERVICEEVENTMANAGEMENT_error_base + 9)

/**
    Unable to resolve Activity Entry Value URI.
*/
#define SERVICEEVENTMANAGEMENT_se_plmxml_unable_to_resolve_activitye_entry_value_URI  (SERVICEEVENTMANAGEMENT_error_base + 10)

/**
    Unable to find Physical Part Revision relate to.
*/
#define SERVICEEVENTMANAGEMENT_se_plmxml_unable_to_find_physical_part_revision  (SERVICEEVENTMANAGEMENT_error_base + 11)

/**
    Service Event already exist.
*/
#define SERVICEEVENTMANAGEMENT_se_plmxml_service_event_already_exist (SERVICEEVENTMANAGEMENT_error_base + 12)

/**
    Service Group '%1$' already exist.
*/
#define SERVICEEVENTMANAGEMENT_se_plmxml_service_group_already_exist (SERVICEEVENTMANAGEMENT_error_base + 13)

/**
    Activity Cost URI not found.
*/
#define SERVICEEVENTMANAGEMENT_se_plmxml_activity_cost_iri_not_found  (SERVICEEVENTMANAGEMENT_error_base + 14)

/**
   Actual Labor Cost URI not found.
*/
#define SERVICEEVENTMANAGEMENT_se_plmxml_actual_labor_cost_not_found  (SERVICEEVENTMANAGEMENT_error_base + 15)

/**
    Actual Material Cost URI not found.
*/
#define SERVICEEVENTMANAGEMENT_se_plmxml_actual_material_cost_not_found  (SERVICEEVENTMANAGEMENT_error_base + 16)

/** @} */

#include <serviceeventmanagement/libserviceeventmanagement_undef.h>

#endif
