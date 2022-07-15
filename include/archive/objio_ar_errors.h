/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This file contains error codes that are generated by OBJIO AR
*/

/*  */

#ifndef OBJIO_AR_ERRORS_H
#define OBJIO_AR_ERRORS_H

#ifndef EMH_CONST_H
    #include <common/emh_const.h>
#endif

#include <archive/libarchive_exports.h>

/**
    @defgroup OBJIO_AR_ERRORS OBJIO AR Errors
    @ingroup OBJIO_AR
    @{
*/

#define OBJIO_AR_error_base                     EMH_ARCHIVE_error_base + 50

#define OBJIO_AR_unable_to_create               (OBJIO_AR_error_base + 1)
#define OBJIO_AR_cannot_archive_checked_out     (OBJIO_AR_error_base + 2)
#define OBJIO_AR_none_to_paste                  (OBJIO_AR_error_base + 3)
#define OBJIO_AR_invalid_operation              (OBJIO_AR_error_base + 4)
#define OBJIO_AR_no_object                      (OBJIO_AR_error_base + 5)
#define OBJIO_AR_invalid_media                  (OBJIO_AR_error_base + 6)
#define OBJIO_AR_no_access                      (OBJIO_AR_error_base + 8)
#define OBJIO_AR_meta_file_name_exist           (OBJIO_AR_error_base + 9)
#define OBJIO_AR_load_pref_attr_error           (OBJIO_AR_error_base + 10)
#define OBJIO_AR_fail_to_archive                (OBJIO_AR_error_base + 11)
#define OBJIO_AR_update_object_fail             (OBJIO_AR_error_base + 12)
#define OBJIO_AR_already_archived               (OBJIO_AR_error_base + 13)
#define OBJIO_AR_media_not_online               (OBJIO_AR_error_base + 14)
#define OBJIO_AR_clipboard_read_fail            (OBJIO_AR_error_base + 15)
#define OBJIO_AR_fail_to_restore                (OBJIO_AR_error_base + 16)
#define OBJIO_AR_no_restore_access              (OBJIO_AR_error_base + 17)
#define OBJIO_AR_no_archive_access              (OBJIO_AR_error_base + 18)
#define OBJIO_AR_no_batch_privilege             (OBJIO_AR_error_base + 20)
#define OBJIO_AR_error_getting_filename         (OBJIO_AR_error_base + 21)
#define OBJIO_AR_internal_error                 (OBJIO_AR_error_base + 22)
#define OBJIO_AR_not_archived                   (OBJIO_AR_error_base + 23)
#define OBJIO_AR_no_markarchive_access          (OBJIO_AR_error_base + 25)
#define OBJIO_AR_no_search_criteria             (OBJIO_AR_error_base + 26)
/** Obsolete */
#define OBJIO_AR_one_and_only_one               (OBJIO_AR_error_base + 27)
#define OBJIO_AR_only_one                       (OBJIO_AR_error_base + 27)
#define OBJIO_AR_no_archive_info_found          (OBJIO_AR_error_base + 28)
#define OBJIO_AR_no_archive_pending             (OBJIO_AR_error_base + 29)
#define OBJIO_AR_no_restore_pending             (OBJIO_AR_error_base + 30)
#define OBJIO_AR_no_delete_request_access       (OBJIO_AR_error_base + 31)
#define OBJIO_AR_no_modify_request_access       (OBJIO_AR_error_base + 32)
#define OBJIO_AR_no_related_filetoc_found       (OBJIO_AR_error_base + 33)
#define OBJIO_AR_load_wrong_tape                (OBJIO_AR_error_base + 34)
#define OBJIO_AR_mediatoc_not_found             (OBJIO_AR_error_base + 35)
#define OBJIO_AR_no_device_label_entered        (OBJIO_AR_error_base + 36)
#define OBJIO_AR_no_object_mark_archive         (OBJIO_AR_error_base + 37)
#define OBJIO_AR_no_object_mark_restore         (OBJIO_AR_error_base + 38)
#define OBJIO_AR_out_of_memory                  (OBJIO_AR_error_base + 39)
#define OBJIO_AR_cannot_restore_remote_object   (OBJIO_AR_error_base + 40)
#define OBJIO_AR_cannot_archive_replica         (OBJIO_AR_error_base + 41)
#define OBJIO_AR_duplicate_selection            (OBJIO_AR_error_base + 42)
#define OBJIO_AR_invalid_class                  (OBJIO_AR_error_base + 43)
#define OBJIO_AR_already_restored               (OBJIO_AR_error_base + 44)

/** @} */

#include <archive/libarchive_undef.h>
#endif
