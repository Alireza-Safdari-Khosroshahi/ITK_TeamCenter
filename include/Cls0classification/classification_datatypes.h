/*Copyright 2020 Siemens Digital Industries Software
**==================================================
**Copyright $2012.
**Siemens Product Lifecycle Management Software Inc.
**All Rights Reserved.
**==================================================
**Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file classification_datatypes.h

    This file contains the definition of data structures used by Cls0Classification calls
    To use these functions, include classification_datatypes.h
*/

#ifndef __INCLUDED_CLASSIFICATION_DATATYPES_H__
#define __INCLUDED_CLASSIFICATION_DATATYPES_H__

/*
 * Hierarchy node types
 */
typedef enum Cls0NodeType_e
{
    CLS_NODE_undefined = -1,
    CLS_NODE_group,
    CLS_NODE_master,
    CLS_NODE_custom,
    CLS_NODE_all,
    CLS_NODE_cst_master
}Cls0NodeType;


/*
 * Hierarchy node attachments types
 */
typedef enum Cls0NodeAttachmentType_e
{
    CLS_NODE_icon = 0,
    CLS_NODE_image
}Cls0NodeAttachmentType;

/*
 * Hierarchy node characteristic types
 */
typedef enum Cls0NodeCharacteristicType_e
{
    CLS_NODE_isAssembly = 0,
    CLS_NODE_hasMultipleInstances,
    CLS_NODE_isLeaf
}Cls0NodeCharacteristicType;

/*
 * Supported classification types
 */
typedef enum ClassifyType_e
{
    CLS_TYPE_Item = 0,
    CLS_TYPE_Item_Revision,
    CLS_TYPE_Dataset,
    CLS_TYPE_Others
}Cls0ClassifyType;

/*
 * Supported Classification attribute types
 */
typedef enum Cls0AttributeType_e
{
    CLS_ATTR_TYPE_keylov = -1,
    CLS_ATTR_TYPE_string,
    CLS_ATTR_TYPE_integer,
    CLS_ATTR_TYPE_real,
    CLS_ATTR_TYPE_date,
    CLS_ATTR_TYPE_time,
}Cls0AttributeType;

/*
 * Classification search types to filter searching.
 */
typedef enum ClsSearchOptionType_e
{
    CLS_SEARCH_default       =  0,
    CLS_SEARCH_in_class_only = (1 << 0 )
}ClsSearchOptions;

typedef enum Cls0ElementType_e
{
    CLS_ELEM_Undefined = -1,
    CLS_ELEM_Node,
    CLS_ELEM_Member
} Cls0ElementType;

/**
 * Forward synchronization Operation types
 * TODO: These should be consumed by internal functions only; so move into an internal / un-kitted header.
 */
typedef enum Cls0OperationType_e
{
    CLS_OP_Undefined = -1,          /**< Default value to be used for initialization. */
    CLS_OP_Save,                    /**< Indicates that a "Save" operation was performed on underlying Storage hierarchy. */
    CLS_OP_Delete,                  /**< Indicates that a "Delete" operation was performed on underlying Storage hierarchy. */
    CLS_OP_SyncL10n                 /**< Indicates that a "L10N" values structure was updated on the underlying Storage hierarchy. */
} Cls0OperationType;

/**
 * Hierarchy node params
 */
typedef struct HierarchyNodeParams_s
{
    std::string     nodeId;                     /**< Identifier of the hierarchy node. */
    std::string     nodeName;                   /**< Name of the hierarchy node. */
    std::string     nodeDescr;                  /**< Description of the hierarchy node. */
    logical         isGroup;                    /**< Flag indicating whether the hierarchy node is a group node or not. */
    tag_t           parentNodeTag;              /**< Reference to the parent hierarchy node. */
    tag_t           hierarchyTag;               /**< Reference to the hierarchy view. */
    logical         isLeafNode;                 /**< Flag indicating whether the hierarchy node is a leaf node or not.*/
    int             sortLevel;                  /**< Indicates the position of the hierarchy node among its peers. */
    std::string     storageClassType;           /**< The Type name of the Storage class associated with the hierarchy node. */

    HierarchyNodeParams_s() : nodeId(), nodeName(), nodeDescr(), isGroup( false ),
        parentNodeTag( 0 ), hierarchyTag( 0 ), isLeafNode( false ), sortLevel( 0 ), storageClassType(){}
} HierarchyNodeParams;

/**
 * Node Member (Classification data) params
 */
typedef struct NodeMemberParams_s
{
    std::string     memberId;                   /**< Identifier of a classification object. This is a mandatory field. */
    std::string     memberName;                 /**< Name of a classification object. This is a mandatory field. */
    std::string     memberDescr;                /**< Description of a classification object. This is an optional field. */
    tag_t           owningNodeTag;              /**< Reference to a node, where a classification object is classified. This is a mandatory field. */
    tag_t           classifiedObjTag;           /**< Reference to a classified object (catalog data).This is an optional field. */

    NodeMemberParams_s() : memberId(), memberName(), memberDescr(),
        owningNodeTag( 0 ), classifiedObjTag( 0 ){}
} NodeMemberParams;

/**
 * Cls0Object params
 */
typedef struct NodeMemberIcoParams_s
{
    NodeMemberParams*   baseMemberParams;           /**< Base 'node params' structure */
    tag_t               icoTag;                     /**< underlying ICO tag which 'Cls0Object' will have in addition to the base 'node params' */

    NodeMemberIcoParams_s() : baseMemberParams( 0 ), icoTag( 0 ){}
} NodeMemberIcoParams;

/**
 * Classification object migration status types
 */
typedef enum Cls0MigrationStatus_e
{
    CLS_MIGRATE_UNPROCESSED = -1,                  /**< Default value to be used for initialization. */
    CLS_MIGRATE_Success,                           /**< Indicates that migration operation performed on underlying Storage hierarchy is sucessful. */
    CLS_MIGRATE_Failure,                           /**< Indicates that migration operation performed on underlying Storage hierarchy is failed. */
    CLS_MIGRATE_Skipped                            /**< Indicates that migration operation performed on underlying Storage hierarchy is skipped. */
} Cls0MigrationStatus_t;

/**
 * Individual Classification object migration record
 */
typedef struct Cls0ObjectMigrationRecord_e
{
    tag_t                   objectTag;             /**< Reference to a class or group or ICO being migrated. */
    Cls0MigrationStatus_t   migrationStatus;       /**< Classification object migration status. */
    int                     errorCode;             /**< Error code of migration operation. */

    Cls0ObjectMigrationRecord_e( tag_t theObjectTag, Cls0MigrationStatus_t theMigrationStatus, int theErrorCode )
        : objectTag( theObjectTag ), migrationStatus( theMigrationStatus ), errorCode( theErrorCode ){}
    Cls0ObjectMigrationRecord_e()
        : objectTag( 0 ), migrationStatus( CLS_MIGRATE_UNPROCESSED ), errorCode( 0 ){}
} Cls0ObjectMigrationRecord_t;


/**
 * Classification CST property types
 * Since Property Data Type is handled via "enum" in the CST interface, I have copied over the enum def here and then added the "CLS_" prefix
 * Any changes here should be kept in sync with the 'solutions\cst0classification\server\Cst0classification\Cst0Object.hxx'
 */
typedef enum {
    CLS_CST_property_type_undefined,
    CLS_CST_property_type_string,
    CLS_CST_property_type_string_array,
    CLS_CST_property_type_logical,
    CLS_CST_property_type_int,
    CLS_CST_property_type_double,
    CLS_CST_property_type_tag,
    CLS_CST_property_type_tag_array,
    CLS_CST_property_type_json,
    CLS_CST_property_type_date
} CLS_CST_property_type;

#endif /* __INCLUDED_CLASSIFICATION_DATATYPES_H__ */
