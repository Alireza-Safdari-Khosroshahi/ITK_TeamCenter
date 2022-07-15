/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Include file to define errors for a Teamcenter Engineering volume
*/

/*  */

#ifndef VM_ERRORS_H
#define VM_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup VM_ERRORS Volume Mananagement Errors
    @ingroup AE
    @{
*/

#define VM_NOLOCK                   (EMH_VM_error_base +    0)
#define VM_NOUNLOCK                 (EMH_VM_error_base +    1)
#define VM_INV_LOGICAL              (EMH_VM_error_base +    2)
#define VM_INV_NODE                 (EMH_VM_error_base +    3)
#define VM_INV_PATH                 (EMH_VM_error_base +    4)
#define VM_INV_MTYPE                (EMH_VM_error_base +    5)
#define VM_NODELETE                 (EMH_VM_error_base +    6)
#define VM_VOLUME_NOT_EMPTY         (EMH_VM_error_base +    7)
#define VM_VOLUME_FULL              (EMH_VM_error_base +    8)
#define VM_NO_CREATE                (EMH_VM_error_base +    9)
#define VM_LOG_IN_USE               (EMH_VM_error_base +   10)
#define VM_PATH_IN_USE              (EMH_VM_error_base +   11)
#define VM_NO_TAG                   (EMH_VM_error_base +   12)
#define VM_NO_SUCH_VOLUME           (EMH_VM_error_base +   13)
#define VM_NO_MOVE                  (EMH_VM_error_base +   14)
#define VM_NO_DATA                  (EMH_VM_error_base +   15)
#define VM_NO_SAVE                  (EMH_VM_error_base +   16)
#define VM_NO_LOAD                  (EMH_VM_error_base +   17)
#define VM_NO_UNLOAD                (EMH_VM_error_base +   18)
#define VM_NO_MODIFY_VNAME          (EMH_VM_error_base +   19)
#define VM_NO_MODIFY_PATH           (EMH_VM_error_base +   20)
#define VM_NO_MODIFY_NODE           (EMH_VM_error_base +   21)
#define VM_NO_SUCH_USER             (EMH_VM_error_base +   22)
#define VM_NO_SUCH_GROUP            (EMH_VM_error_base +   23)
#define VM_NO_GRANT_ACCESS          (EMH_VM_error_base +   24)
#define VM_NO_REVOKE_ACCESS         (EMH_VM_error_base +   25)
#define VM_NO_CHANGE_ACCESS         (EMH_VM_error_base +   26)
#define VM_NO_DELETE_DIR            (EMH_VM_error_base +   27)
#define VM_NO_DELETE_FILE           (EMH_VM_error_base +   28)
#define VM_UNRECOGNIZED_FORMAT      (EMH_VM_error_base +   29)
#define VM_NO_COPY                  (EMH_VM_error_base +   30)
#define VM_NULL_FILE                (EMH_VM_error_base +   31)
#define VM_UNKNOWN_TAG              (EMH_VM_error_base +   32)
#define VM_FINDING_VOLUMES          (EMH_VM_error_base +   33)
#define VM_NO_OSID                  (EMH_VM_error_base +   34)
#define VM_NO_SET_VOLUME            (EMH_VM_error_base +   35)
#define VM_NO_SELECTION             (EMH_VM_error_base +   36)
#define VM_NO_WIPEOUT               (EMH_VM_error_base +   37)
#define VM_NO_CREATE_MIRROR         (EMH_VM_error_base +   38)
#define VM_NO_AUTO_ARCHIVELOG       (EMH_VM_error_base +   39)
#define VM_NO_MIRROR_FILE           (EMH_VM_error_base +   40)
#define VM_NO_MIRROR_PATH           (EMH_VM_error_base +   41)
#define VM_NO_MIRROR_REVOKE_ACCESS  (EMH_VM_error_base +   42)
#define VM_NO_VOLUME_ACCESS         (EMH_VM_error_base +   43)
#define VM_NO_VOLUMES               (EMH_VM_error_base +   44)
#define VM_REVOKE_FAILED            (EMH_VM_error_base +   45)
#define VM_DIR_NOT_EMPTY            (EMH_VM_error_base +   46)
#define VM_TAG_COUNT_MISMATCH       (EMH_VM_error_base +   47)
#define VM_NO_REPORT_OVER_TCP       (EMH_VM_error_base +   48)
#define VM_UNABLE_TO_MOVE           (EMH_VM_error_base +   49)
#define VM_BAD_FSC_PATH             (EMH_VM_error_base +   50)
#define VM_NO_FSC_NAME_GRP_AND_LB   (EMH_VM_error_base +   51)
#define VM_BAD_COMB_FSC_NAME_GRP_LB (EMH_VM_error_base +   52)
#define VM_BAD_VOL_FAILOVER_MAP     (EMH_VM_error_base +   53)
/** The volume "%1$" cannot be deleted, because it is referenced by the object "%2$" of type "%3$". */
#define VM_REF_BY_OBJ               (EMH_VM_error_base +  54)

/**
    @name File Management Errors
    @{
*/

#define VM_FILEEXISTS               (EMH_VM_error_base +  100)
#define VM_NOFILE                   (EMH_VM_error_base +  101)
#define VM_FILENOTLOADED            (EMH_VM_error_base +  102)
#define VM_FILENOTOPEN              (EMH_VM_error_base +  103)
#define VM_NODELETEFILE             (EMH_VM_error_base +  104)
#define VM_NOCREATE                 (EMH_VM_error_base +  105)
#define VM_NOOPEN                   (EMH_VM_error_base +  106)
#define VM_NOCLOSE                  (EMH_VM_error_base +  107)
#define VM_FILENOTLOCKED            (EMH_VM_error_base +  108)
#define VM_FILEALREADYLOCKED        (EMH_VM_error_base +  109)
#define VM_NOACCESS                 (EMH_VM_error_base +  110)
#define VM_TOOMANYARGS              (EMH_VM_error_base +  111)
#define VM_NO_CREATE_FILE           (EMH_VM_error_base +  112)
#define VM_NO_GET_PATH              (EMH_VM_error_base +  113)
#define VM_INV_FILE_NAME            (EMH_VM_error_base +  114)
#define VM_NO_LOAD_FILE             (EMH_VM_error_base +  115)
#define VM_NO_SUCH_FILE             (EMH_VM_error_base +  116)
#define VM_DELETED_FILE             (EMH_VM_error_base +  117)
#define VM_ARCHIVED_FILE            (EMH_VM_error_base +  118)
#define VM_NO_FREEZE                (EMH_VM_error_base +  119)
#define VM_NO_UNFREEZE              (EMH_VM_error_base +  120)
#define VM_ALREADY_FROZEN           (EMH_VM_error_base +  121)
#define VM_NO_UNDEL                 (EMH_VM_error_base +  122)
#define VM_TLM_NO_MATCH             (EMH_VM_error_base +  123)
#define VM_MODIFIED                 (EMH_VM_error_base +  124)
#define VM_NOT_ARCHIVED             (EMH_VM_error_base +  125)
#define VM_NO_RESTORE               (EMH_VM_error_base +  126)
#define VM_NOT_CLOSED               (EMH_VM_error_base +  127)
#define VM_NO_SEND_MSG              (EMH_VM_error_base +  128)
#define VM_INV_FILE_FORMAT          (EMH_VM_error_base +  129)
#define VM_INV_EXT                  (EMH_VM_error_base +  130)
#define VM_INV_FORMAT               (EMH_VM_error_base +  131)
#define VM_INV_OWNER                (EMH_VM_error_base +  132)
#define VM_INV_MODE                 (EMH_VM_error_base +  133)
#define VM_NO_SET_FILENAME          (EMH_VM_error_base +  134)
#define VM_NO_READ                  (EMH_VM_error_base +  135)
#define VM_NO_WRITE                 (EMH_VM_error_base +  136)
#define VM_NO_STAT                  (EMH_VM_error_base +  137)

/** @} */

/**
    @name Modification for Teamcenter Engineering FS modes
    @{
*/

#define VM_BACKUP_MODE              (EMH_VM_error_base +  138)
#define VM_NO_FMS                   (EMH_VM_error_base +  139)
#define VM_INVALID_MODE             (EMH_VM_error_base +  140)
#define VM_RESTART_TCFS             (EMH_VM_error_base +  141)
#define VM_RESTART_BACKUP           (EMH_VM_error_base +  142)
#define VM_RDONLY_MODE              (EMH_VM_error_base +  143)
#define VM_BLOBBYVOL_MODE           (EMH_VM_error_base +  144)
#define VM_NORMAL_MODE              (EMH_VM_error_base +  145)
#define VM_CAUTIONMSG_MODE          (EMH_VM_error_base +  146)
#define VM_INVALID_WRITE_TICKET     (EMH_VM_error_base +  147)
#define VM_INVALID_READ_TICKET      (EMH_VM_error_base +  148)
#define VM_NO_KEY_INSTANCES         (EMH_VM_error_base +  149)
#define VM_INVALID_TRANSIENT_TICKET (EMH_VM_error_base +  150)
#define VM_NON_COMMITED_TICKET      (EMH_VM_error_base +  151)
#define VM_INVALID_TIER             (EMH_VM_error_base +  152)
#define VM_INVALID_FMSFUNCTION_CALL (EMH_VM_error_base +  153)
#define VM_UNICODE_ERROR            (EMH_VM_error_base +  154)
#define VM_INACTIVE_POLICY          (EMH_VM_error_base +  155)
#define VM_ERROR_ACCESS_TIME        (EMH_VM_error_base +  156)
#define VM_UNSUCCESSFUL_MIGRATION   (EMH_VM_error_base +  157)
#define VM_NO_HSM_PREFERENCE        (EMH_VM_error_base +  158)
#define VM_NO_PRY_TIER_VOLUMES      (EMH_VM_error_base +  159)
#define VM_REF_BY_POLICY            (EMH_VM_error_base +  160)
#define VM_FMS_MIG_NOT_SUPPORTED    (EMH_VM_error_base +  161)
#define VM_NOT_ENOUGH_SPACE         (EMH_VM_error_base +  162)
/** The Transient Volume absolute file path is not found as expected in the value of the preference "Transient Volume Root Directory". */
#define VM_INVALID_TVRD_PATH        (EMH_VM_error_base +  163)
/** An invalid value is passed in the "server_mode" parameter of the ITK "IMF_get_transient_file_read_ticket". The value must be either 2 or 4. Please report this error to your system administrator. */
#define VM_INVALID_SERVER_MODE      (EMH_VM_error_base +  164)
/** The asynchronous upload of the file to the Teamcenter volume is currently in progress.*/
#define VM_ASYNC_UPLOAD_IN_PROGRESS (EMH_VM_error_base +  165)
/** The asynchronous upload of the file to the Teamcenter volume is unsuccessful. Please try again. If it fails again, please contact your system administrator.*/
#define VM_ASYNC_UPLOAD_FAILED      (EMH_VM_error_base +  166)
/** An invalid dataset or volume file object was provided in order to generate a PLMD file. Please try again with a valid dataset or volume file object.*/
#define VM_INVALID_OBJ_INPUT        (EMH_VM_error_base +  167)
/** The PLMD file could not be created under the transient volume due to FMS BootStrap errors. Please contact your system administrator.*/
#define VM_CREATE_PLMD_FAILED       (EMH_VM_error_base +  168)
/** The PLMD file could not be created under the transient volume due to Operating System directory permissions. Please contact your system administrator.*/
#define VM_PLMD_NOOPEN              (EMH_VM_error_base +  169)
/** The named reference "%1$" cannot be uploaded, because a reference with the same name already exists. */
#define VM_DUPLICATE_REFNAME        (EMH_VM_error_base +  170)
/** @} */

/** 
    @name Content Verification
    @{
*/
/** The digest information is either missing or invalid. The digest needs to be recomputed using FMS utilities.*/
#define VM_CV_MISSING_INVALID_DIGEST             (EMH_VM_error_base +  171)
/** The provided file is a text file, and digest queries for text files are not supported.*/
#define VM_CV_DIGEST_NOT_SUPPORTED_FOR_TEXT_FILE (EMH_VM_error_base +  172)
/** The Dataset references no file.*/
#define VM_CV_NO_FILES_IN_DATASET                (EMH_VM_error_base +  173)
/** The digest type "%1$" is not supported.*/
#define VM_CV_INVALID_DIGEST_ALGORITHM_TYPE      (EMH_VM_error_base +  174)
/** No digest type is provided.*/
#define VM_CV_EMPTY_DIGEST_ALGORITHM_TYPE        (EMH_VM_error_base +  175)
/** @} */


/**
    @name OSDirWindow Errors
    @{
*/

#define VM_NO_FILES_SELECTED        (EMH_VM_error_base +  200)
#define VM_NO_DIRS_SELECTED         (EMH_VM_error_base +  201)
#define VM_TOO_MANY_DIRS            (EMH_VM_error_base +  202)
#define VM_NOT_A_DIR                (EMH_VM_error_base +  203)
#define VM_NOT_A_FILE               (EMH_VM_error_base +  204)
#define VM_NO_DATA_ON_CLIP          (EMH_VM_error_base +  205)
#define VM_BAD_DATA_TYPE            (EMH_VM_error_base +  206)
#define VM_NO_DATASET               (EMH_VM_error_base +  207)
#define VM_NO_CREATEDATASET         (EMH_VM_error_base +  208)
#define VM_NO_IMPORT                (EMH_VM_error_base +  209)
#define VM_NO_PROCESSID             (EMH_VM_error_base +  210)
#define VM_NO_USER                  (EMH_VM_error_base +  211)
#define VM_NO_FOLDER                (EMH_VM_error_base +  212)
#define VM_NO_INSERT_NSF            (EMH_VM_error_base +  213)
#define VM_NO_SAVE_NSF              (EMH_VM_error_base +  214)
#define VM_NO_UNLOCK_NSF            (EMH_VM_error_base +  215)
#define VM_PATH_TOO_BIG             (EMH_VM_error_base +  216)
#define VM_NO_FILES_IN_DATASET      (EMH_VM_error_base +  217)
#define VM_NO_REFERENCE             (EMH_VM_error_base +  218)
#define VM_NO_LOAD_REF              (EMH_VM_error_base +  219)
#define VM_NO_EXPORTABLE            (EMH_VM_error_base +  220)
/** @} */

/**
    @name Store and Forward Errors
    @{
*/
#define VM_SAF_NULL_INPUT_PARAMS     (EMH_VM_error_base +  221)
#define VM_SAF_BAD_FILE_TAG          (EMH_VM_error_base +  222)
#define VM_SAF_NO_USER_NAME          (EMH_VM_error_base +  223)
#define VM_SAF_BAD_VOLUME_TAG        (EMH_VM_error_base +  224)
#define VM_SAF_NO_DEST_VOLUME        (EMH_VM_error_base +  225)
#define VM_SAF_TSTK_TASK_ERROR       (EMH_VM_error_base +  226)
#define VM_SAF_POST_FAILED           (EMH_VM_error_base +  227)
#define VM_SAF_INIT_DEST_VOLUME_SAME (EMH_VM_error_base +  228)

/** @} */
/** @} */

#endif
