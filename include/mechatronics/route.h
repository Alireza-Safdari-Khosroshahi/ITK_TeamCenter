/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This file contains API interface definition for route objects.
*/

/*  */

#ifndef ROUTE_H
#define ROUTE_H

#include <unidefs.h>
#include <mechatronics/libmechatronics_exports.h>

/**
    @defgroup ROUTE Route
    @ingroup MECHATRONICS

    This module defines the ITK interface for route related operations.
    @{
*/

/**
    @name Defines Route  Relations
    @{
*/
#define ROUTED_BY "TC_Routed_By"
#define DEVICE_TO_CONNECTOR "TC_Device_To_Connector"

/** @}*/

/**
    @name Route display font types
    @{
*/
typedef enum ROUTE_display_font_e {
    ROUTE_display_font_solid = 0,
    ROUTE_display_font_dashed,
    ROUTE_display_font_dotted
} ROUTE_display_font_t;

/** @}*/

#ifdef __cplusplus
        extern "C"{
#endif

/**
    Create a Route object.
*/
extern MECHATRONICS_API int ROUTE_create (
    const char*  name,               /**< (I) Name of the route object */
    const char*  description,        /**< (I) Description of the route object */
    tag_t        bvr,                /**< (I) Tag of the BVR, which specifies the structure context for this object*/
    tag_t*       route               /**< (O) Tag of the route object created by this function call */
    );


/**
    Add a segment to a route at the specified position.
    Valid position values are from 0..n. A value of -1 for position will add the segment at the end.
*/
extern MECHATRONICS_API int ROUTE_add_segment(
    tag_t route,                     /**< (I) Tag of the route object */
    tag_t segment,                   /**< (I) Tag of the segment */
    int   position                   /**< (I) Position where the segment should be inserted. Valid values are 1..n */
    );

/**
    Remove a segment from a route. This function doesn't delete the segment.
*/
extern MECHATRONICS_API int ROUTE_remove_segment (
    tag_t route,                 /**< (I) Tag of the route object */
    tag_t segment                /**< (I) Tag of the segment */
    );

/**
    This function lists the segments associated with a route.
*/
extern MECHATRONICS_API int ROUTE_list_segments(
    tag_t route,                     /**< (I) Tag of the route object */
    int* num,                        /**< (O) Segment count */
    tag_t** segments                 /**< (OF) num Array of segment tags */
    );

/**
    This function returns the real length and the represented length of a route.
*/
extern MECHATRONICS_API int ROUTE_ask_length(
    tag_t route,                     /**< (I) Tag of the route object */
    double *real_length,             /**< (O) Real length */
    double *represented_length       /**< (O) Represented length */
    );

/**
    This function can be used to set the real length on a given route.
*/
extern MECHATRONICS_API int ROUTE_set_real_length(
    tag_t route,                     /**< (I) Tag of the route object */
    double length                    /**< (I) Real length */
    );

/**
    This function can be used to set the represented length on a given route.
*/
extern MECHATRONICS_API int ROUTE_set_represented_length(
    tag_t route,                     /**< (I) Tag of the route object */
    double length                    /**< (I) Represented length */
    );

/**
    This function adds a node to a given route at a given position.
    Valid position values are from 1..n. A value of -1 for position will add the node at the end.
*/
extern MECHATRONICS_API int ROUTE_add_node (
    tag_t route,                 /**< (I) Tag of the route object */
    tag_t node,                  /**< (I) Tag of the node */
    int   position               /**< (I) Position where the node should be inserted. Valid values are 1..n */
    );

/**
    This function removes a node from a route but doesn't delete the node object.
*/
extern MECHATRONICS_API int ROUTE_remove_node (
    tag_t route,                 /**< (I) Tag of the route object */
    tag_t node                   /**< (I) Tag of the node */
    );

/**
    This function lists the nodes associated with the route.
*/
extern MECHATRONICS_API int ROUTE_list_nodes(
    tag_t route,                     /**< (I) Tag of the route object */
    int* num,                        /**< (O) node count */
    tag_t **nodes                    /**< (OF) num Array of node tags */
    );

/**
    This function sets a center curve for a route.
    Use NULLTAG to unset the route curve.
*/
extern MECHATRONICS_API int ROUTE_set_center_curve(
    tag_t route,                   /**< (I) Tag of the route object */
    tag_t center_curve             /**< (I) Tag of the center curve */
    );

/**
    This function returns the center curve of a route.
*/
extern MECHATRONICS_API int ROUTE_ask_center_curve(
    tag_t route,                  /**< (I) Tag of the route object */
    tag_t *center_curve           /**< (O) Tag of the center curve */
    );


/**
    This function creates a new segment.
*/
extern MECHATRONICS_API int ROUTE_create_segment (
    const char *name,           /**< (I) Name of the segment object */
    tag_t bvr,                  /**< (I) Tag of the BVR, which specifies the structure context for this object */
    tag_t  *segment             /**< (O) Tag of the segment object created by this function call */
    );

/**
    This function returns the name of the given segment.
*/
extern MECHATRONICS_API int ROUTE_ask_segment_name (
    tag_t  segment,       /**< (I) Tag of the segment object */
    char**  name          /**< (OF) Name of the segment object */
    );


/**
    This function can be used to query the start node of a segment.
*/
extern MECHATRONICS_API int ROUTE_ask_segment_start (
    tag_t  segment,                 /**< (I) Tag of the segment */
    tag_t  *start_node              /**< (O) Tag of the start node */
    );

/**
    This function can be used to set the start node of a segment.
*/
extern MECHATRONICS_API int ROUTE_set_segment_start (
    tag_t  segment,                 /**< (I) Tag of the segment */
    tag_t  start_node               /**< (I) Tag of the start node */
    );

/**
    This function can be used to query the end node of a segment.
*/
extern MECHATRONICS_API int ROUTE_ask_segment_end (
    tag_t  segment,                /**< (I) Tag of the segment */
    tag_t  *end_node               /**< (O) Tag of the end node */
    );

/**
    This function can be used to set the end node of a segment.
*/
extern MECHATRONICS_API int ROUTE_set_segment_end (
    tag_t  segment,                /**< (I) Tag of the segment */
    tag_t  end_node                /**< (I) Tag of the end node */
    );

/**
    This function returns the center curve for a given segment.
*/
extern MECHATRONICS_API int ROUTE_ask_segment_center_curve (
    tag_t  segment,              /**< (I) Tag of the segment */
    tag_t  *center_curve          /**< (O) Tag of the center curve */
    );

/**
    This function sets the center curve for a given segment. Use
    NULLTAG to unset the center curve for the segment.
*/
extern MECHATRONICS_API int ROUTE_set_segment_center_curve (
    tag_t  segment,            /**< (I) Tag of the segment */
    tag_t  center_curve        /**< (I) Tag of the center_curve */
    );



/**
    This function returns the route objects referencing this segment.
*/
extern MECHATRONICS_API int ROUTE_ask_segment_routes(
    tag_t segment,              /**< (I) Tag of the segment */
    int *count,                  /**< (O) Number of route objects returned */
    tag_t **routes              /**< (OF) count Array of the route tags */
);


/**
    This function gives the real length and the represented length of a segment.
*/
extern MECHATRONICS_API int ROUTE_ask_segment_length(
    tag_t segment,                    /**< (I) Tag of the route object */
    double *real_length,              /**< (O) Real length of the segment */
    double *represented_length        /**< (O) Represented length of the segment */
    );

/**
    This function can be used to set the real length on a given segment.
*/
extern MECHATRONICS_API int ROUTE_set_segment_real_length(
    tag_t segment,                    /**< (I) Tag of the route object */
    double length                     /**< (I) Real length of the segment */
    );

/**
    This function can be used to set the represented length on a given segment.
*/
extern MECHATRONICS_API int ROUTE_set_segment_represented_length(
    tag_t segment,                    /**< (I) Tag of the route object */
    double length                     /**< (I) Represented length of the segment */
    );

/**
    This function can be used to set the cross sectional area on a given segment.
*/
extern MECHATRONICS_API int ROUTE_set_segment_cross_section(
    tag_t segment,                    /**< (I) Tag of the segment object */
    double area                       /**< (I) Cross Sectional Area value of the segment */
    );

/**
    This function gives the cross sectional area of a given segment.
*/
extern MECHATRONICS_API int ROUTE_ask_segment_cross_section(
    tag_t segment,                    /**< (I) Tag of the segment object */
    double *area                      /**< (O) Cross Sectional Area of the segment */
    );

/**
    This function creates a new node.
*/
extern MECHATRONICS_API int ROUTE_create_node (
    const char *name,                /**< (I) Name of the node to be created */
    tag_t bvr,                       /**< (I) Tag of the bvr, which specifies the structure context for this object */
    tag_t  *node                     /**< (O) Tag of the node object created by this function call */
    );

/**
    This function returns the name of the given node.
*/
extern MECHATRONICS_API int ROUTE_ask_node_name (
    tag_t  node,                    /**< (I) Tag of the node object */
    char**  name                    /**< (OF) Name of the node object */
    );

/**
    This function sets the X, Y, Z, position for a node.
*/
extern MECHATRONICS_API int ROUTE_set_node_position (
    tag_t  node,                    /**< (I) Tag of the node object */
    double x,                       /**< (I) X value */
    double y,                       /**< (I) Y value */
    double z                        /**< (I) Z value */
    );

/**
    This function returns the X, Y, Z, position for a given node.
*/
extern MECHATRONICS_API int ROUTE_ask_node_position (
    tag_t  node,                    /**< (I) Tag of the node */
    double *x,                      /**< (O) X value */
    double *y,                      /**< (O) Y value */
    double *z                       /**< (O) Z value */
    );

/**
    This function returns segments referencing a given node.
*/
extern MECHATRONICS_API int ROUTE_ask_node_segments(
    tag_t node,                     /**< (I) Tag of the node*/
    int   *count,                   /**< (O) Number of segments */
    tag_t **segments                /**< (OF) count Tag of the segments */
    );

/**
    This function returns routes referencing a given node.
*/
extern MECHATRONICS_API int ROUTE_ask_node_routes(
    tag_t node,                     /**< (I) Tag of the node */
    int   *count,                   /**< (O) Number of routes */
    tag_t **routes                  /**< (OF) count Array of route tags */
    );

/**
   This function creates a new center curve.
*/
extern MECHATRONICS_API int ROUTE_create_center_curve (
    const char *name,               /**< (I) Name of the curve */
    tag_t  bvr,                     /**< (I) Tag of the BVR, which specifies the structure context for this object */
    tag_t  *center_curve            /**< (O) Tag of the center_curve */
    );

/**
    Set the geometric parameters of the curve. You must define at least two control points.
    The length of each vector in control points is dimension+1 if is_rational is true and
    is same as dimension if is_rational=false. If a curve is uniform then the knots are considered
    as evenly spaced. Therefore, knots should not be specified for uniform curves. A polyline
    can be defined as uniform curve with a degree of 1.
*/
extern MECHATRONICS_API int ROUTE_set_center_curve_data (
    tag_t center_curve,            /**< (I) Tag of the center curve */
    int degree,                    /**< (I) Degree of the curve */
    int dimension,                 /**< (I) Dimension of the curve */
    logical is_rational,           /**< (I) Flag indicating whether this curve is a rational curve */
    logical is_uniform,            /**< (I) Flag indicating whether this curve is a uniform curve */
    double start_parameter,        /**< (I) Start interval of the curve between 0.0 and 1.0 */
    double end_parameter,          /**< (I) End interval of the curve between 0.0 and 1.0 */
    int num_control_points,        /**< (I) Number of control points */
    double **control_points,       /**< (I) Array of control points */
    int num_knots,                 /**< (I) Number of knots */
    double *knots,                 /**< (I) Array of knots */
    int *multiplicities            /**< (I) Array of knot multiplicities */
    );


/**
    Ask the geometric parameters of the curve
*/
extern MECHATRONICS_API int ROUTE_ask_center_curve_data (
    tag_t center_curve,             /**< (I) Tag of the center curve */
    int *degree,                    /**< (O) Degree of the curve */
    int *dimension,                 /**< (O) Dimension of the curve */
    logical *is_rational,           /**< (O) Flag indicating whether this curve is a rational curve */
    logical *is_uniform,            /**< (O) Flag indicating whether this curve is a uniform curve */
    double *start_parameter,        /**< (O) Start interval of the curve between 0.0 and 1.0 */
    double *end_parameter,          /**< (O) End interval of the curve between 0.0 and 1.0 */
    int *num_control_points,        /**< (O) Number of control points */
    double ***control_points,       /**< (OF) num_control_points Array of control points */
    int *num_knots,                 /**< (O) Number of knots */
    double **knots,                 /**< (OF) num_knots Array of knots */
    int **multiplicities            /**< (OF) num_knots Array of knot multiplicities */
    );


/**
    Ask the name of center curve object.
*/
extern MECHATRONICS_API int ROUTE_ask_center_curve_name (
    tag_t center_curve,             /**< (I) Tag of the center_curve */
    char **name                     /**< (OF) Name of the center curve */
    );

/**
    This function returns the segments referencing a given center curve.
*/
extern MECHATRONICS_API int ROUTE_ask_center_curve_segments(
    tag_t center_curve,             /**< (I) Tag of the center_curve */
    int *count,                     /**< (O) Number of segments */
    tag_t **segments                /**< (OF) count Array of segment tags */
    );

/**
    This function returns the segments referencing a given route.
*/
extern MECHATRONICS_API int ROUTE_ask_center_curve_routes(
    tag_t center_curve,         /**< (I) Tag of the center_curve */
    int *count,                 /**< (O) Number of segments */
    tag_t **routes              /**< (OF) count Array of route tags */
    );


/**
    This function associates a connection/device instance (BOMLine) with a
    route.
*/
extern MECHATRONICS_API int ROUTE_associate(
    tag_t bom_line,              /**< (I) BOM Line corresponding to a connection/device instance  */
    tag_t route                 /**< (I) Tag of the route to associate */
    );

/**
   This fucntion breaks the association between the given route and BOM Line
   corresponding to a connection/device instance.
*/
extern MECHATRONICS_API int ROUTE_unassociate(
    tag_t bom_line,             /**< (I) BOM Line corresponding to a connection/device instance */
    tag_t route                 /**< (I) Tag of the route */
    );

/**
   This function returns the route associated with a bom_line.
*/
extern MECHATRONICS_API int ROUTE_ask_associated_route(
    tag_t bom_line,              /**< (I) BOM Line corresponding to a connection/device instance */
    tag_t *route                 /**< (O) Tag of the route */
    );

/**
   This function returns all bom_lines associated with a route.
*/
extern MECHATRONICS_API int ROUTE_ask_associated_bom_lines(
    tag_t route,                 /**< (I) Tag of the route */
    tag_t window,                /**< (I) Tag of the window */
    int   *count,                /**< (O) Number of bom lines */
    tag_t **bom_lines            /**< (OF) count Array of bom line tags */
    );

/**
    This function sets the display properties associated with a route.
*/
extern MECHATRONICS_API int ROUTE_display_set_props(
       tag_t route_tag,            /**< (I) Tag of the route */
       ROUTE_display_font_t font,  /**< (I) font */
       double width,               /**< (I) width */
       const double color[3]       /**< (I) RGB colors */
      );

/**
    This function returns the display properties associated with a route.
*/
extern MECHATRONICS_API int ROUTE_display_ask_props(
       tag_t route_display,         /**< (I) Tag of the route */
       ROUTE_display_font_t *font,  /**< (O) font */
       double *width,               /**< (O) width */
       double color[3]              /**< (O) RGB colors */
      );

/**
    This function will create a new, standalone Location object with the given ID
    and name. The tag of the location and location revision object is returned.

    @note This itk will not save the object. AOM_save_with_extensions needs to be called separately to save the object.
*/
extern MECHATRONICS_API int ROUTE_create_location (
        const char* location_id,        /**< (I) Location identification number. No two Locations can have the same identification string.
                                            <br/>A null is allowed. If null, the system will automatically generate a Location ID. */
        const char* location_name,      /**< (I) Location name. A common name or short description of the Location.*/
        const char* location_type,      /**< (I) It can be used to specify a defined Location type. A null is allowed for this argument. */
        const char* location_rev_id,    /**< (I) Identification string (revision ID) of the Location Revision being created. A null is allowed.
                                            If null, the system will automatically generate a revision ID.*/
        tag_t*      new_location,       /**< (O) Tag for identifying the newly created Location object.*/
        tag_t*      new_location_rev    /**< (O) Tag for identifying the newly created Location Revision object.*/
      );

/**
    This function will create a new, standalone Location object with the given ID,
     name, master form, rev master form. The tag of the location and location revision object is returned.

    @note This itk will not save the object. AOM_save_with_extensions needs to be called separately to save the object.
*/
extern MECHATRONICS_API int ROUTE_create_location_with_forms (
        const char* location_id,        /**< (I) Location identification number. No two Locations can have the same identification string.
                                            <br/>A null is allowed. If null, the system will automatically generate a Location ID. */
        const char* location_name,      /**< (I) Location name. A common name or short description of the Location.*/
        const char* location_type,      /**< (I) It can be used to specify a defined Location type. A null is allowed for this argument. */
        const char* location_rev_id,    /**< (I) Identification string (revision ID) of the Location Revision being created. A null is allowed.
                                            If null, the system will automatically generate a revision ID.*/
        tag_t       routeLocMaster,      /**< (I) Tag for route location master form  */
        tag_t       routeLocRevMaster,   /**< (I) Tag for route location revision master form*/
        tag_t*      new_location,       /**< (O) Tag for identifying the newly created Location object.*/
        tag_t*      new_location_rev    /**< (O) Tag for identifying the newly created Location Revision object.*/
      );


/**
    This function will associate a given bomline or ROUTE object to a specified location
    in the role of assigned location. The tag of the newly created relation is returned.
*/
extern MECHATRONICS_API int ROUTE_set_assigned_location (
        tag_t primary_object,       /**< (I) Tag of bomline or ROUTE object. */
        tag_t location_line,        /**< (I) Tag of Location line */
        tag_t *relation_tag         /**< (O) Tag of newly created relation.*/
      );

/**
    This function will remove the association between a bomline or ROUTE object
    and its associated location
*/
extern MECHATRONICS_API int ROUTE_unset_assigned_location (
        tag_t primary_object,       /**< (I) Tag of bomline or ROUTE object.*/
        tag_t location_line         /**< (I) Tag of Location line. */
      );

/**
    This function will return the locations which are associated with a bomline or ROUTE object.
*/
extern MECHATRONICS_API int ROUTE_ask_assigned_locations (
        tag_t associating_object,           /**< (I) Tag of bomline or ROUTE object.*/
        tag_t window_tag,                   /**< (I) Tag of window.
                                               <br/>If the associating object is not BOMLine, the window tag is mandatory.
                                               <br/>Otherwise, it can be NULLTAG */
        int *location_count,                /**< (O) Count of location lines. */
        tag_t **assigned_location_lines     /**< (OF) location_count Tag list of Location lines. */
      );

/**
   This function will associate a defining item line to a specified location.
   The tag of the newly created relation is returned.
*/
extern MECHATRONICS_API int ROUTE_location_set_defining_item (
        tag_t location_line,            /**< (I) Tag of location line*/
        tag_t defining_item_line,       /**< (I) A Tag of bomline */
        tag_t *relation_tag             /**< (O) Tag for identifying the newly created defining_item relation. */
      );

/**
    This function will remove the association between defining item line and a
    specified location.
*/
extern MECHATRONICS_API int ROUTE_location_unset_defining_item (
        tag_t location_line         /**< (I) Tag of location line. */
      );

/**
    This function will return the defining item line for a location line.
*/
extern MECHATRONICS_API int ROUTE_location_ask_defining_item (
        tag_t location_line,        /**< (I) Tag of location line. */
        tag_t *defining_item_line   /**< (O) Tag of bomline. */
      );

/**
    This function will return assigned objects for a given location.
*/
extern MECHATRONICS_API int ROUTE_location_find_assigned_objects (
        tag_t location_line,        /**< (I) Tag of location line. */
        int *objects_count,         /**< (O) Count of associated object. */
        tag_t **assigned_objects    /**< (OF) objects_count Tag list of associated object.*/
      );

/**
    This function will delete route data created in the context of a given BOMViewRevision.
*/
extern MECHATRONICS_API int ROUTE_delete_route_data (
        tag_t bvr        /**< (I) Tag of BVR */
      );


/** @} */


#ifdef __cplusplus
}
#endif

#include <mechatronics/libmechatronics_undef.h>
#endif

