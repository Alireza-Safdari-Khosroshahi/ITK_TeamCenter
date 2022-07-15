/**
* Copyright 2020 Siemens Digital Industries Software
* ==================================================
* Copyright 2015.
* Siemens Product Lifecycle Management Software Inc.
* All Rights Reserved.
* ==================================================
* Copyright 2020 Siemens Digital Industries Software
*/


/**
    @file

    TargetMgmt Module Validation Error Codes Declaration

*/

#ifndef TGM0TARGETMGMT_ERRORS_H
#define TGM0TARGETMGMT_ERRORS_H

#include <common/emh_const.h>

/** tgm0targetmgmt module errors */
#define TRG0TARGETMGMT_error_base                                            EMH_TGM0TARGETMANAGEMENT_error_base

/**    An internal error has occurred in the Target Management module. Please report this error to your system administrator. */
#define TGM0TARGETMGMT_internal_error                                        ( EMH_TGM0TARGETMANAGEMENT_error_base + 1 )

/**    The operation could not be performed, because an invalid input object is supplied. Please check the Teamcenter server syslog file for more information. */
#define TGM0TARGETMGMT_invalid_input                                         ( EMH_TGM0TARGETMANAGEMENT_error_base + 2 )

/**    The operation could not be performed, because no AppModel is associated with the Plan "%1$". */
#define TGM0TARGETMGMT_no_appmodel_with_plan                                 ( EMH_TGM0TARGETMANAGEMENT_error_base + 3 )

/**    The Goal attribute property type is not supported for the Target Element getting saved. */
#define TGM0TARGETMGMT_goal_property_not_supported                           ( EMH_TGM0TARGETMANAGEMENT_error_base + 4 )

/**    The Plan "%1$" already contains a target created with the Target definition "%2$". */
#define TGM0TARGETMGMT_multiple_targets_with_same_definition_not_supported   ( EMH_TGM0TARGETMANAGEMENT_error_base + 5 )

#endif
