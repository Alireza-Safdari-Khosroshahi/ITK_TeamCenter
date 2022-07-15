/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This header file declares all data types and constants to be used by
    clients of the Event Manager.
*/

/*  */

#ifndef TCEVENTMGR_H
#define TCEVENTMGR_H

#include <tc/tc_startup.h>
#include <stdarg.h>
#include <sub_mgr/libsub_mgr_exports.h>

/**
    @defgroup TCEVENTMGR Event Mangager
    @ingroup SUBSCRIPTION
    @{
*/

#define  TCEVENTMGR_name_size_c 32

#ifdef __cplusplus
extern "C"{
#endif


/**  
      Post an event to Subscription and Audit manager for @p target_object. 
      @note This API handles the specified objects class configuration regardless if it is subscribable/auditable or not.
      @returns
      <ul>
      <li>#ITK_ok on success
      <li>#TCEVENTTYPE_does_not_exist if @p event_type_name is invalid.
      </ul>
  */
extern SUB_MGR_API int TCEVENTMGR_post_event_2 (
    tag_t              target_object,                               /**< (I) Object on which event is posted */
    const char         *event_type_name                             /**< (I) Event type name to post event */
    );

/**  
      Post an event to Subscription and Audit manager for @p target_object along with the specified parameters.
      @note This API handles the specified objects class configuration regardless if it is subscribable/auditable or not.
      @returns
      <ul>
      <li>#ITK_ok on success
      <li>#TCEVENTTYPE_does_not_exist if @p event_type_name is invalid.
      </ul>
  */
extern SUB_MGR_API int TCEVENTMGR_post_event2_2 (
    tag_t              target_object,                             /**< (I) Object on which event is posted */
    tag_t              secondary_object,                          /**< (I) Secondary object associated in event with target object */
    const char         *event_type_name,                          /**< (I) Event type name to post event */
    int                n_attributes,                              /**< (I) Number of attributes to log in event */
    const char**       attribute_names,                           /**< (I) Attribute names to log in event */
    const char**       attribute_values,                          /**< (I) Attribute values to log in event */
    int                error_code,                                /**< (I) Error code to log in event*/
    const char*        error_message                              /**< (I) Error message to log in event */
    );

/**
      Posts an event for multiple objects.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#TCEVENTTYPE_does_not_exist if @p event_type is invalid.
    </ul>

    @note It handles specified objects class configuration whether it is subscrible/auditable or not.
  */
extern SUB_MGR_API int TCEVENTMGR_post_event_bulk (
    const unsigned int  n_targets,          /**< (I) Number of objects. */
    const tag_t*        targets,            /**< (I) n_targets The objects on which the event has occurred. */
    const char*         event_type          /**< (I) Name of the event type. */
    );

/**
    Posts an Assign Status event.
*/
extern SUB_MGR_API int TCEVENTMGR_post_assign_status_event(
    tag_t              object,                      /**< (I) Tag of the object that the release status is assigned to */
    const char*        release_status_type_name     /**< (I) Name of the release status type */
    );

/**
   Posts an Attach event.
*/
extern SUB_MGR_API int TCEVENTMGR_post_attach_event(
    tag_t              relation     /**< (I) Tag of the relation instance that is being created,
                                            and the secondary object of the relation is being attached to
                                            the primary object of the relation. */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <sub_mgr/libsub_mgr_undef.h>

#endif
