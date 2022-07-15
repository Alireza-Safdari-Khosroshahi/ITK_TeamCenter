/*===============================================
   Copyright 2007 UGS Corp. All Rights Reserved.
   ===============================================*/

/** 
    @file

    This file contains the ITK functions for Volume Management.

    The Instances of VM_Policy are used to migrate the files between the Teamcenter
    volumes. The policies are made up of Teamcenter Engineering metadata and various OS 
    File specific attributes.
*/

/**
    @defgroup VOLUME_MANAGEMENT Teamcenter Volume Management
    @ingroup SA

    The Instances of HSM_Policy are used in conjunction with 3rd Party Hierarchical Storage
    Management software(HSM) for migration of files between different volume tiers based
    on policies.
   
    The policies are made up of Teamcenter Engineering metadata and various OS File specific
    attributes.
    @{
*/

#ifndef MIGRATION_H
#define MIGRATION_H

#include <sa/sa.h>
#include <unidefs.h>
#include <sa/libsa_exports.h>

typedef struct VM_policy_info_s
{
    logical is_active;  
    logical migrate_checkedout_file;       
    logical migrate_in_process_file;      
    logical migrate_remote_file;         
    logical purge_immediately;  
    int purge_low_water_mark;        
    int purge_high_water_mark;    
    int  migration_option;
    tag_t src_vol_tag;           
    tag_t dest_vol_tag;            
    int file_size_range_from;     
    int file_size_range_to;      
    int file_size_units;                 /** Bytes = 1, KB = 1024,  MB= 1048576 */       
}VM_policy_info_t, *VM_policy_info_p_t;

typedef struct HSM_policy_info_s
{
    logical is_active;  
    logical migrate_on_refile;               
    logical migrate_checkedout_file;       
    logical migrate_in_process_file;      
    logical migrate_remote_file;         
    logical un_migrate_file;         
    logical purge_immediately;  
    int purge_low_water_mark;        
    int purge_high_water_mark;      
    int migrate_from_tier;           
    int migrate_to_tier;            
    int file_size_range_from;     
    int file_size_range_to;      
    int file_size_units;          /** Bytes = 1, KB = 1024,  MB= 1048576 */       
    int file_access_times;     
}HSM_policy_info_t, *HSM_policy_info_p_t;

#ifdef __cplusplus
extern "C"{
#endif

    /**
    Creates a new HSM_Policy in the database. Need DBA Privileges to create the HSM policy
    It returns the policy tag.
    */

    extern SA_API int SA_create_hsm_policy(
        const char          policy_name[SA_name_size_c + 1],         /**< (I) Name of migration policy */
        const char          policy_desc[SA_description_size_c + 1],  /**< (I) Description of Policy */
        date_t              accessed_before,                         /**< (I) Argument to specify lastAccessDate ange of Volume File */
        date_t              accessed_after,                          /**< (I) Argument to specify lastAccessDate                                                                                                        range of Volume File */
        HSM_policy_info_p_t policy_info,                             /**< (I) Migration/Purging specific filters                                                                                                        and attributes */                  
        tag_t               query_tag,                               /**< (I) Tag of saved query belonging to Class                                                                                                     Item, ItemRevision or Dataset */
        int                 entry_count,                             /**< (I) Number of user entries in this query. */
        const char**        entries,                                 /**< (I) Array of user entries. */
        const char**        values,                                  /**< (I) Array values for the user entries. */    
        tag_t*              policy_tag                               /**< (O) Policy Tag */
        );

    /**
    Modifies a HSM_Policy in the database. Need DBA Privileges to modify the HSM policy
    */

    extern SA_API int SA_modify_hsm_policy(
        tag_t               policy_tag,                              /**< (I) Policy Tag */
        const char          policy_desc[SA_description_size_c + 1],  /**< (I) Description of Policy */
        date_t              accessed_before,                         /**< (I) Argument to specify lastAccessDate                                                                                                        range of Volume File */
        date_t              accessed_after,                          /**< (I) Argument to specify lastAccessDate                                                                                                        range of Volume File */
        HSM_policy_info_p_t policy_info,                             /**< (I) Migration/Purging specific filters                                                                                                        and attributes */                  
        tag_t               query_tag,                               /**< (I) Tag of saved query belonging to Class                                                                                                     Item, ItemRevision or Dataset */
        int                 entry_count,                             /**< (I) Number of user entries in this query. */
        const char**        entries,                                 /**< (I) Array of user entries. */
        const char**        values                                   /**< (I) Array values for the user entries. */    
        );

    /**
    Creates a new VM_Policy in the database. Need DBA Privileges to create the HSM policy
    It returns the policy tag.
    */

    extern SA_API int SA_create_vm_policy(
        const char          policy_name[SA_name_size_c + 1],         /**< (I) Name of migration policy */
        const char          policy_desc[SA_description_size_c + 1],  /**< (I) Description of Policy */
        date_t              accessed_before,                         /**< (I) Argument to specify lastAccessDate ange of Volume File */
        date_t              accessed_after,                          /**< (I) Argument to specify lastAccessDate                                                                                                        range of Volume File */
        VM_policy_info_p_t policy_info,                              /**< (I) Migration/Purging specific filters                                                                                                        and attributes */                  
        tag_t               query_tag,                               /**< (I) Tag of saved query belonging to Class                                                                                                     Item, ItemRevision or Dataset */
        int                 entry_count,                             /**< (I) Number of user entries in this query. */
        const char**        entries,                                 /**< (I) Array of user entries. */
        const char**        values,                                  /**< (I) Array values for the user entries. */    
        tag_t*              policy_tag                               /**< (O) Policy Tag */
        );

    /**
    Modifies a VM_Policy in the database. Need DBA Privileges to modify the HSM policy
    */
    extern SA_API int SA_modify_vm_policy(
        tag_t               policy_tag,                              /**< (I) Policy Tag */
        const char          policy_desc[SA_description_size_c + 1],  /**< (I) Description of Policy */
        date_t              accessed_before,                         /**< (I) Argument to specify lastAccessDate                                                                                                        range of Volume File */
        date_t              accessed_after,                          /**< (I) Argument to specify lastAccessDate                                                                                                        range of Volume File */
        VM_policy_info_p_t policy_info,                              /**< (I) Migration/Purging specific filters                                                                                                        and attributes */                  
        tag_t               query_tag,                               /**< (I) Tag of saved query belonging to Class                                                                                                     Item, ItemRevision or Dataset */
        int                 entry_count,                             /**< (I) Number of user entries in this query. */
        const char**        entries,                                 /**< (I) Array of user entries. */
        const char**        values                                   /**< (I) Array values for the user entries. */    
        );

    /**
    Provides the name of policy Class. Can be HSM_Policy or VM_Policy 
    */
    extern SA_API int SA_policy_name_of_class(
        tag_t               policy_tag,          /**< (I) Policy Tag */
        char**              class_name           /**< (OF) Name of Class */
        );
    
    /**
    Deletes a Migration Policy in the database. Need DBA Privileges to delete the policy
    */
    extern SA_API int SA_delete_policy(
        tag_t               policy_tag      /**< (I) Policy Tag */
        );

    
    /**
       Retrieves the policy tag associated with valid policy name
    */
    extern SA_API int SA_find_policy_tag2(
        const char          *policy_name,                      /**< (I) Name of migration policy */
        tag_t*              policy_tag                         /**< (O) Policy Tag */
        );
    
    
    /**
       Retrieves the policy name associated with valid policy tag
    */
    extern SA_API int SA_find_policy_name2(
        tag_t               policy_tag,                      /**< (I) Policy Tag */
        char                **policy_name                    /**< (OF) Name of migration policy */
        );
    
    /**
       Retrieves  the policy name associated with valid policy tag
    */
    extern SA_API int SA_extent_policies(
        int*               num_of_policies,   /**< (O) Number of policies */
        tag_t**            policies_tags      /**< (OF) Array of Policy tags */
        );
    
    /**
       Provides Migration/Purging specific filters and attributes of a HSM_Policy 
    */
    extern SA_API int SA_ask_hsm_policy_info (
        tag_t                    policy_tag, /**< (I) Policy Tag */
        HSM_policy_info_p_t      policy_info /**< (O) Migration/Purging specific filters and attributes */  
        );
    
    /**
       Provides Migration/Purging specific filters and attributes of a VM_Policy 
    */
    extern SA_API int SA_ask_vm_policy_info (
        tag_t                    policy_tag, /**< (I) Policy Tag */
        VM_policy_info_p_t       policy_info /**< (O) Migration/Purging specific filters and attributes */  
        );
    
    
    /**
       Provides saved query tag and user entry and values of a policy
    */
    extern SA_API int SA_ask_policy_query (
        tag_t               policy_tag,   /**< (I) Policy Tag */
        tag_t*              query_tag,    /**< (O) Tag of saved query belonging to Class                                                                                                     Item, ItemRevision or Dataset */
        int*                entry_count,  /**< (O) Number of user entries in this query. */
        char***             entries,      /**< (OF) Array of user entries. */
        char***             values        /**< (OF) Array values for the user entries. */    
        );
    
    /**
       Evaluates the policy and mark the files for migration.
    */
    extern SA_API int SA_mark_for_migration (
        tag_t                    policy_tag,     /**< (I) Policy Tag */
        int*                     num_of_objs,    /**< (O) Number of requests */ 
        tag_t **                 request_objs    /**< (OF) Array of Migration Pending Requests */  
        );
    
    /**
       Retrieves Migration Pending Requests. 
    */
    extern SA_API int SA_get_pending_requests (
        tag_t                    policy_tag,     /**< (I) Policy Tag */
        int*                     num_of_objs,    /**< (O) Number of requests */ 
        tag_t **                 request_objs    /**< (OF) Array of Migration Pending Requests */  
        );
    
    /**
       Exports Migration Pending Request to the OS file either in  Text or XML format
    */
    extern SA_API int SA_export_pending_requests (
        int                    num_of_requests,   /**< (I) No of request objects */ 
        const tag_t*           request_tags,      /**< (I) Migration Pending request object tags */
        int                    format,            /**< (I) Export format. Valid values are 1 - Text                                                                                                   format , 2 -XML format */ 
        const char*            export_file_path   /**< (I) OS file path to which the output will be saved */  
        );
    /**
       Migrates all Teamcenter 2007 volume files under pending request.
       This function applies the migration related attribute changes on Teamcenter volume 
       file object in database  If this  function is called in the context of HSM Migration than
       ensure that the physical files have been previously migrated by 3rd party HSM systems.  
    */
    extern SA_API int SA_migrate_pending_request (
        tag_t                    request_tag,   /**< (I) Migration Pending request object tag */
        logical                  fms_migration  /**< (I) True or False values depending upon FMS 
                                                   OR 3rd Party Migration */
        );
    
    /**
       Generates the migration report based on specific migration policy. 
    */
    extern SA_API int SA_generate_migration_report (
        tag_t               policy_tag,           /**< (I) Policy Tag. Can be NULLTAG to generate report on all policies*/
        date_t              migration_from_date,  /**< (I) Argument to report migration date range of Volume File */
        date_t              migration_to_date,    /**< (I) Argument to report migration date range of Volume File */
        const char*         report_file_path      /**< (I) OS file path to which the report will be saved */  
        );
    
    
    /**
       Retrieves the TCE Volume file's related hsm_info object. 
    */
    extern SA_API int SA_get_hsminfo_tag (
        tag_t               file_tag,      /**< (I) Tag of TCE Volume file object */
        tag_t*              hsm_info_tag   /**< (O) Tag of related hsm_info object */
        );
    
    /**
       Retrieves the TCE Volume file's related vm_info object. 
    */
    extern SA_API int SA_get_vminfo_tag (
        tag_t               file_tag,     /**< (I) Tag of TCE Volume file object */
        tag_t*              vm_info_tag   /**< (O) Tag of related vm_info object */
        );

/** @} */

#ifdef __cplusplus
}
#endif

#include <sa/libsa_undef.h>
#endif
