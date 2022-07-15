/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This file contains contstants, data structures and function prototypes for
    the class DatasetType and for the C ITK interface to this class.
    It would not normally be included, rather users would normally include ae.h.

    Load, unload, delete, save, and refresh can be done through the AOM ITK interface.
*/

/*  */

#ifndef DATASETTYPE_H
#define DATASETTYPE_H

/**
    @defgroup DATASETTYPE Dataset Type
    @ingroup AE
    @{
*/

#define TEXT_REF        "TEXT"
#define BINARY_REF      "BINARY"
#define OBJECT_REF      "OBJECT"

#define AE_NOEXPORT 0
#define AE_EXPORT 1

/* ******************************************************** */
/** @deprecated EXPORT and NOEXPORT are deprecated and will be removed from Tc13.0.
    In their place, please use AE_EXPORT and AE_NOEXPORT repectively.
*/

/*
** If you get these 'incompatibly defined' errors, then:
**
** 1a. Either move your #include datasettype.h directive ahead of the clashing
** product's #include directives
**
** 1b. Or move whichever #include is including datasettype.h or introduce a new
** #include datasettype.h ahead of the other product's #include.
**
** 2. Put #undef EXPORT immediately after the #include datasettype.h
**
** 3. Make sure that your code uses AE_EXPORT if it means AE_EXPORT. If you really
** want the other product's EXPORT, then use EXPORT.
*/

#ifdef EXPORT
#   error EXPORT is incompatibly defined; use AE_EXPORT and re-arrange includes
#else
#   define EXPORT AE_EXPORT
#endif
#ifdef NOEXPORT
#   error NOEXPORT is incompatibly defined; use AE_NOEXPORT and re-arrange includes
#else
#   define NOEXPORT AE_NOEXPORT
#endif
/* End deprecation.                                         */
/* ******************************************************** */

#include <ae/ae_types.h>
#include <tc/tc_startup.h>
#include <tc/tc_util.h>
#include <ae/libae_exports.h>

#ifdef __cplusplus
    extern "C"{
#endif

/**
    Retrieves all of the datasettypes in the database.
*/
extern AE_API int AE_datasettype_extent(
    int*          n_instances,        /**< (O) */
    tag_t**       instances           /**< (OF) n_instances */
    );

/**
    Sets and retrieves the parent datasettype or the children datasettypes for the input datasettype.
    <br/>Parents are not required, but they give the ability for a site to classify their data types.
*/
extern AE_API int AE_ask_datasettype_parent(
    tag_t         datasettype,         /**< (I) */
    tag_t*        parent_type          /**< (O) */
    );

/**
    Manipulates the set of tools that can be used with a particular datasettype.
    <br/>The "default" tool is the first tool in the list.
    If you remove the first tool in the list, the second tool then becomes the default tool.
*/
extern AE_API int AE_ask_datasettype_def_tool(
    tag_t         datasettype,       /**< (I) */
    tag_t*        tool               /**< (O) */
    );

/**
    Manipulates the set of tools that can be used with a particular datasettype.
    <br/>The "default" tool is the first tool in the list.
    If you remove the first tool in the list, the second tool then becomes the default tool.
*/
extern AE_API int AE_ask_datasettype_def_view_tool(
    tag_t         datasettype,       /**< (I) */
    tag_t*        tool               /**< (O) */
    );

/**
    Retrieves the name for datasettypes, since they are not WorkspaceObjects.
*/
extern AE_API int AE_ask_datasettype_name2(
    tag_t         datasettype,                                       /**< (I) */
    char          **datasettype_name                                 /**< (OF) */
    );

/**
   Retrieves description for datasettypes, since they are not WorkspaceObjects.
*/
extern AE_API int AE_ask_datasettype_desc2(
    tag_t         datasettype,                                       /**< (I) */
    char          **datasettype_desc                                 /**< (OF) */
    );

/**
    <br/>Manipulates the set of tools that can be used with a particular datasettype.
    <br/>The "default" tool is the first tool in the list.
    If you remove the first tool in the list, the second tool then becomes the default tool.
*/
extern AE_API int AE_ask_datasettype_tools(
    tag_t         datasettype,         /**< (I) */
    int*          n_tools,          /**< (O) */
    tag_t**       tools            /**< (OF) n_tools */
    );

/**
   Manipulates the set of tools that can be used with a particular datasettype.
   <br/>The "default" tool is the first tool in the list.
   If you remove the first tool in the list, the second tool then becomes the default tool.
*/
extern AE_API int AE_ask_datasettype_view_tools(
    tag_t         datasettype,         /**< (I) */
    int*          n_tools,          /**< (O) */
    tag_t**       tools            /**< (OF) n_tools */
    );

/**
    Finds a datasettype with the input name.

    @code
    {
        int stat;
        tag_t a_datasettype;
        char dst_name[AE_datasettype_name_size_c + 1];
        strcpy (dst_name, "some_datasettype_to_find");
        stat = AE_find_datasettype (dst_name, &a_datasettype);
        if( stat != ITK_ok )
        {
            TC_printf ("Error %d finding datasettype %s./n", stat, dst_name);
        }
        else
        {
            if (a_datasettype == NULLTAG)
            {
                TC_printf ("DatasetType %s does not exist./n", dst_name);
            }
        }
    }
    @endcode

    @returns
    <ul>
    <li>#ITK_ok on success. It only means that no error has occurred during the search. It does <i>not</i> mean that a datasettype was found.
    <li>Possibly other errors while searching for the datasettype with the name specified.

    @note @p datasettype will be #NULLTAG if it was not found.
*/
extern AE_API int AE_find_datasettype2(
    const char    *datasettype_name,                                 /**< (I) */
    tag_t*        datasettype                                        /**< (O) */
    );

/**
    Sets and retrieves the parent datasettype or the children datasettypes for the input datasettype.
    <br/>Parents are not required, but they give the ability for a site to classify their data types.
*/
extern AE_API int AE_ask_datasettype_children(
    tag_t         datasettype,        /**< (I) */
    int*          child_count,        /**< (O) */
    tag_t**       child_tags          /**< (OF) child_count */
    );

/**
    Retrieves non-zero (TRUE) if the input action is registered, @c 0 otherwise.
*/
extern AE_API int AE_ask_datasettype_action(
    tag_t         datasettype,        /**< (I) */
    AE_action_t   action,             /**< (I) */
    int*          on_or_off          /**< (O) */
    );

/**
    Initializes all of the actions to either on or off depending on the value of @p on_or_off.
*/
extern AE_API int AE_init_datasettype_actions(
    tag_t         datasettype,        /**< (I) */
    int           on_or_off           /**< (I) */
    );

/**
    Retrieves the list of strings which are the names of named references that datasets of this type can have.

    @code
    {
        int istat = ITK_ok;
        char** ref_list;
        int ref_count;
        tag_t datasettype;
        int i;

        ... Get datasettype from somewhere ...

        istat = AE_ask_datasettype_refs (datasettype, &ref_count, &ref_list);
        if( istat == ITK_ok )
        {
            for (i = 0; i < ref_count; i++)
            {
                TC_printf ("named reference %d is <%s>./n", i + 1, ref_list[i]);
            }
            MEM_free (ref_list);
        }
        else
        {
            TC_printf ("Error %d asking for datasettype references./n", istat);
        }

        ...

    }
    @endcode
*/
extern AE_API int AE_ask_datasettype_refs(
    tag_t         datasettype,        /**< (I) The Dataset Type. */
    int*          n_reference_names,  /**< (O) Number of reference names. */
    char***       reference_names     /**< (OF) n_reference_names The reference names.
                                         <br/>This array is not packed, which means that both the elements and the container need to be freed through a call to #MEM_free.  */
    );

/**
    @name Tool
    @{
*/
/**
   Retrieves the list of references of name @p ref_name for the specified datasettype.
   <br/>If more than one reference of the same name exist,
   @p n_references gives the total number of such references of that name.
*/
extern AE_API int AE_ask_datasettype_file_refs(
    tag_t         datasettype,        /**< (I) Tag of the Dataset Type for which the ref_templates and ref_formats are required. */
    const char*   ref_name,           /**< (I) Name of the reference. */
    int*          n_references,       /**< (O) Number of references of the name ref_name for the datasettype. */
    char***       ref_templates,      /**< (OF) n_references The template specifications for the reference name ref_name.
                                         <br/>This array is not packed, which means that both, the elements and the container need to be freed through a call to #MEM_free.  */
    char***       ref_formats         /**< (OF) n_references The format specifications for the reference name ref_name.
                                         <br/>This array is not packed, which means that both, the elements and the container need to be freed through a call to #MEM_free.  */
    );

/**
    Retrieves the references for the tool and datasettype combination for the operation oper_name.
*/
extern AE_API int AE_ask_tool_oper_refs(
    tag_t         datasettype,      /**< (I) Tag of the Dataset Type. */
    tag_t         tool,             /**< (I) Tag of the Tool. */
    int           oper_name,        /**< (I) Identifier of the operation (e.g., #ACTION_open, #ACTION_print, etc.). */
    int*          n_references,     /**< (O) Number of references for the specified Dataset Type, Tool and operation combination. */
    char***       ref_names,        /**< (OF) n_references The reference names for the specified datasettype, tool and operation combination.
                                       <br/>This array is not packed, which means that both, the elements and the container need to be freed through a call to #MEM_free.  */
    int**         export_flags      /**< (OF) n_references List of export flags for the above list of ref_names with the value of 1 or 0,
                                       where 1 is ON and 0 is OFF.*/
    );

/**
    Retrieves the parameters for the datasettype, tool and operation @p oper_name combination.
*/
extern AE_API int AE_ask_tool_oper_params(
    tag_t         datasettype,  /**< (I) Tag of the Dataset Type. */
    tag_t         tool,         /**< (I) Tag of the Tool. */
    int           oper_name,    /**< (I) Identifier of the operation (e.g., #ACTION_open , #ACTION_print , etc.). */
    int*          n_parameters, /**< (O) Number of parameters for the datasettype, tool and operation combination. */
    char***       parameters    /**< (OF) n_parameters List of parameters for the specified datasettype, tool and operation combination.
                                   <br/>This array is not packed, which means that both, the elements and the container need to be freed through a call to #MEM_free.  */
    );

/** @} */

extern AE_API int AE_ask_oper_preaction(
    tag_t         dtag,             /**< (I) */
    tag_t         tool,             /**< (I) */
    int           oper_name,        /**< (I) */
    tag_t*        preaction_tool    /**< (O) */
    );

extern AE_API int AE_ask_oper_postaction (
    tag_t         dtag,             /**< (I) */
    tag_t         tool,             /**< (I) */
    int           oper_name,        /**< (I) */
    tag_t*        postaction_tool   /**< (O) */
    );

extern AE_API int AE_ask_oper_preaction_params (
    tag_t         dtag,               /**< (I) */
    tag_t         tool,               /**< (I) */
    int           oper_name,          /**< (I) */
    int*          n_parameters,          /**< (O) */
    char***       parameters         /**< (OF) n_parameters */
    );

extern AE_API int AE_ask_oper_postaction_params (
    tag_t         dtag,               /**< (I) */
    tag_t         tool,               /**< (I) */
    int           oper_name,          /**< (I) */
    int*          n_parameters,          /**< (O) */
    char***       parameters         /**< (OF) n_parameters */
    );

#ifdef __cplusplus
}
#endif

/** @} */

#include <ae/libae_undef.h>
#endif
