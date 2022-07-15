/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This file contains the interface to identifier data manipulation. For other
    related interfaces please review the related topics in the users guide and
    review the appropriate header files.
*/

/*  */

#ifndef IDFR_H
#define IDFR_H

#include <tc/tc_startup.h>
#include <common/emh_const.h>
#include <tccore/idfr_errors.h>
#include <user_exits/user_exits.h>
#include <tccore/libtccore_exports.h>

/**
    @defgroup IDFR Identifier

    Not all Teamcenter objects such as form storage class,
    type definitions, etc. are allowed to have additional ids.
    So, an identifiable is an abstract term to describe types of
    Teamcenter objects that are allowed to have additional ids.
    In V9.0 of Teamcenter, only items and item revisions will be valid identifiable objects.

    An identifier defines id in some IdContext. 
    All ids in a given context (IdContext + Supplemental Context) are unique.
    A site can sub-class Identifier when additional attributes are desired with the specification of an id.
    They can sub-type an Identifier or any of its sub-classes when
    different behavior is desired but additional attributes are not needed.

    An identifier can be an Alternate identifier for an object as well as
    an Alias identifier for other objects at the same time.
    Similar to item, the ids of an identifier are supposed to be case insensitively unique.
    To support that properly, the administrator must install a unique functional index. 
    Not doing so will severely degrade performance.

    Use AOM functionality to refresh, save, and delete identifier objects.
    Use #MEM_free to release allocated storage.
    Use AOM_ask_value and AOM_set_value functionality to ask/set custom properties or commercial properties.

    All types of Identifier support the following messages:
    <ol>
    <li>#IDENTIFIER_create_alternate_msg
    <li>#IDENTIFIER_revise_alternate_msg
    <li>#IDENTIFIER_saveas_alternate_msg
    <li>#IDENTIFIER_create_alias_msg
    <li>#TC_save_msg
    <li>#TC_delete_msg
    <li>#TC_refresh_msg
    <li>#TC_import_msg
    <li>#TC_export_msg
    <li>#TCTYPE_createprops_msg
    <li>#TCTYPE_viewerprops_msg
    </ol>
    @{
*/

/**
    @name IDENTIFIER class name and property name constants
    @{
*/
#define IDENTIFIER_class_name_c          "Identifier"
#define IDENTIFIER_rev_type_name_c       "IdentifierRev"
#define IDENTIFIER_id                    "idfr_id"
#define IDENTIFIER_idcontext             "idcontext"
#define IDENTIFIER_altidof               "altid_of"
#define IDENTIFIER_dispdefault           "disp_default"
#define IDENTIFIER_supplcontext          "suppl_context"
#define ALIASID_relation                 "IMAN_aliasid"
/** @} */

/**
    @name Messages unique to IDENTIFIER
    @{
*/
#define IDENTIFIER_create_alternate_msg  "IDENTIFIER_create_alternate"
#define IDENTIFIER_revise_alternate_msg  "IDENTIFIER_revise_alternate"
#define IDENTIFIER_saveas_alternate_msg  "IDENTIFIER_saveas_alternate"
#define IDENTIFIER_create_alias_msg      "IDENTIFIER_create_alias"
/** @} */

#ifdef __cplusplus
extern "C"{
#endif

/**
    Creates a new Alias identifier in memory of the given type, but does not save it in the database.
    It supports #IDENTIFIER_create_alias_msg. 

    If identifier_type is null, base type of "Identifier" is assumed. 

    If the system administrator has not configured the IdContextRule to allow the given combination as
    a valid alias identifier creation, the create will fail.

    @note From Tc9.0 onwards, please use generic creation of BusinessObject (i.e. createBusinessObject (C++) or #TCTYPE_create_object).
*/
extern TCCORE_API int IDFR_create_aliasid (
    const char*         identifier_type,    /**< (I) Type of Alias identifier instance to be created */
    tag_t*              new_identifier_tag  /**< (O) Tag of new Alias identifier */
    );

/**
   Creates a new master alternate identifier of type \<identifier type\> and a 
   new supplemental alternate identifier of type \<identifier type\>Rev in memory for
   an identifiable and identifiable revision in the given identifier context. 
   It does not save these objects in the database. 
   
   This call should be used directly to create a master alternate and supplemental alternate identifier.
   This function supports #IDENTIFIER_create_alternate_msg. 
   
   For both the Master and Supplemental identifiers to be created, the system administrator needs to
   configure the IdContextRule:
   <ul>
   <li>idfbl_type, identifier_type, and idcontext as well as
   <li>idfbl_rev_type, identifier_type+"Rev", and idcontext
   </ul>
   
    If the IdContextRule for the Supplemental (Rev) is not configured, this call will 
    create only a Master alternate identifier.
    If the idfbl_rev_tag is null, this call will create only a Master alternate identifier.
    
    @note From Tc9.0 onwards, please use generic creation of BusinessObject (i.e. createBusinessObject (C++) or #TCTYPE_create_object).
    
    @code To use the TCTYPE_create_object ITK instead of IDFR_create_altid
    
    try
    {
        int ifail = ITK_ok;
        ResultStatus rStat = ITEM_create_item ("0012345", "Item_001", "A2MyItem1", "A", &itemTag, &revTag)
        rStat = ITEM_save_item( itemTag )
        rStat = IDCXT_find_idcontext("A2Icx1", &contextTag) //A2Icx1 is the context

        string altId_name = "AltId1"
        char* altId_Id = "000"

        tag_t identifierType = NULLTAG;
        rStat = TCTYPE_find_type( "A2Idfr1", "", &identifierType )
        rStat = TCTYPE_construct_create_input( identifierType, &altIdCreInTag )
        rStat = AOM_set_value_string( altIdCreInTag, "object_name", altId_name )
        tag_t altIdTag = NULLTAG
        rStat = TCTYPE_create_object( altIdCreInTag, &altIdTag )

        rStat = IDFR_set_id( altIdTag, altId_Id )
        rStat = IDFR_set_idcontext( altIdTag, contextTag )
        rStat = IDFR_set_altidof( altIdTag, itemTag )
        rStat = IDFR_set_supplcontext( altIdTag, NULLTAG )
        rStat = AOM_save( altIdTag )

        string altRevId_name = "AltRevId1"
        char* altRevId_Id = "000"

        tag_t identifierRevType = NULLTAG
        rStat = TCTYPE_find_type( "A2Idfr1Rev", "", identifierRevType )
        rStat = TCTYPE_construct_create_input( identifierRevType, &altRevIdCreInTag )
        rStat = AOM_set_value_string( altRevIdCreInTag, "object_name", altRevId_name )
        tag_t altRevIdTag = NULLTAG
        rStat = TCTYPE_create_object( altRevIdCreInTag, &altRevIdTag )

        rStat = IDFR_set_id( altRevIdTag, altRevId_Id )
        rStat = IDFR_set_idcontext( altRevIdTag, contextTag )
        rStat = IDFR_set_altidof( altRevIdTag, revTag )
        rStat = IDFR_set_supplcontext( altRevIdTag, altIdTag ) //Note: The supplemental context points to the item level identifier instance if the instance is of revision level identifier else it is NULL for item level identifier object.
        rStat = AOM_save( altRevIdTag )
    }
    catch( const IFail& ex )
    {
        ifail = ex.ifail();
        Teamcenter::CoreModelGeneral::tccore::logger()->error( ERROR_line, ifail, "Custom Message" );
    }

    @endcode
*/
extern TCCORE_API int IDFR_create_altid (
    const char*         identifier_type,    /**< (I) Type of Alternate identifier instance to be created */
    tag_t               idfbl_tag,          /**< (I) Tag of existing identifiable item object */
    tag_t               idfbl_rev_tag,      /**< (I) Tag of existing identifiable item Revision object */
    tag_t               idcontext_tag,      /**< (I) Tag of identifier context object */
    tag_t*              altid_tag,          /**< (O) Tag of new (master) alternate identifier */
    tag_t*              altid_rev_tag       /**< (O) Tag of new supplemental alternate identifier */
    );

/**
   Creates a new Alternate revision identifier in memory for a given master or
   supplemental alternate identifier and item revision identifiable, but does not save it in the database. 
   
   This call should be used directly to revising an existing master or supplemental alternate identifier.  
   
   In case there is no IdContextRule for the Supplemental, this call would return an error.
*/
extern TCCORE_API int IDFR_revise_altid (
    tag_t               altid_or_rev_tag,   /**< (I) Tag of existing master or supplemental alternate identifier */
    tag_t               idfbl_rev_tag,      /**< (I) Tag of existing identifiable item revision object */
    tag_t*              new_altid_rev_tag   /**< (O) Tag of new supplemental alternate identifier */
    );

/**
   Creates a new Alternate saveas identifier in memory for a given supplemental alternate identifier,
   but does not save it in the database.

   This call should be used directly to saveas an existing supplemental alternate identifier. 
*/
extern TCCORE_API int IDFR_saveas_altid (
    tag_t               altid_rev_tag,      /**< (I) Tag of existing supplemental alternate revision identifier */
    tag_t               idfbl_rev_tag,      /**< (I) Tag of identifiable to which new alternate revision identifier to be saved as*/
    tag_t*              new_altid_rev_tag   /**< (O) Tag of new revision alternate identifier */
    );

/**
   Retrieves the identifiable objects for which the given identifier is an Alias.
*/
extern TCCORE_API int IDFR_ask_aliasidof (
    tag_t               identifier_tag,     /**< (I) Tag of existing identifier */
    int*                num_identifiables,  /**< (O) Number of identifiable objects */
    tag_t**             identifiable_tags   /**< (OF) num_identifiables An array of tags to identifiable objects */
    );

/**
    Retrieves the identifiable object for which the given identifier is an Alternate. 

    <b>Restrictions:</b> The altidof property cannot be set.
*/
extern TCCORE_API int IDFR_ask_altidof (
    tag_t               identifier_tag,     /**< (I) Tag of existing identifier */
    tag_t*              identifiable_tag    /**< (O) Tag of identifiable object */
    );

/**
    Retrieves the ID attribute of the identifier. 
*/
extern TCCORE_API int IDFR_ask_id (
    tag_t               identifier_tag,     /**< (I) Tag of existing identifier */
    char**              identifier_id       /**< (OF) Id attribute value for the given identifier */
    );

/**
    Retrieves the reference to the idcontext object of the identifier.

    <b>Restrictions:</b> The idcontext property cannot be set.
*/
extern TCCORE_API int IDFR_ask_idcontext (
    tag_t               identifier_tag,     /**< (I) Tag of existing identifier */
    tag_t*              idcontext_tag       /**< (O) Tag of idcontext reference to the identifier */
    );

/**
    If the identifier is a supplemental alternate, 
    the returned tag is that of the master alternate identifier of which it is a supplemental. 
    Otherwise, the returned tag will be null tag.

    <b>Restrictions:</b> The supplcontext property cannot be set.
*/
extern TCCORE_API int IDFR_ask_supplcontext (
    tag_t               identifier_tag,     /**< (I) Tag of existing identifier */
    tag_t*              supplcontext_tag    /**< (O) Tag of Alternate identifier or null tag */
    );

extern TCCORE_API int IDFR_set_altidof (
    tag_t               identifier_tag,     /**< (I) */
    tag_t               identifiable_tag    /**< (I) */
    );

/**
    Sets the id attribute of the identifier.  
    If the given identifier tag is a master alternate, 
    and any of its supplemental alternates are released,
    you will not be able to modify this.
*/
extern TCCORE_API int IDFR_set_id (
    tag_t               identifier_tag,     /**< (I) Tag of existing identifier */
    const char*         identifier_id       /**< (I) Id attribute value for the given identifier */
    );

extern TCCORE_API int IDFR_set_idcontext (
    tag_t               identifier_tag,     /**< (I) */
    tag_t               idcontext_tag       /**< (I) */
    );

extern TCCORE_API int IDFR_set_supplcontext (
    tag_t               identifier_tag,     /**< (I) */
    tag_t               supplcontext_tag    /**< (I) */
    );

/**
    Retrieves an alternate identifier value for the given identifier type value in the given idcontext.
*/
extern TCCORE_API int IDFR_new_alt_id (
    tag_t               idcontext_tag,  /**< (I) Tag of idcontext reference to the identifier */
    const char*         idfr_type,      /**< (I) Alternate identifier type value */
    char**              new_id          /**< (OF) New alternate id attribute value */
    );

/**
    Retrieves an alternate identifier value and an alternate identifier revision value for the
    given identifier type value in the given idcontext.
    The identifier revision value will be returned as null, in case the Supplemental IdContext rule is not defined.
*/
extern TCCORE_API int IDFR_new_alt_ids (
    tag_t               idcontext_tag,  /**< (I) Tag of idcontext reference to the identifier */
    const char*         idfr_type,      /**< (I) Alternate identifier type value */
    char**              new_id,         /**< (OF) New alternate id attribute value */
    char**              new_rev_id      /**< (OF) New alternate revision id attribute value */
    );

/**
    Retrieves an alternate identifier revision value for the given identifier revision tag.
*/
extern TCCORE_API int IDFR_new_rev_id (
    tag_t               idfr_rev_tag,   /**< (I) Tag of alternate identifier revision */
    char**              new_rev_id      /**< (OF) New alternate revision id attribute value */
    );

extern TCCORE_API int IDFR_validate_alt_id (
    tag_t               idcontext_tag,  /**< (I) */
    const char*         idfr_type,      /**< (I) */
    const char*         new_id,         /**< (I) */
    const char*         pattern_name,   /**< (I) */
    char**              modified_id,    /**< (OF) */
    IDValid_e*          status          /**< (O) */
    );

extern TCCORE_API int IDFR_validate_alt_ids (
    tag_t               idcontext_tag,      /**< (I) */
    const char*         idfr_type,          /**< (I) */
    const char*         new_id,             /**< (I) */
    const char*         new_rev_id,         /**< (I) */
    const char*         pattern_name,       /**< (I) */
    char**              modified_id,        /**< (OF) */
    char**              modified_rev_id,    /**< (OF) */
    IDValid_e*          status              /**< (O) */
    );

extern TCCORE_API int IDFR_validate_rev_id (
    tag_t               idfr_rev_tag,   /**< (I) */
    const char*         new_rev_id,     /**< (I) */
    const char*         pattern_name,   /**< (I) */
    char**              modified_id,    /**< (OF) */
    IDValid_e*          status          /**< (O) */
    );

/**
    Adds the given identifier as an Alias id for the given identifiable objects. 
*/
extern TCCORE_API int IDFR_add_aliasidof (
    tag_t               identifier_tag,     /**< (I) Tag of existing identifier */
    int                 num_identifiables,  /**< (I) Number of identifiable objects */
    tag_t*              identifiable_tags   /**< (I) An array of tags to identifiable objects */
    );

/**
    Removes the given identifier as an Alias for the given identifiable objects.
*/
extern TCCORE_API int IDFR_remove_aliasidof (
    tag_t               identifier_tag,     /**< (I) Tag of existing identifier */
    int                 num_identifiables,  /**< (I) Number of identifiable objects */
    tag_t*              identifiable_tags   /**< (I) An array of tags to identifiable objects */
    );

/**
    Retrieves all the identifiers that have the given id in the given idcontext. 
    Uses case-insensitive search and allows wildcards in id.  
    If idcontext_tag is null tag, the search is performed on all idcontexts. 
    It returns all identifiers including those for which the user may not have read permission.
*/
extern TCCORE_API int IDFR_find_identifiers (
    const char*         id,                 /**< (I) Id attribute value for the given identifier */
    tag_t               idcontext_tag,      /**< (I) Tag of idcontext reference to the identifier or null tag */
    int*                num_identifiers,    /**< (O) Number of identifier objects */
    tag_t**             identifier_tags     /**< (OF) num_identifiers An array of tags to identifier objects */
    );

/**
    Retrieves all supplemental alternate identifiers associated with the given master alternate.
*/
extern TCCORE_API int IDFR_list_suppl_identifiers(
    tag_t               master_idfr_tag,    /**< (I) Tag of existing master identifier */
    int*                num_suppl,          /**< (O) Number of supplemental alternate objects */
    tag_t**             suppl_idfr_tags     /**< (OF) num_suppl An array of tags to supplemental alternate objects */
    );

/**
    Performs a case insensitive search with wildcards for id of supplemental alternates given the master alternate.
    It could return zero supplemental alternates.
*/
extern TCCORE_API int IDFR_find_suppl_identifiers(
    tag_t               master_idfr_tag,    /**< (I) */
    const char*         suppl_id,           /**< (I) Id of the desired supplemental. Wildcards allowed.
                                                Case insensitive search is performed. */
    int*                num_suppl,          /**< (O) Number of supplemental alternate objects */
    tag_t**             suppl_idfr_tags     /**< (OF) num_suppl An array of tags to supplemental alternate objects */
    );

/**
    Retrieves the Alternate identifier that is the display default identifier of the identifiable.  
    The output could be a null tag if there is no default. 
*/
extern TCCORE_API int IDFR_idfbl_ask_disp_default (
    tag_t               identifiable_tag,   /**< (I) Tag of identifiable object */
    tag_t*              altid_tag           /**< (O) Tag of the default Alternate identifier or null tag */
    );

/**
    Sets the given Alternate identifier as the display default identifier of the identifiable.  
    The input altid_tag could be a null tag to remove the default.
    To change the default, the user needs to have write access to the identifiable, 
    existing default identifier if any, and new default identifier if any.
*/
extern TCCORE_API int IDFR_idfbl_set_disp_default (
    tag_t               identifiable_tag,   /**< (I) Tag of identifiable object */
    tag_t               altid_tag           /**< (I) Tag of the new default Alternate identifier or null tag */
    );

/**
    Finds and Alternate identifier, given an identifiable and identifier display rule that satisfies the rule.  
    If the identifiable does not have any identifier in the contexts specified by the rule, the function returns a null tag.  
    If the iddisprule_tag is null tag, the current display rule of the user is assumed. 
*/
extern TCCORE_API int IDFR_idfbl_ask_disp_altid (
    tag_t               identifiable_tag,   /**< (I) Tag of identifiable object */
    tag_t               iddisprule_tag,     /**< (I) Tag of identifier display rule object or null tag */
    tag_t*              altid_tag           /**< (O) Tag of the Alternate identifier or null tag */
    );

/**
    Lists all Alternate identifiers associated to a given identifiable.
    The user may not have read permission to all the returned alternates.
*/
extern TCCORE_API int IDFR_idfbl_list_altids (
    tag_t               identifiable_tag,   /**< (I) Tag of identifiable object */
    int*                num_altids,         /**< (O) Number of Alternate identifiers */
    tag_t**             altid_tags          /**< (OF) num_altids An array of tags to Alternate identifier objects */
    );

/**
    Lists all Alias identifiers associated to a given identifiable.
    The user may not have read permission to all the returned aliases.
*/
extern TCCORE_API int IDFR_idfbl_list_aliasids (
    tag_t               identifiable_tag,   /**< (I) Tag of identifiable object */
    int*                num_aliases,        /**< (O) Number of Alias identifiers */
    tag_t**             aliasid_tags        /**< (OF) num_aliases An array of tags to Alias identifier objects */
    );

/**
    A case-insensitive search performed to find the Alternate identifiers of a given identifiable with a given id.  
    If id in context is implemented, this search can find more than one Alternate identifier that meets the criteria.  
    The user may not have read permission to all the returned alternates.
*/
extern TCCORE_API int IDFR_idfbl_find_altids (
    tag_t               identifiable_tag,   /**< (I) Tag of identifiable object */
    const char*         id,                 /**< (I) Id attribute value for the given identifiable object */
    tag_t               idcontext_tag,      /**< (I) */
    int*                num_altids,         /**< (O) Number of Alternate identifiers */
    tag_t**             altid_tags          /**< (OF) num_altids An array of tags to Alternate identifier objects */
    );

/**
    Retrieves all the identifiable objects that have the given Alternate identifier in the given idcontext
    and are of the given identifiable class or its subclasses.
    Uses case-insensitive search and allows wildcards in id.
    If idcontext_tag is null tag, the search is performed on all idcontexts for the given id.
    If identifiable_class_tag is null tag, the returned identifiable objects can be of any class.
    The user may not have read permission to all the returned alternates.
*/
extern TCCORE_API int IDFR_idfbl_find_altidsof (
    const char*         id,                         /**< (I) Id attribute value for the given identifier */
    tag_t               idcontext_tag,              /**< (I) Tag of idcontext reference to the Alternate identifier or null tag */
    tag_t               identifiable_class_tag,     /**< (I) Tag of class of the identifiable object or null tag */
    int*                num_identifiables,          /**< (O) Number of identifiable objects */
    tag_t**             identifiable_tags           /**< (OF) num_identifiables An array of tags to identifiable objects */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <tccore/libtccore_undef.h>

#endif
