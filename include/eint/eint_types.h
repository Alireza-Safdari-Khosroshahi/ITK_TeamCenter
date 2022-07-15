/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*  */

#ifndef EINT_TYPES_H
#define EINT_TYPES_H

#include <eint/libeint_exports.h>

/**
    @defgroup EINT_TYPES Types
    @ingroup EINT
    @{
*/

#define EINT_datasource_name_size_c 32
#define EINT_hostname_size_c        32
#define EINT_url_size_c             256
#define EINT_adapter_name_size_c    32
#define EINT_username_size_c        32
#define EINT_password_size_c        32
#define EINT_tablename_size_c       32
#define EINT_attrname_size_c        32
#define EINT_procedure_size_c       128
#define EINT_statement_size_c       256

#define EINT_integer_type           0
#define EINT_string_type            1
#define EINT_date_type              2

typedef enum EINT_account_type_e
{
    EINT_PROXY_USER,    /**< Use the proxy account username and password to login */
    EINT_LOGIN_USER,    /**< Use Teamcenter Engineering account username and password to login */
    EINT_PROMPT_USER    /**< Prompt the user for username and password */
} EINT_account_type_t;

#define EINT_GRANTED_ACCESSOR       "EINT_granted_accessor"
#define EINT_OBJECT_MAPPING         "EINT_object_mapping"
#define EINT_SAVED_QUERY            "EINT_saved_query"

/** @} */

#include <eint/libeint_undef.h>
#endif
