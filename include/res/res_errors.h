/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Definition of error codes associated with Check-in/Check-out module.
*/

/*  */

#ifndef RES_ERRORS_H_INCLUDED
#define RES_ERRORS_H_INCLUDED

#include <common/emh_const.h>

/**
    @defgroup RES_ERRORS Reservation Errors
    @ingroup RES
    @{
*/

#define RES_ERROR_BASE                          EMH_RES_error_base
/** This action is not currently supported for ImanReservation object. */
#define RES_INVALID_ACTION                      RES_ERROR_BASE + 1

/** There is no object to paste. */
#define RES_NO_OBJECT_TO_PASTE                  RES_ERROR_BASE + 2

/** No dataset can be found. */
#define RES_NO_DATASET_FOUND                    RES_ERROR_BASE + 3

/** There is no object to check-out. */
#define RES_NO_OBJECT_TO_RESERVE                RES_ERROR_BASE + 4

/** No project ID is provided. */
#define RES_NO_PROJECTID                        RES_ERROR_BASE + 5

/** No reason has been provided. */
#define RES_NO_REASON                           RES_ERROR_BASE + 6

/** No directory has been provided. */
#define RES_NO_DIRECTORY_NAME                   RES_ERROR_BASE + 7

/** An error has occurred during the creation of an ImanReservation object. */
#define RES_CREATE_ERROR                        RES_ERROR_BASE + 8

/** "%1$" is checked-out by "%2$". */
#define RES_OBJECT_IS_RESERVED                  RES_ERROR_BASE + 9

/** No reservation is selected. */
#define RES_NO_RESERVATION_SELECTED             RES_ERROR_BASE + 10

/** No object is selected. */
#define RES_NO_OBJECT_SELECTED                  RES_ERROR_BASE + 11

/** Submission error has occurred. */
#define RES_SUBMIT_ERROR                        RES_ERROR_BASE + 12

/** An error has occurred during the uncheck-out. */
#define RES_UNRESERVE_ERROR                     RES_ERROR_BASE + 13

/** An error has occurred while deleting the ImanReservation object. */
#define RES_DESTROY_ERROR                       RES_ERROR_BASE + 14

/** "%1$" is not checked-out. */
#define RES_OBJECTS_NOT_RESERVED                RES_ERROR_BASE + 15

/** Objects are still checked-out. */
#define RES_IS_RESERVED                         RES_ERROR_BASE + 16

/** "%1$" cannot be modified nor deleted because it was checked-out by "%2$" on %3$. */
#define RES_UNABLE_TO_SAVE                      RES_ERROR_BASE + 17

/** An invalid file name is provided. */
#define RES_INVALID_FILE_NAME                   RES_ERROR_BASE + 18

/** Deleting a checked-out object is not allowed. */
#define RES_UNABLE_TO_DESTROY                   RES_ERROR_BASE + 19

/** The action cannot be performed because "%1$" was checked-out by "%2$" on %3$. */
#define RES_IS_NOT_RESERVER                     RES_ERROR_BASE + 20

/** An error has occurred while looking for checked-out objects. */
#define RES_FIND_RESERVATION_ERROR              RES_ERROR_BASE + 21

/** An error has occurred while retrieving the reservation type. */
#define RES_ERROR_GET_RESERVATION_TYPE          RES_ERROR_BASE + 22

/** The object is not a Dataset. */
#define RES_NOT_A_DATASET                       RES_ERROR_BASE + 23

/** An error has occurred while searching for the check-out user. */
#define RES_ERROR_FIND_RESERVER                 RES_ERROR_BASE + 24

/** An ImanReservation object cannot be created or opened from here. */
#define RES_CANT_CREATE_OPEN                    RES_ERROR_BASE + 25

/** An error has occurred while trying to removing files in a checked-out directory. */
#define RES_REMOVE_CHECKED_OUT_FILES            RES_ERROR_BASE + 26

/** You do not have sufficient privileges for the object "%1$". Verify its protection. */
#define RES_NO_PRIVILEGE                        RES_ERROR_BASE + 27

/** Purging a checked-out object is not allowed. */
#define RES_PURGE_NOT_ALLOW                     RES_ERROR_BASE + 28

/** The file name is too long. */
#define RES_LONG_FILE_NAME                      RES_ERROR_BASE + 29

/** The user already exists in the notification list. */
#define RES_USER_ALREADY_IN_NOTIFYLIST          RES_ERROR_BASE + 30

/** No Change ID is provided. */
#define RES_NO_CHANGEID                         RES_ERROR_BASE + 31

/** An error has occurred while retrieving the export directory. */
#define RES_NO_EXPORT_DIRECTORY                 RES_ERROR_BASE + 32

/** You are already in the notification list for this object. */
#define RES_ALREADY_IN_NOTIFYLIST               RES_ERROR_BASE + 33

/** The user is not in the notification list. */
#define RES_USER_NOT_IN_NOTIFYLIST              RES_ERROR_BASE + 34

/** The notification list is empty. */
#define RES_NOTIFYLIST_EMPTY                    RES_ERROR_BASE + 35

/** An error has occurred while removing a user from the notification list. */
#define RES_REMOVE_FROM_NOTIFYLIST              RES_ERROR_BASE + 36

/** An error has occurred while sending the notification. */
#define RES_NOTIFICATION_ERROR                  RES_ERROR_BASE + 37

/** Error in Check-Out History. */
#define RES_CHECKOUT_HISTORY_ERROR              RES_ERROR_BASE + 38

/** An error has occurred while adding to the notification list. */
#define RES_ADD_TO_NOTIFYLIST                   RES_ERROR_BASE + 39

/** There are no active Change Packages in Teamcenter. A list of valid Change IDs cannot be generated. */
#define RES_NO_CHANGE_IDS                       RES_ERROR_BASE + 40

/** Error in object-relation. */
#define RES_GRM_RELATION                        RES_ERROR_BASE + 41

/** An error has occurred while retrieving the notification list. */
#define RES_NOTIFYLIST_ERROR                    RES_ERROR_BASE + 42

/** The Dataset cannot be exported because it has no data. */
#define RES_NO_DATA_TO_EXPORT                   RES_ERROR_BASE + 43

/** An invalid date is provided. */
#define RES_INVALID_DATE                        RES_ERROR_BASE + 44

/** No audit file exists for "%1$". */
#define RES_NO_AUDIT_FILE                       RES_ERROR_BASE + 45

/** The restoration of "%1$" to pre-check-out state has failed. */
#define RES_CANT_RESTORE_OBJECT                 RES_ERROR_BASE + 48

/** An error has occurred while deleting the ImanReservation object. */
#define RES_CANT_DELETE_RESERVATION             RES_ERROR_BASE + 49

/** Setting the attributes of the ImanReservation object has failed. */
#define RES_ERROR_SET_RESERVATION_ATTRIBUTES    RES_ERROR_BASE + 50

/** "%1$" is archived and cannot, therefore, be checked-out. */
#define RES_CANT_CO_ARCHIVED                    RES_ERROR_BASE + 51

/** "%1$" exported while checked-out. */
#define RES_EXPORTED_ON_CHECKOUT                RES_ERROR_BASE + 52

/** The type of "%1$" is not supported for check-out. */
#define RES_UNSUPPORTED_TYPE                    RES_ERROR_BASE + 53

/** Only system administrators are allowed to list the check-outs for another user. */
#define RES_LISTCO_DISALLOWED                   RES_ERROR_BASE + 54

/** "%1$" is already checked-out by the specified user. The transfer of check-out must be done using a different user. */
#define RES_NO_SELF_TRANSFER                    RES_ERROR_BASE + 56

/** The user is not a member of the group. */
#define RES_USER_NOT_MEMBER_OF_GROUP            RES_ERROR_BASE + 57

/** Select a user before pressing the button. */
#define RES_SELECT_USER_FROM_LIST               RES_ERROR_BASE + 58

/** The ImanReservation object attribute cannot be changed be because it is already set for a given ImanReservation tag. */
#define RES_RESERVED_OBJECT_EXISTS              RES_ERROR_BASE + 59

/** "%1$" is referenced by an ImanReservation object. Clear its notification list before deleting. */
#define RES_REFERENCED_BY_RESERVATION           RES_ERROR_BASE + 60

/** The "Cancel Check-Out"/"Object Restore" operation is not supported for this object. Check-in "%1$" instead. */
#define RES_CCO_NOT_SUPPORTED                   RES_ERROR_BASE + 61

/** "%1$" is checked-out with export by "%2$". It must be checked-in to allow updates. */
#define RES_EXPORT_UNMODIFIABLE                 RES_ERROR_BASE + 62

/** Only a system administrator can remove someone other than herself/himself from the notification list. */
#define RES_SA_PRIVILEGE                        RES_ERROR_BASE + 63

/** An invalid user ID is provided. */
#define RES_INVALID_USERID                      RES_ERROR_BASE + 64

/** An invalid Reservation type is provided. */
#define RES_INVALID_RESERVATION_TYPE            RES_ERROR_BASE + 65

/** An invalid Reservation state is provided. */
#define RES_INVALID_RESERVATION_STATE           RES_ERROR_BASE + 66

/** Only one "List of checked-out objects" dialog box is allowed at one time in a Teamcenter session. */
#define RES_LISTCO_ONE_DIALOG                   RES_ERROR_BASE + 67

/** Non-Workspace Objects cannot be checked-out. */
#define RES_CANT_CHECKOUT_NON_WSOS              RES_ERROR_BASE + 68

/** Warning: nothing is imported. */
#define RES_NOTHING_IMPORTED                    RES_ERROR_BASE + 69

/** An invalid Relation is provided. */
#define RES_INVALID_RELATION                    RES_ERROR_BASE + 70

/** No Relation is provided. */
#define RES_NULL_RELATION_FIELD                 RES_ERROR_BASE + 71

/** An invalid type is provided. */
#define RES_INVALID_TYPE                        RES_ERROR_BASE + 72

/** No type is provided. */
#define RES_NULL_TYPE_FIELD                     RES_ERROR_BASE + 73

/** No valid object is selected. */
#define RES_NO_VALID_OBJECT_SELECTED            RES_ERROR_BASE + 74

/** No Item Revision is selected for exploring. */
#define RES_NO_IR_TO_EXPLORE                    RES_ERROR_BASE + 75

/** The "Explore IR" functionality is not supported when a "Transfer Check-Out" operation is performed from the "List Check-Out" dialog. */
#define RES_EXPLORE_IR_NOT_SUPPORT              RES_ERROR_BASE + 76

/** The logged-in user does not have sufficient group privileges for the reservation group "%1$". */
#define RES_NO_GROUP_ADMIN                      RES_ERROR_BASE + 77

/** The replica to check-out is out-of-date. Re-import the object and then check it out. */
#define RES_REPLICA_OUT_OF_DATE                 RES_ERROR_BASE + 78

/** The object cannot be checked-out because your site has neither "WRITE" nor "REMOTE CHECKOUT" access to its master copy at the site "%1$". If the data is owned by the user "infodba", check the AM rule on objects owned by "infodba". */
#define RES_SITE_HAS_NO_WRITE_ACCESS            RES_ERROR_BASE + 79

/** "%1$" is checked-out at a remote site. The operation must be performed at the remote site. */
#define RES_IS_REMOTE_RESERVATION               RES_ERROR_BASE + 80

/** You must first remote check-out the item "%1$" before creating a new revision. */
#define RES_ITEM_NOT_REMOTE_CHECKED_OUT         RES_ERROR_BASE + 81

/** The user "%1$" has neither "WRITE" nor "REMOTE CHECKOUT" access to the master copy of the object "%2$". */
#define RES_USER_HAS_NO_WRITE_ACCESS            RES_ERROR_BASE + 82

/** "%1$" cannot be checked-in because it is in a local process. */
#define RES_IN_LOCAL_PROCESS                    RES_ERROR_BASE + 83

/** The object cannot be checked-out because it is a replica at its owning site. The object may be on a hub. */
#define RES_NO_CHECKOUT_OF_MASTER_REPLICA       RES_ERROR_BASE + 84

/** The master copy at the owning site is not checked-out. Please cancel the replica check-out. The updated dataset will then be saved in your "Newstuff" folder. */
#define RES_REPLICA_RESERVED_BUT_NOT_MASTER     RES_ERROR_BASE + 85

/** The "Transfer Check-Out" is complete, but the e-mail notification has failed. */
#define RES_TRANSFERCHECKOUT_NOTIFICATION_ERROR RES_ERROR_BASE + 86

/** All replica BOM View Revisions must be checked-in prior to checking in the associated replica BOM View. */
#define RES_CI_REPLICA_BVR_BEFORE_BV            RES_ERROR_BASE + 87

/** "%1$" is a replica locally checked-out by "%2$". */
#define RES_REPLICA_LOCAL_RESERVED              RES_ERROR_BASE + 88

/** "%1$" cannot be checked-out to another site because your site is not a hub site. */
#define RES_SITE_NOT_HUB                        RES_ERROR_BASE + 89

/** "%1$" is not site checked-out. */
#define RES_OBJECT_NOT_SITE_RESERVED            RES_ERROR_BASE + 90

/** "%1$" cannot be checked-out to the local site. */
#define RES_SITE_CHECKOUT_TO_LOCAL_SITE         RES_ERROR_BASE + 91

/** "%1$" is of a type not supported by the site check-out functionality. */
#define RES_SITE_UNSUPPORTED_TYPE               RES_ERROR_BASE + 92

/** The export record associated with the bject "%1$" has unexpected status. */
#define RES_UNEXPECTED_EXPORT_RECORD_STATUS     RES_ERROR_BASE + 93

/** "%1$" is a replica and is not checked-out to this site. */
#define RES_REPLICA_NOT_SITE_RESERVED           RES_ERROR_BASE + 94

/** "%1$" is checked-out to the site but not locally checked-out. */
#define RES_SITE_CHECKOUT_NOT_LOCAL_CHECKOUT    RES_ERROR_BASE + 95

/** "%1$" is reserved to another site. */
#define RES_RESERVE_TO_OTHER_SITE               RES_ERROR_BASE + 96

/** "%1$" cannot be remote checked-out because it is site reserved. */
#define RES_SITE_RESERVED_DISALLOW_REMOTE       RES_ERROR_BASE + 97

/** "%1$" cannot be modified because it is site reserved. */
#define RES_OBJECT_SITE_RESERVED                RES_ERROR_BASE + 98

/** The Revision ID already exists for the given Item. */
#define RES_REV_ID_ALREADY_EXISTS               RES_ERROR_BASE + 200

/** "%1$" is not a replica. */
#define RES_OBJECT_NOT_REPLICA                  RES_ERROR_BASE + 201

/** One of the selected object's associated form/named reference ownig site is inconsistent. Re-import the object for consistency. */
#define RES_OBJECT_INCONSISTENT_OWNERSHIP       RES_ERROR_BASE + 202

/** The check-out of "%1$", from site "%2$" to site "%3$", is inconsistent: %4$. */
#define RES_INCONSISTENT_REMOTE_CO              RES_ERROR_BASE + 203

/** Remote Check-In failure: an exception was caught while attempting to remotely check-in "%1$". */
#define RES_REMOTE_CI_FAILED                    RES_ERROR_BASE + 204

/** Remote Check-In failure: an exception was caught while attempting to locally check-in "%1$". */
#define RES_LOCAL_CI_FAILED                     RES_ERROR_BASE + 205

/** The "Check-Out" function is not supported on replica objects, because they are owned by a Global Multi-Site. */
#define RES_GMS_SITE                            RES_ERROR_BASE + 206

/** The Replica object "%1$" cannot be checked-in because it contains checked-out attachments. Please run the "Check-In" or "Cancel Check-Out" operation on these attachments and try again. */
#define RES_REMOTE_CI_ATTACH_OBJ_CO             RES_ERROR_BASE + 207

/** "%1$" is not checked-out locally by the current user. */
#define RES_USER_NOT_LOCAL_CO                   RES_ERROR_BASE + 208

/** The object is not a valid Reservation object. */
#define RES_INVALID_OBJECT                      RES_ERROR_BASE + 209

/** The object is not a valid Edit Context object. */
#define RES_INVALID_EDITCONTEXT                 RES_ERROR_BASE + 210

/** @} */
#endif
