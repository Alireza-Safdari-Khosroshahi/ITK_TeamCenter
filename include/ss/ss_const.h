/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Header file to define constants for eim system services
*/

/*  */

#ifndef SS_CONST_H
#define SS_CONST_H

#include <unidefs.h>

#ifndef UNX
    #include <signal.h>
#else
    #include <sys/signal.h>
#endif

#include <ss/libss_exports.h>

/**
    @defgroup SS System Services (SS)
*/

/**
    @defgroup SS_CONST SS Constants
    @ingroup SS
    @{
*/

/**
    @name File context flags
    @{
*/
#define SS_EIM_CONTEXT                  1
#define SS_USER_CONTEXT                 2
/** @} */

/**
    @name Machine format flags
    @{
*/
#define SS_NUM_MTYPES                   3

/** @if DOX_IGNORE
    TJGC 25-Oct-1996
    Revert to the old V3.4 machine types for VMS/UNIX. These constants form
    part of the IMAN ITK and if they are changed, this will force a recompile
    of any customer ITK program that uses them.
@endif */

#define SS_WNT_MACHINE                  0
#define SS_VMS_MACHINE                  1
#define SS_UNIX_MACHINE                 2

#define SS_VALID_MTYPE(a) ( (a >= 0) && (a < SS_NUM_MTYPES) )

#ifdef VMS
    #define SS_MACHINE_TYPE             SS_VMS_MACHINE
#endif

#ifdef UNX
    #define SS_MACHINE_TYPE             SS_UNIX_MACHINE
#endif

#ifdef WNT
    #define SS_MACHINE_TYPE             SS_WNT_MACHINE
#endif

/** @} */

/**
    @name Network protocols
    @{
*/
#define SS_ANYPROTO                     0
#define SS_DECNET                       1
#define SS_TCPIP                        2
/** @} */

/**
    @name Process creation mode flags
    @{
*/
#define SS_BACKGROUND                   1
#define SS_FOREGROUND                   2
#define SS_DETACHED                     3
#define SS_DETACHED2                    4
#define SS_CHAINED                      5
/** @} */

/**
    @name Process termination status
    @{
*/

/** Process still running */
#define SS_NOTSTOPPED                   0

/** Process exited normally */
#define SS_EXITED                       1

/** Process exited because of a signal */
#define SS_SIGNALLED                    2

/** @} */

/**
    @name Command file exit status
    @{
*/
#ifdef VMS
    #define SS_EXIT_STAT_OK             1
#else
    #define SS_EXIT_STAT_OK             0
#endif
/** @} */

/**
    @name IPC creation mode flags
    @{
*/
#define SS_IPCCRT                       1
#define SS_IPCATT                       2
#define SS_IPCNET                       4
#define SS_IPCACCEPT                    8
/** @} */

/**
    @name IPC queue enabled/disabled flags
    @{
*/
#define SS_ENABLED                      1
#define SS_DISABLED                     2
/** @} */

/**
    @name Network ipc constants
    @{
*/
#define SS_NIPC_HEADER_LONGS            1
#define SS_NIPC_MAXMSGLEN               0x10000  /* 64 k */
/** @} */

/**
    @name File accessibility flags
    @{
*/
#define SS_NO_ACCESS                    16
#define SS_NO_EXIST                     07 /*  */
#define SS_READ                         04
#define SS_WRITE                        02
#define SS_EXECUTE                      01
#define SS_EXISTS                       00
/** @} */

/**
    @name IPC message wait flags
    @{
*/
#define SS_MSG_WAIT                     1
#define SS_MSG_NOWAIT                   2
#define SS_MSG_NOTIFY                   4
#define SS_MSG_NETHDR                   8
/** @} */

/**
    @name File systems
    @{
*/
#define SS_NATIVE                       0
#define SS_SERVER                       1
#define SS_UGFM                         2
/** @} */

/**
    @name File types
    @{
*/
#define SS_FILE                         1
#define SS_DIRECTORY                    2
/** @} */

/**
    @name Status of an eim file
    @{
*/
#define SS_NOFILE                       0x0
#define SS_OPEN                         0x1
#define SS_CLOSED                       0x2
#define SS_ERROR                        0x4
#define SS_DELETED                      0x8
#define SS_NODIR                        0x10
/** @} */

/**
    @name Read/write modes
    @{
*/
#define SS_RDONLY                       01
#define SS_WRONLY                       02
#define SS_RDWRITE                      03
#define SS_APPEND                       04
/** @} */

/**
    @name File protection mode for vms and unix
    @{
*/
#ifdef VMS
    #define SS_ALL_PERMISSIONS_DMODE    07777
    #define SS_DEF_FMODE                06644
    #define SS_DEF_DMODE                07755
    #define SS_NO_WORLD_ACCESS_FMODE    06640
    #define SS_NO_WORLD_ACCESS_DMODE    07750
    #define SS_SYS_BIT                  01000
#else
    #define SS_ALL_PERMISSIONS_DMODE    0777
    #define SS_DEF_FMODE                0644
    #define SS_DEF_DMODE                0755
    #define SS_NO_WORLD_ACCESS_FMODE    0640
    #define SS_NO_WORLD_ACCESS_DMODE    0750
    #define SS_SYS_BIT                  0
#endif
/** @} */

/**
    @name Binary/text modes
    @{
*/
#define SS_TEXT                         010000
#define SS_BINARY                       020000
#define SS_TRANSLATE                    040000
/** @} */

/** Modified for generic shell */
#define SS_OBJECT                       0

/**
    @name Data types for translatable files
    @{
*/
#define SS_VOID                         0
#define SS_CHAR                         1
#define SS_WCHAR                        2
#define SS_BYTE                         3
#define SS_SHORT                        4
#define SS_LONG                         5
#define SS_FLOAT                        6
#define SS_DOUBLE                       7
#define SS_NUM_TYPES                    8
/** @} */

/** Maximum message size */
#define SS_MAXMSGLEN                    1024

/** Maximum path length */
#define SS_MAXPATHLEN                   256

/** Maximum host length */
#define SS_MAXHOSTLEN                   80

/**
    Maximum number of characters that can be written to an imanfile
*/
#define SS_MAX_NO_CHAR                  4096

/** Buffer size to use when reading an imanfile */
#define SS_MAXLLEN                      (SS_MAX_NO_CHAR + 3)

/** Maximum number of files for a user */
#define SS_MAX_NUM_FILES                100

/** Size of pid in ascii form */
#define SS_MAXPIDSTR                    (SS_MAXPATHLEN + SS_MAXHOSTLEN + 2)

/** Size of user login name */
#define SS_USERLEN                      80

/** Maximum length of an environment variable */
#define SS_MAX_ENV_LEN                  8192

/** Logical to designate offset from gmt time zone */
#define GMT_ZONE                        "GMT_TIME_ZONE"

/**
    @name Arriving mail signal
    @{
*/
#ifdef UNX
    #define SS_SIGMAIL                  SIGUSR1
    #define SS_SIGCLD                   SIGCLD
#else
    #define SS_SIGCLD                   18
#endif
/** @} */

/**
    @name User usable signals
    @{
*/
#define SS_SIGHUP                       SIGHUP
#define SS_SIGINT                       SIGINT
#define SS_SIGILL                       SIGILL
#define SS_SIGTRAP                      SIGTRAP
#define SS_SIGFPE                       SIGFPE
#define SS_SIGBUS                       SIGBUS
#define SS_SIGSEGV                      SIGSEGV
#define SS_SIGTERM                      SIGTERM
#ifdef WNT
    #define SS_SIGQUIT                  SIGINT
    #define SS_SIGKILL                  SIGINT
#else
    #define SS_SIGQUIT                  SIGQUIT
    #define SS_SIGKILL                  SIGKILL
#endif
/** @} */

/**
    @name Windows NT Constants for SS_ChangeAcessRights
    @{
*/
#ifdef WNT
    #define SS_ACCESS_REPLACE_FOR_USER  (1)
    #define SS_ACCESS_ADD               (2)
    #define SS_ACCESS_REPLACE_ALL       (3)
#endif
/** @} */

/** @} */

#include <ss/libss_undef.h>

#endif
