/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2019.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file
    USER EXIT specific Message definitions for structure clone.
*/

#ifndef BOM_CLONE_BMF_USER_EXIT_MSG_H
#define BOM_CLONE_BMF_USER_EXIT_MSG_H
#include <common/tc_deprecation_macros.h>
/**
    @defgroup STRUCTURE_CLONE_BMF_USER_EXIT_MSG User exit messages for structure clone
    @ingroup USER_EXIT
    @{
*/

/** Message name to be keyed off of in BMIDE for adding user exit for getting clone action for a BOMLine.*/
#define BMF_USER_bom_clone_get_clone_action_msg                     "BMF_USER_bom_clone_get_clone_action"

/** 
    @deprecated #BMF_USER_bom_clone_process_cloned_structure_msg deprecated in Teamcenter 12.3. Use #BMF_USER_bomline_process_cloned_structure_msg instead.

    Message name to be keyed off of in BMIDE for adding user exit for processing cloned objects after clone operation is complete.
*/
#define BMF_USER_bom_clone_process_cloned_structure_msg             "BMF_USER_bom_clone_process_cloned_structure"
TC_DEPRECATED_PREPROCESSOR( "12.3", BMF_USER_bom_clone_process_cloned_structure_msg, "BMF_USER_bomline_process_cloned_structure_msg" )

/** Message name to be keyed off of in BMIDE for adding user exit for processing cloned objects after clone operation is complete.*/
#define BMF_USER_bomline_process_cloned_structure_msg               "BMF_USER_bomline_process_cloned_structure"

/** @} */

#endif
