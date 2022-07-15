/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2015.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/** @if HISTORY_SECTION
=========================================================================================
   Date                   Name                    Description of Change
   July-09-2008           Srinath Vojjala         Initial Version
   July-18-2016           Binuraj Rajagopal       Fix for PR#7675853 When the auto create is 
                                                  enabled and 
                                                  1. if user enters Part Id such 
                                                  that there exist already a techincal document 
                                                  with same id 
                                                  2. and user enters source documents attributes 
                                                  that do not match the already existing techincal document
                                                  Then an error message is shown to user 
                                                  “The Category/Technical Document Category of Technical Document do not match an existing Technical Document.  Either change the base part number or change the Category/Technical Document Category of Technical Document.”
$HISTORY$
=======================================================================================
@endif */

#ifndef ADSFOUNDATION_H
#define ADSFOUNDATION_H

/**   
      @file
      Contains declaration of ITK functions for the ADSFoundation (Aerospace and Defense foundation) module.
*/
/**
    @defgroup ADSFOUNDATION Aerospace and Defense foundation
    @ingroup TC
    @{
*/

#include <unidefs.h>

#include <adsfoundation/libadsfoundation_exports.h>
#define ADSFOUNDATION_external_id_size_c 32

#ifdef __cplusplus
    extern "C"{
#endif

/**
    Searches, auto-selects and auto-creates Source Document objects.
    @returns 
    <ul>
    <li>#ITK_ok on success.
    <li>#ADSFOUNDATION_error_InvalidOrgEntry if the value specified in the Source Document Organization field is invalid
    <li>#ADSFOUNDATION_error_MismatchOrganizationDuringAutoCreate if the value entered in the Source Document Organization field does not match the user's organization ID
    <li>#ADSFOUNDATION_error_Item_does_not_exist if the specified source document does not exist
    <li>#ADSFOUNDATION_error_SourceDocumentDoesNotExist if the information about the source document cannot be derived from the given item ID
    <li>#ADSFOUNDATION_error_Invalid_Id_For_AutoCreate if the value supplied for property Item Id is invalid for auto-creation
    <li>#ADSFOUNDATION_error_EnterSourceDocFields if the auto-creation of source documents is enabled, enter a valid value in the source document field
    <li>#ADSFOUNDATION_error_source_document_not_found_change_part_no if auto-creation is enabled and if the source document attributes do not match with any existing source document with same item ID.
    </ul>
*/
extern ADSFOUNDATION_API int ADS_resolve_source_document(
    const char* object_type,                    /**< (I) Type of the component to be created */
    const char * component_id,                  /**< (I) Id of the component to be created */
    int num_attributes,                         /**< (I) Number of Source Document attributes */
    const char ** attributes_names,             /**< (I) Names of Source Document attributes */
    const char ** attributes_values,            /**< (I) Values of Source Document attributes */
    const char * source_revision_id,            /**< (I) Revision Id of the Source Document */
    const char * source_owning_organization,    /**< (I) Owning Organization of the Source Document Revision */
    logical      is_auto_create,                /**< (I) Source document should be created if not found during search and autocreate is enabled." */
    tag_t * create_input_for_document,          /**< (O) Tag of the create input object used for the auto-creation of the ADSTechDocument object */
    tag_t * autocreate_document,                /**< (O) Tag of the auto-created ADSTechDocument object */
    int * num_documents,                        /**< (O) Number of ADSTechDocument objects in output */
    tag_t ** documents                          /**< (OF) num_documents Tags of matching or created ADSTechDocument objects */
    );

#ifdef __cplusplus
}
#endif

#include <adsfoundation/libadsfoundation_undef.h>

/** @} */
#endif
