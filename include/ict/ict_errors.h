/* =================================================================================================
           Copyright (c) 1999 Unigraphics Solutions Inc., An EDS Company
                   Unpublished - All rights reserved

   THIS PROGRAM IS AN UNPUBLISHED WORK FULLY PROTECTED BY THE UNITED STATES
  COPYRIGHT LAWS AND IS CONSIDERED A TRADE SECRET BELONGING TO THE COPYRIGHT
                                   HOLDER.
====================================================================================================
File description:

    Errors for the ICT Layer

    File   : ict_errors.h
    Module : ict

====================================================================================================
   Date      Name                    Description of Change
27-Aug-1999  Saiganesh Ramani        Error Codes for ICT
03-Nov-1999  S. V. Brahmanandam      More error codes
30-Nov-1999  S. V. Brahmanandam      add ICT_invalid_argument_type
14-Jan-19100  Jeff Currier,,,         add new user error codes
04-Feb-2000  Jifeng Li               Add ICT_cannot_add_self error code
09-Mar-2000  Jifeng Li               Add ICT_cannot_cut_amruletree_root
10-Mar-2000  Jifeng Li               Add ICT_cannot_move_amruletree_root
29-Mar-2000  Jifeng Li               Add ICT_cannot_remove_role_from_group
22-Jun-2000  S. V. Brahmanandam      Add error codes for license check
19-Sep-2000  Chandrashekar Veerapaneni  Add ICT_invalid_selection
02-Nov-2000  Jeff Currier,,,         Added entries for new getUserList errors
13-Dec-2000  Jeff Currier,,,         add errors for the file transfer service
25-Jul-2001  Sunil Viswanathan       Added more FLEX errors
31-Jul-2001  Jeff Currier,,,         add in old internal error message
06-Sep-2001  Sunil Viswanathan       Promoted from viswanat_pv_look_v8
06-Aug-2002  Aaron Ruckman           Split libtc.dll project
05-Sep-2002  Aaron Ruckman           Update headers as part of dll splitiman project
22-Nov-2002  Tim Baverstock          Normalise inclusion
15-Oct-2002  wangp                   add error code for ictrole
04-Feb-2003  Peiyi Wang              add error code for ictgroup
28-Apr-2003  Jim Towers              merge from P9.0.0.0
24-Mar-2006  Johann Chemin-Danielson  DeImanization
$HISTORY$
==================================================================================================*/

#ifndef ICT_ERRORS_H
#define ICT_ERRORS_H

#include <common/emh_const.h>

#define ICT_insufficient_num_of_args            (EMH_ICT_error_base + 1)
#define ICT_no_argument_found                   (EMH_ICT_error_base + 2)
#define ICT_incorrect_argument_type             (EMH_ICT_error_base + 3)
#define ICT_method_not_registered               (EMH_ICT_error_base + 4)
#define ICT_duplicate_method_name               (EMH_ICT_error_base + 5)
#define ICT_argument_stack_not_constructed      (EMH_ICT_error_base + 6)
#define ICT_argument_type_not_implemented       (EMH_ICT_error_base + 7)
#define ICT_void_type_not_allowed               (EMH_ICT_error_base + 8)
#define ICT_invalid_argument_type               (EMH_ICT_error_base + 9)
#define ICT_cannot_add_self                     (EMH_ICT_error_base + 10)
#define ICT_cannot_cut_amruletree_root          (EMH_ICT_error_base + 11)
#define ICT_cannot_move_amruletree_root         (EMH_ICT_error_base + 12)
#define ICT_cannot_remove_role_from_group       (EMH_ICT_error_base + 13)
#define ICT_invalid_selection                   (EMH_ICT_error_base + 14)
#define ICT_internal_error                      (EMH_ICT_error_base + 15)
#define ICT_internal_error_info                 (EMH_ICT_error_base + 16)

#define ICT_USER_ERROR_BASE                     (EMH_ICT_error_base + 25)

#define ICT_USER_unable_to_check_password       (ICT_USER_ERROR_BASE + 1)
#define ICT_USER_unable_to_change_password      (ICT_USER_ERROR_BASE + 2)
#define ICT_USER_unable_to_create_enquiry       (ICT_USER_ERROR_BASE + 3)
#define ICT_USER_unable_to_execute_enquiry      (ICT_USER_ERROR_BASE + 4)
#define ICT_USER_unable_to_reset_bind_val       (ICT_USER_ERROR_BASE + 5)

#define ICT_FILE_XFER_SERVICE_ERROR_BASE        (EMH_ICT_error_base + 50)

#define ICT_FILEXFER_no_directory_given         (ICT_FILE_XFER_SERVICE_ERROR_BASE + 1)
#define ICT_FILEXFER_no_filename_given          (ICT_FILE_XFER_SERVICE_ERROR_BASE + 2)
#define ICT_FILEXFER_no_filetype_given          (ICT_FILE_XFER_SERVICE_ERROR_BASE + 3)
#define ICT_FILEXFER_no_access                  (ICT_FILE_XFER_SERVICE_ERROR_BASE + 4)

#define ICT_FLEXLM_ERROR_BASE                   (EMH_ICT_error_base + 100)

#define ICT_acs_init_failed                     (ICT_FLEXLM_ERROR_BASE +1)
#define ICT_acs_no_attach                       (ICT_FLEXLM_ERROR_BASE +2)
#define ICT_acs_no_tc_first_user_license        (ICT_FLEXLM_ERROR_BASE +3)
#define ICT_acs_no_tc_user_license              (ICT_FLEXLM_ERROR_BASE +4)
#define ICT_acs_no_available_license            (ICT_FLEXLM_ERROR_BASE +5)
#define ICT_acs_cannot_release_license          (ICT_FLEXLM_ERROR_BASE +6)
#define ICT_acs_usage_limit_exceeded            (ICT_FLEXLM_ERROR_BASE +7)
#define ICT_acs_default_error                   (ICT_FLEXLM_ERROR_BASE +8)

#define ICT_ROLE_ERROR_BASE                     (EMH_ICT_error_base + 150)

#define ICT_ROLE_unable_to_create_enquiry       (ICT_ROLE_ERROR_BASE + 1)   
#define ICT_ROLE_unable_to_execute_enquiry      (ICT_ROLE_ERROR_BASE + 2)

#define ICT_PERSON_ERROR_BASE                   (EMH_ICT_error_base + 175)

#define ICT_PERSON_unable_to_create_enquiry     (ICT_ROLE_ERROR_BASE + 1)   
#define ICT_PERSON_unable_to_execute_enquiry    (ICT_ROLE_ERROR_BASE + 2)

#define ICT_GROUP_ERROR_BASE                    (EMH_ICT_error_base + 200)

#define ICT_GROUP_unable_to_create_enquiry      (ICT_GROUP_ERROR_BASE + 1)   
#define ICT_GROUP_unable_to_execute_enquiry     (ICT_GROUP_ERROR_BASE + 2)
#define ICT_GROUP_unable_to_reset_bind_val      (ICT_GROUP_ERROR_BASE + 3)
#define ICT_GROUP_unable_to_find_group          (ICT_GROUP_ERROR_BASE + 4)

#define ICT_SITE_ERROR_BASE                     (EMH_ICT_error_base + 250)

#define ICT_SITE_unable_to_create_enquiry       (ICT_SITE_ERROR_BASE + 1)   
#define ICT_SITE_unable_to_execute_enquiry      (ICT_SITE_ERROR_BASE + 2)

#define ICT_VOLUME_ERROR_BASE                   (EMH_ICT_error_base + 275)

#define ICT_VOLUME_unable_to_create_enquiry     (ICT_VOLUME_ERROR_BASE + 1)   
#define ICT_VOLUME_unable_to_execute_enquiry    (ICT_VOLUME_ERROR_BASE + 2)


#define ICT_GROUPMEMBER_ERROR_BASE                 (EMH_ICT_error_base + 300)

#define ICT_GROUPMEMBER_unable_to_create_enquiry   (ICT_GROUPMEMBER_ERROR_BASE + 1)   
#define ICT_GROUPMEMBER_unable_to_execute_enquiry  (ICT_GROUPMEMBER_ERROR_BASE + 2)   
#define ICT_GROUPMEMBER_unable_to_reset_bind_val   (ICT_GROUPMEMBER_ERROR_BASE + 3)   
#define ICT_GROUPMEMBER_unable_to_find_group       (ICT_GROUPMEMBER_ERROR_BASE + 4)
#define ICT_GROUPMEMBER_unable_to_reset_bind_val_grouprole   (ICT_GROUPMEMBER_ERROR_BASE + 5)
#define ICT_GROUPMEMBER_unable_to_reset_bind_val_activegm    (ICT_GROUPMEMBER_ERROR_BASE + 6)
#define ICT_GROUPMEMBER_unable_to_reset_bind_val_allgm       (ICT_GROUPMEMBER_ERROR_BASE + 7)

#endif
