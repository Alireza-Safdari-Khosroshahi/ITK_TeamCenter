/*=============================================================================
           Copyright (c) 1996 Electronic Data Systems Corporation
                   Unpublished - All rights reserved
 
   THIS PROGRAM IS AN UNPUBLISHED WORK FULLY PROTECTED BY THE UNITED STATES 
  COPYRIGHT LAWS AND IS CONSIDERED A TRADE SECRET BELONGING TO THE COPYRIGHT 
                                   HOLDER.
===============================================================================
H+++  File description:
 
 
    File   : publauditrecord_errors.h (PublicationAuditRecord errors)
    Module : publication
===============================================================================
H:::  History:
 date        name        description of change
15-Apr-1997  Vic Nidoy               Created
15-Apr-1997  Vic Nidoy               Promoted to diman branch
$HISTORY$
H---=========================================================================*/

#define PAR_internal_error        (EMH_PAR_error_base + 1)
#define PAR_no_initialize        (EMH_PAR_error_base + 2)
#define PAR_no_create            (EMH_PAR_error_base + 3)
#define PAR_invalid_target_site        (EMH_PAR_error_base + 5)
#define PAR_invalid_published_object    (EMH_PAR_error_base + 6)
#define PAR_invalid_publisher_id    (EMH_PAR_error_base + 7)
#define PAR_invalid_date        (EMH_PAR_error_base + 8)
