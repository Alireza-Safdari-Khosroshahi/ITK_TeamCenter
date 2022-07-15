/*
   Copyright 2020 Siemens Digital Industries Software
   =====================================================================
   Copyright 2008.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ====================================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    All errors related to Aerospace and Defense foundation.
*/

#ifndef ADSFOUNDATION_ERRORS_H
#define ADSFOUNDATION_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup ADSFOUNDATION_ERRORS Errors
    @ingroup ADSFOUNDATION
    @{
*/

/** In document-centric programs, information about the source document is mandatory. Enter all the mandatory fields related to the source document. */
#define ADSFOUNDATION_error_MissingSourceDocument                       (EMH_ADSFOUNDATION_error_base + 1)

/** The specified source document does not exist. Specify a valid source document. */
#define ADSFOUNDATION_error_Item_does_not_exist                         (EMH_ADSFOUNDATION_error_base + 2)

/** Your role is not authorized to perform this operation. You may contact your System Administrator for help. */
#define ADSFOUNDATION_error_Check_Authority                             (EMH_ADSFOUNDATION_error_base + 3)

/** The delete operation is unsuccessful because the %1$ or the %2$ is used as a source document. */
#define ADSFOUNDATION_error_Technical_Document_Attached                 (EMH_ADSFOUNDATION_error_base + 4)

/** No source document matches the value specified in the '%1$' field. Enter a value that matches the source document. */
#define ADSFOUNDATION_error_MismatchSourceTechDocCategory               (EMH_ADSFOUNDATION_error_base + 5)

/** For document-centric programs, enter the '%1$'. The %1$ must match with the organization of an existing source document. */
#define ADSFOUNDATION_error_MissingSourceDocOrg                         (EMH_ADSFOUNDATION_error_base + 6)

/** For document-centric programs, the '%1$' is a mandatory field. Enter a valid %1$. */
#define ADSFOUNDATION_error_MissingSourceTechDocCategory                (EMH_ADSFOUNDATION_error_base + 7)

/** No source document matches the value specified in the '%1$' field. Enter a value that matches the source document. */
#define ADSFOUNDATION_error_MismatchSourceDocCategory                   (EMH_ADSFOUNDATION_error_base + 8)

/** For document-centric programs, enter the '%1$'. The %1$ must match an existing source document. */
#define ADSFOUNDATION_error_MissingSourceDocCategory                    (EMH_ADSFOUNDATION_error_base + 9)

/** The active project for the user session is document-centric. Enter all the mandatory fields related to the source document. */
#define ADSFOUNDATION_error_MissingMandatoryAttributes                  (EMH_ADSFOUNDATION_error_base + 10)

/** No source document matches the value specified in the '%1$' field. Enter a value that matches the source document. */
#define ADSFOUNDATION_error_PC_MismatchSourceDocAttribute               (EMH_ADSFOUNDATION_error_base + 11)

/** The value specified in the '%1$' field is invalid. Enter a value that matches with the source document. */
#define ADSFOUNDATION_error_InvalidOrgEntry                             (EMH_ADSFOUNDATION_error_base + 14)

/** The relation could not be created: the primary object, the secondary object, or the relation type does not exist. */
#define ADSFOUNDATION_error_InvalidRelation                             (EMH_ADSFOUNDATION_error_base + 15)

/** The auto-selection of the source document is unsuccessful: information about the source document cannot be derived from the given item ID. Enter a correct source document ID. */
#define ADSFOUNDATION_error_SourceDocumentDoesNotExist                  (EMH_ADSFOUNDATION_error_base + 16)

/** "%1$" was not added because a source document with ID "%2$" already exists. Select a different source document and try again. */
#define ADSFOUNDATION_error_EnterSourceDocumentInformtion               (EMH_ADSFOUNDATION_error_base + 17)

/** The auto-creation of the %1$ is unsuccessful: the value entered in the '%2$' field does not match the user's organization ID. Enter a valid organization ID for the %1$. */
#define ADSFOUNDATION_error_MismatchOrganizationDuringAutoCreate        (EMH_ADSFOUNDATION_error_base + 18)

/** The auto-selection of the source document is unsuccessful: the value entered in the '%1$' field does not match the user's organization ID. Enter a valid organization ID for the source document. */
#define ADSFOUNDATION_error_MismatchOrganizationDuringAutoSelect        (EMH_ADSFOUNDATION_error_base + 19)

/** The auto-creation of source documents is enabled.Enter a valid value in the '%1$' field. */
#define ADSFOUNDATION_error_EnterSourceDocFields                        (EMH_ADSFOUNDATION_error_base + 20)

/** The auto-selection and auto-creation of technical documents are disabled. Enter the source document information or contact your System Administrator to enable the auto-selection and auto-creation functionalities. */
#define ADSFOUNDATION_error_AutoSelectionAutoCreationNotPossible        (EMH_ADSFOUNDATION_error_base + 22)

/** The Item can not be created or revised because the entered source document revision has been released. Use a valid source document revision. */
#define ADSFOUNDATION_error_MaturedSourceDoc                            (EMH_ADSFOUNDATION_error_base + 23)

/** The Item cannot be associated to the selected %1$ as a foreign component since its Item Revision has already been associated to this %1$. */
#define ADSFOUNDATION_error_Invalid_ADSCompRelation                     (EMH_ADSFOUNDATION_error_base + 24)

/** The Item Revision is already associated to another %1$. Select an Item Revision which is not already associated to this %2$. */
#define ADSFOUNDATION_error_Invalid_ADSCompRevRelation                  (EMH_ADSFOUNDATION_error_base + 25)

/** The specified '%1$' is not a valid Organization. */
#define ADSFOUNDATION_error_Invalid_CustOrganization                    (EMH_ADSFOUNDATION_error_base + 26)

/** The Item being created or revised does not have access to the %1$. */
#define ADSFOUNDATION_error_Invalid_TechDocPrivilege                    (EMH_ADSFOUNDATION_error_base + 27)

/** The source document for the Part does not exist at the target site. Source document must exist at the target site before importing the Part. */
#define ADSFOUNDATION_error_MissingSourceDocAtImportingSite             (EMH_ADSFOUNDATION_error_base + 28)

/** The value supplied for property Item Id is invalid for %1$ auto-creation. Select a naming rule with pattern '01-NNNN-NNN' where N is any digit. */
#define ADSFOUNDATION_error_Invalid_Id_For_AutoCreate                   (EMH_ADSFOUNDATION_error_base + 29)

/** This Note cannot be set since it is not attached to the parent %1$. Please attach this Note to the %2$. */
#define ADSFOUNDATIONNOTES_error_Invalid_Notes                          (EMH_ADSFOUNDATION_error_base + 30)

/** The input object is not a valid %1$ or %2$. */
#define ADSFOUNDATIONNOTES_error_Not_A_NoteOrRev                        (EMH_ADSFOUNDATION_error_base + 31)

/** You don&apos;t have write access to object %1$, which is set as the current %2$ in the session. Please change the current %2$ in the session to a %2$ object on which you have write access. */
#define ADSFOUNDATIONNOTES_error_No_Write_Acess_on_CN                   (EMH_ADSFOUNDATION_error_base + 32)

/** "%1$" was not saved/added because the Part List Note "%2$" is already being used. */
#define ADSFOUNDATIONNOTES_error_partslistnote_already_attached         (EMH_ADSFOUNDATION_error_base + 33)

/** The following input values for Parts List Note are duplicate. Please specify unique values. Duplicate entries are: %1$. */
#define ADSFOUNDATIONNOTES_error_duplicate_partslistnote                (EMH_ADSFOUNDATION_error_base + 34)

/** The following input values for Parts List Note are not valid. Please specify valid values. Invalid values are: %1$. */
#define ADSFOUNDATIONNOTES_error_invalid_partslistnote                  (EMH_ADSFOUNDATION_error_base + 35)

/** The value provided in the "%1$" field does not match the Item ID of the object mentioned in the "%2$" field. */
#define ADSFOUNDATION_error_MismatchSourceDocAttribute                  (EMH_ADSFOUNDATION_error_base + 36)

/** The new Program to be reassigned must be provided. */
#define ADSFOUNDATION_invalid_input_program                             (EMH_ADSFOUNDATION_error_base + 37)

/** Selected Items must be provided. */
#define ADSFOUNDATION_invalid_input_items                               (EMH_ADSFOUNDATION_error_base + 38)

/** Only Items can be selected. */
#define ADSFOUNDATION_invalid_selection                                 (EMH_ADSFOUNDATION_error_base + 39)

/** An error has occurred while assigning "%1$" to "%2$". Please refer to the Teamcenter server syslog file for more information.  */
#define ADSFOUNDATION_project_assign_error                              (EMH_ADSFOUNDATION_error_base + 40)

/** Only the selected Item and the latest Item Revision are updated with the new Owning Program, because no propagation rule is defined for Owning Programs. */
#define ADSFOUNDATION_no_propagation_rules_warning                      (EMH_ADSFOUNDATION_error_base + 41)

/** The attribute "Category/Technical Document Category/Revision" of the Source Document does not match any existing Source Document. Either change the base part number or change the value of this attribute for the Source Document. */
#define ADSFOUNDATION_error_source_document_not_found_change_part_no    (EMH_ADSFOUNDATION_error_base + 42)

/**  "%1$" was not created because the specified source document is not of the type "%2$", as required by the "Ads0AllowAttachingDocTypesToADSObjs" business object constant. */
#define ADSFOUNDATION_error_invalid_document_type                       (EMH_ADSFOUNDATION_error_base + 43)

/** @} */
#endif

