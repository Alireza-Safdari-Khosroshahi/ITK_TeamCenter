/*
 @<COPYRIGHT_START>@
 ===============================================
 Copyright 2006 UGS Corp. All Rights Reserved.
 ===============================================
 @<COPYRIGHT_END>@
*/



/**
    @file

    This header file declares functions for manipulating ADA (Authorized Data Access) licenses.
    An ADA license is used to grant time limited access to a list of users and/or groups identified
    in the license. Users that would be denied access to a Workspace Object because they have
    insufficient IP (Intelectual Property) or Gov (Governmental) clearance can be given special
    access by listing them or their group in a license and attaching the license to the Workspace
    Object. A license has a type associated with it to specify which kind of clearance it can
    override, IP or Gov.
*/

#ifndef ADA_LICENSE_H
#define ADA_LICENSE_H

#include <unidefs.h>
#include <tc/tc_startup.h>
#include <tccore/libtccore_exports.h>

/**
    @defgroup ADA_License License
    @{
*/

#define ADA_license_id_size_c         128
#define ADA_license_reason_size_c     128
#define ADA_group_name_size_c         256
#define ADA_license_InAccrWith_size_c  80
#define ADA_ip_admin_role             "IP Admin"
#define ADA_itar_admin_role           "ITAR Admin"
#define ADA_site_admin_role           "ADA Site Admin"
#define ADA_itar_classifier_role      "ITAR Classifier"
#define ADA_ip_classifier_role        "IP Classifier"
#define ADA_license_category_size_c   128

/** Defines the length of citizenship strings. */
#define ADA_lic_citizenship_size_c    2

#ifdef __cplusplus
     extern "C"{
#endif

/**
    Creates a new ADA license of specified type with the identification string.
*/
extern TCCORE_API int ADA_create_license(
    const char * license_id,   /**< (I) Identifier for the ADA license.*/
    const char * license_type, /**< (I) Type of ADA license. A valid type for ADA license is @c ITAR_License, @c IP_License, or @c Exclude_License.*/
    tag_t * license        /**< (O) The created ADA license.*/
    );

/**
    Sets the ID of the ADA license.
*/
extern TCCORE_API int ADA_set_license_id(
    tag_t license, /**< (I) Tag of an ADA license */
    const char * id    /**< (I) ID to be set on the ADA license */
    );


/**
    Retrieves the ID of the given ADA license.
*/
extern TCCORE_API int ADA_ask_license_id2(
    tag_t license,                 /**< (I) Tag of an ADA license */
    char **id                          /**< (OF) ID of the ADA license */
    );


/**
    Sets the reason for the ADA license.
*/
extern TCCORE_API int ADA_set_license_reason (
    tag_t license,         /**< (I) Tag of an ADA license */
    const char * reason        /**< (I) Reason to be set for the ADA license */
    );

/**
    Retrieves the reason specified on the ADA license.
*/
extern TCCORE_API int ADA_ask_license_reason2 (
    tag_t license,         /**< (I) Tag of an ADA license */
    char **reason              /**< (OF) Reason specified on the ADA license */
    );

/**
   Sets the category for the ADA license.
*/
extern TCCORE_API int ADA_set_license_category (
    tag_t license,         /**< (I) Tag of an ADA license */
    const char * category      /**< (I) Category to be set for the ADA license */
    );

/**
   Retrieves the category specified on the ADA license.
*/
extern TCCORE_API int ADA_ask_license_category (
    tag_t license,         /**< (I) Tag of an ADA license */
    char ** category           /**< (OF) Category specified on the ADA license */
    );

/**
    Sets an expiry date on the given ADA license.
    <br/>Expiry date should be greater than the current date and the Lock date specified on the License.
*/
extern TCCORE_API int ADA_set_license_expiry (
    tag_t license,         /**< (I) Tag of an ADA license */
    date_t expiry              /**< (I) Expiry date to be set on the ADA license */
    );

/**
   Retrieves the expiry date specified on the given ADA license.
*/
extern TCCORE_API int ADA_ask_license_expiry (
    tag_t license,         /**< (I) Tag of an ADA license */
    date_t *expiry             /**< (O) Expiry date specified on the ADA license */
    );

/**
   Adds a user to ADA license that can access objects with an attached ADA license.
*/
extern TCCORE_API int ADA_add_license_user (
    tag_t license,           /**< (I) Tag of an ADA license */
    tag_t user_tag               /**< (I) Tag of the user to be added to the ADA license */
    );

/**
   Removes the user from ADA license that can access objects with an attached ADA license.
*/
extern TCCORE_API int ADA_remove_license_user (
    tag_t license,           /**< (I) Tag of an ADA license */
    tag_t user_tag               /**< (I) Tag of the user to be removed from the ADA license */
    );

/**
   Checks if a particular user is listed on the given ADA license.
*/
extern TCCORE_API int ADA_user_licensed (
    tag_t license,           /**< (I) Tag of an ADA license */
    tag_t user_tag,              /**< (I) Tag of the user */
    logical *is_licensed         /**< (O) True if the user is listed on ADA license, otherwise false. */
    );

/**
   Lists all the users associated with the given ADA license.
*/
extern TCCORE_API int ADA_list_license_users (
    tag_t license,         /**< (I) Tag of an ADA license */
    int * user_count,          /**< (O) Number of users */
    tag_t ** user_tags         /**< (O) Tag list of users specified on the given ADA license */
    );

/**
    Adds a group to ADA license that can access objects with an attached ADA license.
*/
extern TCCORE_API int ADA_add_license_group (
    tag_t license,          /**< (I) Tag of an ADA license */
    tag_t group_tag             /**< (I) Tag of the group to be added to the ADA license */
    );

/**
   Removes the group from ADA license that can access objects with an attached ADA license.
*/
extern TCCORE_API int ADA_remove_license_group (
    tag_t license,         /**< (I) Tag of an ADA license */
    tag_t group_tag            /**< (I) Tag of the group to be removed from the ADA license */
    );

/**
   Checks if a particular group is listed on the ADA license.
*/
extern TCCORE_API int ADA_group_licensed (
    tag_t license,         /**< (I) Tag of an ADA license */
    tag_t group_tag,           /**< (I) Tag of the group */
    logical *is_licensed       /**< (O) True if the group is listed on ADA license, otherwise false. */
    );

/**
   Lists all the groups associated with the given ADA license.
*/
extern TCCORE_API int ADA_list_license_groups (
    tag_t license,         /**< (I) Tag of an ADA license */
    int * group_count,         /**< (O) Number of users */
    tag_t ** group_tags        /**< (O) Tag list of groups specified on the given ADA license */
    );

/**
   Retrieves the ADA license identified by the given License ID string.
   License ID is the unique key attribute of the ADA license Class.
*/
extern TCCORE_API int ADA_find_license (
    const char *licid,        /**< (I) ID of an ADA license */
    tag_t *license            /**< (O) Tag of ADA license */
    );

/**
   Attaches the given ADA license to the specified object.
*/
extern TCCORE_API int ADA_add_license_object (
    tag_t license,           /**< (I) Tag of an ADA license */
    tag_t object_tag             /**< (I) Tag of a workspace object to attach the ADA license to */
    );

/**
    Attaches the given ADA license to the specified object along with ead paragragh information.
    <br/>@p ead_paragraph is applicable only when attaching ITAR Licenses to objects.
    <br/>For other license types like IP License and Exclude license the ead paragraph information will be null.
*/
extern TCCORE_API int ADA_add_license_object2 (
    tag_t license,           /**< (I) Tag of an ADA license */
    tag_t object_tag,            /**< (I) Tag of a workspace object to attach the ADA license to */
    char *ead_paragraph          /**< (I) Paragraph authorizing attaching the ADA license to the workspace object. Applicable only for ITAR Licenses.*/
    );

/**
   Detaches the given ADA license from the object.
*/
extern TCCORE_API int ADA_remove_license_object (
    tag_t license,           /**< (I) Tag of an ADA license */
    tag_t object_tag             /**< (I) Tag of the workspace object to detach the ADA license from */
    );

/**
   Lists all the objects associated with the given ADA license.
*/
extern TCCORE_API int ADA_list_license_objects (
    tag_t license,           /**< (I) Tag of an ADA license */
    int * object_count,          /**< (O) Number of objects */
    tag_t ** object_tags         /**< (O) Tag list of all workspace objects associated with the ADA license.*/
    );

/**
    Sets the lock date on the ADA license.
    <br/>Lock date should be between current date and expiry date.
*/
extern TCCORE_API int ADA_set_license_lock (
    tag_t license,        /**< (I) Tag of an ADA license */
    date_t myLockdate         /**< (I) Lock date to be set on the ADA license */
    );

/**
   Retrieves the lock date specified on the ADA license.
*/
extern TCCORE_API int ADA_ask_license_lock (
    tag_t license,        /**< (I) Tag of an ADA license */
    date_t *lock_date         /**< (O) Lock date specified on the ADA license */
    );

/**
   Adds the qualifying Code of Federal Regulations (CFR) information (In
   Accordance With) on ITAR licenses.
*/
extern TCCORE_API int ADA_set_in_accordance_with (
    tag_t license,                  /**< (I) Tag of an ADA license */
    const char *  in_accordance         /**< (I) Qualifying Code of Federal Regulations (CFR) to be set on the ITAR License */
    );

/**
   Retrieves the qualifying Code of Federal Regulations (CFR) information (In
   Accordance With) specified on ITAR licenses.
*/
extern TCCORE_API int ADA_ask_in_accordance_with2 (
    tag_t license,                /**< (I) Tag of an ADA license */
    char  **in_accordance             /**< (OF) Qualifying Code of Federal Regulations (CFR) specified on the ITAR License */
    );

/**
   Sets citizenships to the ADA license.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#SA_invalid_citizenship if each citizenship is not two-letter string.
   <li>#PROP_invalid_object if @p license is not a valid ADA license.
   </ul>
*/
extern TCCORE_API int ADA_set_license_citizenships(
    tag_t license,         /**< (I) The ADA license */
    int n_citizenships,        /**< (I) Number of citizenships */
    const char** citizenships  /**< (I) n_citizenships Array of citizenships. Each citizenship is a string of length defined by #ADA_lic_citizenship_size_c */
    );

/**
    Retrieves citizenships of the ADA license.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#SA_invalid_citizenship if each citizenship is not two-letter string.
   <li>#PROP_invalid_object if @p license is not a valid ADA license.
   </ul>
*/
extern TCCORE_API int ADA_ask_license_citizenships(
    tag_t license,         /**< (I) An ADA license */
    int* n_citizenships,       /**< (O) Number of citizenships */
    char*** citizenships       /**< (OF) n_citizenships Array of citizenships */
    );


/**
   Performs bulk attachment of licenses for persisted objects.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#PROP_invalid_object if any member of @p licenses is not a valid ADA license.
   <li>Error code for any failure
   </ul>
*/
extern TCCORE_API int ADA_attach_licenses(
    int n_licenses,                  /**< (I) Number of licenses */
    tag_t *licenses,                 /**< (I) Licenses*/
    char** ead_paragraphs,           /**< (I) Matching paragraphs */
    int n_objects,                   /**< (I) Number of objects to be assigned */
    tag_t *objects,                  /**< (I) n_objects Objects (persisted) */
    int *n_failed_objects,           /**< (O) Number of failed objects */
    tag_t **failed_objects,          /**< (OF) n_failed_objects List of failed objects */
    tag_t rev_rule,                  /**< (I)  RevisionRule for persisted configured traversal (4GD use case) */
    tag_t variant_rule               /**< (I)  variantRule for persisted configured traversal (4GD use case) */
    );

/**
   Performs bulk detachment of licenses for persisted objects.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#CXPOM_invalid_tag if any member of @p objects is #NULLTAG.
   <li>#CXPOM_invalid_tag if any member of @p licenses is #NULLTAG.
   <li>#AOM_internal_error if any member of @p objects is not valid WorkspaceObject.
   <li>#AOM_internal_error if any member of @p licenses is not a valid ADA license.
   <li>Possibly other errors
   </ul>
*/
extern TCCORE_API int ADA_detach_licenses(
    int n_licenses,                 /**< (I) Number of licenses */
    tag_t *licenses,                /**< (I) n_licenses License tags*/
    int n_objects,                  /**< (I) Number of objects to be detached */
    tag_t *objects,                 /**< (I) n_objects Persisted object tags */
    int *n_failed_objects,        /**< (O) Number of failed objects */
    tag_t **failed_objects        /**< (OF) n_failed_objects List of failed objects */
    );

/**
   Performs bulk attachment of licenses for persisted or runtime objects.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#PROP_invalid_object if any member of @p licenses is not a valid ADA license.
   <li>Error code for any failure
   </ul>
*/
extern TCCORE_API int ADA_generic_attach_licenses(
    int n_licenses,                /**< (I) Number of licenses */
    tag_t *licenses,                 /**< (I) n_licenses Licenses */
    char **ead_paragraphs,            /**< (I) Matching paragraphs */
    tag_t rev_rule,                  /**< (I) RevisionRule for persisted configured traversal (4GD use case) */
    tag_t variant_rule,              /**< (I) VariantRule for persisted configured traversal (4GD use case) */
    int n_objects,                    /**< (I) Number of objects to be assigned */
    tag_t *objects,                  /**< (I) n_objects Objects (persisted) */
    int type_option,                  /**< (I) Type option (Item or ItemRevision) */
    int depth,                       /**< (I) Depth (how deep into the BOM structure should we traverse?) */
    int *n_failed_objects,         /**< (O) Number of failed objects */
    tag_t **failed_objects         /**< (OF) n_failed_objects :ist of failed objects */
    );

/**
   Performs bulk removal/detachment of licenses for persisted or runtime objects.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#PROP_invalid_object if any member of @p licenses is not a valid ADA license.
   <li>Error code for any failure
   </ul>
*/
extern TCCORE_API int ADA_generic_detach_licenses(
    int n_licenses,                   /**< (I) Number of licenses */
    tag_t *licenses,                  /**< (I) n_licenses Licenses */
    int n_objects,                    /**< (I) Number of objects to be assigned */
    tag_t *objects,                   /**< (I) n_objects Object (persisted) */
    int type_option,                  /**< (I) Type option (Item or ItemRevision) */
    int depth                         /**< (I) Depth (how deep into the BOM structure should we traverse?) */
    );

/**
   Performs bulk removal/detachment of licenses for persisted or runtime objects.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#CXPOM_invalid_tag if any member of @p licenses is #NULLTAG.
   <li>#AOM_internal_error if any member of @p objects is not a valid WorkspaceObject.
   <li>#AOM_internal_error if any member of @p licenses is not a valid ADA license.
   <li>Possibly other errors
   </ul>
*/
extern TCCORE_API int ADA_generic_detach_licenses2(
    int n_licenses,                   /**< (I) Number of licenses */
    tag_t *licenses,                  /**< (I) n_licenses License tags */
    int n_objects,                    /**< (I) Number of objects to be detached */
    tag_t *objects,                   /**< (I) n_objects Object tags */
    int type_option,                  /**< (I) Type option (Item or ItemRevision) */
    int depth,                        /**< (I) Depth of the BOM structure to traverse */
    int *n_failed_objects,            /**< (O) Number of failed objects */
    tag_t **failed_objects            /**< (OF) n_failed_objects Failed objects */
    );


/** @} */

#ifdef __cplusplus
}
#endif

#include <tccore/libtccore_undef.h>

#endif

