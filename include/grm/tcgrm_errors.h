/*=============================================================================
           Copyright (c) 1994 Electronic Data Systems Corporation
                   Unpublished - All rights reserved

   THIS PROGRAM IS AN UNPUBLISHED WORK FULLY PROTECTED BY THE UNITED STATES
  COPYRIGHT LAWS AND IS CONSIDERED A TRADE SECRET BELONGING TO THE COPYRIGHT
                                   HOLDER.
===============================================================================
H  File description:

    This file contains all the query error numbers.  It was originally named
    as query_errors.h  It is now qry_errors.h so that it is consistent
    with the module naming convention.

    File   : grm_errors.h
    Module : grm
===============================================================================
H:::  History:
 date       name        description of change
13-Jul-2001  Ziv Israeli             Created
19-Jul-2001  Ziv Israeli             EMH_GRM_error_base -> EMH_TCGRM_error_base
13-Sep-2001  Ziv Israeli             Removing EMH_TCGRM_error_base + 2
16-Nov-2001  Ziv Israeli             GRM_no_frozen_addonly_allowed
04-Dec-2001  Ziv Israeli             Merged from israeli_v80_grm_new branch
06-Aug-2002  Aaron Ruckman           Split libtc.dll project
05-Sep-2002  Aaron Ruckman           Update headers as part of dll splittc project
22-Nov-2002  Tim Baverstock          Normalise inclusion
13-Feb-2006  Johann Chemin-Danielson  de-Imanization
$HISTORY$
H---=========================================================================*/

#ifndef TCGRM_ERRORS_H
#define TCGRM_ERRORS_H

#ifndef EMH_CONST_H
#include <common/emh_const.h>
#endif

#include <grm/libgrm_exports.h>

/** The creation of the Generic Relationship Management (GRM) Relation has failed. */
#define GRM_no_create                          (EMH_TCGRM_error_base + 1)

/** A null primary object is not allowed. */
#define GRM_null_primary_not_allowed           (EMH_TCGRM_error_base + 3)

/** A null secondary object is not allowed. */
#define GRM_null_secondary_not_allowed         (EMH_TCGRM_error_base + 4)

/** A negative cardinality is not allowed. */
#define GRM_negative_cardinality_not_allowed   (EMH_TCGRM_error_base + 5)

/** More than one constraint rule was found between the primary "%1$" and the secondary "%2$" for the relation "%3$". */
#define GRM_more_than_one_const_instance       (EMH_TCGRM_error_base + 6)

/** The Relation creation has failed due to some constraints. Please refer to the syslog file for more information. */
#define GRM_constraints_failed_creation        (EMH_TCGRM_error_base + 7)

/** The Relation deletion has failed due to some constraints. Please refer to the syslog file for more information. */
#define GRM_constraints_failed_deletion        (EMH_TCGRM_error_base + 8)

/** No additional objects of type "%2$" can be attached with a relation "%3$" 
under the object "%4$" of type "%5$", because this would exceed the set limit
for the secondary objects. Please refer to the rule for "%1$, %2$, %3$". */
#define GRM_exceeding_secondary_cardinality    (EMH_TCGRM_error_base + 9)

/** No additional objects of type "%2$" can be attached with a relation "%3$" 
under the object "%4$" of type "%1$", because this would exceed the set limit 
for the primary object. Please refer to the rule for "%1$, %2$, %3$". */
#define GRM_exceeding_primary_cardinality      (EMH_TCGRM_error_base + 10)

/** Relationships can only be added, not removed. Please refer to the following rules: %1$, %2$, %3$. */
#define GRM_add_only_relationship              (EMH_TCGRM_error_base + 11)

/** The Relationship is frozen, and addition or removal is therefore not allowed. 
Please refer to the following rules: %1$, %2$, %3$. */
#define GRM_frozen_relationship                (EMH_TCGRM_error_base + 12)

/** The relation of type "%1$" between "%2$" of type "%3$" and "%4$" cannot be created, because the current user does not have write access to modify "%2$". */
#define GRM_no_write_permission_for_adding     (EMH_TCGRM_error_base + 13)

/** The relation of type "%1$" between "%2$" of type "%3$" and "%4$" cannot be deleted, because the current user does not have write access to delete "%2$". */
#define GRM_no_write_permission_for_removal    (EMH_TCGRM_error_base + 14)

/** No constraint exists between the primary "%1$" and the secondary "%2$" with the relation of type "%3$". */
#define GRM_no_constraint_was_established      (EMH_TCGRM_error_base + 15)

/** The secured entries in the Generic Relationship Management (GRM) Relation "%1$" cannot be updated or deleted. */
#define GRM_no_secured_manipulation            (EMH_TCGRM_error_base + 16)

/** The Generic Relationship Management (GRM) relation cannot be created, because the following entry is invalid: %1$. */
#define GRM_xml_node_name_incorrect            (EMH_TCGRM_error_base + 17)

/** An internal error has occurred in the Generic Relationship Management (GRM) module. 
Please refer to the syslog file for more information. */
#define GRM_describe_RULE_val_t                (EMH_TCGRM_error_base + 18)

/** Only adding relationships is allowed. Please refer to the following rules: %1$, %2$, %3$. */
#define GRM_no_frozen_addonly_allowed          (EMH_TCGRM_error_base + 19)

/** The relationship of type "%3$" is not supported between objects of types "%1$" and "%2$". */
#define GRM_relationship_not_allowed           (EMH_TCGRM_error_base + 20)

/** Any relationship between objects of types "%1$" and "%2$" is not supported. */
#define GRM_relationship_not_allowed_match_all  (EMH_TCGRM_error_base + 21)

#include <grm/libgrm_undef.h>
#endif
