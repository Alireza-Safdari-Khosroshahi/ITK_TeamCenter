/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Error codes returned by the AOM ITK module.
*/

/*  */

#ifndef AOM_ERRORS_H
#define AOM_ERRORS_H

#include <common/emh_const.h>
#include <tccore/libtccore_exports.h>

/**
    @defgroup AOM_ERRORS Errors
    @ingroup AOM
    @{
*/

/** An internal error has occurred in the AOM Module. Please report it to your system administrator.*/
#define AOM_internal_error                              (EMH_AOM_error_base + 0)

/** The object is locked for modify in another session. */
#define AOM_inst_in_use                                 (EMH_AOM_error_base + 1)

/** The object is frozen. */
#define AOM_inst_frozen                                 (EMH_AOM_error_base + 2)

/** The current user does not have write access to the object "%1$". */
#define AOM_inst_write_protected                        (EMH_AOM_error_base + 3)

/** The object has been checked-out by someone else. */
#define AOM_inst_checked_out_against                    (EMH_AOM_error_base + 4)

/** The current user does not have read access to the object "%1$". */
#define AOM_inst_read_protected                         (EMH_AOM_error_base + 5)

/** Read protection failed. */
#define AOM_read_protection_failed                      (EMH_AOM_error_base + 6)

/** The operation has failed on the object "%1$". */
#define AOM_where_refd_on_delete_a                      (EMH_AOM_error_base + 7)

/** The object is referenced by "%1$". Please report it to your system administrator. */
#define AOM_where_refd_on_delete_b                      (EMH_AOM_error_base + 8)

/** Locked by "%1$" on node "%2$" in a session started at "%3$".*/
#define AOM_locked_by                                   (EMH_AOM_error_base + 9)

/** The current user does not have delete access to the object "%1$". */
#define AOM_inst_delete_protected                       (EMH_AOM_error_base + 10)

/** The current user does not have copy access to the object "%1$". */
#define AOM_inst_copy_protected                         (EMH_AOM_error_base + 11)

/** The object cannot be loaded as it is archived.*/
#define AOM_inst_archived                               (EMH_AOM_error_base + 12)

/** The current user cannot change the last modification date of a replica of the object "%1$".*/
#define AOM_cannot_touch_replica                        (EMH_AOM_error_base + 13)

/** The current user cannot change the last modification date of the archived object "%1$".*/
#define AOM_cannot_touch_archived                       (EMH_AOM_error_base + 14)

/** Given child is not contained in the given parent.*/
#define AOM_not_in_parent                               (EMH_AOM_error_base + 15)

/** invalid AOM_prop_index_p_t.*/
#define AOM_invalid_prop_index                          (EMH_AOM_error_base + 16)

/** The current user "%1$" has no write access to the object "%2$". */
#define AOM_user_has_no_write_access_to_object          (EMH_AOM_error_base + 17)

/** The object "%1$" is locked for transfer of ownership to another site. */
#define AOM_inst_in_xfer_pending                        (EMH_AOM_error_base + 18)

/** The attribute is not valid for that operation. */
#define AOM_invalid_attribute                           (EMH_AOM_error_base + 19)

/** The attribute name "%1$" is not valid for that operation. */
#define AOM_attrib_invalid_name                         (EMH_AOM_error_base + 20)

/** The length for the localization string of the property &quot;%1$&quot; is "%2$", which exceeds the allowed maximum length of "%3$" characters. 
Excess data will be truncated. If known, the untruncated string is: '%4$'.*/
#define AOM_VLA_data_truncated                          (EMH_AOM_error_base + 21)

/** The operation &quot;%1$&quot; is not allowed when the Deferred Helper is turned on. */
#define AOM_invalid_deferred_operation                  (EMH_AOM_error_base + 22)

/** Invalid or insufficient inputs have been provided for the creation of a Digital Signature object. Please report this error to your system administrator.*/
#define AOM_ds_invalid_input                            (EMH_AOM_error_base + 30)

/** The selected target object "%1$" does not support Digital Signature.*/
#define AOM_ds_not_supported                            (EMH_AOM_error_base + 31)

/** The Digital Signature cannot be applied to the object "%1$" due to mismatch in type constant configuration version with type of the object "%3$". Please report this error to your system administrator. */
#define AOM_ds_creation_error                           (EMH_AOM_error_base + 32)

/** A mismatch is detected in the versions of the Business Object "%1$" type constants "Fnd0DigitalSignatureAttributes' and "Fnd0DigitalSignatureChildObjects". 
Please report this error to your system administrator.*/
#define AOM_ds_key_constants_mismatch                   (EMH_AOM_error_base + 33)

/** The user validation has failed. Please contact your system administrator. */
#define AOM_ds_failed_id_validation                     (EMH_AOM_error_base + 34)

/** The current user does not have the requested "Void Digital Signature" privilege on objects of type "%1$". Please contact your system administrator to add the proper Access Management (AM) rule. */
#define AOM_ds_failed_void_privilege                    (EMH_AOM_error_base + 35)

/** The Generic Relationship Management (GRM) relation "%1$" is not allowed to be updated or deleted. Please contact your system administrator. */
#define AOM_ds_grm_update_not_allowed                   (EMH_AOM_error_base + 36)

/** The current user does not have the requested "Apply Digital Signature" privilege on objects of type "%1$". Please contact your system administrator to add the proper Access Management (AM) rule. */
#define AOM_ds_failed_apply_privilege                   (EMH_AOM_error_base + 37)

/** The Digital Signature on the object "%1$" has became invalid. Most likely one of the object's attribute values used by the Digital Signature has been modified. */
#define AOM_invalid_ds                                  (EMH_AOM_error_base + 38)

/** The current user has already applied a valid Digital Signature on the target object "%1$". */
#define AOM_valid_ds_exists                             (EMH_AOM_error_base + 39)

/** The type constant "%1$" value of the Business Object type "%2$" exceeds the limit 2000 characters. Please contact your system administrator. */
#define AOM_ds_typeconst_value_exceed_length            (EMH_AOM_error_base + 40)

/** The type constant "%1$" value of the Business Object type "%2$" contains the exclusion attribute "%3$". Please contact your system administrator. */
#define AOM_ds_typeconst_contain_exclusion_attr         (EMH_AOM_error_base + 41)

/** An empty value for the type constant "%1$" configuration version of the Business Object type "%2$" is not allowed. Please contact your system administrator. */
#define AOM_ds_empty_typeconst_not_allowed              (EMH_AOM_error_base + 42)

/** The type constant "%1$" configuration version of the Business Object type "%2$" is not allowed to be updated, because it is already used in existing Digital Signature message computations. Please create a new configuration version. */
#define AOM_ds_typeconst_update_not_allowed             (EMH_AOM_error_base + 43)

/** The Digital Signature cannot be voided, because the "Void" operation needs to be completed using the root object "%1$". */
#define AOM_ds_void_allowed_in_rootobj_context          (EMH_AOM_error_base + 44)

/** The Digital Signature on the target "%1$" is already voided. */
#define AOM_ds_obj_already_voided                       (EMH_AOM_error_base + 45)

/** The Digital Signature validation has failed due to an incorrect signature key. Please contact your system administrator.*/
#define AOM_incorrect_ds_key                            (EMH_AOM_error_base + 46) 

/** A Digital Signature cannot be applied to the target object "%1$", because its root object "%2$" already contains a Digital Signature. */
#define AOM_object_has_propagated_ds                    (EMH_AOM_error_base + 47)

/** The required type constant attributes for the Digital Signature feature on the Business Object type "%1$" are not configured. Please report this error to your system administrator. */
#define AOM_ds_type_constants_error                     (EMH_AOM_error_base + 48)

/** An error is detected in the Digital Signature key computation. Please check the Teamcenter server syslog file and report this error to your system administrator */
#define AOM_ds_key_error                                (EMH_AOM_error_base + 49)

/** The type constant attribute value "%3$" for the type constant "%1$" is not defined on the Business Object of type "%2$". Please provide an attribute value, as defined on this Business Object type.*/
#define AOM_ds_undefined_type_constant_attribute        (EMH_AOM_error_base + 50)

/** The type constant "Fnd0DigitalSignatureChildObjects" of the Business Object type "%1$" contains the following incorrect value: "%2$". Valid values are relation (typed/untyped) properties or reference (typed/untyped/external) properties. */
#define AOM_ds_invalid_child_attribute                  (EMH_AOM_error_base + 51)

/** The type constant "Fnd0DigitalSignatureAttributes" of the Business Object type "%1$" contains the following incorrect value: "%2$". Valid values are Boolean, Integer, String, Double, Date or Character properties. */
#define AOM_ds_invalid_signature_attribute              (EMH_AOM_error_base + 52)

/** A problem has been detected with the digital signature certificates stored in the server. Please contact your system administrator. */
#define AOM_ds_server_certificate_error                 (EMH_AOM_error_base + 53)

/** The supplied token "%1$" is not supported. Only "UPPER" and "SUBSTR" values are supported for a given token. */
#define AOM_token_not_supported                         (EMH_AOM_error_base + 54)

/** The current database platform "%1$" is not supported. Supported platforms are Oracle, MSSQL and DB2. */
#define AOM_platform_not_supported                      (EMH_AOM_error_base + 55)

/** The attribute "%1$" of the class "%2$" is already localized. */
#define AOM_attribute_already_localized                 (EMH_AOM_error_base + 56)

/** "%1$" cannot be created because you do not have the required privilege. */
#define AOM_inst_create_protected                       (EMH_AOM_error_base + 57)

/** @} */

#include <tccore/libtccore_undef.h>

#endif
