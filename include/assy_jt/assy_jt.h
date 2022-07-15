#ifndef INCLUDED_ASSY_JT_H
#define INCLUDED_ASSY_JT_H

#include <unidefs.h>

#include <assy_jt/libassy_jt_exports.h>

#ifdef __cplusplus
    extern "C"{
#endif

extern ASSY_JT_API int ASSY_JT_create(
    tag_t     sc_tag,                 /* <I> */
    tag_t    item,                   /* <I> */
    tag_t    item_rev,               /* <I> */
    tag_t    bom_view ,              /* <I> */
    tag_t    bom_view_rev,           /* <I> */
    tag_t    rev_rule,               /* <I> */
    tag_t    var_rule,               /* <I> */
    logical  monolithic_jt ,         /* <I> */
    logical  continue_on_failure,    /* <I> */
    logical  process_interim_nodes,  /* <I> */
    char*    target_loc,             /* <I> */
    char*    tmode ,                 /* <I> */
    int*     num_failed_nodes ,      /* <O> */
    int**    failed_codes ,          /* <OF>*/
    char**   jt_file_name            /* <OF>*/
    );

/**
    Creates a jt file (assembly or monolithic) by traversing the structure given by a structure context,
    or item or itemrevision or bomview or bomviewrevision. Any one of these needs
    to be suplied (and at most one only). The rev_rule is used if any input root object
    is provided other than structure context.     
*/
extern ASSY_JT_API int ASSY_JT_create2(
    tag_t     sc_tag,                 /* <I> structure context object  to start traversal*/
    tag_t    item,                   /* <I> root item to start traversal */
    tag_t    item_rev,               /* <I> root itemrevision to start traversal*/
    tag_t    bom_view ,              /* <I> root bomview to start traversal*/
    tag_t    bom_view_rev,           /* <I> root bomviewrevision to start traversal*/
    tag_t    rev_rule,               /* <I> revision rule to be used for configuration*/
    tag_t    var_rule,               /* <I> variant rule (classic) to be used*/
    logical  monolithic_jt ,         /* <I> whether assembly jt(false) or monolithic jt (true)*/
    logical  continue_on_failure,    /* <I> continue on any failures.*/
    logical  process_interim_nodes,  /* <I> process any jt datasets on intermediate(assembly) nodes*/
    const char*    target_loc,             /* <I> target location. Must be a folder that exists*/
    const char*    tmode ,                 /* <I> optional transfermode name. If not supplied an internalone is used.*/
    const char*    JtWithNameToIgnoreOnExportedTopRev,       /* <I> ignore dataset with specified name on root selected for export. In case 
                                           the monolithic jt (already generated), should not be processed set this field to the name of that dataset.*/
    int*     num_failed_nodes ,      /* <O> any failed node count*/
    int**    failed_codes ,          /* <OF> array of failed codes*/
    char**   jt_file_name            /* <OF> name of the jt_file generated*/
    );

#ifdef __cplusplus
}
#endif

#include <assy_jt/libassy_jt_undef.h>

#endif
