/*==============================================================================
                             Copyright (c) 2016 Siemens PLM Software
                             Unpublished - All rights reserved
 ==============================================================================*/

/**
    @file
    This header file declares public APIs to be used for ImageCompression module.
*/

#ifndef IMAGECOMPRESSION_H
#define IMAGECOMPRESSION_H

#include <string>
#include <unidefs.h>
#include <imagecompression/libimagecompression_exports.h>

/**
    @defgroup IMAGECOMPRESSION Image Compression
    @ingroup TC

    Images play a vital role for the application users and for the external manufacturers.Every product has its representing image which shows how it would look like.
    <br/>Measurement, constructions, color, sample details of the product can be well illustrated using technical images which help manufacturer to cast the design to a
    real time product.Original image which are of high quality with higher sharpness, HD, color accuracy, contrast etc. may be of high size.
    <br/>This leads to slower performance of the application while loading the image.Application does not need to show the original image E.g. on the UI in Product Summary,
    breadcrumb,search result however lower appropriate resolution version should suffice.Image Compression supports the generation of lower resolution representations
    of an image to support more efficient processing. This provides a framework that allows customers to configure and define image resolutions that are appropriate
    for their business process. This also provides a framework to define context versus format of the image required to be displayed.

    <br/>If you intend to enable image compression for the dataset, set the preference "TC__image_compression_enabled" to "true", add the dataset namedreference in
    the preference "TC__thumbnail_dataset_type_order", include the primary object to which dataset is related to in the "Fnd0ImageTranslationSupportedPrimaryTypes"
    global constant and set the resolution information in the preference "TC__image_compression_types".

*/

#ifdef __cplusplus
extern "C"{
#endif

/**
    Invokes the translation on the input Dataset into derived lower resolution Datasets based on the the values specified
    in the preference "TC__image_compression_types".
    <br/>The translated lower resolution datasets will be related to the supplied dataset with "Fnd0DerivedImangeRel" relation.

    @attention The input Dataset must contain the NamedReference listed in the preference "TC__thumbnail_dataset_type_order", must be a secondary
    object of any relation and the primary object of that relation is included in the "Fnd0ImageTranslationSupportedPrimaryTypes" global constant.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#IMAGECOMPRESSION_error_dataset_nulltag if @p dataset is #NULLTAG
    <li>#IMAGECOMPRESSION_error_input_not_dataset if the input object is not of type Dataset.
    <li>#IMAGECOMPRESSION_error_invalid_dataset if @p dataset does not exist or is deleted.
    <li>#IMAGECOMPRESSION_error_imagecompression_not_enabled if the preference "TC__image_compression_enabled" is not set to "true"
    <li>#IMAGECOMPRESSION_error_dataset_invalid_named_reference if @p dataset does not contain any NamedReference specified in the preference "TC__thumbnail_dataset_type_order".
    <li>#IMAGECOMPRESSION_error_invalid_imagetype_pref_value if the preference "TC__image_compression_types" does not contain any value.
    <li>#IMAGECOMPRESSION_error_invalid_primary_type if none of the primary objects associated with @p dataset is of a type listed in the BMIDE constant "Fnd0ImageTranslationSupportedPrimaryTypes".
    </ul>
*/
extern IMAGECOMPRESSION_API int IMAGECOMPRESSION_invoke_translation_on_dataset(
           tag_t dataset  /**< (I) The source dataset on which translation should be invoked.*/
       );

#ifdef __cplusplus
}
#endif
#include <imagecompression/libimagecompression_undef.h>
#endif
