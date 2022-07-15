/* Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright $2014.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software */

/**
    @ingroup BO
    @{
*/
#ifndef METAFRAMEWORK_H
#define METAFRAMEWORK_H

#include <unidefs.h>
#include <metaframework/libmetaframework_exports.h>

#ifdef __cplusplus
extern "C"{
#endif

/**
   Retrieves the children for the input BusinessObject.

 */
extern METAFRAMEWORK_API int BO_get_children (
    tag_t object,                                /**< (I) The object for which to get children. */
    int property_names_count,                    /**< (I) The number of propertyNames which are input */
    const char ** property_names,                /**< (I) Optional listing of children (property names) to return. 
                                                    <br/>If empty, then the TYPE_DefaultChildProperties preference is used. */
    int         * child_count,                   /**< (O) The count of @p child_tags and @p child_context_property_names being returned. */
    tag_t      ** child_tags,                    /**< (OF) child_count The tags of the children */
    char      *** child_context_property_names   /**< (OF) child_count The context (property name) in which the child exists
                                                    in relationship to the input @p object.
                                                 */
    );
    
/**
   Transforms the tag for a type of type ImanType to a string of 
   format TYPE::&lt;typeName&gt;::&lt;ClassName&gt;::&lt;ParentTypeName&gt;.

   <br/>For example, calling with the tag for a type of type "Document" would  
   result in the following string: "TYPE::Document::Item::Item".
   
   @returns
   <ul>
   <li>#ITK_ok on success
   <li>Possibly other errors.
   </ul>
 */
extern METAFRAMEWORK_API int BOREG_tag_to_uid (
    tag_t   tag,           /**< (I)  Tag of the ImanType*/
    char ** string         /**< (OF) UID of the ImanType */
    );

/**
   Transforms a UID string to the tag for a type of type ImanType.

   <br/>For example, calling with a UID "TYPE::Document::Item::Item" will result 
   in the tag for a type of type "Document".

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>Possibly other errors.
   </ul>
 */
extern METAFRAMEWORK_API int BOREG_uid_to_tag (
    const char * uid,               /**< (I) UID string of the ImanType */
    tag_t * tag                     /**< (O) Tag of the ImanType */
    );

/**
   Transforms the tag for session-recoverable RuntimeBusinessObject to a GUID string.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#METAFRAMEWORK_invalid_runtimebusinessobject if @p rbo_tag is #NULLTAG or is a persistent object.
   </ul>
 */
extern METAFRAMEWORK_API int BOREG_rbotag_to_guid (
    tag_t   rbo_tag,      /**< (I) Tag of the session-recoverable RuntimeBusinessObject */
    char ** guid          /**< (OF) GUID string of the RuntimeBusinessObject */
    );

/**
   Transforms a GUID string representing a session-recoverable RuntimeBusinessObject to a tag.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#POM_component_id_not_found if @p guid is not recognized.
   </ul>
 */
extern METAFRAMEWORK_API int BOREG_guid_to_rbotag (
    const char * guid,    /**< (I) GUID string representing a session-recoverable RuntimeBusinessObject */
    tag_t *      rbo_tag  /**< (O) Tag of the RuntimeBusinessObject */
    );


#ifdef __cplusplus
}
#endif

/**
    @}
*/

#include <metaframework/libmetaframework_undef.h>
#endif
