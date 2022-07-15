/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Appearance Group errors.
*/

/*  */

#ifndef APPGRP_ERRORS_H
#define APPGRP_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup APPGRP_ERRORS Errors
    @ingroup APPGRP
    @{
*/

/** Failed to initialize appearance group during creation stage */
#define APPGRP_fail_to_initialize                   (EMH_APPGRP_error_base + 1)

#define APPGRP_fail_to_save                         (EMH_APPGRP_error_base + 2)

/** Unable to create relation between Appearance root and Appearance Group root */
#define APPGRP_fail_to_create_relation              (EMH_APPGRP_error_base + 3)

/** Unable to find the relation type IMAN_AppGroup_Root */
#define APPGRP_fail_to_find_relation_type           (EMH_APPGRP_error_base + 4)

/** Unable to save the relation IMAN_AppGroup_Root */
#define APPGRP_fail_to_save_relation                (EMH_APPGRP_error_base + 5)

/** Wrong parent class */
#define APPGRP_wrong_parent                         (EMH_APPGRP_error_base + 6)

/** Unable to find appearance root */
#define APPGRP_appearance_root_not_found            (EMH_APPGRP_error_base + 7)

/** Need to pass in appearance group */
#define APPGRP_appGroup_needed                      (EMH_APPGRP_error_base + 8)

/** Input object is already in list */
#define APPGRP_object_in_list                       (EMH_APPGRP_error_base + 9)

/** Not an appearance group */
#define APPGRP_invalid_appearance_group_to_add      (EMH_APPGRP_error_base + 10)

/** Cannot add an apn object with from different context */
#define APPGRP_invalid_APN_to_add                   (EMH_APPGRP_error_base + 11)

/** Unable to create GCR relation type */
#define APPGRP_fail_to_create_relation_type         (EMH_APPGRP_error_base + 12)

/** Not an APN object */
#define APPGRP_APN_needed                           (EMH_APPGRP_error_base + 13)
/** cannot add topAPN to occurrence group */
#define APPGRP_top_apn_not_allowed                  (EMH_APPGRP_error_base + 14)

/** @} */

#endif

