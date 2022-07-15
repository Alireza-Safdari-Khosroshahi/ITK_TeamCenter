/* Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright 2020.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software
*/
/*
===================================================================================
File description:

Filename:  caesimulationprocessmanagement_errors.h
module:    CAE0SimulationProcessManagement

This file contains the error codes for the CAE0SimulationProcessManagement module
====================================================================================================*/

#ifndef CAE0SIMULATIONPROCESSMANAGEMENT_ERRORS_H
#define CAE0SIMULATIONPROCESSMANAGEMENT_ERRORS_H

#include <common/emh_const.h>

/**
* A CAE Folder with the name "%1$" already exists under the parent context "%2$".
*/
#define CAE0_duplicate_file_collection_name                           (EMH_CAE0SIMULATIONPROCESSMANAGEMENT_error_base + 1)

/**
* The CAE Folder "%1$" cannot be pasted because it would create a circular reference.
*/
#define CAE0_circular_reference_of_file_collection                    (EMH_CAE0SIMULATIONPROCESSMANAGEMENT_error_base + 2)

/**
* The CAE Folder "%1$" cannot be deleted due to multiple references.
*/
#define CAE0_multiple_references_of_file_collection                   (EMH_CAE0SIMULATIONPROCESSMANAGEMENT_error_base + 3)

/**
* The CAE Folder "%1$" cannot be deleted because it is checked-out.
*/
#define CAE0_unable_to_delete_file_collection                         (EMH_CAE0SIMULATIONPROCESSMANAGEMENT_error_base + 4)

/**
* The CAE Folder "%1$" cannot be deleted because its sub-folder "%2$" contains multiple references.
*/
#define CAE0_multiple_references_of_child_file_collection             (EMH_CAE0SIMULATIONPROCESSMANAGEMENT_error_base + 5)

/**
* The CAE Folder "%1$" cannot be deleted because its sub-folder "%2$" is checked-out.
*/
#define CAE0_unable_to_delete_child_file_collection                   (EMH_CAE0SIMULATIONPROCESSMANAGEMENT_error_base + 6)

/**
* The file "%1$" cannot be added to the StructureMap Filter Dataset "%2$" because the StructureMap Filter Dataset allows only one file to be added. 
  Remove the existing file "%3$" and retry the operation.
*/
#define CAE0_only_single_file_allowed_in_structuremap_filter_dataset  (EMH_CAE0SIMULATIONPROCESSMANAGEMENT_error_base + 7)

/**
* The provided input object "%1$" is invalid because only objects of type "CAE Configuration", with configuration type "Analysis Dashboard" or "Model Dashboard", are allowed.
*/
#define CAE0_invalid_configuration_object                             (EMH_CAE0SIMULATIONPROCESSMANAGEMENT_error_base + 8)

/**
* The provided start index "%1$" is invalid, because the start index must not be greater than total number of objects to monitor "%2$", in order to support the pagination correctly in the Simulation Dashboard.
*/
#define CAE0_invalid_indexing_for_pagination                          (EMH_CAE0SIMULATIONPROCESSMANAGEMENT_error_base + 9)

/**
* The provided dashboard column "%1$" does not exist in the dashboard configuration.
*/
#define CAE0_invalid_dashboard_column_name                           (EMH_CAE0SIMULATIONPROCESSMANAGEMENT_error_base + 10)

/**
* The root item revision "%1$" is invalid. The root item revision should be of type CAE Model Revision or its subtype to be allowed from the BOM structure.
*/
#define CAE0_invalid_root_item_revision                              (EMH_CAE0SIMULATIONPROCESSMANAGEMENT_error_base + 11)

/**
* The CAE Boundary Condition Revision "%1$" can not be attached with a relation "%2$" under the object "%3$" of type "%4$", because it is already attached with the object "%5$" of type "%6$".
*/
#define CAE0_extract_relation_cannot_be_created                      (EMH_CAE0SIMULATIONPROCESSMANAGEMENT_error_base + 12)

/**
* The provided input object "%1$" is invalid because only objects of type "CAE Configuration", with configuration type "CAE Package", are allowed.
*/
#define CAE0_invalid_configuration_type                              (EMH_CAE0SIMULATIONPROCESSMANAGEMENT_error_base + 13)

/**
* The provided input context method "%1$" is invalid. The supported input context methods are "%2$", "%3$", "%4$" and "%5$".
*/
#define CAE0_invalid_input_context_method                            (EMH_CAE0SIMULATIONPROCESSMANAGEMENT_error_base + 14)

/**
* The number of visible monitored objects should not be greater than the total number of monitored objects.
*/
#define CAE0_invalid_visible_monitored_objects                       (EMH_CAE0SIMULATIONPROCESSMANAGEMENT_error_base + 15)

#endif
