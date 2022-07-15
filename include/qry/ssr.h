/* Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright $2010.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software */

/*  */

#ifndef SSR_H
#define SSR_H

#include <tc/tc_startup.h>

#include <qry/libqry_exports.h>

/**
@defgroup SSR Server Side Reports (SSR)
@ingroup QRY

The SSR module is a sub module in the QRY module.
It provides the interfaces to manage Server Side Reports.
@{
*/

/* Supported value types in reports */
typedef enum  SSR_value_types_e {
    SSR_UNKNOWN,
    SSR_BOOLEAN,
    SSR_STRING,
    SSR_CHARACTER,
    SSR_DATE,
    SSR_DOUBLE,
    SSR_INTEGER,
    SSR_TYPEDREFERENCE,
    SSR_UNTYPEDREFERENCE,
    SSR_EXTERNALREFERENCE,
    SSR_LONGSTRING,
    SSR_TYPEDRELEATION,
    SSR_UNTYPEDRELEATION
}SSR_value_types_t;

/* Separator for property values in SSR_property_data_s.*/
#define VR_Split_String "{;}"

/*********************************************/
/* Input Structures for custom methods.*/
/*********************************************/

/* Parameter descriptors.*/
typedef struct parameter_descriptors_s
{
    char parameter_name[80];                
    char parameter_display_name[80];        
    char parameter_default_value[240];      
    SSR_value_types_t valueType;            /* enum value */
} parameter_descriptors_t;

/*********************************************/

#ifdef __cplusplus
extern "C"{
#endif

/**
   Retrieves the visual report parameter descriptors.
*/
    extern QRY_API  int SSR_get_property_descriptors (
        tag_t visual_report_tag,               /**< (I) Visual report definition tag */
        const char* report_descriptor,         /**< (I) Type of report parameter: "general", "search", "property" */
        int *num_parameter_descriptors,        /**< (O) Number of parameter descriptors.*/
        parameter_descriptors_t **pd           /**< (OF) Array of parameter descriptors */
        );

/**
   Creates visual report objects. These objects are non-persistent and are not stored in the database.
   "visual_report_obj_tags" are transient tags generated to identify the visual report objects.
*/
    extern QRY_API int SSR_create_visual_report_objects( 
        tag_t *ctx_tags,                          /**< (I) Array of context object tags */
        int num_ctx_tags,                         /**< (I) Number of context object tags */
        tag_t **visual_report_obj_tags            /**< (OF)Array of visual report object tags */
        );
    
/**
   Creates report property objects. These objects are non-persistent and are not stored in the 
   database."report_property_obj_tags" are transient tags generated to identify the report property objects.
*/
    extern QRY_API int SSR_create_report_property_objects(
        tag_t visual_report_obj_tag,              /**< (I) Visual report object tag */
        int num_props,                            /**< (I) Number of report properties required */
        tag_t **report_property_obj_tags          /**< (OF) Array of report property object tags */
        );
/**
   Set report property data.
*/
    extern QRY_API int SSR_set_report_property_data(
        tag_t report_property_obj_tag,            /**< (I) Report property object tag */
        const char                   *name,             /**< (I) Name of property report results */
        const char                   *displayName,      /**< (I) Display name of property */
        SSR_value_types_t            valueType,         /**< (I) Type of property value */
        int                          numValues,         /**< (I) Number of property values */
        const char                   *values,           /**< (I) Array of property values separated by the delimiter*/
        const char                   *relatedUID,       /**< (I) If it is a typedreference type property, it is the UID of reference object */
        const char                   *source,           /**< (I) Source of the property */
        const char                   *propertyGroup,    /**< (I) Category within a source */
        const char                   *unit,             /**< (I) Unit of the property */
        const char                   *accessURL         /**< (I) Access URL of the property */
        );
    
/**
   Creates related objects for report property or related objects.These objects are non-persistent and are 
   not stored in the database. "related_obj_tags" are transient tags generated to identify the related objects.
*/
    extern QRY_API int SSR_create_related_objects( 
        tag_t parent_tag,                            /**< (I) Parent object tag */
        int num_related_objs,                        /**< (I) Number of related objects required */
        tag_t *obj_tags,                             /**< (I) Array of object tags*/
        tag_t **related_obj_tags                     /**< (OF) Array of related object tags */
        );
    
/**
   Sets the related objects data. Properties and related objects of objects having the same "UID's" are 
   merged before writing them in the XML.
*/
    extern QRY_API int SSR_set_related_object_data( 
        tag_t related_obj_tag,               /**< (I) related object tag */
        const char    *typeOfRelation        /**< (I) Object relationship type */
        ); 
    
/**
   Creates a SSR property object for report property or related objects. These objects are non-persistent and are 
   not stored in the database. "property_obj_tags" are transient tags generated to identify the property objects.
*/
    extern QRY_API int SSR_create_property_objects( 
        tag_t parent_tag,                        /**< (I) Parent object tag */
        int num_props,                           /**< (I) Number of SSR properties required */
        tag_t **property_obj_tags                /**< (OF) Array of SSR property object tags */
        );

/**
   Sets the values in the SSR property object.
*/
    extern QRY_API int SSR_set_property_data(
        tag_t                        property_obj_tag,  /**< (I) SSR Property tag */
        const char                   *name,             /**< (I) Name of property report results */
        const char                   *displayName,      /**< (I) Display name of property */
        SSR_value_types_t            valueType,         /**< (I) Type of property value */
        int                          numValues,         /**< (I) Number of property values */
        const char                   *values,           /**< (I) Array of property values separated by the delimiter*/
        const char                   *relatedUID,       /**< (I) If it is a typedreference type property, it is the UID of reference object */
        const char                   *source,           /**< (I) Source of the property */
        const char                   *propertyGroup,    /**< (I) Category within a source */
        const char                   *unit,             /**< (I) Unit of the property */
        const char                   *accessURL         /**< (I) Access URL of the property */
        );

/**
   Creates external (non-teamcenter) objects for report property or related objects
   These objects do not have a teamcenter representation in the database.
   "related_obj_tags" are transient tags generated by teamcenter which can be used to set 
   data on this external object.
*/
    extern QRY_API int SSR_create_external_related_objects( 
        tag_t parent_tag,                            /**< (I) Parent object tag */
        int num_related_objs,                        /**< (I) Number of related objects required */
        tag_t **related_obj_tags                     /**< (OF) Array of related object tags created */
        );

/**
   Sets external related objects data. The "extObjectID" is used to uniquely identify this object.
   Properties and related objects of external objects having the same "extObjectID" are merged while
   writing them to the XML. If "extObjectSource" is NULL, then default value of "External" will be used.
*/
    extern QRY_API int SSR_set_external_related_object_data( 
        tag_t related_obj_tag,                        /**< (I) External related object transient tag */
        const char    *extObjectID,                   /**< (I) External object ID */
        const char    *extObjectSource,               /**< (I) Source of the External object type*/
        const char    *extObjectName,                 /**< (I) External object display name */
        const char    *extObjectType,                 /**< (I) External object type */
        const char    *extObjectaccessURL,            /**< (I) The URL to directly access the external object*/
        const char    *typeOfRelation                 /**< (I) External Object relationship type */
        ); 


/**
   Adds the specified error message to a SSR Object.

   String arguments are substituted into the translated UIL string when the error string is written into the XML,
   where \%n\$ in the UIL string gives the n'th argument to substitute (XPG3 printf).

   If the error code is not resolved, the parameters s1 thru s7 are concatenated with VR_Split_String as separator
   and output as a single error message into the XML.
*/
    extern QRY_API int SSR_log_error(
        tag_t           object_tag,     /**< (I) Object tag */
        int             severity,       /**< (I) #EMH_severity_error, #EMH_severity_warning, or #EMH_severity_information */
        int             ifail,          /**< (I) Code of the error being stored */
        const char*     s1,             /**< (I) Character string being substituted into the internationalized message
                                           associated with this ifail code */
        const char*     s2,             /**< (I) Character string being substituted into the internationalized message
                                           associated with this ifail code */
        const char*     s3,             /**< (I) Character string being substituted into the internationalized message
                                           associated with this ifail code */
        const char*     s4,             /**< (I) Character string being substituted into the internationalized message
                                           associated with this ifail code */
        const char*     s5,             /**< (I) Character string being substituted into the internationalized message
                                           associated with this ifail code */
        const char*     s6,             /**< (I) Character string being substituted into the internationalized message
                                           associated with this ifail code */
        const char*     s7              /**< (I) Character string being substituted into the internationalized message
                                           associated with this ifail code */
        );

/* ******************************************************************************************
 * Report Definition functions
 * *****************************************************************************************
 */

/* Signature of custom function *

int my_custom_method (METHOD_message_t *msg, va_list args)
{
(I) int numObjects
(I) tag_t *objects    

(I) int num_reporting_property  
(I) parameter_descriptors_t *rpd

(I) int num_search_parameter  
(I) parameter_descriptors_t *spd

(I) int num_general_parameter;
(I) parameter_descriptors_t *gpd;

(I) int num_additional_parameter;
(I) parameter_descriptors_t *apd;

tag_t reportDef = msg->object_tag;
}
*/

    /** @} */
#ifdef __cplusplus
}
#endif

#include <qry/libqry_undef.h>

#endif
