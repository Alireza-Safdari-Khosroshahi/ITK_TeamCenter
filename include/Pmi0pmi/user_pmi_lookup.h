//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2012.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software

/** 
    @file 

    This file contains the definition of user exits for Part and Manufacturing Information (PMI) lookup.

*/
#ifndef USER_PMI_LOOKUP_H
#define USER_PMI_LOOKUP_H

#include <unidefs.h>                /* for TAG definition */
#include <Pmi0pmi/user_pmi_lookup_datatypes.h>

#include <Pmi0pmi/libpmi0pmi_exports.h>
/**
    @defgroup PMI0PMI Part and Manufacturing Information (PMI)
    This header contains the definition of user exits API that would be invoked during the PMI JT file lookup.
    @{
*/

#ifdef __cplusplus
    extern "C"{
#endif

/** 
     Custom method with the given definition can be used to register as base behavior for BMF_PMI0_BOMLINE_preferred_revisions_for_pmilookup message. 
     By registering and implementing base behavior, the business logic that is needed to select the preferred PMI when multiple PMI of same Item are 
     associated with a Product can be achieved.
     Note: This is provided here so that it serves as API prototype reference for the implementer to
           implement Part and Manufacturing Information (PMI) lookup user exit.  
     
     An error ITK_invalid_name (26008) will be returned if the function that is to be invoked as user exit has an invalid name.
 */
extern PMI0PMI_API int PMI0PMI_user_preferred_revisions_for_pmilookup
( 
  tag_t                                         relation_type_tag,  /**< (I) Tag of the relation being traversed. */ 
  int                                           n_bomlines,         /**< (I) Number of BOMLines */
  const PMI0PMI_bomline_traversed_pmilookup_objs_t *traversed_pmis, /**< (I) A list of structures that associates the 
                                                                             bom line and the number of primary or secondary 
                                                                             objects that were traversed during the PMI lookup */
  int                                           *n_preferred_pmis,  /**< (O) Number of bom lines for which the preferred PMIs was determined */
  PMI0PMI_bomline_preferred_pmilookup_obj_t        **preferred_pmis /**< (OF) n_preferred_pmis An array of structures that associates the bom line and the preferred PMI */
);

/** 
     Custom method with the given definition can be used to register as base behavior for BMF_PMI0_BOMLINE_filter_lines_for_pmilookup message. 
     By registering and implementing base behavior, the business logic that is needed to filter the BOMLines on which the PMI lookup has to
     be performed can be acheived. If all BOMLines would not have PMI, then filtering them using this user exit will improve performance.
     Note: This is provided here so that it serves as API prototype reference for the implementer to
           implement  Part and Manufacturing Information (PMI) lookup user exit.  

     An error ITK_invalid_name (26008) will be returned if the function that is to be invoked as user exit has an invalid name.
 */
extern PMI0PMI_API int PMI0PMI_user_filter_lines_for_pmilookup
( 
  int            n_bomlines,              /**< (I) Number of BOMLines */
  const tag_t    *bomlines,               /**< (I) BOMLines on which to perform the PMI look */
  int            *n_filtered_bomlines,    /**< (O) Filter number of BOMLines to consider for PMI lookup */
  tag_t          **filtered_bomlines      /**< (OF) n_filtered_bomlines The array of BOMLines for which the PMI look need to be performed */
);

/** @} */
#ifdef __cplusplus
}
#endif

#include <Pmi0pmi/libpmi0pmi_undef.h>

#endif
