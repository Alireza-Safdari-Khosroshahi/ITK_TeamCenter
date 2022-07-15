/*=============================================================================
Copyright (c) 2018 Siemens Corporation

Unpublished - All rights reserved

===============================================================================
File description: Errors for the SOA DocumentManagement Services

FILE  : soadocumentmanagement_errors.h
MODULE: TcSoaDocumentManagement
====================================================================================================
Date        Name        Description of Change
13-Oct-2010 Kevin Shah      File creation
$HISTORY$
===================================================================================================*/

#ifndef SOADOCUMENTMANAGEMENT_ERRORS_H
#define    SOADOCUMENTMANAGEMENT_ERRORS_H

#include <common/emh_const.h>

#define SOADOCUMENTMANAGEMENT_ERROR_BASE                            EMH_SOADOCUMENTMANAGEMENT_error_base


/** The input is empty. */
#define SOADOCUMENTMANAGEMENT_empty_set_or_get_input                  ( SOADOCUMENTMANAGEMENT_ERROR_BASE + 1 )

/** The input dataset or the attribute exchange setvalue is empty. */
#define SOADOCUMENTMANAGEMENT_empty_dataset_attrex_setvalue           ( SOADOCUMENTMANAGEMENT_ERROR_BASE + 2 )

/** The resolved attribute exchange collection is empty. */
#define SOADOCUMENTMANAGEMENT_empty_resolved_attrex                   ( SOADOCUMENTMANAGEMENT_ERROR_BASE + 3 )

/** The attribute exchange collection is empty. */
#define SOADOCUMENTMANAGEMENT_empty_attrex                            ( SOADOCUMENTMANAGEMENT_ERROR_BASE + 4 )

/** The input dataset or the attribute exchange is empty. */
#define SOADOCUMENTMANAGEMENT_empty_dataset_attrex                    ( SOADOCUMENTMANAGEMENT_ERROR_BASE + 5 )

/** The input properties have failed to be retrieved. Therefore the response collection is empty. */
#define SOADOCUMENTMANAGEMENT_empty_get_props_response                ( SOADOCUMENTMANAGEMENT_ERROR_BASE + 6 )

/** The Foreign object is empty. */
#define SOADOCUMENTMANAGEMENT_empty_foreign_object                    ( SOADOCUMENTMANAGEMENT_ERROR_BASE + 7 )

/** "%1$" cannot be rendered to "%2$" because it is not of type or sub-type of Dataset or Item Revision. */
#define SOADOCUMENTMANAGEMENT_invalid_object                          ( SOADOCUMENTMANAGEMENT_ERROR_BASE + 8 )

/** "%1$" cannot be rendered to "%2$" because it contains no files that can be rendered. */
#define SOADOCUMENTMANAGEMENT_no_renderable_files                     ( SOADOCUMENTMANAGEMENT_ERROR_BASE + 9 )

/** "%1$" is not a supported render format. */
#define SOADOCUMENTMANAGEMENT_unsupported_render_format               ( SOADOCUMENTMANAGEMENT_ERROR_BASE + 10 )

/** "%1$" cannot be rendered to "%2$" because it contains no named references. */
#define SOADOCUMENTMANAGEMENT_no_named_references                     ( SOADOCUMENTMANAGEMENT_ERROR_BASE + 11 )

#endif
