/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    LM defines
*/

/*  */

#include <common/emh_const.h>
#include <tc/tc_startup.h>

/**
    The log manager module has been deprecated as of Tc11.  This functionality will be removed in Tc13.
*/

/**
    @defgroup LOG Defines
    @ingroup LM
    @{
*/

/**
    @name General events
    @{
*/
#define LM_STARTUP              1000
#define LM_SHUTDOWN              1001
/** @} */

/**
    @name Object events
    @{
*/
#define LM_CREATE                   2000
#define LM_READ               2001
#define LM_MODIFY              2002
#define LM_DELETE              2003
#define LM_PURGE              2004
#define LM_ARCHIVED              2005
#define LM_RESTORED              2006
#define LM_RESERVED              2007
#define LM_UNRESERVED             2008
#define LM_SUBMITTED             2009
#define LM_FROZE              2010
#define LM_UNFROZE              2011
#define LM_IMPORTED              2012
#define LM_EXPORTED              2013
#define LM_MOVE               2014
#define LM_GRANT_ACCESS          2015
#define LM_REVOKE_ACCESS         2016
#define LM_EVENT_CREATED            2017
#define LM_EVENT_TAKEN_FROM_QUEUE   2018
#define LM_EVENT_HANDLER_CALLED     2019
#define LM_EVENT_HANDLER_SPAWNED    2020
#define LM_EVENT_RETRIED            2021
#define LM_EVENT_DELETED            2022
#define LM_EVENT_ERROR              2023
#define LM_EVENT_SKIPPED            2024
#define LM_EVENT_INFO               2025
#define LM_GMS_IMPORT               2026
#define LM_GMS_EXPORT               2027
#define LM_GMS_DELETE_REPLICA       2028
#define LM_GMS_SYNC_STATUS          2029
#define LM_GMS_OWNERSHIP_TRANSFER   2030
/** @} */

/**
    @name System events
    @{
*/
#define LM_INTERNAL_ERROR         3200
#define LM_DATA_ERROR          3201
#define LM_INVALID_TAG          3202
#define LM_EXCEPTION          3203
/** @} */

/**
    @name Security events
    @{
*/
#define LM_LOGIN                    4000
#define LM_LOGOUT                   4001
#define LM_BREAKIN                  4002
#define LM_ACCESS_VIOLATION         4003
/** @} */

/**
    @name User events
    @{
*/
#define LM_USER_EVENT_1             9001
#define LM_USER_EVENT_2             9002
/** @} */

/**
    @name Errors
    @{
*/
#define LM_NOT_INITIALIZED          (EMH_LM_error_base + 101)
#define LM_INVALID_FILE             (EMH_LM_error_base + 102)
#define LM_NO_LOG_FILE              (EMH_LM_error_base + 103)
#define LM_LOG_BUSY                 (EMH_LM_error_base + 104)
#define LM_PERMISSION_DENIED        (EMH_LM_error_base + 105)
#define LM_BUSY                     (EMH_LM_error_base + 106)
/** @} */

/** @} */
