/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2014.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    USER EXIT specific Message definitions for me. As per customization guidelines
      we are supposed to have our own user exit functions encapsulated per module.

*/

/*  */

#ifndef ME_BMF_USER_EXIT_MSG_H
#define ME_BMF_USER_EXIT_MSG_H

/**
    @defgroup ME_USER_EXIT_MSG User exit messages for mbom creation
    @ingroup USER_EXIT
    @{
*/

/*  */
/** Message name to be keyed off of in BMIDE for adding user exit for creation of MBOM node.*/
#define BMF_ITEM_create_or_ref_id_msg                       "BMF_ITEM_create_or_ref_id"

/** Message name to be keyed off of in BMIDE for adding user exit for synchronization of MBOM node.*/
#define BMF_ITEM_sync_msg                                   "BMF_ITEM_sync"

/** Message name to be keyed off of in BMIDE for adding user exit for determining equivalent MBOM node.*/
#define BMF_ITEM_find_eqv_line_msg                          "BMF_ITEM_find_eqv_line"

/** Message name to be keyed off of in BMIDE for adding user exit for getting the action on released MBOM node.*/
#define BMF_ITEM_action_on_release_msg                      "BMF_ITEM_action_on_release"

/** Message name to be keyed off of in BMIDE for adding user exit for finding candidate EBOM lines.*/
#define BMF_BOMLINE_find_candidates_msg                      "BMF_BOMLINE_find_candidates"

/** Message name to be keyed off of in BMIDE for adding user exit for repairing MBOM lines.*/
#define BMF_BOMLINE_repair_bomlines_msg                      "BMF_BOMLINE_repair_bomlines"

/** Message name to be keyed off of in BMIDE for adding user exit for finding target Station in PlantBOP for a process or operation in classic bop.*/
#define BMF_BOPLINE_find_target_stations_msg                 "BMF_BOPLINE_find_target_stations"

/** @} */

#endif
