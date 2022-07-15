/*
Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright 2018.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software
*/

#ifndef CLA0CLASSIFICATION_ITK_H
#define CLA0CLASSIFICATION_ITK_H

#include <Cla0classification/libcla0classification_exports.h>

/**
    @defgroup CLA0CLASSIFICATION Classification Interface
    @ingroup TC

    All published Classification APIs will be exposed through this unified interface.

    @{
*/
#ifdef __cplusplus
extern "C"
{
#endif
    /**
       @name Admin
       @{
    */
    /**
       Identifies the Classification deployment level

       Valid values are:
       <ul>
       <li>Traditional Classification
       <li>Next Generation Classification
       <li>Next Generation Classification with Standard Taxonomy
       </ul>

       @returns
       <ul>
       <li>#ITK_ok on success.
       </ul>
    */
    extern CLA0CLASSIFICATION_API int CLA_get_classification_level(
        char** response      /**< (OF) Output */
        );
    /**
       @}
    */

   /**  Creates or saves classification objects.
        @note An error will be returned if the operation could not be completed successfully and information about the error will be in @p response.
        @returns
        <ul>
        <li>#ITK_ok on success.
        </ul>
    */
    extern CLA0CLASSIFICATION_API int CLA_save_classification_objects(
        const char* request,    /**< (I) The inputted JSON request string. */
        char**      response    /**< (OF) The information on saved objects in JSON string format. */
    );

    /** Retrieves the classification objects, with all its values for the given classification object IDs.
        @note An error will be returned if the operation could not be completed successfully and information about the error will be in @p response.
        @returns
        <ul>
        <li>#ITK_ok on success.
        </ul>
    */
    extern CLA0CLASSIFICATION_API int CLA_get_classification_objects(
        const char* request,    /**< (I) The inputted JSON request string. */
        char**      response    /**< (OF) Complete details about requested classification objects in JSON string format. */
    );

    /** Deletes classification objects for the given classification object ids.
        @note An error will be returned if the operation could not be completed successfully and information about the error will be in @p response.
        @returns
        <ul>
        <li>#ITK_ok on success.
        </ul>
    */
    extern CLA0CLASSIFICATION_API int CLA_delete_classification_objects(
        const char* request,    /**< (I) The inputted JSON request string. */
        char**      response    /**< (OF) Uids of deleted classification objects in JSON string format. */
    );

    /** 
    Searches classification objects for the Library focussed classification "search" request.
    <br/>The schema applied for the Json request is from SearchClassificationObjects_Request.schema.json
    @note An error will be returned if the operation could not be completed successfully and information about the error will be in @p response.
    @returns
    <ul>
    <li>#ITK_ok always.
    </ul>
    */
    extern CLA0CLASSIFICATION_API int CLA_search_classification_objects(
        const char* request,    /**< (I) The JSON request string. */
        char**      response    /**< (OF) The retrieved classification objects with ico information. */
    );

    /**
    Retrieve the children nodes for the Classification nodes. The node that is supported currently is the library hierarchy node.
    <br/>The schema applied for the Json request is from GetClassificationChildren_Request.schema.json
    @note An error will be returned if the operation could not be completed successfully and information about the error will be in @p response.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CLA_err_no_valid_json if the input request is not a valid JSON file.
    <li>#CLA_err_schema_validation if the schema validation has failed.
    </ul>
    */
    extern CLA0CLASSIFICATION_API int CLA_get_children_nodes(
        const char* request,    /**< (I) The JSON request string. */
        char**      response    /**< (OF) The retrieved children nodes for a given node in Json string format. */
    );

    /**
    Imports node definitions using a passed in JSON request string, outputs any errors through a JSON response string

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>Possibly other errors.
    </ul>

    @note Errors are returned through the JSON response if any are present, which the caller needs to handle.
    */
    extern CLA0CLASSIFICATION_API int CLA_import_classification_definitions(
        const char* request,    /**< (I) The JSON request string. */
        bool        dry_run,    /**< (I) Validate the input json without creating classification definitions if it is set to true otherwise definitions will get created*/
        char**      response    /**< (OF) The retrieved classification definitions in Json string format. */
    );

    /**
        Searches classification definitions using the criteria provided in the input JSON string and outputs a JSON string containing search results.

        @returns
        <ul>
        <li>#ITK_ok on success.
        <li>Possibly other errors.
        </ul>

        @note Errors are returned through the JSON response if any are present, which the caller needs to handle.
    */
    extern CLA0CLASSIFICATION_API int CLA_search_classification_definitions(
        const char* request,    /**< (I) The JSON request string. */
        char** response         /**< (OF) The JSON response containing search results. */
    );
#ifdef __cplusplus
}
#endif

/** @} */

#include <Cla0classification/libcla0classification_undef.h>
#endif
