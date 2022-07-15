/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This file contains the Object Directory Services Module prototypes and typedefs
    for the ITK interface
*/

/*  */

#ifndef ODS_ITK_HHH
#define ODS_ITK_HHH

#include <tc/tc_startup.h>
#include <publication/libpublication_exports.h>

/**
    @defgroup ODS Object Directory Services (ODS)
    @ingroup PUBR

    <b>Common Return Values</b>

    <table>
    <tr><td>Return Value               </td><td>Description                                              </td></tr> 
    <tr><td>#CXPOM_invalid_tag         </td><td>Specified object tag is not valid.                       </td></tr> 
    <tr><td>#ODS_no_such_site          </td><td>Specified site ID does not exist                         </td></tr> 
    <tr><td>#ODS_no_connect            </td><td>Unable to establish network connection to specified ODS  </td></tr> 
    <tr><td>#ODS_client_access_denied  </td><td>Specified ODS the site does not allow requests from the site where
                                                the publication request came from.                       </td></tr> 
    <tr><td>#ODS_no_default_site       </td><td>Specified site ID is zero but the default ODS was not defined in
                                                site preference file                                     </td></tr> 
    <tr><td>#POM_invalid_tag           </td><td>Specified object tag is not a valid.                     </td></tr> 
    <tr><td>#PUBR_not_publishable_class</td><td>Class of the specified object is not a publishable class.</td></tr>
    </table>
    @{
*/

#ifdef __cplusplus
    extern "C"{
#endif

/**
    Publishes the object to the specified ODS site. The object must be owned by the local site.

    <b>Restrictions:</b>

    The class of the specified object must be a publishable class.
    The specified site must be an ODS site.
*/
extern PUBLICATION_API int ODS_publish_object(
    int                    site_id,     /**< (I) Site ID of ODS site to publish to. If 0, the default ODS will be used. */
    tag_t                  obj_tag      /**< (I) Tag of the object to be published */
    );

/**
    Returns Publication Record information about the specified object previously published to the specified ODS site.
    The information is returned via the description object, 
    which is a run-time object whose properties correspond to the attributes of a Publication Record.

    The Property ITK functions should be used to get the desired property values. 
    The property names are documented in the file named system_property_names.uih under "PublishedObject properties".

    The following properties can be obtained:

    <table>
    <tr><td>Property Name           </td><td>Value Type             </td></tr>
    <tr><td>po_object_tag           </td><td>#PROP_untyped_reference</td></tr>
    <tr><td>po_owning_site          </td><td>#PROP_int              </td></tr>
    <tr><td>po_pub_date             </td><td>#PROP_date             </td></tr>
    <tr><td>po_object_class         </td><td>#PROP_string           </td></tr>
    <tr><td>po_object_type          </td><td>#PROP_string           </td></tr>
    <tr><td>po_object_id            </td><td>#PROP_string           </td></tr>
    <tr><td>po_object_name          </td><td>#PROP_string           </td></tr>
    <tr><td>po_owner_id             </td><td>#PROP_string           </td></tr>
    <tr><td>po_group_id             </td><td>#PROP_string           </td></tr>
    <tr><td>po_object_creation_date </td><td>#PROP_date             </td></tr>
    <tr><td>po_object_desc          </td><td>#PROP_string           </td></tr>
    <tr><td>po_object_rel_stat_names</td><td>#PROP_string           </td></tr>
    </table>

    After the Publication Record information is obtained,
    the description object should be deleted using #ODS_free_description_object.

    <b>Restrictions:</b>
    
    The specified site must be an ODS site.
*/
extern PUBLICATION_API int ODS_describe_object(
    int                    site_id,             /**< (I) Site ID of ODS site. If 0, the default ODS will be used */
    tag_t                  obj_tag,             /**< (I) Tag of the object to get information on */
    tag_t*                 description_obj_tag  /**< (O) Tag of description object */
    );

/**
    Returns the current owning site of the object by searching the specified ODS sites.

    <b>Restrictions:</b>
    
    The object must be previously published.
*/
extern PUBLICATION_API int ODS_locate_object(
    int                    n_ods_site_ids,  /**< (I) Number of ODS sites to search */
    int*                   ods_site_ids,    /**< (I) n_ods_site_ids Site IDs of all ODS sites to search */
    tag_t                  obj_tag,         /**< (I) Tag of the object to be located */
    logical*               found,           /**< (O) Logical that is set to TRUE if object is located and FALSE if not located */
    int*                   site_id          /**< (O) Site ID of site that currently owns the object */
    );

/**
    Unpublishes the object from the specified ODS site. 
    The object must be owned by the local site and the object must have been previously published.

    <b>Restrictions:</b>

    The class of the specified object must be a publishable class.
    The specified site must be an ODS site.
*/
extern PUBLICATION_API int ODS_unpublish_object(
    int                    site_id,     /**< (I) Site ID of ODS site to unpublish from.
                                            If 0, the default ODS will be used. */
    tag_t                  obj_tag      /**< (I) Tag of the object to be unpublished */
    );

/**
    Re-publishes the object to the specified ODS site.
    The object must be owned by the local site and must have been previously published.

    <b>Restrictions:</b>

    The class of the specified object must be a publishable class. 
    The specified site must be an ODS site.
*/
extern PUBLICATION_API int ODS_refresh_object(
    int                    site_id,     /**< (I) Site ID of ODS site to re-publish to.
                                            If 0, the default ODS will be used. */
    tag_t                  obj_tag      /**< (I) Tag of the object to be re-published */
    );

/**
    Frees the memory allocated to the specified description object.
    See #ODS_describe_object for more details about description objects.

    <b>Restrictions:</b>

    The description object must have been obtained from a previous call to #ODS_describe_object.
*/
extern PUBLICATION_API int ODS_free_description_object(
    tag_t                  description_obj_tag      /**< (I) Tag of the description object */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <publication/libpublication_undef.h>

#endif
