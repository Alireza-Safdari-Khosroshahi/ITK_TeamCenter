// @<COPYRIGHT_START>@
// ===============================================
// Copyright 2006 UGS Corp. All Rights Reserved.
// ===============================================
// @<COPYRIGHT_END>@




/** 
    @file 

    This header file declares functions for manipulating IP (Intelectual Property) and Gov
    (Governmental) classification and clearance levels.

*/

#ifndef ADA_H
#define ADA_H

#include <unidefs.h>
#include <tc/tc_startup.h>
#include <sa/libsa_exports.h>

/**
    @defgroup ADA Authorized Data Access
    @{
*/

#ifdef __cplusplus
     extern "C"{
#endif

#define ADA_IP_PREF "IP_level_list_ordering"
#define ADA_ITAR_PREF "ITAR_level_list_ordering"

extern SA_API int ADA_compare_ip_classification_levels(
                                                    const char* c1,                  /* <I> */
                                                    const char* c2,                  /* <I> */
                                                    int *answer                      /* <O> */
                                                   );

extern SA_API int ADA_merge_ip_classification_levels(
                                                    const char* c1,                  /* <I> */
                                                    const char* c2,                  /* <I> */
                                                    char **result                    /* <OF> */
                                                   );

extern SA_API int ADA_test_ip_classification_level(
                                                   const char* expression,          /* <I> */
                                                   const char* classification,      /* <I> */
                                                   logical *answer                  /* <O> */
                                                   );

extern SA_API void ADA_list_ip_classification_levels(
                                                  int *argc,                   /* <O>  */
                                                  char ***argv                 /* <OF> */
                                                 );

extern SA_API int ADA_test_ip_clearance(
                                        tag_t object,                                /* <I> */
                                        const char *expression,                      /* <I> */
                                        logical *verdict                             /* <O> */
                                        );

extern SA_API int ADA_compare_gov_classification_levels(
                                                    const char* c1,                  /* <I> */
                                                    const char* c2,                  /* <I> */
                                                    int *answer                      /* <O> */
                                                   );

extern SA_API int ADA_merge_gov_classification_levels(
                                                    const char* c1,                  /* <I> */
                                                    const char* c2,                  /* <I> */
                                                    char **result                    /* <OF> */
                                                   );

extern SA_API int ADA_test_gov_classification_level(
                                                   const char* expression,          /* <I> */
                                                   const char* classification,      /* <I> */
                                                   logical *answer                  /* <O> */
                                                   );

extern SA_API void ADA_list_gov_classification_levels(
                                                  int *argc,                   /* <O>  */
                                                  char ***argv                 /* <OF> */
                                                 );

extern SA_API int ADA_test_gov_clearance(
                                        tag_t object,                                /* <I> */
                                        const char *expression,                      /* <I> */
                                        logical *verdict                             /* <O> */
                                        );

/** @} */

#ifdef __cplusplus
}
#endif

#include <sa/libsa_undef.h>

#endif

