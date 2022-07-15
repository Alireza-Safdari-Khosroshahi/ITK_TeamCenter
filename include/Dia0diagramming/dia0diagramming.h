/*
// Copyright 2020 Siemens Digital Industries Software
// ==================================================
// Copyright 2015
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2020 Siemens Digital Industries Software
*/
/**
    @file

    This header file declares all functions,  data types and constants to be used by diagramming.

*/

#ifndef DIA0DIAGRAMMING_DIA0DIAGRAMMING_H
#define DIA0DIAGRAMMING_DIA0DIAGRAMMING_H

#include <unidefs.h>
#include <Dia0diagramming/libdia0diagramming_exports.h>


/**
    @defgroup DIA0DIAGRAMMING Diagramming Application
    @ingroup TC
    To manage System Engineering Diagrams for the 4GD model elements specifically Logical and Requirements.
    <br/>This will allow designing interactions between different partition breakdowns diagrammatically.
    @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/**
Finds all the Diagrams associated to an object.
<br/> If the value for the parameter @p partition is empty, all elements in the subset are returned.
<br/> If the value for the parameter @p ctxt_obj is empty, all elements are returned.

@returns
<ul>
<li>#ITK_ok on success.
<li>#DIAGRAMMING_find_diagram_invalid_bo_type if the object is not of type Model Element, Ordered Element Group, or Conditional Element Group.
<li>#POM_invalid_tag error if the input object is invalid.
</ul>

*/
extern DIA0DIAGRAMMING_API int DIA0_find_diagrams (
        tag_t  object,                      /**< (I) The tag of the object to search the diagrams for. */
        tag_t  partition,                   /**< (I) The tag of the Partition object */
        tag_t  ctxt_obj,                    /**< (I) The tag of the configuration context object */
        int*   count,                       /**< (O) The size of the found_diagram_tags array */
        tag_t** found_diagram_tags          /**< (OF) count Array of found objects */
    );


/**
Finds all the elements in a partition that are not part of any diagram sheet(s).
<br/> If the value for the parameter @p ctxt_obj is empty, all elements are returned.

@returns
<ul>
<li>#ITK_ok on success.
<li>#DIAGRAMMING_missing_partition if no object is provided.
<li>#POM_invalid_tag error if the input object is invalid.
</ul>

*/
extern DIA0DIAGRAMMING_API int DIA0_query_unassociated_partitioned_elements (
        int    sheet_count,                 /**< (I) The size of the sheet_tags array. */
        const tag_t* sheet_tags,            /**< (I) sheet_count array of the Sheet objects */
        tag_t  partition,                   /**< (I) The tag of the Partition object */
        tag_t  ctxt_obj,                    /**< (I) The tag of the configuration context object */
        int*   count,                       /**< (O) Number of found objects */
        tag_t** found_element_tags          /**< (OF) count Array of found objects  */
    );

/**
For a Schematic Sheet member of a Partition, finds the elements which belong to the Schematic Sheet and are not the members of the Partition.
<br/>If the Schematic Sheet is not a member of a Partition, an error is returned.
<br/> If the value for the parameter @p ctxt_obj is empty, all elements are returned.

@returns
<ul>
<li>#ITK_ok on success.
<li>#DIAGRAMMING_missing_sheet if an invalid Sheet is provided.
<li>#DIAGRAMMING_missing_partition if the provided Sheet does not contain any Partition.
<li>#MDC0MDC_no_unique_model_element if more than one associated partition exists for the Schematic Sheet.
<li>#POM_invalid_tag error if the input object is invalid.
</ul>

*/
extern DIA0DIAGRAMMING_API int DIA0_query_sheet_elements_not_associated (
        tag_t  sheet,                       /**< (I) The tag of the Schematic Sheet object */
        tag_t  ctxt_obj,                    /**< (I) The tag of the configuration context object */
        int*   count,                       /**< (O) Number of found objects */
        tag_t** found_element_tags          /**< (OF) count Array of found objects  */
    );


/**
Finds the elements that belong to the Schematic Sheet and are in the @p element_tags list.
<br/>If the value for the parameter @p element_tags is empty, all elements in the subset are returned.
<br/>Otherwise, only the elements in both the subset and the @p element_tags list are returned.

@returns
<ul>
<li>#ITK_ok on success.
<li>#DIAGRAMMING_missing_sheet the specified Schematic Sheet is invalid
<li>#POM_invalid_tag error if the input object is invalid.
</ul>

*/
extern DIA0DIAGRAMMING_API int DIA0_query_sheet_elements_associated_with (
        tag_t  sheet,                       /**< (I) The tag of the Schematic Sheet object */
        int    element_count,               /**< (I) The size of the element_tags array. */
        const tag_t* element_tags,          /**< (I) element_count Array of the Conditional Elements object */
        int*   count,                       /**< (O) Number of found objects */
        tag_t** found_element_tags          /**< (OF) count Array of found objects  */
    );

#ifdef __cplusplus
}
#endif

/** @} */

#include <Dia0diagramming/libdia0diagramming_undef.h>
#endif
