/**=============================================================================
Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright $2010.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software*/


/**
    @file

    This file contains the error codes for the MESBVR module
*/

/*  */

#ifndef MESBVR_ERRORS_H
#define MESBVR_ERRORS_H

#include <common/emh_const.h>
#include <mesbvr/libmesbvr_exports.h>

/**
    @defgroup MESBVR_ERRORS MESBVR Errors
    @ingroup MES
    @{
*/

/** @} */
/** A Manufacturing Execution System internal error has occurred. Please contact your system administrator.*/
#define MESBVR_internal_error                                                (EMH_MESBVR_error_base + 1)

/** The specification template preference "%1$" does not exist for Work Instruction objects. */
#define MESBVR_TemplatePreferenceDoesNotExist                                (EMH_MESBVR_error_base + 2)

/** The value for the specification template preference "%1$" is empty for Work Instruction objects. */
#define MESBVR_TemplatePreferenceEmpty                                       (EMH_MESBVR_error_base + 3)

/** The document "%1$" does not exist in the transient volume. */
#define MESBVR_DocumentDoesNotExistInTransVolume                             (EMH_MESBVR_error_base + 4)

/** The object ID is missing for the object "%1$". */
#define MESBVR_ObjectIDIsMissing                                             (EMH_MESBVR_error_base + 5)

/** "Invalid Reference" elements have a control in the document, but the element object was not found in the structure. The object has been removed from the structure or is configured out in the current BOM Window. */
#define MESBVR_ObjectNotFoundInStructureError                                (EMH_MESBVR_error_base + 6)

/** The document type "%1$" is not supported for the import operation. Valid types are "docx" and "txt".*/
#define MESBVR_document_type_not_supported_for_import                        (EMH_MESBVR_error_base + 7)

/** The target object "%1$" is invalid, because only objects of type "Mes0MESTXElement" are allowed. */
#define MESBVR_invalid_target_object                                         (EMH_MESBVR_error_base + 8)

#include <mesbvr/libmesbvr_undef.h>
#endif


