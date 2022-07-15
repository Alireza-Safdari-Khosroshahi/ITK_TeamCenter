/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*  */

#ifndef PSCONNECTION_H
#define PSCONNECTION_H

#include <unidefs.h>
#include <mechatronics/libmechatronics_exports.h>

/**
    @defgroup PSCONN PS Connection
    @ingroup MECHATRONICS

    This module defines the required ITK interface for Connection related operations.
    @{
*/

/**
    @name Defines for PSConnection Types
    @{
*/
#define PSCONNECTION_CLASS_NAME     "PSConnection"
#define PSCONNECTION_TYPE_NAME      PSCONNECTION_CLASS_NAME
#define PSConnectionClassName       PSCONNECTION_CLASS_NAME

#define PSCONNECTION_REV_CLASS_NAME "PSConnectionRevision"
#define PSCONNECTION_REV_TYPE_NAME  PSCONNECTION_REV_CLASS_NAME
#define PSConnectionRevClassName    PSCONNECTION_REV_CLASS_NAME
/** @} */

/**
    @name For OOTB Types of PSConnection
    @{
*/
#define CONNECTION_TYPE_NAME        "Connection"
#define CONNECTION_REV_TYPE_NAME    "ConnectionRevision"
#define NETWORK_TYPE_NAME           "Network"
#define NETWORK_REV_TYPE_NAME       "NetworkRevision"
/** @} */

/**
    @name Defines for Mechatronics Relations
    @{
*/
#define CONNECTED_TO                "TC_Connected_To"
#define IMPLEMENTED_BY              "TC_Implemented_By"
#define REALIZED_BY                 "TC_Realized_By"
#define PSCONNECTION_DEFAULT_TYPE   "PSConnection_default_type"
/** @} */

#ifdef __cplusplus
extern "C"{
#endif

/**
    This function creates new PSConnection and its default Connection Revision, with the given inputs.

    <b>Restrictions:</b>

    Type (input value specified for conn_type argument),
    must be pre-defined by the site using the install_types utility.
    The conn_name will be used as the revision's name.

    @note This itk will not save the object. AOM_save_with_extensions needs to be called separately to save the object.
*/
extern MECHATRONICS_API int PSCONN_create_connection (
    const char*             conn_id,        /**< (I) Connection identification number. No two Connections can have the
                                                    same identification string. A null is allowed. If null,
                                                    the system will automatically generate an Item ID. */
    const char*             conn_name,      /**< (I) A common name or short description of the Connection Item */
    const char*             conn_type,      /**< (I) Connection Type for the Connection Object to be created */
    const char*             conn_rev_id,    /**< (I) Identification string (revision ID) of the Connection Revision being created.
                                                    A null is allowed. If null, the system will automatically generate a revision ID */
    tag_t*                  new_conn,       /**< (O) Tag for identifying the Connection Object in the current program */
    tag_t*                  new_conn_rev    /**< (O) Tag for identifying the Connection Revision in the current program */
    );

/**
    This function connects a set of GDELines to a PSConnection Line.
*/
extern MECHATRONICS_API int PSCONN_add_to_connection (
    tag_t                   conn_line_tag,      /**< (I) Tag of the connection bomline to which the GDELines will be connected */
    int                     gde_line_count,     /**< (I) Number of GDELines to be connected */
    tag_t*                  gde_line_tags       /**< (I) Tags of the GDELine’s to be connected */
    );

extern MECHATRONICS_API int PSCONN_add_itemlines_to_connection (
    tag_t                   conn_line_tag,      /**< (I) */
    tag_t                   context_line_tag,   /**< (I) */
    int                     line_count,         /**< (I) */
    tag_t*                  line_tags           /**< (I) */
    );

/**
    This function creates a PSConnection and its default Connection Revision and connects the given set of GDELines to this newly created 
    PSConnection Line.The new PSConnectionLine is created as a child line to the common parent of the GDELines.  
    
    <b>Restrictions:</b>
    Type (input value specified for connType argument),    
    must be pre-defined by the site using the install_types utility or using BMIDE.   

    The conn_name which is the part attribute list will be used as the revision's name.This is represented by attribute
    object_name.

*/
extern MECHATRONICS_API int PSCONN_connect2 (
    const                   char *connType, /**<I> Connection type*/
    int                     numAttrs,       /**<I> Number of input attributes */
    char                    **attrNames,    /**<I> Names of input attributes */
    char                    **attrValues,   /**<I> Values for the input attributes */
    char                    *connRev,       /**<I> Id for the revision */
    int                     gde_line_count, /**<I> Number of GDELines to be connected  */
    tag_t                   *gde_line_tags, /**<I> Tags of the GDELine’s to be connected */
    tag_t                   *conn_line_tag  /**<O> Tag of the connection bomline to which the GDELines will be connected*/
    );

/**
    This function creates a PSConnection and its default Connection Revision and
    connects the given set of GDELines to this newly created PSConnection Line.

    The new PSConnectionLine is created as a child line to the common parent of the GDELines.

    <b>Restrictions:</b>

    Type (input value specified for conn_type argument),
    must be pre-defined by the site using the install_types utility.
    The conn_name will be used as the revision's name.
*/
extern MECHATRONICS_API int PSCONN_connect (
    char*                   connId,         /**< (I)  */
    char*                   connName,       /**< (I)  */
    char*                   connType,       /**< (I)  */
    char*                   connRev,        /**< (I)  */
    int                     gde_line_count, /**< (I) Number of GDELines to be connected */
    tag_t*                  gde_line_tags,  /**< (I) Tags of the GDELine’s to be connected */
    tag_t*                  conn_line_tag   /**< (O) Tag of the connection bomline to which the GDELines will be connected */
    );
/**
    This function removes the connection(s) between the given list of GDE Lines and the PSConnection Line
*/
extern MECHATRONICS_API int PSCONN_remove_from_connection (
    tag_t                   conn_line_tag,      /**< (I) Tag of the connection bomline to which the GDELines will be connected */
    int                     gde_line_count,     /**< (I) Number of GDELines to be connected */
    tag_t*                  gde_line_tags       /**< (I) Tags of the GDELine’s to be connected */
    );

/**
    This function removes all the connections for this PSConnection Line
*/
extern MECHATRONICS_API int PSCONN_disconnect (
    tag_t                   con_rev_tag     /**< (I) Tag of the connection bomline for which the connections have to be removed */
    );

/**
    This function lists all the gde lines connected to the input PSConnection Line.

    <b>Restrictions:</b>

    Only configured GDE Lines will be returned

    Only BOMLines connected in the context of the said BOM Window will be returned.
*/
extern MECHATRONICS_API int PSCONN_list_connected_gdes (
    tag_t                   conn_line_tag,      /**< (I) Tag of the connection bomline to which the GDELines will be connected */
    int*                    gde_line_count,     /**< (O) Number of GDELines connected */
    tag_t**                 gde_line_tags       /**< (OF) gde_line_count Tags of the connected GDELine’s */
    );

/**
    This function lists all the bomlines realized by the input BOMLine.

    <b>Restrictions:</b>

    Only configured GDE Lines will be returned

    Only Realized BOMLines from the BOM Window in context will be returned.
*/
extern MECHATRONICS_API int PSCONN_list_realizedBy (
    tag_t                   bom_line_tag,       /**< (I) Tag of the bomline for which the realized by are to be listed */
    int*                    gde_line_count,     /**< (O) Number of BOMLines realized by the above bomline */
    tag_t**                 gde_line_tags       /**< (OF) gde_line_count Tags of the realized BOM Lines */
    );

/**
    This function lists all the bomlines realizing the input BOMLine.

    <b>Restrictions:</b>

    Only configured  Lines will be returned

    Only Realizing BOMLines from the BOM Window in context will be returned.
*/
extern MECHATRONICS_API int PSCONN_list_realizingLines (
    tag_t                   bom_line_tag,       /**< (I) Tag of the bomline for which the realizing lines are to be listed */
    int*                    line_count,        /**< (O) Number of BOMLines realized by the above bomline */
    tag_t**                 line_tags         /**< (OF) line_count Tags of the realizing BOM Lines */
    );


/**
    This function lists all the bomlines implemented by the input BOMLine.

    <b>Restrictions:</b>

    Only configured GDE Lines will be returned

    Only Implemented BOMLines from the BOM Window in context will be returned.
*/
extern MECHATRONICS_API int PSCONN_list_implementedBy (
    tag_t                   bom_line_tag,       /**< (I) Tag of the bomline for which the implementations are to be listed */
    int*                    gde_line_count,     /**< (O) Number of BOMLines implemented by the above bomline */
    tag_t**                 gde_line_tags       /**< (OF) gde_line_count Tags of the realized BOM Lines */
    );


/**
    This function lists all the bomlines implementing the input BOMLine.

    <b>Restrictions:</b>

    Only configured Lines will be returned

    Only Implementing BOMLines from the BOM Window in context will be returned.
*/
extern MECHATRONICS_API int PSCONN_list_implementingLines (
    tag_t                   bom_line_tag,       /**< (I) Tag of the bomline for which the implementing lines are to be listed */
    int*                    line_count,         /**< (O) Number of BOMLines implementing the above bomline */
    tag_t**                 line_tags          /**< (OF) line_count Tags of the implementing BOM Lines */
    );


/**
    This function set the implementedBy relation between the given input BOMLines.
*/
extern MECHATRONICS_API int PSCONN_set_implementedBy (
    tag_t                   primary_line_tag,   /**< (I) Tag of BomLine to be used as primary object in implementedBy relation */
    tag_t                   secondary_line_tag  /**< (I) Tag of BomLine to be used as secondary object in implementedBy relation */
    );

/**
    This function set the realizedBy relation between the given input BOMLines.
*/
extern MECHATRONICS_API int PSCONN_set_realizedBy (
    tag_t                   primary_line_tag,   /**< (I) Tag of BomLine to be used as primary object in realizedBy relation */
    tag_t                   secondary_line_tag  /**< (I) Tag of BomLine to be used as secondary object in realizedBy relation */
    );

/**
    This function can be used to set the TC_Device_To_Connector
    relation between the given input BOM lines.
*/
extern MECHATRONICS_API int PSCONN_set_device_connector_relation (
    tag_t                   primary_line_tag,   /**< (I) Tag of BOM line to be used as primary object in TC_Device_To_Connector relation*/
    tag_t                   secondary_line_tag, /**< (I) Tag of BOM line to be used as secondary object in the TC_Device_To_Connector relation*/
    tag_t*                  relation_tag        /**< (O) Tag of the relation */
    );

/**
    This function can be used to unset the TC_Device_To_Connector
    relation between the given input BOM lines.
*/
extern MECHATRONICS_API int PSCONN_unset_device_connector_relation (
    tag_t                   primary_line_tag,   /**< (I) Tag of primary BOM line   */
    tag_t                   secondary_line_tag  /**< (I) Tag of secondary BOM line */
    );

/**
    This function can be used to get the number of connectors associated
    to a given device line
*/

extern MECHATRONICS_API int PSCONN_ask_device_connectors (
    tag_t                   device_line_tag, /**< (I)  Tag of primary BOM line*/
    int*                    count,           /**< (O)  Number of BOM lines related by the above bomline by the TC_Device_To_Connector relation*/
    tag_t**                 connectorTags    /**< (OF) count Tags of the connectors */
    );

/**
    This function can be used to get the number of devices assocaited
    to a given connector line
*/

extern MECHATRONICS_API int PSCONN_ask_connector_devices (
    tag_t                   con_line_tag,    /**< (I) Tag of primary BOM line */
    int*                    count,           /**< (O) No. of Devices          */
    tag_t**                 connectorTags    /**< (OF) count Tags of the Devices     */
    );

/**
    This function will remove the implementedBy relation between the given input primary_line and secondary lines.
    If no secondary lines are given then all the secondary lines with implementedBy relation will be removed.

    <b>Restrictions:</b>

    Only implementedBy BOMLines from the BOM Window in context will be removed.
*/
extern MECHATRONICS_API int PSCONN_remove_implementedBy (
    tag_t                   primary_line_tag,       /**< (I) Tag of primary BOMLine */
    int                     secondary_line_count,   /**< (I) Count of the secondary BOMLines. This can be 0 */
    tag_t*                  secondary_line_tags     /**< (I) Array of secondary bomline tags */
    );

/**
    This function will remove the realizedBy relation between the given input primary_line and secondary lines.
    If no secondary lines are given then all the secondary lines with realizedBy relation will be removed.

    <b>Restrictions:</b>

    Only realizedBy BOMLines from the BOM Window in context will be removed.
*/
extern MECHATRONICS_API int PSCONN_remove_realizedBy (
    tag_t                   primary_line_tag,       /**< (I) Tag of primary BOMLine */
    int                     secondary_line_count,   /**< (I) Count of the secondary BOMLines. This can be 0 */
    tag_t*                  secondary_line_tags     /**< (I) Array of secondary bomline tags */
    );


/**
    This function creates new PSConnection and its default Connection Revision, with the given inputs.

    <b>Restrictions:</b>

    Type (input value specified for conn_type argument),
    must be pre-defined by the site using the install_types utility.
    The conn_name will be used as the revision's name.

    @note This itk will not save the object. AOM_save_with_extensions needs to be called separately to save the object.
*/
extern MECHATRONICS_API int PSCONN_create_connection_with_forms (
    const char*             conn_id,        /**< (I) Connection identification number. No two Connections can have the
                                                    same identification string. A null is allowed. If null,
                                                    the system will automatically generate an Item ID. */
    const char*             conn_name,      /**< (I) A common name or short description of the Connection Item */
    const char*             conn_type,      /**< (I) Connection Type for the Connection Object to be created */
    const char*             conn_rev_id,    /**< (I) Identification string (revision ID) of the Connection Revision being created.
                                                    A null is allowed. If null, the system will automatically generate a revision ID */

    tag_t                  connMasterForm,       /**< (I) Tag for connection master from */
    tag_t                  connRevMasterForm,    /**< (I) Tag for connection revision master form */

    tag_t*                  new_conn,       /**< (O) Tag for identifying the Connection Object in the current program */
    tag_t*                  new_conn_rev    /**< (O) Tag for identifying the Connection Revision in the current program */
    );

/**
    Retrieves all the connection objects of the given BOMLine or GDELine object.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#MECH_invalid_bomline if an invalid BOMLine or GDELine is passed in the parameter @p line_tag.
    </ul>
*/
extern MECHATRONICS_API int PSCONN_get_connections_from_line (
    tag_t                   line_tag,                /**< (I)  Tag of the BOMLine or GDELine object */
    int*                    connection_line_count,   /**< (O)  Size of the Connection BOMLine object tag array */
    tag_t**                 connection_line_tags     /**< (OF) connection_line_count Array of the Connection BOMLine object tags */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <mechatronics/libmechatronics_undef.h>

#endif
