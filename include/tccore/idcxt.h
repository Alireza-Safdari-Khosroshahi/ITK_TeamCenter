/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This file contains the interface to idcontext data manipulation. For other
    related interfaces for say, archive, backup and change control please
    review the related topics in the users guide and review the appropriate
    header files.
*/

/*  */

#ifndef IDCXT_H
#define IDCXT_H

#include <tc/tc_startup.h>
#include <common/emh_const.h>
#include <tccore/idcxt_errors.h>
#include <tccore/libtccore_exports.h>

/**
    @defgroup IDCXT IdContext

    An id is defined in a context. 
    The initial ids of an item (item_id) as well as item revision (item_revision_id)
    are conceptually defined in a Teamcenter Engineering Site context.

    All ids in a given context are unique. 
    However, the item revision defines its revision id as a unique revision id in the context of its owning item.
    Thus, an id is considered defined in an IdContext as well as a Supplemental Context.
    The initial ids are defined in a conceptual IdContext of value null.

    An IdContext defines a context for an id.  
    Names of IdContexts are unique within a Teamcenter Engineering site.  
    To ensure the case insensitive uniqueness of IdContext names,
    a site administrator must install a functional index, otherwise performance will be negatively impacted.
    Only an administrator should be able to create/delete/modify an IdContext.

    For most objects, the supplemental context is null.  
    Thus, they define an id that is unique within the IdContext.  
    However, item revisions define an id that is unique within the IdContext and Supplemental Context
    (Alternate id of the owning item).

    Use AOM functionality to refresh, save, and delete idcontext objects.  
    Use #MEM_free to release allocated storage.

    <b>IDCXT – IdContext Functions</b>

    Messages Supported By IdContext

    All types of IdContext class and its sub-classes support the following messages:
    <ol>
    <li>#TCTYPE_createprops_msg
    <li>#TCTYPE_viewerprops_msg
    </ol>

    @{
*/

/**
    @name IDCONTEXT class name and property name constants
    @{
*/
#define IDCONTEXT_class_name_c          "IdContext"
#define IDCONTEXT_name                  "idcxt_name"
#define IDCONTEXT_description           "idcxt_desc"
/** @} */

/**
    @name IDCONTEXTRULE class name and property constants
    @{
*/
#define IDCONTEXTRULE_class_name_c      "IdContextRule"
#define IDCONTEXTRULE_idfbl_type        "idfbl_type"
#define IDCONTEXTRULE_idfr_type         "idfr_type"
#define IDCONTEXTRULE_idcontext         "idcontext"
#define IDCONTEXTRULE_rule              "idcxt_rule"
/** @} */

#ifdef __cplusplus
    extern "C"{
#endif

/**
    Returns the name attribute for the given idcontext.  
*/
extern TCCORE_API int IDCXT_ask_name (
    tag_t               idcontext_tag,  /**< (I) Tag of existing idcontext */
    char**              name            /**< (OF) Name attribute value for the given idcontext */
    );

/**
    Returns the description attribute for the given idcontext. 
*/
extern TCCORE_API int IDCXT_ask_description (
    tag_t               idcontext_tag,  /**< (I) Tag of existing idcontext */
    char**              description     /**< (OF) Description attribute value for the given idcontext */
    );

/**
    Returns all the idcontext objects that have the given name. 
    Uses case-insensitive search and allows wildcards in name.
*/
extern TCCORE_API int IDCXT_find (
    const char*         name,               /**< (I) Name attribute value of an idcontext */
    int*                num_idcontexts,     /**< (O) Number of idcontext objects */
    tag_t**             idcontext_tags      /**< (OF) num_idcontexts An array of tags to idcontext objects */
    );

/**
    Returns one idcontext object that has the given name. 
    Uses case-insensitive search and allows wildcards in name. 
    An error will be returned if more than one name is qualified in the search.
*/
extern TCCORE_API int IDCXT_find_idcontext (
    const char*         name,           /**< (I) Name attribute value of an idcontext */
    tag_t*              idcontext_tag   /**< (O) Tag of idcontext object */
    );

/** @} */

/**
    @name IdContext Rule Functions

    <b>Messages Supported By IdContextRule</b>

    All types of IdContextRule class and its sub-classes support the following messages:
    <ol>
    <li>#TCTYPE_createprops_msg
    <li>#TCTYPE_viewerprops_msg
    </ol>
    @{
*/

/**
    Returns the reference to the idcontext object of the idcontextrule. 
*/
extern TCCORE_API int IDCXT_rule_ask_idcontext (
    tag_t               idcontextrule_tag,  /**< (I) Tag of existing idcontextrule */
    tag_t*              idcontext_tag       /**< (O) Tag of idcontext reference to the idcontextrule */
    );

/**
    Returns the reference to the identifier type object of the idcontextrule. 
*/
extern TCCORE_API int IDCXT_rule_ask_identifier_type (
    tag_t               idcontextrule_tag,      /**< (I) Tag of existing idcontextrule */
    tag_t*              identifier_type_tag     /**< (O) Tag of identifier type to the idcontextrule */
    );

/**
    Returns the reference to the identifiable object type of the idcontextrule.
    When this is #NULLTAG, then the rule defines the alias usage.
*/
extern TCCORE_API int IDCXT_rule_ask_idfbl_type (
    tag_t               idcontextrule_tag,      /**< (I) Tag of existing idcontextrule */
    tag_t*              identifiable_type_tag   /**< (O) Tag of identifiable type object in the idcontextrule */
    );

/**
    Returns the rule value for the given idcontextrule. 
*/
extern TCCORE_API int IDCXT_rule_ask_rule (
    tag_t               idcontextrule_tag,  /**< (I) Tag of existing idcontextrule */
    char**              rule                /**< (OF) Rule value for the given idcontextrule. Can be null */
    );

/**
    Returns all the Alternate identifier rules in the database.
    Does not filter out restrictions caused due to hide type restrictions.
*/
extern TCCORE_API int IDCXT_rule_list_altid_rules (
    int*                num_rules,          /**< (O) Number of rules */
    tag_t**             idcontext_tags,     /**< (OF) num_rules Array of idcontext tags */
    tag_t**             idfbl_type_tags,    /**< (OF) num_rules Array of identifiable type tags */
    tag_t**             idfr_type_tags,     /**< (OF) num_rules Array of identifier type tags */
    char***             rules               /**< (OF) num_rules Array of rules. Some of the elements could be null. */
    );

/**
    Returns all the alias identifier rules in the database.
    Does not filter out restrictions caused due to hide type restrictions.
*/
extern TCCORE_API int IDCXT_rule_list_aliasid_rules (
    int*                num_rules,          /**< (O) Number of rules */
    tag_t**             idcontext_tags,     /**< (OF) num_rules Array of idcontext tags */
    tag_t**             idfr_type_tags      /**< (OF) num_rules Array of identifier type tags */
    );

/**
    Returns all allowed Alternate identifier rules in the database.
    It filters out restrictions caused due to hide type configuration.
*/
extern TCCORE_API int IDCXT_rule_ui_altid_rules (
    int*                num_rules,          /**< (O) Number of rules */
    tag_t**             idcontext_tags,     /**< (OF) num_rules Array of idcontext tags */
    tag_t**             idfbl_type_tags,    /**< (OF) num_rules Array of identifiable type tags */
    tag_t**             idfr_type_tags,     /**< (OF) num_rules Array of identifier type tags */
    char***             rules               /**< (OF) num_rules Array of rules. Some of the elements could be null. */
    );

/**
    Returns all allowed alias identifier rules in the database. 
    It filters out restrictions caused due to hide type configuration.
*/
extern TCCORE_API int IDCXT_rule_ui_aliasid_rules (
    int*                num_rules,          /**< (O) Number of rules */
    tag_t**             idcontext_tags,     /**< (OF) num_rules Array of idcontext tags */
    tag_t**             idfr_type_tags      /**< (OF) num_rules Array of identifier type tags */
    );

/**
    Returns rule associated with the given combination.
*/
extern TCCORE_API int IDCXT_rule_find_rule(
    tag_t               idcontext_tag,      /**< (I) Idcontext tag */
    tag_t               idfbl_type_tag,     /**< (I) Identifiable type tag */
    tag_t               idfr_type_tag,      /**< (I) Identifier type tag */
    char**              rule                /**< (OF) Rule for the combination above. Can be null. */
    );

/**
    Returns all the Alternate identifier contexts in the database.
*/
extern TCCORE_API int IDCXT_rule_list_altid_contexts (
    int*                num_rules,          /**< (O) Number of rules */
    tag_t**             idcontext_tags     /**< (OF) num_rules Array of idcontext tags */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <tccore/libtccore_undef.h>

#endif
