/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This file contains the interface to identifier errors.
*/

/*  */

#ifndef IDFR_ERRORS_H
#define IDFR_ERRORS_H

/**
    @defgroup IDFR_ERRORS IDFR Errors
    @ingroup IDFR
    @{
*/

/** Installation Error.  Identifier Class Not Initialized. */
#define IDENTIFIER_initialization_error         (EMH_IDENTIFIER_error_base + 1)

/** Installation Error.  IMAN_aliasid relation not found. */
#define IDENTIFIER_relation_not_found           (EMH_IDENTIFIER_error_base + 2)

/** Invalid tag as input. */
#define IDENTIFIER_invalid_tag                  (EMH_IDENTIFIER_error_base + 3)

/** Identifier type not found. */
#define IDENTIFIER_type_not_found               (EMH_IDENTIFIER_error_base + 4)

/** Unable to create Identifier. */
#define IDENTIFIER_unable_to_create             (EMH_IDENTIFIER_error_base + 5)

/** Identifier's id is null. */
#define IDENTIFIER_null_id                      (EMH_IDENTIFIER_error_base + 6)

/** Identifier's id is invalid. */
#define IDENTIFIER_invalid_id                   (EMH_IDENTIFIER_error_base + 7)

/** Identifier's idcontext is null. */
#define IDENTIFIER_null_idcontext               (EMH_IDENTIFIER_error_base + 8)

/** Identifier's idcontext is invalid. */
#define IDENTIFIER_invalid_idcontext            (EMH_IDENTIFIER_error_base + 9)

/** Identifier's id is invalid. */
#define IDENTIFIER_property_protected           (EMH_IDENTIFIER_error_base + 10)

/** Identifier's property is protected.  You cannot change it. */
#define IDENTIFIER_invalid_idfbl_tag            (EMH_IDENTIFIER_error_base + 11)

/** Two alternates set as display default. */
#define IDENTIFIER_duplicate_dispdefault        (EMH_IDENTIFIER_error_base + 12)

/** No access to Identifiable. */
#define IDENTIFIER_idfbl_noaccess               (EMH_IDENTIFIER_error_base + 13)

/** No write access to Identifiable. */
#define IDENTIFIER_idfbl_not_modifiable         (EMH_IDENTIFIER_error_base + 14)

/** Save supplemental identifier before saving master identifier. */
#define IDENTIFIER_save_suppl_id                (EMH_IDENTIFIER_error_base + 15)

/** Master identifier without single supplemental identifier. */
#define IDENTIFIER_master_nosuppl               (EMH_IDENTIFIER_error_base + 16)

/** You cannot delete the identifier at ItemRevision.Instead delete the corresponding Identifier at the Item itself. */
#define IDENTIFIER_delete_last_suppl            (EMH_IDENTIFIER_error_base + 17)

/** No access to supplemental identifier. */
#define IDENTIFIER_suppl_noaccess               (EMH_IDENTIFIER_error_base + 18)

/** Identifier's supplemental context is invalid. */
#define IDENTIFIER_invalid_supplcontext         (EMH_IDENTIFIER_error_base + 19)

/** Duplicate id. */
#define IDENTIFIER_duplicate_id                 (EMH_IDENTIFIER_error_base + 20)

/** Business rule for this combination of identifier type, identifiable type, and idcontext does not exist. */
#define IDENTIFIER_invalid_combination          (EMH_IDENTIFIER_error_base + 21)

/** There may be no naming rule enabled for one or both of the following; Identifier or Identifier Revision.
Additionally, you will not be able to use the Assign button if the naming rule does not have a counter.
Please contact your Business Modeler Administrator to check naming rules for accuracy. */
#define IDENTIFIER_no_autogen_id                (EMH_IDENTIFIER_error_base + 22)

/** Required export data for an identifier does not exist in import file. */
#define IDENTIFIER_missing_exportinfo           (EMH_IDENTIFIER_error_base + 23)

/** IdContext with the same name not found in importing site. */
#define IDENTIFIER_idcontext_notfound           (EMH_IDENTIFIER_error_base + 24)

/** Identifier with the same class/type combination not found in importing site. */
#define IDENTIFIER_invalid_class                (EMH_IDENTIFIER_error_base + 25)

/** Failed business rule validation of Identifier and Identifiable cardinality. */
#define IDENTIFIER_invalid_cardinality          (EMH_IDENTIFIER_error_base + 26)

/** Invalid Identifier Uid tag. */
#define IDENTIFIER_invalid_uid_tag              (EMH_IDENTIFIER_error_base + 27)

/** The operation has failed due to an invalid input. Objects of type Item or Item Revision are the valid inputs. */
#define IDENTIFIER_invalid_identifiable_type    (EMH_IDENTIFIER_error_base + 28)

/** @} */

#endif
