/*==============================================================================
                Copyright (c) 2006 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    req_msg.h

*/

/*  */

#ifndef REQ_MSG_H
#define REQ_MSG_H

#include <req/libreq_exports.h>

/**
    @defgroup REQ_MSG Teamcenter Requirements Messages
    @ingroup Teamcenter
    @{
*/

/**
    Creates a new FullText instance.

    @param const char* object_name
    @param const char* object_desc
    @param tag_t*      new_fulltext

*/
#define FULLTEXT_create_msg     "FULLTEXT_create"


/**
    Set FullText instance content from a file.

    @param tag_t fulltext_tag
    @param const char* file_name

*/
#define FULLTEXT_set_content_from_file_msg     "FULLTEXT_set_content_from_file"

/**
    Get FullText instance content as a file.

    @param tag_t fulltext_tag
    @param const char** file_name

*/
#define FULLTEXT_ask_content_file_msg     "FULLTEXT_ask_content_file"

/** @} */

#include <req/libreq_undef.h>
#endif
