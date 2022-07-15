/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Include file to define entry points for user defined entry points.
*/

/*  */

#ifndef USER_EXITS_H
#define USER_EXITS_H

#include <tc/tc_startup.h>
#include <common/emh_const.h>
#include <unidefs.h>
#include <common/tc_deprecation_macros.h>

#include <tccore/method.h>
#include <qry/qry.h>
#include <sub_mgr/tcactionhandler.h>
#include <sub_mgr/subscription.h>
#include <tccore/workspaceobject.h>
#include <sa/tcfile.h>
#include <ai/aiws_extensions.h>

/**
    @defgroup USER_EXITS User Exits
    @ingroup TC

    Teamcenter provides user exits to allow you to customize the
    Teamcenter applications to best fit your business needs.
    For example, user exits provide a means to customize Teamcenter for
    the way you generate your Item identifiers.

    You can replace the Teamcenter provided user exits by
    using the C routines in this section.

    @note You are required to have version 7.0 or above of Exceed and MS Visual Studio 98 or above,
    for User Exits to function.

    <b>User Exits on UNIX</b>

    In \$TC_ROOT/sample, use the link_user_exits script to build a new shareable library.
    The source files used to build the user_exits shared library must be compiled with -pic or -PIC.

    The link_user_exits script requires that all of the user exit object files reside in the current directory.
    They can be extracted from the user_exits library with the command:

    ar x \$TC_LIBRARY/libuser_exits.a

    You can then replace any of the User exit modules by making the appropriate changes in template user exit functions.
    See the sample directory for the template files.
    These files contain the default behavior that comes with Teamcenter.

    Make a backup copy of the original shareable library (libuser_exits.so.1.1 for SUN and libuser_exits.sl for the HP).
    Once you've created a back up copy of the original shareable library,
    copy the new shareable library back to the \$TC_LIBRARY.

    <b>User Exits on Windows NT</b>

    This example uses User Defined Attributes (UDA) user exits as an example.
    <OL>
    <LI>Create a sub-directory for the user exit library in your HOME directory.

        mkdir \%HOME\%/userexit

    <LI>Set your TC_USER_LIB environment variable.

        set TC_USER_LIB=\%HOME\%/userexit

    <LI>Copy the original user exit library to your directory.

        copy \%TC_ROOT\%/dll/user_exits.a \%HOME\%/userexit/.

    <LI>Extract objects from the library in your userexit directory.
        (If your MSDEV_HOME is not set, set it before running the extract script).

        \%TC_ROOT\%/sample/extract_objects user_exits.a

        There is sample UDA code that uses #USER_exit_module and the registration of properties in
        \%TC_ROOT\%/sample/properties/smp_props.c.
        This sample code shows you how to customize Teamcenter properties.

    <LI>Copy this file to your userexit directory (or you can create your own).

        copy \%TC_ROOT\%/sample/properties/smp_props.c

    <LI>Compile this (or your) C program.

        \%TC_ROOT\%/sample/compile smp_props.c

    <LI>Once the smp_props.o (or your) object is created, remove the original user_init.o from your
        userexit directory since your new object also contains the user exit ITK calls.
        Then build the new library. As a result of the following call, libuser_exits.dll is created.

        \%TC_ROOT\%/sample/link_user_exits

    <LI>Start Teamcenter.

        You should see your customizations.
    </OL>

    @{
*/

#define USER_EXIT                 (EMH_UE_error_base + 1)

/**
    The following type is defined here for compatability with V2.x code;
    IVFType is an obsolete concept and its value will be ignored when passed to v3.x USER functions.
*/
enum IVFType {
    IVF_BAD_TYPE,
    IVF_PRODUCT,
    IVF_STRUCTURE_GROUP,
    IVF_COMPONENT
};

typedef enum IVFType IVFType_e, *IVFType_ep;

/**
   Enumerated types to define the class of id to be defined by the user exit functions
   USER_ask_for_new_item and USER_ask_for_new_version_id
*/
typedef enum IDClass_e_obsolete {
    ID_BAD_CLASS,
    ID_WORKING,
    ID_OFFICIAL
} IDClass_e;

/**
   Indicates whether the requested number is for a copy (saveAs),
   a create, or a freeze action in the workspace.
*/
typedef enum IDFunc_e_obsolete {
    ID_BAD_FUNC,
    ID_SAVEAS,
    ID_CREATE,
    ID_FREEZE
} IDFunc_e;

/**
    Returned by #USER_validate_item_rev_id() to describe the status of the item_rev ID passed to it.
*/
typedef enum IDValid_t {
    USER_valid_id,
    USER_invalid_id,
    USER_modified_id,
    USER_override_id,
    USER_duplicate_id
} IDValid_e;

#define USER_DATASET_always_copy    0
#define USER_DATASET_never_copy     1
#define USER_DATASET_user_chooses   2

typedef struct USER_DATASET_details_s
{
    char    new_name[WSO_name_size_c+1];  /**< New dataset name */
    int     copy_state;                   /**< Output copy state: <br>
                                               #USER_DATASET_always_copy <br>
                                               #USER_DATASET_never_copy <br>
                                               #USER_DATASET_user_chooses

                                               Usually generated from SP4 */
    logical modifiable;                   /**< Whether or not the user should be allowed to change the name */
    logical validation_required;          /**< Whether or not the name of this dataset needs to pass the
                                               validation check provided by #USER_validate_dataset_name
                                               (useful when the user is allowed to change the name). */
    logical original_owner;               /**< Whether the new dataset should be owned by the owner of the original dataset,
                                               or the user doing the copying. */
} USER_DATASET_details_t;

typedef struct USER_DATASET_details_s *USER_DATASET_details_p_t;

#include <user_exits/libuser_exits_exports.h>

#ifdef __cplusplus
    extern "C"{
#endif


/**
    @name User Exits for File Names
    @{
*/

/**
    Method to generate a file name for a dataset.

    The format of the name is: dname_refname_date.ext

    The generated file name should be freed by calling free() rather than MEM_free().

    @note See \$TC_ROOT/sample/user_filenam.c.
*/
extern USER_EXITS_API char* USER_new_file_name(
    const char*             dataset,    /**< (I) Dataset name */
    const char*             ref,        /**< (I) Reference type name */
    const char*             ext,        /**< (I) Extension of the file */
    const int               rev         /**< (I) Revision number of the dataset */
    );


/**
  Log Handler for audit manager
*/
extern USER_EXITS_API int PEC_Log_Handler (
     const TcSubscriptionActionMsg_t* subscription_action_msg,
     int                                nnum_handler_args,
     char**                             handler_args,
     va_list                            other_args
     );


/**
    Method to generate a file name for a dataset using a name that was
    generated using the Teamcenter scheme.
    The name is parsed and rebuilt using the values found while parsing.

    The format of the name is: dname_refname_date.ext

    The generated file name should be freed by calling free() rather than MEM_free().
*/
extern USER_EXITS_API char* USER_rev_file_name(
    const char*             old_file_name   /**< (I) Original File Name */
    );

/** @} */

/**
    @name User Exits for Archive and Restore
    @{
*/

/**
    Method to generate a default filename for the archive metafile. The format of the filename is:

    archive_\<date\>\<time\>

    Where \<date\> is an eight-character date stamp in year/month/date format and \<time\> is
    a six-character time stamp in hours/minutes/seconds format.
*/
extern USER_EXITS_API char* USER_default_archive_filename(void);

/**
    Method to generate a default tape label for tape archive media. The format of the tape label is:

    AR\<date\>\<time\>

    Where \<date\> is an eight-character date stamp in year/month/date format and \<time\> is
    a six-character time stamp in hours/minutes/seconds format.

*/
extern USER_EXITS_API char* USER_default_archive_tape_label(void);


/**
   Creates an Item id generator counter.
   <br/>This is supplied as a mechanism for creating new counters in the IMAN database for the
   Item id generator.
   <br/>See #USER_new_item_id for details to use the multiple counters once they have been
   created.

   @returns
   <ul>
   <li>#POM_ok on success
   </ul>
*/
extern USER_EXITS_API int USER_create_id_counter(
    char*                 counter   /**< (I) Name of the counter to create. */
    );

/**
   Automatically upgrade the database to support the Item id generator. This is to be called by the standard IMAN
   schema program.
   <br/>Counter(s) can be created which can be used along with, or in place of the standard counter.
    See #USER_new_item_id and #USER_create_id_counter for additional details on counter creation.    
*/
extern USER_EXITS_API void  USER_define_tc_next_id (void);

/**
   Creates an instance of ImanNextId, which has its name set to #USER_new_item_id. This instance is used
   by the Item id generator user exit function to keep track of the current id number.
   <br/>This is called by the standard IMAN schema program to automatically upgrade the database to support   the Item id generator.
   <br/>Counter(s) can be created which can be used along with, or in place of the standard counter.
    See #USER_new_item_id and #USER_create_id_counter for additional details on counter creation.   
*/
extern USER_EXITS_API void USER_create_instance_item_next_id (void);


/** @} */

/**
    @name User Exits for Items and Item Revisions
    @{
*/


/**
    Generates an Item ID for a user.
    @note See \$TC_ROOT/sample/examples/user_part_no.c.
*/
extern USER_EXITS_API int USER_new_item_id(
    tag_t                 old_item,         /**< (I) Tag that provides a seed value for Save As.
                                                     May be a #NULLTAG if a new number is requested. */
    tag_t                 item_type,        /**< (I) Tag that provides the type of the Item for which the ID is to be generated */
    logical*              mod,              /**< (O) Specifies if the output ID can be modified.
                                                     <br/>If set to @c false, any attempt to use a modified output ID might lead to issues. */
    char**                item_id           /**< (OF) Generated Item ID. */
    );


/**
    Generate Item IDs in bulk for the specified Item type
    @note See \$TC_ROOT/sample/examples/user_part_no.c.
*/
extern USER_EXITS_API int USER_new_item_ids(
    tag_t                 item_type,        /**< (I) Tag that provides the type of the Item for which the IDs is to be generated */
    int                   quantity,         /**< (I) Number of Item IDs to be generated for the specified Item type.*/
    logical*              mod,              /**< (O) Specifies if any output ID can be modified.
                                                     <br/>If set to @c false, any attempt to use a modified output ID might lead to issues. */
    char***               item_ids          /**< (OF) quantity Generated Item IDs.
                                                      <br/>This array is not packed, which means that both, the elements and the container need to be freed through a call to #MEM_free.  */
    );


/**
    Generates an Item Revision ID for a user.
    @note See \$TC_ROOT/sample/examples/user_part_no.c.
*/
extern USER_EXITS_API int USER_new_revision_id(
    tag_t                 item_tag,         /**< (I) Tag that provides the Item for which a new revision ID is to generated. */
    tag_t                 item_type,        /**< (I) Tag that provides the type of the Item for which the ID is to be generated. */
    logical*              mod,              /**< (O) Specifies if the output ID can be modified.
                                                     <br/>If set to @c false, any attempt to use a modified output ID might lead to issues. */
    char**                revision_id       /**< (OF) Generated Item Revision ID. */
    );


/**
    Handles revision ids for preliminary data
*/
extern USER_EXITS_API int USER_new_revision_id_from_alt_rule(
    char*                 rule_suffix,  /**< (I) */
    tag_t                 item_tag,     /**< (I) */
    tag_t                 item_type,    /**< (I) */
    logical*              mod,          /**< (O) */
    char**                id            /**< (OF) */
    );

/**
    @deprecated #USER_validate_item_rev_id deprecated in Teamcenter 13.1. Use #USER_validate_item_rev_id_3 instead.
    
    This user exit is called when a user chooses OK or Apply in the Item Creation or Save As dialog boxes.
    It can verify that the IDs meet certain criteria and, if necessary, return modified IDs.
    If this function returns with status set to invalid,
    then the user can either accept the modified IDs (if supplied), or cancel the create.
    If this function returns with status set to modified,
    then the user can choose whether to use the modified IDs,
    force the system to use the originally entered IDs, or cancel the create.
    If this function returns with status set to override,
    then the modified IDs will be used without informing the user
    (this is helpful for performing case conversions).
*/
TC_DEPRECATED("13.1","USER_validate_item_rev_id","USER_validate_item_rev_id_3")
extern USER_EXITS_API int USER_validate_item_rev_id(
    const char*           item_id,              /**< (I) Item ID entered in the dialog box by the user. */
    const char*           rev_id,               /**< (I) Item Revision ID entered in the dialog box by the user. */
    const char*           item_type,            /**< (I) Item type entered into the dialog box by the user.
                                                        This may be NULL. */
    char**                modified_item_id,     /**< (OF) New modified Item ID.
                                                        Set this to NULL to indicate that no modification has been made. */
    char**                modified_rev_id,      /**< (OF) New, modified Item Revision ID.
                                                        Set this to NULL to indicate that no modification has been made. */
    IDValid_e*            status                /**< (O) Indicates the result of the checks. May be one of the following: <br>
                                                        #USER_valid_id - IDs are OK. <br>
                                                        #USER_invalid_id - IDs are not acceptable.<br>
                                                        #USER_modified_id - IDs are not ideal,
                                                                            but can be used if the user really wants them. <br>
                                                        #USER_override_id - IDs are not acceptable.
                                                        Silently use the modified ones instead. */
    );
/**
@deprecated #USER_validate_item_rev_id_2 deprecated in Teamcenter 13.1. Use #USER_validate_item_rev_id_3 instead.

*   Validates the item and item revision identifiers selected for a new item
*   revision. This function may reject the supplied IDs, accept them or modify
*   them. This action is reflected in the value of status.
*
*   Compared to the USER_validate_item_rev_id function, this "_2" returns a more
*   granular valid status - separate status for Item id and Revision Id.
*/
TC_DEPRECATED("13.1","USER_validate_item_rev_id_2","USER_validate_item_rev_id_3")
extern USER_EXITS_API int USER_validate_item_rev_id_2(
    const char*           item_id,              /**< (I) Item ID entered in the dialog box by the user. */
    const char*           rev_id,               /**< (I) Item Revision ID entered in the dialog box by the user. */
    const char*           item_type,            /**< (I) Item type entered into the dialog box by the user.
                                                        This may be NULL. */
    char**                modified_item_id,     /**< (OF) New modified Item ID.
                                                        Set this to NULL to indicate that no modification has been made. */
    char**                modified_rev_id,      /**< (OF) New, modified Item Revision ID.
                                                        Set this to NULL to indicate that no modification has been made. */
    IDValid_e*            status_item_id,       /**< (O) Indicates the result of the checks. May be one of the following: <br>
                                                        #USER_valid_id - IDs are OK. <br>
                                                        #USER_invalid_id - IDs are not acceptable.<br>
                                                        #USER_modified_id - IDs are not ideal,
                                                                            but can be used if the user really wants them. <br>
                                                        #USER_override_id - IDs are not acceptable.
                                                        Silently use the modified ones instead. */
    IDValid_e*            status_rev_id         /**< (O) Indicates the result of the checks. May be one of the following: <br>
                                                        #USER_valid_id - IDs are OK. <br>
                                                        #USER_invalid_id - IDs are not acceptable.<br>
                                                        #USER_modified_id - IDs are not ideal,
                                                                            but can be used if the user really wants them. <br>
                                                        #USER_override_id - IDs are not acceptable.
                                                        #USER_duplicate_id - ID is duplicate with existing
                                                        Silently use the modified ones instead. */
    );

/*
*
*   Validates the item and item revision identifiers selected for a new item
*   revision. This function may reject the supplied IDs, accept them or modify
*   them. This action is reflected in the value of status.
*
*   This function uses NR_validate_rev_id_field2 ITK function.
*   This function takes additional item_tag input for validating Rev ID.
*   Compared to the USER_validate_item_rev_id function, this returns a more
*   granular valid status - separate status for Item id and Revision Id.
*   This function will validate Item ID and Rev ID against Naming Rules only.
*   It will not perform validation for duplicate ID since with MFK enabled it
*   might be possible to have multiple Items with same ID.
*
*/
extern USER_EXITS_API int USER_validate_item_rev_id_3(
    const char*           item_id,              /**< (I) Item ID entered in the dialog box by the user. */
    const char*           rev_id,               /**< (I) Item Revision ID entered in the dialog box by the user. */
    const tag_t           item_tag,             /**< (I) Item tag for Item Revise. For new Item this should be NULLTAG */
    const char*           item_type,            /**< (I) Item type entered into the dialog box by the user.
                                                        This may be NULL. */
    char**                modified_item_id,     /**< (OF) New modified Item ID.
                                                        Set this to NULL to indicate that no modification has been made. */
    char**                modified_rev_id,      /**< (OF) New, modified Item Revision ID.
                                                        Set this to NULL to indicate that no modification has been made. */
    IDValid_e*            status_item_id,       /**< (O) Indicates the result of the checks. May be one of the following: <br>
                                                        #USER_valid_id - IDs are OK. <br>
                                                        #USER_invalid_id - IDs are not acceptable.<br>
                                                        #USER_modified_id - IDs are not ideal,
                                                                            but can be used if the user really wants them. <br>
                                                        #USER_override_id - IDs are not acceptable.
                                                        Silently use the modified ones instead. */
    IDValid_e*            status_rev_id         /**< (O) Indicates the result of the checks. May be one of the following: <br>
                                                        #USER_valid_id - IDs are OK. <br>
                                                        #USER_invalid_id - IDs are not acceptable.<br>
                                                        #USER_modified_id - IDs are not ideal,
                                                                            but can be used if the user really wants them. <br>
                                                        #USER_override_id - IDs are not acceptable.
                                                        #USER_duplicate_id - ID is duplicate with existing
                                                        Silently use the modified ones instead. */
    );


/** @} */

/**
    @name User Exits for Non Master Handling During Save As

    Teamcenter User Exits (default implementations).
    @{
*/

/**
    Generates a name for a new dataset.
    This user exit is called when the Dataset Creation dialog box appears.
*/
extern USER_EXITS_API int USER_new_dataset_name (
    tag_t                 owner,            /**< (I) Tag that provides the Item/Item Revision for which the new dataset is to created.
                                                    This parameter may be #NULLTAG.
                                                    In case of Direct Model dataset created from NX/Manager interface this will be
                                                    the tag of dataset for which the Direct Model is being created.

                                                    As an example, It would be the tag of the UGMASTER dataset if
                                                    the DirectModel is created for it */
    tag_t                 dataset_type,     /**< (I) Tag that provides the type of the dataset. This parameter may be #NULLTAG. */
    tag_t                 relation_type,    /**< (I) Tag that provides the type of the relationship between the dataset and
                                                    the Item/Item Revision. This parameter may be #NULLTAG. */
    const char*           basis_name,       /**< (I) Name that should provide the basis for the dataset name.
                                                    <br/>For users of UG/Manager, the contents of the "File Name" text entry box
                                                         on the "New Part" dialog is passed as @p basis_name. The value for @p basis_name is simply returned
                                                         in the dataset name for this default implementation.
                                                    <br/>For users of IMAN, @p basis_name is set to NULL.
                                                    <br/>If @p basis_name is NULL, the dataset name will be the name of Item Revision which tag is provided in the @p owner parameter.*/

    char**                dataset_name,     /**< (OF) Pointer should be set to point to the new name */
    logical*              modifiable        /**< (O) Should be set to true if the returned value must not be modified by the user */
    );


/** @} */


/**
    Generates an Allocation name for the user.

    @note See \$TC_ROOT/sample/examples/user_alloc_name.c.
*/
extern USER_EXITS_API int USER_new_allocation_name (
    tag_t               allocation_map_rev, /**< (I) Tag that provides the allocation map revision context for the allocation */
    tag_t               alloc_type,         /**< (I) Tag that provides the type of the allocation for which the name is to be generated */
    char **             new_allocation_name /**< (OF) Pointer to the new allocation name */
    );

/**
    Defines what it means an Allocation to be Correct

    @note See \$TC_ROOT/sample/examples/user_is_allocation_correct.c.
*/
extern USER_EXITS_API int USER_is_allocation_correct (
    tag_t               allocation_tag,        /**< (I) Tag that provides the allocation object                                                */
    tag_t               allocation_window_tag, /**< (I) Tag that provides the Allocation Window                                                         to which the allocation belongs to.
                                                        This can be NULLTAG */
    logical*            is_correct             /**< (O) Return a boolean value - True or False*/
    );

/**
    Defines what it means for an Allocation to be Complete

    @note See \$TC_ROOT/sample/examples/user_is_allocation_complete.c.
*/
extern USER_EXITS_API int USER_is_allocation_complete (
    tag_t               allocation_tag,        /**< (I) Tag that provides the allocation object                                                */
    tag_t               allocation_window_tag, /**< (I) Tag that provides the Allocation Window                                                         to which the allocation belongs to.
                                                        This can be NULLTAG */
    logical*            is_complete            /**< (O) Return a boolean value - True or False*/
    );

/**
    Defines what it means for an Allocation to be Configured

    @note See \$TC_ROOT/sample/examples/user_is_allocation_configured.c.
*/
extern USER_EXITS_API int USER_is_allocation_configured (
    tag_t               rev_rule,               /**< (I) Tag that provides the Revision Rule */
    logical*            is_configured           /**< (O) Return a boolean value -True or False*/
    );

/**
    Generates a name for a dataset when it is copied.
    This user exit is called when the Dataset Save As dialog box appears.

    This function is required to use whatever inputs it is given to generate a sensible name for the copied dataset.

    @note We cannot use this function for the new NX save-as non-master code,
    as it requires that the new revision exists already, which will not be the case

    <b>Original Default Implementation</b>

    If the old dataset tag is given, set the new name to be equal to that of the original dataset.
    If it has not been given, and the new revision has, then set the name to be the new revision id string.
    If neither the old dataset nor the new revision tag is given, then set the name to be a null pointer.
    In all cases, return modifiable = true.

    <b>New Default Implementation</b>

    Assuming all the tags are given,
    this function should match the original name onto the pattern SP1 and return the new dataset name with
    the replacements made for item and revision ids.
    If either the old revision tag, the old dataset tag, or the new revision tag are missing,
    then we cannot perform the match onto the pattern.
    In this case, we should maintain the original behaviour.
    Return modifiable = SP2 (allow_name_modification).
    The new implementation preserves the original behavior with the default settings of the
    Teamcenter site preferences SP1 and SP2.
*/
extern USER_EXITS_API int USER_copied_dataset_name (
    tag_t                 old_owner,        /**< (I) Tag of the old revision */
    tag_t                 old_dataset,      /**< (I) Tag of the old dataset */
    tag_t                 relation_type,    /**< (I) Tag of the relation type between parent and old dataset */
    tag_t                 new_owner,        /**< (I) Tag of the new parent object, if this is known. Set to #NULLTAG otherwise. */
    char**                dataset_name,     /**< (OF) Pointer to a string containing the generated dataset name */
    logical*              modifiable        /**< (O) A Boolean flag indicating whether the generated name may be overridden subsequently */
    );

/**
   This USER EXIT ITK provides a hook point for customers to plug the customization
   codes into the item creation. It is called at the end of successful item creation.
*/
extern USER_EXITS_API int USER_item_created(
    const char*           item_id,      /**< (I) Id assigned to the newly created item */
    const char*           revision_id   /**< (I) Revision id assigned to the newly created item revision */
    );


/**
    Allocate a sequence number for a prospective occurrence
*/
extern USER_EXITS_API char* USER_ask_for_new_sequence_no(
    tag_t                   parent_bom_revision /**< (I) */
    );

/**
    Returns a find number as a string in SM space,
    to be used for a new occurrence of item in parent_bom_rev.
    This function is called:
    <UL>
    <LI>When the Paste... and Add... dialog boxes are displayed to give a default find number
    <LI>For each item or item revision being pasted in the Paste command
    </UL>
    The find number returned depends on the PS_new_seqno_mode preference which can take one of three values:

    <table>
    <tr><td>new</td>     <td>Each item added to the BOM revision is allocated a new number.
                            This is the default action.</td></tr>
    <tr><td>existing</td><td>If the item to be added already exists in the BOM,
                            then the existing find number for that item is returned.</td></tr>
    <tr><td>none</td>    <td>No number (i.e., an empty string)
                            is returned allowing the user to add numbers in later.</td></tr>
    </table>

    This function replaces #USER_ask_for_new_sequence_no.
    For the case of new the old function is called to provide the find number.
    In the case of existing if the item does not already exist in the BOM revision then the old function is called again.
    It is also called if item is #NULLTAG.

    Any programs that call the old function will still work and the old user exit is still called,
    but programmers should update any code that uses or overrides #USER_ask_for_new_sequence_no
    to the new function so as to take account of the new preference.

    In the case of none, an empty string is always returned.

    The default functionality provided behaves as follows.
    The function returns the next multiple of ten above the largest current find number provided
    all the find numbers in the parent have numeric values.
    If no find numbers have yet been created, it returns 10.
    If there are non-numeric find numbers then these are ignored.
    Find numbers need not be unique.

    @note On error seqno will be NULL, and an ifail error may be returned.
*/
extern USER_EXITS_API int USER_ask_new_seqno (
    tag_t                 parent_bom_rev,   /**< (I) */
    tag_t                 item,             /**< (I) Tag of the item or item revision being pasted*/
    char**                seqn_number       /**< (OF) */
    );

/**
    Obtains a find number to be used for a new occurrence of Item as specified in the @p parent_bom_rev parameter.
    <br/>This function provides the default implementation for USER_ask_new_seqno
    This method provides a default behaviour in case of customer written user_exit/BMF overrides are not able to generate sequence number.

    This function will not replace the existing USER_ask_new_seqno

    The functionality behavior is as follows:
    <ul>
    <li>The function returns the next multiple of ten above the largest current find number,
    provided all the find numbers in the parent have numeric values.</li>
    <li>If no find numbers have yet been created, it returns 10.</li>
    <li>If there are non-numeric find numbers, these are ignored, and the previous rules apply</li>
    </ul>

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PS_invalid_bvr if the @p parent_bom_rev parameter is incorrect.
    <li>#PS_no_seq_no if the @p item parameter is incorrect.
    </ul>
*/
extern USER_EXITS_API int USER_ask_new_default_sequence_number (
    tag_t                 parent_bom_rev,   /**< (I) Tag of the parent BOM Revision */
    tag_t                 item,             /**< (I) Tag of the Item or ItemRevision*/
    char**                sequence_number   /**< (OF) The sequence number*/
    );


/**
    This new version is written specifically for CLONING
*/
extern USER_EXITS_API int USER_ask_seq_numbers(
    tag_t                 parent_bvr, /**< (I) */
    int                   count,      /**< (I) */
    tag_t*                child,      /**< (I) */
    char***               seq_numbers /**< (OF) count */
    );


/**
    Allows the custom-programmer to replace both the query mechanism and the display mechanism.
    <br>This means the query can return information which is not necessarialy contained in Tc objects.
    (see TC_ROOT/sample/examples/user_query.c)
    <br>It is requried to execute "TC_ROOT/bin/tc_set_query_where_run" with argument value "-run=user".
    <br>
    @code
    {
    tc_set_query_where_run -query=<query name> -run=user
    }
    @endcode

    @returns
    <ul>
        <li>#ITK_ok on success. This can also mean that no objects are found.
        <li>A POM-level error in case the query name is invalid, or no keys are provided, or some of the keys are invalid.
    </ul>

*/
extern USER_EXITS_API int USER_query_execute(
    const char*             name,      /**< (I) The name of the query to be executed */
    int                     num_args,  /**< (I) The number of arguments */
    char**                  keys,      /**< (I) The keys of the arguments */
    char**                  values,    /**< (I) The values of the arguments */
    int*                    n_columns, /**< (O) The number of the columns(stored in the col_names) */
    char***                 col_names, /**< (OF) The names of the columns for the result (stored in the rows) */
    QRY_user_query_row_t**  rows       /**< (OF) n_columns The resulting rows */
    );

extern USER_EXITS_API int USER_query_map_row(
    const char*                 query_name, /**< (I) */
    const QRY_user_query_row_t* row,        /**< (I) */
    tag_t*                      tag         /**< (O) */
    );

extern USER_EXITS_API int USER_query_free_rows(
    QRY_user_query_row_t*  rows,           /**< (I) */
    int                    n_columns       /**< (I) */
    );

/**
    Allows a custom-programmer to replace the query mechanism while keeping the display mechanism.
    <br>This means the query must return displayable TC objects, but can run arbitrary code and hence
    do queries too complicated to express in SQL.
    (see TC_ROOT/sample/examples/user_query.c)
    <br>It is required to execute "TC_ROOT/bin/tc_set_query_where_run" with argument value "-run=query"
    <br>@code
    {
    tc_set_query_where_run -query=<query name> -run=query
    }
    @endcode

    @returns
    <ul>
        <li>#ITK_ok on success. This can also mean that no objects are found.
        <li>A POM-level error in case the query name is invalid, or no keys are provided, or some of the keys are invalid.
    </ul>
*/
extern USER_EXITS_API int USER_execute_saved_query(
    const char*           name,        /**< (I) The name of the saved query */
    int                   num_args,    /**< (I) The number of arguments */
    char**                keys,        /**< (I) The keys of the arguments */
    char**                values,      /**< (I) The values of the arguments */
    int*                  num_found,   /**< (O) The number of found result */
    tag_t**               found        /**< (OF) num_found The result found */
    );

/**
    Full Text Keyword Search "PLUG-n-PLAY" feature.
*/
extern USER_EXITS_API int USER_get_keyword_search_client(
    const char*           name,          /**< (I) */
    int                   num_args,      /**< (I) */
    char**                names,         /**< (I) */
    char**                values,        /**< (I) */
    char**                search_client  /**< (OF) search client */
    );

extern USER_EXITS_API int USER_process_keyword_search_results(
    const char*           name,         /**< (I) */
    FILE*                 f_ptr,        /**< (I) */
    int*                  num_found,    /**< (O) */
    tag_t**               results       /**< (OF) num_found */
    );



/**
    @deprecated #NOTE_ask_extension deprecated in Teamcenter 11.4.
*/
TC_DEPRECATED_NO_REPLACEMENT( "11.4", "NOTE_ask_extension" )
extern USER_EXITS_API void NOTE_ask_extension(
    char*                  file_name,
    char*                  extension
    );

/**
    Invoke pdm server
*/
extern USER_EXITS_API void USER_invoke_pdm_server(
    int                    input_code,
    char*                  input_string,
    int*                   output_code,
    char**                 output_string
    );

/**
    Invoke user code from web
*/
extern USER_EXITS_API int USER_invoke_user_code_string(
    int                   input_code,       /**< (I) */
    const char*           input_string,     /**< (I) */
    int*                  output_code,      /**< (O) */
    char**                output_string     /**< (OF) */
    );

extern USER_EXITS_API int USER_invoke_user_code_taglist(
    int                   input_code,       /**< (I) */
    const char*           input_string,     /**< (I) */
    tag_t                 input_tag,        /**< (I) */
    tag_t*                output_tag,       /**< (O) */
    char**                output_string,    /**< (OF) */
    int*                  output_count,     /**< (O) */
    tag_t**               output_taglist    /**< (OF) output_count */
    );

extern USER_EXITS_API int USER_invoke_user_create_objs(
    tag_t tag,              /**< (I) Tag */
    char* form_name,        /**< (I) Form name */
    char* num_of_cost_elem, /**< (I) Number of Cost Elements */
    const char* plant,      /**< (I) Plant array */
    char* currency,         /**< (I) Currency */
    char* lead_time,        /**< (I) Lead Time */
    char* supplier,         /**< (I) Supplier */
    char* percentage,       /**< (I) Percentage */
    char* titles,           /**< (I) Titles */
    char* element_vals,     /**< (I) Elements vals */
    char* ar_number,        /**< (I) ArNumbers */
    char* sender_psp,       /**< (I) Sender PSP */
    char* receiver_psp,     /**< (I) Receiver PSP */
    char* sap_index,        /**< (I) Sap Index */
    char* sap_date,         /**< (I) Sap Date */
    char* sap_amount,       /**< (I) Sap amount */
    char* purchase_req,     /**< (I) Purchase req */
    char* comments,         /**< (I) Comments */
    char* deleted_index,    /**< (I) Deleted Rows */
    char* ignored_index,    /**< (I) Ignored Rows */
    char* modified_index,   /**< (I) Modified Rows */
    char* added_index       /**< (I) Added Rows */
    );


extern USER_EXITS_API void* user_StringLtoRCreate(
    char*                   text
    );

extern USER_EXITS_API int USER_string_compare (
    const char*           s1, /**< (I) */
    const char*           s2  /**< (I) */
    );


/**
    @name User Exits for UIF
    @{
*/

/**
    User exit to allow custom code to be notified whenever the user changes group.
    For example, this might be used to show or hide buttons on the custom pull-down menu in Workspace,
    so that users have access to different custom dialog boxes depending on their role.
*/
extern USER_EXITS_API int USER_new_current_group(
    tag_t                 group_tag,    /**< (I) Tag of the user's new current group */
    tag_t                 role_tag      /**< (I) Tag of the user's new current role */
    );

/** @} */

/**
    User can register PSE bomline attributes for display
*/
extern USER_EXITS_API void USER_register_bomline_attrs(
    char*                  attr_class /**< (I) */
    );

/**
    Demonstrate how to encapsulate an application
*/
extern USER_EXITS_API int USER_gs_shell_init_module(void);

/**
    Demonstrate how to encapsulate Unigraphics
*/
extern USER_EXITS_API void USER_nx_shell_init_module(void);

extern USER_EXITS_API int USER_preinit_module ( void );

extern USER_EXITS_API int USER_init_module ( void );

extern USER_EXITS_API int USER_exit_module ( void );




/**
    @name Item creation & copy
    @{
*/

/**
    @deprecated #USER_copy_revision deprecated in Teamcenter 12.4.
    
    Called before we do the action; returning non-zero ifail will abort the operation
*/
TC_DEPRECATED_NO_REPLACEMENT( "12.4", "USER_copy_revision" )
extern USER_EXITS_API int USER_copy_revision(
    const char*           rev_id,       /**< (I) */
    tag_t                 source_rev    /**< (I) */
    );

extern USER_EXITS_API int USER_create_revision(
    tag_t                 item_tag,     /**< (I) */
    const char*           rev_id        /**< (I) */
    );

extern USER_EXITS_API int USER_create_item(
    const char*           item_id,  /**< (I) */
    const char*           name,     /**< (I) */
    const char*           type,     /**< (I) */
    const char*           rev_id    /**< (I) */
    );

/** @} */


/**
    @name User Exits for BOM Compare
    @{
*/

/**
    This user exit is called by the PSE driven compare and (optionally) the ITK compare function.
    It is called at the start of a compare, even if no differences exist.

    This user exit allows some report initialization and header output to be performed.
    In the supplied compare user exit code it is used to suppress the calling of the other user exit functions.
*/
extern USER_EXITS_API int USER_bom_cmp_start_report(
    tag_t                 line1,    /**< (I) Tag of the first BOM line being compared */
    tag_t                 line2,    /**< (I) Tag of the second BOM line being compared */
    int                   mode,     /**< (I) Compare mode being used. May be one of the following: <br>
                                            #BOM_compare_singlelevel <br>
                                            #BOM_compare_lowestlevel <br>
                                            #BOM_compare_multilevel */
    int                   output    /**< (I) Output mechanism being used.
                                            Constructed by adding the following values as required: <br>
                                            #BOM_compare_output_bomline <br>
                                            #BOM_compare_output_userexit <br>
                                            #BOM_compare_output_report */
    );

/**
    This user exit is called by the PSE driven compare and (optionally) the ITK compare function.
    It is called at the start of a compare, only if differences exist.
    This function is called after #USER_bom_cmp_start_report.

    This user exit allows some report initialization and header output to be performed.
*/
extern USER_EXITS_API int USER_bom_cmp_enter_report(
    tag_t                 line1,    /**< (I) Tag of the first BOM line being compared */
    tag_t                 line2,    /**< (I) Tag of the second BOM line being compared */
    int                   mode,     /**< (I) Compare mode being used. May be one of the following: <br>
                                            #BOM_compare_singlelevel <br>
                                            #BOM_compare_lowestlevel <br>
                                            #BOM_compare_multilevel */
    int                   output    /**< (I) Output mechanism being used.
                                            Constructed by adding the following values as required: <br>
                                            #BOM_compare_output_bomline <br>
                                            #BOM_compare_output_userexit <br>
                                            #BOM_compare_output_report */
    );

/**
    This user exit is called by the PSE driven compare and (optionally) the ITK compare function.
    It is called once for every different item which the BOM compare finds.

    This user exit allows details of a single item which has changed to be output to a report.
    The BOM compare ITK functions can be used to extract information about the exact nature of the changes.

    @note The compare item supplied as an input parameter to this function is not the same as a Teamcenter item.
    This tag should only be used with the BOM compare ITK functions.
*/
extern USER_EXITS_API int USER_bom_cmp_item_report(
    tag_t                 cmp_item,     /**< (I) Tag of a compare item */
    int                   depth         /**< (I) Depth of the compare item below the item selected to be compared.
                                                This is only relevant in multi-level compares. */
    );

/**
    This user exit is called by the PSE driven compare and (optionally) the ITK compare function.
    It is only called in multi-level mode.
    It is called once for every BOM line which is an ancestor of a changed item.

    @note This function is not called for the root of the compare, or any of its ancestors.

    This user exit allows details of a changed item's ancestry to be output to a report.
    This function and #USER_bom_cmp_item_report are called in the correct order to
    allow a report to be output as an indented bill.
*/
extern USER_EXITS_API int USER_bom_cmp_parent_report(
    tag_t                 bom_line,     /**< (I) Tag of the parent BOM line */
    int                   depth         /**< (I) Depth of the BOM line below the item selected to be compared */
    );

/**
    This user exit is called by the PSE driven compare and (optionally) the ITK compare function.
    It is called at the end of a compare, only if differences exist.
    This function is called before #USER_bom_cmp_end_report.

    This user exit allows some tidying up and footer output to be performed.
*/
extern USER_EXITS_API int USER_bom_cmp_exit_report( );

/**
    This user exit is called by the PSE driven compare and (optionally) the ITK compare function.
    It is called at the end of a compare, even if no differences exist.

    This user exit allows some tidying up and footer output to be performed.
*/
extern USER_EXITS_API int USER_bom_cmp_end_report(
    logical               changes   /**< (I) Set to true if changes exist, otherwise false */
    );

/**
    Called by Generic Compare Engine immediately after it has defined all the standard internal
    compare descriptors. This is the user exit in which users should define their own descriptors,
    or adjust the standard ones.
*/
extern USER_EXITS_API int USER_define_compare_descs();

/**
    Called by BOM Compare immediately after it has defined all the standard internal BOM compare modes.
    This is the user exit in which users should define their own modes, or adjust the standard ones.
*/
extern USER_EXITS_API int USER_define_bom_compare_modes();

/** @} */

/**
    @name User Exits for BOMViews and BOMView Revisions
    @{
*/

/**
    Method to generate a name for a new BOMView.

    The default implementation of this function calls #PS_system_default_bom_view_name.
*/
extern USER_EXITS_API int USER_ps_default_bom_view_name(
    tag_t                 item,         /**< (I) Item of the BOMView */
    tag_t                 view_type,    /**< (I) View type of the BOMView */
    char**                name          /**< (OF) */
    );

/**
    Method used to generate a name for a new BOMView Revision.

    The default implementation of this function calls #PS_system_default_bvr_name.
*/
extern USER_EXITS_API int USER_ps_default_bvr_name(
    tag_t                 item_rev,     /**< (I) Item Revision of the BOMView Revision */
    tag_t                 view_type,    /**< (I) View type of the BOMView Revision */
    char**                name          /**< (OF) */
    );

/** @} */

/**
    BOMLine preferred ancestor user exit
*/
extern USER_EXITS_API int USER_bomline_is_preferred_ancestor(
    tag_t                 bomline_or_appearance,    /**< (I) */
    logical               is_bomline,               /**< (I) */
    logical*              is_preferred_ancestor     /**< (O) */
    );

/**
    @name User Exits for Appearances
    @{
*/

/**
    This user exit is called when an appearance requires its mapped attributes to be updated.
    This is called once for each attribute mapping that has its external flag set.
    This user exit can then use #APPR_ask_attr_mapping to obtain details of the mapping being invoked,
    and #APPR_set_attr_value to set the mapped attribute.

    <b>Return Values:</b>

    #APPR_no_mapping_logic_defined - No mapping code has been implemented for the given mapping.
*/
extern USER_EXITS_API int USER_ps_update_appr_attr(
    tag_t                 appr,     /**< (I) Appearance that requires its mapped attributes to be updated */
    tag_t                 parent,   /**< (I) Parent BOMViewRevision of Occurrence */
    tag_t                 occ,      /**< (I) Occurrence being mapped to the Appearance */
    tag_t                 mapping   /**< (I) Attribute Mapping */
    );

/**
    Appearance end-item search results update user exit
*/
extern USER_EXITS_API int USER_appr_update_end_item_search_results(
    tag_t                 configuration_rule,           /**< (I) */
    int                   num_input_search_results,     /**< (I) */
    tag_t*                input_search_results,         /**< (I) */
    int*                  num_output_search_results,    /**< (O) */
    tag_t**               output_search_results         /**< (O) */
    );

/** @} */

/**
    Improve user property registration. Used in user_props.c
*/
typedef struct USER_prop_init_entry_s
{
    char*                   type_name;
    METHOD_function_t       user_method;
    TC_argument_list_t*   user_args;
} USER_prop_init_entry_t;

/**
    DMI register markup pre-action handler which is used to build a customize stack file for the markup tool.
*/
extern USER_EXITS_API int USER_markup_pre_action_handler(
    METHOD_message_t*     msg,
    va_list               args
    );

/**
    @name User Exits for Dataset

    The User Exits feature controls the id and rev of Dataset.
    @{
*/

/**
   Generates new Dataset ID.
   <br/>The default implementation provides the ID using the following steps:
   <ul>
   <li>If an owning Item or Item Revision is specified, the default ID will be generated with
   the format &lt;item_id&gt;&lt;separator&gt;&lt;number&gt;, where the separator can be defined by the
   preference "AE_dataset_id_separator".</li>
   <li>Otherwise, the default ID will be generated with the format &lt;prefix&gt;&lt;number&gt;&lt;suffix&gt;
   where the prefix and suffix are defined by the preferences "AE_dataset_id_prefix" and "AE_dataset_id_postfix",
   respectively. If a preference is not set, the value for the prefix and/or suffix will be retrieved from the server
   internationalized strings "k_dataset_id_prefix" and "k_dataset_id_postfix".</li>
   </ul>
   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#BMF_USER_EXIT_ERROR if a customer user exits was executed and failed.
   <li>#AE_finding_datasettype if the default implementation is running and @p ds_type does not exist.
   </ul>
*/
extern USER_EXITS_API int USER_new_dataset_id(
    const tag_t           item,         /**< (I) Tag of the Item or Item Revision that will own the newly created Dataset.
                                                 <br/>This can be a NULLTAG if a new ID is generated by ID counter.
                                                 <br/>If @p item is invalid, it will be ignored by the default implemenation.*/
    const char*           ds_type,      /**< (I) Name of the Dataset Type.*/
    logical*              is_modifiable,/**< (O) Indicates if a modified version of retrieved Dataset ID can be used.*/
    char**                id            /**< (OF)The new Dataset ID.*/
    );

/**
    Generates new Dataset revision ID.
    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BMF_USER_EXIT_ERROR if a customer user exits was executed and failed.
    <li>#AE_finding_datasettype if the input Dataset Type name does not exist
    </ul>
*/
extern USER_EXITS_API int USER_new_dataset_rev(
    const char*           ds_id,          /**< (I)  The Dataset ID. <br/>This can be a NULL. */
    const char*           ds_type,        /**< (I)  Name of the Dataset Type.*/
    logical*              is_modifiable,  /**< (O)  Indicates if a modified version of retrieved Dataset revision ID can be used.*/
    char**                rev_id          /**< (OF) New dataset revision ID.*/
    );

/** @} */

/**
    @name User Exits for Folders and Forms

    The User Exits feature controls the names of folders and forms during a Revise operation.
    @{
*/

/**
    This program returns a new folder name based on the parent values or the basis name.
    the default action returns the basis_name as the new_name, and mod will be set to true.
    If the basis name is NULL then the following would be tried until a non-NULL value is found;
    the parent name, the folder type, or "Folder."
*/
extern USER_EXITS_API int USER_new_folder_name(
    tag_t                 parent_tag,   /**< (I) Tag of the intended parent of this folder,
                                                use to validate or determine the new folder name. Can be a #NULLTAG. */
    char*                 parent_type,  /**< (I) Type of the intended parent of this folder,
                                                use to validate or determine the new folder name. Can be a NULL. */
    char*                 parent_name,  /**< (I) Name of the intended parent of this folder,
                                                use to validate or determine the new folder name. Can be a NULL. */
    char*                 basis_name,   /**< (I) Possible name for new folder. Can be NULL. */
    char*                 folder_type,  /**< (I) Name of folder type. Can be NULL. */
    logical*              mod,          /**< (O) Returns whether name field can be modified, default value is true */
    char**                new_name      /**< (OF) The new folder name */
    );

/**
    Returns a new form name based on the form type and either the parent tag or the basis name.
    Default action is to return the basis_name as the new_name, and mod will be set to true.
    If the basis name is NULL then the following would be tried until a non-NULL value is found;
    the parent name, the form type, or "Form."
*/
extern USER_EXITS_API int USER_new_form_name(
    tag_t                 parent_tag,   /**< (I) Tag of the intended parent of this form,
                                                use to validate or determine the new form name. Can be a #NULLTAG. */
    char*                 parent_type,  /**< (I) Type of the intended parent of this form,
                                                use to validate or determine the new form name. Can be a NULL. */
    char*                 parent_name,  /**< (I) Name of the intended parent of this form,
                                                use to validate or determine the new form name. Can be a NULL. */
    char*                 basis_name,   /**< (I) Possible name for new form. Can be NULL. */
    char*                 form_type,    /**< (I) Name of form type. Can be NULL. */
    logical*              mod,          /**< (O) Returns whether name field can be modified, default value is true. */
    char**                new_name      /**< (OF) The new form name */
    );

/** @} */

/**
    @name User exits for Global Teamcenter
    @{
*/

extern USER_EXITS_API int USER_ods_check_pubrec_access(
    tag_t                 pubrec_tag,       /**< (I) */
    const char*           user_id,          /**< (I) */
    const char*           group_name,       /**< (I) */
    const char*           role_name,        /**< (I) */
    int                   client_site_id,   /**< (I) */
    logical*              has_read_access   /**< (O) */
    );

extern USER_EXITS_API int USER_ods_publish_object(
    int                   ods_site_id,  /**< (I) */
    tag_t                 object_tag    /**< (I) */
    );

extern USER_EXITS_API int USER_idsm_start_remote_export(
    tag_t                 main_object_tag,              /**< (I) */
    int                   is_transferring_ownership,    /**< (I) */
    int                   ie_options,                   /**< (I) */
    int                   remote_site_id,               /**< (I) */
    const char*           remote_user_id,               /**< (I) */
    const char*           remote_group_name,            /**< (I) */
    const char*           remote_role_name              /**< (I) */
    );

extern USER_EXITS_API int USER_idsm_end_remote_import(
    tag_t                 main_object_tag,              /**< (I) */
    int                   is_transferring_ownership,    /**< (I) */
    const char*           export_directory              /**< (I) */
    );

/**
    This user exit USER_end_local_import runs when a replication is performed at the importing site.
    It enables a site to perform custom actions, for example, when an Item Revision is being replicated
    into the database. (For example: perform validations on certain attributes, release status, etc).
*/

extern USER_EXITS_API int USER_end_local_import(
    tag_t                 main_object_tag,              /**< (I) */
    logical               is_transferring_ownership,    /**< (I) */
    const char*           export_directory              /**< (I) */
    );

extern USER_EXITS_API int USER_end_import_of_item(
    tag_t                 item_tag      /**< (I) */
    );

/** @} */

/**
    @name User Exits for CM
    @{
*/

/**
    User exit to allow custom code to change the affected Item to Problem Item relationship
    from default that has been supplied by i-man.
    Default relation name is the Problem pseudo-folder name that is mentioned in the site preference
    ECM_prev_structure_relation.
    This relation is created when the creator of the EC revision pastes the problem Item Revisions in that folder.
*/
extern USER_EXITS_API int USER_ecm_get_prev_bvr(
    tag_t                 ec_rev_tag,       /**< (I) Tag of the Change Revision */
    tag_t                 bvr_tag,          /**< (I) Tag of the Affected Bom View Revision */
    tag_t*                prev_bvr_tag      /**< (O) Tag of the Problem Bom View Revision */
    );

/**
    User exit to allow custom code to create never used relation between the end item and a part,
    which has a BOM Change associated with it, in the assembly.
    "ECM_never_used" is used as the relation name.
    This relation is used to determine the never used parts in a genealogy trail.
*/
extern USER_EXITS_API int USER_ecm_define_never_used_relations(
    tag_t                 ec_rev_tag,       /**< (I) Tag of the Change Revision */
    tag_t                 parent_ir_tag,    /**< (I) Tag of the Problem Item Revision */
    tag_t                 aff_bvr_tag,      /**< (I) Tag of the Affected Bom View Revision */
    tag_t                 pro_bvr_tag       /**< (I) Tag of the Problem Bom View Revision */
    );

/**
    User exit to allow custom code to set dynamic revision rules for the affected and the problem assemblies.
    Using this method, the user can supply the revision rules to be used while saving BOM change objects and
    also while displaying PSE Supersedure window in i-man Portal.
    By default core CM revision logic will be applied.
*/
extern USER_EXITS_API int USER_ecm_get_base_revision_rules(
    tag_t                 ec_rev_tag,           /**< (I) Tag of the Change Revision */
    tag_t                 affected_bvr_tag,     /**< (I) Tag of the Affected Bom View Revision */
    tag_t                 problem_bvr_tag,      /**< (I) Tag of the Problem Bom View Revision */
    logical*              is_set,               /**< (O) Indicates whether the Revision Rules have been set */
    tag_t*                affected_rule_tag,    /**< (O) Tag of the Revision Rule for the Affected assembly */
    tag_t*                problem_rule_tag      /**< (O) Tag of the Revision Rule for the Problem assembly */
    );

/**
    User exit to allow custom code to set dynamic revision rules for the solution and the impacted assemblies.
    Using this method, the user can supply the revision rules to be used while saving BOM change objects and
    also while displaying PSE Supersedure window in i-man Portal.
    By default core CM revision logic will be applied.
*/
extern USER_EXITS_API int USER_cm_get_base_revision_rules(
    tag_t       cm_rev_tag,             /* (I) Tag of the Change Revision */
    tag_t       solution_bvr_tag,       /* (I) Tag of the Solution Bom View Revision */
    tag_t       impacted_bvr_tag,       /* (I) Tag of the Impacted Bom View Revision */
    logical     *is_set,                /* (O) Indicates whether the Revision Rules have been set */
    tag_t       *solution_rule_tag,     /* (O) Tag of the Revision Rule for the Solution assembly */
    tag_t       *impacted_rule_tag      /* (O) Tag of the Revision Rule for the Impacted assembly */
    );

/**
    User exit to allow custom code to get process name for multiple processes.
    Using this function the user can generate a process name based on
    the targets that have been provided as input.
    This process name is used when multiple processes are to be initiated for
    the targets from the multiple processes dialog.
*/
extern USER_EXITS_API int USER_ecm_get_process_name(
    tag_t                 change_rev_tag,   /**< (I) Tag of the Change Revision */
    int                   n_targets,        /**< (I) Number of targets of the EPM process */
    tag_t*                targets,          /**< (I) Tags of the targets of the EPM process */
    char**                process_name      /**< (OF) Name of the EPM Process */
    );

/** @} */

/**
    User exits for the notification handler. Used in notifyhandler.cxx
*/
extern USER_EXITS_API int USER_build_notify_message(
    const TcSubscriptionActionMsg_t*    theSubscriptionMsg,     /**< (I) */
    char**                              messageSubject,         /**< (O) */
    int*                                nMessageLines,          /**< (O) */
    char***                             messageLines            /**< (O) */
    );

/**
    User exits for the notification handler. Used in notifyhandler.cxx
*/
extern USER_EXITS_API int USER_build_notify_message_with_locale(
    const TcSubscriptionActionMsg_t*    theSubscriptionMsg,     /**< (I) */
    const char*                         localeStr,               /**< (I) */
    char**                              messageSubject,         /**< (O) */
    int*                                nMessageLines,          /**< (O) */
    char***                             messageLines            /**< (O) */
    );

/**
    This USER EXIT will be used to add site based canned methods.
    If a site wants to add custom methods as canned methods so as to make these canned methods
    available for configuration from the Business Rules Application,
    then the function to add canned methods need to be called from within this USER EXIT.
    The function to add the canned methods is #METHOD_CM_add_method2.
*/
extern USER_EXITS_API int USER_add_canned_methods( void );

extern USER_EXITS_API int USER_synchronize_baseline(
    const char*           fullFilePathName /**< (I) */
    );

extern USER_EXITS_API int USER_baseline_dryrun_validator(
    const char*           baseRevListFullFileName /**< (I) */
    );

/**
    Used by the Appearance (APPR) module,
    for appearance sets that are configured by a mixture of unit effectivity and release date.
    Such structures are considered to contain a (ragged) line running across this structure,
    called the Effectivity-Release Configuration Transition (ERCT).
    Above this line items are configured by unit effectivity; below it they are configured by date.
    Whether a given item lies above or below the line is deemed to be a property of the item,
    and possibly of the particular appearance set (context),
    however the specific decision is a matter for the customer's business process,
    hence this function is provided as a user exit for the user to implement.
    The default behavior for this exit as supplied with base Teamcenter is to always return true,
    so that all items will be treated as 'above ERCT' and configured by unit effectivity.
*/
extern USER_EXITS_API int USER_appr_item_is_above_ERCT(
    tag_t                 appr_context, /**< (I) */
    tag_t                 item_tag,     /**< (I) */
    logical*              is_above_erct /**< (O) */
    );

/**
    User exits for saveas project

    This function is required to set valid to true or false depending on
    whether or not dataset_name is a valid dataset name for the given parameters.
    If customizing, then the test done on the name is entirely up to the site.
    However, it is sensible to ensure that #USER_copied_datasets_details and
    #USER_copied_dataset_name return names which pass this validation test.
    (An example of the use of this user exit:
    NX will effectively call this function once a user has entered or modified the dataset name,
    and will tell the user whether or not it is valid)

    <b>Default Implementation</b>

    If SP3 (force_name_validation) is true,
    valid is set to true or false depending on whether or not dataset_name can
    be matched onto SP1 (pattern) using the parameters given.
    If SP3 is false, the function returns true for any input.

    @note It is not possible to report the reason for the failure to the user,
    as there is no internationalization support in the ITK.
*/
extern USER_EXITS_API int USER_validate_dataset_name(
    tag_t                 old_owner,        /**< (I) Tag of the old revision */
    tag_t                 old_dataset,      /**< (I) Tag of the old dataset */
    const char*           new_item_id,      /**< (I) Item ID for the new item (has not necessarily been created yet) */
    const char*           new_revision_id,  /**< (I) Revision ID for the new revision (has not necessarily been created yet) */
    const char*           item_type,        /**< (I) Item type for the new item (has not necessarily been created yet) */
    const char*           dataset_name,     /**< (I) String containing the dataset name to be validated */
    logical*              valid             /**< (O) A logical indicating whether the name specified is valid */
    );

/**
    This function is used to determine how a set of datasets should be copied via a save-as operation.

    <b>Default Implementation</b>

    Generate the new names and whether or not the names can be modified by the user.
    Use SP4 (always/never_copy) which determines which types must
    always/never be copied to determine the copy state for each.
    Set the validation requirement based on SP3 (force_name_validation).
    Set the owner return values based on SP5 (owner).
    allow_duplicates is returned according to the site preference.
*/
extern USER_EXITS_API int USER_copied_datasets_details(
    tag_t                       old_revision,       /**< (I) Tag of the old revision */
    const char*                 new_item_id,        /**< (I) ItemID for the new item (has not necessarily been created yet) */
    const char*                 new_revision_id,    /**< (I) RevisionID for the new revision
                                                        (has not necessarily been created yet) */
    const char*                 new_item_type,      /**< (I) Item type for the new item (has not necessarily been created yet) */
    int                         dataset_count,      /**< (I) Number of datasets in array */
    tag_t                       dataset_list[],     /**< (I) Array of tags of datasets to query */
    USER_DATASET_details_t**    details,            /**< (OF) Pointer to an array of "details" structures, described below.
                                                        Each structure refers to one of the non-master names. */
    logical*                    allow_duplicates    /**< (O) Whether or not duplicate non-master names should be allowed */
    );

/**
    To check if dataset should be allowed to export based on it's classification type
*/
extern USER_EXITS_API int USER_is_dataset_exportable(
    tag_t       dataset_tag ,               /**< (I) tag of dataset object */
    int         n_target_sites,             /**< (I) number of target sites */
    tag_t*      target_sites,               /**< (I) target sites list */
    logical     is_transferring_ownership,  /**< (I) logical indicating if multisite transfer will transfer ownership */
    logical     modified_objects_only,      /**< (I) logical indicating if multisite transfer is transferring only modified objects or otherwise */
    logical*    isExportable                /**< (O) decision, if this dataset tag should be multisite exported or not */
    );

/**
    We invented a new property for an item called "configured_revisions",
    and this method will be called while invoking this property method call.
    So, users may customize this method to get their interested revisions,
    otherwise it returns null tag.
*/
extern USER_EXITS_API int USER_ask_display_revisions(
    tag_t                 item_tag,     /**< (I) */
    int*                  count,        /**< (O) */
    tag_t**               revisions     /**< (OF) count */
    );


/**
    Validates the alternate ID.
    <br/>Customers can override the existing validation and provide their custom validation by implementing a callback function on #IDFR_validate_alternate_msg.
    <br/>This user exit is called when a user chooses OK or Apply in Save As dialog boxes.
    <br/>This API verifies that the Alternate ID is created for the given Item and ID Context.
    <br/>It can verify that the IDs meet certain criteria and, if necessary, return modified IDs.
    <br/>If this function returns with status set to invalid, then the user can either accept the modified IDs (if supplied), or cancel the create.
    <br/>If this function returns with status set to modified, then the user can choose whether to use the modified IDs, force the system to use the originally entered IDs, or cancel the create.
    <br/>If this function returns with status set to override, then the modified IDs will be used without informing the user and will be helpful to perform case conversions. 

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#IDENTIFIER_invalid_tag if either @p idcontext, @p identifiable, @p altid_type or @p altid is #NULLTAG or invalid.
   </ul>
*/
extern USER_EXITS_API int USER_validate_alternate(
    tag_t                 idcontext,        /**< (I)  The ID Context object.*/
    tag_t                 identifiable,     /**< (I)  The identifiable Item object for which to validate the cardinality.*/
    tag_t                 altid_type,       /**< (I)  The Alternate Identifier type.*/
    tag_t                 altid,            /**< (I)  The Alternate ID.*/
    logical*              is_valid          /**< (O)  Indicates if the validition of the Alternate ID was successful.*/
    );

/**
   This function provides a hook point for customers, and gets called
   with following different parameters:

   <table>
   <tr><td>1.</td>  <td>Brand new item creation (assign button selected)
                    <UL>
                       <LI>  Item alternate id:
                             <br>
                             idcontext_tag (cannot be null)
                             <br>
                             altid_type = alt identifier type for item alternateid
                             <br>
                             parent_altid_tag = NULLTAG
                       <LI>  Item Revision alt id:
                             <br>
                             idcontext_tag (cannot be null)
                             <br>
                             altid_type = alt identifier type for itemrevision alternateid
                             <br>
                             parent_altid_tag = NULLTAG
                     </UL>
                     </td> </tr>
   <tr><td>2.</td>  <td>From save function if it was not already assigned
                     <UL>
                       <LI>  Item alternate id:
                             <br>
                             idcontext_tag
                             <br>
                             altid_type = alt identifier type for item alternateid
                             <br>
                             parent_altid_tag = NULLTAG
                        <LI> Item Revision alt id:
                             <br>
                             idcontext_tag
                             <br>
                             altid_type = alt revision identifier type
                             <br>
                             parent_altid_tag = tag to alt identifier for item alternateid
                     </UL>
                     </td> </tr>
    <tr><td>3.</td>  <td>From revise alternate creation (assign button selected)
                             <br>
                             idcontext_tag or NULLTAG
                             <br>
                             altid_type = alt revision identifier type or NULLTAG
                             <br>
                             parent_altid_tag = tag to alt identifier for item alternateid
                     </td> </tr>
    </table>
*/
extern USER_EXITS_API int USER_new_alt_id(
    tag_t                 idcontext_tag,        /**< (I)  Tag of IdContext.*/
    const char*           preferred_pattern,    /**< (I)  Pattern string.*/
    tag_t                 altid_type_tag,       /**< (I)  Tag of alt identifier type.*/
    tag_t                 parent_altid_tag,     /**< (I)  Tag of parent alt identifier type.*/
    char**                new_id                /**< (OF) New Item alternate id.*/
    );

/**
   Validates the new alternate identifiers.
   <br/>Customers can override the existing validation and provide their custom validation by implementing a callback function on #IDFR_validate_alternate_msg.
   <br/>USER_invalid_id if @p status when naming rule pattern did not match with the id specified.
   <br/>This user exit is called when a user chooses OK or Apply in the Item Creation or Save As dialog boxes.
   <br/>It can verify that the IDs meet certain criteria and, if necessary, return modified IDs.
   <br/>If this function returns with status set to invalid, then the user can either accept the modified IDs (if supplied), or cancel the create.
   <br/>If this function returns with status set to modified, then the user can choose whether to use the modified IDs, force the system to use the originally entered IDs, or cancel the create.
   <br/>If this function returns with status set to override,then the modified IDs will be used without informing the user(this is helpful for performing case conversions).

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#IDENTIFIER_invalid_tag if @p idcontext is NULLTAG.
       
   </ul>
*/
extern USER_EXITS_API int USER_validate_alt_id(
    tag_t                 idcontext_tag,    /**< (I)  The ID Context object. */
    const char*           idfr_type,        /**< (I)  Type of the new Identifiers. */
    const char*           new_id,           /**< (I)  The New alternate ID. */
    const char*           pattern_name,     /**< (I)  Name of the Pattern */
    char**                modified_id,      /**< (OF) Modified ID for the Alternate identifier( if any ). */
    IDValid_e*            status            /**< (O)  Indicates if the validition of the alternate ID was successful. */
    );

/**
    This function is used to determine if the Item Revision is mature or not.
    By default, the status on the ItemRevision Object is compared to the value
    specified on the group level preference \<ItemRevision Type Name\>_Maturity_Level
    If the value in the preference matches to any of the status objects on the
    ItemRevision the TRUE is returned. If the preference doesnot exist then the default
    value to compare with against is 'Released'.
*/
extern USER_EXITS_API int USER_is_item_rev_mature(
    tag_t                 item_rev_tag,     /**< (I) */
    logical*              mature            /**< (O) */
    );

extern USER_EXITS_API int USER_make_design_rev_primary_precond (
    tag_t               part_rev,           /**< (I) */
    tag_t               design_rev,         /**< (I) */
    logical*            isDesignRevEligible /**< (O) */
    );

extern USER_EXITS_API int USER_register_plmxml_filters();

extern USER_EXITS_API int USER_register_plmxml_schema_mappings();

extern USER_EXITS_API int USER_register_plmxml_actions();

extern USER_EXITS_API int USER_register_tcplmxml_filters();

extern USER_EXITS_API int USER_register_tcplmxml_actions();

extern USER_EXITS_API int USER_register_aiws_extensions();
extern USER_EXITS_API int USER_register_plmxml_import_methods();
extern USER_EXITS_API int USER_register_plmxml_export_methods();


/**
    @name Report Writer user_exits
    @{
*/

extern USER_EXITS_API int USER_register_report_columns(void);

extern USER_EXITS_API logical USER_report_include_row(
    tag_t                     pff_tag, /**< (I) */
    int                       n_tags,  /**< (I) */
    tag_t*                    obj_tags /**< (I) */
    );

/** @} */

/**
    @name Validation object user_exits
    @{
*/

extern USER_EXITS_API int USER_evaluate_compound_result(
    char*                 validation_name,      /**< (I) */
    int                   validation_status,    /**< (I) */
    logical*              validation_result     /**< (O) */
    );

extern USER_EXITS_API int USER_validation_post_action(
    tag_t                 target,
    logical               validation_result,
    int                   validation_status
    );

extern USER_EXITS_API int TCHANDLER_proxy_link(
    void*                 subMsg,
    int                   nRecipients,
    char**                recipientList
    );

/** @} */


/** @} */

/**
    @name CAE Batch Meshing user_exits
    @{
*/
extern USER_EXITS_API int USER_get_batch_meshing_nr_name2(
    const char *meshFileName,                           /**< (I) file name into which to encode mesh size */
    const char *meshSize,                               /**< (I) mesh size to encode */
    const char *meshFileExt,                            /**< (I) file name extension */
    char        **namedRefName                          /**< (OF) resulting named ref name */
);

/** @} */

extern USER_EXITS_API int USER_ods_client_publish_extra_attributes(
    tag_t       object_to_publish,                      /**< (I) Selected object to be published*/
    int         n_attrs,                                /**< (I) Number of extended attributed to be populated on PubR*/
    char**      pr_pom_attr_names,                      /**< (I) Attribute names on PubR to be added */
    char*       attr_values[]                           /**< (O) Attribute values on PubR to be added */
    );

extern USER_EXITS_API int USER_ods_client_ask_extra_attributes(
    int* n_attrs,                                /**< (O) Number of extended attributed to be populated on PubR*/
    char*** pr_pom_attr_names,                      /**< (OF) Attribute names on PubR to be added */
    char*** attr_options                            /**< (OF) Attribute options on PubR to be added */
);


extern USER_EXITS_API int USER_classification_autocompute_attr();

extern USER_EXITS_API int USER_compute_effectivity(
    tag_t blTag,                                /**< (I) BOMLine tag*/
    logical intersectConfigEff,                /**< (I) If true Occ Effectivity(netEffObjTags) is intersection of
                                                       BOMLine Eff with Effectivity on BOMWindow Configuration */
    logical* occEffExists,                      /**< (O) true if the occurrence has effectivity defined. */
    logical* isConfigured,                      /**< (O) true if the occurrence is configured. */
    int* effyCount,                             /**< (O) Occurrence Effectivity count*/
    WSOM_effectivity_info_t*** effectivityInfo   /**< (OF) Occurrence Effectivity */
);

extern USER_EXITS_API int USER_validate_id(
    char* boType,                                           /**< (I) The type name */
    int nKey,                                               /**< (I) Number of MFK key */
    char **keys,                                            /**< (I) List of MFK keys */
    char **values,                                          /**< (I) List of MKF vlaues */
    logical* isValid                                        /**< (O) The result of ID validation */
    );

/**
    Identifies all the parent Item and ItemRevision objects in the structure where input @p bo_tag is used.
    <br/>This calls #BMF_where_used message to execute the custom implementation available against the #BMF_where_used message.

    @returns
    <ul>
        <li>#ITK_ok on success.
        <li>#ITK_invalid_name if an invalid custom function name is registered against USER_where_used exit (for example, its name contains white spaces).
    </ul>
*/
extern USER_EXITS_API int USER_where_used(
    char* bo_type,                                           /**< (I) The type name */
    tag_t bo_tag,                                            /**< (I) The object tag */
    tag_t revision_rule,                                     /**< (I) The revision rule tag */
    int* num_parents,                                        /**< (O) The number of parent object tags */
    tag_t** parents,                                         /**< (OF) num_parents The Parent object tags where input @p bo_tag is used */
    int** levels                                             /**< (OF) num_parents The Level of parent */
    );



/** @} */

#ifdef __cplusplus
}
#endif

#include <user_exits/libuser_exits_undef.h>
#endif
