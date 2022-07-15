/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Define error codes used with folder.
*/

/*  */

#ifndef FOLDER_ERRORS_H
#define FOLDER_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup FL_ERRORS Errors
    @ingroup FL
    @{
*/

/**
    @name Error code constants
    @{
*/

/** Invalid sort criteria */
#define FL_invalid_sort_criteria           (EMH_FL_error_base + 1)

/** Invalid sort order */
#define FL_invalid_sort_order              (EMH_FL_error_base + 2)

/**
    If any of the indexes provided by the move command is invalid,
    this error code is generated
*/
#define FL_invalid_index                   (EMH_FL_error_base + 3)

#define FL_cannot_add_self                 (EMH_FL_error_base + 4)

/** A folder may not be added to itself nor can a #NULLTAG be added. */
#define FL_cannot_add_null_tag             (EMH_FL_error_base + 5)

/** Specified object is not in the folder */
#define FL_not_found                       (EMH_FL_error_base + 6)

/** Specified object for insertion in a folder already exists in the folder. */
#define FL_object_already_added            (EMH_FL_error_base + 7)

/** When a preference of "FL_duplicates_not_allowed true" is in effect. */
#define FL_duplicate_name                  (EMH_FL_error_base + 8)

/** The initialization of a folder failed. */
#define FL_initialization_failed           (EMH_FL_error_base + 9)

/**
    This error is generated if a name is not provided when the preference
    for not allowing duplicate names is active. See #FL_duplicate_name
*/
#define FL_name_required                   (EMH_FL_error_base + 10)

/**
    This error is generated if users want to save a folder that has not yet
    been modified
*/
#define FL_no_save                         (EMH_FL_error_base + 11)

/** This error is generated if a name input is more than 32 char long */
#define FL_name_limit                      (EMH_FL_error_base + 12)

/** This error is generated if a description input is more than 240 char long */
#define FL_description_limit               (EMH_FL_error_base + 13)

#define FL_cantModifyAFrozenFolder         (EMH_FL_error_base + 14)
#define FL_cantInsertNonWSO                (EMH_FL_error_base + 15)

#define FL_cantExportContained             (EMH_FL_error_base + 16)
#define FL_cantImportContained             (EMH_FL_error_base + 17)

/** @} */

/**
    @name Obsolete

    Please phase out.
    @{
*/

#define FL_invalid_FSC                     (EMH_FL_error_base + 1)
#define FL_invalid_FSO                     (EMH_FL_error_base + 2)

/** @} */

/**
    @name Errors from flwindow, fltable
    @{
*/

#define FL_noneToPaste                     (EMH_FL_error_base + 101)
#define FL_moveUpHetero                    (EMH_FL_error_base + 102)
#define FL_moveUpTop                       (EMH_FL_error_base + 103)
#define FL_moveUpDiffParent                (EMH_FL_error_base + 104)
#define FL_moveDownHetero                  (EMH_FL_error_base + 105)
#define FL_moveDownLast                    (EMH_FL_error_base + 106)
#define FL_moveDownDiffParent              (EMH_FL_error_base + 107)
#define FL_cantMoveBlocks                  (EMH_FL_error_base + 108)
#define FL_clipboardWriteFailed            (EMH_FL_error_base + 109)
#define FL_clipboardReadFailed             (EMH_FL_error_base + 110)
#define FL_cantInsertToNonFolder           (EMH_FL_error_base + 111)
#define FL_nothingToCopy                   (EMH_FL_error_base + 112)
#define FL_notApplicableToRoot             (EMH_FL_error_base + 113)

/** "Mailbox" folder cannot be removed from "Home Folder".*/
#define FL_cantCutMailFolder               (EMH_FL_error_base + 114)

/** "Newstuff" folder cannot be removed from "Home Folder".*/
#define FL_cantCutNewStuff                 (EMH_FL_error_base + 115)

#define FL_cantDestroyMailFolder           (EMH_FL_error_base + 116)
#define FL_cantDestroyHomeFolder           (EMH_FL_error_base + 117)
#define FL_cantDestroyNSFFolder            (EMH_FL_error_base + 118)
#define FL_cantCollapseNonFolder           (EMH_FL_error_base + 119)
#define FL_alreadyExpanded                 (EMH_FL_error_base + 120)
#define FL_cantExpandNonFolder             (EMH_FL_error_base + 121)
#define FL_alreadyCollapsed                (EMH_FL_error_base + 122)
#define FL_columnWidth                     (EMH_FL_error_base + 123)
#define FL_saveColumnWidthPrefFailed       (EMH_FL_error_base + 124)
#define FL_saveColumnsPrefFailed           (EMH_FL_error_base + 125)
#define FL_dontKnowHowToSaveNonFolder      (EMH_FL_error_base + 126)
#define FL_cantLatestNonFolder             (EMH_FL_error_base + 127)
#define FL_cantImportToNonFolder           (EMH_FL_error_base + 128)
#define FL_errorDelete                     (EMH_FL_error_base + 129)
#define FL_saveWsoPrefFailed               (EMH_FL_error_base + 131)
#define FL_duplicateEntry                  (EMH_FL_error_base + 132)
#define FL_addEmptyEntry                   (EMH_FL_error_base + 133)
#define FL_insertObjsFailed                (EMH_FL_error_base + 134)
#define FL_staleObjPtr                     (EMH_FL_error_base + 135)
#define FL_insertNSFFailed                 (EMH_FL_error_base + 136)
#define FL_invalidColumnWidth              (EMH_FL_error_base + 137)
#define FL_emptyColumnWidth                (EMH_FL_error_base + 138)
#define FL_datasetAutoLatest               (EMH_FL_error_base + 139)
#define FL_nonIntColumnWidth               (EMH_FL_error_base + 140)
#define FL_cantImportMultipleObjects       (EMH_FL_error_base + 141)
#define FL_cantImportNonDirectory          (EMH_FL_error_base + 142)
#define FL_cantCutHomeFolder               (EMH_FL_error_base + 143)
#define FL_pasteAccessForbidden            (EMH_FL_error_base + 144)
#define FL_cutAccessForbidden              (EMH_FL_error_base + 145)
#define FL_requiredItemRevisons            (EMH_FL_error_base + 146)
#define FL_noStatuses                      (EMH_FL_error_base + 147)
#define FL_noReadAccessToLatest            (EMH_FL_error_base + 148)
#define FL_noWriteAccessToLatest           (EMH_FL_error_base + 149)
#define FL_cantCutFromInBox                (EMH_FL_error_base + 150)
#define FL_cantPasteToInBox                (EMH_FL_error_base + 151)
#define FL_cantExportSpecial               (EMH_FL_error_base + 152)
#define FL_cantDeleteFolderOwnedByOthers   (EMH_FL_error_base + 153)
#define FL_object_already_added_as         (EMH_FL_error_base + 154)
#define FL_cantExportProjectBackups        (EMH_FL_error_base + 155)
/** The operation is only supported for latest revisions */
#define FL_canOnlySetLatestContents        (EMH_FL_error_base + 156)
/** The folder cannot contain itself. */
#define FL_cantContainSelf                 (EMH_FL_error_base + 157)

/** @} */

/** @} */

#endif
