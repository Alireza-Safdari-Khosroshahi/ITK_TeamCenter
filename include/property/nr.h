/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*  */

#ifndef NR_H
#define NR_H

#include <tc/tc_startup.h>
#include <fclasses/tc_stdio.h>
#include <fclasses/tc_stdlib.h>
#include <tccore/workspaceobject.h>
#include <property/libproperty_exports.h>

/**
    @defgroup NR Naming Rule (NR)
    @ingroup PROP

    Naming Rules allow the site to provide naming pattern validation for various user input fields.

    The set of ITK given here accesses NameRule, NameField and NameCounter classes,
    which can be used to validate and generate ids based on specific patterns.

    <table>
    <tr><td>NameRule Class attributes</td><td>NameField Class attributes</td><td>NameCounter Class attributes</td></tr>
    <tr><td>rule_name                </td><td>type_name                 </td><td>counter_name                </td></tr>
    <tr><td>patterns[]               </td><td>property_name             </td><td>no_of_chars                 </td></tr>
    <tr><td>autogen                  </td><td>field_case                </td><td>char_type                   </td></tr>
    <tr><td>counter_tags             </td><td>rule_tag                  </td><td>start_pos                   </td></tr>
    <tr><td>                         </td><td>                          </td><td>init_value                  </td></tr>
    <tr><td>                         </td><td>                          </td><td>max_value                   </td></tr>
    <tr><td>                         </td><td>                          </td><td>next_id                     </td></tr>
    </table>

    @{
*/

#define NR_CASE_MIXED 0
#define NR_CASE_LOWER 1
#define NR_CASE_UPPER 2

/** Defines the maximum number of characters for a Context name */
#define NR_CONTEXT_NAME_MAX_LENGTH    256


#ifdef __cplusplus
    extern "C"{
#endif

/**
    Returns an array of all of the NameRules objects.
*/
extern PROPERTY_API int NR_rule_extent(
    int*                n_tags,     /**< (O) Number of NameRules objects */
    tag_t**             rule_tags   /**< (OF) n_tags Array of NameRules tags */
    );

/**
    Finds a NameRules object by its name.
*/
extern PROPERTY_API int NR_find(
    char*               rule_name,  /**< (I) The unique name of a rule */
    tag_t*              rule_tag    /**< (O) Tag of NameRules object */
    );

/**
    Returns an array of all of the NameFields objects.
*/
extern PROPERTY_API int NR_field_extent(
    int*                n_tags,     /**< (O) Number of NameFields objects */
    tag_t**             field_tags  /**< (OF) n_tags Array of NameFields tags */
    );


/**
    Retrieves all rule fields.
*/
extern PROPERTY_API int NR_field_desc(
    tag_t               field_tag,      /**< (I) Tag of NameFields object */
    char**              type_name,      /**< (OF) The IMANTYPE that the rule applies to */
    char**              property_name,  /**< (OF) The property field in this IMANTYPE that the rule applies to */
    tag_t*              rule_tag,       /**< (O) Tag of NameRules object containing the rule patterns */
    int*                field_case      /**< (O) The case to automatically translate the property fields contents
                                            (#NR_CASE_MIXED, #NR_CASE_LOWER, #NR_CASE_UPPER) */
    );

/**
    Get the rule tag and field case value for the Teamcenter Engineering type and property name combination.
*/
extern PROPERTY_API int NR_ask_rule_and_case(
    char*               type_name,      /**< (I) The IMANTYPE that the rule applies to */
    char*               property_name,  /**< (I) The property field in this IMANTYPE that the rule applies to */
    tag_t*              rule_tag,       /**< (O) Tag of NameRules object containing the rule patterns */
    int*                field_case      /**< (O) The case to automatically translate the property fields contents
                                            (#NR_CASE_MIXED, #NR_CASE_LOWER, #NR_CASE_UPPER) */
    );

/**
    @name Naming Rule Checker

    The Naming Rule Checker enables the Assign buttons for Item IDs and Revisions and Dataset IDs and Revisions,
    to use the Naming rule patterns as templates.
    Also, the i-Man components for Name Rule and NameField will be created to allow Portal to access the Naming Rules.
    @{
*/


/**
    Validates the field value against the patterns of the naming rule of the property.
    Convert the field value if applicable according to the field_case specification of the naming rule.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#NR_never_matched if @p field_value does not match any of the valid patterns.
    <li>#TYPE_invalid_type_name if @p type_name is not a valid type name.
    <li>#TYPE_unknown_type if @p type_name does not name a type that exists.
    <li>#PROP_invalid_name if @p property_name is not a valid property internal name for the type @p type_name.
    <li>#PROP_not_found if @p property_name is not found for the type @p type_name.
    <li>#PROP_invalid_value if @p field_value is NULL.
    </ul>
*/
extern PROPERTY_API int NR_validate_field(
    const char*         type_name,      /**< (I) Teamcenter type name.  For example, "Item", "ItemRevision", etc. */
    const char*         property_name,  /**< (I) Name of a property for the type. For example "item_id", "item_revision_id", "object_name", etc. */
    char*               field_value     /**< (I)  Input property value to be tested against the patterns of the naming rule, and 
                                        Input property is also converted to match input property value case to the naming rule field_case specification. */
    );

/**
   Matches the given revision id and determines if the revid matches the altrule or not.
   For baseline pattern matching, the the suffix rule should be passed as "PDR"
*/
extern PROPERTY_API logical NR_match_revid_altrule(
    const char*             type_name,  /**< (I) Item Type Name */
    const char*             revid,      /**< (I) Id for which the patten matching needs to be done */
    const char*             suffixrule  /**< (I) For Baseline, its PDR */
    );

extern PROPERTY_API int NR_is_name_matching_pattern(
    const char*         pattern,             /* <I> */
    const char*         string,              /* <I> */
    logical*            is_matched           /* <O> */
    );

/**
   Gets the next id generated for a particular pattern in the Naming Rule
   This ITK is a generalized ITK for generating next id in case of :
   <ol>
   <li>next item id (usage example:  NR_next_value(type_name, next_id) -> NR_next_value(type_name, "item_id", NULLTAG,"", "", "", NULLTAG, ""," ", next_id);)
   <li>next revision id (usage example:  NR_next_rev_id(type_name, item_tag, next_id) -> NR_next_value(type_name, "item_revision_id", item_tag,"","","",NULLTAG,"","", next_id );)
   <li>next revision id generated from the pattern in the alt rule (usage example: NR_next_rev_id_from_alt_rule(type_name, rule_suffix, item_tag, base_rev_id, next_id) -> NR_next_value(type_name, "", item_tag, "", "", "", NULLTAG, rule_suffix, base_rev_id, next_id );)
   <li>next alt id generated from the pattern in rule (usage example: NR_next_alt_id(preferred_type_name, default_type_name, parent_tag, next_id) -> NR_next_value("", "", NULLTAG, "", preferred_type_name, default_type_name, parent_tag, "", "", next_id );)
   <li>next dataset id (usage example: NR_next_dataset_id(ds_type, next_id) -> NR_next_value(ds_type, "pubr_object_id", NULLTAG, "", "","",NULLTAG, "", "", next_id );)
   <li>next dataset revision id (usage example: NR_next_dataset_rev_id(ds_type, ds_id, next_id) -> NR_next_value(ds_type, "rev", NULLTAG, ds_id, "", "", NULLTAG, "", "", next_id );)
   <li>For any String attribute on a type.
   </ol>

   This generates the next id corresponding to the pattern of a Naming Rule that is set as a
   last used pattern in the prefernce "TC_LAST_USED_PATTERNS". This preference is used to store
   the user's last selected naming pattern for a given property of a business object in the
   context of a condition.This is a multi valued User preference.There is not default setting
   for this preference. If this preference is not set then next id will be generated for the first
   pattern of the Naming Rule.
   If the nextId is returned as NULL; either no Naming Rule is defined, or a Naming Rule without any counters is defined for the given input.
   The ITK will return ITK_ok in this case.
   @note Use #NR_next_rev_options to get the next value based on revision naming rule
*/
extern PROPERTY_API int NR_next_value(
    const char* type_name,              /**< (I) Teamcenter Engineering type name, i.e. "Item" */
    const char* property_name,          /**< (I) Property name, i.e. "item_id", "item_revision_id", "object_name"*/
    const tag_t item,                   /**< (I) The tag of the parent item */
    const char* ds_id,                  /**< (I) Dataset ID */
    const char* preferred_type_name,    /**< (I) Preferred type name */
    const char* default_type_name,      /**< (I) Default type name */
    const tag_t parent,                 /**< (I) Used in case of next alt ID*/
    const char* rule_suffix,            /**< (I) This is only used when next revision id to be generated from a baseline rule. 'PDR' must be passed when baseline id is to be generated. */
    const char* base_revision_id,       /**< (I) Used in case of next revision ID generated from the pattern in the alt rule*/
    char**      next_id                 /**< (OF)Generated next ID */
    );

/**
   Retrieves the next item ids generated of the specified quantity
   for a particular pattern in the Naming Rule for item_id property only.
   <br/>This ITK is a generalized ITK for generating single next id in case of:
   <ol>
   <li>next revision id
   <li>next revision id generated from the pattern in the alt rule
   <li>next alt id generated from the pattern in rule
   <li>next dataset id
   <li>next dataset revision id
   <li>For any String attribute on a type.
   </ol>

   This generates the next ids for item_ids corresponding to the pattern of a Naming Rule
   that is set as a last used pattern in the prefernce "TC_LAST_USED_PATTERNS".
   <br/>This preference is used to store the user's last selected naming pattern for
   a given property of a business object in the context of a condition.This is
   a multi-valued User preference.There is not default setting for this preference.
   <br/>If this preference is not set then next id will be generated for the first
   pattern of the Naming Rule.

   @returns
    <ul>
    <li>#ITK_ok on success
    <li>#TYPE_unknown_type if @p type_name is invalid or if @p item is invalid or if @p preferred_type_name is invalid or if @p default_type_name is invalid or if @p parent is invalid
    <li>#TYPE_invalid_type_name if @p type_name is empty
    <li>#NR_invalid_qunatity_value if @p quantity is zero
    <li>#PROP_not_found if @p property_name is empty or invalid
    <li>Other errors returned by the customization
    </ul>

   @note Use #NR_next_rev_options to get the next value based on revision naming rule
*/
extern PROPERTY_API int NR_next_values(
    const char* type_name,              /**< (I) Teamcenter Engineering type name, i.e. "Item" */
    const int   quantity,               /**< (I) Number of instances of the specified type to be created */
    const char* property_name,          /**< (I) Property name, i.e. "item_id", "item_revision_id", "object_name"*/
    const tag_t item,                   /**< (I) The tag of the parent item */
    const char* ds_id,                  /**< (I) Dataset ID */
    const char* preferred_type_name,    /**< (I) Preferred type name */
    const char* default_type_name,      /**< (I) Default type name */
    const tag_t parent,                 /**< (I) Used in case of next alt ID */
    const char* rule_suffix,            /**< (I) This is only used when next revision id to be generated from a baseline rule. 'PDR' must be passed when baseline id is to be generated. */
    const char* base_revision_id,       /**< (I) Used in case of next revision ID generated from the pattern in the alt rule */
    char***     next_ids,               /**< (OF) quantity Generated next IDs.
    <br/>This array is not packed, which means that both, the elements and the container need to be freed through a call to #MEM_free.  */
    logical*    is_nr_without_autogen   /**< (O) Determines if a valid naming rule was found but no counters were found. */
    );

/**
   Retrieves the next id generated for a particular pattern in the Naming Rule.
   This ITK is a generalized ITK for generating next id in case of :
   <ol>
   <li>next item id (usage example:  NR_next_value(type_name, next_id) -> NR_next_value(type_name, "item_id", NULLTAG,"", "", "", NULLTAG, ""," ", next_id);)
   <li>next revision id (usage example:  NR_next_rev_id(type_name, item_tag, next_id) -> NR_next_value(type_name, "item_revision_id", item_tag,"","","",NULLTAG,"","", next_id );)
   <li>next revision id generated from the pattern in the alt rule (usage example: NR_next_rev_id_from_alt_rule(type_name, rule_suffix, item_tag, base_rev_id, next_id) -> NR_next_value(type_name, "", item_tag, "", "", "", NULLTAG, rule_suffix, base_rev_id, next_id );)
   <li>next alt id generated from the pattern in rule (usage example: NR_next_alt_id(preferred_type_name, default_type_name, parent_tag, next_id) -> NR_next_value("", "", NULLTAG, "", preferred_type_name, default_type_name, parent_tag, "", "", next_id );)
   <li>next dataset id (usage example: NR_next_dataset_id(ds_type, next_id) -> NR_next_value(ds_type, "pubr_object_id", NULLTAG, "", "","",NULLTAG, "", "", next_id );)
   <li>next dataset revision id (usage example: NR_next_dataset_rev_id(ds_type, ds_id, next_id) -> NR_next_value(ds_type, "rev", NULLTAG, ds_id, "", "", NULLTAG, "", "", next_id );)
   <li>For any String attribute on a type.
   </ol>

   This generates the next id corresponding to the pattern of a Naming Rule that is set as a
   last used pattern in the prefernce "TC_LAST_USED_PATTERNS". This preference is used to store
   the user's last selected naming pattern for a given property of a business object in the
   context of a condition.This is a multi valued User preference.There is not default setting
   for this preference. If this preference is not set then nex id will be generated for the first
   pattern of the Naming Rule.
   <br/>If the nextId is returned as NULL either no Naming Rule is defined, or a Naming Rule without any counters is defined for the given input.
   <br/>If no Naming Rule is defined, isNRWithoutAutogen will be false.
   <br/>If a Naming Rule without counters is defined, isNRWithoutAutogen will be true.
   <br/>In both the above cases ITK_ok will be returned.

   @note Use #NR_next_rev_options to get the next value based on revision naming rule
*/
extern PROPERTY_API int NR_next_value2(
    const char* type_name,              /**< (I) Teamcenter Engineering type name, i.e. "Item" */
    const char* property_name,          /**< (I) Property name, i.e. "item_id", "item_revision_id", "object_name" */
    const tag_t item,                   /**< (I) The tag of the parent item */
    const char* ds_id,                  /**< (I) Dataset ID */
    const char* preferred_type_name,    /**< (I) Preferred type name */
    const char* default_type_name,      /**< (I) Default type name */
    const tag_t parent,                 /**< (I) Used in case of next alt ID */
    const char* rule_suffix,            /**< (I) This is only used when next revision id to be generated from a baseline rule. 'PDR' must be passed when baseline id is to be generated. */
    const char* base_revision_id,       /**< (I) Used in case of next revision ID generated from the pattern in the alt rule */
    char**      next_id,                /**< (OF) Generated next ID */
    logical*    is_nr_without_autogen   /**< (O) Determines if a valid naming rule was found but no counters were found. */
    );

/**
   Gets the next id generated for a particular input pattern in the Naming Rule
   This ITK is a generalized ITK for generating next id in case of :
   1).next item id
   2).next revision id
   3) next revision id generated from the pattern in the alt rule
   4) next alt id generated from the pattern in rule
   5) next dataset id
   6).next dataset revision id
   7) For any String attribute on a type.

   If pattern doesnot exist then next id will be NULL
*/
extern PROPERTY_API int NR_pattern_next_value(
    const char* type_name,              /**< (I) Teamcenter Engineering type name, i.e. "Item" */
    const char* property_name,          /**< (I) Property name, i.e. "item_id", "item_revision_id", "object_name"*/
    const tag_t item,                   /**< (I) The tag of the parent item */
    const char* ds_id,                  /**< (I) Dataset ID*/
    const char* preferred_type_name,    /**< (I) Preferred type name */
    const char* default_type_name,      /**< (I) Default type name */
    const tag_t parent,                 /**< (I) Used in case of next alt ID*/
    const char* rule_suffix,            /**< (I) This is only used when next revision id to be generated from a baseline rule. 'PDR' must be passed when baseline id is to be generated. */
    const char* base_revision_id,       /**< (I) Used in case of next revision ID generated from the pattern in the alt rule */
    const char* pattern,                /**< (I) The input pattern for which the next ID to be generated */
    char**      next_id                 /**< (OF)Generated next ID */
    );

/**
Description : Gets the next item ids generated of the specified quantity
              for a particular pattern in the Naming Rule for item_id property only.
   This ITK is a generalized ITK for generating single next id in case of:
   2).next revision id
   3) next revision id generated from the pattern in the alt rule
   4) next alt id generated from the pattern in rule
   5) next dataset id
   6).next dataset revision id
   7) For any String attribute on a type.

   If pattern doesnot exist then next id will be NULL
*/
extern PROPERTY_API int NR_pattern_next_values(
    const char* type_name,              /**< (I) Teamcenter Engineering type name, i.e. "Item" */
    const int   quantity,               /**< (I) no of instances of the specified type to be created */
    const char* property_name,          /**< (I) Property name, i.e. "item_id", "item_revision_id", "object_name"*/
    const tag_t item,                   /**< (I) The tag of the parent item */
    const char* ds_id,                  /**< (I) Dataset ID*/
    const char* preferred_type_name,    /**< (I) Preferred type name */
    const char* default_type_name,      /**< (I) Default type name */
    const tag_t parent,                 /**< (I) Used in case of next alt ID*/
    const char* rule_suffix,            /**< (I) This is only used when next revision id to be generated from a baseline rule. 'PDR' must be passed when baseline id is to be generated. */
    const char* base_revision_id,       /**< (I) Used in case of next revision ID generated from the pattern in the alt rule */
    const char* pattern,                /**< (I) The input pattern for which the next ID to be generated */
    char***     next_ids                /**< (OF) quantity Generated next IDs.
    <br/>This array is not packed, which means that both, the elements and the container need to be freed through a call to #MEM_free.  */
    );



/**
   Retrieves all the Naming Rule fields.
*/
extern PROPERTY_API int NR_rule_desc_with_counters2(
    tag_t       rule_tag,                   /**< (I) Naming Rule object.  */
    char**      rule_name,                  /**< (OF) Unique name of the Naming Rule.  */
    int*        n_patterns,                 /**< (O) Number of patterns of the Naming Rule.  */
    char***     patterns,                   /**< (OF) n_patterns Array of pattern strings of the Naming Rule.
                                            <br/>This array is not packed, which means that both, the elements and the container need to be freed through a call to #MEM_free.  */
    logical**   autogen,                    /**< (OF) n_patterns Array of flags, one for each pattern. Flag is true if a counter is present for the pattern and false otherwise.  */
    int**       n_counters,                 /**< (OF) n_patterns Array of counter sizes, one for each pattern. Counter size equals the number of counters present for the pattern. By default, counter size is zero.  */
    tag_t***    counter_tags                /**< (OF) n_patterns Array of counter object lists, one for each pattern. Corresponding size of a counter object list is retrieved from n_counters.
                                            <br/>This array is not packed, which means that both, the elements and the container need to be freed through a call to #MEM_free.  */
    );


/**
   Get all of the values of a NameCounter.
*/
extern PROPERTY_API int NR_ask_counter_details(
    tag_t               counter_tag,    /**< (I) The tag of the NameCounter to retrieve values from */
    char**              counter_name,   /**< (OF) The name of the counter */
    int*                no_of_chars,    /**< (O) The width of this counter */
    int*                start_pos,      /**< (O) The starting position (offset) of this counter in its parent pattern */
    char**              char_type,      /**< (OF) Type of counter */
    char**              start_value,    /**< (OF) The initial value for this counter */
    char**              max_value       /**< (OF) The maximum value for this counter */
    );


/**
    Get all revision name rule fields.
*/
extern PROPERTY_API int NR_revision_naming_rule_desc2(
        tag_t             rule_tag,                       /**< (I) */
        char              **rule_name,                    /**< (OF) */
        logical*          exclude_skip_letters,           /**< (O) */
        int*              init_rev_type,                  /**< (O) */
        char**            init_rev_start,                 /**< (OF) */
        char**            init_rev_desc,                  /**< (OF) */
        int*              sec_rev_type,                   /**< (O) */
        char**            sec_rev_start,                  /**< (OF) */
        char**            sec_rev_desc,                   /**< (OF) */
        int*              suppl_rev_format,               /**< (O) */
        char**            suppl_rev_desc                  /**< (OF) */
        );

/**
    Returns an array of all of the Revision Naming Rules objects.
*/
extern PROPERTY_API int NR_revision_naming_rule_extent(
    int*                n_tags,     /**< (O) Number of Revision Name Rule objects */
    tag_t**             rule_tags   /**< (OF) n_tags Array of Revision Name Rule tags */
    );

/**
    Finds a Revision Naming Rule object by its name.
*/
extern PROPERTY_API int NR_find_revision_naming_rule(
    char*               rule_name,  /**< (I) The unique name of a revision name rule */
    tag_t*              rule_tag    /**< (O) Tag of RevisionNameRules object */
    );

/**
    Returns an array of all of the Revision Name Rule Attach objects.
*/
extern PROPERTY_API int NR_revision_naming_rule_attach_extent(
    int*                n_tags,     /**< (O) Number of RevisionNameRuleAttach objects */
    tag_t**             field_tags  /**< (OF) n_tags Array of RevisionNameRuleAttach tags */
    );

/**
    Get all revision rule attach description.
*/
extern PROPERTY_API int NR_revision_name_rule_attach_desc(
    tag_t               attach_tag,      /**< (I) Tag of Revision Rule Attach object */
    char**              type_name,      /**< (OF) The IMANTYPE that the rule applies to */
    tag_t*              rule_tag,       /**< (O) Tag of Revision Rule Attach object*/
    int*                field_case      /**< (O) The case to automatically translate the property fields contents
                                            (#NR_CASE_MIXED, #NR_CASE_LOWER, #NR_CASE_UPPER) */
    );
/**
     Get the field case and the corresponding rule tag of the attachment
*/
extern PROPERTY_API int NR_ask_revision_naming_rule_and_case(
    char*               type_name,      /**< (I) The Item Type that the rule applies to */
    tag_t*              rule_tag,       /**< (O) Tag of Revision Naming Rule object */
    int*                field_case      /**< (O) The case to automatically translate the property fields contents

                                            (#NR_CASE_MIXED, #NR_CASE_LOWER, #NR_CASE_UPPER) */
    );
/**
    Retrieves all the available next revision values using the Revision Naming Rule attached to the type.
    <br/>If the @p item_rev is #NULLTAG, the retrieved @p init_rev_option and @p sec_rev_option will contain the values set for the initial and secondary revision IDs when the Revision Naming Rule was created in BMIDE.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#NR_rev_exausted if initial, secondary and supplemental revisions IDs are exhausted
    <li>#NR_never_matched if revision naming rule validation fails
    <li>#TYPE_unknown_type if @p item_type does not exist
    <li>#CXPOM_invalid_tag if @p item_rev is invalid
    </ul>
*/
extern PROPERTY_API int NR_next_rev_options(
        char*              item_type,        /**< (I)  The input item type that is used to evaluate the revision naming rule.
                                                       <br/>If this does not correspond to "Item" or one of its subtypes, the Revision Naming Rule cannot be evaluated and the function returns #ITK_ok. */
        tag_t              item_rev,         /**< (I)  The item revision tag used to get initial, secondary and supplemental revision values. */
        char**             init_rev_option,  /**< (OF) The initial revision value. */
        char**             sec_rev_option,   /**< (OF) The secondary revision value. */
        char**             suppl_rev_option  /**< (OF) The supplemental revision value. */
  );

/**
    Retrieves the revNameRuleAttachTag if the type name is specified
*/
extern PROPERTY_API int NR_get_rev_rule_attach(
    const char*     type_name,              /**< (I) The Item Type that the rule applies to */
    tag_t*          revNameRuleAttachTag    /**< (O) Tag of Revision Naming Rule Attach object */
    );

/**
    Validates the revision ID if a Revision Name Rule is attached to the property "item_revision_id"
*/
extern PROPERTY_API int NR_validate_rev_id_field(
    const char* type_name,             /**< (I) The Item Type that the rule applies to */
    const char* property_name,         /**< (I) Property name, i.e. "item_revision_id" */
    char*       field_value,           /**< (I) The field to be tested and, if the case is wrong,
                                                       converted to the rules field_case specification */
    const char* item_id                /**< (I) The item_id of the current item*/
    );

/**
   Validates the revision ID of a new Item Revision that is going to be created, revised or saved-as
   if a Revision Name Rule is attached to the property "item_revision_id" of the Item Revision type.
   <br/>The supplemental revision in Revision Naming Rule can be validated only using a valid item tag.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#NR_never_matched if the @p item_tag is #NULLTAG or if the @p field_value is incorrect
   <li>#TYPE_unknown_type if the @p type_name does not exist
   </ul>

   @note The Revision Naming rule is always evaluated against the "item_revision_id" property.
*/
extern PROPERTY_API int NR_validate_rev_id_field2(
           const char* type_name,             /**< (I) The Item Type that the rule applies to.
                                                       <br/>If this does not correspond to "Item" or one of its subtypes, the Revision Naming Rule cannot be evaluated and the function returns #ITK_ok. */
           const char* property_name,         /**< (I) Not needed. The evaluation always uses the property "item_revision_id". */
           char*       field_value,           /**< (I) The field to be tested and, if the case is wrong,
                                                       converted to the rules field_case specification. */
           const tag_t item_tag               /**< (I) The current item. <br/>It cannot be #NULLTAG for create, revise and save-as operations. */
    );

/**
   Generates context-specific IDs based on the given input.
   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#NR_invalid_number_of_context if @p n_contexts is 0 or negative
  </ul>
*/
extern PROPERTY_API int NR_generate_context_specific_ids(
           int          n_contexts,           /**< (I)  Number of content specific IDs to be generated. */
           const char** context_names,        /**< (I)  n_contexts The names of the context specific IDs to be generated. */
           const int*   n_ids,                /**< (I)  n_contexts The number of IDs to be geneated for each context. */
           char  ****   generated_ids,        /**< (OF) n_contexts Array of the generated IDs for each context. */
           int **       error_codes           /**< (OF) n_contexts Array of error codes for each context.
                                                 <br/>Possible values are:   <ul>
                                                 <li>#ITK_ok on success
                                                 <li>#NR_invalid_context_name if the context name is invalid (empty or more than #NR_CONTEXT_NAME_MAX_LENGTH characters)
                                                 <li>#NR_invalid_number_of_id if the number of ID is invalid (0 or negative value)
                                                   </ul> */

    );

/**
  Resets the internal counter used for generation of IDs specific to the given set of contexts.
  <br/> This ensures that further ID generation for the given contexts will start from the beginning.
  @returns
  <ul>
  <li>#ITK_ok on success
  <li>#NR_invalid_number_of_context if values of @p n_contexts is 0 or negative
  </ul>
*/
extern PROPERTY_API int NR_reset_context_specific_ids(
           int          n_contexts,           /**< (I)  Number of content specific IDs to be reset. */
           const char** context_names,        /**< (I)  n_contexts The names of the context specific IDs to be reset. */
           int**        error_codes           /**< (OF) n_contexts Array of error codes for each context.
                                                 <br/>Possible values are:   <ul>
                                                 <li>#ITK_ok on success
                                                 <li>#NR_invalid_context_name_reset if the context name is invalid (empty or non-existing context name)
                                                 </ul> */

   );

/**
  Generates Item IDs in bulk using either a Naming Rule Pattern with auto-generation if available, or the legacy Counter otherwise.
  <br/>The value is to be used for the property "item_id".
  <br/>Prefixes and suffixes are added to the IDs according to the values of the ITEM_id_prefix and ITEM_id_postfix preferences:
  @returns
  <ul>
  <li>#ITK_ok on success
  <li>#TYPE_unknown_type if @p type_name is empty or not a valid Teamcenter type
  <li>#NR_no_autogen if @p quantity is greater than 1 and the Naming Rule pattern is defined without auto-generation
  </ul>
*/
extern PROPERTY_API int NR_generate_item_ids(
        const tag_t     old_item,           /**< (I) Object instance used to provide a seed value for the "save as" operations.
                                                     <br/>A value of #NULLTAG can be provided if a new number is requested for bulk ID creation.
                                                     <br/>If @p old_item is invalid, IDs are generated without considering it.*/
        const char*     type_name,          /**< (I) Name of the type of Item for which to create the ID */
        const int       quantity,           /**< (I) Number of IDs to be created. */
        logical**       mod,                /**< (OF) quantity Specifies if the logged-in user has the right
                                                      to modify the returned IDs.
                                                      <br/>Note: The preference "ASSIGNED_ITEM_ID_MODIFIABLE" is used to
                                                        determine whether the ID should be modifiable. */
        char***         ids                 /**< (OF) quantity The array of generated IDs.
                                               <br/>The array is packed, which means that the memory is to be deallocated by calling
                                               #MEM_free on the container only.*/
    );


/**
    Executes customization if any and retrieves the Item IDs for the requested quantity.
    <br/>In case the customizations are absent, no ID is generated and @p ids is NULL, which means that the caller must also check the returned pointer prior to using it.
    <br/>Customizations are executed in a priority order. In case a custom User Exit is present, its execution would precede the custom callback function execution.
    <br/>#USER_new_item_id customization is executed if a single ID is requested.
    <br/>#USER_new_item_ids customization is executed if multiple IDs are requested. In case #USER_new_item_ids customization is absent, #USER_new_item_id customization is invoked @p quantity number of times.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#NR_invalid_qunatity_value if @p quantity is zero
    <li>Other errors returned by the customization
    </ul>
*/
extern PROPERTY_API int NR_execute_extensions(
        const tag_t         old_item,           /**< (I) Tag which provides a seed value for saveAs. May be a #NULLTAG if a new number is requested for bulk IDs creation. */
        const tag_t         item_type,          /**< (I) Tag of the Item type which is being created. */
        const int           quantity,           /**< (I) Number of IDs to be created. */
        logical*            mod,                /**< (O) Indicates whether generated IDs are modifiable. */
        char***             ids,                /**< (OF) quantity Array of generated IDs.
                                                   <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only.*/
        int*                decision            /**< (O) Indicates if the customization is applicable. */
    );

/**
    Executes customization corresponding to an Item type if any and retrieves the Item IDs for the requested quantity.
    <br/>In case the customizations are absent, an empty ID is output, which means that the caller must also check if the generated ID is valid before using it.
    <br/>Customizations are executed in a priority order. In case a custom User Exit is present, its execution would precede the custom callback function execution.
    <br/>#USER_new_item_id customization is executed if a single ID is requested.
    <br/>#USER_new_item_ids customization is executed if multiple IDs are requested. In case #USER_new_item_ids customization is absent, #USER_new_item_id customization is invoked @p quantity number of times.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#NR_invalid_qunatity_value if @p quantity is zero
    <li>Other errors returned by the customization
    </ul>
*/
extern PROPERTY_API int NR_execute_extensions_for_saveas(
    const int          n_items,                 /**< (I) Number of objects provided as input. */
    const tag_t*       items,                   /**< (I) n_items The Items required to generate ids. */
    logical**          is_modifiable,           /**< (OF) n_items Indicates if the generated IDs are modifiable. */
    char***            ids,                     /**< (OF) n_items The array of generated IDs.
                                                   <br/>The array is packed, which means that the memory is to be deallocated by calling
                                                   #MEM_free on the container only. */
    int**              decisions                /**< (OF) Indicates if the customization was used. */
    );


/**
  Generates Item IDs in bulk during the "Save As" operation of Item objects using either a Naming Rule Pattern with auto-generation if available, or the legacy counter otherwise.
  <br/>The value is to be used for the property "item_id".
  @returns
  <ul>
  <li>#ITK_ok on success
  <li>#CXPOM_invalid_tag if any member of @p items is #NULLTAG.
  <li>#NR_invalid_qunatity_value if @p quantity is zero.
  <li>#PROP_not_found if any member of @p items is not an Item.
  <li>#ITK_ok on success
  </ul>
*/
extern PROPERTY_API int NR_generate_item_ids_for_saveas(
    const int             n_items,                /**< (I)  Number of objects provided as input. */
    const tag_t*          items,                  /**< (I)  n_items The Items required to generate ids. */
    logical**             is_modifiable,          /**< (OF) n_items Indicates if the generated IDs are modifiable. */
    char***               ids                     /**< (OF) n_items The array of generated IDs.
                                                     <br/>The array is packed, which means that the memory is to be deallocated by calling
                                                     #MEM_free on the container only. */
    );

/**
  Generates Item IDs in bulk during the "Save As" operation of Item objects using either a Naming Rule Pattern with auto-generation if available, or the legacy counter otherwise.
  <br/>This function is required, because to generate custom ids operation input is needed. This function will generate custom ids during saveas by taking operation input as parameter.
  <br/>The value is to be used for the property "item_id".
  @returns
  <ul>
  <li>#ITK_ok on success
  <li>#CXPOM_invalid_tag if any member of @p items is #NULLTAG.
  <li>#NR_invalid_qunatity_value if @p quantity is zero.
  <li>#PROP_not_found if any member of @p items is not an Item.
  </ul>
*/
extern PROPERTY_API int NR_generate_item_ids_for_saveas2(
    const tag_t*          operation_input,        /**< (I)  Number of Operation Inputs. */
    const int             n_items,                /**< (I)  Number of Items. */
    const tag_t*          items,                  /**< (I)  n_items The Items required to generate IDs. */
    logical**             is_modifiable,          /**< (OF) n_items Indicates if the generated IDs are modifiable. */
    char***               ids                     /**< (OF) n_items The array of generated IDs.
                                                     <br/>The array is packed, which means that the memory is to be deallocated by calling
                                                     #MEM_free on the container only. */
    );

/** @} */

/** @} */

#ifdef __cplusplus
}
#endif

#include <property/libproperty_undef.h>

#endif
