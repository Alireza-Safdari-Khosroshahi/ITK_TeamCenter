/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This file contains the prototypes for the ITK functions for the Envelope class.

    Envelope is a subclass of Folder.
    Therefore, all FL and WSOM functions work with objects of this class.
    #FL_insert, #FL_remove and #FL_ask_references are the only way to
    add, remove, or ask the contents of the envelope. 
    Additionally, all AOM functions work with envelopes.

    The basic process involved with mail is to create an envelope, 
    insert the objects that you desire to mail,
    add the users, group members, groups, or distribution lists that
    you wish to send the objects to, and then send the envelope.
*/

/*  */

#ifndef ENVELOPE_H
#define ENVELOPE_H

#include <unidefs.h>

#include <tccore/workspaceobject.h>
#include <tc/libtc_exports.h>

/**
    @defgroup MAIL Teamcenter Mail

    An alias list is a list of objects to which the system can send mail.
    Users, groups, group members, or other distribution lists can be added to an alias list. 
    The alias list is same as the Address List shown in the Teamcenter user interface. 
    You can use these objects in regular Teamcenter mail or as notification lists for authorizations.

    The ImanAliasList class is a subclass of POM_application_object.
    All AOM functions work with alias lists.

    @{
*/

typedef struct MAIL_message_s
{
    tag_t       tag;              /**< Tag of the envelope from where the email is sent */
    const char* from_user;        /**< Email address of the sender */
    const char* to_user;          /**< Email address of the recipient */
    const char* subject;          /**< Subject of the email */
    const char* text;             /**< Body of the email */
    logical     is_Cc_recipient;  /**< Specifies if the recipient is a carbon-copy recipient */
} MAIL_message_t;

typedef int (* MAIL_send_callback_t) ( MAIL_message_t message );

typedef enum MAIL_callback_position_e
{
    MAIL_replaced_callback,
    MAIL_before_callback,
    MAIL_after_callback
}   MAIL_callback_position_t;

typedef enum MAIL_to_or_cc_e
{
    MAIL_send_to,
    MAIL_send_cc
} MAIL_to_or_cc_t;

#ifdef __cplusplus
extern "C"{
#endif

extern TC_API int MAIL_envelope_extent(
    int*            n_instances,    /**< (O) */
    tag_t**         instances       /**< (OF) n_instances */
    );

/**
   Creates a new envelope.
   The values for subject and comments may be read back with
   #WSOM_ask_name2 and #WSOM_ask_description2 respectively.
   
   @note From Tc9.0 onwards, please use generic creation of BusinessObject (i.e. createBusinessObject (C++) or #TCTYPE_create_object ).
*/
extern TC_API int MAIL_create_envelope (
    const char      subject[WSO_name_size_c + 1],   /**< (I) */
    const char      comments[WSO_desc_size_c + 1],  /**< (I) */
    tag_t*          envelope                        /**< (O) */
    );


/**
    Initializes an envelope.
    <br/>Call this function immediately after creating an instance of a subclass of Envelope.
*/
extern TC_API int MAIL_initialize_envelope2 (
    tag_t           envelope,                       /**< (I) */
    const char      *subject,                       /**< (I) */
    const char      *comments                       /**< (I) */
    );

/**
    Adds a new recipient (receiver) to an envelope.
    This can be a user, a groupmember, a group, or a distribution list.
*/
extern TC_API int MAIL_add_envelope_receiver (
    tag_t           envelope,   /**< (I) */
    tag_t           receiver    /**< (I) */
    );

/**
    Adds a new carbon copy recipient (ccReceiver) to an envelope.
    This can be a user, a groupmember, a group, or a distribution list.
*/
extern TC_API int MAIL_add_envelope_cc_receiver (
    tag_t           envelope,   /**< (I) */
    tag_t           ccReceiver  /**< (I) */
    );

/**
    Lists all of the current receivers for the given envelope.
*/
extern TC_API int MAIL_list_envelope_receivers (
    tag_t           envelope,   /**< (I) */
    int*            count,      /**< (O) */
    tag_t**         receivers   /**< (OF) count */
    );

/**
    Lists all of the current primary receivers for the given envelope.
*/
extern TC_API int MAIL_list_envelope_to_receivers (
    tag_t           envelope,   /**< (I) */
    int*            count,      /**< (O) */
    tag_t**         receivers   /**< (OF) count */
    );

/**
    Lists all of the current carbon copy receivers for the given envelope.
*/
extern TC_API int MAIL_list_envelope_cc_receivers (
    tag_t           envelope,    /**< (I) */
    int*            count,       /**< (O) */
    tag_t**         ccReceivers  /**< (OF) count */
    );

/**
    Sends the envelope and its contents to all of the envelope's receivers.
    Once this ITK has been called, the envelope is deleted.

    If the preference Mail_OSMail_activated is not set to true, only Teamcenter 
    mail will be sent, and external recipients will not receive the mail.
*/
extern TC_API int MAIL_send_envelope (
    tag_t           envelope    /**< (I) */
    );

/**
   Registers functions to execute in relation with sending OS Mail.

   When the value of position is MAIL_replaced_callback, the given function will totally
   replace the Teamcenter OSMail code.
   When the value of position is MAIL_before_callback, the given function will be executed
   prior to the OS Mail function (it being either the Teamcenter function or the one given
   through a call to this function with position=MAIL_replaced_callback).
   When the value of position is MAIL_after_callback, the given function will be executed 
   after the OS Mail function.

   The registered functions and/or the Teamcenter mail function are executed only if the
   preference Mail_OSMail_activated is set to TRUE. 
   Besides, they are executed once for each internal recipient.
 */
extern TC_API int MAIL_register_send_callback(
    MAIL_send_callback_t        function_pointer, /**< (I) */
    MAIL_callback_position_t    position          /**< (I) */ 
    );

/**
   Adds a new external recipient (receiver) to an envelope.
   This receiver should be a recognizable e-mail address or alias that is recognized in the current mail domain.
   It must also be specified whether this address is to be on the To list or CC list of the outgoing e-mail.
   
   Note that the preference Mail_OSMail_activated must be set to TRUE for those recipients to receive the message.
*/
extern TC_API int MAIL_add_external_receiver (
    tag_t           envelope,   /**< (I) The envelope tag */
    MAIL_to_or_cc_t to_or_cc,   /**< (I) To or CC information. This must be either #MAIL_send_to or #MAIL_send_cc. */
    char*           receiver    /**< (I) Valid e-mail address ( e.g., joe@company.com ) */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <tc/libtc_undef.h>

#endif
