/*HEAD PDI_SERVER_ERRORS HHH UGMR */
/*==================================================================================================

                    Copyright (c) 1994 Electronic Data Systems Corporation
                             Unpublished - All rights reserved
                                       Shape Data

====================================================================================================
File description:


====================================================================================================
   Date      Name                    Description of Change

20-Mar-1994  Tim Carter              Record last error type so that it can be explained if necessary
23-May-1996  Paul J Wilken           Add a Head and/or Class Card
24-May-1996  Paul J Wilken           Add a CORRECT Head/Class Card !
16-Sep-1996  Tim Carter              Reorganised IMAN error reporting for better error messages
19-Dec-1997  Austin Benson           Transfer from Jeeves to Clearcase
18-Aug-2000  Alexandra Wagner        Export some symbols
18-Aug-2000  Alexandra Wagner        Forgot the NXMGR_IM_API thing
06-Aug-2002  Aaron Ruckman           Split libtc.dll project
05-Sep-2002  Aaron Ruckman           Update headers as part of dll splitiman project
05-Mar-2004  Brendan Brolly          Rebase to NX3
$HISTORY$
==================================================================================================*/
#ifndef PDI_SERVER_ERRORS_H_INCLUDED
#define PDI_SERVER_ERRORS_H_INCLUDED

#include <nxmgr_im/libnxmgr_im_exports.h>

#ifdef __cplusplus
    extern "C"{
#endif
extern NXMGR_IM_API void PDI__set_error_was_error( void );


extern NXMGR_IM_API void PDI__set_error_description(
    int                         error_number,
    char*                       error_name,
    char*                       explanation
    );

typedef const char* (*PDI__error_translator_fn_t)(
    int                         ifail
    );

extern NXMGR_IM_API void PDI__set_error_translator(
    PDI__error_translator_fn_t  handler
    );

#ifdef __cplusplus
}
#endif
#include <nxmgr_im/libnxmgr_im_undef.h>
#endif /* PDI_SERVER_ERRORS_H_INCLUDED */
