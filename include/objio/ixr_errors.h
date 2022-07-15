/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Teamcenter Engineering Export Record Errors
*/

/*  */

#ifndef ixr_errors_h
#define ixr_errors_h

#include <objio/libobjio_exports.h>

/**
    @defgroup IXR_ERRORS Teamcenter Engineering Export Record Errors
    @ingroup OBJIO
    @{
*/

#define IXR_internal_error               (EMH_IXR_error_base + 1)
#define IXR_no_initialize                (EMH_IXR_error_base + 2)
#define IXR_no_create                    (EMH_IXR_error_base + 3)
#define IXR_invalid_export_reason        (EMH_IXR_error_base + 4)
#define IXR_invalid_target_site          (EMH_IXR_error_base + 5)
#define IXR_invalid_exported_object      (EMH_IXR_error_base + 6)
#define IXR_invalid_exporter_id          (EMH_IXR_error_base + 7)
#define IXR_invalid_date                 (EMH_IXR_error_base + 8)
#define IXR_no_create_item_export_record (EMH_IXR_error_base + 9)
#define IXR_invalid_status_type          (EMH_IXR_error_base + 10)
#define IXR_no_init_item_export_record   (EMH_IXR_error_base + 11)
#define IXR_item_export_record_not_found (EMH_IXR_error_base + 12)
#define IXR_invalid_rev_name             (EMH_IXR_error_base + 13)

/** @} */

#include <objio/libobjio_undef.h>
#endif
