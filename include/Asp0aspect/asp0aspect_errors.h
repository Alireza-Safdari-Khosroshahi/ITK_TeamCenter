/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2018.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    Aspect Error Codes Declaration

*/

#ifndef ASP0ASPECT_ERRORS_H
#define ASP0ASPECT_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup ASP0ASPECT_ERRORS Aspect Errors
    @ingroup ASP0ASPECT
    @{
*/

#define ASP0ASPECT_ERROR_BASE                                   EMH_ASP0ASPECT_error_base

/**
 * The following internal error has occurred: %1$. Please report it to your system administrator.
 */
#define ASP0ASPECT_internal_error                               ( ASP0ASPECT_ERROR_BASE + 1 )

/**
  * The requested aspect scheme type &quot;%1$&quot; cannot be deleted, because it is being referenced by one or more aspects in the current model.
*/
#define ASP0ASPECT_scheme_is_referenced                         ( ASP0ASPECT_ERROR_BASE + 2 )

/**
  * An unknown expansion semantic &quot;%1$&quot; was requested.
*/
#define ASP0ASPECT_unknown_expansion_semantic                   ( ASP0ASPECT_ERROR_BASE + 3 )

/**
 * An unknown expand option &quot;%1$&quot; was requested.
*/
 #define ASP0ASPECT_unknown_expand_option                       ( ASP0ASPECT_ERROR_BASE + 4 )

/**
  * An unsupported level of expand value &quot;%1$&quot; was requested.
*/
#define ASP0ASPECT_unsupported_expand_level                     ( ASP0ASPECT_ERROR_BASE + 5 )

/**
  * A duplicate starting node &quot;%1$&quot; was found in the input list. Please remove it and try again.
*/
#define ASP0ASPECT_duplicate_starting_node                      ( ASP0ASPECT_ERROR_BASE + 6 )

/**
  * No Aspect Scheme of type &quot;%1$&quot; could be found in the model &quot;%2$&quot;. Please set an Aspect Scheme type for which an instance exists in the model.
*/
#define ASP0ASPECT_scheme_not_in_model                          ( ASP0ASPECT_ERROR_BASE + 7 )

/**
  * Either the input model or the Aspect Scheme is empty. Please change and try again.
*/
#define ASP0ASPECT_empty_scheme_model_supplied                  ( ASP0ASPECT_ERROR_BASE + 8 )

/**
  * The selected target Aspect "%1$" is not in the same model as the model specified for the "Save As" operation.
*/
#define ASP0ASPECT_sel_aspect_not_in_spec_model                 ( ASP0ASPECT_ERROR_BASE + 9 )

/**
  * The selected target Aspect "%1$" is not in the same model as the object selected for the "Save As" operation.
*/
#define ASP0ASPECT_sel_aspect_not_in_source_model               ( ASP0ASPECT_ERROR_BASE + 10 )

/**
  * The input starting nodes "%1$" and "%2$" do not have the same source model.
*/
#define ASP0ASPECT_multiple_source_models_for_starting_nodes    ( ASP0ASPECT_ERROR_BASE + 11 )

/**
  * The mandatory input parameters to perform this operation are missing.
*/
#define ASP0ASPECT_mandatory_inputs_missing                     ( ASP0ASPECT_ERROR_BASE + 12 )

/**
  * The Aspect category input "%1$" provided to perform this operation is incorrect.
*/
#define ASP0ASPECT_incorrect_category                           ( ASP0ASPECT_ERROR_BASE + 13 )

/**
  * The Aspect schemes provided to perform this operation are not from the same Application Model.
*/
#define ASP0ASPECT_input_schemes_not_from_same_model            ( ASP0ASPECT_ERROR_BASE + 14 )

/**
  * The Aspect schemes and the Application Model provided to perform this operation do not match.
*/
#define ASP0ASPECT_input_schemes_appmodel_mismatch              ( ASP0ASPECT_ERROR_BASE + 15 )

/**
  * This version of the operation is no longer supported. Use the latest version of the operation instead. Please refer to the Teamcenter server syslog file for more information.
*/
#define ASP0ASPECT_unsupport_expand_operation                   ( ASP0ASPECT_ERROR_BASE + 16 )

/**
  * The Engineering object supplied with the Aspect belongs to a different Application Model "%1$".
*/
#define ASP0ASPECT_engobj_different_appmodel                    ( ASP0ASPECT_ERROR_BASE + 17 )

/**
  * The Aspect "%1$" cannot have NULL parent and category "Child". Please provide a correct category.
*/
#define ASP0ASPECT_null_parent_category_mismatch                ( ASP0ASPECT_ERROR_BASE + 18 )

/**
  * The Aspect "%1$" cannot have a non-NULL parent and category "%2$". Please provide a correct category.
*/
#define ASP0ASPECT_valid_parent_category_mismatch               ( ASP0ASPECT_ERROR_BASE + 19 )

/**
  * Valid values for the levels to traverse in Aspect Search Expressions are "-1" (all levels), "0" (no traversal and only the input aspects are considered as scope for Engineering object search) and "n" (traversal is done till n'th level).
*/
#define ASP0ASPECT_invalid_levels_to_traverse                   ( ASP0ASPECT_ERROR_BASE + 20 )

/**
  * All aspect schemes in a single AspectSearchExpressionIn input structure must belong to same application model.
*/
#define ASP0ASPECT_invalid_schemes_for_createsearchexpression   ( ASP0ASPECT_ERROR_BASE + 21 )



/**

    @}
*/

#endif
