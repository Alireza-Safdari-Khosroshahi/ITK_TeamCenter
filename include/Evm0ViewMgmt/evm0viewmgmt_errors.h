/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2019.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

#ifndef EVM0VIEWMGMT_ERRORS_H
#define EVM0VIEWMGMT_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup EVM0VIEWMGMT_ERRORS Errors
    @ingroup EVM0VIEWMGMT
    @{
*/

/**
    The query string does not specify the needed input objects for the "%1$" class with "%2$" alias.
*/
#define EVM0VIEWMGMT_missing_query_input_objs         ( EMH_EVM0VIEWMGMT_error_base + 1 )

/**
     The query string could not be parsed because its syntax is incorrect.
*/
#define EVM0VIEWMGMT_failed_to_parse_query_string     ( EMH_EVM0VIEWMGMT_error_base + 2 )

/**
    A Recipe with the name "%1$" already exists.
*/
#define EVM0VIEWMGMT_recipe_already_exists            ( EMH_EVM0VIEWMGMT_error_base + 3 )

/**
    The closure rule "%1$" does not exist in the database. Please import it and try again.
*/
#define EVM0VIEWMGMT_closurerule_not_exist            ( EMH_EVM0VIEWMGMT_error_base + 4 )

/** @} */

#endif
