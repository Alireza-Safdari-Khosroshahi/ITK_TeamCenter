/* 
   @<COPYRIGHT_START>@
   ===============================================
   Copyright 2006 UGS Corp. All Rights Reserved.
   ===============================================
   @<COPYRIGHT_END>@
*/

/** 
    @file 

    Defines error codes used by Manage dRelation.
*/


#ifndef MANAGEDRELATION_ERRORS_H
#define MANAGEDRELATION_ERRORS_H

#include <common/emh_const.h>


/**
    @defgroup MANAGED_RELATION_ERRORS Managed Relation Errors
    @{
*/

/** Invalid Source Tag */
#define MRel_invalid_source_tag          (EMH_MANAGEDRELATION_error_base + 1) 

/** Invalid Target Tag */
#define MRel_invalid_target_tag          (EMH_MANAGEDRELATION_error_base + 2) 

/** Failed to initialized ManagedRelation Class */
#define MRel_initialization_failure      (EMH_MANAGEDRELATION_error_base + 3) 


/** @} */

#endif
