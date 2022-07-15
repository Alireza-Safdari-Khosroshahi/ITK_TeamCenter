/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Include file to define errors for AuditManager module 
*/

/*  */

#ifndef AUDITMGR_ERRORS_H
#define AUDITMGR_ERRORS_H

#include <common/emh_const.h>
#include <sa/libsa_exports.h>

/**
    @defgroup AUDITMGR_ERRORS Audit Manager Errors
    @ingroup AUDITMGR
    @{
*/

#define AUDITMGR_INVALID_OBJECT                   (EMH_AUDITMGR_error_base + 0)
#define AUDITMGR_INVALID_EVENT                    (EMH_AUDITMGR_error_base + 1)
#define AUDITMGR_DUPLICATE_DEF                    (EMH_AUDITMGR_error_base + 2)
#define AUDITMGR_NO_READ                          (EMH_AUDITMGR_error_base + 3)
#define AUDITMGR_NO_DELETE                        (EMH_AUDITMGR_error_base + 4)
#define AUDITMGR_IS_DISABLED                      (EMH_AUDITMGR_error_base + 5)
#define AUDITMGR_MISSING_OBJECT_TYPE              (EMH_AUDITMGR_error_base + 6)
#define AUDITMGR_INVALID_OBJECT_TYPE              (EMH_AUDITMGR_error_base + 7)
#define AUDITMGR_MISSING_OBJECT_CLASS             (EMH_AUDITMGR_error_base + 8)
#define AUDITMGR_INVALID_OPERATOR                 (EMH_AUDITMGR_error_base + 9)
#define AUDITMGR_UNDEF_AUDIT                      (EMH_AUDITMGR_error_base + 10)
#define AUDITMGR_TOO_MANY_COND                    (EMH_AUDITMGR_error_base + 11) 
#define AUDITMGR_NO_TABLE                         (EMH_AUDITMGR_error_base + 12)
#define AUDITMGR_INVALID_NUMERIC_INPUT            (EMH_AUDITMGR_error_base + 13)


/** @} */

#include <sa/libsa_undef.h>

#endif

