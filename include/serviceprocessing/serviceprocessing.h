/*==============================================================================
                Copyright (c) 2008 Siemens PLM Software
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
 @file serviceprocessing.h

 This header file declares all data types and constants to be used by clients of
 MRO module.
*/

#ifndef SERVICEPROCESSING_H
#define SERVICEPROCESSING_H
#include <string>

#include <unidefs.h>

#include <tccore/method.h>
#include <common/tc_deprecation_macros.h>
#include <serviceprocessing/libserviceprocessing_exports.h>


#ifdef __cplusplus
    extern "C"{
#endif

/**
    @defgroup SERVICEPROCESSING Service Processing

    The Service Processing module implements the basic set of classes and behaviour
    for serviceprocessing module.

    @{
*/

/**
   Sets the ask methods for Time Since Overhaul (TSO) and Time Since Repaired (TSR).

   @returns #ITK_ok always
*/
extern SERVICEPROCESSING_API int SERVICEPROCESSING__init_util_props ( 
    METHOD_message_t * method, /**< (I) The method pointer */
    va_list args               /**< (I) List of arguments for the method */
    );

/**
    @deprecated #SERVICEPROCESSING__get_physBOMLine deprecated in Teamcenter 11.2. Use #SERVICEPROCESSING_get_physical_bom_line instead.

    ITK function to get a phys BOM Line from a physical part   
*/
TC_DEPRECATED( "11.2", "SERVICEPROCESSING__get_physBOMLine", "SERVICEPROCESSING_get_physical_bom_line" )
extern SERVICEPROCESSING_API int SERVICEPROCESSING__get_physBOMLine (
    tag_t physpart,                    /**< (I) Tag of a physical part */
    tag_t *physBOMLine                 /**< (O) Tag of a physical part's BOM Line */
    );

    
/**
   Retrieves Physical BOM Line from a Physical Part.
  
   @returns #ITK_ok always
*/
extern SERVICEPROCESSING_API int SERVICEPROCESSING_get_physical_bom_line (
    tag_t physical_part,                /**< (I) Tag of a physical part */
    tag_t *physical_bom_line            /**< (O) Tag of a physical part's BOM Line */
    );

/**
    @deprecated #SERVICEPROCESSING_setReleaseStatus deprecated in Teamcenter 11.2. Use #SERVICEPROCESSING_set_release_status instead.

    ITK function to update release status
*/
TC_DEPRECATED("11.2", "SERVICEPROCESSING_setReleaseStatus", "SERVICEPROCESSING_set_release_status" )
extern SERVICEPROCESSING_API int SERVICEPROCESSING_setReleaseStatus(
    tag_t object,                     /**< (I) Tag of a service object being updated */
    char* releaseName,                /**< (I) the new release name */
    date_t releaseDate                /**< (I) the new release date */
    );    

    
/**
   Updates the release status.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#POM_attr_null_forbidden if the @p release_name is null or an empty string.
   <li>#POM_string_too_long if the @p release_name is too long
   </ul>
*/
extern SERVICEPROCESSING_API int SERVICEPROCESSING_set_release_status(
    tag_t object,                    /**< (I) Tag of a service object being updated */
    const char* release_name,        /**< (I) The new release name */
    date_t release_date              /**< (I) The new release date */
    );

/**
   @deprecated #SERVICEPROCESSING__valphysPartBase deprecated in Teamcenter 11.2. Use #SERVICEPROCESSING_is_child_physical_part instead.

   ITK function to validate if phys part 2 belongs to phys part 1
   Given two Physical Parts mroProdRev and childPhysicalPart, return true when childPhysicalPart belongs
   to mroProdRev. 
*/
TC_DEPRECATED("11.2", "SERVICEPROCESSING__valphysPartBase", "SERVICEPROCESSING_is_child_physical_part")
extern SERVICEPROCESSING_API int SERVICEPROCESSING__valphysPartBase (
    tag_t mroProdRev,                 /**< (I) Tag of a physical part */
    tag_t childPhysicalPart,          /**< (I) Tag of a child physical part */
    logical*    isChild               /**< (O) Return True if is child physical part
                                               Return False if is not child physical part*/
    );

/**
   Validates if a physical part (parameter @p child_physical_part) belongs to 
   another one (parameter @p physical_part).

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#POM_invalid_tag if either of the tags does not correspond to a Physical Part
   </ul>
*/
extern SERVICEPROCESSING_API int SERVICEPROCESSING_is_child_physical_part (
    tag_t physical_part,                /**< (I) Tag of a physical part */
    tag_t child_physical_part,          /**< (I) Tag of a child physical part */
    logical* is_child                   /**< (O) True if it is a child physical part, false otherwise */
    );

/**
    @deprecated #SERVICEPROCESSING_doubleToString deprecated in Teamcenter 11.2. Use #SERVICEPROCESSING_double_to_string instead.

    ITK function to convert double to string
*/
TC_DEPRECATED( "11.2", "SERVICEPROCESSING_doubleToString", "SERVICEPROCESSING_double_to_string" )
extern SERVICEPROCESSING_API int SERVICEPROCESSING_doubleToString
(
    double value,             /**< (I) Double value to be convert */
    int precision,            /**< (I) Number of decimal point */
    std::string& str          /**< (O) value converted to string */
);
    
/**
   Converts a double to string

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#ITK_internal_error if precision is too high or negative
   </ul>
*/
extern SERVICEPROCESSING_API int SERVICEPROCESSING_double_to_string(
    double value,             /**< (I) Double value to be convert */
    int precision,            /**< (I) Number of decimal point */
    char** double_string       /**< (OF) value converted to string */
);

/**
    @deprecated #SPR0PhysicalPartRevisionSetPropertiesFromSaveAsInputPostAction deprecated in Teamcenter 11.2. Use #SERVICEPROCESSING_set_properties_from_save_as instead.

    ITK function to set the overhaul and repair dates to null dates when a physical part is duplicated
*/
TC_DEPRECATED("11.2", "SPR0PhysicalPartRevisionSetPropertiesFromSaveAsInputPostAction", "SERVICEPROCESSING_set_properties_from_save_as" )
extern SERVICEPROCESSING_API int SPR0PhysicalPartRevisionSetPropertiesFromSaveAsInputPostAction ( METHOD_message_t  *, va_list args );

/**
    Sets the overhaul and repair dates to null dates when a physical part is duplicated
    
    @returns #ITK_ok always 
*/
extern SERVICEPROCESSING_API int SERVICEPROCESSING_set_properties_from_save_as ( METHOD_message_t  *, va_list args );

#ifdef __cplusplus
    }
#endif

/** @} */

#include <serviceprocessing/libserviceprocessing_undef.h>

#endif

