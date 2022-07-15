/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    EPM Access Control
*/

/*  */

#ifndef EPM_ACCESS_CONTROL_H
#define EPM_ACCESS_CONTROL_H

#include <epm/epm.h>
#include <epm/libepm_exports.h>

/**
    @defgroup EPM_ACCESS_CONTROL Access Control
    @ingroup EPM
    @{
*/

/**
    @name Access masks
    
    Formerly part of the old AM, but EPM uses them for its own purposes
    @{
*/
#define AM_NO_ACCESS_MASK   0
#define AM_DELETE_MASK      ( 1 << 0 )
#define AM_CHANGE_MASK      ( 1 << 1 )
#define AM_WRITE_MASK       ( 1 << 2 )
#define AM_READ_MASK        ( 1 << 3 )
#define AM_COPY_MASK        ( 1 << 4 )
#define AM_PROMOTE_MASK     ( 1 << 5 )
#define AM_DEMOTE_MASK      ( 1 << 6 )
/** @} */

typedef struct TC_access_control_s{
    char*      role_name;
    char*      group_name;
    logical    allow_sub_groups;
    int        access_codes;
} TC_access_control_t;

typedef struct TC_access_control_list_s{
    int                     count;
    TC_access_control_t*  controls;
} TC_access_control_list_t;

typedef struct TC_reviewer_s{
    char*      role_name;
    char*      group_name;
    logical    allow_sub_groups;
} TC_reviewer_t;

typedef struct TC_reviewer_team_s{
    int                 count;
    TC_reviewer_t*    reviewers;
} TC_reviewer_team_t;

#define EPM_accessor_equal( ac1, ac2 )                          \
(                                                               \
    (                                                           \
        ( ac1.allow_sub_groups && ac2.allow_sub_groups ) ||     \
        ( ! ac1.allow_sub_groups && ! ac2.allow_sub_groups )    \
    ) &&                                                        \
    strcmp( ac1.role_name, ac2.role_name ) == 0 &&              \
    strcmp( ac1.group_name, ac2.group_name ) == 0               \
)

/** @if DOX_IGNORE
    (JB)  30-Oct-1995  Removed EPM_access_codes_e
@endif */

/** @} */

#include <epm/libepm_undef.h>
#endif
