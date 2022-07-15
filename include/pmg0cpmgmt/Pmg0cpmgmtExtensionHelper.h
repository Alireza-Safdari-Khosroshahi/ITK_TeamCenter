/*
//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2017.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software
//
//  @file
//  This file contains the declaration for the Extensions of template pmg0cpmgmt
//
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
    </ul>
*/
extern PMG0CPMGMT_API int PMG0_product_revision_save_pre_condition(METHOD_message_t* msg, va_list args);

/**
    Validates the dimension value changes and updates the associated Stored Option Value with the update value of the dimensions.

    @returns
    <ul>
    <li>#ITK_ok on success
    </ul>
*/
extern PMG0CPMGMT_API int Pmg0_abstract_sku_revision_save_base(METHOD_message_t* msg, va_list args);

#ifdef __cplusplus
}
#endif

#include <pmg0cpmgmt/libpmg0cpmgmt_undef.h>

#endif
