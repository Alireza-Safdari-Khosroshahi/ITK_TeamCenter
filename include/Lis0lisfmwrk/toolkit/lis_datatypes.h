/*
    Copyright 2020 Siemens Digital Industries Software
    ==================================================
    Copyright 2014.
    Siemens Product Lifecycle Management Software Inc.
    All Rights Reserved.
    ==================================================
    Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    This file contains the declaration for the LIS toolkit property attribute types and constants defined by OSLC specifications
    Open Services for Lifecycle Collaboration (OSLC) specifiications provide a list of properties allowed and/or required for a particular domain and operation on an OSLC defined resource.
    Specifications that provide a list of properties and constraints on them provide the following information for each property that it define.

*/

#ifndef LIS_DATATYPES_H
#define LIS_DATATYPES_H



/**
   Defines different values that can be used as LIS media types
*/
typedef enum LIS_media_type_e
{
    LIS_MEDIA_TYPE_rdf_xml = 0,                /**< Media type RDF+XML. */
    LIS_MEDIA_TYPE_json,                       /**< Media type JSON. */
    LIS_MEDIA_TYPE_xml,                        /**< Media type XML. */
    LIS_MEDIA_TYPE_compact_xml,                /**< Media type Compact XML. */
    LIS_MEDIA_TYPE_compact_json                /**< Media type Compact JSON. */

} LIS_media_type_t;

/**
   Defines different values that can be used as LIS property types
   A property may allow multiple value-types and a value must satisfy one or more of them.
   Each value-type must be a URI that corresponds to one of the following
*/

typedef enum LIS_properties_value_type_e
{
    LIS_PROP_TYPE_boolean = 0,                 /**< Property type boolean, http://www.w3.org/2001/XMLSchema#boolean. */
    LIS_PROP_TYPE_decimal,                     /**< Property type decimal, http://www.w3.org/2001/XMLSchema#decimal */
    LIS_PROP_TYPE_double,                      /**< Property type doubls, http://www.w3.org/2001/XMLSchema#double */
    LIS_PROP_TYPE_float,                       /**< Property type float, http://www.w3.org/2001/XMLSchema#dfloat, */
    LIS_PROP_TYPE_integer,                     /**< Property type integer, http://www.w3.org/2001/XMLSchema#integer */
    LIS_PROP_TYPE_date_time,                   /**< Property type data time, http://www.w3.org/2001/XMLSchema#dateTime */
    LIS_PROP_TYPE_string,                      /**< Property type string, http://www.w3.org/2001/XMLSchema#string */
    LIS_PROP_TYPE_xml_literal,                 /**< Property type XML literal, http://www.w3.org/1999/02/22-rdf-syntax-ns#XMLLiteral */
    LIS_PROP_TYPE_resource,                    /**< Property type resource, http://open-services.net/ns/core#AnyResource */
    LIS_PROP_TYPE_local_resource,              /**< Property type local resource, http://open-services.net/ns/core#LocalResource */
    LIS_PROP_TYPE_typed_reference,             /**< Property type typed reference, http://open-services.net/ns/core#Reference  */
    LIS_PROP_TYPE_untyped_reference,           /**< Property type untyped reference, http://open-services.net/ns/core#Reference  */
    LIS_PROP_TYPE_external_reference,          /**< Property type external refernce, http://open-services.net/ns/core#Reference  */
    LIS_PROP_TYPE_typed_relation,              /**< Property type typed relation, http://open-services.net/ns/core#Reference */
    LIS_PROP_TYPE_untyped_relation,            /**< Property type untyped relation, http://open-services.net/ns/core#Reference */
    LIS_PROP_TYPE_untyped                      /**< Property type untyped, http://open-services.net/ns/core#AnyResource */

} LIS_properties_value_type_t;

/**
   Defines different values that can be used as LIS Property Representation types
   Representation for properties with a resource value-type, OSLC specifications specify the respresentation of the resource.
*/

typedef enum LIS_properties_representation_type_e
{
    LIS_PROP_REPRESENTATION_reference = 0,               /**< Property representation http://open-services.net/ns/core#Reference */
    LIS_PROP_REPRESENTATION_inline,                      /**< Property representation http://open-services.net/ns/core#Inline */
    LIS_PROP_REPRESENTATION_either,                      /**< Property representation http://open-services.net/ns/core#Either */
    LIS_PROP_REPRESENTATION_na                           /**< Property representation Not Applicable. */

} LIS_properties_representation_type_t;

/**
   Defines different values that can be used as LIS Property Occurs .
*/
typedef enum LIS_properties_value_occurs_e
{
    LIS_PROP_OCCURS_exactly_one = 0,           /**< Property occrurs http://open-services.net/ns/core#Exactly-one */
    LIS_PROP_OCCURS_zero_or_one,               /**< Property occrurs http://open-services.net/ns/core#Zero-or-one */
    LIS_PROP_OCCURS_zero_or_many,              /**< Property occrurs http://open-services.net/ns/core#Zero-or-many */
    LIS_PROP_OCCURS_one_or_many,               /**< Property occrurs http://open-services.net/ns/core#One-or-many */
    LIS_PROP_OCCURS_any                        /**< property occrurs http://open-services.net/ns/core#Any */

} LIS_properties_value_occurs_t;

/**
   Defines different values that can be used as LIS Property names along with prefix
   <br/>Valid prefix values are dcterms, rdf, rdfs, oslc, oslc_cm, which are explained below
*/
typedef enum LIS_properties_prefix_name_e
{
    LIS_PROP_NAME_title = 0,                   /**< Property dcterms:title */
    LIS_PROP_NAME_desc,                        /**< Property dcterms:description*/
    LIS_PROP_NAME_domain,                      /**< Property oslc:domain */
    LIS_PROP_NAME_details,                     /**< Property oslc:details */
    LIS_PROP_NAME_identifier,                  /**< Property dcterms:identifier */
    LIS_PROP_NAME_publisher,                   /**< Property dcterms:publisher */
    LIS_PROP_NAME_usage,                       /**< Property oslc:usage */
    LIS_PROP_NAME_icon,                        /**< Property oslc:icon */
    LIS_PROP_NAME_label,                       /**< Property oslc:label */
    LIS_PROP_NAME_oauth_configuration,         /**< Property oslc:oauthConfiguration */
    LIS_PROP_NAME_prefix_definition,           /**< Property oslc:prefixDefinition */
    LIS_PROP_NAME_service,                     /**< Property oslc:service */
    LIS_PROP_NAME_service_provider,            /**< Property oslc:serviceProvider */
    LIS_PROP_NAME_service_provider_catalog,    /**< Property oslc:serviceProviderCatalog */
    LIS_PROP_NAME_creation_factory,            /**< Property oslc:creationFactory */
    LIS_PROP_NAME_query_capability,            /**< Property oslc:queryCapability */
    LIS_PROP_NAME_dialog,                      /**< Property oslc:dialog */
    LIS_PROP_NAME_creation_dialog,             /**< Property oslc:creationDialog */
    LIS_PROP_NAME_selection_dialog,            /**< Property oslc:selectionDialog */
    LIS_PROP_NAME_creation,                    /**< Property oslc:creation */
    LIS_PROP_NAME_resource_shape,              /**< Property oslc:resourceShape */
    LIS_PROP_NAME_resource_type,               /**< Property oslc:resourceType */
    LIS_PROP_NAME_query_base,                  /**< Property oslc:queryBase */
    LIS_PROP_NAME_hint_width,                  /**< Property oslc:hintWidth */
    LIS_PROP_NAME_hint_height,                 /**< Property oslc:hintHeight */
    LIS_PROP_NAME_document,                    /**< Property oslc:document */
    LIS_PROP_NAME_short_title,                 /**< Property oslc:shortTitle */
    LIS_PROP_NAME_small_preview,               /**< Property oslc:smallPreview */
    LIS_PROP_NAME_large_preview,               /**< Property oslc:largePreview */
    LIS_PROP_NAME_type,                        /**< Property dcterms:type */
    LIS_PROP_NAME_property,                    /**< Property oslc:property */
    LIS_PROP_NAME_describes,                   /**< Property oslc:describes */
    LIS_PROP_NAME_name,                        /**< Property oslc:name */
    LIS_PROP_NAME_occurs,                      /**< Property oslc:occurs */
    LIS_PROP_NAME_property_definition,         /**< Property oslc:propertyDefinition */
    LIS_PROP_NAME_range,                       /**< Property oslc:range */
    LIS_PROP_NAME_representation,              /**< Property oslc:representation */
    LIS_PROP_NAME_valueType,                   /**< Property oslc:valueType */
    LIS_PROP_NAME_readOnly,                    /**< Property oslc:readOnly */
    LIS_PROP_NAME_rdfsMember,                  /**< Property oslc:member */
    LIS_PROP_NAME_oslcCount,                   /**< Property oslc:totalCount */
    LIS_PROP_NAME_status_code,                 /**< Property oslc:statusCode */
    LIS_PROP_NAME_message,                     /**< Property oslc:message */
    LIS_PROP_NAME_extended_error,              /**< Property oslc:extendedError */
    LIS_PROP_NAME_more_info,                   /**< Property oslc:moreInfo */
    LIS_PROP_NAME_rel                          /**< Property oslc:rel */

} LIS_properties_prefix_name_t;

/**
   Defines different values that can be used as LIS Property Range
   <br/>Range for properties with a resource value-type.
   <br/>Open Services for Lifecycle Collaboration (OSLC) specifications which usually results in no restrictions on the range of possible resource types allowed.
*/
typedef enum LIS_properties_range_type_e
{
    LIS_PROP_RANGE_any = 0,                    /**< Property range Any */
    LIS_PROP_RANGE_na                          /**< Property range Not applicable */

} LIS_properties_range_type_t;

/**
   Defines dcterms prefix
*/
#define LIS_DCTERMS_NAMESPACE_PREFIX         "dcterms"

/**
   Defines oslc core prefix
*/
#define LIS_OSLC_CORE_NAMESPACE_PREFIX       "oslc"

/**
   Defines oslc data prefix
*/
#define LIS_OSLC_DATA_NAMESPACE_PREFIX       "oslc_data"

/**
   Defines rdf prefix
*/
#define LIS_RDF_NAMESPACE_PREFIX             "rdf"

/**
   Defines rdfs prefix
*/
#define LIS_RDFS_NAMESPACE_PREFIX            "rdfs"

/**
   Defines oslc cm core prefix
*/
#define LIS_OSLC_CM_CORE_NAMESPACE_PREFIX    "oslc_cm"

#endif
