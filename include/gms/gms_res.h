/*=============================================================================
                          Copyright (c) 2005 UGS
                   Unpublished - All rights reserved

   THIS PROGRAM IS AN UNPUBLISHED WORK FULLY PROTECTED BY THE UNITED STATES
  COPYRIGHT LAWS AND IS CONSIDERED A TRADE SECRET BELONGING TO THE COPYRIGHT
                                   HOLDER.
==============================================================================*/
/**
    @file

    This file contains site reservation ITK interfaces
*/

/*  */


/**
    @defgroup GMS_RES Global Multi Site Reservation

    The GMS reservation (GMS_RES) ITK functions provide site check-out, site check-in, site cancel check-out, 
    functionality.
    This uses the same mechanism that the RES module uses.i.e
    An ImanReservation object is associated with each checked out object via an IMAN_RES_checkout GRM relation.
    This reservation functionality gives the capability to reserve objects for other sites to modification.
     

    Not all objects can be site checked out. The following classes and their sub-classes are valid for check-out:
    <UL>
    <LI>Dataset
    <LI>Form
    <LI>Item
    <LI>ItemRevision
    <LI>PSBOMView
    <LI>PSBOMViewRevision 
    </UL>

    To use reservation ITK functions, include the gms_res.h file in the source code.

    The Site reservation functionality uses the following attributes of the ImanReservation:

    <table>
    <tr><td>Attribute            </td><td>Description                                                            </td></tr>
    <tr><td>Site Reserved        </td><td>A logical to differentiate the site check out from remote check out.   </td></tr>
    <tr><td>Remote site          </td><td>Tag of the site to which the object is checked out.                    </td></tr>
    <tr><td>Reservation Type     </td><td>Integer that indicates whether check-out is with or without export.
                                          This attribute has RES_EXCLUSIVE_RESERVE for site checkout.            </td></tr>
    <tr><td>User                 </td><td>Tag to the user that currently holds the associated object's check-out.
                                          It can be a NULLTAG in case of replica                                 </td></tr>
    <tr><td>Group object          </td><td>Tag of the group objectof the user who site checked out the object.
                                          It can be a NULLTAG in case of replica                                 </td></tr>
    <tr><td>Reservation State    </td><td>Integer that holds ImanReservation object current check-out state.
                                          This attribute has #RES_RESERVE                                        </td></tr>
    <tr><td>Notification List    </td><td>VLA containing the tags of users that wish to be notified when
                                          the associated object's check-out status changes.                      </td></tr>
    <tr><td>Date                 </td><td>A date_t that holds the date of the current check-out.                 </td></tr>
    </table>

    @{
*/

#ifndef GMS_RES_HHH
#define GMS_RES_HHH

#include <tc/tc_startup.h>
#include <tccore/workspaceobject.h>

#include <gms/libgms_exports.h>

#ifdef __cplusplus
extern "C"{
#endif


/**

*/
extern GMS_API int GMS_RES_site_check_out2(
    tag_t object_tag,                           /**< (I) Object to checkout */
    tag_t site_tag,                             /**< (I) Site to which to Checkout */
    const char *reason,                         /**< (I) Reason for checkout */
    const char *change_id                       /**< (I) Change Id */
    );

extern GMS_API int GMS_RES_site_check_in(
    tag_t object_tag                            /**< (I) Object to checkin */
    );

extern GMS_API int GMS_RES_cancel_site_check_out(
    tag_t object_tag                            /**< (I) Object to cancel checkout */
    );

extern GMS_API int GMS_RES_is_site_reserved(
    tag_t object_tag,                           /**< (I) Object to be checked */
    logical * is_site_reserved,                 /**< (O) Is site checked out flag */
    tag_t * site_tag                            /**< (O) The site to which it is checked out */
    );

#ifdef __cplusplus
}
#endif

/** @} */

#include <gms/libgms_undef.h>
#endif

