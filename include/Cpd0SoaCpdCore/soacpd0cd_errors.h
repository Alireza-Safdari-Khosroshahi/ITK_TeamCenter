/*Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright 2011.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software*/

#ifndef SOACPD0CD_ERRORS_H
#define SOACPD0CD_ERRORS_H

#include <common/emh_const.h>

#define SOACPD0CD_ERROR_BASE                                        EMH_SOA_CPD0CD_error_base

/**
 * An internal SOA error has occurred in the SOA Collaborative Design module.
 */
#define SOACPD0CD_internal_error                                    ( SOACPD0CD_ERROR_BASE + 1 )

/**
 * The input Business Object type name is &quot;%1$&quot;. A type name of Cpd0DesignSubsetElement (Design Subset Element) or one of its sub-types is expected.
 */
#define SOACPD0CD_invalid_botype_error                              ( SOACPD0CD_ERROR_BASE + 2 )

/**
 * The Revision Rule &quot;%1$&quot; specified in the business constant &quot;%2$&quot; is not a valid Revision Rule for Workset Model objects. Please contact your Teamcenter administrator to update the business constant with a valid Revision Rule.
 */
#define CPD0_invalid_default_revision_rule                          ( SOACPD0CD_ERROR_BASE + 3 )

/**
 * The relation attribute &quot;%1$&quot; is not yet implemented. Only the attribute &quot;mdl0cs_id&quot; is currently supported.
 */
#define CPD_relation_attribute_not_implemented                      ( SOACPD0CD_ERROR_BASE + 4 )

/**
 * An invalid relation traversal input is specified. The source object cannot be NULL.
 */
#define CPD0_invalid_relation_traversal_input_s                     ( SOACPD0CD_ERROR_BASE + 5 )

/**
 * An invalid relation traversal input is specified. The size of input objects cannot be 0.
 */
#define CPD0_invalid_relation_traversal_input_i                     ( SOACPD0CD_ERROR_BASE + 6 )

/**
 * An invalid relation traversal input is specified. The attribute type can only be a string and the attribute values can only have string values.
 */
#define CPD0_invalid_relation_traversal_input_a                     ( SOACPD0CD_ERROR_BASE + 7 )

/**
 * The object &quot;%1$&quot; cannot be updated because it has been modified in a different session by the same user. Refresh the object before making new modifications.
 */
#define CPD0_object_is_modified                                     ( SOACPD0CD_ERROR_BASE + 8 )

/**
 * No target Application Model was provided for the model-to-model instantiation.
 */

#define SOACPD0CD_instantiation_no_target_model_provided_as_input   ( SOACPD0CD_ERROR_BASE + 9 )

/**
 * No source Application Model was provided for the model-to-model instantiation.
 */
#define SOACPD0CD_instantiation_no_source_model_provided_as_input   ( SOACPD0CD_ERROR_BASE + 10 )

/**
 * A preview dataset must be provided as input for the Easy 4G preview-based Item Realization.
 */
#define SOACPD0CD_invalid_preview_dataset                           ( SOACPD0CD_ERROR_BASE + 11 )

/**
 * A mapping dataset must be provided as input for the Easy 4G preview-based Item Realization.
 */
#define SOACPD0CD_invalid_mapping_dataset                           ( SOACPD0CD_ERROR_BASE + 12 )

/**
 * A valid Revision Rule must be provided.
 */
#define SOACPD0CD_invalid_revision_rule                             ( SOACPD0CD_ERROR_BASE + 13 )

/**
 * The operation has failed because some input objects are neither Item Revisions (ItemRevision) nor Design Elements (Cpd0DesignElement).
 */
#define SOACPD0CD_invalid_object_type_design_context                ( SOACPD0CD_ERROR_BASE + 14 )

/**
 * Design Contexts can only be created using Items (Item) and Worksets (Cpd0Workset).
 */
#define SOACPD0CD_invalid_object_type_name_design_context           ( SOACPD0CD_ERROR_BASE + 15 )

/**
 * Please provide value for either Shape Design Element or Business Object type.
 */
#define SOACPD0CD_invalid_input_for_create_or_update_shape          ( SOACPD0CD_ERROR_BASE + 16 )

/**
 * The Product Name and Product Namespace supplied to service operation "%1$" must not be empty.
 */
#define SOACPD0CD_productinfo_empty_error                           ( SOACPD0CD_ERROR_BASE + 17 )

/**
* The Design Feature creation or update has failed because either the Design Model Element and/or the Copy Stable ID are not specified.
*/
#define SOACPD0CD_create_or_update_design_feature_failed            ( SOACPD0CD_ERROR_BASE + 18 )

/**
* The Design Feature creation or update has failed because no Design Feature object is specified.
*/
#define SOACPD0CD_invalid_design_feature_object                     ( SOACPD0CD_ERROR_BASE + 19 )

/**
* The creation or processing of a Connected Information has failed because no Connected Element is specified.
*/
#define SOACPD0CD_invalid_connected_element                         ( SOACPD0CD_ERROR_BASE + 20 )

/**
* The Connected object "%1$" do not exist in the same Collaborative Design "%2$" as the Design Feature "%3$".
*/
#define SOACPD0CD_invalid_connected_object_design_feature_relation  ( SOACPD0CD_ERROR_BASE + 21 )

/**
* The creation of the Design Feature has failed because no Business Object type is specified.
*/
#define SOACPD0CD_invalid_business_object_type                      ( SOACPD0CD_ERROR_BASE + 22 )

#endif
