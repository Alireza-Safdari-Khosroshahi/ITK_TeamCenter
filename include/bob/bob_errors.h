#ifndef BOB_ERRORS_H
#define BOB_ERRORS_H

/*
/  @<COPYRIGHT_START>@
/  ===============================================
/  Copyright 2006 UGS Corp. All Rights Reserved.
/  ===============================================
/  @<COPYRIGHT_END>@
*/

/** 
    @file 

    Teamcenter::Bob errors include file.

*/


#include <common/emh_const.h>

/**
    @defgroup BOB_ERRORS BOB Errors
    @ingroup BOB
    @{
*/

#define BOB_internal_error                          (EMH_BOB_error_base +   0)
#define BOB_invalid_tag                             (EMH_BOB_error_base +   1)

/** All input Appearance Path Nodes must belong to same Appearance Path Root.*/
#define BOB_apns_belong_to_different_apr            (EMH_BOB_error_base +   2)

/** No scope Apprearance Path Node found for the given scope BOM line.*/
#define BOB_no_scope_apn_found                      (EMH_BOB_error_base +   3)

/* BOB Property Errors : 100-199 */
#define BOB_invalid_property_name                   (EMH_BOB_error_base + 100)
#define BOB_invalid_property_type                   (EMH_BOB_error_base + 101)
#define BOB_invalid_property_index                  (EMH_BOB_error_base + 102)
#define BOB_no_uif_values                           (EMH_BOB_error_base + 103)
#define BOB_no_real_values                          (EMH_BOB_error_base + 104)

/** @} */

#endif
