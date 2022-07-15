/*==============================================================================
                Copyright (c) 2019 Siemens PLM
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*  */

#ifndef FCLASSES_CMP_ACCESSORS_H
#define FCLASSES_CMP_ACCESSORS_H

#include <fclasses/libfclasses_exports.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
    @ingroup CMP Compare (CMP)

    Provides access to symbols defined in @file cmp.h.
    <br/>Using the accessor is key to enable delay loading of this library. 
    @{
*/
/** 
    Returns the value of #CMP_std_descriptor_P_id_seq_A_rev_qty_name.
 */
extern FCLASSES_API const char* CMP_get_std_descriptor_p_id_seq_a_rev_qty_name();

/** 
    Returns the value of #CMP_std_descriptor_P_id_A_rev_qty_name.
 */
extern FCLASSES_API const char* CMP_get_std_descriptor_p_id_a_rev_qty_name();

/** 
    Returns the value of #CMP_std_descriptor_appr_compare_name.
 */
extern FCLASSES_API const char* CMP_get_std_descriptor_appr_compare_name();

/** 
    Returns the value of #CMP_std_descriptor_LBOM_compare_name.
 */
extern FCLASSES_API const char* CMP_get_std_descriptor_lbom_compare_name();

/** 
    Returns the value of #CMP_std_descriptor_LBOM_withocc_compare_name.
 */
extern FCLASSES_API const char* CMP_get_std_descriptor_lbom_withocc_compare_name();

/** @} */

#ifdef __cplusplus
}
#endif

#include <fclasses/libfclasses_undef.h>
#endif
