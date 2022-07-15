/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

This file contains methods related to Application Interface module.

    A state of an object can be captured using the Application Interface & Request object APIs.

    Intermediate Data Capture module basically provides APIs to view the captured state of an
    object in the form of a tree structure.

    To view the captured state of an object, a user needs to create IDCWindow, set the context on
    window as "BOM" for a structure, "Attachment" for attachments of bomline, "Activity" for activities
    of an operation. Open the request object or snapshot that store plmxml file or plmxml file itself in
    IDCwindow. The Root of the PLMXML file is set as the root of the IDCWindow.

    IDC also uses an alias file which basically determines what needs to be displayed in the window.
    The alias file will basically have three alias, Root, Children & Properties in the format
    <Context.aliasname>. The Root alias will determine the root of the window, children alias will
    determine the children for each line and the property alias determine the properties for each
    line in the window.

*/

/*  */

#ifndef IDC_H
#define IDC_H

#include <fclasses/tc_basic.h>
#include <ai/libai_exports.h>

#ifdef __cplusplus
        extern "C"{
#endif

/*==================================================================================================*/
/* END OF HEADER */

/**
   @defgroup IDC Intermediate Data Capture
   @{
*/

/**
    @name IDC Setup functions
    @{
*/

/**
    Initializes the IDC module.
    This function must be called before using any other IDC functions.
    This function will be called by the standard ITK startup code.
    The ITK programmer can ignore this function.
*/
extern AI_API int IDC_init_module();

/**
    Cleans up and exits the IDC module.
    This function will be called by the standard ITK exit code.
    The ITK programmer can ignore this function.
*/

extern AI_API int IDC_exit_module();

/** @} */

/**
    @name IDC Window Functions
    @{
*/

/**
    Creates a new IDC Window and returns the tag of the newly created window.
*/
extern AI_API int IDC_create_window
    (  const char* context,  /**< (I) Context for the window*/
       tag_t  *window        /**< (O) Tag of the newly created window */
    );

/**
    Close IDC Window
*/
extern AI_API int IDC_close_window
    ( tag_t  window   /**< (I) Tag of the window */
    );

/**
    Set the root of PLMXML structure as the top line of a given idc window.
    Any existing structure in this window is lost.
*/
extern AI_API int IDC_set_window_top_line
    ( tag_t window,              /**< (I) Tag of the window */
      const char* alias_file,    /**< (I) Alias xml file */
      const char* xml_file,      /**< (I) structure plmxml file */
      tag_t * idc_top_line       /**< (O) Tag of newly creted top line */
    );

/**
    Set the top line of the structure stored with the request object for
    a given idc window.
*/
extern AI_API int IDC_set_window_top_line_request
    ( tag_t window,                  /**< (I) Tag of the window */
      const char* preference_key,    /**< (I) Preference variable pointing to alias file */
      tag_t request,                 /**< (I) Tag of a request object */
      tag_t * idc_top_line           /**< (O) Tag of newly created top line */
    );

/**
    Set the top line of the structure stored with the snapshot dataset object for
    a given idc window.
*/
extern AI_API int IDC_set_window_top_line_snapshot
    ( tag_t window,                  /**< (I) Tag of the window */
      const char* preference_key,    /**< (I) Preference variable pointing to alias file */
      tag_t snapshot,                /**< (I) Tag of snapshot dataset */
      tag_t * idc_top_line           /**< (O) Tag of newly created top line */
    );

/**
    Set the idcline of one window as the topline of another window.
    This will use the plmxml file associated with the idcline window.
*/
extern AI_API int IDC_set_window_top_line_idcline
    ( tag_t window,                  /**< (I) Tag of the window */
      tag_t idc_line,                /**< (I) Tag of the idcline of another window */
      const char* preference_key,    /**< (I) Preference variable point to alias file */
      tag_t * idc_top_line           /**< (O) Tag of newly created top line */
    );

/**
    Returns the tag of the top line of the window
*/
extern AI_API int IDC_ask_window_top_line
    ( tag_t  window,           /**< (I) Tag of the window*/
      tag_t * idc_top_line     /**< (O) Window's top line */
    );

/**
    Returns all the roots of the window
*/
extern AI_API int IDC_ask_window_roots
    ( tag_t window,      /**< (I)   Tag of the window */
      int *count,        /**< (O)   Number of roots returned */
      tag_t **roots      /**< (OF)  Returned root tags */
    );

/**
    Replaces the root of the window with the specified line
*/
extern AI_API int IDC_change_window_top_line
   (  tag_t window,    /**< (I) Tag of window */
      tag_t idcLine    /**< (I) Tag of the root idcline */
   );

/** @} */

/**
    @name IDC Line Functions
    @{
*/

/**
    Returns the child lines of a specified parent line
    The first time this function is called it will load the lines
*/
extern AI_API int IDC_line_ask_child_lines
    ( tag_t idc_line,     /**< (I)  Tag of parent line */
      int   *count,       /**< (O)  Number of child line returned */
      tag_t **children    /**< (OF) Tags of returned lines */
    );

/** @} */

/** @} */

#ifdef __cplusplus
}
#endif

#include <ai/libai_undef.h>
#endif  /* IDC_H */
