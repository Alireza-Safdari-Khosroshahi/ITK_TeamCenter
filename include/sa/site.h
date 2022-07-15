/*==============================================================================
  Copyright (c) 2003-2005 UGS Corporation
  Unpublished - All Rights Reserved
  ==============================================================================*/

/**
   @file

   This header file declares all the functions to be used
   by clients of the Site class which is part of the System
   Administration module of Teamcenter Engineering.

   <b>Restrictions:</b>

   This include file should not generally be used by anyone.
   Normally sa.h should be included instead.
*/

/*  */

#ifndef SITE_H
#define SITE_H
#include <sa/sa.h>
#include <sa/libsa_exports.h>

/**
   @defgroup SITE Site
   @ingroup SA

   <b>Common Return Values</b>

   #SITE_DEFAULT_ODS_ERROR - A default ODS is not defined.
   @{
*/

/**  Site Preferences */
#define SITE_default_ods           "ODS_site"

/** Which sites can access this site */
#define SITE_permitted_sites       "IDSM_permitted_sites"

/** Which sites can not access this site */
#define SITE_restricted_sites      "IDSM_restricted_sites"

/** Which sites can this site search */
#define SITE_searchable_sites      "ODS_searchable_sites"

/** Which sites this site can not search */
#define SITE_nonsearchable_sites   "ODS_searchable_sites_excluded"

/**
   @name Directory Services Preferences
   @{
*/

/** Which sites ODS will allow access */
#define ODS_permitted_sites        "ODS_permitted_sites"

/** Which sites ODS will not permit access */
#define ODS_restricted_sites       "ODS_restricted_sites"

/** @} */

#ifdef __cplusplus
extern "C"{
#endif

    /**
       Allocates an array of tags and stores in the array all sites in the database.

       The client is responsible for deallocating the array of site_tags.
       Use #MEM_free to free the memory pointed to by site_tags.
    */
    extern SA_API int SA_extent_site(
        int*          nsites,       /**< (O) Stores the size of the array */
        tag_t**       site_tags     /**< (OF) nsites Points to the array of tags */
        );


    /**
       Finds a site with the specified name. The site_name is unique in the database.
       If an error occurs, then a non-zero integer returns.
       If no site exists with the specified name, then a zero returns,
       and a #NULLTAG returns for the site_tag.
    */
    extern SA_API int SA_find_site2(
        const char    *sitename,                    /**< (I) */
        tag_t*        site_tag                      /**< (O) */
        );

    /**
       Retrieves the tag of the specified site.

       Retrieves #SA_finding_site if unable to find site with the specified site_id.
    */
    extern SA_API int SA_find_site_by_id(
        int           site_id,      /**< (I) Site ID of the specified site */
        tag_t*        site_tag      /**< (O) Site tag of the specified site */
        );


    /**
       Retrieves the name and ID of the specified site.
    */
    extern SA_API int SA_ask_site_info2(
        tag_t         site_tag,                     /**< (I) */
        char          **sitename,                   /**< (OF) */
        int*          site_id                       /**< (O) */
        );

    /**
       Retrieves the name, ID and external app status of the specified site.
    */
    extern SA_API int SA_ask_site_info_ex2(
        tag_t         site_tag,                     /**< (I) */
        char          **sitename,                   /**< (OF) */
        int*          site_id,                      /**< (O) */
        logical*      external_app                  /**< (O) */
        );


    /**
       Creates a Site object. It is not saved to the database until an explicit call to #AOM_save occurs.
       You must specify a unique sitename and a unique site_id.

       <b>Restrictions:</b>

       This function can only be accessed when logged in as a system administrator.
    */
    extern SA_API int SA_create_site2(
        const char    *sitename,                    /**< (I) */
        int           site_id,                      /**< (I) */
        tag_t*        site_tag                      /**< (O) */
        );


    /**
       Retrieves the nodename where the ODS and/or IDSM daemon(s) are running for the specified site.
    */
    extern SA_API int SITE_ask_node_name2(
        tag_t         site_tag,                     /**< (I) Tag of the specified site */
        char          **nodename                    /**< (OF) Returned node name */
        );

    
    /**
       Sets the nodename where the ODS and/or IDSM daemon(s) will run for the specified site.
    */
    extern SA_API int SITE_set_node_name2(
        tag_t         site_tag,                     /**< (I) Tag of the specified site */
        const char    *nodename                     /**< (I) Node name where the ODS and/or IDSM daemon(s) will
                                                       run for the specified site */
        );
    
    /** 
        Retrieves the license server of the specified site.

        @returns
        <ul>
        <li>#ITK_ok on success
        <li>#ITK_invalid_license_server_name will be returned if the license server tag is invalid.
        </ul>
    */
    extern SA_API int SITE_ask_license_server(
        tag_t         site_tag,          /**< (I)  Tag of the site whose status is to be queried */
        char          **license_server   /**< (OF) Default license server for the site */
        );

    /** 
        Sets the default license server for the specified site.

        @returns
        <ul>
        <li>#ITK_ok on success
        <li>#ITK_invalid_license_server_name will be returned if the license server tag is invalid.
        </ul>
    */
    extern SA_API int SITE_set_license_server(
        tag_t         site_tag,         /**< (I) Tag of the specified site */
        const char    *license_server   /**< (I) Default license server for the site */
        );

    /**
       Retrieves the status of the specified site as to whether or not it is ODS-capable
       (i.e., objects can be published to it).
    */
    extern SA_API int SITE_ask_ods_site(
        tag_t         site_tag,     /**< (I) Tag of the site whose status is to be queried */
        logical*      is_ods_site   /**< (O) Set to TRUE if specified site is ODS-capable and FALSE if not */
        );
    
    /**
       Sets the status of the specified site as to whether or not it is ODS-capable
       (i.e., objects can be published to it).
    */
    extern SA_API int SITE_set_ods_site(
        tag_t         site_tag,     /**< (I) Tag of the site whose ODS-capability status is to be set */
        logical       is_ods_site   /**< (I) If TRUE, then the specified site will be flagged as ODS-capable;
                                       otherwise it will be flagged as not ODS-capable. */
        );

    extern SA_API int SITE_ask_hub_site(
        tag_t         site_tag,     /**< (I) */
        logical*      is_hub_site   /**< (O) */
        );

    extern SA_API int SITE_set_hub_site(
        tag_t         site_tag,     /**< (I) */
        logical       is_hub_site   /**< (I) */
        );

    extern SA_API int SITE_ask_http_site(
        tag_t         site_tag,     /**< (I) */
        logical*      ids_http_site /**< (O) */
        );

    extern SA_API int SITE_set_http_site(
        tag_t         site_tag,     /**< (I) */
        logical       is_http_site   /**< (I) */
        );

    extern SA_API int SITE_ask_ods_url2(
        tag_t         site_tag,     /**< (I) */
        char          **url         /**< (OF) Returned url name for ods node*/
        );

    extern SA_API int SITE_set_ods_url2(
        tag_t         site_tag,     /**< (I) */
        const char    *url          /**< (I) Site name url where ODS daemon(s) will run */
        );

    extern SA_API int SITE_ask_soa_url2(
        tag_t         site_tag,     /**< (I) */
        char          **url         /**< (OF) Returned url name for soa node*/
        );

    extern SA_API int SITE_set_soa_url2(
        tag_t         site_tag,     /**< (I) */
        const char    *url          /**< (I) Site name url where SOA daemon(s) will run */
        );

    extern SA_API int SITE_ask_gms_url2(
        tag_t         site_tag,     /**< (I) */
        char          **url         /**< (OF) Returned url name for gms node*/
        );

    extern SA_API int SITE_set_gms_url2(
        tag_t         site_tag,     /**< (I) */
        const char    *url          /**< (I) Site name url where GMS is deployed */
        );

    extern SA_API int SITE_ask_tcplmxml_site(
        tag_t      siteTag,         /**< (I) */
        logical    *is_plmxml       /**< (O) */
        );

    extern SA_API int SITE_set_tcplmxml_site(
        tag_t       siteTag,       /**< (I) */
        logical     is_plmxml      /**< (I) */
        );

    extern SA_API int SITE_ask_offline_site (
        tag_t      siteTag,       /**< (I) */
        logical    *is_offline    /**< (O) */
        );
    extern SA_API int SITE_set_offline_site(
        tag_t       siteTag,     /**< (I) */
        logical     is_offline   /**< (I) */
        );
    extern SA_API int SITE_ask_unmanaged_site (
        tag_t      siteTag,         /**< (I) Tag of the site whose unmanaged status is to be queried */
        logical    *is_unmanaged    /**< (O) return TRUE if specified site is unmanaged and FALSE if not */
        );

    /** 
        Checks if a site is marked as an unmanaged site.

        @returns
        <ul>
        <li>#ITK_ok on success
        <li>#CXPOM_wrong_class if @p site is not a site object.
        <li>#POM_invalid_tag will if @p site is invalid.
        <li>#SITE_LOCAL_UNMANAGED_ERROR if @p site is local site.
        </ul>
    */
    extern SA_API int SITE_set_unmanaged_site(
        tag_t       site,          /**< (I) The site which unmanaged status is to be set */
        logical     is_unmanaged   /**< (I) If TRUE, then the specified site will be flagged as unmanaged;
                                      otherwise it will be flagged as not unmanaged. */
        );

    /** 
        Checks if a site is marked as an unmanaged briefcase-browser site.

        @returns
        <ul>
        <li>#ITK_ok on success
        <li>#CXPOM_wrong_class if @p site is not a site object.
        <li>#POM_invalid_tag will if @p site is invalid.
        </ul>
    */
    extern SA_API int SITE_ask_unmanaged_bb_site (
        const tag_t     site,            /**< (I) Tag of the site whose unmanaged briefcase-browser status is to be queried */
        logical*        is_unmanaged_bb     /**< (O) Status of the site: @c true if the site is unmanaged briefcase-browser. */
        );

    /** 
        Marks a site as an unmanaged briefcase-browser site.

        @returns
        <ul>
        <li>#ITK_ok on success
        <li>#CXPOM_wrong_class if @p site is not a site object.
        <li>#POM_invalid_tag will if @p site is invalid.
        <li>#SITE_LOCAL_UNMANAGED_ERROR if @p site is local site.
        </ul>
    */
    extern SA_API int SITE_set_unmanaged_bb_site (
        const tag_t       site,          /**< (I) The site which unmanaged briefcase-browser status is to be set */
        const logical     is_unmanaged_bb   /**< (I) Status of the site: @c true if the site is unmanaged briefcase-browser. */
        );

    /** 
        Checks if a site is marked as an unmanaged briefcase-browserwith plugin site.

        @returns
        <ul>
        <li>#ITK_ok on success
        <li>#CXPOM_wrong_class if @p site is not a site object.
        <li>#POM_invalid_tag will if @p site is invalid.
        </ul>
    */
    extern SA_API int SITE_ask_unmanaged_bb_plugin_site (
        const tag_t     site,                /**< (I) Tag of the site whose unmanaged briefcase-browser with plugin status is to be queried */
        logical*        is_unmanaged_bb_plugin  /**< (O) Status of the site: @c true if the site is unmanaged briefcase-browser with plugin. */
        );

    /** 
        Marks a site as an unmanaged briefcase-browser with plugin site.

        @returns
        <ul>
        <li>#ITK_ok on success
        <li>#CXPOM_wrong_class if @p site is not a site object.
        <li>#POM_invalid_tag will if @p site is invalid.
        <li>#SITE_LOCAL_UNMANAGED_ERROR if @p site is local site.
        </ul>
    */
    extern SA_API int SITE_set_unmanaged_bb_plugin_site (
        const tag_t       site,                  /**< (I) The site which unmanaged briefcase-browser with plugin status is to be set */
        const logical     is_unmanaged_bb_plugin    /**< (I) Status of the site: @c true if the site is unmanaged briefcase-browser with plugin. */
        );

    extern SA_API int SITE_ask_master_deletion_allowed (
        tag_t      site,                /**< (I) The site which master deletion status is to be queried */
        logical    *is_master_delete    /**< (O) Indicates if the objects replicated through Global Multi-Site Services can be deleted. It has no impact on the Multi-Site Collaboration. */
        );

    extern SA_API int SITE_set_master_deletion_allowed(
        tag_t       site,               /**< (I) The site which master deletion status is to be set */
        logical     is_master_delete    /**< (I) Indicates if the objects replicated through Global Multi-Site Services can be deleted. It has no impact on the Multi-Site Collaboration. */
        );

    extern SA_API int SITE_ask_application_type(    
        tag_t  site,                     /**< (I) */
        int    *application_type         /**< (O) */
        );

    extern SA_API int SITE_set_application_type(
        tag_t       site,                /**< (I) */
        int         application_type     /**< (I) */
        );

    extern SA_API int SITE_is_external_application(
        tag_t      site,                /**< (I) */
        logical    *is_external         /**< (O) */
        );

    /**
       Retrieves the value of the geography attribute of the specified site.
    */
    extern SA_API int SITE_ask_geography2(
        tag_t site,                                  /**< (I) */
        char **geography                             /**< (OF) */
        );

    /**
       Sets the geography attribute of the specified site.
    */
    extern SA_API int SITE_set_geography(
        tag_t site,                   /**< (I) */
        const char * geography        /**< (I) */
        );

    /**
       Retrieves the site ID of the default ODS.
    */
    extern SA_API int SITE_ask_default_ods(
        int*          site_id       /**< (O) Site ID of the site that is currently designated as the default ODS */
        );

    extern SA_API int SITE_ask_searchable_sites(
        int*          n_sites_included,          /**< (O) */
        tag_t**       sites_included,           /**< (OF) n_sites_included */
        int*          n_sites_excluded,          /**< (O) */
        tag_t**       sites_excluded,           /**< (OF) n_sites_excluded */
        int*          n_user_sites_included,     /**< (O) */
        tag_t**       user_sites_included,      /**< (OF) n_user_sites_included */
        int*          n_user_sites_excluded,     /**< (O) */
        tag_t**       user_sites_excluded       /**< (OF) n_user_sites_excluded */
        );

    /** @} */

#ifdef __cplusplus
}
#endif

#include <sa/libsa_undef.h>

#endif
