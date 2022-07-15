/*HEAD ICS_ERRORS HHH CLASSIFICATION */
/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Errors for the ICS Layer

    Errors from 71001 to 71500 are allocated for SML and the rest are ICS errors.
    All the SML errors are defined in sml_defines.h.
*/

/*  */

#ifndef ICS_ERRORS_H
#define ICS_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup ICS_ERRORS Errors
    @ingroup ICS
    @{
*/


/** The parent does not exist. */
#define ICS_err_parent_does_not_exist                           (EMH_ICS_error_base + 401)

/** Unable to convert values between metric and non-metric using the specified unit*/
#define ICS_err_invalid_unit_id                                 (EMH_ICS_error_base + 402)

/** Value in target unit is not an Integer **/
#define ICS_err_target_unit_not_integer                         (EMH_ICS_error_base + 403)

/** An error has occurred during value conversion, because the conversion from the unit "%1$" to the unit "%2$" is 
  impossible since they are not of the same measurement type. */
#define ICS_err_unit_conversion                                 (EMH_ICS_error_base + 404)


/** Unable to find the relation */
#define ICS_find_relation_failed                                (EMH_ICS_error_base + 501)

/** Workspace Object already Classified */
#define ICS_wso_already_classified                              (EMH_ICS_error_base + 502)

/** Cannot classify the Workspace Object */
#define ICS_cannot_classify_wso                                 (EMH_ICS_error_base + 503)

/** Workspace object not Classified */
#define ICS_wso_not_classified                                  (EMH_ICS_error_base + 504)

/** Relation Type specified does not exist */
#define ICS_relation_type_does_not_exist                        (EMH_ICS_error_base + 505)

/** Invalid Workspace Object */
#define ICS_invalid_wso                                         (EMH_ICS_error_base + 506)

/** Invalid ICO */
#define ICS_invalid_tag                                         (EMH_ICS_error_base + 507)

/** Cannot add image to this type */
#define ICS_cannot_add_image_to_type                            (EMH_ICS_error_base + 508)

/** Invalid Classification Object */
#define ICS_invalid_ico                                         (EMH_ICS_error_base + 509)

/** Empty Resource Id */
#define ICS_empty_resource_id                                   (EMH_ICS_error_base + 510)

/** Empty name specified */
#define ICS_empty_name                                          (EMH_ICS_error_base + 511)

/** Invalid Group */
#define ICS_invalid_group                                       (EMH_ICS_error_base + 512)

/** Invalid Class */
#define ICS_invalid_class                                       (EMH_ICS_error_base + 513)

/** Invalid View */
#define ICS_invalid_view                                        (EMH_ICS_error_base + 514)

/** Invalid Class Id */
#define ICS_invalid_class_id                                    (EMH_ICS_error_base + 515)

/** Invalid View Id */
#define ICS_invalid_view_id                                     (EMH_ICS_error_base + 516)

/** Invalid UNCT */
#define ICS_invalid_attribute_id                                (EMH_ICS_error_base + 517)

/** Invalid Format */
#define ICS_invalid_format                                      (EMH_ICS_error_base + 518)

/** Invalid attribute name */
#define ICS_invalid_attribute                                   (EMH_ICS_error_base + 519)

/** Classification Object does not exist */
#define ICS_ico_does_not_exist                                  (EMH_ICS_error_base + 520)

/** Workspace Object does not exist */
#define ICS_wso_does_not_exist                                  (EMH_ICS_error_base + 521)

/** Workspace Object Id and Classification Object Id do not match */
#define ICS_mismatch_in_id                                      (EMH_ICS_error_base + 522)

/** Invalid Config Field String */
#define ICS_invalid_config_field_string                         (EMH_ICS_error_base + 523)

/** The Function is not implemented */
#define ICS_err_function_not_implemented                        (EMH_ICS_error_base + 524)

/** The Attribute is not unique */
#define ICS_err_attribute_not_unique                            (EMH_ICS_error_base + 525)

/** The KeyLov does not exist */
#define ICS_err_kelov_does_not_exist                            (EMH_ICS_error_base + 526)

/** The Attribute does not exist */
#define ICS_err_attribute_does_not_exist                        (EMH_ICS_error_base + 527)

/** The Class does not exist */
#define ICS_err_class_does_not_exist                            (EMH_ICS_error_base + 528)

/** The View does not exist */
#define ICS_err_view_does_not_exist                             (EMH_ICS_error_base + 529)

/** The Object is referenced */
#define ICS_err_object_referenced                               (EMH_ICS_error_base + 530)

/** The Classification Object already classifies another Workspace Object */
#define ICS_ico_already_classifying                             (EMH_ICS_error_base + 531)

/** Internal error: invalid read operation */
#define ICS_invalid_read_operation                              (EMH_ICS_error_base + 532)

/** Ownership of object was transferred but it could not be loaded */
#define ICS_SYNC_transferred_but_not_loaded                     (EMH_ICS_error_base + 533)

/** Object is not owned by local site */
#define ICS_SYNC_object_is_remote                               (EMH_ICS_error_base + 534)

/** Object is owned by local site */
#define ICS_SYNC_object_is_local                                (EMH_ICS_error_base + 535)

/** Object does not belong to a synchronizable class */
#define ICS_SYNC_not_a_sync_class                               (EMH_ICS_error_base + 536)

/** Object is not read-only */
#define ICS_SYNC_copy_not_read_only                             (EMH_ICS_error_base + 537)

/** Modify date not set */
#define ICS_SYNC_modify_date_not_set                            (EMH_ICS_error_base + 538)

/** The ICO is not shared */
#define ICS_SYNC_ico_not_shared                                 (EMH_ICS_error_base + 539)

/** The class is not shared */
#define ICS_SYNC_class_not_shared                               (EMH_ICS_error_base + 540)

/** The view is not shared */
#define ICS_SYNC_view_not_shared                                (EMH_ICS_error_base + 541)

/** Invalid Character in the specification for attribute value */
#define ICS_invalid_char_in_attribute                           (EMH_ICS_error_base + 542)

/** Invalid value for Key-LOV attribute */
#define ICS_invalid_keylov_value                                (EMH_ICS_error_base + 543)

/** Can not find the corresponding Teamcenter Engineering property for the runtimeIco */
#define ICS_no_tc_property_for_runtime_ico                    (EMH_ICS_error_base + 544)

/** Internal error, buffer full for runtime Ico or Atrr */
#define ICS_attrsync_runtime_buffer_full                        (EMH_ICS_error_base + 545)

/** Internal error, can not delete the SML object */
#define ICS_can_not_delete_sml_objects                          (EMH_ICS_error_base + 546)

/** The group is not shared. */
#define ICS_SYNC_group_not_shared                               (EMH_ICS_error_base + 547)

/** The object is remote. */
#define ICS_err_object_is_remote                                (EMH_ICS_error_base + 548)

/** Error during hierarchy sharing */
#define ICS_err_share_hierarchy_failed                          (EMH_ICS_error_base + 549)

/** Object was properly saved, but some objects in the hierarchy could not be shared. */
#define ICS_save_some_hierarchy_shares_failed                   (EMH_ICS_error_base + 550)

/** Some objects in the hierarchy could not be shared. */
#define ICS_err_some_hierarchy_shares_failed                    (EMH_ICS_error_base + 551)

/** Object was properly saved, but no hierarchy object could be shared. */
#define ICS_save_all_hierarchy_shares_failed                    (EMH_ICS_error_base + 552)

/** No hierarchy object could be shared. */
#define ICS_err_all_hierarchy_shares_failed                     (EMH_ICS_error_base + 553)

/** No target site given. */
#define ICS_SYNC_no_target_site                                 (EMH_ICS_error_base + 554)

/** More than one target site given. */
#define ICS_SYNC_more_than_one_target_site                      (EMH_ICS_error_base + 555)

/** The object is not a Classification object. */
#define ICS_err_no_inclass_object                               (EMH_ICS_error_base + 556)

/** The object must not be shared. */
#define ICS_SYNC_object_not_shared                              (EMH_ICS_error_base + 557)

/** A tag is missing. */
#define ICS_SYNC_missing_tag                                    (EMH_ICS_error_base + 558)

/** The object does not belong to class or subclass. */
#define ICS_SYNC_not_a_header_class                             (EMH_ICS_error_base + 559)

/** The object does not exist. */
#define ICS_SYNC_object_does_not_exist                          (EMH_ICS_error_base + 560)

/** There is no template of this name. */
#define ICS_err_no_template_of_this_name                        (EMH_ICS_error_base + 561)

/** No revision is configured. */
#define ICS_err_no_configured_revision                          (EMH_ICS_error_base + 562)

/** No UG dataset is attached. */
#define ICS_err_no_ugmaster_dataset                             (EMH_ICS_error_base + 563)

/** The column to map to could not be found. */
#define ICS_err_mapping_column_not_found                        (EMH_ICS_error_base + 564)

/** There is no view for the part family template. */
#define ICS_err_no_view_for_template                            (EMH_ICS_error_base + 565)

/** The mapping is empty. */
#define ICS_err_mapping_is_empty                                (EMH_ICS_error_base + 566)

/** The mapping is not enabled. It must not be used. */
#define ICS_err_mapping_must_not_be_used                        (EMH_ICS_error_base + 567)

/** The column name is empty. */
#define ICS_err_column_name_is_empty                            (EMH_ICS_error_base + 568)

/** The PDI Server for the graphics builder could not be started. */
#define ICS_err_could_not_start_pdiserver                       (EMH_ICS_error_base + 569)

/** The IOR is empty. */
#define ICS_err_empty_ior                                       (EMH_ICS_error_base + 570)

/** The \$TC_BIN directory was not found. */
#define ICS_err_no_tcbin                                        (EMH_ICS_error_base + 571)

/** There is more than one template part. */
#define ICS_err_more_than_one_part_family_template              (EMH_ICS_error_base + 572)

/** A member part cannot be created without specifying a template part. */
#define ICS_err_cannot_create_pf_member_without_pft             (EMH_ICS_error_base + 573)

/** A classifying instance cannot be used for part family member creation (because it will not be possible to attach the item for the member part). */
#define ICS_err_cannot_create_pf_member_from_classifying_ico    (EMH_ICS_error_base + 574)

/** The part family template cannot be used. */
#define ICS_err_requested_pft_cannot_be_used                    (EMH_ICS_error_base + 575)

/** Unknown graphics builder name. */
#define ICS_err_unknown_graphicsbuilder_name                    (EMH_ICS_error_base + 576)

/** Internal error: The instance ID does not match the part family. */
#define ICS_err_internal_wrong_ico_id_for_pf                    (EMH_ICS_error_base + 577)

/** There is more than one item revision selected. */
#define ICS_err_more_than_one_item_revision                     (EMH_ICS_error_base + 578)

/** Unknown error. */
#define ICS_err_unknown_error                                   (EMH_ICS_error_base + 579)

/** A parameter is missing. */
#define ICS_err_missing_parameter                               (EMH_ICS_error_base + 580)

/** A parameter is invalid. */
#define ICS_err_invalid_parameter                               (EMH_ICS_error_base + 581)

/** Invalid value. */
#define ICS_err_invalid_value                                   (EMH_ICS_error_base + 582)

/** Invalid property. */
#define ICS_err_invalid_property                                (EMH_ICS_error_base + 583)

/** The property is read-only. */
#define ICS_err_property_readonly                               (EMH_ICS_error_base + 584)

/** The object is not unique. */
#define ICS_err_object_not_unique                               (EMH_ICS_error_base + 585)

/** The activation method for the graphics builder is invalid. */
#define ICS_err_graphicsbuilder_invalid_activation_method       (EMH_ICS_error_base + 586)

/** The graphics builder option value is invalid. */
#define ICS_err_graphics_builder_invalid_option_value           (EMH_ICS_error_base + 587)

/** The graphics builder port is invalid. */
#define ICS_err_graphicsbuilder_invalid_port                    (EMH_ICS_error_base + 588)

/** The graphics builder option is invalid. */
#define ICS_err_graphics_builder_invalid_option                 (EMH_ICS_error_base + 589)

/** There are no options given for the graphics builder. */
#define ICS_err_graphicsbuilder_no_options                      (EMH_ICS_error_base + 590)

/** There is no activation method for the graphics builder. */
#define ICS_err_graphics_builder_no_activation_method           (EMH_ICS_error_base + 591)

/** The mutex is locked. */
#define ICS_err_mutex_locked                                    (EMH_ICS_error_base + 592)

/** The mutex is already locked. */
#define ICS_err_mutex_already_locked                            (EMH_ICS_error_base + 593)

/** The mutex is not locked. */
#define ICS_err_mutex_not_locked                                (EMH_ICS_error_base + 594)

/** Files cannot be created. */
#define ICS_err_cannot_create_files                             (EMH_ICS_error_base + 595)

/** A file could not be created. */
#define ICS_err_could_not_create_file                           (EMH_ICS_error_base + 596)

/** The file could not be opened. */
#define ICS_err_could_not_open_file                             (EMH_ICS_error_base + 597)

/** Timeout. */
#define ICS_err_timeout                                         (EMH_ICS_error_base + 598)

/** There are no more indices. */
#define ICS_err_out_of_tls_indexes                              (EMH_ICS_error_base + 599)

/** The thread local value could not be set. */
#define ICS_err_could_not_set_tls_value                         (EMH_ICS_error_base + 600)

/** The mapping does not match the template. */
#define ICS_err_mapping_does_not_match_template                 (EMH_ICS_error_base + 601)

/** There is more than one template view. */
#define ICS_err_more_than_one_view_for_template                 (EMH_ICS_error_base + 602)

/** The template belongs to a different class. */
#define ICS_err_template_belongs_to_other_class_or_subclass     (EMH_ICS_error_base + 603)

/** The template is already attached to a different class. */
#define ICS_err_template_is_already_attached                    (EMH_ICS_error_base + 604)

/** Internal error: The key LOV definition was not inserted. */
#define ICS_err_internal_keylov_definition_not_inserted         (EMH_ICS_error_base + 605)

/** The Key LOV key is unknown. */
#define ICS_err_keylov_key_unknown                              (EMH_ICS_error_base + 606)

/** The item id could not be created. */
#define ICS_err_could_not_create_item_id                        (EMH_ICS_error_base + 607)

/** The Classification instance belongs to a part family member. */
#define ICS_err_ico_belongs_to_part_family_member               (EMH_ICS_error_base + 608)

/** The item revision does not contain a part file. */
#define ICS_err_no_partfile_on_item_revision                    (EMH_ICS_error_base + 609)

/** Null object in constructor. */
#define ICS_err_null_ico_in_constructor                         (EMH_ICS_error_base + 610)

/** Array index out of bounds. */
#define ICS_err_array_index_out_of_bounds                       (EMH_ICS_error_base + 611)

/** The attribute is not a Key LOV. */
#define ICS_err_attribute_is_no_keylov                          (EMH_ICS_error_base + 612)

/** The classification instance is not stored in a subclass. */
#define ICS_err_ico_not_stored_in_a_subclass                    (EMH_ICS_error_base + 613)

/* The Item of the selected Revision is already used as a template in the class "%1$" (%2$). */
#define ICS_err_item_of_rev_already_used_as_template            (EMH_ICS_error_base + 614)

/** The Revision "%1$" of selected Item is already used as a template in the class "%2$" (%3$). */
#define ICS_err_rev_of_item_already_used_as_template            (EMH_ICS_error_base + 615)

/** "%1$" is already used as a template in the class "%2$" (%3$). */
#define ICS_err_item_or_rev_already_used_as_template            (EMH_ICS_error_base + 616)

/** Internal error: Trying to insert a stored mapping as a new one. */
#define ICS_err_insert_old_mapping                              (EMH_ICS_error_base + 617)

/** Trying to insert a second mapping for the Item. */
#define ICS_err_insert_second_mapping_for_item                  (EMH_ICS_error_base + 618)

/** Internal error: Classification lock is not initialized. */
#define ICS_err_lock_uninitialized                              (EMH_ICS_error_base + 619)

/** Classification lock was already obtained. */
#define ICS_err_lock_already_obtained                           (EMH_ICS_error_base + 620)

/** Classification lock is loaded. */
#define ICS_err_lockobject_loaded                               (EMH_ICS_error_base + 621)

/** Another user is querying the same data. Please try again later. */
#define ICS_err_lock_in_use                                     (EMH_ICS_error_base + 622)

/** Internal error: try to get a storage mapping with a #NULLTAG storage. */
#define ICS_err_try_to_get_mapping_without_storage              (EMH_ICS_error_base + 623)

/** Internal error: try to get a storage mapping with a wrong storage tag. */
#define ICS_err_wrong_store_object_tag                          (EMH_ICS_error_base + 624)

/** There is no mapping for this item / item revision. */
#define ICS_err_mapping_does_not_exist                          (EMH_ICS_error_base + 625)

/** The given tag neither belongs to an item nor to an item revision. */
#define ICS_err_instance_neither_item_nor_revision              (EMH_ICS_error_base + 626)

/** The mapping cannot be removed because Classification instances have been created. */
#define ICS_err_cannot_remove_pft_with_members                  (EMH_ICS_error_base + 627)

/** The Classification lock is locked for modifying. */
#define ICS_err_lockobject_has_modify_lock                      (EMH_ICS_error_base + 628)

/** The Key LOV key is not unique. */
#define ICS_err_keylov_key_not_unique                           (EMH_ICS_error_base + 629)

/** The Key LOV id is invalid. */
#define ICS_err_invalid_keylov_id                               (EMH_ICS_error_base + 630)

/** The file already exists */
#define ICS_err_file_already_exists                             (EMH_ICS_error_base + 631)

/** The given tag does not belong to a part family template view. */
#define ICS_err_not_a_template_view                             (EMH_ICS_error_base + 632)

/** The classification instance classifies a workspace object that is not related to the part family member. */
#define ICS_err_ico_classifies_wrong_wso_for_pft                (EMH_ICS_error_base + 633)

/** The reference type is invalid */
#define ICS_err_invalid_reference_type                          (EMH_ICS_error_base + 634)

/** You can only classify the part family member part file item revision with the part family member ICO. */
#define ICS_err_try_to_classify_wrong_wso_for_pft               (EMH_ICS_error_base + 635)

/** The class can't be shared, because the parent class isn't shared. */
#define ICS_err_parent_is_not_shared                            (EMH_ICS_error_base + 636)


/*
**  error codes from 637 to 645 are used for ICS_creation_* functions
*/

/** The value for at least one of the ICS_PREFERENCE preferences is invalid. */
#define ICS_err_wso_creation_prefs_invalid           (EMH_ICS_error_base + 637)
/** Either the number check file %1$ does not exist or it has no read access. */
#define ICS_err_wso_creation_checkfile_invalid       (EMH_ICS_error_base + 638)
/** The preference %1$ is not set. */
#define ICS_err_wso_creation_prefs_missing           (EMH_ICS_error_base + 639)
/** The generated Item ID %1$ already exists in the check file. */
#define ICS_err_wso_creation_id_exists               (EMH_ICS_error_base + 640)
/** Either the seed part does not exist or it has no read access. */
#define ICS_err_wso_creation_seedpart_invalid        (EMH_ICS_error_base + 641)
/** The counter %1$ has reached its maximum value. */
#define ICS_err_wso_creation_counter_greater_maxval  (EMH_ICS_error_base + 642)
/** The counter %1$ has reached its limit and cannot count up. */
#define ICS_err_wso_creation_counter_error           (EMH_ICS_error_base + 643)
/** A workspace object of Item/ItemRevision could not be created. */
#define ICS_err_wso_creation_failed                  (EMH_ICS_error_base + 644)


/** PLMXML Module reported error: %1$s */
#define ICS_err_plmxml                                          (EMH_ICS_error_base + 645)

/** The template being used is a remote object. You cannot update the member data in the spreadsheet but only create/update the part file or jt file. */
#define ICS_err_only_write_part_file_or_jt_in_remote_template   (EMH_ICS_error_base + 646)

/** No ICO for attribute mapping. */
#define ICS_err_attr_mapping_ico_does_not_exist      (EMH_ICS_error_base + 647)

/** Error during Classification attribute mapping: %1$s */
#define ICS_err_attr_mapping                         (EMH_ICS_error_base + 648)

/** Error getting ICOs for attribute mapping. */
#define ICS_err_could_not_get_icos_for_attr_mapping  (EMH_ICS_error_base + 649)

/** There aren't any ICOs for attribute mapping. */
#define ICS_err_attr_mapping_no_ico                  (EMH_ICS_error_base + 650)

/** Error setting attribute mapping value. */
#define ICS_err_set_attr_mapping_value               (EMH_ICS_error_base + 651)

/** Attribute not defined in (any of) the ICO(s). */
#define ICS_err_attribute_not_in_ico                 (EMH_ICS_error_base + 652)

/** No attribute value set. */
#define ICS_err_attr_mapping_no_value_set            (EMH_ICS_error_base + 653)

/** There are no entries in the Key LOV. */
#define ICS_err_no_key_lov_entries                   (EMH_ICS_error_base + 654)

/** Error formatting attribute value: */
#define ICS_attr_mapping_value_formatting            (EMH_ICS_error_base + 655)

/** No attribute with the given ID. */
#define ICS_err_no_attr                              (EMH_ICS_error_base + 656)

/** No attribute format set. */
#define ICS_err_no_attr_format                       (EMH_ICS_error_base + 657)

/** Could not find the given string. */
#define ICS_err_string_not_found                     (EMH_ICS_error_base + 658)

/** Could not get TC property for Classification runtime attribute. */
#define ICS_no_tc_property_for_runtime_attr        (EMH_ICS_error_base + 659)

/** Could not create ICO. */
#define ICS_err_attr_mapping_ico_creation            (EMH_ICS_error_base + 660)

/** The number of attribute mapping 'ICS_CREATE([number])' is too big (no ICO number ([number] - 1) exists). */
#define ICS_err_attr_mapping_ico_creation_gaps       (EMH_ICS_error_base + 661)

/** Problem during Classification attribute mapping: %s */
#define ICS_note_attr_mapping                        (EMH_ICS_error_base + 662)

/** To much values for given attribute. */
#define ICS_err_to_much_attribute_values             (EMH_ICS_error_base + 663)

/** The id given to create a new view specifies an existing view. */
#define ICS_err_view_id_not_unique                              (EMH_ICS_error_base + 664)

/** The id given to create a new class specifies an existing class. */
#define ICS_err_class_id_not_unique                             (EMH_ICS_error_base + 665)

/** The class has unreadable children. */
#define ICS_err_unreadable_children                             (EMH_ICS_error_base + 666)

/** The new parent of the class is not writable. */
#define ICS_err_new_parent_not_writable                         (EMH_ICS_error_base + 667)

/** The class has children that are classes. */
#define ICS_has_class_children                                  (EMH_ICS_error_base + 668)

/** There are shared objects in the hierarchy. */
#define ICS_shared_objects                                      (EMH_ICS_error_base + 669)

/** There are part family templates in the hierarchy. */
#define ICS_has_part_family_templates                           (EMH_ICS_error_base + 670)

/** The functionality cannot be used because the views have not been converted to the new format yet. */
#define ICS_err_must_convert_views                              (EMH_ICS_error_base + 671)

/** The id was specified twice. */
#define ICS_err_duplicate_id                                    (EMH_ICS_error_base + 672)

/** In the copy operation a class in the hierarchy was specified to be copied without specifying its parent, too. */
#define ICS_err_parent_not_in_list                              (EMH_ICS_error_base + 673)

/** The class specified to be the new parent is a descendant of the class to copy. */
#define ICS_err_parent_is_descendant                            (EMH_ICS_error_base + 674)

/** The view could not be copied. */
#define ICS_view_could_not_be_copied                            (EMH_ICS_error_base + 675)

/** The object "%1$s" could not be copied.*/
#define ICS_object_could_not_be_copied                          (EMH_ICS_error_base + 676)

/** Problem during the copy/migrate operation: %1$s */
#define ICS_note_copy_or_conversion                             (EMH_ICS_error_base + 677)

/** An object to copy was given twice and the values for the new id are different. */
#define ICS_err_different_value_in_duplicate                    (EMH_ICS_error_base + 678)

/** A class id could not be generated. */
#define ICS_err_cannot_generate_class_id                        (EMH_ICS_error_base + 679)

/** The subclass could not be converted. */
#define ICS_err_subclass_could_not_be_converted                 (EMH_ICS_error_base + 680)

/** The subclass "00" must not be converted. */
#define ICS_err_dont_convert_subclass_00                        (EMH_ICS_error_base + 681)

/** Attribute "%3$s" of the new class "%2$s" is inherited and differs in its properties from the source in "%1$s". */
#define ICS_new_class_has_different_attribute_properties        (EMH_ICS_error_base + 682)

/** The id given does not specify a view. */
#define ICS_err_not_a_view                                      (EMH_ICS_error_base + 683)

/** The object "%1$s" could not be shared. */
#define ICS_err_could_not_share_object                          (EMH_ICS_error_base + 684)

/** An error occurred during the share of the class' views. */
#define ICS_err_share_views_of_class                            (EMH_ICS_error_base + 685)

/** The site specified is unknown. */
#define ICS_err_unknown_site                                    (EMH_ICS_error_base + 686)

/** Error during the share operation. */
#define ICS_err_share                                           (EMH_ICS_error_base + 687)

/** To generate a unique id you must not specify the old Subclass ID but not the old Class ID.  */
#define ICS_err_cannot_create_class_id_using_old_sid_but_no_cid (EMH_ICS_error_base + 688)

/** %1$s does not specify a Classification subclass ID. */
#define ICS_err_not_a_subclass                                  (EMH_ICS_error_base + 689)

/** Not all ICOs could be moved from class %1$s to class %1$s. */
#define ICS_err_not_all_icos_could_be_moved                     (EMH_ICS_error_base + 690)

/** Ico %1$s is no longer a part family member of template %1$s. */
#define ICS_ico_no_longer_pft_member                            (EMH_ICS_error_base + 691)

/** Class %1$s is shared. */
#define ICS_err_class_is_shared                                 (EMH_ICS_error_base + 692)

/** The class/view %1$s could not be moved. */
#define ICS_err_object_could_not_be_moved                       (EMH_ICS_error_base + 693)

/** The group %1$s cannot not be moved/copied under class %1$s. */
#define ICS_err_cant_put_group_under_class                      (EMH_ICS_error_base + 694)

/** Could not remove object %1$s. */
#define ICS_err_could_not_remove_object                         (EMH_ICS_error_base + 695)

/** ICOs cannot be stored in a view. */
#define ICS_err_cannot_store_ico_in_view                        (EMH_ICS_error_base + 696)

/** Error in copy class operation. See syslog file for more information. */
#define ICS_err_in_class_copy_operation                         (EMH_ICS_error_base + 697)

/** Error in move class operation. See syslog file for more information. */
#define ICS_err_in_class_move_operation                         (EMH_ICS_error_base + 698)

/** Error in migrate subclass operation. See syslog file for more information. */
#define ICS_err_in_migrate_subclass_operation                   (EMH_ICS_error_base + 699)


/**
    @name Errors for in-CLASS Xml Import/Export

    Errors from 71700 to 71749 are allocated for this
    @{
*/

/** Xml4c Error */
#define ICSX_XmlParser                                          (EMH_ICS_error_base + 700)

/** Unable to Initialize Xml4c Parser Module */
#define ICSX_ParserInit                                         (EMH_ICS_error_base + 701)

/** Xml4c Parsing Error: %1$s. */
#define ICSX_XmlParsing                                         (EMH_ICS_error_base + 702)

/** Unable to get valid Root Element by Parsing */
#define ICSX_UnbGetDocRoot                                      (EMH_ICS_error_base + 703)

/** Error traversing Xml Data objects */
#define ICSX_XmlDataStorage                                     (EMH_ICS_error_base + 704)

/** Unable to generate Xml Doc */
#define ICSX_UnbGenXmlDoc                                       (EMH_ICS_error_base + 705)

/** Invalid XML Element */
#define ICSX_InvObjXmlElement                                   (EMH_ICS_error_base + 706)

/** Unable to create Xml Element */
#define ICSX_UnbCreateElement                                   (EMH_ICS_error_base + 707)

/** No Data for Xml Element */
#define ICSX_NoXmlData                                          (EMH_ICS_error_base + 708)

/** Unable to get the required Data from Xml Doc */
#define ICSX_UnbGetXmlData                                      (EMH_ICS_error_base + 709)

/** %1$s %2$s already exists. Use the update option to overwrite. */
#define ICSX_IgnUpdate                                          (EMH_ICS_error_base + 710)

/** Unable to Open existing object */
#define ICSX_UnbOpenObj                                         (EMH_ICS_error_base + 711)

/** Unable to Create Object */
#define ICSX_UnbNewObj                                          (EMH_ICS_error_base + 712)

/** Unable to Get Property */
#define ICSX_UnbGetProp                                         (EMH_ICS_error_base + 713)

/** Unable to Set Property */
#define ICSX_UnbSetProp                                         (EMH_ICS_error_base + 714)

/** Unable to Set Properties %1$s.*/
#define ICSX_UnbUpdProp                                         (EMH_ICS_error_base + 715)

/** Unable to Save Object %1$s.*/
#define ICSX_UnbSaveObj                                         (EMH_ICS_error_base + 716)

/** Unable to get ICS object */
#define ICSX_UnbGetObj                                          (EMH_ICS_error_base + 717)

/** Unable to set ICS object */
#define ICSX_UnbSetObj                                          (EMH_ICS_error_base + 718)

/** No object found to Export */
#define ICSX_ExpNoObject                                        (EMH_ICS_error_base + 719)

/** Importing object %1$s %2$s. */
#define ICSX_ImpObject                                          (EMH_ICS_error_base + 720)

/** Exporting object %1$s %2$s. */
#define ICSX_ExpObject                                          (EMH_ICS_error_base + 721)

/** Import Created the object Successfully */
#define ICSX_ImpNewObject                                       (EMH_ICS_error_base + 722)

/** Import Updated the object Successfully */
#define ICSX_ImpUpdObject                                       (EMH_ICS_error_base + 723)

/** Exported the Object Data Successfully */
#define ICSX_ExportedObject                                     (EMH_ICS_error_base + 724)

/** Import Failed */
#define ICSX_ImpFailed                                          (EMH_ICS_error_base + 725)

/** Export Failed */
#define ICSX_ExpFailed                                          (EMH_ICS_error_base + 726)

/** Ignored : Filtered Out Object Type %1$s */
#define ICSX_IgnObjTypeFiltOut                                  (EMH_ICS_error_base + 727)

/** Ignored : Hook Function returns Cancel-Object */
#define ICSX_HookCancelObj                                      (EMH_ICS_error_base + 728)

/** Discontinued : Hook Function returns Cancel-All */
#define ICSX_HookCancelAll                                      (EMH_ICS_error_base + 729)

/** Invalid - Exporting this sub-set is not Supported */
#define ICSX_InvInput                                           (EMH_ICS_error_base + 730)

/** Error while trying to set value to read only meta data for a dictionary attribute during plmxml import */
#define ICS_err_in_set_read_only_meta_data                      (EMH_ICS_error_base + 731)

/** @} */

/**
    @name Errors for in-CLASS GraphicsBuilder

    Errors from 71750 to 71799 are allocated for this
    @{
*/

/** Graphics builder exception */
#define ICS_GB_exception                                        (EMH_ICS_error_base + 750)

/** Graphics builder system exception */
#define ICS_GB_system_exception                                 (EMH_ICS_error_base + 751)

/** Graphics builder user exception */
#define ICS_GB_user_exception                                   (EMH_ICS_error_base + 752)

/** The graphics builder is already initialized. */
#define ICS_GB_already_initialized                              (EMH_ICS_error_base + 753)

/** Unknown graphics builder error */
#define ICS_GB_unknown                                          (EMH_ICS_error_base + 754)

/** Graphics builder file exception */
#define ICS_GB_file_operation                                   (EMH_ICS_error_base + 755)

/** General graphics builder error */
#define ICS_GB_general                                          (EMH_ICS_error_base + 756)

/** Internal graphics builder error */
#define ICS_GB_internal                                         (EMH_ICS_error_base + 757)

/** Graphics builder parameter error */
#define ICS_GB_parameter                                        (EMH_ICS_error_base + 758)

/** Graphics builder mode error */
#define ICS_GB_mode                                             (EMH_ICS_error_base + 759)

/** Graphics builder activation failed. */
#define ICS_GB_activation_failed                                (EMH_ICS_error_base + 760)

/** The classified part file revision object is of the wrong type. The part family member part file revision must always be of the same type as the part family template. */
#define ICS_GB_type_does_not_match                              (EMH_ICS_error_base + 761)

/** The member cannot be created, because the classified object "%1$" contains a value for the Multifield Key "%2$" and the key is not mapped to any Classification attribute. */
#define ICS_GB_missing_mfk_property                             (EMH_ICS_error_base + 762)

/** The installed NX version does not support template parts. Please install NX10.0.3 MP9, NX11.0.1 or higher. */
#define ICS_GB_does_not_support_template_parts                  (EMH_ICS_error_base + 763)

/** Failed to parse the JSON response. */
#define ICS_GB_FAILED_TO_PARSE_JSON                             (EMH_ICS_error_base + 764)

/** Incorrect or empty response received from Graphics Builder. Please check that graphics builder is configured correctly and running. */
#define ICS_GB_INCORRECT_RESPONSE                               (EMH_ICS_error_base + 765)

/** The unit system of the stored mapping is different then the unit system of the template part. Please refresh the unit system information of the mapping. */
#define ICS_GB_unit_system_does_not_match                       (EMH_ICS_error_base + 766)

/** The Classification objects cannot be created for the members of a metric template part in non-metric storage class. */
#define ICS_GB_class_unit_system_is_different_metric            (EMH_ICS_error_base + 767)

/** The Classification objects cannot be created for the members of a non-metric template part in metric storage class. */
#define ICS_GB_class_unit_system_is_different_non_metric        (EMH_ICS_error_base + 768)

/** Cannot load the Manufacturing Resource Library template '%1$.' Install it using MRL Installer->Database Population->Import MRL NX Seed Parts. */
#define ICS_GB_missing_mrl_template_item                        (EMH_ICS_error_base + 769)

/** @} */

/**
    @name Errors for Guided Component Search (GCS)

    Errors from 71800 to 71849 are allocated for this
    @{
*/

/** Can't create GCS CT! This GCS CT name is already in use. */
#define GCS_err_CT_already_exists                               (EMH_ICS_error_base + 800)

/** Given attribute count does not match to the GCS CT attribute count. */
#define GCS_err_CT_wrong_attribute_count                        (EMH_ICS_error_base + 801)

/** No GCS CT found with this name. */
#define GCS_err_no_CT_found                                     (EMH_ICS_error_base + 802)

/** Component classes of GCS CPD and Component do not match! */
#define GCS_err_CPD_component_class_doesnt_match                (EMH_ICS_error_base + 803)

/** Can't create GCS CP! There is already a GCS CP for this ICO/CPD/CPIndex combination! */
#define GCS_err_CP_already_exists                               (EMH_ICS_error_base + 804)

/** No GCS CP found for this ICO/CPD/CPIndex combination. */
#define GCS_err_no_CP_found                                     (EMH_ICS_error_base + 805)

/** There are multiple GCS CPs found for this ICO/CPD/CPIndex combination. */
#define GCS_err_system_is_inconsistent                          (EMH_ICS_error_base + 806)

/** Can't create GCS CPD! There is already a GCS CPD with this CPDIndex for this component class. */
#define GCS_err_CPD_already_exists                              (EMH_ICS_error_base + 807)

/** Shape is not set correctly in GCS CP. */
#define GCS_err_incorrect_shape_setting                         (EMH_ICS_error_base + 808)

/** No GCS CP ICO tag found for occurrence. */
#define GCS_err_no_CP_found_for_occ                             (EMH_ICS_error_base + 809)

/** Multiple GCS CP ICO tags found for occurrence. */
#define GCS_err_multiple_CPs_found_for_occ                      (EMH_ICS_error_base + 810)

/** First substring index out of range of ICO value. */
#define GCS_err_first_substring_index_out_of_range              (EMH_ICS_error_base + 811)

/** Second substring index out of range of ICO value. */
#define GCS_err_second_substring_index_out_of_range             (EMH_ICS_error_base + 812)

/** Replacements cannot be initialized using the class "%1$", because this requires the pre-installed class "MRM_map_replacements". Please check the Teamcenter server syslog file and contact your system administrator. */
#define GCS_err_map_cannot_initialize_replacements              (EMH_ICS_error_base + 813)

/** The source attribute ID "%1$" of the replacement "%2$" is not a valid attribute ID. Valid attribute IDs must be integers, and be defined in the Classification's attribute dictionary. */
#define GCS_err_map_invalid_src_attr_id                         (EMH_ICS_error_base + 814)

/** The target attribute ID "%1$" of the replacement "%2$" is not a valid attribute ID. Valid attribute IDs must be integers, and be defined in the Classification's attribute dictionary. */
#define GCS_err_map_invalid_tgt_attr_id                         (EMH_ICS_error_base + 815)

/** The attribute "%1$" of the replacement "%2$" needs to have two values: an original source attribute value, and a replacement target attribute value. */
#define GCS_err_map_wrong_number_of_replacement_values          (EMH_ICS_error_base + 816)

/** The replacement "%1$" cannot be initialized because of an unexpected error. Please check the Teamcenter server syslog file and contact your system administrator. */
#define GCS_err_map_cannot_initialize_replacement               (EMH_ICS_error_base + 817)


/** The mapped attribute value "%1$", obtained through the mapping "%2$", cannot be stored in the target attribute "%3$" with ID "%4$" and annotation "%5$". */ 
#define GCS_err_cannot_set_target_value                         (EMH_ICS_error_base + 818)

/** The source attribute "%1$" with ID "%2$" and annotation "%3$" cannot be mapped to the specified target attribute. Please check the Teamcenter server syslog file for more information. */
#define GCS_err_source_attribute_value                          (EMH_ICS_error_base + 819)

/** The tool parameter checking has failed with the following error: %1$. Please refer to the Teamcenter server syslog file for more information. */
#define MRM_err_tool_parameter_checking_failed                  (EMH_ICS_error_base + 820)

/** The unzip operation on the Generic Tool Catalog package has failed. Please refer to the Teamcenter server syslog file for more information. */
#define MRM_GTC_err_unzip_gtc_package_failed                    (EMH_ICS_error_base + 821)

/** The classification object could not be created because source and target classes have different unit systems. */
#define ICS_err_attr_mapping_ico_unit_mismatch                  (EMH_ICS_error_base + 850)

/** The Key LOV value is unknown. */
#define ICS_error_keylov_value_unknown                          (EMH_ICS_error_base + 851)

/** The Key LOV entry is not valid. */

#define ICS_error_keylov_entry_not_valid                        (EMH_ICS_error_base + 852)

/** The value entered is not in min max range. */

#define ICS_error_attr_value_lesser_than_min                    (EMH_ICS_error_base + 853)

#define ICS_error_attr_value_greater_than_max                   (EMH_ICS_error_base + 854)


/** The invalid classification attribute property name. */
#define ICS_invalid_classification_property_name                (EMH_ICS_error_base + 855)

/****************Autocompute error*********************************************************/

/** Invalid id */
#define ICS_autocompute_invalidId                               (EMH_ICS_error_base + 856)

/** not an autcompute attribute id */
#define ICS_autocompute_nonautocomputeId                        (EMH_ICS_error_base + 857)

/** Method not registered for the autocompute attribute*/
#define ICS_autocompute_unregistered_method                     (EMH_ICS_error_base + 858)

/** Invalid class */
#define ICS_autocompute_invalidClass                            (EMH_ICS_error_base + 859)

/** Autocompute method is not registered for class attribute*/
#define ICS_autocompute_unregistered_classAttrId                (EMH_ICS_error_base + 860)

/** Autocompute method is not registered for class attribute*/
#define ICS_autocompute_unregistered_viewAttrId                 (EMH_ICS_error_base + 861)

/** Attribute is not an input attribute */
#define ICS_autocompute_nonInput_AttrId                         (EMH_ICS_error_base + 862)

/** cyclic id */
#define ICS_autocompute_cyclicId                                (EMH_ICS_error_base + 863)



/** Localized property cannot be set on class attribute which has ICO'S */
#define ICS_ico_exists                                          (EMH_ICS_error_base + 864)


/** The given VLA position %1$ does not exist. The maximum number of values allowed for this attribute is %2$.*/
#define ICS_err_attr_mapping_vla                               (EMH_ICS_error_base + 865)

/** The transfer privileges are insufficient on the given object. */
#define ICS_insufficient_transfer_access                       (EMH_ICS_error_base + 866)

/** Historical objects are frozen and cannot be classified. Please use the latest working revision of this object instead. */
#define ICS_err_cannot_classify_historical_objects             (EMH_ICS_error_base + 867)

/** The provided Classification Object ID "%1$" is not unique. */
#define ICS_ico_id_not_unique                                  (EMH_ICS_error_base + 868)

/** The provided Classification Object "%1$" has no associated workspace object. */
#define ICS_ico_has_no_associated_wso                          (EMH_ICS_error_base + 869)

/** No setup sheet templates can be found for the class "%1$" nor for any of its ancestors. */
#define ICS_no_setup_sheet_template_found                      (EMH_ICS_error_base + 870)

/** The installed NX version does not support setup sheet creation. Please upgrade NX to a version that supports setup sheet generation. */
#define ICS_unknown_user_function_create_setup_sheet           (EMH_ICS_error_base + 871)

/** @} */

/** Unexpected error. */
#define ICS_err_unexpected_error                                (EMH_ICS_error_base + 998)

/** Internal error. */
#define ICS_err_internal_error                                  (EMH_ICS_error_base + 999)


/** @} */

/**
    @name Errors for icsutility

    Errors from 211000 to 212000 are allocated for this
    @{
*/

/** icsutility error base */
#define ICSUTIL_ERROR_ICSUTILITY_ERROR_BASE                                                 (EMH_ICSUTIL_error_base + 0)

/** Less message codes than messages in message array */
#define ICSUTIL_ERROR_LESS_MESSAGE_CODES_THAN_MESSAGES_IN_MESSAGE_ARRAY                     (EMH_ICSUTIL_error_base + 1)

/** More message codes than messages in message array */
#define ICSUTIL_ERROR_MORE_MESSAGE_CODES_THAN_MESSAGES_IN_MESSAGE_ARRAY                     (EMH_ICSUTIL_error_base + 2)

/** Overwritten by internal error message \"Message text index out of bounds\ */
#define ICSUTIL_ERROR_MESSAGE_INDEX_OUT_OF_MESSAGE_ARRAY_BOUNDS                             (EMH_ICSUTIL_error_base + 3)

/** Unable to copy file */
#define ICSUTIL_ERROR_UNABLE_TO_COPY_FILE                                                   (EMH_ICSUTIL_error_base + 4)

/** Attempt to create duplicate POMObject for Item */
#define ICSUTIL_ERROR_ATTEMPT_TO_CREATE_DUPLICATE_POM_OBJECT_FOR_ITEM                       (EMH_ICSUTIL_error_base + 5)

/** Unknown error text */
#define ICSUTIL_ERROR_UNKNOWN_EXTERNAL_ERROR                                                (EMH_ICSUTIL_error_base + 6)

/** Cannot dump array */
#define ICSUTIL_ERROR_NULL_POINTER_FOR_ARRAY_TO_BE_DUMPED                                   (EMH_ICSUTIL_error_base + 7)

/** Missing mandatory import mode parameter (-mod=&lt;import mode&gt;) */
#define ICSUTIL_ERROR_MISSING_MANDATORY_IMPORT_MODE_OPTION                                  (EMH_ICSUTIL_error_base + 8)

/** Missing mandatory username for login (-u=&lt;username&gt;) */
#define ICSUTIL_ERROR_NO_USER_NAME_FOR_LOGIN                                                (EMH_ICSUTIL_error_base + 9)

/** Missing mandatory password for login (-p=&lt;password&gt;) */
#define ICSUTIL_ERROR_NO_PASSWORD_FOR_LOGIN                                                 (EMH_ICSUTIL_error_base + 10)

/** Missing mandatory groupname for login (-g=&lt;groupname&gt;) */
#define ICSUTIL_ERROR_NO_GROUP_NAME_FOR_LOGIN                                               (EMH_ICSUTIL_error_base + 11)

/** Cannot create named reference without dataset */
#define ICSUTIL_ERROR_NO_DATASET_FOR_NAMED_REFERENCE                                        (EMH_ICSUTIL_error_base + 12)

/** Cannot create named reference without file tag */
#define ICSUTIL_ERROR_NO_FILETAG_FOR_NAMED_REFERENCE                                        (EMH_ICSUTIL_error_base + 13)

/** Cannot create a relation without a relation type */
#define ICSUTIL_ERROR_NO_RELATION_TYPE_FOR_GRM_RELATIONSHIP                                 (EMH_ICSUTIL_error_base + 14)

/** Cannot create a relation without a primary tag */
#define ICSUTIL_ERROR_NO_PRIMARY_TAG_FOR_GRM_RELATIONSHIP                                   (EMH_ICSUTIL_error_base + 15)

/** Cannot create a relation without a secondary tag */
#define ICSUTIL_ERROR_NO_SECONDARY_TAG_FOR_GRM_RELATIONSHIP                                 (EMH_ICSUTIL_error_base + 16)

/** Cannot find requested relation type */
#define ICSUTIL_ERROR_NO_RELATION_TAG_FOR_GRM_RELATIONSHIP                                  (EMH_ICSUTIL_error_base + 17)

/** Failed to create relationship */
#define ICSUTIL_ERROR_NO_TAG_CREATED_FOR_GRM_RELATIONSHIP                                   (EMH_ICSUTIL_error_base + 18)

/** Cannot classify item with classification object having invalid ID */
#define ICSUTIL_ERROR_NO_SML_OBJECT_ID_TO_CLASSIFY_ITEM_WITH                                (EMH_ICSUTIL_error_base + 19)

/** Cannot classify item having invalid item tag */
#define ICSUTIL_ERROR_ITEM_TAG_NULL_FOR_ITEM_TO_CLASSIFY                                    (EMH_ICSUTIL_error_base + 20)

/** Cannot link item and classification object because of invalid classification object ID */
#define ICSUTIL_ERROR_MISSING_ID_FOR_SML_OBJECT_TO_LINK_ITEM_TO                             (EMH_ICSUTIL_error_base + 21)

/** Cannot link item and classification object because of invalid item tag pointer */
#define ICSUTIL_ERROR_ITEM_TAG_POINTER_NULL_FOR_ITEM_TO_LINK_TO_SML_OBJECT                  (EMH_ICSUTIL_error_base + 22)

/** Cannot link item and classification object because the provided item tag is already in use */
#define ICSUTIL_ERROR_ITEM_TAG_FOR_ITEM_TO_LINK_TO_SML_OBJECT_ALREADY_IN_USE                (EMH_ICSUTIL_error_base + 23)

/** Cannot link item and classification object because of invalid item revision tag pointer */
#define ICSUTIL_ERROR_ITEM_REVISION_TAG_POINTER_NULL_FOR_ITEM_TO_LINK_TO_SML_OBJECT         (EMH_ICSUTIL_error_base + 24)

/** Cannot link item and classification object because the provided item revision tag is already in use */
#define ICSUTIL_ERROR_ITEM_REVISION_TAG_FOR_ITEM_TO_LINK_TO_SML_OBJECT_ALREADY_IN_USE       (EMH_ICSUTIL_error_base + 25)

/** Cannot find a classification object having the provided name */
#define ICSUTIL_ERROR_NO_CLASSIFICATION_OBJECT_WITH_THIS_NAME_FOUND                         (EMH_ICSUTIL_error_base + 26)

/** Unable to obtain the tag pointer of the classified item */
#define ICSUTIL_ERROR_NULL_ITEM_TAG_POINTER_RETURNED_FOR_ITEM_LINKED_TO_SML_OBJECT          (EMH_ICSUTIL_error_base + 27)

/** Unable to obtain the tag pointer of the item to be classified */
#define ICSUTIL_ERROR_NULL_ITEM_TAG_POINTER_RETURNED_FOR_ITEM_TO_LINK_TO_SML_OBJECT         (EMH_ICSUTIL_error_base + 28)

/** Failed to create item to be classified */
#define ICSUTIL_ERROR__NO_ITEM_TAG_CREATED_FOR_ITEM_TO_LINK_TO_SML_OBJECT                   (EMH_ICSUTIL_error_base + 29)

/** Cannot create item for classification object having invalid ID */
#define ICSUTIL_ERROR_MISSING_ID_FOR_SML_OBJECT_TO_CREATE_ITEM_FOR                          (EMH_ICSUTIL_error_base + 30)

/** Cannot create item for classification object because of invalid item tag pointer */
#define ICSUTIL_ERROR_ITEM_TAG_POINTER_NULL_FOR_ITEM_TO_CREATE_FOR_SML_OBJECT               (EMH_ICSUTIL_error_base + 31)

/** Cannot create item for classification object because of invalid item revision tag pointer */
#define ICSUTIL_ERROR_ITEM_REVISION_TAG_POINTER_NULL_FOR_ITEM_TO_CREATE_FOR_SML_OBJECT      (EMH_ICSUTIL_error_base + 32)

/** Cannot create item for classification object because the provided item tag is already in use */
#define ICSUTIL_ERROR_ITEM_TAG_FOR_ITEM_TO_CREATE_FOR_SML_OBJECT_ALREADY_IN_USE             (EMH_ICSUTIL_error_base + 33)

/** Cannot create item for classification object because the provided item revision tag is already in use */
#define ICSUTIL_ERROR_ITEM_REVISION_TAG_FOR_ITEM_TO_CREATE_FOR_SML_OBJECT_ALREADY_IN_USE    (EMH_ICSUTIL_error_base + 34)

/** Obtained invalid item tag pointer while creating item for classification object */
#define ICSUTIL_ERROR_NULL_ITEM_TAG_POINTER_RETURNED_FOR_ITEM_TO_CREATE_FOR_SML_OBJECT      (EMH_ICSUTIL_error_base + 35)

/** Obtained invalid item tag while creating item for classification object */
#define ICSUTIL_ERROR_NO_ITEM_TAG_CREATED_FOR_ITEM_TO_CREATE_FOR_SML_OBJECT                 (EMH_ICSUTIL_error_base + 36)

/** Cannot find item for classification object having invalid ID */
#define ICSUTIL_ERROR_MISSING_ID_FOR_SML_OBJECT_TO_FIND_ITEM_FOR                            (EMH_ICSUTIL_error_base + 37)

/** Cannot find item for classification object because of invalid item tag pointer */
#define ICSUTIL_ERROR_ITEM_TAG_POINTER_NULL_FOR_ITEM_TO_FIND_FOR_SML_OBJECT                 (EMH_ICSUTIL_error_base + 38)

/** Cannot find item for classification object because of invalid item revision tag pointer */
#define ICSUTIL_ERROR_ITEM_REVISION_TAG_POINTER_NULL_FOR_ITEM_TO_FIND_FOR_SML_OBJECT        (EMH_ICSUTIL_error_base + 39)

/** Cannot find item for classification object because the provided item tag is already in use */
#define ICSUTIL_ERROR_ITEM_TAG_FOR_ITEM_TO_FIND_FOR_SML_OBJECT_ALREADY_IN_USE               (EMH_ICSUTIL_error_base + 40)

/** Cannot find item for classification object because the provided item revision tag is already in use */
#define ICSUTIL_ERROR_ITEM_REVISION_TAG_FOR_ITEM_TO_FIND_FOR_SML_OBJECT_ALREADY_IN_USE      (EMH_ICSUTIL_error_base + 41)

/** Obtained invalid item revision tag pointer for item found for classification object */
#define ICSUTIL_ERROR_NULL_ITEM_REVISION_TAG_POINTER_RETURNED_FOR_ITEM_FOUND_FOR_SML_OBJECT (EMH_ICSUTIL_error_base + 42)

/** Cannot link item and dataset because of invalid item revision tag */
#define ICSUTIL_ERROR_NULLTAG_PASSED_FOR_ITEM_REVISION_TO_LINK_TO_DATASET                   (EMH_ICSUTIL_error_base + 43)

/** Cannot link item and dataset because of invalid dataset tag */
#define ICSUTIL_ERROR_NULLTAG_PASSED_FOR_DATASET_TO_LINK_TO_ITEM_REVISION                   (EMH_ICSUTIL_error_base + 44)

/** Cannot obtain file lookup table index because of invalid file extension */
#define ICSUTIL_ERROR_NO_FILE_EXTENSION_TO_LOOK_UP_INDEX_OF                                 (EMH_ICSUTIL_error_base + 45)

/** Cannot obtain file lookup table index because of invalid file lookup table index pointer */
#define ICSUTIL_ERROR_NO_POINTER_TO_RETURN_LOOK_UP_INDEX_WITH                               (EMH_ICSUTIL_error_base + 46)

/** The requested file type has not been configured.  Please check file type configuration file filetypeDefaults.txt. */
#define ICSUTIL_ERROR_UNSUPPORTED_FILE_TYPE_SEARCHED                                        (EMH_ICSUTIL_error_base + 47)

/** Cannot save and unlock object because of invalid object tag */
#define ICSUTIL_ERROR_NO_TAG_FOR_OBJECT_TO_SAVE_AND_UNLOCK                                  (EMH_ICSUTIL_error_base + 48)

/** Cannot delete object because of invalid object tag */
#define ICSUTIL_ERROR_NO_TAG_FOR_OBJECT_TO_DELETE                                           (EMH_ICSUTIL_error_base + 49)

/** Cannot find dataset for item revision because of invalid item revision tag */
#define ICSUTIL_ERROR_MISSING_ITEM_REVISION_TAG_TO_FIND_DATASET_FOR                         (EMH_ICSUTIL_error_base + 50)

/** Cannot find dataset for item revision because of invalid relation type name */
#define ICSUTIL_ERROR_MISSING_RELATION_TYPE_NAME_TO_FIND_DATASET_FOR                        (EMH_ICSUTIL_error_base + 51)

/** Cannot find dataset for classification object having invalid ID */
#define ICSUTIL_ERROR_MISSING_ID_OF_SML_OBJECT_TO_FIND_DATASET_FOR                          (EMH_ICSUTIL_error_base + 52)

/** Cannot find dataset for classification object because of invalid dataset type name */
#define ICSUTIL_ERROR_MISSING_DATASET_TYPE_NAME_TO_FIND_DATASET_FOR                         (EMH_ICSUTIL_error_base + 53)

/** Cannot find dataset for classification object because of invalid dataset tag pointer */
#define ICSUTIL_ERROR_NULL_DATASET_TAG_POINTER_TO_RETURN_DATASET_FOR_OBJECT                 (EMH_ICSUTIL_error_base + 54)

/** Cannot find dataset for classification object because the provided dataset tag pointer is already in use */
#define ICSUTIL_ERROR_TAG_POINTER_FOR_DATASET_TO_BE_FOUND_ALREADY_IN_USE                    (EMH_ICSUTIL_error_base + 55)

/** Cannot create dataset for classification object having invalid ID */
#define ICSUTIL_ERROR_MISSING_ID_OF_SML_OBJECT_TO_CREATE_DATASET_FOR                        (EMH_ICSUTIL_error_base + 56)

/** Cannot create dataset for classification object because of invalid dataset type name */
#define ICSUTIL_ERROR_MISSING_DATASET_TYPE_NAME_TO_CREATE_DATASET_FOR                       (EMH_ICSUTIL_error_base + 57)

/** Cannot create dataset for classification object because of invalid dataset tag pointer */
#define ICSUTIL_ERROR_NULL_DATASET_TAG_POINTER_FOR_DATASET_TO_BE_CREATED_FOR_OBJECT         (EMH_ICSUTIL_error_base + 58)

/** Cannot create dataset for classification object because the provided dataset tag pointer is already in use */
#define ICSUTIL_ERROR_TAG_POINTER_FOR_DATASET_TO_BE_CREATED_ALREADY_IN_USE                  (EMH_ICSUTIL_error_base + 59)

/** Cannot create dataset for classification object because of invalid filetype name pointer */
#define ICSUTIL_ERROR_NULL_FILETYPE_NAME_POINTER_FOR_DATASET_TO_BE_CREATED_FOR_OBJECT       (EMH_ICSUTIL_error_base + 60)

/** Cannot obtain dataset for item revision because of invalid item revision tag */
#define ICSUTIL_ERROR_MISSING_TAG_OF_ITEM_REVISION_TO_PROVIDE_DATASET_FOR                   (EMH_ICSUTIL_error_base + 61)

/** Cannot obtain dataset for classification object having invalid ID */
#define ICSUTIL_ERROR_MISSING_ID_OF_SML_OBJECT_TO_PROVIDE_DATASET_FOR                       (EMH_ICSUTIL_error_base + 62)

/** Cannot obtain dataset for classification object because of invalid dataset tag pointer */
#define ICSUTIL_ERROR_NULL_DATASET_TAG_POINTER_TO_RETURN_DATASET_FOR_FILE_TYPE              (EMH_ICSUTIL_error_base + 63)

/** Cannot obtain dataset for classification object because the provided dataset tag pointer is already in use */
#define ICSUTIL_ERROR_TAG_POINTER_FOR_DATASET_ALREADY_IN_USE                                (EMH_ICSUTIL_error_base + 64)

/** Obtained invalid dataset tag while creating dataset */
#define ICSUTIL_ERROR_NO_TAG_CREATED_FOR_DATASET                                            (EMH_ICSUTIL_error_base + 65)

/** Cannot concatenate file specification because the path parameter is missing */
#define ICSUTIL_ERROR_NO_PATH_TO_CONCATENATE_FILE_SPECIFICATION                             (EMH_ICSUTIL_error_base + 66)

/** Cannot concatenate file specification because the file name parameter is missing */
#define ICSUTIL_ERROR_NO_FILE_NAME_TO_CONCATENATE_FILE_SPECIFICATION                        (EMH_ICSUTIL_error_base + 67)

/** Cannot concatenate file specification because the file extension parameter is missing */
#define ICSUTIL_ERROR_NO_EXTENSION_TO_CONCATENATE_FILE_SPECIFICATION                        (EMH_ICSUTIL_error_base + 68)

/** Invalid import file name */
#define ICSUTIL_ERROR_NO_FILE_NAME_FOR_IMPORT_FILE                                          (EMH_ICSUTIL_error_base + 69)

/** Invalid import file tag pointer */
#define ICSUTIL_ERROR_NULL_FILE_TAG_POINTER_FOR_IMPORT_FILE                                 (EMH_ICSUTIL_error_base + 70)

/** File tag pointer for import file is already in use */
#define ICSUTIL_ERROR_FILE_TAG_FOR_IMPORT_FILE_ALREADY_IN_USE                               (EMH_ICSUTIL_error_base + 71)

/** Cannot add import file as named reference to dataset because of invalid dataset name */
#define ICSUTIL_ERROR_NO_NAME_FOR_DATASET_TO_ADD_FILE_TO                                    (EMH_ICSUTIL_error_base + 72)

/** Cannot add import file as named reference to dataset because of invalid dataset tag */
#define ICSUTIL_ERROR_NO_TAG_FOR_DATASET_TO_ADD_FILE_TO                                     (EMH_ICSUTIL_error_base + 73)

/** Cannot add import file as named reference to dataset because of invalid file path */
#define ICSUTIL_ERROR_NO_PATH_FOR_FILE_TO_ADD_TO_DATASET                                    (EMH_ICSUTIL_error_base + 74)

/** Cannot add import file as named reference to dataset because of invalid file extension */
#define ICSUTIL_ERROR_NO_EXTENSION_FOR_FILE_TO_ADD_TO_DATASET                               (EMH_ICSUTIL_error_base + 75)

/** Cannot add import file as named reference to dataset because of invalid file tag pointer */
#define ICSUTIL_ERROR_NULL_FILE_TAG_POINTER_FOR_FILE_TO_ADD_TO_DATASET                      (EMH_ICSUTIL_error_base + 76)

/** Cannot add import file as named reference to dataset because the provided file tag pointer is already in use */
#define ICSUTIL_ERROR_FILE_TAG_FOR_FILE_TO_ADD_TO_DATASET_ALREADY_IN_USE                    (EMH_ICSUTIL_error_base + 77)

/** Generated internal file name for import file is invalid */
#define ICSUTIL_ERROR_NO_NAME_GENERATED_FOR_IMPORT_FILE                                     (EMH_ICSUTIL_error_base + 78)

/** Cannot find import file */
#define ICSUTIL_ERROR_IMPORT_FILE_NOT_FOUND                                                 (EMH_ICSUTIL_error_base + 79)

/** File import returned invalid file tag */
#define ICSUTIL_ERROR_NO_FILE_TAG_RETURNED_BY_FILE_IMPORT                                   (EMH_ICSUTIL_error_base + 80)

/** Received invalid pointer to logical when supposed to find import file */
#define ICSUTIL_ERROR_NULL_POINTER_TO_LOGICAL                                               (EMH_ICSUTIL_error_base + 81)

/** Cannot import files for classification object having invalid ID */
#define ICSUTIL_ERROR_NO_ID_OF_SML_OBJECT_TO_ADD_FILES_TO                                   (EMH_ICSUTIL_error_base + 82)

/** Cannot import files for classification object because of invalid file paths */
#define ICSUTIL_ERROR_NO_PATHS_FOR_FILES_TO_ADD_TO_SML_OBJECT                               (EMH_ICSUTIL_error_base + 83)

/** Cannot import files for classification object because of invalid file extensions */
#define ICSUTIL_ERROR_NO_EXTENSIONS_FOR_FILES_TO_ADD_TO_SML_OBJECT                          (EMH_ICSUTIL_error_base + 84)

/** Cannot obtain length of string array because of invalid string array pointer */
#define ICSUTIL_ERROR_STRING_ARRAY_POINTER_NULL                                             (EMH_ICSUTIL_error_base + 85)

/** Cannot obtain number of delimited substrings because of invalid delimited string */
#define ICSUTIL_ERROR_NO_DELIMITED_STRING_TO_COUNT_SUBSTRINGS_OF                            (EMH_ICSUTIL_error_base + 86)

/** Cannot obtain number of delimited substrings because of invalid delimiter */
#define ICSUTIL_ERROR_NO_DELIMITER_FOR_DELIMITED_STRING                                     (EMH_ICSUTIL_error_base + 87)

/** Cannot convert delimited string to string array because of invalid delimited string */
#define ICSUTIL_ERROR_NO_DELIMITED_STRING_TO_CONVERT_TO_ARRAY                               (EMH_ICSUTIL_error_base + 88)

/** Cannot append invalid string to string array */
#define ICSUTIL_ERROR_NO_STRING_TO_APPEND_TO_ARRAY                                          (EMH_ICSUTIL_error_base + 89)

/** Cannot append string to invalid string array */
#define ICSUTIL_ERROR_NO_ARRAY_TO_APPEND_STRING_TO                                          (EMH_ICSUTIL_error_base + 90)

/** Received invalid pointer to logical when supposed to search string in string array */
#define ICSUTIL_ERROR_NO_LOGICAL_POINTER                                                    (EMH_ICSUTIL_error_base + 91)

/** Received invalid pointer to string array when supposed to free string array */
#define ICSUTIL_ERROR_NULL_POINTER_FOR_STRING_ARRAY_TO_FREE                                 (EMH_ICSUTIL_error_base + 92)

/** Received empty string array when supposed to free string array */
#define ICSUTIL_ERROR_NO_STRINGS_IN_STRING_ARRAY_TO_BE_FREED                                (EMH_ICSUTIL_error_base + 93)

/** Imported assembly BOM line contains invalid component quantity */
#define ICSUTIL_ERROR_ILLEGAL_COMPONENT_QUANTITY                                            (EMH_ICSUTIL_error_base + 94)

/** Top-level index of component access path in imported assembly BOM line is outside the range of top-level components */
#define ICSUTIL_ERROR_TOP_LEVEL_COMPONENT_INDEX_OUT_OF_BOUNDS                               (EMH_ICSUTIL_error_base + 95)

/** Imported assembly BOM line contains invalid intermediate index in component access path */
#define ICSUTIL_ERROR_INTERMEDIATES_INDEX_OUT_OF_BOUNDS                                     (EMH_ICSUTIL_error_base + 96)

/** Cannot obtain BOM handle because of invalid item or item revision tag */
#define ICSUTIL_ERROR_NO_TAG_FOR_ITEM_TO_PROVIDE_VIEW_FOR                                   (EMH_ICSUTIL_error_base + 97)

/** Cannot obtain BOM handle because of invalid view type tag */
#define ICSUTIL_ERROR_NO_TAG_FOR_VIEWTYPE_TO_PROVIDE_VIEW_FOR                               (EMH_ICSUTIL_error_base + 98)

/** Cannot obtain BOM handle because of invalid BOM handle pointer */
#define ICSUTIL_ERROR_NULL_POINTER_FOR_BOM_HANDLE_TO_INITIALIZE                             (EMH_ICSUTIL_error_base + 99)

/** Cannot remove trailing level from component access path because trailing level does not exist */
#define ICSUTIL_ERROR_NO_TRAILING_LEVEL_IN_ACCESS_PATH                                      (EMH_ICSUTIL_error_base + 100)

/** The component access path of the imported assembly BOM line is invalid */
#define ICSUTIL_ERROR_INVALID_COMPONENT_ACCESS_PATH                                         (EMH_ICSUTIL_error_base + 101)

/** Top-level index of component access path in imported assembly BOM line is not a valid integer */
#define ICSUTIL_ERROR_INVALID_TOP_LEVEL_COMPONENT_INDEX                                     (EMH_ICSUTIL_error_base + 102)

/** Intermediate index of component access path in imported assembly BOM line is not a valid integer */
#define ICSUTIL_ERROR_INVALID_COMPONENT_INDEX_IN_ACCESS_PATH                                (EMH_ICSUTIL_error_base + 103)

/** Intermediate index of component access path in imported assembly BOM line is outside the range of successor components */
#define ICSUTIL_ERROR_COMPONENT_INDEX_IN_ACCESS_PATH_OUT_OF_BOUNDS                          (EMH_ICSUTIL_error_base + 104)

/** Cannot find classification object having invalid ID */
#define ICSUTIL_ERROR_NO_NAME_FOR_ICO_TO_BE_FOUND                                           (EMH_ICSUTIL_error_base + 105)

/** Cannot find classification object to be updated */
#define ICSUTIL_ERROR_NO_ICO_FOUND_TO_BE_UPDATED                                            (EMH_ICSUTIL_error_base + 106)

/** Cannot open file type configuration file filetypeDefaults.txt */
#define ICSUTIL_ERROR_CANNOT_OPEN_CONFIGURATION_FILE                                        (EMH_ICSUTIL_error_base + 107)

/** Cannot get new classification object ID because of invalid item or item revision tag */
#define ICSUTIL_ERROR_NULL_TAG_FOR_ITEM_OR_ITEM_REV                                         (EMH_ICSUTIL_error_base + 108)

/** Cannot get relation because of invalid relation tag pointer */
#define ICSUTIL_ERROR_RELATION_TAG_POINTER_FOR_GRM_RELATIONSHIP_NULL                        (EMH_ICSUTIL_error_base + 109)

/** Cannot get relation because the provided relation tag is already in use */
#define ICSUTIL_ERROR_RELATION_TAG_FOR_GRM_RELATIONSHIP_ALREADY_IN_USE                      (EMH_ICSUTIL_error_base + 110)

/** Cannot create connection item for connection point because of invalid connection point tag */
#define ICSUTIL_ERROR_NULLTAG_PASSED_FOR_CONNECTION_POINT                                   (EMH_ICSUTIL_error_base + 111)

/** Cannot find component classification object associated to the provided connection point classification object */
#define ICSUTIL_ERROR_NO_COMPONENT_FOR_CONNECTION_POINT                                     (EMH_ICSUTIL_error_base + 112)

/** Cannot get secondary of relation because of invalid secondary tag pointer */
#define ICSUTIL_ERROR_SECONDARY_TAG_POINTER_FOR_GRM_RELATIONSHIP_NULL                       (EMH_ICSUTIL_error_base + 113)

/** Cannot get secondary of relation because the provided secondary tag is already in use */
#define ICSUTIL_ERROR_SECONDARY_TAG_FOR_GRM_RELATIONSHIP_ALREADY_IN_USE                     (EMH_ICSUTIL_error_base + 114)

/** Cannot obtain an item revision that is associated to the component classification object */
#define ICSUTIL_ERROR_NO_ITEM_REVISION_FOUND_FOR_COMPONENT                                  (EMH_ICSUTIL_error_base + 115)

/** icsutility current end of error range */
#define ICSUTIL_ERROR_ICSUTILITY_ERROR_END                                                  (EMH_ICSUTIL_error_base + 116)

/** @} */

#endif
