/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2015.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    User Exits declaration for Cfg0configurator template.
*/

#ifndef CFG0CONFIGURATOR_USER_EXITS_H
#define CFG0CONFIGURATOR_USER_EXITS_H

#include <unidefs.h>
#include <Cfg0configurator/libcfg0configurator_exports.h>

/**
 @brief User Exit API that converts a Teamcenter formula to a custom formula format.
 @param[in]  tag_t cfg0_perspective  The Cfg0ConfiguratorPerspective object for which Teamcenter formula to custom formula conversion is expected.
 @param[in]  const char* tc_formula  Teamcenter formula string
 @param[out] char** custom_formula   Converted custom formula. The memory will need to be deallocated using #MEM_free.
*/
#define CFG0_convert_tc_formula_to_custom_formula            "BMF_USER_CFG0_convert_teamcenter_formula_to_custom_formula"

/**
 @ brief User Exit API that converts a custom formula to a Teamcenter formula format.
 @param[in]  tag_t cfg0_perspective     The Cfg0ConfiguratorPerspective object for which custom formula to Teamcenter formula conversion is expected.
 @param[in]  const char* custom_formula Custom formula string
 @param[out] char** tc_formula          Converted Teamcenter formula. The memory will need to be deallocated using #MEM_free.
*/
#define CFG0_convert_custom_formula_to_tc_formula            "BMF_USER_CFG0_convert_custom_formula_to_teamcenter_formula"

#ifdef __cplusplus
extern "C"
{
#endif

/**
    Provides an extension point for customers to plug the customization for converting Teamcenter formula into customized format.
    @returns
    <ul>
        <li>#ITK_ok on success</li>
        <li>Possibly other errors.</li>
    </ul>
*/
extern CFG0CONFIGURATOR_API int USER_CFG0_convert_teamcenter_formula_to_custom_formula(
     tag_t cfg0_perspective, /**< (I) The Cfg0ConfiguratorPerspective object for which Teamcenter formula to custom formula conversion is expected. */
     const char* tc_formula, /**< (I) Teamcenter formula string */
     char** custom_formula   /**< (OF) Converted custom formula */
);

/**
    Provides an extension point for customers to plug the customization for converting customized formula into Teamcenter format.
    @returns
    <ul>
        <li>#ITK_ok on success</li>
        <li>Possibly other errors.</li>
    </ul>
*/
extern CFG0CONFIGURATOR_API int USER_CFG0_convert_custom_formula_to_teamcenter_formula(
    tag_t cfg0_perspective,     /**< (I) The Cfg0ConfiguratorPerspective object for which Custom formula to Teamcenter formula conversion is expected. */
    const char* custom_formula, /**< (I) Custom formula string */
    char** tc_formula           /**< (OF) Converted Teamcenter formula */
);

#ifdef __cplusplus
}
#endif


#include <Cfg0configurator/libcfg0configurator_undef.h>
#endif /* CFG0CONFIGURATOR_USER_EXITS_H */
