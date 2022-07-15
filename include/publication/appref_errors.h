/*==================================================================================================

                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved

====================================================================================================
File description:

    Errors for the APPREF Module

====================================================================================================
   Date      Name                    Description of Change
07-Nov-2005  Tom McCabe              ODS extensions for NXMI
$HISTORY$
==================================================================================================*/

#ifndef APPREF_ERRORS_H
#define APPREF_ERRORS_H

#include <common/emh_const.h>

#define APPREF_ALREADY_EXISTS           (EMH_APPREF_error_base + 1)
#define APPREF_INVALID_DELETE_OPTION    (EMH_APPREF_error_base + 2)
#define APPREF_NO_REGISTRY_SITE_DEFINED (EMH_APPREF_error_base + 3)
#define APPREF_REGISTRY_NOT_ODS_CAPABLE (EMH_APPREF_error_base + 4)
#define APPREF_FINDING_SITE             (EMH_APPREF_error_base + 5)
#define APPREF_OWNING_SITE_NOT_LOCAL    (EMH_APPREF_error_base + 6)
#define APPREF_DOES_NOT_EXIST           (EMH_APPREF_error_base + 7)

#endif
