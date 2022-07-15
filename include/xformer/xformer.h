/* 
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2016.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    XFORMER module definitions file
*/

#ifndef TEAMCENTER_XFORMER_H
#define TEAMCENTER_XFORMER_H

#include <unidefs.h>
#include <xformer/libxformer_exports.h>

/**
    @defgroup XFORMER Transformer
    @ingroup TC

    Provides functions to transform data model from one format to another.

    The XFORMER functions include:
    <ul>
    <li> Functions to transform data model in xml format to xml/csv format.
    </ul>
    @{
*/

#ifdef __cplusplus
    extern "C"{
#endif

/**
   @name Transformer External Function definition methods

   Example for implementing Transformer External Function
   @code
   extern int func_ext_example ( void* scope )   
   {
        // Get arguments
        unsigned int cnt = 0;
        char** args = NULL;
        int ifail = XFORMER_get_scope_arguments( scope, &cnt, &args );
        if ( ifail != ITK_ok )
        {
             return ifail;
        }

        // Evaluate
        // NOTE: better to do argList chcek before go to this step
        std::string val(args[0]);
        val.append("_test");

        // Deallocate arguments
        MEM_free(args);

        // Apply Result
        ifail  = XFORMER_set_scope_return_value( val.c_str(), scope );
        return ifail;
   }
   @endcode
   @{
*/
    /**
       Teamcenter Transformer external function definition.
       <br/>The function is used to implement specific Transformer function logic in C/C++.
    */
    typedef int (*XFORMER_custom_function_fn_t) ( 
            void*           /**< (O) XFormer Function Scope for storing local variable */ 
       );
    /**
       Retrieves the input arguments in a specific Transformer Function Scope. 
       @returns
       <ul>
       <li>#ITK_ok on success
       <li>#XFORMER_symbol_undefined if @p scope has not been setup properly and cannot be processed by that ITK.
       <li>#XFORMER_invalid_function_arg if @p arguments or @p n_arguments is are not specified as valid output pointers.
       <li>Possibly other XFORMER errors.
       </ul>
    */
    extern XFORMER_API int XFORMER_get_scope_arguments ( 
            const void* scope,         /**< (I)  XFormer Function Scope    */ 
            unsigned int* n_arguments, /**< (O)  Number of input arguments */
            char*** arguments          /**< (OF) n_arguments Input arguments. <br/>The array is packed, which means it is to be deallocated by calling #MEM_free on the container only.          */
       );
    
    /**
       Sets the return value to a specific Transformer Function Scope.  
       @returns
       <ul>
       <li>#ITK_ok on success
       <li>#XFORMER_invalid_function_unit if @p value is a null pointer.
       <li>#XFORMER_symbol_undefined if @p scope has not been setup properly and cannot be processed by that ITK.
       <li>Possibly other XFORMER errors.
       </ul>
    */
    extern XFORMER_API int XFORMER_set_scope_return_value ( 
            const char* value,     /**< (I)   Value as string        */
            void* scope            /**< (I/O) XFormer Function Scope. The return value is saved in the scope */ 
       );  

    /**
       Set return values as string list to specific Transformer Function Scope. 
       @returns
       <ul>
       <li>#ITK_ok on success
       <li>#XFORMER_invalid_function_unit if @p value is a null pointer.
       <li>#XFORMER_symbol_undefined if @p scope has not been setup properly and cannot be processed by that ITK.
       <li>Possibly other XFORMER errors.
       </ul>
    */
    extern XFORMER_API int XFORMER_set_scope_return_values ( 
            const unsigned int n_values, /**< (I)   Number of values                */
            const char** values,         /**< (I)   n_values Values as string list  */
            void* scope                  /**< (I/O) XFormer Function Scope. The return values are saved in the scope */ 
       );  
/** @} */


/**
   @name Transformer Function evaluation methods
   @{
*/
    /**
       Creates a Transformer Function Scope.
       <br/> The scope can be used for applying transformer rule in C++ context.
       @returns #ITK_ok always.
    */
    extern XFORMER_API int XFORMER_create_function_scope ( 
            void** scope           /**< (OF) XFormer Function Scope */ 
       ); 
    
    /**
       Deletes Transformer Function Scope and frees the memory.  
       @returns #ITK_ok always.
    */
    extern XFORMER_API int XFORMER_delete_function_scope ( 
            void** scope          /**< (OF) XFormer Function Scope */ 
       ); 

    /**
       Evaluates a Function Expression using a specific Transformer Function Scope.  
       @returns
       <ul>
       <li>#ITK_ok on success
       <li>#XFORMER_invalid_function_arg if @p expression is a either empty, or a null-pointer, or has a syntax issue.
       <li>#XFORMER_invalid_function_arg if @p scope has not been setup properly and cannot be processed by that ITK.
       <li>Possibly other XFORMER errors.
       </ul>
    */
    extern XFORMER_API int XFORMER_evaluate_expression ( 
            const char* expression,    /**< (I)   The expression to evaluate. */
            void*       scope,         /**< (I/O) XFormer Function Scope. The expression evaluation may change the scope */ 
            char**      value          /**< (OF)  The result of the evaluation. */
       );     
/** @} */

/**
   @name Transform ITK
   @{
*/

    /**
       Transforms XML files to a unique object graph, then transforms this graph to
       an output file in a format driven by Transformer rules in a rule file.  
       @returns
       <ul>
       <li>#ITK_ok on success
       <li>#XFORMER_no_input_file if @p n_xml_files is 0
       <li>#XFORMER_xml_parse_error if some of the @p xml_files are not valid xml files or do not exist
       <li>#XFORMER_invalid_rule_file if the @p rule_file cannot be read
       <li>#XFORMER_invalid_output_file if the @p output_file cannot be created or opened correctly
       <li>Possibly other XFORMER errors.
       </ul>
    */
    extern XFORMER_API int XFORMER_transform_xml ( 
            unsigned int n_xml_files,      /**< (I) Number of XML files to process */
            const char** xml_files,        /**< (I) n_xml_files Paths to the XML files */
            unsigned int n_options,        /**< (I) Number of session options. */
            const char** options,          /**< (I) n_options Session option names. */
            const char** option_values,    /**< (I) n_options Session option values. */
            const char*  rule_file,        /**< (I) Path to the Transformer rule file. */
            const char*  output_file,      /**< (I) Path to the output file. It will be overwritten if the file already exists in the location. */
            const char*  log_file          /**< (I) Path to the log file. It will be overwritten if the file already exists. The log will be printed to the syslog if the @p log_file is not specified.*/
       );     
    
        
    /**
       Transforms XML files to a unique object graph, then transforms this graph to
       an output file in a format driven by Transformer rules in one or more rule file.
       @returns
       <ul>
       <li>#ITK_ok on success
       <li>#XFORMER_no_input_file if @p n_xml_files is 0
       <li>#XFORMER_xml_parse_error if some of the @p xml_files are not valid xml files or do not exist
       <li>#XFORMER_invalid_rule_file if the @p rule_file cannot be read
       <li>#XFORMER_invalid_output_file if the @p output_file cannot be created or opened correctly
       <li>Possibly other XFORMER errors.
       </ul>
    */
    extern XFORMER_API int XFORMER_transform_xml2( 
            unsigned int n_xml_files,      /**< (I) Number of XML files to process */
            const char** xml_files,        /**< (I) n_xml_files Paths to the XML files */
            unsigned int n_options,        /**< (I) Number of session options. */
            const char** options,          /**< (I) n_options Session option names. */
            const char** option_values,    /**< (I) n_options Session option values. */
            unsigned int n_rule_files,     /**< (I) Number of rule files to apply */
            const char** rule_files,       /**< (I) n_rule_files Paths to the Transformer rule files. */
            const char*  output_file,      /**< (I) Path to the output file. It will be overwritten if the file already exists in the location. */
            const char*  log_file          /**< (I) Path to the log file. It will be overwritten if the file already exists. The log will be printed to the syslog if the @p log_file is not specified.*/
            );
/** @} */

#ifdef __cplusplus
}
#endif

/** @} */

#include <xformer/libxformer_undef.h>
#endif
