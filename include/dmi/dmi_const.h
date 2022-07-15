/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    DMI constants
*/

/*  */

#ifndef DMI_CONST_H_INCLUDED
#define DMI_CONST_H_INCLUDED

#include <dmi/libdmi_exports.h>

/**
    @defgroup DMI_CONST Constants
    @ingroup DMI
    @{
*/

/**
    @name DMI constants
    @{
*/
#define DMI_file_name_size_c    32
#define DMI_path_name_size_c    255
#define DMI_CREATE_MARKUP       101
#define DMI_MERGE_ALL_MARKUPS   102
/** @} */

/** Document Profile */
#define DMI_PROFILE             "DocProfile"

/** Document Item */
#define DMI_TYPE                "Document"

/** Doc Item Rev */
#define DMI_REV_TYPE            "DocumentRevision"

/** Binder relation type. Now, we use the IMAN reference to associate with the binder */
#define DMI_DOC_BINDER          TC_reference_rtype

/** Binder name */
#define DMI_BINDER_NAME         "Binder"

/** Markup Dataset type */
#define DMI_MARKUP              "Markup"

/** Temporary markup Dataset type */
#define DMI_TEMP_MARKUP         "TempMarkup"

/** Markup Relation type */
#define DMI_MARKUP_rtype        "DMI_markup"

/** Image named reference */
#define DMI_IMAGE               "Image"

/**
    @name Image Dataset type
    @{
*/

/** Thumbnail named reference */
#define DMI_THUMBNAIL           "ThumbNail"

/** Text named reference */
#define DMI_TEXT                "Text"

/** Doc stack named reference */
#define DMI_STACK               "DocStack"
/** @} */

/** Temp directory to export file */
#define  EXPORT_DIR             "/tmp"

/** @} */

#include <dmi/libdmi_undef.h>

#endif
