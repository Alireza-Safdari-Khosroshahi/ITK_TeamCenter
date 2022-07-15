/*==================================================================================================

                    Copyright (c) 2000 Unigraphics Solutions Inc., An EDS Company
                             Unpublished - All rights reserved

====================================================================================================
File description:

    Filename: nw_errors.h
    Module  :

    Header file to define errors for network services

====================================================================================================
   Date      Name                    Description of Change
09-Aug-2000  Tom McCabe              PR 4136983
06-Aug-2002  Aaron Ruckman           Split libtc.dll project
04-Sep-2002  Aaron Ruckman           Update headers as part of dll splitiman project
22-Nov-2002  Tim Baverstock          Normalise inclusion
$HISTORY$
==================================================================================================*/
/*
*
*  header file to define errors for network services
*
*  revisions
*  rv date    who pr     reason for change
*  00 10may92 tem    initial implementation
*  01 13jul92 tem    added NW_SERVER_ERROR
*
*/
#ifndef NW_ERRORS_H
#define NW_ERRORS_H

#ifndef EMH_CONST_H
#include <common/emh_const.h>
#endif

#include <ss/libss_exports.h>

#define NW_EB       EMH_NW_error_base
#define NW_NOCRTIPC         NW_EB + 1   /*  Unable to create net ipc queue */
#define NW_NOIPCENTRY       NW_EB + 2   /*  Unable to create net ipc entry in table */
#define NW_NOSUCHIPC        NW_EB + 3   /*  Unable to find net ipc entry in table   */
#define NW_NODELIPC         NW_EB + 4   /*  Unable to delete net ipc queue */
#define NW_NOSNDMSG         NW_EB + 5   /*  Unable to send message to net queue */
#define NW_NORCVMSG         NW_EB + 6   /*  Unable to receive message from net queue*/
#define NW_NOPROTOCOL       NW_EB + 7   /*  Unable to get protocol number */
#define NW_NOSERVICE        NW_EB + 8   /*  Unable to get service by name */
#define NW_NOHOST           NW_EB + 9   /*  Unable to get host by name */
#define NW_INCOMP           NW_EB + 10  /*  Operation incomplete */
#define NW_NOACCEPT         NW_EB + 11  /*  Unable to accept connection */
#define NW_SERVER_ERROR     NW_EB + 12  /*  Unclassified network server error */
#define NW_RCV_TIMEDOUT     NW_EB + 13  /*  Timed out doing recvs */
#define NW_SETSOCKOPT_FAIL  NW_EB + 14  /*  Call to setsockopt failed */

#include <ss/libss_undef.h>
#endif

