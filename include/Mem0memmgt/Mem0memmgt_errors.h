/* Copyright 2020 Siemens Digital Industries Software
 ==================================================
 Copyright 2015
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2020 Siemens Digital Industries Software */

/**
    @file

    This file contains the error codes of Mem0memmgt

*/

#ifndef MEM0MEMMGT_ERRORS_H
#define MEM0MEMMGT_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup MEM0MEMMGT_ERRORS Errors
    @ingroup MEM0MEMMGT
    @{
*/
#define MEM0MEMMGT_ERROR_BASE                                           EMH_MEM0MEMMGT_error_base

#define MEM0MEMMGT_validate_license_failed                              (MEM0MEMMGT_ERROR_BASE + 1)
#define MEM0MEMMGT_invalid_hex_string                                   (MEM0MEMMGT_ERROR_BASE + 2)
#define MEM0MEMMGT_error_set_start_address_failed                       (MEM0MEMMGT_ERROR_BASE + 3)
#define MEM0MEMMGT_error_set_header_object_failed                       (MEM0MEMMGT_ERROR_BASE + 4)
#define MEM0MEMMGT_error_set_trailer_object_failed                      (MEM0MEMMGT_ERROR_BASE + 5)
#define MEM0MEMMGT_error_set_memory_records_failed                      (MEM0MEMMGT_ERROR_BASE + 6)
#define MEM0MEMMGT_error_set_memory_blocks_failed                       (MEM0MEMMGT_ERROR_BASE + 7)
#define MEM0MEMMGT_error_set_memory_content_failed                      (MEM0MEMMGT_ERROR_BASE + 8)
#define MEM0MEMMGT_error_set_size_failed                                (MEM0MEMMGT_ERROR_BASE + 9)
#define MEM0MEMMGT_error_set_mirrored_offset_failed                     (MEM0MEMMGT_ERROR_BASE + 10)
#define MEM0MEMMGT_error_set_offset_address_failed                      (MEM0MEMMGT_ERROR_BASE + 11)
#define MEM0MEMMGT_error_set_attribute_failed                           (MEM0MEMMGT_ERROR_BASE + 12)
#define MEM0MEMMGT_error_set_memory_type_failed                         (MEM0MEMMGT_ERROR_BASE + 13)
#define MEM0MEMMGT_error_set_prg_type_failed                            (MEM0MEMMGT_ERROR_BASE + 14)
#define MEM0MEMMGT_invalid_object_tag                                   (MEM0MEMMGT_ERROR_BASE + 15)
#define MEM0MEMMGT_error_invalid_size                                   (MEM0MEMMGT_ERROR_BASE + 16)
#define MEM0MEMMGT_copy_mem0memorycontent_obj_failed                    (MEM0MEMMGT_ERROR_BASE + 17)
#define MEM0MEMMGT_copy_mem0memorylayoutrevision_obj_failed             (MEM0MEMMGT_ERROR_BASE + 18)
#define MEM0MEMMGT_copy_mem0memoryblock_obj_failed                      (MEM0MEMMGT_ERROR_BASE + 19)
#define MEM0MEMMGT_copy_mem0memoryrecord_obj_failed                     (MEM0MEMMGT_ERROR_BASE + 20)
#define MEM0MEMMGT_error_set_block_name_failed                          (MEM0MEMMGT_ERROR_BASE + 21)
#define MEM0MEMMGT_empty_block_name_failed                              (MEM0MEMMGT_ERROR_BASE + 22)
#define MEM0MEMMGT_duplicated_block_name_failed                         (MEM0MEMMGT_ERROR_BASE + 23)
#define MEM0MEMMGT_duplicated_offset_address_failed                     (MEM0MEMMGT_ERROR_BASE + 24)
#define MEM0MEMMGT_duplicated_memorylayout_start_address_failed         (MEM0MEMMGT_ERROR_BASE + 25)
#define MEM0MEMMGT_duplicated_memoryblock_start_address_failed          (MEM0MEMMGT_ERROR_BASE + 26)

/** @} */

#endif
