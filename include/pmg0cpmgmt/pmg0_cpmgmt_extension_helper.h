/*
Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright $2017.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software
*/

/**
  @file
  This file contains the declaration for the Extensions of template pmg0cpmgmt
  
  @defgroup PMG0CPMGMT Consumer Product Management
  @ingroup TC
  @{
*/

#ifndef TEAMCENTER__PMG0CPMGMT__PMG0CPMGMTEXTENSIONHELPER_H
#define TEAMCENTER__PMG0CPMGMT__PMG0CPMGMTEXTENSIONHELPER_H

#include <tccore/method.h>
#include <pmg0cpmgmt/libpmg0cpmgmt_exports.h>

#ifdef __cplusplus
extern "C"{
#endif

/**
    Controls the changes with the dimensions of the Product Revision.
    <br/>If the dimension is referenced by the generated SKUs, this extension prevents the changes in all such dimensions.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PMG0CPMGMT_error_product_nulltag if product is #NULLTAG.
    <li>#PMG0CPMGMT_error_dimension_already_referenced if dimension is referenced in SKU, which prevents the changes in all such dimensions.
    </ul>
*/
extern PMG0CPMGMT_API int PMG0_product_revision_save_pre_condition(
            METHOD_message_t* msg,       /**< (I) Message of the extension method. */
            va_list args                /**< (I) Arguments of the extension method. */
            );


/**
    Validate effective to and effective from properties before save. Effective to property should be grater than effective from property.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PMG0CPMGMT_effectiveto_less_than_effectivefrom if effective to is lesser than effective from date.
    </ul>
*/
extern PMG0CPMGMT_API int PMG0_abstract_sku_revision_save_pre_condition(
            METHOD_message_t* msg,       /**< (I) Message of the extension method. */
            va_list args                /**< (I) Arguments of the extension method. */
            );

/**
    Validates the dimension value changes and updates the associated Stored Option Value with the update value of the dimensions.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PMG0CPMGMT_error_product_nulltag if product is #NULLTAG
    </ul>
*/
extern PMG0CPMGMT_API int PMG0_abstract_sku_revision_save_base(
            METHOD_message_t* msg,       /**< (I) Message of the extension method. */
            va_list args                /**< (I) Arguments of the extension method. */
            );

#ifdef __cplusplus
}
#endif

#include <pmg0cpmgmt/libpmg0cpmgmt_undef.h>

#endif

/** @} */
