/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Header file to define types for eim system services
*/

/*  */

#ifndef SS_TYPES_H
#define SS_TYPES_H

#include <unidefs.h>
#include <ss/ss_const.h>
#include <stdarg.h>

#ifdef WNT
    #define NOMINMAX
    #include <windows.h>
    #undef NOMINMAX
#endif
#include <ss/libss_exports.h>

/**
    @defgroup SS_TYPES Types
    @ingroup SS
    @{
*/

/** Pipe handle */
#ifdef WNT
    typedef HANDLE SS_pipe_handle_t;
#else
    typedef int SS_pipe_handle_t;
#endif

/**
    File descriptor entry
*/
typedef struct {
        int fd;                   /**< The file descriptor on a particular machine */
        int context;              /**< Context of the file - USER vs. EIM */
        int file_type;            /**< File/directory flag */
        int format;               /**< Type of file - binary or text */
        int mode;                 /**< Protection mode */
        int machine_format;       /**< Machine this came from */
        int translate;            /**< Translation flag #SS_TRANSLATE or 0 */
        char path[SS_MAXPATHLEN]; /**< The path name for the file */
        char node[SS_MAXHOSTLEN]; /**< the node name for remote node */
}  SS_file_descriptor_t;

/**
    File descriptor
*/
typedef int SS_fd;

/**
    Directory descriptor
*/
typedef int SS_dir;

/**
    Pid descriptor
*/
typedef struct {
    #ifdef WNT
        PROCESS_INFORMATION procinfo;   /**< Misc information needed on WNT */
    #endif
    int pid;                            /**< The pid on a particular machine */
    char node[SS_MAXHOSTLEN];           /**< The node name for remote node */
}  SS_pid;

/**
    Key definition
*/
typedef struct {
    long int id;              /**< Unique number to identify entity */
    char node[SS_MAXHOSTLEN]; /**< The node name for remote node */
}  SS_key;

/**
    Network key definition
*/
typedef struct {
    SS_key key;               /**< Regular key */
    int     proto;            /**< Network protocol */
    int     service;          /**< Network port number */
    long int id;              /**< Server/client indicator */
}  SS_net_key;

/**
    File status block
*/
typedef struct {
    int oid;                  /**< The owner id */
    int gid;                  /**< The group id */
    int pmode;                /**< The protection mode */
    int ftype;                /**< The file type (file or directory) */
    int crd;                  /**< The creation date */
    int mdd;                  /**< The date last modified */
    int fmt;                  /**< The file format ( #SS_TEXT or #SS_BINARY ) */
    unsigned long int size;   /**< The file size */
    char path[SS_MAXPATHLEN]; /**< Full path name of file or dir */
}  SS_file_status;

/**
    File spec
*/
typedef struct {
    int len;
    char buf[SS_MAXPATHLEN];
}  SS_fspec_t;

typedef int (*SS_function_ptr_t)(
    void*,
    int,
    char**,
    va_list args
    );

/** @} */

#include <ss/libss_undef.h>
#endif
