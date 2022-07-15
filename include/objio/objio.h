/* Copyright 2020 Siemens Digital Industries Software
 ==================================================
 Copyright 2015
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2020 Siemens Digital Industries Software */

/**
    @file

    This header file declares constants and functions to be used by
    clients of the OBJIO class (for Backup/Recover/Import/Export/Archive/Restore).
*/

/*  */

#ifndef OBJIO_H
#define OBJIO_H

#include <tccore/tctype.h>
#include <archive/objio_errors.h>
#include <pom/pom/pom.h>
#include <sa/sa.h>
#include <ss/ss_const.h>
#include <tccore/workspaceobject.h>
#include <epm/epm.h>
#include <objio/libobjio_exports.h>

/**
    @defgroup OBJIO Object Import and Export (OBJIO)
    @ingroup TC
    The Object Import/Export (OBJIO) module facilitates the movement of data associated with
    Teamcenter objects between Teamcenter sites with either "read-only" or "write" privileges.

    The object types, including all their internal supporting data, that can be imported or exported are:

    <table>
    <tr><td>Folders </td><td>When exporting, you may choose to export any general folder.
                             You may not export pseudo folders.                               </td></tr>
    <tr><td>Datasets</td><td>When exporting, you may choose to export either all versions,
                             the latest version, or a specific version.                       </td></tr>
    <tr><td>Forms   </td><td>When exporting, you may choose to export a Form.
                             The definition of the form (UIL) must be identical at both sites.</td></tr>
    <tr><td>Items   </td><td>When exporting, if you choose an Item, then the Item and all its related data
                             (such as the Item Revisions, BOM View and BOM View Revisions,
                             associated Item Master and Item Revision master forms,
                             and also any exportable Requirement, Specification,
                             Manifestation or Reference objects) are exported.
                             Additionally, if the selected Item has an assembly (structure),
                             then all the items that make up the assembly are exported.       </td></tr>
    </table>

    You cannot choose part of an Item to be exported.
    For example, you cannot choose an Item Revision alone to be exported.
    You need to select the Item which contains this Item Revision, in order to export the Item.
    Similarly, the same would be true with BOMView and BOMViewRevision objects.

    @note You can export any forms, datasets or any other exportable objects associated with the Item.
        These will be as independent objects, rather than being part of the Item.

    All the Teamcenter files that the dataset represents will be exported,
    including the operating system files that these encapsulate, and the dataset's revision anchor.

    When exporting, there is an option to transfer the ownership to another site.
    If the ownership is transferred to a particular site, then,
    when the same objects are imported at that particular site,
    they will be imported with a read/write privilege. If the ownership is not transferred,
    then the ownership of the objects still belongs to the export site.
    When these objects are imported at another site, they will be imported with read only privilege.
    Any modifications attempted on them would not be allowed.

    <b>Common Return Values</b>

    <table>
    <tr><td>Return Value                      </td><td>Description                                                  </td></tr>
    <tr><td>#BIER_invalid_for_remote_bier_type</td><td>manager_tag was not created with the proper type.            </td></tr>
    <tr><td>#IDSM_client_access_denied        </td><td>The local site is not a permitted client of the remote site. </td></tr>
    <tr><td>#IDSM_no_connect                  </td><td>Unable to connect to remote site.                            </td></tr>
    <tr><td>#OBJIO_cannot_reuse_dir           </td><td>area_name has already been used for object export.           </td></tr>
    <tr><td>#OBJIO_dir_not_found              </td><td>area_name does not exist.                                    </td></tr>
    <tr><td>#OBJIO_invalid_attribute_flag     </td><td>The attribute flag given for the import/export area is not supported.
                                                       See objio.h for valid attribute flags.                       </td></tr>
    <tr><td>#OBJIO_invalid_dir_contents       </td><td>Cannot read the import data.
                                                       Most likely due to out-of-date or missing POM transmit files.</td></tr>
    <tr><td>#OBJIO_invalid_site               </td><td>The given target site is not defined in the database.        </td></tr>
    <tr><td>#OBJIO_invalid_tag                </td><td>The given tag for the import/export manager is not valid.    </td></tr>
    <tr><td>#OBJIO_unsupported_type           </td><td>The type given for the import/export area is not supported.
                                                       See objio.h for valid types.                                 </td></tr>
    </table>
    @{
*/

/**
 @defgroup OBJIO_AREA Type of import/export manager to create via OBJIO_create().
 @ingroup OBJIO
 @{
*/

/**Defines a local export operation area*/
#define OBJIO_export_type                       1

/**Defines a local import operation area*/
#define OBJIO_import_type                       2

/** Defines an OBJIO area for archived objects.
<br/>Archived objects are exportable, but not transferable. */

#define OBJIO_archive_type                      3

/**Defines an OBJIO area for archived objects.*/
#define OBJIO_restore_type                      4

/**Defines an OBJIO area for backup objects.*/
#define OBJIO_backup_type                       5

/**Defines an OBJIO area for recovery objects.*/
#define OBJIO_recover_type                      6

/**OBJIO_create() should be called to create the manager_tag, specifying a type of
#OBJIO_remote_transfer_from_type as well as the local directory
 where the metafile will go into.*/
#define OBJIO_remote_transfer_from_type         7

/**OBJIO_create() must be called with a type of #OBJIO_remote_transfer_to_type
    and with the local directory containing the metafile*/
#define OBJIO_remote_transfer_to_type           8

/** @} */


/**
    @defgroup OBJIO_IMPORT_EXPORT_TOKENS Tokens
    <br/>Import/Export Options tokens are to be used to set the an import/export option by calling OBJIO_set_attribute().
    <br/>Unless otherwise specified, an option is set to either 1 or 0 to indicate if option is selected/set or not
    @ingroup OBJIO
    @{
*/

/**Set this option to export all dataset versions.*/
#define OBJIO_dataset_all_versions              1

/**Set this option to export all revisions.
<br/>When transferring site ownership, this is the only option available.*/
#define OBJIO_item_all_revisions                2

/**This Opotion assumes that Object is owned by this Site.*/
#define OBJIO_assume_ownership                  3

/**This option aborts operation if object is chacked out.*/
#define OBJIO_abort_if_checked_out              4

/**This option includes the contents of any specified folders.*/
#define OBJIO_include_contents                  5

/**Select this option to transfer site ownership of the selected assembly
item and export all components with no site ownership transfer.
<br/>This option is enabled only if the Transfer Ownership option is selected.*/
#define OBJIO_xfr_top_lvl_only                  6

/**Set this option to exclude reference attachments when transferring site ownership.*/
#define OBJIO_xfr_xcl_ref_atth                  7

/**Set this option to exclude requirement attachments when transferring site ownership.*/
#define OBJIO_xfr_xcl_req_atth                  8

/**Set this option to exclude Manifestation attachments when transferring site ownership.*/
#define OBJIO_xfr_xcl_manif_atth                9

/**Set this option to exclude Specifications when transferring site ownership.*/
#define OBJIO_xfr_xcl_spec_atth                 10

/**Set this option to exclude Reference attachments when replicating.*/
#define OBJIO_xcl_ref_atth                      11

/**Set this option to exclude Requirement attachments when replicating.*/
#define OBJIO_xcl_req_atth                      12

/**Set this option to exclude Manifestation attachments when replicating.*/
#define OBJIO_xcl_manif_atth                    13

/**Set this option to exclude Specification attachments when replicating.*/
#define OBJIO_xcl_spec_atth                     14

/**This option exports dataset refrences.*/
#define OBJIO_export_dataset_refs               15

/**Select this option to include all components if the item selected is an assembly.
<br/>The revision selectors allow you choose which revision to
export with the selected item and its component items, if applicable.
You can choose only one revision selector.*/
#define OBJIO_export_BOM_components             16

/**Select this option to include a workspace object only if it was modified
since the last time it was exported to the target sites.
<br/>For example, if only the specification dataset was modified, then it is included and the remaining items are excluded.
<br/>When exporting to multiple target sites, an object is exported if it was modified since the last export to any site on the list.*/
#define OBJIO_include_modified_only             17

/**Select this option to exclude workspace objects that are protected
through the Access Manager from replication to remote sites.
<br/>For example, some of the revisions for an item do not have Export
and/or Import privileges granted at the owning site.
<br/>When this option is cleared, you receive an error when attempting to import/export the item.
<br/>By selecting this option, you can import/export those revisions (or other subobjects) that have Export and Import privileges.*/
#define OBJIO_exclude_protected_wso             18

/**Select this option to exclude assembly components that are protected through Access Manager from site ownership transfer to remote sites.*/
#define OBJIO_exclude_no_xfr_comp               19

/**Select this option to exclude assembly components that are protected through the Access Manager from replication to remote sites.*/
#define OBJIO_exclude_protected_comp            20

/**Set this option to export/import only the particular item revision selected in the GUI or specified via the -rev switch of a command line util.
<br/>This option is not valid for Remote Import of an item revision for the first time; however, it can be used for Remote Import to re-import a previously replicated item revision.*/
#define OBJIO_selected_revs_only                21

/**Set this option to export the latest revision regardless of whether it is a working or released revision*/
#define OBJIO_latest_rev_only                   22

/**Set this option to export the latest working revision, if any; if no working revision found, an error is returned. */
#define OBJIO_latest_working_rev_only           23

/**Set this option to export the latest released revision with any release status.If no released revision is found, an error is returned*/
#define OBJIO_latest_released_rev_only          24

/**Set this option to export the latest working revision;if no working revision is found, export the latest released item revision with any release release status.*/
#define OBJIO_latest_working_any_only           25

/**This option states whether this is synching operation*/
#define OBJIO_is_synchronizing                  26

/**Set this option if the operation is to be performed over a network to differentiate it with an offline operation (such as item_export/item_import).*/
#define OBJIO_is_remote_operation               27

/**If you select this option, no actual import or export object operation is performed.
<br/>Instead, a dry run of the import or export is performed and a report is generated.
<br/>During the dry run, all import/export options selected apply.
<br/>The report contains the list of Teamcenter objects that
are exported/imported if the actual operation were to be performed plus the names and size of files.
<br/>The report also includes error codes and messages for errors that would be encountered during the actual operation.
<br/>You can print the report or save it to a text or HTML file.*/
#define OBJIO_preview_mode                      28

/**This option genrates report after completion of Operation*/
#define OBJIO_completion_report                 29

/**Select this option to allow the remote import or export objects operation to continue
 if errors are encountered while importing/exporting optional objects.
 <br/>The objects that are required are dependent on your data model with many
 objects related to items being optional.*/
#define OBJIO_continue_on_error                 30

/**Use this option to ignore any import/export error regardless of whether object is required or optional.
<br/>Currently used only with undocumented "-force" switch in item_import util which is used to fix corrupted objects.
<br/>Use with extreme caution.*/
#define OBJIO_force_import_export               31

/**Set this to export the latest item revision with the given release status; if no item revision is found with the given release status, an error is returned.
<br/>This is currently available in the Rich Client only but it can also be used in command line utils if so desired.*/
#define OBJIO_specific_status_only              32

/**If selected during a remote import, set this option to execute the
Remote Import operation in the background so you can continue to use your workspace session
while the import/export operation takes place behind the scene.
<br/>You are allowed to import in background only one selected object at a time
so it is recommended that you use this option for importing an assembly.
<br/>While the background operation takes place, you can perform other Multi-Site Collaboration operations.
<br/>Even with the multiple simultaneous Multi-Site Collaboration operations, only one Multi-Site
Collaboration user license is used.*/
#define OBJIO_is_background_mode                33

/**When this option is selected, all the options that were used during the last export/import operation on an item,
as stored in the ItemExportRecord, will be used for the current operation.
<br/>By default, the data_sync utility synchronizes only the latest revision of
an item (latest_revision) when synchronizing to multiple sites.
<br/>If you are synchronizing to a single site, the selector used the last time the item was exported (same_as_last_export) is used.*/
#define OBJIO_same_as_last_export               34

/**Set this option to prevent the remote IDSM process from terminating until the client itself terminates.*/
#define OBJIO_synchronous_remote_transfer       35

/**Select this option to include components that may be owned by sites
other than the site from which you are importing an assembly.
Includes distributed components within a distributed assembly.
<br/>A distributed assembly consists of components owned by more than one site.
<br/>First, the top-level assembly and all components owned by the assemblies owning site are retrieved.
<br/>Then individual distributed components are retrieved from their respective owning sites.
<br/>This option is enabled only when you select the Include Entire BOM option.
<br/>It cannot be used in conjunction with the Transfer Ownership option.
<br/>This option is available only when you select the Remote Import
option; it cannot be used with an Interactive Object Export command.*/
#define OBJIO_is_retrieving_distributed_comp    36

/**Select this option to export all the revision(s) that are released.*/
#define OBJIO_all_released_revs_only            37

/**Select this option to include the BOMChange objects associated
with the affected assembly of the selected change object during
remote export.*/
#define OBJIO_include_bomchanges                38

/**Select this option to include supersedure objects associated with
each BOMChange object during a remote export.
<br/>When you select this option, you must also select the Include BomChanges option,
because supersedure information can only be transferred within the
context of a BOMChange.*/
#define OBJIO_include_supercedures              39

/**This option is set when export is performed for remote checkin*/
#define OBJIO_export_for_remote_checkin         40

/**This option is set when import is performed for remote checkin*/

#define OBJIO_import_for_remote_checkin         41
/**
Set this option to exclude variant expressions from the export/import operation.
*/
#define OBJIO_exclude_variant_expressions       42

/**Set this to defer the export/import of variant expressions. Can now be used to defer export/import of any class.*/
#define OBJIO_is_variant_background_mode        43

/**Set this to indicate that the transfer of volume files should be done via the FSC. Set this for export/import operations over a network.
<br/>Unset it for offline operations.*/
#define OBJIO_defer_bulk_data_xfer              44

/**This option is specific to NX Part Families.
<br/>Select this option to include Part Family members.*/
#define OBJIO_include_pfmembers                 45

/**This option is specific to NX Part Families.
<br/>Select this option to include Part Family templates*/
#define OBJIO_include_pftemplates               46

/**This option is related to NX Part Families.
<br/>This option is set to export entire BOM of NX part families*/
#define OBJIO_bom_pf_option                     47

/**This option is set to get error report for perticular operation*/
#define OBJIO_error_report                      48

/**Select the revision rule to use for the report or synchronization
from a list of local site revision rules. When synchronizing
item revisions, Selected Revision appears as the value for the revision rule.
<br/>This indicates that the selected revision is the configured revision to be synchronized.*/
#define OBJIO_specific_rev_rule_only            49

/**This option is set for performing synchronous transfer of ownership*/
#define OBJIO_synchronous_site_transfer         50

/**When performing a remote import with transfer of ownership, Multi-Site Collaboration first exports the
object from the remote site into a metafile, then copies the metafile over the network in preparation
for import into the local site.
<br/>If an error occurs after the export but before the object is imported, the object is in a state where it
is not owned by any site. Multi-Site Collaboration attempts to automatically recover from such an
error by restoring ownership at the remote site using the metafile located at the remote site's transfer
area.*/
#define OBJIO_export_recovery_mode              51

/**When this option is set it indicates that operation is remote export to be performed over a network
to differentiate it with an offline operation (such as item_export/item_import)*/
#define OBJIO_is_remote_send                    52

/** @} */
/**
@defgroup OBJIO_Global_Organization_Project Global Organization Project
@ingroup OBJIO

Options set by OBJIO_set_attribute
@{
*/
#define OBJIO_all_roles                         53

/**Export all subgroups under a group.*/
#define OBJIO_all_subgroups                     54

/**Export all group members under a group, or all groupmembers associated with a user.*/
#define OBJIO_all_groupmembers                  55

/**Indicates this is an organization data export/import session.*/
#define OBJIO_org_exp_flag                      56

/**Indicates the organization data export type. Pass by RAC ICCT remote export operation.*/
#define OBJIO_org_exp_type                      57

/**Indicates this is an organization data export/import migration mode, to migrate remote site organization data as replica.*/
#define OBJIO_org_migrate_mode                  58

#define OBJIO_transfer_shared_effectivity       59

/** Indicates this is a batch transfer of variant expressions from one site to another */
#define OBJIO_batch_transfer_of_ve              60

/** @} */

/**
   @defgroup Global_Organization Global Organization
   <br/>Options used during import/export related to organization
   @ingroup OBJIO
   @{
*/

/**An indicator to indicate the pom_file has AllRoles set(through Bier ask/setData in organization import/export).*/
#define OBJIO_all_roles_key                     "AllRoles"

/**An indicator to indicate the pom_file has AllSubGroups set(through Bier ask/setData in organization import/export).*/
#define OBJIO_all_subgroups_key                 "AllSubGroups"

/**An indicator to indicate the pom_file has AllGroupMembers set(through Bier ask/setData in organization import/export).*/
#define OBJIO_all_groupmembers_key              "AllGroupMembers"

/**Indicate this is an organization data export/import session.*/
#define OBJIO_org_exp_flag_key                  "IsOrgImpExp"

/**Indicate the organization data export/import type.*/
#define OBJIO_org_exp_type_key                  "OrgExpType"

/**The first successfully stored organization top level object.*/
#define OBJIO_top_export_tag                    "TopExpObject"

/**The first successfully stored organization migration top level object.*/
#define OBJIO_top_migrate_tag                   "TopMigrateTag"

/**Indicate the selected Role to export under the RAC organization export panel tree.*/
#define OBJIO_role_export_index                 "RoleExpIndex"
/** @} */

/** Indicates Type of org object*/
typedef enum {
    PERSON_EXP = 0,                              /**<Person in Organization.*/
    ROLE_EXP,                                    /**<Role in Organization.*/
    GROUP_EXP,                                   /**<Group in Organization.*/
    USER_EXP,                                    /**<User in Organization.*/
    ROLE_IN_HIERACHY                             /**<Role in Organization.*/
}
ORGExpType;


/**
   @defgroup Relation_Options Relation Options
   <br/>This suggests that relation is mandatory or optional
   @ingroup OBJIO
   @{
*/
/**This option indicates that specified relation is required*/
#define OBJIO_IS_REQUIRED                       0

/**This option indicates that specified relation is optional*/
#define OBJIO_IS_OPTIONAL                       1
/** @} */

/**Holds reporting information on an object.*/
typedef struct OBJIO_report_s
{
    char    tag_string[POM_MAX_NAME_LENGTH+1];                            /**<Tag of object.*/
    char    object_id[WSO_name_size_c+1];                                 /**<Identifier of object.*/
    char    object_string[(WSO_name_size_c+1)*2];                         /**<Object display name.*/
    char    object_class[POM_MAX_NAME_LENGTH+1];                          /**<Class of Object.*/
    char    object_relation[TCTYPE_name_size_c+1];                        /**<Relation of object.*/
    char    object_comment[WSO_desc_size_c+1];                            /**<Object comment.*/
    int     error_code;                                                   /**<Returns Error code for failure objects */
    logical is_optional_object;                                           /**<Defines if object is optional.*/
} OBJIO_report_t;

/**
   @defgroup OBJIO_OPTIONS_TOKEN Tokens for OBJIO_set_sync_options
   @ingroup OBJIO
   @{
*/

/**Select this option to have the replica automatically synchronized
when master data is modified.*/
#define OBJIO_auto_sync                         1
/**Select this option if you want the replica to be synchronized in batch
mode using the sync utility.*/
#define OBJIO_batch_sync                        2
/**Select this option if you don't want the replica to be synchronized in batch
mode using the sync utility.*/
#define OBJIO_do_not_sync                       3

/** @} */

/**
   @defgroup OBJIO_Sync_Options Synchronization options
   @ingroup OBJIO
   @{
*/

/**Select this option if you want to be notified by e-mail when the master copy is modified and replica copy is automatically synchronized.*/
#define OBJIO_auto_sync_and_notify              101

/**Select this option if you want to sync replica copy but does not want notification via an email when the master copy is modified.*/
#define OBJIO_batch_sync_but_notify             102

/**Select this option if you want to be notified by e-mail but do not want replica to be automatically synchronized when the master copy is modified.*/
#define OBJIO_do_not_sync_but_notify            103

/**Select this option if you want to be notified by e-mail and synchronize replica copy when the master copy is modified.*/
#define OBJIO_notify_and_sync_unchanged         104

/**Select this option if you do not want to be notified by e-mail when the master copy is modified.*/
#define OBJIO_no_notify_and_sync_unchanged      105
/** @} */

/**
   @defgroup OBJIO_REVISION_RULE_OPTIONS Revision Rules
   <br/> These options indicate the status of revision rule at remote site
   @ingroup OBJIO
   @{
*/

/** This option indicates that rev rule at remote site is not defined*/
#define OBJIO_rev_rule_not_defined_at_remote_site     1

/** This option indicates that rev rule at remote site is diffrent*/
#define OBJIO_rev_rule_different_at_remote_site       2

/** This option indicates that rev rule at remote site is not identical even though it has same name*/
#define OBJIO_rev_rule_non_identical_with_same_name   3
/** @} */

#ifdef __cplusplus
extern "C"{
#endif

/**
    Creates an area to use when moving objects into or out of the database.

    <b>Restrictions:</b> The type must be #OBJIO_import_type or #OBJIO_export_type.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#SS_NOCREATE if the directory specified by @p area_name cannot be created.
    <li>#OBJIO_unsupported_type if the @p type is not supported.
    <li>#OBJIO_internal_error if any internal error occurs.
    </ul>
*/
extern OBJIO_API int OBJIO_create(
    int              type,          /**< (I) Type of area to create.
                                         <br>Types are #OBJIO_export_type, #OBJIO_import_type, #OBJIO_remote_transfer_from_type, #OBJIO_remote_transfer_to_type and #OBJIO_restore_type. */
    char*            area_name,     /**< (I) Name of the area (for #OBJIO_export_type,
                                            this is the name of the directory to be written to;
                                            for #OBJIO_import_type,
                                            it is the name of the directory to be read from). */
    tag_t*           manager_tag    /**< (O) Tag of the newly created area */
    );

/**
    Identifies the sites that are authorized to import the data that will be exported without ownership transfer.
    <br/>Either this function or #OBJIO_set_owning_site is required when exporting data.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BIER_invalid_site if an invalid site is specified.
    <li>#OBJIO_invalid_tag if the @p manager_tag is invalid.
    <li>#OBJIO_internal_error if any internal error occurs.
    </ul>
*/
extern OBJIO_API int OBJIO_set_target_sites(
    tag_t            manager_tag,   /**< (I) Tag of the OBJIO area to export data to */
    int              n_sites,       /**< (I) Number of target sites */
    tag_t*           site_list      /**< (I) n_sites Tag of target sites */
    );

/**
    Sets the given site as the new owning site.
    <br/>Either this function or #OBJIO_set_target_sites is required when exporting data.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BIER_invalid_site if an invalid site is specified.
    <li>#OBJIO_invalid_tag if the @p manager_tag is invalid.
    <li>#OBJIO_internal_error if any internal error occurs.
    </ul>
*/
extern OBJIO_API int OBJIO_set_owning_site(
    tag_t            manager_tag,   /**< (I) Tag of the OBJIO area to export data to */
    tag_t            site_tag       /**< (I) Tag of the new owning site */
    );


/**
    Sets the owning user of the imported objects.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#OBJIO_invalid_tag if the @p manager_tag is invalid.
    </ul>
*/
extern OBJIO_API int OBJIO_set_receiving_user2(
    tag_t            manager_tag,                       /**< (I) Tag of the OBJIO area */
    const char       *receiving_user                    /**< (I) Name of receiving user */
    );



/**
    Sets the owning group of the imported objects.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#OBJIO_invalid_tag if the @p manager_tag is invalid.
    </ul>
*/
extern OBJIO_API int OBJIO_set_receiving_group2(
    tag_t            manager_tag,                       /**< (I) Tag of the OBJIO area */
    const char       *receiving_user                    /**< (I) Name of receiving user */
    );


/**
    Sets the sending user of the imported objects.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#OBJIO_invalid_tag if the @p manager_tag is invalid.
    </ul>
*/
extern OBJIO_API int OBJIO_set_sending_user2(
        tag_t           manager_tag,                     /**< (I) Tag of the OBJIO area */
        const char      *sending_user                    /**< (I) Name of sending user */
    );


/**
    Sets the sending group of the imported objects.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#OBJIO_invalid_tag if the @p manager_tag is invalid.
    </ul>
*/
extern OBJIO_API int OBJIO_set_sending_group2(
        tag_t           manager_tag,                     /**< (I) Tag of the OBJIO area */
        const char      *sending_group                   /**< (I) Name of sending group */
    );


/**
    Retrieves the receiving user of the imported objects.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#OBJIO_invalid_tag if the @p manager_tag is invalid.
    </ul>
*/
extern OBJIO_API int OBJIO_ask_receiving_user2(
        tag_t           manager_tag,                     /**< (I) Tag of the OBJIO area */
        char            **receiving_user                 /**< (OF) Name of receiving user */
    );


/**
    Retrieves the receiving group of the imported objects.

    @returns
    <ul>
    <li>#ITK_ok on success.
    </ul>
*/
extern OBJIO_API int OBJIO_ask_receiving_group2(
        tag_t           manager_tag,                     /**< (I) Tag of the OBJIO area */
        char            **receiving_group                /**< (OF) Name of receiving group */
    );


/**
    Retrieves the sending user of the imported objects.

    @returns
    <ul>
    <li>#ITK_ok on success.
    </ul>
*/
extern OBJIO_API int OBJIO_ask_sending_user2(
        tag_t           manager_tag,                     /**< (I) Tag of the OBJIO area */
        char            **sending_user                   /**< (OF) Name of sending user */
    );


/**
    Retrieves the sending group of the imported objects.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#OBJIO_invalid_tag if the @p manager_tag is invalid.
    </ul>
*/
extern OBJIO_API int OBJIO_ask_sending_group2(
        tag_t           manager_tag,                     /**< (I) Tag of the OBJIO area */
        char            **sending_group                  /**< (OF) Name of sending group */
    );


/**
    Sets an attribute for the area specified by manager_tag.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#OBJIO_invalid_attribute_flag if an invalid attribute flag is specified.
    </ul>
*/
extern OBJIO_API int OBJIO_set_attribute(
    tag_t            manager_tag,       /**< (I) Tag of the OBJIO area */
    int              attribute_flag,    /**< (I) Attribute flag to set or unset. Valid values are in objio.h.
                                                 The following attribute flags show examples of the valid values: <br>
                                                 #OBJIO_dataset_all_versions If value is non-zero,
                                                 include all revisions of any specified datasets. <br>
                                                 #OBJIO_include_contents If value is non-zero,
                                                 include the contents of any specified folders. */
    int              value              /**< (I) Value to which to set the attribute */
    );

/**
    Sets an attribute for the area specified by manager_tag.  The attribute may not be supported by all sites.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BIER_invalid_site if @p remote_site is not a valid site.
    <li>#OBJIO_invalid_attribute_flag if an invalid attribute flag is specified.
    <li>#IDSM_ie_option_not_supported if an attribute flag is not supported at the the remote site.
    <li>#OBJIO_internal_error if any internal error occurs.
    </ul>
*/
extern OBJIO_API int OBJIO_set_site_based_attribute(
    tag_t            manager_tag,       /**< (I) Tag of the OBJIO area */
    tag_t            remote_site,       /**< (I) Tag of remote site */
    int              attribute_flag,    /**< (I) Attribute flag to set or unset. */
    int              value              /**< (I) Value to which to set the attribute */
    );

/**
    Sets the export reason for the particular export. This is optional.

    @returns
    <ul>
    <li>#ITK_ok on success.
    </ul>
*/
extern OBJIO_API int OBJIO_set_export_reason(
    tag_t            manager_tag,   /**< (I) Tag of the OBJIO area to export data to */
    const char*      export_reason  /**< (I) Reason for the export. This can be up to 240 characters. */
    );



/**
    Sets the release status type that will be used to select item revisions to be exported.

    For the release status type to take effect,
    the attribute #OBJIO_specific_status_only must be set through #OBJIO_set_attribute.

    <b>Restrictions:</b> The given release status type must be defined in the database where the export is being performed.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CFM_invalid_status_type if an invalid release status is specified.
    </ul>
*/
extern OBJIO_API int OBJIO_set_release_status2(
    tag_t            manager_tag,                       /**< (I) Export manager tag created via #OBJIO_create */
    const char       *status_type                       /**< (I) Valid release status type.
                                                                Only revisions with this release status will be exported. */
    );


/**
    Sets the revision rule type that will be used to select item revisions to be exported.

    For the revision rule to take effect,
    the attribute #OBJIO_specific_rev_rule_only must be set through #OBJIO_set_attribute.

    <b>Restrictions:</b> The given revision rule type must be defined in the database where the export is being performed.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CFM_cant_find_rev_rule if @p rev_rule_name is not a valid revision rule.
    </ul>
*/
extern OBJIO_API int OBJIO_set_revision_rule2(
        tag_t               manager_tag,                      /**< (I) Tag of the OBJIO area */
        const char          *rev_rule_name                    /**< (I) Name of status type */
    );


/**
    Stores the specified objects, ready for writing to the area specified by manager_tag.

    You may call this function several times before calling #OBJIO_write.

    <b>Restrictions:</b> You must have read access to all the objects.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BIER_unknown_object if a target object class is not supported by OBJIO.
    <li>#BIER_conflicting_ie_options if an invalid combination of export options were previously set with #OBJIO_set_attribute.
    <li>#BIER_invalid_option_when_xferring if an invalid combination of transfer ownership options were previously set with #OBJIO_set_attribute.
    <li>#OBJIO_internal_error if any internal error occurs.
    </ul>
*/
extern OBJIO_API int OBJIO_store_objects(
    tag_t            manager_tag,   /**< (I) Tag of the OBJIO area */
    int              n_objects,     /**< (I) Number of objects to store */
    tag_t*           objects        /**< (I) n_objects Tags of the objects to store */
    );

/**
    Writes the objects, specified in calls to #OBJIO_store_objects, to the area specified by manager_tag.

    <b>Restrictions:</b> You should not call this function more than once with the same manager_tag, as it is not cumulative; that is, each call will overwrite the result of the previous call.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BIER_nothing_to_export if no objects have been specified for export.
    <li>#OBJIO_invalid_tag if the @p manager_tag is invalid.
    <li>#OBJIO_internal_error if any internal error occurs.
    </ul>
*/
extern OBJIO_API int OBJIO_write(
    tag_t            manager_tag    /**< (I) Tag of the OBJIO area to which to write objects */
    );

/**
    Reads the objects that were written to the area specified by manager_tag,
    preparatory to listing those objects.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#OBJIO_invalid_dir_contents if no valid metadata file found.
    <li>#OBJIO_invalid_tag if the @p manager_tag is invalid.
    <li>#OBJIO_internal_error if any internal error occurs.
    </ul>
*/
extern OBJIO_API int OBJIO_read(
    tag_t            manager_tag    /**< (I) Tag of the OBJIO area */
    );

/**
    Lists the contents of the area specified by manager_tag.

    You must call #OBJIO_read before using this function, otherwise no objects will be listed.

    The client is responsible for freeing objects with #MEM_free.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#OBJIO_invalid_tag if the @p manager_tag is invalid.
    </ul>
*/
extern OBJIO_API int OBJIO_ask_contents(
    tag_t            manager_tag,   /**< (I) Tag of the OBJIO area */
    int*             n_objects,     /**< (O) Number of objects in the area */
    tag_t**          objects        /**< (OF) n_objects Tags of the objects in the area */
    );

/**
    Restores the specified objects from the area specified by manager_tag.

    You must call #OBJIO_read before using this function, otherwise no objects will be restored.

    You may call this function several times with the same manager_tag.

    <ul>
    <li>#ITK_ok on success.
    <li>#BIER_require_import_site_priv if there is insufficient site privilege to import into this site.
    <li>#OBJIO_invalid_tag if the @p manager_tag is invalid.
    <li>#OBJIO_internal_error if any internal error occurs.
    </ul>
*/
extern OBJIO_API int OBJIO_restore_objects(
    tag_t            manager_tag,   /**< (I) Tag of the OBJIO area */
    int              n_objects,     /**< (I) Number of objects to restore */
    tag_t*           objects        /**< (I) n_objects Tags of the objects to restore */
    );

/**
    Lists the objects which failed to be stored/restored by a call to
    #OBJIO_store_objects or #OBJIO_restore_objects.
    For example, an object will not be restored if it does not exist in the area.

    The client is responsible for freeing failing_objects and failures with #MEM_free.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#IDSM_get_remote_stack_failed if the remote error stack was not available.
    <li>#OBJIO_internal_error if any internal error occurs.
    <li>#OBJIO_invalid_tag if the @p manager_tag is invalid.
    </ul>
*/
extern OBJIO_API int OBJIO_ask_failures(
    tag_t            manager_tag,       /**< (I) Tag of the OBJIO area */
    int*             n_failures,        /**< (O) Number of objects that failed to be stored/restored */
    tag_t**          failing_objects,   /**< (OF) n_failures Tags of the objects which failed to be stored/restored */
    int**            failures           /**< (OF) n_failures Reasons why the objects failed */
    );

/**
    Specifies a number of objects to be excluded explicitly from operations on the area specified by manager_tag.

    For example, when exporting a folder with many contents,
    you can conveniently export most of the contents by first setting the #OBJIO_include_contents attribute to 1,
    and then using this function to specify the small number of objects that you do not wish to export.

    This function must be called before #OBJIO_store_objects or #OBJIO_restore_objects.

    You may call this function several times before calling #OBJIO_store_objects or #OBJIO_restore_objects.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#OBJIO_invalid_tag if the @p manager_tag is invalid.
    </ul>
*/
extern OBJIO_API int OBJIO_exclude_objects(
    tag_t            manager_tag,   /**< (I) Tag of the OBJIO area */
    int              n_objects,     /**< (I) Number of objects to exclude */
    tag_t*           objects        /**< (I) n_objects Tags of the objects to exclude */
    );

/**
    Includes the specified objects to the bier class tag provided with @p manager_tag, in order to later export the objects to other sites.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#OBJIO_invalid_tag if @p manager_tag is invalid.
    <li>#OBJIO_internal_error if any internal error occurs
    </ul>
*/
extern OBJIO_API int OBJIO_include_objects(
    tag_t               manager_tag,    /**< (I) Tag of the OBJIO area */
    int                 n_objects,      /**< (I) Number of objects to include */
    tag_t *             objects         /**< (I) n_objects Tags of the objects to include */
    );

/**
    Deletes the area specified by manager_tag.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#OBJIO_invalid_tag if the @p manager_tag is invalid.
    </ul>
*/
extern OBJIO_API int OBJIO_delete(
    tag_t            manager_tag    /**< (I) Tag of the OBJIO area to be deleted */
    );

/**
    Sets the the the being imported flag on the input tag.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#OBJIO_invalid_tag if the @p manager_tag is invalid.
    </ul>
*/
extern OBJIO_API int OBJIO_record_being_imported(
    tag_t            manager_tag    /**< (I) Tag that is to be flagged as being imported */
    );

/**
    Sets the relation types excluded from export.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#OBJIO_invalid_tag if the @p manager_tag is invalid.
    </ul>
*/
extern OBJIO_API int OBJIO_exclude_relation_types(
    tag_t            manager_tag,       /**< (I) Tag of the OBJIO area */
    int              count,             /**< (I) Number of relation types  to exclude */
    tag_t*           relation_types     /**< (I) count Tags of the relation types to exclude */
    );

/**
    Exports object(s) from the given remote site into a metafile within a local directory.

    Before calling this function, the following functions must be called first with the appropriate parameters:

    <table>
    <tr><td>#OBJIO_create       </td><td>This should be called to create the manager_tag, specifying a type of
                                         #OBJIO_remote_transfer_from_type as well as the local directory
                                         where the metafile will go into.                                     </td></tr>
    <tr><td>#OBJIO_store_objects</td><td>This should be called to specify which remote object(s) to export.   </td></tr>
    <tr><td>#OBJIO_set_attribute</td><td>May also be called before calling #OBJIO_retrieve.
                                         If #OBJIO_retrieve returns a successful status, it is recommended
                                         that you call #OBJIO_ask_failures to determine if any error occurred.</td></tr>
    </table>

    <b>Restrictions:</b> The local site must be a permitted client of the remote site.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BIER_user_denied_remote_import_privilege_for_site if the user lacks IMPORT privilege.
    <li>#BIER_user_denied_transfer_ownership_privilege_for_site if the user lacks TRANSFER_IN privilege.
    <li>#BIER_no_target_site if no target sites were specified.
    <li>#BIER_invalid_site if the target site was invalid or the target site was the local site.
    <li>#IDSM_client_access_denied if the remote IDSM is not configured to allow the local site access.
    </ul>
*/
extern OBJIO_API int OBJIO_retrieve(
    tag_t            manager_tag,   /**< (I) Export manager tag created via an earlier call to #OBJIO_create */
    tag_t            source_site    /**< (I) Tag of remote site to export from */
    );

/**
    Imports object(s) from a metafile within a local directory into a remote site.

    Before calling this function,
    #OBJIO_create must be called with a type of #OBJIO_remote_transfer_to_type
    and with the local directory containing the metafile.

    If #OBJIO_send returns a successful status,
    it is recommended that you call #OBJIO_ask_failures to determine if any error occurred.

    <b>Restrictions:</b> The local site must be a permitted client of the remote site.

    Before calling this function,
    the metafile must already exist in the directory given in the #OBJIO_create call.
    If the object to be sent has not been exported yet,
    then you need to create a separate manager area,
    store objects (via #OBJIO_store_objects) and write the objects (via #OBJIO_write).
    After the object is exported, create a second manager area for sending and then call #OBJIO_send.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BIER_user_denied_remote_import_privilege_for_site if the user lacks IMPORT privilege.
    <li>#BIER_user_denied_transfer_ownership_privilege_for_site if the user lacks TRANSFER_IN privilege.
    <li>#BIER_no_target_site if no target sites were specified.
    <li>#BIER_invalid_site if the target site was invalid or the target site was the local site.
    <li>#IDSM_client_access_denied if the remote IDSM is not configured to allow the local site access.
    </ul>
*/
extern OBJIO_API int OBJIO_send(
    tag_t            manager_tag,       /**< (I) Export manager tag created via an earlier call to #OBJIO_create */
    tag_t            destination_site   /**< (I) Tag of remote site to import into */
    );

/**
    Deletes the provided temporary staging directory.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#SS_FILEBUSY if the directory is in use.
    <li>#OBJIO_internal_error on error.
    </ul>
*/
extern OBJIO_API int OBJIO_delete_staging_dir(
    const char*      directory  /**< (I) Staging directory to be deleted */
    );

/**Creates temporary staging Directory and returns path in output parameter directory. This directory is used to store files temporary during transfer.*/
extern OBJIO_API int OBJIO__make_temp_staging_dir(
    char**           directory  /**< (OF) Name of staging directory*/
    );

/**
    Removes a relation type from the excluded from export list.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#OBJIO_invalid_tag if the @p manager_tag is invalid.
    </ul>
*/
extern OBJIO_API int OBJIO_remove_excluded_reltype(
    tag_t            manager_tag,   /**< (I) Tag of the OBJIO area */
    tag_t            relation_type  /**< (I) Tag of the relation type */
    );

/**
    Removes a relation type from the excluded from export list.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#OBJIO_invalid_tag if the @p manager_tag is invalid.
    <li>#BIER_conflicting_ie_options if the reporting options conflict.
    </ul>
*/
extern OBJIO_API int OBJIO_ask_report_info(
    tag_t            manager_tag,   /**< (I) Tag of the OBJIO area */
    int*             n_info,        /**< (O) Number of information count */
    OBJIO_report_t** info_list      /**< (O) info_list contains report information */
    );

/**
    Removes a relation type from the excluded from export list.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#OBJIO_invalid_tag if the @p manager_tag is invalid.
    <li>#BIER_conflicting_ie_options if the reporting options conflict.
    </ul>
*/
extern OBJIO_API int OBJIO_ask_error_report_info(
        tag_t             manager_tag,           /**< (I) Tag of the OBJIO area */
        int *             n_info,                /**< (O) Number of error information count */
        OBJIO_report_t**  info_list              /**< (O) info_list contains error report information */
    );


/**
    Aborts a site synchronous transfer operation before #OBJIO_write is called.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BIER_unknown_sst_state if the operation state in invalid.
    <li>#OBJIO_internal_error on error.
    </ul>
*/
extern OBJIO_API int OBJIO_abort_sst_export(
    tag_t            export_bier_tag  /**< (I) Tag of the export object */
    );

/**
    Aborts a site synchronous transfer operation after #OBJIO_write is called.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BIER_unknown_sst_state if the operation state in invalid.
    <li>#OBJIO_internal_error on error.
    </ul>
*/
extern OBJIO_API int OBJIO_abort_sst_export_post_write(
    tag_t            main_object_tag  /**< (I) Main object tag*/
    );

/**
    Abort a site synchronous transfer operation.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BIER_unknown_sst_state if the operation state in invalid.
    <li>#OBJIO_internal_error on error.
    </ul>
*/
extern OBJIO_API int OBJIO_abort_sst_import(
    tag_t            obj_tag          /**< (I) Tag of the OBJIO area */
    );

/**
    Get the tag for the import/export metadata file.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#OBJIO_invalid_tag if the @p manager_tag is invalid
    </ul>
*/
extern OBJIO_API int OBJIO_ask_metafile(
    tag_t            manager_tag,   /**< (I) Tag of the OBJIO area */
    tag_t*           metafile_tag   /**< (O) Tag of the metafile */
    );

/**
    @name Multi-Site Collaboration Functions
    @{
*/

/**
    This function is called from the replica side to the owning site and is used to
    set synchronization options for the existing replica objects given in the obj_tags argument.
    The desired options are specified via the options_token argument.

    <b>Restrictions:</b> The given owning site must be running V7.0 or later and must enable Subscriptions.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#OBJIO_invalid_sync_option if an invalid option was specified.
    <li>#OBJIO_invalid_site if an invalid @p owning_site was specified.
    </ul>
*/
extern OBJIO_API int OBJIO_set_sync_options(
    tag_t            owning_site,       /**< (I) Integer site id of the site that owns the objects given in object_tags */
    int              options_token,     /**< (I) Integer value that indicates the sync options specified.
                                             Valid values are defined in objio.h. */
    int              n_obj_tags,        /**< (I) Number of replica objects to apply sync options to */
    const tag_t*     obj_tags,          /**< (I) Replica objects tags to apply options to.
                                             All tags must be of the WorkspaceObject class. */
    int**            failure_codes      /**< (OF) n_obj_tags Error code returned for each
                                             corresponding object in object_tags list */
    );

/**
    Retrieves information regarding distributed components from the import/export metafile.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#OBJIO_invalid_tag if the @p manager_tag is invalid
    </ul>
*/
extern OBJIO_API int OBJIO_ask_distributed_assy_info(
    tag_t            manager_tag,           /**< (I) Import manager tag */
    int*             n_dist_components,     /**< (O) Number of distributed components */
    tag_t**          dist_component_list,   /**< (OF) n_dist_components Tags of distributed components */
    int**            owning_site_list       /**< (OF) n_dist_components Site ID of corresponding owning site for each component tag */
    );

/**
    Retrieves information about components owned by the exporting site so that they
    can be remote-imported individually from the exporting site
    as part of a one-at-a-time Remote Import operation of assembly components.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#OBJIO_invalid_tag if the @p manager_tag is invalid
    </ul>
*/
extern OBJIO_API int OBJIO_ask_assembly_components_owned_by_exporting_site(
    tag_t            manager_tag,           /**< (I) Import manager tag */
    int*             n_components,          /**< (O) Number of components */
    tag_t**          component_list,        /**< (OF) n_components Tags of the Assembly components */
    int**            owning_site_list       /**< (OF) n_components Site ID of the exporting site */
    );


/**
    Sets the new, modified and deleted occurrences for a incremental BVR export.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#OBJIO_invalid_tag if the @p manager_tag is invalid
    </ul>
*/
extern OBJIO_API int OBJIO_set_incremental_bvr_changes (
        tag_t         manager_tag,              /**< (I) Import manager tag */
        tag_t         bvr,                      /**< (I) BOMViewRevision tag */
        int           n_modified_or_added_occs, /**< (I) Number of modifed or added occurrences */
        const tag_t*  modified_or_added_occs,   /**< (I) List of modified and added occurrences */
        int           n_deleted_occs,           /**< (I) Number of deleted occurrences */
        const tag_t*  deleted_occs              /**< (I) List of deleted occurrences */
    );

/** @} */

/**
    Sets the full path to the script executed after export is complete.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#OBJIO_invalid_tag if the @p manager_tag is invalid
    <li>#SS_NOOPEN if the script file @p script cannot be opened.
    </ul>
*/
extern OBJIO_API int OBJIO_set_script2(
    tag_t            manager_tag,               /**< (I) Tag of the OBJIO area */
    const char       *script                    /**< (I) Full path to the post-export script */
    );

/**
    Retrieves the full path to the report file generated by an import/export operation.

    @returns
    <ul>
    <li>#ITK_ok on success
    </ul>
*/
extern OBJIO_API int OBJIO_get_report_file(
    char**           report_file_name   /**< (OF) Full path to the report file */
    );

/**
    Retrieves the full path to the report file generated by a background import/export operation.

    @returns
    <ul>
    <li>#ITK_ok on success
    </ul>
*/
extern OBJIO_API int OBJIO_get_bg_report_file(
    char*            reportStr,         /**< (I) Input string in the form of \<Current Process ID\>_sync */
    char**           report_file_name   /**< (OF) Full path to the report file */
    );

/**
    Initiate controlled replication for the specified workflow hander.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BIER_CntrlRep_assembly_invalid_for_replication if the assembly is not valid for replication and release per the workflow handler definition.
    <li>#BIER_CntrlRep_no_revision_rule_provided There is no revision rule provided in the handler.
    <li>#BIER_CntrlRep_no_replication_sites if there are no valid controlled replication sites on the associated Project.
    </ul>
*/
extern OBJIO_API int OBJIO_release_and_replicate(
    EPM_action_message_t msg            /**< (I) Message containing the EPM task */
    );

/**
    Return the GSIdentity object associated with a replicated organization object.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#POM_invalid_tag if an invalid @p object_tag was supplied.
    </ul>
*/
extern OBJIO_API int OBJIO_find_import_record_by_tag(
    tag_t       object_tag,                 /* (I) Tag of organization object */
    tag_t*      gsidentity_tag              /* (O) Tag of GSIdentity object */
    );

/**
    Retrieves the sites an organization object has been exported to.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#POM_invalid_tag if an invalid @p object_tag was supplied.
    </ul>
*/
extern OBJIO_API int OBJIO_find_export_sites_by_tag(
    tag_t           object_tag,                  /* (I) Tag of tc object */
    int*            nSites,                      /* (O) number of expoted sites. */
    tag_t**         site_tags,                    /* (O) Tag of IXR object */
    char**          export_sites_as_string,       /* (O) append site name as string. Useful for run time property */
    logical*        isSiteStrNull                 /* (O) check if the export_site_string is null */
    );

/**
    Deletes the main replicated object and all its dependents objects.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag  if an invalid @p replica_object is supplied.
    <li>#CXPOM_object_deleted if a deleted @p replica_object is supplied.
    <li>#OBJIO_invalid_object_type if a local @p replica_object is supplied.
    <li>#OBJIO_ref_iman_master_form if a Form object is supplied which is referenced by IMAN_master_form relation.
    <li>#OBJIO_is_checked_out  if dependent objects are checked-out at remote site.
    <li>#OBJIO_few_dependent_object_count if the supplied dependent object list count @p n_objects is fewer than the internal evaluation count.
    <li>#OBJIO_insufficient_privileges  if the current user does not have sufficient privileges to perform this operation.
    <li>#OBJIO_mixed_ownership if dependent objects have mixed ownership of local and replica objects.
    <li>#OBJIO_is_part_of_workflow if dependent objects are part of a workflow.
    <li>#BIER_unable_to_exclude if an internally evaluated object is not part of the dependent objects list.
    </ul>
*/
extern OBJIO_API int OBJIO_delete_replica_objects(
      tag_t             replica_object,               /**< (I)  A tag of main replica workspace object */
      int               n_objects,                    /**< (I)  Number of dependent objects. This value can be set to zero (0).
                                                                <br/>If non-zero the input dependent_tags should match evaluated
                                                                dependent objects using optionset. */
      const tag_t*      dependents,                   /**< (I)  n_objects The dependent objects
                                                                <br/>The ITK method ensures that internally evaluated object list is a subset of
                                                                supplied dependent object list. If it is determined that an internally evaluated
                                                                object is not part of dependent objects list, an error #BIER_unable_to_exclude is returned. */
      const char*       optionset,                    /**< (I)  Name of the TransferOptionset used for traversal and evaluation of dependent objects.
                                                                <br/>This value can be set to NULL if internal TransferOptionset is to be used
                                                                for traversal and evaluation of dependent objects. */
      logical           delete_unref_pomstubs,        /**< (I)  Set it to "true" if the unreferenced POM stubs associated with dependent objects
                                                                are to be deleted. */
      logical           delete_export_records         /**< (I)  Set it to "true if the owning site ImanExportRecords and ItemExportRecords
                                                                associated with dependent objects is to be deleted. */
      );

/** @} */

#ifdef __cplusplus
}
#endif

#include <objio/libobjio_undef.h>

#endif
