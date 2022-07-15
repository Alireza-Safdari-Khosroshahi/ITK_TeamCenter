/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Define error codes used for the TcIDCreator in Teamcenter
*/

/*  */

#ifndef TCID_ERRORS_H
#define TCID_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup TCID_ERRORS Errors
    @ingroup TCID
    @{
*/

#define TCID_ERROR_BASE                   EMH_ID_error_base

#define TCID_start_sequence_null         (TCID_ERROR_BASE + 1)
#define TCID_sequence_out_of_range       (TCID_ERROR_BASE + 2)
#define TCID_wrong_sequence              (TCID_ERROR_BASE + 3)
#define TCID_sequence_overflow           (TCID_ERROR_BASE + 4)
#define TCID_bad_start_value             (TCID_ERROR_BASE + 5)
#define TCID_mixed_case                  (TCID_ERROR_BASE + 6)
#define TCID_unable_to_save              (TCID_ERROR_BASE + 7)
#define TCID_unable_to_create            (TCID_ERROR_BASE + 8)
#define TCID_unable_to_assign_digits     (TCID_ERROR_BASE + 9)
#define TCID_unable_to_destroy           (TCID_ERROR_BASE + 10)

/** @} */

#endif
