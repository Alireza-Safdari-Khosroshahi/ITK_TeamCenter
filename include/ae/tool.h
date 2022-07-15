/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This file contains the constants, datastructures and function
    prototypes for working with the class Tool and specifically with the
    C ITK interface to this class. Normally, clients would not include
    this file, but rather include ae.h.
*/

/*  */

#ifndef TOOL_H
#define TOOL_H

#include <ae/ae_types.h>
#include <tc/tc_util.h>
#include <tccore/workspaceobject.h>
#include <ae/libae_exports.h>

/**
    @defgroup TOOL Tool
    @ingroup AE
    @{
*/

/**
    @name Constants used in setting tool load method
    @{
*/
#define AE_LOAD_AS_PROCESS  1
#define AE_LOAD_AS_MODULE   2

#define AE_MAX_LOAD_METHOD  2
/** @} */

#ifdef __cplusplus
    extern "C"{
#endif

/**
    Returns the tags to all of the tools in the database.
    Free up the memory for tool_tags with #MEM_free .
*/
extern AE_API int AE_tool_extent(
    int*          n_instances,        /**< (O) */
    tag_t**       instances           /**< (OF) n_instances */
    );



/**
    Returns a tag to a tool in the database with the input tool name.
    An error code not equal to #ITK_ok means that some error occurred while searching for the  tool with the name specified.
    A return of #ITK_ok means that there was no error. 
    It does not mean that a  tool was found.
    The value of tool must be compared with #NULLTAG using #tags_equal to determine if a tool was actually found.

    @code
    { 
        int stat;
        tag_t a_tool;
        char tool_name[WSO_name_size_c + 1];
        strcpy (tool_name, "some_tool_to_find"); 
        
        stat = AE_find_tool (tool_name, &tool);
        if( stat != ITK_ok )
            TC_printf ("Error %d finding tool %s./n", stat, tool_name); 
        else
        {
            if (tool, NULLTAG) TC_printf (" tool %s does not exist./n", tool_name); 
        }
    }
    @endcode
*/
extern AE_API int AE_find_tool2(
    const char    *tool_name,                          /**< (I) */
    tag_t*        tool_tag                             /**< (O) */
    );


/**
   Retrieves the string stored for the symbol name.
*/
extern AE_API int AE_ask_tool_symbol_name2(
    tag_t         tool_tag,                            /**< (I) */
    char          **symbol_name                        /**< (OF) */
    );


/**
    Retrieves the current value for the version of a tool.
*/
extern AE_API int AE_ask_tool_version2(
    tag_t         tool_tag,                                /**< (I) */
    char          **tool_version                           /**< (OF) */
    );


/**
   Retrieves the string stored for the tool's site classification.
*/
extern AE_API int AE_ask_tool_classification2(
    tag_t         tool_tag,                                      /**< (I) */
    char          **site_classification                          /**< (OF) */
    );


/**
   Retrieves the tool's vendor value.
*/
extern AE_API int AE_ask_tool_vendor2(
    tag_t         tool_tag,                                  /**< (I) */
    char          **tool_vendor                              /**< (OF) */
    );

/**
    Retrieves the installation date. 
    This should only be needed if the date is found to be wrong after registration with Teamcenter Engineering.
*/
extern AE_API int AE_ask_tool_install_date(
    tag_t         tool_tag,        /**< (I) */
    date_t*       install_date     /**< (O) */
    );

/**
    Reads the shell tool value for the input tool. 
    This means that when the input tool is invoked through AE, the shell tool is started first.
*/
extern AE_API int AE_ask_tool_shell(
    tag_t         tool_tag,        /**< (I) */
    tag_t*        shell_tool       /**< (O) */
    );

/**
    Manipulates the lists of input and output formats that are understood by this tool.
    The user is responsible to free each string returned in the array formats individually before freeing up the formats array itself. 

    Use #MEM_free to free up the memory used by the format arrays.
*/
extern AE_API int AE_ask_tool_input_formats(
    tag_t         tool_tag,                               /**< (I) */
    int*          format_count,                           /**< (O) */
    char***       input_formats                           /**< (OF) format_count */
    );

/**
    Manipulates the lists of input and output formats that are understood by this tool.
    Use #MEM_free to free up the memory used by the format arrays.
*/
extern AE_API int AE_ask_tool_output_formats(
    tag_t         tool_tag,                               /**< (I) */
    int*          format_count,                           /**< (O) */
    char***       output_formats                          /**< (OF) format_count */
    );

/**
    Manipulates the list of parameter names and default values attached to the input tool.
*/
extern AE_API int AE_ask_tool_parameters(
    tag_t         tool_tag,                               /**< (I) */
    int*          parameter_count,                        /**< (O) */
    char***       parameters,                             /**< (OF) parameter_count */
    char***       default_values                          /**< (OF) parameter_count */
    );

/**
    Reads the value which indicates whether a particular tool may function as a shell for another tool. 
    Set shell_flag to true if the tool should be used as a shell.
*/
extern AE_API int AE_ask_tool_shell_flag(
    tag_t         tool_tag,      /**< (I) */
    logical*      shell_flag     /**< (O) */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <ae/libae_undef.h>
#endif
