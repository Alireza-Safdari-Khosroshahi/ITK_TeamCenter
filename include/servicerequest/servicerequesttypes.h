//
//   Copyright 2020 Siemens Digital Industries Software
//   ==================================================
//   Copyright 2009.
//   Siemens Product Lifecycle Management Software Inc.
//   All Rights Reserved.
//   ==================================================
//   Copyright 2020 Siemens Digital Industries Software
//

//
//
//    @file       : servicerequesttypes.h
//
//    Description: This File gives the Definitions of all the servicerequest
//                 Types used
//

#ifndef SERVICEREQUEST_TYPES_H
#define SERVICEREQUEST_TYPES_H
#include <servicerequest/libservicerequest_exports.h>
#include <unidefs.h>

// SERVICEREQUEST Types

#define SRP_SRP0MROSupervisor              "SRP0MROSupervisor"
#define SRP_SRP0SupervisorAssignableCond   "SRP0SupervisorAssignableCond"
#define SRP_SRP0IsSupervisorAssignable     "SRP0IsSupervisorAssignable"
#define SRP_MROSUPERVISOR                  "MROSUPERVISOR"
#define SRP_CANCELED                       "Canceled"
#define SRP_OPEN                           "Open"
#define SRP_SUPERSEDED                     "Superseded"
#define SRP_CLOSED                         "Closed"
#define SRP_SRP0SERVICEREQUEST             "srp0ServiceRequest"
#define SRP_SRP0SERVICEOFFERINGS           "srp0ServiceOfferings"
#define SRP_SRP0REQUESTEDACTIVITY          "SRP0RequestedActivity"

// SERVICEREQUEST Relation Types
#define SRP_SRP0PHYSICALELEMENTSREL         "SRP0MROProduct"
#define SRP_SRP0CUSTOMERCONTACTREL          "SRP0CustomerContact"
#define SRP_SRP0LOCATIONINCOMPANYREL        "LocationInCompany"
#define SRP_HWSOSTRUCTUREREL                "HWSOStructure"
#define SRP_SRP0PERFORMSSREL                "SRP0Performs"
#define SRP_SRP0INCLUDESACTIVITYREL         "SRP0IncludesActivity"
#define SRP_SRP0DELGATESTOREL               "SRP0DelgatesTo"
#define SRP_SRP0ACTIVITYOFFERING            "SRP0ActivityOffering"

// LOV Name

// Conditions
#define SRP_IsRequestedActivityCancelable  "SRP0IsRequestedActivityCancelable"
#define SRP_IsServiceRequestCancelable     "SRP0IsServiceRequestCancelable"
#define SRP0IsRequestedActivityInvalidForRollup "SRP0IsRequestedActivityInvalidForRollup"
#define SRP0IsRequestedActivityDelegateable "SRP0IsRequestedActivityDelegateable"
#define SRP0IsRequestedActivityQualifiable "SRP0IsRequestedActivityQualifiable"

// Attribute names
#define SRP_LICENSELEVELATTR               "license_level"
#define SRP_OBJECTNAMEATTR                 "object_name"
#define SRP_ITEMIDATTR                     "item_id"
#define SRP_OBJECTTYPEATTR                 "object_type"
#define SRP_REVISIONATTR                   "revision"
#define SRP_SERVICEOFFERINGNUMBERATTR      "SRP0ServiceOfferingNumber"
#define SRP_SERVICECODEATTR                "SRP0ServiceCode"
#define SRP_NARRATIVEATTR                  "SRP0Narrative"
#define SRP_SRP0SERVICECATALOGATTR         "srp0ServiceCatalog"
#define SRP_SRP0INITIATIONDATEATTR         "SRP0InitiationDate"
#define SRP_SRP0PURPOSEATTR                "SRP0Purpose"
#define SRP_SRP0PHYSICALELEMENTSATTR       "srp0PhysicalElements"
#define SRP_SRP0PHYSICALELEMENTATTR        "srp0PhysicalElement"
#define SRP_SRP0PRODUCTCATALOGATTR         "srp0NeutralPart"
#define SRP_SRP0ACTIVITYCOSTATTR           "SRP0ActivityCost"
#define SRP_ACTUALLABORHOURSATTR           "actual_labor_hours"
#define SRP_SRP0NEEDEDBYDATEATTR           "SRP0NeededByDate"
#define SRP_SRP0ACTIVITYCOSTATTR           "SRP0ActivityCost"
#define SRP_ESTIMATEDLABORHOURSATTR        "estimated_labor_hours"
#define SRP_ESTIMATEDLABORCOSTATTR         "estimated_labor_cost"
#define SRP_ESTIMATEDMATERIALCOSTATTR      "estimated_material_cost"
#define SRP_ESTIMATEDTOTALCOSTATTR         "estimated_total_cost"
#define SRP_CMCLOSUREATTR                  "CMClosure"
#define SRP_CMMATURITYATTR                 "CMMaturity"
#define SRP_SRP0REQUESTEDACTIVITYTATTR     "SRP0RequestedActivity"
#define SRP_SRP0CUSTOMERCONTACTATTR         "srp0CustContact"
#define SRP_SRP0CUSTOMERLOCATIONATTR        "srp0CustLocation"



// SERVICEPROCESSING Relation Types

#define SRP_SRP0PRODUCTCATALOGREL         "SRP0ProductCatalog"
#define SRP_HWSOSTRUCTUREREL              "HWSOStructure"

// Preference Names

#include <servicerequest/libservicerequest_undef.h>
#endif
