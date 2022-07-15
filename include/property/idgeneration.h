/* 
    Copyright 2020 Siemens Digital Industries Software
    ==================================================
    Copyright 2013.
    Siemens Product Lifecycle Management Software Inc.
    All Rights Reserved.
    ==================================================
    Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    Header file for declaring ID Generation Rule related APIs

*/
#ifndef TEAMCENTER_PROPERTY_IDGR_H
#define TEAMCENTER_PROPERTY_IDGR_H

#include <tc/tc_startup.h>
#include <property/libproperty_exports.h>

/**
    @defgroup IDGENERATION ID Generation

    ID Generation functionality supports generation and validation of IDs.
    <br>ID Generation Rule/s need to be defined from BMIDE. Each ID Generation Rule is associated with subtype of Fnd0BaseIdGenerator object. This object collects the user inputs which is used for ID Generation.
    <br>Each ID Generation Rule has a list of Concatenation Rules having a condition and an optional Naming Rule.
    <br>ID Generation is based on inputs provided in object of Fnd0BaseIdGenerator type.
    <br>ID validation is based on the Naming Rules used while creating Concatenation Rules.

    @{
*/

#ifdef __cplusplus
    extern "C"{
#endif

/**
    Validates the provided ID with the attached ID Generation Rule.
    <br> The given ID is validated for the property (specified by 'property_name' of the specified 'type_name' type).
    Naming Rule can be optionally added to each Concatenation Rule and acts as validator.
    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#TYPE_unknown_type if the @p type_name is not found.
    <li>#PROP_not_found if @p property_name is NULL or empty string.
    <li>#PROP_invalid_prop_name if @p property_name is invalid.
    <li>Potentially other errors
    </ul>
*/
extern PROPERTY_API int IDGR_validate_field(
    const char*         type_name,                /**< (I) Type name */
    const char*         property_name,            /**< (I) Property name */
    const char*         field_value,              /**< (I) Field value of ID */
    logical*            id_generation_is_valid    /**< (O) Indicates if @p field_value is valid. */
    );

/**
    Generates the ID based on attached ID Generation Rule.
    <br> The ID is generated for the property (specified by 'property_name' of the specified 'type_name' type).
    An object of subtype of Fnd0BaseIdGenerator object is also required. Its tag is passed as id_generator_configuration_tag. This object contains the properties populated with user inputs. For example - Consider two properties are defined for MyFnd0BaseIdGenerator -
    <br> PropCountry, PropMachineType
    <br> And when an object of MyFnd0BaseIdGenerator is created those properties are populated with values such as
    <br> PropCountry - Canada, PropMachineType - CNC
    <br> While ID Generation, Concatenation Rules are evaluated. If the Condition specified in a Concatenation Rule is evaluated to true, that Concatenation Rule is used for creating ID.
    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#TYPE_unknown_type if the @p type_name is not found.
    <li>#PROP_not_found if @p property_name is NULL or empty string.
    <li>#PROP_invalid_prop_name if @p property_name is invalid.
    <li>#POM_invalid_tag if @p id_generator_configuration is NULL or invalid.
    <li>Potentially other errors
    </ul>
*/
extern PROPERTY_API int IDGR_generate_id_for_type(
    const char *        type_name,                       /**< (I) Type name */
    const char*         property_name,                   /**< (I) Property name */
    tag_t               id_generator_configuration,      /**< (I) Fnd0BaseIdGenerator type tag */
    char **             generated_id                     /**< (OF) The Generated ID */
    );

/** @} */
#ifdef __cplusplus
}
#endif

/** @} */

#include <property/libproperty_undef.h>

#endif
