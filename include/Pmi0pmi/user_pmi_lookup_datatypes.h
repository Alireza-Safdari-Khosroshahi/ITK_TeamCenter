//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2012.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software

/** 
    @file 

    This file contains the definition of user exits data types for Part and Manufacturing Information (PMI) lookup.

*/
#ifndef USER_PMI_LOOKUP_DATATYPES_H
#define USER_PMI_LOOKUP_DATATYPES_H

#include <unidefs.h>                /* for TAG definition */

#include <Pmi0pmi/libpmi0pmi_exports.h>
/**
    @ingroup PMI0PMI
    @{
*/

/**
    Structure which holds information about the BOMLine for which the Part and Manufacturing Information (PMI) is looked for, the intermediate Item Revision at which the lookup traversal is at and the Part and Manufacturing Information (PMI) Item Revisions from which the preferred one needs to be selected. 
    This structure is used in #PMI0PMI_user_preferred_revisions_for_pmilookup as input which lists the Item Revisions for a given BOMLine from which the preferred Item Revision is to chosen.
 */

typedef struct PMI0PMI_bomline_traversed_pmilookup_objs_s
{
    tag_t         bomline;          /**< The BOMLine that is being traversed */
    tag_t         source_object;    /**< The source object in the relation traversal path  */
    int           n_traversed_objs; /**< Number of associated Item Revisions during grm traversal */
    tag_t*        traversed_objs;   /**< The associated Item Revisions during grm traversal */
} PMI0PMI_bomline_traversed_pmilookup_objs_t;

/**
    Structure which holds information about the BOMLine and its preferred  Part and Manufacturing Information (PMI) Item Revision. 
    This structure is used in #PMI0PMI_user_preferred_revisions_for_pmilookup as output.
 */

typedef struct PMI0PMI_bomline_preferred_pmilookup_obj_s
{
    tag_t         bomline;       /**< The BOMLine that is being traversed */
    tag_t         preferred_obj; /**< The preferred Item Revision to lookup Part and Manufacturing Information (PMI) on */
} PMI0PMI_bomline_preferred_pmilookup_obj_t;

/** @} */

#include <Pmi0pmi/libpmi0pmi_undef.h>

#endif
