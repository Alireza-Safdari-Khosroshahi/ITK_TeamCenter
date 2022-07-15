/* Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2017.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/
/**
    @file
        BOMLITE errors
*/
#ifndef TEAMCENTER_BOMLITE_ERRORS_HXX
#define TEAMCENTER_BOMLITE_ERRORS_HXX

#include <common/emh_const.h>

/**
    @defgroup FND0BOMLITE_ERRORS BOMLite Errors
    @ingroup BOMLite
    @{
*/

/**    An internal error has occurred in the BOMLite module: %1$. Please report this error to your system administrator.*/
#define BOMLITE_internal_error                               (EMH_BOMLITE_error_base +   1)

/**    The BOMLite configuration does not support the "%1$" feature. Please report this error to your system administrator.*/
#define BOMLITE_feature_unsupported                          (EMH_BOMLITE_error_base +   2)

/**    The 150% Configuration is not supported because either flag Show Unconfigured Variants or Occurrence Effectivity are unchecked.*/
#define BOMLITE_expand_unsuccessful                          (EMH_BOMLITE_error_base +   3)

/**    The object "%1$" is not a BOM Line Light type.*/
#define BOMLITE_invalid_input_tag                            (EMH_BOMLITE_error_base +   4)

/**    The input BOM Line Light objects must be from the same BOM Window.*/
#define BOMLITE_objects_from_different_windows               (EMH_BOMLITE_error_base +   5)

/**    There are multiple BOM Line Light objects from the same hierarchy.*/
#define BOMLITE_objects_in_same_hierarchy                    (EMH_BOMLITE_error_base +   6)

/**    Unable to convert BOM Line Light object to BOM Line object.*/
#define BOMLITE_conversion_unsuccessful                      (EMH_BOMLITE_error_base +   7)

/**
    @}
*/
#endif
