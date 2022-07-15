/* @<COPYRIGHT_START>@    
===============================================    
Copyright 2007 UGS Corp. All Rights Reserved.    
===============================================    
@<COPYRIGHT_END>@    
*/    
    
/**     
    @file design.h 
    
    This header file declares functions related to Design type.        
*/

#ifndef DESIGN_H
#define DESIGN_H

#include <unidefs.h>
#include <tccore/libtccore_exports.h>

/**
    @defgroup DESIGN Design
    @ingroup TCCORE
    @{
*/

#ifdef __cplusplus
    extern "C"{
#endif

/**
    Create and save a Design object
    @note This itk will not save the object. AOM_save_with_extensions needs to be called separately to save the object.

    The function returns:
    <ul>
    <li>#ITK_ok on success
    <li>#PROP_id_name_exceeds_allowed_length, if design_id or design_name exceeds the allowed length of 128 characters.
    <li>#CXPOM_invalid_tag, if uom_tag is invalid.
    <li>#ALL_TYPE_invalid_type, if the provided design_type_name does not exists.
    </ul>
*/
extern TCCORE_API int DESIGN_create_design (
                      const char *design_id,        /**< (I) identification number for the Design. A null is allowed.
                                                             If null, the system will automatically generate a design_id */
                      const char *design_desc,      /**< (I) description for the Design, can be empty */
                      const tag_t uom_tag,          /**< (I) tag of Unit of Mesaure to be assign to part (may be #NULLTAG). 
                                                             For more see #ITEM_set_unit_of_measure function */
                      const char *design_name,      /**< (I) common name or short description for the Design. A null is allowed. */
                      const char *design_type_name, /**< (I) specify a defined Design type */
                      const char *rev_id,           /**< (I) Identification string (revision ID) of the Part Revision 
                                                             being created. A null is allowed. If null, the system will 
                                                             automatically generate a revision ID */
                      tag_t      *design_tag,       /**< (O) Tag for identifying the Design in the current program */
                      tag_t      *design_rev_tag    /**< (O) Tag for identifying the Design Revision in the current program */
                     );

/**
    Returns the Part Revision objects to which the Design Revision is 
    associated as secondary via TC_Is_Represented_by relation
     
    The function returns:
    <ul>
    <li>#ITK_ok on success
    <li>#ALL_TYPE_internal_error, if unable to find TC_Is_Represented_By relation type.
    <li>#CXPOM_invalid_tag, if design_rev is invalid.
    </ul>
*/
extern TCCORE_API int DESIGN_rev_ask_associated_part_revs(
                    tag_t design_rev,       /**< (I) Tag of Design Revision object */
                    int* part_revs_count,   /**< (O) number of associated Part Revision objects */
                    tag_t** part_revs       /**< (OF) part_revs_count Array of associated Part Revision objects */
                    );

/**
Validates if a Design allows a Part Revision to be associated with it.
<br\>It will return the value of the property set by the user for the global constant "Pma0PartReqdPropNameOnDesign" to indicate if the Part is required for designs.

@returns
<ul>
<li>#ITK_ok always
</ul>
*/

extern TCCORE_API int DESIGN_ask_part_required(
                                tag_t* design_revs,                          /**< (I) The Design Revision objects.*/
                                int n_revs,                                  /**< (I) The number of Design Revisions. */
                                logical** part_required_values,              /**< (OF) n_revs Array of property values indicating if Part required for Design.*/
                                int** error_codes,                           /**< (OF) n_revs Array of error codes.
                                                                             <br/>#ITK_ok on success.
                                                                             <br/>#POM_invalid_tag, if any object in @p design_revs is invalid.
                                                                             <br/>#ALL_TYPE_invalid_type, if any object in @p design_revs is not of the type Design.
                                                                             <br/>#PROP_not_found, if property set in global constant "Pma0PartReqdPropNameOnDesign" is invalid.*/
                                char*** error_messages                       /**< (OF) n_revs Array of error messages.
                                                                             <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only.*/
                                );

/** @} */
#ifdef __cplusplus
}
#endif
#include <tccore/libtccore_undef.h>
#endif
