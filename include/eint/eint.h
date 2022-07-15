/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*  */

#ifndef EINT_H
#define EINT_H

#include <tc/tc_startup.h>
#include <eint/eint_types.h>
#include <eint/libeint_exports.h>

#ifdef __cplusplus
extern "C"{
#endif

/**
    @defgroup EINT e-Integrator (EINT)
    @{
*/
extern EINT_API int EINT_init_module( void );

/**
    Creates an ExternalDataSource Object.

    <b>Restrictions:</b>
    
    Datasource_name has to be unique
*/
extern EINT_API int EINT_create_external_datasource (
    const char*     datasource_name,    /**< (I) The datasource name for the new ExternalDataSource object */
    const char*     hostname,           /**< (I) The hostname in which the ExternalDataSource reside */
    const char*     url,                /**< (I) The universal resouce locator for the ExternalDataSource */
    const char*     adapter_name,       /**< (I) The datasource adapter used */
    tag_t*          datasource          /**< (O) */
    );

/**
    Finds all externalDataSources in the database according to the datasource_name.
*/
extern EINT_API int EINT_find_external_datasource (
    const char*     datasource_name,    /**< (I) The datasource name for the new ExternalDataSource object.
                                                The argument also accepts wildcards. */
    int*            num,                /**< (O) Number of ExternalDataSource objects return */
    tag_t**         tags                /**< (OF) num The tag list for the ExternalDataSource Object */
    );

/**
    Set the ExternalDataSource object name
*/
extern EINT_API int EINT_set_external_datasource_name (
    tag_t           datasource,         /**< (I) The tag for the ExternalDataSource object */
    const char*     datasource_name     /**< (I) The new ExternaDataSource name */
    );

/**
    Returns the ExternalDataSource object name
*/
extern EINT_API int EINT_ask_external_datasource_name (
    tag_t           datasource,         /**< (I) The tag for the ExternalDataSource object */
    char**          datasource_name     /**< (OF) The new ExternaDataSource name */
    );

/**
    Set the ExternalDataSource hostname
*/
extern EINT_API int EINT_set_external_datasource_hostname (
    tag_t           datasource,     /**< (I) The tag for the ExternalDataSource object */
    const char*     hostname        /**< (I) The input ExternalDataSource hostname */
    );

/**
    Returns the ExternalDataSource hostname
*/
extern EINT_API int EINT_ask_external_datasource_hostname (
    tag_t           datasource,     /**< (I) The tag for the ExternalDataSource object */
    char**          hostname        /**< (OF) The return ExternalDataSource hostname */
    );

/**
    Set the ExternalDataSource universal resource locator
*/
extern EINT_API int EINT_set_external_datasource_URLName (
    tag_t           datasource,     /**< (I) The tag for the ExternalDataSource object */
    const char*     url_name        /**< (I) The input ExternalDataSource URL name */
    );

/**
    Returns the ExternalDataSource universal resource locator
*/
extern EINT_API int EINT_ask_external_datasource_URLName (
    tag_t           datasource,     /**< (I) The tag for the ExternalDataSource object */
    char**          url_name        /**< (OF) The return ExternalDataSource URL name */
    );

/**
    Set the ExternalDataSource adaptername.
*/
extern EINT_API int EINT_set_external_datasource_adaptername (
    tag_t           datasource,     /**< (I) The tag for the ExternalDataSource object */
    const char*     adaptername     /**< (I) The input Adapter name */
    );

/**
    Returns the ExternalDataSource adaptername 
*/
extern EINT_API int EINT_ask_external_datasource_adaptername (
    tag_t           datasource,     /**< (I) The tag for the ExternalDataSource object */
    char**          adaptername     /**< (OF) The return Adapter name */
    );

/**
    Returns the Authentication object which represents the proxy account
*/
extern EINT_API int EINT_find_external_datasource_proxy_account (
    tag_t           datasource,         /**< (I) The tag for the ExternalDataSource object */
    const char*     proxyUsername,      /**< (I) The username for the proxy account */
    tag_t*          authentication      /**< (O) The return Authentication object tag */
    );

/**
    Adds a new proxy account into the ExternDataSource
*/
extern EINT_API int EINT_add_external_datasource_proxy_account (
    tag_t               datasource,         /**< (I) The tag for the ExternalDataSource object */
    const char*         proxyUsername,      /**< (I) The username for the proxy account */
    const char*         proxyPassword,      /**< (I) The password for the proxy account */
    EINT_account_type_t accountType         /**< (I) */
    );

/**
    Removes the proxy account from the external datasource
*/
extern EINT_API int EINT_remove_external_datasource_proxy_account (
    tag_t           datasource,     /**< (I) The tag for the ExternalDataSource object */
    const char*     proxyUsername   /**< (I) The username for the proxy account */
    );

/**
    Set the properties of the proxy account based on the authentication object
*/
extern EINT_API int EINT_set_external_datasource_proxy_account (
    tag_t               datasource,         /**< (I) The tag for the ExternalDataSource object */
    tag_t               authentication,     /**< (I) The Authentication object which represents the proxy account */
    const char*         proxyUsername,      /**< (I) The proxy account username */
    const char*         proxyPassword,      /**< (I) The proxy account password */
    EINT_account_type_t accountType         /**< (I) The proxy account type (see #EINT_add_external_datasource_proxy_account) */
    );

/**
    Returns the properties of the proxy account based on the authentication object
*/
extern EINT_API int EINT_ask_external_datasource_proxy_account (
    tag_t                   datasource,         /**< (I) The tag for the ExternalDataSource object */
    tag_t                   authentication,     /**< (I) The Authentication object which represents the proxy account */
    char**                  proxyUsername,      /**< (OF) The proxy account username */
    char**                  proxyPassword,      /**< (OF) The proxy account password */
    EINT_account_type_t*    accountType         /**< (O) The proxy account type (see #EINT_add_external_datasource_proxy_account) */
    );

/**
    Returns the properties of the proxy account based on the login GroupMember.
    Each datasource for a give login GroupMember should lead to one proxy account.
*/
extern EINT_API int EINT_ask_external_datasource_groupmember_proxy_account (
    tag_t                   datasource,         /**< (I) The tag for the ExternalDataSource object */
    tag_t                   groupmember,        /**< (I) The login GroupMember object tag */
    char**                  proxyUsername,      /**< (OF) The proxy account username */
    char**                  proxyPassword,      /**< (OF) The proxy account password */
    EINT_account_type_t*    accountType         /**< (O) The proxy account type (see #EINT_add_external_datasource_proxy_account) */
    );

/**
    Returns all the Authentication objects associated with a ExternalDataSource.
*/
extern EINT_API int EINT_list_external_datasource_proxy_accounts (
    tag_t           datasource,         /**< (I) The tag for the ExternalDataSource object */
    int*            nFound,             /**< (O) The number of Authentication objects */
    tag_t**         authentications     /**< (OF) nFound The Authentication object tags */
    );

/**
    Adds a GroupMember object to the ExternalDataSource accessor list
*/
extern EINT_API int EINT_add_external_datasource_accessor (
    tag_t           datasource,     /**< (I) The ExternalDataSource object tag */
    tag_t           groupMember     /**< (I) The GroupMember object tag */
    );

/**
    Removes a GroupMember object to the ExternalDataSource accessor list
*/
extern EINT_API int EINT_remove_external_datasource_accessor (
    tag_t           datasource,     /**< (I) The ExternalDataSource object tag */
    tag_t           groupMember     /**< (I) The GroupMember object tag */
    );

/**
    Lists all GroupMember objects associated with an ExternalDataSource
*/
extern EINT_API int EINT_list_external_datasource_accessors (
    tag_t           datasource,         /**< (I) The ExternalDataSource object tag */
    int*            n_groupmembers,     /**< (O) Number of groupmember tags returns */
    tag_t**         groupMembers        /**< (OF) n_groupmembers GroupMember object tags */
    );

/**
    Removes all GroupMember objects from the ExternalDataSource accessor list
*/
extern EINT_API int EINT_clear_external_datasource_accessors (
    tag_t           datasource      /**< (I) The ExternalDataSource object tag */
    );

/**
    Grants accessors to the proxy account belongs to the particular ExternalDataSource
*/
extern EINT_API int EINT_external_datasource_add_proxy_account_accessors (
    tag_t           datasource,         /**< (I) The ExternalDataSource object tag */
    tag_t           authentication,     /**< (I) The Authentication which represents the proxy account */
    int             n_accessor,         /**< (I) Number of accessors to be granted */
    tag_t*          accessors           /**< (I) n_accessor GroupMember tags which represents the accessor list */
    );

/**
    Removes accessors from the proxy account belongs to the particular ExternalDataSource
*/
extern EINT_API int EINT_external_datasource_remove_proxy_account_accessors (
    tag_t           datasource,         /**< (I) The ExternalDataSource object tag */
    tag_t           authentication,     /**< (I) The Authentication which represents the proxy account */
    int             n_accessor,         /**< (I) Number of accessors to be removed */
    tag_t*          accessors           /**< (I) n_accessor GroupMember tags which represents the accessor list */
    );

/**
    Lists all accessors from the proxy account belongs to the particular ExternalDataSource
*/
extern EINT_API int EINT_external_datasource_list_proxy_account_accessors (
    tag_t           datasource,         /**< (I) The ExternalDataSource object tag */
    tag_t           authentication,     /**< (I) The Authentication which represents the proxy account */
    int*            n_groupmember,      /**< (O) Number of GroupMember object tags returned */
    tag_t**         groupMembers        /**< (OF) n_groupmember GroupMember tags which represents the accessor list */
    );

/**
    Removes all accessors from the proxy account belongs to the particular ExternalDataSource
*/
extern EINT_API int EINT_external_datasource_clear_proxy_account_accessors (
    tag_t           datasource,         /**< (I) The ExternalDataSource object tag */
    tag_t           authentication      /**< (I) The Authentication which represents the proxy account */
    );

/**
    Finds an ExternalAttribute object in the Teamcenter database.
    An ExternalAttribute object represents each column attribute of each table in the ExternalDataSource.
    Given a datasource_name, table_name and attr_name will lead to a unique ExternalAttribute object
*/
extern EINT_API int EINT_find_ext_attribute (
    const char*     datasource_name,    /**< (I) The ExternalDataSource name */
    const char*     table_name,         /**< (I) The table name */
    const char*     attr_name,          /**< (I) The attribute name */
    tag_t*          ext_attr            /**< (O) ExternaAttribute object tags */
    );

/**
    Creates an ExternalAttribute object.
    An ExternalAttribute object represents each column attribute of each table in the ExternalDataSource.
    Given a datasource_name, table_name and attr_name will lead to a unique ExternalAttribute object
*/
extern EINT_API int EINT_create_ext_attribute (
    const char*     datasource_name,    /**< (I) The ExternalDataSource name */
    const char*     tablename,          /**< (I) The table name */
    const char*     attr_name,          /**< (I) The attribute name */
    int             attr_datatype,      /**< (I) The datatype for the attribute */
    int             attr_length,        /**< (I) The returned ExternalAttribute object tags */
    tag_t*          ext_attr            /**< (O) The attribute length */
    );

/**
    Set the tablename attribute for an ExternalAttribute object.
*/
extern EINT_API int EINT_set_ext_attribute_tablename (
    tag_t           ext_attr,       /**< (I) The  ExternalAttribute object tags */
    const char*     tablename       /**< (I) The table name */
    );

/**
    Returns the tablename attribute for an ExternalAttribute object.
*/
extern EINT_API int EINT_ask_ext_attribute_tablename (
    tag_t           ext_attr,       /**< (I) The  ExternalAttribute object tags */
    char**          tablename       /**< (OF) The table name */
    );

/**
    Set the attribute name for an ExternalAttribute object.
*/
extern EINT_API int EINT_set_ext_attribute_name (
    tag_t           ext_attr,       /**< (I) The ExternalAttribute object tag */
    const char*     attr_name       /**< (I) The attribute name */
    );

/**
    Returns the attribute name for an ExternalAttribute object.
*/
extern EINT_API int EINT_ask_ext_attribute_name (
    tag_t           ext_attr,       /**< (I) The ExternalAttribute object tags */
    char**          attr_name       /**< (OF) The returned external attribute name */
    );

/**
    Set the attribute name for an ExternalAttribute object.
*/
extern EINT_API int EINT_set_ext_attribute_datatype (
    tag_t           ext_attr,       /**< (I) The ExternalAttribute object tags */
    int             attrtype        /**< (I) The attribute name */
    );

/**
    Set the attribute name for an ExternalAttribute object.
*/
extern EINT_API int EINT_ask_ext_attribute_datatype (
    tag_t           ext_attr,       /**< (I) The ExternalAttribute object tag */
    int*            attrtype        /**< (O) The attribute type */
    );

/**
    Set the attribute length for an ExternalAttribute object.
*/
extern EINT_API int EINT_set_ext_attribute_length (
    tag_t           ext_attr,       /**< (I) The ExternalAttribute object tag */
    int             length          /**< (I) The attribute length */
    );

/**
    Returns the attribute length for an ExternalAttribute object.
*/
extern EINT_API int EINT_ask_ext_attribute_length (
    tag_t           ext_attr,   /**< (I) The ExternalAttribute object tag */
    int*            length      /**< (O) The attribute length */
    );

/**
    Finds the MappedProperty object given the ExternalAttribute object tag, TcType name and TcProperty name
*/
extern EINT_API int EINT_find_mapped_property (
    tag_t           ext_attr,           /**< (I) The ExternalAttribute object tag */
    const char*     tc_typename,      /**< (I) The Teamcenter type name */
    const char*     tc_propname,      /**< (I) The Teamcenter property name */
    tag_t*          mapped_property     /**< (O) The return MappedProperty object tag */
    );

/**
    Create the MappedProperty object given the ExternalAttribute object tag, TcType name and TcProperty name
*/
extern EINT_API int EINT_create_mapped_property (
    tag_t           ext_attr,           /**< (I) The ExternalAttribute object tag */
    const char*     tc_typename,      /**< (I) The Teamcenter type name */
    const char*     tc_propname,      /**< (I) The Teamcenter property name */
    tag_t*          property            /**< (O) The return MappedProperty object tag */
    );

/**
    Returns the ExternalAttribute object tag for the given MappedProperty object.
*/
extern EINT_API int EINT_ask_mapped_property_extattr (
    tag_t           mapped_property,    /**< (I) The MappedProperty object tag */
    tag_t*          ext_attr            /**< (O) The returned ExternalAttribute object tag */
    );

/**
    Set the TcType name attribute for the given MappedProperty object.
*/
extern EINT_API int EINT_set_mapped_property_tctypename (
    tag_t           mapped_property,    /**< (I) The MappedProperty object tag */
    const char*     tc_typename       /**< (I) The Teamcenter type name */
    );

/**
    Asks the TcType name attribute for the given MappedProperty object.
*/
extern EINT_API int EINT_ask_mapped_property_tctypename (
    tag_t           mapped_property,    /**< (I) The MappedProperty object tag */
    char**          tc_typename       /**< (OF) The returned Teamcenter Type name */
    );

/**
    Set the Teamcenter property name attribute for the given MappedProperty object.
*/
extern EINT_API int EINT_set_mapped_property_tcpropname (
    tag_t           mapped_property,    /**< (I) The MappedProperty object tag */
    const char*     tc_propname       /**< (I) The Teamcenter propertry name */
    );

/**
    Asks the Teamcenter property name attribute for the given MappedProperty object.
*/
extern EINT_API int EINT_ask_mapped_property_tcpropname (
    tag_t           mapped_property,    /**< (I) The MappedProperty object tag */
    char**          tc_propname       /**< (OF) The returned Teamcenter property name */
    );

/**
    Finds all ObjetMapping objects in the Teamcenter database
*/
extern EINT_API int EINT_find_object_mapping (
    tag_t           datasource,         /**< (I) The ExternalDataSource tag */
    int*            num,                /**< (O) Number of ObjectMapping returned */
    tag_t**         object_mappings     /**< (OF) num The tags representing the returned ObjectMapping objects */
    );

/**
    Creates a new ObjectMapping object
*/
extern EINT_API int EINT_create_object_mapping (
    tag_t           data_source,            /**< (I) The ExternalDataSource tag */
    logical         persistent_flag,        /**< (I) The flag which indicates if the object created is
                                                    persistent or not */
    logical         related_to_item_flag,   /**< (I) This flag indicates if the object created will be
                                                    related to a Teamcenter Item or not */
    logical         update_on_save_flag,    /**< (I) This flag indicates if the object will be updated on save */
    tag_t           ext_attr_item,          /**< (I) The ExternalAttribute object tag which uses for the ItemId */
    tag_t           ext_attr_itemrev,       /**< (I) The ExternalAttribute object tag which uses for the ItemRevId */
    tag_t           ext_attr_itemname,      /**< (I) The ExtarnalAttribute object tag which uses for the ItemName */
    tag_t           ext_attr_itemdesc,      /**< (I) The ExternalAttribute object tag which uses for the ItemDesc */
    tag_t           itemtype,               /**< (I) The ExternalAttribute object tag which uses for the ItemType */
    const char*     sql_stmt,               /**< (I) The SQL statement for the ObjectMapping */
    const char*     store_procedure,        /**< (I) */
    tag_t*          object_mapping          /**< (O) The new ObjectMapping object tag */
    );

/**
    Set the datasource attribute for the ObjectMapping object.
*/
extern EINT_API int EINT_set_object_mapping_datasource (
    tag_t           object_mapping,     /**< (I) The ObjectMapping object tag */
    tag_t           datasource          /**< (I) The ExternalDataSource object tag */
    );

/**
    Returns the datasource attribute for the ObjectMapping object.
*/
extern EINT_API int EINT_ask_object_mapping_datasource (
    tag_t           object_mapping,     /**< (I) The ObjectMapping object tag */
    tag_t*          datasource          /**< (O) The returned External DataSource object tag */
    );

/**
    Set the persistent flag attribute for the ObjectMapping object.
*/
extern EINT_API int EINT_set_object_mapping_persistent_flag (
    tag_t           object_mapping,     /**< (I) The ObjectMapping object tag */
    logical         flag                /**< (I) The persistent flag */
    );

/**
    Returns the persistent flag attribute for the ObjectMapping object.
*/
extern EINT_API int EINT_ask_object_mapping_persistent_flag (
    tag_t           object_mapping,     /**< (I) The ObjectMapping object tag */
    logical*        flag                /**< (O) The persistent flag */
    );

/**
    Set the update on save flag attribute for the ObjectMapping object.
*/
extern EINT_API int EINT_set_object_mapping_update_on_save_flag (
    tag_t           object_mapping,     /**< (I) The ObjectMapping object tag */
    logical         flag                /**< (I) The update on save flag */
    );

/**
    Returns the update on save flag attribute for the ObjectMapping object.
*/
extern EINT_API int EINT_ask_object_mapping_update_on_save_flag (
    tag_t           object_mapping,     /**< (I) The ObjectMapping object tag */
    logical*        flag                /**< (O) The returned update on save flag */
    );

/**
    Set the related to Item flag attribute for the ObjectMapping object.
*/
extern EINT_API int EINT_set_object_mapping_related_to_item_flag (
    tag_t           object_mapping,     /**< (I) The ObjectMapping object tag */
    logical         flag                /**< (I) The related to Item flag */
    );

/**
    Returns the related to Item flag attribute for the ObjectMapping object.
*/
extern EINT_API int EINT_ask_object_mapping_related_to_item_flag (
    tag_t           object_mapping,     /**< (I) The ObjectMapping object tag */
    logical*        flag                /**< (O) The returned related to Item flag */
    );

/**
    Assigns the ExternalObject attribute which represents the Item Id for the ObjectMapping object.
*/
extern EINT_API int EINT_set_object_mapping_ext_attr_item (
    tag_t           object_mapping,     /**< (I) The ObjectMapping object tag */
    tag_t           ext_attr            /**< (I) The ExternalAttribute object tag which represents the ItemId */
    );

/**
    Returns the ExternalObject attribute which represents the Item Id for the ObjectMapping object.
*/
extern EINT_API int EINT_ask_object_mapping_ext_attr_item (
    tag_t           object_mapping,     /**< (I) The ObjectMapping object tag */
    tag_t*          ext_attr            /**< (O) The ExternalAttribute object tag which represents the Item Id */
    );

/**
    Assigns the ExternalObject attribute which represents the Item Rev Id for the ObjectMapping object.
*/
extern EINT_API int EINT_set_object_mapping_ext_attr_itemrev (
    tag_t           object_mapping,     /**< (I) The ObjectMapping object tag */
    tag_t           ext_attr            /**< (I) The ExternalAttribute object tag which represents the Item Rev Id */
    );

/**
    Returns the ExternalObject attribute which represents the Item Rev Id for the ObjectMapping object.
*/
extern EINT_API int EINT_ask_object_mapping_ext_attr_itemrev (
    tag_t           object_mapping,     /**< (I) The ObjectMapping object tag */
    tag_t*          ext_attr            /**< (O) The ExternalAttribute object tag which represents the Item Rev Id */
    );

/**
    Assigns the ExternalObject attribute which represents the Item name for the ObjectMapping object.
*/
extern EINT_API int EINT_set_object_mapping_ext_attr_itemname (
    tag_t           object_mapping,     /**< (I) The ObjectMapping object tag */
    tag_t           ext_attr            /**< (I) The ExternalAttribute object tag which represents the Item name */
    );

/**
    Returns the ExternalObject attribute which represents the Item name for the ObjectMapping object.
*/
extern EINT_API int EINT_ask_object_mapping_ext_attr_itemname (
    tag_t           object_mapping,     /**< (I) The ObjectMapping object tag */
    tag_t*          ext_attr            /**< (O) The ExternalAttribute object tag which represents the Item name */
    );

extern EINT_API int EINT_set_object_mapping_itemtype (
    tag_t           object_mapping,     /**< (I) */
    tag_t           itemtype            /**< (I) */
    );

extern EINT_API int EINT_ask_object_mapping_itemtype (
    tag_t           object_mapping,     /**< (I) */
    tag_t*          itemtype            /**< (O) */
    );

/**
    Assigns the ExternalObject attribute which represents the Item description for the ObjectMapping object.
*/
extern EINT_API int EINT_set_object_mapping_ext_attr_itemdesc (
    tag_t           object_mapping,     /**< (I) The ObjectMapping object tag */
    tag_t           ext_attr            /**< (I) The ExternalAttribute object tag which represents the Item description */
    );

/**
    Returns the ExternalObject attribute which represents the Item description for the ObjectMapping object.
*/
extern EINT_API int EINT_ask_object_mapping_ext_attr_itemdesc (
    tag_t           object_mapping,     /**< (I) The ObjectMapping object tag */
    tag_t*          ext_attr            /**< (O) The ExternalAttribute object tag which represents the Item description */
    );

/**
    Assigned the query_stmt attribute to the ObjectMapping.
*/
extern EINT_API int EINT_set_object_mapping_query_stmt (
    tag_t           object_mapping,     /**< (I) The ObjectMapping object tag */
    const char*     query_stmt          /**< (I) The SQL statement for the ObjectMapping */
    );

/**
    Returns the query_stmt attribute for the ObjectMapping
*/
extern EINT_API int EINT_ask_object_mapping_query_stmt (
    tag_t           object_mapping,     /**< (I) The ObjectMapping object tag */
    char**          query_stmt          /**< (OF) The SQL statement for the ObjectMapping */
    );

extern EINT_API int EINT_set_object_mapping_store_procedure (
    tag_t           object_mapping,     /**< (I) */
    const char*     procedure_name      /**< (I) */
    );

extern EINT_API int EINT_ask_object_mapping_store_procedure (
    tag_t           object_mapping,     /**< (I) */
    char**          procedure_name      /**< (OF) */
    );

/**
    Add an ExternalAttribute object to the ObjectMapping key list.
    The list stores all keys involved in the query for the ObjectMapping
*/
extern EINT_API int EINT_add_object_mapping_key (
    tag_t           object_mapping,     /**< (I) The ObjectMapping object tag */
    tag_t           ext_attr            /**< (I) The External Attribute object tag */
    );

/**
    Removes an ExternalAttribute object from the key list associated with the ObjectMapping.
*/
extern EINT_API int EINT_remove_object_mapping_key (
    tag_t           object_mapping,     /**< (I) The ObjectMapping object tag */
    tag_t           ext_attr            /**< (I) The External Attribute object tag */
    );

/**
    Returns all ExternalAttribute objects from the key list associated with the ObjectMapping.
*/
extern EINT_API int EINT_ask_object_mapping_keys (
    tag_t           object_mapping,     /**< (I) The ObjectMapping object tag */
    int*            num,                /**< (O) The number of ExternalAttribute object returned */
    tag_t**         ext_attrs           /**< (OF) num The External Attribute object tags */
    );

/**
    Removes all keys associated with the ObjectMapping object
*/
extern EINT_API int EINT_clear_object_mapping_keys (
    tag_t           object_mapping      /**< (I) The ObjectMapping object tag */
    );

/**
    Add an MappedProperty object to the mapped property list.
    This list represents all the mapped properties associated with the ObjectMapping
*/
extern EINT_API int EINT_add_object_mapping_mapped_prop (
    tag_t           object_mapping,     /**< (I) The ObjectMapping object tag */
    tag_t           mapped_property     /**< (I) The Mapped Property object tag */
    );

/**
    Removes an MappedProperty object from the mapped property list associated with the ObjectMapping.
*/
extern EINT_API int EINT_remove_object_mapping_mapped_prop (
    tag_t           object_mapping,     /**< (I) The ObjectMapping object tag */
    tag_t           mapped_property     /**< (I) The Mapped Property object tag */
    );

/**
    Returns all MappedProperty objects from the key list associated with the ObjectMapping.
*/
extern EINT_API int EINT_ask_object_mapping_mapped_props (
    tag_t           object_mapping,     /**< (I) The ObjectMapping object tag */
    int*            num,                /**< (O) The number of MappedProperty object returned */
    tag_t**         mapped_properties   /**< (OF) num The Mapped Property object tags */
    );

/**
    Removes all mapped properties associated with the ObjectMapping object
*/
extern EINT_API int EINT_clear_object_mapping_mapped_props (
    tag_t           object_mapping      /**< (I) The ObjectMapping object tag */
    );

/**
    Relates the given formtype to the ObjectMapping object.
*/
extern EINT_API int EINT_relate_object_mapping_to_formtype (
    tag_t           object_mapping,     /**< (I) The ObjectMapping object tag */
    tag_t           formtype            /**< (I) The number of MappedProperty object returned */
    );

extern EINT_API int EINT__init_classes();

extern EINT_API int EINT_register_runtime_props( void );

/** @} */

#ifdef __cplusplus
}
#endif

#include <eint/libeint_undef.h>
#endif
