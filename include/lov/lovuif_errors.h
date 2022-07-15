/*=============================================================================
           Copyright (c) 1995 Electronic Data Systems Corporation
                   Unpublished - All rights reserved

   THIS PROGRAM IS AN UNPUBLISHED WORK FULLY PROTECTED BY THE UNITED STATES
  COPYRIGHT LAWS AND IS CONSIDERED A TRADE SECRET BELONGING TO THE COPYRIGHT
                                   HOLDER.
===============================================================================
H+++  File description:

    File Name: lovuif_errors.h
    Subsystem: listofvalues

===============================================================================
H:::  History:
   date         name                 description of change
11-Apr-1996  Takito Masaaki          Created
06-Aug-2002  Aaron Ruckman           Split libtc.dll project
05-Sep-2002  Aaron Ruckman           Update headers as part of dll splitiman project
22-Nov-2002  Tim Baverstock          Normalise inclusion
$HISTORY$
H---=========================================================================*/

#ifndef LOVUIF_ERRORS_H
#define LOVUIF_ERRORS_H


#include <common/emh_const.h>
#include <lov/liblov_exports.h>


#define LOVUIF_unexpected_error         (EMH_LOVUIF_error_base + 1)
#define LOVUIF_cant_start_lovwindow     (EMH_LOVUIF_error_base + 2)
#define LOVUIF_no_lov_selected          (EMH_LOVUIF_error_base + 3)
#define LOVUIF_cant_get_lovs_name       (EMH_LOVUIF_error_base + 4)
#define LOVUIF_cant_get_lovs_desc       (EMH_LOVUIF_error_base + 5)
#define LOVUIF_cant_get_lovs_type       (EMH_LOVUIF_error_base + 6)
#define LOVUIF_cant_get_lovs_value_type (EMH_LOVUIF_error_base + 7)
#define LOVUIF_cant_get_lovs_usage      (EMH_LOVUIF_error_base + 8)
#define LOVUIF_unknown_value_type       (EMH_LOVUIF_error_base + 9)
#define LOVUIF_unknown_usage            (EMH_LOVUIF_error_base + 10)
#define LOVUIF_cant_get_reference_info  (EMH_LOVUIF_error_base + 11)
#define LOVUIF_cant_have_multiple_range (EMH_LOVUIF_error_base + 12)
#define LOVUIF_not_unique_data          (EMH_LOVUIF_error_base + 13)
#define LOVUIF_inconsistent_range       (EMH_LOVUIF_error_base + 14)
#define LOVUIF_cant_fetch_instance      (EMH_LOVUIF_error_base + 15)
#define LOVUIF_cant_get_method          (EMH_LOVUIF_error_base + 16)
#define LOVUIF_lack_of_lov_name         (EMH_LOVUIF_error_base + 17)
#define LOVUIF_lack_of_reference_info   (EMH_LOVUIF_error_base + 18)
#define LOVUIF_no_memory                (EMH_LOVUIF_error_base + 19)
#define LOVUIF_cant_get_attached_type   (EMH_LOVUIF_error_base + 20)
#define LOVUIF_cant_get_attached_class  (EMH_LOVUIF_error_base + 21)
#define LOVUIF_cant_get_attached_attr   (EMH_LOVUIF_error_base + 22)
#define LOVUIF_unknown_attachment_type  (EMH_LOVUIF_error_base + 23)
#define LOVUIF_existing_attachement     (EMH_LOVUIF_error_base + 24)
#define LOVUIF_invalid_reference        (EMH_LOVUIF_error_base + 25)
#define LOVUIF_lack_of_association_info (EMH_LOVUIF_error_base + 26)
#define LOVUIF_cant_found_class         (EMH_LOVUIF_error_base + 27)
#define LOVUIF_cant_get_class_def       (EMH_LOVUIF_error_base + 28)
#define LOVUIF_cant_get_attr_def        (EMH_LOVUIF_error_base + 29)
#define LOVUIF_no_length_attr_name      (EMH_LOVUIF_error_base + 30)
#define LOVUIF_no_appropriate_attr      (EMH_LOVUIF_error_base + 31)
#define LOVUIF_cant_get_prop_def        (EMH_LOVUIF_error_base + 32)
#define LOVUIF_cant_get_prop_value_type (EMH_LOVUIF_error_base + 33)
#define LOVUIF_cant_get_prop_name       (EMH_LOVUIF_error_base + 34)
#define LOVUIF_no_length_prop_name      (EMH_LOVUIF_error_base + 35)
#define LOVUIF_cant_detach              (EMH_LOVUIF_error_base + 36)
#define LOVUIF_lack_of_association_data (EMH_LOVUIF_error_base + 37)
#define LOVUIF_cant_attach              (EMH_LOVUIF_error_base + 38)
#define LOVUIF_no_allowable_values      (EMH_LOVUIF_error_base + 39)
#define LOVUIF_specify_value            (EMH_LOVUIF_error_base + 40)
#define LOVUIF_unexpected_locale        (EMH_LOVUIF_error_base + 41)


#include <lov/liblov_undef.h>
#endif  /* LOVUIF_ERRORS_H */


