/* Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright 2012.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software */

/** 
    @file 

    Define error codes used with Part and Manufacturing Information (PMI)

*/

#ifndef PMI0PMI_ERRORS_H
#define PMI0PMI_ERRORS_H

#ifndef EMH_CONST_H
    #include <common/emh_const.h>
#endif

/**
    @defgroup PMI0PMI_ERRORS Errors
    @ingroup PMI0PMI
    @{
*/

#define PMI0PMI_ERROR_BASE                                                          EMH_PMI0PMI_error_base

/** The primary or secondary object of the relation is not an Item Revision. */
#define PMI0PMI_primary_or_secondary_of_relation_not_itemrevision                   (PMI0PMI_ERROR_BASE + 1)

/** The primary and secondary objects are Item Revisions which belong to same Item. */
#define PMI0PMI_primary_and_secondary_revisions_of_same_item                        (PMI0PMI_ERROR_BASE + 2)

/** A "Part and Manufacturing Information (PMI) Authoring" relation cannot be created, because either the primary Item Revision or its siblings, are already associated by a "PMI Definition" relation as primary.
 */
#define PMI0PMI_no_pmiauthoring_primary_is_already_primary_in_pmidefinition         (PMI0PMI_ERROR_BASE + 3)

/** A "Part and Manufacturing Information (PMI) Authoring" relation cannot be created, because either the primary Item Revision, or its siblings, are already associated by a "PMI Authoring" relation as secondary. */
#define PMI0PMI_no_pmiauthoring_primary_is_already_secondary_in_pmiauthoring         (PMI0PMI_ERROR_BASE + 4)

/** A "Part and Manufacturing Information (PMI) Authoring" relation cannot be created, because primary Item Revision has secondary Item Revisions belonging to a different Item family. */
#define PMI0PMI_secondary_in_pmiauthoring_not_of_same_item_family                    (PMI0PMI_ERROR_BASE + 5)

/** A "Part and Manufacturing Information (PMI) Authoring" relation cannot be created, because either the secondary Item Revision, or its siblings, are already associated by a "PMI Authoring" relation as primary. */
#define PMI0PMI_no_pmiauthoring_secondary_is_already_primary_in_pmiauthoring         (PMI0PMI_ERROR_BASE + 6)

/** A "Part and Manufacturing Information (PMI) Authoring" relation cannot be created, because secondary Item Revision has primary Item Revisions belonging to a different Item family. */
#define PMI0PMI_primary_in_pmiauthoring_not_of_same_item_family                      (PMI0PMI_ERROR_BASE + 7)

/** A "Part and Manufacturing Information (PMI) Authoring" relation cannot be created, because either the secondary Item Revision, or its siblings, are already associated by a "PMI Definition" relation as secondary. */
#define PMI0PMI_no_pmiauthoring_secondary_is_already_secondary_in_pmidefinition      (PMI0PMI_ERROR_BASE + 8)

/** A "Part and Manufacturing Information (PMI) Authoring" relation cannot be created, because either the secondary Item Revision, or its siblings, are already associated by a "PMI Definition" relation as primary. */
#define PMI0PMI_no_pmiauthoring_secondary_is_already_primary_in_pmidefinition        (PMI0PMI_ERROR_BASE + 9)

/** A "Part and Manufacturing Information (PMI) Definition" relation cannot be created, because either the primary Item Revision, or its siblings, are already associated by a "PMI Authoring" relation as primary. */
#define PMI0PMI_no_pmidefinition_primary_is_already_primary_in_pmiauthoring           (PMI0PMI_ERROR_BASE + 10)

/** A "Part and Manufacturing Information (PMI) Definition" relation cannot be created, because either the secondary Item Revision, or its siblings, are already associated by a "PMI Definition" relation as primary. */
#define PMI0PMI_no_pmidefinition_secondary_is_already_primary_in_pmidefinition        (PMI0PMI_ERROR_BASE + 11)

/** A "Part and Manufacturing Information (PMI) Definition" relation cannot be created, because either the primary Item Revision, or its siblings, are already associated by a "PMI Definition" relation as secondary. */
#define PMI0PMI_no_pmidefinition_primary_is_already_secondary_in_pmidefinition        (PMI0PMI_ERROR_BASE + 12)

/** A "Part and Manufacturing Information (PMI) Definition" relation cannot be created, because either the secondary Item Revision, or its siblings, are already associated by a "PMI Authoring" relation as secondary. */
#define PMI0PMI_no_pmidefinition_secondary_is_already_secondary_in_pmiauthoring       (PMI0PMI_ERROR_BASE + 13)

/** A "Part and Manufacturing Information (PMI) Definition" relation cannot be created, because either the primary Item Revision, or its siblings, are already associated by a "PMI Authoring" relation as secondary. */
#define PMI0PMI_no_pmidefinition_primary_is_already_secondary_in_pmiauthoring         (PMI0PMI_ERROR_BASE + 14)

/** @} */
#endif
