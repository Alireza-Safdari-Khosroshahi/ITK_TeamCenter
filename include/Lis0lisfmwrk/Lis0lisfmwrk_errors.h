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

    Lifecycle Interoperability Services Framework Error Codes Declaration

*/

#ifndef LIS0LISFMWRK_ERRORS_H
#define LIS0LISFMWRK_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup LIS0LISFMWRK_ERRORS Lifecycle Interoperability Services Errors
    @ingroup LIS0LISFMWRK
    @{
*/

#define LIS0LISFMWRK_ERROR_BASE                                     EMH_LIS0LISFMWRK_error_base

/** The requested information for the URL is empty. */
#define LIS0LISFMWRK_invalid_url_input                              ( EMH_LIS0LISFMWRK_error_base + 1 )

/** The system has failed to connect to the host. Please check that the provided URL is correct: %1$ */
#define LIS0LISFMWRK_url_cannot_connect                             ( EMH_LIS0LISFMWRK_error_base + 2 )

/** The system could not resolve the host. Please check that the provided URL is correct: %1$ */
#define LIS0LISFMWRK_url_cannot_resolve_host                        ( EMH_LIS0LISFMWRK_error_base + 3 )

/** The provided URL is not properly formatted: %1$ */
#define LIS0LISFMWRK_url_use_wrongformat                            ( EMH_LIS0LISFMWRK_error_base + 4 )

/** The connection has timed out. Please check that the provided URL is correct: %1$ */
#define LIS0LISFMWRK_url_operation_timeout                          ( EMH_LIS0LISFMWRK_error_base + 5 )

/** A memory allocation request failed. Please contact the system administrator. */
#define LIS0LISFMWRK_url_out_of_memory                              ( EMH_LIS0LISFMWRK_error_base + 6 )

/** The provided URL (%1$) cannot be accessed because of authorization issues. */
#define LIS0LISFMWRK_url_not_authorized                             ( EMH_LIS0LISFMWRK_error_base + 7 )

/** The http response is not valid. Probably it is not a good OSLC provider. */
#define LIS0LISFMWRK_invalid_http_response                          ( EMH_LIS0LISFMWRK_error_base + 8 )

/** The domain "%1$" is not supported. Please refer to TDoc regarding the scope of supported domains. */
#define LIS0LISFMWRK_domain_not_supported                           ( EMH_LIS0LISFMWRK_error_base + 9 )

/** The license "%1$" for the Lifecycle Interoperability Services module is not available. Please contact the system administrator. */
#define LIS0LISFMWRK_validate_license_failed                        ( EMH_LIS0LISFMWRK_error_base + 10 )

/** Changing the URL "%1$" is not allowed. */
#define LIS0LISFMWRK_url_cannot_modified                            ( EMH_LIS0LISFMWRK_error_base + 11 )

/** The URL "%1$" request cannot be processed successfully. The returned HTTP code is "%2$".*/
#define LIS0LISFMWRK_url_request_error                              ( EMH_LIS0LISFMWRK_error_base + 12 )

/** The Lifecycle Interoperability Services link could not be created, because the corresponding LIS Service Provider (%1$) or Site (%2$) is not active. */
#define LIS0LISFMWRK_site_or_service_provider_inactive              ( EMH_LIS0LISFMWRK_error_base + 13 )

/** The input resource is either not supported or invalid.*/
#define LIS0LISFMWRK_resource_not_supported                         ( EMH_LIS0LISFMWRK_error_base + 14 )

/** No Media Writer exist for the type "%1$" */
#define LIS0LISFMWRK_media_writer_not_exist                         ( EMH_LIS0LISFMWRK_error_base + 15 )

/** The Media Reader has failed to parse the input JSON envelop/document. Check the Teamcenter server syslog for more details. */
#define LIS0LISFMWRK_failed_to_parse_json_envelope                  ( EMH_LIS0LISFMWRK_error_base + 16 )

/** The type "%1$" provided in the Resource Shapes request is either invalid or does not exist. */
#define LIS0LISFMWRK_resource_shape_invalid_type                    ( EMH_LIS0LISFMWRK_error_base + 17 )

/** The Registry Helper has failed to process the request. Check the Teamcenter server syslog for more details. */
#define LIS0LISFMWRK_regsitry_helper_failed                         ( EMH_LIS0LISFMWRK_error_base + 18 )

/** The object provided for the API processing of the Factory "%1$" is invalid. It should be sub-type of Item or Item Revision.*/
#define LIS0LISFMWRK_input_invalid_object                           ( EMH_LIS0LISFMWRK_error_base + 19 )

/** The Registry Helper has failed to process the request, because it is invalid. Check the Teamcenter syslog file for more details.*/
#define LIS0LISFMWRK_input_invalid_request                          ( EMH_LIS0LISFMWRK_error_base + 20 )

/** The request body of the provided Rest action "%1$" is invalid. Check the Teamcenter syslog file for more details.*/
#define LIS0LISFMWRK_input_request_body_empty                       ( EMH_LIS0LISFMWRK_error_base + 21 )

/** The object provided for update is out of synchronization, because its "If-Match" header is not matching the object timestamp. */
#define LIS0LISFMWRK_input_object_out_of_sync                       ( EMH_LIS0LISFMWRK_error_base + 22 )

/** The requesting application does not exist for the input consumer key "%1$". */
#define LIS0LISFMWRK_application_name_not_registered                ( EMH_LIS0LISFMWRK_error_base + 23 )

/** No valid Attribute Helper exists for the Catalog "%1$". Please run the "create_botype_reader" utility to create a catalog specific Attribute Helper.*/
#define LIS0LISFMWRK_valid_attr_helper_not_found                    ( EMH_LIS0LISFMWRK_error_base + 24 )

/** No valid Media Writer exists for the provided Request "%1$". Please run the "create_media_writer" utility to create a specific Writer.*/
#define LIS0LISFMWRK_valid_writer_not_found                         ( EMH_LIS0LISFMWRK_error_base + 25 )

/** The object type information is not specified in the input JSON xml given for creation factory request. Please add the "dcterms:type" entry to the request body.*/
#define LIS0LISFMWRK_input_type_not_specified                       ( EMH_LIS0LISFMWRK_error_base + 26 )

/** The input object type "%1$" is not supported by Provider Catalog. Please validate the Included Types and Excluded Types lists by the Provider Catalog.*/
#define LIS0LISFMWRK_invalid_type_catalog                           ( EMH_LIS0LISFMWRK_error_base + 27 )

/**The input consumer key "%1$" and application name "%2$" are either invalid or do not exist.*/
#define LIS0LISFMWRK_consumerkey_or_appname_does_not_exist          ( EMH_LIS0LISFMWRK_error_base + 28 )

/**The Registry Helper has failed to process the request, because no valid Provider Catalog exists.*/
#define LIS0LISFMWRK_input_invalid_catalog_request                  ( EMH_LIS0LISFMWRK_error_base + 29 )

/**No Factory services have been defined for the Service Provider "%1$".*/
#define LIS0LISFMWRK_no_factory_services_defined                    ( EMH_LIS0LISFMWRK_error_base + 30 )

/**No Delegated UI services have been defined for the Service Provider "%1$".*/
#define LIS0LISFMWRK_no_delegated_ui_services_defined               ( EMH_LIS0LISFMWRK_error_base + 31 )

/** No defined relation is available for the combination of Service Provider "%1$", Teamcenter object of type "%2$" and remote object of type "%3$". */
#define LIS0LISFMWRK_no_relation_type_found_to_link                 ( EMH_LIS0LISFMWRK_error_base + 32 )

/** The provided Service Provider object is either invalid or does not exist. */
#define LIS0LISFMWRK_invalid_service_provider_object                ( EMH_LIS0LISFMWRK_error_base + 33 )

/** "%1$" is not a valid Teamcenter object type. */
#define LIS0LISFMWRK_invalid_teamcenter_object_type                 ( EMH_LIS0LISFMWRK_error_base + 34 )

/** The input semantic type "%1$" is either invalid or has not been configured */
#define LIS0LISFMWRK_no_semantic_type_configured                    ( EMH_LIS0LISFMWRK_error_base + 35 )

/** The property check has failed for the remote object "%3$" belonging to the Linked Data Framework Provider "%6$" and which is linked to the target Teamcenter object "%5$". The value "%1$" for the property "%2$" of "%3$" did not match the expected value "%4$". */
#define LIS0LISFMWRK_remote_property_expected_actual_value_mismatch ( EMH_LIS0LISFMWRK_error_base + 36 )

/** The check of the remote property "%2$" has failed because of the following error in the Rule Handler "LDF-sync-ldf-status": %1s. Please make sure that properties and their expected values are configured correctly. */
#define LIS0LISFMWRK_incorrect_property_value_configuartion_mismatch ( EMH_LIS0LISFMWRK_error_base + 37 )

/** The check of the remote property "%2$" has failed because of the following error in the Rule Handler "LDF-sync-ldf-status": %1s. Unexpected error has occured. */
#define LIS0LISFMWRK_unexpected_error_querying_remote_property       ( EMH_LIS0LISFMWRK_error_base + 38 )

/** Invalid input received from the remote system for notification. */
#define LIS0LISFMWRK_invalid_input_received_notification             ( EMH_LIS0LISFMWRK_error_base + 39 )

/** The check of the existence of the remote property "%2$" has failed: %1$. Please ensure that the property is supported by the remote site. */
#define LIS0LISFMWRK_remote_property_not_found                       ( EMH_LIS0LISFMWRK_error_base + 40 )

/** The requested resource "%1$" cannot be found. The returned HTTP code is "%2$".*/
#define LIS0LISFMWRK_resource_not_found                              ( EMH_LIS0LISFMWRK_error_base + 41 )

/** The following required arguments are missing for the Rule Handler "LDF-sync-ldf-status": %1$.*/
#define LIS0LISFMWRK_missing_req_arg                                 ( EMH_LIS0LISFMWRK_error_base + 42 )

/** An invalid argument was sent to the Rule Handler "LDF-sync-ldf-status": %1$. Please check the argument and syntax.*/
#define LIS0LISFMWRK_invalid_argument                                ( EMH_LIS0LISFMWRK_error_base + 43 )

/** The input object type "%1$" is not supported by Provider Catalog "%2$". Please validate the Semantic Type and corressponding Teamcenter types mapped to the Provider Catalog.*/
#define LIS0LISFMWRK_invalid_tctype_mapped_catalog                   ( EMH_LIS0LISFMWRK_error_base + 44 )

/** The input relation "%1$" is either invalid or has not been configured for the combination of Service Provider "%2$", Teamcenter object of type "%3$" and remote object of type "%4$".*/
#define LIS0LISFMWRK_invalid_relation_type_to_link                   ( EMH_LIS0LISFMWRK_error_base + 45 )

/** The input remote object "%1$" is already linked to given Teamcenter object "%2$" through the relation "%3$".*/
#define LIS0LISFMWRK_remote_object_link_exists                       ( EMH_LIS0LISFMWRK_error_base + 46 )

/** The input request format type "%1$" is either invalid or not supported.*/
#define LIS0LISFMWRK_invalid_request_format                          ( EMH_LIS0LISFMWRK_error_base + 47 )

/** No Factory services have been defined for the Remote Type "%1$".*/
#define LIS0LISFMWRK_no_factory_services_remote_type                 ( EMH_LIS0LISFMWRK_error_base + 48 )

/** The "%1$" information is missing from the body XML provided for the creation factory request.*/
#define LIS0LISFMWRK_createfactory_missing_req_input                 ( EMH_LIS0LISFMWRK_error_base + 49 )

/** Your Remote System does not support "File Selection Delegated UI" for the resource "%1$".*/
#define LIS0LISFMWRK_no_file_selection_dialog_remote_resource        ( EMH_LIS0LISFMWRK_error_base + 50 )

/** The "%1$" information is missing from the body XML provided for the "%2$" factory service request.*/
#define LIS0LISFMWRK_factory_service_missing_req_input               ( EMH_LIS0LISFMWRK_error_base + 51 )

/** The processing of the factory service "%1$" request has failed because it is invalid or the service operation is not associated with the input "REST" action.*/
#define LIS0LISFMWRK_factory_service_invalid_request                 ( EMH_LIS0LISFMWRK_error_base + 52 )

/** No Dataset Types have been defined for the provided file types. Please contact your system administrator.*/
#define LIS0LISFMWRK_no_dataset_type_define_file_types               ( EMH_LIS0LISFMWRK_error_base + 53 )

/** The operation has failed due to invalid input data. Please consult the syslog file for more information.*/
#define LIS0LISFMWRK_invalid_input_data                              ( EMH_LIS0LISFMWRK_error_base + 54 )

/** The processing of the request from the dialog service "%1$" has failed because the input URL parameters are either invalid or missing.*/
#define LIS0LISFMWRK_dialog_service_invalid_url_parameter            ( EMH_LIS0LISFMWRK_error_base + 55 )

/** The dialog service "%1$" from the Provider Catalog "%2$" is not mapped to any semantic type. Please check the semantic type mapping configuration for this Provider Catalog.*/
#define LIS0LISFMWRK_no_symantic_type_mapped_catalog                 ( EMH_LIS0LISFMWRK_error_base + 56 )

/** The associated Dataset cannot be found on specified object or selected file types.*/
#define LIS0LISFMWRK_dataset_not_found                              ( EMH_LIS0LISFMWRK_error_base + 57 )

/** @} */
#endif
