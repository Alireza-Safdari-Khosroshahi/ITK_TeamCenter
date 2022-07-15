/*==================================================================================================

                    Copyright (c) 1994 Electronic Data Systems Corporation
                             Unpublished - All rights reserved

====================================================================================================
File description:

    interop_errors.h

    Define error codes used with Interop module.

====================================================================================================
   Date      Name                    Description of Change
27-Nov-2002  Sanjay Patel            Initial Version
13-Dec-2002  Sanjay Patel            Merge in
30-Dec-2002  Sanjay Patel            Adding INTEROP_DIRECTMODEL_DATASET_WITHOUT_JTPART error
28-Feb-2003  Carla Jenkins           Changed comments to C-style comments
24-Mar-2003  Nigel Morse (vobman)    split DLLs for v9
$HISTORY$
==================================================================================================*/
#ifndef INTEROP_ERRORS_H
#define INTEROP_ERRORS_H

#include <common/emh_const.h>

/*
 * Error code constants.
 */

#define INTEROP_NULL_INPUTS                      (EMH_INTEROP_error_base + 1)
#define INTEROP_TAG_PLMXML_BOTH_CANNOT_EXIST     (EMH_INTEROP_error_base + 2)
#define INTEROP_SERVER_NOT_DEFINED               (EMH_INTEROP_error_base + 3)
#define INTEROP_GET_HOST_FAILED                  (EMH_INTEROP_error_base + 4)
#define INTEROP_PORT_NOT_FOUND                   (EMH_INTEROP_error_base + 5)
#define INTEROP_CONNECT_INVALID_INPUT            (EMH_INTEROP_error_base + 6)
#define INTEROP_NO_VALID_SERVER_FOUND            (EMH_INTEROP_error_base + 7)
#define INTEROP_NO_DIRECTMODEL_FOUND             (EMH_INTEROP_error_base + 8)
#define INTEROP_OBJECTS_WITHOUT_DIRECTMODEL      (EMH_INTEROP_error_base + 9)
#define INTEROP_TAG_NOT_VALID                    (EMH_INTEROP_error_base + 10)
#define INTEROP_RENDERING_RELATION_NOT_FOUND     (EMH_INTEROP_error_base + 11)
#define INTEROP_DATASET_NO_REFS                  (EMH_INTEROP_error_base + 12)
#define INTEROP_OBJECT_IS_NOT_VALID_INPUT        (EMH_INTEROP_error_base + 13)
#define INTEROP_DATASET_NO_VALID_REF             (EMH_INTEROP_error_base + 14)
#define INTEROP_NO_DEFAULT_BUT_MULTIPLE_VIEW     (EMH_INTEROP_error_base + 15)
#define INTEROP_NO_BVR_OF_SELECTED_VIEW_TYPE     (EMH_INTEROP_error_base + 16)
#define INTEROP_ITEMREV_NO_ASSY_NO_DIRECT_MODEL  (EMH_INTEROP_error_base + 17)
#define INTEROP_GENERATED_FILE_DOES_NOT_EXISTS   (EMH_INTEROP_error_base + 18)
#define INTEROP_FAILED_TO_OPEN_FILE              (EMH_INTEROP_error_base + 19)
#define INTEROP_WRITE_NOT_COMPLETE               (EMH_INTEROP_error_base + 20)
#define INTEROP_FAILED_TO_GENERATE_OBID          (EMH_INTEROP_error_base + 21)
#define INTEROP_DIRECTMODEL_WITHOUT_JTPART       (EMH_INTEROP_error_base + 22)

/* Socket Communication Errors */

#define INTEROP_HOST_NOT_FOUND                (EMH_INTEROP_error_base + 51)
#define INTEROP_FAILED_TO_CONNECT             (EMH_INTEROP_error_base + 52)
#define INTEROP_RESPONSE_STATUS_NOT_OK        (EMH_INTEROP_error_base + 53)
#define INTEROP_WINSOCK_FAILED                (EMH_INTEROP_error_base + 54)
#define INTEROP_SOCKET_ERROR                  (EMH_INTEROP_error_base + 55)


#endif /* End of INTEROP_ERRORS_H */
