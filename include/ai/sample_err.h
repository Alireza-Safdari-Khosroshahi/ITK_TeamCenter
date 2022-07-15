/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*  */

#ifndef SAMPLE_ERR_H_INCLUDED
#define SAMPLE_ERR_H_INCLUDED

#include <pom/pom/pom_errors.h>
#include <base_utils/Mem.h>
#include <tc/tc_startup.h>
#include <tc/emh.h>
#include <tc/tc_util.h>

#define CALL(x) {               \
  int stat;                     \
  char *err_string;             \
  if( (stat = (x)) != ITK_ok)   \
  {                             \
    EMH_ask_error_text (stat, &err_string);              \
    TC_printf ("ERROR: %d ERROR MSG: %s.\n", stat, err_string);        \
    printf ("Function: %s FILE: %s LINE: %d\n",#x, __FILE__, __LINE__);             \
    MEM_free (err_string);   \
    return (stat);          \
  }                         \
}

#define DO(x) {             \
  int stat;                     \
  char *err_string;             \
  if( (stat = (x)) != POM_ok)   \
  {                             \
    EMH_ask_error_text (stat, &err_string);              \
    TC_printf ("ERROR: %d ERROR MSG: %s.\n", stat, err_string);        \
    printf ("Function: %s FILE: %s LINE: %d\n",#x, __FILE__, __LINE__);             \
    MEM_free (err_string);   \
  }                         \
}

#define CALLRNULL(x) {              \
  int stat;                     \
  char *err_string;             \
  if( (stat = (x)) != ITK_ok)   \
  {                             \
    EMH_ask_error_text (stat, &err_string);              \
    TC_printf ("ERROR: %d ERROR MSG: %s.\n", stat, err_string);        \
    printf ("Function: %s FILE: %s LINE: %d\n",#x, __FILE__, __LINE__);             \
    MEM_free (err_string);   \
    return ((char *)NULL);  \
  }                         \
}

#endif
