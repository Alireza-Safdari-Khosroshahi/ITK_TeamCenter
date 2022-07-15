/*
   ===============================================
   Copyright 2006 UGS Corp. All Rights Reserved.
   ===============================================
*/

/**
    @file

    ITK API for Appearance Group class.
*/

#ifndef APPGRP_H
#define APPGRP_H

#include <unidefs.h>

#include <ps/libps_exports.h>

/**
    @defgroup APPGRP Appearance Group
    @ingroup PS
    @{
*/

#define AppearanceGroupClassName            "AppearanceGroup"
#define AppearanceGroupRootRelation         "IMAN_AppGroup_Root"
#define AppearanceGroupItemRelation         "IMAN_AppGroup_Item"
#define AppearanceGroup_private_type_name_c "PrivateAppGrp"

#ifdef __cplusplus
    extern "C"{
#endif

extern PS_API int APPGRP_create_appearance_group(
    tag_t         appearanceRoot,   /**< (I) */
    const char*   type,             /**< (I) */
    const char*   name,             /**< (I) */
    const char*   desc,             /**< (I) */
    tag_t*        appGroupTag       /**< (O) */
    );

extern PS_API int APPGRP_create_appearance_group_with_search_criteria(
    tag_t         pathRoot,         /**< (I) */
    tag_t         search_criteria,  /**< (I) */
    const char*   type,             /**< (I) */
    const char*   name,             /**< (I) */
    const char*   desc,             /**< (I) */
    tag_t*        appGroupTag       /**< (O) */
    );

extern PS_API int APPGRP_set_search_criteria(
    tag_t         thisTag,          /**< (I) */
    tag_t         search_criteria   /**< (I) */
    );

extern PS_API int APPGRP_get_search_criteria(
    tag_t         thisTag,          /**< (I) */
    tag_t*        search_criteria   /**< (O) */
    );

extern PS_API int APPGRP_ask_root_item_and_bv(
    tag_t         thisTag,          /**< (I) */
    tag_t*        tracked_item,     /**< (O) */
    tag_t*        tracked_bv        /**< (O) */
    );

extern PS_API int APPGRP_re_evaluate_members(
    tag_t         thisTag,                      /**< (I) */
    tag_t         bom_window,                   /**< (I) */
    tag_t         config_context_tag,           /**< (I) */
    int*          n_bomlines,                   /**< (O) */
    tag_t**       bomlines,                     /**< (O) */
    int*          n_unconfigured_bomlines,      /**< (O) */
    tag_t**       unconfigured_bomlines,        /**< (O) */
    int*          n_unconfigurable_bomlines,    /**< (O) */
    tag_t**       unconfigurable_bomlines       /**< (O) */
    );

extern PS_API int APPGRP_remove_appearance(
    tag_t         thisTag,          /**< (I) */
    tag_t         appearanceTag     /**< (I) */
    );

extern PS_API int APPGRP_remove_appearance_group(
    tag_t         thisTag,      /**< (I) */
    tag_t         appGroupTag   /**< (I) */
    );

extern PS_API int APPGRP_add_appearance(
    tag_t         thisTag,          /**< (I) */
    tag_t         appearanceTag     /**< (I) */
    );

extern PS_API int APPGRP_add_appearance_group(
    tag_t         thisTag,          /**< (I) */
    tag_t         appGroupTag       /**< (I) */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <ps/libps_undef.h>

#endif
