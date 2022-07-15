/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This file contains helper functions for hrn related itks
*/

/*  */

#ifndef HRN_H
#define HRN_H

#include <epm/epm.h>
#include <unidefs.h>
#include <mechatronics/libmechatronics_exports.h>

/**
    @defgroup HRN Harness
    @ingroup MECHATRONICS

    This module defines the required ITK interface for HRN (Harness) related operations.
    @{
*/

#define HRN_INT_NULL (-9999)
#define HRN_STRING_NULL "NULL"
#define HRN_DOUBLE_NULL ((double)-9999.99)

/**
    <b>Structures in HRN</b>

    The occurrence specific attribute values for bomlines are set and returned using structures. The diferent structure and specific element access for these structures as given below.

    <b>Note:</b>

    All char* and char** type attributes in the structure are allocated memory for "get" methods of ITK. This memory allocated for all returning values of char* and char** need to be explicitly freed using SM_free.

    All structures to be passed as input should be initialized. For initializing any int, double or charecter to a null value, the following can be used:

    HRN_INT_NULL - This definition has a value as "-9999". This can be used to initialize an int value in the structure to null.

    HRN_DOUBLE_NULL - This definition has a value as "-9999.99". This can be used to initialize a double value in the structure to null.

    HRN_STRING_NULL - This definition has a value as "NULL". This can be used to initialize a charecter value in the structure to null.

    Certain harness part objects can have occurrence spscific attributes specified on them. These are deifned in the preference HRN_part_data_relation_primary. To access occurrence specific values for any of the bomlines of type or subtype specified in the preference, use structure HRN_part_occ_data_t:
    <table>
    <tr>
        <td>structure_name.id           </td>
        <td>Occurrence specific ID.     </td>
        <td>char *.                     </td>
    </tr>
    <tr>
        <td>structure_name.alias_count      </td>
        <td>Number of alias Ids specified.  </td>
        <td>int                             </td>
    </tr>
    <tr>
        <td>structure_name.alias_ids            </td>
        <td>Alias Ids specified for the bomline.</td>
        <td>char **                             </td>
    </tr>
    </table>

    In addition to the part occurrence data (id, alias_count, alias_ids), the HRN_ConHousing and its subtype have the following ocurrence specific attributes specified using structure HRN_connector_occ_data_t:
    <table>
    <tr><td>structure_name.usage    </td><td>Usage defined for the bomline</td>
    <td>char * </td></tr>
    </table>

    In addition to the part occurrence data (id, alias_count, alias_ids), the HRN_WireProtect and its subtype have the following ocurrence specific attributes specified in structure HRN_wire_protect_occ_data_t:
    <table>
    <tr><td>structure_name.protect_length    </td><td>protection length value on the bomline</td>
    <td>double </td></tr>
    </table>

    BOMLines of type HRN_Cavity (or subtype) can have the following occurrence specific attributes specified using structure HRN_cavity_occ_data_t:
    <table>
    <tr>
        <td>structure_name.id           </td>
        <td>Occurrence specific ID.     </td>
        <td>char *.                     </td>
    </tr>
    <tr>
        <td>structure_name.position_on_wire </td>
        <td>Position on wire specified on the line tag</td>
        <td>double                             </td>
    </tr>
    </table>

    BOMLines of type HRN_GeneralWire, HRN_Core (or subtype) can have the following occurrence specific attributes specified using structure HRN_general_wire_occ_data_t:
    <table>
    <tr>
        <td>structure_name.wire_number </td>
        <td>Wire number for the wire    </td>
        <td>char *                      </td>
    </tr>
    <tr>
        <td>structure_name.multiplier           </td>
        <td>Multiplier value for the line tag   </td>
        <td>char *                              </td>
    </tr>
    <tr>
        <td>structure_name.offset             </td>
        <td>Offset specified for the line tag</td>
        <td>char *                              </td>
    </tr>
    <tr>
        <td>structure_name.seperation_code     </td>
        <td>Seperation code specified for the line tag</td>
        <td>char *                              </td>
    </tr>
    </table>

    The Protection area defined on the wire protection type line have the following occurrence specific attributes specified in structure HRN_protection_area_data_t:
    <table>
    <tr>
        <td>structure_name.end_location </td>
        <td>Occurrence specific ID.     </td>
        <td>double                      </td>
    </tr>
    <tr>
        <td>structure_name.start_location   </td>
        <td>Number of alias Ids specified.  </td>
        <td>double                          </td>
    </tr>
    <tr>
        <td>structure_name.gradient             </td>
        <td>Alias Ids specified for the bomline.</td>
        <td>double                              </td>
    </tr>
    <tr>
        <td>structure_name.taping_direction     </td>
        <td>Alias Ids specified for the bomline.</td>
        <td>char *                              </td>
    </tr>
    </table>

    The Fixing Assignment defined on the line type of Fixing/Accessory (or their subtypes) have the following fixing assignment attributes specified in structure HRN_fixing_assignment_data_t:
    <table>
    <tr>
        <td>structure_name.location_value       </td>
        <td>The location value for the line tag where the segment is specified</td>
        <td>double                      </td>
    </tr>
    <tr>
        <td>structure_name.orientation_value</td>
        <td>The orientation value to be specified on the line tag  </td>
        <td>double[3]                          </td>
    </tr>
    </table>

    Certain harness types and subtypes , as specified in the preference HRN_wire_length_data_relation_primary, can have wire length information (length_type and length_value) specified on them. To retrieve all the wire length information associated to a bomline, use the structure HRN_wire_length_data_t:
    <table>
    <tr>
        <td>structure_name.length_type       </td>
        <td>The length type to be specified</td>
        <td>char *                      </td>
    </tr>
    <tr>
        <td>structure_name.length_value</td>
        <td>The length value for the perticular length type on the bomline</td>
        <td>double                          </td>
    </tr>
    </table>

    The item objects of type HRN_GeneralWire, HRN_Core and their subtypes can have wire color information associated on the item type. To retrieve all wire color information on a perticular item object tag use the structure HRN_wire_color_data_t:
    <table>
    <tr>
        <td>structure_name.color_type       </td>
        <td>The color type to be specified</td>
        <td>char *                      </td>
    </tr>
    <tr>
        <td>structure_name.color_value</td>
        <td>The color value for the perticular color type on the object tag</td>
        <td>char *                          </td>
    </tr>
    </table>

*/

typedef struct HRN_wire_length_data_s
{
    char *length_type;
    double length_value;
} HRN_wire_length_data_t, *HRN_wire_length_data_p_t;

typedef struct HRN_wire_color_data_s
{
    char *color_type;
    char *color_value;
} HRN_wire_color_data_t, *HRN_wire_color_data_p_t;

typedef struct HRN_fixing_assignment_data_s
{
    double location_value;
    double orientation_value[3];
} HRN_fixing_assignment_data_t, *HRN_fixing_assignment_data_p_t;

typedef struct HRN_connector_occ_data_s
{
    char* id;
    int alias_count;
    char** alias_ids;
    char* usage;
} HRN_connector_occ_data_t, *HRN_connector_occ_data_p_t;

typedef struct HRN_protection_area_data_s
{
    double end_location;
    double start_location;
    double gradient;
    char* taping_direction;
} HRN_protection_area_data_t, *HRN_protection_area_data_p_t;

typedef struct HRN_part_occ_data_s
{
    char* id;
    int alias_count;
    char** alias_ids;
} HRN_part_occ_data_t, *HRN_part_occ_data_p_t;

typedef struct HRN_cavity_occ_data_s
{
    char* id;
    double position_on_wire;
} HRN_cavity_occ_data_t, *HRN_cavity_occ_data_p_t;

typedef struct HRN_wire_protect_occ_data_s
{
    char* id;
    double protect_length;
    int alias_count;
    char** alias_ids;
} HRN_wire_protect_occ_data_t, *HRN_wire_protect_occ_data_p_t;

typedef struct HRN_general_wire_occ_data_s
{
    char* wire_number;
    char* multiplier;
    char* offset;
    char* seperation_code;
} HRN_general_wire_occ_data_t, *HRN_general_wire_occ_data_p_t;

#ifdef __cplusplus
    extern "C"{
#endif


/**
    Sets the part line tag as associated part to the cavity line tag


    <b>Restrictions:</b>
    If @p cavity_line is not a cavity line, this will throw an
    error - MECH_invalid_input
    <br/>Also, if @p part_line is not of the object type (or subtype of the object type)
    as specified in the preference, this will throw error MECH_invalid_input

*/
extern MECHATRONICS_API int HRN_set_associated_part(
    tag_t  cavity_line,  /**< (I) The cavity line tag   */
    tag_t  part_line,    /**< (I) The part line tag to be associated to the cavity */
    tag_t  *relation  /**< (O) The relation tag returned by the association */
    );

/**
   Asks all the associated parts to the cavity line tag

   <b>Restrictions:</b>
   If @p cavity_line is not a cavity line, this will throw an
   error - MECH_invalid_input

*/
extern MECHATRONICS_API int HRN_ask_associated_parts (
    tag_t  cavity_line,          /**< (I) The cavity line tag   */
    int *associated_parts_count,     /**< (O) The number of associated parts to the cavity */
    tag_t **associated_parts     /**< (OF) associated_parts_count The tags fot the associated parts */
    );

/**
    Unsets the part line tag from the cavity line tag

    <b>Restrictions:</b>
    If @p cavity_line is not a cavity line, this will throw an
    error - MECH_invalid_input
    <br/>Also, if @p part_line is not of the object type(or subtype of the object type)
    as specified in the preference, this will throw error MECH_invalid_input

    If there is no association between the cavity_line and part_line, this will throw error

*/
extern MECHATRONICS_API int HRN_unset_associated_part(
    tag_t  cavity_line, /**< (I) The cavity line tag   */
    tag_t  part_line    /**< (I) The part line tag to be un-associated to the cavity */
    );


/**
   Retrieves the segments that are associated to the wire
   protection line

   <b>Restrictions:</b>
    If @p wire_protection_line is not a wire protection line,
    or if any of @p segments are not of segment objects this will throw
    an error - MECH_invalid_input

*/
extern MECHATRONICS_API int HRN_ask_wire_protection_segments (
    tag_t   wire_protection_line,   /* <I> */
    int     *n_segments,                /* <O> */
    tag_t   **segments              /* <OF> */
);

/**
   Sets multiple segment objects to the wire protection line

    <b>Restrictions:</b>
    If @p wire_protection_line is not a wire protection
    line, or if any of the segments are not of segment objects, this
    will throw an error - MECH_invalid_input
*/
extern MECHATRONICS_API int HRN_set_wire_protection_segments (
    tag_t  wire_protection_line,    /* <I> */
    int n_segments,                     /* <I> */
    tag_t* segments                 /* <I> */
);

/**
   Unsets multiple segment objects that are associated
    to the wire protection line

    <b>Restrictions:</b>
    If @p wire_protection_line is not a wire protection line,
    or if any of @p segments are not segment objects this will throw an
    error - MECH_invalid_input

    If @p segments are not associated to @p wire_protection_line, this will
    throw error
*/
extern MECHATRONICS_API int HRN_unset_wire_protection_segments (
    tag_t   wire_protection_line,   /* <I> */
    int     n_segments,                 /* <I> */
    tag_t*  segments                /* <I> */
);


/**
    Adds protection area information to the wire protection line tag

    <b>Restrictions:</b>
    If @p wire_protect_line cannot have a wire protection information attached, this will throw an error - MECH_invalid_input

*/
extern MECHATRONICS_API int HRN_set_protection_area_data (
    tag_t wire_protect_line,                        /**< (I) */
    const HRN_protection_area_data_t* protect_area_data /**< (I) List having values for protection area*/
    );


/**
  Retrieves the protection area information to the wire protection line tag

  <b>Restrictions:</b>
  If @p wire_protect_line is not a wire protection bom line tag this will throw error - MECH_invalid_input

*/
extern MECHATRONICS_API int HRN_get_protection_area_data (
    tag_t wire_protect_line,                    /**< (I) */
    HRN_protection_area_data_t* protect_area_data   /**< (O) List having values for protection area*/
    );


/**
   Removes protection area information to the wire protection line tag

   <b>Restrictions:</b>
    If @p wire_protect_line is not a wire protection bom line tag this will throw error - MECH_invalid_input
    <br>If @p wire_protect_line does not have wire protection information attached, this will throw an error - MECH_invalid_input
*/
extern MECHATRONICS_API int HRN_remove_protection_area_data (
    tag_t wire_protect_line         /**< (I) */
    );


/**
   Sets segment object to the fixing or accessory line

   <b>Restrictions:</b>
   If @p bom_line is not a fixing/acessory line, or if @p segment is not of segment object this will throw an error - MECH_invalid_input

    If a segment is already associated to the bom_line, this will throw error - HRN_duplicate_association
*/
extern MECHATRONICS_API int HRN_set_fixing_segment(
    tag_t  bom_line,     /**< (I) The fixing/accessory line tag   */
    tag_t  segment,      /**< (I) The segment tag to be associated to the bom line tag */
    tag_t  *relation  /**< (O) The relation tag associating the bom line with the segment */
    );

/**
   Retrieves the segment tag that is associated to the fixing or accessory line

   <b>Restrictions:</b>
   If @p bom_line is not a fixing/acessory line, or if @p segment
   is not of segment object this will throw an error - MECH_invalid_input
*/
extern MECHATRONICS_API int HRN_ask_fixing_segment (
    tag_t  bom_line,            /**< (I) The fixing/accessory line tag   */
    tag_t  *segment             /**< (O) The segment tag associated to the bom line tag */
    );


/**
   Adds fixing assignment information to the fixing/accessory line tag

   <b>Restrictions:</b>
   If @p fixing_line cannot have a fixing assignment information attached, this will throw an error - MECH_invalid_input

*/
extern MECHATRONICS_API int HRN_set_fixing_assignment_data (
    tag_t fixing_line,                              /**< (I) */
    const HRN_fixing_assignment_data_t* assignment_data /**< (I) List having values for location_value and orientation_value */
    );


/**
   Retrieves fixing assignment information to the fixing/accessory line tag

   <b>Restrictions:</b>
   If @p fixing_line cannot have a fixing assignment information attached, this will throw an error - MECH_invalid_input
*/
extern MECHATRONICS_API int HRN_get_fixing_assignment_data (
    tag_t fixing_line,                          /**< (I) */
    HRN_fixing_assignment_data_t* assignment_data   /**< (O) List having values for location_value and orientation_value */
    );


/**
   Removes fixing assignment information to the fixing/accessory line tag

   <b>Restrictions:</b>
   If @p fixing_line cannot have a fixing assignment information attached, this will throw an error - MECH_invalid_input
   <br/>If no fixing assignment information exists for @p fixing_line, this will throw an error - HRN_no_association

*/
extern MECHATRONICS_API int HRN_remove_fixing_assignment_data (
    tag_t fixing_line            /**< (I) */
    );


/**
   Unsets segment object that is associated to the fixing or accessory line

   <b>Restrictions:</b>
   If @p bom_line is not a fixing/acessory line, or if @p
   segment is not of segment object this will throw an error - MECH_invalid_input
   <br/>If @p segment is not associated to bom_line, this will throw error
*/
extern MECHATRONICS_API int HRN_unset_fixing_segment(
    tag_t  bom_line,   /**< (I) The fixing/accessory line tag   */
    tag_t  segment     /**< (I) The segment tag to be un-associated to the bom line tag */
    );

/**
   Retrieves all referenced components associated to the Node object

   <b>Restrictions:</b>
   If @p node is not of node object this will throw an error - MECH_invalid_input
   Also, @p window must be specified
*/
extern MECHATRONICS_API int HRN_ask_referenced_component (
    tag_t  node,                /**< (I) The node tag   */
    tag_t  window,              /**< (I) Tag of the window in which the referenced components would be listed */
    int *reference_comp_count,      /**< (O) The referenced components count  */
    tag_t **reference_comps     /**< (OF) reference_comp_count Tag of referenced components */
    );

/**
   Sets BOMLine as referenced component to the Node object

   <b>Restrictions:</b>
   If @p note is not of node object, or if the referenced component tag is not of the object type (or subtype of the object type) as apecified in preference, this will throw an error - MECH_invalid_input
*/
extern MECHATRONICS_API int HRN_set_referenced_component(
    tag_t  node,              /**< (I) The node tag   */
    tag_t  reference_comp,    /**< (I) The bom line tag to be added as referenced component */
    tag_t  *relation       /**< (O) The relation tag that associates the node to reference component */
    );

/**
   Unsets BOMLine as referenced component to the Node object

   <b>Restrictions:</b>
   If @p node is not of node object, or if the referenced component tag is not of the object type as apecified in preference, this will throw an error - MECH_invalid_input
   <br/>If no association is made between @p node and @p reference_comp, an error will be thrown
*/
extern MECHATRONICS_API int HRN_unset_referenced_component(
    tag_t  node,             /**< (I) The node tag   */
    tag_t  reference_comp    /**< (I) The bom line tag to be removed from referenced component association */
    );


/**
   Adds part occurrence information to the bom line tag

    <b>Restrictions:</b>
    If @p bom_line cannot have a part occurrence data attached, this will throw an error - MECH_invalid_input
*/
extern MECHATRONICS_API int HRN_set_part_occ_data (
    tag_t  bom_line,                     /**< (I) */
    const HRN_part_occ_data_t* part_occ_data /**< (I) List having values for part occurrence data*/
    );


/**
   Retrieves part occurrence information to the bom line tag

   <b>Restrictions:</b>
    If @p bom_line does not have a part occurrence data attached, this will throw an error - HRN_no_association
*/
extern MECHATRONICS_API int HRN_get_part_occ_data (
    tag_t  bom_line,                /**< (I) */
    HRN_part_occ_data_t* part_occ_data  /**< (O) List having values for part occurrence data*/
    );


/**
   Removes part occurrence information to the bom line tag

   <b>Restrictions:</b>
   If @p bom_line does not have a part occurrence data attached, this will throw an error - HRN_no_association
   <br/>If part occurrence data does not exists for this part occurrence data, this will throw an error - HRN_no_association

*/
extern MECHATRONICS_API int HRN_remove_part_occ_data (
    tag_t  bom_line                /**< (I) */
    );

/**
   Adds connector housing occurrence to the bom line tag

   <b>Restrictions:</b>
    If @p bom_line cannot have a connector housing occurrence data attached, this will throw an error - MECH_invalid_input
*/
extern MECHATRONICS_API int HRN_set_connector_occ_data (
    tag_t bom_line,                                 /**< (I) */
    const HRN_connector_occ_data_t* connector_occ_data  /**< (I) List having values for connector occurrence data*/
    );


/**
   Retrieves connector housing occurrence to the bom line tag

   <b>Restrictions:</b>
    If @p bom_line cannot have a connector housing occurrence data attached, this will throw an error - MECH_invalid_input
*/
extern MECHATRONICS_API int HRN_get_connector_occ_data (
    tag_t bom_line,                             /**< (I) */
    HRN_connector_occ_data_t* connector_occ_data    /**< (O) List having values for connector occurrence data*/
    );

/**
    Removes connector housing occurrence to the bom line tag

    <b>Restrictions:</b>
    If @p bom_line cannot have a connector housing occurrence data attached, this will throw an error - MECH_invalid_input
    <br/>If connector housing occurrence data  does not exists for this bom_line, this will throw an error - HRN_no_association

*/
extern MECHATRONICS_API int HRN_remove_connector_occ_data (
    tag_t  bom_line              /**< (I) */
    );

/**
   Adds cavity instance data to the cavity line tag

   <b>Restrictions:</b>
    If @p cavity_line cannot have a cavity instance data attached, this will throw an error - MECH_invalid_input
*/
extern MECHATRONICS_API int HRN_set_cavity_data (
    tag_t cavity_line,                          /**< (I) */
    const HRN_cavity_occ_data_t* cavity_occ_data    /**< (I) List having values for cavity occurrence data*/
    );


/**
   Retrieves cavity instance data to the cavity line tag

   <b>Restrictions:</b>
   If @p cavity_line cannot have a cavity instance data attached, this will throw an error - MECH_invalid_input
*/
extern MECHATRONICS_API int HRN_get_cavity_data (
    tag_t cavity_line,                  /**< (I) */
    HRN_cavity_occ_data_t* cavity_occ_data  /**< (O) List having values for cavity occurrence data*/
    );

/**
   Removes cavity instance data to the cavity line tag

   <b>Restrictions:</b>
   If @p cavity_line cannot have a cavity instance data attached, this will throw an error - MECH_invalid_input
   <br/>If cavity instance data does not exists for this bom_line, this will
   throw an error - HRN_no_association
*/
extern MECHATRONICS_API int HRN_remove_cavity_data (
    tag_t cavity_line          /**< (I) */
    );

/**
  Adds wire protection instance data to a BOMLine.

  <b>Restrictions:</b>
  If @p bom_line cannot have a  wire protection instance data attached, this will throw an error - MECH_invalid_input
*/
extern MECHATRONICS_API int HRN_set_wire_protect_occ_data (
    tag_t bom_line,                                         /**< (I) */
    const HRN_wire_protect_occ_data_t* wire_protect_occ_data    /**< (I) List having values for wire protection occurrence data*/
    );


/**
   Retrieves wire protection instance data to a BOMLine.

   <b>Restrictions:</b>
   If @p bom_line cannot have a wire protection instance data attached, this will throw an error - MECH_invalid_input
*/
extern MECHATRONICS_API int HRN_get_wire_protect_occ_data (
    tag_t bom_line,                                 /**< (I) */
    HRN_wire_protect_occ_data_t* wire_protect_occ_data  /**< (O) List having values for wire protection occurrence data*/
    );


/**
   Removes wire protection instance data to a BOMLine.

    <b>Restrictions:</b>
    If @p bom_line cannot have a  wire protection instance data attached, this will throw an error - MECH_invalid_input
    <br/>If  wire protection instance data does not exists for this bom_line,
    this will throw an error - HRN_no_association
*/
extern MECHATRONICS_API int HRN_remove_wire_protect_occ_data (
    tag_t  bom_line             /**< (I) */
    );

/**
   Adds general wire/core occurrence data to a line.

   <b>Restrictions:</b>
   <br/>If @p line cannot have a general wire/core occurrence data attached, this will throw an error - MECH_invalid_input

*/
extern MECHATRONICS_API int HRN_set_general_wire_occ_data (
    tag_t line,                                     /**< (I) */
    const HRN_general_wire_occ_data_t *wire_occ_data    /**< (I) */
    );

/**
   Retrieves general wire/core occurrence data to a line.

   <b>Restrictions:</b>
    If @p line cannot have a  wire number data attached, this will throw an error - MECH_invalid_input
*/
extern MECHATRONICS_API int HRN_get_general_wire_occ_data (
    tag_t line,                                 /**< (I) */
    HRN_general_wire_occ_data_t *wire_occ_data      /**< (O) List having values for general wire/core occurrence data */
    );

/**
   Removes general wire/core occurrence data to a line.

   <b>Restrictions:</b>
    If @p line cannot have a general wire/core occurrence data attached, this will throw an error - MECH_invalid_input
*/
extern MECHATRONICS_API int HRN_remove_general_wire_occ_data (
    tag_t line              /**< (I) */
    );

/**
   Adds wire length information to a BOMLine.

    <b>Restrictions:</b>
    If @p bom_line cannot have a wire length information attached,
    this will throw an error - MECH_invalid_input
    If @p length_type already exists for this bom_line, it will be
    updated with the new length_value sent
*/
extern MECHATRONICS_API int HRN_set_wire_length_information (
    tag_t bom_line,              /**< (I) The bom line for which the wire length information has to be added */
    const char *length_type,     /**< (I) The length type */
    double length_value          /**< (I) The length value */
    );

/**
   Retrieves the length value of given length type attached to a BOMLine.

    <b>Restrictions:</b>
    If @p bom_line cannot have a wire length information attached,
    this will throw an error - MECH_invalid_input
*/
extern MECHATRONICS_API int HRN_get_wire_length_information (
    tag_t bom_line,               /**< (I) The bom line from which wire length information has to be obtained */
    const char *length_type,      /**< (I) The length type required */
    double *length_value          /**< (O) The length value */
    );

/**
   Retrieves all wire length information attached to a BOMLine.

    <b>Restrictions:</b>
    If @p bom_line  cannot have a wire length information attached,
    this will throw an error - MECH_invalid_input

*/

extern MECHATRONICS_API int HRN_get_all_wire_length_information (
    tag_t bom_line,                         /**< (I) The bom line from which wire length information has to be obtained */
    int* count,                             /**< (O) Number of wire length objects found */
    HRN_wire_length_data_t** length_data    /**< (OF) Count list of lenth type and length value */
    );

/**
    Deletes wire length information to a BOMLine.

    <b>Restrictions:</b>
    If @p bom_line cannot have a wire length information
    attached, this will throw an error - MECH_invalid_input
    <br/>If no wire length information with the specified length_type exists for this bom_line, this will throw an error - HRN_no_association
*/
extern MECHATRONICS_API int HRN_remove_wire_length_information (
    tag_t bom_line,             /**< (I) The bom line from which wire length information has to be removed */
    const char *length_type     /**< (I) The length type to be removed */
    );

/**
    Adds wire color information to an object.

    <b>Restrictions:</b>
    @p object has to be an item tag of type HRN_GeneralWire/ HRN_Code or subtype of these item types.
    <br/>If @p object cannot have a  color information attached, this will throw an error - MECH_invalid_input
    <br/>If @p color_type already exists for this bom_line, it will be updated with the new color_value sent

*/
extern MECHATRONICS_API int HRN_set_wire_color (
    tag_t object,              /**< (I) */
    const char *color_type,        /**< (I) */
    const char *color_value        /**< (I) */
    );

/**
   Retrieves wire color information to an object.

   <b>Restrictions:</b>
   @p object has to be an item tag of type HRN_GeneralWire/ HRN_Code or subtype of these item types.
   <br/>If @p object cannot have a color information attached, this will throw an error - MECH_invalid_input
*/
extern MECHATRONICS_API int HRN_get_wire_color (
    tag_t object,              /**< (I) */
    const char *color_type,        /**< (I) */
    char **color_value             /**< (OF) Pointer to char * to return the color value */
    );

/**
   Retrieves wire color information associated to an object.

   <b>Restrictions:</b>
   @p object has to be an item tag of type HRN_GeneralWire/ HRN_Code or subtype of these item types.
   <br/>If @p object cannot have a  color information attached, this will throw an error - MECH_invalid_input
*/
extern MECHATRONICS_API int HRN_get_all_wire_color (
    tag_t object,                          /**< (I) */
    int* count,                                /**< (O) */
    HRN_wire_color_data_t** wire_color_data    /**< (OF) Count number of color_type and color_value information */
    );

/**
   Removes wire color information to an object.

   <b>Restrictions:</b>
   @p object has to be an item tag of type HRN_GeneralWire/ HRN_Code or subtype of these item types.
   <br/>If @p object cannot have a  color information attached(not a HRN_GeneralWire/HRN_Core or subtype of these two types), this will throw an error - MECH_invalid_input
    <br/>If the color information with @p color_type does not exist for this object, this will throw an error - HRN_no_association
*/
extern MECHATRONICS_API int HRN_remove_wire_color (
    tag_t object,             /**< (I) */
    const char *color_type        /**< (I) */
    );


/**
   This function implements EPM action handler HRN_capital_set_release_state

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#EPM_invalid_argument if the number of arguments available is not appropriate for the handler.
    </ul>
*/
extern MECHATRONICS_API int HRN_capital_set_release_state(
    EPM_action_message_t msg /**< (I) */
);

/**
   This function implements EPM action handler HRN_capital_set_reject_state

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#EPM_invalid_argument if the number of arguments available is not appropriate for the handler.
    </ul>
*/
extern MECHATRONICS_API int HRN_capital_set_reject_state(
    EPM_action_message_t msg /**< (I) */
);

/**
    This function implements EPM action handler HRN_capital_revise.
    <br\>This handler when used in a workflow template will fetch all the electrical designs for the target Teamcenter design through webservices and then revise the teamcenter and the corresponding electrical designs.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#EPM_invalid_argument if the number of arguments available is not appropriate for the handler.
    </ul>
*/
extern MECHATRONICS_API int HRN_capital_revise(
    EPM_action_message_t msg /**< (I) */
);

/** @} */

#ifdef __cplusplus
}
#endif

#include <mechatronics/libmechatronics_undef.h>
#endif
