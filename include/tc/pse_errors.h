/*==================================================================================================

                    Copyright (c) 1992 Electronic Data Systems Corporation
                             Unpublished - All rights reserved

====================================================================================================
File description:

    pse_errors.h

    Errors reported by the PSE user interface.

====================================================================================================
   Date      Name                    Description of Change
10-Mar-1994  Paul Jackson            pse user interface errors
10-Mar-1994  Paul Jackson            cant cut from multiple parents
16-Mar-1994  Paul Jackson            cant add structure to a mixture of precise and imprecise parents
24-Mar-1994  Paul Jackson            editing note ifail for may i edit stuff
05-Apr-1994  Paul Jackson            prevent deletion or modification of ug reserved note types
06-Apr-1994  Chris Pointon           Add Bill Display Options errors
13-Apr-1994  Chris Pointon           Add user callback failure
28-Apr-1994  Chris Pointon           Add ifail for may I edit note
12-May-1994  Hewat Kennedy           add editing status error code
20-May-1994  Hugh Stewart            transfer from Jeeves
09-Jun-1994  Paul Jackson            cant replace child if substituting parent at same time
10-Jun-1994  Paul Jackson            no lines for replace
10-Jun-1994  Philip Cope             add vt100 disabled error
16-Jun-1994  Paul Jackson            errors for nothing entered in the find in bom dialog
07-Jul-1994  Hugh Stewart            findinbom.cxx
07-Jul-1994  Hugh Stewart            block editing item name of a released item
12-Jul-1994  Jenkins, Phill          Syncing from sdl
12-Jul-1994  INFOMAN                 Promoted from sdldev to main
28-Apr-1994  Chris Pointon           Add ifail for may I edit note
13-Jul-1994  Boma Koko               Merge main into idm_main
20-Jul-1994  Boma Koko               Promoted from idm_main to main
19-Jul-1994  Hugh Stewart            invent PSE_editing_elsewhere
01-Aug-1994  Paul Jackson            merge out from main to sdldev branch after idm promote
19-Oct-1994  Paul Jackson            move sdls object used in pse error to here
19-Oct-1994  Paul Jackson            move sdl cant configure item error to here
19-Oct-1994  Paul Jackson            move the sdl bvr does not belong to item rev error to pse errors
19-Oct-1994  Paul Jackson            move the sdl delete bv by bvrs error to pse errors
19-Oct-1994  Paul Jackson            move the sdl rev has no bvr of bv error to pse errors
19-Oct-1994  Paul Jackson            move the sdl cant save im/precise preference error to pse errors
19-Oct-1994  Paul Jackson            move sdl single view error to pse errors
20-Oct-1994  Paul Jackson            move silly paste count error from sdl to pse
26-Oct-1994  Paul Jackson            move sdl errors for the config rule dialogs to pse errors
26-Oct-1994  Paul Jackson            move item8 rev has no parents error from sdl to pse errors
26-Oct-1994  Paul Jackson            move the not found in bom error from sdl to pse errors
22-Nov-1994  Vic Nidoy               Add PSE_ie_callbacks_failed
17-Feb-1995  Hewat Kennedy           add PSE_no_window_on_bom
12-Sep-1995  Paul Jackson            no view types defined
21-Sep-1995  Paul Jackson            rev uses all view types
09-Oct-1995  Michael Bowles          Add PSE_item_rev_not_writable
12-Dec-1995  Philip Cope             new error code
29-Feb-1996  Charles Brown           removing illegal characters from previous comment
29-Feb-1996  Philip Cope             add proper error for create dialog
29-Mar-1996  Neil Ross               Adding BOM Compare errors
13-Mar-1996  Charles Brown           Add no alternative view types error
29-Mar-1996  Paul Jackson            merge out from sdldev to mv branch
14-May-1996  Neil Ross               Add compare find errors
15-Jul-1996  James Beard             Add PSEbv_referenced and PSE_bvr_referenced
04-Jul-1997  Neil Ross               Adding error for failing to insert new Item into Workspace
27-Oct-1997  Paul Jackson            no advanced psm user licence error
09-Dec-1997  Neil Ross               Adding Variant Rule errors
04-Feb-1998  James Beard             Add PSE_invalid_seq_no
10-Jun-1999  Ramesh Ramaiah          Added Res Callback error mesg
08-Mar-2000  Neil Ross               Add an error for variant data changing behind your back
06-Aug-2002  Aaron Ruckman           Split libtc.dll project
25-Jun-2003  reger                   remove Motif
25-Jun-2003  reger                   remove export files
12-Apr-2005  Elizabeth Ayer          Remove PSE_no_advanced_license, add PSE_no_variants_license
24-Mar-2006  Johann Chemin-Danielson  DeImanization
$HISTORY$
==================================================================================================*/

#ifndef PSE_ERRORS_H
#define PSE_ERRORS_H

#include <common/emh_const.h>

#define PSE_internal_error                 (EMH_PSE_error_base +  0)
#define PSE_frozen_ir                      (EMH_PSE_error_base +  1)
#define PSE_cant_cut_from_multiple_parents (EMH_PSE_error_base +  2)
#define PSE_cant_add_to_mixed_parents      (EMH_PSE_error_base +  3)
#define PSE_editing_elsewhere              (EMH_PSE_error_base +  4)
#define PSE_cant_modify_nx_note            (EMH_PSE_error_base +  5)
#define PSE_cant_save_options              (EMH_PSE_error_base +  6)
#define PSE_user_callbacks_failed          (EMH_PSE_error_base +  7)
#define PSE_not_called_from_pse            (EMH_PSE_error_base +  8)
#define PSE_cant_replace_parent_and_child  (EMH_PSE_error_base + 10)
#define PSE_no_lines_for_replace           (EMH_PSE_error_base + 11)
#define PSE_cant_display_on_vt100          (EMH_PSE_error_base + 12)
#define PSE_findinbom_enter_id             (EMH_PSE_error_base + 14)
#define PSE_findinbom_enter_name           (EMH_PSE_error_base + 15)
#define PSE_findinbom_no_such_rev          (EMH_PSE_error_base + 16)
#define PSE_may_not_edit_released_item     (EMH_PSE_error_base + 17)
/** The object "%1$" is in use in a BOM window.
Close the window with top line "%2$". */
#define PSE_obj_in_use                     (EMH_PSE_error_base + 18)
#define PSE_cant_configure_item            (EMH_PSE_error_base + 19)
#define PSE_not_bvr_of_item_rev            (EMH_PSE_error_base + 20)
#define PSE_delete_bv_by_its_bvrs          (EMH_PSE_error_base + 21)
#define PSE_item_rev_has_no_bvr_of_bv      (EMH_PSE_error_base + 22)
#define PSE_cant_save_precise_pref         (EMH_PSE_error_base + 23)
#define PSE_single_view_only               (EMH_PSE_error_base + 24)
#define PSE_invalid_paste_count            (EMH_PSE_error_base + 25)
#define PSE_select_status                  (EMH_PSE_error_base + 26)
#define PSE_enter_eff_date                 (EMH_PSE_error_base + 27)
#define PSE_enter_eff_no                   (EMH_PSE_error_base + 28)
#define PSE_select_rule                    (EMH_PSE_error_base + 29)
#define PSE_select_override_folder         (EMH_PSE_error_base + 30)
#define PSE_rev_has_no_parents             (EMH_PSE_error_base + 31)
#define PSE_not_found_in_bom               (EMH_PSE_error_base + 32)
#define PSE_ie_callbacks_failed            (EMH_PSE_error_base + 33)
#define PSE_no_window_on_bom               (EMH_PSE_error_base + 34)
#define PSE_item_rev_not_writable          (EMH_PSE_error_base + 35)
#define PSE_ask_auto_revise                (EMH_PSE_error_base + 36)
#define PSE_duplicate_bvr_failed           (EMH_PSE_error_base + 37)
#define PSE_compare_insufficient_data      (EMH_PSE_error_base + 38)
#define PSE_compare_identical_data         (EMH_PSE_error_base + 39)
#define PSE_compare_invalid_bomline        (EMH_PSE_error_base + 40)
#define PSE_compare_failure                (EMH_PSE_error_base + 41)
#define PSE_compare_no_difference          (EMH_PSE_error_base + 42)
#define PSE_compare_paste_empty            (EMH_PSE_error_base + 43)
#define PSE_compare_paste_overflow         (EMH_PSE_error_base + 44)
#define PSE_compare_invalid_selection      (EMH_PSE_error_base + 45)
#define PSE_no_view_types                  (EMH_PSE_error_base + 46)
#define PSE_rev_uses_all_view_types        (EMH_PSE_error_base + 47)
#define PSE_no_alternative_views           (EMH_PSE_error_base + 48)
#define PSE_compare_not_active             (EMH_PSE_error_base + 49)
#define PSE_compare_no_map_parents         (EMH_PSE_error_base + 50)
#define PSE_bv_referenced                  (EMH_PSE_error_base + 51)
#define PSE_cant_delete_bv                 (EMH_PSE_error_base + 52)
#define PSE_cant_delete_bvr                (EMH_PSE_error_base + 53)
#define PSE_ws_insert_failed               (EMH_PSE_error_base + 54)
#define PSE_no_variants_license            (EMH_PSE_error_base + 55)
#define PSE_no_vrule_selected              (EMH_PSE_error_base + 56)
#define PSE_no_vrule_on_clipboard          (EMH_PSE_error_base + 57)
#define PSE_multiple_vrules_on_clipboard   (EMH_PSE_error_base + 58)
#define PSE_invalid_seq_no                 (EMH_PSE_error_base + 59)
#define PSE_res_callbacks_failed           (EMH_PSE_error_base + 60)
#define PSE_variant_data_updated           (EMH_PSE_error_base + 61)


#endif  /* PSE_ERRORS_H */
