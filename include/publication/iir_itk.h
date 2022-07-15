/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Item ID Record functions
*/

/*  */

#ifndef IIR_ITK_HHH
#define IIR_ITK_HHH

#include <tc/tc_startup.h>

/**
    @defgroup IIR Item ID Registry (IIR)
    @ingroup PUBR

    The Item ID Registry is a centralized database of all Item Ids that have been assigned
    throughout the Teamcenter Engineering federation.
    @{
*/

#define ITEM_REGISTRY_ACTIVE                    "ITEM_id_registry"
#define ITEM_REGISTRY_SITE                      "ITEM_id_registry_site"
#define ITEM_REGISTRY_UNREGISTER_ON_DELETE      "ITEM_id_unregister_on_delete"
#define ITEM_REGISTRY_ALLOW_IF_SERVER_DOWN      "ITEM_id_allow_if_registry_down"
#define ITEM_REGISTRY_REGISTER_ON_CREATE        "ITEM_id_always_register_on_creation"

#include <publication/libpublication_exports.h>

#ifdef __cplusplus
    extern "C"{
#endif

/**
    This function is used to register an item id.
*/
extern PUBLICATION_API int IIR_register_item_id(
    const char*            item_id,     /**< (I) The item id to be registered */
    int                    site_id      /**< (I) */
    );

/**
    This function is used to unregister an item id.

    <b>Return Values:</b>

    #IIR_item_not_registered - Item ID not found in registry database
*/
extern PUBLICATION_API int IIR_unregister_item_id(
    const char*            item_id,     /**< (I) The item id to be unregistered */
    int                    site_id      /**< (I) */
    );

extern PUBLICATION_API int IIR_is_item_id_registered(
    const char*            item_id,     /**< (I) */
    int*                   verdict,     /**< (O) */
    int                    site_id      /**< (I) */
    );

extern PUBLICATION_API int IIR_register_item_with_mfk(
    tag_t                         item_tag,           /**< (I) */
    int                          site_id              /**< (I) */
    );

extern PUBLICATION_API int IIR_unregister_item_with_mfk(
    tag_t                        item_tag,            /**< (I) */
    int                          site_id              /**< (I) */
    );

extern PUBLICATION_API int IIR_is_item_with_mfk_registered(
    tag_t                        item_tag,            /**< (I) */
    int                         * verdict,            /**< (O) */
    int                         site_id               /**< (I) */
    );

/**
   Registers a Multi-Field Key Identifier for a given MFKItem (Multi-Field Key Definition Item).

   @returns
   <ul>
   <li>#ITK_ok on success 
   <li>#IIR_registry_not_active if the item id registry is not active.
   <li>#ODS_function_unavailable if the Object Directory Services (ODS) server is not available.
   <li>#IIR_invalid_item_id_arg if the input arguments given are not valid.
   </ul>
*/
extern PUBLICATION_API int IIR_register_item_mfk_id(
     tag_t          type_tag,       /**< (I) Item type tag                           */
     int            n_key_values,   /**< (I) Number of key-value pairs               */
     const char**   keys,           /**< (I) Array of keys                           */
     const char**   values,         /**< (I) Array of values                         */
     int            site_id         /**< (I) Object Directory Services (ODS) site ID */
     );

/**
   Unregisters a Multi-Field Key Identifier for a given MFKItem (Multi-Field Key Definition Item).

   @returns
   <ul>
   <li>#ITK_ok on success 
   <li>#IIR_registry_not_active if the item id registry is not active.
   <li>#ODS_function_unavailable if the Object Directory Services (ODS) server is not available.
   <li>#IIR_invalid_item_id_arg if the input arguments given are not valid.
   </ul>
*/
extern PUBLICATION_API int IIR_unregister_item_mfk_id(
     tag_t          type_tag,       /**< (I) Item type tag                           */
     int            n_key_values,   /**< (I) Number of key-value pairs               */
     const char**   keys,           /**< (I) Array of keys                           */
     const char**   values,         /**< (I) Array of values                         */
     int            site_id         /**< (I) Object Directory Services (ODS) site ID */
     );

/**
   Checks if a Multi-Field Key Identifier for a given MFKItem (Multi-Field Key Definition Item) is registered.

   @returns
   <ul>
   <li>#ITK_ok on success 
   <li>#IIR_registry_not_active if the item id registry is not active.
   <li>#ODS_function_unavailable if the Object Directory Services (ODS) server is not available.
   <li>#IIR_invalid_item_id_arg if the input arguments given are not valid.
   </ul>
*/
extern PUBLICATION_API int IIR_is_item_mfk_id_registered(
     tag_t          type_tag,       /**< (I) Item type tag                             */
     int            n_key_values,   /**< (I) Number of key-value pairs                 */
     const char**   keys,           /**< (I) Array of keys                             */
     const char**   values,         /**< (I) Array of values                           */
     int*           verdict,        /**< (O) Given Multi-Field ID is registered or not */
     int            site_id         /**< (I) Object Directory Services (ODS) site ID   */
     );



/**
    Registers the specified Item in the PostAction extension of Item Create event.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#IIR_registry_not_active if the item registry is not active 
    <li>#IIR_invalid_item_id_arg if an invalid @p item_id is supplied 
    <li>#ODS_function_unavailable if an incompatible ODS server is used for Item registration
    <li>#POM_attr_null_forbidden if @p item_id is an empty string. 
    <li>Possibly a BMF (Business Modeler Framework) error if there are any issues with the customization for this method.
    </ul>
*/
extern PUBLICATION_API int IIR_postaction_register_item_id (
    const char* item_id,        /**< (I) The item_id used for registering the item. */
    int   site_id               /**< (I) Object Directory Services (ODS) site ID */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <publication/libpublication_undef.h>

#endif
