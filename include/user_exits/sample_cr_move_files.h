/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*  */

#ifndef SAMPLE_CR_MOVE_FILES_H
#define SAMPLE_CR_MOVE_FILES_H

#include <epm/epm.h>

#define FLRELDIR  "/usr/tmp/released"

#include <user_exits/libuser_exits_exports.h>

int startup_ITK_environment     (void);
int shutdown_ITK_environment    (void);
int find_released_objects();
int relocate_released_dataset_file(tag_t jobtag);

#ifdef __cplusplus
    extern "C"{
#endif


extern USER_EXITS_API int SMP_relocate_file_handler(EPM_action_message_t msg);

#ifdef __cplusplus
}
#endif

#include <user_exits/libuser_exits_undef.h>

#endif
