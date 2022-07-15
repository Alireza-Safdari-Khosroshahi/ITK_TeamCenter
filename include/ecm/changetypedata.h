/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This include file contains the definitions for the ITK functions to access ChangeTypeData.
*/

/*  */

#ifndef CHANGETYPEDATA_H
#define CHANGETYPEDATA_H

#include <unidefs.h>
#include <ecm/ecm_errors.h>
#include <ecm/libecm_exports.h>

#ifdef __cplusplus
    extern "C"{
#endif

/**
    @defgroup CHANGETYPEDATA Change Type Data
    @ingroup ECM
    @{
*/

/**
    Finds the change type of the specified name.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#ECM_unable_to_get_typename if @p changetype_name is not a valid Change Type
    <li>Possibly other ECM errors
    </ul>
*/
extern ECM_API int ECM_find_change_type(
    const char*    changetype_name,     /**< (I) Name of Change Type to be searched */
    tag_t*         change_type          /**< (O) Tag of type change type requested.
                                            This will return #NULLTAG if it is not found. */
    );

/**
    Retrieves all available change types in the database.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>Possibly some ECM errors
    </ul>
*/
extern ECM_API int ECM_get_all_change_types(
    int*           n_types,             /**< (O) Number of change types in the database */
    tag_t**        changetypes          /**< (OF) n_types Array of tags for the change types */
    );

/**
    Retrieves all process templates for the given change type.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if @p change_type is invalid
    <li>Possibly some ECM errors
    </ul>
*/
extern ECM_API int ECM_ask_processes_of_type(
    tag_t          change_type,      /**< (I) Tag of the Change type */
    int*           n_processes,      /**< (O) Number of process templates */
    char***        process_strs      /**< (OF) n_processes Process template list.    
                                        <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only. */
    );

/**
    Retrieves all form types for the given change type.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if @p change_type is invalid
    <li>Possibly some ECM errors
    </ul>
 */
extern ECM_API int ECM_ask_formtypes_of_type(
    tag_t          change_type,       /**< (I) Tag of change type */
    int*           n_types,           /**< (O) The number of form types */
    tag_t**        formtypes          /**< (OF) n_types Array of tags for the form types */
    );

/**
    Retrieves the name for the given change type tag.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if @p change_type is invalid
    <li>#ECM_unable_to_get_typename if @p change_type is not a valid Change Type
    <li>Possibly some ECM errors
    </ul>
*/
extern ECM_API int ECM_ask_typename(
    tag_t          change_type,         /**< (I) Tag of change type */
    char**         changetype_name      /**< (OF) Change type name */
    );

/**
    Retrieves the ID format for the given Change Type.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if @p change_type is invalid
    <li>#ECM_unable_to_get_idformat if id format does not exist
    <li>Possibly some ECM errors
    </ul>
*/
extern ECM_API int ECM_ask_idformat(
    tag_t          change_type,       /**< (I) Tag of Change type */
    tag_t*         id_format          /**< (O) ID format tag */
    );

/**
    Retrieves the EC Revision ID format for the given Change Type.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if @p change_type is invalid
    <li>#ECM_unable_to_get_revidformat if id format does not exist
    <li>Possibly some ECM errors
    </ul>
*/
extern ECM_API int ECM_ask_revidformat(
    tag_t          change_type,       /**< (I) Tag of change type */
    tag_t*         revision_id_format /**< (O) Rev ID format tag */
    );

/**
    Retrieves the value for 'is_effectivity_shared' flag.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if @p change_type is invalid
    <li>Possibly some ECM errors
    </ul>
*/
extern ECM_API int ECM_is_effectivity_shared(
    tag_t          change_type,       /**< (I) Tag of Change type */
    logical*       is_shared          /**< (O) Returns true or false */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <ecm/libecm_undef.h>
#endif
