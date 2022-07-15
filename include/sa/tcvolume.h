/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This file contains the constants, data structures and function prototypes for
    working with the class TcVolume and specifically with the C ITK interface to this class.

    Volumes are POMApplication Objects so AOM functions will work with them.
*/

/*  */

#ifndef TCVOLUME_H
#define TCVOLUME_H

#include <tc/tc_startup.h>
#include <ss/ss_const.h>
#include <sa/libsa_exports.h>

/**
    @defgroup TCVOLUME Teamcenter Volumes
    @ingroup SA

    This set of functions enables you to create and manipulate volumes for Teamcenter.

    Because Teamcenter Volumes are POM Application Objects, AOM functions work with them.

    Include tcvolume.h to use these functions.
    @{
*/

#define VM_node_size_c  80
#define VM_path_size_c  SS_MAXPATHLEN
#define VM_name_size_c  32
#define VM_TCP_ACCESS    1
#define VM_FMS_ACCESS    1
#define VM_NO_SECURITY   2

#define VM_external_storage_id_c 256
#define VM_storage_type_c         64

#ifdef __cplusplus
extern "C"{
#endif

/**
    Lists all instances of Teamcenter Volumes.
*/
extern SA_API int VM_extent(
    int*          n_instances,  /**< (O) */
    tag_t**       instances     /**< (OF) n_instances */
    );


/**
    Finds a volume with the given name.
    <br/>If @p volume is #NULLTAG, no volumes exist with the given name.
    <br/>An error is not returned if no volumes exist with the given name.
*/
extern SA_API int VM_find2(
    const char    *volume_name,                     /**< (I) */
    tag_t*        volume                            /**< (O) */
    );


/**
    Retrieves the tag of the volume with the given path name.
    <br/>The machine type (#SS_WNT_MACHINE or #SS_UNIX_MACHINE),
    must be specified to indicate whether you want to match on the UNIX or NT pathname.
*/
extern SA_API int VM_find_by_path2(
    const char    *path,                    /**< (I) */
    int           machine_type,             /**< (I) */
    tag_t*        volume                    /**< (O) */
    );


/**
    Retrieves the current value for the specified attribute on the specified volume.
*/
extern SA_API int VM_ask_name2(
    tag_t         volume,                           /**< (I) */
    char          **volume_name                     /**< (OF) */
    );

/**
    Retrieves the current value for the specified attribute on the specified volume.
*/
extern SA_API int VM_ask_node_name2(
    tag_t         volume,                           /**< (I) */
    char          **node_name                       /**< (OF) */
    );


/**
    Retrieves the current value for the specified attribute on the specified volume.
*/
extern SA_API int VM_ask_path2(
    tag_t         volume,                   /**< (I) */
    int           machine_type,             /**< (I) */
    char          **path                    /**< (OF) */
    );

/**
    Retrieves the current value for the specified attribute on the specified volume.
*/
extern SA_API int VM_ask_machine_type(
    tag_t         volume,       /**< (I) */
    int*          machine_type  /**< (O) */
    );

/**
    Retrieves the current access mode for the volume.
    <br/>This can be either #VM_FMS_ACCESS or #VM_NO_SECURITY.
*/
extern SA_API int VM_ask_access_mode(
    tag_t         volume,       /**< (I) */
    int*          access_mode   /**< (O) */
    );

/**
    Grants or revokes access to the given volume for a user or group.
*/
extern SA_API int VM_grant_access(
    tag_t         volume,   /**< (I) */
    tag_t         target    /**< (I) */
    );

/**
    Grants or revokes access to the given volume for a user or group.
*/
extern SA_API int VM_revoke_access(
    tag_t         volume,   /**< (I) */
    tag_t         target    /**< (I) */
    );

/**
    Checks if a specific user has access to specific volume.
    <br/>The access flag is TRUE if the currently logged in user has access to the input volume.
    <br/>The access flag is FALSE if the user does not have access.
    <br/>The volume and user arguments specify the volume and user for which access is to be checked.
*/
extern SA_API int VM_check_access(
    tag_t         volume,       /**< (I) */
    tag_t         user,         /**< (I) */
    int*          access_flag   /**< (O) */
    );

/**
    Retrieves an array of tags for all of the groups and users that have access to this volume.
    <br/>The space allocated to tag_list should be freed with a call to #MEM_free.
*/
extern SA_API int VM_ask_access_list(
    tag_t         volume,   /**< (I) */
    int*          count,    /**< (O) */
    tag_t**       tag_list  /**< (OF) count */
    );

/**
    Retrieves the volume currently assigned to the user.
*/
extern SA_API int VM_ask_current_volume(
    tag_t*        volume_tag    /**< (O) */
    );

/**
    Retrieves the local volume currently assigned to the current user.
*/
extern SA_API int VM_ask_current_local_volume(
    tag_t*        volume_tag    /**< (O) */
    );

/**
    Retrieves the local volume currently assigned to the specified user.
*/
extern SA_API int VM_ask_current_local_volume_for_user(
    tag_t         user_tag,     /**< (I) */
    tag_t*        volume_tag    /**< (O) */
    );

/**
    Checks if Store and Forward is enabled for this user.
*/
extern SA_API int VM_ask_store_and_forward_enabled(
    logical*        enabled    /**< (O) */
    );

/**
    Sets the current volume to that specified by volumeTag or volumeName.
    <br/>@p volume_name is used if @p volume is set to #NULLTAG.
*/
extern SA_API int VM_set_current_volume(
    tag_t         volume,        /**< (I) */
    char*         volume_name    /**< (I) */
    );

/**
    Sets the current local volume to that specified by volumeTag or volumeName.
    <br/>@p volume_name is used if @p volume is set to #NULLTAG.
    <br/>@p volume takes precedence over @p volume_name in case both parameters are present.
*/
extern SA_API int VM_set_current_local_volume(
    tag_t         volume,        /**< (I) The current local volume. */
    char*         volume_name    /**< (I) The current local volume name */
    );

/**
    Converts a pathname contain an environment variable to a complete operating system pathname.
*/
extern SA_API int VM_expand_path(
    char*         old_path,      /**< (I) Path name returned from #VM_ask_path2.
                                    <br/>It can contain a logical or an environment variable. */
    char*         new_path       /**< (O) Full operating system pathname */
    );


/**
    Creates a new volume and automatically saves it if there are no errors.
*/
extern SA_API int VM_createEx2(
    const char*  volume_name,                     /**< (I) */
    const char*  node_name,                       /**< (I) */
    const char** path_names,                         /**< (I) Pathname of the volume to be created.
                                                             The array index should correspond to the machine type
                                                             on which the volume will reside.
                                                             (e.g. pathnames[SS_WNT_MACHINE] = myNTVolumePath; */
    int           machine_type,                     /**< (I) Must be #SS_WNT_MACHINE, #SS_UNIX_MACHINE or SS_MACHINE_TYPE
                                                            (i.e., the type of machine you are running on) */
    tag_t*        volume                            /**< (O) */
    );


/**
    Creates a new volume and automatically saves it if there are no errors.
    <br/>The FMS configuration will be automatically updated.
    <br/>Only one of fsc_name, filestore_group, and load_balancer may be specified.  The other two arguments must be NULL.
    <br/>@p fsc_path is obsolete.  Any value may be specified, but a value of NULL is recommended.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#VM_INV_PATH if the pathname for the volume is does not exist or is syntactically incorrect.
    <li>#VM_NO_CREATE if the volume cannot be created.  This could occur for any number of reasons
    including, but not limited to, an inactive FSC.
    <li>#VM_NO_FSC_NAME_GRP_AND_LB if the arguments fsc_name, filestore_group, and load_balancer are all null.
    <li>#VM_BAD_COMB_FSC_NAME_GRP_LB if a load_balancer argument is supplied and either the fsc_name
    or the filestore_group are non-null.
    </ul>
    */
extern SA_API int VM_createExFMS2(
    const char    *volume_name,                    /**< (I) The name of the volume to be created. */
    const char    *node_name,                      /**< (I) The name of node on which the volume will reside. */
    const char    **path_names,                    /**< (I) Pathname of the volume to be created.
                                                             The array index should correspond to the machine type
                                                             on which the volume will reside.
                                                             (e.g., pathnames[SS_WNT_MACHINE] = myNTVolumePath; */
    int           machine_type,                     /**< (I) Must be #SS_WNT_MACHINE, #SS_UNIX_MACHINE or SS_MACHINE_TYPE
                                                            (i.e., the type of machine you are running on) */
    const char*   fsc_path,                         /**< (I) Obsolete.  A value of NULL is recommended. */
    const char*   fsc_name,                         /**< (I) The name of the FSC that will serve this volume.  May be NULL. */
    const char*   filestore_group,                  /**< (I) The name of the Filestore Group that will serve this volume.  May be NULL. */
    const char*   load_balancer,                    /**< (I) The name of the Load Balancer that will serve this volume.  May be NULL. */
    tag_t*        volume                            /**< (O) The tag of the volume that was created.*/
    );


/**
    Initializes standard volume attributes for a newly created instance of a subclass of TcVolume.
    <br/>It is not necessary to call it for any TcVolumes.
*/
extern SA_API int VM_initializeEx2(
    tag_t         volume,                           /**< (I) */
    const char    *volume_name,                     /**< (I) */
    const char    *node_name,                       /**< (I) */
    const char **path_names,                        /**< (I)  Pathname of volume whose attributes will be initialized.
                                                             The array index should correspond to the machine type
                                                             on which the volume resides.
                                                             (e.g. pathnames[SS_WNT_MACHINE] = myNTVolumePath;*/
    int           machine_type                      /**< (I) */
    );


/**
    Sets new values for all of the input attributes for a volume.
    <br/>All of the input values to this function must have valid values.
    <br/>Even if you only want to change the volume name you must first read the current values of node_name,
    vms_path, unix_path, and machine_type,
    then pass the current values along with the new value for volume_name into this function.

    <br/>If you provide new values for the paths, only the TcVolume attributes will be modified.
    The files will not be moved and a new directory will not be created. Also ensure that
    the OS directories can be created under the modified paths.
    In addition you may have to manually configure the fmsmaster.xml with the modified
    path to make the volume available.
*/
extern SA_API int VM_modifyEx2(
    tag_t         volume,                           /**< (I) */
    const char    *volume_name,                     /**< (I) */
    const char    *node_name,                       /**< (I) */
    const char **path_names,                        /**< (I) Pathname of volume whose attributes will be modified.
                                                             The array index should correspond to the machine type
                                                             on which the volume resides.
                                                             (e.g. pathnames[SS_WNT_MACHINE] = myNTVolumePath;*/
    int           machine_type                      /**< (I) */
    );


/**
    Moves a volume and all of its contents to another location.
    <br/>The TcVolume object is saved automatically on success.
*/
extern SA_API int VM_moveEx2(
    tag_t         volume,                           /**< (I) */
    const char    *node_name,                       /**< (I) */
    const char  **path_names,                       /**< (I) Pathname of the destination volume.
                                                             The array index should correspond to the machine type
                                                             on which the newly located volume will reside.
                                                             (e.g. pathnames[SS_WNT_MACHINE] = myNTVolumePath;*/
    int           machine_type                      /**< (I) Unused. */
    );

/**
    Lists all Teamcenter Volumes to which user has access.
*/
extern SA_API int VM_list_accessible_volumes(
    int*          n_instances,   /**< (O)  Count of volume instances. */
    tag_t**       instances      /**< (OF) n_instances */
    );

/**
    Obtains the storage ID and storage type of the given volume in the external system.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>Possibly other error codes.
    </ul>
*/
extern SA_API int VM_ask_storage (
    tag_t         volume,                           /**< (I)  The volume */
    char          **storage_type,                   /**< (OF) Storage type */
    char          **storage_id                      /**< (OF) External ID */
    );

/**
    Sets the storage type of the given volume in the external system.

    @note Teamcenter uses this storage type when constructing FMS ticket for files owned by this volume.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>Possibly other error codes.
    </ul>
*/
extern SA_API int VM_set_storage_type (
    tag_t         volume,                           /**< (I)  The volume */
    const char    *storage_type                     /**< (I)  Storage type */
    );

/**
    Sets the storage ID of the given volume in the external system.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>Possibly other error codes.
    </ul>
*/
extern SA_API int VM_set_storage_id (
    tag_t         volume,                           /**< (I)  The volume */
    const char    *storage_id                       /**< (I)  External ID */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <sa/libsa_undef.h>

#endif
