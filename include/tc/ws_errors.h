/*==================================================================================================

                    Copyright (c) 1994 Electronic Data Systems Corporation
                             Unpublished - All rights reserved

====================================================================================================
File description:

    Filename: ws_errors.h
    Module  : wrksp

    Define error codes used with workspace.

====================================================================================================
   Date      Name                    Description of Change
20-Jul-1994  Tom McCabe              add latest baseline version
20-Jul-1994  Boma Koko               Add original
20-Jul-1994  Boma Koko               Promoted from idm_main to main
15-Aug-1994  Tom McCabe              add errors
15-Aug-1994  Tom McCabe              Promoted from idm_workspace to main
26-Oct-1994  Paul Jackson            move cant find containing item rev of bvr from sdl to ws errors
23-Nov-1994  Rowlands,Lee            pr 341982, added WS_failed_to_open_help_file
06-Jan-1995  Philip Cope             add error for pasting to hidden reln
19-Jun-1995  Chu Ken                 add error WS_paste_to_psuedo_folder
26-Jun-1995  Philip Cope             add relation editing errors
04-Jul-1995  VOB Manager (pcj)       merge out from main to sdldev branch
09-Aug-1995  James Beard             Correct spelling mistake in 'WS_paste_to_pseudo_folder' token.
09-Aug-1995  James Beard             Error in change
21-Aug-1995  James Beard             Correct "WS_paste_to_psuedo_folder" to "WS_paste_to_pseudo_folder".
15-Dec-1995  Philip Cope             move errors
08-Jan-1996  Heyn Dan                add mult owner setting error
15-Oct-1998  Nigel Morse             make consistant with other headers
06-Aug-2002  Aaron Ruckman           Split libtc.dll project
25-Jun-2003  reger                   remove Motif
25-Jun-2003  reger                   remove export files
12-May-2005  sharmaa                 Protection against infodba changes
$HISTORY$
==================================================================================================*/

#ifndef WS_ERRORS_H
#define WS_ERRORS_H

#include <common/emh_const.h>

#define WS_cut_pseudo_folder               (EMH_WS_error_base +  1)
#define WS_copy_pseudo_folder              (EMH_WS_error_base +  2)
#define WS_invalid_for_pseudo_folder       (EMH_WS_error_base +  3)
#define WS_invalid_action                  WS_invalid_for_pseudo_folder
#define WS_cut_rev_from_item               (EMH_WS_error_base +  4)
#define WS_reference_to_self               (EMH_WS_error_base +  5)
#define WS_cut_bomview_from_item           (EMH_WS_error_base +  6)
#define WS_cut_bvr_from_itemrev            (EMH_WS_error_base +  7)
#define WS_non_folder_container            (EMH_WS_error_base +  8)
#define WS_not_modifiable                  (EMH_WS_error_base +  9)
#define WS_cant_find_item_rev_of_bvr       (EMH_WS_error_base + 10)
#define WS_failed_to_open_help_file        (EMH_WS_error_base + 11)
#define WS_paste_to_hidden_folder          (EMH_WS_error_base + 12)
#define WS_relation_not_found              (EMH_WS_error_base + 13)
#define WS_relation_no_access              (EMH_WS_error_base + 14)
#define WS_relation_no_access_error        (EMH_WS_error_base + 15)
#define WS_paste_to_pseudo_folder          (EMH_WS_error_base + 16)
/* ITK errors */
#define WS_internal_error                  (EMH_WS_error_base + 17)
#define WS_bad_tag                         (EMH_WS_error_base + 18)
/* This error is doubled up - WS_bad_tag should be obsoleted */
#define WS_invalid_tag                     (EMH_WS_error_base + 18)
#define WS_not_yet_initialised             (EMH_WS_error_base + 19)

#define WS_dup_owner_names                 (EMH_WS_error_base + 20)
#define WS_infodba_cannot_create_wsobjects (EMH_WS_error_base + 21)



#define FL_cut_pseudo_folder               WS_cut_pseudo_folder
#define FL_copy_pseudo_folder              WS_copy_pseudo_folder
#define FL_invalid_for_pseudo_folder       WS_invalid_for_pseudo_folder
#define FL_cut_rev_from_item               WS_cut_rev_from_item
#define FL_reference_to_self               WS_reference_to_self
#define FL_cut_bomview_from_item           WS_cut_bomview_from_item
#define FL_cut_bvr_from_itemrev            WS_cut_bvr_from_itemrev
#define FL_non_folder_container            WS_non_folder_container

#endif
