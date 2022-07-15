/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This header file contains constants and ITK functions for the Form class.
*/

/*  */

#ifndef FORM_H
#define FORM_H

#include <tccore/workspaceobject.h>
#include <form/libform_exports.h>

/**
    @defgroup FORM Forms

    Forms are WorkspaceObjects that give the user access to a set of name-value pairs and
    a form definition file used to display the form. 
    The actual name-value pairs can be stored in an ImanFile or in an instance of a POM class defined by us or the user.

    Because Forms are WorkspaceObject's, WSOM and AOM functions work on instances of Form.

    To use these functions include form.h.

    @note The variable const char* form_file_name should be the name of the FormType.
    FormType is an ImanType. The system administrator is responsible for defining all of the Form Types.

    @{
*/

#ifdef __cplusplus
    extern "C"{
#endif

/**
    Lists all instances of class Form in the database.
*/
extern FORM_API int FORM_extent(
    int*            n_instances,    /**< (O) */
    tag_t**         instances       /**< (OF) n_instances */
    );

/**
    Creates a form object in the database. 

    @note From Tc9.0 onwards, please use generic creation of BusinessObject (i.e. createBusinessObject (C++) or #TCTYPE_create_object).

    @returns 
    <ul>
    <li>#ITK_ok on success.
    <li>Possibly some errors.
    </ul>
*/
extern FORM_API int FORM_create2(
    const char*     name,             /**< (I) The Form name. */
    const char*     description,      /**< (I) The Form description. */
    const char*     type,             /**< (I) The Form type.
                                         <br/>It also:
                                         <ul>
                                         <li>determines the behavior of the Form, 
                                         <li>identifies the name of the file that contains the
                                         definition of the Form for use in the user interface.
                                         <li>identifies the @c pom_class_name used to have the Form values placed in the database.
                                         </ul>
                                      */
    tag_t*          new_form          /**< (O) The create Form. */
    );

/**
    Creates a fresh instance of object form which is exact copy of source form.

    @note Save must be explicitly called for the newly created form.
*/
extern FORM_API int FORM_copy2(
    const char      *new_name,                      /**< (I) The name for new Form. */
    tag_t*          source_form,                    /**< (I) The source Form. */
    tag_t*          new_form                        /**< (O) The newly created Form. */
    );

/**
    Initializes the Form attributes for a newly created instance of a subclass of Form.
*/
extern FORM_API int FORM_initialize2(
    tag_t           form,                               /**< (I) */
    const char      *form_name,                         /**< (I) */
    const char      *description,                       /**< (I) */
    const char*     form_type                           /**< (I) */
    );


/**
    Retrieves the object that actually contains all of the name-value pairs.
    This could be an ImanFile or a instance of a class.
*/
extern FORM_API int FORM_ask_pom_instance(
    tag_t           form,           /**< (I) */
    tag_t*          pom_instance    /**< (O) */
    );

extern FORM_API int FORM_null_pom_instance(
    tag_t           form    /**< (I) */
    );

extern FORM_API int FORM_ask_prop_names(
    tag_t           form,           /**< (I) */
    int*            n_prop_names,   /**< (O) The number of property associated with the given form identified by form */
    char***         prop_names      /**< (OF) n_prop_names Property names of the given form identified by form.
                                        Each property name string in prop_names array must be separately freed,
                                        and then prop_names array is freed. */
    );

extern FORM_API int FORM_ask_property_descriptors(
    tag_t           form,                  /**< (I) */
    int*            n_prop_descriptors,    /**< (O) */
    tag_t**         prop_descriptors       /**< (OF) n_propdescs */      
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <form/libform_undef.h>
#endif
