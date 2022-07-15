#ifndef FCLASSES_ERRORS_H
#define FCLASSES_ERRORS_H

/*
/  @<COPYRIGHT_START>@
/  ===============================================
/  Copyright 2006 UGS Corp. All Rights Reserved.
/  ===============================================
/  @<COPYRIGHT_END>@
*/

/**
    @file

    Teamcenter::Bob errors include file.

*/


#include <common/emh_const.h>
#include <fclasses/libfclasses_exports.h>

/**
    @defgroup FCLASSES_ERRORS FCLASSES Errors
    @ingroup FCLASSES
    @{
*/

/**
 * An internal error has occurred while acquiring lock for given object. Please contact your system administrator for further analysis.
 */
#define FCLASSES_internal_error                          (EMH_FCLASSES_error_base +   0)
#define FCLASSES_PomQueryLite_internal_error             (EMH_FCLASSES_error_base +   1)
#define FCLASSES_PomQueryLite_invalid_query              (EMH_FCLASSES_error_base +   2)
#define FCLASSES_PomQueryLite_invalid_type               (EMH_FCLASSES_error_base +   3)
#define FCLASSES_PomQueryLite_invalid_column             (EMH_FCLASSES_error_base +   4)
#define FCLASSES_PomQueryLite_invalid_row                (EMH_FCLASSES_error_base +   5)
#define FCLASSES_PomQueryLite_invalid_null               (EMH_FCLASSES_error_base +   6)
#define FCLASSES_error_in_polling_setup                  (EMH_FCLASSES_error_base +   7)
#define FCLASSES_error_in_polling_execute                (EMH_FCLASSES_error_base +   8)

/**
 * The allocator for the shared memory storage file "%1$" cannot be set, so the
 * system cannot use shared memory for the "%2$" domain.
 * Please report this error to your system administrator.
 */
#define FCLASSES_cannot_set_backing_store_allocator      (EMH_FCLASSES_error_base +  20)

/**
 * An error has occurred during the initialization of the shared memory for the
 * "%1$" domain, so the system cannot use shared memory for the "%1$" domain.
 * Please report this error to your system administrator.
 */
#define FCLASSES_cannot_initialize_shared_memory         (EMH_FCLASSES_error_base +  21)

/**
 * An error has occurred during the population of the shared memory for the
 * "%1$" domain, so the system cannot use shared memory for the "%1$" domain.
 * Please report this error to your system administrator.
 */
#define FCLASSES_cannot_load_shared_memory               (EMH_FCLASSES_error_base +  22)

/**
 * An error has occurred while marking the shared memory as initialized for the
 * "%1$" domain, so the system cannot use shared memory for the "%1$" domain.
 * Please report this error to your system administrator.
 */
#define FCLASSES_cannot_mark_init_shared_memory          (EMH_FCLASSES_error_base +  23)

/**
 * An error has occurred while writing the shared memory storage file for the
 * "%1$" domain. Please contact your system administrator to delete the shared
 * memory storage directory "%2$" to repair this problem.
 */
#define FCLASSES_cannot_synchronize_shared_memory        (EMH_FCLASSES_error_base +  24)

/**
 * An error has occurred while creating the shared memory pool lock for the
 * "%1$" domain, so the system cannot use shared memory for the "%1$" domain.
 * Please report this error to your system administrator.
 */
#define FCLASSES_cannot_create_pool_lock                 (EMH_FCLASSES_error_base +  25)

/**
 * The environment variable "TC_SHARED_MEMORY_DIR" is not set.
 * Please contact your system administrator to set this variable in order to
 * use shared memory.
 */
#define FCLASSES_env_not_set                             (EMH_FCLASSES_error_base +  26)

/**
 * The following shared memory directory cannot be created: %1$.
 * The system cannot use shared memory for the "%2$" domain.
 * Please report this error to your system administrator.
 */
#define FCLASSES_error_set_backing_store_directory       (EMH_FCLASSES_error_base +  27)

/**
 * An error has occurred while acquiring the mutex for the segment "%1$-%2$".
 * This is probably caused by insufficient system resources.
 * Please report this to your system administrator.
 */
#define FCLASSES_mutex_unavailable                       (EMH_FCLASSES_error_base +  28)

/** @} */

#include <fclasses/libfclasses_undef.h>
#endif
