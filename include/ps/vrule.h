/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Function prototypes for saving Variant Rules.

    These functions provide basic functionality for creating Variant Rules and
    populating them based on a configured BOM Window.

    Variant Rules can be applied to a BOM Window using the BOM ITK functions #BOM_window_apply_full_vrule and
    #BOM_window_apply_partial_vrule.

    The Variant Rule stores the options and values as Variant Expressions using the RULE_SET operator.
    These variant expressions can be accessed by retrieving the "expression_block" property from the Variant Rule,
    and using the Variant ITK on the returned Variant Expression Block.
*/

/*  */

#ifndef VRULE_H_INCLUDED
#define VRULE_H_INCLUDED

#include <unidefs.h>
#include <ps/libps_exports.h>

/**
    @defgroup VRULE Variant Rule
    @ingroup PS

    <b>Common Return Values</b>

    <table>
    <tr><td>Return Value             </td><td>Description                                          </td></tr>
    <tr><td>#VRULE_empty_rule        </td><td>The supplied variant rule contains no options.
                                              This is an information message rather than an error. </td></tr>
    <tr><td>#VRULE_invalid_bom_window</td><td>The supplied BOM Window is not valid.                </td></tr>
    <tr><td>#VRULE_invalid_rule      </td><td>The supplied variant rule is not valid.              </td></tr>
    <tr><td>#VRULE_unable_to_create  </td><td>Teamcenter Engineering could not create the variant rule.
                                              This should be accompanied by a more specific reason.</td></tr>
    </table>
    @{
*/

#define VRULE_vrule_class_name_c  "VariantRule"

#ifdef __cplusplus
    extern "C"{
#endif

/**
    Creates an empty Variant Rule, with the given name and description
*/
extern PS_API int VRULE_create(
    const char*   name,         /**< (I) Name for the new variant rule */
    const char*   description,  /**< (I) Description for the new variant rule */
    tag_t*        vrule         /**< (O) Newly created variant rule */
    );

/**
    Creates a Variant Rule with the given name and description.
    This new rule is populated with the supplied list of options,
    with the values being taken from the given BOM window.
    If n_options is set to zero, then all set options (by user or rule) are saved.
*/
extern PS_API int VRULE_create_from_bom(
    const char*   name,         /**< (I) Name for the new variant rule */
    const char*   description,  /**< (I) Description for the new variant rule */
    tag_t         bom_window,   /**< (I) BOM Window that supplies variant option values */
    int           n_options,    /**< (I) Number of variant options in the supplied option array.
                                         Setting this value to zero will result in all options that are set
                                         in the BOM Window being saved. */
    const tag_t*  options,      /**< (I) n_options Array of variant options to save to the new Rule.
                                         If any of these options were not set by the user or by a rule,
                                         their entry in here will be ignored. */
    tag_t*        vrule         /**< (O) Newly created variant rule */
    );

/**
    Saves a given set of option values to an existing variant rule.
    Only those options which have been manually set
    (either by the user or by another variant rule) are stored in the rule.
*/
extern PS_API int VRULE_set_from_bom(
    tag_t         vrule,        /**< (I) Variant rule to save the values to */
    tag_t         bom_window,   /**< (I) BOM Window that supplies variant option values */
    logical       update_only,  /**< (I) Controls whether the supplied option values will replace
                                         the rule's existing options or simply update the existing values. <br>
                                         true - Only save the values of those options that are already defined in the rule. <br>
                                         false - Save all the options that are set in the BOM Window
                                         and listed in the option array. */
    int           n_options,    /**< (I) Number of variant options in the supplied option array.
                                         Setting this value to zero will result in all options that are
                                         set in the BOM Window being saved. */
    const tag_t*  options       /**< (I) n_options Array of variant options to save to the new Rule.
                                         If any of these options were not set by the user or by a rule,
                                         their entry in here will be ignored. */
    );

/**
    Creates a new variant rule and populates it using option values set in the given BOM variant rule.
    Only those options which have been manually set (either by the user or by another variant rule)
    are stored in the new rule.
*/
extern PS_API int VRULE_create_from_variant_rule(
    const char*   name,             /**< (I) The name for the new variant rule */
    const char*   description,      /**< (I) The description for the new rule */
    tag_t         bomvariantrule,   /**< (I) The BOM variant rule that supplies the variant option values */
    int           n_options,        /**< (I) Number of options in the supplied option array.
                                         Setting this value to zero will result in all options that are set
                                         in the BOM variant rule being saved. */
    const tag_t*  options,          /**< (I) n_options Array of variant options to save to the new variant rule.
                                         If any of these options were not set by the user or by a rule,
                                         their entry in here will be ignored. */
    tag_t*        vrule             /**< (O) The tag of the newly created variant rule */
    );

/**
    Saves the given list of options (with their values being taken from the BOM Variant Rule)
    to the given existing Variant Rule.
    If n_options is zero, then all set options (by user or rule) are saved.
    If update_only is set to TRUE, then only those options which are already in the rule are saved.
*/
extern PS_API int VRULE_set_from_variant_rule(
    tag_t         vrule,            /**< (I) The variant rule to save the values to */
    tag_t         bomvariantrule,   /**< (I) The BOM variant rule that supplies the variant option values */
    logical       update_only,      /**< (I) Controls whether the supplied option values will replace
                                         the rule's existing options or simply update the existing values.
                                         Set this to true to only save the values of those options that are
                                         already defined in the rule.
                                         Set this to false to save all options that are set in the BOM variant rule
                                         and listed in the option array. */
    int           n_options,        /**< (I) Number of options in the supplied option array.
                                         Setting this value to zero will result in all options that are set
                                         in the BOM variant rule being saved. */
    const tag_t*  options           /**< (I) n_options Array of variant options to save to the new variant rule.
                                         If any of these options were not set by the user or by a rule,
                                         their entry in here will be ignored. */
    );

/**
    Retrieves the contents of a Variant Rule in text format. The BOM Window can be used to context.
    If it is set to #NULLTAG, a BOM Window will be created with a default configuration.

    @note The user is responsible to free each string returned in the arrays  before freeing up the arrays.
    Use #MEM_free to free up the memory.
*/
extern PS_API int VRULE_ask_rule_text(
    tag_t         vrule,            /**< (I) Variant rule to query */
    tag_t         bom_window,       /**< (I) BOM Window that supplies variant option values */
    int*          n_entries,        /**< (O) Number of options defined in the rule */
    char***       items,            /**< (OF) n_entries Array of Item IDs on which the options are defined */
    char***       options,          /**< (OF) n_entries Array of names of the options stored in the rule */
    char***       descriptions,     /**< (OF) n_entries Array of descriptions of the options stored in the rule */
    char***       values            /**< (OF) n_entries Array of values of the options stored in the rule */
    );

/**
    Checks whether the given Variant Rule is present in the database.
    If it is not, it saves the variant rule with the object_desc "_PRIVATE_PURGEABLE_VR_".
    <br/>This ITK is a temporary solution to mark adhoc temporary variant rule objects that stateless clients (e.g Active Workspace) might have created.
    Once marked the objects will be easily identifiable by the mentioned utility in order to be purged.
    <br/>This ITK should not be used for any other purposes.

    @note Adhoc Variant Rule objects saved in this manner can be searched using the object description "_PRIVATE_PURGEABLE_VR_", and then purged.
    <br>Use the utility 'purge_adhoc_configuration_contexts' in order to achieve that.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#VRULE_invalid_rule if @p variant_rule does not correspond to a valid Variant Rule
    </ul>
*/
extern PS_API int VRULE_save_adhoc_variant_rule(
    const tag_t               variant_rule             /**< (I) The Variant Rule. */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <ps/libps_undef.h>

#endif
