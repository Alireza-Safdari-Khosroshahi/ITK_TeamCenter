/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Function prototypes for the unit of measure (UOM) ITK.
*/

/*  */

#ifndef UOM_H_INCLUDED
#define UOM_H_INCLUDED

#include <tccore/uom_errors.h>
#include <tccore/libtccore_exports.h>

/* END OF HEADER */

#ifdef __cplusplus
    extern "C"{
#endif

/**
    @defgroup UOM Unit of Measure (UOM)

    This module provides support for the creation and maintenance of Units of Measure (UOMs) for 
    a Teamcenter Engineering installation. A UOM can be attached to an Item to indicate, for example,
    that usages of engine oil part number 3487 must be expressed in quantities measured in pints.

    Standard UOMs are defined for a Teamcenter Engineering installation by the Teamcenter Engineering 
    system administrator using either System Administration interactive user interface or via this ITK module.

    @note The prototypes for these functions are in header file uom.h.

    <b>Common Return Values</b>

    <table>
    <tr><td>Return Value               </td><td>Description                                                      </td></tr>
    <tr><td>#POM_attr_null_forbidden   </td><td>Name or symbol is null or zero length.                           </td></tr>
    <tr><td>#POM_inst_violates_unique  </td><td>If a UOM of the same name and/or symbol already exists in the database,
                                                this error will be returned when you attempt to save the new UOM.</td></tr>
    <tr><td>#POM_invalid_string        </td><td>Name or symbol is too long.                                      </td></tr>
    <tr><td>#UOM_insufficient_privilege</td><td>This function is only available to Teamcenter Engineering
                                                system administrators.                                           </td></tr>
    <tr><td>#UOM_invalid               </td><td>Tag supplied is not a valid UOM.                                 </td></tr>
    </table>

    @{
*/

/**
    Returns a list of the UOMs defined for this Teamcenter Engineering installation.
*/
extern TCCORE_API int UOM_extent(
    int*                n_uoms,     /**< (O) Returns the number of UOMs in the list */
    tag_t**             uoms        /**< (OF) n_uoms Returned array of the tags of the UOMs */
    );

/**
    Inquires on the name of a UOM.
*/
extern TCCORE_API int UOM_ask_name(
    tag_t               uom,    /**< (I) Tag of the UOM */
    char**              name    /**< (OF) Returns the full name of the UOM */
    );

/**
    Inquires on the symbol text of a UOM.
*/
extern TCCORE_API int UOM_ask_symbol(
    tag_t               uom,    /**< (I) Tag of the UOM */
    char**              symbol  /**< (OF) Returns the symbol text of the UOM */
    );

/**
    Returns the tag of the UOM with the given name.
*/
extern TCCORE_API int UOM_find_by_name(
    const char*         name,   /**< (I) Name of the UOM */
    tag_t*              uom     /**< (O) Returns the tag of the UOM. 
                                    If no such UOM exists in the database, #NULLTAG is returned. */
    );

/**
    Returns the tag of the UOM with the given symbol.
*/
extern TCCORE_API int UOM_find_by_symbol(
    const char*         symbol,     /**< (I) Symbol of the UOM */
    tag_t*              uom         /**< (O) Returns the tag of the UOM. 
                                        If no such UOM exists in the database, #NULLTAG is returned. */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <tccore/libtccore_undef.h>

#endif

