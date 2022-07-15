/** @<COPYRIGHT_START>@    
===============================================    
 Copyright 2007 UGS Corp. All Rights Reserved.    
===============================================    
@<COPYRIGHT_END>@    
*/
    
/**     
    @file part.h 
    
    This header file declares functions related to Part type.    
*/

#ifndef PART_H
#define PART_H

#include <unidefs.h>
#include <tccore/libtccore_exports.h>

/**
    @defgroup PART Part
    @ingroup TCCORE
    @{
*/

#ifdef __cplusplus
    extern "C"{
#endif

/**
    Creates and saves a new part object.
    @note This itk will not save the object. AOM_save_with_extensions needs to be called separately to save the object.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PROP_id_name_exceeds_allowed_length, if part_number or part_name exceeds the allowed length of 128 characters.
    <li>#CXPOM_invalid_tag, if uom_tag is invalid.
    <li>#ALL_TYPE_invalid_type, if the provided part_type_name does not exists.
    <li>#PROP_invalid_value, if source of the Part Revision is not valid. Valid values are 0 - None, 1 - Make , 2 - Buy.
    </ul>
*/
extern TCCORE_API int PART_create_part (
                      const char *part_number,      /**< (I) identification number for the part. A null is allowed.
                                                             If null, the system will automatically generate a part number */
                      const char *part_desc,        /**< (I) description for the created part. A null is allowed. */
                      const tag_t uom_tag,          /**< (I) tag of Unit of Mesaure to be assign to part (may be #NULLTAG).
                                                            For more see #ITEM_set_unit_of_measure function */
                      const char *part_name,        /**< (I) common name or short description for the Part. A null is allowed. */
                      const char *part_type_name,   /**< (I) specify a defined Part type */
                      const char *rev_id,           /**< (I) Identification string (revision ID) of the Part Revision 
                                                            being created. A null is allowed. If null, the system will 
                                                            automatically generate a revision ID */
                      const logical is_design_reqd, /**< (I) specify whether a Design is required by this Part of not. 
                                                            This attrbiute is present on the master form of the Part */
                      const int source,             /**< (I) defines the source of the Part Revision, eg. make/buy. 
                                                            Valid values are 0 - None, 1 - Make , 2 - Buy.
                                                            This attribute is present on Part Revision Master form */
                      tag_t *part,                  /**< (O) Tag for identifying the Part in the current program */
                      tag_t *part_rev               /**< (O) Tag for identifying the Part Revision in the current program */
                     );

/**
   This itk is a wrapper on ITEM_create_item_with_masters2. It creates a new part type item and sets the required attributes 
   (is_designrequired and source) on the master forms with values specified by the user.
   @note This itk will not save the object. AOM_save_with_extensions needs to be called separately to save the object.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#ALL_TYPE_invalid_type, if the provided item_type does not exists.
   <li>#PROP_id_name_exceeds_allowed_length, if attrValues exceeds the allowed length of 128 characters.
   <li>#PROP_not_found, if any of the attribute name provided in attrNames does not exists or if the value of numAttrs is more than actual number of attributes in attrNames.
   <li>#PROP_invalid_value, if source of the Part Revision is not valid. Valid values are 0 - None, 1 - Make , 2 - Buy.
   </ul>
*/
extern TCCORE_API int PART_create_part2(
                      const char*         item_type,  /**< (I) It can be used to specify a defined Item type */
                      int                 numAttrs,   /**< (I) Number of input attributes */
                      char **             attrNames,  /**< (I) Names of input attributes */
                      char **             attrValues, /**< (I) Values for the input attributes*/
                      const char*         rev_id,     /**< (I) ID for the revision. A null is allowed. If null, the system will automatically generate a revision ID */
                      const logical       is_design_reqd, /**< (I) Specifies whether a Design is required by this Part of not. 
                                                                  This attrbiute is present on the master form of the Part */
                      const int           source,     /**< (I) Defines the source of the Part Revision, eg. make/buy. 
                                                               Valid values are 0 - None, 1 - Make , 2 - Buy.
                                                               This attribute is present on Part Revision Master form*/
                      tag_t*              part,       /**< (O) Tag for identifying the Part in the current program */
                      tag_t*              part_rev    /**< (O) Tag for identifying the Part Revision in the current program*/
    );


/**
    Associates a Part Revision object to Design Revision object using 
    TC_Is_Represented_by relation

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag, if either part_rev or design_rev tag is invalid.
    <li>#PART_DESIGN_ASSO_unable_to_associate, if unable to associate Part Revision object to Design Revision object.
    <li>#PART_DESIGN_jt_file_not_present, if JT file not attached to the Primary Representation.
    </ul>
*/
extern TCCORE_API int PART_rev_associate_design_rev(
                                 tag_t part_rev,    /**< (I) tag of Part Revision object */
                                 tag_t design_rev,  /**< (I) tag of Design Revision object */
                                 tag_t *rel_tag     /**< (O) tag of the relation object created */
                                 );

/**
    For a Part Revision object, this functions returns the Design Revisions objects assciated
    with TC_Is_Represented_by relation.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag, if part_rev tag is invalid.
    <li>#ALL_TYPE_unable_to_find, if unable to find associated Design Revision objects for given part_rev.
    </ul>
*/
extern TCCORE_API int PART_rev_ask_associated_design_revs(
                                tag_t part_rev,             /**< (I) tag of part revision */
                                int *design_revs_count,     /**< (O) no of Design Revision objects associated */
                                tag_t** design_revs         /**< (OF) design_revs_count Array of tags of associated Design Revision objects */
                                );

/**
    Sets Primary Design Representation for a Part Revision.
    A Part Revisions may be associated with multiple Design Revisions using the 
    TC_Is_Represented_by relation. One of the associated Design Revision object
    can be denoted as the Primary Representation.

    @note Primary Desing Representation will be used when a Part Revision is visualized in Portal Viewer

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag, if either part_rev or design_rev tag is invalid.
    <li>#ALL_TYPE_invalid_type, if design type or part type specified by design_rev or part_rev tag is invalid.
    </ul>
*/
extern TCCORE_API int PART_rev_set_primary_representation(
                                tag_t part_rev,     /**< (I) tag of Part Revision object */
                                tag_t design_rev    /**< (I) tag of the Design Revision object to be denoted as Primary */
                                );
/**
    Returns the Primary Design Representation for a Part revision object

    A Part Revisions may be associated with multiple Design Revisions using the 
    TC_Is_Represented_by relation. One of the associated Design Revision object
    can be denoted as the Primary Representation.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag, if part_rev tag is invalid.
    <li>#ALL_TYPE_unable_to_find, if unable to find primary Design Revision object.
    <li>#ITEM_internal_error, if Part revision have more than one Primary Design representations
    </ul>
*/
extern TCCORE_API int PART_rev_ask_primary_representation( 
                                tag_t part_rev,             /**< (I) tag of Part Revision object */
                                tag_t* primary_design_rev   /**< (O) tag of the Design Revision object which is Primary */
                                );

/**
Validates if a Part allows a Design Revision to be associated with it.
<br\>It will return the value of property set by the user for the global constant "Pma0DesignReqdPropNameOnPart" to indicate if the Design is required for part.

    @returns
    <ul>
    <li>#ITK_ok always
</ul>
*/
extern TCCORE_API int PART_ask_design_required(
                                tag_t* part_revs,                       /**< (I) The Part Revision objects.*/
                                int n_revs,                             /**< (I) The number of Part Revisions.*/
                                logical** design_required_values,       /**< (OF) n_revs Array of property values indicating if Design required for Part.*/
                                int** error_codes,                      /**< (OF) n_revs Array of error codes.
                                                                        <br/>#ITK_ok on success.
                                                                        <br/>#POM_invalid_tag, if any object in @p part_revs tag is invalid.
                                                                        <br/>#ALL_TYPE_invalid_type, if any object in @p part_revs tag is not of the type Part.
                                                                        <br/>#PROP_not_found, if invalid property is set in global constant "Pma0DesignReqdPropNameOnPart".*/
                                char*** error_messages                  /**< (OF) n_revs Array of error messages.
                                                                        <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only.*/
                                );

/**
    Validates if input Part(s) has multiple designs.
    <br\>It will return the value of property set by the user for the global constant "Fnd0MultipleDesignsPropName" to indicate if Part has multiple designs.

    @returns
    <ul>
    <li>#ITK_ok always
    </ul>
*/
extern TCCORE_API int PART_has_multiple_designs(
                                      const int n_revs,                       /**< (I) The number of Part Revisions.*/
                                      const tag_t* part_revs,                 /**< (I) The Part Revision objects.*/
                                      logical** has_multiple_design_values,   /**< (OF) n_revs Array of property values indicating if Part Part has multiple designs.*/
                                      int** error_codes,                      /**< (OF) n_revs Array of error codes.
                                                                              <br/>#ITK_ok on success.
                                                                              <br/>#POM_invalid_tag, if any object in @p part_revs tag is invalid.
                                                                              <br/>#ALL_TYPE_invalid_type, if any object in @p part_revs tag is not of the type Part.
                                                                              <br/>#PROP_not_found, if invalid property is set in global constant "Fnd0MultipleDesignsPropName".*/
                                      char*** error_messages                  /**< (OF) n_revs Array of error messages.
                                                                              <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only.*/
);


/** @} */

#ifdef __cplusplus
}
#endif

#include <tccore/libtccore_undef.h>
#endif
