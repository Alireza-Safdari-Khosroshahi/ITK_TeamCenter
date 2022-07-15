/*
  Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright $2012.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software
*/
/**
    @file

    This file contains the defined values and ITK function declarations for secore.
*/


#ifndef __SECORE_H__
#define __SECORE_H__

#include <unidefs.h>
#include <secore/libsecore_exports.h>


#ifdef __cplusplus
    extern "C"{
#endif


/**
   Moves down the selected BOM line with respect to its parent
*/
extern SECORE_API int SECORE_move_down
(
    tag_t    bom_line,             /**< (I) Selected BOM line to move down */
    tag_t*   modified_bom_line     /**< (O) Repositioned BOM line after move down */
);


/**
   Moves up the selected BOM line with respect to its parent
*/
extern SECORE_API int SECORE_move_up
(
    tag_t    bom_line,             /**< (I) Selected BOM line to move up */
    tag_t*   modified_bom_line     /**< (O) Repositioned BOM line after move up */
);

/**
   Promotes the selected BOM line to its immediate Super Parent
*/
extern SECORE_API int SECORE_promote
(
    tag_t    bom_line ,            /**< (I) Selected BOM line for promote */
    tag_t*   modified_bom_line     /**< (O) Repositioned BOM line after promote */
);

/**
   Demotes the selected BOM line to its previous sibling.
*/
extern SECORE_API int SECORE_demote
(
    tag_t   bom_line,          /**< (I) Selected BOM line for demote */
    tag_t*  modified_bom_line  /**< (O) Repositioned BOM line after demote */
);

/**
  Moves the selected BOM line to specified position.
*/
extern SECORE_API int SECORE_move_to
(
    tag_t    bom_line,          /**< (I) Selected BOM line to move to a specified position */
    char*    number,            /**< (I) New position number to reposition the BOM line */
    tag_t*   modified_bom_line  /**< (O) Repositioned BOM line after move */
);

/**
    Retrieves the BOMLines and Tracelinks present in diagram for a given Saved Bookmark (WorkspaceObject) object.
    @note The method relies on a callback registered on the callback type SEG0_GetDiagramContent_Callback during the installation of a solution through the following call:
    @code
    install_callback -u=<userid> -p=<password> -g=dba -mode=create -type=SEG0_GetDiagramContent_Callback -library=<libraryname> -function=<functionname> -name=<nameofcallback>
    // The function signature is 
    // int functionname 
    // ( 
    // const tag_t& workspaceObject, <I> Input object 
    // std::vector< tag_t >& bomLines, <O> Vector of BOMLine objects of the diagram members for input object 
    // std::vector< tag_t >& tracelinks <O> Vector of FND_TraceLink objects present in the diagram members for input object 
    // )
    @endcode

    @returns 
    <ul> 
    <li>#ITK_ok on success 
    <li>#REQ_invalid_tag_nulltag if @p workspace_object is #NULLTAG. 
    <li>#SECORE_invalid_tag_nulltag if @p workspace_object is not of WorkspaceObject type.
    <li>#SECORE_callback_not_registered if no callback of type SEG0_GetDiagramContent_Callback is registered.
    </ul> 
*/
extern SECORE_API int SECORE_get_diagram_contents 
( 
    const tag_t workspace_object, /**< (I) The WorkspaceObject object. */ 
    int * n_bom_lines,            /**< (O) The number of BOMLines of the diagram elements. */ 
    tag_t ** bom_lines,           /**< (OF) n_bom_lines BOMLines of the diagram elements. */ 
    int * n_tracelinks,           /**< (O) The number of Tracelinks in diagram. */ 
    tag_t ** tracelinks           /**< (OF) n_tracelinks Tracelinks in diagram. */ 
);

#ifdef __cplusplus
}
#endif

#include <secore/libsecore_undef.h>
#endif
