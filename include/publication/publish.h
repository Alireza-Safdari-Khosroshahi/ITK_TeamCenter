/*==================================================================================================

                    Copyright (c) 1994 Electronic Data Systems Corporation
                             Unpublished - All rights reserved

====================================================================================================
File description:

    ITK interface for Publication Records


*/

#ifndef TEAMCENTER_PUBLISH_HHH
#define TEAMCENTER_PUBLISH_HHH

#include <sa/sa.h>
#include <publication/libpublication_exports.h>

/** 
    @defgroup PUBLICATION Publication
    @ingroup TC
    Publication module is for performing 'publication' related operations for MultiSite collaboration.
    <br/>Multiple Sites can create objects, and publish in a central repository, where other sites in the federation
    can perform search operation, and do remote import of the searched objects.
    <br/>ODS(Object Directory Service) is the central 'index service' which keeps a record.
    publication and remote search happens at ODS.Publication Records are the entries which are created/used in this.
    <br/>The header below is used for core operations for the publication record.
    @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/** Maximum number of ods'es to publish to in one shot */
#define MAX_ODS_PER_PUBLISH      10

/** Maximum length in characters of comma-separated ODS list */
#define MAX_ODS_LIST_LEN        256


/**
   PUBLISH_ods_list_s structure holds the entire information about
   the number of ODS sites, ODS site IDs and site names. ODS stands for Object Directory Services
   and the function of ODS site is to maintain record of each object in the entire Multi-Site
   collaboration network.
*/
typedef struct PUBLISH_ods_list_s {
    int            n_ods;                                                    /**< The number of ODS sites. */
    int            ods_site_id[MAX_ODS_PER_PUBLISH];                         /**< ODS site IDs. */
    char           ods_names[MAX_ODS_PER_PUBLISH * (SA_site_size_c + 1)];    /**< ODS site names. */
} PUBLISH_ods_list_t;

/**
    Publishes the object and gets its corresponding publication record.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#PUBR_no_create if the object cannot be published.
    </ul>
 */
extern PUBLICATION_API int PUBR_publish_object(
    tag_t          object_tag,         /**< (I)  The Teamcenter object tag.*/
    tag_t*         pubr_tag            /**< (O)  Publication Record tag.*/
    );


/**
    Retrieves object tag as a string for the input publication record.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if the publication record tag is invalid.
    </ul>
 */
extern PUBLICATION_API int PUBR_ask_obj_tag_as_string(
    tag_t          pr_tag,             /**< (I)   Publication Record tag.*/
    char**         obj_tag_as_string   /**< (OF)  Object tag string.*/
    );


/**
    Sets object tag as a string for the input publication record.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if the publication record tag is invalid.
    </ul>
 */
extern PUBLICATION_API int PUBR_set_obj_tag_as_string(
    tag_t          pr_tag,             /**< (I)  Publication Record tag.*/
    const char*    obj_tag_as_string   /**< (O)  Object tag string.*/
    );


/**
    Retrieves site ID for the input publication record.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if the publication record tag is invalid.
    </ul>
 */
extern PUBLICATION_API int PUBR_ask_obj_site_id(
    tag_t          pr_tag,             /**< (I)  Publication Record tag.*/
    int*           site_id             /**< (O)  The site ID number.*/
    );


/**
    Sets site ID for the input publication record.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if the publication record tag is invalid.
    </ul>
 */
extern PUBLICATION_API int PUBR_set_obj_site_id(
    tag_t          pr_tag,             /**< (I)  Publication Record tag.*/
    int            site_id             /**< (I)  The site ID number.*/
    );


/**
    Retrieves object name for the input publication record.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if the publication record tag is invalid.
    </ul>
 */
extern PUBLICATION_API int PUBR_ask_obj_name(
    tag_t          pr_tag,             /**< (I)   Publication Record tag.*/
    char**         obj_name            /**< (OF)  The Teamcenter object name.*/
    );


/**
    Sets object name for the input publication record.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if the publication record tag is invalid.
    </ul>
 */
extern PUBLICATION_API int PUBR_set_obj_name(
    tag_t          pr_tag,             /**< (I)  Publication Record tag.*/
    const char*    obj_name            /**< (I)  The Teamcenter object name.*/
    );


/**
    Sets null object name for the input publication record.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if the publication record tag is invalid.
    </ul>
 */
extern PUBLICATION_API int PUBR_null_obj_name(
    tag_t          pr_tag              /**< (I)  Publication Record tag.*/
    );


/**
    Retrieves domain name for the input publication record.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if the publication record tag is invalid.
    </ul>
 */
extern PUBLICATION_API int PUBR_ask_domain(
    tag_t          pr_tag,             /**< (I)   Publication Record tag.*/
    char**         domain              /**< (OF)  Domain name.*/
    );


/**
    Sets domain name for the input publication record.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if the publication record tag is invalid.
    </ul>
 */
extern PUBLICATION_API int PUBR_set_domain(
    tag_t          pr_tag,             /**< (I)  Publication Record tag.*/
    const char*    domain              /**< (I)  Domain name.*/
    );


/**
    Retrieves key value name for the input publication record.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if the publication record tag is invalid.
    </ul>
 */
extern PUBLICATION_API int PUBR_ask_key_value(
    tag_t          pr_tag,             /**< (I)   Publication Record tag.*/
    char**         keyvalue            /**< (OF)  Key value.*/
    );


/**
    Sets key value name for the input publication record.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if the publication record tag is invalid.
    </ul>
 */
extern PUBLICATION_API int PUBR_set_key_value(
    tag_t          pr_tag,             /**< (I)  Publication Record tag.*/
    const char*    keyvalue            /**< (I)  Key value.*/
    );


/**
    Retrieves object ID as a string for the input publication record.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if the publication record tag is invalid.
    </ul>
 */
extern PUBLICATION_API int PUBR_ask_obj_id(
    tag_t          pr_tag,             /**< (I)   Publication Record tag.*/
    char**         obj_id              /**< (OF)  The Teamcenter object ID.*/
    );


/**
    Sets object ID for the input publication record.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if the publication record tag is invalid.
    </ul>
 */
extern PUBLICATION_API int PUBR_set_obj_id(
    tag_t          pr_tag,             /**< (I)  Publication Record tag.*/
    const char*    obj_id              /**< (I)  The Teamcenter object ID.*/
    );


/**
    Retrieves object revision ID for the input publication record.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if the publication record tag is invalid.
    </ul>
 */
extern PUBLICATION_API int PUBR_ask_obj_rev_id(
    tag_t          pr_tag,             /**< (I)   Publication Record tag.*/
    char**         obj_rev_id          /**< (OF)  The Teamcenter object revision ID.*/
    );


/**
    Sets object revision ID for the input publication record.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if the publication record tag is invalid.
    </ul>
 */
extern PUBLICATION_API int PUBR_set_obj_rev_id(
    tag_t          pr_tag,             /**< (I)  Publication Record tag.*/
    const char*    obj_rev_id          /**< (I)  The Teamcenter object revision ID.*/
    );


/**
    Retrieves object descriptor for the input publication record.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if the publication record tag is invalid.
    </ul>
 */
extern PUBLICATION_API int PUBR_ask_obj_desc(
    tag_t          pr_tag,             /**< (I)   Publication Record tag.*/
    char**         obj_desc            /**< (OF)  The Teamcenter object descriptor.*/
    );


/**
    Sets object descriptor for the input publication record.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if the publication record tag is invalid.
    </ul>
 */
extern PUBLICATION_API int PUBR_set_obj_desc(
    tag_t          pr_tag,             /**< (I)  Publication Record tag.*/
    const char*    obj_desc            /**< (I)  The Teamcenter object descriptor.*/
    );


/**
    Sets null object descriptor for the input publication record.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if the publication record tag is invalid.
    </ul>
 */
extern PUBLICATION_API int PUBR_null_obj_desc(
    tag_t          pr_tag              /**< (I)  Publication Record tag.*/
    );


/**
    Retrieves object class for the input publication record.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if the publication record tag is invalid.
    </ul>
 */
extern PUBLICATION_API int PUBR_ask_obj_class(
    tag_t          pr_tag,             /**< (I)   Publication Record tag.*/
    char**         obj_class           /**< (OF)  Object Class.*/
    );


/**
    Sets object class for the input publication record.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if the publication record tag is invalid.
    </ul>
 */
extern PUBLICATION_API int PUBR_set_obj_class(
    tag_t          pr_tag,             /**< (I)  Publication Record tag.*/
    const char*    obj_class           /**< (I)  Object Class.*/
    );


/**
    Retrieves object type for the input publication record.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if the publication record tag is invalid.
    </ul>
 */
extern PUBLICATION_API int PUBR_ask_obj_type(
    tag_t          pr_tag,             /**< (I)   Publication Record tag.*/
    char**         obj_type            /**< (OF)  Object Type.*/
    );


/**
    Sets object type for the input publication record.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if the publication record tag is invalid.
    </ul>
 */
extern PUBLICATION_API int PUBR_set_obj_type(
    tag_t          pr_tag,             /**< (I)  Publication Record tag.*/
    const char*    obj_type            /**< (I)  Object Type.*/
    );


/**
    Sets null object type for the input publication record.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if the publication record tag is invalid.
    </ul>
 */
extern PUBLICATION_API int PUBR_null_obj_type(
    tag_t          pr_tag              /**< (I)  Publication Record tag.*/
    );


/**
    Retrieves object owner for the input publication record.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if the publication record tag is invalid.
    </ul>
 */
extern PUBLICATION_API int PUBR_ask_obj_owner(
    tag_t          pr_tag,             /**< (I)   Publication Record tag.*/
    char**         obj_owner           /**< (OF)  Object Owner.*/
    );


/**
    Sets object owner for the input publication record.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if the publication record tag is invalid.
    </ul>
 */
extern PUBLICATION_API int PUBR_set_obj_owner(
    tag_t          pr_tag,             /**< (I)  Publication Record tag.*/
    const char*    obj_owner           /**< (I)  Object Owner.*/
    );


/**
    Sets null object owner for the input publication record.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if the publication record tag is invalid.
    </ul>
 */
extern PUBLICATION_API int PUBR_null_obj_owner(
    tag_t          pr_tag              /**< (I)  Publication Record tag.*/
    );


/**
    Retrieves object group for the input publication record.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if the publication record tag is invalid.
    </ul>
 */
extern PUBLICATION_API int PUBR_ask_obj_group(
    tag_t          pr_tag,             /**< (I)   Publication Record tag.*/
    char**         obj_group           /**< (OF)  Object Group.*/
    );


/**
    Sets object group for the input publication record.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if the publication record tag is invalid.
    </ul>
 */
extern PUBLICATION_API int PUBR_set_obj_group(
    tag_t          pr_tag,             /**< (I)  Publication Record tag.*/
    const char*    obj_group           /**< (I)  Object Group.*/
    );


/**
    Sets null object group for the input publication record.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if the publication record tag is invalid.
    </ul>
 */
extern PUBLICATION_API int PUBR_null_obj_group(
    tag_t          pr_tag              /**< (I)  Publication Record tag.*/
    );


/**
    Retrieves the flag value for the input publication record.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if the publication record tag is invalid.
    </ul>
 */
extern PUBLICATION_API int PUBR_ask_flag(
    tag_t          pr_tag,             /**< (I)  Publication Record tag.*/
    int*           flag                /**< (O)  The status for the flag.*/
    );


/**
    Sets the flag value for the input publication record.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if the publication record tag is invalid.
    </ul>
 */
extern PUBLICATION_API int PUBR_set_flag(
    tag_t          pr_tag,             /**< (I)  Publication Record tag.*/
    int            flag                /**< (I)  The status for the flag.*/
    );


/**
    Retrieves the application reference name and number for the input publication record.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if the publication record tag is invalid.
    </ul>
 */
extern PUBLICATION_API int PUBR_ask_apprefs(
    tag_t          pr_tag,             /**< (I)   Publication Record tag.*/
    int*           n_apprefs,          /**< (O)   The number of application reference.*/
    char***        apprefs             /**< (OF)  The name of application reference.*/
    );


/**
    Sets the application reference name and number for the input publication record.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if the publication record tag is invalid.
    </ul>
 */
extern PUBLICATION_API int PUBR_set_apprefs(
    tag_t          pr_tag,             /**< (I)  Publication Record tag.*/
    int            n_apprefs,          /**< (I)  The number of application reference.*/
    const char**   apprefs             /**< (I)  The name of application reference.*/
    );


/**
    Adds the application reference name for the input publication record.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if the publication record tag is invalid.
    </ul>
 */
extern PUBLICATION_API int PUBR_add_appref(
    tag_t          pr_tag,             /**< (I)  Publication Record tag.*/
    const char*    appref              /**< (I)  The name of application reference.*/
    );


/**
    Removes the application reference name for the input publication record.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if the publication record tag is invalid.
    </ul>
 */
extern PUBLICATION_API int PUBR_remove_appref(
    tag_t          pr_tag,             /**< (I)  Publication Record tag.*/
    const char*    appref,             /**< (I)  The name of application reference.*/
    int*           n_remaining         /**< (O)  The number of remaining application reference.*/
    );


/**
    Sets create date to null for the  input publication record.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if the publication record tag is invalid.
    </ul>
 */
extern PUBLICATION_API int PUBR_null_obj_create_date(
    tag_t          pr_tag              /**< (I)  Publication Record tag.*/
    );


/**
    Sets publication date to null for the  input publication record. 

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if the publication record tag is invalid.
    </ul>
 */
extern PUBLICATION_API int PUBR_null_obj_pub_date(
    tag_t          pr_tag              /**< (I)  Publication Record tag.*/
    );


/**
    Sets status date to null for the  input publication record.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if the publication record tag is invalid.
    </ul>
 */
extern PUBLICATION_API int PUBR_null_status_names(
    tag_t          pr_tag              /**< (I)  Publication Record tag.*/
    );


/**
    Retrieves object contexts for the input publication record.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if the publication record tag is invalid.
    </ul>
 */
extern PUBLICATION_API int PUBR_ask_obj_contexts(
    tag_t          pr_tag,             /**< (I)   Publication Record tag.*/
    int*           n_contexts,         /**< (O)   Context number.*/
    char***        contexts,           /**< (OF)  n_contexts The array of context names.*/
    char***        alt_ids             /**< (OF)  n_contexts The array of Alternate ID names.*/
    );


/**
    Sets object contexts for the input publication record.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if the publication record tag is invalid.
    </ul>
 */
extern PUBLICATION_API int PUBR_set_obj_contexts(
    tag_t          pr_tag,             /**< (I)   Publication Record tag.*/
    int            n_contexts,         /**< (I)   Context number.*/
    char**         contexts,           /**< (I)   n_contexts The array of context names.*/
    char**         alt_ids             /**< (I)   n_contexts The array of Alternate ID names.*/
    );

#ifdef __cplusplus
}
#endif

/** @} */

#include <publication/libpublication_undef.h>
#endif
