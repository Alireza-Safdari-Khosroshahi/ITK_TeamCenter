/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Site Mananagement Errors
*/

/*  */

#ifndef SITE_ERRORS_H
#define SITE_ERRORS_H

#include <common/emh_const.h>
/**
    @defgroup SITE_ERRORS Errors
    @ingroup SITE
    @{
*/

#define SITE_NO_SUCH_SITE       (EMH_SITE_error_base +   0)
#define SITE_NO_DATA            (EMH_SITE_error_base +   1)
#define SITE_FINDING_SITES      (EMH_SITE_error_base +   2)
#define SITE_INV_SITE_NAME      (EMH_SITE_error_base +   3)
#define SITE_LOG_IN_USE         (EMH_SITE_error_base +   4)
#define SITE_NO_SELECTION       (EMH_SITE_error_base +   5)
#define SITE_NO_CREATE          (EMH_SITE_error_base +   6)
#define SITE_NO_SAVE            (EMH_SITE_error_base +   7)
#define SITE_DEFAULT_ODS_ERROR  (EMH_SITE_error_base +   8)
#define SITE_NOT_SEARCHABLE     (EMH_SITE_error_base +   9)
#define SITE_NOT_ODS_CAPABLE    (EMH_SITE_error_base +  10)
#define SITE_UNAUTHORIZED_ODS   (EMH_SITE_error_base +  11)
#define SITE_HUB_NOT_DEFINED    (EMH_SITE_error_base +  12)

/**
  No "%1$" license is available.
*/
#define SITE_LIC_NOT_AVAILABLE              (EMH_SITE_error_base +  13)

/**
  The site license token is invalid. Please contact the administrator.
*/
#define SITE_LIC_INVALID_TOKEN              (EMH_SITE_error_base +  14)

/**
  Site licenses cannot be revoked within 30 days after assignment.
*/
#define SITE_LIC_REVOKE_BLOCKED             (EMH_SITE_error_base +  15)

/**
  The site license information is corrupted. Please contact the administrator.
*/
#define SITE_LIC_INVALID_STAMP              (EMH_SITE_error_base +  16)

/**
  The license "%2$" is not assigned to the site "%1$".
*/
#define SITE_LIC_NOT_ASSIGNED               (EMH_SITE_error_base +  17)

/**
  Local Teamcenter site cannot be marked as unmanaged site.
*/
#define SITE_LOCAL_UNMANAGED_ERROR          (EMH_SITE_error_base +  18)

/**
  Please provide a valid Site name.
*/
#define SITE_NO_NAME                        (EMH_SITE_error_base + 19)

/**
  Please provide a valid Site ID.
*/
#define SITE_NO_ID                          (EMH_SITE_error_base + 20)

/**
  The Site requires additional attributes to enable "Briefcase Browser Plugin". Please check to make sure that the following attributes are enabled for this site: "uses tcxml", "is offline", "is an unmanaged site", "briefcase browser enabled".
*/
#define SITE_BBPLUGIN_MISSING_ATTRIBUTE     (EMH_SITE_error_base + 21)

/**
  The Site requires additional attributes to enable "Briefcase Browser". Please check to make sure that the following attributes are enabled for this site: "uses tcxml", "is offline", "is an unmanaged site".
*/
#define SITE_BB_MISSING_ATTRIBUTE           (EMH_SITE_error_base + 22)

/**
  The Site requires additional attributes to enable "Unmanaged". Please check to make sure that the following attributes are enabled for this site: "uses tcxml", "is offline".
*/
#define SITE_UNMANAGED_MISSING_ATTRIBUTE    (EMH_SITE_error_base + 23)

/**
  The Site requires additional attributes to enable "Offline". Please check to make sure that the following attribute is enabled for this site: "uses tcxml".
*/
#define SITE_OFFLINE_MISSING_ATTRIBUTE      (EMH_SITE_error_base + 24)

/**
  The Site requires additional attributes to enable "Replicate Delete". Please check to make sure that the following attribute is enabled for this site: "uses tcxml".
*/
#define SITE_REPLICA_MISSING_ATTRIBUTE      (EMH_SITE_error_base + 25)

/**
  A Site with name "%1$" already exists.
*/
#define SITE_FAILED_TO_SET_NAME             (EMH_SITE_error_base + 26)

/** @} */

#endif

