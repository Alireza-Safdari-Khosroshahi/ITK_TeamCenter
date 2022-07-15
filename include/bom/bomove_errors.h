/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Error codes returned by the OVE via BOM ITK
*/

/*  */

#ifndef BOMOVE_ERRORS_H
#define BOMOVE_ERRORS_H

#include <common/emh_const.h>
#include <bom/libbom_exports.h>

/**
    @defgroup BOMOVE_ERRORS OVE Errors
    @ingroup BOM
    @{
*/

#define BOM_OVE_internal                        (EMH_BOM_OVE_error_base +   1)
#define BOM_OVE_Programming                     (EMH_BOM_OVE_error_base +   2)
#define BOM_OVE_NotInitialized                  (EMH_BOM_OVE_error_base +   3)
#define BOM_OVE_SyntaxError                     (EMH_BOM_OVE_error_base +  10)
#define BOM_OVE_OptPreChild                     (EMH_BOM_OVE_error_base +  21)
#define BOM_OVE_OptPrePath                      (EMH_BOM_OVE_error_base +  22)
#define BOM_OVE_OptOutOfScopeMVL                (EMH_BOM_OVE_error_base +  23)
#define BOM_OVE_OptOutOfScopeCond               (EMH_BOM_OVE_error_base +  24)
#define BOM_OVE_OptionAlreadyExists             (EMH_BOM_OVE_error_base + 101)
#define BOM_OVE_NoSuchOption                    (EMH_BOM_OVE_error_base + 102)
#define BOM_OVE_NullOption                      (EMH_BOM_OVE_error_base + 103)
#define BOM_OVE_cantAddValueToDerrivedOption    (EMH_BOM_OVE_error_base + 104)
#define BOM_OVE_valueNotValidForOption          (EMH_BOM_OVE_error_base + 105)
#define BOM_OVE_OptionAlreadyUsed               (EMH_BOM_OVE_error_base + 108)
#define BOM_OVE_OptionIsReferenced              (EMH_BOM_OVE_error_base + 109)
#define BOM_OVE_InvalidOptionId                 (EMH_BOM_OVE_error_base + 110)
#define BOM_OVE_CantReferenceOptionOfSameModule (EMH_BOM_OVE_error_base + 111)
#define BOM_OVE_ScopeError                      (EMH_BOM_OVE_error_base + 201)
#define BOM_OVE_TypeMismatch                    (EMH_BOM_OVE_error_base + 202)
#define BOM_OVE_DivideByZero                    (EMH_BOM_OVE_error_base + 203)
#define BOM_OVE_InvalidValue                    (EMH_BOM_OVE_error_base + 204)
#define BOM_OVE_ConditionCanOnlyBeBool          (EMH_BOM_OVE_error_base + 206)
#define BOM_OVE_NonUniqueModuleName             (EMH_BOM_OVE_error_base + 301)
#define BOM_OVE_NoSuchModule                    (EMH_BOM_OVE_error_base + 302)
#define BOM_OVE_cantPresentNonPublicOption      (EMH_BOM_OVE_error_base + 303)
#define BOM_OVE_cantUseNonPublicOption          (EMH_BOM_OVE_error_base + 305)
#define BOM_OVE_cantImplementNonPublicOption    (EMH_BOM_OVE_error_base + 306)
#define BOM_OVE_nodeHasNoModule                 (EMH_BOM_OVE_error_base + 309)
#define BOM_OVE_EvaluationAborted               (EMH_BOM_OVE_error_base + 500)

#define BOM_OVE_inform_check                    (EMH_BOM_OVE_error_base + 501)
#define BOM_OVE_warn_check                      (EMH_BOM_OVE_error_base + 502)
#define BOM_OVE_error_check                     (EMH_BOM_OVE_error_base + 503)

#define BOM_OVE_error_at_line                   (EMH_BOM_OVE_error_base + 505)
#define BOM_OVE_error_at_node                   (EMH_BOM_OVE_error_base + 506)
#define BOM_OVE_error_at_node_line              (EMH_BOM_OVE_error_base + 507)

#define BOM_OVE_legacy_data_error                 (EMH_BOM_OVE_error_base + 600)
#define BOM_OVE_legacy_evaluation_error           (EMH_BOM_OVE_error_base + 601)

/** @} */

#include <bom/libbom_undef.h>
#endif
