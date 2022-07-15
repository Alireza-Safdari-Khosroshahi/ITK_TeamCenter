/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2017.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    This file contains the constants, data structures and function prototypes for working with BooleanSolve C ITK interface.
    The BooleanSolve module deals with variant and effectivity expressions set on objects, and their configuration.

*/

#ifndef TEAMCENTER__BOOLEANSOLVE__H
#define TEAMCENTER__BOOLEANSOLVE__H

#include <unidefs.h>
#include <fnd0booleansolve/libfnd0booleansolve_exports.h>

#ifdef __cplusplus
extern "C"{
#endif

/**
    @defgroup BOOLEANSOLVE Boolean Solve (BSLV)
    @ingroup TC

    The Boolean Solve (BSLV) module is intended to give a consistent interface to
    operate on the variant and effectivity expressions.

    @{
*/

/**
   Represents a configuration option family by specifying the family id and its namespace.

   <br/>For example, an option family model in a family namespace 'ProductCar' can be specified as:
   @code
   BSLV_option_family_info_t model_family;
   model_family.family_id = "model";
   model_family.family_namespace = "ProductCar";
   @endcode
   It is used with #BSLV_option_value_info_t struct to specify an option family and value combination. If family_id and family_namespace are not provided, an error ##VARSOLVE_expr_is_invalid will be returned.
*/
typedef struct
{
   const char* family_id;         /**< The ID of a family */
   const char* family_namespace;  /**< The namespace for @p family_id */
} BSLV_option_family_info_t;

/**
   Represents a configuration option value by specifying the value id and its family info.
   <br/>For example, an option value Luxury for a family model having namespace 'ProductCar' can be specified as:

   @code
   BSLV_option_family_info_t model_family;
   model_family.family_id = "model";
   model_family.family_namespace = "ProductCar";
   BSLV_option_value_info_t luxury_model;
   luxury_model.family = &model_family;
   luxury_model.value_id = "Luxury";
   @endcode
   It is used with #BSLV_expression_info_t struct to specify a Boolean expression. If family is not provided, an error ##VARSOLVE_expr_is_invalid will be returned.
*/
typedef struct
{
   const BSLV_option_family_info_t*  family;  /**< The option family info for @p value_id */
   const char*  value_id;                     /**< The ID of a variant option value */
} BSLV_option_value_info_t;

/**
   Represents a Boolean expression with effectivity or variant options.

   <br/>For example, a variant expression "( [ProductCar]model = Luxury ) & [ProductCar]color = Red" can be represented as:
   @code
   // [ProductCar]model
   BSLV_option_family_info_t model_family;
   model_family.family_id = "model";
   model_family.family_namespace = "ProductCar";

   // Luxury
   BSLV_option_value_info_t luxury_model;
   luxury_model.family = &model_family;
   luxury_model.value_id = "M1";

   // [ProductCar]color
   BSLV_option_family_info_t color_family;
   color_family.family_id = "color";
   color_family.family_namespace = "ProductCar";

   // Red
   BSLV_option_value_info_t color_red;
   color_red.family = &color_family;
   color_red.value_id = "Red";

   // Construct the expression info

   // [ProductCar]model = Luxury
   BSLV_expression_info_t modelExpr;
   modelExpr.operator_code = CFG_operator_is_equal;
   modelExpr.value = &luxury_model;
   modelExpr.left = 0;
   modelExpr.right = 0;

   // [ProductCar]color = Red
   BSLV_expression_info_t colorFamilyExpr;
   colorFamilyExpr.operator_code = CFG_operator_is_equal;
   colorFamilyExpr.value = &color_red;
   colorFamilyExpr.left = 0;
   colorFamilyExpr.right = 0;

   // ( [ProductCar]model = Luxury )
   BSLV_expression_info_t bracesExpr;
   bracesExpr.operator_code = CFG_operator_brackets;
   bracesExpr.left = &modelExpr;
   bracesExpr.right = 0;

   // ( [ProductCar]model = Luxury ) & [ProductCar]color = Red
   BSLV_expression_info_t finalExpr;
   finalExpr.operator_code = CFG_operator_and;
   finalExpr.value = 0;
   finalExpr.left = &bracesExpr;
   finalExpr.right = &colorFamilyExpr;
   @endcode

   The validity of structure parameters is determined based on the operator tokens in <configurator/cfg_tokens.h>.
*/
typedef struct BSLV_expression_info BSLV_expression_info_t;

struct BSLV_expression_info
{
    int operator_code;                      /**< One of the operator tokens in <configurator/cfg_tokens.h> e.g. #CFG_operator_is_equal */
    const BSLV_option_value_info_t* value;  /**< NULL if @p opcode is a Boolean operator, e.g. #CFG_operator_and */
    const BSLV_expression_info_t* left;     /**< NULL if @p opcode is a comparison operator, e.g. #CFG_operator_is_equal */
    const BSLV_expression_info_t* right;    /**< NULL if @p opcode is a comparison operator or a unary operator, e.g. #CFG_operator_brackets */
};

/**
Holds parameters for searching VariantRule Objects. This struct is used to pass search parameters to saved query "Variant Rules"
*/
typedef struct
{
    tag_t primary_object;               /**< The primary object to which VariantRule or its subtype instances are attached through GRM relation as secondary objects. */
    tag_t relation_type;                /**< The GRM relation type with which VariantRule or its subtype instances are attached to @p primaryObject. Can be NULLTAG. */
    const char * object_name;           /**< The object_name of the Variant Rule. */
    const char * object_desc;           /**< The object_desc of the Variant Rule. */
    const char * object_id;             /**< The object ID of the Variant Rule. For objects of type VariantRule do not have ID. However, sub-type like Cfg0VariantCriteria
                                        do have a unique ID across multiple revisions. */
    const char * object_revision_id;    /**< The revision ID of the Variant Rule. For objects of type VariantRule do not support revisioning. However, sub-type like Cfg0VariantCriteria
                                        support multiple revisions. Each revision has its revision ID. */
} BSLV_variant_rule_search_param_t;

/**
    @name Variant Expression Functions
    @{
*/
/**
   Sets the variant expression on an object.
   <br/>An empty or NULL expression resets the assigned variant expression.
   <br/>It is the responsibility of the @p context object to choose the right configurator. It is assumed that the @p context will return
   a configurator implementation based on its business object type and/or the configurator data that is attached to it. The user should
   refer to the documentation of the BMIDE template that provides the configurator implementation for his site (e.g. Cfg0configurator)
   to find out how that configurator implementation selects a default revision rule. If no BMIDE template is installed to provide a configurator
   implementation, it is assumed that the Item or ItemRevision will select a configurator implementation that does not need a revision rule
   (e.g. the configurator implementation for classic variants).

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#ITK_invalid_nulltag if either @p context or @p object is #NULLTAG.
   <li>#VARSOLVE_context_is_invalid if the @p context is neither an Item nor an ItemRevision or their subtypes.
   <li>#CFM_cant_find_rev_rule if @p revision_rule is provided but does not correspond to a Revision Rule object.
   <li>#VARSOLVE_object_is_not_variant_configurable if the @p object is not a variant configurable object.
   <li>#CFG_convert_expr_unknown_value if @p expression is invalid.
   </ul>
*/
extern FND0BOOLEANSOLVE_API int BSLV_set_variant_expression(
    const tag_t     context,         /**< (I) The configurator context item to which the variant option values used in @p expression are associated */
    const tag_t     revision_rule,   /**< (I) The revision rule to configure the variant option values in @p context. If #NULLTAG, the configurator implementation may select a default revision rule. */
    const tag_t     object,          /**< (I) The variant configurable object to which @p expression will be attached as the primary variant expression */
    const char*     expression       /**< (I) The Boolean formula for the expression to be attached to @p object as the primary variant expression. An empty or null value will reset the assigned expression. */
    );

/**
   Retrieves the variant expression set on an object.
   <br/>It is the responsibility of the @p object object to choose the right configurator. It is assumed that the @p object will return a configurator
   implementation based on its business object type and/or the configurator data that is attached to it. The user should refer to the documentation of
   the BMIDE template that provides the configurator implementation for his/her site (e.g. Cfg0configurator) to find out how that configurator implementation
   selects a default revision rule. If no BMIDE template is installed to provide a configurator implementation, the API assumes that a configurator
   implementation is selected that does not need a revision rule (e.g. the configurator implementation for classic variants).

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#ITK_invalid_nulltag if @p object is #NULLTAG.
   <li>#VARSOLVE_object_is_not_variant_configurable if the @p object is not a variant configurable object.
   <li>#CFM_cant_find_rev_rule if @p revision_rule is provided but does not correspond to a Revision Rule object.
   </ul>
*/
extern FND0BOOLEANSOLVE_API int BSLV_get_variant_expression(
    const tag_t     revision_rule,   /**< (I) The revision rule to configure the variant option values in @p context. If #NULLTAG, the configurator implementation may select a default revision rule. */
    const tag_t     object,          /**< (I) The variant configurable object to which @p expression is be attached as the primary variant expression */
    char**          expression       /**< (OF) The Boolean formula for the primary variant expression of @p object. */
    );

/**
   Converts the nested expression structure into a formula using the Teamcenter format (e.g. "[Namespace]Color=Red").
   <br/>It is the responsibility of the @p context object to choose the right configurator. It is assumed that the @p context will return
   a configurator implementation based on its business object type and/or the configurator data that is attached to it. The user should
   refer to the documentation of the BMIDE template that provides the configurator implementation for his site (e.g. Cfg0configurator)
   to find out how that configurator implementation selects a default revision rule. If no BMIDE template is installed to provide a configurator
   implementation, it is assumed that the Item or ItemRevision will select a configurator implementation that does not need a revision rule
   (e.g. the configurator implementation for classic variants).

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#ITK_invalid_nulltag if @p context is #NULLTAG.
   <li>#VARSOLVE_context_is_invalid if the @p context is neither an Item nor an ItemRevision or their subtypes.
   <li>#CFM_cant_find_rev_rule if the @p revision_rule is not a RevisionRule object.
   <li>#VARSOLVE_expr_is_invalid if @p expression is invalid.
   <li>#BOOLEANMATH_invalid_operation if @p expression contains an invalid operator code.
   </ul>
*/
extern FND0BOOLEANSOLVE_API int BSLV_convert_variant_expression_to_formula(
    const tag_t                    context,        /**< (I) The configurator context item to which the variant option values used in @p expression are allocated */
    const tag_t                    revision_rule,  /**< (I) The Revision Rule to configure the variant option values in @p context */
    const BSLV_expression_info_t*  expression,     /**< (I) The structure to use for the formula generation */
    char**                         formula         /**< (OF) The Boolean formula for @p expression */
    );

/**
   Converts the formula to a nested expression structure using the Teamcenter format (e.g. "[Namespace]Color=Red").
   <br/>It is the responsibility of the @p context object to choose the right configurator. It is assumed that the @p context will return
   a configurator implementation based on its business object type and/or the configurator data that is attached to it. The user should
   refer to the documentation of the BMIDE template that provides the configurator implementation for his site (e.g. Cfg0configurator)
   to find out how that configurator implementation selects a default revision rule. If no BMIDE template is installed to provide a configurator
   implementation, it is assumed that the Item or ItemRevision will select a configurator implementation that does not need a revision rule
   (e.g. the configurator implementation for classic variants).

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#ITK_invalid_nulltag if @p context is #NULLTAG.
   <li>#VARSOLVE_context_is_invalid if the @p context is neither an Item nor an ItemRevision or their subtypes.
   <li>#CFM_cant_find_rev_rule if the @p revision_rule is not a RevisionRule object.
   <li>#CFG_convert_expr_unknown_value if @p formula is invalid.
   </ul>
*/
extern FND0BOOLEANSOLVE_API int BSLV_convert_variant_formula_to_expression(
    const tag_t                    context,        /**< (I) The configurator context item to which the variant option values used in @p formula are allocated */
    const tag_t                    revision_rule,  /**< (I) The Revision Rule to configure the variant option values in @p context */
    const char*                    formula,        /**< (I) The Boolean formula for @p expression */
    BSLV_expression_info_t**       expression      /**< (OF) The BSLV_expression_info structure that corresponds to @p formula <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only. */
    );

/** @} */

/**
    @name Effectivity Expression Functions
    @{
*/

/**
   Sets the effectivity expression on an object.
   <br/>An empty or NULL expression resets the assigned effectivity expression.
   <br/>If @p context is an item, @p revision_rule is used to configure the valid Item Revision used to retrieve the effectivity intent values.
   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#EFFSOLVE_context_is_invalid if the @p context is invalid.
   <li>#CFM_cant_find_rev_rule if @p revision_rule is provided but does not correspond to a Revision Rule object.
   <li>#EFFSOLVE_revision_rule_not_provided_for_item_context if the @p context is of "Item" type and @p revision_rule is #NULLTAG.
   <li>#EFFSOLVE_unable_to_configure_itemrev_for_item_context if the @p context is of "Item" type and @p revision_rule is not able to configure any valid Item Revision.
   <li>#ITK_invalid_nulltag if @p object is #NULLTAG.
   <li>#EFFSOLVE_object_is_not_effectivity_configurable if the @p object is not an effectivity configurable object.
   <li>#CFG_convert_expr_unknown_value if the @p effectivity_expression is an invalid effectivity expression string.
   <li>#CFM_has_object_based_eff_cant_have_expr_based_eff if the @p object is of "Fnd0EffectvtyGrp" type and it has an object based effectivity on it.
   </ul>
*/
extern FND0BOOLEANSOLVE_API int BSLV_set_effectivity_expression(
    const tag_t     context,                  /**< (I) The configurator context item or item revision to which the effectivity intent option values used in @p effectivity_expression are associated. This can be a #NULLTAG if there are no effectivity intent options used in @p effectivity_expression. */
    const tag_t     revision_rule,            /**< (I) The revision rule to configure the effectivity intent option values in @p context. This can be a #NULLTAG if there are no effectivity intent options used in @p effectivity_expression. */
    const tag_t     object,                   /**< (I) The effectivity configurable object to which @p effectivity_expression will be attached as the primary effectivity expression. */
    const char*     effectivity_expression    /**< (I) The Boolean formula for the effectivity expression to be attached to @p object as the primary effectivity expression. An empty or null value will reset the assigned expression. */
    );

/**
   Retrieves the effectivity expression on an object.
   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#CFM_cant_find_rev_rule if @p revision_rule is provided but does not correspond to a Revision Rule object.
   <li>#ITK_invalid_nulltag if @p object is #NULLTAG.
   <li>#EFFSOLVE_object_is_not_effectivity_configurable if the @p object is not a effectivity configurable object.
   </ul>
*/
extern FND0BOOLEANSOLVE_API int BSLV_get_effectivity_expression(
    const tag_t    object,                   /**< (I) The effectivity configurable object whose effectivity expressions will be read and will be set in @p effectivity_expression */
    const tag_t    revision_rule,            /**< (I) The revision rule provided along with configurator to to retrieve effectivity expression. This can be a #NULLTAG. */
    char**         effectivity_expression    /**< (OF) The Boolean formula for the effectivity expression (in string format) read from @p object. */
    );

/**
   Converts the nested effectivity expression structure into a formula using the Teamcenter format (e.g. "[Teamcenter]Unit=5").

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#EFFSOLVE_context_is_invalid if the @p context is neither an Item nor an ItemRevision or their subtypes.
   <li>#EFFSOLVE_revision_rule_not_provided_for_item_context if the @p context is of "Item" type and @p revision_rule is #NULLTAG.
   <li>#EFFSOLVE_unable_to_configure_itemrev_for_item_context if the @p context is of "Item" type and @p revision_rule is not able to configure any valid Item Revision.
   <li>#CFM_cant_find_rev_rule if the @p revision_rule is not a RevisionRule object.
   <li>#VARSOLVE_expr_is_invalid if @p effectivity_expression is invalid.
   <li>#BOOLEANMATH_invalid_operation if @p effectivity_expression contains an invalid operator code.
   </ul>
*/
extern FND0BOOLEANSOLVE_API int BSLV_convert_effectivity_expression_to_formula(
    const tag_t                    context,                   /**< (I) The configurator context item or item revision to which the effectivity intent option values used in @p effectivity_expression are associated. This can be a #NULLTAG if there are no effectivity intent options used in @p effectivity_expression. */
    const tag_t                    revision_rule,             /**< (I) The revision rule to configure the effectivity intent option values in @p context. This can be a #NULLTAG if there are no effectivity intent options used in @p effectivity_expression. */
    const BSLV_expression_info_t*  effectivity_expression,    /**< (I) The BSLV_expression_info structure corresponding to @p effectivity_expression */
    char**                         effectivity_formula        /**< (OF) The Boolean formula for @p effectivity_expression */
    );

/**
   Converts the formula to a nested expression structure using the Teamcenter format (e.g. "[Teamcenter]Unit=5").

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#EFFSOLVE_context_is_invalid if the @p context is neither an Item nor an ItemRevision or their subtypes.
   <li>#EFFSOLVE_revision_rule_not_provided_for_item_context if the @p context is of "Item" type and @p revision_rule is #NULLTAG.
   <li>#EFFSOLVE_unable_to_configure_itemrev_for_item_context if the @p context is of "Item" type and @p revision_rule is not able to configure any valid Item Revision.
   <li>#CFM_cant_find_rev_rule if the @p revision_rule is not a RevisionRule object.
   <li>#CFG_convert_expr_unknown_value if @p effectivity_formula is invalid.
   </ul>
*/
extern FND0BOOLEANSOLVE_API int BSLV_convert_effectivity_formula_to_expression(
    const tag_t                    context,                  /**< (I) The configurator context item or item revision to which the effectivity intent option values used in @p effectivity_expression are associated. This can be a #NULLTAG if there are no effectivity intent options used in @p effectivity_expression. */
    const tag_t                    revision_rule,            /**< (I) The revision rule to configure the effectivity intent option values in @p context. This can be a #NULLTAG if there are no effectivity intent options used in @p effectivity_expression. */
    const char*                    effectivity_formula,      /**< (I) The Boolean formula for @p effectivity_expression */
    BSLV_expression_info_t**       effectivity_expression    /**< (OF) The BSLV_expression_info structure corresponding to @p effectivity_formula <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only. */
    );

/** @} */

/**
Searches VariantRule instances including the sub-types of VariantRule based on search parameters supplied.
<br/> If only primary_object is provided, all Variant rules appached to it are returned.
<br/> relation_type is only considered when primary_object is provided.
<br/> If the primary_object and relation_type is not provided but object_name is provided then all the VariantRules with the object_name would be returned.

@returns
<ul>
<li>#ITK_ok on success
<li>#VARSOLVE_invalid_variant_rule_search_param if @p variant_rule_search_param is invalid
</ul>

@note
<br/>If no VariantRules are found for the given input, no error is returned and @p n_variant_rules is zero.
*/
extern FND0BOOLEANSOLVE_API int BSLV_search_variant_rules(
    const BSLV_variant_rule_search_param_t * variant_rule_search_param,    /**< (I)  Structure which includes primary_object, relation_type and object_name, object_id, revision_id, description of variant rule as search parameters. */
    int * n_variant_rules,                                                 /**< (O)  Number of elements in @p variant_rules. */
    tag_t ** variant_rules                                                 /**< (OF) n_variant_rules filtered variant rule objects that include instances of subtypes which match the search parameters. */
);

/** @} */
#ifdef __cplusplus
}
#endif
#include <fnd0booleansolve/libfnd0booleansolve_undef.h>
#endif
