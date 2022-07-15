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
    @file imagecompression_errors.h

    Error codes for ImageCompression module.

*/

#ifndef IMAGECOMPRESSION_ERRORS_H
#define IMAGECOMPRESSION_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup IMAGECOMPRESSION_ERRORS Image Compression Errors
    @ingroup  IMAGECOMPRESSION
    @{
*/

/**
    The input dataset cannot be NULL.
*/
#define IMAGECOMPRESSION_error_dataset_nulltag                                   ( EMH_IMAGECOMPRESSION_error_base + 1 )

/**
    The input object must be a Dataset.
*/
#define IMAGECOMPRESSION_error_input_not_dataset                                 ( EMH_IMAGECOMPRESSION_error_base + 2 )

/**
    The input Dataset is invalid because either it does not exist or it is deleted.
*/
#define IMAGECOMPRESSION_error_invalid_dataset                                   ( EMH_IMAGECOMPRESSION_error_base + 3 )

/**
     The image compression functionality is not enabled, because the preference "TC__image_compression_enabled" is not set to "true".
*/
#define IMAGECOMPRESSION_error_imagecompression_not_enabled                      ( EMH_IMAGECOMPRESSION_error_base + 4 )

/**
    The input Dataset "%1$" does not contain any valid Named Reference. Please see the preference "TC__thumbnail_dataset_type_order" for valid Dataset NamedReferences for the image translation.
*/
#define IMAGECOMPRESSION_error_dataset_invalid_named_reference                    ( EMH_IMAGECOMPRESSION_error_base + 5 )

/**
    The values specified in the preference "TC__image_compression_types" are not valid. Please contact your system administrator.
*/
#define IMAGECOMPRESSION_error_invalid_imagetype_pref_value                      ( EMH_IMAGECOMPRESSION_error_base + 6 )


/**
    No value is specified for the BMIDE constant "Fnd0ImageTranslationSupportedPrimaryTypes". Please report this error to your system administrator.
*/
#define IMAGECOMPRESSION_error_primary_constant_not_set                          ( EMH_IMAGECOMPRESSION_error_base + 7 )

/**
   None of the primary object types associated with the Dataset "%1$" is valid according to the BMIDE constant "Fnd0ImageTranslationSupportedPrimaryTypes". Valid types are: %2$.
*/
#define IMAGECOMPRESSION_error_invalid_primary_type                              ( EMH_IMAGECOMPRESSION_error_base + 8 )

/**
    At least one Dataset must be provided.
*/
#define IMAGECOMPRESSION_error_invalid_dataset_length                            ( EMH_IMAGECOMPRESSION_error_base + 9 )

/** @} */

#endif
