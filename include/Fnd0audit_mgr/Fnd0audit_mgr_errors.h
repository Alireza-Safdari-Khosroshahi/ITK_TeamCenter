/*==============================================================================
    Copyright 2011.
    Siemens Product Lifecycle Management Software Inc.
    All Rights Reserved.
 ==============================================================================*/
/*  */

#ifndef FND0AUDIT_MGR_ERRORS_H
#define FND0AUDIT_MGR_ERRORS_H

#include <common/emh_const.h>
#include <Fnd0audit_mgr/libFnd0audit_mgr_exports.h>

/**
    @defgroup FND0AUDIT_MGR_ERRORS FND0AUDIT_MGR Errors
    @ingroup FND0AUDIT_MGR
    @{
*/

#define FND0AUDIT_MGR_ERROR_BASE                                EMH_FND0AUDIT_MGR_error_base

/** Audit defintion not found */
#define FND0AUDIT_MGR_undef_audit                               (FND0AUDIT_MGR_ERROR_BASE + 1)

/** The container object for audit nearline archive was not created. */
#define FND0AUDIT_MGR_archive_create_failed                     (FND0AUDIT_MGR_ERROR_BASE + 2)

/** The search criteria on the container object for audit nearline archive is invalid. */
#define FND0AUDIT_MGR_archive_invalid_search_criteria           (FND0AUDIT_MGR_ERROR_BASE + 3)

/** Audit logs were not found for the given input criteria. */
#define FND0AUDIT_MGR_archive_audit_logs_not_found               (FND0AUDIT_MGR_ERROR_BASE + 4)

/** @} */

#include <Fnd0audit_mgr/libFnd0audit_mgr_undef.h>
#endif

