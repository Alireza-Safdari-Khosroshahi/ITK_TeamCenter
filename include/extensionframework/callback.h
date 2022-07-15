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
    @file callback.h

    Public API for callbacks in Extension Framework Library   
 */

#ifndef EXTENSIONFRAMEWORK_H_INCLUDED
#define EXTENSIONFRAMEWORK_H_INCLUDED

#include <unidefs.h>

#include <extensionframework/libextensionframework_exports.h>
/**
    @defgroup EXTENSION_FRAMEWORK Extension Framework
    Extension Framework provides the functions for representing operations, pre/post extensions and callback functions.
    @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/**
    Function signature of registered callback functions that are returned by CALLBACK_get_function_pointers
*/
typedef void (*Callback_fn_t)(void);

/**
    Retrieves the registered callback functions using the value of the "type" attribute on the CallbackFunction Business Object.
    <br/>If a specific callback function is needed, please use #CALLBACK_get_function_pointer_by_name.

    @code
        int numberOfAdapters = 0;
        Callback_fn_t* functions = NULL;
        ResultStatus stat = CALLBACK_get_function_pointers("OccManagementAdapter", &numberOfAdapters, &functions);
        for (int i = 0; i < numberOfAdapters; ++i)
        {
            if ( functions[i] != NULL )
            {
                //Now execute the function using the function pointer
                (functions[i])( );
            }
        }
    @endcode

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#ENQ_timeout if the query to get callback functions from database timed out.
    <li>Possibly any other error.
    </ul>
*/
extern EXTENSIONFRAMEWORK_API int CALLBACK_get_function_pointers( 
    const char* callback_type,   /**< (I) Value of the "type" attribute on CallbackFunction Business Object, for which the callback function is to be retrieved. */
    int* number_of_callbacks,    /**< (O) Number of found callback function objects. */
    Callback_fn_t** functions    /**< (OF) number_of_callbacks Registered callback function pointers. */
    );


/**
    Retrieves the registered callback function using the value of the "type" and "name" attributes on the CallbackFunction Business Object.

    @code
        int numberOfAdapters = 0;
        Callback_fn_t* functions = NULL;
        scoped_smptr< tag_t > objectTags;

        CALLBACK_get_function_pointer_by_name( "LOV_API", "LOV-ask-local-display-values", &numberOfAdapters, &functions, objectTags )
        if( numberOfAdapters == 1 )
        {
            m_contentValueCallback = (Callback_fn_t*) functions[0];
        }
        
        //Now execute the function using the function pointer
        (m_contentValueCallback)( );
        }
    @endcode

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#POM_invalid_name if an empty callback function name is provided or if no match is found.
    <li>#ENQ_timeout if the query to get callback functions from database timed out.
    <li>Possibly any other error.
    </ul>
*/
extern EXTENSIONFRAMEWORK_API int CALLBACK_get_function_pointer_by_name(
    const char* callback_type,    /**< (I) Value of the "type" attribute on CallbackFunction Business Object, for which the callback function is to be retrieved. */
    const char* callback_name,    /**< (I) Value of the "name" attribute. */
    Callback_fn_t* function       /**< (O) Registered callback function pointer. */
    );


/**
    Retrieves the names and the tags for all the Callback Function objects with the specified value 
    for the "type" attribute on the CallbackFunction Business Object.

    @code
        int numberOfCBTags = 0;

        scoped_smptr< tag_t > allCBTagsOnBO;
        char** allCBNamesOnBO = 0;
        CALLBACK_get_tags_by_name( "OccManagementAdapter", &numberOfCBTags, &allCBNamesOnBO, &allCBTagsOnBO )
        if( numberOfCBTags > 0 )
        {
            //Do whatever is needed with the object tag: possibly AOM_delete, etc.
        }
        MEM_free( allCBNamesOnBO );
        allCBNamesOnBO = 0;        
    @endcode

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#POM_invalid_name if no match is found.
    <li>#ENQ_timeout if the query to get callback functions from database timed out.
    <li>Possibly any other error.
    </ul>
*/
extern EXTENSIONFRAMEWORK_API int CALLBACK_get_names_and_tags(
    const char* callback_type,    /**< (I) Value of the "type" attribute on CallbackFunction Business Object, for which the object tag is to be retrieved */
    int* number_of_callbacks,     /**< (O) Number of found Callback Function objects. */
    char*** callback_names,       /**< (OF) number_of_callbacks Value of the "name" attribute. 
                                     <br/>The returned array is packed, which means that only the container needs to be de-allocated. 
                                     This de-allocation will also de-allocate its elements. */
    tag_t** cb_functions          /**< (OF) number_of_callbacks Tags for all the matching Callback Function objects. */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <extensionframework/libextensionframework_undef.h>

#endif


