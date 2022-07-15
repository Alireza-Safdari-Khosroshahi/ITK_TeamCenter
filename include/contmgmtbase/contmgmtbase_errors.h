/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2008.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    Content Management Base errors

*/

#ifndef CONTMGMTBASE_ERRORS_H
#define CONTMGMTBASE_ERRORS_H

#include <common/emh_const.h>
#include <common/tc_deprecation_macros.h>

#include <contmgmtbase/libcontmgmtbase_exports.h>

/**
    @defgroup CONTMGMTBASE_ERRORS CONTMGMTBASE Errors
    @ingroup CONTMGMTBASE
    @{
*/

#define CONTMGMTBASE_ERROR_BASE                              EMH_CONTMGMTBASE_error_base

/**
    An error has occurred in the Content Management Base module.
*/
#define CONTMGMTBASE_GENERAL_ERROR                           (CONTMGMTBASE_ERROR_BASE + 0)

/**
    The Item "%1$" cannot be unfrozen.
*/
#define CONTMGMTBASE_cant_unfreeze                           (CONTMGMTBASE_ERROR_BASE + 1)

/**
    The valid topic types that can be added to topic "%1$" are: "%2$".
*/
#define CONTMGMTBASE_invalid_paste_topic_type                (CONTMGMTBASE_ERROR_BASE + 2)

/**
    The XML procedure "%1$" cannot be used with the selected function "%2$".
*/
#define CONTMGMTBASE_cannot_use_function_type_with_procdure  (CONTMGMTBASE_ERROR_BASE + 3)

/**
    The number of graphic options found (%1$) is greater than the maximum allowed (%2$)
*/
#define CONTMGMTBASE_exceeds_grphPrioMaxOptions              (CONTMGMTBASE_ERROR_BASE + 4)

/**
    The name "%1$" already exists. It must be unique.
*/
#define CONTMGMTBASE_object_name_uniqueness                  (CONTMGMTBASE_ERROR_BASE + 5)

/**
    The procedure failed to get DOM Implementation object. Please request help from a Content Management administrator.
*/
#define CONTMGMTBASE_DOMImplementation_error                 (CONTMGMTBASE_ERROR_BASE + 6)

/**
    The following DOM Exception was caught: %1$.
*/
#define CONTMGMTBASE_DOM_error                               (CONTMGMTBASE_ERROR_BASE + 7)

/**
    The Xalan transformer has failed to execute the procedure.
*/
#define CONTMGMTBASE_transform_error                         (CONTMGMTBASE_ERROR_BASE + 8)

/**
    The preference "%1$" does not exist.
*/
#define CONTMGMTBASE_preference_not_found                    (CONTMGMTBASE_ERROR_BASE + 9)

/**
    The graphic attribute mapping procedure has failed to convert the file name. Please request help from a content management administrator.
*/
#define CONTMGMTBASE_graphic_attr_mapping_error              (CONTMGMTBASE_ERROR_BASE + 10)

/**
    The parameter "%1$" should be proceeded by a &apos;-&apos; sign.
*/
#define CONTMGMTBASE_missing_param_specifier                 (CONTMGMTBASE_ERROR_BASE + 11)

/**
    System Administrator access is required to run this utility.
*/
#define CONTMGMTBASE_sysadmin_access_required                (CONTMGMTBASE_ERROR_BASE + 12)

/**
    There are %1$ instances and %2$ classes referencing an instance of class "%3$".
*/
#define CONTMGMTBASE_instances_and_references_exist          (CONTMGMTBASE_ERROR_BASE + 13)

/**
    The decompose process has failed to cache the topic types correctly.
*/
#define CONTMGMTBASE_topic_type_caching_error                (CONTMGMTBASE_ERROR_BASE + 14)

/**
    The decompose process has failed to parse the topic type condition correctly.
*/
#define CONTMGMTBASE_topic_type_condition_parsing_error      (CONTMGMTBASE_ERROR_BASE + 15)

/**
    The topic "%1$" cannot be found.
*/
#define CONTMGMTBASE_find_topic_error                        (CONTMGMTBASE_ERROR_BASE + 16)

/**
    The topic type "%1$" cannot be found.
*/
#define CONTMGMTBASE_find_topic_type_error                   (CONTMGMTBASE_ERROR_BASE + 17)

/**
    The dataset "%1$" cannot be found.
*/
#define CONTMGMTBASE_find_dataset_error                      (CONTMGMTBASE_ERROR_BASE + 18)

/**
    The file "%1$" cannot be found.
*/
#define CONTMGMTBASE_file_not_found_error                    (CONTMGMTBASE_ERROR_BASE + 19)

/**
    The decompose process has failed to create the topic "%1$".
*/
#define CONTMGMTBASE_create_topic_error                      (CONTMGMTBASE_ERROR_BASE + 20)

/**
    The decompose process has failed to update the topic "%1$".
*/
#define CONTMGMTBASE_update_topic_error                      (CONTMGMTBASE_ERROR_BASE + 21)

/**
    The file name or path "%1$" could not be resolved to a valid file.
*/
#define CONTMGMTBASE_file_path_error                         (CONTMGMTBASE_ERROR_BASE + 22)

/**
    An XML exception was detected.
*/
#define CONTMGMTBASE_XML_Exception                           (CONTMGMTBASE_ERROR_BASE + 23)

/**
    An exception was detected while converting XML to SGML. Please request help from a Content Management administrator.
*/
#define CONTMGMTBASE_Xml_to_sgml_exception                   (CONTMGMTBASE_ERROR_BASE + 24)

/**
    The procedure has failed to convert the XML to SGML. Please request help from a Content Management administrator.
*/
#define CONTMGMTBASE_Xml_to_sgml_error_converting            (CONTMGMTBASE_ERROR_BASE + 25)

/**
    The procedure has failed to initialize the XML to SGML parser. Please request help from a Content Management administrator.
*/
#define CONTMGMTBASE_Xml_to_sgml_xml_init_error              (CONTMGMTBASE_ERROR_BASE + 26)

/**
    The PLMXML Import has failed to create the object "%1$". Please request help from a Content Management administrator.
*/
#define CONTMGMTBASE_unable_create_obj                       (CONTMGMTBASE_ERROR_BASE + 27)

/**
    There are no graphic usages defined for the object "%1$". Please add one or more graphic file types to the "ctm0GraphicUsagePref" preference and then try again.
*/
#define CONTMGMTBASE_NotDefGraphicUsage_error                (CONTMGMTBASE_ERROR_BASE + 28)

/**
    The SGML parser has failed to execute. Please request help from a Content Management administrator.
*/
#define CONTMGMTBASE_SGMLParser_error                        (CONTMGMTBASE_ERROR_BASE + 29)

/**
    The SGML Parser is supported only on Windows and Linux64 platforms.
*/
#define CONTMGMTBASE_SGMLParser_not_supported                (CONTMGMTBASE_ERROR_BASE + 30)

/**
    XML attribute mapping was not found.
*/
#define CONTMGMTBASE_XMLAttrMap_not_found                    (CONTMGMTBASE_ERROR_BASE + 31)

/**
    The provided Item Revision is null.
*/
#define CONTMGMTBASE_ItemRev_is_null                         (CONTMGMTBASE_ERROR_BASE + 32)

/**
    The provided topic type is null.
*/
#define CONTMGMTBASE_TopicType_is_null                       (CONTMGMTBASE_ERROR_BASE + 33)

/**
    The SGML file "%1$" does not contain a schema file declaration. Please add a schema declaration and resubmit the SGML file.
*/
#define CONTMGMTBASE_SGML_schema_not_found                   (CONTMGMTBASE_ERROR_BASE + 34)

/**
    The graphic object "%1$" could not be found during the decomposition. Please check the graphic option used and the graphic import mode.
*/
#define CONTMGMTBASE_failed_to_find_graphic                  (CONTMGMTBASE_ERROR_BASE + 35)

/**
    The modified topic "%1$" is not checked-out. Please check-out this topic and start the decomposition process again.
*/
#define CONTMGMTBASE_TopicNotCheckedOut                      (CONTMGMTBASE_ERROR_BASE + 36)

/**
    The public ID (as specified in the DTD) could not be extracted from the SGML file "%1$".
*/
#define CONTMGMTBASE_FailToGetPublicIdFromSGML               (CONTMGMTBASE_ERROR_BASE + 37)

/**
    More than one topic type is associated with the schema "%1$".
*/
#define CONTMGMTBASE_MoreThanOneTopicTypeWithSchema          (CONTMGMTBASE_ERROR_BASE + 38)

/**
    The original composed XML file for the topic "%1$" cannot be found.
*/
#define CONTMGMTBASE_EditErrorNoOrginalFile                  (CONTMGMTBASE_ERROR_BASE + 39)

/**
    A translation object for the topic "%1$" cannot be found.
*/
#define CONTMGMTBASE_UnableToFindTranslationObject           (CONTMGMTBASE_ERROR_BASE + 40)

/**
   No language with language code "%1$" and country code "%2$" can be found.
*/
#define CONTMGMTBASE_UnableToFindLanguageObject              (CONTMGMTBASE_ERROR_BASE + 41)

/**
    The graphic mode "%1$" sent to the "Import" operation is not valid.
*/
#define CONTMGMTBASE_GraphicModeError                        (CONTMGMTBASE_ERROR_BASE + 42)

/**
    No graphic attribute mapping object with the name "%1$" can be found.
*/
#define CONTMGMTBASE_GraphicAttributMappingError             (CONTMGMTBASE_ERROR_BASE + 43)

/**
    The schema entity "%1$" cannot be resolved.
*/
#define CONTMGMTBASE_UnableToResolveSchemaEntity             (CONTMGMTBASE_ERROR_BASE + 44)

/**
    The schema "%1$" does not contain a dataset.
*/
#define CONTMGMTBASE_SchemaHasNoDataset                      (CONTMGMTBASE_ERROR_BASE + 45)

/**
    The overwrite mode "Keep" cannot be used for the graphic "%1$", because the graphic is not found. Please check the graphic name.
*/
#define CONTMGMTBASE_CanNotUseOverKEEP_error                 (CONTMGMTBASE_ERROR_BASE + 46)

/**
    The overwrite mode "Merge" cannot be used for the graphic "%1$", because either the graphic or the usage are not found. Please check the graphic name and the graphic usage.
*/
#define CONTMGMTBASE_CanNotUseOverMERGE_error                (CONTMGMTBASE_ERROR_BASE + 47)

/**
    The overwrite mode "Overwrite" cannot be used for graphic "%1$", because the graphic is not found. Please check the graphic name.
*/
#define CONTMGMTBASE_CanNotUseOverOVERWRITE_error            (CONTMGMTBASE_ERROR_BASE + 48)

/**
    The public ID "%1$" already exists.
*/
#define CONTMGMTBASE_Duplicated_publicId_error               (CONTMGMTBASE_ERROR_BASE + 49)

/**
    The system ID "%1$" already exists.
*/
#define CONTMGMTBASE_Duplicated_systemId_error               (CONTMGMTBASE_ERROR_BASE + 50)

/**
    The image "%1$" cannot be found.
*/
#define CONTMGMTBASE_WarningImageNotFound                    (CONTMGMTBASE_ERROR_BASE + 51)

/**
    The Item ID "%1$" used in the imported document is already in use by another object that is not of type Topic. Please change the Item ID in the imported document, or turn off the option to reuse existing Topics while importing.
*/
#define CONTMGMTBASE_ItemIdIsAlreadyUsed                     (CONTMGMTBASE_ERROR_BASE + 52)

/**
    The publishing cannot proceed because no stylesheet can be found. Please contact your administrator.
*/
#define CONTMGMTBASE_PublishStylesheetNotFound               (CONTMGMTBASE_ERROR_BASE + 53)

/**
    The publishing cannot proceed because multiple stylesheets are found. Please contact your administrator.
*/
#define CONTMGMTBASE_PublishMultipleStylesheetFound          (CONTMGMTBASE_ERROR_BASE + 54)

/**
    The topic type in the XML file "%1$" cannot be found.
*/
#define CONTMGMTBASE_TopicTypeNotFound                       (CONTMGMTBASE_ERROR_BASE + 55)

/**
    The compose process has failed to find a correct graphic option related to the graphic "%1$". Please verify that the graphic option exists with the usage(s) "%2$" and the language(s) "%3$".
*/
#define CONTMGMTBASE_GraphicOptionNotFound                   (CONTMGMTBASE_ERROR_BASE + 56)

/**
    The abstract content type name must be the file suffix in the mapping "%1$".
*/
#define CONTMGMTBASE_GraphicAttrMap_Suffix_error             (CONTMGMTBASE_ERROR_BASE + 57)

/**
    An exception was detected while importing the image "%1$". Please request help from a Content Management administrator.
*/
#define CONTMGMTBASE_Image_Creating_exception                (CONTMGMTBASE_ERROR_BASE + 58)

/**
    The overwrite mode "Skip" cannot be used for the graphic "%1$", because the imported graphic contains different graphic names with the same existing usage. Please check the imported graphic.
*/
#define CONTMGMTBASE_CanNotUseOverSKIP_error                 (CONTMGMTBASE_ERROR_BASE + 59)

/**
    The overwrite mode is not set for the graphic "%1$", because the imported graphic contains the same existing usage. Please select the "Overwrite existing" mode and set the Usages to "Keep" or "Merge" or "Overwrite", and try again.
*/
#define CONTMGMTBASE_OverwriteModeIsNotSet_error             (CONTMGMTBASE_ERROR_BASE + 60)

/**
    The function "splitImportGraphicFileName" with suffix or without suffix, is missing a field separator or a fixed field length in the mapping "%1$".
*/
#define CONTMGMTBASE_GraphicAttrMap_error                    (CONTMGMTBASE_ERROR_BASE + 61)

/**
    The content reference in "%1$" to the topic or graphic "%2$" cannot be resolved. Please correct the reference in the document.
*/
#define CONTMGMTBASE_TopicContentRefNotFound                 (CONTMGMTBASE_ERROR_BASE + 62)

/**
    The topic cannot be updated with the current changes because the referenced element "%1$" has been removed.
*/
#define CONTMGMTBASE_ReferencedElementRemoved                (CONTMGMTBASE_ERROR_BASE + 63)

/**
    The topic "%1$" could not be updated during the decomposition, because it already exists with a different class than the one being imported. Please either delete the existing topic, or do not use the "Find by XML Number" option for the import operation.
*/
#define CONTMGMTBASE_update_topic_error_different_classes     (CONTMGMTBASE_ERROR_BASE + 64)

/**
    The value entered for the attribute "%1$" does not match the schema. The format should be "%2$".
*/
#define CONTMGMTBASE_ValueDoesntMatchSchema                    (CONTMGMTBASE_ERROR_BASE + 65)

/**
    Multiple topic types are found for the imported file "%1$". Please update the topic type conditions so that the topic type can be determined.
*/
#define CONTMGMTBASE_MultipleTopicTypes                        (CONTMGMTBASE_ERROR_BASE + 66)

/**
    The attributes for the topic type "%1$" do not match the imported XML file for the topic. Please update the topic type to match the XML data.
*/
#define CONTMGMTBASE_TopicTypeDataIssue                        (CONTMGMTBASE_ERROR_BASE + 67)

/**
    The XPath "%1$" used for deep link testing is invalid. Please fix the XPath in the referencing topic, or update the XML attribute mapping.
*/
#define CONTMGMTBASE_XPathIssueDuringDeepLink                  (CONTMGMTBASE_ERROR_BASE + 68)

/**
    An XML exception has occurred on line "%1$" and column "%2$". This is most likely caused by a schema validation error. Please either update the XML file to be conforming to the schema, or disable schema validation on parse option for the topic type.
*/
#define CONTMGMTBASE_ValidationError                           (CONTMGMTBASE_ERROR_BASE + 69)

/**
     Failed to find a standard number system node for the topic "%1$". However, this topic has been related to the selected standard number system root node.
*/
#define CONTMGMTBASE_sns_node_not_found                        (CONTMGMTBASE_ERROR_BASE + 70)

/**
     A topic with item_id "%1$" already exists.
*/
#define CONTMGMTBASE_item_exists_with_id                       (CONTMGMTBASE_ERROR_BASE + 71)

/**
     A Standard Numbering System node of type "%1$" cannot be pasted under the node "%2$". Only types "%3$" are allowed.
*/
#define CONTMGMTBASE_sns_node_paste_error                      (CONTMGMTBASE_ERROR_BASE + 72)

/**
    The reference to the key "%1$" found in the topic "%2$" cannot be resolved. Please add a definition to this key in the DITA map.
*/
#define CONTMGMTBASE_key_reference_not_found                   (CONTMGMTBASE_ERROR_BASE + 73 )

/**
    The reference topic type "%1$" has a child reference topic type.  Please contact your administrator to remove the child reference topic type.
*/
#define CONTMGMTBASE_ref_topic_type_to_ref_topic_type          (CONTMGMTBASE_ERROR_BASE + 74 )

/**
    The reference cannot be created, because the specified topic "%1$" does not exist.
*/
#define CONTMGMTBASE_ref_topic_doesnt_exist                    (CONTMGMTBASE_ERROR_BASE + 75 )

/**
     More than one "%1$" callback is registered. Only one callback of this type should be registered at a time. Contact your Content Management administrator to remove the extra callback.
*/
#define CONTMGMTBASE_too_many_pre_callback_functions           (CONTMGMTBASE_ERROR_BASE + 76)

/**
     %1$ callback functions are registered to "%2$".
*/
#define CONTMGMTBASE_too_many_post_callback_functions          (CONTMGMTBASE_ERROR_BASE + 77)

/**
     The callback function "%1$" on "%2$" has thrown an exception.
*/
#define CONTMGMTBASE_callback_exception                        (CONTMGMTBASE_ERROR_BASE + 78)

/**
     The callback function "%1$" on "%2$" has returned an error.
*/
#define CONTMGMTBASE_callback_function_error                   (CONTMGMTBASE_ERROR_BASE + 79)

/**
     No callback function can be found on "%1$".
*/
#define CONTMGMTBASE_callback_function_missing                 (CONTMGMTBASE_ERROR_BASE + 80)

/**
     No callback function can be found on "%1$" from the "%2$" XML attribute map.
*/
#define CONTMGMTBASE_callback_function_missing_xam             (CONTMGMTBASE_ERROR_BASE + 81)

/**
     No valid Revision can be found based on the Revision Rule "%1$".
*/
#define CONTMGMTBASE_warning_revision_rule                     (CONTMGMTBASE_ERROR_BASE + 82)

/**
    %2$ valid topic types are found for "%1$", when there can be only one. Contact your Content Management administrator to remove the extra topic types.
*/
#define CONTMGMTBASE_too_many_valid_paste_topic_type           (CONTMGMTBASE_ERROR_BASE + 83)

/**
    Importing non-topic items is not supported and will be skipped.
*/
#define CONTMGMTBASE_import_non_topic_not_supported            (CONTMGMTBASE_ERROR_BASE + 84)

/**
    The SGML catalog file "%1$" could not be found. Please request help from a Content Management administrator.
*/
#define CONTMGMTBASE_error_getting_sgml_catalog                (CONTMGMTBASE_ERROR_BASE + 85)

/**
    The Topic "%1$" is already checked-out by the user "%2$".
*/
#define CONTMGMTBASE_topic_already_checked_out                 (CONTMGMTBASE_ERROR_BASE + 86)

/**
    An error has occurred during the "Content Management Revise" operation. Please check the server syslog file for more information.
*/
#define CONTMGMTBASE_error_during_contmgmt_revise_operation    (CONTMGMTBASE_ERROR_BASE + 87)

/**
    An error has occurred during the "Content Management Save As" operation. Please check the server syslog file for more information.
*/
#define CONTMGMTBASE_error_during_contmgmt_saveas_operation    (CONTMGMTBASE_ERROR_BASE + 88)

/**
    An error has occurred during the "Content Management Baseline" operation. Please check the server syslog file for more information.
*/
#define CONTMGMTBASE_error_during_contmgmt_baseline_operation  (CONTMGMTBASE_ERROR_BASE + 89)

/**
    @deprecated #CONTMGMTBASE_duplicate_sequence_number deprecated in Teamcenter 11.5. Use #CONTMGMTBASE_duplicate_sequence_number_and_occurrence instead.
*/
#define CONTMGMTBASE_duplicate_sequence_number                 (CONTMGMTBASE_ERROR_BASE + 90)
TC_DEPRECATED_PREPROCESSOR( "11.5", CONTMGMTBASE_duplicate_sequence_number, "CONTMGMTBASE_duplicate_sequence_number_and_occurrence" )

/**
    The BOM Structure for "%1$" contains the duplicate sequence (find) number "%2$" for the occurrence type "%3$".
*/
#define CONTMGMTBASE_duplicate_sequence_number_and_occurrence  (CONTMGMTBASE_ERROR_BASE + 90)

/**
    @deprecated #CONTMGMTBASE_missing_sequence_number deprecated in Teamcenter 11.5. Use #CONTMGMTBASE_missing_sequence_number_and_occurrence instead.
*/
#define CONTMGMTBASE_missing_sequence_number                   (CONTMGMTBASE_ERROR_BASE + 91)
TC_DEPRECATED_PREPROCESSOR( "11.5", CONTMGMTBASE_missing_sequence_number, "CONTMGMTBASE_missing_sequence_number_and_occurrence" )
/**
    The BOM Structure for "%1$" is missing the sequence (find) number "%2$" and occurrence type "%3$".
*/
#define CONTMGMTBASE_missing_sequence_number_and_occurrence    (CONTMGMTBASE_ERROR_BASE + 91)

/**
    The BOM Structures for "%1$" and "%2$" do not match.
*/
#define CONTMGMTBASE_structures_do_not_match                   (CONTMGMTBASE_ERROR_BASE + 92)

/**
    The "Compose" process has failed to find the Graphic "%1$". Please verify that it exists.
*/
#define CONTMGMTBASE_graphic_not_found                         (CONTMGMTBASE_ERROR_BASE + 93)

/**
    The "Compose" process has failed to find the correct graphic translation related to "%1$". Please verify that a graphic translation exists for the following languages: %2$.
*/
#define CONTMGMTBASE_graphic_translation_not_found             (CONTMGMTBASE_ERROR_BASE + 94)

/**
    A relation cannot be created from "%1$" to itself. Please correct the reference in the document.
*/
#define CONTMGMTBASE_self_reference                            (CONTMGMTBASE_ERROR_BASE + 95)

/**
    The value of the attribute "%1$" on "%2$" exceeds the maximum length of %3$ characters.
*/
#define CONTMGMTBASE_attr_exceeds_max_length                   (CONTMGMTBASE_ERROR_BASE + 96)

/**
    Removing content or graphic references in the Publication Structure is not allowed. Please remove the content or graphic reference in an edit session.
*/
#define CONTMGMTBASE_remove_conref_in_pub_struct_not_allowed   (CONTMGMTBASE_ERROR_BASE + 97)

/**
    "%1$" cannot be added to "%2$". The valid topic types that can be added are: "%3$".
*/
#define CONTMGMTBASE_invalid_paste_topic_type_expanded         (CONTMGMTBASE_ERROR_BASE + 98)

/**
    The topic "%1$", rev "%2$" cannot be found.
*/
#define CONTMGMTBASE_find_topic_rev_error                      (CONTMGMTBASE_ERROR_BASE + 99)

/**
    The imported translation zip file is not valid
*/
#define CONTMGMTBASE_translation_zip_error                      (CONTMGMTBASE_ERROR_BASE + 400)

/**
    The translation zip file contains both "compose" and "decompose" folders under the "translated" folder.Only one can be present.

*/
#define CONTMGMTBASE_translation_both_error                     (CONTMGMTBASE_ERROR_BASE + 401)

/**
    Cannot find translation order for the topic "%1$".

*/
#define CONTMGMTBASE_cannot_find_order_error                    (CONTMGMTBASE_ERROR_BASE + 402)

/** @} */

#include <contmgmtbase/libcontmgmtbase_undef.h>

#endif
