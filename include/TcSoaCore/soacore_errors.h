/* =================================================================================================
           Copyright (c) 1999,2000,2001,2003 Unigraphics Solutions Inc., An EDS Company
                   Unpublished - All rights reserved

   THIS PROGRAM IS AN UNPUBLISHED WORK FULLY PROTECTED BY THE UNITED STATES
  COPYRIGHT LAWS AND IS CONSIDERED A TRADE SECRET BELONGING TO THE COPYRIGHT
                                   HOLDER.
====================================================================================================*/

/**
    @file

    Errors for the soa core services


*/

/** @if HISTORY_SECTION
====================================================================================================
09-Feb-2006  Duane Silkworth         Error codes for soacore
23-Feb-2006  x_pattna                Add data management service specific error handling
01-Mar-2006  x_pattna                Updates to datamanagement error handling
07-Apr-2006  x_chanda                Updates to datamanagement error handling
07-Apr-2006  x_chanda                error handling stuffs
07-Apr-2006  x_chanda                SOACORE_no_attr_name_value_input
17-Apr-2006  x_chanda                Updates to datamanagement error handling
19-Apr-2006  x_chanda                Incorporated review comments from Ron
19-Apr-2006  x_chanda                Incorporated review comments from Balaji
03-Aug-2006  Joe Herbers             Backport SOA from plm2007
28-Sep-2006  pmbrickl                add error codes
25-Jan-2007  x_chanda                Incorporate the review comments
25-Jan-2007  x_chanda                added SOACORE_relation_type_not_found error string
15-Feb-2007  gesubram                Change for Validate Item Id and Rev Id SOA Service
27-Feb-2007  pesharpe                Add error code for getDatasetTypeInfo
28-Feb-2007  x_chanda                added otherSideObject_type_not_found error code
11-Mar-2007  pmbrickl                merge from developer branch
10-Apr-2007  pesharpe                Add expandGRMRelationsForPrimary abd expandGRMRelationsForSecondary to core
27-Apr-2007  x_pattna                Add LOV Service Errors
28-Feb-2008  Sunil Gopinath          Add licensing errors.
07-Mar-2008  Subramonia Kishore      Added error code Relation_already_exists for Properties on Relations
$HISTORY$
==================================================================================================
@endif */

#ifndef SOACORE_ERRORS_H
#define SOACORE_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup SOACORE_ERRORS TCWS Errors
    @ingroup SOACORE
    @{
*/
/** Login service username does not match session username. */
#define SOACORE_bad_username                                     (EMH_SOACORE_error_base + 0)

/** Login service group does not match session group. */
#define SOACORE_bad_group                                        (EMH_SOACORE_error_base + 1)

/** Logging in with the role "%1$" has failed because the current role is set to "%2$".*/
#define SOACORE_bad_role                                         (EMH_SOACORE_error_base + 2)

/** Invalid preference scopeName value.*/
#define SOACORE_bad_preference_scope                             (EMH_SOACORE_error_base + 3)

/** Failed to load the Object Property Policy %1$.*/
#define SOACORE_invalid_policy                                   (EMH_SOACORE_error_base + 4)

/** %1$.*/
#define SOACORE_policy_detailed_message                          (EMH_SOACORE_error_base + 5)

/** The Object Property Policy %1$ could not be updated. The policy ID must be active in the server's cache. Please use an ID previously returned from a setObjectPropetyPolicy call.*/
#define SOACORE_failed_to_update_policy                          (EMH_SOACORE_error_base + 6)

/** The feature '%1$' is not a valid Client Cache feature.*/
#define SOACORE_client_cache_invalid                             (EMH_SOACORE_error_base + 7)

/** The key "%1$" is not a valid Text Server resource key.*/
#define SOACORE_invalid_text_key                                 (EMH_SOACORE_error_base + 8)

/** The login service group is empty but the login role is not.*/
#define SOACORE_empty_group                                      (EMH_SOACORE_error_base + 9)



/** Where Used Services */
#define SOACORE_invalid_object_tag                               (EMH_SOACORE_error_base + 10)
#define SOACORE_where_referenced_failed                          (EMH_SOACORE_error_base + 11)
#define SOACORE_where_used_failed                                (EMH_SOACORE_error_base + 12)
#define SOACORE_failed_to_lock_object                            (EMH_SOACORE_error_base + 13)
#define SOACORE_setProperties_failed                             (EMH_SOACORE_error_base + 14)
#define SOACORE_empty_attribute_name                             (EMH_SOACORE_error_base + 15)
#define SOACORE_relation_type_not_found                          (EMH_SOACORE_error_base + 16)
#define SOACORE_no_referencer_for_input_relation_type            (EMH_SOACORE_error_base + 17)
#define SOACORE_no_referencer_found                              (EMH_SOACORE_error_base + 18)
#define SOACORE_no_referencer_for_input_otherSideObject_type     (EMH_SOACORE_error_base + 19)
#define SOACORE_null_input_for_relation_name                     (EMH_SOACORE_error_base + 20)
#define SOACORE_empty_property_name                              (EMH_SOACORE_error_base + 21)


/** Data Management Service */
#define SOACORE_no_name_type_input                 (EMH_SOACORE_error_base +  22 )
#define SOACORE_not_folder_relation                (EMH_SOACORE_error_base +  23 )
#define SOACORE_revision_prop_is_null              (EMH_SOACORE_error_base +  24 )
#define SOACORE_nothing_deleted                    (EMH_SOACORE_error_base +  25 )
#define SOACORE_item_prop_is_null                  (EMH_SOACORE_error_base +  26 )
#define SOACORE_no_item_mast_form_props_input      (EMH_SOACORE_error_base +  27 )
#define SOACORE_no_rev_mast_form_props_input       (EMH_SOACORE_error_base +  28 )
#define SOACORE_no_attr_name_value_input           (EMH_SOACORE_error_base +  29 )
#define SOACORE_setImmunity_failed                 (EMH_SOACORE_error_base +  30 )
#define SOACORE_purgeSequences_failed              (EMH_SOACORE_error_base +  31 )
#define SOACORE_null_return_from_ask_type          (EMH_SOACORE_error_base +  32 )
#define SOACORE_no_tctype_found                    (EMH_SOACORE_error_base +  33 )

/** An error has occurred during the property validation for the object of client ID "%1$". Please check the returned partial errors related to this object for additional information. */
#define SOACORE_prop_validation_failed             (EMH_SOACORE_error_base +  34 )

/** Datasettype */
#define SOACORE_datasettype_does_not_exist         (EMH_SOACORE_error_base +  35 )

/** The business object of UID "%1$" could not be loaded. */
#define SOACORE_failed_to_load_obj                 (EMH_SOACORE_error_base +  36 )

/** One or more business objects could not be loaded. */
#define SOACORE_failed_to_load_objs                (EMH_SOACORE_error_base +  37 )

/** The business object "%1$" could not be refreshed. Please refer to the Teamcenter server syslog file for more information. */
#define SOACORE_failed_to_refresh_obj              (EMH_SOACORE_error_base +  38 )

/** The business object "%1$" could not be deleted. Please refer to the Teamcenter server syslog file for more information. */
#define SOACORE_failed_to_delete_obj               (EMH_SOACORE_error_base +  39 )

/** The business object "%1$" could not be revised. */
#define SOACORE_failed_to_revise_obj               (EMH_SOACORE_error_base +  40 )

/** Validate Ids */
#define SOACORE_unable_to_validate_Id              (EMH_SOACORE_error_base +  41 )

/** The user "%1$" has already created the revision "%2$" on the Item "%3$" on date "%4$". Choose a different revision ID and try again.*/
#define SOACORE_failed_to_revise_duplicate_id      (EMH_SOACORE_error_base +  42 )

/** Utilities */
#define SOACORE_null_return_from_find_relation     (EMH_SOACORE_error_base +  50 )
#define SOACORE_invalid_input_vector               (EMH_SOACORE_error_base +  51 )
#define SOACORE_invalid_dataset_type               (EMH_SOACORE_error_base +  52 )
#define SOACORE_no_attr_values_for_query           (EMH_SOACORE_error_base +  53 )

/** ExpandPrimaryObjects Service (60 - 69) **/
#define SOACORE_null_preference_filters            (EMH_SOACORE_error_base +  60 )

/** List Of Values (LOV) Service (70 - 79) */
#define SOACORE_null_type_input                    (EMH_SOACORE_error_base +  70 )
#define SOACORE_null_prop_input                    (EMH_SOACORE_error_base +  71 )

/* Session Service (80 - 89 ) */
/** The current user does not have permissions to change the bypass flag. */
#define SOACORE_invalid_state_property             (EMH_SOACORE_error_base +  80 )

/** The state propery name, %1$, is not valid. */
#define SOACORE_invalid_bypass_user                (EMH_SOACORE_error_base +  81 )

/** The volume cannot be set to null. */
#define SOACORE_volume_null                        (EMH_SOACORE_error_base +  82 )

/** The local volume cannot be set to null. */
#define SOACORE_local_volume_null                  (EMH_SOACORE_error_base +  83 )

/** The security token could not be generated. */
#define SOACORE_failed_to_generate_token           (EMH_SOACORE_error_base +  84)

/** GetItemFromId Service (90 - 99 ) */
#define SOACORE_item_not_found                     (EMH_SOACORE_error_base +  90 )
#define SOACORE_item_no_read_access                (EMH_SOACORE_error_base +  91 )
#define SOACORE_revision_not_found                 (EMH_SOACORE_error_base +  92 )
#define SOACORE_revision_no_read_access            (EMH_SOACORE_error_base +  93 )
#define SOACORE_dataset_not_found                  (EMH_SOACORE_error_base +  94 )
#define SOACORE_dataset_no_read_access             (EMH_SOACORE_error_base +  95 )
#define SOACORE_multiple_items_found               (EMH_SOACORE_error_base +  96 )

/** Generic creation (100 - 109) */
#define SOACORE_object_not_created                 (EMH_SOACORE_error_base +  100 )

/** ExpandGRMs Service (130 - 139) */
#define SOACORE_dm_egr_invalid_object              (EMH_SOACORE_error_base +  131 )

/** Both primary and secondary objects are null. */
#define SOACORE_pri_and_sec_are_null               (EMH_SOACORE_error_base +  132 )

/** Project Level Security (201 - 210) */
#define SOACORE_unable_to_assign_object            (EMH_SOACORE_error_base +  201 )
#define SOACORE_unable_to_remove_object            (EMH_SOACORE_error_base +  202 )

/** Alternate Id (211 - 220) */
#define SOACORE_invalid_type_tag                   (EMH_SOACORE_error_base +  211 )
#define SOACORE_invalid_display_rule_tag           (EMH_SOACORE_error_base +  212 )

/** Wire Harness SOA error IDs */
#define SOACORE_error_in_creating_structure_association  (EMH_SOACORE_error_base +  213 )
#define SOACORE_invalid_association_type           (EMH_SOACORE_error_base +  214 )
#define SOACORE_invalid_input_primary_is_null      (EMH_SOACORE_error_base +  215 )
#define SOACORE_invalid_input_secondary_is_null    (EMH_SOACORE_error_base +  216 )
#define SOACORE_failed_to_get_primaries            (EMH_SOACORE_error_base +  217 )
#define SOACORE_unable_to_get_secondaries          (EMH_SOACORE_error_base +  218 )
#define SOACORE_failed_to_get_secondaries          (EMH_SOACORE_error_base +  219 )
#define SOACORE_unable_to_remove_structure_association (EMH_SOACORE_error_base +  220 )
#define SOACORE_failed_to_remove_structure_association (EMH_SOACORE_error_base +  221 )

#define SOACORE_unable_to_create_itemelement       (EMH_SOACORE_error_base +  222 )
#define SOACORE_failed_to_create_itemelement       (EMH_SOACORE_error_base +  223 )

#define SOACORE_failed_to_update_itemelement_property (EMH_SOACORE_error_base +  224 )
#define SOACORE_invalid_input_for_itemelement_create  (EMH_SOACORE_error_base +  225 )

#define SOACORE_failed_to_create_form               (EMH_SOACORE_error_base +  226 )
#define SOACORE_failed_to_set_property              (EMH_SOACORE_error_base +  227 )
#define SOACORE_failed_to_create_connection         (EMH_SOACORE_error_base +  228 )
#define SOACORE_failed_to_create_route_location     (EMH_SOACORE_error_base +  229 )
#define SOACORE_failed_to_add_object_into_container (EMH_SOACORE_error_base +  230 )

/** Favorites Service (231 - 260) */
#define SOACORE_getFavorites_ask_pref_failed        (EMH_SOACORE_error_base +  231 )
#define SOACORE_getFavorites_missing_field          (EMH_SOACORE_error_base +  232 )
#define SOACORE_getFavorites_obj_not_found          (EMH_SOACORE_error_base +  233 )
#define SOACORE_getFavorites_internal_failed        (EMH_SOACORE_error_base +  234 )
#define SOACORE_getFavorites_failed                 (EMH_SOACORE_error_base +  235 )
#define SOACORE_setFavorites_invalid_container_id   (EMH_SOACORE_error_base +  236 )
#define SOACORE_setFavorites_no_container_id        (EMH_SOACORE_error_base +  237 )
#define SOACORE_setFavorites_no_container_type      (EMH_SOACORE_error_base +  238 )
#define SOACORE_setFavorites_no_container_name      (EMH_SOACORE_error_base +  239 )
#define SOACORE_setFavorites_no_container_parent_id (EMH_SOACORE_error_base +  240 )
#define SOACORE_setFavorites_dup_container_id       (EMH_SOACORE_error_base +  241 )

#define SOACORE_setFavorites_prep_cntnrs_failed     (EMH_SOACORE_error_base +  242 )
#define SOACORE_setFavorites_invalid_obj_type       (EMH_SOACORE_error_base +  243 )
#define SOACORE_setFavorites_invalid_obj_uid        (EMH_SOACORE_error_base +  244 )
#define SOACORE_setFavorites_obj_not_found          (EMH_SOACORE_error_base +  245 )
#define SOACORE_setFavorites_no_obj_name            (EMH_SOACORE_error_base +  246 )
#define SOACORE_setFavorites_unknown_parent         (EMH_SOACORE_error_base +  247 )
#define SOACORE_setFavorites_no_obj_parent_id       (EMH_SOACORE_error_base +  248 )
#define SOACORE_setFavorites_prep_objs_failed       (EMH_SOACORE_error_base +  249 )

#define SOACORE_setFavorites_save_failed            (EMH_SOACORE_error_base +  250 )
#define SOACORE_setFavorites_cur_favs_not_latest    (EMH_SOACORE_error_base +  251 )
#define SOACORE_setFavorites_failed                 (EMH_SOACORE_error_base +  252 )

/** GDELinks Service (261 - 270) **/

#define SOACORE_failed_to_create_GDELink            (EMH_SOACORE_error_base +  261 )
#define SOACORE_failed_to_update_GDELink_property   (EMH_SOACORE_error_base +  262 )
#define SOACORE_invalid_input_for_GDELink_create    (EMH_SOACORE_error_base +  263 )

/** The Participant "%1$" could not be removed. */
#define SOACORE_failed_to_remove_participant        (EMH_SOACORE_error_base +  264 )
/** The Participant "%1$" could not be added. */
#define SOACORE_failed_to_add_participants          (EMH_SOACORE_error_base +  265 )
/** The Participant could not be created. */
#define SOACORE_failed_to_create_participant        (EMH_SOACORE_error_base +  266 )

/** ADDED BY Properties On Relation sdlc id 7460 **/
/** createCachedRelations 241**/
#define SOACORE_relation_already_exists             (EMH_SOACORE_error_base +  271 )

/** The connection is already established with the locale "%1$", which is different from the requested locale "%2$". **/
#define SOACORE_inconsistent_requested_locale       (EMH_SOACORE_error_base +  280)

/** The thumbnail file tickets could not be retrieved for the Business Object %1$. */
#define SOACORE_failed_to_get_thumbnail_file_tickets      (EMH_SOACORE_error_base +  290)

/** Licensing connect service (301 - 350) **/
/** NOTE: The error numbers assigned in this file must match those in the soacore_errors.xml file **/
#define SOACORE_failed_to_init_ILM_module            (EMH_SOACORE_error_base + 301)
#define SOACORE_failed_to_exit_ILM_module            (EMH_SOACORE_error_base + 302)
#define SOACORE_failed_to_release_ILM_module         (EMH_SOACORE_error_base + 303)
#define SOACORE_failed_to_check_ILM_module           (EMH_SOACORE_error_base + 304)
#define SOACORE_failed_to_get_ILM_module             (EMH_SOACORE_error_base + 305)
#define SOACORE_user_does_not_have_license           (EMH_SOACORE_error_base + 306)
#define SOACORE_invalid_action_found                 (EMH_SOACORE_error_base + 307)
#define SOACORE_invalid_scenario_found               (EMH_SOACORE_error_base + 308)
#define SOACORE_input_structure_is_empty             (EMH_SOACORE_error_base + 309)
#define SOACORE_input_quantity_is_null               (EMH_SOACORE_error_base + 310)

/** No input object is being provided. Please select the object to obtain the Traceability Report. */
#define SOACORE_input_object_empty                   (EMH_SOACORE_error_base + 311)

/** The provided report type value is not correct. Valid values are 1, 2 and 3. */
#define SOACORE_invalid_report_type                  (EMH_SOACORE_error_base + 312)

/** The provided report depth value is not correct. Please provide any value greater than zero. */
#define SOACORE_invalid_report_depth                 (EMH_SOACORE_error_base + 313)

/** Internal Envelop service (320 - 323) **/
/** Invalid email addresses are provided **/
#define SOACORE_invalid_email_address                (EMH_SOACORE_error_base + 320)

/** An error has occurred while accessing the attachment file from FMS **/
#define SOACORE_invalid_FMS_ticket                   (EMH_SOACORE_error_base + 321)

/** None of the recipients has a valid email address **/
#define SOACORE_no_valid_recipient                   (EMH_SOACORE_error_base + 322)

/** An error has occurred when sending the email **/
#define SOACORE_email_send_error                     (EMH_SOACORE_error_base + 323)

/** The object "%1$" has been saved as "%2$". Teamcenter, however, did not find a suitable target object into which to paste the newly created object. */
#define SOACORE_paste_failure_no_target_found        (EMH_SOACORE_error_base + 324)

/** The object "%1$" has been saved as "%2$". Instead of Item, however, an item revision might have been pasted to "%3$". */
#define SOACORE_paste_itemrev_instead_of_item        (EMH_SOACORE_error_base + 325)

/** The "Save As" action performed on the object "%1$" has failed. */
#define SOACORE_save_as_failure                      (EMH_SOACORE_error_base + 326)

/** The operation has failed, because the workflow process creation has failed. */
#define SOACORE_workflow_process_not_created         (EMH_SOACORE_error_base + 327 )

/** @} */

/**
    @defgroup ADD_REMOVE_CHILDREN_ERRORS Add Remove Children SOA Errors
    @ingroup SOACORE_ERRORS
    @{
*/
/** An error has occurred while retrieving the default relation given by the "<ParentTypeName>_<ChildTypeName>_default_relation" preference. Please consult the Teamcenter server syslog file and report this error to your system administrator. */
#define SOACORE_failed_relation                      (EMH_SOACORE_error_base + 350)
/** A failure has occurred while adding child object to the parent object "%1$". Only one object is allowed. */
#define SOACORE_failed_add_children                  (EMH_SOACORE_error_base + 351)

/** A child object already exists on the parent object "%1$". Only one object is allowed. */
#define SOACORE_cannot_add_more_children             (EMH_SOACORE_error_base + 352)

/** The object "%1$" cannot be added to the parent object, because it is already there. */
#define SOACORE_cannot_add_existing_object           (EMH_SOACORE_error_base + 353)

/** The object "%1$" cannot be added to itself. */
#define SOACORE_cannot_add_object_to_itself          (EMH_SOACORE_error_base + 354)

/** A failure has occurred while removing children from the parent object "%1$". Please consult the Teamcenter server syslog file for more details. */
#define SOACORE_failed_remove_children               (EMH_SOACORE_error_base + 355)

/** No child object can be removed from the parent object "%1$", because it does not contain any children. */
#define SOACORE_no_children                          (EMH_SOACORE_error_base + 356)

/** The following specified objects are not currently children of the parent object "%1$": %2$. They cannot, therefore, be removed. */
#define SOACORE_non_existing_objects                 (EMH_SOACORE_error_base + 357)

/** No input child object is provided. */
#define SOACORE_no_children_provided                 (EMH_SOACORE_error_base + 358)

/** The target object "%1$" cannot be modified, because the current user does not have write access. */
#define SOACORE_no_write_access                      (EMH_SOACORE_error_base + 359)

/** The user "%1$" has already created the revision "%2$" on the Item "%3$" on date "%4$". Choose a different revision ID and retry the Revise operation. */
#define SOACORE_revision_creation_failed             (EMH_SOACORE_error_base + 360)

/** @} */

/**
    @defgroup SOACORE_IDGENERATIONRULE__ERRORS ID Generation Rule SOA Errors
    @ingroup SOACORE_ERRORS
    @{
*/
/** The generation of ID using the ID Generation Rule has failed, because the Business Object specified in the CreateInput is empty. */
#define SOACORE_empty_object_for_id_generation_rule                  (EMH_SOACORE_error_base + 361)

/** The generation of ID using the ID Generation Rule has failed, because the specified property is empty. */
#define SOACORE_empty_property_for_id_generation_rule                (EMH_SOACORE_error_base + 362)

/** The generation of ID using the ID Generation Rule has failed, because an invalid quantity ("%1$) has been specified. A valid quantity must be more than 0. */
#define SOACORE_invalid_quantity_for_id_generation_rule              (EMH_SOACORE_error_base + 363)

/** The generation of ID using the ID Generation Rule has failed, because an invalid Create Input has been provided. */
#define SOACORE_invalid_createInput_for_id_generation_rule           (EMH_SOACORE_error_base + 364)

/** IDs were partially generated for the type "%1$" and the property "%2$". The counter might have been exhausted while generating IDs. Please increase the maximum value of counter segment for respective Concatenation Rule. */
#define SOACORE_ids_partially_generated                              (EMH_SOACORE_error_base + 365)

/** The generation of ID using the ID Generation Rule has failed for the type "%1$" and the property "%2$". Please consult the Teamcenter server syslog file for more details, and report this error to your system administrator. */
#define SOACORE_unable_to_generate_ids_for_id_generation_rule        (EMH_SOACORE_error_base + 366)

/** @} */

/**
    @defgroup SOACORE_MISC__ERRORS Miscellaneous SOA Errors
    @ingroup SOACORE_ERRORS
    @{
*/
/** The selected Participant was already removed. */
#define SOACORE_invalid_participant_tag                              (EMH_SOACORE_error_base + 367)

/** The selected operation input "%1$" is invalid, because valid values are 1 (Create), 2 (Revise) and 3 (Save as). */
#define SOACORE_invalid_operation                                    (EMH_SOACORE_error_base + 368)

/** The operation has failed during row addition. Please refer to the Teamcenter server syslog file for more details.   */
#define SOACORE_associate_row_with_property                          (EMH_SOACORE_error_base + 369)

/** An error has occurred while reassigning participants. Please consult the Teamcenter server syslog file for more details. */
#define SOACORE_failed_to_reassign_participants                      (EMH_SOACORE_error_base + 370)

/** An error has occurred while updating the default group. Please consult the Teamcenter server syslog file for more details. */
#define SOACORE_failed_to_update_default_group                       (EMH_SOACORE_error_base + 371)

/** An error has occurred while updating the default role. Please consult the Teamcenter server syslog file for more details. */
#define SOACORE_failed_to_update_default_role                        (EMH_SOACORE_error_base + 372)

/** An error has occurred while updating the default project. Please consult the Teamcenter server syslog file for more details. */
#define SOACORE_failed_to_update_default_project                     (EMH_SOACORE_error_base + 373)

/** Multiple values for the option "%1$" are not allowed. Please provide only one value. */
#define SOACORE_multiple_option_values                               (EMH_SOACORE_error_base + 374)

/** An error has occurred while performing the "Save As" operation. Please refer to the Teamcenter server syslog file for more details. */
#define SOACORE_save_as_failed                                       (EMH_SOACORE_error_base + 375)

/** An error has occurred while performing the "Revise" operation. Please refer to the Teamcenter server syslog file for more details. */
#define SOACORE_revise_failed                                        (EMH_SOACORE_error_base + 376)

/** @} */



/**
    @defgroup SOFTWARE ANALYTICS ERRORS Software Analytics Data Errors
    @ingroup SOACORE_ERRORS
    @{
*/
/** The operation to retrieve the required data for software analytics has failed. Please refer to the Teamcenter server syslog file for more information. */
#define SOACORE_failed_to_fetch_software_analytics_data              (EMH_SOACORE_error_base + 377)
/** @} */



/**
    @ingroup SOACORE_MISC__ERRORS
    @{
*/
/** Not all the information related to the data to "Save As" is supplied. Please report this error to your system administrator. */
#define SOACORE_save_as_size_not_match                               (EMH_SOACORE_error_base + 378)

/** Provide a new owning program to be assigned. */
#define SOACORE_invalid_input_program                                (EMH_SOACORE_error_base + 379)

/** Provide an object whose owning program needs to be changed. */
#define SOACORE_invalid_input_objects                                (EMH_SOACORE_error_base + 380)

/** "%1$" is invalid. Only Items or Item Revisions can be selected. */
#define SOACORE_invalid_selection                                    (EMH_SOACORE_error_base + 381)

/** "%1$" is invalid. Valid types are Items, Item Revisions, Forms and Datasets. */
#define SOACORE_invalid_object_for_autoassigntoproject               (EMH_SOACORE_error_base + 382)

/** No object is provided. */
#define SOACORE_no_input_objects                                     (EMH_SOACORE_error_base + 383)

/** The "autoAssignToProject" extension is not enabled on "%1$". Please contact your system administrator. */
#define SOACORE_autoassigntoproject_not_enabled                      (EMH_SOACORE_error_base + 384)

/** "%1$" out of "%2$" Items were updated with the new owning program. */
#define SOACORE_changeowningprogram_partial_success                  (EMH_SOACORE_error_base + 385)

/** The business object was successfully cut from the parent, but could not be deleted. Please refer to the Teamcenter server syslog file for more information. */
#define SOACORE_single_object_successfully_cut_but_not_deleted       (EMH_SOACORE_error_base + 386)

/** The business objects were successfully cut from the parent, but some could not be deleted. Please refer to the Teamcenter server syslog file for more information. */
#define SOACORE_objects_successfully_cut_but_not_deleted             (EMH_SOACORE_error_base + 387)
/** @} */

/**
    @defgroup SOACORE_ACTIVEMODELER__ERRORS Active Modeler SOA Errors
    @ingroup SOACORE_ERRORS
    @{
*/

 /** The size of the array specified for the attribute "%1$" is invalid. */
#define SOACORE_invalid_array_length                                 ( EMH_SOACORE_error_base + 388 )

 /** The addtion of new property on type "%1$" is not supported. */
#define SOACORE_property_addition_not_allowed                        ( EMH_SOACORE_error_base + 389 )

 /** The property "%1$" is already defined on "%2$", which is a subtype of "%3$". */
#define SOACORE_property_present_on_subtype                          ( EMH_SOACORE_error_base + 390 )

 /** The 'Nulls Not Allowed' property "%1$" cannot be added as there are instances of type "%2$" in the database. */
#define SOACORE_instances_present                                    ( EMH_SOACORE_error_base + 391 )

 /** The addition of new property of type "%1$" is not supported.  */
#define SOACORE_invalid_property_type_for_create                     ( EMH_SOACORE_error_base + 392 )

/** @} */

#endif
