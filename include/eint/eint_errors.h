/*==================================================================================================

                    Copyright (c) 2001 Electronic Data Systems Corporation
                             Unpublished - All rights reserved

====================================================================================================
File description:

    Define error codes used with eintegrator.

====================================================================================================
   Date      Name                    Description of Change
09-Aug-2001  chu                     Merged from snap_v7023
30-Aug-2001  chu                     Prepared for new database
05-Sep-2001  chu                     Clean up errors
05-Sep-2001  chu                     Merged to snap_chu_v80
12-Sep-2001  chu                     Added EINT_proxyaccount_find_error
22-Oct-2001  kao                     mreged to P7034
08-Nov-2001  x_ramak                 Added server and adapter errors
09-Nov-2001  bunly                   Merge from chu_v80_eint
25-Jan-2002  chu                     Added new errors
28-Jan-2002  x_ramak                 Added error number for license check
28-Jan-2002  x_ramak                 Merge out from project branch
14-Feb-2002  x_ramak                 Add more error codes
26-Mar-2002  x_ramak                 Added more errors for dynamic loading
16-Apr-2002  x_ramak                 Added more error messages
03-Jun-2002  x_ramak                 Added new error
23-Aug-2002  x_ramak                 Added ItemRev not revisable error
06-Aug-2002  Aaron Ruckman           Split libtc.dll project
03-Sep-2002  Aaron Ruckman           merge
05-Sep-2002  Aaron Ruckman           Update headers as part of dll splitiman project
22-Nov-2002  Tim Baverstock          Normalise inclusion
10-Jun-2003  x_ramak                 Added new error message for PR 4667321
21-Feb-2005  x_suje                  checkin after fixes
$HISTORY$
==================================================================================================*/

#ifndef EINT_ERRORS_H
#define EINT_ERRORS_H

#include <common/emh_const.h>
#include <eint/libeint_exports.h>

#define EINT_ERROR_BASE                    EMH_EINT_error_base
#define EINT_duplicate_object             (EINT_ERROR_BASE + 1) 
#define EINT_objectmapping_relation_exist (EINT_ERROR_BASE + 2)
#define EINT_unresolve_authentication     (EINT_ERROR_BASE + 3)
#define EINT_datasource_find_error        (EINT_ERROR_BASE + 4)
#define EINT_proxyaccount_find_error      (EINT_ERROR_BASE + 5)

#define EINT_invalid_query                (EINT_ERROR_BASE + 6)
#define EINT_key_not_found                (EINT_ERROR_BASE + 7)
#define EINT_invalid_datasource           (EINT_ERROR_BASE + 8)
#define EINT_invalid_connection           (EINT_ERROR_BASE + 9)
#define EINT_invalid_statement            (EINT_ERROR_BASE + 10)
#define EINT_invalid_result_set           (EINT_ERROR_BASE + 11)
#define EINT_unsupported_property         (EINT_ERROR_BASE + 12)
#define EINT_unsupported_adapter          (EINT_ERROR_BASE + 13)
#define EINT_key_not_unique               (EINT_ERROR_BASE + 14)
#define EINT_invalid_data                 (EINT_ERROR_BASE + 15)

#define EINT_get_dsadapter_error          (EINT_ERROR_BASE + 16)
#define EINT_get_datasource_error         (EINT_ERROR_BASE + 17)
#define EINT_get_connection_error         (EINT_ERROR_BASE + 18)
#define EINT_create_statement_error       (EINT_ERROR_BASE + 19)
#define EINT_execute_query_error          (EINT_ERROR_BASE + 20)
#define EINT_get_column_data_error        (EINT_ERROR_BASE + 21)
#define EINT_commit_ext_source_error      (EINT_ERROR_BASE + 22)
#define EINT_register_dsadapter_error     (EINT_ERROR_BASE + 23)
#define EINT_datasource_mismatch_error    (EINT_ERROR_BASE + 24)
#define EINT_null_itemtype                (EINT_ERROR_BASE + 25)
#define EINT_duplicate_item_prop          (EINT_ERROR_BASE + 26)
#define EINT_itemtype_mismatch_error      (EINT_ERROR_BASE + 27)

#define EINT_no_license_error             (EINT_ERROR_BASE + 28)

#define EINT_invalid_saved_query_count    (EINT_ERROR_BASE + 29)
#define EINT_invalid_storage_tag          (EINT_ERROR_BASE + 30)
#define EINT_read_join_clause_error       (EINT_ERROR_BASE + 31)
#define EINT_read_key_value_error         (EINT_ERROR_BASE + 32)
#define EINT_form_property_not_found      (EINT_ERROR_BASE + 33)
#define EINT_read_property_value_error    (EINT_ERROR_BASE + 34)
#define EINT_table_keys_not_found         (EINT_ERROR_BASE + 35)
#define EINT_invalid_formtype             (EINT_ERROR_BASE + 36)
#define EINT_adapter_info_not_found       (EINT_ERROR_BASE + 37)
#define EINT_memory_allocation_error      (EINT_ERROR_BASE + 38)
#define EINT_result_set_data_mismatch     (EINT_ERROR_BASE + 39)
#define EINT_mapping_relation_error       (EINT_ERROR_BASE + 40)
#define EINT_relationtype_not_found       (EINT_ERROR_BASE + 41)
#define EINT_invalid_formtype_count       (EINT_ERROR_BASE + 42)
#define EINT_no_attr_on_external_object   (EINT_ERROR_BASE + 43)
#define EINT_mapping_info_error           (EINT_ERROR_BASE + 44)

#define EINT_lib_already_loaded           (EINT_ERROR_BASE + 45)
#define EINT_lib_not_found                (EINT_ERROR_BASE + 46)
#define EINT_error_loading_library        (EINT_ERROR_BASE + 47)
#define EINT_symbol_not_found             (EINT_ERROR_BASE + 48)
#define EINT_error_updating_ext_source    (EINT_ERROR_BASE + 49)
#define EINT_wild_card_not_supported      (EINT_ERROR_BASE + 50)

#define EINT_itemrev_not_revisable        (EINT_ERROR_BASE + 51)
#define EINT_mapped_itemrev_not_revisable (EINT_ERROR_BASE + 52)
#define EINT_refresh_failure              (EINT_ERROR_BASE + 53)
#define EINT_invalid_config_file          (EINT_ERROR_BASE + 54)

#define EINT_dspref_empty                 (EINT_ERROR_BASE + 55)
#define EINT_no_mapping_dsource_error     (EINT_ERROR_BASE + 56) 
#define EINT_no_rows_of_data              (EINT_ERROR_BASE + 57)
#define EINT_property_attribute_type_mismatch        (EINT_ERROR_BASE + 58)
#define EINT_primary_attribute_null                  (EINT_ERROR_BASE + 59)
#define EINT_Primary_mapped_attr_mismatch            (EINT_ERROR_BASE + 60)
#define EINT_primary_dependent_prop_mismatch         (EINT_ERROR_BASE + 61)
#define EINT_primary_dependent_prop_valtype_mismatch (EINT_ERROR_BASE + 62)
#define EINT_no_mapping_defined                      (EINT_ERROR_BASE + 63)
#define EINT_dep_prop_error                          (EINT_ERROR_BASE + 64)
#define EINT_same_primary_dependent_prop             (EINT_ERROR_BASE + 65)
#define EINT_query_clause_failure                    (EINT_ERROR_BASE + 66)       
#define EINT_query_column_mismatch                   (EINT_ERROR_BASE + 67)

#define EINT_datasource_find_error_no_parameter      (EINT_ERROR_BASE + 68)


#include <eint/libeint_undef.h>
#endif
