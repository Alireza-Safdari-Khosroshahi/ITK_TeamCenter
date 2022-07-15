/*
    Copyright 2020 Siemens Digital Industries Software
    ==================================================
    Copyright 2016.
    Siemens Product Lifecycle Management Software Inc.
    All Rights Reserved.
    ==================================================
    Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    Error codes that are used by the Cpc0cpdcm module

*/

#ifndef TEAMCENTER_CPC0CPDCM_ERRORS_H
#define TEAMCENTER_CPC0CPDCM_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup CPC0CPDCM_ERRORS Change Management for 4GD Errors
    @ingroup CPC0CPDCM
    @{
*/

/**
 * The Workset "%1$" cannot be related to the Engineering Change Notice (ECN) "%2$", because it has contents from ECNs that are not concurrent to the ECN "%2$".
 */
#define CPC0CPDCM_relation_creation_not_allowed            (EMH_CPC0CPDCM_error_base + 0)

/**
 * The subset cannot be created in the Workset "%1$", because the Engineering Change Notice (ECN) "%2$" associated with the subset is not concurrent to the ECN "%3$" of the Workset "%1$".
 */
#define CPC0CPDCM_subset_creation_not_allowed              (EMH_CPC0CPDCM_error_base + 1)

/**
 * The Design Element "%1$" is not allowed in the subset "%2$", because the associated Engineering Change Notice (ECN) "%3$" of "%1$" is not concurrent to the ECN "%4$" of the Workset "%5$".
 */
#define CPC0CPDCM_subset_content_not_allowed               (EMH_CPC0CPDCM_error_base + 2)

/**
    @}
*/

#endif
